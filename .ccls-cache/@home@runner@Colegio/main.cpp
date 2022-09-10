#include <iostream>
using namespace std;

int n_est;

struct estudiante
{
  int cod;
  int notas[4];
};

int leer_nota()
{
  int nota;
  do
  {
    cout<<"digite la nota: ";
    cin>>nota;
    
  }
  while(nota<0 || nota >50);
  return nota;
}

int nota_aprob(int notapro)
{
  bool v = true, f = false;
  if (notapro<30)
  {
    return f;
  }
  else
  {
    return v;
  }
  
}

estudiante leer_est()
{
  estudiante e;
  cout<<"\nDigite el codigo del estudiante: ";
  cin>>e.cod;
  for (int i=0; i<4; i++)
  {
    e.notas[i] = leer_nota();
  }
  return e;  
}

int prom_est (estudiante e)
{
  int prom = 0;
  for(int i = 0; i < 4; i++)
  {
    prom += e.notas[i];
  }
  return prom/4.0+0.5;
}

void imp_est(estudiante e)
{
  cout<<e.cod<<"  ";
  for(int i = 0; i < 4; i++)
  {
    cout<<e.notas[i]<<"  ";
  }
  cout<<prom_est(e)<<"  ";
  if (nota_aprob(prom_est(e))== 0)
  {
    cout<<"Reprobado"<<endl;
  }
  else
  {
    cout<<"Aprobado"<<endl;
  }
}

struct curso
{
  int cod;
  estudiante est[10];
};

curso leer_curso()
{
  curso c;
  cout<<"Digite el codigo del curso: ";
  cin>>c.cod;
  cout<<"Cuantos estudiantes desea ingresar (Maximo 10)";
  cin>>n_est;
  for(int i = 0; i < n_est and i < 10; i++)
  {
    c.est[i] = leer_est();
  }
  return c;
}

void imp_curso(curso c)
{
  for(int i = 0; i < n_est; i++)
  {
    imp_est(c.est[i]);
  }
}


int main() 
{ 
  
  imp_curso(leer_curso());
}