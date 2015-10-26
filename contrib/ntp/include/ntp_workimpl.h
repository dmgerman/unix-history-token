begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_workimpl.h - selects worker child implementation  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_WORKIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_WORKIMPL_H
end_define

begin_comment
comment|/*  * Some systems do not support fork() and don't have an alternate  * threads implementation of ntp_intres.  Such systems are limited  * to using numeric IP addresses.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_define
define|#
directive|define
name|WORK_THREAD
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ISC_PLATFORM_USETHREADS
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_SEM_TIMEDWAIT
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|HAVE_GETCLOCK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_CLOCK_GETTIME
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|WORK_THREAD
end_define

begin_define
define|#
directive|define
name|WORK_PIPE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
end_elif

begin_comment
comment|/* empty */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_WORKING_FORK
argument_list|)
end_elif

begin_define
define|#
directive|define
name|WORK_FORK
end_define

begin_define
define|#
directive|define
name|WORK_PIPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WORK_FORK
argument_list|)
operator|||
name|defined
argument_list|(
name|WORK_THREAD
argument_list|)
end_if

begin_define
define|#
directive|define
name|WORKER
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
comment|/* !NTP_WORKIMPL_H */
end_comment

end_unit

