begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|"sio.h"
end_include

begin_decl_stmt
name|unsigned
name|int
name|bio_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|cam_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|net_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|tty_imask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
specifier|static
name|void
name|swi_net
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|void
argument_list|(
argument|*netisrs[
literal|32
argument|]
argument_list|)
end_macro

begin_expr_stmt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|swihand_t
modifier|*
name|ihandlers
index|[
literal|32
index|]
init|=
block|{
comment|/* software interrupts */
name|swi_null
block|,
name|swi_net
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|softclock
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|,
name|swi_null
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|netisr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|ipending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|idelayed
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|getcpl
parameter_list|()
value|(alpha_pal_rdps()& ALPHA_PSL_IPL_MASK)
end_define

begin_function
specifier|static
name|void
name|atomic_setbit
parameter_list|(
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|bit
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	"1:\tldl_l %0,%2\n\t"
comment|/* load current mask value, asserting lock */
asm|"or %3,%0,%0\n\t"
comment|/* add our bits */
asm|"stl_c %0,%1\n\t"
comment|/* attempt to store */
asm|"beq %0,2f\n\t"
comment|/* if the store failed, spin */
asm|"br 3f\n"
comment|/* it worked, exit */
asm|"2:\tbr 1b\n"
comment|/* *p not updated, loop */
asm|"3:\tmb\n"
comment|/* it worked */
asm|: "=&r"(temp), "=m" (*p) 	: "m"(*p), "r"(bit) 	: "memory");
block|}
end_function

begin_function
specifier|static
name|u_int32_t
name|atomic_readandclear
parameter_list|(
name|u_int32_t
modifier|*
name|p
parameter_list|)
block|{
name|u_int32_t
name|v
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( 	"wmb\n"
comment|/* ensure pending writes have drained */
asm|"1:\tldl_l %0,%3\n\t"
comment|/* load current value, asserting lock */
asm|"ldiq %1,0\n\t"
comment|/* value to store */
asm|"stl_c %1,%2\n\t"
comment|/* attempt to store */
asm|"beq %1,2f\n\t"
comment|/* if the store failed, spin */
asm|"br 3f\n"
comment|/* it worked, exit */
asm|"2:\tbr 1b\n"
comment|/* *p not updated, loop */
asm|"3:\tmb\n"
comment|/* it worked */
asm|: "=&r"(v), "=&r"(temp), "=m" (*p) 	: "m"(*p) 	: "memory");
return|return
name|v
return|;
block|}
end_function

begin_function
name|void
name|swi_null
parameter_list|()
block|{
comment|/* No interrupt registered, do nothing */
block|}
end_function

begin_function
name|void
name|swi_generic
parameter_list|()
block|{
comment|/* Just a placeholder, we call swi_dispatcher directly */
name|panic
argument_list|(
literal|"swi_generic() called"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|swi_net
parameter_list|()
block|{
name|u_int32_t
name|bits
init|=
name|atomic_readandclear
argument_list|(
operator|&
name|netisr
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|bits
operator|&
literal|1
condition|)
name|netisrs
index|[
name|i
index|]
operator|(
operator|)
expr_stmt|;
name|bits
operator|>>=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|do_sir
parameter_list|()
block|{
name|u_int32_t
name|pend
decl_stmt|;
name|int
name|i
decl_stmt|;
name|atomic_add_int
argument_list|(
operator|&
name|intr_nesting_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|splsoft
argument_list|()
expr_stmt|;
while|while
condition|(
operator|(
name|pend
operator|=
name|atomic_readandclear
argument_list|(
operator|&
name|ipending
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|pend
operator|&&
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|pend
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
block|{
if|if
condition|(
name|ihandlers
index|[
name|i
index|]
operator|==
name|swi_generic
condition|)
name|swi_dispatcher
argument_list|(
name|i
argument_list|)
expr_stmt|;
else|else
name|ihandlers
index|[
name|i
index|]
operator|(
operator|)
expr_stmt|;
name|pend
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
block|}
block|}
block|}
name|atomic_subtract_int
argument_list|(
operator|&
name|intr_nesting_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|GENSET
parameter_list|(
name|name
parameter_list|,
name|ptr
parameter_list|,
name|bit
parameter_list|)
define|\ 						\
value|void name(void)					\ {						\     atomic_setbit(ptr, bit);			\ }
end_define

begin_macro
name|GENSET
argument_list|(
argument|setdelayed
argument_list|,
argument|&ipending
argument_list|,
argument|atomic_readandclear(&idelayed)
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsofttty
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_TTY
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsoftnet
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_NET
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsoftcamnet
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_CAMNET
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsoftcambio
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_CAMBIO
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsoftvm
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_VM
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsofttq
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_TQ
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|setsoftclock
argument_list|,
argument|&ipending
argument_list|,
literal|1
argument|<< SWI_CLOCK
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsofttty
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_TTY
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsoftnet
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_NET
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsoftcamnet
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_CAMNET
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsoftcambio
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_CAMBIO
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsoftvm
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_VM
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsofttq
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_TQ
argument_list|)
end_macro

begin_macro
name|GENSET
argument_list|(
argument|schedsoftclock
argument_list|,
argument|&idelayed
argument_list|,
literal|1
argument|<< SWI_CLOCK
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANT_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|SPLASSERT_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|SPLASSERT_LOG
value|1
end_define

begin_define
define|#
directive|define
name|SPLASSERT_PANIC
value|2
end_define

begin_decl_stmt
specifier|static
name|int
name|splassertmode
init|=
name|SPLASSERT_LOG
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|splassertmode
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|splassertmode
argument_list|,
literal|0
argument_list|,
literal|"Set the mode of SPLASSERT"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"kern.splassertmode"
argument_list|,
operator|&
name|splassertmode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|splassertfail
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|level
parameter_list|)
block|{
switch|switch
condition|(
name|splassertmode
condition|)
block|{
case|case
name|SPLASSERT_IGNORE
case|:
break|break;
case|case
name|SPLASSERT_LOG
case|:
name|printf
argument_list|(
name|str
argument_list|,
name|msg
argument_list|,
name|name
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SPLASSERT_PANIC
case|:
name|panic
argument_list|(
name|str
argument_list|,
name|msg
argument_list|,
name|name
argument_list|,
name|level
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|GENSPLASSERT
parameter_list|(
name|name
parameter_list|,
name|pri
parameter_list|)
define|\
value|void							\ name##assert(const char *msg)				\ {							\ 	u_int cpl;					\ 							\ 	cpl = getcpl();					\ 	if (cpl< ALPHA_PSL_IPL_##pri)			\ 		splassertfail("%s: not %s, cpl == %#x",	\ 		    msg, __XSTRING(name) + 3, cpl);	\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GENSPLASSERT
parameter_list|(
name|name
parameter_list|,
name|pri
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splbio
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splcam
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splclock
argument_list|,
argument|CLOCK
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splhigh
argument_list|,
argument|HIGH
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splimp
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splnet
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsoftcam
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsoftcambio
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_comment
comment|/* XXX no corresponding spl for alpha */
end_comment

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsoftcamnet
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_comment
comment|/* XXX no corresponding spl for alpha */
end_comment

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsoftclock
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsofttty
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_comment
comment|/* XXX no corresponding spl for alpha */
end_comment

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsoftvm
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splsofttq
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splstatclock
argument_list|,
argument|CLOCK
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|spltty
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|GENSPLASSERT
argument_list|(
argument|splvm
argument_list|,
argument|IO
argument_list|)
end_macro

end_unit

