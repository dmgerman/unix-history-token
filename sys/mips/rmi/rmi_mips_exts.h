begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MIPS_EXTS_H__
end_ifndef

begin_define
define|#
directive|define
name|__MIPS_EXTS_H__
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_IFU
value|0
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_ICU
value|1
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_IEU
value|2
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_LSU
value|3
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_MMU
value|4
end_define

begin_define
define|#
directive|define
name|CPU_BLOCKID_PRF
value|5
end_define

begin_define
define|#
directive|define
name|LSU_CERRLOG_REGID
value|9
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

begin_function
specifier|static
name|__inline
name|uint64_t
name|read_xlr_ctrl_register
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
name|uint64_t
name|res
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n\t" 	    ".set	noreorder\n\t" 	    "move	$9, %1\n\t" 	    ".word	0x71280018\n\t"
comment|/* mfcr $8, $9 */
asm|"move	%0, $8\n\t" 	    ".set	pop\n" 	    : "=r" (res) : "r"((block<< 8) | reg) 	    : "$8", "$9" 	);
return|return
operator|(
name|res
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|write_xlr_ctrl_register
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n\t" 	    ".set	noreorder\n\t" 	    "move	$8, %0\n" 	    "move	$9, %1\n" 	    ".word	0x71280019\n"
comment|/* mtcr $8, $9  */
asm|".set	pop\n" 	    : 	    : "r" (value), "r" ((block<< 8) | reg) 	    : "$8", "$9" 	);
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(defined(__mips_n64) || defined(__mips_n32)) */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|read_xlr_ctrl_register
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
name|uint32_t
name|high
decl_stmt|,
name|low
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push\n\t" 	    ".set	noreorder\n\t" 	    ".set	mips64\n\t" 	    "move	$9, %2\n" 	    ".word 	0x71280018\n"
comment|/* "mfcr    $8, $9\n" */
asm|"dsra32	%0, $8, 0\n\t" 	    "sll	%1, $8, 0\n\t" 	    ".set	pop"					 	    : "=r" (high), "=r"(low) 	    : "r" ((block<< 8) | reg) 	    : "$8", "$9");
return|return
operator|(
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|high
operator|)
operator|<<
literal|32
operator|)
operator||
name|low
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|write_xlr_ctrl_register
parameter_list|(
name|int
name|block
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|uint32_t
name|low
decl_stmt|,
name|high
decl_stmt|;
name|high
operator|=
name|value
operator|>>
literal|32
expr_stmt|;
name|low
operator|=
name|value
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	   ".set	push\n\t" 	   ".set	noreorder\n\t" 	   ".set	mips64\n\t" 	   "dsll32	$9, %0, 0\n\t" 	   "dsll32	$8, %1, 0\n\t" 	   "dsrl32	$8, $8, 0\n\t" 	   "or		$8, $9, $8\n\t" 	   "move	$9, %2\n\t" 	   ".word	0x71280019\n\t"
comment|/* mtcr $8, $9 */
asm|".set	pop\n" 	   :
comment|/* No outputs */
asm|: "r" (high), "r" (low), "r"((block<< 8) | reg) 	   : "$8", "$9");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__mips_n64) || defined(__mips_n32) */
end_comment

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

begin_define
define|#
directive|define
name|read_c2_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({								\ 	uint32_t __rv;						\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips32\n\t"				\ 	    "mfc2	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	    : "=r" (__rv) : "i" (reg), "i" (sel) );		\ 	__rv;							\  })
end_define

begin_define
define|#
directive|define
name|write_c2_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips32\n\t"				\ 	    "mtc2	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	: : "r" (value), "i" (reg), "i" (sel) );
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

begin_define
define|#
directive|define
name|read_c2_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({								\ 	uint64_t __rv;						\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dmfc2	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	    : "=r" (__rv) : "i" (reg), "i" (sel) );		\ 	__rv;							\  })
end_define

begin_define
define|#
directive|define
name|write_c2_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dmtc2	%0, $%1, %2\n\t"			\ 	    ".set	pop\n"					\ 	: : "r" (value), "i" (reg), "i" (sel) );
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

