begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: acconfig.h,v 1.71 1997/06/01 22:32:24 assar Exp $ */
end_comment

begin_comment
comment|/*  Define this if RETSIGTYPE == void  */
end_comment

begin_undef
undef|#
directive|undef
name|VOID_RETSIGTYPE
end_undef

begin_comment
comment|/*  Define this if struct utmp have ut_user  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_USER
end_undef

begin_comment
comment|/*  Define this if struct utmp have ut_host  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_HOST
end_undef

begin_comment
comment|/*  Define this if struct utmp have ut_addr  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_ADDR
end_undef

begin_comment
comment|/*  Define this if struct utmp have ut_type  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_TYPE
end_undef

begin_comment
comment|/*  Define this if struct utmp have ut_pid  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_PID
end_undef

begin_comment
comment|/*  Define this if struct utmp have ut_id  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_ID
end_undef

begin_comment
comment|/*  Define this if struct utmpx have ut_syslen  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UT_SYSLEN
end_undef

begin_comment
comment|/*  Define this if struct winsize is declared in sys/termios.h */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRUCT_WINSIZE
end_undef

begin_comment
comment|/*  Define this if struct winsize have ws_xpixel */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_WS_XPIXEL
end_undef

begin_comment
comment|/*  Define this if struct winsize have ws_ypixel */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_WS_YPIXEL
end_undef

begin_comment
comment|/*  Define this to be the directory where the dictionary for cracklib */
end_comment

begin_comment
comment|/*  resides */
end_comment

begin_undef
undef|#
directive|undef
name|DICTPATH
end_undef

begin_comment
comment|/* Define this if you want to use SOCKS v5 */
end_comment

begin_undef
undef|#
directive|undef
name|SOCKS
end_undef

begin_comment
comment|/* Define this to the path of the mail spool directory */
end_comment

begin_undef
undef|#
directive|undef
name|KRB4_MAILDIR
end_undef

begin_comment
comment|/* Define this if `struct sockaddr' includes sa_len */
end_comment

begin_undef
undef|#
directive|undef
name|SOCKADDR_HAS_SA_LEN
end_undef

begin_comment
comment|/* Define this if `struct siaentity' includes ouid */
end_comment

begin_undef
undef|#
directive|undef
name|SIAENTITY_HAS_OUID
end_undef

begin_comment
comment|/* Define if getlogin has POSIX flavour, as opposed to BSD */
end_comment

begin_undef
undef|#
directive|undef
name|POSIX_GETLOGIN
end_undef

begin_comment
comment|/* Define if getpwnam_r has POSIX flavour */
end_comment

begin_undef
undef|#
directive|undef
name|POSIX_GETPWNAM_R
end_undef

begin_comment
comment|/* define if getcwd() is broken (such as in SunOS) */
end_comment

begin_undef
undef|#
directive|undef
name|BROKEN_GETCWD
end_undef

begin_comment
comment|/* define if the system is missing a prototype for crypt() */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_CRYPT_PROTO
end_undef

begin_comment
comment|/* define if the system is missing a prototype for strtok_r() */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_STRTOK_R_PROTO
end_undef

begin_comment
comment|/* define if /bin/ls takes -A */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LS_A
end_undef

begin_comment
comment|/* define if you have h_errno */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_ERRNO
end_undef

begin_comment
comment|/* define if you have h_errlist but not hstrerror */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_ERRLIST
end_undef

begin_comment
comment|/* define if you have h_nerr but not hstrerror */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_NERR
end_undef

begin_comment
comment|/* define if your system doesn't declare h_errlist */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_ERRLIST_DECLARATION
end_undef

begin_comment
comment|/* define if your system doesn't declare h_nerr */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_NERR_DECLARATION
end_undef

begin_comment
comment|/* define this if you need a declaration for h_errno */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_ERRNO_DECLARATION
end_undef

begin_comment
comment|/* define if you need a declaration for optarg */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPTARG_DECLARATION
end_undef

begin_comment
comment|/* define if you need a declaration for optind */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPTIND_DECLARATION
end_undef

begin_comment
comment|/* define if you need a declaration for opterr */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPTERR_DECLARATION
end_undef

begin_comment
comment|/* define if you need a declaration for optopt */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPTOPT_DECLARATION
end_undef

begin_comment
comment|/* define if you need a declaration for __progname */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE___PROGNAME_DECLARATION
end_undef

begin_expr_stmt
unit|@
name|BOTTOM
expr|@
end_expr_stmt

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
value|const char *const rcsid[] = { (char *)rcsid, "\100(#)" msg }
end_define

begin_comment
comment|/*  * Set ORGANIZATION to be the desired organization string printed  * by the 'kinit' program.  It may have spaces.  */
end_comment

begin_define
define|#
directive|define
name|ORGANIZATION
value|"eBones International"
end_define

begin_if
if|#
directive|if
literal|0
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|KRB_CNF_FILES
value|{ "/etc/krb.conf",   "/etc/kerberosIV/krb.conf", 0}
end_define

