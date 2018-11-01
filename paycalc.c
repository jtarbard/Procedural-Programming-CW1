/* This is a template with the function you must implement for this assignment.
 *
 * Note that you are free to implement any additional function you consider appropriate.
 */
 //add libraries
#include <stdio.h>

//declare argument variables
float annualSalary, personalAllowance, taxableIncome, annual_salary, annualIncomeTax, annualNatInsurance;
int age, menu_selection = 0;

//declare additional variables
float total_money_paid, total_net_paid, minimum_income_tax = 100000000, maximum_income_tax, monthly_net_pay;
int employee_count;

//additional function: compares and updates min/max income tax variables
void update_company_stats() {
  if(annualIncomeTax/12 < minimum_income_tax){ //if tax is smaller than current minimum
    minimum_income_tax = annualIncomeTax/12; //set minimum to current tax
  }
  else {
    ; //pass
  }
  if(annualIncomeTax/12 > maximum_income_tax){ //if tax is larger than current maximum
    maximum_income_tax = annualIncomeTax/12; //set maximum to current tax
  }
  else {
    ; //pass
  }

}

//Returns the personal allowance of a person with the given annual salary
float compute_personal_allowance ( float annualSalary ) {
     if(annualSalary < 100000) { //if salary under allowance threshhold
       return 11850.0; //return allowance
     }
     else if(annualSalary >= 123700) { //if salary over cap
       return 0.0; //return allowance
     }
     else { //salary is under cap but over threshold
       return 11850.0 - (annualSalary - 100000.0)/2.0; //return allowance
     }

}

//Returns the taxable income of a person with the given annual salary and personal allowance
float compute_taxable_income(float annualSalary, float personalAllowance) {
  if(annualSalary > 11850){ //if salary more than maximum personal allowance
    return annualSalary - personalAllowance; //return taxable income
  }
  else { //salary is less than maximum personal allowance
    return 0; // return taxable income as 0
  }

}

//Returns the annual income tax of a person with the given taxable income
float compute_annual_income_tax ( float taxableIncome ) {
    if(taxableIncome <= 34500){ //if taxable income within band 1
      return taxableIncome*0.2; //return yearly tax
    }
    else if(taxableIncome > 34500 && taxableIncome <= 150000){ //if taxable income within band 2
      return 34500*0.2 + (taxableIncome - 34500.0)*0.4; //return yearly tax
    }
    else {  //taxable income within band 3
      return 34500*0.2 + 115500*0.4 + (taxableIncome - 150000)*0.45; //return yearly tax
    }
}

//Returns the annual national insurance for a person with the given annual salary and age.
float compute_annual_national_insurance ( float annualSalary, int age ) {
  if(age >= 65) { //if emoloyee 65 or over
    return 0; //return 0 nic
  }
  else if (annualSalary < 8424){ //if employee earns below threshold
    return 0; //return 0 nic
  }
  else {
    if(annualSalary <= 46350){ //if salary within band 1
      return (annualSalary - 8424)*0.12; //return nic
    }
    else { //salary is above band 1
      return (annualSalary - 46350)*0.02 + ((46350 - 8424))*0.12; //return nic
    }
  }
}


//Computes the monthly net pay of a person with the given annual salary, annual income tax, and annual national insurance
float compute_monthly_net_pay ( float annualSalary, float annualIncomeTax, float annualNatInsurance ) {
    return (annualSalary - annualIncomeTax - annualNatInsurance)/12; //return net monthly pay

}

//additional function prints the employees Payroll
void print_payrol(){
  printf("Employee %i Payroll:\n", employee_count); //formatting
  printf("Employee Age: %i\n", age); //print age
  printf("Annaual Salary: %f\n", annualSalary); //print annual salary
  printf("Taxable Income: %f\n", taxableIncome); //print taxable income
  printf("Monthly Income Tax: %f\n", annualIncomeTax/12); //print income tax
  printf("Monthly NIC: %f\n", annualNatInsurance/12); //print nic
  printf("Net Monthly Pay: %f\n", monthly_net_pay); //print net pay
}

