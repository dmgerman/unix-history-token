begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* include/config.h.in.  Generated from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|RCSID
end_ifndef

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
value|const char *const rcsid[] = { (const char *)rcsid, "@(#)" msg }
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

begin_ifdef
ifdef|#
directive|ifdef
name|BUILD_KRB5_LIB
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_LIB_FUNCTION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_
end_ifdef

begin_define
define|#
directive|define
name|KRB5_LIB_FUNCTION
value|_export _stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_LIB_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BUILD_ROKEN_LIB
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ROKEN_LIB_FUNCTION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_
end_ifdef

begin_define
define|#
directive|define
name|ROKEN_LIB_FUNCTION
value|_export _stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ROKEN_LIB_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you want authentication support in telnet. */
end_comment

begin_define
define|#
directive|define
name|AUTHENTICATION
value|1
end_define

begin_comment
comment|/* path to bin */
end_comment

begin_define
define|#
directive|define
name|BINDIR
value|"/usr/bin"
end_define

begin_comment
comment|/* Define if realloc(NULL) doesn't work. */
end_comment

begin_comment
comment|/* #undef BROKEN_REALLOC */
end_comment

begin_comment
comment|/* Define if you want support for DCE/DFS PAG's. */
end_comment

begin_comment
comment|/* #undef DCE */
end_comment

begin_comment
comment|/* Define if you want to use DES encryption in telnet. */
end_comment

begin_define
define|#
directive|define
name|DES_ENCRYPTION
value|1
end_define

begin_comment
comment|/* Define this to enable diagnostics in telnet. */
end_comment

begin_define
define|#
directive|define
name|DIAGNOSTICS
value|1
end_define

begin_comment
comment|/* Define if want to use the weak AFS string to key functions. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_AFS_STRING_TO_KEY
value|1
end_define

begin_comment
comment|/* Define if you want have a thread safe libraries */
end_comment

begin_comment
comment|/* #undef ENABLE_PTHREAD_SUPPORT */
end_comment

begin_comment
comment|/* Define if you want encryption support in telnet. */
end_comment

begin_define
define|#
directive|define
name|ENCRYPTION
value|1
end_define

begin_comment
comment|/* define if sys/param.h defines the endiness */
end_comment

begin_define
define|#
directive|define
name|ENDIANESS_IN_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define this if you want support for broken ENV_{VAR,VAL} telnets. */
end_comment

begin_comment
comment|/* #undef ENV_HACK */
end_comment

begin_comment
comment|/* define if prototype of gethostbyaddr is compatible with struct hostent    *gethostbyaddr(const void *, size_t, int) */
end_comment

begin_define
define|#
directive|define
name|GETHOSTBYADDR_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* define if prototype of gethostbyname is compatible with struct hostent    *gethostbyname(const char *) */
end_comment

begin_define
define|#
directive|define
name|GETHOSTBYNAME_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* define if prototype of getservbyname is compatible with struct servent    *getservbyname(const char *, const char *) */
end_comment

begin_define
define|#
directive|define
name|GETSERVBYNAME_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* define if prototype of getsockname is compatible with int getsockname(int,    struct sockaddr*, socklen_t*) */
end_comment

begin_define
define|#
directive|define
name|GETSOCKNAME_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* Define if you have the `altzone' variable. */
end_comment

begin_comment
comment|/* #undef HAVE_ALTZONE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `arc4random' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/ftp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_FTP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/inet.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/nameser.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/telnet.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_TELNET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `asnprintf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ASNPRINTF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `asprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `atexit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<bind/bitypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BIND_BITYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<bsdsetjmp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BSDSETJMP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bswap16' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP16 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bswap32' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BSWAP32 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<capability.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `cap_set_proc' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CAP_SET_PROC */
end_comment

