#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hmm.h"

using namespace std;

typedef struct {
    string name;
    int phone_num;
    hmmType* phone_hmm;
} wordType;

vector<wordType> words;

void read_dictionary();

int main()
{

    read_dictionary();

}

void read_dictionary()
{
    ifstream dic("../dictionary.txt");
    if(dic.is_open())
    {
        string line;
        int phone_size = 21;
        while(getline (dic,line))
        {
            int t = line.find('\t');
            string word_name = line.substr(0, t);
            cout << "word : "<< word_name << endl;
            string phone_name = line.substr(t+1);
            int phone_num = 0;
            hmmType* h = new hmmType[6];

            string temp = "" ;
            for(string::iterator it = phone_name.begin(); it != phone_name.end(); ++it)
            {
                if(*it == ' ' || *it == '\n' || *it == '\r' || *it == '\r\n')
                {
                    for(int i = 0; i < 21; i++)
                    {
                        if(temp == phones[i].name)
                        {
                            h[phone_num] = phones[i];
                            phone_num++;
                            cout << phones[i].name << " ";
                            temp.clear();
                        }
                    }
                }
                else temp = temp + *it;
            }
            wordType w ={
                word_name,
                phone_num,
                h
            };
            words.push_back(w);
            cout << endl;
        }
        dic.close();
    }
    else
    {
        cout << "dictionary not opened!" << endl;
        exit(-1);
    }
}

void construct_utterance_HMM()
{
    ifstream uni("../dictionary.txt");
    if(uni.is_open())
    {
        string line;
        while(getline (uni,line))
        {

        }
    }
}