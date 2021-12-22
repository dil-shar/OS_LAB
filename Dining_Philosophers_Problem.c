#include <stdio.h>

typedef struct philo
{
int left;
int right;
int finished;
}philosophers;
void picked(int fork,int philono)
{
    printf("Philosopher %d picked fork%d\n",philono,fork);
}
void eat(int philono)
{
    printf("Philosopher %d has finished eating \n",philono);

}
void waitingforfork(int fork,int philno)
{
    printf("Philosopher %d is waiting for fork%d\n",philno,fork);
}

void startdinner(int nofphil,int* hungry,int nofhung)
{
  philosophers p[30];
   int i,j,count = nofphil,fork[30];
  for(int i = 0;i<nofphil;i++)
  {
     
      p[i].left = -1;
      p[i].right = -1;
      p[i].finished = 1;
      fork[i] = 1;

  }
  for(i = 0;i<nofhung;i++)
  {
      p[hungry[i]].finished = -1;
      count--;
  }
  while(count!=nofphil)
  {
      int flag = 0;
      for(j = 0;j<nofphil;j++)
      {
          if(p[j].finished==-1)
          {
              if(j!=nofphil-1)
              {
                  if(fork[j]==1){
                      picked(j,j);
                      p[j].left = 1;
                      fork[j] = -1;
                    //   continue;
                  }
                  else if(p[j].left!=1)
                  waitingforfork(j,j);

                  if(fork[(j+1)%nofphil]==1)
                  {
                      picked((j+1)%nofphil,j);
                      p[j].right = 1;
                      fork[(j+1)%nofphil] = -1;
                      continue;

                  }
                  else if(p[j].right != 1)
                  waitingforfork((j+1)%nofphil,j);
                
                  if(p[j].left==1 && p[j].right==1)
                  {
                        eat(j);
                        p[j].finished = 1;
                        count++;
                        fork[j] = 1;
                        fork[(j+1)%nofphil] = 1;
                        break;
                  }
                  
              }
              else
              {
                  
                  if(fork[(j+1)%nofphil]==1)
                  {
                      picked((j+1)%nofphil,j);
                      p[j].right = 1;
                      fork[(j+1)%nofphil] = -1;
                    //   continue;
                  }
                  else if(p[j].right!=1)
                  waitingforfork((j+1)%nofphil,j);

                  if(fork[j]==1){
                      picked(j,j);
                      p[j].left = 1;
                      fork[j] = -1;
                      
                  }
                  else if(p[j].left!=1)
                  waitingforfork(j,j);
                  
                  
                  if(p[j].left==1 && p[j].right==1)
                  {
                        eat(j);
                        p[j].finished = 1;
                        count++;
                        fork[j] = 1;
                        fork[(j+1)%nofphil] = 1;
                        break;
                  }
              }
          }
          if(count==nofphil) break;
      }
      if(count==nofphil) break;
  }
}
void main()
{
    int nofphil,tot[20],n;
    printf("Enter the total number of philosophers sitting around the table\n");
    scanf("%d",&nofphil);
    printf("Enter the no of hungry philosophers\n");
    scanf("%d",&n);
    printf("Enter the indices of philosophers hungry\n");
    for(int i = 0;i < n;i++) scanf("%d",tot+i);
    startdinner(nofphil,tot,n);
}
