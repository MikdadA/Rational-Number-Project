/* 
 Project - Rat class
*/


#include <iostream>
using namespace std; 
 //rational number class
  class Rat{
    //declare n and d. Set to private
    private:
    int n; //numerator
    int d; //denominator
    
    public:
    //constructors
    //default constructor
    Rat(){
        n=0;
        d=1;
    } 
    //2 parameter constructor 
    Rat(int i, int j){ 
        n=i;
        d=j;
    } 
    //conversion constructor to handle rational number 
    Rat(int i){
        n=i;
        d=1;
    }
    //accessor functions usually called (getters) get() and (setters) set(...)  
    int getN(){ //get for numerator
        return n;
    }
    
    int getD(){ //get for denominator
        return d;
    } 
 
    void setN(int i){ //set for numerator
        n=i;
        
    }
    void setD(int i){ //set for denominator
        d=i;
        
    } 
    
    // addition operator
    Rat operator+(Rat r){
        Rat t; //declare t
        t.n=n*r.d + d*r.n; //defining t numerator and denominator as a sum for rational numbers (first n * second d + first d * second n) or the butterfly method I leanred in high school.
        t.d=d*r.d; //multiply the 2 denominator with each other 
        t.reduce(); //now here we are simplying it to the lowest terms by calling the reduce function
        return t; //then return
    }
    // subtraction operator
    Rat operator-(Rat r){
      Rat t; //declare t
      t.n=n*r.d - d*r.n; //defining t numerator and denominator as a difference for rational numbers (first n * second d - first d * second n)
      t.d=d*r.d; //multiply the 2 denominator with each other
      t.reduce(); //now here we are simplying it to the lowest terms by calling the reduce function
      return t; //then return
    }
    //multiplication
    Rat operator*(Rat r){
      Rat t; //declare t 
      t.n = n*r.n; //numerator * numerator
      t.d = d*r.d; //denominator * denominator
      t.reduce(); //simplify again by calling the reduce function
      return t; //then return
   }
   //division
   Rat operator/(Rat r){
      Rat t; //declare t
      t.n = n*r.d; //numerator * denominator
      t.d = d*r.n; //denominator * numerator
      t.reduce(); //simplify again by calling the reduce function
      return t; //then return
   }
    //find the greatest common denominator
    int gcd(int num, int den){
      int temp; //declare temp
      while(den!=0){ //when the denominator is not equal to 0
        temp=num; //change temp to numerator
        num=den; //then change numerator to the denominator
        den=temp%den; //set the denominator to find the remainder 
      }
      return num;
    }
    //Reduce function to simplify to lowest terms
    void reduce(){
      int theGCD = gcd(n,d); //call the gcd function to find the GCD for the numerator and denominator
      n=n/theGCD; //finding the numerator
      d=d/theGCD; //finding the denominator
      if (d<0) { //to check  denominator is not a negative integer 
        d=-d; //if so then we set the denominator and numerator to negative
        n=-n;
      }
    }
    
    // 2 overloaded i/o operators. 
    friend ostream& operator<<(ostream& os, Rat r); 
    friend istream& operator>>(istream& is, Rat& r); 
  }; //end Rat 
 
  // operator<<() is NOT a member function but since it was declared a friend of Rat
  // it has access to its private parts. 
  ostream& operator<<(ostream& os, Rat r){
    os<<r.n<<" / "<<r.d<<endl;
    return os;
  } 
  // operator>>() is NOT a member function but since it was declared a friend of Rat
  // it has access to its provate parts. 
  istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    return is;
  } 
 
  int main(){
    Rat x(1,2), y(2,3), z; //integers to store
    z=x+y; cout<<z;
    
    x.setN(3);
    y.setD(2);
    z=x+y; cout<<z; 
    cin>>x; cout<<x; 
    
    z= x+5; cout<<z;   
    system("pause");
    return 0; 
    
} //main

//end of the code