begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|BOTTOM
expr|@
end_expr_stmt

begin_undef
undef|#
directive|undef
name|BINDIR
end_undef

begin_undef
undef|#
directive|undef
name|LIBDIR
end_undef

begin_undef
undef|#
directive|undef
name|LIBEXECDIR
end_undef

begin_undef
undef|#
directive|undef
name|SBINDIR
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_INT8_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_INT16_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_INT32_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_INT64_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_U_INT8_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_U_INT16_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_U_INT32_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_U_INT64_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_UINT8_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_UINT16_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_UINT32_T
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_UINT64_T
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FOUR_VALUED_KRB_PUT_INT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|KRB4
argument_list|)
end_if

begin_define
define|#
directive|define
name|KRB_PUT_INT
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|,
name|L
parameter_list|,
name|S
parameter_list|)
value|krb_put_int((F), (T), (L), (S))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB_PUT_INT
parameter_list|(
name|F
parameter_list|,
name|T
parameter_list|,
name|L
parameter_list|,
name|S
parameter_list|)
value|krb_put_int((F), (T), (S))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_REALLOC
end_ifdef

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|isoc_realloc((X), (Y))
end_define

begin_define
define|#
directive|define
name|isoc_realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X) ? realloc((X), (Y)) : malloc(Y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOID_RETSIGTYPE
end_ifdef

begin_define
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return (RETSIGTYPE)(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|static
comment|/**/
value|const char *const rcsid[] = { (const char *)rcsid, "\100(#)" msg }
end_define

begin_undef
undef|#
directive|undef
name|PROTOTYPES
end_undef

begin_comment
comment|/* Maximum values on all known systems */
end_comment

begin_define
define|#
directive|define
name|MaxHostNameLen
value|(64+4)
end_define

begin_define
define|#
directive|define
name|MaxPathLen
value|(1024+4)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SGTTY_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|__NeXT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SGTTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define NDBM if you are using the 4.3 ndbm library (which is part of  * libc).  If not defined, 4.2 dbm will be assumed.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DBM_FIRSTKEY
argument_list|)
end_if

begin_define
define|#
directive|define
name|NDBM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* telnet stuff ----------------------------------------------- */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ENCRYPTION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|AUTHENTICATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|AUTHENTICATION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set this to the default system lead string for telnetd   * can contain %-escapes: %s=sysname, %m=machine, %r=os-release  * %v=os-version, %t=tty, %h=hostname, %d=date and time  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_IM
end_undef

begin_comment
comment|/* Used with login -p */
end_comment

begin_undef
undef|#
directive|undef
name|LOGIN_ARGS
end_undef

begin_comment
comment|/* set this to a sensible login */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGIN_PATH
end_ifndef

begin_define
define|#
directive|define
name|LOGIN_PATH
value|BINDIR "/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* random defines */
end_comment

begin_comment
comment|/*  * Defining this enables lots of useful (and used) extensions on  * glibc-based systems such as Linux  */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/*  * this assumes that KRB_C_BIGENDIAN is used.  * if we can find out endianess at compile-time, do so,  * otherwise WORDS_BIGENDIAN should already have been defined  */
end_comment

begin_if
if|#
directive|if
name|ENDIANESS_IN_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

