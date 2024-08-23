#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int roll(int dice[], const int num_dice);
int print_histogram(const int num_bins, const int bin_array[]);
int main()
{
    const int max_dice = 12;
    int dice[max_dice];
    const int possible_outcomes = max_dice*6;
    int freq_counters[possible_outcomes+1];
    // Extra 1 is because outcomes will go from 1 to
    // possible_outcomes, not from 0 to possible_outcomes-1
    int num_dice;
    int num_rolls;
    int roll_cnt;
    int i;
    cout << "Enter number of dice (1-"<<max_dice<<"):";
    cin >> num_dice;
    if ((num_dice<1) || (num_dice > max_dice))
    {
        cout << "Number of dice MUST be between 1 and " << max_dice << '\n';
        return 0;
    }
    cout << "Enter number of rolls:";
    cin >> num_rolls;
    if (num_rolls < 1)
    {
        cout << "MUST roll 1 or more times\n";
        return 0;
    }
    srand((int) time(NULL));
    for (i=0; i<possible_outcomes+1;i++)
        freq_counters[i] = 0;
    for (roll_cnt = 0; roll_cnt < num_rolls; roll_cnt++)
    {
        roll(dice, num_dice);
        int sum = 0;
        for (i=0;i<num_dice;i++)
            sum+=dice[i];
        freq_counters[sum]++;
    }
    print_histogram(num_dice*6, freq_counters);
    return 1;
}
int roll(int dice[], const int num_dice)
{
    for (int i=0; i<num_dice; i++)
    {
        dice[i] = rand()/(RAND_MAX/6)+1;
    }
    return 0;
}
int print_histogram(const int num_bins, const int bin_array[])
{
    const int max_height = 25; // Fit in 25 lines
    const int line_length = 79; // Length of text line
    char outline[line_length+1];
    int i;
    // Clear output
    for (i=0;i<line_length;i++)
        outline[i] = ' ';
    outline[line_length] = '\0';
    // find highesest peak
    int height = -1;
    for (i=0;i<num_bins;i++)
    {
        if (bin_array[i] > height)
            height = bin_array[i];
    }
    // tweak histogram to fit on screen
    int height_dec = height/max_height;
    if (height_dec<1)
        height_dec = 1;
    for (i=0;i<=num_bins;i++)
        cout << i%10;
    cout << '\n';
    while (height >= 0)
    {
        for (i=0; i<=num_bins;i++)
        {
            if (bin_array[i] > height)
                outline[i] = '*';
        }
        cout << outline << '\n';
        height -= height_dec;
    }
    for (i=0;i<=num_bins;i++)
        cout << i%10;
    cout << '\n';
    return 0;
}
                               
                               

