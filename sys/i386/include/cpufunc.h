begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: cpufunc.h,v 1.72 1997/09/07 22:01:27 fsmp Exp $  */
end_comment

begin_comment
comment|/*  * Functions to provide access to special i386 instructions.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/lock.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SWTCH_OPTIM_STATS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|tlb_flush_count
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

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
name|void
name|disable_intr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("cli" : : : "memory");
name|MPINTR_LOCK
argument_list|()
expr_stmt|;
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
name|MPINTR_UNLOCK
argument_list|()
expr_stmt|;
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
name|int
name|result
decl_stmt|;
comment|/* 	 * bsfl turns out to be not all that slow on 486's.  It can beaten 	 * using a binary search to reduce to 4 bits and then a table lookup, 	 * but only if the code is inlined and in the cache, and the code 	 * is quite large so inlining it probably busts the cache. 	 * 	 * Note that gcc-2's builtin ffs would be used if we didn't declare 	 * this inline or turn off the builtin.  The builtin is faster but 	 * broken in gcc-2.4.5 and slower but working in gcc-2.5 and 2.6. 	 */
asm|__asm __volatile("testl %0,%0; je 1f; bsfl %0,%0; incl %0; 1:"
block|:
literal|"=r"
operator|(
name|result
operator|)
operator|:
literal|"0"
operator|(
name|mask
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|HAVE_INLINE_FLS
end_define

begin_function
unit|static
name|__inline
name|int
name|fls
parameter_list|(
name|int
name|mask
parameter_list|)
block|{
name|int
name|result
decl_stmt|;
asm|__asm __volatile("testl %0,%0; je 1f; bsrl %0,%0; incl %0; 1:"
block|:
literal|"=r"
operator|(
name|result
operator|)
operator|:
literal|"0"
operator|(
name|mask
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_if
unit|}
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
unit|static
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
name|u_long
name|inl
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_long
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
block|: :
literal|"d"
operator|(
name|port
operator|)
operator|,
literal|"D"
operator|(
name|addr
operator|)
operator|,
literal|"c"
operator|(
name|cnt
operator|)
operator|:
literal|"di"
operator|,
literal|"cx"
operator|,
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
block|: :
literal|"d"
operator|(
name|port
operator|)
operator|,
literal|"D"
operator|(
name|addr
operator|)
operator|,
literal|"c"
operator|(
name|cnt
operator|)
operator|:
literal|"di"
operator|,
literal|"cx"
operator|,
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
block|: :
literal|"d"
operator|(
name|port
operator|)
operator|,
literal|"D"
operator|(
name|addr
operator|)
operator|,
literal|"c"
operator|(
name|cnt
operator|)
operator|:
literal|"di"
operator|,
literal|"cx"
operator|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * When using APIC IPI's, the inlining cost is prohibitive since the call  * executes into the IPI transmission system.  */
end_comment

begin_decl_stmt
name|void
name|invlpg
name|__P
argument_list|(
operator|(
name|u_int
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|invltlb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SMP */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|invlpg
parameter_list|(
name|u_int
name|addr
parameter_list|)
block|{
asm|__asm __volatile("invlpg (%0)" : : "r" (addr) : "memory");
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
name|u_long
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

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
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
name|u_int
name|loadandclear
parameter_list|(
name|u_int
modifier|*
name|addr
parameter_list|)
block|{
name|u_int
name|result
decl_stmt|;
asm|__asm __volatile("xorl %0,%0; xchgl %1,%0"
block|:
literal|"=&r"
operator|(
name|result
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_function
unit|}  static
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
name|u_long
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
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; outsb"
block|: :
literal|"d"
operator|(
name|port
operator|)
operator|,
literal|"S"
operator|(
name|addr
operator|)
operator|,
literal|"c"
operator|(
name|cnt
operator|)
operator|:
literal|"si"
operator|,
literal|"cx"
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
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; outsw"
block|: :
literal|"d"
operator|(
name|port
operator|)
operator|,
literal|"S"
operator|(
name|addr
operator|)
operator|,
literal|"c"
operator|(
name|cnt
operator|)
operator|:
literal|"si"
operator|,
literal|"cx"
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
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
asm|__asm __volatile("cld; rep; outsl"
block|: :
literal|"d"
operator|(
name|port
operator|)
operator|,
literal|"S"
operator|(
name|addr
operator|)
operator|,
literal|"c"
operator|(
name|cnt
operator|)
operator|:
literal|"si"
operator|,
literal|"cx"
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
name|u_long
name|rcr2
parameter_list|(
name|void
parameter_list|)
block|{
name|u_long
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
name|u_long
name|read_eflags
parameter_list|(
name|void
parameter_list|)
block|{
name|u_long
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
name|quad_t
name|rdmsr
parameter_list|(
name|u_int
name|msr
parameter_list|)
block|{
name|quad_t
name|rv
decl_stmt|;
asm|__asm __volatile(".byte 0x0f, 0x32" : "=A" (rv) : "c" (msr));
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
name|quad_t
name|rdpmc
parameter_list|(
name|u_int
name|pmc
parameter_list|)
block|{
name|quad_t
name|rv
decl_stmt|;
asm|__asm __volatile(".byte 0x0f, 0x33" : "=A" (rv) : "c" (pmc));
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
name|quad_t
name|rdtsc
parameter_list|(
name|void
parameter_list|)
block|{
name|quad_t
name|rv
decl_stmt|;
asm|__asm __volatile(".byte 0x0f, 0x31" : "=A" (rv));
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
name|setbits
parameter_list|(
specifier|volatile
name|unsigned
modifier|*
name|addr
parameter_list|,
name|u_int
name|bits
parameter_list|)
block|{
asm|__asm __volatile(
ifdef|#
directive|ifdef
name|SMP
literal|"lock; "
endif|#
directive|endif
literal|"orl %1,%0"
operator|:
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"ir"
operator|(
name|bits
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
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
name|u_long
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
name|quad_t
name|newval
parameter_list|)
block|{
asm|__asm __volatile(".byte 0x0f, 0x30" : : "A" (newval), "c" (msr));
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_decl_stmt
name|int
name|breakpoint
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disable_intr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enable_intr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|inb
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|inl
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|insb
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|void
operator|*
name|addr
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|insl
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|void
operator|*
name|addr
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|insw
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|void
operator|*
name|addr
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|invd
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|invlpg
name|__P
argument_list|(
operator|(
name|u_int
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|invltlb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|inw
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|loadandclear
name|__P
argument_list|(
operator|(
name|u_int
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outb
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|u_char
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outl
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|u_long
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outsb
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|void
operator|*
name|addr
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outsl
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|void
operator|*
name|addr
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outsw
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|void
operator|*
name|addr
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outw
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|u_short
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|rcr2
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|quad_t
name|rdmsr
name|__P
argument_list|(
operator|(
name|u_int
name|msr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|quad_t
name|rdpmc
name|__P
argument_list|(
operator|(
name|u_int
name|pmc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|quad_t
name|rdtsc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|read_eflags
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setbits
name|__P
argument_list|(
operator|(
specifier|volatile
name|unsigned
operator|*
name|addr
operator|,
name|u_int
name|bits
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wbinvd
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_eflags
name|__P
argument_list|(
operator|(
name|u_long
name|ef
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wrmsr
name|__P
argument_list|(
operator|(
name|u_int
name|msr
operator|,
name|quad_t
name|newval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_decl_stmt
name|void
name|load_cr0
name|__P
argument_list|(
operator|(
name|u_long
name|cr0
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|load_cr3
name|__P
argument_list|(
operator|(
name|u_long
name|cr3
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|load_cr4
name|__P
argument_list|(
operator|(
name|u_long
name|cr4
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ltr
name|__P
argument_list|(
operator|(
name|u_short
name|sel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|rcr0
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|rcr3
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|rcr4
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

