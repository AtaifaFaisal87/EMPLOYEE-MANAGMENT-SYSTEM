#include<stdio.h> 
#include<string.h> // used for strcmp and strcpy
#include<stdlib.h>  // for atoi and atoll

/*-------------------------------------------
-----------------STRUCTURE-------------------
--------------------------------------------*/
struct employee {
    int ID;
    char NAME[50];
    int AGE;
    char GENDER[50];
    int SALARY;
    char DEPARTMENT[50];
    char DESIGNATION[50];
    int ATTENDANCE;
    int YEAROFSERVICE;
    long long int CONTACT;
    char PASSWORD[50];
    char EMAIL[50];
}e;

/*-------------------------------------------
------------------MENUS----------------------
--------------------------------------------*/
int adminlogin();
void employeeinfo();
void salary();
void statistics();
void printmenumodules();
void printEmployeemodules();
void printStatisticsmenu();
void printSalarysmenu();

/*-------------------------------------------
-----------------EMPLOYEE INFO---------------
--------------------------------------------*/
int UniqueID(int id);
void AddEmployee();
void DisplayAllEmployee();
void SearchEmployeeByID(int a);
void SearchEmployeeByName();
void UpdateEmployeeByID(int a);
void DeleteEmployeeByID(int a);
void TotalNumberOfEmployees();


/*-------------------------------------------
-----------------STATISTICS-------------------
--------------------------------------------*/
void attendance_Record();
void view_Attendance();
void Display();
void Percentage();
void Display_Designation();
void departmentWiseList();

/*-------------------------------------------
-----------------SALARY-------------------
--------------------------------------------*/
void HighLow();
void avgsalary();
void sortEmployeesByName();
void sortEmployeesBySalary();
void calculateBonus();
void pensioncalculator();

/*-------------------------------------------
----------------INPUT VALIDATION-------------
--------------------------------------------*/

int getValidInt(const char *msg);
void getValidstr(char *name, const char *msg);
long long int getValidLongLong(const char *msg);


/*-------------------------------------------
-----------MAIN FUNCTION------------------
--------------------------------------------*/
int main() {
     printf("=========================================\n");
    printf("     EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
   
    if (adminlogin() == 0) {
       
        return 0;
    }

    int choice;

    while (1) {
        printmenumodules();

        choice = getValidInt("Enter your choice: ");

        switch (choice) {
            case 1:
                employeeinfo();
                break;

            case 2:
                salary();
                break;

            case 3:
                statistics();
                break;

            case 4:
                printf("EXITING...\n");
                return 0;

            default:
                printf("Invalid choice, try again!\n");
                break;
        }
    }

}

/*-------------------------------------------
-----------------MENU------------------------
--------------------------------------------*/

//MAIN MENU
void printmenumodules(){
    printf("\n==== MAIN MENU ====\n\n");
        printf("1. Employee Management Module\n");
        printf("2. Salary Department Module\n");
        printf("3. Statistics Module\n");
        printf("4. EXIT\n");
}

//EMPLOYEE MENU
void printEmployeemodules(){
    printf("\n==== EMPLOYEE MANAGEMENT MENU ====\n\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employee\n");
        printf("3. Search Employee By ID\n");
        printf("4. Search Employee By Name\n");
        printf("5. Update Employee By ID\n");
        printf("6. Delete Employee By ID\n");
        printf("7. Total Number Of Employees\n");;
        printf("8. Back\n");
}

//STATISTICS MENU
void printStatisticsmenu(){
        printf("\n==== STATISTICS MANAGEMENT MENU ====\n\n");
        printf("1. View Attendence Record\n");
        printf("2. View Attendence Record by ID\n");
        printf("3. Display Employees Gender wise\n");
        printf("4. Percentage Of Male And Female Employees\n");
        printf("5. Display Employees By Designation\n");
        printf("6. Display Employees By DEPARTMENT\n");
        printf("7. Back\n");
}

//SALARY MENU
void printSalarysmenu(){
        printf("\n==== SALARY MANAGEMENT MENU ====\n\n");
        printf("1. Lowest/Highest Salary Employee\n");
        printf("2. Average Salary\n");
        printf("3. Sort Employees by Name\n");
        printf("4. Sort Employees by Salary\n");
        printf("5. Calculate Bonus\n");
        printf("6. Pension Calculator\n");
        printf("7. Back\n");
}

/*-------------------------------------------
----------------ADMIN LOGIN--------------------
--------------------------------------------*/
int adminlogin() {
    char adminUser[20], adminPass[20];
    char inputUser[20], inputPass[20];

    // Setting predefined admin username and password
    strcpy(adminUser, "admin");
    strcpy(adminPass, "admin1234");

    printf("\n===== ADMIN LOGIN =====\n");

    // Taking username input from user
    printf("Enter Username: ");
    scanf("%s", inputUser);

    // Taking password input from user
    printf("Enter Password: ");
    scanf("%s", inputPass);

    // Checking if entered username and password match the stored ones
    if (strcmp(adminUser, inputUser) == 0 && strcmp(adminPass, inputPass) == 0) {
        printf("\nLogin Successful!\n");
        return 1;   // login success
    } else {
        printf("\nInvalid username or password! Access Denied.\n");
        return 0;   // login failed
    }
}


/*-------------------------------------------
-----------VALIDATION FUNCTIONS--------------
--------------------------------------------*/
//valid integer
int getValidInt(const char *msg)
{ // pointer to char array i.e("enter your age")
    char input[100];
    int value;
    int valid;

    do
    {
        printf("%s", msg);
        scanf("%s", input);
             while (getchar() != '\n');   //CLEARS BUFFER
         valid = 1; // assume input is valid

        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                valid = 0;
                break;
            }
        }

        if (valid==0)
            printf("Invalid input. Please enter a valid number.\n");
        else
            value = atoi(input);  //returning integer to value 

    } while (valid==0); // UNTIL NOT VALID

    return value; //will return the integer 
}

