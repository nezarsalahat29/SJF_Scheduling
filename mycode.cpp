/*
Written by:
Rami Mustafa Haider 131021
Nezar Bilal Al-Salahat 132827
*/

#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>

using namespace std;

struct process
{
    string name;
    int AT, PT, PE, PS, TA, D, R;
    /*
    ArriveTime
    processingTime
    processEndTime
    processStartTime
    responseTime
    turnaround
    delay
*/
};
int gt = 0;// global timer

class SJF
{
    process* list;
    int length;// # of process

    process* temp2;
    process* temp1;
    int mv;


public:
    SJF() //constructor
    {
        fstream file;
        file.open("in.txt");
        if (!file)
            cout << "no file with this name" << endl;
        else
        {

            file >> length;
            list = new process[length];
            for (int i = 0;i < length; i++) {
                file >> list[i].name >> list[i].AT >> list[i].PT;


            }
        }
        int seconedprocess, index;
        process temp;
        minvalue();
        // sort list by Process Time
        for (seconedprocess = 1; seconedprocess < length; seconedprocess++)
        {
            if (list[seconedprocess].AT < list[seconedprocess - 1].AT)
            {
                temp = list[seconedprocess];
                index = seconedprocess;

                do
                {
                    list[index] = list[index - 1];
                    index--;

                } while (index > 0 && list[index - 1].AT > temp.AT);
                list[index] = temp;
            }
        }
        gt=list[0].AT;
        file.close();
        temp1 = new process[length];
        temp2 = new process[length];


    }

    void minvalue() //min  value of Arrival time
    {
        int* a;
        a=new int(length);
        for (int i = 1; i < length; i++)
        {
            a[i] = list[i].AT;
        }
        mv = *min_element(a+1, a + length);

    }

    void schedule()
    {



        int seconedprocess, index;
        process temp;
        minvalue();
        // sort list by Process Time
        for (seconedprocess = 1; seconedprocess < length; seconedprocess++)
        {
            if (list[seconedprocess].PT < list[seconedprocess - 1].PT)
            {
                temp = list[seconedprocess];
                index = seconedprocess;

                do
                {
                    list[index] = list[index - 1];
                    index--;

                } while (index > 0 && list[index - 1].PT > temp.PT);
                list[index] = temp;
            }
        }


        int c = 0; 
        int c2 = 0;
        for (int i = 0;i < length;i++)
        {


            if (list[i].AT <= gt) {
                list[i].PS = gt;
                list[i].PE = gt + list[i].PT;
                list[i].TA = list[i].PE - list[i].AT;
                list[i].R = list[i].PS - list[i].AT;
                list[i].D = list[i].TA - list[i].PT;
                gt += list[i].PT;
                temp1[c++] = list[i];

            }
            else 
            {
                if (gt < mv && c>c2)
                {
                    gt++;
                    i--;        // dealing with gaps
                    continue;
                }
                temp2[c2++] = list[i];


            }

        }
        // merge 2 temp arrays
        for (int j = 0;j < c2;j++)
        {
            temp2[j].PS = gt;
            temp2[j].PE = gt + temp2[j].PT;
            temp2[j].TA = temp2[j].PE - temp2[j].AT;
            temp2[j].R = temp2[j].PS - temp2[j].AT;
            temp2[j].D = temp2[j].TA - temp2[j].PT;
            gt += temp2[j].PT;
            temp1[c++] = temp2[j];
        }
        for (int i = 0; i < length; i++)
        {

            list[i]=temp1[i];
        }

        sortalpha(list);

    }

    // sort array alphapitical
    void sortalpha(process* T){
        int seconedprocess, index;
        process temp;
        for (seconedprocess = 1; seconedprocess < length; seconedprocess++)
        {
            if (T[seconedprocess].name < T[seconedprocess - 1].name)
            {
                temp = T[seconedprocess];
                index = seconedprocess;

                do
                {
                    T[index] = T[index - 1];
                    index--;

                } while (index > 0 && T[index - 1].name > temp.name);
                T[index] = temp;
            }
        }
    }
    // write data in file
    void write() {
        fstream file;
        file.open("out.txt",ios::out);
        for (int i = 0; i < length; i++)
            file << temp1[i].name;
        file << endl << endl;

        for (int i = 0; i < length; i++)
        {
            file << list[i].name << ": (response=" << list[i].R << ", turnaround=" << list[i].TA << ", delay=" << list[i].D << ")" << endl << endl;
        }


        file.close();

    }


    // print data on screen
    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << temp1[i].name;
        }
        cout << endl;
        for (int i = 0; i < length; i++) {
            cout << list[i].name << ": (response=" << list[i].R << ", turnaround=" << list[i].TA << ", delay=" << list[i].D << ")" << endl << endl;
        }
        cout << endl << endl;



    }


};


int main()
{
    SJF S;
    S.schedule();
    S.print();
    S.write();
}