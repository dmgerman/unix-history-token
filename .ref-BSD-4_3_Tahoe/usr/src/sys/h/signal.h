begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)signal.h	7.3 (Berkeley) 5/14/88  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

begin_define
define|#
directive|define
name|NSIG
value|32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../machine/trap.h"
end_include

begin_comment
comment|/* codes for SIGILL, SIGFPE */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_comment
comment|/* codes for SIGILL, SIGFPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_comment
comment|/* hangup */
end_comment

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_comment
comment|/* interrupt */
end_comment

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_comment
comment|/* quit */
end_comment

begin_define
define|#
directive|define
name|SIGILL
value|4
end_define

begin_comment
comment|/* illegal instruction (not reset when caught) */
end_comment

begin_define
define|#
directive|define
name|SIGTRAP
value|5
end_define

begin_comment
comment|/* trace trap (not reset when caught) */
end_comment

begin_define
define|#
directive|define
name|SIGIOT
value|6
end_define

begin_comment
comment|/* IOT instruction */
end_comment

begin_define
define|#
directive|define
name|SIGABRT
value|SIGIOT
end_define

begin_comment
comment|/* compatibility */
end_comment

begin_define
define|#
directive|define
name|SIGEMT
value|7
end_define

begin_comment
comment|/* EMT instruction */
end_comment

begin_define
define|#
directive|define
name|SIGFPE
value|8
end_define

begin_comment
comment|/* floating point exception */
end_comment

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_comment
comment|/* kill (cannot be caught or ignored) */
end_comment

begin_define
define|#
directive|define
name|SIGBUS
value|10
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|SIGSEGV
value|11
end_define

begin_comment
comment|/* segmentation violation */
end_comment

begin_define
define|#
directive|define
name|SIGSYS
value|12
end_define

begin_comment
comment|/* bad argument to system call */
end_comment

begin_define
define|#
directive|define
name|SIGPIPE
value|13
end_define

begin_comment
comment|/* write on a pipe with no one to read it */
end_comment

begin_define
define|#
directive|define
name|SIGALRM
value|14
end_define

begin_comment
comment|/* alarm clock */
end_comment

begin_define
define|#
directive|define
name|SIGTERM
value|15
end_define

begin_comment
comment|/* software termination signal from kill */
end_comment

begin_define
define|#
directive|define
name|SIGURG
value|16
end_define

begin_comment
comment|/* urgent condition on IO channel */
end_comment

begin_define
define|#
directive|define
name|SIGSTOP
value|17
end_define

begin_comment
comment|/* sendable stop signal not from tty */
end_comment

begin_define
define|#
directive|define
name|SIGTSTP
value|18
end_define

begin_comment
comment|/* stop signal from tty */
end_comment

begin_define
define|#
directive|define
name|SIGCONT
value|19
end_define

begin_comment
comment|/* continue a stopped process */
end_comment

begin_define
define|#
directive|define
name|SIGCHLD
value|20
end_define

begin_comment
comment|/* to parent on child stop or exit */
end_comment

begin_define
define|#
directive|define
name|SIGCLD
value|SIGCHLD
end_define

begin_comment
comment|/* compatibility */
end_comment

begin_define
define|#
directive|define
name|SIGTTIN
value|21
end_define

begin_comment
comment|/* to readers pgrp upon background tty read */
end_comment

begin_define
define|#
directive|define
name|SIGTTOU
value|22
end_define

begin_comment
comment|/* like TTIN for output if (tp->t_local&LTOSTOP) */
end_comment

begin_define
define|#
directive|define
name|SIGIO
value|23
end_define

begin_comment
comment|/* input/output possible signal */
end_comment

begin_define
define|#
directive|define
name|SIGXCPU
value|24
end_define

begin_comment
comment|/* exceeded CPU time limit */
end_comment

begin_define
define|#
directive|define
name|SIGXFSZ
value|25
end_define

begin_comment
comment|/* exceeded file size limit */
end_comment

begin_define
define|#
directive|define
name|SIGVTALRM
value|26
end_define

begin_comment
comment|/* virtual time alarm */
end_comment

begin_define
define|#
directive|define
name|SIGPROF
value|27
end_define

begin_comment
comment|/* profiling time alarm */
end_comment

begin_define
define|#
directive|define
name|SIGWINCH
value|28
end_define

begin_comment
comment|/* window size changes */
end_comment

begin_define
define|#
directive|define
name|SIGUSR1
value|30
end_define

begin_comment
comment|/* user defined signal 1 */
end_comment

begin_define
define|#
directive|define
name|SIGUSR2
value|31
end_define

begin_comment
comment|/* user defined signal 2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_expr_stmt
name|int
argument_list|(
operator|*
name|signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Signal vector "template" used in sigvec call.  */
end_comment

begin_struct
struct|struct
name|sigvec
block|{
name|int
function_decl|(
modifier|*
name|sv_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* signal handler */
name|int
name|sv_mask
decl_stmt|;
comment|/* signal mask to apply */
name|int
name|sv_flags
decl_stmt|;
comment|/* see signal options below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SV_ONSTACK
value|0x0001
end_define

begin_comment
comment|/* take signal on signal stack */
end_comment

begin_define
define|#
directive|define
name|SV_INTERRUPT
value|0x0002
end_define

begin_comment
comment|/* do not restart system on signal return */
end_comment

begin_define
define|#
directive|define
name|sv_onstack
value|sv_flags
end_define

begin_comment
comment|/* isn't compatibility wonderful! */
end_comment

begin_comment
comment|/*  * Structure used in sigstack call.  */
end_comment

begin_struct
struct|struct
name|sigstack
block|{
name|char
modifier|*
name|ss_sp
decl_stmt|;
comment|/* signal stack pointer */
name|int
name|ss_onstack
decl_stmt|;
comment|/* current status */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to properly restore state if  * a non-standard exit is performed.  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|int
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_sp
decl_stmt|;
comment|/* sp to restore */
name|int
name|sc_fp
decl_stmt|;
comment|/* fp to restore */
name|int
name|sc_ap
decl_stmt|;
comment|/* ap to restore */
name|int
name|sc_pc
decl_stmt|;
comment|/* pc to restore */
name|int
name|sc_ps
decl_stmt|;
comment|/* psl to restore */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BADSIG
value|(int (*)())-1
end_define

begin_define
define|#
directive|define
name|SIG_DFL
value|(int (*)())0
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|(int (*)())1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SIG_CATCH
value|(int (*)())2
end_define

begin_define
define|#
directive|define
name|SIG_HOLD
value|(int (*)())3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macro for converting signal number to a mask suitable for  * sigblock().  */
end_comment

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|m
parameter_list|)
value|(1<< ((m)-1))
end_define

end_unit