// valid string
void getValidstr(char *name, const char *msg) 
{ /* Here the first argument will store the valid string in it while the second argument is for
    pointer to char array i.e("enter your name")*/ 
    int valid;
    do
    {
        printf("%s", msg);
        scanf(" %[^\n]", name);     // read full line including spaces
        while (getchar() != '\n');  // clear input buffer

        valid = 1;  // assume valid

        for (int i = 0; name[i] != '\0'; i++)
        {
            if ((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z') && name[i] != ' ')  
            {
                valid = 0;
                break;
            }
        }

        if (valid==0)
            printf("Invalid input.Please write correctly\n");

    } while (valid==0);  // repeat until valid input
}
//long int validation
long long int getValidLongLong(const char *msg)
{
    char input[100];
    long long int value;
    int valid;

    do
    {
        printf("%s", msg);
        scanf("%s", input);
        while (getchar() != '\n');   // clear the input buffer
        valid = 1; // assume input is valid

        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
            printf("Invalid input. Please enter a valid number.\n");
        else
            value = atoll(input);  // convert string to long long int

    } while (!valid);

    return value;
}

/*-------------------------------------------
-------------EMPLOYEE INFO MODULE------------
--------------------------------------------*/
void employeeinfo(){
    int choice,value;
    

    while(1){
        printEmployeemodules();
        choice=getValidInt("Enter your choice:");

switch(choice){
           case 1:
            AddEmployee();
            break;
            case 2:
            DisplayAllEmployee();
            break;
            case 3:
            value=getValidInt("Enter Employee ID You Want To Search:");
            SearchEmployeeByID(value);
            break;
            case 4:
            SearchEmployeeByName();
            break;
            case 5:
            value=getValidInt("Enter Employee ID You Want To Update:");
            UpdateEmployeeByID(value);
            break;
            case 6:
             value=getValidInt("Enter Employee ID You Want To Delete:");
            DeleteEmployeeByID(value);
            break;
            case 7:
            TotalNumberOfEmployees();
            break;
            case 8:
            printf("GOING BACK....");
            return;
            break;
            default:
            printf("Invalid choice, try again!\n");
            break;    
      }
  }
}

// UNIQUE IDS
int UniqueID(int id) 
{
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
      {return 0;}

    struct employee e;

    while (fscanf(fp,
       "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
       &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY,
       e.DEPARTMENT, e.DESIGNATION, &e.ATTENDANCE,
       &e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
        if (e.ID == id) {
            fclose(fp);
            return 1;   // ID already exists
        }


    }
    
    fclose(fp);
    return 0;  // ID not found 
}

// ADD EMPLOYEE
void AddEmployee(){
    // Open file in append mode to add new employee at the end
    FILE *fp = fopen("employee.txt", "a");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;  // Exit if file cannot be opened
    }

    struct employee e;

    printf("============ADD INFO OF EMPLOYEE===============\n\n");

    // Loop until user enters a unique ID
    do {
        e.ID = getValidInt("ENTER ID: ");

        // Check if ID already exists
        if (UniqueID(e.ID)) {
            printf("ID already exists! Please enter a different ID.\n");
        }
        else {
            break;  // ID is unique -> exit loop
        }

    } while (1);

    // Take input for employee fields
    getValidstr(e.NAME, "ENTER NAME: ");
    e.AGE = getValidInt("ENTER AGE: ");
    getValidstr(e.GENDER, "ENTER GENDER(in lower case): ");
    e.SALARY = getValidInt("ENTER SALARY: ");
    getValidstr(e.DEPARTMENT, "ENTER DEPARTMENT: ");
    getValidstr(e.DESIGNATION, "ENTER DESIGNATION: ");
    e.ATTENDANCE = getValidInt("ENTER ATTENDANCE: ");
    e.YEAROFSERVICE = getValidInt("ENTER YEAR OF SERVICE: ");
    e.CONTACT = getValidLongLong("ENTER CONTACT: ");

    // Take password input
    printf("Enter password=");
    scanf(" %[^\n]", e.PASSWORD);

    // Take email input
    printf("Enter Email=");
    scanf(" %[^\n]", e.EMAIL);

    // Store the entered details in file in formatted structure
    fprintf(fp,
            "ID=%d|NAME=%s|AGE=%d|GENDER=%s|SALARY=%d|DEPARTMENT=%s|DESIGNATION=%s|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%s|EMAIL=%s\n",
            e.ID, e.NAME, e.AGE, e.GENDER, e.SALARY, e.DEPARTMENT, e.DESIGNATION,
            e.ATTENDANCE, e.YEAROFSERVICE, e.CONTACT, e.PASSWORD, e.EMAIL);

    // Close the file
    fclose(fp);

    printf("EMPLOYEE ADDED SUCCESSFULLY!\n");
    printf("_____________________________________________________________\n");
}


// DISPLAY ALL EMPLOYEE
void DisplayAllEmployee() {
    // Open the employee file in read mode
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;   // Exit if file cannot be opened
    }

    struct employee e;

    printf("============ EMPLOYEE LIST =============\n\n");

    // Table header
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-18s %-5s %-10s %-10s %-15s %-18s %-6s %-5s %-15s %s\n",
           "ID", "NAME", "AGE", "GENDER", "SALARY", "DEPARTMENT",
           "DESIGNATION", "ATT%", "YOS", "CONTACT", "EMAIL");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    // Read each employee record from file
    while (fscanf(fp,
       "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
       &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION,
       &e.ATTENDANCE, &e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
        // Convert attendance integer to "xx%"
        char attWithPercent[10];
        sprintf(attWithPercent, "%d%%", e.ATTENDANCE);

        // Display employee in formatted table row
        printf("%-5d %-18s %-5d %-10s %-10d %-15s %-18s %-6s %-5d %-15lld %s\n",
       e.ID, e.NAME, e.AGE, e.GENDER, e.SALARY, e.DEPARTMENT,
       e.DESIGNATION, attWithPercent, e.YEAROFSERVICE,
       e.CONTACT, e.EMAIL);

    }

    // Close the file after reading all records
    fclose(fp);
}


//SEARCH EMPLOYEE BY ID
void SearchEmployeeByID(int a){
    // Open file in read mode
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;   // Exit if file can't be opened
    }

    int found = 0;
    struct employee e;

    // Read file record by record
    while (fscanf(fp,
       "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
       &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION,
       &e.ATTENDANCE, &e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
        // Check if current record matches the searched ID
        if (e.ID == a) {
            found++;
            break; // Stop reading after finding the employee
        }
    }

    // If employee found
    if (found == 1) {
        printf("ID Found Successfully!\n\n");

        // Print table header
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-5s %-18s %-5s %-10s %-10s %-15s %-18s %-6s %-5s %-15s %s\n",
               "ID", "NAME", "AGE", "GENDER", "SALARY", "DEPARTMENT",
               "DESIGNATION", "ATT%", "YOS", "CONTACT", "EMAIL");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");

        // Format attendance as "xx%"
        char attWithPercent[10];
        sprintf(attWithPercent, "%d%%", e.ATTENDANCE);

        // Print employee details
        printf("%-5d %-18s %-5d %-10s %-10d %-15s %-18s %-6s %-5d %-15lld %s\n",
               e.ID, e.NAME, e.AGE, e.GENDER, e.SALARY, e.DEPARTMENT,
               e.DESIGNATION, attWithPercent, e.YEAROFSERVICE,
               e.CONTACT, e.EMAIL);
    }
    else {
        // If not found
        printf("No Such ID Exists! Try Again.\n");
    }

    fclose(fp); // Close file
}


