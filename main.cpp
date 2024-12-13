#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

class Department {
public:
    string Name;
    vector<int> Students;
    Department(string name)
    {
        Name = name;
        for (int i = 0; i < 10; i++)
        {
            Students.push_back(rand() % (40 + 1));
        }
    }
};

void listUniversity(vector<Department>& uni)
{
    cout << "\t\t\t" << "Up Town University" << endl << endl;;
    for (int i = 0; i < uni.size(); i++)
    {
        cout << "\t\t" << i << ".  " << uni[i].Name << " Department" << endl;
    }
    cout << endl;
}

int main()
{
    srand(int(time(0)));
    
    string input{};
    int depId = -1;

    vector<Department> university{};
    university.push_back(Department("English"));
    university.push_back(Department("Mathematics"));
    university.push_back(Department("Computer Science"));
    university.push_back(Department("Business"));
    university.push_back(Department("Kinesiology"));
    university.push_back(Department("Architecture"));
    university.push_back(Department("Biology"));
    university.push_back(Department("Education"));
    university.push_back(Department("Chemistry"));
    university.push_back(Department("Engineering"));
    
    do
    {
        // list the all the departments
        system("cls");
        listUniversity(university);

        // get user input
        while (true)
        {
            cout << "\t\tPlease pick a department : ";
            cin >> input;
            try
            {
                depId = stoi(input);
                if (depId < 0 || depId > university.size()) throw exception();

                break;
            }
            catch (exception e)
            {
                cout << "\t\tinvalid input" << endl << endl;
            }
        }

        // display horizontal graph
        system("cls");
        cout << "Department" << string(34, ' ') << "Students" << endl << endl;

        for (int i = 0; i < university[depId].Students.size(); i++)
        {
            cout << depId << '0' << i << "  ";
            cout << string(university[depId].Students[i], '*') << string(40 - university[depId].Students[i], ' ') << "  ";
            cout << university[depId].Students[i];
            cout << endl << endl;
        }

        // clear screen
        system("pause");
        system("cls");

        // display vertical graph
        // ---------------------------------------------
        // initalize vertical graph table
        vector<vector<char>> verticalGraph{};
        for (int x = 0; x < 40; x++)
        {
            verticalGraph.push_back(vector<char>());
            for (int y = 0; y < 10; y++)
            {
                if (university[depId].Students[y] > x) verticalGraph[x].push_back('*');
                else verticalGraph[x].push_back(' ');
            }
            verticalGraph[x].push_back('\n');
        }

        // print out number of students
        // char 1
        cout << "Students" << string(8, ' ');
        for (int i = 0; i < 10; i++)
        {
            string s = to_string(university[depId].Students[i]);
            if (s.size() > 1) cout << s[0];
            else cout << " ";
            cout << " ";
        }

        cout << endl;
        cout << string(16, ' ');

        // char 2
        for (int i = 0; i < 10; i++)
        {
            string s = to_string(university[depId].Students[i]);
            if (s.size() > 1) cout << s[1];
            else cout << s[0];

            cout << ' ';
        }

        cout << endl << ' ';

        // print out graph
        for (int x = verticalGraph.size() - 1; x >= 0; x--)
        {
            cout << string(15, ' ');
            for (int y = 0; y < verticalGraph[x].size(); y++)
            {
                //cout << y << endl;

                cout << verticalGraph[x][y];
                cout << ' ';
                //cout << verticalGraph[x][y];
            }
        
        }

        // print out department numbers

        // char 1
        cout << endl;
        cout << "Department" << string(6, ' ');
        for (int i = 0; i < 10; i++)
        {
            cout << depId << " ";
        }

        // char 2
        cout << endl << string(16, ' ');
        for (int i = 0; i < 10; i++)
        {
            cout << "0" << " ";
        }

        // char 3
        cout << endl << string(16, ' ');
        for (int i = 0; i < 10; i++)
        {
            cout << i << " ";
        }

        // ask user if they want to run the program again
        cout << endl << endl;
        cout << "run again (Y/y)? : ";
        cin >> input;
    } while (input == "y" || input == "Y");
}
