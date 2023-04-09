#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto

  filas=3;
  columnas=3;
  ptr=new float*[3];
  for(int i=0; i<3;i++)
    ptr[i]=new float[3];
  for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
          ptr[i][j]=static_cast <float> (rand())/static_cast<float>(RAND_MAX);
      }
  }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
  filas=n;
  columnas=n;
  ptr=new float*[filas];
  for(int i=0; i<filas;i++)
    ptr[i]=new float[columnas];
  for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
          ptr[i][j]=static_cast <float> (rand())/static_cast<float>(RAND_MAX);
      }
  }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
  filas=n;
  columnas=m;
  ptr=new float*[filas];
  for(int i=0; i<filas;i++)
    ptr[i]=new float[columnas];
  for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
          ptr[i][j]=static_cast <float> (rand())/static_cast<float>(RAND_MAX);
      }
  }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
  filas=m.filas;
  columnas=m.columnas;
  ptr=new float*[filas];
  for(int i=0; i<filas;i++)
      ptr[i]=new float[columnas];
  for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
          ptr[i][j]=m.ptr[i][j];
      }
  }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    filas=m.filas;
    columnas=m.columnas;
    ptr=new float*[filas];
    for(int i=0; i<filas;i++)
        ptr[i]=new float[columnas];
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ptr[i][j]=m.ptr[i][j];
        }
    }
    for (int i = 0; i < filas; ++i) {
        delete(m.ptr[i]);
    }
    delete(m.ptr);
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
  int f=m.columnas;
  int c=m.filas;
  Matriz2D r(f, c);
  for (int i = 0; i < f; ++i) {
      for (int j = 0; j < c; ++j) {
            r.ptr[i][j]=m.ptr[j][i];
      }
  }
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            os<<m.ptr[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D m(m1.filas, m1.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            m.ptr[i][j]=m1.ptr[i][j]+m2.ptr[i][j];
        }
    }
    return m;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D m(m1.filas, m1.columnas);
    for (int i = 0; i < m.filas; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            m.ptr[i][j]=m1.ptr[i][j]-m2.ptr[i][j];
        }
    }
    return m;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D m(m1.filas, m2.columnas);
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m2.columnas; ++j) {
            m.ptr[i][j]=0;
        }
    }
    for (int i = 0; i < m1.filas; ++i) {
        for (int j = 0; j < m2.columnas; ++j) {
            for (int k = 0; k < m1.columnas; ++k) {
                m.ptr[i][j]+=m1.ptr[i][k] * m2.ptr[k][j];
            }
        }
    }
    return m;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D r=m;
    for (int i = 0; i < r.filas; ++i) {
        for (int j = 0; j < r.columnas; ++j) {
            r.ptr[i][j]+=n;
        }
    }
    return r;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D r=m;
    for (int i = 0; i < r.filas; ++i) {
        for (int j = 0; j < r.columnas; ++j) {
            r.ptr[i][j]=r.ptr[i][j] - n;
        }
    }
    return r;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D r=m;
    for (int i = 0; i < r.filas; ++i) {
        for (int j = 0; j < r.columnas; ++j) {
            r.ptr[i][j]=r.ptr[i][j] * n;
        }
    }
    return r;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D r=m;
    for (int i = 0; i < r.filas; ++i) {
        for (int j = 0; j < r.columnas; ++j) {
            r.ptr[i][j]=r.ptr[i][j] / n;
        }
    }
    return r;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
