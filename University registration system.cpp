#Belal Mohamed Sameh
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef struct StudentData StudentData;
typedef struct StudentData* StudentDataPtr;

typedef struct FinishedCourses FinishedCourses;
typedef struct FinishedCourses* FinishedCoursesPtr;

typedef struct CurrentCourses CurrentCourses;
typedef struct CurrentCourses* CurrentCoursesPtr;

struct FinishedCourses
{
    char CourseCode[8],CourseName[30],LecturerFirstName[30],LecturerMiddleName[30],LecturerLastName[30],
         GTAFirstName[30],GTAMiddleName[30],GTALastName[30];

    int NumberOfTimes, CourseCreditHours, CourseSemester, CourseYear;

    float Course7thMark,Course12thMark, CourseYearWork, CourseFinalMark, CoursePoints;

    double CourseTotalMark;

    FinishedCoursesPtr FinNextCourse;
};

FinishedCoursesPtr Head2=NULL;

struct CurrentCourses
{
    char CourseCode[8],CourseName[30],LecturerFirstName[30],LecturerMiddleName[30],LecturerLastName[30],
         GTAFirstName[30],GTAMiddleName[30],GTALastName[30];

    int NumberOfTimes, CourseCreditHours, CourseSemester, CourseYear;

    CurrentCoursesPtr CurNextCourse;
};

CurrentCoursesPtr Head3=NULL;

struct StudentData
{
    char FirstName[30],MiddleName[30],LastName[30],InstructorName[50],InstructorCode[15],
         Nationality[15],StudentId[15],Password[10],Country[15],Governorate[15],City[15],
         District[15],StreetName[20],HouseNumber[5],FlatNumber[5],PostalCode[10],
         MailingCountry[15],MailingGovernorate[15],MailingCity[15],MailingDistrict[15],
         MailingStreetName[20],MailingHouseNumber[5],MailingFlatNumber[5],MailingPostalCode[10],
         StudentEmail[40],PhoneNumber[20],HomePhoneNumber[20],RegNum[20],Gender[10],IdType[15],
         EnrolmentTerm[3],EnrolmentYear[5],Department[50],TypeOfFunding[15];

    int DayOfBirth,MonthOfBirth,YearOfBirth,Term,MaxCreditHours,Age,NumberOfPayments,FinishedCourses,CurrentCourses;

    double TotalGPA,FinishedCreditHours,CurrentCreditHours,RemainingCreditHours,TotalPayment;

    double AmountPaid[20];

    int DayOfTransaction[20],MonthOfTransaction[20],YearOfTransaction[20];

    long long NumberOfTransaction[20];

    FinishedCoursesPtr  GetFinishedCourses;
    CurrentCoursesPtr GetCurrentCourses;
    StudentDataPtr next;
};

StudentDataPtr Head=NULL;
StudentDataPtr sorted = NULL;

void AddStData(char *FirstName, char *MiddleName, char *LastName, char *InstructorName, char *InstructorCode, char *Nationality,
               char *StudentId,char *Password,char *Country, char *Governorate, char *City, char *District, char *StreetName,
               char *HouseNumber,char *FlatNumber,char *PostalCode, char *MailingCountry, char *MailingGovernorate,char *MailingCity,
               char *MailingDistrict, char *MailingStreetName,char *MailingHouseNumber, char *MailingFlatNumber,char *MailingPostalCode,
               char *StudentEmail, char *PhoneNumber,char *HomePhoneNumber, char *RegNum,int DayOfBirth,int MonthOfBirth,int YearOfBirth,
               char *EnrolmentTerm, char *EnrolmentYear,int Term,int MaxCreditHours, int Department, int Gender,int IdType,
               double FinishedCreditHours,double CurrentCreditHours,double TotalGPA,int Age,int TypeOfFunding,
               int NumberOfPayments,double TotalPayment,double *AmountPaid,long long *NumberOfTransaction,int *DayOfTransaction,
               int *MonthOfTransaction,int *YearOfTransaction,int FinishedCourses,int CurrentCourses)
{
    StudentDataPtr current = (StudentDataPtr) malloc(sizeof(struct StudentData));

    strcpy(current->FirstName,FirstName);
    strcpy(current->MiddleName,MiddleName);
    strcpy(current->LastName,LastName);
    current->DayOfBirth=DayOfBirth;
    current->MonthOfBirth=MonthOfBirth;
    current->YearOfBirth=YearOfBirth;
    current->Age=Age;

    if(Gender==1)
        strcpy(current->Gender,"Male");
    else
        strcpy(current->Gender,"Female");
    strcpy(current->Nationality,Nationality);

    if(IdType==1)
        strcpy(current->IdType,"National Id");
    else
        strcpy(current->IdType,"Passport");

    strcpy(current->StudentId,StudentId);
    strcpy(current->Password,Password);
    strcpy(current->Country,Country);
    strcpy(current->Governorate,Governorate);
    strcpy(current->City,City);
    strcpy(current->District,District);
    strcpy(current->StreetName,StreetName);
    strcpy(current->HouseNumber,HouseNumber);
    strcpy(current->FlatNumber,FlatNumber);
    strcpy(current->PostalCode,PostalCode);
    strcpy(current->MailingCountry,MailingCountry);
    strcpy(current->MailingGovernorate,MailingGovernorate);
    strcpy(current->MailingCity,MailingCity);
    strcpy(current->MailingDistrict,MailingDistrict);
    strcpy(current->MailingStreetName,MailingStreetName);
    strcpy(current->MailingHouseNumber,MailingHouseNumber);
    strcpy(current->MailingFlatNumber,MailingFlatNumber);
    strcpy(current->MailingPostalCode,MailingPostalCode);
    strcpy(current->StudentEmail,StudentEmail);
    strcpy(current->PhoneNumber,PhoneNumber);
    strcpy(current->HomePhoneNumber,HomePhoneNumber);
    strcpy(current->RegNum,RegNum);
    strcpy(current->InstructorName,InstructorName);
    strcpy(current->InstructorCode,InstructorCode);
    strcpy(current->EnrolmentTerm,EnrolmentTerm);
    strcpy(current->EnrolmentYear,EnrolmentYear);

    if(Department==1)
        strcpy(current->Department,"Global Studies");
    else if(Department==2)
        strcpy(current->Department,"Robotics");
    else if(Department==3)
        strcpy(current->Department,"Intelligence system");
    else if(Department==4)
        strcpy(current->Department,"Business analytics");
    else if(Department==5)
        strcpy(current->Department,"Bio computing");

    if(TypeOfFunding==1)
        strcpy(current->TypeOfFunding,"Self-Funded");
    else
        strcpy(current->TypeOfFunding,"Grant-Funded");

    if (TypeOfFunding==1)
    {
        current->TotalPayment=TotalPayment;
        current->NumberOfPayments=NumberOfPayments;
        for(int i=0; i<NumberOfPayments; i++)
        {
            current->AmountPaid[i]=*(AmountPaid+i);
            current->NumberOfTransaction[i]=*(NumberOfTransaction+i);
            current->DayOfTransaction[i]=*(DayOfTransaction+i);
            current->MonthOfTransaction[i]=*(MonthOfTransaction+i);
            current->YearOfTransaction[i]=*(YearOfTransaction+i);
        }
    }

    current->FinishedCourses=FinishedCourses;
    current->CurrentCourses=CurrentCourses;
    current->Term=Term;
    current->MaxCreditHours=MaxCreditHours;
    current->FinishedCreditHours=FinishedCreditHours;
    current->CurrentCreditHours=CurrentCreditHours;
    current->RemainingCreditHours=MaxCreditHours-FinishedCreditHours-CurrentCreditHours;
    current->TotalGPA=TotalGPA;

    current->next = NULL;
    current->GetFinishedCourses=Head2;
    current->GetCurrentCourses=Head3;

    if(Head == NULL)
    {
        Head = current;
        return;
    }

    StudentDataPtr temp = Head;

    while(temp->next != NULL)
        temp = temp -> next;

    temp->next = current;
}

