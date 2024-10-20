#include "param.h"

struct proc_info {
  char name[16];
  int pid;
  int ppid;
  char state[16];
};

struct child_processes {
  int count;
  struct proc_info processes[NPROC];
};