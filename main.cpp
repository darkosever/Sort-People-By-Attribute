#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// structures
struct person{
    string name="";
    string surname="";
    double weight=0;
    double height=0;
    double iq=0;
};

// functions
void process_data(person people[]);
void print_people(person people[], int n);
void sort_data_by_name(person people[], int n);
void sort_data_by_iq(person people[], int n);

int main(){
    // data setup
    int n=3; // just need to set number of people
    person people[n]; // ... created array

    process_data(people); // transform txt to array of person struct
    print_people(people, n); // print them into console

    sort_data_by_name(people, n); // sort people by their names
    print_people(people, n); // print them into console

    sort_data_by_iq(people, n); // sort people by their names
    print_people(people, n); // print them into console
}

void process_data(person people[]){
    string name="", surname="";
    double weight=0, height=0, iq=0;
    ifstream data("data.txt");

    int counter=0;
    while(data>>name>>surname>>weight>>height>>iq){
        people[counter].name=name;
        people[counter].surname=surname;
        people[counter].weight=weight;
        people[counter].height=height;
        people[counter].iq=iq;
        counter+=1;
    }
    cout<<"[data has been processed]"<<endl;
}
void print_people(person people[], int n){
    cout<<endl;
    cout<<"name"<<setw(8)<<"surname"<<setw(7)<<"weight"<<setw(7)<<"height"<<setw(3)<<"iq"<<endl;
    for(int i=0; i<n; i++)
        cout<<people[i].name<<" "<<people[i].surname<<" "<<people[i].weight<<" "<<people[i].height<<" "<<people[i].iq<<endl;
    cout<<"[data has been printed]"<<endl;
}
void sort_data_by_name(person people[], int n){
    for(int i=0; i<n; i++){ // loop for every person
        if(i!=n-1){ // do if is not last element
            for(int j=i; j<n; j++){
                if(people[i].name[0]>people[j].name[0]){
                    person temporary_person = people[i]; // create temporary person
                    people[i]=people[j]; // swap
                    people[j]=temporary_person; // swap
                }
            }
        }else{
            break; // go out of loop if is last element
        }
    }
    cout<<endl<<"[data has been sorted]"<<endl; // alert
}
void sort_data_by_iq(person people[], int n){
    for(int i=0; i<n; i++){
        if(i!=n-1){
            for(int j=i; j<n; j++){
                if(people[i].iq<people[j].iq){
                    person temporary_person = people[i];
                    people[i]=people[j];
                    people[j]=temporary_person;
                }
            }
        }else{
            break;
        }
    }
    cout<<endl<<"[data has been sorted]"<<endl;
}