void GetPersonlInfo(char *FirstName, char *MiddleName,char *LastName,int *Gender,char *Nationality,int *IdType,
                    char *StudentId,char *Password,int *DayOfBirth, int *MonthOfBirth,int *YearOfBirth)
{
    int flag=0;
    cout<<"----------------"<<endl;
    cout<<"Personal information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"First name : ";
    cin>>FirstName;
    cout<<"Middle name : ";
    cin>>MiddleName;
    cout<<"Last name : ";
    cin>>LastName;
    cout<<"Day of birth : ";
    cin>>*(DayOfBirth);
    while(*(DayOfBirth)>31 || *(DayOfBirth)<0)
    {
        cout<<"Incorrect day entered please enter the correct day of birth : ";
        cin>>*(DayOfBirth);
    }
    cout<<"Month of birth : ";
    cin>>*(MonthOfBirth);
    while(*(MonthOfBirth)>12 || *(MonthOfBirth)<0)
    {
        cout<<"Incorrect month entered please enter the correct month of birth : ";
        cin>>*(MonthOfBirth);
    }
    cout<<"Year of birth : ";
    cin>>*(YearOfBirth);
    while(*(YearOfBirth)>2022 || *(YearOfBirth)<1980)
    {
        cout<<"Incorrect year entered please enter the correct year of birth : ";
        cin>>*(YearOfBirth);
    }
    cout<<"Gender ( choose 1 for male and 0 for female ) : ";
    cin>>*(Gender);
    while(*(Gender)>1 || *(Gender)<0)
    {
        cout<<"Incorrect choice please choose 1 for male and 0 for female : ";
        cin>>*(Gender);
    }
    cout<<"Nationality : ";
    cin>>Nationality;
    cout<<"Id type (choose 1 for national id and 0 for passport) : ";
    cin>>*(IdType);
    while(*(IdType)>1 || *(IdType)<0)
    {
        cout<<"Incorrect choice please choose 1 for national id and 0 for passport : ";
        cin>>*(IdType);
    }
    cout<<"Student id : ";
    cin>>StudentId;
    if (*IdType==1)
    {
        while(flag==0)
        {
            if(strlen(StudentId)!=14)
            {
                cout<<"Incorrect Id entered please re enter your id that consist of 14 digit : ";
                cin>>StudentId;
                flag=0;
                continue;
            }
            if(StudentId[0]=='2' && *YearOfBirth>1999)
            {
                cout<<"Incorrect first digit of Id entered please re enter your id that consist of 14 digit : ";
                cin>>StudentId;
                flag=0;
                continue;
            }
            if(StudentId[0]=='3' && *YearOfBirth<2000)
            {
                cout<<"Incorrect first digit of Id entered please re enter your id that consist of 14 digit : ";
                cin>>StudentId;
                flag=0;
                continue;
            }
            flag=1;
        }
    }
    cout<<"Password : ";
    cin>>Password;
}


void GetContactDetails(char *Country,char *Governorate,char *City,char *District,char *StreetName,char *HouseNumber,char *FlatNumber,
                       char *PostalCode,char *MailingCountry, char *MailingGovernorate,char *MailingCity, char *MailingDistrict,
                       char *MailingStreetName, char *MailingHouseNumber,char *MailingFlatNumber, char *MailingPostalCode,char *StudentEmail,
                       char *PhoneNumber,char *HomePhoneNumber)
{
    int AddressCheck;
    cout<<"----------------"<<endl;
    cout<<"Contact details"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Country : ";
    cin>>Country;
    cout<<"Governorate : ";
    cin>>Governorate;
    cout<<"City : ";
    cin>>City;
    cout<<"District : ";
    cin>>District;
    cout<<"Street name : ";
    cin>>StreetName;
    cout<<"House number : ";
    cin>>HouseNumber;
    cout<<"Flat number : ";
    cin>>FlatNumber;
    cout<<"Postal code : ";
    cin>>PostalCode;
    cout<<"Is your mailing address the same as your own address ? Choose 1 for yes and 0 for no : ";
    cin>>AddressCheck;
    while(AddressCheck>1 || AddressCheck<0)
    {
        cout<<"Incorrect choice please choose 1 for yes and 0 for no : ";
        cin>>AddressCheck;
    }
    if (AddressCheck==1)
    {
        strcpy(MailingCountry,Country);
        strcpy(MailingGovernorate,Governorate);
        strcpy(MailingCity,City);
        strcpy(MailingDistrict,District);
        strcpy(MailingStreetName,StreetName);
        strcpy(MailingHouseNumber,HouseNumber);
        strcpy(MailingFlatNumber,FlatNumber);
        strcpy(MailingPostalCode,PostalCode);
    }
    else
    {
        cout<<"Mailing country: ";
        cin>>MailingCountry;
        cout<<"Mailing governorate : ";
        cin>>MailingGovernorate;
        cout<<"Mailing city :";
        cin>>MailingCity;
        cout<<"Mailing district :";
        cin>>MailingDistrict;
        cout<<"Mailing street name :";
        cin>>MailingStreetName;
        cout<<"Mailing house number :";
        cin>>MailingHouseNumber;
        cout<<"Mailing flat number :";
        cin>>MailingFlatNumber;
        cout<<"Mailing postal code :";
        cin>>MailingPostalCode;
    }
    cout<<"Student email : ";
    cin>>StudentEmail;
    cout<<"Phone number : ";
    cin>>PhoneNumber;
    cout<<"Home phone number : ";
    cin>>HomePhoneNumber;
}


int StuCon=0;
void GetUniDetails(char *EnrolmentTerm,char *EnrolmentYear,char *RegNum,int *Department, char *InstructorName, char *InstructorCode,int *FinishedCourses,int *CurrentCourses)
{
    char TempDepartment[30];
    cout<<"----------------"<<endl;
    cout<<"University details"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Instructor name : ";
    cin>>InstructorName;
    cout<<"Instructor code : ";
    cin>>InstructorCode;
    cout<<"Enrolment term : ";
    cin>>EnrolmentTerm;
    cout<<"Enrolment year : ";
    cin>>EnrolmentYear;
    cout<<"Choose a Department from : "<<endl;
    cout<<"1- General Studies\n"<<"2- Robotics\n"<<"3- Intelligence system\n"<<"4- Business analytics\n"<<"5- Bio computing\n";
    cout<<"Department : ";
    cin>>*(Department);
    while(*(Department)<1 && *(Department)>5)
    {
        cout<<"Incorrect choice entered please choose from the following list"<<endl;
        cout<<"1- General Studies\n"<<"2- Robotics\n"<<"3- Intelligence system\n"<<"4- Business analytics\n"<<"5- Bio computing\n";
        cin>>*(Department);
    }
    cout<<"Your Registration number : ";
    strcpy(RegNum,EnrolmentYear);
    strcat(RegNum,EnrolmentTerm);
    strcat(RegNum,"250");
    itoa(*Department,TempDepartment,10);
    strcat(RegNum,TempDepartment);
    long long RegNumGen=atoi(RegNum);
    char RegNumTemp[10],RegNumTemp2[10];
    memset(RegNum,'\0',20);
    RegNumGen*=10000;
    RegNumGen+=StuCon;
    StuCon++;
    int RegNum1=RegNumGen/100000;
    int RegNum2=RegNumGen%1000000;
    itoa(RegNum1,RegNumTemp,10);
    itoa(RegNum2,RegNumTemp2,10);
    strcpy(RegNum,RegNumTemp);
    strcat(RegNum,RegNumTemp2);
    cout<<RegNum<<endl;
    cout<<"Number of finished Courses : ";
    cin>>*(FinishedCourses);
    while(*FinishedCourses>48 || *FinishedCourses<0)
    {
        cout<<"Incorrect number of courses. Number of finished Courses : ";
        cin>>*(FinishedCourses);
    }
    cout<<"Number of current Courses : ";
    cin>>*(CurrentCourses);
    while(*CurrentCourses>6 || *CurrentCourses<0)
    {
        cout<<"Incorrect number of courses. Number of current Courses : ";
        cin>>*(CurrentCourses);
    }
}

int CalcAge(int *DayOfBirth,int *MonthOfBirth,int *YearOfBirth)
{
    float TodayDay,TodayMonth,TodayYear;
    cout<<"Today's Day : ";
    cin>>TodayDay;
    while(TodayDay>31 || TodayDay<0)
    {
        cout<<"Incorrect day entered please enter the correct day : ";
        cin>>TodayDay;
    }
    cout<<"Today's Month : ";
    cin>>TodayMonth;
    while(TodayMonth>12 || TodayMonth<0)
    {
        cout<<"Incorrect month entered please enter the correct month : ";
        cin>>TodayMonth;
    }
    cout<<"Today's Year : ";
    cin>>TodayYear;
    while(TodayYear>2022 || TodayYear<1980)
    {
        cout<<"Incorrect year entered please enter the correct year of birth : ";
        cin>>TodayYear;
    }
    int age=((TodayYear-*YearOfBirth)+((TodayMonth-*MonthOfBirth)/12)+((TodayDay-*DayOfBirth)/365));
    return age;
}

