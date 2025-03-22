#include<bits/stdc++.h>
using namespace std;
class Task{
	public:
	//Structure of the Task
	int id;
	string description;
	int priority;  //lowest value has higher value
	
	Task(int id,string description,int priority){
		this->id=id;
		this->description=description;
		this->priority=priority;
		
	}
    //Custom comparaator for value in minheap place according to the value of the priority
   struct Compare {
        bool operator()(const Task* a, const Task* b) {
            return a->priority > b->priority;  // Min-heap: lower priority value comes first
        }
    };

};

class TaskManager{
	public:
	//defining the meanheap
     priority_queue<Task*, vector<Task*>, Task::Compare> p;  
	//hash map for store the task for meanheap to check the value is deleted or not
	unordered_map<int,Task*> mp;
	
	//functiom for add a task 
	void addtask(int id,string description,int priority){
        Task* t=new Task(id, description, priority);
		p.push(t);
		mp[id]=t;
	}
	
	// remove a task whose id is given
	void removeTask(int id){
		if(mp.find(id)!=mp.end()){
			mp.erase(id);
			cout<<"Task with id "<<id<<" removed successfully"<<endl;
		}
		else{
			cout<<"No task present with the id you give!"<<endl;
		
		}
	}
	
	//display all the task according to the lower value of priority has higher priority
	
	void display(){
		if(p.size()==0){
			 cout<<"No task is present!"<<endl;
			 return;
		}
		priority_queue<Task*,vector<Task*>,Task::Compare> temp=p;
		cout<<"Total task present according to their priority value :"<<endl;
		while(temp.size()>0) {
			Task* a=temp.top();
			temp.pop();
			//checking the task a present in the map or not
			if(mp.find(a->id)!=mp.end()){
				cout<<"ID: "<<a->id<<" Description: "<<a->description<<" Priority: "<<a->priority<<endl;
			}
			
			
		}
	}
	
	//Getting the highest priority task that is present
	
	void highestTask() {
    while (!p.empty() && mp.find(p.top()->id) == mp.end()) {
        p.pop();  // Remove invalid (deleted) tasks
    }

    if (p.empty()) {
        cout << "No task is present!" << endl;
        return;
    }

    Task* b = p.top();
    cout << "Task with highest priority is: "
         << "ID: " << b->id << " Description: " << b->description << " Priority: " << b->priority << endl;
}

};
int main(){
	TaskManager  manager;
	string dest;
	int id,priority,choice;
	
	while(1){
		
		cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display All Tasks\n";
        cout << "4. Get Highest Priority Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;
        if(choice==1){
        	cout<<"enter the id:";
        	cin>>id;
        	cout<<"enter the description:";
        	cin>>dest;
        	cout<<"enter the priority value:";
        	cin>>priority;
        	manager.addtask(id,dest,priority);
		}
		else if(choice==2){
			cout<<"enter the id of the task that you want to remove :";
			cin>>id;
			manager.removeTask(id);
		}
		else if(choice==3){
			manager.display();
		}
		else if(choice==4){
			manager.highestTask();
		}
		else if(choice==5) break;
		else{
			cout<<"invalid input! try again";
		}
	}
	
	
}