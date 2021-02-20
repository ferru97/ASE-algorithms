#include <iostream>

//Chapter 2: Maximum sub-array problem

void maxSubArray_Cubic(int arr[], int len);
void maxSubArray_Quadratic(int arr[], int len);
void maxSubArray_Linear(int arr[], int len);


int main(){

    int arr[] = {4,-6,3,1,3,-2,3,-4,1,-9,+6}; //solution arr[3.7]
    
    maxSubArray_Cubic(arr,11);
    maxSubArray_Quadratic(arr,11);
    maxSubArray_Linear(arr,11);

    return 0;
}


//O(n^3) algorithmn
void maxSubArray_Cubic(int arr[], int len){
    int b,s,temp_sum;
    int max_sum = -999;
    for(int i=0; i<len; i++){ //O(n)
        for(int c=i; c<len; c++){ //O(n)
            temp_sum = 0;
            for(int k=i; k<c; k++) //O(n)
                temp_sum += arr[k];
            
            if(temp_sum>max_sum){
                max_sum = temp_sum;
                b = i;
                s = c;
            }
        }
    }
    std::cout << "O(n^3) Max sum = " << max_sum << " - Start:" << b << " End:" << s << std::endl;
}



//O(n^2) algorithmn
void maxSubArray_Quadratic(int arr[], int len){
    int b,s,temp_sum;
    int max_sum = -999;
    for(int i=0; i<len; i++){ //O(n)
        temp_sum = 0; //avoid recompting subarray sum
        for(int c=i; c<len; c++){ //O(n)
            temp_sum += arr[c];
            if(temp_sum>max_sum){
                max_sum = temp_sum;
                b = i;
                s = c;
            }
        }
    }
    std::cout << "O(n^2) Max sum = " << max_sum << " - Start:" << b << " End:" << s << std::endl;
}


//O(n) algorithmn
void maxSubArray_Linear(int arr[], int len){
    /*
        Property 1: The sum of arr[x,b-1] cannot be strictly positive
        Property 2: The sum of att[b,y] with y <=s cannot be strictly negative
    */

    int b,b2,s,temp_sum;
    b2 = 0;
    temp_sum = 0;
    int max_sum = -999;
    for(int i=0; i<len; i++){ //O(n)
        temp_sum += arr[i];
            
        if(temp_sum>max_sum){
            max_sum = temp_sum;
            b = b2;
            s = i;
        }

        if(temp_sum < 0){
            temp_sum = 0;
            b2 = i+1;
        }
    }
    std::cout << "O(n) Max sum = " << max_sum << " - Start:" << b << " End:" << s << std::endl;
}
