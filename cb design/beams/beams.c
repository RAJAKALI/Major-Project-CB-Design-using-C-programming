#include<stdio.h>
#include<stdio.h>
#include <math.h>
#define PI (3.141592653589793)
void main()
{//start main
    int fck1,fy1,n1c,dropsd,snl;
	float b,fck,fy,dt,ct,mu,mulimit,mubd,pt,ast,d,n,asp,pd,efcd,mor,nob,nod,cc,sb,sd,asmin,asmax,vu,std,stl,tv,tc,asv,sv,svmax,vuc,vus,efd,pc,aspt,asmint,asmaxt,asc,aspc,asmaxc,aspd;
	printf("-------BEAMS DESIGN-----------\n");
	printf("------cross section------\n");
	printf("enter width(b):");
	scanf("%f",&b);
	printf("enter depth(d):");
	scanf("%f",&d);
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
                           printf("enter tenstion cover:\n");
                           scanf("%f",&dt);
                           printf("enter compression cover:\n");
                           scanf("%f",&ct);
                            efcd=d-dt;
                            printf("value of efcd:%f\n",efcd);
                           if(fy==250)
                           {
                           	mulimit=0.148*fck*b*(efcd*efcd);
						   }
                           else if (fy==415)
                           {
                           	mulimit=0.138*fck*b*(efcd*efcd);
						   }
						   mulimit=mulimit/1000000;
                           printf("value of multimit:%f\n",mulimit);
                           printf("---------EFFECTIVE COVER---------------\n");
                           printf("enter factored moment:\n");
                           scanf("%f",&mu);
                           if(mu<mulimit)
                           {//start singly reinforced if
                            printf("SINGLY REINFORCED BEAM\n");
                           	mubd=mu*1000000/(b*(efcd*efcd));
                           	printf("value of mubd:%f\n",mubd);
                           	printf("value of fy:%f\n",fy);
                           	printf("-----Table----\n");
                           	printf("Enter pecentage of steel according to the above fy and mubd value\n");
                           	scanf("%f",&pt);
                           	ast=(pt/100)*(b*efcd);
                           	printf("value of ast:%f\n",ast);
                           	printf("Assume bar dia(pd):");
                           	scanf("%f",&pd);
                           	n=ast/((PI/4)*(pd*pd));
                           	printf("no.of duplicate bars:%f\n",n);
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
			              asp=(PI/4)*(pd*pd)*n;
			              printf("value of asp:%f\n",asp);
			              printf("-----------MINIMUM TENSION REINFORCEMET----------\n");
			              asmin=(0.85*b*efcd)/fy;
			              printf("value of asmin:%f\n",asmin);
			              printf("-----------MAXIMUM TENSION REINFORCEMET----------\n");
			              asmax=(0.04*b*d);
			              printf("value of asmax:%f\n",asmax);
			              if(asp>asmin&&asp<asmax)
			              {
			              	printf("section is safe\n");
						  }
						  else
						  {
						  	printf("not safe\n");
						  }
			              printf("-----SPACING-----\n");
			              printf("enter no.0f bars width(for one side):");
                          scanf("%f",&nob); 
                          printf("enter no.0f bars depth(for one side):");
                          scanf("%f",&nod);
                          printf("enter clear cover:");
                          scanf("%f",&cc);
                          sb=(b-2*cc-nob*pd)/(nob-1);
                          printf("value of sb:%f\n",sb);
		                  sd=(d-2*cc-nod*pd)/(nod-1);
		                  printf("value of sd:%f\n",sd);
		                  if(sd>40&&sb>40)
						      {//start sd if
			                    printf("section is safe by spacing\n"); 
			                  }//end sd if
			               else
						      {//start sd else
			 	                    printf("minumum spacing equal or greater than 40 so,change cross section or change assumed diameter\n\n");
			                  }//end sd else
			              printf("------CALCULATING MOMENT OF RESISTANCE------\n");
			              printf("value of efcd:%f",efcd);
			              mor=0.87*fy*asp*efcd*(1-(fy*asp)/(fck*b*d));
			              mor=mor/1000000;
			              printf("value of mor:%f\n",mor);
			              if(mu<mor)
			              {
			              	printf("section is safe\n");
			              	printf("---------CHECK FOR SHEAR---------\n");
			                printf("enter factored shear:");
			                scanf("%f",&vu);
			                printf("enter stirrup diameter(DROP DOWN):\n 1 for 6\n 2 for 8 \n 3 for 10:\n");
			                scanf("%d",&dropsd);
			                switch(dropsd)
			                {//start dropsd
			                	case 1:
			                		{
			                			std=6;
			                			break;
									}
								case 2:
								{
									std=8;
									break;
								}
								case 3:
								{
									std=10;
									break;
								}
							}//end dropsd
			                printf("select no.of legs(DROP DOWN):\n 1 for 2\n 2 for 4 \n 3 for 6:\n");
			                scanf("%d",&snl);
			                switch(snl)
			                {//start snl
			                	case 1:
			                		{
			                			stl=2;
			                			break;
									}
								case 2:
								{
									stl=4;
									break;
								}
								case 3:
								{
									stl=6;
									break;
								}
							}//end snl
							printf("value of std from drop down:%f\n",std);
							printf("value of stl from drop down:%f\n",stl);
			                tv=(vu*1000)/(b*efcd);
			                printf("nominal shear stress:%f\n",tv);
			                pt=((asp)/(b*efcd))*100;
			                printf("value of pt:%f\n",pt);
			                printf("value of fck:%f\n",fck);
			                printf("------DISPLAY TABLE-----\n");
			                printf("enter shear strength of concreate from table 19:");
			                scanf("%f",&tc);
			                if(tv<tc)
			                {//start tv if
			                	asv=(PI/4)*(std*std)*stl;
			                	printf("area of sheared reinforcemt:%f\n",asv);
			                	sv=(asv*0.87*fy)/(0.4*b);
			                	printf("value of sv:%f\n",sv);
			                	printf("SPACING OF SHEARED REINFORCEMENT SHALL BE LESS THAN OR EQUALE TO sv:%f\n",sv);
			                	svmax=0.75*efcd;
			                	printf("max spacing sheared reinforment:%f\n",svmax);
			                	if(sv<=svmax)
			                	{//srart sv if
			                		printf("section is safe\n");
								}//end sv if
								else
								{
									printf("not safe\n");
								}
							}//end tv if
			                else
			                {//start tv else
			                	vuc=tc*b*efcd;
			                	printf("shear carried by cocrete:%f\n",vuc);
			                	vus=vu-vuc;
			                	printf("shear carried by stirrup:%f\n",vus);
			                	asv=(PI/4)*(std*std)*stl;
			                	printf("area of sheared reinforcemt:%f\n",asv);
			                	printf("----------spacing of stirrups--------\n");
			                	sv=(0.87*fy*asv*efcd)/(vus);
			                	printf("value of sv:%f\n",sv);
			                	printf("SPACING OF SHEARED REINFORCEMENT SHALL BE LESS THAN OR EQUALE TO sv:%f\n");
			                	svmax=0.75*efcd;
			                	printf("max spacing sheared reinforment:%f\n",svmax);
			                	if(sv<=svmax)
			                	{//srart sv if
			                		printf("section is safe\n");
								}//end sv if
								else
								{
									printf("not safe\n");
								}
							}//end tv else
						  }
						  else
						  {
						  	printf("not safe\n");
						  }
					}//end singly reinforced if
                    else
                        {//start doubly reinforced else
                          printf("DOUBLY REIFORCED BEAM\n");
                          mubd=mu*1000000/(b*(efcd*efcd));
                          printf("value of mubd:%f\n",mubd);
                          printf("value of fy:%f\n",fy);
                          efd=dt/d;
                          printf("value of duplicate efd:%f\n",efd);
                          if(efd<=0.05)
							{//start efd if
			                    efd=0.05;
	                        }//end efd if
		                  else if(efd>0.05&&efd<=0.1)
							{//start efd else if1
			                    efd=0.1;
	                        }//end efd else if1
		                  else if(efd>0.1&&efd<=0.15)
						    {//start efd else if2
			                    efd=0.15;
		                    }//end efd else if2
						   else if(efd>=0.16)
							{//start efd else if3
			                          efd=0.2;
		                    }//end efd else if3
		                    printf("value of efd:%f\n",efd);
		                    printf("-----Table----\n");
                           	printf("Enter pecentage of Tension steel according to the above fy, efd and mubd value\n");
                           	scanf("%f",&pt);
		                    printf("Enter pecentage of Compression steel according to the above fy, efd and mubd value\n");
                           	scanf("%f",&pc);
                           	ast=(pt/100)*(b*efcd);
                           	printf("value of ast:%f\n",ast);
                           	printf("Assume bar dia(pd):");
                           	scanf("%f",&pd);
                           	n=ast/((PI/4)*(pd*pd));
                           	printf("no.of duplicate bars:%f\n",n);
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
			              aspt=(PI/4)*(pd*pd)*n;
			              printf("value of aspt:%f\n",aspt);
			              printf("-----------MINIMUM TENSION REINFORCEMET----------\n");
			              asmint=(0.85*b*efcd)/fy;
			              printf("value of asmin:%f\n",asmint);
			              printf("-----------MAXIMUM TENSION REINFORCEMET----------\n");
			              asmaxt=(0.04*b*d);
			              printf("value of asmax:%f\n",asmaxt);
                          asc=(pc/100)*(b*efcd);
                          printf("value of asc:%f\n",asc);
                          printf("Assume bar dia(pd):");
                           	scanf("%f",&pd);
                           	n=asc/((PI/4)*(pd*pd));
                           	printf("no.of duplicate bars:%f\n",n);
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
			              aspc=(PI/4)*(pd*pd)*n;
			              printf("value of aspc:%f\n",aspc);
			              printf("-----------MAXIMUM Compression REINFORCEMET----------\n");
			              asmaxc=(0.04*b*d);
			              printf("value of asmaxc:%f\n",asmaxc);
			              aspd=aspt+aspc;
                          printf("Total area of steel:%f\n",aspd);
                        
						printf("-----SPACING-----\n");
			              printf("enter no.0f bars width(for one side):");
                          scanf("%f",&nob); 
                          printf("enter no.0f bars depth(for one side):");
                          scanf("%f",&nod);
                          printf("enter clear cover:");
                          scanf("%f",&cc);
                          sb=(b-2*cc-nob*pd)/(nob-1);
                          printf("value of sb:%f\n",sb);
		                  sd=(d-2*cc-nod*pd)/(nod-1);
		                  printf("value of sd:%f\n",sd);
		                  if(sd>40&&sb>40)
						      {//start sd if
			                    printf("section is safe by spacing\n"); 
			                  }//end sd if
			               else
						      {//start sd else
			 	                    printf("minumum spacing equal or greater than 40 so,change cross section or change assumed diameter\n\n");
			                  }//end sd else
			              printf("------CALCULATING MOMENT OF RESISTANCE------\n");
			              printf("value of efcd:%f",efcd);
			              mor=0.87*fy*aspd*efcd*(1-(fy*aspd)/(fck*b*d));
			              mor=mor/1000000;
			              printf("value of mor:%f\n",mor);
			              if(mu<mor)
			              {
			              	printf("section is safe\n");
			              	printf("---------CHECK FOR SHEAR---------\n");
			                printf("enter factored shear:");
			                scanf("%f",&vu);
			                printf("enter stirrup diameter(DROP DOWN):\n 1 for 6\n 2 for 8 \n 3 for 10:\n");
			                scanf("%d",&dropsd);
			                switch(dropsd)
			                {//start dropsd
			                	case 1:
			                		{
			                			std=6;
			                			break;
									}
								case 2:
								{
									std=8;
									break;
								}
								case 3:
								{
									std=10;
									break;
								}
							}//end dropsd
			                printf("select no.of legs(DROP DOWN):\n 1 for 2\n 2 for 4 \n 3 for 6:\n");
			                scanf("%d",&snl);
			                switch(snl)
			                {//start snl
			                	case 1:
			                		{
			                			stl=2;
			                			break;
									}
								case 2:
								{
									stl=4;
									break;
								}
								case 3:
								{
									stl=6;
									break;
								}
							}//end snl
							printf("value of std from drop down:%f\n",std);
							printf("value of stl from drop down:%f\n",stl);
			                tv=(vu*1000)/(b*efcd);
			                printf("nominal shear stress:%f\n",tv);
			                pt=((aspd)/(b*efcd))*100;
			                printf("value of pt:%f\n",pt);
			                printf("value of fck:%f\n",fck);
			                printf("------DISPLAY TABLE-----\n");
			                printf("enter shear strength of concreate from table 19:");
			                scanf("%f",&tc);
			                if(tv<tc)
			                {//start tv if
			                	asv=(PI/4)*(std*std)*stl;
			                	printf("area of sheared reinforcemt:%f\n",asv);
			                	sv=(asv*0.87*fy)/(0.4*b);
			                	printf("value of sv:%f\n",sv);
			                	printf("SPACING OF SHEARED REINFORCEMENT SHALL BE LESS THAN OR EQUALE TO sv:%f\n",sv);
			                	svmax=0.75*efcd;
			                	printf("max spacing sheared reinforment:%f\n",svmax);
			                	if(sv<=svmax)
			                	{//srart sv if
			                		printf("section is safe\n");
								}//end sv if
								else
								{
									printf("not safe\n");
								}
							}//end tv if
			                else
			                {//start tv else
			                	printf("value of tc:%f\tefcd:%f\tb:%f\n",tc,efcd,b);
								vuc=tc*b*efcd;
								vuc=vuc/1000;
			                	printf("shear carried by cocrete:%f\n",vuc);
			                	vus=vu-vuc;
			                	printf("shear carried by stirrup:%f\n",vus);
			                	asv=(PI/4)*(std*std)*stl;
			                	printf("area of sheared reinforcemt:%f\n",asv);
			                	printf("----------spacing of stirrups--------\n");
			                	sv=(0.87*fy*asv*efcd)/(vus);
			                	sv=sv/1000;
			                	printf("value of sv:%f\n",sv);
			                	printf("SPACING OF SHEARED REINFORCEMENT SHALL BE LESS THAN OR EQUALE TO sv:%f\n",sv);
			                	svmax=0.75*efcd;
			                	printf("max spacing sheared reinforment:%f\n",svmax);
			                	if(sv<=svmax)
			                	{//srart sv if
			                		printf("section is safe\n");
								}//end sv if
								else
								{
									printf("not safe\n");
								}
							}//end tv else
						  }
						  else
						  {
						  	printf("not safe\n");
						  }
						}//end doubly reinforced else
}//end main
