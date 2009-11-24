begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pio.h,v 1.2 1998/09/15 10:50:12 pefo Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995-1999 Per Fogelstrom.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Per Fogelstrom.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	JNPR: cpufunc.h,v 1.5 2007/08/09 11:23:32 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUFUNC_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_comment
comment|/*   * These functions are required by user-land atomi ops  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mips_barrier
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile (".set noreorder\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|".set reorder\n\t"
operator|:
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|mips_wbflush
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("sync" : : : "memory");
name|mips_barrier
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|__asm __volatile("mtc0 %0, $12\n"
comment|/* MIPS_COP_0_STATUS */
block|: : "r" (flag));
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mips_read_membar
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Nil */
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mips_write_membar
parameter_list|(
name|void
parameter_list|)
block|{
name|mips_wbflush
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|mips_tlbp
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("tlbp");
name|mips_barrier
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|register_t ret; 	register_t tmp;  	__asm __volatile("mfc0	%0, $12\n"
comment|/* MIPS_COP_0_STATUS */
block|"and	%1, %0, $~1\n"
comment|/* MIPS_SR_INT_IE */
block|"mtc0	%1, $12\n"
comment|/* MIPS_COP_0_STATUS */
block|: "=r" (ret), "=r" (tmp)); 	return (ret);
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mips_tlbr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("tlbr");
name|mips_barrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mips_tlbwi
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("tlbwi");
name|mips_barrier
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|__asm __volatile("mfc %0, $12\n"
comment|/* MIPS_COP_0_STATUS */
block|"or  %0, %0, $1\n"
comment|/* MIPS_SR_INT_IE */
block|"mtc0 %0, $12\n"
comment|/* MIPS_COP_0_STATUS */
block|: "=r" (tmp));
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mips_tlbwr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("tlbwr");
name|mips_barrier
argument_list|()
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX mips64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_RDRW64_COP0
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
define|\
value|static __inline uint64_t					\ mips_rd_ ## n (void)						\ {								\ 	int v0;							\ 	__asm __volatile ("dmfc0 %[v0], $"__XSTRING(r)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n (uint64_t a0)					\ {								\ 	__asm __volatile ("dmtc0 %[a0], $"__XSTRING(r)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_undef
unit|MIPS_RDRW64_COP0(entrylo0, MIPS_COP_0_TLB_LO0); MIPS_RDRW64_COP0(entrylo1, MIPS_COP_0_TLB_LO1); MIPS_RDRW64_COP0(entryhi, MIPS_COP_0_TLB_HI); MIPS_RDRW64_COP0(pagemask, MIPS_COP_0_TLB_PG_MASK); MIPS_RDRW64_COP0(xcontext, MIPS_COP_0_TLB_XCONTEXT);
undef|#
directive|undef
name|MIPS_RDRW64_COP0
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIPS_RDRW32_COP0
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
define|\
value|static __inline uint32_t					\ mips_rd_ ## n (void)						\ {								\ 	int v0;							\ 	__asm __volatile ("mfc0 %[v0], $"__XSTRING(r)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n (uint32_t a0)					\ {								\ 	__asm __volatile ("mtc0 %[a0], $"__XSTRING(r)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_define
define|#
directive|define
name|MIPS_RDRW32_COP0_SEL
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|s
parameter_list|)
define|\
value|static __inline uint32_t					\ mips_rd_ ## n ## s(void)						\ {								\ 	int v0;							\ 	__asm __volatile ("mfc0 %[v0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n ## s(uint32_t a0)					\ {								\ 	__asm __volatile ("mtc0 %[a0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_OCTEON
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|mips_sync_icache
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|".word 0x041f0000\n"
comment|/* xxx ICACHE */
literal|"nop\n"
literal|".set pop\n"
operator|:
operator|:
block|)
function|;
end_function

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|MIPS_RDRW32_COP0
operator|(
name|compare
operator|,
name|MIPS_COP_0_COMPARE
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|config
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|config
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|config
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|config
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|count
argument_list|,
name|MIPS_COP_0_COUNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|index
argument_list|,
name|MIPS_COP_0_TLB_INDEX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|wired
argument_list|,
name|MIPS_COP_0_TLB_WIRED
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|cause
argument_list|,
name|MIPS_COP_0_CAUSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|status
argument_list|,
name|MIPS_COP_0_STATUS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX: Some of these registers are specific to MIPS32. */
end_comment

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|entrylo0
argument_list|,
name|MIPS_COP_0_TLB_LO0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|entrylo1
argument_list|,
name|MIPS_COP_0_TLB_LO1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|entrylow
argument_list|,
name|MIPS_COP_0_TLB_LOW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|entryhi
argument_list|,
name|MIPS_COP_0_TLB_HI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|pagemask
argument_list|,
name|MIPS_COP_0_TLB_PG_MASK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|prid
argument_list|,
name|MIPS_COP_0_PRID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|watchlo
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|watchlo
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|watchlo
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|watchlo
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0
argument_list|(
name|watchhi
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|watchhi
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|watchhi
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RDRW32_COP0_SEL
argument_list|(
name|watchhi
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|MIPS_RDRW32_COP0
end_undef

begin_function
specifier|static
name|__inline
name|register_t
name|intr_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|s
decl_stmt|;
name|s
operator|=
name|mips_rd_status
argument_list|()
expr_stmt|;
name|mips_wr_status
argument_list|(
name|s
operator|&
operator|~
name|MIPS_SR_INT_IE
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|intr_enable
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|s
decl_stmt|;
name|s
operator|=
name|mips_rd_status
argument_list|()
expr_stmt|;
name|mips_wr_status
argument_list|(
name|s
operator||
name|MIPS_SR_INT_IE
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|intr_restore
parameter_list|(
name|s
parameter_list|)
value|mips_wr_status((s))
end_define

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("break");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|readb
parameter_list|(
name|va
parameter_list|)
value|(*(volatile uint8_t *) (va))
end_define

begin_define
define|#
directive|define
name|readw
parameter_list|(
name|va
parameter_list|)
value|(*(volatile uint16_t *) (va))
end_define

begin_define
define|#
directive|define
name|readl
parameter_list|(
name|va
parameter_list|)
value|(*(volatile uint32_t *) (va))
end_define

begin_define
define|#
directive|define
name|writeb
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint8_t *) (va) = (d))
end_define

begin_define
define|#
directive|define
name|writew
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint16_t *) (va) = (d))
end_define

begin_define
define|#
directive|define
name|writel
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint32_t *) (va) = (d))
end_define

