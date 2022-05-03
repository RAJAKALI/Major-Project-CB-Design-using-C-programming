#include<stdio.h>
#include <math.h>
#define PI (3.141592653589793)
int sectionsafe(float,float,float,float);
void main()
{//start main
    int fck1,fy1,n1c,dw,ag1,sr,d1,exit,ulc,cb,src,testing;
    float p,b,d,mux,muy,efc,ul,ac,as,fck,fy,n1,asp1,asp2,asp3,asp4,asp5,asmin,aspc,asmax,ad,nb,cc,nd,sd,sb,ag,ps,el,gpsfck,gps,efcd,x,y,alphan,ir;
    float ex,ey,exmin,eymin,pd,diatc,diat,plt,plt1,plt2,plt3,pltf,nob,nod,scb,scd,efcb,muxmuy,asp,mut,actp,agpsfck,smux1,smuy1,graph,mux1,muy1,puz,ppuz;
	printf("<--------------YOU ARE SELECTED RECTANGLE COLUMN------------->\n");
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
                    printf("Enter\n1 foR with width and depth\n2 for without width and depth\n:");
                    scanf("%d",&dw);
                    switch(dw)
					{//start switch bd
                            	case 1:
                            	{//start bd case1
                                   printf("enter the width:");
	                               scanf("%f",&b);
	                               printf("enter the depth:");
	                               scanf("%f",&d);
	                               break;
							    }//end bd case1
    	                        case 2:
    	                        {//start bd case2
    	                     	   printf("-------------calculating for rectangular columns-----------------\n");
					               printf("Assume width:");
				                   scanf("%f",&b);
				                   printf("assume percentage of steel:");
				                   scanf("%f",&ps);
					               ag=p/((0.4)*fck*((100-ps)/100)+(0.67*fy*(ps/100)));
    				               printf("ag value:%f\n",ag);
    				               d=ag/b;
    				               d=ceil(d);
    				               d1=d;
                                   while(d1%10!=0)
                                    {//start d1 while
                    	             d1=d1+1;
					                }//end d1 while
					               d=d1;
    				               printf("b:%f\td:%f\n",b,d);
					               break;
					           }//end bd case2	
			    	}//end switch bd
			    	printf("value of b:%f",b);
			    	printf("value of b:%f",d);
                    exmin=0.05*d;
                    eymin=0.05*b;
                    printf("-------------------cheacking slenderness ratio------------------\n");
					if(el/d<12||el/b<12)
                       {//start slender if
	                     printf("short colum\n\n");
	                     printf(" value of el/d:%f\tel/b:%f\n",el/d,el/b);
	                     printf("--------eccntricity check------------\n");
	                     ex=ul/500+d/30;
	                     printf("value of ex:%f\n",ex);
	                     ey=ul/500+b/30;
	                     printf("value of ey:%f\n",ey);
	                     printf("value of exmin:%f\n",exmin);
	                     printf("value of eymin:%f\n\n",eymin);
	                     if((ex<=exmin)&&(ey<=eymin))
					       {//start axial if
					         printf("column is axial loaded\n");
		                     printf("---------------reincefeorcemet calculation----------------\n");
		                     as=(p-0.4*fck*b*d)/((0.67*fy)-(0.4*fck));
		                     printf("area of steel rquired:%f\n",as);
		                     if(as<=0)
					           {//start as if
			                     printf("area of steel can't be zero or negitive please recheck");
			                     system("pause");
	                           }//end  as if
	                          else
	                           {//start as else
	                          	 ac=b*d-as;
  		                         asmin=0.008*b*d;
		                         asmax=0.06*b*d;
		                         printf("value of asmin:%f\n",asmin);
		                         printf("value of asmax:%f\n",asmax);
  		                         printf("area of concreate:%f\n\n",ac);
		                         printf("-------section safe cheacking for dia 12-------\n");	
		                         sectionsafe(as,12,asmin,asmax);
		                         printf("-------section safe cheacking for dia 16-------\n");	
		                         sectionsafe(as,16,asmin,asmax);
		                         printf("-------section safe cheacking for dia 20-------\n");	
		                         sectionsafe(as,20,asmin,asmax);
		                         printf("-------section safe cheacking for dia 25-------\n");	
		                         sectionsafe(as,25,asmin,asmax);
		                         printf("-------section safe cheacking for dia 32-------\n");	
		                         sectionsafe(as,32,asmin,asmax);
		                         printf("NOTE:Colums with less no.of bars are effectitve in practical conditions\n\n");
		                         printf("--------------------calculation of spacing---------------\n");
	                             printf("Assume preferred diameter from above:");
		                         scanf("%f",&ad);
	                             printf("enter no.0f bars width(for one side):");
                                 scanf("%f",&nob); 
                                 printf("enter no.0f bars depth(for one side):");
                                 scanf("%f",&nod);
                                 printf("enter clear cover:");
                                 scanf("%f",&cc);
		                         sb=(b-2*cc-nob*ad)/(nob-1);
		                         sd=(d-2*cc-nod*ad)/(nod-1);
		                         if(sd>40&&sb>40)
						           {//start sd if
			                        printf("section is safe by spacing\n"); 
			                       }//end sd if
			                     else
						           {//start sd else
			 	                    printf("minumum spacing equal or greater than 40 so,change cross section or change assumed diameter\n\n");
			                       }//end sd else
		                         printf("---------desing of lateral ties---------------\n");			 
			                     diatc=(1/4)*ad;
			                     diat=6;
			                     if(diatc>diat)
			                       {//start diatc if  
			            	       diat=diatc;
			                       }//end diatc if
			                     printf("size of lateral ties:%f\n",diat);
			                     plt1=16*ad;
			                     if(b<d)
			                       {//start plt if
			 	                    plt=b;
			                       }//end plt if
			                     else
						           {//start plt else
			 	                    plt=d;
			                       }//else plt else
			                       plt2=plt;
			                       plt3=300;
			                      if(plt1<=plt2&&plt1<=plt3)
			                        {//start pltf if
			              	          pltf=plt1;
			                        }//end pltf if
			                      else if(plt2<plt3)
						            {//start pltf nested if
			                          pltf=plt2;
			                        }//end pltf nested if
			                     else
						           {//start pltf else
			 	                     pltf=plt3;
			                       }//end pltf else
			                     printf("pitch of lateral ties:%f\n",pltf);
			                     printf("---------extra stirrup check---------------\n");
			                     printf("----------along width-------------\n");
			                     sb=(b-2*efc)/(nob-1);
			                     if(sb>75)
			                       {//start sb if
			 	                    printf("value greater than 75 so extra stirrup required\n");
			 	                    printf("------type of stirrup-----------\n");
			 	                    scb=b-2*efc;
			 	                         if(scb>48*diat)
							                {//start scb if
			 		                          printf("value greater than 48 times of dia of lateral tie so provide colsed stirrup\n");
				                            }//end scb if
				                          else
				                            {//start scb else
				 	                          printf("provide open stirrup\n");
				                            }//end scb else
			                       }//end sd if
			                     else
						           {//start sb else
			             	           printf("value is less than 75 so extra strrup not required\n");
			                       }//else sb else 
							   }//end as else
	                       }//end axial if
	                        else if((ex>exmin)&&(ey<=eymin))
							 {//start x uniaxially elseif 
		                       printf("column is uniaxially loaded in x direction\n");
		                       efcd=efc/d;
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
							   else if(efcd>0.15)
							   {//start efcd else if3
			                      efcd=0.2;
		                       }//end efcd else if3
		                       printf("value of fy:%f\n",fy);
	                    	   printf("value of d'/d:%f\n",efcd);
		                       x=mux/(fck*b*d*d);
		                       y=p/(fck*b*d);
		                       printf("Graph:\n");
		                       ///fy 250 code
		                       /*if(fy==250&&efcd==0.05)
							   {//start fy250 if1
		                          printf("use %f & %f graph\n",fy,efcd);	
							   }//end fy250 if1
							   else if(fy==250&&efcd==0.1)
							   {//start fy250 else if2
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy250 else if2
							   else if(fy==250&&efcd==0.15)
							   {//start fy250 else if3
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy250 else if3
							   else if(fy==250&&efcd==0.2)
							   {//start fy250 else if4
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy250 else if4
							   ///fy 415 code
							   else if(fy==415&&efcd==0.05)
							   {//start fy415 else if1
		                          printf("use %f & %f graph\n",fy,efcd);	
							   }//end fy415 else if1
							   else if(fy==415&&efcd==0.1)
							   {//start fy415 else if2
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy415 else if2
							   else if(fy==415&&efcd==0.15)
							   {//start fy415 else if3
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy415 else if3
							   else if(fy==415&&efcd==0.2)
							   {//start fy415 else if4
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy415 else if4*/
		                       printf("value of x:%f\t",x);
		                       printf("value of y:%f\n",y);
		                       printf("select the graph fy:%f and d'/d:%f\n",fy,efcd);
		                       printf("by using the x and y value select gps/fck value from the above graph\n");
		                       printf("enter gps/fck value:\n");
		                       scanf("%f",&gpsfck);
		                       printf("gps/fck value:%f\n",gpsfck);
	                           gps=gpsfck*fck;
	                           printf("gps value:%f\n",gps);
	                           as=(gps/100)*(b*d);
	                           printf("as value:%f\n",as);
	                           ac=b*d-as;
		                       asmin=0.008*b*d;
		                       asmax=0.06*b*d;
		                       printf("value of asmin:%f\n",asmin);
		                       printf("value of asmax:%f\n",asmax);
  		                       printf("area of concreate:%f\n\n",ac);
		                       printf("-------section safe cheacking for dia 12-------\n");	
		                       sectionsafe(as,12,asmin,asmax);
		                       printf("-------section safe cheacking for dia 16-------\n");	
		                       sectionsafe(as,16,asmin,asmax);
		                       printf("-------section safe cheacking for dia 20-------\n");	
		                       sectionsafe(as,20,asmin,asmax);
		                       printf("-------section safe cheacking for dia 25-------\n");	
		                       sectionsafe(as,25,asmin,asmax);
		                       printf("-------section safe cheacking for dia 32-------\n");	
		                       sectionsafe(as,32,asmin,asmax);
		                       printf("NOTE:Colums with less no.of bars are effectitve in practical conditions\n\n");
		                       printf("--------------------calculation of spacing---------------\n");
	                           printf("Assume preferred diameter from above:");
                               scanf("%f",&ad);
	                           printf("enter no.0f bars width(for one side):");
                               scanf("%f",&nob); 
                               printf("enter no.0f bars depth(for one side):");
                               scanf("%f",&nod);
                               printf("enter clear cover:");
                               scanf("%f",&cc);
		                       sb=(b-2*cc-nob*ad)/(nob-1);
		                       sd=(d-2*cc-nod*ad)/(nod-1);
		                       if(sd>40&&sb>40)
						           {//start sd if
			                        printf("section is safe by spacing\n"); 
			                       }//end sd if
			                   else
						           {//start sd else
			 	                    printf("minumum spacing equal or greater than 40 so,change cross section or change assumed diameter\n\n");
			                       }//end sd else
		                       printf("---------desing of lateral ties---------------\n");			 
			                   diatc=(1/4)*ad;
			                   diat=6;
			                   if(diatc>diat)
			                     {//start diatc if  
		                	       diat=diatc;
			                     }//end diatc if
			                    printf("size of lateral ties:%f\n",diat);
			                    plt1=16*ad;
			                    if(b<d)
			                       {//start plt if
			 	                    plt=b;
			                       }//end plt if
			                    else
						           {//start plt else
			 	                    plt=d;
			                       }//else plt else
			                    plt2=plt;
			                    plt3=300;
			                    if(plt1<=plt2&&plt1<=plt3)
			                        {//start pltf if
			              	          pltf=plt1;
			                        }//end pltf if
			                    else if(plt2<plt3)
						            {//start pltf nested if
			                          pltf=plt2;
			                        }//end pltf nested if
			                    else
						           {//start pltf else
			 	                     pltf=plt3;
			                       }//end pltf else
			                    printf("pitch of lateral ties:%f\n",pltf);
			                    printf("---------extra stirrup check---------------\n");
			                    printf("----------along width-------------\n");
			                    sb=(b-2*efc)/(nob-1);
			                    if(sb>75)
			                       {//start sb if
			 	                    printf("value greater than 75 so extra stirrup required\n");
			 	                    printf("------type of stirrup-----------\n");
			 	                    scb=b-2*efc;
			 	                         if(scb>48*diat)
							                {//start scb if
			 		                          printf("value greater than 48 times of dia of lateral tie so provide colsed stirrup\n");
				                            }//end scb if
				                          else
				                            {//start scb else
				 	                          printf("provide open stirrup\n");
				                            }//end scb else
			                       }//end sd if
			                    else
						           {//start sb else
			             	           printf("value is less than 75 so extra strrup not required\n");
			                       }//end sb else 
		                     }//end x uniaxially elseif
		                    else if((ex<=exmin)&&(ey>=eymin))
							 {//start y uniaxially else if
		                       printf("column is uniaxially loaded in y direction\n");
		                       efcd=efc/d;
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
							   else if(efcd>0.15)
							   {//start efcd else if3
			                      efcd=0.2;
		                       }//end efcd else if3
		                       printf("value of fy:%f\n",fy);
	                    	   printf("value of d'/d:%f\n",efcd);
		                       x=muy/(fck*b*d*d);
		                       y=p/(fck*b*d);
		                       printf("Graph:\n");
		                       ///fy 250 code
		                       /*if(fy==250&&efcd==0.05)
							   {//start fy250 if1
		                          printf("use %f & %f graph\n",fy,efcd);	
							   }//end fy250 if1
							   else if(fy==250&&efcd==0.1)
							   {//start fy250 else if2
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy250 else if2
							   else if(fy==250&&efcd==0.15)
							   {//start fy250 else if3
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy250 else if3
							   else if(fy==250&&efcd==0.2)
							   {//start fy250 else if4
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy250 else if4
							   ///fy 415 code
							   else if(fy==415&&efcd==0.05)
							   {//start fy415 else if1
		                          printf("use %f & %f graph\n",fy,efcd);	
							   }//end fy415 else if1
							   else if(fy==415&&efcd==0.1)
							   {//start fy415 else if2
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy415 else if2
							   else if(fy==415&&efcd==0.15)
							   {//start fy415 else if3
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy415 else if3
							   else if(fy==415&&efcd==0.2)
							   {//start fy415 else if4
							   	  printf("use %f & %f graph\n",fy,efcd); 
							   }//end fy415 else if4*/
		                       printf("value of x:%f\t",x);
		                       printf("value of y:%f\n",y);
		                       printf("select the graph fy:%f and d'/d:%f\n",fy,efcd);
		                       printf("by using the x and y value select gps/fck value from the above graph\n");
		                       printf("enter gps/fck value:\n");
		                       scanf("%f",&gpsfck);
		                       printf("gps/fck value:%f\n",gpsfck);
	                           gps=gpsfck*fck;
	                           printf("gps value:%f\n",gps);
	                           as=(gps/100)*(b*d);
	                           printf("as value:%f\n",as);
	                           ac=b*d-as;
		                       asmin=0.008*b*d;
		                       asmax=0.06*b*d;
		                       printf("value of asmin:%f\n",asmin);
		                       printf("value of asmax:%f\n",asmax);
  		                       printf("area of concreate:%f\n\n",ac);
		                       printf("-------section safe cheacking for dia 12-------\n");	
		                       sectionsafe(as,12,asmin,asmax);
		                       printf("-------section safe cheacking for dia 16-------\n");	
		                       sectionsafe(as,16,asmin,asmax);
		                       printf("-------section safe cheacking for dia 20-------\n");	
		                       sectionsafe(as,20,asmin,asmax);
		                       printf("-------section safe cheacking for dia 25-------\n");	
		                       sectionsafe(as,25,asmin,asmax);
		                       printf("-------section safe cheacking for dia 32-------\n");	
		                       sectionsafe(as,32,asmin,asmax);
		                       printf("NOTE:Colums with less no.of bars are effectitve in practical conditions\n\n");
		                       printf("--------------------calculation of spacing---------------\n");
	                           printf("Assume preferred diameter from above:");
                               scanf("%f",&ad);
	                           printf("enter no.0f bars width(for one side):");
                               scanf("%f",&nob); 
                               printf("enter no.0f bars depth(for one side):");
                               scanf("%f",&nod);
                               printf("enter clear cover:");
                               scanf("%f",&cc);
		                       sb=(b-2*cc-nob*ad)/(nob-1);
		                       sd=(d-2*cc-nod*ad)/(nod-1);
		                       if(sd>40&&sb>40)
						           {//start sd if
			                        printf("section is safe by spacing\n"); 
			                       }//end sd if
			                   else
						           {//start sd else
			 	                    printf("minumum spacing equal or greater than 40 so,change cross section or change assumed diameter\n\n");
			                       }//end sd else
		                       printf("---------desing of lateral ties---------------\n");			 
			                   diatc=(1/4)*ad;
			                   diat=6;
			                   if(diatc>diat)
			                     {//start diatc if  
		                	       diat=diatc;
			                     }//end diatc if
			                    printf("size of lateral ties:%f\n",diat);
			                    plt1=16*ad;
			                    if(b<d)
			                       {//start plt if
			 	                    plt=b;
			                       }//end plt if
			                    else
						           {//start plt else
			 	                    plt=d;
			                       }//else plt else
			                    plt2=plt;
			                    plt3=300;
			                    if(plt1<=plt2&&plt1<=plt3)
			                        {//start pltf if
			              	          pltf=plt1;
			                        }//end pltf if
			                    else if(plt2<plt3)
						            {//start pltf nested if
			                          pltf=plt2;
			                        }//end pltf nested if
			                    else
						           {//start pltf else
			 	                     pltf=plt3;
			                       }//end pltf else
			                    printf("pitch of lateral ties:%f\n",pltf);
			                    printf("---------extra stirrup check---------------\n");
			                    printf("----------along width-------------\n");
			                    sb=(b-2*efc)/(nob-1);
			                    if(sb>75)
			                       {//start sb if
			 	                    printf("value greater than 75 so extra stirrup required\n");
			 	                    printf("------type of stirrup-----------\n");
			 	                    scb=b-2*efc;
			 	                         if(scb>48*diat)
							                {//start scb if
			 		                          printf("value greater than 48 times of dia of lateral tie so provide colsed stirrup\n");
				                            }//end scb if
				                          else
				                            {//start scb else
				 	                          printf("provide open stirrup\n");
				                            }//end scb else
			                       }//end sd if
			                    else
						           {//start sb else
			             	           printf("value is less than 75 so extra strrup not required\n");
			                       }//end sb else
		                     }//end y uniaxially else if
	                        else if ((ex>exmin)&&(ey>eymin))
				                {//start biaxially elseif
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
		                          efcb=efc/b;
		                           printf("value of efcb:%f\n",efcb);
		                          if(efcb<=0.05)
							        {//start efcb if
			                          efcb=0.05;
	                                }//end efcb if
		                          else if(efcb>0.05&&efcb<=0.1)
							        {//start efcb else if1
			                         efcb=0.1;
	                                }//end efcb else if1
		                          else if(efcb>0.1&&efcb<=0.15)
							       {//start efcb else if2
			                        efcb=0.15;
		                           }//end efcb else if2
							      else if(efcb>=0.16)
							        {//start efcb else if3
			                          efcb=0.2;
		                            }//end efcb else if3
		                           printf("value of fy:%f\n",fy);
	                    	      printf("value of d'/d:%f\n",efcd);
	                    	      printf("value of d'/b:%f\n",efcb);
	                    	      mux=mux/1000000;
	                    	      muy=muy/1000000;
	                    	      muxmuy=(mux*mux)+(muy*muy);
	                    	      printf("value of muxmuy:%f\n",muxmuy);
	                    	      muxmuy=sqrt(muxmuy);
		                          mut=1.15*muxmuy;
		                          printf("value of mut:%f\n",mut);
		                          x=mut*1000000/(fck*b*(d*d));
		                          printf("value of x:%f\t",x);
								  y=p/(fck*b*d);
								  printf("value of y:%f\n",y);
								  printf("select below Graph\n");
		                        printf("value of fy:%f and d'/d':%f and d'/b:%f\n",fy,efcd,efcb);
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
	                           as=(gps/100)*(b*d);
	                           printf("as value:%f\n",as);
	                           ac=b*d-as;
		                       asmin=0.008*b*d;
		                       asmax=0.06*b*d;
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
							   ///
	                           printf("enter no.0f bars width(for one side):");
                               scanf("%f",&nob); 
                               printf("enter no.0f bars depth(for one side):");
                               scanf("%f",&nod);
                               printf("enter clear cover:");
                               scanf("%f",&cc);
		                       sb=(b-2*cc-nob*ad)/(nob-1);
		                       sd=(d-2*cc-nod*ad)/(nod-1);
		                       if(sd>40&&sb>40)
						           {//start sd if
						            printf("value of asp:%f\n",asp);
			                        printf("section is safe by spacing\n"); 
			                        actp=(asp/(b*d))*100;
			                        printf("actual percentage of steel:%f\n",actp);
			                        agpsfck=actp/fck;
			                        printf("actual gps/fck value:%f\n",agpsfck);
			                        printf("value of y:%f\n",y);
			                        printf("value of efcd:%f\n",efcd);
			                        printf("value of efcb:%f\n",efcb);
			                        printf("value of fy:%f and d'/d':%f and d'/b:%f\n",fy,efcd,efcb);
			                        printf("enter the mux1/fck*b*(d*d) from graph d'/d:");
			                        scanf("%f",&smux1);
			                        printf("enter the mux1/fck*(b*b)*d from graph d'/b:");
			                        scanf("%f",&smuy1);
			                        mux1=smux1*fck*b*d*d;
			                        mux1=mux1/1000000;
			                        muy1=smuy1*fck*b*b*d;
			                        muy1=muy1/1000000;
			                        printf("value of mux1:%f\n",mux1);
			                        printf("value of muy1:%f\n",muy1);
			                        printf("value of asp:%f\n",asp);
			                        puz=((0.45*fck*ac)+(0.75*fy*asp));
			                        
			                        printf("value of Puz:%f\n",puz);
			                        ppuz=p/puz;
			                        printf("value of p/puz:%f\n",ppuz);
			                        if(ppuz<0.2)
			                        {//start ppuz if
			                        	alphan=1;
			                        	printf("value of alphan:%f\n",alphan);
									}//end ppuz if
									else if (ppuz>0.8)
									{//start ppuz else if1
										alphan=2;
										printf("value of alphan:%f\n",alphan);
									}//end ppuz else if1
			                        else if(ppuz>=0.2&&ppuz<=0.8)
			                        {//start ppuz else if2
			                        	alphan=1+((ppuz-0.2)/0.6);
			                        	printf("value of alphan:%f\n",alphan);
									}//end ppuz else if2
			                        printf("--------cheacking interaction fromula--------\n");
			                        ir=(pow(mux/mux1,alphan)+pow(muy/muy1,alphan));
			                        printf("value of ir:%f\n",ir);
			                        if(ir<1)
			                        {//start ir if
			                    printf("section is safe by interaction ratio\n");
			                    printf("---------desing of lateral ties---------------\n");			 
			                    diatc=(1/4)*ad;
			                    diat=6;
			                    if(diatc>diat)
			                     {//start diatc if  
		                	       diat=diatc;
			                     }//end diatc if
			                    printf("size of lateral ties:%f\n",diat);
			                    plt1=16*ad;
			                    if(b<d)
			                       {//start plt if
			 	                    plt=b;
			                       }//end plt if
			                    else
						           {//start plt else
			 	                    plt=d;
			                       }//else plt else
			                    plt2=plt;
			                    plt3=300;
			                    if(plt1<=plt2&&plt1<=plt3)
			                        {//start pltf if
			              	          pltf=plt1;
			                        }//end pltf if
			                    else if(plt2<plt3)
						            {//start pltf nested if
			                          pltf=plt2;
			                        }//end pltf nested if
			                    else
						           {//start pltf else
			 	                     pltf=plt3;
			                       }//end pltf else
			                    printf("pitch of lateral ties:%f\n",pltf);
			                    printf("---------extra stirrup check---------------\n");
			                    printf("----------along width-------------\n");
			                    sb=(b-2*efc)/(nob-1);
			                    printf("value of spacing along width:%f\n",sb);
			                    if(sb>75)
			                       {//start sb if
			 	                    printf("value greater than 75 so extra stirrup required\n");
			 	                    printf("------type of stirrup-----------\n");
			 	                    scb=b-2*efc;
			 	                    printf("value of scb:%f\n",scb);
			 	                         if(scb>48*diat)
							                {//start scb if
			 		                          printf("value greater than 48 times of dia of lateral tie so provide colsed stirrup\n");
				                            }//end scb if
				                          else
				                            {//start scb else
				 	                          printf("provide open stirrup\n");
				                            }//end scb else
			                       }//end sd if
			                    else
						           {//start sb else
			             	           printf("value is less than 75 so extra strrup not required\n");
			                       }//end sb else
									}//end ir if
									else
									{//start ir else
										printf("section is not safe\n");
									}//else ir else
			                       }//end sd if
			                   else
						           {//start sd else
			 	                    printf("minumum spacing equal or greater than 40 so,change cross section or change assumed diameter\n\n");
			                       }//end sd else								  	
				                }//end biaxially elseif
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
			if(n<=4)
			{
				printf("min no.of bars in square/rectangular columns are 4 so this is not safe\n");
			}else
			{
				printf("min no.of bars in square/rectangular colums are >4 so this is safe\n");
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
