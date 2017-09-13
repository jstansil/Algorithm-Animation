#ifndef SORTER_H
#define SORTER_H
#include<vector>

class Sorter{
    public:

	Sorter(){}

	~Sorter(){}

	void insert_step(std::vector<int> &a, int index, int result[]){
		index = result[0];
		if (index == 0) { index == 1; }
		if (index == a.size()) { 
			result[0] = -1; 
			return;
		} //return -1 if we've finished
		for (int j = index; j >= 1; j--)
		{
			if (a[j] < a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				result[1] = j - 1;
				return;
			}
		}
		index++;
		result[0] = index;
		return;  //else, return the index for the next iteration
	}

	void bubble_step(std::vector<int> &a, int index, int result[]){
		index = result[0];
		if(index == a.size()-1){ 
			result[0] = -1;
			return;
		} //return -1 if we've finished
		for (int j = index; j < a.size() - 1; j++){
			for(int k = 0; k < a.size() - 1; k++)
			{
				if(a[k] > a[k+1]){
					int temp = a[k];
					a[k] = a[k+ 1];
					a[k + 1] = temp;
					result[1] = k;
					return;
				}
			}
			index++;
			result[0] = index;
			return;
		}
	}

	void selection_step(std::vector<int> &a, int index, int result[]) {
		index = result[0];
		if (index == a.size()) {
				result[0] = -1;
				return;
		} //return -1 if we've finished
		for (int j = index; j <a.size() - 1; j++) {
			int min = j;
			for (int k = j + 1; k < a.size(); k++) {
				if (a[k] < a[min]) {
					min = k;

					int temp = a[j];
					a[j] = a[min];
					a[min] = temp;
					result[1] = min;
					return;

				}
			}
			index++;
			result[0] = index;
			return;
		}

	}

	void shell_step(std::vector<int> &a, int gap, int result[]) {

		int i, j, temp;
		gap = result[0] / 2;
		if (gap == 0) {
			result[0] = -1;
			return;
		}//  return -1 if we've finished
		for (i = gap; i < a.size(); i++){
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
					
				temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = temp;
				result[1] = j + gap;
				result[2] = j;
				return;
			}
		}
		result[0] = gap;
		return;
			
	}

};

#endif