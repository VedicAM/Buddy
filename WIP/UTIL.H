#ifndef UTIL_H
#define UTIL_H

int arrayLength(int array[]){
 int i;
 int count = 0;

 for(i = 0; array[i] != '\0'; i++){
  count++;
 }

 return count;
}

#endif