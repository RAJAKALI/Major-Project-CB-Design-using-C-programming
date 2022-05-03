#include<stdio.h>
#include<stdio.h>
#include <math.h>
#define PI (3.141592653589793)
int sectionsafe(float,float,float,float);
void main()
{//start main
    int fck1,fy1,n1c,dw,ag1,sr,d1,exit,ulc,cb,src,testing;
    float p,b,d,mux,muy,efc,ul,ac,as,fck,fy,n1,asp1,asp2,asp3,asp4,asp5,asmin,aspc,asmax,ad,nb,cc,nd,sd,pu,sb,ag,ps,el,gpsfck,gps,efcd,x,y,mut,graph,asp,actp,agpsfck,smux1,mux1,muy1,puz;
    float ex,ey,exmin,eymin,pd,diatc,diat,plt,plt1,plt2,plt3,pltf,nob,nod,scb,scd,ppuz,alphan,ir,muxmuy,e,emin,cd,cdmax,ptmin,pitch,vc,vuvus,acc,arc,rhr,vu,vus,vusr;
	printf("<--------------YOU ARE SELECTED CIRCULAR COLUMN------------->\n");
    				printf("enter the factored load:");
	                scanf("%f",&p);
                    p=p*10*10*10;
	                printf("enter fck\nenter 1 for 20\nenter 2 for 25\n:");
	                scanf("%d",&fck1);
	                switch (fck1)
							 {//start switch fck
                                    case 1:
                                    	{
										
                                            fck=20;
                                            break;
                                        }
                                    case 2:
                                    	{
										
    	                                    fck=25;
                                            break;
                                        }
                                    default:
                                    	{
    	                                    printf("enter valid input");
    	                                    break;
    	                                }
                             }//end switch fck
	                 printf("Enter fy\nenter 1 for 250\nenter 2 for 415\n:");
	                scanf("%d",&fy1);
                            switch (fy1)
							{//start switch fy
                                    case 1:
                                    	{
                                            fy=250;
                                            break;
                                        }
                                    case 2:
                                    	{
    	                                    fy=415;
                                            break;
                                        }
                                   default:
                                     	{
									   
                                        	printf("enter valid input");
                                        }
                           }//end switch fy
                     printf("enter moment x direction(mux):");
                    scanf("%f",&mux);
                    mux=mux*1000000;
                    printf("enter moment y direction(muy):");
                    scanf("%f",&muy);
                    muy=muy*1000000;
                    printf("enter effective cover:(d'):");
                    scanf("%f",&efc);
                    printf("enter unsupported lenght:");
                    scanf("%f",&ul);
                    printf("choose:\n 1.against rotation in both ends\n2.against rotaion at one end\n3.not restrained against rotation\n4.held in posion\n5.partially restraied\n6.not held in position\n7.nor restrained\n");
                    scanf("%d",&ulc);
		                        	switch(ulc)
									{//start switch ulc
			                                    case 1:
												{
			                                        	el=0.65*ul;
				                                        break;
		                                        }
			                                    case 2:
												{
				                                        el=0.8*ul;
			                                        	break;
		                                        }
			                                    case 3:
												{
			                                        	el=1*ul;
				                                        break;
			                                    }
                                                case 4:
												{
				                                        el=1.2*ul;
				                                        break;
			                                    }	
			                                    case 5:
												{
				                                        el=1.5*ul;
				                                        break;
			                                    }		
			                                    case 6:
												{
				                                        el=2*ul;
			                                        	break;
			                                    }
		                                    	case 7:
												{
				                                        el=2*ul;
				                                        break;
			                                    }
		                            }//end switch ulc
                    printf("Enter\n1 foR with diameter\n2 for without diameter\n:");
                    scanf("%d",&dw);
                    switch(dw)
					{//start switch bd
                            	case 1:
                            	{
                                   printf("enter the Diameter:");
	                               scanf("%f",&d);
	                               ag=(PI/4)*d*d;
	                               printf("ag value:%f\n",ag);
	                               break;
							   }
    	                        case 2:
    	                        {
    	                     	   printf("Assume percentage of steel:");
    		                       scanf("%f",&ps);
    				               ag=p/((0.42)*fck*((100-ps)/100)+(0.7035*fy*(ps/100)));
    				               printf("ag value:%f\n",ag);
    				               d=(ag*4)/PI;
    				               d=sqrt(d);
    				               d=ceil(d);
    				               d1=d;
    				               while(d1%10!=0)
								   {
    					                         d1=d1+1;
					               }
					              d=d1;
					              printf("diameter of column(d):%f\n",d);
				                  break;
				               }
			    	}//end switch bd
                    emin=0.05*d;
                    printf("-------------------cheacking slenderness ratio------------------\n");
					if(el/d<12)
                       {//start slender if
	                     printf("short colum\n\n");
	                     printf(" value of el/d:%f\n",el/d);
	                     printf("--------eccntricity check------------\n");
	                     e=ul/500+d/30;
	                     printf("value of e:%f\n",e);
	                     printf("value of emin:%f\n",emin);
	                     if(e<=emin)
					       {//start axial if
					         printf("column is axial loaded\n");
		                     printf("---------------reincefeorcemet calculation----------------\n");
		                     as=(p-0.42*fck*ag)/((0.7035*fy)-(0.42*fck));
		                     
		                     printf("area of steel rquired:%f\n",as);
		                     if(as<=0)
					           {//start as if
			                     printf("area of steel can't be zero or negitive please recheck");
			                     system("pause");
	                           }//end  as if
	                          else
	                           {//start as else
	                          	 ac=ag-as;
  		                         asmin=0.008*ag;
		                         asmax=0.04*ag;
		                         printf("value of asmin:%f\n",asmin);
		                         printf("value of asmax:%f\n",asmax);
  		                         printf("area of concreate:%f\n\n",ac);
		                         printf("-------section safe cheacking for dia 12-------\n");	
		                         asp1=sectionsafe(as,12,asmin,asmax);
		                         printf("-------section safe cheacking for dia 16-------\n");	
		                         asp2=sectionsafe(as,16,asmin,asmax);
		                         printf("-------section safe cheacking for dia 20-------\n");	
		                         asp3=sectionsafe(as,20,asmin,asmax);
		                         printf("-------section safe cheacking for dia 25-------\n");	
		                         asp4=sectionsafe(as,25,asmin,asmax);
		                         printf("-------section safe cheacking for dia 32-------\n");	
		                         asp5=sectionsafe(as,32,asmin,asmax);
		                         printf("NOTE:Colums with less no.of bars are effectitve in practical conditions\n\n");
		                          printf("Assume preferred diameter from above:");
                               scanf("%f",&ad);
                               if(ad==12)
                               {//start ad if1
                               	asp=asp1;
							   }//end ad if1
                               else if(ad==16)
                               {//start ad if2
                               	asp=asp2;
							   }//end ad if2
							   else if(ad==20)
                               {//start ad if3
                               	asp=asp3;
							   }//end ad if3
							   else if(ad==25)
                               {//start ad if4
                               	asp=asp4;
							   }//end ad if4
							   else if(ad==32)
                               {//start ad if5
                               	asp=asp5;
							   }//end ad if5
							   printf("value of asp after cal:%f\n",asp);
		                         printf("---------desing of helical reinforcement---------------\n");			 
			                     diatc=(1/4)*ad;
			                     diat=6;
			                     if(diatc>diat)
			                       {//start diatc if  
			            	       diat=diatc;
			                       }//end diatc if
			                     printf("size of lateral ties:%f\n",diat);
			                     printf("---------Pitch of helical reinforcement---------------\n");
			                     printf("Assume clear cover:");
			                     scanf("%f",&cc);
			                     cd=d-(2*cc);
			                     cdmax=cd/6;
			                     printf("pitch max values 75 and cdmax:%f\n",cdmax);
			                     ptmin=3*diat;
			                     printf("pitch min values 25 and ptmin:%f\n",ptmin);
			                     printf("select pitch of helical reinforcement between minimum and maxiamum values from above\n");
			                     scanf("%f",&pitch);
			                     printf("value of cd:%f\n",cd);
			                     acc=(PI/4)*(cd*cd);
			                     printf("value of acc:%f\n",acc);
			                     arc=acc-asp;
			                     printf("value of arc:%f\n",arc);
			                     vc=arc*pitch;
			                     printf("value of volume of core per pitch height:%f\n",vc);
			                     vu=PI*(cd-diat);
			                     printf("value of vu:%f\n",vu);
			                     vus=(PI/4)*(diat*diat)*vu;
			                     printf("volume of one helical reinforcement:%f\n",vus);
			                     printf("value of ag:%f\n",ag);
			                     rhr=0.36*((ag/arc)-1)*(fck/fy);
			                     printf("value of rhr:%f\n",rhr);
			                     vusr=vus/vc;
			                     printf("value of vusr:%f\n",vusr);
			                     if(vusr>rhr)
			                     {
			                     	printf("section is safe\n");
								 }
								 else 
								 {
								 	printf("not safe\n");
								 }
							   }//end as else
	                       }//end axial if
	                     else if (e>emin)
				                {//start biaxially if
		                          printf("column is biaxially loaded\n");
		                          efcd=efc/d;
		                          printf("value of efcd:%f\n",efcd);
		                          if(efcd<=0.05)
							        {//start efcd if
			                          efcd=0.05;
	                                }//end efcd if
		                          else if(efcd>0.05&&efcd<=0.1)
							        {//start efcd else if1
			                         efcd=0.1;
	                                }//end efcd else if1
		                          else if(efcd>0.1&&efcd<=0.15)
							       {//start efcd else if2
			                        efcd=0.15;
		                           }//end efcd else if2
							      else if(efcd>=0.16)
							        {//start efcd else if3
			                          efcd=0.2;
		                            }//end efcd else if3
		                           printf("value of fy:%f\n",fy);
	                    	      printf("value of d'/d:%f\n",efcd);
	                    	      mux=mux/1000000;
	                    	      muy=muy/1000000;
	                    	      muxmuy=(mux*mux)+(muy*muy);
	                    	      printf("value of muxmuy:%f\n",muxmuy);
	                    	      muxmuy=sqrt(muxmuy);
		                          mut=1.15*muxmuy;
		                          printf("value of mut:%f\n",mut);
		                          x=mut*1000000/(fck*(d*d*d));
		                          printf("value of x:%f\t",x);
								  y=p/(fck*(d*d));
								  printf("value of y:%f\n",y);
								  printf("select below Graph\n");
		                        printf("value of fy:%f and d'/d':%f\n",fy,efcd);
		                       /*if((fy==250)&&(efcd==0.05))
							   {//start fy250 if1
							      graph=1;
		                          printf("use %f & %f graph:%f\n",fy,efcd,graph);
							   }//end fy250 if1
							   else if((fy==250)&&(efcd==0.1))
							   {//start fy250 else if2
							      graph=2;
							   	  printf("use %f & %f graph:%f\n",fy,efcd,graph); 
							   }//end fy250 else if2
							   else if((fy==250)&&(efcd==0.15))
							   {//start fy250 else if3
							      graph=3;
							   	  printf("use %f & %f graph:%f\n",fy,efcd,graph); 
							   }//end fy250 else if3
							   else if((fy==250)&&(efcd==0.2))
							   {//start fy250 else if4
							      graph=4;
							   	  printf("use %f & %f graph:%f\n",fy,efcd,graph); 
							   }//end fy250 else if4
							   ///fy 415 code
							   else if((fy==415)&&(efcd==0.05))
							   {//start fy415 else if1
							      graph=5;
		                          printf("use %f & %f graph:%f\n",fy,efcd,graph);	
							   }//end fy415 else if1
							   else if((fy==415)&&(efcd==0.1))
							   {//start fy415 else if2
							      graph=6;
							   	  printf("use %f & %f graph:%f\n",fy,efcd,graph); 
							   }//end fy415 else if2
							   else if((fy==415)&&(efcd==0.15))
							   {//start fy415 else if3
							      graph=7;
							      printf("graph7\n");
							   	  printf("use %f & %f graph:%f\n",fy,efcd,graph); 
							   }//end fy415 else if3
							   else if((fy==415)&&(efcd==0.2))
							   {//start fy415 else if4
							      graph=8;
							   	  printf("use %f & %f graph:%f\n",fy,efcd,graph); 
							   }//end fy415 else if4*/
							   
							   printf("by using the x and y value select gps/fck value from the above graph\n");
		                       printf("enter gps/fck value:\n");
		                       scanf("%f",&gpsfck);
		                       printf("gps/fck value:%f\n",gpsfck);
	                           gps=gpsfck*fck;
	                           printf("gps value:%f\n",gps);
	                           as=(gps/100)*(PI/4)*(d*d);
	                           printf("as value:%f\n",as);
	                           ac=ag-as;
		                       asmin=0.008*ag;
		                       asmax=0.04*ag;
		                       printf("value of asmin:%f\n",asmin);
		                       printf("value of asmax:%f\n",asmax);
  		                       printf("area of concreate:%f\n\n",ac);
		                       printf("-------section safe cheacking for dia 12-------\n");	
		                       asp1=sectionsafe(as,12,asmin,asmax);
		                       printf("-------section safe cheacking for dia 16-------\n");	
		                       asp2=sectionsafe(as,16,asmin,asmax);
		                       printf("-------section safe cheacking for dia 20-------\n");	
		                       asp3=sectionsafe(as,20,asmin,asmax);
		                       printf("-------section safe cheacking for dia 25-------\n");	
		                       asp4=sectionsafe(as,25,asmin,asmax);
		                       printf("-------section safe cheacking for dia 32-------\n");	
		                       asp5=sectionsafe(as,32,asmin,asmax);
		                       printf("NOTE:Colums with less no.of bars are effectitve in practical conditions\n\n");
							   printf("Assume preferred diameter from above:");
                               scanf("%f",&ad);
                               if(ad==12)
                               {//start ad if1
                               	asp=asp1;
							   }//end ad if1
                               else if(ad==16)
                               {//start ad if2
                               	asp=asp2;
							   }//end ad if2
							   else if(ad==20)
                               {//start ad if3
                               	asp=asp3;
							   }//end ad if3
							   else if(ad==25)
                               {//start ad if4
                               	asp=asp4;
							   }//end ad if4
							   else if(ad==32)
                               {//start ad if5
                               	asp=asp5;
							   }//end ad if5
							   printf("value of asp after cal:%f\n",asp);
		                         printf("---------desing of helical reinforcement---------------\n");			 
			                     diatc=(1/4)*ad;
			                     diat=6;
			                     if(diatc>diat)
			                       {//start diatc if  
			            	       diat=diatc;
			                       }//end diatc if
			                     printf("size of lateral ties:%f\n",diat);
			                     printf("---------Pitch of helical reinforcement---------------\n");
			                     printf("Assume clear cover:");
			                     scanf("%f",&cc);
			                     cd=d-(2*cc);
			                     cdmax=cd/6;
			                     printf("pitch max values 75 and cdmax:%f\n",cdmax);
			                     ptmin=3*diat;
			                     printf("pitch min values 25 and ptmin:%f\n",ptmin);
			                     printf("select pitch of helical reinforcement between minimum and maxiamum values from above\n");
			                     scanf("%f",&pitch);
			                     printf("value of cd:%f\n",cd);
			                     acc=(PI/4)*(cd*cd);
			                     printf("value of acc:%f\n",acc);
			                     arc=acc-asp;
			                     printf("value of arc:%f\n",arc);
			                     vc=arc*pitch;
			                     printf("value of volume of core per pitch height:%f\n",vc);
			                     vu=PI*(cd-diat);
			                     printf("value of vu:%f\n",vu);
			                     vus=(PI/4)*(diat*diat)*vu;
			                     printf("volume of one helical reinforcement:%f\n",vus);
			                     printf("value of ag:%f\n",ag);
			                     rhr=0.36*((ag/arc)-1)*(fck/fy);
			                     printf("value of rhr:%f\n",rhr);
			                     vusr=vus/vc;
			                     printf("value of vusr:%f\n",vusr);
			                     if(vusr>rhr)
			                     {
			                     	printf("section is safe\n");
								 }
								 else 
								 {
								 	printf("not safe\n");
								 }
				                }//end biaxially if
	                   }//end slender if
			        else
                       {//start slender else
             	        printf("ration is > 12 hence it is long colum\n");
			           }//end slender else				 
}//end main
int sectionsafe(float as,float dia,float asmin,float asmax){
	float n,aspc;
	int n1c;
	n=(as)/((PI/4)*(dia*dia));
	printf("no.of bars duplicate:%f\n",n);
  		n= ceil(n);
  		n1c=n;
  			if(n1c%2!=0)
  			{
  			n1c=n1c+1;	
			}
			else
			{
				n1c=n1c;
			}
			n=n1c;
			printf("no.of bars:%f\n",n);
			if(n<6)
			{
				printf("min no.of bars in square/rectangular columns are 6 so this is not safe\n");
			}else
			{
				printf("min no.of bars in square/rectangular colums are >=6 so this is safe\n");
			}
			aspc=(PI/4)*(dia*dia*n);
			printf("value of asp:%f\n",aspc);
			if(aspc>=asmin&&aspc<=asmax){
  		printf("section is safe by gross area\n\n");	
		}else{
			
			printf("section is not safe by gross area\n\n");
		}
		return aspc;
}
