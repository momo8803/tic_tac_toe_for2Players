#include <stdio.h>

//char box[3][3] = {{1,2,3},{4,5,6},{7,8,9}};//<--2d array
char box[10]={'0','1','2','3','4','5','6','7','8','9'};
void CreateTheBoard();
void MarkingTheBoard(int, char);
int CheckTheWinner();
int main()
{
    int choice,player=1,i;
    char mark, ans;
    do{
        do{
            CreateTheBoard();
            player= (player % 2) ? 1: 2; // ? mean <--statement if true : statement is false
        
            printf("Player %d, enter a number: ",player);
            scanf("%d",&choice);

            mark = (player==1) ? 'O' : 'X';
            MarkingTheBoard(choice,mark);

            i=CheckTheWinner();
            player++;

        }while(i == -1);

        CreateTheBoard();

        if(i==1)
        printf("Player %d  you have won the game\n",--player);
        else
        printf("it is a Draw\n");

        printf("Do you want to play again? (y/n)");
        scanf(" %c", &ans);
    }while(ans=='Y'||ans=='y');

    return 0;
}

void CreateTheBoard()
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (O) -- Player 2 (X)\n\n");
    printf("     |     |     \n");
    printf(" %c   | %c   | %c   \n",box[1],box[2],box[3]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");
    printf(" %c   | %c   | %c   \n",box[4],box[5],box[6]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");
    printf(" %c   | %c   | %c   \n",box[7],box[8],box[9]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");


}
void MarkingTheBoard( int choice, char mark)
{

    if(choice==1 && box[1]=='1')
        box[1]=mark;
    else if(choice==2 && box[2]=='2')
        box[2]=mark;
    else if(choice==3 && box[3]=='3')
        box[3]=mark;
    else if(choice==4 && box[4]=='4')
        box[4]=mark;
    else if (choice==5 && box[5]=='5')
        box[5]=mark;
    else if (choice==6 && box[6]=='6')
        box[6]=mark;
    else if (choice==7 && box[7]=='7')
        box[7]=mark;
    else if (choice==8 && box[8]=='8')
        box[8]=mark;
    else if (choice==9 && box[9]=='9')
        box[9]=mark;
    else
    {
        printf("Invalid choice");
 
    }
}

int CheckTheWinner()
{
    if(box[1]==box[2] && box[2]==box[3])
        return 1;
    else if(box[4]==box[5] && box[5]==box[6])
        return 1;                                   
    else if (box[7]==box[8] && box[8]==box[9])
        return 1;
    else if (box[1]==box[4] && box[4]==box[7])
        return 1;
    else if(box[2]==box[5] && box[5]==box[8])           
        return 1;
    else if(box[3]==box[6] && box[6]==box[9])
        return 1;
    else if(box[1]==box[5] && box[5]==box[9])
        return 1;
    else if(box[3]==box[5] && box[5]==box[7])
        return 1;
    //draw    
    else if(box[1]!= '1' && box[2]!= '2' && box[3]!= '3' && box[4]!= '4'&& box[5]!= '5' && box[6]!= '6'&& box[7]!= '7' && box[8]!= '8' && box[9]!='9')  //no match
        return 0;
    //again
    else
        return -1;


}