void GetPaymentDetails(int *TypeOfFunding,int *NumberOfPayments,double *TotalPayment,double *AmountPaid,long long *NumberOfTransaction,
                       int *DayOfTransaction,int *MonthOfTransaction,int *YearOfTransaction)
{
    cout<<"----------------"<<endl;
    cout<<"Payment details"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Type of funding (choose 1 for self-funded or 0 for grant funded) : ";
    cin>>*(TypeOfFunding);
    while((*TypeOfFunding)>1||(*TypeOfFunding)<0)
    {
        cout<<"Incorrect choice of Type of funding (choose 1 for self-funded or 0 for grant funded : ";
        cin>>*(TypeOfFunding);
    }
    if(*(TypeOfFunding)==1)
    {
        cout<<"Number of payments done : ";
        cin>>*(NumberOfPayments);
        cout<<"Total payments : ";
        cin>>*(TotalPayment);
        for(int i=0; i<*(NumberOfPayments); i++)
        {
            cout<<"Transaction "<<i+1<<endl;
            cout<<"Amount paid : ";
            cin>>AmountPaid[i];
            cout<<"Transaction Number : ";
            cin>>NumberOfTransaction[i];
            cout<<"Day of transaction : ";
            cin>>DayOfTransaction[i];
            while(DayOfTransaction[i]>31 || DayOfTransaction[i]<0)
            {
                cout<<"Incorrect day entered please enter the correct day of transaction : ";
                cin>>DayOfTransaction[i];
            }
            cout<<"Month of transaction : ";
            cin>>MonthOfTransaction[i];
            while(MonthOfTransaction[i]>12 || MonthOfTransaction[i]<0)
            {
                cout<<"Incorrect month entered please enter the correct month of transaction : ";
                cin>>MonthOfTransaction[i];
            }
            cout<<"Year of transaction : ";
            cin>>YearOfTransaction[i];
            while(YearOfTransaction[i]>2022 || YearOfTransaction[i]<1980)
            {
                cout<<"Incorrect year entered please enter the correct year of transaction : ";
                cin>>YearOfTransaction[i];
            }
        }
    }

}

void ScanStuData(char *FirstName, char *MiddleName, char *LastName, char *InstructorName, char *InstructorCode, char *Nationality,
                 char *StudentId,char *Password,  char *Country, char *Governorate, char *City, char *District, char *StreetName,
                 char *HouseNumber, char *FlatNumber, char *PostalCode,char *MailingCountry, char *MailingGovernorate,char *MailingCity,
                 char *MailingDistrict, char *MailingStreetName, char *MailingHouseNumber,char *MailingFlatNumber,char *MailingPostalCode,
                 char *StudentEmail, char *PhoneNumber,char *HomePhoneNumber, char *RegNum,int *DayOfBirth,int *MonthOfBirth,int *YearOfBirth,
                 char *EnrolmentTerm,char *EnrolmentYear, int *MaxCreditHours,int *Department,int *Gender,int *IdType,int *Age,int *TypeOfFunding,
                 int *NumberOfPayments,double *TotalPayment,double *AmountPaid,long long *NumberOfTransaction,int *DayOfTransaction,
                 int *MonthOfTransaction,int *YearOfTransaction,int *FinishedCourses,int *CurrentCourses)
{
    GetPersonlInfo(FirstName,MiddleName,LastName,Gender,Nationality,IdType,StudentId,Password,DayOfBirth,MonthOfBirth,YearOfBirth);

    *Age=CalcAge(DayOfBirth,MonthOfBirth,YearOfBirth);

    GetContactDetails(Country,Governorate,City,District,StreetName,HouseNumber,FlatNumber,PostalCode,MailingCountry, MailingGovernorate,
                      MailingCity, MailingDistrict, MailingStreetName, MailingHouseNumber, MailingFlatNumber, MailingPostalCode,
                      StudentEmail,PhoneNumber,HomePhoneNumber);

    GetUniDetails(EnrolmentTerm,EnrolmentYear,RegNum,Department,InstructorName,InstructorCode,FinishedCourses,CurrentCourses);

    GetPaymentDetails(TypeOfFunding,NumberOfPayments,TotalPayment,AmountPaid,NumberOfTransaction,DayOfTransaction,MonthOfTransaction,YearOfTransaction);
}

void  AddFinishedCoursesDetails(char *CourseCode,char *CourseName,char *LecturerFirstName, char*LecturerMiddleName,char *LecturerLastName,char *GTAFirstName,
                                char *GTAMiddleName,char *GTALastName,int NumberOfTimes,int CourseCreditHours, int CourseSemester,int CourseYear,float Course7thMark,
                                float Course12thMark,float CourseYearWork,float CourseFinalMark,float CoursePoints,double CourseTotalMark)
{
    FinishedCoursesPtr current = (FinishedCoursesPtr) malloc(sizeof(struct FinishedCourses));
    strcpy(current->CourseCode,CourseCode);
    strcpy(current->CourseName,CourseName);
    strcpy(current->LecturerFirstName,LecturerFirstName);
    strcpy(current->LecturerMiddleName,LecturerMiddleName);
    strcpy(current->LecturerLastName,LecturerLastName);
    strcpy(current->GTAFirstName,GTAFirstName);
    strcpy(current->GTAMiddleName,GTAMiddleName);
    strcpy(current->GTALastName,GTALastName);
    current->NumberOfTimes=NumberOfTimes;
    current->CourseCreditHours=CourseCreditHours;
    current->CourseSemester=CourseSemester;
    current->CourseYear=CourseYear;
    current->Course7thMark=Course7thMark;
    current->Course12thMark=Course12thMark;
    current->CourseYearWork=CourseYearWork;
    current->CourseFinalMark=CourseFinalMark;
    current->CoursePoints=CoursePoints;
    current->CourseTotalMark=CourseTotalMark;

    current->FinNextCourse = NULL;

    if(Head2 == NULL)
    {
        Head2 = current;
        return;
    }

    FinishedCoursesPtr temp = Head2;

    while(temp->FinNextCourse != NULL)
        temp = temp -> FinNextCourse;

    temp->FinNextCourse = current;
}

void ScanFinishedCoursesDetails(char *CourseCode,char *CourseName,char *LecturerFirstName, char*LecturerMiddleName,char *LecturerLastName,char *GTAFirstName,
                                char *GTAMiddleName,char *GTALastName,int *NumberOfTimes,int *CourseCreditHours, int *CourseSemester,int *CourseYear,float *Course7thMark,
                                float *Course12thMark,float *CourseYearWork,float *CourseFinalMark,float *CoursePoints,double *CourseTotalMark)
{
    cout<<"Course Code : ";
    cin>>CourseCode;
    cout<<"Course Name : ";
    cin>>CourseName;
    cout<<"Lecturer First Name : ";
    cin>>LecturerFirstName;
    cout<<"Lecturer middle Name : ";
    cin>>LecturerMiddleName;
    cout<<"Lecturer Last Name : ";
    cin>>LecturerLastName;
    cout<<"GTA First Name : ";
    cin>>GTAFirstName;
    cout<<"GTA Middle Name : ";
    cin>>GTAMiddleName;
    cout<<"GTA Last Name : ";
    cin>>GTALastName;
    cout<<"Number of times taken : ";
    cin>>*NumberOfTimes;
    cout<<"Course credit hours : ";
    cin>>*CourseCreditHours;
    cout<<"Course taken at semester : ";
    cin>>*CourseSemester;
    while(*CourseSemester<1 || *CourseSemester>8)
    {
        cout<<"Incorrect semester. Course taken at semester : ";
        cin>>*CourseSemester;
    }
    cout<<"Course taken at year : ";
    cin>>*CourseYear;
    while(*CourseYear<2000 || *CourseSemester>2022)
    {
        cout<<"Incorrect year. Course taken at year : ";
        cin>>*CourseYear;
    }
    cout<<"Course 7th mark : ";
    cin>>*Course7thMark;
    while(*Course7thMark<0 || *Course7thMark>30)
    {
        cout<<"Incorrect 7th mark. Course 7th mark : ";
        cin>>*Course7thMark;
    }
    cout<<"Course 12th mark : ";
    cin>>*Course12thMark;
    while(*Course12thMark<0 || *Course12thMark>20)
    {
        cout<<"Incorrect 12th mark. Course 12th mark : ";
        cin>>*Course12thMark;
    }
    cout<<"Course year work mark : ";
    cin>>*CourseYearWork;
    while(*CourseYearWork<0 || *CourseYearWork>10)
    {
        cout<<"Incorrect year work mark. Course year work : ";
        cin>>*CourseYearWork;
    }
    cout<<"Course final mark : ";
    cin>>*CourseFinalMark;
    while(*CourseFinalMark<0 || *CourseFinalMark>40)
    {
        cout<<"Incorrect Final mark. Course final mark : ";
        cin>>*CourseFinalMark;
    }
    *CourseTotalMark=*Course7thMark+*Course12thMark+*CourseYearWork+*CourseFinalMark;
    if(*CourseTotalMark>=95)
        *CoursePoints=12.0;
    else if(*CourseTotalMark>=90)
        *CoursePoints=11.5;
    else if(*CourseTotalMark>=85)
        *CoursePoints=11;
    else if(*CourseTotalMark>=80)
        *CoursePoints=10.5;
    else if(*CourseTotalMark>=75)
        *CoursePoints=10.0;
    else if(*CourseTotalMark>=70)
        *CoursePoints=9.5;
    else if(*CourseTotalMark>=65)
        *CoursePoints=9.0;
    else if(*CourseTotalMark>=60)
        *CoursePoints=8.5;
    else if(*CourseTotalMark>=55)
        *CoursePoints=8.0;
    else if(*CourseTotalMark>=50)
        *CoursePoints=7.5;
    else
        *CoursePoints=0;
}

