#include <iostream>
#include <cstring>
using namespace std;
class Employee{
      private:
            int id ;
            char name[20];
            float salary;
      public:
            Employee(int i = 0 , const char *n = "NULL" , float s = 0.0){
                  id = i;
                  strcpy(name , n);
                  salary = s;
            }
            void input(){
                  cout << " Input id : "; cin >> id;fflush(stdin); cin.clear();
                  cout << " Input name : "; cin.seekg(0, ios::end); cin.clear(); cin.getline(name , 20);
                  cout << " Input salary : "; cin >> salary;
            }
            void output (){
                  cout << id << "\t" << name << "\t" << salary << "\n";
            }
            int getId(){ return id; }
};
#include <fstream>
// write data
/*
int main (){
      Employee x ;
      int n;
      ofstream f("empdata.bin", ios::binary); // ofstream = write file (ios::out)
      if (f.fail()){
            cout << "Cannot open file to write\n";
            return 0;
      }
      cout << " input number of employee : "; cin >> n;
      for (int i=0 ; i<n ; i++){
            cout << " Input employee " << i+1 << " : \n";
            x.input();
            f.write((char*)&x , sizeof(x)); // write binary file
      }
      f.close();
      return 0;
}
*/

// read store on array
/*
int main (){
      Employee a[100];
      int n =0;
      // open file to read
      ifstream f("empdata.bin", ios::binary); // ifstream = read file (ios::in)
      if (f.fail()){
            cout << "Cannot open file to read\n";
            return 0;
      }
      cout << "Data from file:\n";
      while (1){
            f.read((char*)&a[n] , sizeof(a[n])); // read binary file
            if (f.eof()) break;
            n++;
      }
      f.close();
      for (int i=0 ; i<n ; i++)
            a[i].output();
      return 0;
}
*/

// random access file
/*
int main (){
     Employee *a,x,y; int n;
     ifstream f("empdata.bin", ios::binary); // ifstream = read file (ios::in)
      if (f.fail()){
            cout << "Cannot open file to read\n";
            return 0;
      }
      f.seekg(-4*sizeof (Employee) , ios::end); // move to 4th record from end
      f.read((char*)&x , sizeof(x));
      f.seekg(2*sizeof (Employee) , ios::cur); // move to 2nd record from current position
      f.read((char*)&y , sizeof(y)); // read record
      x.output(); 
      y.output(); 
      f.seekg(0 , ios::end); // move to end of file
      n = f.tellg()/sizeof(Employee); // get number of record
      a = new Employee[n]; // dynamic array
      // read all record
      f.seekg(0 , ios::beg); // move to beginning of file
      f.read((char*)a , n*sizeof(Employee)); // read all record
      f.close();
      cout << "All data from file:\n";
      for (int i=0 ; i<n ; i++)
            a[i].output();
      delete [] a;
      return 0;
}
*/
// search by id and remove
 
int main (){
      Employee *a;
      int n , idRemove;
      ofstream f1("empdata.bin", ios::binary); // ofstream = write file (ios::out)
      if (f1.fail()){
            cout << "Cannot open file to write\n";
            return 0;
      }
      cout << " Input id to remove : "; cin >> idRemove;
      for (int i=0 ; i<n ; i++){
            if (a[i].getId() != idRemove){
                  a[i].output();
                  f1.write((char*)&a[i] , sizeof(a[i])); // write binary file
            }
      }
      f1.close();
      cout << "All data from file:\n";
      
      ifstream f("empdata.bin", ios::binary); // ifstream = read file (ios::in)
      if (f.fail()){
            cout << "Cannot open file to read\n";
            return 0;
      }
      f.seekg(0 , ios::end); // move to end of file
      n = f.tellg()/sizeof(Employee); // get number of record
      a = new Employee[n];
      f.seekg(0 , ios::beg); // move to beginning of file
      f.read((char*)a , n*sizeof(Employee)); // read all record
      f.close();
      for (int i=0 ; i<n ; i++)
            a[i].output();
      delete [] a;
      return 0;

}
/* Output
 Input id to remove : 2
 All data from file:
 1       John    5000
 3       Alice   6000
*/
