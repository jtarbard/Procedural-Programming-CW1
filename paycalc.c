/* This is a template with the function you must implement for this assignment.
 *
 * Note that you are free to implement any additional function you consider appropriate.
 */
 //add libraries
#include <stdio.h>

//declare variables
float annualSalary, personalAllowance, taxableIncome, annual_salary, annualIncomeTax;
int age;
//global variables
float monthly_tax;

//Returns the personal allowance of a person with the given annual salary
float compute_personal_allowance ( float annualSalary ) {
     if(annualSalary < 100000) {
       return 11850.0;
     }
     else if(annualSalary >= 123700) {
       return 0.0;
     }
     else {
       return 11850.0 - (annualSalary - 100000.0)/2.0;
     }

}

//Returns the taxable income of a person with the given annual salary and personal allowance
float compute_taxable_income(float annualSalary, float personalAllowance) {
  if(annualSalary > 11850){
    return annualSalary - personalAllowance;
  }
  else {
    return 0;
  }

}

//Returns the annual income tax of a person with the given taxable income
float compute_annual_income_tax ( float taxableIncome ) {
    if(taxableIncome <= 34500){
      return taxableIncome*0.2;
    }
    else if(taxableIncome >= 34501 && taxableIncome <= 150000){
      return 34500*0.2 + (taxableIncome - 34500)*0.4;
    }
    else if(taxableIncome > 150000) {
      return 34500*0.2 + 115499*0.4 + (taxableIncome - 150000)*0.45;
    }
}

//Returns the annual national insurance for a person with the given annual salary and age.
float compute_annual_national_insurance ( float annual_salary, int age ) {
    if(age <= 65 && annualSalary >= 8424){
      if(annualSalary < 37926){
        return annualSalary*0.12;
      }
      else {
        return 37926*0.12 + (annualSalary - 37926)*0.02;
      }
    }
    else {
      return 0;
    }
}


//Computes the monthly net pay of a person with the given annual salary, annual income tax, and annual national insurance
float compute_monthly_net_pay ( float annualSalary, float annualIncomeTax, float annualNatInsurance ) {
    return 0;
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
  personalAllowance = compute_personal_allowance (annualSalary);
  taxableIncome = compute_taxable_income(annualSalary, personalAllowance);
  monthly_tax = compute_annual_income_tax(taxableIncome);
  printf("%f", monthly_tax);
  printf("\n%f", monthly_tax/12);
  printf("\n%f", compute_annual_national_insurance(annualSalary, age));
//  annualIncomeTax = compute_annual_national_insurance (annual_salary, age);
}


//Returns the total money paid by the company to the employees entered
//into the system through add_person()
float get_total_money_paid() {

}

//Returns the average net salary of all the employees entered into the
//system through add_person()
float get_average_net_salary() {

}

//Returns the maximum income tax paid by any of the employees entered into the
//system through add_person()
float get_maximum_income_tax() {

}

//Returns the minumum income tax paid by any of the employees entered into the
//system through add_person()
float get_minimum_income_tax() {

}


int main () {

  printf("Employees age: ");
  scanf("%i", &age);

  printf("Employees gross salary: ");
  scanf("%f", &annualSalary);

  add_person(annualSalary, age);


    return 0;
}
