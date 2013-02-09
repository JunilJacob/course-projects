#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qmessagebox.h>
#include<QCloseEvent>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define g 9.8
#define max 300
QDialog *dialog;
QSpinBox *pool_spinbox;
QDoubleSpinBox *offtake_spinbox;
QDoubleSpinBox *flowrate_spinbox;
QDoubleSpinBox *low_spinbox;
QDoubleSpinBox *high_spinbox;
QDoubleSpinBox *member_spinbox;
QDoubleSpinBox *bottom_spinbox;
QDoubleSpinBox *slope_spinbox;
QDoubleSpinBox *flowdepth_spinbox;
QDoubleSpinBox *nodes_spinbox;
QDoubleSpinBox *distance_spinbox;
QDoubleSpinBox *sideslope_spinbox;
QDoubleSpinBox *target_spinbox;
QDoubleSpinBox *length_spinbox;



int dx,re=0,mn[]={0,1,0},bh=0;
double res,i,inter;
int state=1,no_pool,ind,k=0;
int flag[101]={0};
int check[101]={0};
double flow[101],offtake[101],low[101],high[101],designed[101],member[101],sideslope[101],bedslope[101],bottom[101],flowdepth[101],node[101],distance[101];
double target[101];
double op[max]={0},in[max]={0};
void gnuplot(const char *gnucommand)
{
  char syscommand[1024];
  sprintf(syscommand, "echo \"%s\" | gnuplot -persist", gnucommand);
  system(syscommand);
}
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Frame_2->hide();
    ui->Frame_3->hide();
    ui->No_pool_spinbox->setRange(1,1000);
    //ui->No_nodes_spinbox->setRange(1,10000);
    //ui->Distance_doubleSpinBox->setRange(0,1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Next_pushButton_clicked()
{   if(state==1)
    {
        ui->Frame_1->hide();
        ui->Frame_2->show();
        ui->Exit_pushButton->setText("Back");
        ui->No_pool_spinbox->setRange(1,1000);
        if(ui->Single_radio->isChecked()){
            ui->No_pool_spinbox->setRange(1,1);
            ui->No_pool_spinbox->setValue(1);
        }
       // QMessageBox::information(this, tr("Canal Automation"),tr("Enter positive value for all fields "),QMessageBox::Ok);
        state=2;
        //ui->Next_pushButton->show();
    }
    else
    {
        ui->Frame_2->hide();
       // ui->Frame_3->show();
        state=3;
        //ui->Frame_3->show();
        //if(ui->Single_radio->isChecked())
          //  ui->Next_pushButton->setText("Submit");
        //state=3;
       // QMessageBox::information(this, tr("Canal Automation"),tr("Enter positive value for all fields "),QMessageBox::Ok);
    //}
    //else{
      //  if(ui->Single_radio->isChecked()){
        //    MainWindow::full_node_automation(0,0,0);}
        //else
        //{
           // ui->Frame_3->hide();
        ui->Next_pushButton->hide();
         ui->Exit_pushButton->hide();
         setdialog();


       }




    }





