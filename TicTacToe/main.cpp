#include <iostream>
#include <SFML/Network.hpp>

#include "TicTacToe.h";

using namespace std;

void jouer(bool estServeur, unsigned short port);

void saisirPosition(int& ligne, int& colonne, char lettreJoueur);

int main()
{
	const unsigned short PORT = 54000;
	int choixOption;

	setlocale(LC_ALL, "");

	while (true) {
		cout << "TIC TAC TOE" << endl
			<< "===========" << endl << endl
			<< "Choisir une option: " << endl
			<< "1. Créer une partie" << endl
			<< "2. Joindre une partie" << endl << endl;

		do {
			cout << "Votre choix: ";
			cin >> choixOption;
		} while (choixOption != 1 && choixOption != 2);

		if (choixOption == 1) {
			jouer(true, PORT);
		}
		else {
			jouer(false, PORT);
		}

		cout << endl;
		system("pause");
		system("cls");
	}
}

void jouer(bool estServeur, unsigned short port) {
	sf::TcpSocket socket;
	sf::Packet packet;
	sf::Socket::Status status;
	char lettreJoueur;
	if (estServeur) {
		sf::TcpListener listener;
		if (listener.listen(port) != sf::Socket::Done) {
			cout << "Une erreur est servenu lors de la creation du listener." << endl;
			return;
		}
		cout << "En attente de l'autre joueur..." << endl;
		listener.accept(socket);
		cout << "L'autre joueur vient de se connecter." << endl;
		lettreJoueur = 'x';
	}
	else {
		string adresseServeur;
		cout << "Entrer l'adresse du serveur: ";
		cin >> adresseServeur;
		if (socket.connect(adresseServeur, port) != sf::Socket::Done) {
			cout << "Une erreur est servenu lors de la connexion." << endl;
			return;
		}
		lettreJoueur = 'o';
	}

	TicTacToe ticTacToe;
	char tour = 'x';
	bool coupValide;

	int ligne, colonne;

	while (ticTacToe.getGagnant() == ' ' && !ticTacToe.estMatchNul()) {
		cout << endl << ticTacToe << endl;

		if (tour == lettreJoueur) {
			cout << "C'est votre tour." << endl;
			do {
				saisirPosition(ligne, colonne, tour);

				coupValide = ticTacToe.jouer(ligne, colonne, tour);
				if (!coupValide) {
					cout << "Vous ne pouvez pas placer votre " << tour << " là." << endl;
				}
			} while (!coupValide);
			packet << ligne << colonne;
			status = socket.send(packet);
			if (status == sf::Socket::Disconnected) {
				cout << "L'autre joueur est deconnecter, fin de la partie" << endl;
				return;
			}
		}
		else {
			cout << "C'est le tour de l'autre joueur." << endl;
			status = socket.receive(packet);
			if (status == sf::Socket::Disconnected) {
				cout << "L'autre joueur est deconnecter, fin de la partie" << endl;
				return;
			}
			packet >> ligne >> colonne;
			ticTacToe.jouer(ligne, colonne, tour);
		}

		if (tour == 'x') {
			tour = 'o';
		}
		else {
			tour = 'x';
		}
		packet.clear();
	}

	cout << endl << ticTacToe << endl;
	if (ticTacToe.getGagnant() != ' ') {
		cout << endl << "Le joueur " << '"' << ticTacToe.getGagnant() << "\" a gagné!" << endl;
	}
	else {
		cout << endl << "Match nul!" << endl;
	}
	socket.disconnect();
}

void saisirPosition(int& x, int& y, char lettreJoueur) {
	char saisieLigne;
	int saisieColonne;

	do {
		cout << "Où voulez-vous placer votre " << lettreJoueur << "?" << endl
			<< "ligne colonne : ";
		cin >> saisieLigne >> saisieColonne;
	} while (saisieLigne < 'a' || saisieLigne > 'c' || saisieColonne < 1 || saisieColonne > 3);

	x = saisieLigne - 'a';
	y = saisieColonne - 1;
}
