#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Browser
{
    stack<string> backStack, forwardStack;
    string currentPage = "Home";

public:
    void visit(const string &url)
    {
        backStack.push(currentPage);
        currentPage = url;

        // Clear forward history
        while (forwardStack.empty() == false)
            forwardStack.pop();

        cout << "Visited: " << currentPage << endl;
    }

    void back()
    {
        if (backStack.empty() == true)
        {
            cout << "No previous page.\n";
            return;
        }

        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();

        cout << "Back to: " << currentPage << endl;
    }

    void forward()
    {
        if (forwardStack.empty() == true)
        {
            cout << "No forward page.\n";
            return;
        }

        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();

        cout << "Forward to: " << currentPage << endl;
    }

    void showCurrent()
    {
        cout << "Current Page: " << currentPage << endl;
    }

    void showHistory()
    {
        cout << "\nBack Stack: ";
        if (backStack.empty() == true)
            cout << "(empty)";
        else
        {
            stack<string> temp = backStack;
            while (temp.empty() == false)
            {
                cout << temp.top() << " ";
                temp.pop();
            }
        }

        cout << "\nForward Stack: ";
        if (forwardStack.empty() == true)
            cout << "(empty)";
        else
        {
            stack<string> temp = forwardStack;
            while (temp.empty() == false)
            {
                cout << temp.top() << " ";
                temp.pop();
            }
        }
        cout << "\n";
    }
};

int main()
{
    Browser b;
    int ch;
    string url;

    while (true)
    {
        cout << "\n1.Visit 2.Back 3.Forward 4.Current 5.History 0.Exit\nChoice: ";
        cin >> ch;

        if (ch == 0)
            break;

        switch (ch)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            b.visit(url);
            break;
        case 2:
            b.back();
            break;
        case 3:
            b.forward();
            break;
        case 4:
            b.showCurrent();
            break;
        case 5:
            b.showHistory();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}