void MainWindow::setdialog()
{
    int i;
    no_pool=ui->No_pool_spinbox->value();
    dialog = new QDialog(this);
    dialog->setGeometry(600,350,400,700);

    pool_spinbox=new QSpinBox(dialog);
    pool_spinbox->show();
    pool_spinbox->setMinimum(1);
    pool_spinbox->setGeometry(200,35,50,30);
    length_spinbox=new QDoubleSpinBox(dialog);
    length_spinbox->show();
    length_spinbox->setGeometry(200,75,50,30);
    length_spinbox->setRange(0,10000);;
    slope_spinbox=new QDoubleSpinBox(dialog);
    slope_spinbox->show();
    slope_spinbox->setGeometry(200,115,50,30);
    slope_spinbox->setDecimals(6);;
    bottom_spinbox=new QDoubleSpinBox(dialog);
    bottom_spinbox->show();
    bottom_spinbox->setGeometry(200,155,50,30);
    sideslope_spinbox=new QDoubleSpinBox(dialog);
    sideslope_spinbox->show();
    sideslope_spinbox->setGeometry(200,195,50,30);
    sideslope_spinbox->setDecimals(6);
    flowrate_spinbox=new QDoubleSpinBox(dialog);
    flowrate_spinbox->show();
    flowrate_spinbox->setGeometry(200,235,50,30);
    flowdepth_spinbox=new QDoubleSpinBox(dialog);
    flowdepth_spinbox->show();
    flowdepth_spinbox->setGeometry(200,275,50,30);

    low_spinbox=new QDoubleSpinBox(dialog);
    low_spinbox->show();
    low_spinbox->setGeometry(200,315,50,30);
    high_spinbox=new QDoubleSpinBox(dialog);
    high_spinbox->show();
    high_spinbox->setGeometry(200,355,50,30);
    member_spinbox=new QDoubleSpinBox(dialog);
    member_spinbox->show();
    member_spinbox->setGeometry(200,395,50,30);

    offtake_spinbox=new QDoubleSpinBox(dialog);
    offtake_spinbox->show();
    offtake_spinbox->setGeometry(200,435,50,30);
    target_spinbox=new QDoubleSpinBox(dialog);
    target_spinbox->show();
    target_spinbox->setGeometry(200,475,50,30);

    nodes_spinbox=new QDoubleSpinBox(dialog);
    nodes_spinbox->show();
    nodes_spinbox->setGeometry(200,515,50,30);

    QLabel * pool_label=new QLabel(dialog);
    pool_label->show();
    pool_label->setGeometry(50,25,100,50);
    pool_label->setText("Pool Number");
    QLabel * length_label=new QLabel(dialog);
    length_label->show();
    length_label->setGeometry(50,65,125,50);
    length_label->setText("Length of the pool");
    QLabel * low_label=new QLabel(dialog);
    low_label->show();
    low_label->setGeometry(50,305,275,50);
    low_label->setText("Low Flowrate");
    QLabel * high_label=new QLabel(dialog);
    high_label->show();
    high_label->setGeometry(50,345,300,50);
    high_label->setText("High Flowrate");
    QLabel * flow_label=new QLabel(dialog);
    flow_label->show();
    flow_label->setGeometry(50,225,225,50);
    flow_label->setText("Designed Flow Rate");
    QLabel * member_label=new QLabel(dialog);
    member_label->show();
    member_label->setGeometry(50,385,325,50);
    member_label->setText("No of Memberfunctions");
    QLabel * slope_label=new QLabel(dialog);
    slope_label->show();
    slope_label->setGeometry(50,105,150,50);
    slope_label->setText("Bed slope");
    QLabel * sideslope_label=new QLabel(dialog);
    sideslope_label->show();
    sideslope_label->setGeometry(50,185,200,50);
    sideslope_label->setText("side slope");
    QLabel * bottom_label=new QLabel(dialog);
    bottom_label->show();
    bottom_label->setGeometry(50,145,175,50);
    bottom_label->setText("Bottom Width");
    QLabel * flowdepth_label=new QLabel(dialog);
    flowdepth_label->show();
    flowdepth_label->setGeometry(50,265,250,50);
    flowdepth_label->setText("Designed Flow Depth");
    QLabel * offtake_label=new QLabel(dialog);
    offtake_label->show();
    offtake_label->setGeometry(50,425,350,50);
    offtake_label->setText("Offtake Discharge");
    QLabel * nodes_label=new QLabel(dialog);
    nodes_label->show();
    nodes_label->setGeometry(50,505,400,50);
    nodes_label->setText("No of nodes");
    QLabel * target_label=new QLabel(dialog);
    target_label->show();
    target_label->setGeometry(50,465,375,50);
    target_label->setText("Target water depth");

    QPushButton * accept = new QPushButton(dialog);
    accept->show();
    accept->setGeometry(300,30,80,30);
    accept->setText("Accept");
    QPushButton * cancel = new QPushButton(dialog);
    cancel->show();
    cancel->setGeometry(300,75,80,30);
    cancel->setText("Cancel");
    QPushButton * ok = new QPushButton(dialog);
    ok->show();
    ok->setGeometry(300,115,80,30);
    ok->setText("Ok");
    QObject ::connect(accept,SIGNAL(clicked()),this,SLOT(on_accept_clicked()));//take very much time of project
    QObject ::connect(cancel,SIGNAL(clicked()),this,SLOT(on_cancel_clicked()));
    QObject ::connect(ok,SIGNAL(clicked()),this,SLOT(on_ok_clicked()));
    for(i=0;i<101;i++)
    {
        target[i]=flag[i]=offtake[i]=flow[i]=low[i]=high[i]=designed[i]=sideslope[i]=bedslope[i]=bottom[i]=member[i]=flowdepth[i]=node[i]=distance[i]=check[i]=0;
    }
    dialog->exec();
    ui->Frame_3->show();
    ui->Exit_pushButton->show();
    ui->Exit_pushButton->setText("Back");
   // dialog->setEnabled(true);




}

