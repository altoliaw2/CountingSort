#include <iostream>

void fn_CoSort(int* ip_IA, int* ip_OA, int i_Size, int i_Max);

int main() {

    int ia_Arr[]    = {5, 5, 3, 4, 4, 1, 3};
    int i_Max       = 5;
    int i_Size      = sizeof(ia_Arr)/sizeof(int);
    int* ip_2Arr    = new int[i_Size]{};
    fn_CoSort(ia_Arr, ip_2Arr, i_Size, i_Max);

    for(int i_Ct = 0; i_Ct < i_Size; i_Ct++){
        std::cout<< ip_2Arr[i_Ct] << " ";
    }

    delete [] ip_2Arr;
	return 0;
}

void fn_CoSort(int* ip_IA, int* ip_OA, int i_Size, int i_Max) {
    int* ip_CtArr   = new int[(i_Max + 1)]{};

	for (int i_Ct = 0; i_Ct < i_Size; i_Ct++){
		ip_CtArr[ip_IA[i_Ct]]++;
	}

	for(int i_Ct = 1; i_Ct < (i_Max + 1); i_Ct++){
        ip_CtArr[i_Ct]  += ip_CtArr[i_Ct - 1];
	}

	for(int i_Ct= (i_Size -1) ; i_Ct>= 0; i_Ct--){
        int i_Val       = ip_IA[i_Ct];
        int i_Ind       = --ip_CtArr[i_Val];
        ip_OA[i_Ind]    = i_Val;
	}

	delete [] ip_CtArr;
}
