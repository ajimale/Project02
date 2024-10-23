#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Name: Abdikarim Jimale
 * Project02 = Knapsack problem. 
 * 
 */

// The funcation use to solve the Knapsack problem.I used int & To be able to point to the integer variable and be able to modify that original vlaue 
int knapsack(const vector<int>& weights, const vector<int>& value, int maximum_weight) {
    int n = value.size();

    // create a Dynamic Programming table. 
    vector<vector<int>> dp(n + 1, vector<int>(maximum_weight + 1,0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= maximum_weight; ++w) {
            if (weights[i-1] <= w){ 
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i -1]] + value[i - 1]); 
            }
            else{
                dp[i][w] = dp[i -1][w];
            }
        }
    }

    // Return Maximum value
    return dp[n][maximum_weight];    
}

// This funcation used to handle the format input: W n v1 w1 v2 w2 . . . vn wn
bool processInput(string input, int& maximum_weight, vector<int>& values, vector<int>& weights) {
    stringstream ss(input);
    int n;

    //make sure the maximum weight number isn't less or equal 0 
    if(!(ss >> maximum_weight) || maximum_weight <= 0){ 
        cout << "The Maximum weight number can't be less or equal 0" << endl;
        return false;
    }

    //make sure the item number isn't less or equal 0 
    if(!(ss >> n) || n <= 0){ 
        cout << "The item number can't be less or equal 0" << endl;
        return false;
    }

    //we use clear to removes all elements from the vector to empty to re-enter the values.
    values.clear();
    weights.clear();

    //read the v and w for each item
    for (int i=0; i < n; ++i){
        int value;
        int weight;

        //make sure the item value isn't less or equal 0 
        if(!(ss >> value) || value <= 0){ 
        cout << "The value for the item " << (i+1) << " have to be greater than 0" << endl;
        return false;
        }

        //make sure the item weight isn't less or equal 0 
        if(!(ss >> weight) || weight <= 0){ 
        cout << "The weight for the item " << (i+1) << " have to be greater than 0" << endl;
        return false;
        }

        // Add it to vector.
        values.push_back(value);
        weights.push_back(weight);
    }

    // Check if there is an extra item ( total item number != n )
    string extra; 
    if (ss >> extra) {
        cout << "There still extra input check your input: " << endl;
        return false;
    }    

    return true;
}

//This funcation take the user input.
void getInput(int& maximum_weight, vector<int>& values, vector<int>& weights){ 
    string input; 
    bool intput_valid= false; 

    while (!intput_valid)
    {
        // Take the user input.
        cout << "Please enter the Format as (W n v1 w1 v2 w2 ..... vn wn): " << endl;
        getline(cin, input);
        intput_valid = processInput(input, maximum_weight, values, weights); 
    }
    
}

int main() {

    int maximum_weight; 
    vector<int> values; 
    vector<int> weights; 

    //calling the fucation to handle the formt input.
    getInput(maximum_weight, values, weights);

    //Find the maximum value.
    int max_value = knapsack(weights, values, maximum_weight);

    cout << "Maximum value: " <<max_value <<endl;

    return 0;
}