#include<bits/stdc++.h>
using namespace std;
class ATM{
	private:
		vector<int> NoteAvailable={20,50,100,200,500}; //The notes that we can used like 20,50,100,200,500
		vector<int> NotesRemain;// The number of notes currently present of the notes used
	public:
	ATM(){
		NotesRemain.resize(5,0);//initailly there is no notes are present
	}
	void deposit(vector<int> DepositNotes){
		for(int i=0;i<5;i++){
			NotesRemain[i]+=DepositNotes[i];
			
		}
	}
	
	//function for withdraw the money from the bank
	vector<int> withdraw(int amount){
		vector<int> result(5,0); //How many notes that we have been withdraw form the vector NotesRemain
		vector<int> temp=NotesRemain;
		
		//we travel from the last in vector temp so that we use max value notes first
		for(int i=4;i>=0;i--){
			int need=amount/NoteAvailable[i];
			int use=min(need,temp[i]);
			//push the no of notes that we use in result vector
			result[i]=use;
			amount-=use*NoteAvailable[i];
		}
		
		//checking if the amount is not equal to zero
		if(amount>0){//we can not withdraw this money
		   return {-1};
			
		}
		
		//decrese the no. of notes form each notes that we use in withdraw the amount
		for(int i=0;i<5;i++){
			NotesRemain[i]-=result[i];
		}
		return result;
	}
	
	
	
	//function to check that how many notes of each give notes are available
	void CheckBalance(){
		int TotalBalance=0;
		for(int i=0;i<5;i++){
			cout<<NoteAvailable[i]<< "$:" << NotesRemain[i]<<" ";
			TotalBalance+=NoteAvailable[i]*NotesRemain[i];
		
		}
		cout<<endl;
		cout<<"Total amount available in the ATM is : "<<TotalBalance;
	}
		
};
int main(){
	ATM atm; //make an object of ATM class 
	
	int select;
	while(1){
		 cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nEnter choice: ";
        cin >> select;
        
        if(select==1){
        	vector<int> saving(5,0);
        	 cout << "Enter deposit counts for $20, $50, $100, $200, $500: ";
        	 for(int i=0;i<5;i++){
        	 	cin>>saving[i];
			 }
			 atm.deposit(saving);
		}
		
		else if(select==2){
			int remove;
			cout<<"enter the amount that you want to withdraw :";
			cin>>remove;
		vector<int> result=atm.withdraw(remove);
		if(result[0]==-1) {
			cout<<"withdraw is not possible"<<endl;
		}
		else{
			cout<<"The notes that are withdraw are :"<<endl;
			cout<<endl;
			for(int i=0;i<5;i++){
				cout<<result[i]<<" ";
			}
			cout<<endl;
		}
	}
	   else	if(select==3){
			atm.CheckBalance();	
		}
		else if(select==4){
			break;
		}
		else{
			cout<<"Invalid choice,Please enter a valid input :"<<endl;
		}
	}
}