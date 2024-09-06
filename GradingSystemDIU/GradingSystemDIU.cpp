#include<stdio.h>
int main() {
int marks;
printf("Grading system in Daffodil International University \n");
printf("Class attendance marks: 7 ");
printf("Assignment marks: 5 ");
printf("Presentation (Mandatory) marks: 8 ");
printf("3 Quizzes marks: 15");
printf("Midterm Test marks: 25 ");
printf("Semester Final Examination marks: 40");
printf("Total marks: 100 ");
printf("Enter your  marks (0-100) :");
scanf("%d", &marks);

if (marks >= 0 && marks < 39 )
{
   printf("Grades: F \n");
   printf("Grade-Point Equivlaent : 0.00 \n");
   printf("Fail \n");
} else if (marks >= 40 && marks <= 45)
{
   printf("Grades: D \n");
   printf("Grade-Point Equivlaent : 2.00 \n");
   printf("Remarks :Pass \n");
   printf("Pass \n");

} else if (marks >= 46 && marks <= 49)
{
   printf("Grades: C \n");
   printf("Grade-Point Equivlaent : 2.25 \n");
   printf("Remarks :Below Average \n");
   printf("Pass \n");

} else if (marks >= 50 && marks <= 54 )
{
   printf("Grades: C+ \n");
   printf("Grade-Point Equivlaent : 2.50 \n");
   printf("Remarks :Average \n");
   printf("Pass \n");

} else if (marks >= 55 && marks <= 59)
{
   printf("Grades: B- \n");
   printf("Grade-Point Equivlaent : 2.75 \n");
   printf("Remarks :Above Average \n");
   printf("Pass \n");

} else if (marks >= 60 && marks <= 64 )
{
   printf("Grades: B \n");
   printf("Grade-Point Equivlaent : 2.33 \n");
   printf("Remarks :Satisfactory \n");
   printf("Pass \n");

} else if (marks >= 65 && marks <= 69)
{
   printf("Grades: B+ \n");
   printf("Grade-Point Equivlaent : 2.67 \n");
   printf("Remarks :Good \n");
   printf("Pass \n");
} else if (marks >= 70 && marks <= 74 )
{
   printf("Grades: A- \n");
   printf("Grade-Point Equivlaent : 3.00 \n");
   printf("Remarks :Very Good \n");
   printf("Pass \n");

} else if (marks >= 75 && marks <= 79 )
{
   printf("Grades: A \n");
   printf("Grade-Point Equivlaent : 3.75 \n");
   printf("Remarks :Excellent \n");
   printf("Pass \n");

} else if (marks >= 80 && marks <= 100 )
{
   printf("Grades: A+ \n");
   printf("Grade-Point Equivlaent : 4.00 \n");
   printf("Remarks :Outstanding \n");
   printf("Pass \n");
   

} else {
    printf("invalid marks");
}
return 0;
}