begin_comment
comment|/* Define to 1 if you have the `cgetent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CGETENT
value|1
end_define

begin_comment
comment|/* Define if you have the function `chown'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHOWN
value|1
end_define

begin_comment
comment|/* Define if you have the function `closefrom'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOSEFROM
end_define

begin_comment
comment|/* Define to 1 if you have the<config.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CONFIG_H */
end_comment

begin_comment
comment|/* Define if you have the function `copyhostent'. */
end_comment

begin_comment
comment|/* #undef HAVE_COPYHOSTENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `crypt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRYPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<crypt.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<curses.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `daemon'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* define if you have a berkeley db1/2 library */
end_comment

begin_define
define|#
directive|define
name|HAVE_DB1
value|1
end_define

begin_comment
comment|/* define if you have a berkeley db3/4 library */
end_comment

begin_comment
comment|/* #undef HAVE_DB3 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<db3/db.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DB3_DB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<db4/db.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DB4_DB_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `dbm_firstkey' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DBM_FIRSTKEY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dbm.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DBM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `dbopen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DBOPEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<db_185.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DB_185_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `db_create' function. */
end_comment

begin_comment
comment|/* #undef HAVE_DB_CREATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<db.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DB_H
value|1
end_define

begin_comment
comment|/* define if you have ndbm compat in db */
end_comment

begin_comment
comment|/* #undef HAVE_DB_NDBM */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `altzone', and to 0 if you    don't. */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_ALTZONE */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `environ', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ENVIRON
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `h_errlist', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_H_ERRLIST
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `h_errno', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_H_ERRNO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `h_nerr', and to 0 if you don't.    */
end_comment

begin_comment
comment|/* #undef HAVE_DECL_H_NERR */
end_comment

begin_comment
comment|/* Define to 1 if you have the declaration of `optarg', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OPTARG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `opterr', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OPTERR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `optind', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OPTIND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `optopt', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_OPTOPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `timezone', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_TIMEZONE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `_res', and to 0 if you don't.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL__RES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `__progname', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL___PROGNAME
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dlopen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLOPEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dn_expand' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DN_EXPAND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `door_create' function. */
end_comment

begin_comment
comment|/* #undef HAVE_DOOR_CREATE */
end_comment

begin_comment
comment|/* Define if you have the function `ecalloc'. */
end_comment

begin_comment
comment|/* #undef HAVE_ECALLOC */
end_comment

begin_comment
comment|/* Define to 1 if you have the `el_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EL_INIT
value|1
end_define

begin_comment
comment|/* Define if you have the function `emalloc'. */
end_comment

begin_comment
comment|/* #undef HAVE_EMALLOC */
end_comment

begin_comment
comment|/* Define if you have the function `erealloc'. */
end_comment

begin_comment
comment|/* #undef HAVE_EREALLOC */
end_comment

begin_comment
comment|/* Define if you have the function `err'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `errx'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<err.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `estrdup'. */
end_comment

begin_comment
comment|/* #undef HAVE_ESTRDUP */
end_comment

begin_comment
comment|/* Define if you have the function `fchown'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fcntl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `flock'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the function `fnmatch'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fnmatch.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH_H
value|1
end_define

begin_comment
comment|/* Define if el_init takes four arguments. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FOUR_VALUED_EL_INIT
value|1
end_define

begin_comment
comment|/* Have -framework Security */
end_comment

begin_comment
comment|/* #undef HAVE_FRAMEWORK_SECURITY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `freeaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FREEADDRINFO
value|1
end_define

begin_comment
comment|/* Define if you have the function `freehostent'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FREEHOSTENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gai_strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAI_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<gdbm/ndbm.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GDBM_NDBM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getconfattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETCONFATTR */
end_comment

