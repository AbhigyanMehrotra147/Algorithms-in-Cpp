#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include "Linked_list.h"
using namespace std;
// 15is chosen because it is not too close to an exact power of two
const int hash_table_size = 100000;
class Compound_words
{
private:
    // The original dictionary taken from the user
    vector<string> dictionary;
    int length_of_dictionary = 0;
    // compound_words will contain all the compound words from the dictionary
    vector<string> compound_words;
    int length_of_compound_words = 0;
    // hash_table_size hundred is an arbritrary size
    Node<string> *hash_table[hash_table_size];

public:
    Compound_words(vector<string> dict)
    {
        dictionary = dict;
        length_of_dictionary = dictionary.size();
        for (int i = 0; i < hash_table_size; i += 1)
        {
            hash_table[i] = nullptr;
        }
    }
    /*
    functions returns the ascii value of a word.
    */
    int ascii_word(string word)
    {
        int word_length = word.length();
        int ascii = 0;
        for (int i = 0; i < word_length; i += 1)
        {
            ascii = ascii + word[i];
        }
        return ascii;
    }
    /*
    Generates hash_table key for the specified word
    */
    int generate_key(string word)
    {
        // return ascii_word(word) % hash_table_size;
        hash<string> mystdhash;
        return mystdhash(word) % hash_table_size;
    }
    /*
    assigns a single word to a index in the hash_table;
    */
    void assign_word_to_hashtable(string word)
    {
        int key = generate_key(word);
        if (hash_table[key] == nullptr)
        {
            hash_table[key] = new Node<string>(word);
            return;
        }
        Node<string> *temp = hash_table[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node<string>(word);
        return;
    }
    /*
    Assigns the comple dictionary to the hash_table
    */
    void assign_all_words()
    {
        for (int i = 0; i < length_of_dictionary; i += 1)
        {
            assign_word_to_hashtable(dictionary[i]);
        }
    }
    /*
    Searches if a specified word is there in the dictionary or not
    returns boolean values.
    */
    bool search_if_word_in_hash_table(string word)
    {
        if (word.length() == 0)
        {
            return false;
        }
        int key = generate_key(word);
        Node<string> *temp = hash_table[key];
        while (temp)
        {
            if (temp->data == word)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    /*
    Function checks if a word is a compound word or not
    */
    bool check_if_compound_word(string word)
    {

        int word_length = word.length();
        string first_part = "";
        string second_part = "";
        for (int i = 0; i < word_length - 1; i += 1)
        {
            first_part = word.substr(0, i + 1);
            second_part = word.substr(i + 1, word_length - (i + 1));
            if (search_if_word_in_hash_table(first_part) && search_if_word_in_hash_table(second_part))
            {
                return true;
            }
        }
        return false;
    }
    /*
    creates a vector of compound words
    */
    void create_vector_compound_words()
    {
        for (int i = 0; i < length_of_dictionary; i += 1)
        {
            if (check_if_compound_word(dictionary[i]))
            {
                compound_words.push_back(dictionary[i]);
            }
        }

        return;
    }
    /*
    prints the vector of compound words
    */
    void print_compound_words()
    {
        length_of_compound_words = compound_words.size();
        /* for (int i = 0; i < length_of_compound_words; i += 1)
        {
            cout << compound_words[i] << endl;
        }*/
        // cout << length_of_dictionary << endl;
        cout << length_of_compound_words << endl;
    }
};
int main()
{
    // fstream fin("C:/Users/Abhigyan/Desktop/CPP/dictionary.txt");
    string words;
    vector<string> dictionary;
    while (cin >> words)
    {
        dictionary.push_back(words);
    }
    Compound_words CW(dictionary);
    CW.assign_all_words();
    // cout << CW.search_if_word_in_hash_table("al") << endl;
    // cout << CW.search_if_word_in_hash_table("zymologic") << endl;
    CW.create_vector_compound_words();
    CW.print_compound_words();
    return 0;
}
