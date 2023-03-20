#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <dos.h> //for delay
#include <conio.h> //for getch()

# define MAX 645
using namespace std;
//Node *Inorder(Node * temp);
int n1=0; //int [] arr;
class Node{
	public:
		Node* left; 
		Node* right;
		
		int id,year, agencies, population, total_male, total_female;

		int m_18, m_19, m_20, m_21, m_22, m_23, m_24, m_25_29;
		int m_30_34, m_35_39, m_40_44, m_45_49, m_50_54, m_55_59;
		int m_60_64, m_65;
	
		int f_18, f_19, f_20, f_21, f_22, f_23, f_24, f_25_29;
		int f_30_34, f_35_39, f_40_44, f_45_49, f_50_54, f_55_59;
		int f_60_64, f_65;  
   
		int f_18_24, m_18_24;
	
		int race_agencies, race_pop, white, black, asian, american_indian;
		string offense_code, offense_name;

		Node()
		{
		
			left = right = NULL;
			m_18= m_19= m_20= m_21= m_22= m_23= m_24= m_25_29 = 0;
			m_30_34= m_35_39= m_40_44= m_45_49= m_50_54= m_55_59 = 0;
			m_60_64= m_65 = 0;
	
			f_18= f_19= f_20= f_21= f_22= f_23= f_24= f_25_29 = 0;
			f_30_34= f_35_39= f_40_44= f_45_49= f_50_54= f_55_59 = 0;
			f_60_64= f_65 = 0;  
   
			f_18_24= m_18_24 = 0;
	
			race_agencies= race_pop= white= black= asian= american_indian = 0;
			id= year = agencies= population= total_male= total_female=0;
			offense_code= offense_name= "";			
	
		}
		Node(int ii, int yy, string oc, string on, int ag, int pop, int tm, int tf, int m18, int m19, int m20, int m21, int m22, int m23, int m24, int m2529, int m3034, int m3539, int m4044, int m4549, int m5054, int m5559, int m6064, int m65, int f18, int f19, int f20, int f21, int f22, int f23, int f24, int f2529, int f3034, int f3539, int f4044, int f4549, int f5054, int f5559, int f6064, int f65, int ra, int rp, int w, int b, int ap, int ai)
		{
			id=ii;
			year=yy;
			offense_code=oc;
			offense_name=on,
			agencies=ag;
			population=pop;
			total_male=tm;
			total_female=tf;
			m_18=m18;
			m_19=m19;
			m_20=m20;
			m_21=m21;
			m_22=m22;
			m_23=m23;
			m_24=m24;
			m_25_29= m2529;
			m_30_34= m3034;
			m_35_39= m3539;
			m_40_44= m4044;
			m_45_49= m4549;
			m_50_54= m5054;
			m_55_59 =m5559;
			m_60_64= m6064;
			m_65 = m65;
			f_18= f18;
			f_19= f19;
			f_20= f20;
			f_21= f21;
			f_22= f22;
			f_23= f23;
			f_24= f24;
			f_25_29= f2529;
			f_30_34= f3034;
			f_35_39= f3539;
			f_40_44= f4044;
			f_45_49= f4549;
			f_50_54= f5054;
			f_55_59 = f5559;
			f_60_64= f6064;
			f_65 = f65;
			race_agencies= ra;
			race_pop= rp;
			white= w;
			black= b;
			asian= ap;
			american_indian = ai;
			left = right = NULL;
		}
		
};

class AVL
{
	public:
		Node *root;
		long maximum;
		long min;
		int arr[MAX];
	string offense;		
		string minoffense;
		string crime[MAX];
	//	string type array
		string crime1[MAX];
	AVL()
	{		
		root = NULL;
		for(int i=0;i<MAX;i++)
		{
			arr[i]=0;
		}
	}
	
	int height(Node * r) 
	{
    	if (r == NULL)
    	{
    		return -1;
		}
      
    	else 
		{
			int lheight = height(r -> left);
			int rheight = height(r -> right);

			if (lheight > rheight)
			{
				return (lheight + 1);
			}
			else return (rheight + 1);
		}
	}
	
	Node* rightrotate(Node* y) 
	{
    	Node* x = y->left;
    	Node* T2 = x->right;

    	x->right = y;
    	y->left = T2;

    	return x;
	}

