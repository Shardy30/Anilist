#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
int LoadBasics();
int FirstScreen();
int SecScreen();
int SecScreen2();
int ThirdScreen1();
int ThirdScreen2();
int Login();
int Signup();
char* searchconvert();
int search();
char** SplitRecomm();
int CheckRecomm();
int Recommendation();
char* makeuidstring();
char* getname();
int fulldiscuss();
int CreateHotTopic();
int Discussion();
int printcurrentdetails(char,int,int);
int getanimename(char*);
int PostRating(int,char*);
int modanime(int,char);
int addanime(char);
int anilist(char);
int AnimeLists();
int Myprofile();
int Rememberme();
int ChangeBasics();
int call1();
int call2();
int loginflag=0;
int keepme;
int totalusers;
int totaltopics;
int scoreofanime;
int episodesofanime;
int curruid=0;
int runs=0;
int payreq=0;
char typeofanime;
char currname[30];
char name[30];
char animename[76];
char anicomment[1000];
char idstring[6]="";
char idstring2[6]="";

struct login
{                           
  char username[31];
  char password[21];
  int uid;
};

int FirstScreen()
{
    printf("\n\nPlease Maximize the Wnidow to the Fullscreen View and Enter any key to Start Anilist");
    getch();
    system("CLS");
    printf("******************************************************************************************************************************************************************************************************************\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t************************************************************************************************");
    printf("\n\t\t\t\t\t\t\t*       ####          ###     ##    ########    ##           ########       #####    ########  *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t*      ##  ##         ####    ##       ##       ##              ##         ##           ##     *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t*     ##    ##        ## ##   ##       ##       ##              ##         ##           ##     *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t*    ##      ##       ##  ##  ##       ##       ##              ##           ##         ##     *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t*   ############      ##   ## ##       ##       ##              ##             ##       ##     *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t*  ##          ##     ##    ####       ##       ##              ##             ##       ##     *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t* ##            ##    ##     ###    ########    #########    ########      #####        ##     *");Sleep(50);
    printf("\n\t\t\t\t\t\t\t************************************************************************************************");Sleep(50);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tYour own Animeground ");Sleep(50);
    printf("\n\n\n\t\t\t\t\t\t\t\tTo Select an Option in this Application, Please Enter the number or Letter preceding it\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n******************************************************************************************************************************************************************************************************************");Sleep(4000);
    return 0;
}

int SecScreen()
{
    loginflag=0;
    int choice=0;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tWelcome User, Please Select One of the Following Options to continue:\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\t\t\t1. Existing User Login");
    printf("\n\n\n\t\t\t\t\t\t\t2. New User Sign Up");
    printf("\n\n\n\t\t\t\t\t\t\t3. Continue as Guest\n\n");
    printf("\n\n\t\t\t\t\t\t\tPlease Enter Your Choice: ");

    while(choice!=1 && choice!=2 && choice!=3)
    {
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1: 
            {
                system("CLS");
                curruid = Login();
                if(curruid!=0)
                {
                    loginflag=1;
                }
                break;
            }

            case 2: 
            {
                system("CLS");
                curruid = Signup();
                if(curruid!=0)
                {
                    loginflag=1;
                }
                break;
            }

            case 3: 
            {
                break;
            }

            default: 
            {
                MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\t\tPlease Enter a Valid Choice: ");
                break;
            }
        }
    }
    return 0;
}

int SecScreen2()
{
    
    int choice = 1;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t Welcome Back to Anilist, %s",currname);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t             Enter any key to Continue");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t  Not %s? Enter 0 to Log Out and Change User",currname);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t                   Your Response: ");
    scanf("%d",&choice);
    fflush(stdin);
    if(choice == 0)
    {
        curruid=0;
        strcpy(currname,"");
        keepme=0;
        return 0;
    }
    return 1;

}

int ThirdScreen1()
{
    int choice = -1;
    int logouting=1;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tWelcome %s, What would You Like to do Today?\n\n\n",currname);
    printf("\n\n\n\t\t\t\t\t\t1. Search Various Things Related to Anime Through the Internet (Top Animes, Wallpapers, Music, Videos, Merchandise and Much More)");
    printf("\n\n\n\t\t\t\t\t\t2. Get Anime Recommendations based on the Genre(s) You Select");
    printf("\n\n\n\t\t\t\t\t\t3. View and Participate in Current Hot Topics and Discussions");
    printf("\n\n\n\t\t\t\t\t\t4. Manage Your AnimeLists");
    printf("\n\n\n\t\t\t\t\t\t5. Manage Your Profile ");
    printf("\n\n\n\t\t\t\t\t\t0. Exit Anilist");
    printf("\n\n\n\n\t\t\t\t\t\tPlease Enter Your Choice: ");
    while(choice<1 || choice>5)
    {
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
            {
                system("CLS");
                while(search())
                {
                    system("CLS");
                }
                break;
            }
            case 2:
            {
                system("CLS");
                Recommendation();
                break;
            }
            case 3:
            {
                system("CLS");
                while(Discussion(10)==1)
                {
                    system("CLS");
                }
                break;
            }
            case 4:
            {
                system("CLS");
                while(AnimeLists())
                {
                    system("CLS");
                }
                break;
            }
            case 5:
            {
                system("CLS");
                while(1)
                {
                    logouting = Myprofile();
                    if(logouting==1)
                    {
                        system("CLS");
                    }
                    else if(logouting==2)
                    {
                        return 2;
                        break;
                    }
                    else
                    {
                        return 1;
                        break;
                    }
                }
                break;
            }
            case 0:
            {
                return 0;
                break;
            }
            default:
            {
                MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\tPlease Enter a Valid Choice: ");
                break;
            }

        }
    }
     return 1;
}

int ThirdScreen2()
{
    int choice =-1;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tWelcome User, What would You Like to do Today?\n\n\n");
    printf("\n\n\n\t\t\t\t\t\t1. Search Various Things Related to Anime Through the Internet (Top Animes, Wallpapers, Music, Videos, Merchandise and Much More)");
    printf("\n\n\n\t\t\t\t\t\t2. Get Anime Recommendations based on the Genre(s) You Select");
    printf("\n\n\n\t\t\t\t\t\t3. View the Current Hot Topics and Discussions");
    printf("\n\n\n\t\t\t\t\t\t4. Login / Sign Up (To Create Your Animelists, Rate Animes, Discuss Hot Topics and Much More)");
    printf("\n\n\n\t\t\t\t\t\t0. Exit Anilist");
    printf("\n\n\n\n\t\t\t\t\t\tPlease Enter Your Choice: ");
    while(choice<1 || choice>5)
    {
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
            {
                system("CLS");
                while(search())
                {
                    system("CLS");
                }
                break;
            }
            case 2:
            {
                system("CLS");
                Recommendation();
                break;
            }
            case 3:
            {
                system("CLS");
                while(Discussion(10)==1)
                {
                    system("CLS");
                }
                break;
            }
            case 4:
            {
                system("CLS");
                SecScreen();
                break;
            }
            case 0:
            {
                return 0;
                break;
            }
            default:
            {
                MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\tPlease Enter a Valid Choice: ");
                break;
            }
        }
    }
    return 1;
}

