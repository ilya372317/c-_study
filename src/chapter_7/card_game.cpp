//
// Created by ilya on 04.10.22.
//

#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace std;

enum Suit {clubs, diamonds, hearts, spades};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
const int CARD_ON_HAND = 13;

class Card {
private:
    int number;
    Suit suit;
public:
    void set(int n, Suit s) {
        suit = s;
        number = n;
    }

    void display();
};

void Card::display() {
    if (number >= 2 && number <= 10) {
        cout << number;
    } else {
        switch (number) {
            case jack:
                cout << "J";
                break;
            case queen:
                cout << "Q";
                break;
            case king:
                cout << "K";
                break;
            case ace:
                cout << "A";
                break;
        }
    }

    switch (suit) {
        case clubs:
            cout << '#';
            break;
        case diamonds:
            cout << '$';
            break;
        case hearts:
            cout << '^';
            break;
        case spades:
            cout << '*';
            break;
    }
}

void displayDeck(Card deck[]);

int main() {
    Card deck[52];
    int j;

    cout << endl;

    for (j = 0; j < 52; j++) {
        int num = (j % 13) + 2;
        Suit suit = Suit(j/13);
        deck[j].set(num, suit);
    }

    cout << "Start deck: " << endl;
    for (j = 0; j < 52; j++) {
        deck[j].display();
        cout << " ";
        if (!((j+1) % 13)) {
            cout << endl;
        }
    }
    srand(time(NULL));
    for (j = 0; j < 52; j++) {
        int k = rand() % 52;
        Card temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }

    cout << "Flip deck: " << endl;
    displayDeck(deck);

    cout << "Slice on four piece: " << endl;

    Card firstDeck[CARD_ON_HAND], secondDeck[CARD_ON_HAND], thirdDeck[CARD_ON_HAND], fourDeck[CARD_ON_HAND];

    for(int i = 0, k = 0; i < 13; i++, k++) {
        firstDeck[i] = deck[i];
    }

    for (int i = 13, k = 0; i < 26; i++, k++) {
        secondDeck[k] = deck[i];
    }

    for (int i = 26, k = 0; i < 39; i++, k++) {
        thirdDeck[k] = deck[i];
    }

    for (int i = 39, k = 0; i < 52; i++, k++) {
        fourDeck[k] = deck[i];
    }

    cout << "First deck: " << endl;
    displayDeck(firstDeck);

    cout << endl << "Second deck: " << endl;
    displayDeck(secondDeck);

    cout << endl << "Third deck: " << endl;
    displayDeck(thirdDeck);

    cout << endl << "Four deck: " << endl;
    displayDeck(fourDeck);
    return 0;
}

void displayDeck(Card deck[]) {
    for (int i = 0; i < 13; i++) {
        deck[i].display();
        cout << " ";
        if (!((i + 1) % 13)) {
            cout << endl;
        }
    }
}