begin_comment
comment|/* Define if you have the function `getcwd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the function `getdtablesize'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the function `getegid'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the function `geteuid'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the function `getgid'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyname2' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME2
value|1
end_define

begin_comment
comment|/* Define if you have the function `gethostname'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define if you have the function `getifaddrs'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIFADDRS
value|1
end_define

begin_comment
comment|/* Define if you have the function `getipnodebyaddr'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYADDR
value|1
end_define

begin_comment
comment|/* Define if you have the function `getipnodebyname'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getlogin' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETLOGIN
value|1
end_define

begin_comment
comment|/* Define if you have a working getmsg. */
end_comment

begin_comment
comment|/* #undef HAVE_GETMSG */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getnameinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define if you have the function `getopt'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpagesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpeereid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPEEREID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpeerucred' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPEERUCRED */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getprogname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPROGNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpwnam_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPWNAM_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getsockopt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETSOCKOPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getspnam' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETSPNAM */
end_comment

begin_comment
comment|/* Define if you have the function `gettimeofday'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getudbnam' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETUDBNAM */
end_comment

begin_comment
comment|/* Define if you have the function `getuid'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the function `getusershell'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUSERSHELL
value|1
end_define

begin_comment
comment|/* define if you have a glob() that groks GLOB_BRACE, GLOB_NOCHECK,    GLOB_QUOTE, GLOB_TILDE, and GLOB_LIMIT */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `grantpt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GRANTPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<grp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `hstrerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_HSTRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the `h_errlist' variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRLIST
value|1
end_define

begin_comment
comment|/* Define if you have the `h_errno' variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRNO
value|1
end_define

begin_comment
comment|/* Define if you have the `h_nerr' variable. */
end_comment

begin_comment
comment|/* #undef HAVE_H_NERR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ifaddrs.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IFADDRS_H
value|1
end_define

begin_comment
comment|/* Define if you have the in6addr_loopback variable */
end_comment

begin_define
define|#
directive|define
name|HAVE_IN6ADDR_LOOPBACK
value|1
end_define

begin_comment
comment|/* define */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_comment
comment|/* define */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* define */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_comment
comment|/* Define if you have the function `initgroups'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INITGROUPS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `initstate' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INITSTATE
value|1
end_define

begin_comment
comment|/* Define if you have the function `innetgr'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INNETGR
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int16_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT16_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int8_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT8_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<io.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IO_H */
end_comment

begin_comment
comment|/* Define if you have IPv6. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IPV6
value|1
end_define

begin_comment
comment|/* Define if you have the function `iruserok'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IRUSEROK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `issetugid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISSETUGID
value|1
end_define

begin_comment
comment|/* Define if you want to use the Kerberos Credentials Manager. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KCM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<libutil.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBUTIL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `loadquery' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOADQUERY */
end_comment

begin_comment
comment|/* Define if you have the function `localtime_r'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALTIME_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `logout' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGOUT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `logwtmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGWTMP
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `long long'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if you have the function `lstat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<maillock.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MAILLOCK_H */
end_comment

begin_comment
comment|/* Define if you have the function `memmove'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `mkstemp'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mktime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have a working `mmap' system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* define if you have a ndbm library */
end_comment

begin_define
define|#
directive|define
name|HAVE_NDBM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ndbm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netgroup.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETGROUP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet6/in6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET6_IN6_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet6/in6_var.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET6_IN6_VAR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/in6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN6_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/in6_machtypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN6_MACHTYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/in.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in_systm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/ip.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/tcp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_TCP_H
value|1
end_define

begin_comment
comment|/* Define if you want to use Netinfo instead of krb5.conf. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinfo/ni.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO_NI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<net/if.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_comment
comment|/* Define if NDBM really is DB (creates files *.db) */
end_comment

begin_define
define|#
directive|define
name|HAVE_NEW_DB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `on_exit' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ON_EXIT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `openpty' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENPTY
value|1
end_define

begin_comment
comment|/* define to use openssl's libcrypto */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL
value|1
end_define

begin_comment
comment|/* Define to enable basic OSF C2 support. */
end_comment

