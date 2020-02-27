# include <fstream>
# include <algorithm>
# include <vector>
# include <iomanip>
using namespace std;


long maximum_area(const int & m, const int & n, vector <int> & h, vector <int> & v)
{
    int h_size = h.size();
    int v_size = v.size();

    long h_max_size = 1;
    long v_max_size = 1;


    ////////////////////////////////////////
    // In this code, we will treat h and v separately
    // then, multiply the h_maximum_size and v_maximum_size to get the largest hole area

    // check if there are any adjacent or consecutiove bars being removed :
    // if 0 horizontal / vertical bar being removed, maximum horizontal / vertical area is 1
    // if 1 horizontal / vertical bar being removed, maximum horizontal / vertical area is 2
    // if 2 horizontal / vertical neighboring bars being removes, maximum horizontal / vertical area is 3
    // if 3 horizontal / vertical neighbouring bars being removed, maximum horizontal / vertical area is 4
    // ........... and so on so forth .......
    ///////////////////////////////////////

    sort(h.begin(), h.end()); // sort h in ascending order
    sort(v.begin(), v.end()); // sort v in ascending order


    ////////////////////////////
    // process vector h first
    ////////////////////////////

    if (h_size == 0)
        h_max_size = 1;         // if 0 horizontal bar being removed, maximum horizontal area is 1
    else if (h_size == 1)
        h_max_size = 2;         // if only 1 horizontal bar being removed, maximum horizontal area is 2
    else if (h_size >= 2)
    {
        for (int i = 0; i < h_size - 1; i++) // starts from i = 0, iterates up to h_size - 1
        {
            // if 2 horizontal bars being removed, the horizontal area is at least 2
            // if they are nor neighbours
            long h_temp_size = 2;
            for (int j = i; j < h_size; j++) // starts from j = i, iterates up to h_size
            {
                if (h[j + 1] - h[j] == 1)    // check if there are any consecutive horizontal bars being removed
                    h_temp_size += 1;        // if yes, increases the horizontal area by 1
                else
                    break;                   // if no more consecutive horizontal bars detected, quit the inner for-loop
            };

            if (h_temp_size > h_max_size)
                h_max_size = h_temp_size;    // update the h_max_size if found area larger than it
        }
    };


    ////////////////////////////
    // process vector v next
    ////////////////////////////

    if (v_size == 0)
        v_max_size = 1;         // if 0 vertical bar being removed, maximum vertical area is 1
    else if (v_size == 1)
        v_max_size = 2;         // if 1 vertical bar being removed, maximum vertical area is 1
    else if (v_size >= 2)
    {
        for (int i = 0; i < v_size - 1; i++) // starts from i = 0, iterates up to v_size - 1
        {
            // if 2 vertical bars being removed, the vertical area is at least 2
            // if they are nor neighbours
            long v_temp_size = 2;
            for (int j = i; j < v_size; j++) // starts from j = i, iterates up to v_size
            {
                if (v[j + 1] - v[j] == 1)    // check if there are any consecutive vertical bars being removed
                    v_temp_size += 1;        // if yes, increases the vertical area by 1
                else
                    break;                   // if no more consecutive vertical bars detected, quit the inner for-loop
            };

            if (v_temp_size > v_max_size)
                v_max_size = v_temp_size;    // update the v_max_size if found area larger than it
        }
    };

    // get the multiplication of the maximum horizontal area and maximum vertical area
    return h_max_size * v_max_size;
}

int main()
{
    ifstream input;
    input.open("Input.txt"); // to provide the input

    ofstream output;
    output.open("Output.txt"); // to give the output

    int test_case_number;
    int m, n;               // m vertical bars, n horizontal bars
    vector <int> h;
    vector <int> v;
    int h_size, v_size;     // size of vector h and vector v


    input >> test_case_number; // the first line in "Input.txt" tells about the numer of test cases
    for (int example = 0; example < test_case_number; example++)
    {
        input >> m >> n;                    // input the values, m and n

        input >> h_size;                    // give the size of vector h
        h.resize(h_size);                   // resize vector h
        for (int i = 0; i < h_size; i++)
            input >> h[i];                  // read in h[i]

        input >> v_size;                    // give the size of vector v
        v.resize(v_size);                   // resize vector v
        for (int i = 0; i < v_size; i++)
            input >> v[i];                  // read in v[i]


        // output the results to "Output.txt"
        output << "Test case number " << example + 1 << ", maximum area is ";
        output << maximum_area(m, n, h, v) << endl;

        h.clear(); // clear the vector h
        v.clear(); // clear the vector v
    };


    // close the files
    input.close();
    output.close();

    return 0;
}
