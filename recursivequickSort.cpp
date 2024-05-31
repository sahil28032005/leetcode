#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int partition(vector<int> &arr, int start, int end)
{

    int select = arr[start], count = 0, i = start, j = end;
    // cout << "select" << arr[start] << endl;
    // cout << "start" << start << endl;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < select)
        {
            count += 1;
        }
    }
    // cout << "count = " << count << endl;
    swap(arr[start], arr[count + start]);

    for (int k = start; k <= end; k++)
    {
        for (int f = i; f < start + count; f++)
        {
            if (arr[f] < select)
            {
                i++;
                continue;
            }
            break;
        }
        for (int f = j; f > start + count; f--)
        {
            if (arr[f] > select)
            {
                j--;
                continue;
            }
            break;
        }
        // while (arr[i] < select && i < (start + count))
        // {
        //     i++;
        // }
        // while (arr[j] > select && j > (start + count))
        // {
        //     j--;
        // }
        cout << endl;
        if ((i) < (start + count) && (j) > (start + count))
        {
            swap(arr[i], arr[j]);
            continue;
        }
        else
        {
            break;
        }
    }
    return (start + count);
}
void quickSortHelper(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int partitionNumber = partition(arr, start, end);

    // cout << "no" << partitionNumber << endl;
    quickSortHelper(arr, start, partitionNumber - 1);
    quickSortHelper(arr, partitionNumber + 1, end); // ethun gela (3 ala partition houn)
}
vector<int> quickSort(vector<int> arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = quickSort(arr);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
