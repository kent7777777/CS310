#include <stdio.h>

typedef struct{
	char* name;
	char* adress;
	int ssnum;
	int age;
	char* gender;
	char* department;
	int salary;
} Employee;

void displaye(Employee e){
	printf("Name: %s\n Adress: %s\n Social Security: %d\n Age: %d\n Gender: %s\n Department: %s\n, Salary: %d\n", e.name, e.adress, e.ssnum, e.age, e.gender, e.department, e.salary);
}
