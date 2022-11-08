//Created by Tyler C. Hayes
//Professor Vanechek
#include <iostream> 
#include <stdlib.h> //Srand, rand
#include <ctime> //Time
#include <string>
using namespace std;


//Return the position of the grade in the array if it is in the list
int searcharr(int grade, int arr[],int counter)
{
	for(int i = 0; i < counter; i++)
	{
		if(arr[i] == grade)
		{
			return i;		}
	}
	return -1;
}


//Swap 2 nums in the array
void swap(int* pos1, int* pos2)
{
	int temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}


//Sorts array least to greatest
void bubble_sort(int arr[], int total_size)
{
	//first & second couter
	int fc, sc; 

	//First for loop
	for (fc = 0; fc < total_size - 1; fc++)
	{
		//Second for loop
		for (sc = 0; sc < total_size - fc - 1; sc++)
		{
			//Call swap function if pos1 > pos2
			if (arr[sc] > arr[sc + 1])
			{
				swap(&arr[sc], &arr[sc + 1]);			}		
		}
	}
}


//Prints the entire array
void coutArray(int arr[], int counter)
{
		int i;
		for(i = 0; i < counter; i++)
		{
			cout<<arr[i]<<endl;
		}
}


//Binary search
int binary_search(int grade, int arr[], int low, int high)
{
	cout<<"In bin search"<<endl;
	int mid;
	mid = low + high / 2; 
	
	cout<<"Grade in mid: "<<arr[mid]<<endl;
	
	while(high - low > 1)
	{
		//Is grade mid?
		if(grade == arr[mid])
		{
			cout<<"Grade Found!"<<endl;
			return 1;
		}

		//Is grade greater than mid?
		if(grade > arr[mid])
		{
			low = mid;
			mid = low + high / 2; 
			cout<<"Test >"<<endl;
			cout<<arr[mid]<<endl;
		}

		//Is grade less than mid?
		if(grade < arr[mid])
		{
			high = mid;
			mid = low + high / 2;
			cout<<"Test < "<<endl;
			cout<<arr[mid]<<endl;
		}
	}
	
	return -1;
}
	

long double non_rec_factorial(long double value)
{
	long double i, answer;
	answer = value;

	if(value == 0 or value == 1)
	{
		return 1;
	}

	for(i = value - 1; i >= 1; i--)
	{
		answer = answer * i;
	}
	return answer;
	
}


long double rec_factorial(long double value)
{
	long double i, answer;
	answer = value;

	if(value == 0 or value == 1)
	{
		return 1;
	}

	else
	{
		return value * rec_factorial(value - 1);
	}
	
}