begin_define
define|#
directive|define
name|KRB_RLM_FILES
value|{ "/etc/krb.realms", "/etc/kerberosIV/krb.realms", 0}
end_define

begin_define
define|#
directive|define
name|KRB_EQUIV
value|"/etc/krb.equiv"
end_define

begin_define
define|#
directive|define
name|KEYFILE
value|"/etc/srvtab"
end_define

begin_define
define|#
directive|define
name|KRBDIR
value|"/var/kerberos"
end_define

begin_define
define|#
directive|define
name|DBM_FILE
value|KRBDIR "/principal"
end_define

begin_define
define|#
directive|define
name|DEFAULT_ACL_DIR
value|KRBDIR
end_define

begin_define
define|#
directive|define
name|KRBLOG
value|"/var/log/kerberos.log"
end_define

begin_comment
comment|/* master server  */
end_comment

begin_define
define|#
directive|define
name|KRBSLAVELOG
value|"/var/log/kerberos_slave.log"
end_define

begin_comment
comment|/* slave server  */
end_comment

begin_define
define|#
directive|define
name|KADM_SYSLOG
value|"/var/log/admin_server.syslog"
end_define

begin_define
define|#
directive|define
name|K_LOGFIL
value|"/var/log/kpropd.log"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* ftp stuff -------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|KERBEROS
end_define

begin_comment
comment|/* telnet stuff ----------------------------------------------- */
end_comment

begin_comment
comment|/* define this if you have kerberos 4 */
end_comment

begin_undef
undef|#
directive|undef
name|KRB4
end_undef

begin_comment
comment|/* define this if you want encryption */
end_comment

begin_undef
undef|#
directive|undef
name|ENCRYPTION
end_undef

begin_comment
comment|/* define this if you want authentication */
end_comment

begin_undef
undef|#
directive|undef
name|AUTHENTICATION
end_undef

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
comment|/* Set this if you want des encryption */
end_comment

begin_undef
undef|#
directive|undef
name|DES_ENCRYPTION
end_undef

begin_comment
comment|/* Set this to the default system lead string for telnetd   * can contain %-escapes: %s=sysname, %m=machine, %r=os-release  * %v=os-version, %t=tty, %h=hostname, %d=date and time  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_IM
end_undef

begin_comment
comment|/* define this if you want diagnostics in telnetd */
end_comment

begin_undef
undef|#
directive|undef
name|DIAGNOSTICS
end_undef

begin_comment
comment|/* define this if you want support for broken ENV_{VALUE,VAR} systems  */
end_comment

begin_undef
undef|#
directive|undef
name|ENV_HACK
end_undef

begin_comment
comment|/*  */
end_comment

begin_undef
undef|#
directive|undef
name|OLD_ENVIRON
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
comment|/* Define if there are working stream ptys */
end_comment

begin_undef
undef|#
directive|undef
name|STREAMSPTY
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
comment|/* ------------------------------------------------------------ */
end_comment

begin_comment
comment|/*  * Define this if your ndbm-library really is berkeley db and creates  * files that ends in .db.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_NEW_DB
end_undef

begin_comment
comment|/* Define this if you have a working getmsg */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETMSG
end_undef

begin_comment
comment|/* Define to enable new master key code */
end_comment

begin_undef
undef|#
directive|undef
name|RANDOM_MKEY
end_undef

begin_comment
comment|/* Location of the master key file, default value lives in<kdc.h> */
end_comment

begin_undef
undef|#
directive|undef
name|MKEYFILE
end_undef

begin_comment
comment|/* Define if you don't want support for afs, might be a good idea on    AIX if you don't have afs */
end_comment

begin_undef
undef|#
directive|undef
name|NO_AFS
end_undef

begin_comment
comment|/* Define if you have a readline compatible library */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_READLINE
end_undef

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

begin_comment
comment|/* Define this if your compiler supports '#pragma weak' */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PRAGMA_WEAK
end_undef

begin_comment
comment|/* Temporary fixes for krb_{rd,mk}_safe */
end_comment

begin_define
define|#
directive|define
name|DES_QUAD_GUESS
value|0
end_define

begin_define
define|#
directive|define
name|DES_QUAD_NEW
value|1
end_define

begin_define
define|#
directive|define
name|DES_QUAD_OLD
value|2
end_define

begin_comment
comment|/* Set this to one of the constants above to specify default checksum    type to emit */
end_comment

begin_undef
undef|#
directive|undef
name|DES_QUAD_DEFAULT
end_undef

begin_comment
comment|/*  * AIX braindamage!  */
end_comment

begin_if
if|#
directive|if
name|_AIX
end_if

begin_define
define|#
directive|define
name|_ALL_SOURCE
end_define

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_comment
comment|/* this is left for hysteric reasons :-) */
end_comment

begin_define
define|#
directive|define
name|unix
end_define

begin_comment
comment|/* well, ok... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SunOS braindamage! (Sun include files are generally braindead)  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|SunOS
value|5
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SunOS
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

end_unit

