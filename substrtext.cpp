    #include <iostream>
    #include <string>
    /* run this program using the console pauser or add your own getch, system("pause") or input loop */
    using namespace std;
    int main(int argc, char** argv) {
        string str="The current page will delete.";
        cout <<str.substr(2)<<endl;
        cout <<str.substr(str.find("c",0))<<endl;
        cin.get();
        return 0;
    }