begin_define
define|#
directive|define
name|read_c2_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({								\ 	uint32_t __high, __low;					\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	noreorder\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dmfc2	$8, $%2, %3\n\t"			\ 	    "dsra32	%0, $8, 0\n\t"				\ 	    "sll	%1, $8, 0\n\t"				\ 	    ".set	pop\n"					\ 	    : "=r"(__high), "=r"(__low): "i"(reg), "i"(sel)	\ 	    : "$8");						\ 	((uint64_t)__high<< 32) | __low;			\ })
end_define

begin_define
define|#
directive|define
name|write_c2_register64
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|value
parameter_list|)
define|\
value|do {								\        uint32_t __high = value>> 32;				\        uint32_t __low = value& 0xffffffff;			\ 	__asm__ __volatile__(					\ 	    ".set	push\n\t"				\ 	    ".set	noreorder\n\t"				\ 	    ".set	mips64\n\t"				\ 	    "dsll32	$8, %1, 0\n\t"				\ 	    "dsll32	$9, %0, 0\n\t"				\ 	    "dsrl32	$8, $8, 0\n\t"				\ 	    "or		$8, $8, $9\n\t"				\ 	    "dmtc2	$8, $%2, %3\n\t"			\ 	    ".set	pop"					\ 	    :: "r"(__high), "r"(__low),	 "i"(reg), "i"(sel)	\ 	    :"$8", "$9");					\ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__mips_n64) || defined(__mips_n32) */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|xlr_cpu_id
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
operator|&
literal|0x1f
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|xlr_core_id
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xlr_cpu_id
argument_list|()
operator|/
literal|4
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|xlr_thr_id
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
operator|&
literal|0x3
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Additional registers on the XLR */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_OSSCRATCH
value|22
end_define

begin_define
define|#
directive|define
name|XLR_CACHELINE_SIZE
value|32
end_define

begin_comment
comment|/* functions to write to and read from the extended  * cp0 registers.  * EIRR : Extended Interrupt Request Register  *        cp0 register 9 sel 6  *        bits 0...7 are same as cause register 8...15  * EIMR : Extended Interrupt Mask Register  *        cp0 register 9 sel 7  *        bits 0...7 are same as status register 8...15  */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|read_c0_eirr64
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
name|write_c0_eirr64
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
name|read_c0_eimr64
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
name|write_c0_eimr64
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
name|__inline
name|int
name|xlr_test_and_set
parameter_list|(
name|int
modifier|*
name|lock
parameter_list|)
block|{
name|int
name|oldval
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set push\n" 	    ".set noreorder\n" 	    "move $9, %2\n" 	    "li $8, 1\n"
comment|//      "swapw $8, $9\n"
asm|".word 0x71280014\n" 	    "move %1, $8\n" 	    ".set pop\n" 	    : "+m"(*lock), "=r"(oldval) 	    : "r"((unsigned long)lock) 	    : "$8", "$9" 	);
return|return
operator|(
name|oldval
operator|==
literal|0
condition|?
literal|1
comment|/* success */
else|:
literal|0
comment|/* failure */
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|xlr_mfcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    "move   $8, %1\n" 	    ".word  0x71090018\n" 	    "move   %0, $9\n" 	    : "=r"(val) 	    : "r"(reg):"$8", "$9");
return|return
name|val
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|xlr_mtcr
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( 	    "move   $8, %1\n" 	    "move   $9, %0\n" 	    ".word  0x71090019\n" 	    :: "r"(val), "r"(reg) 	    : "$8", "$9");
block|}
end_function

