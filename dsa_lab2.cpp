#include <iostream>

using namespace std;

int temp;

template<typename T>
class KeyStorage{
	public:
       int key;
	   T member; 
       KeyStorage(int theKey, T theMember);
       ~KeyStorage();
       T get();
       T set(T arg);
};
template<typename T>
KeyStorage<T>::KeyStorage(int theKey, T theMember){
         //TODO
}
template<typename T>
KeyStorage<T>::~KeyStorage(void){
         //TODO
}
template<typename T>
T KeyStorage<T>::get(){
	return member;
}
template<typename T>
T KeyStorage<T>::set(T arg){
    this -> member = arg;
}

class Complex {
private:
double a;
double b;

public:

    Complex();

    Complex(double theA, double theB) {
        this -> a = theA;
        this -> b = theB;
    };
    
    static Complex addition(Complex &nrOne, Complex &nrTwo) {
        Complex result(0,0);
        result.a = nrOne.a + nrTwo.a;
        result.b = nrOne.b + nrTwo.b;
        return result;
    }
    
    static Complex division(Complex &nrOne, Complex &nrTwo) {
        Complex result(0,0);
        result.a = (nrOne.a * nrTwo.a + nrOne.b * nrTwo.b) / ((nrTwo.a * nrTwo.a) + (nrTwo.b * nrTwo.b));
        result.b = (nrOne.b * nrTwo.a - nrTwo.b * nrOne.a) / ((nrTwo.a * nrTwo.a) + (nrTwo.b * nrTwo.b));
        return result;
    }
    
    static Complex multiplication(Complex &nrOne, Complex &nrTwo) {
        Complex result(0,0);
        result.a = nrOne.a * nrTwo.a - (nrOne.b * nrTwo.b);
        result.b = nrOne.a * nrTwo.b + nrTwo.a * nrOne.b;
        return result;
    }
    
    void printNumber() {
        cout << a << " + i" << b;
    }
};


void bubbleSort(int (&array)[5]) {
    bool changed;
    do {
        changed = false;
        for (int i = 0 ; i < 4; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                changed = true;
            }
        }
    } while (changed == true);
}

int main() {
    int array[5] = {6, 5, 4, 3, 2};
    for (int i = 0; i < 5; i++) {
        cout << array[i] << ' ';
    }
    bubbleSort(array);
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
    Complex firstNumber(5,6);
    Complex secondNumber(8, 9);
    firstNumber.printNumber();
    cout << endl;
    secondNumber.printNumber();
    cout << endl;
    Complex added(0,0);
    Complex divided(0,0);
    Complex multiplied(0,0);
    added = Complex::addition(firstNumber, secondNumber);
    divided = Complex::division(firstNumber, secondNumber);
    multiplied = Complex::multiplication(firstNumber, secondNumber);
    added.printNumber();
    cout << endl;
    divided.printNumber();
    cout << endl;
    multiplied.printNumber();
    KeyStorage <int> theKeyStorage(2,5);
    cout << theKeyStorage.get();
    return 0;
}
