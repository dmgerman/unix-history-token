begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_MIPS_EXTNS_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_MIPS_EXTNS_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_function
specifier|static
name|__inline__
name|int32_t
name|nlm_swapw
parameter_list|(
name|int32_t
modifier|*
name|loc
parameter_list|,
name|int32_t
name|val
parameter_list|)
block|{
name|int32_t
name|oldval
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		"move $9, %2\n" 		"move $8, %3\n" 		".word 0x71280014\n"
comment|/* "swapw $8, $9\n" */
asm|"move %1, $8\n" 		".set pop\n" 		: "+m" (*loc), "=r" (oldval) 		: "r" (loc), "r" (val) 		: "$8", "$9" );
return|return
name|oldval
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_swapwu
parameter_list|(
name|int32_t
modifier|*
name|loc
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|oldval
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		"move $9, %2\n" 		"move $8, %3\n" 		".word 0x71280015\n"
comment|/* "swapwu $8, $9\n" */
asm|"move %1, $8\n" 		".set pop\n" 		: "+m" (*loc), "=r" (oldval) 		: "r" (loc), "r" (val) 		: "$8", "$9" );
return|return
name|oldval
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|(
name|__mips
operator|==
literal|64
operator|)
end_if

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_swapd
parameter_list|(
name|int32_t
modifier|*
name|loc
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|oldval
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 		".set push\n" 		".set noreorder\n" 		"move $9, %2\n" 		"move $8, %3\n" 		".word 0x71280014\n"
comment|/* "swapw $8, $9\n" */
asm|"move %1, $8\n" 		".set pop\n" 		: "+m" (*loc), "=r" (oldval) 		: "r" (loc), "r" (val) 		: "$8", "$9" );
return|return
name|oldval
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Atomic increment a unsigned  int  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|nlm_ldaddwu
parameter_list|(
name|unsigned
name|int
name|value
parameter_list|,
name|unsigned
name|int
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n" 	    ".set	noreorder\n" 	    "move	$8, %2\n" 	    "move	$9, %3\n" 	    ".word	0x71280011\n"
comment|/* ldaddwu $8, $9 */
asm|"move	%0, $8\n" 	    ".set	pop\n" 	    : "=&r"(value), "+m"(*addr) 	    : "0"(value), "r" ((unsigned long)addr) 	    :  "$8", "$9");
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * 32 bit read write for c0  */
end_comment

begin_define
define|#
directive|define
name|read_c0_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({								\ 	 uint32_t __rv;						\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips32\n\t"				\ 	    "mfc0	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	    : "=r" (__rv) : "i" (reg), "i" (sel) );		\ 	__rv;							\  })
end_define

begin_define
define|#
directive|define
name|write_c0_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips32\n\t"				\ 	    "mtc0	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	: : "r" (value), "i" (reg), "i" (sel) );
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/*  * On 64 bit compilation, the operations are simple  */
end_comment

begin_define
define|#
directive|define
name|read_c0_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({								\ 	uint64_t __rv;						\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dmfc0	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	    : "=r" (__rv) : "i" (reg), "i" (sel) );		\ 	__rv;							\  })
end_define

begin_define
define|#
directive|define
name|write_c0_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dmtc0	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	: : "r" (value), "i" (reg), "i" (sel) );
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (defined(__mips_n64) || defined(__mips_n32)) */
end_comment

begin_comment
comment|/*  * 32 bit compilation, 64 bit values has to split   */
end_comment

begin_define
define|#
directive|define
name|read_c0_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({								\ 	uint32_t __high, __low;					\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	noreorder\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dmfc0	$8, $%2, %3\n\t"			\ 	    "dsra32	%0, $8, 0\n\t"				\ 	    "sll	%1, $8, 0\n\t"				\ 	    ".set	pop\n"					\ 	    : "=r"(__high), "=r"(__low): "i"(reg), "i"(sel)	\ 	    : "$8");						\ 	((uint64_t)__high<< 32) | __low;			\ })
end_define

begin_define
define|#
directive|define
name|write_c0_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|do {								\        uint32_t __high = value>> 32;				\        uint32_t __low = value& 0xffffffff;			\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	noreorder\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dsll32	$8, %1, 0\n\t"				\ 	    "dsll32	$9, %0, 0\n\t"				\ 	    "dsrl32	$8, $8, 0\n\t"				\ 	    "or		$8, $8, $9\n\t"				\ 	    "dmtc0	$8, $%2, %3\n\t"			\ 	    ".set	pop"					\ 	    :: "r"(__high), "r"(__low),	 "i"(reg), "i"(sel)	\ 	    :"$8", "$9");					\ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* functions to write to and read from the extended  * cp0 registers.  * EIRR : Extended Interrupt Request Register  *        cp0 register 9 sel 6  *        bits 0...7 are same as cause register 8...15  * EIMR : Extended Interrupt Mask Register  *        cp0 register 9 sel 7  *        bits 0...7 are same as status register 8...15  */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|nlm_read_c0_eirr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|read_c0_register64
argument_list|(
literal|9
argument_list|,
literal|6
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|nlm_write_c0_eirr
parameter_list|(
name|uint64_t
name|val
parameter_list|)
block|{
name|write_c0_register64
argument_list|(
literal|9
argument_list|,
literal|6
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|nlm_read_c0_eimr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|read_c0_register64
argument_list|(
literal|9
argument_list|,
literal|7
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|nlm_write_c0_eimr
parameter_list|(
name|uint64_t
name|val
parameter_list|)
block|{
name|write_c0_register64
argument_list|(
literal|9
argument_list|,
literal|7
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_read_c0_ebase
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|read_c0_register32
argument_list|(
literal|15
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

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

begin_define
define|#
directive|define
name|XLP_MAX_NODES
value|4
end_define

begin_define
define|#
directive|define
name|XLP_MAX_CORES
value|8
end_define

begin_define
define|#
directive|define
name|XLP_MAX_THREADS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

