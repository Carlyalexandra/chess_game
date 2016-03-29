//void main()
//{
//
//    //Graphics Initialization
//    int gdriver = DETECT;
//    int gmode;
//    initgraph(&gdriver,&gmode,"e:\\borlandc\\bgi");
//
//    //Loading Intro
//    for(float i=0; i<=6;i=i+0.1)
//    {
//        setcolor(12);
//        settextstyle(4,HORIZ_DIR,i);
//        outtextxy(50,120,"WELCOME TO THE CHESS");
//        delay(30);
//        cleardevice();
//    }
//    outtextxy(50,120,"WELCOME TO THE CHESS");
//    settextstyle(1,HORIZ_DIR,3);
//    getch();
//    cleardevice();
//
//    //Displaying Group Members
//    setcolor(CYAN);
//    outtextxy(50,220,"Designed by:");
//    setcolor(6);
//    outtextxy(50,250,"Atif Zia Khan");
//
//    //Displaying Roll Numbers
//    outtextxy(350,250,"L1F01BSCS0144");
//    getch();
//    cleardevice();
//    cleardevice();
//
//    settextstyle(1,HORIZ_DIR,2);
//    setcolor(12);
//    outtextxy(50,10,"During the game Press:\n");
//    outtextxy(50,10,"______________________\n");
//
//
//    setcolor(6);
//    settextstyle(1,HORIZ_DIR,1.5);
//    outtextxy(50,60,"F2 to save file\n");
//    outtextxy(50,80,"F3 to load file\n");
//    outtextxy(50,100,"ESC to exit game\n");
//    outtextxy(50,120,"U to undo selection\n");
//    outtextxy(50,200,"\nPress any key to play ");
//    getch();
//    cleardevice();
//
//
//    cleartext();
//    initialize();
//    char ch;
//    int x=-1,y=-1,x1=-1,y1=-1;
//    setcolor(9);
//    outtextxy(10,400,"Player 1");
//    for(;;)
//    {
//        int game;
//        game=gameover();
//        if(game==0)
//        {
//            break;
//        }
//        FILE *fp;
//        ch=getch();
//        if(ch==0){
//            ch=getch();
//            if(ch=='<'){
//
//
//                //////SAVE/////
//
//                for(;;)
//                {
//
//                    cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\
//\b\b\bEnter File name to save \n";
//                    cin>>strFileName;  //Enter File Name
//                    fp=fopen(strFileName,"r+");
//                    if(fp!=NULL)
//                    {
//                        cout<<"File already exist\n";
//                    }
//                    else
//                    {
//                        fp=fopen(strFileName,"w+");
//                        if(fp==NULL)
//                        {
//                            cout<<"Invalid File Name\n";
//                        }
//                        else
//                            break;
//                    }
//                }//end for
//                fprintf(fp,"%d\n",turn);
//                for(int i=0;i<8;i++)
//                {
//                    for(int j=0;j<8;j++)
//                    {
//                        fprintf(fp,"%d\n",board[i][j]);
//                    }
//                }
//                fclose(fp);
//                cleartext();
//                x=-1;
//                y=-1;
//                x1=-1;
//                y1=-1;
//                continue;
//            }
//
//            if(ch=='=')
//            {
//////Load/////
//
//
//                for(;;)
//                {
//
//                    cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\
//\b\b\b\b\bEnter File name to Load \n";
//                    cin>>strFileName;
//                    fp=fopen(strFileName,"r+");
//                    if(fp==NULL)
//                    {
//                        cout<<"File does not exist\n";
//                    }
//                    else
//                    {
//                        break;
//                    }
//                }//end for
//                fscanf(fp,"%d",&turn);
//                for(int i=0;i<8;i++){
//                    for(int j=0;j<8;j++){
//                        fscanf(fp,"%d",&board[i][j]);
//                    }
//                }
//                fclose(fp);
//                printboard();
//                cleartext();
//                x=-1;
//                y=-1;
//                x1=-1;
//                y1=-1;
//                setcolor(0);
//                outtextxy(10,400,"Player Û");
//                if(turn!=0){
//                    check();
//                    setcolor(2);
//                    outtextxy(10,400,"Player 2");
//                }
//                else{
//                    check();
//                    setcolor(9);
//                    outtextxy(10,400,"Player 1");
//                }
//                continue;
//            }
//        }
//
//        if(ch==27){
//            break;
//        }
//        else if(ch=='u'||ch=='U'){
//            x=-1;
//            x1=-1;
//            y1=-1;
//            y=-1;
//            cleartext();
//            continue;
//        }
//        if(x==-1){
//            ch=toupper(ch);
//            if(ch>=65 && ch<=72){
//                cout<<ch;
//                x=ch-65;
//            }
//        }
//        else if(y==-1)
//        {
//            if(ch>='1' && ch<='8')
//            {
//                cout<<ch;
//                y=ch-'1';
//                if(board[y][x]==0){
//                    wrongStart();
//                    x=-1;
//                    y=-1;
//                }
//                else
//                {
//                    if(turn==0)
//                    {
//                        if(board[y][x]<0)
//                            //if Player 1 has selected a piece of Player 2
//                        {
//                            wrongStart();
//                            x=-1;
//                            y=-1;
//                        }
//                    }
//                    else if(turn!=0)
//                    {
//                        if(board[y][x]>0)
//                        {
//                            wrongStart();
//                            x=-1;
//                            y=-1;
//                        }
//                    }
//                }
//            }
//            if(x!=-1 && y!=-1)
//                cout<<"\nenter final position  ¯ ";
//        }
//        else if(x1==-1)
//        {		//Converting lower to upper case
//
//            ch=toupper(ch);
//            if(ch>=65 && ch<=72)
//            {
//                cout<<ch;
//                x1=ch-65;
//            }
//        }
//        else if(y1==-1)
//        {
//            if(ch>='1' && ch<='8')
//            {
//                cout<<ch;
//                y1=ch-'1';
//            }
//            int b=0,killed=0;
//
///////pawn/////
//
//            if(abs(board[y][x])>=9 &&
//               abs(board[y][x])<=16){	//if piece selscted has value greater than 8
//                and less than 17
//                b = pawn(x,y,x1,y1);
//            }//end pawn
//
////////horse//////
//
//            else if(abs(board[y][x])==2 ||
//                    abs(board[y][x])==7){	   //if piece selscted has value 2 and 7
//                b = horse(x,y,x1,y1);
//            }//end horse
//
//////queen///
//
//            else if(abs(board[y][x])==4){	////if piece
//                selscted has value 4
//                b = queen(x,y,x1,y1);
//            }//end queen
/////king///
//
//            else if(abs(board[y][x])==5){	//if piece
//                selscted has value 5
//                b = king(x,y,x1,y1);
//            }//end king
//
/////rook///
//
//            else if(abs(board[y][x])==1 ||
//                    abs(board[y][x])==8){	   //if piece selscted has value 1 and 8
//                b = rook(x,y,x1,y1);
//            }//end rook
//
/////bishop///
//
//            else if(abs(board[y][x])==3 ||
//                    abs(board[y][x])==6){	   //if piece selscted has value 3 and 6
//                b = bishop(x,y,x1,y1);
//            }//end bishop
//
//            if(b==2){
//                if(abs(board[y][x])>=9 && abs(board[y][x])<=16){
//                    char pp;
//
//                    cout<<"\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\
//\bwhich piece Q,R,H,B";
//                    pp=getch();
//                    if(turn==0){
//                        if(pp=='r')
//                            board[y1][x1]=1;
//                        else if(pp=='h')
//                            board[y1][x1]=2;
//                        else if(pp=='b')
//                            board[y1][x1]=3;
//                        else if(pp=='q')
//                            board[y1][x1]=4;
//                    }
//                    else{
//                        if(pp=='r')
//                            board[y1][x1]=-1;
//                        else if(pp=='h')
//                            board[y1][x1]=-2;
//                        else if(pp=='r')
//                            board[y1][x1]=-3;
//                        else if(pp=='q')
//                            board[y1][x1]=-4;
//                    }
//
//                    board[y][x]=0;
//                    killed =1;
//                }
//                else if(abs(board[y][x])==5){
//                    if(board[y][x]==5){
//                        if(count1==1);
//                        wrongStart();}
//                    else if(board[y][x]==-5){
//                        if(count1==1);
//                        wrongStart();}
//                    else{
//                        board[y][x+1]=board[y1][x1];
//                        board[y][x+2]=board[y][x];
//                        board[y1][x1]=0;
//                        board[y][x]=0;
//                        killed=1;
//                    }
//                }
//                printboard();
//            }
//            else if(b==1)
//            {
//                if(turn==0)
//                {
//                    if(board[y1][x1]<0)
//                    {
//                        board[y1][x1]=board[y][x];
//                        board[y][x] = 0;
//                        killed=1;
//                    }
//                }
//                if(turn!=0)
//                {
//                    if(board[y1][x1]>0)
//                    {
//                        board[y1][x1]=board[y][x];
//                        board[y][x] = 0;
//                        killed=1;
//                    }
//                }
//                if(board[y1][x1]==0)
//                {
//                    int temp=board[y][x];
//                    board[y][x]=board[y1][x1];
//                    board[y1][x1]=temp;
//                    killed=1;
//                }
//                printboard();
//            }
//            x=-1;
//            y=-1;
//            x1=-1;
//            y1=-1;
//            setcolor(0);
//            outtextxy(30,340,"Check");
//            if(killed==0){
//                wrongStart();
//                continue;
//            }
//            cleartext();
//            setcolor(0);
//            outtextxy(10,400,"Player Û");
//            if(turn==0){
//                check();
//                turn=1;
//                setcolor(2);
//                outtextxy(10,400,"Player 2");
//            }
//            else{
//                check();
//                turn=0;
//                setcolor(9);
//                outtextxy(10,400,"Player 1");
//            }
//        }//end legal move
//    }//end for
//}//end main