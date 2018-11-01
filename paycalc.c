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
float employee_count, total_money_paid, total_net_paid, minimum_income_tax = 100000000, maximum_income_tax, monthly_net_pay;

//additional function: compares and updates min/max income tax variables
void update_company_stats() {
  if(annualIncomeTax/12 < minimum_income_tax){
    minimum_income_tax = annualIncomeTax/12;
  }
  else {
    ;
  }
  if(annualIncomeTax/12 > maximum_income_tax){
    maximum_income_tax = annualIncomeTax/12;
  }
  else {
    ;
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
  if(age >= 65) {
    return 0;
  }
  else if (annualSalary < 8424){
    return 0;
  }
  else {
    if(annualSalary <= 46350){
      return (annualSalary - 8424)*0.12;
    }
    else {
      return (annualSalary - 46350)*0.02 + ((46350 - 8424))*0.12;
    }
  }
}


//Computes the monthly net pay of a person with the given annual salary, annual income tax, and annual national insurance
float compute_monthly_net_pay ( float annualSalary, float annualIncomeTax, float annualNatInsurance ) {
    return (annualSalary - annualIncomeTax - annualNatInsurance)/12; //return net monthly pay

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
  employee_count = employee_count + 1;
  personalAllowance = compute_personal_allowance (annualSalary);
  taxableIncome = compute_taxable_income(annualSalary, personalAllowance);
  annualIncomeTax = compute_annual_income_tax(taxableIncome);
  annualNatInsurance = compute_annual_national_insurance(annualSalary, age);
  update_company_stats();
  monthly_net_pay = compute_monthly_net_pay(annualSalary, annualIncomeTax, annualNatInsurance);
  total_net_paid = total_net_paid + monthly_net_pay;
  total_money_paid = total_money_paid + (annualSalary/12);


}


//Returns the total money paid by the company to the employees entered
//into the system through add_person()
float get_total_money_paid() {
  return total_money_paid;
}

//Returns the average net salary of all the employees entered into the
//system through add_person()
float get_average_net_salary() {
  return total_net_paid/employee_count;
}

//Returns the maximum income tax paid by any of the employees entered into the
//system through add_person()
float get_maximum_income_tax() {
  return maximum_income_tax;
}

//Returns the minumum income tax paid by any of the employees entered into the
//system through add_person()
float get_minimum_income_tax() {
  return minimum_income_tax;
}

//addition function
int parse_input() {
  if(age > 0 && annualSalary >= 0){
    return 1;
  }
  else {
    return 0;
  }
}

int mymain () {

  printf("Welcome To The Payroll Calcultor!\n");
  while(menu_selection != 3) {
   printf("Select Operation:\n1. Compute employee payroll\n2. Show company sums \n3. Quit program \n\nPlease enter choice: ");
   scanf("%i", &menu_selection);

    switch(menu_selection){
      case 1:
        printf("Employees age: ");
        scanf("%i", &age);

        printf("Employees gross salary: ");
        scanf("%f", &annualSalary);

        if(parse_input() == 1){
          add_person(annualSalary, age);
        }
        else {
          printf("Age or salary input invalid; please make sure values are numerical and positive.");
        }
        break;
      case 2:
        get_total_money_paid();
        get_average_net_salary();
        get_maximum_income_tax();
        get_minimum_income_tax();
        break;
      case 3:
        printf("You have selected exit, goodbye!");;
        break;
      default:
        printf("Menu item selection invalid, please input 1, 2 or 3.\n\n");
        break;
    }
  }


    return 0;
}
