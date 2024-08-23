//
// Division tester program
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int dividend, divisor, answer;  //answer = dividend/divisor
    int users_answer;
    long start_time;
    int duration;
    int sum_correct = 0;
    int sum_durations = 0;
    int i;  //counter
    srand(time(NULL));  //use current time as seed

    for (i=0; i<10; i++)
    {
        answer = rand()/(RAND_MAX/8) + 2;
        divisor = rand()/(RAND_MAX/8) + 2;
        dividend = answer*divisor;  // Generate answer and divisort, then work out dividend from them.
        cout << "what is " << dividend << " divided by " << divisor << "?\n";
        start_time = time(NULL);
        cin >> users_answer;
        if (users_answer != answer)
            cout << "WRONG! The answer is " << answer << '\n';
        else
        {
            cout << "Correct!\n" << "Time taken: " << (duration = time(NULL)-start_time) << " seconds\n";
            sum_correct++;
            sum_durations += duration;
        }
    }
    cout << sum_correct << " out of 10 correct.\n";
    if (sum_correct)
        cout << "Average time = "<< (double) sum_durations/sum_correct << " seconds\n";
    return 0;
}