void  AddCurrentCoursesDetails(char *CourseCode,char *CourseName,char *LecturerFirstName, char*LecturerMiddleName,char *LecturerLastName,char *GTAFirstName,
                               char *GTAMiddleName,char *GTALastName,int NumberOfTimes,int CourseCreditHours, int CourseSemester,int CourseYear)
{
    CurrentCoursesPtr current = (CurrentCoursesPtr) malloc(sizeof(struct CurrentCourses));
    strcpy(current->CourseCode,CourseCode);
    strcpy(current->CourseName,CourseName);
    strcpy(current->LecturerFirstName,LecturerFirstName);
    strcpy(current->LecturerMiddleName,LecturerMiddleName);
    strcpy(current->LecturerLastName,LecturerLastName);
    strcpy(current->GTAFirstName,GTAFirstName);
    strcpy(current->GTAMiddleName,GTAMiddleName);
    strcpy(current->GTALastName,GTALastName);
    current->NumberOfTimes=NumberOfTimes;
    current->CourseCreditHours=CourseCreditHours;
    current->CourseSemester=CourseSemester;
    current->CourseYear=CourseYear;

    current->CurNextCourse = NULL;

    if(Head3 == NULL)
    {
        Head3 = current;
        return;
    }

    CurrentCoursesPtr temp = Head3;

    while(temp->CurNextCourse != NULL)
        temp = temp -> CurNextCourse;

    temp->CurNextCourse = current;
}

void ScanCurrentCoursesDetails(char *CourseCode,char *CourseName,char *LecturerFirstName, char*LecturerMiddleName,char *LecturerLastName,char *GTAFirstName,
                               char *GTAMiddleName,char *GTALastName,int *NumberOfTimes,int *CourseCreditHours, int *CourseSemester,int *CourseYear)
{
    cout<<"Course Code : ";
    cin>>CourseCode;
    cout<<"Course Name : ";
    cin>>CourseName;
    cout<<"Lecturer First Name : ";
    cin>>LecturerFirstName;
    cout<<"Lecturer middle Name : ";
    cin>>LecturerMiddleName;
    cout<<"Lecturer Last Name : ";
    cin>>LecturerLastName;
    cout<<"GTA First Name : ";
    cin>>GTAFirstName;
    cout<<"GTA Middle Name : ";
    cin>>GTAMiddleName;
    cout<<"GTA Last Name : ";
    cin>>GTALastName;
    cout<<"Number of times taken : ";
    cin>>*NumberOfTimes;
    cout<<"Course credit hours : ";
    cin>>*CourseCreditHours;
    cout<<"Course taken at semester : ";
    cin>>*CourseSemester;
    while(*CourseSemester<1 || *CourseSemester>8)
    {
        cout<<"Incorrect semester. Course taken at semester : ";
        cin>>*CourseSemester;
    }
    cout<<"Course taken at year : ";
    cin>>*CourseYear;
    while(*CourseYear<2000 || *CourseSemester>2022)
    {
        cout<<"Incorrect year. Course taken at year : ";
        cin>>*CourseYear;
    }
}

void GetGpa(double *TotalPoints,double *TotalGPA, double *FinishedCreditHours,int *Term)
{
    *TotalGPA=(*TotalPoints)/(*FinishedCreditHours);
    *Term=((*FinishedCreditHours)/18)+1;
}

StudentDataPtr RefPassword()
{
    char EntryRegNum[20],EntryPassword[10];
    int validity=0;
    cout<<"Enter your registration number : "<<endl;
    cin>>EntryRegNum;
    cout<<"Enter your password : "<<endl;
    cin>>EntryPassword;
    if(Head == NULL)
    {
        return NULL;
    }
    StudentDataPtr Ref = Head;
    StudentDataPtr temp = Head;
    while( temp != NULL )
    {
        if(((strcmp(temp->RegNum,EntryRegNum))==0 )&&((strcmp(temp->Password,EntryPassword))==0))
        {
            Ref=temp;
            validity=1;
            break;
        }
        temp = temp->next;
    }
    while(validity==0)
    {
        cout<<"Incorrect registration number or password entered"<<endl;
        cout<<"Enter your registration number : "<<endl;
        cin>>EntryRegNum;
        cout<<"Enter your password : "<<endl;
        cin>>EntryPassword;
        temp=Head;
        while( temp != NULL )
        {
            if(((strcmp(temp->RegNum,EntryRegNum))==0 )&&((strcmp(temp->Password,EntryPassword))==0))
            {
                Ref=temp;
                validity=1;
                break;
            }
            temp = temp->next;
        }
    }
    return Ref;
}

