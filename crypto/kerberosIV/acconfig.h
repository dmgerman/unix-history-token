begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: acconfig.h,v 1.105 1999/12/02 13:09:41 joda Exp $ */
end_comment

begin_expr_stmt
unit|@
name|BOTTOM
expr|@
undef|#
directive|undef
name|HAVE_INT8_T
undef|#
directive|undef
name|HAVE_INT16_T
undef|#
directive|undef
name|HAVE_INT32_T
undef|#
directive|undef
name|HAVE_INT64_T
undef|#
directive|undef
name|HAVE_U_INT8_T
undef|#
directive|undef
name|HAVE_U_INT16_T
undef|#
directive|undef
name|HAVE_U_INT32_T
undef|#
directive|undef
name|HAVE_U_INT64_T
comment|/* This for compat with heimdal (or something) */
define|#
directive|define
name|KRB_PUT_INT
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|)
value|krb_put_int((f), (t), (l), (s))
define|#
directive|define
name|HAVE_KRB_ENABLE_DEBUG
value|1
define|#
directive|define
name|HAVE_KRB_DISABLE_DEBUG
value|1
define|#
directive|define
name|HAVE_KRB_GET_OUR_IP_FOR_REALM
value|1
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|static
comment|/**/
value|const char *const rcsid[] = { (char *)rcsid, "\100(#)" msg }
comment|/*  * Set ORGANIZATION to be the desired organization string printed  * by the 'kinit' program.  It may have spaces.  */
define|#
directive|define
name|ORGANIZATION
value|"eBones International"
if|#
directive|if
literal|0
undef|#
directive|undef
name|BINDIR
undef|#
directive|undef
name|LIBDIR
undef|#
directive|undef
name|LIBEXECDIR
undef|#
directive|undef
name|SBINDIR
endif|#
directive|endif
if|#
directive|if
literal|0
define|#
directive|define
name|KRB_CNF_FILES
value|{ "/etc/krb.conf",   "/etc/kerberosIV/krb.conf", 0}
define|#
directive|define
name|KRB_RLM_FILES
value|{ "/etc/krb.realms", "/etc/kerberosIV/krb.realms", 0}
define|#
directive|define
name|KRB_EQUIV
value|"/etc/krb.equiv"
define|#
directive|define
name|KEYFILE
value|"/etc/srvtab"
define|#
directive|define
name|KRBDIR
value|"/var/kerberos"
define|#
directive|define
name|DBM_FILE
value|KRBDIR "/principal"
define|#
directive|define
name|DEFAULT_ACL_DIR
value|KRBDIR
define|#
directive|define
name|KRBLOG
value|"/var/log/kerberos.log"
comment|/* master server  */
define|#
directive|define
name|KRBSLAVELOG
value|"/var/log/kerberos_slave.log"
comment|/* slave server  */
define|#
directive|define
name|KADM_SYSLOG
value|"/var/log/admin_server.syslog"
define|#
directive|define
name|K_LOGFIL
value|"/var/log/kpropd.log"
endif|#
directive|endif
comment|/* Maximum values on all known systems */
define|#
directive|define
name|MaxHostNameLen
value|(64+4)
define|#
directive|define
name|MaxPathLen
value|(1024+4)
comment|/* ftp stuff -------------------------------------------------- */
define|#
directive|define
name|KERBEROS
comment|/* telnet stuff ----------------------------------------------- */
comment|/* define this for OTP support */
undef|#
directive|undef
name|OTP
comment|/* define this if you have kerberos 4 */
undef|#
directive|undef
name|KRB4
comment|/* define this if you want encryption */
undef|#
directive|undef
name|ENCRYPTION
comment|/* define this if you want authentication */
undef|#
directive|undef
name|AUTHENTICATION
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
define|#
directive|define
name|AUTHENTICATION
value|1
endif|#
directive|endif
comment|/* Set this if you want des encryption */
undef|#
directive|undef
name|DES_ENCRYPTION
comment|/* Set this to the default system lead string for telnetd   * can contain %-escapes: %s=sysname, %m=machine, %r=os-release  * %v=os-version, %t=tty, %h=hostname, %d=date and time  */
undef|#
directive|undef
name|USE_IM
comment|/* define this if you want diagnostics in telnetd */
undef|#
directive|undef
name|DIAGNOSTICS
comment|/* define this if you want support for broken ENV_{VALUE,VAR} systems  */
undef|#
directive|undef
name|ENV_HACK
comment|/*  */
undef|#
directive|undef
name|OLD_ENVIRON
comment|/* Used with login -p */
undef|#
directive|undef
name|LOGIN_ARGS
comment|/* set this to a sensible login */
ifndef|#
directive|ifndef
name|LOGIN_PATH
define|#
directive|define
name|LOGIN_PATH
value|BINDIR "/login"
endif|#
directive|endif
comment|/* ------------------------------------------------------------ */
ifdef|#
directive|ifdef
name|BROKEN_REALLOC
define|#
directive|define
name|realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|isoc_realloc((X), (Y))
define|#
directive|define
name|isoc_realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X) ? realloc((X), (Y)) : malloc(Y))
endif|#
directive|endif
ifdef|#
directive|ifdef
name|VOID_RETSIGTYPE
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return
else|#
directive|else
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return (RETSIGTYPE)(x)
endif|#
directive|endif
comment|/* Temporary fixes for krb_{rd,mk}_safe */
define|#
directive|define
name|DES_QUAD_GUESS
value|0
define|#
directive|define
name|DES_QUAD_NEW
value|1
define|#
directive|define
name|DES_QUAD_OLD
value|2
comment|/*  * All these are system-specific defines that I would rather not have at all.  */
comment|/*  * AIX braindamage!  */
if|#
directive|if
name|_AIX
define|#
directive|define
name|_ALL_SOURCE
comment|/* XXX this is gross, but kills about a gazillion warnings */
expr|struct
name|ether_addr
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SYSTYPE_SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|_SYSTYPE_SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX
value|5
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRIX
value|4
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
comment|/* IRIX 4 braindamage */
end_comment

begin_if
if|#
directive|if
name|IRIX
operator|==
literal|4
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC__
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Defining this enables lots of useful (and used) extensions on  * glibc-based systems such as Linux  */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* some strange OS/2 stuff.  From<d96-mst@nada.kth.se> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_define
define|#
directive|define
name|_EMX_TCPIP
end_define

begin_define
define|#
directive|define
name|MAIL_USE_SYSTEM_LOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ROKEN_RENAME
end_ifdef

begin_include
include|#
directive|include
file|"roken_rename.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