//SEARCH EMPLOYEE
void SearchEmployeeByName(){
    char c[50];

    // Get the name user wants to search
    getValidstr(c, "Enter Employee Name You Want To Search:");

    // Open file in read mode
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;   // Exit if file cannot be opened
    }

    int found = 0;   
    struct employee e;

    // Read each employee record from file
    while (fscanf(fp,
       "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
       &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION,
       &e.ATTENDANCE, &e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
        // Compare names (exact match)
        if (strcmp(e.NAME, c) == 0) {
            found++;
            break;   // Employee found → stop reading
        }
    }

    // If employee is found
    if (found == 1) {
        printf("Employee Found Successfully!\n\n");

        // Print table header
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-5s %-18s %-5s %-10s %-10s %-15s %-18s %-6s %-5s %-15s %s\n",
               "ID", "NAME", "AGE", "GENDER", "SALARY", "DEPARTMENT",
               "DESIGNATION", "ATT%", "YOS", "CONTACT", "EMAIL");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");

        // Format attendance with % symbol
        char attWithPercent[10];
        sprintf(attWithPercent, "%d%%", e.ATTENDANCE);

        // Display employee record
        printf("%-5d %-18s %-5d %-10s %-10d %-15s %-18s %-6s %-5d %-15lld %s\n",
               e.ID, e.NAME, e.AGE, e.GENDER, e.SALARY, e.DEPARTMENT,
               e.DESIGNATION, attWithPercent, e.YEAROFSERVICE,
               e.CONTACT, e.EMAIL);
    }
    else {
        // If no match found
        printf("No Such Employee Exists! Try Again.\n");
    }

    fclose(fp); // Close file
}