void display(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    FinishedCoursesPtr TempFinCourse=temp->GetFinishedCourses;
    CurrentCoursesPtr TempCurCourse=temp->GetCurrentCourses;
    cout<<"Your information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Personal information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"First name: "<<temp->FirstName<<endl;
    cout<<"Middle name: "<<temp->MiddleName<<endl;
    cout<<"Last name: "<<temp->LastName<<endl;
    cout<<"Day of birth : "<<temp->DayOfBirth<<endl;
    cout<<"Month of birth : "<<temp->MonthOfBirth<<endl;
    cout<<"Year of birth : "<<temp->YearOfBirth<<endl;
    cout<<"Age : "<<temp->Age<<endl;
    cout<<"Gender : "<<temp->Gender<<endl;
    cout<<"Nationality: "<<temp->Nationality<<endl;
    cout<<"IdType : "<<temp->IdType<<endl;
    cout<<"Student Id : "<<temp->StudentId<<endl;
    cout<<"Password : "<<temp->Password<<endl;
    cout<<"----------------"<<endl;
    cout<<"Contact information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Country : "<<temp->Country<<endl;
    cout<<"Governorate : "<<temp->Governorate<<endl;
    cout<<"City : "<<temp->City<<endl;
    cout<<"District : "<<temp->District<<endl;
    cout<<"Street name : "<<temp->StreetName<<endl;
    cout<<"House number : "<<temp->HouseNumber<<endl;
    cout<<"Flat number : "<<temp->FlatNumber<<endl;
    cout<<"Postal code : "<<temp->PostalCode<<endl;
    cout<<"Mailing country : "<<temp->MailingCountry<<endl;
    cout<<"Mailing governorate : "<<temp->MailingGovernorate<<endl;
    cout<<"Mailing city : "<<temp->MailingCity<<endl;
    cout<<"Mailing district : "<<temp->MailingDistrict<<endl;
    cout<<"Mailing street name : "<<temp->MailingStreetName<<endl;
    cout<<"Mailing house number : "<<temp->MailingHouseNumber<<endl;
    cout<<"Mailing flat number : "<<temp->MailingFlatNumber<<endl;
    cout<<"Mailing postal code :"<<temp->MailingPostalCode<<endl;
    cout<<"Student email : "<<temp->StudentEmail<<endl;
    cout<<"Phone number : "<<temp->PhoneNumber<<endl;
    cout<<"Home phone number : "<<temp->HomePhoneNumber<<endl;
    cout<<"----------------"<<endl;
    cout<<"University information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Registration number : "<<temp->RegNum<<endl;
    cout<<"Instructor name: "<<temp->InstructorName<<endl;
    cout<<"Instructor code: "<<temp->InstructorCode<<endl;
    cout<<"Enrolment term : "<<temp->EnrolmentTerm<<endl;
    cout<<"Enrolment year : "<<temp->EnrolmentYear<<endl;
    cout<<"Department: "<<temp->Department<<endl;
    cout<<"Term : "<<temp->Term<<endl;
    cout<<"Max credit hours : "<<temp->MaxCreditHours<<endl;
    cout<<"Finished credit hours : "<<temp->FinishedCreditHours<<endl;
    cout<<"Current credit hours : "<<temp->CurrentCreditHours<<endl;
    cout<<"Remaining credit hours : "<<temp->RemainingCreditHours<<endl;
    cout<<"----------------"<<endl;
    cout<<"GPA information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Total Gpa : "<<temp->TotalGPA<<endl;
    cout<<"----------------"<<endl;
    cout<<"Payment details"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Type of funding : "<<temp->TypeOfFunding<<endl;
    if (strcmp(temp->TypeOfFunding,"Self-Funded")==0)
    {
        cout<<"Total Payment : "<<temp->TotalPayment<<endl;
        cout<<"Number of payments done : "<<temp->NumberOfPayments<<endl;
        for(int i=0; i<(temp->NumberOfPayments); i++)
        {
            cout<<"Payment number : "<<i+1<<endl;
            cout<<"Amount paid : "<<temp->AmountPaid[i]<<endl;
            cout<<"Transaction number : "<<temp->NumberOfTransaction[i]<<endl;
            cout<<"Day of transaction : "<<temp->DayOfTransaction[i]<<endl;
            cout<<"Month of transaction : "<<temp->MonthOfTransaction[i]<<endl;
            cout<<"Year of transaction : "<<temp->YearOfTransaction[i]<<endl;
            cout<<"----------------"<<endl;
        }
    }
    cout<<"----------------"<<endl;
    cout<<"Finished courses details"<<endl;
    cout<<"----------------"<<endl;
    while(TempFinCourse != NULL)
    {
        cout<<"CourseCode : "<<TempFinCourse->CourseCode<<endl;
        cout<<"Course Name : "<<TempFinCourse->CourseName<<endl;
        cout<<"Lecturer First Name : "<<TempFinCourse->LecturerFirstName<<endl;
        cout<<"Lecturer middle Name : "<<TempFinCourse->LecturerMiddleName<<endl;
        cout<<"Lecturer Last Name : "<<TempFinCourse->LecturerLastName<<endl;
        cout<<"GTA First Name : "<<TempFinCourse->GTAFirstName<<endl;
        cout<<"GTA Middle Name : "<<TempFinCourse->GTAMiddleName<<endl;
        cout<<"GTA Last Name : "<<TempFinCourse->GTALastName<<endl;
        cout<<"Number of times taken : "<<TempFinCourse->NumberOfTimes<<endl;
        cout<<"Course credit hours : "<<TempFinCourse->CourseCreditHours<<endl;
        cout<<"Course taken at semester : "<<TempFinCourse->CourseSemester<<endl;
        cout<<"Course taken at year : "<<TempFinCourse->CourseYear<<endl;
        cout<<"Course 7th mark : "<<TempFinCourse->Course7thMark<<endl;
        cout<<"Course 12th mark : "<<TempFinCourse->Course12thMark<<endl;
        cout<<"Course year work mark : "<<TempFinCourse->CourseYearWork<<endl;
        cout<<"Course final mark : "<<TempFinCourse->CourseFinalMark<<endl;
        cout<<"Course total mark : "<<TempFinCourse->CourseTotalMark<<endl;
        cout<<"Course points : "<<TempFinCourse->CoursePoints<<endl;
        cout<<"----------------"<<endl;
        TempFinCourse=TempFinCourse->FinNextCourse;
    }
    cout<<"----------------"<<endl;
    cout<<"Current courses details"<<endl;
    cout<<"----------------"<<endl;
    while(TempCurCourse != NULL)
    {
        cout<<"CourseCode : "<<TempCurCourse->CourseCode<<endl;
        cout<<"Course Name : "<<TempCurCourse->CourseName<<endl;
        cout<<"Lecturer First Name : "<<TempCurCourse->LecturerFirstName<<endl;
        cout<<"Lecturer middle Name : "<<TempCurCourse->LecturerMiddleName<<endl;
        cout<<"Lecturer Last Name : "<<TempCurCourse->LecturerLastName<<endl;
        cout<<"GTA First Name : "<<TempCurCourse->GTAFirstName<<endl;
        cout<<"GTA Middle Name : "<<TempCurCourse->GTAMiddleName<<endl;
        cout<<"GTA Last Name : "<<TempCurCourse->GTALastName<<endl;
        cout<<"Number of times taken : "<<TempCurCourse->NumberOfTimes<<endl;
        cout<<"Course credit hours : "<<TempCurCourse->CourseCreditHours<<endl;
        cout<<"Course taken at semester : "<<TempCurCourse->CourseSemester<<endl;
        cout<<"Course taken at year : "<<TempCurCourse->CourseYear<<endl;
        cout<<"----------------"<<endl;
        TempCurCourse=TempCurCourse->CurNextCourse;
    }
    cout<<"----------------"<<endl;
}

void displaypersonalinfo(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    cout<<"Your information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Personal information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"First name: "<<temp->FirstName<<endl;
    cout<<"Middle name: "<<temp->MiddleName<<endl;
    cout<<"Last name: "<<temp->LastName<<endl;
    cout<<"Day of birth : "<<temp->DayOfBirth<<endl;
    cout<<"Month of birth : "<<temp->MonthOfBirth<<endl;
    cout<<"Year of birth : "<<temp->YearOfBirth<<endl;
    cout<<"Age : "<<temp->Age<<endl;
    cout<<"Gender : "<<temp->Gender<<endl;
    cout<<"Nationality: "<<temp->Nationality<<endl;
    cout<<"IdType : "<<temp->IdType<<endl;
    cout<<"Student Id : "<<temp->StudentId<<endl;
    cout<<"Password : "<<temp->Password<<endl;
    cout<<"----------------"<<endl;
}

void displaycontactdetails(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    cout<<"Contact information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Country : "<<temp->Country<<endl;
    cout<<"Governorate : "<<temp->Governorate<<endl;
    cout<<"City : "<<temp->City<<endl;
    cout<<"District : "<<temp->District<<endl;
    cout<<"Street name : "<<temp->StreetName<<endl;
    cout<<"House number : "<<temp->HouseNumber<<endl;
    cout<<"Flat number : "<<temp->FlatNumber<<endl;
    cout<<"Postal code : "<<temp->PostalCode<<endl;
    cout<<"Mailing country : "<<temp->MailingCountry<<endl;
    cout<<"Mailing governorate : "<<temp->MailingGovernorate<<endl;
    cout<<"Mailing city : "<<temp->MailingCity<<endl;
    cout<<"Mailing district : "<<temp->MailingDistrict<<endl;
    cout<<"Mailing street name : "<<temp->MailingStreetName<<endl;
    cout<<"Mailing house number : "<<temp->MailingHouseNumber<<endl;
    cout<<"Mailing flat number : "<<temp->MailingFlatNumber<<endl;
    cout<<"Mailing postal code :"<<temp->MailingPostalCode<<endl;
    cout<<"Student email : "<<temp->StudentEmail<<endl;
    cout<<"Phone number : "<<temp->PhoneNumber<<endl;
    cout<<"Home phone number : "<<temp->HomePhoneNumber<<endl;
    cout<<"----------------"<<endl;
}

void displayuniversityinformation(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    cout<<"University information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Registration number : "<<temp->RegNum<<endl;
    cout<<"Instructor name: "<<temp->InstructorName<<endl;
    cout<<"Instructor code: "<<temp->InstructorCode<<endl;
    cout<<"Enrolment term : "<<temp->EnrolmentTerm<<endl;
    cout<<"Enrolment year : "<<temp->EnrolmentYear<<endl;
    cout<<"Department: "<<temp->Department<<endl;
    cout<<"Term : "<<temp->Term<<endl;
    cout<<"Max credit hours : "<<temp->MaxCreditHours<<endl;
    cout<<"Finished credit hours : "<<temp->FinishedCreditHours<<endl;
    cout<<"Current credit hours : "<<temp->CurrentCreditHours<<endl;
    cout<<"Remaining credit hours : "<<temp->RemainingCreditHours<<endl;
    cout<<"----------------"<<endl;
    cout<<"GPA information"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Total Gpa : "<<temp->TotalGPA<<endl;
    cout<<"----------------"<<endl;
}

void displaypaymentdetails(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    cout<<"Payment details"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Type of funding : "<<temp->TypeOfFunding<<endl;
    if (strcmp(temp->TypeOfFunding,"Self-Funded")==0)
    {
        cout<<"Total Payment : "<<temp->TotalPayment<<endl;
        cout<<"Number of payments done : "<<temp->NumberOfPayments<<endl;
        for(int i=0; i<(temp->NumberOfPayments); i++)
        {
            cout<<"Payment number : "<<i+1<<endl;
            cout<<"Amount paid : "<<temp->AmountPaid[i]<<endl;
            cout<<"Transaction number : "<<temp->NumberOfTransaction[i]<<endl;
            cout<<"Day of transaction : "<<temp->DayOfTransaction[i]<<endl;
            cout<<"Month of transaction : "<<temp->MonthOfTransaction[i]<<endl;
            cout<<"Year of transaction : "<<temp->YearOfTransaction[i]<<endl;
            cout<<"----------------"<<endl;
        }
    }
    cout<<"----------------"<<endl;
}

