begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_COP0_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_COP0_H__
end_define

begin_define
define|#
directive|define
name|NLM_C0_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|NLM_C0_RANDOM
value|1
end_define

begin_define
define|#
directive|define
name|NLM_C0_ENTRYLO0
value|2
end_define

begin_define
define|#
directive|define
name|NLM_C0_ENTRYLO1
value|3
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONTEXT
value|4
end_define

begin_define
define|#
directive|define
name|NLM_C0_USERLOCAL
value|4
end_define

begin_define
define|#
directive|define
name|NLM_C0_PAGEMASK
value|5
end_define

begin_define
define|#
directive|define
name|NLM_C0_WIRED
value|6
end_define

begin_define
define|#
directive|define
name|NLM_C0_BADVADDR
value|8
end_define

begin_define
define|#
directive|define
name|NLM_C0_COUNT
value|9
end_define

begin_define
define|#
directive|define
name|NLM_C0_EIRR
value|9
end_define

begin_define
define|#
directive|define
name|NLM_C0_EIMR
value|9
end_define

begin_define
define|#
directive|define
name|NLM_C0_ENTRYHI
value|10
end_define

begin_define
define|#
directive|define
name|NLM_C0_COMPARE
value|11
end_define

begin_define
define|#
directive|define
name|NLM_C0_STATUS
value|12
end_define

begin_define
define|#
directive|define
name|NLM_C0_INTCTL
value|12
end_define

begin_define
define|#
directive|define
name|NLM_C0_SRSCTL
value|12
end_define

begin_define
define|#
directive|define
name|NLM_C0_CAUSE
value|13
end_define

begin_define
define|#
directive|define
name|NLM_C0_EPC
value|14
end_define

begin_define
define|#
directive|define
name|NLM_C0_PRID
value|15
end_define

begin_define
define|#
directive|define
name|NLM_C0_EBASE
value|15
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG0
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG1
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG2
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG3
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG4
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG5
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG6
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_CONFIG7
value|16
end_define

begin_define
define|#
directive|define
name|NLM_C0_WATCHLO
value|18
end_define

begin_define
define|#
directive|define
name|NLM_C0_WATCHHI
value|19
end_define

begin_define
define|#
directive|define
name|NLM_C0_XCONTEXT
value|20
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH0
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH1
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH2
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH3
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH4
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH5
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH6
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_SCRATCH7
value|22
end_define

begin_define
define|#
directive|define
name|NLM_C0_DEBUG
value|23
end_define

begin_define
define|#
directive|define
name|NLM_C0_DEPC
value|24
end_define

begin_define
define|#
directive|define
name|NLM_C0_PERFCNT
value|25
end_define

begin_define
define|#
directive|define
name|NLM_C0_PERFCNT0
value|25
end_define

begin_define
define|#
directive|define
name|NLM_C0_PERFCNT1
value|25
end_define

begin_define
define|#
directive|define
name|NLM_C0_TAGLO
value|28
end_define

begin_define
define|#
directive|define
name|NLM_C0_DATALO
value|28
end_define

begin_define
define|#
directive|define
name|NLM_C0_TAGHI
value|29
end_define

begin_define
define|#
directive|define
name|NLM_C0_DATAHI
value|29
end_define

begin_define
define|#
directive|define
name|NLM_C0_ERROREPC
value|30
end_define

begin_define
define|#
directive|define
name|NLM_C0_DESAVE
value|31
end_define

begin_comment
comment|/* cop0 status bits */
end_comment

begin_define
define|#
directive|define
name|NLM_STATUS_CP0_EN
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|NLM_STATUS_CP1_EN
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|NLM_STATUS_CP2_EN
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|NLM_STATUS_KX_EN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|NLM_STATUS_UX_EN
value|(1<<5)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|nlm_memory_barrier
parameter_list|()
define|\
value|__asm__ __volatile__(			\ 		".set	push\n\t"		\ 		".set	noreorder\n\t"		\ 		" sync\n\t"			\ 		".set	pop"			\ 		::: "memory")
end_define

