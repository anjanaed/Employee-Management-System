#include <stdio.h>
#include <stdlib.h>

struct Emoloyees{
    int id;
    char name[10];
    double salary;
};

void addemp(struct Emoloyees **employee,int *number);
void showemp(struct Emoloyees *emoloyee,int number);
void searchemp(struct Emoloyees *emoloyee,int number, int id);
void updateemp(struct Emoloyees *emoloyee,int number, int id);
void delemp(struct Emoloyees **emoloyee,int *number, int id);

int main(){
    struct Emoloyees *employee=NULL;
    int choice,id;
    int number=0;

    printf("Welcome to Employee Management System!\n\n");
    do{
        printf("\n\n1.Add Employee\n");
        printf("2.Show Employee\n");
        printf("3.Search Employee\n");
        printf("4.Update Employee Salary\n");
        printf("5.Delete Employee\n");
        printf("6.Exit\n\n");
        printf("Enter the Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addemp(&employee,&number);
                break;
            case 2:
                showemp(employee,number);
                break;
            case 3:
                printf("Enter the ID: ");
                scanf("%d",&id);
                searchemp(employee,number,id);
                break;
            case 4:
                printf("Enter the ID: ");
                scanf("%d",&id);
                updateemp(employee,number,id);
                break;
            case 5:
                printf("Enter the ID: ");
                scanf("%d",&id);
                delemp(&employee,&number,id);
                break;
            case 6:
                break;
        }
    }while(choice!=6);
    free(employee);
    return 0;
}

void addemp(struct Emoloyees **employee,int *number){
    *employee=(struct Emoloyees*) realloc(*employee,((*number)+1)*sizeof(struct Emoloyees));
    if(*employee==NULL){
        printf("Memory Allocation Failed!");
        exit(1);
    }
    printf("Enter Employee ID: ");
    scanf("%d",&(*employee)[*number].id);
    printf("Enter Employee Name: ");
    scanf("%s",(*employee)[*number].name);
    printf("Enter Employee Salary: ");
    scanf("%lf",&(*employee)[*number].salary);
    (*number)++;
    printf("Succeed!\n");
}

void showemp(struct Emoloyees *employee,int number){
    printf("\n\n***Employee Details***\n\n");
    printf("ID\tName\tSalary\t\n");
    for(int i=0;i<number;i++){
        printf("%d\t%s\t%.2lf\n",(employee)[i].id,employee[i].name,employee[i].salary);
    }
}

void searchemp(struct Emoloyees *employee,int number, int id){
    int found=0;
    for(int i=0;i<number;i++){
        if(employee[i].id==id){
            printf("\nEmployee found\n");
            printf("ID\tName\tSalary\t\n");
            printf("%d\t%s\t%.2lf\n",employee[i].id,employee[i].name,employee[i].salary);
            found=1;
        }
    }
    if (!found){
        printf("\nQuery Not Found!");
    }
}

void updateemp(struct Emoloyees *employee,int number, int id){
    int found=0;
    for(int i=0;i<number;i++){
        if(employee[i].id==id){
            printf("Enter the new Salary: ");
            scanf("%lf",&employee[i].salary);
            printf("Successfully Updated!\n");
            found=1;
        }
    }
    if(!found){
        printf("Employee ID not Found!");
    }
}

void delemp(struct Emoloyees **employee,int *number, int id){
    int found=0;
    for(int i=0;i<(*number);i++){
        if((*employee)[i].id==id){
            for(int j=i;j<(*number)-1;j++){
                (*employee)[j]=(*employee)[j+1];
            }
            (*number)--;
            found=1;
            *employee=(struct Emoloyees*) realloc(*employee,(*number)*sizeof(struct Emoloyees));
            printf("Employee Deleted\n");
        }
    }
    if(!found){
        printf("Employee ID not Found!");
    }
}