begin_comment
comment|/*  * I/O macros.  */
end_comment

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile unsigned char*)(a) = (v))
end_define

begin_define
define|#
directive|define
name|out8
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile unsigned char*)(a) = (v))
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile unsigned short*)(a) = (v))
end_define

begin_define
define|#
directive|define
name|out16
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outw(a,v)
end_define

begin_define
define|#
directive|define
name|outl
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile unsigned int*)(a) = (v))
end_define

begin_define
define|#
directive|define
name|out32
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outl(a,v)
end_define

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|a
parameter_list|)
value|(*(volatile unsigned char*)(a))
end_define

begin_define
define|#
directive|define
name|in8
parameter_list|(
name|a
parameter_list|)
value|(*(volatile unsigned char*)(a))
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|a
parameter_list|)
value|(*(volatile unsigned short*)(a))
end_define

begin_define
define|#
directive|define
name|in16
parameter_list|(
name|a
parameter_list|)
value|inw(a)
end_define

begin_define
define|#
directive|define
name|inl
parameter_list|(
name|a
parameter_list|)
value|(*(volatile unsigned int*)(a))
end_define

begin_define
define|#
directive|define
name|in32
parameter_list|(
name|a
parameter_list|)
value|inl(a)
end_define

begin_define
define|#
directive|define
name|out8rb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile unsigned char*)(a) = (v))
end_define

begin_define
define|#
directive|define
name|out16rb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__out16rb((volatile uint16_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|out32rb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__out32rb((volatile uint32_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|in8rb
parameter_list|(
name|a
parameter_list|)
value|(*(volatile unsigned char*)(a))
end_define

begin_define
define|#
directive|define
name|in16rb
parameter_list|(
name|a
parameter_list|)
value|(__in16rb((volatile uint16_t *)(a)))
end_define

begin_define
define|#
directive|define
name|in32rb
parameter_list|(
name|a
parameter_list|)
value|(__in32rb((volatile uint32_t *)(a)))
end_define

begin_define
define|#
directive|define
name|_swap_
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24) | ((x)<< 24) | \ 	    (((x)>> 8)& 0xff00) | (((x)& 0xff00)<< 8))
end_define

begin_function_decl
specifier|static
name|__inline
name|void
name|__out32rb
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|__out16rb
parameter_list|(
specifier|volatile
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint32_t
name|__in32rb
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|uint16_t
name|__in16rb
parameter_list|(
specifier|volatile
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|__out32rb
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|uint32_t
name|_v_
init|=
name|v
decl_stmt|;
name|_v_
operator|=
name|_swap_
argument_list|(
name|_v_
argument_list|)
expr_stmt|;
name|out32
argument_list|(
name|a
argument_list|,
name|_v_
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__out16rb
parameter_list|(
specifier|volatile
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16_t
name|v
parameter_list|)
block|{
name|uint16_t
name|_v_
decl_stmt|;
name|_v_
operator|=
operator|(
operator|(
name|v
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator||
operator|(
name|v
operator|<<
literal|8
operator|)
expr_stmt|;
name|out16
argument_list|(
name|a
argument_list|,
name|_v_
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|__in32rb
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
name|uint32_t
name|_v_
decl_stmt|;
name|_v_
operator|=
name|in32
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|_v_
operator|=
name|_swap_
argument_list|(
name|_v_
argument_list|)
expr_stmt|;
return|return
name|_v_
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint16_t
name|__in16rb
parameter_list|(
specifier|volatile
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
name|uint16_t
name|_v_
decl_stmt|;
name|_v_
operator|=
name|in16
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|_v_
operator|=
operator|(
operator|(
name|_v_
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator||
operator|(
name|_v_
operator|<<
literal|8
operator|)
expr_stmt|;
return|return
name|_v_
return|;
block|}
end_function

begin_function_decl
name|void
name|insb
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insw
parameter_list|(
name|uint16_t
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insl
parameter_list|(
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsb
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsw
parameter_list|(
name|uint16_t
modifier|*
parameter_list|,
specifier|const
name|uint16_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsl
parameter_list|(
name|uint32_t
modifier|*
parameter_list|,
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|loadandclear
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

