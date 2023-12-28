#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int validate1();
int validate2();
int view1reg();
int deletevoter();
int check2();
int main();
void addcandidate();
int viewcandidate();
void search();
void check();
void vote();
void viewvoter();
void view2reg();
void viewcanvote();
void viewcanvote2();
void viewbydiv();
void instructions();
void sortbydivision();

/* FUNCTIONS MODULE:

  validate 1 - it checks whether the candidate gets registered already or not.
  validate 2 - it will check two things.it checks whether the voter is registered in voter table or not and it checks whether
                   the voter has already voted or not.it allows the voter to Register after this two checks.
  view1reg -  after the voter has voted,then it will automatically writes that voted voters in the voted voters file.
  deletevoter - after the voter has voted, then this function automatically deletes that voter from voter table(register table).
  check2 - it counts the number of records that is the number of voters in voter table and returns that value.
  addcandidate - it adds the candidate to the candidate table after checking whether the candidate is registered already or not by using the
                       validate 1().
  viewcandidate - it displays all the candidates present in that candidate table.
  search - this function searches the candidates or party or division in the candidate table according to the user convenience(entities entered by the user)
  check - this checks the number of records(the number of candidates) present in the candidate table.
  vote - this function writes the voter in the voter table(register table) after the validation given by validate 2 function.
  viewvoter - it displays all the voters present in the voter table(register table).
  view2reg - it displays all the voters in voted voters file(that is all the voters who has voted).
  viewcanvote - it displays the current status of the candidates along with their count according to authority preference.
  viewcanvote2 - it displays the results of the election in all divisions.
  viewbydiv - it displays the results in a particular division according to the division entered by the user.
  instructions - it displays the working modules of all options.
  sortbydivision - it displays the candidates in the ascending order(division) just for voters convenience.
*/

int a=0,b=0,c=0,d=0,w=0,f=0,g=0,h=0,j=0,k=0,l=0,m=0,n=0,o=0,q=0,u=0;
int t1,t2,t3,t4,cont;
struct candidate{//creating a structure to store the candidate details.
    char name[50];
    char ID[50];
    char party[50];
    int division;
    int Count;
    float percent;

}can;