begin_comment
comment|/*  * Atomic increment a unsigned  int  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|xlr_ldaddwu
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|uint32_t
name|xlr_paddr_lw
parameter_list|(
name|uint64_t
name|paddr
parameter_list|)
block|{
name|paddr
operator||=
literal|0x9800000000000000ULL
expr_stmt|;
return|return
operator|(
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
name|paddr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|xlr_paddr_ld
parameter_list|(
name|uint64_t
name|paddr
parameter_list|)
block|{
name|paddr
operator||=
literal|0x9800000000000000ULL
expr_stmt|;
return|return
operator|(
operator|*
operator|(
name|uint64_t
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
name|paddr
operator|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_elif

begin_function
specifier|static
name|__inline
name|uint32_t
name|xlr_paddr_lw
parameter_list|(
name|uint64_t
name|paddr
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
name|paddr
operator||=
literal|0x9800000000000000ULL
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "lw		%0, 0(%1)	\n\t" 	    ".set	pop		\n" 	    : "=r"(val) 	    : "r"(paddr));
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|xlr_paddr_ld
parameter_list|(
name|uint64_t
name|paddr
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
name|paddr
operator||=
literal|0x9800000000000000ULL
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "ld		%0, 0(%1)	\n\t" 	    ".set	pop		\n" 	    : "=r"(val) 	    : "r"(paddr));
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* o32 compilation */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|xlr_paddr_lw
parameter_list|(
name|uint64_t
name|paddr
parameter_list|)
block|{
name|uint32_t
name|addrh
decl_stmt|,
name|addrl
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|addrh
operator|=
literal|0x98000000
operator||
operator|(
name|paddr
operator|>>
literal|32
operator|)
expr_stmt|;
name|addrl
operator|=
name|paddr
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	$8, %1, 0	\n\t" 	    "dsll32	$9, %2, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	$9, $9, 0	\n\t"
comment|/* sign extend */
asm|"or		$9, $8, $8	\n\t" 	    "lw		%0, 0($9)	\n\t" 	    ".set	pop		\n" 	    :	"=r"(val) 	    :	"r"(addrh), "r"(addrl) 	    :	"$8", "$9");
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|xlr_paddr_ld
parameter_list|(
name|uint64_t
name|paddr
parameter_list|)
block|{
name|uint32_t
name|addrh
decl_stmt|,
name|addrl
decl_stmt|;
name|uint32_t
name|valh
decl_stmt|,
name|vall
decl_stmt|;
name|addrh
operator|=
literal|0x98000000
operator||
operator|(
name|paddr
operator|>>
literal|32
operator|)
expr_stmt|;
name|addrl
operator|=
name|paddr
operator|&
literal|0xffffffff
expr_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	    ".set	push		\n\t" 	    ".set	mips64		\n\t" 	    "dsll32	%0, %2, 0	\n\t" 	    "dsll32	%1, %3, 0	\n\t"
comment|/* get rid of the */
asm|"dsrl32	%1, %1, 0	\n\t"
comment|/* sign extend */
asm|"or		%0, %0, %1	\n\t" 	    "lw		%1, 4(%0)	\n\t" 	    "lw		%0, 0(%0)	\n\t" 	    ".set	pop		\n" 	    :       "=&r"(valh), "=&r"(vall) 	    :       "r"(addrh), "r"(addrl));
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|valh
operator|<<
literal|32
operator|)
operator||
name|vall
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX: Not really needed in n32 or n64, retain for now  */
end_comment

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

begin_function
specifier|static
name|__inline
name|uint32_t
name|xlr_enable_kx
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|xlr_restore_kx
parameter_list|(
name|uint32_t
name|sr
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined(__mips_n64)&& !defined(__mips_n32) */
end_comment

begin_comment
comment|/*  * o32 compilation, we will disable interrupts and enable  * the KX bit so that we can use XKPHYS to access any 40bit  * physical address  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|xlr_enable_kx
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|sr
init|=
name|mips_rd_status
argument_list|()
decl_stmt|;
name|mips_wr_status
argument_list|(
operator|(
name|sr
operator|&
operator|~
name|MIPS_SR_INT_IE
operator|)
operator||
name|MIPS_SR_KX
argument_list|)
expr_stmt|;
return|return
operator|(
name|sr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|xlr_restore_kx
parameter_list|(
name|uint32_t
name|sr
parameter_list|)
block|{
name|mips_wr_status
argument_list|(
name|sr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__mips_n64) || defined(__mips_n32) */
end_comment

begin_comment
comment|/*  * XLR/XLS processors have maximum 8 cores, and maximum 4 threads  * per core  */
end_comment

begin_define
define|#
directive|define
name|XLR_MAX_CORES
value|8
end_define

begin_define
define|#
directive|define
name|XLR_NTHREADS
value|4
end_define

begin_comment
comment|/*  * FreeBSD can be started with few threads and cores turned off,  * so have a hardware thread id to FreeBSD cpuid mapping.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xlr_ncores
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlr_threads_per_core
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|xlr_hw_thread_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlr_cpuid_to_hwtid
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xlr_hwtid_to_cpuid
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

