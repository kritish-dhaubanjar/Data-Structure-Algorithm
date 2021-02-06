#include <iostream>
using namespace std;

class Sample
{
public:
    int flag;
    int *A;
    Sample();
    ~Sample();
    void show();
};

Sample::Sample()
{
    this->flag = 1;
    this->A = new int[10];
}
Sample::~Sample()
{
    cout << "delete[] A;\n";
    delete[] A;
}

void Sample::show()
{
    {
        cout << "sample.flag="
             << this->flag << "\n";

        for (int i = 0; i < 10; i++)
        {
            cout << this->A[i] << " ";
        }
        cout << "\n";
    }
}

void passByValue(Sample sample)
{
    cout << &sample << "\n";
    cout << sample.A << "\n";
    sample.flag = 100;
    for (int i = 0; i < 10; i++)
    {
        sample.A[i] = 100 + i;
    }
}

void passByReference(Sample *sample)
{
    sample->flag = 200;
    for (int i = 0; i < 10; i++)
    {
        sample->A[i] = 200 + i;
    }
}

//

int main()
{
    Sample sample;
    sample.flag = 1;
    sample.A = new int[10];
    sample.show();

    cout << &sample << "\n";
    cout << sample.A << "\n";

    cout << "\npassByValue(sample)\n";
    passByValue(sample);
    sample.show();

    cout << "\npassByReference(&sample)\n";
    passByReference(&sample);
    sample.show();

    return 0;
}
