begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_syscall.h - various ways to perform the ntp_adjtime() and ntp_gettime()  * 		   system calls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_SYSCALL_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_SYSCALL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMEX_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_SYSCALLS_STD
end_ifdef

begin_define
define|#
directive|define
name|ntp_adjtime
parameter_list|(
name|t
parameter_list|)
value|syscall(SYS_ntp_adjtime, (t))
end_define

begin_define
define|#
directive|define
name|ntp_gettime
parameter_list|(
name|t
parameter_list|)
value|syscall(SYS_ntp_gettime, (t))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NTP_SYSCALLS_STD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE___ADJTIMEX
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|__adjtimex
name|P
argument_list|(
operator|(
expr|struct
name|timex
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ntp_adjtime
parameter_list|(
name|t
parameter_list|)
value|__adjtimex((t))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|ntp_gettime
parameter_list|(
name|struct
name|ntptimeval
modifier|*
name|ntv
parameter_list|)
block|{
name|struct
name|timex
name|tntx
decl_stmt|;
name|int
name|result
decl_stmt|;
name|tntx
operator|.
name|modes
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|__adjtimex
argument_list|(
operator|&
name|tntx
argument_list|)
expr_stmt|;
name|ntv
operator|->
name|time
operator|=
name|tntx
operator|.
name|time
expr_stmt|;
name|ntv
operator|->
name|maxerror
operator|=
name|tntx
operator|.
name|maxerror
expr_stmt|;
name|ntv
operator|->
name|esterror
operator|=
name|tntx
operator|.
name|esterror
expr_stmt|;
ifdef|#
directive|ifdef
name|NTP_API
if|#
directive|if
name|NTP_API
operator|>
literal|3
name|ntv
operator|->
name|tai
operator|=
name|tntx
operator|.
name|tai
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE__ADJTIMEX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE___NTP_GETTIME
end_ifdef

begin_define
define|#
directive|define
name|ntp_gettime
parameter_list|(
name|t
parameter_list|)
value|__ntp_gettime((t))
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
comment|/* !HAVE_ADJTIMEX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NTP_SYSCALLS_STD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_SYSCALL_H */
end_comment

end_unit

