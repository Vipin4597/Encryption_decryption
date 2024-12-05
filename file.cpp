#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define endl "\n"
#define vi vector<int>

//Random string generater for noise
const int MAX = 62;
string printRandomString(){
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm',
						   'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z',
						   'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M',
						   'N','O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z',
						   '0', '1', '2', '3', '4', '5', '6','7', '8', '9'};
	string res="";
	srand(time(0));
	for (int i = 0; i < 1000; i++) res = res + alphabet[rand() % MAX];
	return res;
}
//Function for encryption
	string encrypt(string &s){
	vector<char> source{'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm',
					    'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z',
						'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M',
						'N','O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z',
						'!', '@', '#', '$', '%', '^', '&','*', '(', ')', '{', '}', '[',
						']','\\', '|', ';', ':', '\'', ',', '<','.', '>', '?', '/', '~',
						'`',' ','0','1','2','3','4','5','6','7','8','9','-','_','+','='};
	string q1 = "%1";
	string q2 = "%2";
	int n = s.size();
	if(n > 4){
		for (int i = 0; i < s.size()-4; i++){
			if (s[i] == ' ' && s[i+1] == 't' && s[i+2] == 'h' && s[i+3] == 'e' && s[i+4] == ' '){
				s.replace(i+1, 3, q1);
				i-=2;
			}
			if (s[i] == ' ' && s[i+1] == 'a' && s[i+2] == 'n' && s[i+3] == 'd' && s[i+4] == ' '){
				s.replace(i+1, 3, q2);
				i-=2;
			}
		}
	}
	for (int i = 0; i < s.size(); i++){
		auto it = find(source.begin(), source.end(), s[i]);
		s[i] = source[((it - source.begin()) + i) % 94];
	}
	string s1;
	int h = 0;
	s1 = printRandomString();
	for (int i = 0; i < s.size(); i++){
		if (i%2 == 0){
			s.insert(i, s1.substr(h, 1));
			h = (h + 1) % 1000;
		}
	}
	return s;
	//cout<<s;
}

//Function for decryption
string decrypt(string s){
	vector<char> source{'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm',
					    'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z',
						'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M',
						'N','O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z',
						'!', '@', '#', '$', '%', '^', '&','*', '(', ')', '{', '}', '[',
						']','\\', '|', ';', ':', '\'', ',', '<','.', '>', '?', '/', '~',
						'`',' ','0','1','2','3','4','5','6','7','8','9','-','_','+','='};

	for (int i = s.size() - 1; i >= 0; i--){
		if (i % 2 == 0){
			s.erase(i, 1);
		}
	}
	for (int i = 0; i < s.size(); i++){
		auto it = find(source.begin(), source.end(), s[i]);
		int k = (it - (source.begin()) + 94 - i) % 94;
		s[i] = source[k];
	}
	string q1 = "the";
	string q2 = "and";
	int n = s.size();
	if(n > 3){
		for (int i = 0; i < s.size()-3; i++){
			if (s[i] == ' ' && s[i+1] == '%' && s[i+2] == '1' && s[i+3] == ' '){
				s.replace(i+1, 2, q1);
				i-=1;
			}
			if (s[i] == ' ' && s[i+1] == '%' && s[i+2] == '2' && s[i+3] == ' '){
				s.replace(i+1, 2, q2);
				i-=1;
			}
		}
	}
	return s;

}


 void encryptfile(string s)
 {
     string line;
	string encline;

	ifstream fin(s,ios::in);
	ofstream fout("x2.txt");
	if(!fin)
        cout<<"file not found";
    else
    {
        while(fin.eof()==0)
        {
          getline(fin,line);
          encline=encrypt(line);
          fout<<encline<<endl;
        }

        fin.close();
        fout.close();
    }
    ifstream fin2("x2.txt");
    ofstream fout2(s);
    if(!fin2)
        cout<<"file not found";
    else
    {
        while(fin2.eof()==0)
        {
          getline(fin2,line);
          fout2<<line<<endl;
        }

        fin2.close();
        fout2.close();
        cout<<"Encryption successfull"<<endl;
    }
 }


 void decryptfile(string s)
 {
     string line;
	 string encline;
     ifstream fin3(s,ios::in);
	ofstream fout3("x2.txt");
	if(!fin3)
        cout<<"file not found";
    else
    {
        while(fin3.eof()==0)
        {
          getline(fin3,line);
          encline=decrypt(line);
          fout3<<encline<<endl;
        }

        fin3.close();
        fout3.close();
    }
    ifstream fin4("x2.txt");
    ofstream fout4(s);
    if(!fin4)
        cout<<"file not found";
    else
    {
        while(fin4.eof()==0)
        {
          getline(fin4,line);
          fout4<<line<<endl;
        }

        fin4.close();
        fout4.close();
        cout<<"Decryption successful"<<endl;
    }


 }
int main(){

    int ch;
    while(1)
    {
        cout<<"\nChoose any one option";
        cout<<"\n1. Encrypt file";
        cout<<"\n2. Decrypt file";
        cout<<"\n3. Exit\n";
        cin>>ch;

        switch(ch)
        {

        case 1:{
            string filename;
            cout<<"Enter the text file name in .txt format: "; cin>>filename;
            encryptfile(filename);
            break;}
        case 2:{
            string filename;
            cout<<"Enter the text file name in .txt format: "; cin>>filename;
            decryptfile(filename);
            break;}
        case 3:
            exit(0);
        default:{
            cout<<"Invalid choice";
            break;}
        }
    }
	
	return 0;

}