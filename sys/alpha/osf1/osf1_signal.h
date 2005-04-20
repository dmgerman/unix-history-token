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
name|OSF1_NSIG
value|64
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

begin_typedef
typedef|typedef
name|u_long
name|osf1_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|osf1_handler_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
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

begin_function_decl
name|void
name|bsd_to_osf1_sigaltstack
parameter_list|(
specifier|const
name|struct
name|sigaltstack
modifier|*
parameter_list|,
name|struct
name|osf1_sigaltstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_to_osf1_sigset
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|osf1_sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osf1_to_bsd_sigaltstack
parameter_list|(
specifier|const
name|struct
name|osf1_sigaltstack
modifier|*
parameter_list|,
name|struct
name|sigaltstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osf1_to_bsd_sigset
parameter_list|(
specifier|const
name|osf1_sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osf1_sendsig
parameter_list|(
name|sig_t
parameter_list|,
name|int
parameter_list|,
name|sigset_t
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OSF1_SIGNAL_H */
end_comment

end_unit

