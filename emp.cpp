#include <iostream>
using namespace std;
class employee
{
private:
  int id;
  string desig, name;
  float bp, hra, total, da;
  static int count;

public:
  employee()
  {
    name = "Kishore";
    desig = "CEO";
    bp = 100000.0;
    count++;
    id = count;
  }
  employee(string name, string desig, float bp)
  {
    this->name = name;
    this->desig = desig;
    this->bp = bp;
    count++;
    id = count;
  }
  static int empcount();
  float calc_sal();
  void display();
  ~employee()
  {
    cout << "Object destroyed\n";
  }
};
float employee::calc_sal()
{
  if (desig == "CEO")
  {
    hra = 0.95 * bp;
    da = 0.75 * bp;
  }
  else if (desig == "Manager")
  {
    hra = 0.85 * bp;
    da = 0.65 * bp;
  }
  else if(desig=="Clerk")
  {
    hra = 0.75 * bp;
    da = 0.55 * bp;
  }
  else {
    hra = 0.65 * bp;
    da = 0.45 * bp;
  }
  total = bp + da + hra;
  return total;
}
void employee::display()
{
  cout << "Name: " << name << "\n"
       << "Employee Id: " << id << "\n"
       << "Designation:" << desig << "\n"
       << "Basic Pay: " << bp << "\n"
       << "Dear Allowance: " << da << "\n"
       << "HRA: " << hra << "\n"
       << "Count: " << count << "\n"
       << "Total: " << calc_sal() << "\n";
}
int employee::count = 0;
int employee::empcount()
{
  return count;
}
int main()
{
  employee e[3];
  e[0] = employee("Hari", "Manager", 120000.21);
  e[1] = employee("Vignesh", "HR", 12121.12);
  e[2] = employee("Waran", "Some", 2121.12);
  int i;
  for (i = 0; i <= 2; i++)
  {
    e[i].calc_sal();
    e[i].display();
  }
  return 0;
}