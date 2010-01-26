begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|region_descriptor
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|readb
parameter_list|(
name|va
parameter_list|)
value|(*(volatile u_int8_t *) (va))
end_define

begin_define
define|#
directive|define
name|readw
parameter_list|(
name|va
parameter_list|)
value|(*(volatile u_int16_t *) (va))
end_define

begin_define
define|#
directive|define
name|readl
parameter_list|(
name|va
parameter_list|)
value|(*(volatile u_int32_t *) (va))
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
value|(*(volatile u_int8_t *) (va) = (d))
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
value|(*(volatile u_int16_t *) (va) = (d))
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
value|(*(volatile u_int32_t *) (va) = (d))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUCLIKE_ASM
argument_list|)
operator|&&
name|defined
argument_list|(
name|__CC_SUPPORTS___INLINE
argument_list|)
end_if

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
name|clflush
parameter_list|(
name|u_long
name|addr
parameter_list|)
block|{
asm|__asm __volatile("clflush %0" : : "m" (*(char *)addr));
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
asm|__asm __volatile("cpuid"
block|:
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
name|void
name|cpuid_count
parameter_list|(
name|u_int
name|ax
parameter_list|,
name|u_int
name|cx
parameter_list|,
name|u_int
modifier|*
name|p
parameter_list|)
block|{
asm|__asm __volatile("cpuid"
block|:
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
operator|,
literal|"c"
operator|(
name|cx
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
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

begin_function
specifier|static
name|__inline
name|void
name|mfence
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("mfence" : : : "memory");
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
operator|(
name|int
operator|)
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
operator|(
name|int
operator|)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|halt
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("hlt");
block|}
end_function

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUCLIKE_BUILTIN_CONSTANT_P
argument_list|)
operator|||
name|__GNUCLIKE_ASM
operator|<
literal|3
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
comment|/* __GNUCLIKE_BUILTIN_CONSTANT_P&& __GNUCLIKE_ASM>= 3 */
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
comment|/* __GNUCLIKE_BUILTIN_CONSTANT_P&& __GNUCLIKE_ASM>= 3*/
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

begin_function
specifier|static
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
name|void
name|ia32_pause
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("pause");
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
name|uint64_t
name|rdmsr
parameter_list|(
name|u_int
name|msr
parameter_list|)
block|{
name|uint64_t
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
name|uint64_t
name|rdpmc
parameter_list|(
name|u_int
name|pmc
parameter_list|)
block|{
name|uint64_t
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
name|uint64_t
name|rdtsc
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
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
name|uint64_t
name|newval
parameter_list|)
block|{
asm|__asm __volatile("wrmsr" : : "A" (newval), "c" (msr));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|load_cr0
parameter_list|(
name|u_int
name|data
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%cr0" : : "r" (data));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rcr0
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%cr0,%0" : "=r" (data));
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
name|void
name|load_cr3
parameter_list|(
name|u_int
name|data
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%cr3" : : "r" (data) : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rcr3
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%cr3,%0" : "=r" (data));
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
name|load_cr4
parameter_list|(
name|u_int
name|data
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%cr4" : : "r" (data));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rcr4
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|data
decl_stmt|;
asm|__asm __volatile("movl %%cr4,%0" : "=r" (data));
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Global TLB flush (except for thise for pages marked PG_G)  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|invltlb
parameter_list|(
name|void
parameter_list|)
block|{
name|load_cr3
argument_list|(
name|rcr3
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * TLB flush for an individual page (even if it has PG_G).  * Only works on 486+ CPUs (i386 does not have PG_G).  */
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
asm|__asm __volatile("invlpg %0" : : "m" (*(char *)addr) : "memory");
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
name|uint64_t
name|rgdt
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|gdtr
decl_stmt|;
asm|__asm __volatile("sgdt %0" : "=m" (gdtr));
return|return
operator|(
name|gdtr
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
name|uint64_t
name|ridt
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|idtr
decl_stmt|;
asm|__asm __volatile("sidt %0" : "=m" (idtr));
return|return
operator|(
name|idtr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_short
name|rldt
parameter_list|(
name|void
parameter_list|)
block|{
name|u_short
name|ldtr
decl_stmt|;
asm|__asm __volatile("sldt %0" : "=g" (ldtr));
return|return
operator|(
name|ldtr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|rss
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|sel
decl_stmt|;
asm|__asm __volatile("movl %%ss,%0" : "=rm" (sel));
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
name|u_short
name|rtr
parameter_list|(
name|void
parameter_list|)
block|{
name|u_short
name|tr
decl_stmt|;
asm|__asm __volatile("str %0" : "=g" (tr));
return|return
operator|(
name|tr
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
name|void
name|lidt
parameter_list|(
name|struct
name|region_descriptor
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm __volatile("lidt (%0)" : : "r" (addr));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|lldt
parameter_list|(
name|u_short
name|sel
parameter_list|)
block|{
asm|__asm __volatile("lldt %0" : : "r" (sel));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ltr
parameter_list|(
name|u_short
name|sel
parameter_list|)
block|{
asm|__asm __volatile("ltr %0" : : "r" (sel));
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
name|dr0
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr0" : : "r" (dr0));
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
name|dr1
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr1" : : "r" (dr1));
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
name|dr2
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr2" : : "r" (dr2));
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
name|dr3
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr3" : : "r" (dr3));
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
name|dr4
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr4" : : "r" (dr4));
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
name|dr5
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr5" : : "r" (dr5));
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
name|dr6
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr6" : : "r" (dr6));
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
name|dr7
parameter_list|)
block|{
asm|__asm __volatile("movl %0,%%dr7" : : "r" (dr7));
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_char
name|read_cyrix_reg
parameter_list|(
name|u_char
name|reg
parameter_list|)
block|{
name|outb
argument_list|(
literal|0x22
argument_list|,
name|reg
argument_list|)
expr_stmt|;
return|return
name|inb
argument_list|(
literal|0x23
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|write_cyrix_reg
parameter_list|(
name|u_char
name|reg
parameter_list|,
name|u_char
name|data
parameter_list|)
block|{
name|outb
argument_list|(
literal|0x22
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x23
argument_list|,
name|data
argument_list|)
expr_stmt|;
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
comment|/* !(__GNUCLIKE_ASM&& __CC_SUPPORTS___INLINE) */
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
name|void
name|halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ia32_pause
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
name|register_t
name|intr_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr_restore
parameter_list|(
name|register_t
name|ef
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
name|lidt
parameter_list|(
name|struct
name|region_descriptor
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lldt
parameter_list|(
name|u_short
name|sel
parameter_list|)
function_decl|;
end_function_decl

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
name|load_dr0
parameter_list|(
name|u_int
name|dr0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr1
parameter_list|(
name|u_int
name|dr1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr2
parameter_list|(
name|u_int
name|dr2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr3
parameter_list|(
name|u_int
name|dr3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr4
parameter_list|(
name|u_int
name|dr4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr5
parameter_list|(
name|u_int
name|dr5
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr6
parameter_list|(
name|u_int
name|dr6
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_dr7
parameter_list|(
name|u_int
name|dr7
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
specifier|const
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
specifier|const
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
specifier|const
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
name|rcr0
parameter_list|(
name|void
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
name|uint64_t
name|rdmsr
parameter_list|(
name|u_int
name|msr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|rdpmc
parameter_list|(
name|u_int
name|pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|rdr7
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|rdtsc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
name|read_cyrix_reg
parameter_list|(
name|u_char
name|reg
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
name|u_int
name|rfs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|rgdt
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
name|uint64_t
name|ridt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|rldt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|rtr
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
name|write_cyrix_reg
parameter_list|(
name|u_char
name|reg
parameter_list|,
name|u_char
name|data
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
name|uint64_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUCLIKE_ASM&& __CC_SUPPORTS___INLINE */
end_comment

begin_function_decl
name|void
name|reset_dbregs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|rdmsr_safe
parameter_list|(
name|u_int
name|msr
parameter_list|,
name|uint64_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wrmsr_safe
parameter_list|(
name|u_int
name|msr
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

