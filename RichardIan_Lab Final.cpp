//Authors: Richard Gunasena and Ian Nobile
//Lab Section: 01
//Assignment: Lab Final
/*Program Description: Two game bots, named correspondingly to the names of the two programmers who created them, play 10 games of 3D Tic-Tac-Toe in a row against each other and a winner is determined and announced at the end of the competition. */
//Due Date: 12/5/18

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>
using namespace std;

class TTT{
	
    public:
        int count;
        int rWin;
        int iWin;
        int cWin;
        int uWin;
        int pos[27];
        string board[27];
        int status;
    
        void win(void);
        void print(void);
        int check(int);
        void move(void);
        void cMove(void);
        int rCount(void);
        void next(void);
        TTT();
    
    
};

TTT::TTT(){
    count = 0;
    rWin = 0;
    iWin = 0;
    status = 0;
    string b[27] = {"1", "2", "3", "4", "5","6","7","8","9",
        "10", "11", "12", "13", "14","15","16","17","18",
        "19", "20", "21", "22", "23","24","25","26","27"};
    
    for(int i = 0; i < 27; i++){
        pos[i] = i + 1;
        board[i] = b[i];
        
    }
}

void TTT::next(void){
    count = 0;
    status = 0;
    string b[27] = {"1", "2", "3", "4", "5","6","7","8","9",
        "10", "11", "12", "13", "14","15","16","17","18",
        "19", "20", "21", "22", "23","24","25","26","27"};
    
    for(int i = 0; i < 27; i++){
        pos[i] = i + 1;
        board[i] = b[i];
        
    }
}

int TTT :: rCount(void){
    return count;
}

void TTT :: win(void){
    
    if(count != 27){
        cWin = 0;
        uWin = 0;
        
        //2D horizontal wins
        for(int i = 0; i < 27; i = i + 3){
            if(board[i] == "X" && board[i+1] == "X" && board[i+2] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+1] == "O" && board[i+2] == "O"){
                cWin++;
            }
            
        }
        
        //2D vertical wins
        for(int x = 0; x < 27; x = x + 9){
            for(int i = x; i < (x+3); i++){
                if(board[i] == "X" && board[i+3] == "X" && board[i+6] == "X"){
                    uWin++;
                }
                
                if(board[i] == "O" && board[i+3] == "O" && board[i+6] == "O"){
                    cWin++;
                }
                
            }
        }
        
        //2D Diagonal wins
        for(int i = 0; i < 27; i = i + 9){
            
            if(board[i] == "X" && board[i+4] == "X" && board[i+8] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+4] == "O" && board[i+8] == "O"){
                cWin++;
            }
            
            if(board[i+2] == "X" && board[i+4] == "X" && board[i+6] == "X"){
                uWin++;
            }
            
            if(board[i+2] == "O" && board[i+4] == "O" && board[i+6] == "O"){
                cWin++;
            }
        }
        
        //3D Straight up wins
        for(int i = 0; i < 9; i++){
            if(board[i] == "X" && board[i+9] == "X" && board[i+18] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+9] == "O" && board[i+18] == "O"){
                cWin++;
            }
        }
        
        //3D Diagonal YZ bottom up wins
        for(int i = 0; i < 3; i++){
            if(board[i] == "X" && board[i+12] == "X" && board[i+24] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+12] == "O" && board[i+24] == "O"){
                cWin++;
            }
        }
        
        //3D Diagonal YZ top down wins
        for(int i = 6; i < 9; i++){
            if(board[i] == "X" && board[i+6] == "X" && board[i+12] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+6] == "O" && board[i+12] == "O"){
                cWin++;
            }
        }
        
        //3D Diagonal XZ bottom up wins
        for(int i = 0; i < 9; i = i + 3){
            if(board[i] == "X" && board[i+10] == "X" && board[i+20] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+10] == "O" && board[i+20] == "O"){
                cWin++;
            }
        }
        
        //3D Diagonal XZ top down wins
        for(int i = 2; i < 9; i = i + 3){
            if(board[i] == "X" && board[i+8] == "X" && board[i+16] == "X"){
                uWin++;
            }
            
            if(board[i] == "O" && board[i+8] == "O" && board[i+16] == "O"){
                cWin++;
            }
        }
        
        //3D XYZ Diagonal Wins
        if(board[0] == "X" && board[13] == "X" && board[26] == "X"){
            uWin++;
        }
        
        if(board[0] == "O" && board[13] == "O" && board[26] == "O"){
            cWin++;
        }
        
        if(board[2] == "X" && board[13] == "X" && board[24] == "X"){
            uWin++;
        }
        
        if(board[2] == "O" && board[13] == "O" && board[24] == "O"){
            cWin++;
        }
        
        if(board[6] == "X" && board[13] == "X" && board[20] == "X"){
            uWin++;
        }
        
        if(board[6] == "O" && board[13] == "O" && board[20] == "O"){
            cWin++;
        }
        
        if(board[8] == "X" && board[13] == "X" && board[18] == "X"){
            uWin++;
        }
        
        if(board[8] == "O" && board[13] == "O" && board[18] == "O"){
            cWin++;
        }
        
        //cout <<"\nComputer Wins: " << cWin <<endl;
        //cout <<"User Wins: " << uWin << endl;
    }
    else{
        //cout <<"\nComputer Wins: " << cWin <<endl;
        //cout <<"User Wins: " << uWin << endl;
        
        if(cWin == uWin){
        	Sleep(1000);
            cout << "\nIts a Draw! ";
        }else{
            if(cWin > uWin){
            	Sleep(1000);
                cout << "\nRichard WINS! ";
                rWin++;
            }else{
            	Sleep(1000);
                cout << "\nIan WINS! ";
                iWin++;
            }
            
        }
    }
}