void displayfinishedcourses(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    FinishedCoursesPtr TempFinCourse=temp->GetFinishedCourses;
    cout<<"----------------"<<endl;
    cout<<"Finished courses details"<<endl;
    cout<<"----------------"<<endl;
    while(TempFinCourse != NULL)
    {
        cout<<"CourseCode : "<<TempFinCourse->CourseCode<<endl;
        cout<<"Course Name : "<<TempFinCourse->CourseName<<endl;
        cout<<"Lecturer First Name : "<<TempFinCourse->LecturerFirstName<<endl;
        cout<<"Lecturer middle Name : "<<TempFinCourse->LecturerMiddleName<<endl;
        cout<<"Lecturer Last Name : "<<TempFinCourse->LecturerLastName<<endl;
        cout<<"GTA First Name : "<<TempFinCourse->GTAFirstName<<endl;
        cout<<"GTA Middle Name : "<<TempFinCourse->GTAMiddleName<<endl;
        cout<<"GTA Last Name : "<<TempFinCourse->GTALastName<<endl;
        cout<<"Number of times taken : "<<TempFinCourse->NumberOfTimes<<endl;
        cout<<"Course credit hours : "<<TempFinCourse->CourseCreditHours<<endl;
        cout<<"Course taken at semester : "<<TempFinCourse->CourseSemester<<endl;
        cout<<"Course taken at year : "<<TempFinCourse->CourseYear<<endl;
        cout<<"Course 7th mark : "<<TempFinCourse->Course7thMark<<endl;
        cout<<"Course 12th mark : "<<TempFinCourse->Course12thMark<<endl;
        cout<<"Course year work mark : "<<TempFinCourse->CourseYearWork<<endl;
        cout<<"Course final mark : "<<TempFinCourse->CourseFinalMark<<endl;
        cout<<"Course total mark : "<<TempFinCourse->CourseTotalMark<<endl;
        cout<<"Course points : "<<TempFinCourse->CoursePoints<<endl;
        cout<<"----------------"<<endl;
        TempFinCourse=TempFinCourse->FinNextCourse;
    }
    cout<<"----------------"<<endl;
}

void displaycurrentcourses(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    CurrentCoursesPtr TempCurCourse=temp->GetCurrentCourses;
    cout<<"Current courses details"<<endl;
    cout<<"----------------"<<endl;
    while(TempCurCourse != NULL)
    {
        cout<<"CourseCode : "<<TempCurCourse->CourseCode<<endl;
        cout<<"Course Name : "<<TempCurCourse->CourseName<<endl;
        cout<<"Lecturer First Name : "<<TempCurCourse->LecturerFirstName<<endl;
        cout<<"Lecturer middle Name : "<<TempCurCourse->LecturerMiddleName<<endl;
        cout<<"Lecturer Last Name : "<<TempCurCourse->LecturerLastName<<endl;
        cout<<"GTA First Name : "<<TempCurCourse->GTAFirstName<<endl;
        cout<<"GTA Middle Name : "<<TempCurCourse->GTAMiddleName<<endl;
        cout<<"GTA Last Name : "<<TempCurCourse->GTALastName<<endl;
        cout<<"Number of times taken : "<<TempCurCourse->NumberOfTimes<<endl;
        cout<<"Course credit hours : "<<TempCurCourse->CourseCreditHours<<endl;
        cout<<"Course taken at semester : "<<TempCurCourse->CourseSemester<<endl;
        cout<<"Course taken at year : "<<TempCurCourse->CourseYear<<endl;
        cout<<"----------------"<<endl;
        TempCurCourse=TempCurCourse->CurNextCourse;
    }
    cout<<"----------------"<<endl;
}

void ConfigureCourse(StudentDataPtr RefPass,double *TotalPoints,double *FinishedCreditHours,double *TotalGPA,int *Term)
{
    StudentDataPtr temp = RefPass;
    FinishedCoursesPtr TempFinCourse=temp->GetFinishedCourses;
    char TempCourseCode[8],CourseCode[8],CourseName[30],LecturerFirstName[30],LecturerMiddleName[30],LecturerLastName[30],
         GTAFirstName[30],GTAMiddleName[30],GTALastName[30];

    int NumberOfTimes, CourseCreditHours, CourseSemester, CourseYear;

    float Course7thMark,Course12thMark, CourseYearWork, CourseFinalMark, CoursePoints;

    double CourseTotalMark;
    cout<<"Enter the course code that you want to configure : "<<endl;
    cin>>TempCourseCode;
    while(TempFinCourse != NULL)
    {
        if(strcmp(TempFinCourse->CourseCode,TempCourseCode)==0)
        {
            ScanFinishedCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName,LecturerLastName,GTAFirstName,GTAMiddleName,
                                       GTALastName,&NumberOfTimes,&CourseCreditHours, &CourseSemester, &CourseYear, &Course7thMark, &Course12thMark,
                                       &CourseYearWork,&CourseFinalMark,&CoursePoints,&CourseTotalMark);
            *TotalPoints-=TempFinCourse->CoursePoints;
            *FinishedCreditHours-=TempFinCourse->CourseCreditHours;
            strcpy(TempFinCourse->CourseCode,CourseCode);
            strcpy(TempFinCourse->CourseName,CourseName);
            strcpy(TempFinCourse->LecturerFirstName,LecturerFirstName);
            strcpy(TempFinCourse->LecturerMiddleName,LecturerMiddleName);
            strcpy(TempFinCourse->LecturerLastName,LecturerLastName);
            strcpy(TempFinCourse->GTAFirstName,GTAFirstName);
            strcpy(TempFinCourse->GTAMiddleName,GTAMiddleName);
            strcpy(TempFinCourse->GTALastName,GTALastName);
            TempFinCourse->NumberOfTimes=NumberOfTimes;
            TempFinCourse->CourseCreditHours=CourseCreditHours;
            TempFinCourse->CourseSemester=CourseSemester;
            TempFinCourse->CourseYear=CourseYear;
            TempFinCourse->Course7thMark=Course7thMark;
            TempFinCourse->Course12thMark=Course12thMark;
            TempFinCourse->CourseYearWork=CourseYearWork;
            TempFinCourse->CourseFinalMark=CourseFinalMark;
            TempFinCourse->CoursePoints=CoursePoints;
            TempFinCourse->CourseTotalMark=CourseTotalMark;
            *TotalPoints+=CoursePoints;
            *FinishedCreditHours+=CourseCreditHours;
            cout<<"GPA before configuration : "<<temp->TotalGPA<<endl;
            GetGpa(TotalPoints,TotalGPA,FinishedCreditHours,Term);
            temp->TotalGPA=*TotalGPA;
            cout<<"GPA after configuration : "<<temp->TotalGPA<<endl;

            return;
        }
        TempFinCourse=TempFinCourse->FinNextCourse;
    }
    cout<<"Course not found. Please try again"<<endl;
    cout<<"----------------"<<endl;
}

void ConfigureContactDetails(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;
    char TempStudentEmail[40],TempPhoneNumber[20],TempHomePhoneNumber[20];
    int Choice;
    cout<<"----------------"<<endl;
    cout<<"Do you want to change your email ? choose 1 for yes or 0 for no : "<<endl;
    cin>>Choice;
    while(Choice>1 || Choice<0)
    {
        cout<<"Incorrect choice\nDo you want to change your email ? choose 1 for yes or 0 for no : "<<endl;
        cin>>Choice;
    }
    if (Choice==1)
    {
        cout<<"Enter your new email : ";
        cin>>TempStudentEmail;
        cout<<"Old mail : "<<temp->StudentEmail<<endl;
        strcpy(temp->StudentEmail,TempStudentEmail);
        cout<<"New mail : "<<temp->StudentEmail<<endl;
    }

    cout<<"Do you want to change your phone number ? choose 1 for yes or 0 for no : ";
    cin>>Choice;
    while(Choice>1 || Choice<0)
    {
        cout<<"Incorrect choice\nDo you want to change your phone number ? choose 1 for yes or 0 for no : ";
        cin>>Choice;
    }
    if (Choice==1)
    {
        cout<<"Enter your new phone number : ";
        cin>>TempPhoneNumber;
        cout<<"Old phone number : "<<temp->PhoneNumber<<endl;
        strcpy(temp->PhoneNumber,TempPhoneNumber);
        cout<<"New phone number : "<<temp->PhoneNumber<<endl;
    }

    cout<<"Do you want to change your home phone number ? choose 1 for yes or 0 for no : ";
    cin>>Choice;
    while(Choice>1 || Choice<0)
    {
        cout<<"Incorrect choice\nDo you want to change your home phone number ? choose 1 for yes or 0 for no : ";
        cin>>Choice;
    }
    if (Choice==1)
    {
        cout<<"Enter your new home phone number : ";
        cin>>TempHomePhoneNumber;
        cout<<"Old home phone number : "<<temp->HomePhoneNumber<<endl;
        strcpy(temp->HomePhoneNumber,TempHomePhoneNumber);
        cout<<"New home phone number : "<<temp->HomePhoneNumber<<endl;
    }
    cout<<"----------------"<<endl;
}