begin_comment
comment|/* #undef HAVE_OSFC2 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<paths.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pidfile' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PIDFILE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `poll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `ptsname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTSNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PTY_H */
end_comment

begin_comment
comment|/* Define if you have the function `putenv'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pwd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `rand' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `random' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the function `rcmd'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RCMD
value|1
end_define

begin_comment
comment|/* Define if you have a readline compatible library. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINE
value|1
end_define

begin_comment
comment|/* Define if you have the function `readv'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READV
value|1
end_define

begin_comment
comment|/* Define if you have the function `recvmsg'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<resolv.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `res_ndestroy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_NDESTROY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `res_nsearch' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_NSEARCH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `res_search' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_SEARCH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `revoke' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REVOKE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<rpcsvc/ypclnt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_YPCLNT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sac.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SAC_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `sa_family_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<security/pam_modules.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SECURITY_PAM_MODULES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `select' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define if you have the function `sendmsg'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SENDMSG
value|1
end_define

begin_comment
comment|/* Define if you have the function `setegid'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the function `setenv'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the function `seteuid'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setitimer' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETITIMER
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlim' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETLIM */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setlogin' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOGIN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setpcred' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETPCRED */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setpgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setproctitle' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROCTITLE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setprogname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROGNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setregid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setresgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRESGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setresuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRESUID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setreuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setsid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setsockopt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSOCKOPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setstate' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSTATE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setutent' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETUTENT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sgi_getcapabilitybyname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SGI_GETCAPABILITYBYNAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sgtty.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SGTTY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<shadow.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHADOW_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<siad.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SIAD_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sigaction' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* define if you have a working snprintf */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `socket' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `socklen_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `ssize_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SSIZE_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<standards.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STANDARDS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `strcasecmp'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the function `strdup'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the function `strerror'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the function `strftime'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRFTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the function `strlcat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define if you have the function `strlcpy'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define if you have the function `strlwr'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRLWR */
end_comment

begin_comment
comment|/* Define if you have the function `strncasecmp'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the function `strndup'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNDUP
value|1
end_define

begin_comment
comment|/* Define if you have the function `strnlen'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRNLEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the function `strptime'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_comment
comment|/* Define if you have the function `strsep'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* Define if you have the function `strsep_copy'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRSEP_COPY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strstr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strsvis' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRSVIS */
end_comment

begin_comment
comment|/* Define if you have the function `strtok_r'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOK_R
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct addrinfo'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_ADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct ifaddrs'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_IFADDRS
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct iovec'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_IOVEC
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct msghdr'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_MSGHDR
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct sockaddr'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR
value|1
end_define

begin_comment
comment|/* Define if struct sockaddr has field sa_len. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `struct sockaddr_storage'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_STORAGE
value|1
end_define

begin_comment
comment|/* define if you have struct spwd */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_SPWD */
end_comment

begin_comment
comment|/* Define if struct tm has field tm_gmtoff. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_GMTOFF
value|1
end_define

begin_comment
comment|/* Define if struct tm has field tm_zone. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_ZONE
value|1
end_define

begin_comment
comment|/* Define if struct utmpx has field ut_exit. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMPX_UT_EXIT */
end_comment

begin_comment
comment|/* Define if struct utmpx has field ut_syslen. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMPX_UT_SYSLEN */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_addr. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_ADDR */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_host. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_HOST */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_id. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_ID */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_pid. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_PID */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_type. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_TYPE */
end_comment

begin_comment
comment|/* Define if struct utmp has field ut_user. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_UTMP_UT_USER */
end_comment