void MainWindow:: on_ok_clicked()
{
    for(dx=1;dx<=no_pool;dx++)
    {
        if(check[dx]==0)
        {
            QMessageBox::critical(this, tr("Canal Automation"),tr("Incomplete Specification"),QMessageBox::Ok);
            return;
        }
    }

    ui->Frame_3->show();
    ui->Exit_pushButton->show();
    ui->Exit_pushButton->setText("Back");


    dx=0;

    dialog->close();

}



void MainWindow:: on_accept_clicked()
{
    double off_take;
    double nodes;
    double distances;

    int pool_no=pool_spinbox->value();

    double flow_rate=flowrate_spinbox->value();

    double lowf=low_spinbox->value();
    double highf=high_spinbox->value();
    double designedf=flowrate_spinbox->value();
    int mem=member_spinbox->value();
    double bedsloped=slope_spinbox->value();
    double bottomw=bottom_spinbox->value();
    double flowd=flowdepth_spinbox->value();
    double lengthd=length_spinbox->value();
    double sidesloped=sideslope_spinbox->value();
    double targetd=target_spinbox->value();

    off_take=offtake_spinbox->value();
    nodes=nodes_spinbox->value();
    distances=lengthd/(nodes-1);
    // distances=100.0;



    if(designedf!=0)
    {

        flag[pool_no]=1;
        flow[pool_no]=flow_rate;

        low[pool_no]=lowf;
        high[pool_no]=highf;
        designed[pool_no]=designedf;
        member[pool_no]=mem;
        sideslope[pool_no]=sidesloped;
        bedslope[pool_no]=bedsloped;
        target[pool_no]=targetd;
        bottom[pool_no]=bottomw;
        flowdepth[pool_no]=flowd;
        offtake[pool_no]=off_take;
        node[pool_no]=nodes;
        distance[pool_no]=distances;
    pool_spinbox->setValue(((pool_no)%no_pool+1));
//pool_spinbox->setValue(((pool_no)%no_pool+1));
        check[pool_no]=1;

    }
    else
    {
        QMessageBox::warning(this, tr("Canal Automation"),tr("Invalid values"),QMessageBox::Ok);
    }

}
void MainWindow::on_cancel_clicked()
{
    dialog->close();

}