//UPDATE EMPLOYEE
void UpdateEmployeeByID(int a){
      
   struct employee arr[200];
    int count = 0;

    FILE *fp = fopen("employee.txt", "r");
    if (!fp) {
        printf("ERROR OPENING FILE!\n");
        return;
    }

    // Read all employees into array
    while (fscanf(fp,
       "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
       &arr[count].ID, arr[count].NAME, &arr[count].AGE, arr[count].GENDER,
       &arr[count].SALARY, arr[count].DEPARTMENT, arr[count].DESIGNATION,
       &arr[count].ATTENDANCE, &arr[count].YEAROFSERVICE, &arr[count].CONTACT,
       arr[count].PASSWORD, arr[count].EMAIL) == 12)
    {
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No employees in the file.\n");
        return;
    }
    // Search employee ID
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (arr[i].ID == a) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No employee with this ID exists!\n");
        return;
    }

    int choice;

    printf("\nWhat do you want to update?\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("3. Gender\n");
    printf("4. Salary\n");
    printf("5. Department\n");
    printf("6. Designation\n");
    printf("7. Attendance\n");
    printf("8. Years of Service\n");
    printf("9. Contact\n");
    printf("10. Password\n");
    printf("11. Email\n");

    choice=getValidInt("ENTER YOUR CHOICE=");


    switch(choice) {

        case 1:

        getValidstr(arr[index].NAME,"Enter new NAME: ");
            break;

        case 2:

        arr[index].AGE=getValidInt("Enter new AGE: ");
            break;

        case 3:

        getValidstr(arr[index].GENDER,"Enter new GENDER: ");
            break;

        case 4:
          arr[index].SALARY=getValidInt("Enter new SALARY: ");
            break;

        case 5:

        getValidstr(arr[index].DEPARTMENT,"Enter new DEPARTMENT: ");
            break;

        case 6:

        getValidstr(arr[index].DESIGNATION,"Enter new DESIGNATION: ");
            break;

        case 7:

          arr[index].ATTENDANCE=getValidInt("Enter new ATTENDANCE: ");
            break;

        case 8:
          arr[index].YEAROFSERVICE=getValidInt("Enter new YEAR OF SERVICE: ");
            break;

        case 9:
          arr[index].CONTACT=getValidLongLong("Enter new CONTACT: ");
            break;

        case 10:
            printf("Enter new PASSWORD: ");
            scanf(" %[^\n]", arr[index].PASSWORD);
            break;

        case 11:
            printf("Enter new EMAIL: ");
            scanf(" %[^\n]", arr[index].EMAIL);
            break;

        default:
            printf("Invalid choice!\n");
            return;
    }


    // Rewrite all employees back to file
    fp = fopen("employee.txt", "w");
    if (fp==NULL) {
        printf("ERROR WRITING TO FILE!\n");
        return;
    }

    for (int i = 0; i < count; i++) {

        fprintf(fp,
        "ID=%d|NAME=%s|AGE=%d|GENDER=%s|SALARY=%d|DEPARTMENT=%s|DESIGNATION=%s|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%s|EMAIL=%s\n",
        arr[i].ID, arr[i].NAME, arr[i].AGE, arr[i].GENDER,
        arr[i].SALARY, arr[i].DEPARTMENT, arr[i].DESIGNATION,
        arr[i].ATTENDANCE, arr[i].YEAROFSERVICE, arr[i].CONTACT,
        arr[i].PASSWORD, arr[i].EMAIL);
    }

    fclose(fp);

    printf("\nEmployee updated successfully!\n");
}


// DELETE EMPLOYEE

void DeleteEmployeeByID(int a) {
    struct employee emp[100];
    int n = 0;
    int found = 0;

    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("ERROR OPENING FILE!\n");
        return;
    }

    // READ ALL EMPLOYEES
    while (fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp[n].ID, emp[n].NAME, &emp[n].AGE, emp[n].GENDER,
        &emp[n].SALARY, emp[n].DEPARTMENT, emp[n].DESIGNATION,
        &emp[n].ATTENDANCE, &emp[n].YEAROFSERVICE,
        &emp[n].CONTACT, emp[n].PASSWORD, emp[n].EMAIL) == 12)
    {
        n++;
    }
    fclose(fp);

    if (n == 0) {
        printf("No employees to delete.\n");
        return;
    }

    // FIND THE EMPLOYEE INDEX
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (emp[i].ID == a) {
            index = i;
            found = 1;
            break;
        }
    }

    if (found==0) {
        printf("Employee with ID %d not found.\n", a);
        return;
    }

    // SHIFT THE ARRAY TO DELETE RECORD
    for (int i = index; i < n - 1; i++) {
        emp[i] = emp[i + 1];
    }
    n--;  // reduce total count

    // WRITE UPDATED LIST BACK TO FILE
    fp = fopen("employee.txt", "w");
    if (fp == NULL) {
        printf("ERROR OPENING FILE!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp,
            "ID=%d|NAME=%s|AGE=%d|GENDER=%s|SALARY=%d|DEPARTMENT=%s|DESIGNATION=%s|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%s|EMAIL=%s\n",
            emp[i].ID, emp[i].NAME, emp[i].AGE, emp[i].GENDER,
            emp[i].SALARY, emp[i].DEPARTMENT, emp[i].DESIGNATION,
            emp[i].ATTENDANCE, emp[i].YEAROFSERVICE,
            emp[i].CONTACT, emp[i].PASSWORD, emp[i].EMAIL);
    }

    fclose(fp);

    printf("Employee ID %d deleted successfully.\n", a);
}