begin_comment
comment|/* define if struct winsize is declared in sys/termios.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_WINSIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strunvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUNVIS
value|1
end_define

begin_comment
comment|/* Define if you have the function `strupr'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUPR */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strvisx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVISX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `svis' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SVIS */
end_comment

begin_comment
comment|/* Define if you have the function `swab'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SWAB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sysconf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sysctl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCTL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `syslog' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<syslog.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/bitypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BITYPES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/bswap.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BSWAP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/capability.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/category.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CATEGORY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/file.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/filio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ioccom.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCCOM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mman.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/proc.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ptyio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTYIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ptyvar.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTYVAR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/pty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/resource.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/select.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/socket.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sockio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stream.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STROPTS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/strtty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STRTTY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/str_tty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STR_TTY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/syscall.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCALL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sysctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TERMIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/timeb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/times.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/tty.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TTY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ucred.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UCRED_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/uio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/un.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/utsname.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termcap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<term.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `tgetent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TGETENT
value|1
end_define

begin_comment
comment|/* Define if you have the function `timegm'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEGM
value|1
end_define

begin_comment
comment|/* Define if you have the `timezone' variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEZONE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<tmpdir.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TMPDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ttyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `ttyslot' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYSLOT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<udb.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UDB_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `uint16_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT16_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint8_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT8_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uintptr_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINTPTR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `umask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UMASK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `uname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `unlockpt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNLOCKPT
value|1
end_define

begin_comment
comment|/* Define if you have the function `unsetenv'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `unvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<userconf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_USERCONF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<usersec.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_USERSEC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<util.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTIL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<utmpx.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPX_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<utmp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int16_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT16_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int8_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT8_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vasnprintf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_VASNPRINTF */
end_comment

begin_comment
comment|/* Define to 1 if you have the `vasprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the function `verr'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VERR
value|1
end_define

begin_comment
comment|/* Define if you have the function `verrx'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VERRX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vhangup' function. */
end_comment

begin_comment
comment|/* #undef HAVE_VHANGUP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `vis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vis.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS_H
value|1
end_define

begin_comment
comment|/* define if you have a working vsnprintf */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the function `vsyslog'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSYSLOG
value|1
end_define

begin_comment
comment|/* Define if you have the function `vwarn'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VWARN
value|1
end_define

begin_comment
comment|/* Define if you have the function `vwarnx'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VWARNX
value|1
end_define

begin_comment
comment|/* Define if you have the function `warn'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARN
value|1
end_define

begin_comment
comment|/* Define if you have the function `warnx'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARNX
value|1
end_define

begin_comment
comment|/* Define if you have the function `writev'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WRITEV
value|1
end_define

begin_comment
comment|/* define if struct winsize has ws_xpixel */
end_comment

begin_define
define|#
directive|define
name|HAVE_WS_XPIXEL
value|1
end_define

begin_comment
comment|/* define if struct winsize has ws_ypixel */
end_comment

begin_define
define|#
directive|define
name|HAVE_WS_YPIXEL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `XauFileName' function. */
end_comment

begin_comment
comment|/* #undef HAVE_XAUFILENAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `XauReadAuth' function. */
end_comment

begin_comment
comment|/* #undef HAVE_XAUREADAUTH */
end_comment

begin_comment
comment|/* Define to 1 if you have the `XauWriteAuth' function. */
end_comment

begin_comment
comment|/* #undef HAVE_XAUWRITEAUTH */
end_comment

begin_comment
comment|/* Define to 1 if you have the `yp_get_default_domain' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_YP_GET_DEFAULT_DOMAIN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_getpty' function. */
end_comment

begin_comment
comment|/* #undef HAVE__GETPTY */
end_comment

begin_comment
comment|/* Define if you have the `_res' variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE__RES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_scrsize' function. */
end_comment

begin_comment
comment|/* #undef HAVE__SCRSIZE */
end_comment

begin_comment
comment|/* define if your compiler has __attribute__ */
end_comment

begin_define
define|#
directive|define
name|HAVE___ATTRIBUTE__
value|1
end_define

begin_comment
comment|/* Define if you have the `__progname' variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE___PROGNAME
value|1
end_define

begin_comment
comment|/* Define if you have the hesiod package. */
end_comment