begin_define
define|#
directive|define
name|NLM_DEFINE_ACCESSORS32
parameter_list|(
name|name
parameter_list|,
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|static __inline__ uint32_t nlm_read_c0_##name(void)			\ {								\ 	uint32_t __rv; 						\         __asm__ __volatile__ (                                  \         ".set	push\n"                                         \         ".set	noreorder\n"                                    \         ".set	mips64\n"                                       \         "mfc0	%0, $%1, %2\n"                                  \         ".set	pop\n"                                          \         : "=r" (__rv)						\ 	: "i" (reg), "i" (sel)					\ 	); 		                			\         return __rv;						\ }								\ 								\ static __inline__ void nlm_write_c0_##name(uint32_t val)	\ {								\         __asm__ __volatile__(                                   \         ".set	push\n"                                         \         ".set	noreorder\n"                                    \         ".set	mips64\n"                                       \         "mtc0	%0, $%1, %2\n"                                  \         ".set	pop\n"                                          \         :: "r" (val), "i" (reg), "i" (sel) 			\ 	);							\ } struct __hack
end_define

begin_comment
comment|/* struct __hack above swallows a semicolon - otherwise the macro  * usage below cannot have the terminating semicolon */
end_comment

begin_if
if|#
directive|if
operator|(
name|__mips
operator|==
literal|64
operator|)
end_if

begin_define
define|#
directive|define
name|NLM_DEFINE_ACCESSORS64
parameter_list|(
name|name
parameter_list|,
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|static __inline__ uint64_t nlm_read_c0_##name(void) 	\ {								\ 	uint64_t __rv;                                \         __asm__ __volatile__ (                                  \         ".set	push\n"                                         \         ".set	noreorder\n"                                    \         ".set	mips64\n"                                       \         "dmfc0	%0,$%1,%2\n"                                    \         ".set	pop\n"                                          \         : "=r" (__rv)						\ 	: "i" (reg), "i" (sel) );                 		\         return __rv;						\ }								\ 								\ static __inline__ void nlm_write_c0_##name(uint64_t val)	\ {								\         __asm__ __volatile__ (                                  \         ".set	push\n"                                         \         ".set	noreorder\n"                                    \         ".set	mips64\n"                                       \         "dmtc0	%0,$%1,%2\n"                                    \         ".set	pop\n"                                          \         :: "r" (val), "i" (reg), "i" (sel) );			\ } struct __hack
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NLM_DEFINE_ACCESSORS64
parameter_list|(
name|name
parameter_list|,
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|static __inline__ uint64_t nlm_read_c0_##name(void)	\ {								\ 	uint32_t __high, __low;                             \         __asm__ __volatile__ (                                  \         ".set	push\n"                                         \         ".set	noreorder\n"                                    \         ".set	mips64\n"                                       \         "dmfc0	$8, $%2, %3\n"                                  \ 	"dsra32	%0, $8, 0\n"					\ 	"sll	%1, $8, 0\n"					\         ".set	pop\n"                                          \         : "=r"(__high), "=r"(__low)				\ 	: "i"(reg), "i"(sel)					\ 	: "$8" );						\ 								\         return (((uint64_t)__high<< 32) | __low);	\ }								\ 								\ static __inline__ void nlm_write_c0_##name(uint64_t val)	\ {								\        uint32_t __high = val>> 32;                           \        uint32_t __low = val& 0xffffffff;                   \         __asm__ __volatile__ (                                  \         ".set	push\n"                                         \         ".set	noreorder\n"                                    \         ".set	mips64\n"                                       \         "dsll32	$8, %1, 0\n"                                    \         "dsll32	$9, %0, 0\n"                                    \ 	"dsrl32	$8, $8, 0\n"					\         "or	$8, $8, $9\n"                                   \         "dmtc0	$8, $%2, %3\n"                                  \         ".set	pop\n"                                          \         :: "r"(__high), "r"(__low), "i"(reg), "i"(sel)		\ 	: "$8", "$9");						\ } struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|index
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|random
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|entrylo0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|entrylo1
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|context
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|userlocal
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|pagemask
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|wired
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|badvaddr
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|count
argument_list|,
literal|9
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|eirr
argument_list|,
literal|9
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|eimr
argument_list|,
literal|9
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|entryhi
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|compare
argument_list|,
literal|11
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|status
argument_list|,
literal|12
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|intctl
argument_list|,
literal|12
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|srsctl
argument_list|,
literal|12
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|cause
argument_list|,
literal|13
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|epc
argument_list|,
literal|14
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|prid
argument_list|,
literal|15
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|ebase
argument_list|,
literal|15
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|config0
argument_list|,
literal|16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|config1
argument_list|,
literal|16
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|config2
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|config3
argument_list|,
literal|16
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|config6
argument_list|,
literal|16
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|config7
argument_list|,
literal|16
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|watchlo0
argument_list|,
literal|18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|watchhi0
argument_list|,
literal|19
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|xcontext
argument_list|,
literal|20
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch0
argument_list|,
literal|22
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch1
argument_list|,
literal|22
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch2
argument_list|,
literal|22
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch3
argument_list|,
literal|22
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch4
argument_list|,
literal|22
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch5
argument_list|,
literal|22
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch6
argument_list|,
literal|22
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|scratch7
argument_list|,
literal|22
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|debug
argument_list|,
literal|23
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|depc
argument_list|,
literal|24
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|perfctrl0
argument_list|,
literal|25
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|perfcntr0
argument_list|,
literal|25
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|perfctrl1
argument_list|,
literal|25
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|perfcntr1
argument_list|,
literal|25
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|perfctrl2
argument_list|,
literal|25
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|perfcntr2
argument_list|,
literal|25
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS32
argument_list|(
name|perfctrl3
argument_list|,
literal|25
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|perfcntr3
argument_list|,
literal|25
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|taglo0
argument_list|,
literal|28
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|taglo2
argument_list|,
literal|28
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|taghi0
argument_list|,
literal|29
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|taghi2
argument_list|,
literal|29
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|errorepc
argument_list|,
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NLM_DEFINE_ACCESSORS64
argument_list|(
name|desave
argument_list|,
literal|31
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|__inline__
name|int
name|nlm_nodeid
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_c0_ebase
argument_list|()
operator|>>
literal|5
operator|)
operator|&
literal|0x3
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_cpuid
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|nlm_read_c0_ebase
argument_list|()
operator|&
literal|0x1f
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_threadid
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|nlm_read_c0_ebase
argument_list|()
operator|&
literal|0x3
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_coreid
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_c0_ebase
argument_list|()
operator|>>
literal|2
operator|)
operator|&
literal|0x7
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