// TOTAL NUMBER OF EMPLOYEE
void TotalNumberOfEmployees(){
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;
    }
    int count=0;
    struct employee e;
    while (fscanf(fp,
       "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
       &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION,
       &e.ATTENDANCE, &e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
count++;}
  printf("Total Number Of Employees are:%d\n", count);

}

/*-------------------------------------------
---------STATISTICS MODULE FUNCTIONS---------
--------------------------------------------*/
void statistics(){
    int choice;
    while(1){
        printStatisticsmenu();
    choice=getValidInt("ENTER YOUR CHOICE=");

        switch (choice)
        {
        case 1:
            attendance_Record();
            break;

        case 2:
            view_Attendance();
            break;

        case 3:
            Display();
            break;

        case 4:
            Percentage();
            break;

        case 5:
            Display_Designation();
            break;

        case 6:
            departmentWiseList();
            break;

        case 7:
            printf("GOING BACK...\n");
            return;

        default:
            printf("INVALID CHOICE\n");
    }}

}

// VIEW ALL ATTENDANCE
void attendance_Record()
{
    FILE *fp = fopen("employee.txt", "r");       //FILE OPEN IN READ MODE
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;
    }

    struct employee e;
    printf("----------------------------------------\n");
    printf("%-5s %-20s %-10s\n", "ID", "NAME", "ATTENDANCE");
     printf("----------------------------------------\n");

     // READ IT UNTIL ALL DATA IS READ
    while (fscanf(fp,
                  "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
                  &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION, &e.ATTENDANCE,&e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)  
    {
      char attWithPercent[10];

      // STORES ATTENDANCE VALUE IN A STRING AND ADD %
       sprintf(attWithPercent, "%d%%", e.ATTENDANCE);

       printf("%-5d %-20s %-10s\n", e.ID, e.NAME, attWithPercent);

    }
   //CLOSE FILE
    fclose(fp);
    printf("\nATTENDANCE RECORD DISPLAYED!\n");
    printf("_____________________________________________________________\n");
}

// VIEW ATTENDANCE BY ID
void view_Attendance()
{
    FILE *fp = fopen("employee.txt", "r");  // FILE OPEN IN READ MODE
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;
    }

    struct employee e;
    int id,found=0;

    // ENTER THE DESIRED ID
    id=getValidInt("ENTER EMPLOYEE ID=");
    

    printf("----------------------------------------\n");
    printf("%-5s %-20s %-10s\n", "ID", "NAME", "ATTENDANCE");
printf("----------------------------------------\n");
 
 // READ IT UNTIL ALL DATA IS READ
    while (fscanf(fp,
                  "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
                  &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY,e.DEPARTMENT, e.DESIGNATION, &e.ATTENDANCE,&e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
        if (e.ID == id)
        {
            found=1;
            // STORES ATTENDANCE VALUE IN A STRING AND ADD %
            char attWithPercent[10];
           sprintf(attWithPercent, "%d%%", e.ATTENDANCE);
            
          printf("%-5d %-20s %-10s\n", e.ID, e.NAME, attWithPercent);

        }
    }

    // CLOSE FILE
    fclose(fp);

 if (found==0)
        printf("No employee with ID %d found!\n", id);
else
    printf("\nATTENDANCE DISPLAYED!\n");
    printf("_____________________________________________________________\n");
}


