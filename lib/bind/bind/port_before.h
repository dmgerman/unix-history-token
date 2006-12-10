begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|port_before_h
end_ifndef

begin_define
define|#
directive|define
name|port_before_h
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_struct_decl
struct_decl|struct
name|group
struct_decl|;
end_struct_decl

begin_comment
comment|/* silence warning */
end_comment

begin_struct_decl
struct_decl|struct
name|passwd
struct_decl|;
end_struct_decl

begin_comment
comment|/* silence warning */
end_comment

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_comment
comment|/* silence warning */
end_comment

begin_struct_decl
struct_decl|struct
name|timezone
struct_decl|;
end_struct_decl

begin_comment
comment|/* silence warning */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMERS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timers.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_undef
undef|#
directive|undef
name|WANT_IRS_GR
end_undef

begin_undef
undef|#
directive|undef
name|WANT_IRS_NIS
end_undef

begin_undef
undef|#
directive|undef
name|WANT_IRS_PW
end_undef

begin_undef
undef|#
directive|undef
name|BSD_COMP
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_POLL
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_MD5
end_undef

begin_undef
undef|#
directive|undef
name|SOLARIS2
end_undef

begin_undef
undef|#
directive|undef
name|DO_PTHREADS
end_undef

begin_define
define|#
directive|define
name|GETGROUPLIST_ARGS
value|const char *name, gid_t basegid, gid_t *groups, int *ngroups
end_define

begin_define
define|#
directive|define
name|GETNETBYADDR_ADDR_T
value|unsigned long int
end_define

begin_define
define|#
directive|define
name|SETPWENT_VOID
value|1
end_define

begin_undef
undef|#
directive|undef
name|SETGRENT_VOID
end_undef

begin_define
define|#
directive|define
name|NET_R_ARGS
value|char *buf, size_t buflen, struct netent **answerp, int *h_errnop
end_define

begin_define
define|#
directive|define
name|NET_R_BAD
value|ERANGE
end_define

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
value|char *buf, size_t buflen
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
name|NET_R_END_RETURN
value|void
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
name|NET_R_OK
value|0
end_define

begin_define
define|#
directive|define
name|NET_R_RETURN
value|int
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
name|NET_R_SETANSWER
value|1
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
name|NETENT_DATA
end_undef

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
name|GROUP_R_ENT_ARGS
value|void
end_define

begin_define
define|#
directive|define
name|HOST_R_ARGS
value|char *buf, size_t buflen, struct hostent **answerp, int *h_errnop
end_define

begin_define
define|#
directive|define
name|HOST_R_BAD
value|ERANGE
end_define

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
name|HOST_R_END_RETURN
value|void
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
name|HOST_R_ERRNO
value|*h_errnop = h_errno
end_define

begin_define
define|#
directive|define
name|HOST_R_OK
value|0
end_define

begin_define
define|#
directive|define
name|HOST_R_RETURN
value|int
end_define

begin_define
define|#
directive|define
name|HOST_R_SETANSWER
value|1
end_define

begin_undef
undef|#
directive|undef
name|HOST_R_SET_RESULT
end_undef

begin_define
define|#
directive|define
name|HOST_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|HOSTENT_DATA
end_undef

begin_define
define|#
directive|define
name|NGR_R_ARGS
value|char *buf, int buflen
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
name|NGR_R_END_RESULT
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
name|NGR_R_END_RETURN
value|void
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
name|NGR_R_OK
value|1
end_define

begin_define
define|#
directive|define
name|NGR_R_RETURN
value|int
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
name|NGR_R_SET_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|PROTO_R_ARGS
value|char *buf, size_t buflen, struct protoent **answerp
end_define

begin_define
define|#
directive|define
name|PROTO_R_BAD
value|ERANGE
end_define

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
value|char *buf, size_t buflen
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
name|PROTO_R_END_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|PROTO_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_undef
undef|#
directive|undef
name|PROTO_R_ENT_UNUSED
end_undef

begin_define
define|#
directive|define
name|PROTO_R_OK
value|0
end_define

begin_define
define|#
directive|define
name|PROTO_R_SETANSWER
value|1
end_define

begin_define
define|#
directive|define
name|PROTO_R_RETURN
value|int
end_define

begin_undef
undef|#
directive|undef
name|PROTO_R_SET_RESULT
end_undef

begin_define
define|#
directive|define
name|PROTO_R_SET_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|PROTOENT_DATA
end_undef

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
name|PASS_R_END_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|PASS_R_ENT_ARGS
end_undef

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
name|PASS_R_SET_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|SERV_R_ARGS
value|char *buf, size_t buflen, struct servent **answerp
end_define

begin_define
define|#
directive|define
name|SERV_R_BAD
value|ERANGE
end_define

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
value|char *buf, size_t buflen
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
name|SERV_R_END_RETURN
value|void
end_define

begin_undef
undef|#
directive|undef
name|SERV_R_ENT_ARGS
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_undef
undef|#
directive|undef
name|SERV_R_ENT_UNUSED
end_undef

begin_comment
comment|/*empty*/
end_comment

begin_define
define|#
directive|define
name|SERV_R_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|SERV_R_SETANSWER
value|1
end_define

begin_define
define|#
directive|define
name|SERV_R_RETURN
value|int
end_define

begin_undef
undef|#
directive|undef
name|SERV_R_SET_RESULT
end_undef

begin_define
define|#
directive|define
name|SERV_R_SET_RETURN
value|void
end_define

begin_define
define|#
directive|define
name|DE_CONST
parameter_list|(
name|konst
parameter_list|,
name|var
parameter_list|)
define|\
value|do { \                 union { const void *k; void *v; } _u; \                 _u.k = konst; \                 var = _u.v; \         } while (0)
end_define

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|(x) = (x)
end_define

begin_undef
undef|#
directive|undef
name|NEED_SOLARIS_BITTYPES
end_undef

begin_define
define|#
directive|define
name|ISC_SOCKLEN_T
value|socklen_t
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

begin_comment
comment|/* Pull in host order macros when _XOPEN_SOURCE_EXTENDED is defined. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
name|defined
argument_list|(
name|_XOPEN_SOURCE_EXTENDED
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/byteorder.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

