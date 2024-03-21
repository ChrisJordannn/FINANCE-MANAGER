#include <iostream>
#include <vector>
#include<iomanip>
#include<numeric>
#include<list>
#include<array>
#include<fstream>
using namespace std;
float income, debt, loan,tot2=0;
int choice1, count3=0, count4=0;
char choice2, choice5, choice6;
double Finrepincome;
void ExpenseTracking();
void Budgeting();
void IncomeTracking();
void FinancialReport();
void saveExpenses(const vector<double>& expenses);
void saveIncomes(const list<pair<string, double>>& incomes);
void saveFinancialReport(const array<int, 7>& Financial_rep);
void displayTotalExpenses(const vector<double>& expenses) {
    double total = 0.0;
    for (double expense : expenses) {
        total += expense;
    }

    cout << fixed << setprecision(2);
    cout << "Total Expenses: " << total << endl;
}
void ExpenseTracking() {
    static vector<double> expenses;
    do{
        cout << "1. Add Expense\n";
        cout << "2. View Total Expenses\n";
        cout << "3. Save contents to file\n";
        cout << "Enter your choice: ";
        cin >> choice1;
        switch (choice1) {
            case 1: {
                cout << "Enter expense amount:\t";
                double expense;
                cin >> expense;
                expenses.push_back(expense);
                cout << "Expense added successfully!\n";
                break;
            }
            case 2:
                if (expenses.empty()) {
                    cout << "No expenses added yet.\n";
                } else {
                    displayTotalExpenses(expenses);
                }
                break;
            case 3:
                if (expenses.empty()) {
                    cout << "No expenses to save.\n";
                } else {
                    saveExpenses(expenses);
                }
                break;
            default:
                cout << "Invalid choice!";
        }
        cout << "\n------------------------\n";
        cout<< " Do you wish to add/ view your expenses? (Y/N)"<<endl;
        cin>>choice2;
    }while(choice2 =='Y' || choice2 =='y');
}
void saveExpenses(const vector<double>& expenses) {
    ofstream outputFile("FinanceDocument.txt", ios::app); // Open the file in append mode
    double i=0;
    outputFile<<"EXPENSE TRACKING\n";
    if (outputFile.is_open()) {
        for (double expense : expenses) {
            outputFile << expense << "\n";
            i+=expense;
        }
    outputFile<<"TOTAL:\t"<< i <<endl;
    outputFile<<"-----------------------------------------------------------------------\n";
        cout << "Expenses saved to file successfully!\n";
        outputFile.close();
    } else {
        cout << "Error opening file for writing!\n";
    }
}
void Budgeting() {
    vector<double> incomes;
    vector<double> expenses;
    double income, expense;
    char addmore;
    do {
        cout << "Enter income amount:\t";
        cin >> income;
        incomes.push_back(income);

        cout << "Enter expense amount:\t";
        cin >> expense;
        expenses.push_back(expense);

        cout << "Do you want to add more income or expenses? (Y/N): ";
        cin >> addmore;
    } while (addmore == 'Y' || addmore == 'y');

    double totalIncome = accumulate(incomes.begin(), incomes.end(), 0.0);
    double totalExpense = accumulate(expenses.begin(), expenses.end(), 0.0);
    double budget = totalIncome - totalExpense;
    cout << "\nBudget Summary\n";
    cout << "------------------------\n";
    cout << "Total Income:\t" << totalIncome << endl;
    cout << "Total Expenses:\t" << totalExpense << endl;
    cout << "------------------------\n";
    cout << "Budget: $" << budget << endl;
    if (budget > 0) {
        cout << "You have a surplus. Good job!\n";
    } else if (budget < 0) {
        cout << "Warning: You have a deficit. Adjust your expenses.\n";
    } else {
        cout << "Your budget is balanced. Keep it up!\n";
    }
}  
void IncomeTracking() {
    static list<pair<string, double>> Incomes;
    long double tax1;
    do{
    count3++;
    string a; double b;
    cout<< " enter your source of income number: "<< count3 <<endl;
    cin>> a;
     cout<< " enter your income/ revenue from source: " << count3<<endl;
    cin>> b;
    Incomes.push_back({a,b});
    cout<< "do you want to add more? (Y/N)"<<endl;
    cin>>choice5;
    }while(choice5=='Y' || choice5 == 'y');
    cout <<"                                        INCOME CHART                                        " << endl;
    cout << setw(5)<<"\tS.no.\t   " <<setw(30)<< "INCOME SOURCE\t\t\t"<<setw(20) << "INCOME AFTER TAX DEDUCTION\n";
    //cout << setw(10) << "S.no." << setw(35) << "Income source" << setw(35) << "Income after tax deduction\n";
    for (const auto& income : Incomes) {
        count4++;
        if (income.second > 1000000 || income.second == 1000000) {
            tax1 = income.second - (12500 + ((income.second - 500000) * 0.10));
        }
        else if ((income.second > 500000) && (income.second < 1000000)){
            tax1 = income.second - ((income.second - 250000) * 0.05);
        }
        else{
            tax1= income.second;
        }
        cout << setw(10) << count4 << setw(35) << income.first << setw(35) <<  fixed << setprecision(2)<< tax1 << endl;
    }
    saveIncomes(Incomes);
}
void saveIncomes(const list<pair<string, double>>& incomes) {
    ofstream outputFile("FinanceDocument.txt", ios::app); // Open the file in append mode

    if (outputFile.is_open()) {
        outputFile<< "INCOME TRACKING\n";
        int sno=1;
        double tot1=0.0;
        for (const auto& income : incomes) {
            outputFile<<sno<<"  " << income.first << " :" << income.second << "\n";
            tot1+=income.second;
            sno++;
        }
        outputFile<< "TOTAL:\t" << tot1<<endl;
        outputFile<<"-----------------------------------------------------------------------\n";
        cout << "Income data saved to file successfully!\n";
        outputFile.close();
    } else {
        cout << "Error opening file for writing!\n";
    }
}
void FinancialReport() {
    const int s = 7;
    cout<< " Enter your total income\n";
    cin>>Finrepincome;
    array <int, s> Financial_rep;
    cout<< " Enter your Rent/ mortgage amount, if any\n";
    cin>> Financial_rep[0];
    cout<< " Enter your Utilities expense\n";
    cin>> Financial_rep[1];
    cout<< " Enter your Interest/ EMI amount, if any\n";
    cin>> Financial_rep[2];
    cout<< " Enter your Electricity expenditure\n";
    cin>> Financial_rep[3];
    cout<< " Enter your Gasoline expense\n";
    cin>> Financial_rep[4];
    cout<< " Enter Miscallaneous, if any\n";
    cin>> Financial_rep[5];
    // Calculate total expenses
    int totalExpenses = accumulate(Financial_rep.begin(), Financial_rep.end()-1, 0);
    // Calculate savings
    double savings = Finrepincome - totalExpenses;

    Financial_rep[6]= savings;
    cout<< "---------------------------------------"<<endl;
    cout<< "             FINANCIAL REPORT          "<<endl;
    cout<< "---------------------------------------"<<endl;
    cout<<"Rent:\t\t"<<Financial_rep[0]<<endl;
    cout<<"Utilities:\t"<<Financial_rep[1]<<endl;
    cout<<"Loan/ EMIs:\t"<<Financial_rep[2]<<endl;
    cout<<"Electricity:\t"<<Financial_rep[3]<<endl;
    cout<<"Gasoline:\t"<<Financial_rep[4]<<endl;
    cout<<"Miscallenous:\t"<<Financial_rep[5]<<endl;
    cout<<"Savings:\t"<<Financial_rep[6]<<endl;
    if(Financial_rep[6] >0 ){
        cout<< "You have surplus for the month!!, and "<<(Finrepincome -  totalExpenses)<< " rupees is your total expenditure"<<endl;
    }
    else if (Financial_rep[6]==0){
        cout<< "You have the perfect amount for the month!!, but you have 0 rupees in your Financial savings"<<endl;
    }
    else{
        cout<<"Oops!! you fell short by "<< abs((Finrepincome - totalExpenses)) << " amount"<<endl;
    }
    saveFinancialReport(Financial_rep);
}
void saveFinancialReport(const array<int, 7>& Financial_rep) {
    ofstream outputFile("FinanceDocument.txt", ios::app); // Open the file in append mode

    if (outputFile.is_open()) {
        for (const auto& finrep : Financial_rep) {
            tot2+=finrep;
        }
        outputFile<< "FINANCIAL REPORT\n "<<endl;
        outputFile<< "BALANCE BEFORE EXPENDITURE:\t"<<tot2<<endl;
        outputFile << "Rent: " << Financial_rep[0] << "\n";
        outputFile << "Utilities: " << Financial_rep[1] << "\n";
        outputFile << "Loan/EMIs: " << Financial_rep[2] << "\n";
        outputFile << "Electricity: " <<Financial_rep[3] << "\n";
        outputFile << "Gasoline: " << Financial_rep[4] << "\n";
        outputFile << "Miscellaneous: " << Financial_rep[5] << "\n";
        outputFile << "Savings: " << Financial_rep[6] << "\n\n";
        outputFile<<"-----------------------------------------------------------------------\n";
        cout << "Financial report saved to file successfully!\n";
        outputFile.close();
    } else {
        cout << "Error opening file for writing!\n";
    }
}
int main() {
    int choice;
    cout << "============================" << endl;
    cout << "       FINANCE MANAGER      " << endl;
    cout << "============================" << endl;
    cout << endl;
    do {
        const string a[4] = {"1. Expense Tracking", "2. Budgeting", "3. Income Tracking", "4. Financial Report"};
        for (auto i : a) {
            cout << i << endl;
        }
        cout << "Enter which operation to perform: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                ExpenseTracking();
                break;
            }
            case 2: {
                Budgeting();
                break;
            }
            case 3: {
                IncomeTracking();
                break;
            }
            case 4: {
                FinancialReport();
                break;
            }
            default: {
                cout << "Invalid entry\n";
            }
        }
        
        cout << "Do you want to continue with Finanace Manager (Y/N)? ";
        cin >> choice6;
    } while (choice6 == 'Y' || choice6 == 'y');
    return 0;
}