int Login()
{ 
    int choice;
    char username[30],password[20];
    int passcheck=0;
    FILE *fp;
    fp = fopen("Users.txt","r");

    struct login l;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Existing User Login");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t       Please Enter your Login Credentials Below :\n\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tUsername: ");
    scanf("%s",username);
    for (int j = 0; j < strlen(username); ++j) 
    {
        username[j]=tolower((unsigned char) username[j]);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPassword: ");
    scanf("%s",password);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tVerifying Details");Sleep(200);
    printf(".");Sleep(200);
    printf(".");Sleep(200);
    printf(".");Sleep(200);
    if(strcmp(username,"user")==0)
    {
        MessageBox(NULL, "Sorry, No such User ID Exists.", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
        fclose(fp);
        return 0;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d",l.username,l.password,&l.uid);
        fflush(stdin);
        if(strcmp(username,l.username)==0)
        {
            passcheck++;
            if(strcmp(password,l.password)==0)
            {
                MessageBox(NULL, "You have Successfully Logged In", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                fclose(fp);
                return l.uid;
            }
            break;
        }
    }
    fclose(fp);
    if(passcheck==0)
    {
        MessageBox(NULL, "Sorry, No such User ID exists.", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
    }
    else
    {
        MessageBox(NULL, "Sorry, The Password did not Match", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
    }
    return 0;
}

int Signup()
{
    FILE *fp;
    struct login l,new;
    new.uid=0;
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t                    New User Sign Up");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t         Please Select your Credentials Below :\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t\tEnter Username (4-30 characters and without space): ");
    for(int i=0;i==0;)
    {
        scanf("%s",new.username);
        fflush(stdin);
        i=1;
        if((strcmp(new.username,"user")==0)||(strlen(new.username)<4))
        {
            MessageBox(NULL, "Sorry, This Username is not Valid \n\nPlease try a Different Username", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONERROR));
            i=0;
            printf("\n\n\t\t\t\t\t\t\t\t\t\tTry a Different Username: ");
        }
        for(int j=0;((j<totalusers)&&(i==1));j++)
        {
            fp=fopen("Users.txt","r");
            fscanf(fp,"%s %s %d",l.username,l.password,&l.uid);
            fflush(stdin);
            if(strcmp(new.username,l.username)==0)
            {
                MessageBox(NULL, "Sorry, This Username Already Exists \n\nPlease try a Different Username", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                i=0;
                printf("\n\n\t\t\t\t\t\t\t\t\t\tTry a Different Username: ");
                fclose(fp);
                break;
            }
        }
    }    
    FILE *fpw;
    fpw=fopen("Users.txt","a");
    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter Password (max. 20 characters): ");
    scanf("%s",new.password);
    new.uid=++totalusers;
    fprintf(fpw,"\n%s %s %d",new.username, new.password,new.uid);
    fclose(fpw);
    char filename[10]="";
    strcpy(idstring2,"");
    strcpy(filename,makeuidstring(new.uid));
    strcat(filename,".txt");
    fpw=fopen(filename,"w");
    fprintf(fpw,"%s",new.username);
    fclose(fpw);
    ChangeBasics();
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tCreating Your ID");Sleep(300);
    printf(".");Sleep(300);
    printf(".");Sleep(300);
    printf(".");Sleep(300);
    MessageBox(NULL, "Congrats! User ID Successfully Created." , "Anilist",( MB_OK | MB_TOPMOST| MB_ICONASTERISK));
    return new.uid;
}

char parturl[200];

char* searchconvert(char* search, char* spacecode)
{
    for(int i=0, j=0; search[j]!='\0';i++,j++)
    {
        if(search[j]==' ')
        {
            for(int l=0; spacecode[l]!='\0';l++,i++)
            {
                parturl[i]=spacecode[l];
            }
            i--;
        }
        else
        {
            parturl[i]=search[j];
        }
    }
    return parturl;
}

int search()
{
    int choice=-1;
    char search[100];
    char *searchurl;
    char *spacecode;
    char message[500];
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tPlease Select What You Want to do:\n\n\n");
    printf("\n\n\t\t\t\t1. Search an Anime by Name");
    printf("\n\n\t\t\t\t2. View 100 Top Rated Animes of All Time");
    printf("\n\n\t\t\t\t3. View Top Airing Animes");
    printf("\n\n\t\t\t\t4. View Upcoming Animes");
    printf("\n\n\t\t\t\t5. Search and Get Wallpapers of an Anime or Character");
    printf("\n\n\t\t\t\t6. Search and Watch/Listen Anime Music Videos (AMVs) and Original Sound Tracks (OSTs) from Anime");
    printf("\n\n\t\t\t\t7. Search and Listen Anime Musics and Tracks (Exact Titles only)");
    printf("\n\n\t\t\t\t8. Search Fanarts and Designs of an Anime or Character");
    printf("\n\n\t\t\t\t9. Search Merchandise related to an Anime or Characters");
    printf("\n\n\t\t\t\t0. Return to the previous Menu");
    printf("\n\n\n\t\t\t\tPlease Enter Your Choice: ");

    while(choice<1 || choice>9)
    {
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
            {
                printf("\n\n\n\t\t\t\tEnter The Name of The Anime You Want to Search: ");
                fgets(search,100,stdin);
                spacecode="%20";
                searchurl = searchconvert(search,spacecode);
                char fullurl[500];
                sprintf(message,"Get the Details of the Desired Season of %s here.\n\nIf You Wish, You can return to the Anicrypt Application",search);
                strcpy(fullurl,"START https://anilist.co/search/anime?search=");
                strcat(fullurl,searchurl);
                system(fullurl);
                MessageBox(NULL, message , "Anicrypt",MB_OK | MB_TOPMOST | MB_ICONASTERISK);
                break;
            }
            case 2:
            {
                system("START https://anilist.co/search/anime/top-100");
                MessageBox(NULL, "Find the Details the Top-100 Animes here.\n\nIf You Wish, You can return to the Anicrypt Application", "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 3:
            {
                system("START https://anilist.co/search/anime?airing%20status=RELEASING");
                MessageBox(NULL, "Find the Details the Top Airing Animes here.\n\nIf You Wish, You can return to the Anicrypt Application", "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 4:
            {
                system("START https://myanimelist.net/topanime.php?type=upcoming");
                MessageBox(NULL, "Find the Details the Top Upcoming Animes here.\n\nIf You Wish, You can return to the Anicrypt Application", "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 5:
            {
                printf("\n\n\n\t\t\t\tEnter The Name of The Anime or Character Whose Wallpapers You Want to Search: ");
                fgets(search,100,stdin);
                spacecode="+";
                searchurl = searchconvert(search,spacecode);
                char fullurl[500];
                sprintf(message,"Get the Wallpapers of %s here.\n\nIf You Wish, You can return to the Anicrypt Application",search);
                strcpy(fullurl,"START https://www.wallpaperflare.com/search?wallpaper=");
                strcat(fullurl,searchurl);
                system(fullurl);
                MessageBox(NULL, message, "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 6:
            {
                printf("\n\n\n\t\t\t\tWrite the Name of AMV/OST You Want to Watch: ");
                fgets(search,100,stdin);
                spacecode="+";
                searchurl = searchconvert(search,spacecode);
                char fullurl[500];
                sprintf(message,"Play the AMV/OST related to %s here.\n\nIf You Wish, You can return to the Anicrypt Application",search);
                strcpy(fullurl,"START https://www.youtube.com/results?search_query=");
                strcat(fullurl,searchurl);
                system(fullurl);
                MessageBox(NULL, message, "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 7:
            {
                printf("\n\n\n\t\t\t\tEnter the Exact Name of Anime Track/Music You Want to Listen: ");
                fgets(search,100,stdin);
                spacecode="%20";
                searchurl = searchconvert(search,spacecode);
                char fullurl[500];
                sprintf(message,"Stream the Tracks/Music related to %s here.\n\nIf You Wish, You can return to the Anicrypt Application",search);
                strcpy(fullurl,"START https://soundcloud.com/search?q=");
                strcat(fullurl,searchurl);
                system(fullurl);
                MessageBox(NULL, message, "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 8:
            {
                printf("\n\n\n\t\t\t\tEnter The Name of The Anime or Character Whose Fanart or Designs You Want to Search: ");
                fgets(search,100,stdin);
                spacecode="%20";
                searchurl = searchconvert(search,spacecode);
                char fullurl[500];
                sprintf(message,"Get the Fanarts and Designs related to %s here.\n\nIf You Wish, You can return to the Anicrypt Application",search);
                strcpy(fullurl,"START https://www.pinterest.com/search/pins/?q=");
                strcat(fullurl,searchurl);
                system(fullurl);
                MessageBox(NULL, message, "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 9:
            {
                printf("\n\n\n\t\t\t\tEnter The Name of The Anime or Character with/or the Type of Merchandise You Want to Search: ");
                fgets(search,100,stdin);
                spacecode="+";
                searchurl = searchconvert(search,spacecode);
                char fullurl[500];
                sprintf(message,"Buy the Merchandise of %s from here.\n\nIf You Wish, You can return to the Anicrypt Application",search);
                strcpy(fullurl,"START https://shop.otakuhouse.com/pages/search-results-page?q=");
                strcat(fullurl,searchurl);
                system(fullurl);
                MessageBox(NULL, message, "Anicrypt",( MB_OK | MB_TOPMOST | MB_ICONASTERISK));
                break;
            }
            case 0:
            {
                return 0;
                break;
            }
            default:
            {
                MessageBox(NULL, "Please Enter A Valid Choice", "Anicrypt",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\tPlease Enter a Valid Choice: ");
                break;
            }
        }
    }
    return 1;
}

char** SplitRecomm(char* string, char* delim)
{
    char **splitted=malloc(100 * sizeof (char*));
    for(int i=0;i<100;i++)
    {
        splitted[i]=malloc(20*sizeof(char*));
    }
    char str[100];
    strcpy(str,string);
    char *token = strtok(str, delim);
    for(int i=0;(token != NULL);i++)
    {
        splitted[i]=token;
        token = strtok(NULL, delim);
    }
    return splitted;
}

int CheckRecomm(char *inputted)
{
    int val;
    char *input=inputted;
    for(int i=0; input[i]!= '\0' ;i++)
    {
        val=((int)(input[i]))-97;
        if(((val>=0)&&(val<=14))||(val==-53))
        continue;
        else
        return 0;
    }
    return 1;
}

int Recommendation()
{
    char message[500];
    char search[100];
    char searchurl[500];
    char **selgenre=malloc(100 * sizeof (char*));
    for(int i=0;i<100;i++)
    {
        selgenre[i]=malloc(20*sizeof(char*));
    }
    int flag=0;
    int index=0;
    char genres[15][20]={
                         "Action",
                         "Adventure",
                         "Comedy",
                         "Drama",
                         "Fantasy",
                         "Horror",
                         "Mech",
                         "Music",
                         "Mystery",
                         "Psychological",
                         "Romance",
                         "Sci-fi",
                         "Sports",
                         "Supernatural",
                         "Thriller"
                        };
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSelect the Genre(s) of the Anime You Want to Search for Recommendations:");
    printf("\n\n\n\n\n\t\t\t\t\t\t\ta. Action\t\tb. Adventure\t\tc. Comedy\t\td. Drama\t\te. Fantasy\n\n\n\t\t\t\t\t\t\tf. Horror\t\tg. Mecha\t\th. Music\t\ti. Mystery\t\tj. Psychological\n\n\n\t\t\t\t\t\t\tk. Romance\t\tl. Sci-Fi\t\tm. Sports\t\tn. Supernatural\t\to. Thriller");
    printf("\n\n\n\n\t\t\t\t\t\t\tFor Example, To get Recommendations of Animes that have Action,Fantasy and Thriller as their genres, input a,e,o");
    printf("\n\n\n\n\t\t\t\t\t\t\tTo Return to the Previous Menu, Enter 0");
    printf("\n\n\n\n\t\t\t\t\t\t\tEnter Your Choice(s) : ");
    while(flag==0)
    {
        scanf("%s",search);
        fflush(stdin);
        if((search[0]=='0')&&(search[1]=='\0'))
        {
            return 0;
        }
        selgenre = SplitRecomm(search, ",");
        flag = CheckRecomm(search);
        if(flag==0)
        {
            MessageBox(NULL, "Please Enter A Valid Response", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
            printf("\n\n\t\t\t\t\t\tPlease Enter a Valid Response: ");
        }
        else
        {
            strcpy(searchurl,"START https://anilist.co/search/anime?genres=");
            index=((int)(selgenre[0][0])-97);
            strcat(searchurl,genres[index]);
            if(search[1]=='\0')
            {
                strcpy(message,"These are the Anime Recommendations from the genre ");
                strcat(message,genres[index]);
            }
            else
            {
                strcpy(message,"These are the Anime Recommendations of the genres ");
                strcat(message,genres[index]);
            }
            for(int i=1; selgenre[i][0]!='\0';i++)
            {
                index=(int)selgenre[i][0]-97;
                strcat(searchurl,"^&genres=");
                strcat(searchurl,genres[index]);
                strcat(message,", ");
                strcat(message,genres[index]);
            }
            if(loginflag==1)
            {
                strcat(message,"\n\nIf You Wish, You can return to the Anilist Application");
            }
            else
            {
                strcat(message,"\n\nIf You Wish, You can return to the Anilist Application");
            }
            system(searchurl);
            MessageBox(NULL, message , "Anilist",MB_OK | MB_TOPMOST);
        }
    }
    return 0;
}

char* makeuidstring(int uid)
{
    char testid[6];
    itoa(uid,testid,10);
    int len = strlen(testid);
    for(;len<5;len++)
    {
        strcat(idstring2,"0");
    }
    strcat(idstring2,testid);
    return idstring2;
}

char* getname(char *i)
{
    FILE *fp;
    char filename[10]="";
    strcpy(name,"");
    strncpy(filename,i,5);
    strcat(filename,".txt");
    fp = fopen(filename,"r");
    fscanf(fp,"%s",name);
    fclose(fp);
    return name;
}

int fulldiscuss(int n, int show)
{
    int count=0;
    char c;
    char topic[20000]="";
    int len, commsindex, checkid=0,commscheck=0,checkeof=0;
    char ids[6]="";
    FILE *fp1;
    fp1= fopen("disc.txt","r");
    while(count!=(n-1))
    {
        c=getc(fp1);
        if(c=='\n')
        {
            count++;
        }
    }
    c=getc(fp1);
    while((c!='\n')&&(c!=EOF))
    {
        strncat(topic,&c,1);
        c=getc(fp1);
    }
    c=getc(fp1);
    if(feof(fp1))
    {
        checkeof++;
    }
    len=strlen(topic);
    fclose(fp1);
    count = 0;
    for(int j=0;((j<=(len))&&(count<=((show*2)+3)));j++)
    {
        if((topic[j]==',')&&(topic[j+1]=='#')&&(topic[j+2]=='%'))
        {
            count++;
            j+=3;
            if(((count==6)&&(topic[0]=='1'))||((count==4)&&(topic[0]=='2')))
            {
                commsindex=j-1;
                commscheck=1;
            }
        }
        if((((count==5)&&(topic[0]=='1'))||((count==3)&&(topic[0]=='2')))&&(topic[j]=='\0'))
        {
            commsindex=j;
        }
        if((count>3)&&(count%2==0)&&(count<=((show*2)+3)))
        {
            strncat(ids,&topic[j],1);
            checkid=0;
        }
        if((count>3)&&(count%2==1))
        {
            if(checkid==0)
            {
                strcpy(idstring2,"");
                printf("\n\n\t\t\t\t%s: ",getname(ids));
                checkid++;
                strcpy(ids,"");
            }
            printf("%c",topic[j]);
        }
    }
    int choice =-1;
    if(loginflag==1)
    {
        printf("\n\n\n");
        if(count==((show*2)+4))
        {
            printf("\t\t\t\t1. View More Comments\t\t\t\t\t\t\t");
        }
        else
        {
            printf("\t\t\t\t1. Refresh\t\t\t\t\t\t\t");
        }
        printf("\t\t\t\t2. Add Comment");
        printf("\n\n\t\t\t\t0. Return to the Previous Menu");
        printf("\n\n\t\t\t\t   Enter Your Choice: ");
        while(choice!=1 && choice!=2 && choice!=0)
        {
            scanf("%d",&choice);
            fflush(stdin);
            switch(choice)
            {
                case 1: 
                {
                    show+=10;
                    system("CLS");
                    return show;
                    break;
                }
                case 2:
                {
                    if((n==1)&&(commscheck==0))
                    {
                        commsindex--;
                    }
                    char comment[2000];
                    printf("\n\n\t\t\t\t   Enter Your Comment: ");
                    fgets(comment,2000,stdin);
                    comment[strlen(comment)-1]='\0';
                    if(strlen(comment)>0)
                    {
                        FILE *fp2;
                        fp2 = fopen("newdisc.txt","w");
                        fp1 = fopen("disc.txt","r");
                        count =0;
                        c=fgetc(fp1);
                        while(count<(n-1))
                        {
                            fputc(c,fp2);
                            c=fgetc(fp1);
                            if(c=='\n')
                            {
                                count++;
                            }
                        }
                        fputc(c,fp2);
                        count =0;
                        for(int j=0;j<commsindex;j++)
                        {
                            c=fgetc(fp1);
                            fputc(c,fp2);
                        }
                        strcpy(idstring2,"");
                        if((commscheck==1)&&(n!=1))
                        {
                            fprintf(fp2,"%%%s,#%%",makeuidstring(curruid));
                            fprintf(fp2,"%s,#",comment);
                        }
                        else if((commscheck==1)&&(n==1))
                        {
                            fprintf(fp2,"%s,#%%",makeuidstring(curruid));
                            fprintf(fp2,"%s,#%%",comment);
                        }
                        else
                        {
                            if(checkeof==1)
                            {
                                fprintf(fp2,",#%%%s,#%%",makeuidstring(curruid));
                                fprintf(fp2,"%s",comment);
                                fprintf(fp2,"\n");
                            }
                            else
                            {
                                fprintf(fp2,",#%%%s,#%%",makeuidstring(curruid));
                                fprintf(fp2,"%s",comment);
                            }
                        }
                        c=fgetc(fp1);
                        while(c!=EOF)
                        {
                            fputc(c,fp2);
                            c=fgetc(fp1);
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("disc.txt");
                        rename("newdisc.txt","disc.txt");
                        MessageBox(NULL, "You Commented on This Topic", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                    }
                    else
                    {
                        MessageBox(NULL, "Your Comment wasn't Valid", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONERROR));
                    }
                    if((n==1)&&(commscheck==0))
                    {
                        commsindex++;
                    }
                    break;
                }
                case 0:
                {
                    return 0;
                    break;
                }
                default:
                {
                    MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                    printf("\n\n\t\t\t\tPlease Enter a Valid Choice: ");
                    break;
                }
            }
        }
    }
    else
    {
        printf("\n\n\n");
        if(count==((show*2)+4))
        {
            printf("\t\t\t\t1. View More Comments\t\t\t");
        }
        else
        {
            printf("\t\t\t\t1. Refresh\t\t\t");
        }
        printf("\n\n\t\t\t\t0. Return to the Previous Menu");
        printf("\n\n\n\t\t\t\t   Enter Your Choice: ");
        while(choice!=1 && choice!=0)
        {
            scanf("%d",&choice);
            fflush(stdin);
            switch(choice)
            {
                case 1: 
                {
                    show+=10;
                    system("CLS");
                    return show;
                    break;
                }
                case 0:
                {
                    return 0;
                    break;
                }
                default:
                {
                    MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                    printf("\n\n\t\t\t\tPlease Enter a Valid Choice: ");
                    break;
                }
            }
        }
    }
    return 1;
}

int CreateHotTopic()
{
    char head[101];
    char mess[2001];
    char date[26];
    char c;
    FILE *fp1;
    fp1 = fopen("newdisc.txt","w");
    time_t now;
    time(&now);
    sprintf(date,"%s",ctime(&now));
    date[24]='\0';
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    Starting a New Hot Topic");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t Enter its Heading and Details:");    
    printf("\n\n\n\t\t\t\t\t\tType a Heading (max. 100 characters): ");
    fgets(head,100,stdin);
    head[strlen(head)-1]='\0';
    if(strlen(head)>0)
    {
        printf("\n\n\n\t\t\t\t\t\tType about this Topic: ");
        fgets(mess,20000,stdin);
        mess[strlen(mess)-1]='\0';
        fprintf(fp1,"1,#%%");
        strcpy(idstring2,"");
        fprintf(fp1,"%s,#%%",makeuidstring(curruid));
        fprintf(fp1,"%s,#%%",date);
        fprintf(fp1,"%s,#%%",head);
        fprintf(fp1,"%s,#%%",idstring2);
        if(strlen(mess)>0)
        {
            fprintf(fp1,"%s",mess);
        }
        else
        {
            fprintf(fp1,"What are Your Views on my Topic");
        }
        fprintf(fp1,"\n");
        fclose(fp1);
        FILE *fp2;
        fp1 = fopen("newdisc.txt","a");
        fp2 = fopen("disc.txt","r");
        c=fgetc(fp2);
        while(c!=EOF)
        {
            fputc(c,fp1);
            c=fgetc(fp2);
        }
        fclose(fp1);
        fclose(fp2);
        remove("disc.txt");
        rename("newdisc.txt","disc.txt");
        char message[127]="";
        sprintf(message,"You Started A new Topic: %s",head);
        MessageBox(NULL, message, "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
        totaltopics++;
        ChangeBasics();
    }
    else
    {
         MessageBox(NULL, "Your Topic Heading wasn't Valid", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONERROR));
    }
    return 0;
}

int Discussion(int totalshow)
{
    int choice = 0;
    FILE *fp;
    fp = fopen("disc.txt", "r");
    char heading[500][143];
    char temp[143];
    char name[30];
    char filename[10];
    int count=0;
    int exit=1;
    int type=0;
    int i;
    int show =5;
    for(i=0;!feof(fp);i++)
    {
        fgets(heading[i],2000*sizeof(char),fp);
        strncpy(temp,heading[i],142);
        strcpy(heading[i],"");
        for(int j=0;j<141;j++)
            {
                if((temp[j]==',')&&(temp[j+1]=='#')&&(temp[j+2]=='%'))     
                {
                    count++;
                }
                if(count==4)
                {
                    break;
                }
                strncat(heading[i],&temp[j],1);   
            }
        count=0;
    }
    fclose(fp);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tCurrent Hot Topics\n\n\n");
    for(i=0;(((i<(totaltopics))&&(i<(totalshow-1))||((totaltopics==totalshow)&&(i<totaltopics))));i++)
    {
        type = strtol(strdup(heading[i]),NULL,10);
        strcpy(idstring,"");
        for(int j=4;j<9;j++)
        {
            strncat(idstring,&heading[i][j],1);
        }
        printf("\n\n\t\t\t\t%d. %s, on ",(i+1),getname(idstring));
        for(int j=12;j<36;j++)
        {
            printf("%c",heading[i][j]);
        }
        if(type==1)
        {
            printf(", Started the Hot Topic: ");
        }
        else
        {
            printf(" :");
        }
        printf("\n\t\t\t\t   %s",(&heading[i][39]));
    }
    if(totaltopics>totalshow)
    printf("\n\n\t\t\t\t%d. View more Topics...",totalshow);
    if(totaltopics==0)
    {
        printf("\n\n\n\t\t\t\t\tCurrently there are no Hot Topic Discussions.\n\n");
        if(loginflag==1)
        {
            printf("\n\n\t\t\t\t\tTo Start Your own Hot Topic, Enter 1000\n\n");
        }
    }
    else
    {
        if(loginflag == 1)
        {
        printf("\n\n\n\t\t\t\t\tTo View a full Discussion or Participate in it, Enter the number preceding it.");
        printf("\n\n\t\t\t\t\tTo Start Your own Hot Topic, Enter 1000");
        }
        else
        {
            printf("\n\n\n\t\t\t\t\tTo View a full Discussion of the Hot Topic, Enter the number preceding it.");
            printf("\n\n\t\t\t\t\tTo Start Your own Hot Topic or Participate in one, Login or Register.");
        }
    }
    printf("\n\n\t\t\t\t\tTo Return to the Previous Menu, Enter 0");
    printf("\n\n\t\t\t\t\tPlease Enter Your Choice: ");
    i=0;
    while(i==0)
    {
        scanf("%d",&choice);
        fflush(stdin);
        if((choice>=1)&&(choice<=(totalshow-1))&&(choice<=totaltopics))
        {
            i++;
            do
            {
                system("CLS");
                strcpy(idstring,"");
                for(int j=4;j<9;j++)
                {
                    strncat(idstring,&heading[choice-1][j],1);
                }
                printf("\n\n\t\t\t\tTopic by: %s",getname(idstring));
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDated: ");
                for(int j=12;j<36;j++)
                {
                    printf("%c",heading[choice-1][j]);
                }
                printf("\n\n\t\t\t\t%s",(&heading[choice-1][39]));
                printf("\n\n\n\t\t\t\tDiscussion: ");
                if(show==1)
                {
                    show = 5;
                }
            }while((show=fulldiscuss(choice,show))!=0);
        }
        else if((loginflag==1)&&(choice==1000))
        {
            i++;
            system("CLS");
            CreateHotTopic();
        }
        else if(choice ==totalshow)
        {
            if(totaltopics==totalshow)
            {
                i++;
                do
                {
                    system("CLS");
                    strcpy(idstring,"");
                    for(int j=4;j<9;j++)
                    {
                        strncat(idstring,&heading[choice-1][j],1);
                    }
                    printf("\n\n\t\t\t\tTopic by: %s",getname(idstring));
                    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDated: ");
                    for(int j=12;j<36;j++)
                    {
                        printf("%c",heading[choice-1][j]);
                    }
                    printf("\n\n\t\t\t\t%s",(&heading[choice-1][39]));
                    printf("\n\n\n\t\t\t\tDiscussion: ");
                }while(fulldiscuss(choice,5)==1);
            }
            else
            {
            i++;
            system("CLS");
            totalshow+=10;
            exit=Discussion(totalshow);
            }
        }
        else if(choice == 0)
        {
            i++;
            return 0;
        }
        else
        {
            MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
            printf("\n\n\t\t\t\t\tPlease Enter a Valid Choice: ");
        }
    }
    if(exit==0)
    {
        return 0;
    }
    return 1;
}

int getanimename(char *str)
{
    int i;
    strcpy(anicomment,"");
    strcpy(animename,"");
    for(i=0;!((str[i]=='$')&&(str[i+1]=='^')&&(str[i+2]=='@'));i++)
    {
        strncat(animename,&str[i],1);
    }
    strcpy(anicomment,&str[i+3]);
    return 0;
}

int PostRating(int score, char *aniname)
{
    char head[101];
    char date[26];
    char c;
    FILE *fp1;
    fp1 = fopen("newdisc.txt","w");
    time_t now;
    time(&now);
    sprintf(date,"%s",ctime(&now));
    date[24]='\0';
    sprintf(head,"Rated %s %d/100",aniname,score);
    head[6]=toupper(head[6]);
    fprintf(fp1,"2,#%%");
    strcpy(idstring2,"");
    fprintf(fp1,"%s,#%%",makeuidstring(curruid));
    fprintf(fp1,"%s,#%%",date);
    fprintf(fp1,"%s",head);
    fprintf(fp1,"\n");
    fclose(fp1);
    FILE *fp2;
    fp1 = fopen("newdisc.txt","a");
    fp2 = fopen("disc.txt","r");
    c=fgetc(fp2);
    while(c!=EOF)
    {
        fputc(c,fp1);
        c=fgetc(fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("disc.txt");
    rename("newdisc.txt","disc.txt");
    sprintf(head,"Your Rating for %s was Posted Publicly",aniname);
    MessageBox(NULL, head, "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
    totaltopics++;
    return 0;
}

int modanime(int sno, char type)
{
    FILE *fp;
    char typecheck,c;
    char filename[10]="";
    int counter=0;
    int episodes, score;
    char str[1079]="";
    strcpy(idstring2,"");
    strcpy(filename,"");
    strncpy(filename,makeuidstring(curruid),5);
    strcat(filename,".txt");
    fp = fopen(filename,"r");
    fscanf(fp,"%s",str);
    c=fgetc(fp);
    c=fgetc(fp);
    while(c!=EOF)
    {
        if((c==type)||(type=='0'))
        {
            counter++;
        }
        if(counter==sno)
        {
            typecheck=c;
            fscanf(fp,"%d %d ",&score,&episodes);
            strcpy(str,"");
            while((c!='\n')&&(c!=EOF))
            {
                c=fgetc(fp);
                strncat(str,&c,1);
            }
            str[strlen(str)-1]='\0';
            getanimename(str);
            break;
        }
        else
        {
            while((c!='\n')&&(c!=EOF))
            {
                c=fgetc(fp);
            }
            c=fgetc(fp);
        }
    }
    fclose(fp);
    printcurrentdetails(typecheck,episodes,score);
    if(runs!=0)
    {
        FILE *fp1;
        FILE *fp2;
        strcpy(idstring2,"");
        strcpy(filename,"");
        strncpy(filename,makeuidstring(curruid),5);
        strcat(filename,".txt");
        filename[10]='\0';
        strcpy(str,"");
        fp1 = fopen(filename,"r");
        fp2 = fopen("templist.txt","w");
        fscanf(fp1,"%s",str);
        fprintf(fp2,"%s",str);
        strcpy(str,"");
        strcpy(str,animename);
        strcat(str,"$^@");
        strcat(str,anicomment);
        c=fgetc(fp1);
        fputc(c,fp2);
        c=fgetc(fp1);
        counter=0;
        while(c!=EOF)
        {
            if((c==type)||(type=='0'))
            {
                counter++;
            }
            if(counter==sno)
            {
                fprintf(fp2,"%c %d %d %s",typeofanime,scoreofanime,episodesofanime,str);
                while((c!='\n')&&(c!=EOF))
                {
                    c=fgetc(fp1);
                }
                if(c!=EOF)
                {
                    fputc(c,fp2);
                }
                c=fgetc(fp1);
                while(c!=EOF)
                {
                    fputc(c,fp2);
                    c=fgetc(fp1);
                }
                break;
            }
            else
            {
                while(c!='\n')
                {
                    fputc(c,fp2);
                    c=fgetc(fp1);
                }
                fputc(c,fp2);
                c=fgetc(fp);
            }
        }
        fclose(fp1);
        fclose(fp2);
        strcpy(idstring2,"");
        strcpy(filename,"");
        strncpy(filename,makeuidstring(curruid),5);
        strcat(filename,".txt");
        filename[10]='\0';
        remove(filename);
        rename("templist.txt",filename);
    }
    runs=0;
    return 0;
}

int printcurrentdetails(char typecheck, int episodes, int score)
{
    system("CLS");
    typeofanime=typecheck;
    episodesofanime=episodes;
    scoreofanime=score;
    char scorestr[8]="";
    char status[20]="";
    int choice=0,choice2=0,choice3=0,i=0;
    char term;
    char newanimename[76];
    char newanimecomment[1000];
    strcpy(scorestr,"");
    if(score!=0)
    {
        itoa(score,scorestr,10);
        strcat(scorestr,"/100");
    }
    else
    {
        strcpy(scorestr,"--");
    }
    if(typecheck=='1')
    {
        strcpy(status,"Unwatched");
    }
    else if(typecheck=='2')
    {
        strcpy(status,"Currently Watching");
    }
    else
    {
        strcpy(status,"Watched");
    }
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tAnime Details");
    printf("\n\n\n\n\t\t\t\t\t\tAnime Name : %s",animename);
    printf("\n\n\t\t\t\t\t\tStatus : %s",status);
    if(typecheck!='1')
    {
        printf("\n\n\t\t\t\t\t\tEpisodes Watched : %d",episodes);
        printf("\n\n\t\t\t\t\t\tScore : %s",scorestr);
    }
    if(strcmp(anicomment,"")==0)
    {
        printf("\n\n\t\t\t\t\t\tPersonal Note : <none>");
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tPersonal Note : %s",anicomment);
    }
    printf("\n\n\n\t\t\t\t\t\t1. Edit Anime Name.\n\n\t\t\t\t\t\t2. Change Anime Status.");
    if(strcmp(anicomment,"")==0)
    {
        printf("\n\n\t\t\t\t\t\t3. Add Personal Note.");
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t3. Edit Personal Note.");
    }
    if(typecheck!='1')
    {
        printf("\n\n\t\t\t\t\t\t4. Update the Number of Episodes Watched.");
        if(score==0)
        {
            printf("\n\n\t\t\t\t\t\t5. Give a Score to This Anime.");
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t5. Change the Score Given.");
        }
    }
    printf("\n\n\t\t\t\t\t\t0. Return to Previous Page.");
    printf("\n\n\n\t\t\t\t\t\t Enter Your Choice : ");
    while(i==0)
    {
        scanf("%d",&choice);
        fflush(stdin);
        i=1;
        if(choice==1)
        {
            strcpy(newanimename,"");
            printf("\n\n\n\t\t\t\t\t\tEnter the New Anime Name : ");
            fgets(newanimename,76,stdin);
            newanimename[strlen(newanimename)-1]='\0';
            strcpy(animename,"");
            strcpy(animename,newanimename);
            runs++;
            MessageBox(NULL, "The Name of Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
            printcurrentdetails(typecheck,episodes,score);
        }
        else if(choice==2)
        {
            if(typecheck=='1')
            {
                printf("\n\n\n\t\t\t\t\t\tEnter the New Status of the Anime :            1. Currently Watching\t\t2. Watched\t\t0. Cancel");
                printf("\n\n\t\t\t\t\t\tEnter the Your Choice : ");
                while(1)
                {
                    scanf("%d",&choice2);
                    fflush(stdin);
                    if(choice2!=1 && choice2!=2 && choice2!=0)
                    {
                        MessageBox(NULL, "Please Enter a Valid Status", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                        printf("\n\n\t\t\t\t\t\tPlease Enter a Valid Status : ");
                    }
                    else if(choice==0)
                    {
                        break;
                    }
                    else
                    {
                        runs++;
                        typecheck=(choice2+1)+'0';
                        MessageBox(NULL, "The Status of the Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                        break;
                    }
                }
            }
            else if(typecheck=='2')
            {
                printf("\n\n\n\t\t\t\t\t\tEnter any key to Change the Status to 'Watched' and 0 to Cancel : ");
                printf("\n\n\t\t\t\t\t\tEnter the Choice : ");
                scanf("%d",&choice2);
                fflush(stdin);
                if(choice2!=0)
                {
                    runs++;
                    typecheck='3';
                    MessageBox(NULL, "The Status of the Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                }
            }
            else
            {
                printf("\n\n\n\t\t\t\t\t\tEnter any key to Change the Status to 'Currently Watching' and 0 to Cancel : ");
                printf("\n\n\t\t\t\t\t\tEnter the Choice : ");
                scanf("%d",&choice2);
                fflush(stdin);
                if(choice2!=0)
                {
                    runs++;
                    typecheck='2';
                    MessageBox(NULL, "The Status of the Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                }
            }
            printcurrentdetails(typecheck,episodes,score);
        }
        else if(choice==3)
        {
            strcpy(newanimecomment,"");
            printf("\n\n\n\t\t\t\t\t\tEnter the New Personal Comment : ");
            fgets(newanimecomment,76,stdin);
            newanimecomment[strlen(newanimecomment)-1]='\0';
            strcpy(anicomment,"");
            strcpy(anicomment,newanimecomment);
            runs++;
            MessageBox(NULL, "The Personal Comment on the Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
            printcurrentdetails(typecheck,episodes,score);
        }
        else if((typecheck!='1')&&(choice==4))
        {
            printf("\n\n\n\t\t\t\t\t\tEnter the New No. of Episodes Watched : ");
            while(1)
            {
                if(scanf("%d%c", &episodes, &term) != 2 || term != '\n')
                {
                    fflush(stdin);
                    MessageBox(NULL, "Please Enter Valid no. of Episodes", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                    printf("\n\n\t\t\t\t\t\tPlease Enter a Valid no. of Episodes: ");
                }
                else
                {
                    fflush(stdin);
                    break;
                }    
            }
            runs++;
            MessageBox(NULL, "The No. of Episodes Watched of the Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
            printcurrentdetails(typecheck,episodes,score);
        }
        else if((typecheck!='1')&&(choice==5))
        {
            printf("\n\n\n\t\t\t\t\t\tEnter the Score (out of 100) You want to Give to this Anime : ");
            while(1)
            {
                scanf("%d", &score);
                fflush(stdin);
                if( score>=0 && score<=100)
                {
                    break;
                }
                else
                {
                    MessageBox(NULL, "Please Enter Valid Score", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                    printf("\n\n\t\t\t\t\t\tPlease Enter a Score : ");
                }    
            }
            runs++;
            MessageBox(NULL, "The Score of the Anime was Updated", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
            if(score!=0)
            {
                printf("\n\n\t\t\t\t\t\tWould You Like to post this Rating Publicly? Enter 1 to post or any other key to decline : ");
                scanf("%d",&choice3);
                fflush(stdin);
                if(choice3==1)
                {
                    PostRating(score,animename);
                }
            }
            printcurrentdetails(typecheck,episodes,score);
        }
        else if(choice==0)
        {
            return 0;
        }
        else
        {
            i=0;
            MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
            printf("\n\n\t\t\t\t\tPlease Enter a Valid Choice: ");
        }
    }
    return 0;
}

int addanime(char type)
{
    int score=0,episodes=0,choice=0;
    char newanimename[76]="";
    char pmessage[1000]="";
    char str[1079]="";
    char filename[10]="";
    char term;
    char message[100];
    if(type=='1')
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tAdding a New Unwatched Anime in the Animelist.");
    }
    if(type=='2')
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tAdding a New Currently Watching Anime in the Animelist.");
    }
    if(type=='3')
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tAdding a New Watched Anime in the Animelist.");
    }
    if(type=='0')
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tAdding a Anime in the Animelist.");
    }
    printf("\n\n\n\n\t\t\t\t\t\t\tEnter The Name of the Anime: ");
    strcpy(newanimename,"");
    fgets(newanimename,75,stdin);
    newanimename[strlen(newanimename)-1]='\0';
    if(type=='0')
    {
        printf("\n\n\n\t\t\t\t\t\t\tEnter the current status of the Anime:\n\n\t\t\t\t\t\t\t1. Unwatched      2. Currently Watching     3. Watched");
        printf("\n\n\t\t\t\t\t\t\tEnter the status: ");
        while(1)
        {
            scanf("%c",&type);
            fflush(stdin);
            if(!(type!='1'||type!='2'||type!='3'))
            {
                MessageBox(NULL, "Please Enter A Valid Status of the Anime", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\t\tPlease Enter a Valid Status: ");
            }
            else
            {
                break;
            }
        }   
    }
    if(type!='1')
    {
        printf("\n\n\n\t\t\t\t\t\t\tEnter The Number of Episodes you have Watched in the Anime: ");
        while(1)
        {
            if(scanf("%d%c", &episodes, &term) != 2 || term != '\n')
            {
                fflush(stdin);
                MessageBox(NULL, "Please Enter Valid no. of Episodes", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\t\tPlease Enter a Valid no. of Episodes: ");
            }
            else
            {
                fflush(stdin);
                break;
            }    
        }
        printf("\n\n\n\t\t\t\t\t\t\tPlease Give A Score (out of 100) to the Anime (Enter 0 to Skip for Now): ");
        while(1)
        {
            scanf("%d", &score);
            fflush(stdin);
            if( score>=0 && score<=100)
            {
                break;
            }
            else
            {
                MessageBox(NULL, "Please Enter Valid Score", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\t\tPlease Enter a Score : ");
            }    
        }
    }
    strcpy(pmessage,"");
    printf("\n\n\n\t\t\t\t\t\t\tEnter a Personal Comment/Message Regarding this Anime (Leave Blank and hit Enter to Ignore) : ");
    fgets(pmessage,999,stdin);
    pmessage[strlen(pmessage)-1]='\0';
    strcpy(str,"");
    strcpy(str,newanimename);
    strcat(str,"$^@");
    strcat(str,pmessage);
    FILE *fp;
    strcpy(filename,"");
    strcpy(idstring2,"");
    strncpy(filename,makeuidstring(curruid),5);
    strcat(filename,".txt");
    fp = fopen(filename,"a");
    fprintf(fp,"\n%c %d %d %s",type,score,episodes,str);
    fclose(fp);
    sprintf(message,"%s was Successfully Added to Your Animelist",newanimename);
    MessageBox(NULL, message, "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
    if(score!=0)
    {
        printf("\n\n\n\n\t\t\t\t\t\t\tWould You Like to post the Score Given Publicly? Enter 1 to post or any other key to decline : ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            PostRating(score,newanimename);
        }
    }
    return 0;
}

int anilist(char type)
{
    FILE *fp;
    char c;
    char status[20];
    char filename[10]="";
    int counter=0,flag=0,choice=0;
    int episodes, score;
    char str[1079]="";
    char scorestr[8]="";
    strcpy(idstring2,"");
    strcpy(filename,"");
    strncpy(filename,makeuidstring(curruid),5);
    strcat(filename,".txt");
    fp = fopen(filename,"r");
    fscanf(fp,"%s",str);
    c=fgetc(fp);
    c=fgetc(fp);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tRetrieving Data From Your Animelist");Sleep(200);
    printf(".");Sleep(200);
    printf(".");Sleep(200);
    printf(".");Sleep(200);
    system("CLS");
    while(c!=EOF)
    {
        if(c=='1')
        {
            strcpy(status,"Unwatched");
        }
        else if(c=='2')
        {
            strcpy(status,"Currently Watching");
        }
        else
        {
            strcpy(status,"Watched");
        }
        fscanf(fp,"%d %d ",&score,&episodes);
        strcpy(scorestr,"");
        if(score!=0)
        {
            itoa(score,scorestr,10);
            strcat(scorestr,"/100");
        }
        else
        {
            strcpy(scorestr,"--");
        }
        if((c==type)||(type=='0'))
        {
            if(counter==0)
            {
                if(type=='1')
                {
                    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t      The Unwatched Animes in Your Animelist are:");
                }
                if(type=='2')
                {
                    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tThe Currently Watching Animes in Your Animelist are:");
                }
                if(type=='3')
                {
                    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t       The Watched Animes in Your Animelist are:");
                }
                if(type=='0')
                {
                    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tYour Animelist:\n\n");
                }
                if(type=='1')
                {
                    printf("\n\n\n\t\t\t\t\t%-5s\t%-75s\n","S No.","Anime Name");
                }
                else if(type=='0')
                {
                    printf("\n\n\n\t\t\t\t\t%-5s\t%-75s\t%-16s\t%-8s\t%s\n","S No.","Anime Name","Episodes Watched","Score","Status");
                }
                else
                {
                    printf("\n\n\n\t\t\t\t\t%-5s\t%-75s\t%-16s\t%s\n","S No.","Anime Name","Episodes Watched","Score");
                }
            }
            counter++;
            strcpy(str,"");
            while((c!='\n')&&(c!=EOF))
            {
                c=fgetc(fp);
                strncat(str,&c,1);
            }
            str[strlen(str)-1]='\0';
            getanimename(str);
            if(type=='1')
            {
                printf("\n\n\t\t\t\t\t%-5d\t%-75s",counter,animename);
            }
            else if(type == '0')
            {
                printf("\n\n\t\t\t\t\t%-5d\t%-75s\t%-16d\t%-8s\t%s",counter,animename,episodes,scorestr,status);
            }
            else
            {
                printf("\n\n\t\t\t\t\t%-5d\t%-75s\t%-16d\t%s",counter,animename,episodes,scorestr);
            }
            if(c!=EOF)
            {
                c=fgetc(fp);
            }
        }
        else
        {
            while((c!='\n')&&(c!=EOF))
            {
                c=fgetc(fp);
            }
            if(c!=EOF)
            {
                c=fgetc(fp);
            }
        }
    }
    fclose(fp);
    if(counter==0)
    {
        if(type=='1')
        {
            printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tThere are Currently no Unwatched Animes in Your Animelist.");
        }
        if(type=='2')
        {
            printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t    There are Currently no Currently Watching Animes in Your Animelist.");
        }
        if(type=='3')
        {
            printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tThe are Currently no Watched Animes in Your Animelist.");
        }
        if(type=='0')
        {
            printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tThere are Currently no Animes in Your Animelist.\n\n");
        }
    }
    else
    {
        printf("\n\n\n\n\t\t\t\t\tTo View/Edit/Delete Details or Status of an Anime, Enter The S.No. of that Anime.");
    }
    if(type=='1')
    {
        printf("\n\n\t\t\t\t\tTo Add a New Unwatched Anime to the Animelist, Enter 1000");
    }
    if(type=='2')
    {
        printf("\n\n\t\t\t\t\tTo Add a New Currently Watching Anime to the Animelist, Enter 1000");
    }
    if(type=='3')
    {
        printf("\n\n\t\t\t\t\tTo Add a New Watched Anime to the Animelist, Enter 1000");
    }
    if(type=='0')
    {
        printf("\n\n\t\t\t\t\tTo Add a New Anime to the Animelist, Enter 1000");
    }
    printf("\n\n\t\t\t\t\tTo Return to the Previous Menu, Enter 0");
    printf("\n\n\n\t\t\t\t\tEnter Your Choice : ");
    while(flag==0)
    {
        scanf("%d",&choice);
        fflush(stdin);
        if((choice<=counter)&&(choice>=1))
        {
            flag++;
            modanime(choice,type);
        }
        else if (choice==1000)
        {
            flag++;
            addanime(type);
        }
        else if(choice==0)
        {
            return 0;
        }
        else
        {
            MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
            printf("\n\n\t\t\t\t\tPlease Enter a Valid Choice: ");
        }
    }
    return 1;
}

int AnimeLists()
{
    int choice2=-1;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tHey %s, Which Part of Your Animelist do You Wish to View/Edit?\n\n",currname);
    printf("\n\n\n\t\t\t\t\t\t\t1. Unwatched Animes");
    printf("\n\n\n\t\t\t\t\t\t\t2. Currently Watching Animes");
    printf("\n\n\n\t\t\t\t\t\t\t3. Watched Animes");
    printf("\n\n\n\t\t\t\t\t\t\t4. The Entire Animelist");
    printf("\n\n\n\t\t\t\t\t\t\t0. Return to the Previous Menu\n\n");
    printf("\n\n\t\t\t\t\t\t\tPlease Enter Your Choice: ");
    while(choice2!=1 && choice2!=2 && choice2!=3 && choice2!=4 && choice2!=0)
    {
        scanf("%d",&choice2);
        fflush(stdin);
        switch(choice2)
        {
            case 1: 
            {
                system("CLS");
                while(anilist('1'))
                {
                    system("CLS");
                }
                break;
            }
            case 2: 
            {
                system("CLS");
                while(anilist('2'))
                {
                    system("CLS");
                }
                break;
            }
            case 3: 
            {
                system("CLS");
                while(anilist('3'))
                {
                    system("CLS");
                }
                break;
            }
            case 4: 
            {
                system("CLS");
                while(anilist('0'))
                {
                    system("CLS");
                }
                break;
            }
            case 0: 
            {
                return 0;
                break;
            }
            default: 
            {
                MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\t\tPlease Enter a Valid Choice: ");
                break;
            }
        }
    }
    return 1;
}

int Myprofile()
{
    int choice =-1;
    int ret=1;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tCurrently Logged In as %s",currname);
    printf("\n\n\n\t\t\t\t\t\t\t1. Change Password");
    printf("\n\n\n\t\t\t\t\t\t\t2. Log Out");
    printf("\n\n\n\t\t\t\t\t\t\t3. Delete Account");
    printf("\n\n\n\t\t\t\t\t\t\t0. Return to the Previous Menu\n\n");
    printf("\n\n\t\t\t\t\t\t\tPlease Enter Your Choice: ");
    while(choice!=1 && choice!=2 && choice!=3 && choice!=0)
    {
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1: 
            {
                system("CLS");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tChange Password\n\n\n");
                FILE *fp1;
                FILE *fp2;
                int count=0;
                char c;
                int id;
                char password[20],newpassword[20],checkpass[20],username[30];
                printf("\n\n\t\t\t\t\t\t\t\tEnter Current Password: ");
                scanf("%s",password);
                fp1 = fopen("Users.txt","r");
                while(count<(curruid-1))
                {
                    c=fgetc(fp1);
                    if(c=='\n')
                    {
                    count++;
                    }
                }
                fscanf(fp1,"%s %s %d",username,checkpass,&id);
                fclose(fp1);
                if(strcmp(checkpass,password)==0)
                {
                    fp2 = fopen("newusers.txt","w");
                    fp1 = fopen("Users.txt","r");
                    c=fgetc(fp1);
                    count=0;
                    while(count<(curruid-1))
                    {
                        fputc(c,fp2);
                        c=fgetc(fp1);
                        if(c=='\n')
                        {
                        count++;
                        }
                    }
                    if(curruid!=1)
                    {
                        fputc(c,fp2);
                    }
                    count =0;
                    printf("\n\n\t\t\t\t\t\t\t\tEnter New Password: ");
                    scanf("%s",newpassword);
                    fprintf(fp2,"%s %s %d\n",username,newpassword,id);
                    if(curruid!=totalusers)
                    {
                        while(count<1)
                        {
                            c=fgetc(fp1);
                            if(c=='\n')
                            {
                                count++;
                            }
                        }
                        c=fgetc(fp1);
                        while(c!=EOF)
                        {
                            fputc(c,fp2);
                            c=fgetc(fp1);
                        }
                    }
                    fclose(fp1);
                    fclose(fp2);
                    remove("Users.txt");
                    rename("newusers.txt","Users.txt");
                    MessageBox(NULL, "You Changed Your Password Successfully", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                }
                else
                {
                    MessageBox(NULL, "Wrong Password", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONERROR));
                }
                break;
                ret=1;
            }
            case 2:
            {
                strcpy(currname,"");
                loginflag=0;
                curruid=0;
                MessageBox(NULL, "You have Logged Out Successfully", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                ret=2;
                break;
            }
            case 3: 
            {
                int choose;
                printf("\n\n\n\t\t\t\t\t\tSelecting this option will permanently delete your account. Enter 1 to confirm and anything else to cancel: ");
                scanf("%d",&choose);
                fflush(stdin);
                if(choose==1)
                {
                    FILE *fp1;
                    FILE *fp2;
                    char filename[10]="";
                    char c;
                    int count = 0;
                    strcpy(idstring2,"");
                    strcpy(filename,makeuidstring(curruid));
                    strcat(filename,".txt");
                    fp1=fopen(filename,"w");
                    fprintf(fp1,"user");
                    fclose(fp1);
                    fp2 = fopen("newusers.txt","w");
                    fp1 = fopen("Users.txt","r");
                    c=fgetc(fp1);
                    count=0;
                    while(count<(curruid-1))
                    {
                        fputc(c,fp2);
                        c=fgetc(fp1);
                        if(c=='\n')
                        {
                        count++;
                        }
                    }
                    if(curruid!=1)
                    {
                        fputc(c,fp2);
                    }
                    count =0;
                    fprintf(fp2,"user <deleted> %d",curruid);
                    if(curruid!=totalusers)
                    {
                        fprintf(fp2,"\n");
                        while(count<1)
                        {
                            c=fgetc(fp1);
                            if(c=='\n')
                            {
                                count++;
                            }
                        }
                        c=fgetc(fp1);
                        while(c!=EOF)
                        {
                            fputc(c,fp2);
                            c=fgetc(fp1);
                        }
                    }
                    fclose(fp1);
                    fclose(fp2);
                    remove("Users.txt");
                    rename("newusers.txt","Users.txt");
                    loginflag=0;
                    curruid=0;
                    strcpy(currname,"");
                    MessageBox(NULL, "Your Account was Deleted Successfully", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONINFORMATION));
                    ret=2;
                }
                break;
            }
            case 0: 
            {
                ret=0;
                break;
            }
            default:
            {
                MessageBox(NULL, "Please Enter A Valid Choice", "Anilist",( MB_OK | MB_TOPMOST| MB_ICONEXCLAMATION));
                printf("\n\n\t\t\t\t\t\t\tPlease Enter a Valid Choice: ");
                break;
            }    
        }
    }
    return ret;
}

int LoadBasics()
{
    FILE *fp;
    fp = fopen("basic.txt", "r");
    fscanf(fp,"%d",&keepme);
    fscanf(fp,"%d",&totalusers);
    fscanf(fp,"%d",&totaltopics);
    fclose(fp);
    return 0;
}

int ChangeBasics()
{
    FILE *fp;
    fp = fopen("basic.txt", "w");
    fprintf(fp,"%d\n",keepme);
    fprintf(fp,"%d\n",totalusers);
    fprintf(fp,"%d",totaltopics);
    fclose(fp);
    return 0;
}

int Rememberme()
{
    int choice = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t  Do You Want Anilist to keep You Logged In the Next Time You Run it?");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    Enter 1 to Confirm");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter any Other key to Deny");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t      Your Response: ");
    scanf("%d",&choice);
    fflush(stdin);
    if(choice == 1)
    {
        keepme = curruid;
    }
    return 0;
}

int call1()
{
    LoadBasics();
    if(keepme!=0)
    {
        curruid=keepme;
        strcpy(idstring2,"");
        strcpy(currname,getname(makeuidstring(curruid)));
        loginflag=1;
        keepme=0;
    }
    system("CLS");
    FirstScreen();
    system("CLS");
    return 0;
}

int call2()
{
    int selection;
    int choice=0;
    system("CLS");
    if(curruid==0)
    {
        SecScreen();
    }
    else
    {
        choice = SecScreen2();
        if(choice==0)
        {
            system("CLS");
            SecScreen(); 
        }
    }
    system("CLS");
    if(loginflag == 1)
    {
        strcpy(idstring2,"");
        strcpy(currname,getname(makeuidstring(curruid)));
        while(1)
        {
            selection=ThirdScreen1();
            if(selection==1)
            {
                system("CLS");
            }
            else if(selection==2)
            {
                return 1;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        while(ThirdScreen2()==1)
        {
            system("CLS");
            if(loginflag == 1)
            {
                strcpy(idstring2,"");
                strcpy(currname,getname(makeuidstring(curruid)));
                while(1)
                {
                    selection=ThirdScreen1();
                    if(selection==1)
                    {
                        system("CLS");
                    }
                    else if(selection==2)
                    {
                        return 1;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }
        }
    }
    if (curruid !=0)
    {
        system("CLS");
        Rememberme();
    }
    ChangeBasics();
    system("CLS");
    return 0;
}

int main()
{
    call1();
    while(call2()==1);
}