int main() 
{
	//Declarations
	int small_arr [10];
	int large_arr [100000];
	int exam_score;
	int rand_num;
	int timer, timer2, time_result;

	//A random seed derived from time
	srand(time(NULL)); 

	//Filling small array
	for(int counter = 0;  counter < 10; counter++)
	{
		small_arr[counter] = 1+rand()%101; //Rand num 1-10 
	}
	//Filling large array
	for(int counter = 0; counter < 100000; counter++)
	{
		large_arr[counter] = 1+rand()%101; //Rand num 1-10 
	}
	
	//Declarations	int grade, result;	string again = "y";
	int arrchoice, array_size_s, array_size_l, search_choice;


	//Get num of elements in array. Array_size - 1 = (0-9) & (0-999999)
	array_size_s = sizeof(small_arr) / sizeof(small_arr[0]) - 1; 
	array_size_l = sizeof(large_arr) / sizeof(large_arr[0]) - 1; 
	//binary_search(grade, small_arr, 0, array_size_s);

	string again = "y";
	//int time_result;
	int result;
	int grade;
	long double answer;
	long double rec_value, non_rec_val;
	
	cout<<"Sequential Search (1) Binary Search (2) Non-Recursive Factorial (3) Recursive Factorial (4)"<<endl;
	cin>>search_choice;

	//Sequential Search
	if (search_choice == 1)
	{
		//Asking user which array they want to search
		cout<<"Would you like to search the small array (1) or large array? (2):";
		cin>>arrchoice;
		
		if (arrchoice == 1)
		{
			while(again == "y")
			{
				//Insert 555 in the middle
				small_arr[5] = 555;
				cout<<"==================small-array==============="<<endl;
				cout<<"What grade are you looking for 1-100:";
				cin>>grade;
				cout<<""<<endl;
				//Start the clock before the function call
				timer = clock();
				//Calling the function that searches for the grade
				result = searcharr(grade, small_arr, 10); 
				//Starts another timer
				timer2 = clock();
				//Subtracting both timers to get the time it took to run the function
				time_result = timer2 - timer;
				
				if (result == -1)
				{
					cout <<"Grade not found in list!"<<endl;
					cout <<""<<endl;
				}
			
				else
				{
					cout <<"Grade was found at position:"<<result<<endl;
				}
	
				cout<<"====Timer===="<<endl;
				cout<<"Timer 1:"<<timer<<endl;
				cout<<"Timer 2:"<<timer2<<endl;
				cout<<"Program runtime: "<<time_result<<" Sec"<<endl;
				cout<<"===================="<<endl;
				cout<<"Do you want to search again? (y/n)"<<endl;
				cin>>again;
			
	
			}
		}
		if (arrchoice == 2)
		{
			while(again == "y")
			{
				//Insert 555 in the middle
				large_arr[500000] = 555;
				cout<<"==================large-array==============="<<endl;
				cout<<"What grade are you looking for 1-100:";
				cin>>grade;
				//Start the clock before the function call
				timer = clock();
				//Calling the function that searches for the grade
				result = searcharr(grade, large_arr, 1000000); 
				//Starts another timer
				timer2 = clock();
				//Subtracting both timers to get the time it took to run the function
				time_result = timer2 - timer;
				
				if (result == -1)
				{
					cout <<"Grade not found in list!"<<endl;
					cout <<""<<endl;
				}
					
				else
				{
					cout <<"Grade was found at position:"<<result<<endl;
				}
	
				cout<<"====Timer===="<<endl;
				cout<<"Timer 1:"<<timer<<endl;
				cout<<"Timer 2:"<<timer2<<endl;
				cout<<"Program runtime: "<<time_result<<" Sec"<<endl;
				cout<<"===================="<<endl;
				cout<<"Do you want to search again? (y/n)"<<endl;
				cin>>again;
			
				cout<<"Do you want to search again? (y/n)"<<endl;
				cin>>again;
			
			}
		}
			
		else
		{
			cout<<"Error please choose 1 or 2"<<endl;
			return -1;
		}
		
	}
	
	//Binary Search
	if (search_choice == 2)
	{
		cout<<"Which array would like to search? Small (1) Large (2): ";
		cin>>arrchoice;

		if (arrchoice == 1) 
		{
			while(again == "y")
			{
				small_arr[4] = 50;
				cout<<"==================small-array==============="<<endl;
				cout<<"What grade are you looking for 1-100:";
				cin>>grade;
				cout<<""<<endl;
				//Start the clock before the function call
				timer = clock();
				//Calling the function that searches for the grade
				bubble_sort(small_arr, 10); 
				result = binary_search(grade, small_arr, 0, array_size_s);
				//Starts another timer
				timer2 = clock();
				//Subtracting both timers to get the time it took to run the function
				time_result = timer2 - timer;

				if (result == -1)
				{
					cout <<"Grade not found in list!"<<endl;
					cout <<""<<endl;
				}
			
				else
				{
					cout <<"Grade was found at position:"<<result<<endl;
				}
		
	
				cout<<"====Timer===="<<endl;
				cout<<"Timer 1:"<<timer<<endl;
				cout<<"Timer 2:"<<timer2<<endl;
				cout<<"Program runtime: "<<time_result<<" Sec"<<endl;
				cout<<"===================="<<endl;
				cout<<"Do you want to search again? (y/n)"<<endl;
				cin>>again;
		}
		}

		if (arrchoice == 2)
		{
			while(again == "y")
			{
				large_arr[50000] = 50;
				cout<<"==================large-array==============="<<endl;
				cout<<"What grade are you looking for 1-100:";
				cin>>grade;
				cout<<""<<endl;
				//Start the clock before the function call
				timer = clock();
				//Calling the function that searches for the grade
				bubble_sort(large_arr, 100000); 
				result = binary_search(grade, large_arr, 0, array_size_l);
				//Starts another timer
				timer2 = clock();
				//Subtracting both timers to get the time it took to run the function
				time_result = timer2 - timer;

				if (result == -1)
				{
					cout <<"Grade not found in list!"<<endl;
					cout <<""<<endl;
				}
			
				else
				{
					cout <<"Grade was found at position:"<<result<<endl;
				}
		
	
				cout<<"====Timer===="<<endl;
				cout<<"Timer 1:"<<timer<<endl;
				cout<<"Timer 2:"<<timer2<<endl;
				cout<<"Program runtime: "<<time_result<<" Sec"<<endl;
				cout<<"===================="<<endl;
				cout<<"Do you want to search again? (y/n)"<<endl;
				cin>>again;
			}
		}

		else
		{
			cout<<"Error wrong input. Input 1 or 2"<<endl;
			return -1;
		}
	}

	//Non Recursive Factorial
	if (search_choice == 3)
	{
		
		while (again == "y")
		{
			cout << "======== Get The Factorial of A Number (Non Recursive) =======" << endl;
			cout << "Enter a value: ";
			cin >> non_rec_val;
			timer = clock();
			answer = non_rec_factorial(non_rec_val);
			timer2 = clock();
			result = timer2 - timer;
			cout<<"The Factorial of "<<non_rec_val<<" is "<<answer<<endl;
			cout<<"Time Taken For Non-Recursive Factorial Function:"<<result<<" Clicks"<<endl;
			cout<<"===================="<<endl;
			cout<<"Do you want to search again? (y/n)"<<endl;
			cin>>again;

		}
		
		
	}

	//Non Recursive Factorial
	if (search_choice == 4)
	{
		
		while (again == "y")
		{
			cout << "======== Get The Factorial of A Number (Recursive) =======" << endl;
			cout << "Enter a value: ";
			cin >> rec_value;
			timer = clock();
			answer = rec_factorial(rec_value);
			timer2 = clock();
			result = timer2 - timer;
			cout<<"The Factorial of "<<rec_value<<" is "<<answer<<endl;
			cout<<"Time Taken For Recursive Factorial Function:"<<result<<" Clicks"<<endl;
			cout<<"===================="<<endl;
			cout<<"Do you want to search again? (y/n)"<<endl;
			cin>>again;

		}
		
		
	}
	else
	{
		cout<<'wrong'<<endl;
	}








	





}
	
	
	

	


//References
//https://www.geeksforgeeks.org
//https://java2blog.com/get-number-of-elements-in-array-cpp/