	Node* leftrotate(Node* x) 
	{
    	Node* y = x->right;
    	Node* T2 = y->left;

    	y->left = x;
    	x->right = T2;

    	return y;
	}
	
	int balancefactor(Node* n) 
	{
    	if (n == NULL)
    	{
    		return -1;
		}
    	return height(n -> left) - height(n -> right);
	}
	
	Node* insert(Node* r, int ii, int yy, string oc, string on, int ag, int pop, int tm, int tf, int m18, int m19, int m20, int m21, int m22, int m23, int m24, int m2529, int m3034, int m3539, int m4044, int m4549, int m5054, int m5559, int m6064, int m65, int f18, int f19, int f20, int f21, int f22, int f23, int f24, int f2529, int f3034, int f3539, int f4044, int f4549, int f5054, int f5559, int f6064, int f65, int ra, int rp, int w, int b, int ap, int ai)
	{
		Node* n = new Node(ii,yy,oc,on,ag,pop,tm,tf,m18,m19,m20,m21,m22,m23,m24,m2529,m3034,m3539,m4044,m4549,m5054,m5559,m6064,m65,f18,f19,f20,f21,f22,f23,f24,f2529,f3034,f3539,f4044,f4549,f5054,f5559,f6064,f65,ra,rp,w,b,ap,ai);
			
		if(r==NULL)
		{
			r=n;
			//cout<<"| ";
			return r;
		}
		else
		{
			if(n->id > r->id)
			{
				r->right = insert(r->right, ii,yy,oc,on,ag,pop,tm,tf,m18,m19,m20,m21,m22,m23,m24,m2529,m3034,m3539,m4044,m4549,m5054,m5559,m6064,m65,f18,f19,f20,f21,f22,f23,f24,f2529,f3034,f3539,f4044,f4549,f5054,f5559,f6064,f65,ra,rp,w,b,ap,ai);
			//	cout<<"| " ;
			}
			else if(n->id < r->id)
			{
				r->left = insert(r->left, ii,yy,oc,on,ag,pop,tm,tf,m18,m19,m20,m21,m22,m23,m24,m2529,m3034,m3539,m4044,m4549,m5054,m5559,m6064,m65,f18,f19,f20,f21,f22,f23,f24,f2529,f3034,f3539,f4044,f4549,f5054,f5559,f6064,f65,ra,rp,w,b,ap,ai);
			//	cout<<"| ";
			}
			else
			{
				return r;
			}
		}
		
		int bf = balancefactor(r);
    // Left Left Case  
    	if (bf > 1 && n->id < r->left->id)
    	{
    		return rightrotate(r);
		}
      

    // Right Right Case  
    	if (bf < -1 && n->id > r->right->id)
    	{
    		return leftrotate(r);
		}

    // Left Right Case  
    	if (bf > 1 && n->id > r->left->id) 
		{
			r->left = leftrotate(r->left);
			return rightrotate(r);
		}

    // Right Left Case  
    	if (bf < -1 && n->id < r->right->id) 
		{
			r->right = rightrotate(r->right);
			return leftrotate(r);
		}
		return r;
	}
	
	
	bool AVLsearch( Node* root, int key){
		int i;
		bool val;
		
    	if (root == NULL)
       	 cout<<"the id is wrong ";
  		
  		
 	    if (root->id == key)
    	 val=1;
  		
  		
    	else if (root->id > key) {
         val = AVLsearch(root->left, key);
         return val;
    }
  
    	else if (root->id<key) {
          val = AVLsearch(root->right, key);
         return val;
    }
    	
    	if(val==true){
		cout<<endl<<endl;
  		cout<<"                                   what info do you want to get from the id: \n";
  		
  		cout<<endl;
		cout<<"\t\t\t1. offense name \n";
  		cout<<"\t\t\t2. total male   \n";
  		cout<<"\t\t\t3. total female  \n";
  		cout<<"\t\t\t4. population    \n";
  		cout<<endl;
		cout<<"\t\t\t5. male of age 18             \t\t\t21. female of age 18 \n" ;
		cout<<"\t\t\t6. male of age 19             \t\t\t22. female of age 19 \n ";		  
		cout<<"\t\t\t7. male of age 20             \t\t\t23. female of age 20 \n ";		  
		cout<<"\t\t\t8. male of age 21             \t\t\t24. female of age 21 \n ";		  
		cout<<"\t\t\t9. male of age 22             \t\t\t25. female of age 22 \n ";		  
		cout<<"\t\t\t10. male of age 23            \t\t\t26. female of age 23 \n ";		  
		cout<<"\t\t\t11. male of age 24            \t\t\t27. female of age 24 \n ";		  
		cout<<"\t\t\t12. male of age 25_29         \t\t\t28. female of age 25_29 \n ";		  
		cout<<"\t\t\t13. male of age 30_34         \t\t\t29. female of age 30_34 \n ";		  
		cout<<"\t\t\t14. male of age 35_39         \t\t\t30. female of age 35_39 \n ";		  
		cout<<"\t\t\t15. male of age 40_44         \t\t\t31. female of age 40_44 \n ";		  
		cout<<"\t\t\t16. male of age 45_49         \t\t\t32. female of age 45_49 \n ";		  
		cout<<"\t\t\t17. male of age 50_54         \t\t\t33. female of age 50_54 \n ";		  
		cout<<"\t\t\t18. male of age 55_59         \t\t\t34. female of age 55_59 \n ";		  
		cout<<"\t\t\t19. male of age 60_64         \t\t\t35. female of age 60_64 \n ";		  
		cout<<"\t\t\t20. male of age 65            \t\t\t36. female of age 65 \n";
		
		cout<<endl<<endl;	
		cout<<"\t\t\t\t\t\t37. race_agencies \n ";		  
		cout<<"\t\t\t\t\t\t38. race population \n ";		  
		cout<<"\t\t\t\t\t\t39. white \n ";		  
		cout<<"\t\t\t\t\t\t40. black \n ";		  
		cout<<"\t\t\t\t\t\t41. asian_pacific_islander \n ";		  
		cout<<"\t\t\t\t\t\t42. american indian \n ";		  
		
		cin>>i;
			
		switch(i){
			case 1:
				cout<<root->offense_name<<endl;
				break;
			case 2:
				cout<<root->total_male<<endl;
				break;
			case 3:
				cout<<root->total_female<<endl;
				break;
			case 4:
				cout<<root->population<<endl;
				break;
			case 5:
				cout<<root->m_18<<endl;
				break;
				
			case 6:
				cout<<root->m_19<<endl;
				break;
			case 7:
				cout<<root->m_20<<endl;
				break;
			case 8:
				cout<<root->m_21<<endl;
				break;
			case 9:
				cout<<root->m_22<<endl;
				break;
			case 10:
				cout<<root->m_23<<endl;
				break;
			case 11:
				cout<<root->m_24<<endl;
				break;
			case 12:
				cout<<root->m_25_29<<endl;
				break;
			case 13:
				cout<<root->m_30_34<<endl;
				break;
			case 14:
				cout<<root->m_35_39<<endl;
				break;
			case 15:
				cout<<root->m_40_44<<endl;
				break;
			case 16:
				cout<<root->m_45_49<<endl;
				break;
			case 17:
				cout<<root->m_50_54<<endl;
				break;
			case 18:
				cout<<root->m_55_59<<endl;
				break;
			case 19:
				cout<<root->m_60_64<<endl;
				break;
			case 20:
				cout<<root->m_65<<endl;
				break;
			
			case 21:
				cout<<root->f_18<<endl;
				break;
				
			case 22:
				cout<<root->f_19<<endl;
				break;
			case 23:
				cout<<root->f_20<<endl;
				break;
			case 24:
				cout<<root->f_21<<endl;
				break;
			case 25:
				cout<<root->f_22<<endl;
				break;
			case 26:
				cout<<root->f_23<<endl;
				break;
			case 27:
				cout<<root->f_24<<endl;
				break;
			case 28:
				cout<<root->f_25_29<<endl;
				break;
			case 29:
				cout<<root->f_30_34<<endl;
				break;
			case 30:
				cout<<root->f_35_39<<endl;
				break;
			case 31:
				cout<<root->f_40_44<<endl;
				break;
			case 32:
				cout<<root->f_45_49<<endl;
				break;
			case 33:
				cout<<root->f_50_54<<endl;
				break;
			case 34:
				cout<<root->f_55_59<<endl;
				break;
			case 35:
				cout<<root->f_60_64<<endl;
				break;
			case 36:
				cout<<root->f_65<<endl;
				break;
			case 37:
				cout<<root->race_agencies<<endl;
				break;
			case 38:
				cout<<root->race_pop<<endl;
				break;
			case 39:
				cout<<root->white<<endl;
				break;
			case 40:
				cout<<root->black<<endl;
				break;
			case 41:
				cout<<root->asian<<endl;
				break;
			case 42:
				cout<<root->american_indian<<endl;
				break;
				
	}}
	//	if(val==false)
	 //     cout<<"NO DATA FOUND FROf THIS ID \n\n THIS ID IS WRONG! ";
	
}
	void Inorder(Node *temp, int i)
	{
		if(temp==NULL)
		{
			//cout<<"no data: ";
			return;
		}
		 
		Inorder(temp->left, i);
		arr[++i]=temp->total_female+temp->total_male;
		//crime[++i]=temp->offense_name;
		//i++;
		Inorder(temp->right, i);
		
	}	
	
