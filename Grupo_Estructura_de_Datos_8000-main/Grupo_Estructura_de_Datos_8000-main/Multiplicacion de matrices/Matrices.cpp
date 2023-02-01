#include "Matrices.h"
#include "Validacion.cpp"

template <typename T>
Matrices<T>::Matrices(){
	mat1=(T **)calloc (3,sizeof(T*));
	mat2=(T **)calloc (3,sizeof(T*));
	matR=(T **)calloc (3,sizeof(T*));
	//fa=0; fb=0; ca=0; cb=0,k=0;
	//k=ca;
}

template <typename T>
T** Matrices<T>::getMat1(){
	return mat1;
}

template <typename T>
T** Matrices<T>::getMat2(){
	return mat2;
}

template <typename T>
T** Matrices<T>::getMatR(){
	return matR;
}

template <typename T>
T Matrices<T>::getFa(){
	return fa;	
}

template <typename T>
T Matrices<T>::getFb(){
	return fb;
}

template <typename T>
T Matrices<T>::getCa(){
	return ca;	
}

template <typename T>
T Matrices<T>::getCb(){
	return cb;
}

template <typename T>
T Matrices<T>::getK(){
	return k;
}

template <typename T>
void Matrices<T>::setMat1(T** otroMat1){
	mat1=otroMat1;
}

template <typename T>
void Matrices<T>::setMat2(T** otroMat2){
	mat2=otroMat2;
}

template <typename T>
void Matrices<T>::setMatR(T** otroMatR){
	matR=otroMatR;
}

template <typename T>
void Matrices<T>::setFa(T otroFa){
	fa=otroFa;	
}

template <typename T>
void Matrices<T>::setFb(T otroFb){
	fb=otroFb;	
}

template <typename T>
void Matrices<T>::setCa(T otroCa){
	ca=otroCa;
}

template <typename T>
void Matrices<T>::setCb(T otroCb){
	cb=otroCb;	
}

template <typename T>
void Matrices<T>::setK(T otroK){
	k=otroK;	
}

template <typename T>
void Matrices<T>::multiplicacionMatrices(T **mat1, T **mat2, T **matR){
	for(int i=0;i<fa;i++){
		for(int j=0;j<cb;j++){
			*(*(matR+i)+j)=0; //C[i][j]=0;
				for(int k=0;k<ca;k++){
					*(*(matR+i)+j)+=(*(*(mat1+i)+k)) * (*(*(mat2+k)+j)); //	C[i][j]+=A[i][k]*B[k][j];
				}
		}
	}
}

template <typename T>
void Matrices<T>::encerarMatriz(){
	for(int j=0;j<3;j++){
		*(mat1+j)=(T*)calloc(3,sizeof(T*));
		*(mat2+j)=(T*)calloc(3,sizeof(T*));
		*(matR+j)=(T*)calloc(3,sizeof(T*));
	} 
}

template <typename T>
void Matrices<T>::llenarMatrizRandom(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			*(*(mat1+i)+j)=(T)((rand()/32768.1)*1000); //mat1[i][j]=numero int randomico
			*(*(mat2+i)+j)=(T)((rand()/32768.1)*1000); //mat2[i][j]=numero int randomico
			*(*(matR+i)+j)=0; 							 //matR[i][j]=0 de inicializacion
		}
	}
}

template <typename T>
void Matrices<T>::llenarMatrizA(){
	for(int i=0;i<fa;i++){
		for(int j=0;j<ca;j++){
			cout<<"\nA["<<i<<"] ["<<j<<"]: ";
			cin>>*(*(mat1+i)+j); 
			}
	}
}
	
template <typename T>	
void Matrices<T>::llenarMatrizB(){
	for(int i=0;i<fb;i++){
		for(int j=0;j<cb;j++){
			cout<<"\nB["<<i<<"] ["<<j<<"]: ";
			cin>>*(*(mat2+i)+j); 
		}
	}	
}
template <typename T>
void Matrices<T>::imprimirMatriz(T **matAux,char *charMat){
	cout<<"\n La matriz " <<*charMat<< " es :\n";
	for(int i=0;i<fa;i++){
		for(int j=0;j<cb;j++){
			printf("%d",*(*(matAux+i)+j));
			printf("%*s",j+4,"");
		}
		cout<<"\n";
	}
}

template <typename T>
void Matrices<T>::multiplicacionRecursivaMatrizA(T** mat1,T** mat2,T** matR,T i){
	if (i<fa)
       {
           multiplicacionRecursivaMatrizB(mat1,mat2,matR,i,0);
           multiplicacionRecursivaMatrizA(mat1,mat2,matR,i+1);
       }
}
   
template <typename T>
 void Matrices<T>::multiplicacionRecursivaMatrizB(T** mat1,T** mat2,T** matR, T i, T j){
 	if(j<cb){
 			multiplicacionRecursiva(mat1,mat2,matR,i,j,0);
           	multiplicacionRecursivaMatrizB(mat1,mat2,matR,i,j+1);
	 }
 }

template <typename T>
void Matrices<T>::multiplicacionRecursiva(T** mat1,T** mat2,T** matR,T i,T j,T k){
	if(k<ca){
	(*(*(matR+i)+j)) +=(*(*(mat1+i)+k)) * (*(*(mat2+k)+j)); //	C[i][j]+=A[i][k]*B[k][j];	
	multiplicacionRecursiva(mat1,mat2,matR,i,j,k+1);
	}
}


