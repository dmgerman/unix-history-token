begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/spl.h>
end_include

begin_comment
comment|/* XXX belongs elsewhere */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BDE_DEBUGGER
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|bdb_exists
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|bdb
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|bdb_exists
condition|)
return|return
operator|(
literal|0
operator|)
return|;
asm|__asm __volatile("int $3");
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BDE_DEBUGGER */
end_comment

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
comment|/*  * The following complications are to get around gcc not having a  * constraint letter for the range 0..255.  We still put "d" in the  * constraint because "i" isn't a valid constraint when the port  * isn't constant.  This only matters for -O0 because otherwise  * the non-working version gets optimized away.  *   * Use an expression-statement instead of a conditional expression  * because gcc-2.6.0 would promote the operands of the conditional  * and produce poor code for "if ((inb(var)& const1) == const2)".  */
end_comment

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|({						\ 	u_char	_data;							\ 	if (__builtin_constant_p((int) (port))&& (port)< 256ul)	\ 		_data = inbc(port);					\ 	else								\ 		_data = inbv(port);					\ 	_data; })
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
define|\
value|(__builtin_constant_p((int) (port))&& (port)< 256ul \ 	 ? outbc(port, data) : outbv(port, data))
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
name|unsigned
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
name|void
name|pmap_update
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

begin_function
unit|}  static
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

begin_comment
comment|/*  * XXX queue stuff belongs elsewhere.  */
end_comment

