begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|WANT_IRS_NIS
end_define

begin_define
define|#
directive|define
name|WANT_IRS_PW
end_define

begin_define
define|#
directive|define
name|WANT_IRS_GR
end_define

begin_define
define|#
directive|define
name|SIG_FN
value|void
end_define

begin_define
define|#
directive|define
name|ts_sec
value|tv_sec
end_define

begin_define
define|#
directive|define
name|ts_nsec
value|tv_nsec
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_PTHREADS
argument_list|)
operator|&&
name|defined
argument_list|(
name|_REENTRANT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DO_PTHREADS
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
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
end_if

begin_define
define|#
directive|define
name|SETPWENT_VOID
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

