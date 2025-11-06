#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        	T* arr;
		int max;
		int n;
		static const int MINSIZE =2;

		void resize(int new_size){
			
			T * new_arr = new T[new_size];
			delete [] arr;
			arr = new_arr;
	 		max = new_size;
		}
    public:
	ListArray() {
	
		max = MINSIZE;
		n = 0;
		arr = new T[max];
	}

	 ~ListArray(){
	
		delete [] arr;
	}
    	
	T &operator[] (int pos){
	
		if(pos < 0 || pos > n) 
  			throw std::out_of_range("Posición fuera del intervalo");
		
		return arr[pos];
	}
	
	friend std::ostream& operator << (std::ostream &out, const ListArray<T> &list){
	
		out<< "[" ;
		for (int i = 0; i < list.n; i++) {
			out << list.arr[i];
			if ( i < list.n-1)
				out << ",";
		}
		out<< "]";
	return out;
	}

	void insert(int pos, T e) override {
		
		if(pos < 0 || pos > n)
			throw std::out_of_range("Posición inválida en insert()");


		if (n == max)
			resize(max * 2);

		for (int i= n; i > pos; i--)
			arr[i] = arr[i-1];

		arr[pos] = e;
		n++;	

	
	}

	void append(T e) override {
		insert (n, e);

	}		
};