begin_struct
struct|struct
name|quehead
block|{
name|struct
name|quehead
modifier|*
name|qh_link
decl_stmt|;
name|struct
name|quehead
modifier|*
name|qh_rlink
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|void
name|insque
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|)
block|{
name|struct
name|quehead
modifier|*
name|element
init|=
operator|(
expr|struct
name|quehead
operator|*
operator|)
name|a
decl_stmt|,
modifier|*
name|head
init|=
operator|(
expr|struct
name|quehead
operator|*
operator|)
name|b
decl_stmt|;
name|element
operator|->
name|qh_link
operator|=
name|head
operator|->
name|qh_link
expr_stmt|;
name|element
operator|->
name|qh_rlink
operator|=
name|head
expr_stmt|;
name|head
operator|->
name|qh_link
operator|=
name|element
expr_stmt|;
name|element
operator|->
name|qh_link
operator|->
name|qh_rlink
operator|=
name|element
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|remque
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
block|{
name|struct
name|quehead
modifier|*
name|element
init|=
operator|(
expr|struct
name|quehead
operator|*
operator|)
name|a
decl_stmt|;
name|element
operator|->
name|qh_link
operator|->
name|qh_rlink
operator|=
name|element
operator|->
name|qh_rlink
expr_stmt|;
name|element
operator|->
name|qh_rlink
operator|->
name|qh_link
operator|=
name|element
operator|->
name|qh_link
expr_stmt|;
name|element
operator|->
name|qh_rlink
operator|=
literal|0
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

begin_decl_stmt
name|int
name|bdb
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
name|void
name|pmap_update
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
name|insque
name|__P
argument_list|(
operator|(
name|void
operator|*
name|a
operator|,
name|void
operator|*
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|remque
name|__P
argument_list|(
operator|(
name|void
operator|*
name|a
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

begin_comment
comment|/*  * XXX the following declarations document garbage in support.s.  * gcc hasn't needed _divsi* for years.  * bcopy[bwx]() was used by pccons but isn't used now.  */
end_comment

begin_decl_stmt
name|int
name|__divsi3
name|__P
argument_list|(
operator|(
name|int
name|factor1
operator|,
name|int
name|factor2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__udivsi3
name|__P
argument_list|(
operator|(
name|u_int
name|factor1
operator|,
name|u_int
name|factor2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bcopyb
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bcopyw
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bcopyx
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|from
operator|,
name|void
operator|*
name|to
operator|,
name|size_t
name|len
operator|,
name|int
name|stride
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * These functions in support.s are declared elsewhere.  */
end_comment

begin_comment
unit|void	bcopy		__P((const void *from, void *to, size_t len)); void	blkclr		__P((void *buf, size_t len)); void	bzero		__P((void *buf, size_t len)); int	copyin		__P((void *udaddr, void *kaddr, size_t len)); int	copyinstr	__P((void *udaddr, void *kaddr, size_t len, 			     size_t *lencopied)); int	copyout		__P((void *kaddr, void *udaddr, size_t len)); int	copystr		__P((void *kfaddr, void *kdaddr, size_t len, 			     size_t *lencopied)); int	fubyte		__P((void *base)); int	fuswintr	__P((void *base)); int	fuibyte		__P((void *base)); int	fuword		__P((void *base)); struct	region_descriptor; void	lgdt		__P((struct region_descriptor *rdp)); void	lidt		__P((struct region_descriptor *rdp)); void	lldt		__P((u_short sel));
comment|/*  * longjmp() and setjmp() are only used by ddb.  They probably shouldn't  * shouldn't be supported in the kernel.  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
unit|void	longjmp		__P((jmp_buf jb, int rv)); void	ovbcopy		__P((const void *from, void *to, size_t len); int	setjmp		__P((jmp_buf jb)); struct soft_segment_descriptor; union descriptor; int	ssdtosd		__P((struct soft_segment_descriptor *ssdp, 			     union descriptor *sdp)); int	subyte		__P((void *base, int byte)); int	suibyte		__P((void *base, int byte)); int	suswintr	__P((void *base, int word)); int	suword		__P((void *base, int word));
comment|/*  * These functions in support.s are declared elsewhere, but never used.  * A silly amount of effort went into copyoutstr().  It's not worth  * maintaining, since the string length is usually known so copyout  * works better, or is easy to find so copyout() can be used.  */
end_comment

begin_comment
unit|int	copyoutstr	__P((void *kaddr, void *udaddr, size_t len, 			     size_t *lencopied)); int	fuiword		__P((void *base)); int	suiword		__P((void *base, int word));
comment|/*  * These functions in support.s are also in libkern.a and are declared in  * libkern.h.  * ffs() is built in to gcc-2 and was buggy in gcc-2.4.5 so we may may the  * buggy version if we don't replace it by an inline.  */
end_comment

begin_endif
unit|int	bcmp		__P((const void *b1, const void *b2, size_t length)); int	ffs		__P((int mask));
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * These variables and functions in support.s are used.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|atdevbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset in virtual memory of ISA io mem */
end_comment

begin_decl_stmt
name|void
name|filli
name|__P
argument_list|(
operator|(
name|int
name|pat
operator|,
name|void
operator|*
name|base
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fillw
name|__P
argument_list|(
operator|(
name|int
comment|/*u_short*/
name|pat
operator|,
name|void
operator|*
name|base
operator|,
name|size_t
name|cnt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fusword
name|__P
argument_list|(
operator|(
name|void
operator|*
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|int
name|rtcin
name|__P
argument_list|(
operator|(
name|int
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * These functions are NOT in support.s and should be declared elsewhere.  */
end_comment

begin_decl_stmt
name|void
name|Debugger
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|kvtop
name|__P
argument_list|(
operator|(
name|void
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|alias_for_inthand_t
name|__P
typedef|((
name|u_int
name|cs
typedef|,
name|u_int
name|ef
typedef|,
name|u_int
name|esp
typedef|,
name|u_int
name|ss
typedef|));
end_typedef

begin_decl_stmt
name|void
name|setidt
name|__P
argument_list|(
operator|(
name|int
name|idx
operator|,
name|alias_for_inthand_t
operator|*
name|func
operator|,
name|int
name|typ
operator|,
name|int
name|dpl
operator|,
name|int
name|selec
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