void AddNewPayment(StudentDataPtr RefPass)
{
    StudentDataPtr temp = RefPass;

    double AmountPaid;

    long long NumberOfTransaction;

    int DayOfTransaction,MonthOfTransaction,YearOfTransaction;

    cout<<"Transaction "<<endl;
    cout<<"Amount paid : ";
    cin>>AmountPaid;
    cout<<"Transaction Number : ";
    cin>>NumberOfTransaction;
    cout<<"Day of transaction : ";
    cin>>DayOfTransaction;
    while(DayOfTransaction>31 || DayOfTransaction<0)
    {
        cout<<"Incorrect day entered please enter the correct day of transaction : ";
        cin>>DayOfTransaction;
    }
    cout<<"Month of transaction : ";
    cin>>MonthOfTransaction;
    while(MonthOfTransaction>12 || MonthOfTransaction<0)
    {
        cout<<"Incorrect month entered please enter the correct month of transaction : ";
        cin>>MonthOfTransaction;
    }
    cout<<"Year of transaction : ";
    cin>>YearOfTransaction;
    while(YearOfTransaction>2022 || YearOfTransaction<1980)
    {
        cout<<"Incorrect year entered please enter the correct year of transaction : ";
        cin>>YearOfTransaction;
    }
    temp->AmountPaid[temp->NumberOfPayments]=AmountPaid;
    temp->NumberOfTransaction[temp->NumberOfPayments]=NumberOfTransaction;
    temp->DayOfTransaction[temp->NumberOfPayments]=DayOfTransaction;
    temp->MonthOfTransaction[temp->NumberOfPayments]=MonthOfTransaction;
    temp->YearOfTransaction[temp->NumberOfPayments]=YearOfTransaction;
    temp->TotalPayment+=AmountPaid;
    temp->NumberOfPayments++;
}

void SortedInsert(StudentDataPtr NewNode)
{
    if (sorted == NULL || sorted->TotalGPA >= NewNode->TotalGPA)
    {
        NewNode->next = sorted;
        sorted = NewNode;
    }
    else
    {
        StudentDataPtr current = sorted;

        while (current->next != NULL && current->next->TotalGPA < NewNode->TotalGPA)
        {
            current = current->next;
        }
        NewNode->next = current->next;
        current->next = NewNode;
    }
}

void InsertionSort()
{
    StudentDataPtr current = Head;

    while (current != NULL)
    {
        StudentDataPtr next = current->next;
        SortedInsert(current);
        current = next;
    }
    Head = sorted;
}

void PrintSortedList()
{
    StudentDataPtr temp=Head;
    while (temp != NULL)
    {
        cout<< temp->RegNum<<"--"<<temp->FirstName<<" "<<temp->MiddleName<<" "<<temp->LastName<<"---"<<temp->TotalGPA<<endl;
        temp = temp->next;
    }
}