begin_comment
comment|/* #undef HESIOD */
end_comment

begin_comment
comment|/* Define if you are running IRIX 4. */
end_comment

begin_comment
comment|/* #undef IRIX4 */
end_comment

begin_comment
comment|/* Enable Kerberos 5 support in applications. */
end_comment

begin_define
define|#
directive|define
name|KRB5
value|1
end_define

begin_comment
comment|/* path to lib */
end_comment

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/lib"
end_define

begin_comment
comment|/* path to libexec */
end_comment

begin_define
define|#
directive|define
name|LIBEXECDIR
value|"/usr/libexec"
end_define

begin_comment
comment|/* path to localstate */
end_comment

begin_define
define|#
directive|define
name|LOCALSTATEDIR
value|"/var/heimdal"
end_define

begin_comment
comment|/* define if the system is missing a prototype for asnprintf() */
end_comment

begin_define
define|#
directive|define
name|NEED_ASNPRINTF_PROTO
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for asprintf() */
end_comment

begin_comment
comment|/* #undef NEED_ASPRINTF_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for crypt() */
end_comment

begin_comment
comment|/* #undef NEED_CRYPT_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for daemon() */
end_comment

begin_define
define|#
directive|define
name|NEED_DAEMON_PROTO
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for gethostname() */
end_comment

begin_comment
comment|/* #undef NEED_GETHOSTNAME_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for getusershell() */
end_comment

begin_comment
comment|/* #undef NEED_GETUSERSHELL_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for glob() */
end_comment

begin_comment
comment|/* #undef NEED_GLOB_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for hstrerror() */
end_comment

begin_comment
comment|/* #undef NEED_HSTRERROR_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for inet_aton() */
end_comment

begin_comment
comment|/* #undef NEED_INET_ATON_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for iruserok() */
end_comment

begin_comment
comment|/* #undef NEED_IRUSEROK_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for mkstemp() */
end_comment

begin_comment
comment|/* #undef NEED_MKSTEMP_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for SecKeyGetCSPHandle() */
end_comment

begin_comment
comment|/* #undef NEED_SECKEYGETCSPHANDLE_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for setenv() */
end_comment

begin_comment
comment|/* #undef NEED_SETENV_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for snprintf() */
end_comment

begin_comment
comment|/* #undef NEED_SNPRINTF_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strndup() */
end_comment

begin_define
define|#
directive|define
name|NEED_STRNDUP_PROTO
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for strsep() */
end_comment

begin_comment
comment|/* #undef NEED_STRSEP_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strsvis() */
end_comment

begin_define
define|#
directive|define
name|NEED_STRSVIS_PROTO
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for strtok_r() */
end_comment

begin_comment
comment|/* #undef NEED_STRTOK_R_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strunvis() */
end_comment

begin_comment
comment|/* #undef NEED_STRUNVIS_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strvisx() */
end_comment

begin_comment
comment|/* #undef NEED_STRVISX_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strvis() */
end_comment

begin_comment
comment|/* #undef NEED_STRVIS_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for svis() */
end_comment

begin_define
define|#
directive|define
name|NEED_SVIS_PROTO
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for unsetenv() */
end_comment

begin_comment
comment|/* #undef NEED_UNSETENV_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for unvis() */
end_comment

begin_comment
comment|/* #undef NEED_UNVIS_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for vasnprintf() */
end_comment

begin_define
define|#
directive|define
name|NEED_VASNPRINTF_PROTO
value|1
end_define

begin_comment
comment|/* define if the system is missing a prototype for vasprintf() */
end_comment

begin_comment
comment|/* #undef NEED_VASPRINTF_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for vis() */
end_comment

begin_comment
comment|/* #undef NEED_VIS_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for vsnprintf() */
end_comment

begin_comment
comment|/* #undef NEED_VSNPRINTF_PROTO */
end_comment

begin_comment
comment|/* Define if you don't wan't support for AFS. */
end_comment