	void Inorder2(Node *temp, int i)
	{
		if(temp==NULL)
		{
			//cout<<"no data: ";
			return;
		}
		 
		Inorder2(temp->left, i);
		//arr[++i]=temp->total_female+temp->total_male;
		crime[++i]=temp->offense_name;
		//i++;
		Inorder2(temp->right, i);
		
	}
	
	void Inorder3(Node *temp, int i)
	{
		if(temp==NULL)
		{
			//cout<<"no data: ";
			return;
		}
		 
		Inorder3(temp->left, i);
		//arr[++i]=temp->total_female+temp->total_male;
		crime1[++i]=temp->offense_name;
		//i++;
		Inorder3(temp->right, i);
	}	
	
	void maxfunc()
	{
	//	int maximum=0;
		int i;
	//string offense
		for(i=0;i<MAX;i++){
			if(arr[i]>arr[i+1])
			{
			
				maximum=arr[i];
				offense=crime[i];
			}
	}}
	
	void minfunc(){
		for(int i=0;i<MAX;i++){
			if(arr[i]<arr[i+1]){
			 min=arr[i];
			 minoffense=crime1[i];
		}
		}
	}
};

 void read_data()
 {
 	AVL b;
 	//int n1=0;
 	//Node *root=NULL;
 	
 	fstream fin;
 	fin.open("arrests_national_adults.csv", ios::in);
 	string line;
 	string temp, line2,line3;
 	string line1,line4,line5,line6,line7,line8,line9,line10, line11, line12, line13, line14, line15, line16, line17, line18, line19, line20, line21, line22,line23,line24,line25, line26,line27, line28;
	string line29,line30,line31, line32, line33, line34, line35, line36, line37, line38, line39, line40, line41, line42, line43, line44, line45, line46;
 	
 	
		int id,year, agencies, population, total_male, total_female;

		int m_18, m_19, m_20, m_21, m_22, m_23, m_24, m_25_29;
		int m_30_34, m_35_39, m_40_44, m_45_49, m_50_54, m_55_59;
		int m_60_64, m_65;
	
		int f_18, f_19, f_20, f_21, f_22, f_23, f_24, f_25_29;
		int f_30_34, f_35_39, f_40_44, f_45_49, f_50_54, f_55_59;
		int f_60_64, f_65;  
   
		int f_18_24, m_18_24;
	
		int race_agencies, race_pop, white, black, asian, american_indian;
		string offense_code, offense_name;

	
	
	getline(fin, temp);
	while(!fin.eof())
	{
		
 	getline(fin, line, ',');
	stringstream geek(line);
    geek >> id;
    //cout<<id<<"  ";
    
 	getline(fin, line1, ',');
 	stringstream geek1(line1);
    geek1 >> year;
    //cout<<year<<"  ";
    
 	getline(fin, line2, ',');
	offense_code=line2;
 	//cout<<offense_code<<"  ";
 	
 	
 	getline(fin, line3, ',');
 	offense_name=line3;
 	//cout<<offense_name<<"  ";
 	
 	getline(fin, line4, ',');
 	stringstream geek2(line4);
    geek2 >> agencies;
    //cout<<agencies<<"  ";
    
 	getline(fin, line5, ',');
 	stringstream geek3(line5);
    geek3 >> population;
    //cout<<population<<"  ";
    
 	getline(fin, line6, ',');
 	stringstream geek4(line6);
    geek4 >> total_male;
    //cout<<total_male<<"  ";
    
 	getline(fin, line7, ',');
 	stringstream geek48(line7);
    geek48 >> total_female;
    //cout<<total_female<<"  ";
    
 	getline(fin, line8, ',');
 	stringstream geek5(line8);
    geek5 >> m_18;
    //cout<<m_18<<"  ";
    
 	getline(fin, line9, ',');
 	stringstream geek6(line9);
    geek6 >> m_19;
    //cout<<m_19<<"  ";
    
 	getline(fin, line10, ',');
 	stringstream geek7(line10);
    geek7 >>m_20;
    //cout<<m_20<<"  ";
    
 	getline(fin, line11, ',');
 	stringstream geek8(line11);
    geek8 >> m_21;
    //cout<<m_21<<"  ";
    
 	getline(fin, line12, ',');
 	stringstream geek9(line12);
    geek9 >> m_22;
    //cout<<m_22<<"  ";
    
 	getline(fin, line13, ',');
 	stringstream geek10(line13);
    geek10 >> m_23;
    //cout<<m_23<<"  ";
    
 	getline(fin, line14, ',');
 	stringstream geek11(line14);
    geek11 >> m_24;
    //cout<<m_24<<"  ";
    
 	getline(fin, line15, ',');
 	stringstream geek12(line15);
    geek12 >> m_25_29;
    //cout<<m_25_29<<"  ";
    
 	getline(fin, line16, ',');
 	stringstream geek14(line16);
    geek14 >> m_30_34;
    //cout<<m_30_34<<"  ";
    
 	getline(fin, line17, ',');
 	stringstream geek15(line17);
    geek15 >> m_35_39;
    //cout<<m_35_39<<"  ";
    
 	getline(fin, line18, ',');
 	stringstream geek16(line18);
    geek16 >> m_40_44;
    //cout<<m_40_44<<"  ";
    
 	getline(fin, line19, ',');
 	stringstream geek17(line19);
    geek17 >> m_45_49;
    //cout<<m_45_49<<"  ";
    
 	getline(fin, line20, ',');
 	stringstream geek18(line20);
    geek18 >> m_50_54;
    //cout<<m_50_54<<"  ";
    
 	getline(fin, line21, ',');
 	stringstream geek19(line21);
    geek19 >> m_55_59;
    //cout<<m_55_59<<"  ";
    
 	getline(fin, line22, ',');
 	stringstream geek20(line22);
    geek20 >> m_60_64;
    //cout<<m_60_64<<"  ";
    
 	getline(fin, line23, ',');
 	stringstream geek21(line23);
    geek21 >> m_65;
    //cout<<m_65<<"  ";
    
 	getline(fin, line24, ',');
 	stringstream geek22(line24);
    geek22 >> f_18;
    //cout<<f_18<<"  ";
    
 	getline(fin, line25, ',');
 	stringstream geek23(line25);
    geek23 >> f_19;
    //cout<<f_19<<"  ";
    
 	getline(fin, line26, ',');
 	stringstream geek24(line26);
    geek24 >> f_20;
    //cout<<f_20<<"  ";
    
 	getline(fin, line27, ',');
 	stringstream geek25(line27);
    geek25 >> f_21;
    //cout<<f_21<<"  ";
    
 	getline(fin, line28, ',');
 	stringstream geek26(line28);
    geek26 >> f_22;
    //cout<<f_22<<"  ";
    
 	getline(fin, line29, ',');
 	stringstream geek27(line29);
    geek27 >> f_23;
    //cout<<f_23<<"  ";
    
 	getline(fin, line30, ',');
 	stringstream geek28(line30);
    geek28 >> f_24;
    //cout<<f_24<<"  ";
    
 	getline(fin, line31, ',');
 	stringstream geek29(line31);
    geek29 >> f_25_29;
    //cout<<f_25_29<<"  ";
    
 	getline(fin, line32, ',');
 	stringstream geek30(line32);
    geek30 >> f_30_34;
    //cout<<f_30_34<<"  ";
    
 	getline(fin, line33, ',');
 	stringstream geek31(line33);
    geek31 >> f_35_39;
    //cout<<f_35_39<<"  ";
    
 	getline(fin, line34, ',');
 	stringstream geek32(line34);
    geek32 >> f_40_44;
    //cout<<f_40_44<<"  ";
    
 	getline(fin, line35, ',');
	stringstream geek33(line35);
    geek33 >> f_45_49;
//    //cout<<f_45_49<<"  ";
     	
 	getline(fin, line36, ',');
 	stringstream geek34(line36);
    geek34 >> f_50_54;
//    //cout<<f_50_54<<"  ";
    
 	getline(fin, line37, ',');
 	stringstream geek35(line37);
    geek35 >> f_55_59;
 //   //cout<<f_55_59<<"  ";
    
 	getline(fin, line38, ',');
	stringstream geek36(line38);
    geek36 >> f_60_64;
//    //cout<<f_60_64<<"  ";
    
	getline(fin, line39, ',');
	stringstream geek37(line39);
    geek37 >> f_65;
    ////cout<<f_65<<"  ";
    
 	getline(fin, line40, ',');
	stringstream geek38(line40);
    geek38 >>race_agencies;
  //  //cout<<race_agencies<<"  ";
    
	getline(fin, line41, ',');
	stringstream geek39(line41);
    geek39 >> race_pop;
//    //cout<<race_pop<<"  ";
    
	getline(fin, line42, ',');
	stringstream geek40(line42);
    geek40 >> white;
//    //cout<<white<<"  ";
    
	getline(fin, line43, ',');
	stringstream geek41(line43);
    geek41 >> black;
   // //cout<<black<<"  ";
    
	getline(fin, line44, ',');
	stringstream geek42(line44);
    geek42 >> asian;
    ////cout<<asian<<"  ";
    
	getline(fin, line45);
	stringstream geek43(line45);
    geek43 >> american_indian;
    ////cout<<american_indian<<"  ";
    
	cout<<endl<<endl;	
	
	b.root=b.insert(b.root, id,  year, offense_code, offense_name, agencies, population, total_male, total_female, m_18, m_19, m_20, m_21, m_22, m_23, m_24, m_25_29, 
	         m_30_34, m_35_39, m_40_44, m_45_49, m_50_54, m_55_59, m_60_64, m_65, f_18, f_19, f_20, f_21, f_22, f_23, f_24, f_25_29,f_30_34, f_35_39, 
			 f_40_44, f_45_49, f_50_54, f_55_59, f_60_64, f_65, race_agencies, race_pop, white, black, asian, american_indian);
	
}

	

	system("cls");
	
	cout<<endl<<endl<<"THE DATA IS INSERTED INTO THE AVL TREE! \n\n";
	getch();
//return b.root;
	l1: cout<<"\n\n";
	
	system("cls");
	int key;
	cout<<"\n\n\n\t\t\t\t----------------------ENTER THE ID TO SEARCH FOR THE DATA:--------------------------- "<<endl;
	cin>>key;
	
	system("cls");
	cout<<endl<<endl;
	b.AVLsearch(b.root,key);
	
	cout<<"do you want to get any othere info:   1.yes   2.no: "<<endl;
	int n5;
	cin>>n5;
	
	if(n5==1)
	 goto l1;
	 
	 
	int w;
	cout<<"\t\t\t\t\n\n\nDo you want to get the maximum number of people involved in a crime: \n1.max 2.min 3.no\n";
	cin>>w;
	
	b.Inorder(b.root, -1);
	b.Inorder2(b.root,-1);
	b.Inorder3(b.root,-1);
	if(w==1){
	 b.maxfunc();
	 
	cout<<"\t\t\t\t\n\n\nthe max of number of people involved in a crime are: "<<b.maximum<<endl<<"\t\t\t\t\n\nthe offense is: "<<b.offense<<endl;
}

	else if(w==2){
		b.minfunc();
		cout<<"\t\t\t\t\n\n\nthe min number of people involved in any crime are: "<<b.min<<endl<<"\t\t\t\n\nthe offense is: "<<b.minoffense<<endl;
	}
	else exit(1);
}




int main()
{
	read_data();
}