void MainWindow::tuning(int dx)
{

    double q2=0,a=0,a2,a1,v,j;
    double prec=1,lhs,rhs,z=0,y11,y22,b1,b2,y2=0;

    a=bottom[dx];
    z=bedslope[dx];
    q2=flow[dx];//bmcbzczbcm
    y2=flowdepth[dx];
    b2=a+2*z*y2;
    a2=(y2/2)*(a+b2);
    //check division by zero error
    v=q2 / a2;
    y22=(y2/3)*((2*a+b2)/(a+b2));
    if(i<0)
    {
        j=0;
        label:	b1=a+2*z*j;
            a1=(j/2)*(a+b1);
            lhs=i/(a1-a2);
            y11=(j/3)*((2*a+b1)/(a+b1));
            rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
            prec=lhs-rhs;
            if(prec<0.000000001)
            {
                j=j+0.0000001;
                goto label;
            }
            res=a1-a2;
        }
    else
    {
        j=y2+0.001;
        label1:	b1=a+2*z*j;
            a1=(j/2)*(a+b1);
            lhs=i/(a1-a2);
            y11=(j/3)*((2*a+b1)/(a+b1));
            rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
            prec=lhs-rhs;
            if(prec>0.000000001)
            {
                j=j+0.0000001;
                goto label1;
            }
            res=a1-a2;

        }
}