begin_comment
comment|/* #undef NO_AFS */
end_comment

begin_comment
comment|/* Define to 1 if your C compiler doesn't accept -c and -o together. */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Define if you don't want to use mmap. */
end_comment

begin_comment
comment|/* #undef NO_MMAP */
end_comment

begin_comment
comment|/* Define this to enable old environment option in telnet. */
end_comment

begin_define
define|#
directive|define
name|OLD_ENVIRON
value|1
end_define

begin_comment
comment|/* Define if you have the openldap package. */
end_comment

begin_comment
comment|/* #undef OPENLDAP */
end_comment

begin_comment
comment|/* Define if you want support for hdb ldap module */
end_comment

begin_comment
comment|/* #undef OPENLDAP_MODULE */
end_comment

begin_comment
comment|/* define if prototype of openlog is compatible with void openlog(const char    *, int, int) */
end_comment

begin_define
define|#
directive|define
name|OPENLOG_PROTO_COMPATIBLE
value|1
end_define

begin_comment
comment|/* Define if you want OTP support in applications. */
end_comment

begin_define
define|#
directive|define
name|OTP
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"heimdal"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"heimdal-bugs@h5l.org"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"Heimdal"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"Heimdal 1.1"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"heimdal"
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"1.1"
end_define

begin_comment
comment|/* Define to enable PKINIT. */
end_comment

begin_define
define|#
directive|define
name|PKINIT
value|1
end_define

begin_comment
comment|/* Define if getlogin has POSIX flavour (and not BSD). */
end_comment

begin_comment
comment|/* #undef POSIX_GETLOGIN */
end_comment

begin_comment
comment|/* Define if getpwnam_r has POSIX flavour. */
end_comment

begin_comment
comment|/* #undef POSIX_GETPWNAM_R */
end_comment

begin_comment
comment|/* Define if you have the readline package. */
end_comment

begin_comment
comment|/* #undef READLINE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* path to sbin */
end_comment

begin_define
define|#
directive|define
name|SBINDIR
value|"/usr/sbin"
end_define

begin_comment
comment|/* Define if you want to use samba socket wrappers. */
end_comment

begin_comment
comment|/* #undef SOCKET_WRAPPER_REPLACE */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you have streams ptys. */
end_comment

begin_comment
comment|/* #undef STREAMSPTY */
end_comment

begin_comment
comment|/* path to sysconf */
end_comment

begin_define
define|#
directive|define
name|SYSCONFDIR
value|"/etc"
end_define

begin_comment
comment|/* Define to what version of SunOS you are running. */
end_comment

begin_comment
comment|/* #undef SunOS */
end_comment

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"1.1"
end_define

begin_comment
comment|/* Define if signal handlers return void. */
end_comment

begin_define
define|#
directive|define
name|VOID_RETSIGTYPE
value|1
end_define

begin_comment
comment|/* define if target is big endian */
end_comment

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/* Define to 1 if the X Window System is missing or not being used. */
end_comment

begin_define
define|#
directive|define
name|X_DISPLAY_MISSING
value|1
end_define

begin_comment
comment|/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a    `char[]'. */
end_comment

begin_define
define|#
directive|define
name|YYTEXT_POINTER
value|1
end_define

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define to enable extensions on glibc-based systems such as Linux. */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this to what the type mode_t should be. */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define this to what the type sig_atomic_t should be. */
end_comment

begin_comment
comment|/* #undef sig_atomic_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

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
value|rk_realloc((X), (Y))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* XXX this is gross, but kills about a gazillion warnings */
end_comment

begin_struct_decl
struct_decl|struct
name|ether_addr
struct_decl|;
end_struct_decl

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

begin_comment
comment|/* #undef USE_IM */
end_comment

begin_comment
comment|/* Used with login -p */
end_comment

begin_comment
comment|/* #undef LOGIN_ARGS */
end_comment

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

end_unit