/*Enters a person with a given annual salary and age into the system.

This function uses the functions above to compute and update the cumulative statistics, namely:

A.	The total amount of money paid out by the company to all employees.

B.	The total amount of income tax paid by all employees.

C.	The total amount of national insurance contributions paid by all employees.

D.	The average net monthly salary.

E.	The maximum income tax paid by any employee.

F.	The minimum income tax paid by any employee.

G.	The maximum national insurance contribution paid by any employee.

H.	The minimum national insurance contribution paid by any employee.


hint: store the values into global variables, so that the function below can return them.
*/
void add_person ( float annualSalary, int age ) {
  //employee added increment count
  employee_count = employee_count + 1;
  //calculate personal allowance
  personalAllowance = compute_personal_allowance (annualSalary);
  //calculate taxable income
  taxableIncome = compute_taxable_income(annualSalary, personalAllowance);
  //calculate annual income tax
  annualIncomeTax = compute_annual_income_tax(taxableIncome);
  //calculate annaual nation insurance
  annualNatInsurance = compute_annual_national_insurance(annualSalary, age);
  //update min/max income tax
  update_company_stats();
  //calculate monthly net pay
  monthly_net_pay = compute_monthly_net_pay(annualSalary, annualIncomeTax, annualNatInsurance);
  //update total net pay
  total_net_paid = total_net_paid + monthly_net_pay;
  //update total salaray paid
  total_money_paid = total_money_paid + (annualSalary/12);
  //print employee Payroll
  print_payrol();

}


//Returns the total money paid by the company to the employees entered
//into the system through add_person()
float get_total_money_paid() {
  return total_money_paid; //return total salary paid
}

//Returns the average net salary of all the employees entered into the
//system through add_person()
float get_average_net_salary() {
  return total_net_paid/employee_count; //reutrn total net salary
}

//Returns the maximum income tax paid by any of the employees entered into the
//system through add_person()
float get_maximum_income_tax() {
  return maximum_income_tax; //return maximum income tax
}

//Returns the minumum income tax paid by any of the employees entered into the
//system through add_person()
float get_minimum_income_tax() {
  return minimum_income_tax; //return minimum income tax
}

//addition function checks that input values are valid
int parse_input() {
  if(age > 0 && annualSalary >= 0){ //if inputs are positive
    return 1; //return true
  }
  else {
    return 0; //return false
  }
}

int main () {

  printf("Welcome To The Payroll Calcultor!\n"); //greet user
  //menu while loop
  while(menu_selection != 3) { //while menu selection isnt quit
    printf("-------------------------\n"); //formatting
    printf("Select Operation:\n1. Compute Employee Payroll\n2. Show Company Sums & Stats \n3. Quit Program \n\nOperation Selection: "); //print menu options
    scanf("%i", &menu_selection); //scan menu selection
    printf("-------------------------\n"); //formatting
    //menu selection statement
    switch(menu_selection){
      case 1: // compute employee payroll
        printf("Employees age: "); //ask for employees age
        scanf("%i", &age); //scan employees age

        printf("Employees gross salary: "); //ask for employees salary
        scanf("%f", &annualSalary); //scan employees age
        printf("-------------------------\n"); //formatting
        if(parse_input() == 1){ //if input validation returns true
          add_person(annualSalary, age); //run add person
        }
        else { //input validation returned false
          printf("Error: Age or salary input invalid; please make sure values are numerical and positive.\n"); //invalid input warning
        }
        break;
      case 2: //show company sums
        if(employee_count > 0) {
          printf("Company Sums and Statistics:\n"); //formatting
          printf("Total Monthly Salary Paid: %f\n", get_total_money_paid()); //print total money paid
          printf("Average Net Salary: %f\n", get_average_net_salary()); //print average net salary
          printf("Maximum Income Tax: %f\n", get_maximum_income_tax()); //print maximum income tax
          printf("Minimum Income Tax: %f\n", get_minimum_income_tax()); //print minimum income tax
        }
        else {
          printf("Error: No sums or statistics to show as no employees have been entered.\n"); //warning message
        }
        break;
      case 3: //exit program
        printf("You have selected exit, goodbye!\n"); //print exit message
        break;
      default: //menu selection invalid
        printf("Error: Menu item selection invalid, please input 1, 2 or 3.\n"); //print error warning message
        break;
    }
  }
    return 0;
}
