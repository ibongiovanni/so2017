static inline unsigned int xchg(volatile unsigned int * addr, unsigned int newval)
{ unsigned int result;						//      (*addr)  (newval)
 asm volatile ("xchg %0, %1":				//xchgl 8(%ebp), 12(%ebp) 
               "+m" (* addr),"=a" (result): //mov eax -4(%ebp)
              "1" (newval) );
        return result ;
}