// DISPLAY EMPLOYEES BY GENDER
void Display()
{
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;
    }

    struct employee e;
    char gender[20];

    int choice;

    // CHOOSE THE GENDER TO BE DISPLAYED
    choice=getValidInt("Enter 1 for Male  or 2 for Female :");

    if (choice == 1)
        strcpy(gender, "male");
    else if (choice == 2)
        strcpy(gender, "female");
    else
    {
        printf("Invalid choice!\n");
        fclose(fp);
        return;
    }

    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-18s %-5s %-10s %-10s %-15s %-18s %-6s %-5s %-15s %s\n", 
           "ID", "NAME", "AGE", "GENDER", "SALARY", "DEPARTMENT", "DESIGNATION", "ATT%", "YOS", "CONTACT", "EMAIL"); 
    printf("--------------------------------------------------------------------------------------------------------------------------\n");

    // READ IT UNTIL ALL DATA IS READ
    while (fscanf(fp,
                  "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
                  &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY,
                  e.DEPARTMENT, e.DESIGNATION, &e.ATTENDANCE, &e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    { 
        if (strcmp(gender, e.GENDER) == 0)
        {
            // STORES ATTENDANCE VALUE IN A STRING AND ADD %
            char attWithPercent[10];
            sprintf(attWithPercent, "%d%%", e.ATTENDANCE);

            printf("%-5d %-18s %-5d %-10s %-10d %-15s %-18s %-6s %-5d %-15lld %s\n", 
                   e.ID, e.NAME, e.AGE, e.GENDER, e.SALARY, e.DEPARTMENT, e.DESIGNATION, 
                   attWithPercent, e.YEAROFSERVICE, e.CONTACT, e.EMAIL);
        }
    }
// CLOSE FILE
    fclose(fp);
    printf("\nDATA DISPLAYED!\n");
    printf("_____________________________________________________________\n");
}

// PERCENTAGE OF GENDER
void Percentage()
{
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR LOADING THE FILE!");
        return;
    }

    int count = 0, total = 0;
    struct employee e;
    char gender[20];

    int choice;
    //CHOOSE THE GENDER TO FIND PERCENTAGE
    choice=getValidInt("Enter 1 for Male percentage or 2 for Female percentage:");


    if (choice == 1)
        strcpy(gender, "male");
    else if (choice == 2)
        strcpy(gender, "female");
    else
    {
        printf("Invalid choice!\n");
        fclose(fp);
        return;
    }

    // READ IT UNTIL ALL DATA IS READ
    while (fscanf(fp,
                  "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
                  &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION, &e.ATTENDANCE,&e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
    {
        total++;

        if (strcmp(gender, e.GENDER) == 0)
        {
            count++;
        }
    }

    //CLOSE FILE
    fclose(fp);

    if (total == 0)
    {
        printf("No employee data found.\n");
        return;
    }

    float percentage = ((float)count / total) * 100;



    // ---------- PRINT TABLE ----------s
    printf("--------------------------------------------------\n");
    printf("%-15s | %-15s\n", "GENDER", "PERCENTAGE(%)");
    printf("--------------------------------------------------\n");
    printf("%-15s | %-14.2f%%\n", gender, percentage);
    printf("--------------------------------------------------\n");
}

// DISPLAY DESIGNATIONS
void Display_Designation() {
    FILE *fp;
    struct employee e;
    char desig[20];

    getValidstr(desig,"Enter designation to search: ");
 
// FILE OPEN IN READ MODE
    fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n----------------------------------------\n");
    printf("| %-5s | %-15s | %-15s |\n", "ID", "Name", "Designation");
    printf("----------------------------------------\n");

    int found = 0;
    
    // READ IT UNTIL ALL DATA IS READ(12)
    while (fscanf(fp,
                  "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
                  &e.ID, e.NAME, &e.AGE, e.GENDER, &e.SALARY, e.DEPARTMENT, e.DESIGNATION, &e.ATTENDANCE,&e.YEAROFSERVICE, &e.CONTACT, e.PASSWORD, e.EMAIL) == 12)
 {
        if (strcmp(e.DESIGNATION, desig) == 0) {
            printf("| %-5d | %-15s | %-15s |\n", e.ID, e.NAME, e.DESIGNATION);
            found = 1;
        }
    }

    if (found==0) {
        printf("|      No employee found with designation '%s'      |\n", desig);
    }

    printf("----------------------------------------\n");
    // CLOSE FILE
    fclose(fp);
}

// DEPARTMENT WISE LIST
void departmentWiseList() {
    struct employee emp[50];
    int n = 0;
   //open file
    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("ERROR OPENING FILE!\n");
        return;
    }

    // Load all employees
    while (fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp[n].ID, emp[n].NAME, &emp[n].AGE, emp[n].GENDER,
        &emp[n].SALARY, emp[n].DEPARTMENT, emp[n].DESIGNATION,
        &emp[n].ATTENDANCE, &emp[n].YEAROFSERVICE, &emp[n].CONTACT,
        emp[n].PASSWORD, emp[n].EMAIL) == 12) {
        n++;
    }

    // close file
    fclose(fp);

    if(n == 0) {
        printf("No employee data found.\n");
        return;
    }

    char dept[50];
    getValidstr(dept, "Enter Department Name: ");

    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-15s %-15s %-10s\n", "ID", "NAME", "SALARY", "DEPARTMENT", "DESIGNATION", "GENDER");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    int found = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(emp[i].DEPARTMENT, dept) == 0) {
            found = 1;
            printf("%-5d %-20s %-10d %-15s %-15s %-10s\n",
                   emp[i].ID, emp[i].NAME, emp[i].SALARY, emp[i].DEPARTMENT, emp[i].DESIGNATION, emp[i].GENDER);
        }
    }

    if(!found) {
        printf("No employees found in the %s department.\n", dept);
    }

    printf("--------------------------------------------------------------------------------------------------------------\n");
}


/*===========================================
=============SALARY MODULE===================
=============================================*/
void salary(){
    int choice;
    while(1){
        printSalarysmenu();
      choice=getValidInt("ENTER YOUR CHOICE=");

        switch (choice)
        {
        case 1:
            HighLow();
            break;

        case 2:
            avgsalary();
            break;

        case 3:
            sortEmployeesByName();
            break;

        case 4:
            sortEmployeesBySalary();
            break;

        case 5:
            calculateBonus();
            break;

        case 6:
            pensioncalculator();
            break;

        case 7:
            printf("GOING BACK...\n");
            return;

        default:
            printf("INVALID CHOICE\n");
    }}

}

