begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Functions to provide access to special i386 instructions.  * This in included in sys/systm.h, and that file should be  * used in preference to this.  */
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
define|#
directive|define
name|readb
parameter_list|(
name|va
parameter_list|)
value|(*(volatile u_int8_t *) (va))
define|#
directive|define
name|readw
parameter_list|(
name|va
parameter_list|)
value|(*(volatile u_int16_t *) (va))
define|#
directive|define
name|readl
parameter_list|(
name|va
parameter_list|)
value|(*(volatile u_int32_t *) (va))
define|#
directive|define
name|writeb
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile u_int8_t *) (va) = (d))
define|#
directive|define
name|writew
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile u_int16_t *) (va) = (d))
define|#
directive|define
name|writel
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile u_int32_t *) (va) = (d))
ifdef|#
directive|ifdef
name|__GNUC__
ifdef|#
directive|ifdef
name|SWTCH_OPTIM_STATS
specifier|extern
name|int
name|tlb_flush_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("int $3");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|bsfl
parameter_list|(
name|u_int
name|mask
parameter_list|)
block|{
name|u_int
name|result
decl_stmt|;
asm|__asm __volatile("bsfl %1,%0" : "=r" (result) : "rm" (mask));
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|bsrl
parameter_list|(
name|u_int
name|mask
parameter_list|)
block|{
name|u_int
name|result
decl_stmt|;
asm|__asm __volatile("bsrl %1,%0" : "=r" (result) : "rm" (mask));
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|disable_intr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("cli" : : : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|enable_intr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("sti");
block|}
end_function

begin_define
define|#
directive|define
name|HAVE_INLINE_FFS
end_define

begin_function
specifier|static
name|__inline
name|int
name|ffs
parameter_list|(
name|int
name|mask
parameter_list|)
block|{
comment|/* 	 * Note that gcc-2's builtin ffs would be used if we didn't declare 	 * this inline or turn off the builtin.  The builtin is faster but 	 * broken in gcc-2.4.5 and slower but working in gcc-2.5 and later 	 * versions. 	 */
return|return
operator|(
name|mask
operator|==
literal|0
condition|?
name|mask
else|:
name|bsfl
argument_list|(
operator|(
name|u_int
operator|)
name|mask
argument_list|)
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|HAVE_INLINE_FLS
end_define

begin_function
specifier|static
name|__inline
name|int
name|fls
parameter_list|(
name|int
name|mask
parameter_list|)
block|{
return|return
operator|(
name|mask
operator|==
literal|0
condition|?
name|mask
else|:
name|bsrl
argument_list|(
operator|(
name|u_int
operator|)
name|mask
argument_list|)
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
end_if

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|inbv(port)
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|port
parameter_list|,
name|data
parameter_list|)
value|outbv(port, data)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC>= 2 */
end_comment

begin_comment
comment|/*  * The following complications are to get around gcc not having a  * constraint letter for the range 0..255.  We still put "d" in the  * constraint because "i" isn't a valid constraint when the port  * isn't constant.  This only matters for -O0 because otherwise  * the non-working version gets optimized away.  *   * Use an expression-statement instead of a conditional expression  * because gcc-2.6.0 would promote the operands of the conditional  * and produce poor code for "if ((inb(var)& const1) == const2)".  *  * The unnecessary test `(port)< 0x10000' is to generate a warning if  * the `port' has type u_short or smaller.  Such types are pessimal.  * This actually only works for signed types.  The range check is  * careful to avoid generating warnings.  */
end_comment

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|__extension__ ({					\ 	u_char	_data;							\ 	if (__builtin_constant_p(port)&& ((port)& 0xffff)< 0x100	\&& (port)< 0x10000)					\ 		_data = inbc(port);					\ 	else								\ 		_data = inbv(port);					\ 	_data; })
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|port
parameter_list|,
name|data
parameter_list|)
value|(						\ 	__builtin_constant_p(port)&& ((port)& 0xffff)< 0x100		\&& (port)< 0x10000						\ 	? outbc(port, data) : outbv(port, data))
end_define

begin_function
specifier|static
name|__inline
name|u_char
name|inbc
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_char
name|data
decl_stmt|;
asm|__asm __volatile("inb %1,%0" : "=a" (data) : "id" ((u_short)(port)));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|outbc
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_char
name|data
parameter_list|)
block|{
asm|__asm __volatile("outb %0,%1" : : "a" (data), "id" ((u_short)(port)));
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC<= 2 */
end_comment

begin_function
specifier|static
name|__inline
name|u_char
name|inbv
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_char
name|data
decl_stmt|;
comment|/* 	 * We use %%dx and not %1 here because i/o is done at %dx and not at 	 * %edx, while gcc generates inferior code (movw instead of movl) 	 * if we tell it to load (u_short) port. 	 */
asm|__asm __volatile("inb %%dx,%0" : "=a" (data) : "d" (port));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|inl
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("inl %%dx,%0" : "=a" (data) : "d" (port));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|insb
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; insb"
block|:
literal|"+D"
operator|(
name|addr
operator|)
operator|,
literal|"+c"
operator|(
name|cnt
operator|)
operator|:
literal|"d"
operator|(
name|port
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|insw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; insw"
block|:
literal|"+D"
operator|(
name|addr
operator|)
operator|,
literal|"+c"
operator|(
name|cnt
operator|)
operator|:
literal|"d"
operator|(
name|port
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|insl
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; insl"
block|:
literal|"+D"
operator|(
name|addr
operator|)
operator|,
literal|"+c"
operator|(
name|cnt
operator|)
operator|:
literal|"d"
operator|(
name|port
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|invd
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("invd");
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/*  * When using APIC IPI's, invlpg() is not simply the invlpg instruction  * (this is a bug) and the inlining cost is prohibitive since the call  * executes into the IPI transmission system.  */
end_comment

begin_function_decl
name|void
name|invlpg
parameter_list|(
name|u_int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invltlb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|cpu_invlpg
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm __volatile("invlpg %0" : : "m" (*(char *)addr) : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|cpu_invltlb
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|temp
decl_stmt|;
comment|/* 	 * This should be implemented as load_cr3(rcr3()) when load_cr3() 	 * is inlined. 	 */
asm|__asm __volatile("movl %%cr3, %0; movl %0, %%cr3" : "=r" (temp)
block|: :
literal|"memory"
block|)
function|;
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SWTCH_OPTIM_STATS
argument_list|)
end_if

begin_expr_stmt
operator|++
name|tlb_flush_count
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* !(SMP&& _KERNEL) */
end_comment

begin_function
unit|static
name|__inline
name|void
name|invlpg
parameter_list|(
name|u_int
name|addr
parameter_list|)
block|{
asm|__asm __volatile("invlpg %0" : : "m" (*(char *)addr) : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|invltlb
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|temp
decl_stmt|;
comment|/* 	 * This should be implemented as load_cr3(rcr3()) when load_cr3() 	 * is inlined. 	 */
asm|__asm __volatile("movl %%cr3, %0; movl %0, %%cr3" : "=r" (temp)
block|: :
literal|"memory"
block|)
function|;
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|SWTCH_OPTIM_STATS
end_ifdef

begin_expr_stmt
operator|++
name|tlb_flush_count
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP&& _KERNEL */
end_comment

begin_function
unit|static
name|__inline
name|u_short
name|inw
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_short
name|data
decl_stmt|;
asm|__asm __volatile("inw %%dx,%0" : "=a" (data) : "d" (port));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|outbv
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_char
name|data
parameter_list|)
block|{
name|u_char
name|al
decl_stmt|;
comment|/* 	 * Use an unnecessary assignment to help gcc's register allocator. 	 * This make a large difference for gcc-1.40 and a tiny difference 	 * for gcc-2.6.0.  For gcc-1.40, al had to be ``asm("ax")'' for 	 * best results.  gcc-2.6.0 can't handle this. 	 */
name|al
operator|=
name|data
expr_stmt|;
asm|__asm __volatile("outb %0,%%dx" : : "a" (al), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|outl
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_int
name|data
parameter_list|)
block|{
comment|/* 	 * outl() and outw() aren't used much so we haven't looked at 	 * possible micro-optimizations such as the unnecessary 	 * assignment for them. 	 */
asm|__asm __volatile("outl %0,%%dx" : : "a" (data), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|outsb
parameter_list|(
name|u_int
name|port
parameter_list|,
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; outsb"
block|:
literal|"+S"
operator|(
name|addr
operator|)
operator|,
literal|"+c"
operator|(
name|cnt
operator|)
operator|:
literal|"d"
operator|(
name|port
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|outsw
parameter_list|(
name|u_int
name|port
parameter_list|,
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; outsw"
block|:
literal|"+S"
operator|(
name|addr
operator|)
operator|,
literal|"+c"
operator|(
name|cnt
operator|)
operator|:
literal|"d"
operator|(
name|port
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|outsl
parameter_list|(
name|u_int
name|port
parameter_list|,
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; outsl"
block|:
literal|"+S"
operator|(
name|addr
operator|)
operator|,
literal|"+c"
operator|(
name|cnt
operator|)
operator|:
literal|"d"
operator|(
name|port
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|outw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_short
name|data
parameter_list|)
block|{
asm|__asm __volatile("outw %0,%%dx" : : "a" (data), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rcr2
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%cr2,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|read_eflags
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|ef
decl_stmt|;
asm|__asm __volatile("pushfl; popl %0" : "=r" (ef));
return|return
operator|(
name|ef
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|do_cpuid
parameter_list|(
name|u_int
name|ax
parameter_list|,
name|u_int
modifier|*
name|p
parameter_list|)
block|{
asm|__asm __volatile(
literal|"cpuid"
operator|:
literal|"=a"
operator|(
name|p
index|[
literal|0
index|]
operator|)
operator|,
literal|"=b"
operator|(
name|p
index|[
literal|1
index|]
operator|)
operator|,
literal|"=c"
operator|(
name|p
index|[
literal|2
index|]
operator|)
operator|,
literal|"=d"
operator|(
name|p
index|[
literal|3
index|]
operator|)
operator|:
literal|"0"
operator|(
name|ax
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|u_int64_t
name|rdmsr
parameter_list|(
name|u_int
name|msr
parameter_list|)
block|{
name|u_int64_t
name|rv
decl_stmt|;
asm|__asm __volatile("rdmsr" : "=A" (rv) : "c" (msr));
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|rdpmc
parameter_list|(
name|u_int
name|pmc
parameter_list|)
block|{
name|u_int64_t
name|rv
decl_stmt|;
asm|__asm __volatile("rdpmc" : "=A" (rv) : "c" (pmc));
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|rdtsc
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int64_t
name|rv
decl_stmt|;
asm|__asm __volatile("rdtsc" : "=A" (rv));
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|wbinvd
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("wbinvd");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|write_eflags
parameter_list|(
name|u_int
name|ef
parameter_list|)
block|{
asm|__asm __volatile("pushl %0; popfl" : : "r" (ef));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|wrmsr
parameter_list|(
name|u_int
name|msr
parameter_list|,
name|u_int64_t
name|newval
parameter_list|)
block|{
asm|__asm __volatile("wrmsr" : : "A" (newval), "c" (msr));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rfs
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|sel
decl_stmt|;
asm|__asm __volatile("movl %%fs,%0" : "=rm" (sel));
return|return
operator|(
name|sel
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rgs
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|sel
decl_stmt|;
asm|__asm __volatile("movl %%gs,%0" : "=rm" (sel));
return|return
operator|(
name|sel
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_fs
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%fs" : : "rm" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_gs
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%gs" : : "rm" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr0
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr0,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr0
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr0" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr1
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr1,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr1
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr1" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr2
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr2,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr2
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr2" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr3
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr3,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr3
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr3" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr4
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr4,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr4
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr4" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr5
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr5,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr5
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr5" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr6
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr6,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr6
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr6" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rdr7
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%dr7,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_dr7
parameter_list|(
name|u_int
name|sel
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr7" : : "r" (sel));
block|}
end_function

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
name|eflags
decl_stmt|;
name|eflags
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
return|return
operator|(
name|eflags
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|intr_restore
parameter_list|(
name|register_t
name|eflags
parameter_list|)
block|{
name|write_eflags
argument_list|(
name|eflags
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_function_decl
name|int
name|breakpoint
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bsfl
parameter_list|(
name|u_int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bsrl
parameter_list|(
name|u_int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disable_intr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_cpuid
parameter_list|(
name|u_int
name|ax
parameter_list|,
name|u_int
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enable_intr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
name|inb
parameter_list|(
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|inl
parameter_list|(
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insb
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insl
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|insw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invlpg
parameter_list|(
name|u_int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invltlb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|inw
parameter_list|(
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outb
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_char
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outl
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsb
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsl
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outsw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_short
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rcr2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|rdmsr
parameter_list|(
name|u_int
name|msr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|rdpmc
parameter_list|(
name|u_int
name|pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|rdtsc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|read_eflags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wbinvd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_eflags
parameter_list|(
name|u_int
name|ef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wrmsr
parameter_list|(
name|u_int
name|msr
parameter_list|,
name|u_int64_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rfs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rgs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_fs
parameter_list|(
name|u_int
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_gs
parameter_list|(
name|u_int
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_function_decl
name|void
name|load_cr0
parameter_list|(
name|u_int
name|cr0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_cr3
parameter_list|(
name|u_int
name|cr3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_cr4
parameter_list|(
name|u_int
name|cr4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ltr
parameter_list|(
name|u_short
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rcr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rcr3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rcr4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_dbregs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_fork_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_link
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