void TTT :: print(void){
    cout << "\n | " << board[0] << " | " << board[1] << " | " << board[2] << " |" <<endl
    << "---------------" <<endl
    << " | " << board[3] << " | " << board[4] << " | " << board[5] << " |" <<endl
    << "---------------" <<endl
    << " | " << board[6] << " | " << board[7] << " | " << board[8] << " |" <<endl
    
    << "\n\t | " << board[9] << " | " << board[10] << " | " << board[11] << " |" <<endl
    << "\t------------------" <<endl
    << "\t | " << board[12] << " | " << board[13] << " | " << board[14] << " |" <<endl
    << "\t------------------" <<endl
    << "\t | " << board[15] << " | " << board[16] << " | " << board[17] << " |" <<endl
    
    << "\n\t\t | " << board[18] << " | " << board[19] << " | " << board[20] << " |" <<endl
    << "\t\t------------------" <<endl
    << "\t\t | " << board[21] << " | " << board[22] << " | " << board[23] << " |" <<endl
    << "\t\t------------------" <<endl
    << "\t\t | " << board[24] << " | " << board[25] << " | " << board[26] << " |" <<endl;
}

int TTT :: check(int move){
    int check = 0;
    
    for(int i = 0; i < 27; i++){
        if(pos[i] == move){
            check = 1;
        }
    }
    
    return check;
}

void TTT :: move(void){
    int move = -1;
    
    while(move == -1){
        cout <<"\nEnter the number of the position you want to play:";
        cin >> move;
        
        if(check(move)){
            board[move - 1] = "X";
            pos[move - 1] = 30;
            count++;
        }else{
            cout <<"ILLEGAL MOVE, please choose a different position"<<endl;
            move = -1;
        }
        
    }
    
    print();
    win();
    
}

void TTT :: cMove(void){
    if(count < 27){
    	int move = -1;
    
	    while(!(check(move))){
	        move = (rand() % 27) + 1;
	    }
	    
	    board[move - 1] = "O";
	    pos[move - 1] = 30;
	    count++;
	    
	    cout <<"\nRichard's Move:"<<endl;
	    print();
	    win();
    }
	
}


class BoardIan3D{
    public:
        int iAvailableSpaces[27];
        string sSpace[27];
    
        //constructor; sets the values for a board and marks spaces as untaken
        BoardIan3D();    
        void IanPlay(void);


};//end class BoardIan3D

BoardIan3D :: BoardIan3D(){
	int i;
    for(i=0;i<27;i++){
        iAvailableSpaces[i]=i+1;
        sSpace[i] = i;
    }//end for
	
}

//the original IanPlay from my Lab 10
void BoardIan3D::IanPlay(void){
    int iComputerSelection=0;
    //generates a random selection for the computer and checks that it is available
    //game1 is the name of my object, like your g1
    do{iComputerSelection = rand()%(27-1+1)+1;}while(iAvailableSpaces[iComputerSelection-1]==0);
    
    //marks space for computer
    std::cout<<"I choose "<<iComputerSelection<<"."<<std::endl;
            sSpace[iComputerSelection] = "O";
            iAvailableSpaces[iComputerSelection-1]=0;
            system("PAUSE");
            system("CLS");
            
    
}//end IanPlay


//combining our two classes into a new one via inheritance:
class competition: public TTT, public BoardIan3D{
   public:
        void IanPlay();
        void overall(void);
        //competition constructor here:
};

//redefinition of IanPlay()
void competition::IanPlay(){
	if(count < 27){
		int iComputerSelection=0;
	    //generates a random selection for me and checks that it is available using your check function
	    do{iComputerSelection= rand()%(27-1+1)+1;}while(!check(iComputerSelection));
	    
	    //marks space for computer; uses your functions
	    std::cout<<"Ian chooses "<<iComputerSelection<<"."<<std::endl;
	    board[iComputerSelection - 1] = "X";
	    pos[iComputerSelection - 1] = 30;
	    count++;
	    print();
	    win();
    }
} 

void competition :: overall(){
	cout <<"\nRichard Overall Wins: " << rWin <<endl;
	cout <<"Ian Overall Wins: " << iWin <<endl;
	
	 if(rWin == iWin){
            cout << "Its a OVERALL Draw!" << endl;
        }else{
            if(rWin > iWin){
                cout << "Richard is the OVERALL WINNER!" << endl;
                rWin++;
            }else{
                cout << "Ian is the OVERALL WINNER!" << endl;
                iWin++;
            }
            
        }
	
}


int main(void){
    competition g1;
    srand(time(NULL));
    int i;
    
    //greetings from the computer
    cout<<"Welcome to the 3D Tic-Tac-Toe Final Showdown: Richard (O) vs. Ian (X)"<<endl;
    Sleep(2000);
    cout<<"The bots will play ten games and then a winner will be announced."<<endl;
    Sleep(2000);
    cout<<"Let the games begin!"<<endl;
    Sleep(2000);
  
	for(i = 1; i < 11; i++){
        int turn = rand()%2;
        
        cout << "\nGAME " << i << ":" <<endl;
        
        if(turn == 0){
            cout << "Richard plays first!" <<endl;
            Sleep(2000);
        }//end for
        else{
            cout << "Ian plays first!" <<endl;
            Sleep(2000);
        }//end else
        
        g1.print();
        
        while(g1.rCount() < 27){
            
            if(turn == 0){
                g1.cMove();
                g1.IanPlay();
            }//end if turn0

            if(turn == 1){
                g1.IanPlay();
                g1.cMove();
            }//end if turn1
            
        }//end while
        
        cout << "GAME " << i <<endl;
        Sleep(2000);
        g1.next();
	}
	
	g1.overall();
    
} //end main

