#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
#include <climits>
using namespace std;
class person // when turn on virtual function then don't create person object.
{
    char password[20];
    char firstname[20];
    char lastname[20];
    long int phonenumber;

public:
    // virtual void virtualFunction()=0;
    friend istream &operator>>(istream &din, person &stu);
    friend ofstream &operator<<(ofstream &dout, person stu);
    friend ifstream &operator>>(ifstream &fin, person &stu);
};
class ECE : public person
{

public:
    void virtualFunction() {};
};
class CSE : public person
{

public:
    void virtualfunction() {};
};
class BBA : public person
{

public:
    void virtualFunction() {};
};
class TECHERS : public person
{

public:
    void virtualFunction() {};
};
istream &operator>>(istream &din, person &stu)
{
    cout << "enter password : ";
    cin >> stu.password;
    cout << "enter first name : ";
    cin >> stu.firstname;
    cout << "enter last name : ";
    cin >> stu.lastname;
    cout << "enter mobile number : ";
    din >> stu.phonenumber;
    return din;
}

ofstream &operator<<(ofstream &dout, person stu)
{
    dout << endl;
    dout << stu.password << " ";
    dout << stu.firstname << " ";
    dout << stu.lastname << " ";
    dout << stu.phonenumber << endl;
    return dout;
}

bool check(int roll)
{
    ifstream fin;
    fin.open("first.txt");
    int r;
    fin >> r;
    while (!fin.eof())
    {
        if (r == roll)
        {
            return true;
        }
        string nam;
        getline(fin, nam);
        string na;
        getline(fin, na);
        fin >> r;
    }
    fin.close();
    return false;
}
void addMember()
{
    ofstream fout;
    fout.open("first.txt", ios::app);
    map<int, person> ece;
    int roll = 1;
    while (roll != 0)
    {
    ROLL:
        cout << "enter roll :";
        cin >> roll;
        if (roll == 0)
            break;
        if (check(roll))
        {
            cout << "This roll is not available.\nplease try again." << endl;
            goto ROLL;
        }
        cin >> ece[roll];
        cout << "\nfor end enter roll = 0. " << endl;
    }
    for (auto &p : ece)
    {
        fout << p.first << " ";
        fout << p.second;
    }
}

void findMember()
{
    ifstream fin;
    fin.open("first.txt");
    bool checkFind = false;
    int n;
    cout << "enter roll: ";
    cin >> n;
    int x;
    fin >> x;
    int trypass = 0;
    string passw;
    fin >> passw;
    while (!fin.eof())
    {

        string fulln;
        getline(fin, fulln);
        if (n == x)
        {
            checkFind = true;
        PAS:
            string pas;
            cout << "enter your password :";
            cin >> pas;
            if (pas == passw)
            {
                cout << x << " " << passw << " " << fulln;
                break;
            }
            else
            {
                if (trypass == 3)
                    break;
                cout << "wrong password." << endl
                     << "please try again .";
                trypass++;
                goto PAS;
            }
        }
        fin >> x;
        fin >> passw;
    }
    if (checkFind == false)
        cout << "not found.";

    fin.close();
}
int main()
{
    ifstream fin;
    fin.open("first.txt"); // auto open/create.

    cout << "\t\t\t\t\t"
         << "STUDENT DATA " << endl
         << endl;
    int call;
T:
    cout << "write :" << endl;
    cout << "\t\t type 1 = add new member." << endl;
    cout << "\t\t type 2 =find member. " << endl;
    cout << "\t\t type 0 = end." << endl;
    cout << "enter your chosse: ";
    cin >> call;
    switch (call)
    {
    case 1:
    {
        addMember();
        break;
    }
    case 2:
    {
        findMember();
        break;
    }
    case 0:
    {
        break;
    }
    default:
    {
        cout << "wrong input." << endl;
        goto T;
    }
    }
    fin.close();
    return 0;
}