struct voter{//creating a structure to store the voter details.
    char ID[90];
    char name[90];
    int age;
    int division;
    char status[3];
    char CandID[7];
}vot;
//function to add the candidates in the table
void addcandidate(struct candidate s){
    FILE *p;//file pointer to access the binary file.
    FILE *p1;//file pointer to access the text file.
    int i,j,t;
    p=fopen("d:\\data.txt","a+");//text file
    p1=fopen("d:\\addcandidate.txt","a+");//text file.
    if(p==NULL){
        printf("UNABLE TO OPEN THE FILE\n");
    }
    if(p1==NULL){
        printf("UNABLE TO OPEN THE FILE\n");

    }
    fflush(stdin);
    t=validate1(can);//checks validation before writing into the file.
    if(t==0){
        main();//validate 1 function returns 0 when the candidate is already registered.
    }
    //writing in file after validation.
    else if(t==1){
    fflush(stdin);

        fwrite(&can,sizeof(can),1,p);//write in binary mode
        fprintf(p1,"%-6s               %-20s %-20s%-5d\n",can.ID,can.name,can.party,can.division);//write in text mode.


    fclose(p);
    fclose(p1);
    }
     printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
}
int viewcandidate(struct candidate s){


    int i=1;
    FILE *p;
    int seen=0;
    p=fopen("d:\\data.txt","r");//binary file.
    if(p==NULL){
        printf("UNABLE TO OPEN THE FILE\n");
    }
    char a[90]=" ID",b[90]="NAME",c[90]="PARTY",d[90]="DIVISION",e[90]="CANDIDATE.NO";
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\n%s     %s                   %-20s%-18s %-20s\n",e,a,b,c,d);
    printf("\n----------------------------------------------------------------------------------------\n");
    //read the file and view the candidates in the file.

    while(fread(&s,sizeof(s),1,p)){
        if(i<10){
        printf("\n%d.               %-6s               %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);//read from the file and displays the entities in console window.
        i++;
        seen=1;
        }
        else{
           printf("\n%d               %-6s               %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);
        i++;
        seen=1;
        }
    }
    if(!seen){
        printf("\n                           NO CANDIDATES.CANDIDATE TABLE IS EMPTY                    \n");//if no candidates are there .
    }
    printf("\n----------------------------------------------------------------------------------------\n");
    fclose(p);
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    return 1;

}

void search(struct candidate s){
    FILE *p;
    int choice,i=1;
    p=fopen("d:\\data.txt","r");//binary file.
    char can[90];
    int num;
    int seen=0;
    fflush(stdin);
    //search by user's convenience.
    printf("-------------------------------********** Portal to Search Candidates **********-------------------------------\n\n");
    printf("WHAT KIND OF SEARCH DO U PREFER\n");
    printf("enter 2 TO SEARCH BY CANDIDATE NAME\n");
    printf("enter 3 TO SEARCH BY DIVISION NAME\n");
    printf("enter 4 TO SEARCH BY PARTY NAME\n");
    scanf("%d",&choice);
    char a[90]="ID",b[90]="NAME",c[90]="PARTY",d[90]="DIVISION",e[90]="CANDIDATE.NO";
    //check for candidate according to user input in the file.
    if(choice==2){
    fflush(stdin);
    printf("ENTER THE NAME OF THE CANDIDATE TO SEARCH: \n");
    scanf("%[^\n]s",can);
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\n%s     %s                  %-20s%-18s %-20s\n",e,a,b,c,d);
    printf("\n----------------------------------------------------------------------------------------\n");
    //printing the candidate details which is entered by the user.
    while(fread(&s,sizeof(s),1,p)){
        if(strcmp(can,s.name)==0){
        seen=1;
        if(i<10){
        printf("\n     %d.         %-6s               %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);//prints all attributes of the matching candidate name
        i++;
        }
        else{
           printf("\n%d              %-6s               %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);
        i++;
        }
        printf("\n---------------------------------------------------------------------------------------\n");

    }

    }
    if(!seen){
        printf("\n    NO SUCH CANDIDATE IS FOUND\n");
        printf("\n------------------------------------------------------------------------------------\n");

    }

    fclose(p);
	printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}}
    //check for party according to user input in the file.
    else if(choice==4){
         fflush(stdin);
         printf("ENTER THE NAME OF THE PARTY TO SEARCH: \n");
         scanf("%[^\n]s",can);
         printf("\n--------------------------------------------------------------------------------------------\n");
         printf("\n%s     %s                  %-20s%-18s %-20s\n",e,a,b,c,d);
         printf("\n--------------------------------------------------------------------------------------------\n");
         //print the candidate according to party.
    while(fread(&s,sizeof(s),1,p)){
        if(strcmp(can,s.party)==0){
        seen=1;
        if(i<10){
        printf("\n     %d.         %-6s               %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);//prints all attributes of the matching party which is entered by user.
        i++;
        }
        else{
           printf("\n%d              %-6s               %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);
        i++;
        }
        printf("\n--------------------------------------------------------------------------------------------\n");

    }

    }
    if(!seen){
        printf("\n    NO SUCH PARTY IS FOUND\n");
        printf("\n-----------------------------------------------------------------------------------------\n");

    }

    fclose(p);
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    }
    // check for the division according to user input
    else if(choice==3){
          printf("ENTER THE NUMBER OF DIVISION TO SEARCH: \n");
          scanf("%d",&num);
          seen=0;
          printf("\n--------------------------------------------------------------------------------------------\n");
          printf("\n%s     %s                  %-20s%-18s %-20s\n",e,a,b,c,d);
          printf("\n--------------------------------------------------------------------------------------------\n");

    while(fread(&s,sizeof(s),1,p)){
        if(num==s.division){
        seen=1;
        if(i<10){
        printf("\n     %d.         %-6s                %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);//prints all attributes according to the division.
        i++;
        }
        else{
           printf("\n%d              %-6s                %-20s %-20s%-5d\n",i,s.ID,s.name,s.party,s.division);
        i++;
        }
        printf("\n--------------------------------------------------------------------------------------------\n");



    }

    }
    if(!seen){
        printf("\n   NO SUCH DIVISION IS FOUND\n");
        printf("\n-----------------------------------------------------------------------------------------\n");
        //when user enters a invalid division.
    }

    fclose(p);
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    }
    main();

}
int validate1(struct candidate s){
    FILE *p;
    int choice,i;
    p=fopen("d:\\data.txt","r+");//opening in r+ mode to open the file successfully.
    int seen=0;
    fflush(stdin);
    printf("PLEASE ENTER YOUR NAME TO CHECK VALIDATION: \n");
    scanf("%[^\n]s",can.name);
    for(i=0;i<1;i++){
            fflush(stdin);
            printf("ENTER THE PARTY NAME TO CHECK VALIDATION\n");
            scanf("%[^\n]s",can.party);
            fflush(stdin);
            //check whether the user enters the valid division number or not.
            for(i=0;i<1;i++){

        printf("ENTER THE DIVISION(1-4)");
        scanf("%d",&can.division);
        fflush(stdin);
        //p=fopen("d:\\data.txt","r");
        fseek(p,0,SEEK_END);
        int ID=ftell(p)/sizeof(s);//to get the no of candidates present in the candidate table.
        ID=ID+11;
        char party[4];
        strncpy(party,can.party,3);
        party[3]='\0';
        sprintf(can.ID,"%s%d",party,ID);//creation of ID.
        s.Count=0;

        if(can.division>0 && can.division<5){
            fseek(p,0,SEEK_SET);//setting the pointer to first position in the file.
            break;
        }
        else {
            printf("PLEASE ENTER VALID DIVISION NUMBER\n");
            i=-1;
            continue;//executes when user enters an invalid division number.

        }

            }



     //check whether the candidate is registered already or not.
     while(fread(&s,sizeof(s),1,p)){
        if(can.division==s.division && strcmp(s.party,can.party)==0){//checks whether the party is registered in that division or not.
        seen=1;
        printf("SORRY,YOU ARE ALREADY REGISTERED.YOU ARE NOT ABLE TO REGISTER AGAIN. OR THIS DIVISION IS REGISTERD BY OTHER CANDIDATE IN YOUR PARTY\n");
        printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
        fclose(p);
        return 0;
          }
        }
    if(!seen){
        fclose(p);
        return 1;
    }




    }


}
void check(struct candidate s){
    FILE *p;
    int candidate;
    fflush(stdin);
    p=fopen("d:\\data.txt","r");
    //gives total no of records that is found in the file.
    fseek(p,0,SEEK_END);
    candidate=ftell(p)/sizeof(s);
    printf("-------------------------------********** Number of Candidates **********-------------------------------\n\n");
    printf("THE TOTAL NUMBER OF CANDIDATES STANDING IN THE ELECTION IS: %d\n",candidate);
    printf("\n");
    fclose(p);
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    main();

}
void vote(struct voter s){
    FILE *p,*fp;
    int t;
    char status[3]="N";
    p=fopen("d:\\data2.txt","a+");//text file.
    fp=fopen("d:\\votecandidate.txt","a+");//text file.

    if(p==NULL){
        printf("FILE DATA 2 NOT OPENED\n");
    }
    if(fp==NULL){
        printf("FILE VOTECANDIDATE NOT OPENED\n");
    }
    fflush(stdin);
    int n,i,j;
    //move to validation.
    t=validate2(vot);//validates whether the voter has voted or already registered for voting.
    if(t==1){
    for(i=0;i<1;i++){
        fflush(stdin);
        printf("\nYOU ARE ELIGIBLE TO VOTE\n\n");

        printf("ENTER YOUR NAME: ");
        scanf("%[^\n]s",vot.name);
        fflush(stdin);

        printf("ENTER THE DIVISION(1-4): ");
        scanf("%d",&vot.division);
        fflush(stdin);
        //write in the file after checking the validation

        fwrite(&vot,sizeof(vot),1,p);//writing in binary file.
        fprintf(fp,"\n%-20s%-20s%-20d%-20d  %-20s\n",vot.ID,vot.name,vot.age,vot.division,status);//writing in text file



    }
    }
    fclose(p);
    fclose(fp);
    printf("\nNew Voter added to record\n");
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    main();
}

void viewvoter(struct voter s){
    FILE *p;
    char status[3]="N";
    int seen=0;
    char a[90]="ID",b[90]="NAME",c[90]="AGE",d[90]="DIVISION",e[90]="STATUS";
    p=fopen("d:\\data2.txt","r");
    if(p==NULL){
        printf("\n FILE NOT OPENED \n");
    }
    printf("-------------------------------********** Voter Table **********------------------------------\n\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("\n   %-20s  %-20s%-20s%-20s %-20s\n",a,b,c,d,e);
    printf("\n---------------------------------------------------------------------------------------------\n");
    //view the voters present in the file.
    while(fread(&s,sizeof(s),1,p)){
          printf("\n  %-20s%-20s   %-20d   %-20d%-20s\n",s.ID,s.name,s.age,s.division,status);
          seen=1;
          }
    if(!seen){
        printf("\n                            NO VOTERS.VOTER TABLE IS EMPTY.     \n");
    }
    printf("\n----------------------------------------------------------------------------------------------\n");
    fclose(p);
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    main();
}



int validate2(struct voter s1){
    FILE *p,*p1;
    p=fopen("d:\\data2.txt","r+");//binary file.
    p1=fopen("d:\\votedvoters.txt","r+");//binary file.
    if(p1==NULL){
        printf("VOTEDVOTERS FILE NOT OPENED\n");
    }
    int seen=0;
    fflush(stdin);
    printf("PLEASE ENTER YOUR ID TO CHECK VALIDATION: ");
    scanf("%[^\n]s",vot.ID);
    fflush(stdin);
    printf("ENTER THE AGE:\n");
    scanf("%d",&vot.age);
    fflush(stdin);
    //check for the eligibility for voting
    while(fread(&s1,sizeof(s1),1,p)){
          if((strcmp(vot.ID,s1.ID)==0)){
            seen++;
            printf("YOU ARE REGISTERING FOR SECOND TIME.\n");
            fclose(p);
            main();
            }
          }
    fseek(p,0,SEEK_SET);
    while(fread(&s1,sizeof(s1),1,p)){
          if(vot.age<=18){
            seen++;
            printf("YOU ARE INELIGIBLE TO VOTE\n");
            fclose(p);
            main();
            }
          }
        fseek(p,0,SEEK_SET);

          //check whether the voter has been already voted or not.
    while(fread(&s1,sizeof(s1),1,p1)){
          if(strcmp(vot.ID,s1.ID)==0){
            seen++;
            printf("YOU ARE VOTING FOR SECOND TIME.NOT VALID.\n");
            fclose(p1);
            main();
          }
    }

          if(!seen){
            fclose(p);
            fclose(p1);
            return 1;
          }

   fclose(p);



}

int votecasting(int *a,int *b,int *c,int *d,int *w,int *f,int *g,int *h,int *u,int *j,int *k,int *l,int *m,int *n,int *o,int *q,struct voter s,struct candidate s1){
    FILE *p,*fp,*p1;
    fp=fopen("d:\\data.txt","r+");//opening in r+ mode for overwrite the count value of candidate.
    p=fopen("d:\\data2.txt","a+");
    if(p==NULL){
        printf("FILE DATA NOT OPENED");
    }
    if(fp==NULL){
            printf("DATA 2 NOT OPENED");
    }
    int seen=0;
    int found=0;
    int r,x,lp,pl;
    int res,t,i;
    char vote[90];
    char fg[90]="NAME",cf[90]="PARTY",de[90]="DIVISION",rt[90]="COUNT";
    char voterid[90];
    char votername[90];
    char status[3]="Y";
    int  voterdivision;
    fflush(stdin);
    printf("ENTER THE NAME AND YOUR DIVISION(1-4)\n");
    scanf("%[^\n]s",votername);
    fflush(stdin);
    scanf("%d",&voterdivision);
    fflush(stdin);
    printf("ENTER THE VOTERID\n");
    scanf("%[^\n]s",voterid);
    fflush(stdin);
    //check whether the entered details matches with the voters registered table.
    while(fread(&s,sizeof(s),1,p)){
        if(strcmp(votername,s.name)==0 && strcmp(voterid,s.ID)==0 && (voterdivision==s.division)){//matches the voter name,ID,division in the voter table with respect to the details entered by voter

            printf("YOU ARE A REGISTERED VOTER\n");//checking registered voter or not.
            seen=1;
            fflush(stdin);
            pl=viewcandidate(can);
            for(int i=0;i<1;i++){
            fseek(fp,0,SEEK_END);//moving up the pointer to the end to get the total number of voters.
            int noofcan=ftell(fp)/sizeof(can);//to get the number of candidates.
            fseek(fp,0,SEEK_SET);//setting the pointer to first position in the file.
            int candindex=0;
            fflush(stdin);
            //voting through candidate id.
            printf("ENTER THE CANDIDATE ID TO VOTE\n");
            scanf("%[^\n]s",vote);
            fflush(stdin);
            for(int ii=1;ii<=noofcan;ii++){//iterates until the file reaches to the end.
                    fread(&can,sizeof(can),1,fp);
                    if(strcmp(vote,can.ID)==0 && voterdivision==can.division){
                        candindex=ii;//if the candidate ID and division matches then we calculate the offset is calculated.

                        found=1;
                        break;
                    }
                  }
            long offset=(candindex-1)*sizeof(can);//to get the offset .
            fseek(fp,offset,SEEK_SET);
            can.Count++;
            fwrite(&can,sizeof(can),1,fp);//overwrites the value of count.


            //checks whether he has entered valid candidate id.
            if(!found){
                printf("ENTER THE VALID CANDIDATE ID IN YOUR DIVISION\n");
                i=-1;//when user enters the invalid candidate ID starts iteration again.
                fseek(fp,0,SEEK_SET);
                continue;
            }
            }


           fclose(fp);
           fclose(p);








            lp=view1reg(vot,voterid);//to store the voters who has voted.
            x=deletevoter(vot,voterid);//to delete the voters who has voted from register table.



                 break;


            }
    }


    if(!seen){
        printf("YOU ARE VOTING FOR SECOND TIME NOT VALID  OR YOU HAVE ENTERED WRONG PERSONAL INFORMATION.\n");

    }
    //calculating and printing the results automatically after the election gets completed.
    int large=0,large2=0,large3=0,large4=0;



        t=check2(vot);//checks whether the register table becomes empty to display the results automatically.
        if(t==0){
        fp=fopen("d:\\data.txt","r");
        if(fp==NULL){
            printf("FILE NOT OPENED\n");
        }
        else{

            while(fread(&can,sizeof(can),1,fp)){//reads the entire file up to the end.

                        if(can.division==1 ){
                            if(can.Count>large){
                                large=can.Count;//get the highest number of votes in division 1.
                                 continue;
                            }
                        }


            }

            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==2 ){
                            if(can.Count>large2){
                                large2=can.Count;//get the highest number of votes in division 2.
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==3 ){
                            if(can.Count>large3){
                                large3=can.Count;//get the highest number of votes in division 3.
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==4 ){
                            if(can.Count>large4){
                                large4=can.Count;//get the highest number of votes in division 4.
                                 continue;
                            }
                        }


            }


        }





        fclose(fp);
        fp=fopen("d:\\data.txt","r");
        while(fread(&can,sizeof(can),1,fp)){//finding the winners by using the highest votes in each division.
            if(can.division==1){
                if(can.Count==large){//if candidate count matches with the large value then,that candidate is the winner in division 1.
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 1.%s IS THE WINNER IN DIVISION 1***   \n",can.name,can.party);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){//if candidate count matches with the large value then,that candidate is the winner in division 1.
            if(can.division==2){
                if(can.Count==large2){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 2.%s IS THE WINNER IN DIVISION 2***    \n",can.name,can.party);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==3){
                if(can.Count==large3){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 3.%s IS THE WINNER IN DIVISION 3***     \n",can.name,can.party);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==4){
                if(can.Count==large4){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 4.%s IS THE WINNER IN DIVISION 4***       \n",can.name,can.party);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
         printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
        }


       else if(t==1){//checks whether the voter table(register table ) becomes empty,if it becomes empty then the result will be automatically displayed.
            printf("\n           THE ELECTION IS GOING ON.RESULTS WILL BE SHOWN AFTER THE ELECTION GETS COMPLETED        \n");
        }













    fclose(fp);
  printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}


}
//after entering the vote to remove the voter from registered voter table.
int deletevoter(struct voter s,char *voterid){
    FILE *p,*p1;
    int seen=0;
    p=fopen("d:\\data2.txt","r");//binary
    p1=fopen("d:\\test1.txt","w");//binary
    while(fread(&s,sizeof(s),1,p)){
        if(strcmp(s.ID,voterid)==0){//omitting the voted voter.
            seen=1;
        }
        else
            fwrite(&s,sizeof(s),1,p1);//only writes the non-voters in the file .all the voters who has voted will be skipped.
    }
    fclose(p);
    fclose(p1);

    if(seen){
        p1=fopen("d:\\test1.txt","r");
        p=fopen("d:\\data2.txt","w");

        while(fread(&s,sizeof(s),1,p1)){
            fwrite(&s,sizeof(s),1,p);//copying from test file to data 2 file.
        }
        fclose(p);
        fclose(p1);
        return 1;

    }

    }
//writing the voted voters in file.
int view1reg(struct voter s,char *voterid){
    FILE *p,*p1;
    int seen=0,i=0;
    p=fopen("d:\\data2.txt","r");
    p1=fopen("d:\\votedvoters.txt","a+");
    while(fread(&s,sizeof(s),1,p)){
        if(strcmp(s.ID,voterid)==0){
            seen=1;
            fwrite(&s,sizeof(s),1,p1);//writes only the voted voters in the  votedvoters file.
        }
    }
    fclose(p);
    fclose(p1);
    return i;


}
//displaying the voted voters from the file.
void view2reg(struct voter s){
    FILE *p;
    char status[3]="Y";
    char a[90]="ID",b[90]="NAME",c[90]="AGE",d[90]="DIVISION",e[90]="STATUS";
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\n%-20s%-20s%-20s%-20s%-20s\n",a,b,c,d,e);
    printf("\n------------------------------------------------------------------------------------------\n");
    p=fopen("d:\\votedvoters.txt","r");
    //displaying the voted voters from the file
    while(fread(&s,sizeof(s),1,p)){
          printf("\n%-20s%-20s%-20d%-20d  %-20s\n",s.ID,s.name,s.age,s.division,status);
          }
    printf("\n-------------------------------------------------------------------------------------------\n");
    fseek(p,0,SEEK_SET);
    fclose(p);
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    main();

}



//it sorts the candidates division by division in ascending order for voter convenience.
void sortbydivision(){
    struct candidate s;
    struct candidate s1[50];
    int l;

    int num1=0,j,num2=0;
    FILE *fp;
    fp=fopen("d:\\data.txt","r");
    char a[90]="ID",b[90]="NAME",c[90]="PARTY",d[90]="DIVISION",e[90]="CANDIDATE.NO";

    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\n%s     %s                   %-20s%-18s %-20s\n",e,a,b,c,d);
    printf("\n----------------------------------------------------------------------------------------\n");
    num1=0;
    while(fread(&s1[num1],sizeof(s1[num1]),1,fp)){
        num1++;
        num2++;
    }
    for(num1=0;num1<num2;num1++){
        for(j=0;j<num2-num1-1;j++){
            if(s1[j].division>s1[j+1].division){
                s=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=s;
            }

        }
    }
    for(num1=0,l=1;num1<num2;num1++){

         if(l<10){
         printf("\n%d.              %6s               %-20s %-20s  %-5d\n",l,s1[num1].ID,s1[num1].name,s1[num1].party,s1[num1].division);
         }
         else{
           printf("\n%d               %6s              %-20s %-20s  %-5d\n",l,s1[num1].ID,s1[num1].name,s1[num1].party,s1[num1].division);
         }
         l++;

    }
    printf("\n-----------------------------------------------------------------------------------------\n");
    fclose(fp);

     printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
}
//checks no of voters in voter table.

int check2(struct voter s){
    FILE *p;
    p=fopen("d:\\data2.txt","r");
    fseek(p,0,SEEK_END);//reads until the end of file is reached.
    int voter = ftell(p)/sizeof(s);//gives the number of voters.
    if(voter==0){
        return 0;
    }
    else{
        return 1;
    }

    fclose(p);

}

void instructions(){
    printf("\n **NOTE THAT FOR VOTING YOU MUST HAVE REGISTERED ALREADY.FOR REGISTRATION PRESS 7**\n");
    printf("\n **IF YOU ARE VOTING BEFORE REGISTERING,THEN YOU WILL BE CONSIDERED INELIGIBLE TO VOTE\n");
    printf("\n **NOTE THAT IN THIS ELECTION THERE ARE ONLY FOUR DIVISIONS IN SUCH A WAY WE HAVE DESIGNED IT.**\n");
    printf("\n **AFTER THE VOTING HAS COMPLETED, THE RESULTS  WILL BE VIEWED AUTOMATICALLY** \n");
    printf("\n **THE ELECTION WILL CONSIDERED AS COMPLETED  IF AND ONLY IF ALL THE REGISTERED CANDIDATES IN THE TABLE SHOULD BE VOTED FOR A PARTICULAR PERSON IN A PARTICULAR PARTY IN PARTICULAR DIVISION**\n");
    printf("\n **OPTION 1 ALLOWS THE USER TO READ INSTRUCTIONS**\n");
    printf("\n **OPTION 2 ALLOWS THE USER TO ADD HIM AS CANDIDATE**\n");
    printf("\n **OPTION 3 ALLOWS THE USER TO VIEW THE CANDIDATES**\n");
    printf("\n **OPTION 4 ALLOWS THE USER TO EXIT**\n");
    printf("\n **OPTION 5 ALLOWS THE USER TO SEARCH A CANDIDATE BY MEANS OF DIVISION,NAME,PARTY**\n");
    printf("\n **OPTION 6 ALLOWS THE USER TO VISUALIZE THE TOTAL NUMBER OF CANDIDATES STANDING IN THE ELECTION**\n");
    printf("\n **OPTION 7 ALLOWS THE USER TO ADD HIM AS A VOTER IN REGISTER TABLE**\n");
    printf("\n **OPTION 8 ALLOWS THE USER TO VISUALIZE THE VOTERS**\n");
    printf("\n **OPTION 9 ALLOWS THE USER TO CAST THE VOTES**\n");
    printf("\n **OPTION 10 ALLOWS THE USER TO SORT THE CANDIDATES BY MEANS OF DIVISION**\n");
    printf("\n **OPTION 11 ALLOWS THE USER TO VIEW THE CURRENT STATUS OF THE CANDIDATES IN BETWEEN THE VOTING BASED ON CONVENIENCE.ONLY AUTHORIZED PERSON IS ADVICED TO VIEW USE THIS OPTION**\n");
    printf("\n **OPTION 12 ALLOWS THE USER TO VISUALIZE THE RESULTS IN ALL DIVISIONS**\n");
    printf("\n **OPTION 13 ALLOWS THE USER TO VIEW THE VOTERS WHO HAS VOTED**\n");
    printf("\n **OPTION 14 ALLOWS THE USER TO VISUALIZE THE RESULTS IN PARTICULAR DIVISION FOR CONVENIENCE.**\n");
    printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
}

//printing the current status of the candidates by voter convenience.
void viewcanvote(struct candidate s1,int *t1,int *t2,int *t3,int *t4){

        FILE *fp;
        int sp,seen=0;
        int fgp;
        char par[90],can[90];
        int total=0,total2=0,total3=0,total4=0;
        int voterdivision;
        fp=fopen("d:\\data.txt","r");
        char ag[90]="ID",fg[90]="NAME",cf[90]="PARTY",de[90]="DIVISION",rt[90]="COUNT",st[90]="PERCENTAGE";
        printf("ENTER 1 TO SEARCH BY CANDIDATE\n");
        printf("ENTER 2 TO SEARCH BY DIVISION\n");
        printf("ENTER 3 TO SEARCH BY PARTY\n");
        scanf("%d",&sp);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1 ){
                total=total+s1.Count;
                *t1=total;//get total number of votes in division 1.
                continue;
            }


        }

        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2 ){
                total2=total2+s1.Count;
                *t2=total2;//get total number of votes in division 2.
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){
                total3=total3+s1.Count;
                *t3=total3;//get total number of votes in division 3.
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);

        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4 ){
                total4=total4+s1.Count;
                *t4=total4;//get total number of votes in division 4.
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        if(sp==2){
        for(fgp=0;fgp<1;fgp++){


        printf("ENTER THE DIVISION YOU WANT\n");
        scanf("%d",&voterdivision);
        if(voterdivision>0 && voterdivision<5){
            break;
        }
        else{
            printf("PLEASE ENTER A VALID DIVISION NUMBER\n");//accept only the valid division number.
            fgp=-1;
            continue;

        }
        }





      printf("\n---------------------------------------------------------------------------------------------------------------------------\n");
      printf("\n%-20s%-20s%-20s   %-20s  %-20s  %-20s\n",ag,fg,cf,de,rt,st);
      printf("\n---------------------------------------------------------------------------------------------------------------------------\n");

      total=0;
      if(voterdivision==1){

        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1 ){

                total=total+s1.Count;
                *t1=total;//storing the total number of votes in division 1.
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1){
                float percent=0.0;
                if(total>0)//if the voting starts in the division 1 then percentage is calculated.
                    percent=(s1.Count/(float)total)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);


    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
}
        total2=0;
       if(voterdivision==2){

             while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2 ){//storing the total number of votes in division 2.

                total2=total2+s1.Count;
                *t2=total2;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2){
                float percent=0.0;
                if(total2>0)//if the voting starts in the division 2 then percentage is calculated.
                    percent=(s1.Count/(float)total2)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);

       printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
       }
       total3=0;
        if(voterdivision==3){

          while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){//storing the total number of votes in division 3.

                total3=total3+s1.Count;
                *t3=total3;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){
                float percent=0.0;
                if(total3>0)//if the voting starts in the division 3 then percentage is calculated.
                    percent=(s1.Count/(float)total3)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);

       printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
        }
        total4=0;
        if(voterdivision==4){

          while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4 ){//storing the total number of votes in division 4.

                total4=total4+s1.Count;
                *t4=total4;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4){
                float percent=0.0;
                if(total4>0)//if the voting starts in the division 3 then percentage is calculated.
                    percent=(s1.Count/(float)total4)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);


        printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
        }
        printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}

        }


        else if(sp==1){


            fflush(stdin);
            printf("ENTER THE NAME OF THE CANDIDATE U WANT TO SEARCH");
            scanf("%[^\n]s",can);
             printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
             printf("\n%-20s%-20s%-20s   %-20s  %-20s  %-20s\n",ag,fg,cf,de,rt,st);
             printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
            int total=0;
            int total2=0;
            int total4=0;
             while(fread(&s1,sizeof(s1),1,fp)){
            if( strcmp(s1.name,can)==0 && s1.division==1){//matches the candidate name in division 1.

                    float percent=0.0;
                    if(*t1>0)
                    percent=(s1.Count/(float)*t1)*100;

                 printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                 seen=1;
                continue;
            }
             }



            fseek(fp,0,SEEK_SET);
             while(fread(&s1,sizeof(s1),1,fp)){

                  if( strcmp(s1.name,can)==0 && s1.division==2){//matches the candidate name in division 2.

                      float percent=0.0;
                      if(*t2>0)
                         percent=(s1.Count/(float)*t2)*100;
                         printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                         seen=1;
                         continue;
             }
             }

             fseek(fp,0,SEEK_SET);
               while(fread(&s1,sizeof(s1),1,fp)){

                    float percent=0.0;
                    if(*t3>0)
                    percent=(s1.Count/(float)*t3)*100;

                if( strcmp(s1.name,can)==0 && s1.division==3){//matches the candidate name in division 3.
                 printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                 seen=1;
                continue;
            }
               }
            fseek(fp,0,SEEK_SET);

            while(fread(&s1,sizeof(s1),1,fp)){
            if( strcmp(s1.name,can)==0 && s1.division==4){//matches the candidate name in division 4.

                    float percent=0.0;
                    if(*t4>0)
                    percent=(s1.Count/(float)*t4)*100;
                 printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                 seen=1;
                continue;
            }

            }
            fseek(fp,0,SEEK_SET);
            if(!seen){
                printf("\n                             NO SUCH CANDIDATE EXISTS                 \n");
            }


           printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");









            fclose(fp);
            printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
        }

       else if(sp==3){
            fflush(stdin);
            printf("ENTER THE NAME OF THE PARTY TO SEARCH: \n");
            scanf("%[^\n]s",can);
             printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
             printf("\n%-20s%-20s%-20s   %-20s  %-20s  %-20s\n",ag,fg,cf,de,rt,st);
             printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
             while(fread(&s1,sizeof(s1),1,fp)){
            if( strcmp(s1.party,can)==0 && s1.division==1){//matches the party name in division 1.
                    seen=1;
                    float percent=0.0;
                    if(*t1>0)
                    percent=(s1.Count/(float)*t1)*100;
                 printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
             }



            fseek(fp,0,SEEK_SET);
             while(fread(&s1,sizeof(s1),1,fp)){

                  if( strcmp(s1.party,can)==0 && s1.division==2){//matches the party name in division 2.
                      seen=1;
                      float percent=0.0;
                      if(*t2>0)
                      percent=(s1.Count/(float)*t2)*100;
                         printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                         continue;
             }
             }

             fseek(fp,0,SEEK_SET);
               while(fread(&s1,sizeof(s1),1,fp)){

                    float percent=0.0;
                    if(*t3>0)
                    percent=(s1.Count/(float)*t3)*100;

                if( strcmp(s1.party,can)==0 && s1.division==3){//matches the party name in division 3.
                        seen=1;
                 printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                    continue;
            }
               }
            fseek(fp,0,SEEK_SET);

            while(fread(&s1,sizeof(s1),1,fp)){
            if( strcmp(s1.party,can)==0 && s1.division==4){//matches the party name in division 4.
                    seen=1;
                    float percent=0.0;
                    if(*t4>0)
                    percent=(s1.Count/(float)*t4)*100;
                 printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }

            }
              fseek(fp,0,SEEK_SET);
            if(!seen){

              printf("\n                                  NO SUCH PARTY EXISTS                             \n");


           }




     printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);
        }












        fclose(fp);
        printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}

}
//printing the winning status of all candidates in all divisions.
void viewcanvote2(struct candidate s1){
      FILE *fp,*p1;
      fp=fopen("d:\\data.txt","r");
      p1=fopen("d:\\results.txt","a+");
      char ag[90]="ID",fg[90]="NAME",cf[90]="PARTY",de[90]="DIVISION",rt[90]="COUNT",st[90]="PERCENTAGE";

      printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
      printf("\n%-20s%-20s%-20s   %-20s  %-20s  %-20s\n",ag,fg,cf,de,rt,st);
      printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

      int total=0;
      int total3=0;
      int total2=0;

      int total4=0;
      int to1,to2,to3,to4;



        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1 ){
                total=total+s1.Count;//calculates the total in division 1.
                to1=total;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1){
                float percent=0.0;
                if(total>0)
                    percent=(s1.Count/(float)total)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                fprintf(p1,"\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);





             while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2 ){

                total2=total2+s1.Count;
                to2=total2;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2){
                float percent=0.0;
                if(total2>0)
                    percent=(s1.Count/(float)total2)*100;//reads from the binary file.
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                fprintf(p1,"\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                //writing in the text file.
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);






          while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){

                total3=total3+s1.Count;
                to3=total3;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){
                float percent=0.0;
                if(total3>0)
                    percent=(s1.Count/(float)total3)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                fprintf(p1,"\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);





          while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4 ){

                total4=total4+s1.Count;
                to4=total4;
                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4){
                float percent=0.0;
                if(total4>0)
                    percent=(s1.Count/(float)total4)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                fprintf(p1,"\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);
        fclose(p1);

        printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");



      int large=0;
      int large2=0;
      int large3=0;
      int large4=0;
      while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==1 ){
                            if(can.Count>large){
                                large=can.Count;
                                 continue;
                            }
                        }


            }

            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==2 ){
                            if(can.Count>large2){
                                large2=can.Count;
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==3 ){
                            if(can.Count>large3){
                                large3=can.Count;
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==4 ){
                            if(can.Count>large4){
                                large4=can.Count;
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);

            printf("\n                         ---------------------PRINTING THE WINNERS---------------------------                     \n");



        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==1){
                if(can.Count==large){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 1.%s IS THE WINNER IN DIVISION 1.NO OF VOTES IS %d.***   \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==2){
                if(can.Count==large2){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 2.%s IS THE WINNER IN DIVISION 2.NO OF VOTES IS %d.***    \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==3){
                if(can.Count==large3){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 3.%s IS THE WINNER IN DIVISION 3.NO OF VOTES IS %d.***     \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==4){
                if(can.Count==large4){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 4.%s IS THE WINNER IN DIVISION 4.NO OF VOTES IS %d.***       \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);



        fclose(fp);

        fp=fopen("d:\\data.txt","r");
        int sm1=10000,sm2=10000,sm3=100000,sm4=100000;
        printf("\n            --------------------------THE CANDIDATES WITH LOWEST NUMBER VOTES-----------------------------\n");
        while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==1 ){
                            if(can.Count<sm1){
                                sm1=can.Count;//get the lowest number of votes in division 1.
                                 continue;
                            }
                        }


            }

            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==2 ){
                            if(can.Count<sm2){
                                sm2=can.Count;//get the lowest number of votes in division 2.
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==3 ){
                            if(can.Count<sm3){
                                sm3=can.Count;//get the lowest number of votes in division 3.
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==4 ){
                            if(can.Count<sm4){
                                sm4=can.Count;//get the lowest number of votes in division 4.
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){
            if(can.division==1){
                if(can.Count==sm1){//matches candidate count with sm1 ,if it matches then that candidate is the winner in division 1.
                    printf("\n                  ****%s(%s) IS LOSER IN DIVISION 1.NO OF VOTES IS %d.***   \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){//matches candidate count with sm2 ,if it matches then that candidate is the winner in division 2.
            if(can.division==2){
                if(can.Count==sm2){
                    printf("\n                  ****%s (%s) IS THE LOSER IN DIVISION 2.NO OF VOTES IS %d.***    \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){//matches candidate count with sm3 ,if it matches then that candidate is the winner in division 3.
            if(can.division==3){
                if(can.Count==sm3){
                    printf("\n                  ****%s(%s) IS THE LOSER IN DIVISION 3.NO OF VOTES IS %d.***     \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);
        while(fread(&can,sizeof(can),1,fp)){//matches candidate count with sm4 ,if it matches then that candidate is the winner in division 4.
            if(can.division==4){
                if(can.Count==sm4){
                    printf("\n                  ****%s HAS GOT LOWEST NUMBER OF VOTES IN THE DIVISION 4.%s IS THE LOSER IN DIVISION 4.NO OF VOTES IS %d.***       \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        fseek(fp,0,SEEK_SET);





        fclose(fp);

        printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
}


//printing the results in accordance with voter convenience.
void viewbydiv(struct candidate s1){
      FILE *fp;
      int fgp,voterdivision;
      fp=fopen("d:\\data.txt","r");

      char ag[90]="ID",fg[90]="NAME",cf[90]="PARTY",de[90]="DIVISION",rt[90]="COUNT",st[90]="PERCENTAGE";
      for(fgp=0;fgp<1;fgp++){


        printf("ENTER THE DIVISION YOU WANT\n");
        scanf("%d",&voterdivision);
        if(voterdivision>0 && voterdivision<5){
            break;
        }
        else{
            printf("PLEASE ENTER A VALID DIVISION NUMBER\n");
            fgp=-1;
            continue;

        }

        }
      int r,sp3,sp1,sp2;
      int total=0;
      int total3=0;
      int total2=0;
      int total4=0;
      int large=0;
      int large2=0;
      int large3=0;
      int large4=0;
      printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
      printf("\n%-20s%-20s%-20s   %-20s  %-20s  %-20s\n",ag,fg,cf,de,rt,st);
      printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
      if(voterdivision==1){

        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1 ){
                total=total+s1.Count;

                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==1){
                float percent=0.0;
                if(total>0)
                    percent=(s1.Count/(float)total)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);


    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
}
        total2=0;
       if(voterdivision==2){

             while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2){
                total2=total2+s1.Count;

                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==2){
                float percent=0.0;
                if(total2>0)
                    percent=(s1.Count/(float)total2)*100;

                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);

       printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
       }
       total3=0;
        if(voterdivision==3){

          while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){

                total3=total3+s1.Count;

                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==3 ){
                float percent=0.0;
                if(total3>0)
                    percent=(s1.Count/(float)total3)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);

       printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
        }
        total4=0;
        if(voterdivision==4){

          while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4 ){

                total4=total4+s1.Count;

                continue;
            }


        }
        fseek(fp,0,SEEK_SET);
        while(fread(&s1,sizeof(s1),1,fp)){
            if( s1.division==4){
                float percent=0.0;
                if(total4>0)
                    percent=(s1.Count/(float)total4)*100;
                printf("\n%-20s%-20s%-20s     %-5d                 %-5d                 %5f\n",s1.ID,s1.name,s1.party,s1.division,s1.Count,percent);
                continue;
            }
        }
        fseek(fp,0,SEEK_SET);


        printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
        }

      while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==1 ){
                            if(can.Count>large){
                                large=can.Count;
                                 continue;
                            }
                        }


            }

            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==2 ){
                            if(can.Count>large2){
                                large2=can.Count;
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==3 ){
                            if(can.Count>large3){
                                large3=can.Count;
                                 continue;
                            }
                        }


            }
            fseek(fp,0,SEEK_SET);
            while(fread(&can,sizeof(can),1,fp)){

                        if(can.division==4 ){
                            if(can.Count>large4){
                                large4=can.Count;
                                 continue;
                            }
                        }


            }
            printf("\n                         ---------------------PRINTING THE WINNERS---------------------------                     \n");



        fseek(fp,0,SEEK_SET);
        if(voterdivision==1){// if the user division matches then that the attributes of that division is displayed.
        while(fread(&can,sizeof(can),1,fp)){
            if(can.division==1){
                if(can.Count==large){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 1.%s IS THE WINNER IN DIVISION 1.NO OF VOTES IS %d.***   \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        }
        else if(voterdivision==2){
        while(fread(&can,sizeof(can),1,fp)){// if the user division matches then that the attributes of that division is displayed.
            if(can.division==2){
                if(can.Count==large2){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 2.%s IS THE WINNER IN DIVISION 2.NO OF VOTES IS %d.***    \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        }



        else if(voterdivision==3){
        while(fread(&can,sizeof(can),1,fp)){// if the user division matches then that the attributes of that division is displayed.
            if(can.division==3){
                if(can.Count==large3){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 3.%s IS THE WINNER IN DIVISION 3.NO OF VOTES IS %d.***     \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        }
        else if(voterdivision==4){
        while(fread(&can,sizeof(can),1,fp)){// if the user division matches then that the attributes of that division is displayed.
            if(can.division==4){
                if(can.Count==large4){
                    printf("\n                  ****%s IS THE WINNER IN THE DIVISION 4.%s IS THE WINNER IN DIVISION 4.NO OF VOTES IS %d.***       \n",can.name,can.party,can.Count);
                    continue;
                }
            }
        }
        }
        fseek(fp,0,SEEK_SET);

        fclose(fp);
        printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
    	main();
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}



}






int main(){

    int i=1;


    while(i){
    printf("\t\t\t\t\t\tElectoral Commission E-Systems\n");
    printf("Menu Options: \n");
    printf("ENTER [1] TO SEARCH A CANDIDATE BY YOUR CONVINIENCE\n");
    printf("ENTER [2] TO CHECK THE TOTAL NUMBER OF CANDIDATES\n");
    printf("ENTER [3] TO CHECK THE ELIGIBILITY FOR VOTING AND TO REGISTER FOR VOTING\n");
    printf("ENTER [4] TO EXIT\n");
    printf("ENTER [5] TO VIEW THE VOTERS\n");
    printf("ENTER [6] TO CAST THE VOTE \n");
    printf("ENTER [7] TO SORT CANDIDATE BY DIVISION FOR CONVINIENCE \n");
    printf("ENTER [8] TO DISPLAY THE CANDIDATES ALONG WITH THEIR CURRENT NUMBER OF VOTES BY YOUR CONVINENIENCE \n");
    printf("ENTER [9] TO DISPLAY THE RESULTS IN ALL DIVISIONS\n");
    printf("ENTER [10] TO DISPLAY THE VOTED VOTERS\n");
    printf("ENTER [11] TO DISPLAY THE RESULTS OF YOUR DIVISION BY YOUR CONVINIENCE\n");
    scanf("%d",&i);
    system("cls");
    while(i>0 && i<12){
        if(i==1){
            search(can);
        }
        else if(i==2){
            check(can);
        }
        else if(i==3){
            vote(vot);
        }
        else if(i==4){
        	printf("\n                                  ****** GOOD BYE *******                                            ");
        	exit(0);
            break;
        }
        else if(i==5){
            viewvoter(vot);
            break;
        }
        else if(i==6){
            votecasting(&a,&b,&c,&d,&w,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&q,vot,can);

        }
        else if(i==7){
            sortbydivision();
        }
        else if(i==8){
            viewcanvote(can,&t1,&t2,&t3,&t4);
        }
        else if(i==9){
            viewcanvote2(can);
        }

        else if(i==10){
            view2reg(vot);

        }
        else if(i==11){
            viewbydiv(can);
        }

        else{
            break;
        }
    }
    }
     printf("\nIf you want to continue, Enter 0\nIf you want to quit, Enter 4\n\n\tEnter your option: ");
    scanf("%d",&cont);
    if(cont==0)
    {
    	system("cls");
	}
	if(cont==4)
    {
    	printf("\n                                  ****** GOOD BYE *******                                            ");
    	exit(0);
	}
    }