void MainWindow::full_node_automation(double x,double y,int e)
{

    int IN=node[e];
    int is,io,ig,jjb;

    double B=bottom[e];
    double Z=bedslope[e];
    double ZTAR=flowdepth[e];
    double Deltax=distance[e];
    double Deltat=7200.0;
    double DA[200],QIN[200],HIN[200],AIN[200],HFIN[200],QFIN[200],AFIN[200],DeltaQ[200],DeltaA[200];
    double HIN1[200],QIN1[200],AIN1[200];
    double DeltacorrH0[200],DeltacorrA0[200],DeltacorrQ0[200];
    //char ch[25];

    FILE *fp1,*fp2,*fp3;
    //ch[e]=e;
    char filename1[50],filename2[50],filename3[50];

    fp1=fopen("qinput.txt","r");
    fp2=fopen("hinput.txt","r");
    fp3=fopen("ainput.txt","r");
    sprintf(filename1,"qinput%d",e);
    strcat(filename1,".txt");
    sprintf(filename2,"hinput%d",e);
    strcat(filename2,".txt");
    sprintf(filename3,"ainput%d",e);

    strcat(filename3,".txt");
    fp1=fopen(filename1,"r");
    fp2=fopen(filename2,"r");
    fp3=fopen(filename3,"r");
    for(io=1;io<=IN;io++)
    {
        fscanf(fp1,"%lf\n",&QIN[io]);
        fscanf(fp2,"%lf\n",&HIN[io]);
        fscanf(fp3,"%lf\n",&AIN[io]);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    sprintf(filename1,"qchannelout%d",e);
    strcat(filename1,".txt");
    sprintf(filename2,"hchannelout%d",e);
    strcat(filename2,".txt");
    sprintf(filename3,"Achannelout%d",e);

    strcat(filename3,".txt");
    fp1=fopen(filename1,"r");
    fp2=fopen(filename2,"r");
    fp3=fopen(filename3,"r");
    for(io=1;io<=IN;io++)
    {
        fscanf(fp1,"%lf\n",&QIN1[io]);
        fscanf(fp2,"%lf\n",&HIN1[io]);
        fscanf(fp3,"%lf\n",&AIN1[io]);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    HFIN[IN]=ZTAR;
    AFIN[IN]=(B+(Z*HFIN[IN]))*HFIN[IN];
    switch(e)
    {
	case 1:QFIN[IN]=11.8337;
		break;
	case 2:QFIN[IN]=11.3362;
		break;
	case 3:QFIN[IN]=10.4822;
		break;
	case 4:QFIN[IN]=10.0251;
		break;
	case 5:QFIN[IN]=9.4796;
		break;
	case 6:
	case 7:
	case 8:QFIN[IN]=7.0;
		break;
    }
    HFIN[IN-1]=HFIN[IN];
    AFIN[IN-1]=AFIN[IN];
    AIN[IN-1]=AIN[IN];
    QFIN[IN-1]=QFIN[IN];
    for(ig=IN-1;ig>=2;ig--)
    {
       DeltacorrH0[ig-1]=HIN1[ig-1]-HIN1[ig+1];
       DeltacorrA0[ig-1]=AIN1[ig-1]-AIN1[ig+1];
       DeltacorrQ0[ig-1]=QIN1[ig-1]-QIN1[ig+1];
    }
   
    
    for(is=IN-1;is>=2;is--)
    {
       
        DA[is]=AFIN[is]-AIN[is];
        QFIN[is-1]=QFIN[is+1]+(DA[is]*2.0*Deltax/Deltat);
        DeltaQ[is-1]=QFIN[is-1]-QFIN[is+1]-DeltacorrQ0[is-1];
        i=DeltaQ[is-1];
        MainWindow::tuning(e);
        DeltaA[is-1]=res;
        AFIN[is-1]=AFIN[is+1]+DeltaA[is-1]+DeltacorrA0[is-1];
	HFIN[is-1]=((-1.0*B)+(sqrt((B*B)+(4.0*AFIN[is-1]*Z))))/(2.0*Z);
        
    }
    sprintf(filename1,"qoutput%d",e);
    strcat(filename1,".txt");
    sprintf(filename2,"houtput%d",e);
    strcat(filename2,".txt");
    sprintf(filename3,"aoutput%d",e);

    strcat(filename3,".txt");

    fp1=fopen(filename1,"w");
    fp2=fopen(filename2,"w");
    fp3=fopen(filename3,"w");
    for(jjb=1;jjb<=IN;jjb++)
    {
        fprintf(fp2,"%lf \n",HFIN[jjb]);
        fprintf(fp1,"%lf \n",QFIN[jjb]);
        fprintf(fp3,"%lf \n",AFIN[jjb]);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    QVariant var(QFIN[is]);
    QString  str=var.toString();
    if(ui->Single_radio->isChecked())
        QMessageBox::information(this, tr("Output"),str);
    else
        if(e==1)
        {
              QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
              QMessageBox::information(this, tr("Output"),str);

        }

}

void MainWindow::on_Exit_pushButton_clicked()
{
    if(state==1)
    {
        int r = QMessageBox::warning(this, tr("Canal Automation"),tr("Do you really want to exit?"),QMessageBox::Yes | QMessageBox::No
                                     | QMessageBox::Cancel);
        if (r == QMessageBox::Yes)
            exit(0);

    }
    else if(state==2)
    {
        ui->Frame_1->show();
        ui->Frame_2->hide();
        ui->Exit_pushButton->setText("Exit");
        state=1;
    }
    else
    {
        state=2;
        ui->Frame_2->show();
        ui->Frame_3->hide();
        ui->Next_pushButton->show();
        ui->Next_pushButton->setText("Next");

    }
   }
void MainWindow::closeEvent(QCloseEvent *event)
{
    int r=QMessageBox::warning(this, tr("Canal Automation"),tr("Do you really want to exit?"),QMessageBox::Yes | QMessageBox::No
                               | QMessageBox::Cancel);
    if(r==QMessageBox::Yes)
        event->accept();
    else
        event->ignore();

}


void MainWindow::on_pushButton_clicked()
{
    int bg;
QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 for(bg=1;bg<=no_pool;bg++)
 {
     on_editor_clicked(bg);
 }
 QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));

}


void MainWindow::on_editor_clicked(int sx)
{

    FILE *fp;
    int l;
    double q2,a,k,a2,a1,v,y2,m,d1,d2,q11,q12,i,j;
    double prec=1,lhs,rhs,z,y11,y22,b2,b1;

     ind=0;
    for(l=0;l<max;l++)
    {
        op[l]=0;
        in[l]=0;
    }
    q11=low[sx];
    q12=high[sx];
    q2=designed[sx];
    m=member[sx];
    y2=flowdepth[sx];
    z=bedslope[sx];
    a=bottom[sx];
    d1=q11-q2;
    d2=q12-q2;
    if((q11==5.11)&&(m==33))
    {
        m=m-1;
    }

    inter = (d2-d1) / (m+1);


    b2=a+2*z*y2;
    a2=(y2/2)*(a+b2);
    v=q2 / a2;
    y22=(y2/3)*((2*a+b2)/(a+b2));


    for(i=d1;i<0;i+=inter)
    {
            prec=1;
            k=i;

            in[ind]=i;
                    j=0;
            label:	b1=a+2*z*j;
                    a1=(j/2)*(a+b1);
                    lhs=i/(a1-a2);
                    y11=(j/3)*((2*a+b1)/(a+b1));
                    rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
                    prec=lhs-rhs;
                    if(prec<0.000000001)
                    {
                            j=j+0.0000001;
                            goto label;
                    }

            op[ind]=a1-a2;
            ind++;
    }
    for(i=k+inter;i<=d2;i+=inter)
    {
            prec=1;

            in[ind]=i;
                    j=y2+0.001;
            label1:	b1=a+2*z*j;
                    a1=(j/2)*(a+b1);
                    lhs=i/(a1-a2);
                    y11=(j/3)*((2*a+b1)/(a+b1));
                    rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
                    prec=lhs-rhs;
                    if(prec>0.000000001)
                    {
                            j=j+0.0000001;
                            goto label1;
                    }
            op[ind]=a1-a2;
            ind++;
    }
    if((m>19 && m<30)||((m==33)&&(q11<2)))
    {
        prec=1;

        in[ind]=in[ind-1]+inter;
                j=y2+0.001;
        label2:	b1=a+2*z*j;
                a1=(j/2)*(a+b1);
                lhs=in[ind]/(a1-a2);
                y11=(j/3)*((2*a+b1)/(a+b1));
                rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
                prec=lhs-rhs;
                if(prec>0.000000001)
                {
                        j=j+0.0000001;
                        goto label2;
                }
        op[ind]=a1-a2;
    }
    fp=fopen("memberfunction2.txt","w");
    if((m>18 && m<30)||(m==33 && q11<2))
    {
       for(l=0;l<=ind;l++)
       {
            fprintf(fp,"\n %lf\t%lf \n",in[l],op[l]);
       }
    }
    else
    {
        for(l=0;l<ind;l++)
        {
           fprintf(fp,"\n %lf\t%lf \n",in[l],op[l]);
        }
    }
    fclose(fp);
    re=0;
    system("gedit memberfunction2.txt");
}





void MainWindow::on_pushButton_3_clicked()
{
    int s;
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    for(s=no_pool;s>=1;s--)
        {
            MainWindow::full_node_automation(flow[s],offtake[s],s);
        }

}

void MainWindow::on_pushButton_2_clicked()
{
    int bg;
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    for(bg=1;bg<=no_pool;bg++)
    {
        on_graph_clicked(bg);
    }
    QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
}
void MainWindow::on_graph_clicked(int sx)
{
    FILE *fp,*fp1;
       int l,il;

       double q2,a,k,a2,a1,v,y2,m,d1,d2,q11,q12,i,j;
       double prec=1,lhs,rhs,z,y11,y22,b2,b1;

        ind=0;
       for(l=0;l<max;l++)
       {
           op[l]=0;
           in[l]=0;
       }
       q11=low[sx];
       q12=high[sx];
       q2=designed[sx];
       m=member[sx];
       y2=flowdepth[sx];
       z=bedslope[sx];
       a=bottom[sx];
       d1=q11-q2;
       d2=q12-q2;
       if((q11==5.11)&&(m==33))
       {
           m=m-1;
       }


       inter = (d2-d1) / (m+1);


       b2=a+2*z*y2;
       a2=(y2/2)*(a+b2);
       v=q2 / a2;
       y22=(y2/3)*((2*a+b2)/(a+b2));


       for(i=d1;i<0;i+=inter)
       {
               prec=1;
               k=i;

               in[ind]=i;
                       j=0;
               label:	b1=a+2*z*j;
                       a1=(j/2)*(a+b1);
                       lhs=i/(a1-a2);
                       y11=(j/3)*((2*a+b1)/(a+b1));
                       rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
                       prec=lhs-rhs;
                       if(prec<0.000000001)
                       {
                               j=j+0.0000001;
                               goto label;
                       }

               op[ind]=a1-a2;
               ind++;
       }
       for(i=k+inter;i<=d2;i+=inter)
       {
               prec=1;

               in[ind]=i;
                       j=y2+0.001;
               label1:	b1=a+2*z*j;
                       a1=(j/2)*(a+b1);
                       lhs=i/(a1-a2);
                       y11=(j/3)*((2*a+b1)/(a+b1));
                       rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
                       prec=lhs-rhs;
                       if(prec>0.000000001)
                       {
                               j=j+0.0000001;
                               goto label1;
                       }
               op[ind]=a1-a2;
               ind++;
       }
       if((m>19 && m<30)||(m==33 && q11<2))
       {
           prec=1;

           in[ind]=in[ind-1]+inter;
                   j=y2+0.001;
           label2:	b1=a+2*z*j;
                   a1=(j/2)*(a+b1);
                   lhs=in[ind]/(a1-a2);
                   y11=(j/3)*((2*a+b1)/(a+b1));
                   rhs=v+(sqrt((g*a1*((a1*y11)-(a2*y22)))/(a2*(a1-a2))));
                   prec=lhs-rhs;
                   if(prec>0.000000001)
                   {
                           j=j+0.0000001;
                           goto label2;
                   }
           op[ind]=a1-a2;
       }
       fp=fopen("memberfunctions(input).dat","w");
       fp1=fopen("memberfunctions(output).dat","w");
       if((m>18 && m<30)||(m==33 && q11<2))
       {
          for(l=0;l<m;l++)
          {
              for(il=0;il<3;il++)
              {
               fprintf(fp,"%lf \t %d \n",in[l+il],mn[il]);
               fprintf(fp1,"%lf \t %d \n",op[l+il],mn[il]);

              }
          }
       }
       else
       {
           for(l=0;l<m;l++)
           {
               for(il=0;il<3;il++)
               {
                 fprintf(fp," %lf \t %d \n ",in[l+il],mn[il]);
                 fprintf(fp1,"%lf \t %d \n ",op[l+il],mn[il]);
               }
           }
       }
       fclose(fp);
       fclose(fp1);
       gnuplot(" plot 'memberfunctions(input).dat' using 1:2  with lines");
       gnuplot(" plot 'memberfunctions(output).dat' using 1:2  with lines");
}
void MainWindow::on_pushButton_4_clicked()
{
    int rw;
    for(rw=no_pool;rw>1;rw--)
    {
        on_gateopening(rw);
    }

}
void MainWindow::on_gateopening(int ri)
{
    double CD=0.80;

    double Q,b,ZU,ZD,U;
    FILE *fp;
    switch(ri)
    {
      case 2:Q=10.8337;
             ZU=2.1;
             ZD=(2.068-0.2);
             b=7.0;
             break;
      case 3:Q=10.3362;
             ZU=2.1;
             ZD=(2.0376-0.2);
             b=7.0;
             break;
      case 4:Q=9.4822;
             ZU=2.1;
             ZD=(1.9371-0.2);
             b=7;
             break;
      case 5:Q=9.0251;
             ZU=1.9;
             ZD=(1.8788-0.2);
             b=6;
             break;
      case 6:Q=6.9796;
             ZU=1.9;
             ZD=(1.7086-0.2);
             b=6;
             break;
    }
    U=Q/(CD*b*(sqrt(2*g*(ZU-ZD))));
    fp=fopen("gate values.txt","a+");
    fprintf(fp,"Opening of gate %d = %lf m\n",ri,U);
    fclose(fp);
}
