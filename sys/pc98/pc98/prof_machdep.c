begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * NEED A COPYRIGHT NOPTICE HERE  *  *	$Id: prof_machdep.c,v 1.2 1996/04/08 16:41:06 wollman Exp $  */
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
file|<machine/clock.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_include
include|#
directive|include
file|<pc98/pc98/timerreg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/timerreg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int
name|cputime
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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_asm
asm|asm(" GM_STATE	=	0 GMON_PROF_OFF	=	3  	.text 	.align	4,0x90 	.globl	__mcount __mcount: 	# 	# Check that we are profiling.  Do it early for speed. 	# 	cmpl	$GMON_PROF_OFF,__gmonparam+GM_STATE  	je	Lmcount_exit  	#  	# __mcount is the same as mcount except the caller hasn't changed  	# the stack except to call here, so the caller's raddr is above  	# our raddr.  	#  	movl	4(%esp),%edx  	jmp	Lgot_frompc    	.align	4,0x90  	.globl	mcount mcount: 	cmpl	$GMON_PROF_OFF,__gmonparam+GM_STATE 	je	Lmcount_exit 	# 	# The caller's stack frame has already been built, so %ebp is 	# the caller's frame pointer.  The caller's raddr is in the 	# caller's frame following the caller's caller's frame pointer. 	# 	movl	4(%ebp),%edx Lgot_frompc: 	# 	# Our raddr is the caller's pc. 	# 	movl	(%esp),%eax  	pushf 	pushl	%eax 	pushl	%edx 	cli 	call	_mcount 	addl	$8,%esp 	popf Lmcount_exit: 	ret ");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GUPROF
end_ifdef

begin_comment
comment|/*  * mexitcount saves the return register(s), loads selfpc and calls  * mexitcount(selfpc) to do the work.  Someday it should be in a machine  * dependent file together with cputime(), __mcount and mcount.  cputime()  * can't just be put in machdep.c because it has to be compiled without -pg.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_asm
asm|asm(" 	.text # # Dummy label to be seen when gprof -u hides mexitcount. # 	.align	4,0x90 	.globl	__mexitcount __mexitcount: 	nop  GMON_PROF_HIRES	=	4  	.align	4,0x90 	.globl	mexitcount mexitcount: 	cmpl	$GMON_PROF_HIRES,__gmonparam+GM_STATE 	jne	Lmexitcount_exit 	pushl	%edx 	pushl	%eax 	movl	8(%esp),%eax 	pushf 	pushl	%eax 	cli 	call	_mexitcount 	addl	$4,%esp 	popf 	popl	%eax 	popl	%edx Lmexitcount_exit: 	ret ");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/*  * Return the time elapsed since the last call.  The units are machine-  * dependent.  */
end_comment

begin_function
name|u_int
name|cputime
parameter_list|()
block|{
name|u_int
name|count
decl_stmt|;
name|u_int
name|delta
decl_stmt|;
name|u_char
name|low
decl_stmt|;
specifier|static
name|u_int
name|prev_count
decl_stmt|;
comment|/* 	 * Read the current value of the 8254 timer counter 0. 	 */
name|outb
argument_list|(
name|TIMER_MODE
argument_list|,
name|TIMER_SEL0
operator||
name|TIMER_LATCH
argument_list|)
expr_stmt|;
name|low
operator|=
name|inb
argument_list|(
name|TIMER_CNTR0
argument_list|)
expr_stmt|;
name|count
operator|=
name|low
operator||
operator|(
name|inb
argument_list|(
name|TIMER_CNTR0
argument_list|)
operator|<<
literal|8
operator|)
expr_stmt|;
comment|/* 	 * The timer counts down from TIMER_CNTR0_MAX to 0 and then resets. 	 * While profiling is enabled, this routine is called at least twice 	 * per timer reset (for mcounting and mexitcounting hardclock()), 	 * so at most one reset has occurred since the last call, and one 	 * has occurred iff the current count is larger than the previous 	 * count.  This allows counter underflow to be detected faster 	 * than in microtime(). 	 */
name|delta
operator|=
name|prev_count
operator|-
name|count
expr_stmt|;
name|prev_count
operator|=
name|count
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|delta
operator|<=
literal|0
condition|)
return|return
operator|(
name|delta
operator|+
name|timer0_max_count
operator|)
return|;
return|return
operator|(
name|delta
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not GUPROF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_asm
asm|asm(" 	.text 	.align	4,0x90 	.globl	mexitcount mexitcount: 	ret ");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GUPROF */
end_comment

end_unit

