begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSF1_SIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_OSF1_SIGNAL_H
end_define

begin_define
define|#
directive|define
name|OSF1_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|OSF1_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|OSF1_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|OSF1_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|OSF1_SIGEMT
value|7
end_define

begin_define
define|#
directive|define
name|OSF1_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|OSF1_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|OSF1_SIGBUS
value|10
end_define

begin_define
define|#
directive|define
name|OSF1_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|OSF1_SIGSYS
value|12
end_define

begin_define
define|#
directive|define
name|OSF1_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|OSF1_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|OSF1_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|OSF1_SIGURG
value|16
end_define

begin_define
define|#
directive|define
name|OSF1_SIGSTOP
value|17
end_define

begin_define
define|#
directive|define
name|OSF1_SIGTSTP
value|18
end_define

begin_define
define|#
directive|define
name|OSF1_SIGCONT
value|19
end_define

begin_define
define|#
directive|define
name|OSF1_SIGCHLD
value|20
end_define

begin_define
define|#
directive|define
name|OSF1_SIGTTIN
value|21
end_define

begin_define
define|#
directive|define
name|OSF1_SIGTTOU
value|22
end_define

begin_define
define|#
directive|define
name|OSF1_SIGIO
value|23
end_define

begin_define
define|#
directive|define
name|OSF1_SIGXCPU
value|24
end_define

begin_define
define|#
directive|define
name|OSF1_SIGXFSZ
value|25
end_define

begin_define
define|#
directive|define
name|OSF1_SIGVTALRM
value|26
end_define

begin_define
define|#
directive|define
name|OSF1_SIGPROF
value|27
end_define

begin_define
define|#
directive|define
name|OSF1_SIGWINCH
value|28
end_define

begin_define
define|#
directive|define
name|OSF1_SIGINFO
value|29
end_define

begin_define
define|#
directive|define
name|OSF1_SIGUSR1
value|30
end_define

begin_define
define|#
directive|define
name|OSF1_SIGUSR2
value|31
end_define

begin_define
define|#
directive|define
name|OSF1_NSIG
value|32
end_define

begin_define
define|#
directive|define
name|OSF1_SIGTBLSZ
value|32
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_DFL
value|0
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_ERR
value|-1
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_IGN
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_HOLD
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_SIGNO
parameter_list|(
name|a
parameter_list|)
value|((a)& OSF1_SIGNO_MASK)
end_define

begin_define
define|#
directive|define
name|OSF1_SIGCALL
parameter_list|(
name|a
parameter_list|)
value|((a)& ~OSF1_SIGNO_MASK)
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_UNBLOCK
value|2
end_define

begin_define
define|#
directive|define
name|OSF1_SIG_SETMASK
value|3
end_define

begin_define
define|#
directive|define
name|OSF1_BSD2OSF1_SIG
parameter_list|(
name|sig
parameter_list|)
define|\
value|(((sig)<= OSF1_SIGTBLSZ) ? bsd_to_osf1_sig[_SIG_IDX(sig)] : sig)
end_define

begin_define
define|#
directive|define
name|OSF1_OSF12BSD_SIG
parameter_list|(
name|sig
parameter_list|)
define|\
value|(((sig)<= OSF1_SIGTBLSZ) ? osf1_to_bsd_sig[_SIG_IDX(sig)] : sig)
end_define

begin_typedef
typedef|typedef
name|u_long
name|osf1_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*osf1_handler_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|osf1_sigaction
block|{
name|osf1_handler_t
name|osa_handler
decl_stmt|;
name|osf1_sigset_t
name|osa_mask
decl_stmt|;
name|int
name|osa_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|osf1_sigaltstack
block|{
name|caddr_t
name|ss_sp
decl_stmt|;
name|int
name|ss_flags
decl_stmt|;
name|size_t
name|ss_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sa_flags */
end_comment

begin_define
define|#
directive|define
name|OSF1_SA_ONSTACK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OSF1_SA_RESTART
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OSF1_SA_NOCLDSTOP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|OSF1_SA_NODEFER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|OSF1_SA_RESETHAND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|OSF1_SA_NOCLDWAIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|OSF1_SA_SIGINFO
value|0x00000040
end_define

begin_comment
comment|/* ss_flags */
end_comment

begin_define
define|#
directive|define
name|OSF1_SS_ONSTACK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OSF1_SS_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OSF1_SIGNO_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|OSF1_SIGNAL_MASK
value|0x0000
end_define

begin_define
define|#
directive|define
name|OSF1_SIGDEFER_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|OSF1_SIGHOLD_MASK
value|0x0200
end_define

begin_define
define|#
directive|define
name|OSF1_SIGRELSE_MASK
value|0x0400
end_define

begin_define
define|#
directive|define
name|OSF1_SIGIGNORE_MASK
value|0x0800
end_define

begin_define
define|#
directive|define
name|OSF1_SIGPAUSE_MASK
value|0x1000
end_define

begin_decl_stmt
specifier|extern
name|int
name|osf1_to_linux_sig
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bsd_to_osf1_sigaltstack
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|sigaltstack
operator|*
operator|,
expr|struct
name|osf1_sigaltstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bsd_to_osf1_sigset
name|__P
argument_list|(
operator|(
specifier|const
name|sigset_t
operator|*
operator|,
name|osf1_sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|osf1_to_bsd_sigaltstack
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|osf1_sigaltstack
operator|*
operator|,
expr|struct
name|sigaltstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|osf1_to_bsd_sigset
name|__P
argument_list|(
operator|(
specifier|const
name|osf1_sigset_t
operator|*
operator|,
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|osf1_sendsig
name|__P
argument_list|(
operator|(
name|sig_t
operator|,
name|int
operator|,
name|sigset_t
operator|*
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OSF1_SIGNAL_H */
end_comment

end_unit