int main()
{
    char FirstName[30],MiddleName[30],LastName[30],InstructorName[50],InstructorCode[15],Nationality[15],StudentId[15],
         Password[10],Country[15],Governorate[15],City[15],District[15],StreetName[20],
         HouseNumber[5],FlatNumber[5],PostalCode[10],MailingCountry[15],MailingGovernorate[15],
         MailingCity[15],MailingDistrict[15],MailingStreetName[20],MailingHouseNumber[5],
         MailingFlatNumber[5],MailingPostalCode[10],StudentEmail[40],PhoneNumber[20],
         HomePhoneNumber[20],RegNum[20],EnrolmentTerm[3],EnrolmentYear[5],CourseCode[8],CourseName[30],
         LecturerFirstName[30],LecturerMiddleName[30],LecturerLastName[30],
         GTAFirstName[30],GTAMiddleName[30],GTALastName[30];

    int DayOfBirth, MonthOfBirth,YearOfBirth, Term,MaxCreditHours=144,Gender,IdType,NewStu,StudentTerminator,ProgramTerminator=1,
                                                   Choice,Age,Department,TypeOfFunding,NumberOfPayments,NumberOfTimes, CourseCreditHours,
                                                   CourseSemester, CourseYear,FinishedCourses,CurrentCourses;

    float Course7thMark,Course12thMark, CourseYearWork, CourseFinalMark, CoursePoints;

    long long NumberOfTransaction[20];

    int DayOfTransaction[20], MonthOfTransaction[20],YearOfTransaction[20];

    double FinishedCreditHours=0,CurrentCreditHours=0,TotalPayment,CourseTotalMark,TotalPoints=0,TotalGPA=0;

    double AmountPaid[20];
    cout<<"Data set scan"<<endl;
    cout<<"----------------"<<endl;
    for(int j=0; j<1; j++)
    {
        FinishedCreditHours=0;
        CurrentCreditHours=0;
        TotalPoints=0;
        cout<<"----------------"<<endl;
        cout<<"You are now asked to fill in your details"<<endl;
        cout<<"----------------"<<endl;
        ScanStuData(FirstName, MiddleName, LastName, InstructorName, InstructorCode, Nationality, StudentId,
                    Password,  Country, Governorate, City, District, StreetName, HouseNumber, FlatNumber, PostalCode, MailingCountry,
                    MailingGovernorate,MailingCity, MailingDistrict, MailingStreetName, MailingHouseNumber, MailingFlatNumber,
                    MailingPostalCode, StudentEmail, PhoneNumber,HomePhoneNumber, RegNum, &DayOfBirth, &MonthOfBirth,&YearOfBirth,
                    EnrolmentTerm, EnrolmentYear, &MaxCreditHours, &Department,&Gender,&IdType,&Age,&TypeOfFunding,&NumberOfPayments,&TotalPayment,AmountPaid,
                    NumberOfTransaction,DayOfTransaction,MonthOfTransaction,YearOfTransaction,&FinishedCourses,&CurrentCourses);
        for(int i=0; i<FinishedCourses; i++)
        {
            cout<<"----------------"<<endl;
            cout<<"You are now asked to fill in your finished courses details : "<<endl;
            cout<<"----------------"<<endl;
            cout<<"Course "<<i+1<<endl;
            ScanFinishedCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName,LecturerLastName,GTAFirstName,GTAMiddleName,
                                       GTALastName,&NumberOfTimes,&CourseCreditHours, &CourseSemester, &CourseYear, &Course7thMark, &Course12thMark,
                                       &CourseYearWork,&CourseFinalMark,&CoursePoints,&CourseTotalMark);
            AddFinishedCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName, LecturerLastName, GTAFirstName, GTAMiddleName,
                                      GTALastName,NumberOfTimes,CourseCreditHours, CourseSemester, CourseYear, Course7thMark, Course12thMark,
                                      CourseYearWork,CourseFinalMark, CoursePoints,CourseTotalMark);
            FinishedCreditHours+=CourseCreditHours;
            TotalPoints+=CoursePoints;
            cout<<"----------------"<<endl;
        }

        GetGpa(&TotalPoints,&TotalGPA,&FinishedCreditHours,&Term);

        for(int i=0; i<CurrentCourses; i++)
        {
            cout<<"You are now asked to fill in your current courses details : "<<endl;
            cout<<"Course "<<i+1<<endl;
            ScanCurrentCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName,LecturerLastName,GTAFirstName,GTAMiddleName,
                                      GTALastName,&NumberOfTimes,&CourseCreditHours, &CourseSemester, &CourseYear);
            AddCurrentCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName, LecturerLastName, GTAFirstName, GTAMiddleName,
                                     GTALastName,NumberOfTimes,CourseCreditHours, CourseSemester, CourseYear);
            CurrentCreditHours+=CourseCreditHours;
            cout<<"----------------"<<endl;
        }

        AddStData(FirstName, MiddleName, LastName, InstructorName, InstructorCode, Nationality, StudentId,
                  Password, Country, Governorate, City, District, StreetName, HouseNumber, FlatNumber, PostalCode, MailingCountry,
                  MailingGovernorate,MailingCity, MailingDistrict, MailingStreetName, MailingHouseNumber, MailingFlatNumber,
                  MailingPostalCode, StudentEmail, PhoneNumber,HomePhoneNumber, RegNum,DayOfBirth, MonthOfBirth,YearOfBirth,
                  EnrolmentTerm, EnrolmentYear, Term,MaxCreditHours, Department,Gender,IdType, FinishedCreditHours,
                  CurrentCreditHours,TotalGPA,Age,TypeOfFunding,NumberOfPayments,TotalPayment,AmountPaid,
                  NumberOfTransaction,DayOfTransaction,MonthOfTransaction,YearOfTransaction,FinishedCourses,CurrentCourses);
        Head2=NULL;
        Head3=NULL;
    }

    cout<<"\n\n\t\t\t *****************************************************"<<endl;
    cout<<"\t\t\t * Welcome to Arab academy of science and technology *"<<endl;
    cout<<"\t\t\t *****************************************************\n\n\n"<<endl;

    while(ProgramTerminator==1)
    {
        cout<<"Are you a registered student ?"<<"\n"<<"Choose 1 for yes and 0 for no"<<endl;
        cin>>NewStu;
        while(  NewStu>1 || NewStu<0)
        {
            cout<<"Incorrect choice please Choose 1 for yes and 0 for no";
            cin>>NewStu;
        }
        if(NewStu==0)
        {
            FinishedCreditHours=0;
            CurrentCreditHours=0;
            TotalPoints=0;
            cout<<"You are now asked to fill in your details"<<endl;
            ScanStuData(FirstName, MiddleName, LastName, InstructorName, InstructorCode, Nationality, StudentId,
                        Password,  Country, Governorate, City, District, StreetName, HouseNumber, FlatNumber, PostalCode, MailingCountry,
                        MailingGovernorate,MailingCity, MailingDistrict, MailingStreetName, MailingHouseNumber, MailingFlatNumber,
                        MailingPostalCode, StudentEmail, PhoneNumber,HomePhoneNumber, RegNum, &DayOfBirth, &MonthOfBirth,&YearOfBirth,
                        EnrolmentTerm, EnrolmentYear, &MaxCreditHours, &Department,&Gender,&IdType,&Age,&TypeOfFunding,&NumberOfPayments,&TotalPayment,AmountPaid,
                        NumberOfTransaction,DayOfTransaction,MonthOfTransaction,YearOfTransaction,&FinishedCourses,&CurrentCourses);
            for(int i=0; i<FinishedCourses; i++)
            {
                cout<<"You are now asked to fill in your finished courses details : "<<endl;
                cout<<"Course "<<i+1<<endl;
                ScanFinishedCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName,LecturerLastName,GTAFirstName,GTAMiddleName,
                                           GTALastName,&NumberOfTimes,&CourseCreditHours, &CourseSemester, &CourseYear, &Course7thMark, &Course12thMark,
                                           &CourseYearWork,&CourseFinalMark,&CoursePoints,&CourseTotalMark);
                AddFinishedCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName, LecturerLastName, GTAFirstName, GTAMiddleName,
                                          GTALastName,NumberOfTimes,CourseCreditHours, CourseSemester, CourseYear, Course7thMark, Course12thMark,
                                          CourseYearWork,CourseFinalMark, CoursePoints,CourseTotalMark);
                FinishedCreditHours+=CourseCreditHours;
                TotalPoints+=CoursePoints;
                cout<<"----------------"<<endl;
            }

            GetGpa(&TotalPoints,&TotalGPA,&FinishedCreditHours,&Term);

            for(int i=0; i<CurrentCourses; i++)
            {
                cout<<"You are now asked to fill in your current courses details : "<<endl;
                cout<<"Course "<<i+1<<endl;
                ScanCurrentCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName,LecturerLastName,GTAFirstName,GTAMiddleName,
                                          GTALastName,&NumberOfTimes,&CourseCreditHours, &CourseSemester, &CourseYear);
                AddCurrentCoursesDetails(CourseCode,CourseName,LecturerFirstName, LecturerMiddleName, LecturerLastName, GTAFirstName, GTAMiddleName,
                                         GTALastName,NumberOfTimes,CourseCreditHours, CourseSemester, CourseYear);
                CurrentCreditHours+=CourseCreditHours;
                cout<<"----------------"<<endl;
            }

            AddStData(FirstName, MiddleName, LastName, InstructorName, InstructorCode, Nationality, StudentId,
                      Password, Country, Governorate, City, District, StreetName, HouseNumber, FlatNumber, PostalCode, MailingCountry,
                      MailingGovernorate,MailingCity, MailingDistrict, MailingStreetName, MailingHouseNumber, MailingFlatNumber,
                      MailingPostalCode, StudentEmail, PhoneNumber,HomePhoneNumber, RegNum,DayOfBirth, MonthOfBirth,YearOfBirth,
                      EnrolmentTerm, EnrolmentYear, Term,MaxCreditHours, Department,Gender,IdType, FinishedCreditHours,
                      CurrentCreditHours,TotalGPA,Age,TypeOfFunding,NumberOfPayments,TotalPayment,AmountPaid,
                      NumberOfTransaction,DayOfTransaction,MonthOfTransaction,YearOfTransaction,FinishedCourses,CurrentCourses);
            Head2=NULL;
            Head3=NULL;
        }
        else
        {
            StudentDataPtr RefPass=RefPassword();
            StudentTerminator=1;
            while(StudentTerminator==1)
            {
                cout<<"Please choose the required function"<<endl;
                cout<<"1- Display student data"<<endl;
                cout<<"2- Display personal information"<<endl;
                cout<<"3- Display contact details"<<endl;
                cout<<"4- Display university information"<<endl;
                cout<<"5- Display payment details"<<endl;
                cout<<"6- Display finished courses"<<endl;
                cout<<"7- Display current courses"<<endl;
                cout<<"8- Change any course details"<<endl;
                cout<<"9- Change any contact details"<<endl;
                cout<<"10- Add new payment"<<endl;
                cout<<"11- List of sorted student by GPA"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Choice : ";
                cin>>Choice;
                cout<<"----------------"<<endl;
                while(Choice>11 || Choice<0)
                {
                    cout<<"Incorrect choice...Please choose the required function from the list"<<endl;
                    cout<<"Please choose the required function"<<endl;
                    cout<<"1- Display student data"<<endl;
                    cout<<"2- Display personal information"<<endl;
                    cout<<"3- Display contact details"<<endl;
                    cout<<"4- Display university information"<<endl;
                    cout<<"5- Display payment details"<<endl;
                    cout<<"6- Display finished courses"<<endl;
                    cout<<"7- Display current courses"<<endl;
                    cout<<"8- Change any course details"<<endl;
                    cout<<"9- Change any contact details"<<endl;
                    cout<<"10- Add new payment"<<endl;
                    cout<<"11- List of sorted student by GPA"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"Choice : ";
                    cin>>Choice;
                    cout<<"----------------"<<endl;
                }

                if(Choice==1)
                {

                    display(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==2)
                {
                    displaypersonalinfo(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==3)
                {
                    displaycontactdetails(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==4)
                {
                    displayuniversityinformation(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==5)
                {
                    displaypaymentdetails(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==6)
                {
                    displayfinishedcourses(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==7)
                {
                    displaycurrentcourses(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==8)
                {
                    ConfigureCourse(RefPass,&TotalPoints,&FinishedCreditHours,&TotalGPA,&Term);
                    cout<<"----------------"<<endl;
                }
                if(Choice==9)
                {
                    ConfigureContactDetails(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==10)
                {
                    AddNewPayment(RefPass);
                    cout<<"----------------"<<endl;
                }
                if(Choice==11)
                {
                    InsertionSort();
                    PrintSortedList();
                    cout<<"----------------"<<endl;
                }
                cout<<"Do you want to perform another function for student "<< RefPass->RegNum<<"\n"<<"Choose 1 for yes and 0 for no"<<endl;
                cin>>StudentTerminator;
                while( StudentTerminator>1 || StudentTerminator<0)
                {
                    cout<<"Incorrect choice please Choose 1 for yes and 0 for no"<<endl;
                    cin>>StudentTerminator;
                }
            }
            cout<<"Do you want to perform another function for another student"<<"\n"<<"Choose 1 for yes and 0 for no"<<endl;
            cin>>ProgramTerminator;
            while( ProgramTerminator>1 || ProgramTerminator<0)
            {
                cout<<"Incorrect choice please Choose 1 for yes and 0 for no"<<endl;
                cin>>ProgramTerminator;
            }
        }
    }
    return 0;
}
