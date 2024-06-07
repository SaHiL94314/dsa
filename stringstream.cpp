string replaceWords(vector<string> &dictionary,string sentence){

    stringstream ss(sentence);
    string word;

    while(getline(ss,word,' ')){
        cout<<word<<endl;
    }
}