//HIGHEST LOWEST
void HighLow() {
    struct employee emp[100];
    int n = 0;
    int choice;


    FILE *fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("ERROR OPENING FILE!\n");
        return ;
    }

    choice=getValidInt("Enter 1 for Highest salary or 2 for Lowest salary:");

      if(choice != 1 && choice !=2)
      {
        printf("INVALID INPUT");
        fclose(fp);
        return;
      }

    // Read all records
 while(fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp[n].ID, emp[n].NAME, &emp[n].AGE, emp[n].GENDER,&emp[n].SALARY,
        emp[n].DEPARTMENT, emp[n].DESIGNATION,&emp[n].ATTENDANCE,
        &emp[n].YEAROFSERVICE,&emp[n].CONTACT, emp[n].PASSWORD, emp[n].EMAIL) == 12) {
        n++;
    }

    if(n == 0) {
        printf("No data found. Enter data!\n");
        return ;
    }

    // Find minimum salary
    int min = emp[0].SALARY;
    int max=emp[0].SALARY;
    int index=0;
    
    if(choice ==1)
       {

        for(int i = 1; i < n; i++) {
        if(emp[i].SALARY > max) {
            max = emp[i].SALARY;
            index=i;
        }
    }
            // Print highest salary employee
            printf("\n--------HIGHEST SALARY---------\n");
    printf("ID:%d | NAME:%s | SALARY:%d | DEPARTMENT:%s | DESIGNATION:%s | GENDER:%s\n",
       emp[index].ID, emp[index].NAME, max, emp[index].DEPARTMENT, emp[index].DESIGNATION, emp[index].GENDER);

    printf("--------------------------------------------------------------------------------------------\n");
 }

    if(choice ==2)
    {
    for(int i = 1; i < n; i++) {
        if(emp[i].SALARY < min) {
            min = emp[i].SALARY;
            index=i;
        }
    }
        // Print lowest salary employee
    printf("\n--------LOWEST SALARY---------\n");
    printf("ID:%d | NAME:%s | SALARY:%d | DEPARTMENT:%s | DESIGNATION:%s | GENDER:%s\n",
       emp[index].ID, emp[index].NAME, min, emp[index].DEPARTMENT, emp[index].DESIGNATION, emp[index].GENDER);

    printf("--------------------------------------------------------------------------------------------\n");
   } 

    

     fclose(fp); // close file after printing
}


// AVERAGE SALARY
void avgsalary() {
    struct employee emp[50];
    int sum = 0, n = 0;

    FILE *fp = fopen("employee.txt", "r");
    if(fp == NULL) {
        printf("ERROR OPENING FILE!\n");
        return;
    }

    while(fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp[n].ID, emp[n].NAME, &emp[n].AGE, emp[n].GENDER,&emp[n].SALARY,
        emp[n].DEPARTMENT, emp[n].DESIGNATION,&emp[n].ATTENDANCE,
        &emp[n].YEAROFSERVICE,&emp[n].CONTACT, emp[n].PASSWORD, emp[n].EMAIL) == 12) {
        n++;
    }

    if(n == 0) { printf("No data found.\n"); fclose(fp); return; }

    // Sum Of All Salary
    for(int i = 0; i < n; i++)
        sum += emp[i].SALARY;

    float avg = (float)sum / n;

    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-15s %-15s %-10s\n", "ID", "NAME", "SALARY", "DEPARTMENT", "DESIGNATION", "GENDER");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-5d %-20s %-10d %-15s %-15s %-10s\n",
               emp[i].ID, emp[i].NAME, emp[i].SALARY, emp[i].DEPARTMENT, emp[i].DESIGNATION, emp[i].GENDER);
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("Average Salary: %.2f\n", avg);
    printf("--------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);
}

//SORT BY NAME
void sortEmployeesByName() {
    struct employee emp[50];
    int n = 0;

    FILE *fp = fopen("employee.txt", "r");
    if(fp == NULL) 
    { 
        printf("ERROR OPENING FILE!\n"); return; 
    }

    while(fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp[n].ID, emp[n].NAME, &emp[n].AGE, emp[n].GENDER, &emp[n].SALARY,
        emp[n].DEPARTMENT, emp[n].DESIGNATION, &emp[n].ATTENDANCE,
        &emp[n].YEAROFSERVICE, &emp[n].CONTACT, emp[n].PASSWORD, emp[n].EMAIL) == 12) {
        n++;
    }

    if(n == 0)
     {
         printf("No data found.\n"); fclose(fp); return; 
        }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(strcmp(emp[i].NAME, emp[j].NAME) > 0){
                struct employee tmp = emp[i];
                emp[i] = emp[j];
                emp[j] = tmp;
            }
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-15s %-15s %-10s\n", "ID", "NAME", "SALARY", "DEPARTMENT", "DESIGNATION", "GENDER");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-5d %-20s %-10d %-15s %-15s %-10s\n",
               emp[i].ID, emp[i].NAME, emp[i].SALARY, emp[i].DEPARTMENT, emp[i].DESIGNATION, emp[i].GENDER);
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);
}

