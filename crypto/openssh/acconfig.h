begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: acconfig.h,v 1.145 2002/09/26 00:38:48 tim Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H
end_define

begin_comment
comment|/* Generated automatically from acconfig.h by autoheader. */
end_comment

begin_comment
comment|/* Please make your changes there */
end_comment

begin_expr_stmt
unit|@
name|TOP
expr|@
comment|/* Define to a Set Process Title type if your system is */
comment|/* supported by bsd-setproctitle.c */
undef|#
directive|undef
name|SPT_TYPE
comment|/* setgroups() NOOP allowed */
undef|#
directive|undef
name|SETGROUPS_NOOP
comment|/* SCO workaround */
undef|#
directive|undef
name|BROKEN_SYS_TERMIO_H
comment|/* Define if you have SecureWare-based protected password database */
undef|#
directive|undef
name|HAVE_SECUREWARE
comment|/* If your header files don't define LOGIN_PROGRAM, then use this (detected) */
comment|/* from environment and PATH */
undef|#
directive|undef
name|LOGIN_PROGRAM_FALLBACK
comment|/* Define if your password has a pw_class field */
undef|#
directive|undef
name|HAVE_PW_CLASS_IN_PASSWD
comment|/* Define if your password has a pw_expire field */
undef|#
directive|undef
name|HAVE_PW_EXPIRE_IN_PASSWD
comment|/* Define if your password has a pw_change field */
undef|#
directive|undef
name|HAVE_PW_CHANGE_IN_PASSWD
comment|/* Define if your system uses access rights style file descriptor passing */
undef|#
directive|undef
name|HAVE_ACCRIGHTS_IN_MSGHDR
comment|/* Define if your system uses ancillary data style file descriptor passing */
undef|#
directive|undef
name|HAVE_CONTROL_IN_MSGHDR
comment|/* Define if you system's inet_ntoa is busted (e.g. Irix gcc issue) */
undef|#
directive|undef
name|BROKEN_INET_NTOA
comment|/* Define if your system defines sys_errlist[] */
undef|#
directive|undef
name|HAVE_SYS_ERRLIST
comment|/* Define if your system defines sys_nerr */
undef|#
directive|undef
name|HAVE_SYS_NERR
comment|/* Define if your system choked on IP TOS setting */
undef|#
directive|undef
name|IP_TOS_IS_BROKEN
comment|/* Define if you have the getuserattr function.  */
undef|#
directive|undef
name|HAVE_GETUSERATTR
comment|/* Work around problematic Linux PAM modules handling of PAM_TTY */
undef|#
directive|undef
name|PAM_TTY_KLUDGE
comment|/* Use PIPES instead of a socketpair() */
undef|#
directive|undef
name|USE_PIPES
comment|/* Define if your snprintf is busted */
undef|#
directive|undef
name|BROKEN_SNPRINTF
comment|/* Define if you are on Cygwin */
undef|#
directive|undef
name|HAVE_CYGWIN
comment|/* Define if you have a broken realpath. */
undef|#
directive|undef
name|BROKEN_REALPATH
comment|/* Define if you are on NeXT */
undef|#
directive|undef
name|HAVE_NEXT
comment|/* Define if you are on NEWS-OS */
undef|#
directive|undef
name|HAVE_NEWS4
comment|/* Define if you want to enable PAM support */
undef|#
directive|undef
name|USE_PAM
comment|/* Define if you want to enable AIX4's authenticate function */
undef|#
directive|undef
name|WITH_AIXAUTHENTICATE
comment|/* Define if you have/want arrays (cluster-wide session managment, not C arrays) */
undef|#
directive|undef
name|WITH_IRIX_ARRAY
comment|/* Define if you want IRIX project management */
undef|#
directive|undef
name|WITH_IRIX_PROJECT
comment|/* Define if you want IRIX audit trails */
undef|#
directive|undef
name|WITH_IRIX_AUDIT
comment|/* Define if you want IRIX kernel jobs */
undef|#
directive|undef
name|WITH_IRIX_JOBS
comment|/* Location of PRNGD/EGD random number socket */
undef|#
directive|undef
name|PRNGD_SOCKET
comment|/* Port number of PRNGD/EGD random number socket */
undef|#
directive|undef
name|PRNGD_PORT
comment|/* Builtin PRNG command timeout */
undef|#
directive|undef
name|ENTROPY_TIMEOUT_MSEC
comment|/* non-privileged user for privilege separation */
undef|#
directive|undef
name|SSH_PRIVSEP_USER
comment|/* Define if you want to install preformatted manpages.*/
undef|#
directive|undef
name|MANTYPE
comment|/* Define if your ssl headers are included with #include<openssl/header.h>  */
undef|#
directive|undef
name|HAVE_OPENSSL
comment|/* Define if you are linking against RSAref.  Used only to print the right  * message at run-time. */
undef|#
directive|undef
name|RSAREF
comment|/* struct timeval */
undef|#
directive|undef
name|HAVE_STRUCT_TIMEVAL
comment|/* struct utmp and struct utmpx fields */
undef|#
directive|undef
name|HAVE_HOST_IN_UTMP
undef|#
directive|undef
name|HAVE_HOST_IN_UTMPX
undef|#
directive|undef
name|HAVE_ADDR_IN_UTMP
undef|#
directive|undef
name|HAVE_ADDR_IN_UTMPX
undef|#
directive|undef
name|HAVE_ADDR_V6_IN_UTMP
undef|#
directive|undef
name|HAVE_ADDR_V6_IN_UTMPX
undef|#
directive|undef
name|HAVE_SYSLEN_IN_UTMPX
undef|#
directive|undef
name|HAVE_PID_IN_UTMP
undef|#
directive|undef
name|HAVE_TYPE_IN_UTMP
undef|#
directive|undef
name|HAVE_TYPE_IN_UTMPX
undef|#
directive|undef
name|HAVE_TV_IN_UTMP
undef|#
directive|undef
name|HAVE_TV_IN_UTMPX
undef|#
directive|undef
name|HAVE_ID_IN_UTMP
undef|#
directive|undef
name|HAVE_ID_IN_UTMPX
undef|#
directive|undef
name|HAVE_EXIT_IN_UTMP
undef|#
directive|undef
name|HAVE_TIME_IN_UTMP
undef|#
directive|undef
name|HAVE_TIME_IN_UTMPX
comment|/* Define if you don't want to use your system's login() call */
undef|#
directive|undef
name|DISABLE_LOGIN
comment|/* Define if you don't want to use pututline() etc. to write [uw]tmp */
undef|#
directive|undef
name|DISABLE_PUTUTLINE
comment|/* Define if you don't want to use pututxline() etc. to write [uw]tmpx */
undef|#
directive|undef
name|DISABLE_PUTUTXLINE
comment|/* Define if you don't want to use lastlog */
undef|#
directive|undef
name|DISABLE_LASTLOG
comment|/* Define if you don't want to use lastlog in session.c */
undef|#
directive|undef
name|NO_SSH_LASTLOG
comment|/* Define if you don't want to use utmp */
undef|#
directive|undef
name|DISABLE_UTMP
comment|/* Define if you don't want to use utmpx */
undef|#
directive|undef
name|DISABLE_UTMPX
comment|/* Define if you don't want to use wtmp */
undef|#
directive|undef
name|DISABLE_WTMP
comment|/* Define if you don't want to use wtmpx */
undef|#
directive|undef
name|DISABLE_WTMPX
comment|/* Some systems need a utmpx entry for /bin/login to work */
undef|#
directive|undef
name|LOGIN_NEEDS_UTMPX
comment|/* Some versions of /bin/login need the TERM supplied on the commandline */
undef|#
directive|undef
name|LOGIN_NEEDS_TERM
comment|/* Define if your login program cannot handle end of options ("--") */
undef|#
directive|undef
name|LOGIN_NO_ENDOPT
comment|/* Define if you want to specify the path to your lastlog file */
undef|#
directive|undef
name|CONF_LASTLOG_FILE
comment|/* Define if you want to specify the path to your utmp file */
undef|#
directive|undef
name|CONF_UTMP_FILE
comment|/* Define if you want to specify the path to your wtmp file */
undef|#
directive|undef
name|CONF_WTMP_FILE
comment|/* Define if you want to specify the path to your utmpx file */
undef|#
directive|undef
name|CONF_UTMPX_FILE
comment|/* Define if you want to specify the path to your wtmpx file */
undef|#
directive|undef
name|CONF_WTMPX_FILE
comment|/* Define if you want external askpass support */
undef|#
directive|undef
name|USE_EXTERNAL_ASKPASS
comment|/* Define if libc defines __progname */
undef|#
directive|undef
name|HAVE___PROGNAME
comment|/* Define if compiler implements __FUNCTION__ */
undef|#
directive|undef
name|HAVE___FUNCTION__
comment|/* Define if compiler implements __func__ */
undef|#
directive|undef
name|HAVE___func__
comment|/* Define if you want Kerberos 5 support */
undef|#
directive|undef
name|KRB5
comment|/* Define this if you are using the Heimdal version of Kerberos V5 */
undef|#
directive|undef
name|HEIMDAL
comment|/* Define if you want Kerberos 4 support */
undef|#
directive|undef
name|KRB4
comment|/* Define if you want AFS support */
undef|#
directive|undef
name|AFS
comment|/* Define if you want S/Key support */
undef|#
directive|undef
name|SKEY
comment|/* Define if you want OPIE support */
undef|#
directive|undef
name|OPIE
comment|/* Define if you want TCP Wrappers support */
undef|#
directive|undef
name|LIBWRAP
comment|/* Define if your libraries define login() */
undef|#
directive|undef
name|HAVE_LOGIN
comment|/* Define if your libraries define daemon() */
undef|#
directive|undef
name|HAVE_DAEMON
comment|/* Define if your libraries define getpagesize() */
undef|#
directive|undef
name|HAVE_GETPAGESIZE
comment|/* Define if xauth is found in your path */
undef|#
directive|undef
name|XAUTH_PATH
comment|/* Define if you want to allow MD5 passwords */
undef|#
directive|undef
name|HAVE_MD5_PASSWORDS
comment|/* Define if you want to disable shadow passwords */
undef|#
directive|undef
name|DISABLE_SHADOW
comment|/* Define if you want to use shadow password expire field */
undef|#
directive|undef
name|HAS_SHADOW_EXPIRE
comment|/* Define if you have Digital Unix Security Integration Architecture */
undef|#
directive|undef
name|HAVE_OSF_SIA
comment|/* Define if you have getpwanam(3) [SunOS 4.x] */
undef|#
directive|undef
name|HAVE_GETPWANAM
comment|/* Define if you have an old version of PAM which takes only one argument */
comment|/* to pam_strerror */
undef|#
directive|undef
name|HAVE_OLD_PAM
comment|/* Define if you are using Solaris-derived PAM which passes pam_messages  */
comment|/* to the conversation function with an extra level of indirection */
undef|#
directive|undef
name|PAM_SUN_CODEBASE
comment|/* Set this to your mail directory if you don't have maillock.h */
undef|#
directive|undef
name|MAIL_DIRECTORY
comment|/* Data types */
undef|#
directive|undef
name|HAVE_U_INT
undef|#
directive|undef
name|HAVE_INTXX_T
undef|#
directive|undef
name|HAVE_U_INTXX_T
undef|#
directive|undef
name|HAVE_UINTXX_T
undef|#
directive|undef
name|HAVE_INT64_T
undef|#
directive|undef
name|HAVE_U_INT64_T
undef|#
directive|undef
name|HAVE_U_CHAR
undef|#
directive|undef
name|HAVE_SIZE_T
undef|#
directive|undef
name|HAVE_SSIZE_T
undef|#
directive|undef
name|HAVE_CLOCK_T
undef|#
directive|undef
name|HAVE_MODE_T
undef|#
directive|undef
name|HAVE_PID_T
undef|#
directive|undef
name|HAVE_SA_FAMILY_T
undef|#
directive|undef
name|HAVE_STRUCT_SOCKADDR_STORAGE
undef|#
directive|undef
name|HAVE_STRUCT_ADDRINFO
undef|#
directive|undef
name|HAVE_STRUCT_IN6_ADDR
undef|#
directive|undef
name|HAVE_STRUCT_SOCKADDR_IN6
comment|/* Fields in struct sockaddr_storage */
undef|#
directive|undef
name|HAVE_SS_FAMILY_IN_SS
undef|#
directive|undef
name|HAVE___SS_FAMILY_IN_SS
comment|/* Define if you have /dev/ptmx */
undef|#
directive|undef
name|HAVE_DEV_PTMX
comment|/* Define if you have /dev/ptc */
undef|#
directive|undef
name|HAVE_DEV_PTS_AND_PTC
comment|/* Define if you need to use IP address instead of hostname in $DISPLAY */
undef|#
directive|undef
name|IPADDR_IN_DISPLAY
comment|/* Specify default $PATH */
undef|#
directive|undef
name|USER_PATH
comment|/* Specify location of ssh.pid */
undef|#
directive|undef
name|_PATH_SSH_PIDDIR
comment|/* Use IPv4 for connection by default, IPv6 can still if explicity asked */
undef|#
directive|undef
name|IPV4_DEFAULT
comment|/* getaddrinfo is broken (if present) */
undef|#
directive|undef
name|BROKEN_GETADDRINFO
comment|/* Workaround more Linux IPv6 quirks */
undef|#
directive|undef
name|DONT_TRY_OTHER_AF
comment|/* Detect IPv4 in IPv6 mapped addresses and treat as IPv4 */
undef|#
directive|undef
name|IPV4_IN_IPV6
comment|/* Define if you have BSD auth support */
undef|#
directive|undef
name|BSD_AUTH
comment|/* Define if X11 doesn't support AF_UNIX sockets on that system */
undef|#
directive|undef
name|NO_X11_UNIX_SOCKETS
comment|/* Define if the concept of ports only accessible to superusers isn't known */
undef|#
directive|undef
name|NO_IPPORT_RESERVED_CONCEPT
comment|/* Needed for SCO and NeXT */
undef|#
directive|undef
name|BROKEN_SAVED_UIDS
comment|/* Define if your system glob() function has the GLOB_ALTDIRFUNC extension */
undef|#
directive|undef
name|GLOB_HAS_ALTDIRFUNC
comment|/* Define if your system glob() function has gl_matchc options in glob_t */
undef|#
directive|undef
name|GLOB_HAS_GL_MATCHC
comment|/* Define in your struct dirent expects you to allocate extra space for d_name */
undef|#
directive|undef
name|BROKEN_ONE_BYTE_DIRENT_D_NAME
comment|/* Define if your getopt(3) defines and uses optreset */
undef|#
directive|undef
name|HAVE_GETOPT_OPTRESET
comment|/* Define on *nto-qnx systems */
undef|#
directive|undef
name|MISSING_NFDBITS
comment|/* Define on *nto-qnx systems */
undef|#
directive|undef
name|MISSING_HOWMANY
comment|/* Define on *nto-qnx systems */
undef|#
directive|undef
name|MISSING_FD_MASK
comment|/* Define if you want smartcard support */
undef|#
directive|undef
name|SMARTCARD
comment|/* Define if you want smartcard support using sectok */
undef|#
directive|undef
name|USE_SECTOK
comment|/* Define if you want smartcard support using OpenSC */
undef|#
directive|undef
name|USE_OPENSC
comment|/* Define if you want to use OpenSSL's internally seeded PRNG only */
undef|#
directive|undef
name|OPENSSL_PRNG_ONLY
comment|/* Define if you shouldn't strip 'tty' from your ttyname in [uw]tmp */
undef|#
directive|undef
name|WITH_ABBREV_NO_TTY
comment|/* Define if you want a different $PATH for the superuser */
undef|#
directive|undef
name|SUPERUSER_PATH
comment|/* Path that unprivileged child will chroot() to in privep mode */
undef|#
directive|undef
name|PRIVSEP_PATH
comment|/* Define if your platform needs to skip post auth file descriptor passing */
undef|#
directive|undef
name|DISABLE_FD_PASSING
expr|@
name|BOTTOM
expr|@
end_expr_stmt

begin_comment
comment|/* ******************* Shouldn't need to edit below this line ************** */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONFIG_H */
end_comment

end_unit

