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
name|HAVE_PW_CLASS
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
name|HAS_PTHREADS
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|GROUP_R_RETURN
value|struct group *
end_define

begin_define
define|#
directive|define
name|GROUP_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|GROUP_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|GROUP_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|GROUP_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|GROUP_R_ARGS
value|char *buf, int buflen
end_define

begin_define
define|#
directive|define
name|GROUP_R_ENT_ARGS
value|void
end_define

begin_define
define|#
directive|define
name|GROUP_R_OK
value|gptr
end_define

begin_define
define|#
directive|define
name|GROUP_R_BAD
value|NULL
end_define

begin_define
define|#
directive|define
name|GETGROUPLIST_ARGS
value|const char *name, int basegid, int *groups, \ 			  int *ngroups
end_define

begin_define
define|#
directive|define
name|HOST_R_RETURN
value|struct hostent *
end_define

begin_define
define|#
directive|define
name|HOST_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|HOST_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|HOST_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|HOST_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|HOST_R_ARGS
value|char *buf, int buflen, int *h_errnop
end_define

begin_undef
undef|#
directive|undef
name|HOST_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|HOST_R_COPY
value|buf, buflen
end_define

begin_define
define|#
directive|define
name|HOST_R_COPY_ARGS
value|char *buf, int buflen
end_define

begin_define
define|#
directive|define
name|HOST_R_ERRNO
value|*h_errnop = h_errno
end_define

begin_define
define|#
directive|define
name|HOST_R_OK
value|hptr
end_define

begin_define
define|#
directive|define
name|HOST_R_BAD
value|NULL
end_define

begin_define
define|#
directive|define
name|NET_R_RETURN
value|struct netent *
end_define

begin_define
define|#
directive|define
name|NET_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|NET_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|NET_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|NET_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|NET_R_ARGS
value|char *buf, int buflen
end_define

begin_undef
undef|#
directive|undef
name|NET_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|NET_R_COPY
value|buf, buflen
end_define

begin_define
define|#
directive|define
name|NET_R_COPY_ARGS
value|NET_R_ARGS
end_define

begin_define
define|#
directive|define
name|NET_R_OK
value|nptr
end_define

begin_define
define|#
directive|define
name|NET_R_BAD
value|NULL
end_define

begin_define
define|#
directive|define
name|NGR_R_RETURN
value|int
end_define

begin_define
define|#
directive|define
name|NGR_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|NGR_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|NGR_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|NGR_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
value|return
end_define

begin_define
define|#
directive|define
name|NGR_R_ARGS
value|char *buf, int buflen
end_define

begin_undef
undef|#
directive|undef
name|NGR_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|NGR_R_COPY
value|buf, buflen
end_define

begin_define
define|#
directive|define
name|NGR_R_COPY_ARGS
value|NGR_R_ARGS
end_define

begin_define
define|#
directive|define
name|NGR_R_OK
value|1
end_define

begin_define
define|#
directive|define
name|NGR_R_BAD
value|(0)
end_define

begin_define
define|#
directive|define
name|PROTO_R_RETURN
value|struct protoent *
end_define

begin_define
define|#
directive|define
name|PROTO_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|PROTO_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|PROTO_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|PROTO_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|PROTO_R_ARGS
value|char *buf, int buflen
end_define

begin_undef
undef|#
directive|undef
name|PROTO_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|PROTO_R_COPY
value|buf, buflen
end_define

begin_define
define|#
directive|define
name|PROTO_R_COPY_ARGS
value|PROTO_R_ARGS
end_define

begin_define
define|#
directive|define
name|PROTO_R_OK
value|pptr
end_define

begin_define
define|#
directive|define
name|PROTO_R_BAD
value|NULL
end_define

begin_define
define|#
directive|define
name|PASS_R_RETURN
value|struct passwd *
end_define

begin_define
define|#
directive|define
name|PASS_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|PASS_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|PASS_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|PASS_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|PASS_R_ARGS
value|char *buf, int buflen
end_define

begin_undef
undef|#
directive|undef
name|PASS_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|PASS_R_COPY
value|buf, buflen
end_define

begin_define
define|#
directive|define
name|PASS_R_COPY_ARGS
value|PASS_R_ARGS
end_define

begin_define
define|#
directive|define
name|PASS_R_OK
value|pwptr
end_define

begin_define
define|#
directive|define
name|PASS_R_BAD
value|NULL
end_define

begin_define
define|#
directive|define
name|SERV_R_RETURN
value|struct servent *
end_define

begin_define
define|#
directive|define
name|SERV_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|SERV_R_SET_RESULT
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|SERV_R_END_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|SERV_R_END_RESULT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|SERV_R_ARGS
value|char *buf, int buflen
end_define

begin_undef
undef|#
directive|undef
name|SERV_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|SERV_R_COPY
value|buf, buflen
end_define

begin_define
define|#
directive|define
name|SERV_R_COPY_ARGS
value|SERV_R_ARGS
end_define

begin_define
define|#
directive|define
name|SERV_R_OK
value|sptr
end_define

begin_define
define|#
directive|define
name|SERV_R_BAD
value|NULL
end_define

begin_define
define|#
directive|define
name|IRS_LCL_SV_DB
end_define

begin_define
define|#
directive|define
name|ISC_SOCKLEN_T
value|int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ISC_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
define|\
value|__attribute__((__format__(__printf__, fmt, args)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_FORMAT_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

