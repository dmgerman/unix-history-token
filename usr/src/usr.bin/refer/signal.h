begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|K_INT_OVF_T
value|0x1
end_define

begin_comment
comment|/* integer overflow */
end_comment

begin_define
define|#
directive|define
name|K_INT_DIV_T
value|0x2
end_define

begin_comment
comment|/* integer divide by zero */
end_comment

begin_define
define|#
directive|define
name|K_FLT_OVF_T
value|0x3
end_define

begin_comment
comment|/* floating overflow */
end_comment

begin_define
define|#
directive|define
name|K_FLT_DIV_T
value|0x4
end_define

begin_comment
comment|/* floating/decimal divide by zero */
end_comment

begin_define
define|#
directive|define
name|K_FLT_UND_T
value|0x5
end_define

begin_comment
comment|/* floating underflow */
end_comment

begin_define
define|#
directive|define
name|K_DEC_OVF_T
value|0x6
end_define

begin_comment
comment|/* decimal overflow */
end_comment

begin_define
define|#
directive|define
name|K_SUB_RNG_T
value|0x7
end_define

begin_comment
comment|/* subscript out of range */
end_comment

begin_define
define|#
directive|define
name|K_FLT_OVF_F
value|0x8
end_define

begin_comment
comment|/* floating overflow fault */
end_comment

begin_define
define|#
directive|define
name|K_FLT_DIV_F
value|0x9
end_define

begin_comment
comment|/* divide by zero floating fault */
end_comment

begin_define
define|#
directive|define
name|K_FLT_UND_F
value|0xa
end_define

begin_comment
comment|/* floating underflow fault */
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
name|SIGTINT
value|23
end_define

begin_comment
comment|/* to pgrp on every input character if LINTRUP */
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

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|SIG_TYP
function_decl|)
parameter_list|()
function_decl|;
end_typedef

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIG_HOLD
value|(int (*)())3
end_define

begin_define
define|#
directive|define
name|SIGISDEFER
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)& 1) != 0)
end_define

begin_define
define|#
directive|define
name|SIGUNDEFER
parameter_list|(
name|x
parameter_list|)
value|(int (*)())((int)(x)&~ 1)
end_define

begin_define
define|#
directive|define
name|DEFERSIG
parameter_list|(
name|x
parameter_list|)
value|(int (*)())((int)(x) | 1)
end_define

begin_define
define|#
directive|define
name|SIGNUMMASK
value|0377
end_define

begin_comment
comment|/* to extract pure signal number */
end_comment

begin_define
define|#
directive|define
name|SIGDOPAUSE
value|0400
end_define

begin_comment
comment|/* do pause after setting action */
end_comment

begin_define
define|#
directive|define
name|SIGDORTI
value|01000
end_define

begin_comment
comment|/* do ret+rti after setting action */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

