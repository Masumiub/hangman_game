#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int hidden_word_fillup(char guess, string hidden_word, string &guess_word)
{
    int i;
    int count=0;

    for (i = 0; i< hidden_word.length(); i++)
    {
        if (guess == guess_word[i])
        return 0;

        if (guess == hidden_word[i])
        {
        guess_word[i] = guess;
        count++;
        }
    }
    return count;
}

int main ()
{

    string words[] ={"award", "await", "attend", "bubble", "coding", "spring", "mango", "night", "orange", "reward"};
    char letter;
    string word;
    int wrong_guesses=0;


    srand(time(NULL));
    int n=rand()% 10;
    word=words[n];

    int guessing_limit=word.length()+2;

    string hidden_word(word.length(),'_');


 for(int i=0; i<=guessing_limit; i++)
 {
    cout << hidden_word<< endl;
    cout << "Guess a letter: "<<endl;
    cin >> letter;

        if(hidden_word_fillup(letter, word, hidden_word)==0)
            {
                cout <<"Sorry! That letter isn't in the word!" << endl;
                wrong_guesses++;
            }
        else
            {
            cout << "Correct Word Guess. Go forward!" << endl;
            }

        if(word==hidden_word)
            {
            cout << word << endl;
            cout << "Congrats! Correct Guess!";
            break;
            }
       
        if(wrong_guesses==guessing_limit)
        {
            cout << "Sorry, you lose this hangman game!" << endl;
            cout << "The word was =" << word << endl;
            break;
        }
}

 return 0;
}