//SORT BY SALARY
void sortEmployeesBySalary() {
    struct employee emp[50];
    int n = 0;

    FILE *fp = fopen("employee.txt", "r");
    if(fp == NULL) { printf("ERROR OPENING FILE!\n"); return; }

    // Reading All Employees
    while(fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp[n].ID, emp[n].NAME, &emp[n].AGE, emp[n].GENDER, &emp[n].SALARY,
        emp[n].DEPARTMENT, emp[n].DESIGNATION, &emp[n].ATTENDANCE,
        &emp[n].YEAROFSERVICE, &emp[n].CONTACT, emp[n].PASSWORD, emp[n].EMAIL) == 12) {
        n++;
    }

    if(n == 0) 
    { printf("No data found.\n"); fclose(fp); return; }
   
    //Sorting Highest->Lowest
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(emp[i].SALARY < emp[j].SALARY){
                struct employee tmp = emp[i];
                emp[i] = emp[j];
                emp[j] = tmp;
            }
        }
    }

    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-20s %-10s %-15s %-15s %-10s\n", "ID", "NAME", "SALARY", "DEPARTMENT", "DESIGNATION", "GENDER");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-5d %-20s %-10d %-15s %-15s %-10s\n",
               emp[i].ID, emp[i].NAME, emp[i].SALARY, emp[i].DEPARTMENT, emp[i].DESIGNATION, emp[i].GENDER);
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);
}

// CALCULATE BONUS
void calculateBonus() {
    struct employee emp;
    int id;
    float bonusRate;

    id=getValidInt("ENTER THE ID=");
    printf("Enter bonus (%%): ");
    scanf("%f", &bonusRate);

    FILE *fp = fopen("employee.txt", "r");
    if(fp == NULL) 
    { printf("ERROR OPENING FILE!\n"); 
        return; }

    int found = 0;
    while(fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp.ID, emp.NAME, &emp.AGE, emp.GENDER, &emp.SALARY,
        emp.DEPARTMENT, emp.DESIGNATION, &emp.ATTENDANCE,
        &emp.YEAROFSERVICE,&emp.CONTACT, emp.PASSWORD, emp.EMAIL) == 12)
    {
        // Calculate Bonus
        if(emp.ID == id){
            float bonus = emp.SALARY * (bonusRate / 100);    
            float newSalary = emp.SALARY + bonus;  // Calculate salary after bonus

            
            char bonusWithPercent[10];
            sprintf(bonusWithPercent, "%.2f%%", bonusRate);  // bonus rate with %

            printf("--------------------------------------------------------------------------------------------------------------\n");
            printf("%-5s %-20s %-10s %-15s %-15s %-10s %-10s %-10s\n",
                   "ID", "NAME", "SALARY", "DEPARTMENT", "DESIGNATION", "GENDER", "BONUS","NEW SALARY");
            printf("--------------------------------------------------------------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-15s %-15s %-10s %-10s %-10.2f\n",
                   emp.ID, emp.NAME, emp.SALARY, emp.DEPARTMENT, emp.DESIGNATION, emp.GENDER, bonusWithPercent,newSalary);
            printf("--------------------------------------------------------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }

    if(found==0) 
    {printf("Employee with ID %d not found.\n", id);}
    fclose(fp);
}

//PENSION CALCULATOR
void pensioncalculator(){
    struct employee emp;
    int id;
    float pension, ContributionRate;
 

    id=getValidInt("Enter Employee ID: ");
    printf("Enter Contribution Rate (%%): ");
    scanf("%f", &ContributionRate);

    FILE *fp = fopen("employee.txt", "r");
    if(fp == NULL) 
    { printf("ERROR OPENING FILE!\n"); 
        return; }

    int found = 0;

    // Load all employees
    while(fscanf(fp,
        "ID=%d|NAME=%[^|]|AGE=%d|GENDER=%[^|]|SALARY=%d|DEPARTMENT=%[^|]|DESIGNATION=%[^|]|ATTENDANCE=%d|YEAR_OF_SERVICE=%d|CONTACT=%lld|PASSWORD=%[^|]|EMAIL=%[^\n]\n",
        &emp.ID, emp.NAME, &emp.AGE, emp.GENDER, &emp.SALARY,
        emp.DEPARTMENT, emp.DESIGNATION, &emp.ATTENDANCE,
        &emp.YEAROFSERVICE,&emp.CONTACT, emp.PASSWORD, emp.EMAIL) == 12)
    {
        //Pension Calculation
        if(emp.ID == id){
            pension = emp.SALARY * emp.YEAROFSERVICE * (ContributionRate/100);
            found = 1;

            printf("--------------------------------------------------------------------------------------------------------------\n");
            printf("%-5s %-20s %-10s %-15s %-15s %-10s %-5s %-10s\n",
                   "ID", "NAME", "SALARY", "DEPARTMENT", "DESIGNATION", "GENDER","YOS","PENSION");
            printf("--------------------------------------------------------------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-15s %-15s %-10s %-5d %-10.2f\n",
                   emp.ID, emp.NAME, emp.SALARY, emp.DEPARTMENT, emp.DESIGNATION,emp.GENDER, emp.YEAROFSERVICE, pension);
            printf("--------------------------------------------------------------------------------------------------------------\n");
            break;
        }
    }

    if(!found)
     printf("Employee with ID %d not found.\n", id);


    fclose(fp);
}