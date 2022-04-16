#include <bits/stdc++.h>
using namespace std;

int page_size;
int no_of_pages = 0;

struct page
{
    int n = 0;
    int space;
    vector<int> a;
    page *next;
    page *previous;
    page(int size)
    {
        space = size;
    }
};

int main()
{
    cin >> page_size;
    page_size -= 16;
    page *head = nullptr;
    while (1)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            int size, key;
            cin >> size >> key;
            if (head == nullptr)
            {
                head = new page(page_size);
                no_of_pages += 1;
                head->previous = nullptr;
                head->next = nullptr;
            }

            int inserted = 0;

            if (inserted != 1)
            {
                page *temp3 = head;
                while (temp3 != nullptr)
                {
                    if (temp3->space >= size + 4)
                    {
                        temp3->a.push_back(key);
                        temp3->space = temp3->space - (size + 4);
                        inserted = 1;
                    }
                    if (inserted == 1)
                    {
                        break;
                    }
                    else
                    {
                        temp3 = temp3->next;
                    }
                }
            }

            if (inserted != 1)
            {
                page *k;
                k = new page(page_size);
                no_of_pages += 1;
                page *temp = head;
                k->a.push_back(key);
                k->space = k->space - (size + 4);
                k->n += 1;
                k->next = nullptr;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = k;
                k->previous = temp;
            }
        }

        else if (n == 2)
        {
            cout << no_of_pages << " ";
            page *temp2 = head;
            if (head == nullptr)
            {
                cout << endl;
                continue;
            }
            else
            {
                while (temp2 != nullptr)
                {
                    cout << temp2->a.size() << " ";
                    temp2 = temp2->next;
                }
            }
            cout << endl;
        }

        else if (n == 3)
        {
            int k;
            cin >> k;
            page *temp1 = head;
            if (temp1 == nullptr)
            {
                cout << "empty file"
                     << " ";
            }

            int n = 0, found = 0;
            while (temp1 != nullptr)
            {
                if (count(temp1->a.begin(), temp1->a.end(), k))
                {
                    cout << n << " " << count(temp1->a.begin(), temp1->a.end(), k);
                    found = 1;
                }
                temp1 = temp1->next;
                n++;
            }
            if (found != 1)
            {
                cout << -1 << " " << -1;
            }
            cout << endl;
        }

        else
            break;
    }
}