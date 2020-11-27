#include <iostream>
#include <fstream>
#include "cards/table.h"
#include "cards/createClass.h"

using namespace std;
using namespace cards;

// functions
Table setup();
void loop(Table &, string &);
Table load(string &);
void save(string &, Table &);

// save
bool pause = false;

//Card factory
CardFactory *CardFactory::cardFactory;

int main(int argc, char **argv)
{
    //check if a a file was given
    bool load_game = (argc > 0) ? true : false;
    //if file was given use it to load the game
    string save_file = (load_game) ? argv[1] : "saved_game.txt";
    Table table = (load_game) ? load(save_file) : setup();

    //play the game
    loop(table, save_file);
}

//From filename is loads table game. This will throw a CreateClass Exception if the file is corrupted
Table load(string &filename)
{
    CardFactory *cf = CardFactory::getFactory();
    fstream myfile(filename);

    if (myfile.is_open())
    {
        try
        {
            Table table = Table(myfile, cf);
            cout << "==============================" << endl;
            cout << "Loaded game from file '" << filename << "'." << endl;
            cout << "==============================" << endl;
            return table;
        }
        catch (CreateClass &e)
        {
            cout << e.what() << endl;
            cout << "Saved file is corrupted. Unable to load game." << endl;
            return setup();
        }
    }
    else
    {
        cout << "==============================" << endl;
        cout << "Unable to open file: " << filename << endl;
        cout << "==============================" << endl;
        cout << endl;
        return setup();
    }
}

//Saves the game with the specified file name, if the file does not exist one will be created
void save(string &filename, Table &table)
{
    fstream myfile;
    myfile.open(filename, fstream::app);

    if (!myfile)
    {
        cout << "==============================" << endl;
        cout << "Unable to open file: " << filename << endl;
        cout << "Creating file: " << filename << endl;
        cout << "==============================" << endl;
    }

    myfile << table;

    cout << "==============================" << endl;
    cout << "Game has been saved to file: " << filename << endl;
    cout << "==============================" << endl;
}

// sets up all of the variables for the game to take place
Table setup()
{
    //TODO: grab name from user
    // player 1 and player 2
    string name1 = "Patrick";
    string name2 = "Rodger";
    CardFactory *cf = CardFactory::getFactory();
    Table table = Table(name1, name2, cf);

    cout << "==============================" << endl;
    cout << "Creating new game" << endl;
    cout << "==============================" << endl;

    // adds 5 cards to each player's hand
    for (int i = 0; i < 5; i++)
    {
        table.addPlayer(table.draw(), true);
    }

    for (int i = 0; i < 5; i++)
    {
        table.addPlayer(table.draw(), false);
    }

    return table;
}

// main state of the game
void loop(Table &table, string &save_file)
{
    while (!table.isEmpty())
    {
        // random
        bool removeTop = true;
        bool tradeMatch = false;
        string trading;
        string bean;
        int index;

        // save functionality
        // if (pause) {
        //     save()
        // }

        cout << "Here is your starting hand: " << endl;
        table.printHand(table.getTurn());

        // trading phase
        if (table.getTradeArea() != 0)
        {
            // Give option to take cards
            cout << "Would you like to take any cards from the trading table? " << endl;
            cin >> trading;

            if (trading == "yes")
            {
                while (trading == "yes" && table.getTradeArea() != 0)
                {
                    cout << "Choose a card (by suit): " << endl;
                    cin >> bean;

                    // add cards to chain if possible
                    table.addCardToChain(table.tradeCard(bean));

                    cout << "Would you like to take any cards from the trading table? " << endl;
                    cin >> trading;
                }
            }

            // remove the rest of the cards into the discard pile
            table.clearTrade();
        }

        // adding top card phase
        while (removeTop)
        {
            cout << "Your top card is being added to your chains." << endl;
            cout << "" << endl;

            if (!table.addCardToChain(table.discardTopCard()))
            {
                cout << "Please choose a chain to discard: (by index): " << endl;
                cin >> index;

                while (index > 1 || index < 0)
                {
                    cout << "Invalid index. Please choose again." << endl;
                    cin >> index;
                }

                table.sellChain(index);
            }

            removeTop = false;
        }

        // discard phase
        string discard;
        int discard_index;

        cout << "Here is your hand: " << endl;
        table.printHand(table.getTurn());
        cout << "" << endl;

        cout << "Would you like to discard a card? (yes/no)" << endl;
        cin >> discard;
        cout << "" << endl;

        if (discard == "yes")
        {
            cout << "Which card would you like to discard (choose index): " << endl;
            cin >> discard_index;

            table.discardCard(discard_index, table.getTurn());

            cout << "" << endl;
            cout << "Here is your hand after discarding:" << endl;
            table.printHand(table.getTurn());
            cout << "" << endl;
        }

        // trade area phase
        for (int i = 0; i < 3; i++)
        {
            table.addTrade(table.draw());
        }

        table.tradePhase();

        // add cards to chain, optional for player
        cout << "Here is the tradeArea: " << endl;
        table.getTradeArea();
        // print trade area and optional collection!!!

        // Give option to take cards
        cout << "Would you like to take any cards from the trading table? (yes/no)" << endl;
        cin >> trading;
        cout << "" << endl;

        if (trading == "yes")
        {
            while (trading == "yes" && table.getTradeArea() != 0)
            {
                cout << "" << endl;
                cout << "Choose a card (by suit): " << endl;
                cin >> bean;

                // add cards to chain if possible
                if (table.addCardToChain(table.tradeCard(bean)))
                {
                    cout << "Please choose a chain to discard: (by index): " << endl;
                    cin >> index;

                    while (index > 1 || index < 0)
                    {
                        cout << "Invalid index. Please choose again." << endl;
                        cin >> index;
                    }

                    table.sellChain(index);
                }

                cout << "Would you like to take any cards from the trading table? (yes/no)" << endl;
                cin >> trading;
            }
        }

        // draw phase
        for (int i = 0; i < 2; i++)
        {
            table.addPlayer(table.draw(), table.getTurn());
        }

        cout << "Here is your hand at the end of the round:" << endl;
        table.printHand(table.getTurn());

        // this player's turn is over
        cout << "Ready to continue? (yes/no)" << endl;
        cin >> trading;

        while (trading != "yes")
        {
            cout << "Please type yes when you're ready to continue" << endl;
            cin >> trading;
        }
    }
}