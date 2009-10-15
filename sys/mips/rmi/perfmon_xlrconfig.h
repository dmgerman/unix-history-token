begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XLR_PERFMON
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|XLRCONFIG_PERFMON_H
end_ifndef

begin_define
define|#
directive|define
name|XLRCONFIG_PERFMON_H
end_define

begin_include
include|#
directive|include
file|<mips/xlr/perfmon_utils.h>
end_include

begin_comment
comment|/* for DPRINT */
end_comment

begin_define
define|#
directive|define
name|NCPUS
value|32
end_define

begin_define
define|#
directive|define
name|NCORES
value|8
end_define

begin_define
define|#
directive|define
name|NTHREADS
value|4
end_define

begin_define
define|#
directive|define
name|PERF_SAMPLE_BUFSZ
value|32
end_define

begin_comment
comment|/*select timeout is 512*1024 microsecs */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SYS_SAMPLING_INTERVAL
value|(512*1024)
end_define

begin_comment
comment|/* default timer value programmed to PIC is 10*1024*1024 */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CPU_SAMPLING_INTERVAL
value|(10*1024)
end_define

begin_define
define|#
directive|define
name|DEFAULT_CC_SAMPLE_RATE
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_CP0_FLAGS
value|0x0A
end_define

begin_define
define|#
directive|define
name|NUM_L2_BANKS
value|8
end_define

begin_define
define|#
directive|define
name|NUM_DRAM_BANKS
value|4
end_define

begin_comment
comment|/* CP0 register for timestamp */
end_comment

begin_define
define|#
directive|define
name|CP0_COUNT
value|9
end_define

begin_define
define|#
directive|define
name|CP0_EIRR_REG
value|9
end_define

begin_define
define|#
directive|define
name|CP0_EIRR_SEL
value|6
end_define

begin_define
define|#
directive|define
name|CP0_EIMR_REG
value|9
end_define

begin_define
define|#
directive|define
name|CP0_EIMR_SEL
value|7
end_define

begin_comment
comment|/* CP0 register for perf counters */
end_comment

begin_define
define|#
directive|define
name|CP0_PERF_COUNTER
value|25
end_define

begin_comment
comment|/* selector values */
end_comment

begin_define
define|#
directive|define
name|PERFCNTRCTL0
value|0
end_define

begin_define
define|#
directive|define
name|PERFCNTR0
value|1
end_define

begin_define
define|#
directive|define
name|PERFCNTRCTL1
value|2
end_define

begin_define
define|#
directive|define
name|PERFCNTR1
value|3
end_define

begin_define
define|#
directive|define
name|XLR_IO_PIC_OFFSET
value|0x08000
end_define

begin_define
define|#
directive|define
name|PIC_SYS_TIMER_0_BASE
value|0x120
end_define

begin_define
define|#
directive|define
name|PIC_SYS_TIMER_NUM_6
value|6
end_define

begin_comment
comment|/* CP2 registers for reading credit counters */
end_comment

begin_define
define|#
directive|define
name|CC_REG0
value|16
end_define

begin_define
define|#
directive|define
name|read_c0_register
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({ unsigned int __rv;                                           \         __asm__ __volatile__(                                   \ 	".set\tpush\n\t"					\         ".set mips32\n\t"                                       \         "mfc0\t%0,$%1,%2\n\t"                                   \ 	".set\tpop"						\         : "=r" (__rv) : "i" (reg), "i" (sel) );                 \         __rv;})
end_define

begin_define
define|#
directive|define
name|write_c0_register
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(                                   \ 	".set\tpush\n\t"					\         ".set mips32\n\t"                                       \         "mtc0\t%0,$%1,%2\n\t"                                   \ 	".set\tpop"						\         : : "r" (value), "i" (reg), "i" (sel) );
end_define

begin_define
define|#
directive|define
name|read_c2_register
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({ unsigned int __rv;                                           \         __asm__ __volatile__(                                   \ 	".set\tpush\n\t"					\         ".set mips32\n\t"                                       \         "mfc0\t%0,$%1,%2\n\t"                                   \ 	".set\tpop"					 	\         : "=r" (__rv) : "i"(reg), "i" (sel) );                  \         __rv;})
end_define

begin_comment
comment|/*  * We have 128 registers in C2 credit counters, reading them one at  * a time using bitmap will take a lot of code, so we have two functions  * to read registers sel0-3 and sel 4-7 into one 32 bit word.  */
end_comment

begin_define
define|#
directive|define
name|read_cc_registers_0123
parameter_list|(
name|reg
parameter_list|)
define|\
value|({     	      						       \ 	unsigned int __rv;				       \ 							       \         __asm__ __volatile__(				       \ 		".set	push\n\t"			       \ 		".set	mips32\n\t"			       \ 		".set	noreorder\n\t"			       \ 		"mfc2	%0, $%1, 0\n\t"	                       \ 		"mfc2	$8, $%1, 1\n\t"	                       \ 		"sll    %0, %0, 8\n\t"			       \ 		"or     %0, %0, $8\n\t"			       \ 		"mfc2	$8, $%1, 2\n\t"	                       \ 		"sll    %0, %0, 8\n\t"			       \ 		"or     %0, %0, $8\n\t"			       \ 		"mfc2	$8, $%1, 3\n\t"	                       \ 		"sll    %0, %0, 8\n\t"			       \ 		"or     %0, %0, $8\n\t"			       \ 		".set	pop"				       \ 		: "=r" (__rv) : "i"(reg) : "$8");	       \ 							       \        __rv;						       \ })
end_define

begin_define
define|#
directive|define
name|read_cc_registers_4567
parameter_list|(
name|reg
parameter_list|)
define|\
value|({     	      						       \ 	unsigned int __rv;				       \ 							       \         __asm__ __volatile__(				       \ 		".set	push\n\t"			       \ 		".set	mips32\n\t"			       \ 		".set	noreorder\n\t"			       \ 		"mfc2	%0, $%1, 4\n\t"	                       \ 		"mfc2	$8, $%1, 5\n\t"	                       \ 		"sll    %0, %0, 8\n\t"			       \ 		"or     %0, %0, $8\n\t"			       \ 		"mfc2	$8, $%1, 6\n\t"	                       \ 		"sll    %0, %0, 8\n\t"			       \ 		"or     %0, %0, $8\n\t"			       \ 		"mfc2	$8, $%1, 7\n\t"	                       \ 		"sll    %0, %0, 8\n\t"			       \ 		"or     %0, %0, $8\n\t"			       \ 		".set	pop"				       \ 		: "=r" (__rv) :"i"(reg) : "$8");	       \ 							       \        __rv;						       \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

