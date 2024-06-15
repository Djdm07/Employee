#include <bits/stdc++.h>
#include<stdlib.h>
#define max 20
using namespace std;

// Structure of Employee
struct employee
{
    string name;
    long int code;
    string designation;
    int exp;
    int age;
};

int num;
void showMenu();

// Array of Employees to store the
// data in the form of the Structure
// of the Array
employee emp[max], tempemp[max],
         sortemp[max], sortemp1[max];

// Function to build the given datatype
void build()
{
    int flag = 0;
    cout << "Build The Table\n";
    cout << "Maximum Entries can be "
         << max << "\n";

    cout << "Enter the number of "
         << "Entries required ";
    cin >> num;
    system("CLS");

    if (num > 20)
    {
        cout << "Maximum number of "
             << "Entries are 20\n";
        num = 20;
    }
    cout << "Enter the following data:\n";

    for (int i = 0; i < num; i++)
    {
        cout << "Name ";

        cin.ignore();
        getline(cin, emp[i].name);

        cout << "Employee ID ";
        cin >> emp[i].code;
        for(int j=0; j<i; j++)
        {
            if(emp[i].code==emp[j].code)
            {
                flag = 5;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if(flag==5)
        {
            cout<<" sorry id have been used "<<endl;
            emp[i].name='0';
            emp[i].code=0;
        }
        else
        {
            cout << "Designation ";
            cin.ignore();
            getline(cin, emp[i].designation);

            cout << "Experience years ";
            cin >> emp[i].exp;

            cout << "Age ";
            cin >> emp[i].age;
        }

    }
    system("CLS");

    showMenu();
}

// Function to insert the data into
// given data type
void insert()
{
    if (num < max)
    {
        int i = num, flag =0;
        num++;

        cout << "Enter the information "
             << "of the Employee\n";
        cout << "Name ";
        cin.ignore();
        getline(cin, emp[i].name);

        cout << "Employee ID ";
        cin >> emp[i].code;
        for(int j=0; j<i; j++)
        {
            if(emp[i].code==emp[j].code)
            {
                flag = 5;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if(flag==5)
        {
            cout<<"sorry id have been used "<<endl;
            emp[i].name='0';
            emp[i].code=0;
        }
        else
        {
            cout << "Designation ";
            cin.ignore();
            getline(cin, emp[i].designation);

            cout << "Experience years ";
            cin >> emp[i].exp;

            cout << "Age ";
            cin >> emp[i].age;
        }
    }
    else
    {
        cout << "Employee Table Full\n";
    }


    showMenu();
}

// Function to delete record at index i
void deleteIndex(int i)
{
    for (int j = i; j < num - 1; j++)
    {
        emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].designation
            = emp[j + 1].designation;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;
    }
    return;
}

// Function to delete record
void deleteRecord()
{
    cout << "Enter the Employee ID "
         << "to Delete Record ";

    int code;

    cin >> code;
    for (int i = 0; i < num; i++)
    {
        if (emp[i].code == code)
        {
            deleteIndex(i);
            num--;
            break;
        }
    }
    system("CLS");
    showMenu();
}

void searchRecord()
{
    cout << "Enter the Employee"
         << " ID to Search Record ";

    int code;
    cin >> code;

    for (int i = 0; i < num; i++)
    {

        // If the data is found
        if (emp[i].code == code)
        {
            cout << "Name "
                 << emp[i].name << "\n";

            cout << "Employee ID "
                 << emp[i].code << "\n";

            cout << "Designation "
                 << emp[i].designation << "\n";

            cout << "Experience "
                 << emp[i].exp << "\n";

            cout << "Age "
                 << emp[i].age << "\n";
            break;
        }
    }


    showMenu();
}
void showall()
{
    int i;
    for(i=0; i<num; i++)
    {
        cout << "Name "
             << emp[i].name << "\n";

        cout << "Employee ID "
             << emp[i].code << "\n";

        cout << "Designation "
             << emp[i].designation << "\n";

        cout << "Experience "
             << emp[i].exp << "\n";

        cout << "Age "
             << emp[i].age << "\n";
    }
    cout<<endl;

    showMenu();
}
void edit()
{
    cout << "Enter the Employee"
         << " ID to Search Record ";

    int code,flag=0;
    cin >> code;

    for (int i = 0; i < num; i++)
    {

        // If the data is found
        if (emp[i].code == code)
        {
            cout << "Name ";
            cin.ignore();
            getline(cin, emp[i].name);

            cout << "Employee ID ";
            cin >> emp[i].code;

            for(int j=0; j<i; j++)
            {
                if(emp[i].code==emp[j].code)
                {
                    flag = 5;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            if(flag==5)
            {
                cout<<"sorry id have been used "<<endl;
                emp[i].name='0';
                emp[i].code=0;
            }
            else
            {
                cout << "Designation ";
                cin.ignore();
                getline(cin, emp[i].designation);

                cout << "Experience years ";
                cin >> emp[i].exp;

                cout << "Age ";
                cin >> emp[i].age;
            }
            break;
        }
    }


    showMenu();
}
// Function to show menu
void showMenu()
{

    cout << "-------------------------"
         << " Employee"
         << " Management System"
         << "-------------------------\n\n";

    cout << "Available Options:\n\n";
    cout << "Build Table         (1)\n";
    cout << "Insert New Entry    (2)\n";
    cout << "Delete Entry        (3)\n";
    cout << "Search a Record     (4)\n";
    cout << "Edit a Record       (5)\n";
    cout << "Show all record     (6)\n";
    cout << "Exit                (7)\n";

    int option;

    // Input Options
    cin >> option;
    system("CLS");

    // Call function on the basis of the
    // above option
    if (option == 1)
    {
        build();
    }
    else if (option == 2)
    {
        insert();
    }
    else if (option == 3)
    {
        deleteRecord();
    }
    else if (option == 4)
    {
        searchRecord();
    }
    else if (option == 5)
    {
        edit();
    }
    else if (option == 6)
    {
        showall();
    }

    else if (option == 7)
    {
        return;
    }
    else
    {
        cout << "Expected Options"
             << " are 1/2/3/4/5/6";
        showMenu();
    }
}

//main code
int main()
{

    showMenu();

    return 0;
}


