begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Kernel interface to machine-dependent clock driver.  * Garrett Wollman, September 1994.  * This file is in the public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CLOCK_H_
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|pentium_mhz
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|I586_CPU
end_ifdef

begin_comment
comment|/* 	 * This resets the CPU cycle counter to zero, to make our 	 * job easier in microtime().  Some fancy ifdefs could speed 	 * this up for Pentium-only kernels. 	 * We want this to be done as close as possible to the actual 	 * timer incrementing in hardclock(), because there is a window 	 * between the two where the value is no longer valid.  Experimentation 	 * may reveal a good precompensation to apply in microtime(). 	 */
end_comment

begin_define
define|#
directive|define
name|CPU_CLOCKUPDATE
parameter_list|(
name|otime
parameter_list|,
name|ntime
parameter_list|)
define|\
value|do { \ 	if(pentium_mhz) { \ 		__asm __volatile("cli\n" \ 				 "movl (%2),%%eax\n" \ 				 "movl %%eax,(%1)\n" \ 				 "movl 4(%2),%%eax\n" \ 				 "movl %%eax,4(%1)\n" \ 				 "movl $0x10,%%ecx\n" \ 				 "xorl %%eax,%%eax\n" \ 				 "movl %%eax,%%edx\n" \ 				 ".byte 0x0f, 0x30\n" \ 				 "sti\n" \ 				 "#%0%1%2" \ 				 : "=m"(*otime)
comment|/* no outputs */
value|\ 				 : "c"(otime), "b"(ntime)
comment|/* fake input */
value|\ 				 : "ax", "cx", "dx"); \ 	} else { \ 		*(otime) = *(ntime); \ 	} \ 	} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPU_CLOCKUPDATE
parameter_list|(
name|otime
parameter_list|,
name|ntime
parameter_list|)
define|\
value|(*(otime) = *(ntime))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CLOCK_H_ */
end_comment

end_unit

