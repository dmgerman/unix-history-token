begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* include/config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

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
value|static
comment|/**/
value|const char *const rcsid[] = { (const char *)rcsid, "\100(#)" msg }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BINDIR
value|"/usr/heimdal/bin"
end_define

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/heimdal/lib"
end_define

begin_define
define|#
directive|define
name|LIBEXECDIR
value|"/usr/heimdal/libexec"
end_define

begin_define
define|#
directive|define
name|SBINDIR
value|"/usr/heimdal/sbin"
end_define

begin_define
define|#
directive|define
name|HAVE_INT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT64_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

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
comment|/* Define if you want authentication support in telnet. */
end_comment

begin_define
define|#
directive|define
name|AUTHENTICATION
value|1
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

begin_comment
comment|/* #undef GETHOSTBYADDR_PROTO_COMPATIBLE */
end_comment

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
comment|/* Define if you have the<arpa/ftp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_FTP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/inet.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/nameser.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define if you have the<arpa/telnet.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_TELNET_H
value|1
end_define

begin_comment
comment|/* Define if you have the `asnprintf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ASNPRINTF */
end_comment

begin_comment
comment|/* Define if you have the `asprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the<bind/bitypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BIND_BITYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<bsdsetjmp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BSDSETJMP_H */
end_comment

begin_comment
comment|/* Define if you have the<capability.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CAPABILITY_H */
end_comment

begin_comment
comment|/* Define if you have the `cap_set_proc' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CAP_SET_PROC */
end_comment

begin_comment
comment|/* Define if you have the `cgetent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CGETENT
value|1
end_define

begin_comment
comment|/* Define if you have the `chown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHOWN
value|1
end_define

begin_comment
comment|/* Define if you have the<config.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CONFIG_H */
end_comment

begin_comment
comment|/* Define if you have the `copyhostent' function. */
end_comment

begin_comment
comment|/* #undef HAVE_COPYHOSTENT */
end_comment

begin_comment
comment|/* Define if you have the `crypt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRYPT
value|1
end_define

begin_comment
comment|/* Define if you have the<crypt.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
end_comment

begin_comment
comment|/* Define if you have the<curses.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

begin_comment
comment|/* Define if you have the `daemon' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* Define if you have the `dbm_firstkey' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DBM_FIRSTKEY
value|1
end_define

begin_comment
comment|/* Define if you have the<dbm.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DBM_H */
end_comment

begin_comment
comment|/* Define if you have the `dbopen' function. */
end_comment

begin_comment
comment|/* #undef HAVE_DBOPEN */
end_comment

begin_comment
comment|/* Define if you have the<db_185.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DB_185_H */
end_comment

begin_comment
comment|/* Define if you have the `db_create' function. */
end_comment

begin_comment
comment|/* #undef HAVE_DB_CREATE */
end_comment

begin_comment
comment|/* Define if you have the<db.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DB_H
value|1
end_define

begin_comment
comment|/* Define if you have the `des_cbc_encrypt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DES_CBC_ENCRYPT
value|1
end_define

begin_comment
comment|/* Define if you have the<dirent.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define if you have the `dlopen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLOPEN
value|1
end_define

begin_comment
comment|/* Define if you have the `dn_expand' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DN_EXPAND
value|1
end_define

begin_comment
comment|/* Define if you have the `el_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EL_INIT
value|1
end_define

begin_comment
comment|/* define if your system declares environ */
end_comment

begin_comment
comment|/* #undef HAVE_ENVIRON_DECLARATION */
end_comment

begin_comment
comment|/* Define if you have the `err' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR
value|1
end_define

begin_comment
comment|/* Define if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the `errx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRX
value|1
end_define

begin_comment
comment|/* Define if you have the<err.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERR_H
value|1
end_define

begin_comment
comment|/* Define if you have the `fchown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHOWN
value|1
end_define

begin_comment
comment|/* Define if you have the `fcntl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the `flock' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the `fnmatch' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH
value|1
end_define

begin_comment
comment|/* Define if you have the<fnmatch.h> header file. */
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

begin_comment
comment|/* #undef HAVE_FOUR_VALUED_EL_INIT */
end_comment

begin_comment
comment|/* define if krb_put_int takes four arguments. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FOUR_VALUED_KRB_PUT_INT
value|1
end_define

begin_comment
comment|/* Define if you have the `freeaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FREEADDRINFO
value|1
end_define

begin_comment
comment|/* Define if you have the `freehostent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FREEHOSTENT
value|1
end_define

begin_comment
comment|/* Define if you have the `gai_strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAI_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the<gdbm/ndbm.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_GDBM_NDBM_H */
end_comment

begin_comment
comment|/* Define if you have the `getaddrinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define if you have the `getconfattr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETCONFATTR */
end_comment

begin_comment
comment|/* Define if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the `getdtablesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the `getegid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the `geteuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the `getgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define if you have the `gethostbyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the `gethostbyname2' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME2
value|1
end_define

begin_comment
comment|/* Define if you have the `gethostname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define if you have the `getifaddrs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIFADDRS
value|1
end_define

begin_comment
comment|/* Define if you have the `getipnodebyaddr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYADDR
value|1
end_define

begin_comment
comment|/* Define if you have the `getipnodebyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIPNODEBYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the `getlogin' function. */
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
comment|/* Define if you have the `getnameinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define if you have the `getopt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_comment
comment|/* Define if you have the `getpwnam_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPWNAM_R */
end_comment

begin_comment
comment|/* Define if you have the `getrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define if you have the `getsockopt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETSOCKOPT
value|1
end_define

begin_comment
comment|/* Define if you have the `getspnam' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETSPNAM */
end_comment

begin_comment
comment|/* Define if you have the `gettimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the `getudbnam' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETUDBNAM */
end_comment

begin_comment
comment|/* Define if you have the `getuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the `getusershell' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUSERSHELL
value|1
end_define

begin_comment
comment|/* define if you have a glob() that groks GLOB_BRACE, GLOB_NOCHECK,    GLOB_QUOTE, and GLOB_TILDE */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_comment
comment|/* Define if you have the `grantpt' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GRANTPT */
end_comment

begin_comment
comment|/* Define if you have the<grp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_comment
comment|/* Define if you have the `hstrerror' function. */
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
comment|/* define if your system declares h_errlist */
end_comment

begin_comment
comment|/* #undef HAVE_H_ERRLIST_DECLARATION */
end_comment

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
comment|/* define if your system declares h_errno */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRNO_DECLARATION
value|1
end_define

begin_comment
comment|/* Define if you have the `h_nerr' variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_NERR
value|1
end_define

begin_comment
comment|/* define if your system declares h_nerr */
end_comment

begin_comment
comment|/* #undef HAVE_H_NERR_DECLARATION */
end_comment

begin_comment
comment|/* Define if you have the<ifaddrs.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IFADDRS_H
value|1
end_define

begin_comment
comment|/* Define if you have the `inet_aton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_comment
comment|/* Define if you have the `inet_ntop' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* Define if you have the `inet_pton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_comment
comment|/* Define if you have the `initgroups' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INITGROUPS
value|1
end_define

begin_comment
comment|/* Define if you have the `innetgr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INNETGR
value|1
end_define

begin_comment
comment|/* Define if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<io.h> header file. */
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
comment|/* Define if you have the `iruserok' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IRUSEROK
value|1
end_define

begin_comment
comment|/* Define if you have the `krb_disable_debug' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KRB_DISABLE_DEBUG
value|1
end_define

begin_comment
comment|/* Define if you have the `krb_enable_debug' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KRB_ENABLE_DEBUG
value|1
end_define

begin_comment
comment|/* Define if you have the `krb_get_our_ip_for_realm' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KRB_GET_OUR_IP_FOR_REALM
value|1
end_define

begin_comment
comment|/* Define if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the `logwtmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGWTMP
value|1
end_define

begin_comment
comment|/* Define if the system has the type `long long'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if you have the `lstat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the<maillock.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MAILLOCK_H */
end_comment

begin_comment
comment|/* Define if you have the `MD4_Init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MD4_INIT
value|1
end_define

begin_comment
comment|/* Define if you have the `MD5_Init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MD5_INIT
value|1
end_define

begin_comment
comment|/* Define if you have the `memmove' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the `mkstemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the `mktime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_comment
comment|/* Define if you have the<ndbm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NDBM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet6/in6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET6_IN6_H */
end_comment

begin_comment
comment|/* Define if you have the<netinet6/in6_var.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET6_IN6_VAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN6_H */
end_comment

begin_comment
comment|/* Define if you have the<netinet/in6_machtypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN6_MACHTYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<netinet/in6_var.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN6_VAR_H */
end_comment

begin_comment
comment|/* Define if you have the<netinet/in.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in_systm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/ip.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/tcp.h> header file. */
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
comment|/* Define if you have the<netinfo/ni.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO_NI_H */
end_comment

begin_comment
comment|/* Define if you have the<net/if.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<openssl/des.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_DES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<openssl/md4.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_MD4_H
value|1
end_define

begin_comment
comment|/* Define if you have the<openssl/md5.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_MD5_H
value|1
end_define

begin_comment
comment|/* Define if you have the<openssl/rc4.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_RC4_H
value|1
end_define

begin_comment
comment|/* Define if you have the<openssl/sha.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_SHA_H
value|1
end_define

begin_comment
comment|/* define if your system declares optarg */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTARG_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares opterr */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTERR_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares optind */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTIND_DECLARATION
value|1
end_define

begin_comment
comment|/* define if your system declares optopt */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPTOPT_DECLARATION
value|1
end_define

begin_comment
comment|/* Define to enable basic OSF C2 support. */
end_comment

begin_comment
comment|/* #undef HAVE_OSFC2 */
end_comment

begin_comment
comment|/* Define if you have the<paths.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHS_H
value|1
end_define

begin_comment
comment|/* Define if you have the `pidfile' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PIDFILE */
end_comment

begin_comment
comment|/* Define if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_comment
comment|/* Define if you have the `ptsname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PTSNAME */
end_comment

begin_comment
comment|/* Define if you have the<pty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PTY_H */
end_comment

begin_comment
comment|/* Define if you have the `putenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the<pwd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define if you have the `rand' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAND
value|1
end_define

begin_comment
comment|/* Define if you have the `random' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the `RC4' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RC4
value|1
end_define

begin_comment
comment|/* Define if you have the `rcmd' function. */
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
comment|/* Define if you have the `readv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READV
value|1
end_define

begin_comment
comment|/* Define if you have the `recvmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_comment
comment|/* Define if you have the<resolv.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define if you have the `res_search' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_SEARCH
value|1
end_define

begin_comment
comment|/* Define if you have the `revoke' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REVOKE
value|1
end_define

begin_comment
comment|/* Define if you have the<rpcsvc/dbm.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_RPCSVC_DBM_H */
end_comment

begin_comment
comment|/* Define if you have the<rpcsvc/ypclnt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RPCSVC_YPCLNT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sac.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SAC_H */
end_comment

begin_comment
comment|/* Define if the system has the type `sa_family_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_FAMILY_T
value|1
end_define

begin_comment
comment|/* Define if you have the<security/pam_modules.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SECURITY_PAM_MODULES_H
value|1
end_define

begin_comment
comment|/* Define if you have the `select' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define if you have the `sendmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SENDMSG
value|1
end_define

begin_comment
comment|/* Define if you have the `setegid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the `seteuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the `setitimer' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETITIMER
value|1
end_define

begin_comment
comment|/* Define if you have the `setlim' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETLIM */
end_comment

begin_comment
comment|/* Define if you have the `setlogin' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOGIN
value|1
end_define

begin_comment
comment|/* Define if you have the `setpcred' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETPCRED */
end_comment

begin_comment
comment|/* Define if you have the `setpgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGID
value|1
end_define

begin_comment
comment|/* Define if you have the `setproctitle' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPROCTITLE
value|1
end_define

begin_comment
comment|/* Define if you have the `setregid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREGID
value|1
end_define

begin_comment
comment|/* Define if you have the `setresgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRESGID
value|1
end_define

begin_comment
comment|/* Define if you have the `setresuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRESUID
value|1
end_define

begin_comment
comment|/* Define if you have the `setreuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|1
end_define

begin_comment
comment|/* Define if you have the `setsid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define if you have the `setsockopt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSOCKOPT
value|1
end_define

begin_comment
comment|/* Define if you have the `setutent' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETUTENT */
end_comment

begin_comment
comment|/* Define if you have the `sgi_getcapabilitybyname' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SGI_GETCAPABILITYBYNAME */
end_comment

begin_comment
comment|/* Define if you have the<sgtty.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SGTTY_H
value|1
end_define

begin_comment
comment|/* Define if you have the `SHA1_Init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHA1_INIT
value|1
end_define

begin_comment
comment|/* Define if you have the<shadow.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SHADOW_H */
end_comment

begin_comment
comment|/* Define if you have the<siad.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SIAD_H */
end_comment

begin_comment
comment|/* Define if you have the `sigaction' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the<signal.h> header file. */
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
comment|/* Define if you have the `socket' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKET
value|1
end_define

begin_comment
comment|/* Define if the system has the type `socklen_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_comment
comment|/* Define if you have the<standards.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STANDARDS_H */
end_comment

begin_comment
comment|/* Define if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the `strftime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRFTIME
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define if you have the `strlwr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRLWR */
end_comment

begin_comment
comment|/* Define if you have the `strncasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the `strndup' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRNDUP */
end_comment

begin_comment
comment|/* Define if you have the `strnlen' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRNLEN */
end_comment

begin_comment
comment|/* Define if you have the<stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the `strptime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_comment
comment|/* Define if you have the `strsep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* Define if you have the `strsep_copy' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRSEP_COPY */
end_comment

begin_comment
comment|/* Define if you have the `strstr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define if you have the `strsvis' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRSVIS */
end_comment

begin_comment
comment|/* Define if you have the `strtok_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOK_R
value|1
end_define

begin_comment
comment|/* Define if the system has the type `struct addrinfo'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_ADDRINFO
value|1
end_define

begin_comment
comment|/* Define if the system has the type `struct ifaddrs'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_IFADDRS
value|1
end_define

begin_comment
comment|/* Define if the system has the type `struct sockaddr'. */
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
comment|/* Define if the system has the type `struct sockaddr_storage'. */
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
comment|/* Define if you have the `strunvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUNVIS
value|1
end_define

begin_comment
comment|/* Define if you have the `strupr' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUPR */
end_comment

begin_comment
comment|/* Define if you have the `strvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVIS
value|1
end_define

begin_comment
comment|/* Define if you have the `strvisx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVISX
value|1
end_define

begin_comment
comment|/* Define if you have the `svis' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SVIS */
end_comment

begin_comment
comment|/* Define if you have the `swab' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SWAB
value|1
end_define

begin_comment
comment|/* Define if you have the `sysconf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have the `sysctl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCTL
value|1
end_define

begin_comment
comment|/* Define if you have the `syslog' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG
value|1
end_define

begin_comment
comment|/* Define if you have the<syslog.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/bitypes.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_BITYPES_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/capability.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_CAPABILITY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/category.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CATEGORY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/file.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/filio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ioccom.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCCOM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/proc.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ptyio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTYIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ptyvar.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTYVAR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/pty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/resource.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/select.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/socket.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sockio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stream.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/strtty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STRTTY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/str_tty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STR_TTY_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/syscall.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCALL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sysctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/timeb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/times.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/tty.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TTY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/uio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/un.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/utsname.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTSNAME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the<term.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERM_H
value|1
end_define

begin_comment
comment|/* Define if you have the `tgetent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TGETENT
value|1
end_define

begin_comment
comment|/* Define if you have the `timegm' function. */
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
comment|/* define if your system declares timezone */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEZONE_DECLARATION
value|1
end_define

begin_comment
comment|/* Define if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<tmpdir.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TMPDIR_H */
end_comment

begin_comment
comment|/* Define if you have the `ttyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYNAME
value|1
end_define

begin_comment
comment|/* Define if you have the `ttyslot' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TTYSLOT
value|1
end_define

begin_comment
comment|/* Define if you have the<udb.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UDB_H */
end_comment

begin_comment
comment|/* Define if you have the `umask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UMASK
value|1
end_define

begin_comment
comment|/* Define if you have the `uname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the `unlockpt' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UNLOCKPT */
end_comment

begin_comment
comment|/* Define if you have the `unsetenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define if you have the `unvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNVIS
value|1
end_define

begin_comment
comment|/* Define if you have the<userconf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_USERCONF_H */
end_comment

begin_comment
comment|/* Define if you have the<usersec.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_USERSEC_H */
end_comment

begin_comment
comment|/* Define if you have the<util.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTIL_H */
end_comment

begin_comment
comment|/* Define if you have the<utmpx.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPX_H */
end_comment

begin_comment
comment|/* Define if you have the<utmp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMP_H
value|1
end_define

begin_comment
comment|/* Define if you have the `vasnprintf' function. */
end_comment

begin_comment
comment|/* #undef HAVE_VASNPRINTF */
end_comment

begin_comment
comment|/* Define if you have the `vasprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the `verr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VERR
value|1
end_define

begin_comment
comment|/* Define if you have the `verrx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VERRX
value|1
end_define

begin_comment
comment|/* Define if you have the `vhangup' function. */
end_comment

begin_comment
comment|/* #undef HAVE_VHANGUP */
end_comment

begin_comment
comment|/* Define if you have the `vis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS
value|1
end_define

begin_comment
comment|/* Define if you have the<vis.h> header file. */
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
comment|/* Define if you have the `vsyslog' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSYSLOG
value|1
end_define

begin_comment
comment|/* Define if you have the `vwarn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VWARN
value|1
end_define

begin_comment
comment|/* Define if you have the `vwarnx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VWARNX
value|1
end_define

begin_comment
comment|/* Define if you have the `warn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARN
value|1
end_define

begin_comment
comment|/* Define if you have the `warnx' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WARNX
value|1
end_define

begin_comment
comment|/* Define if you have the<winsock.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WINSOCK_H */
end_comment

begin_comment
comment|/* Define if you have the `writev' function. */
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
comment|/* Define if you have the `XauFileName' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_XAUFILENAME
value|1
end_define

begin_comment
comment|/* Define if you have the `XauReadAuth' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_XAUREADAUTH
value|1
end_define

begin_comment
comment|/* Define if you have the `XauWriteAuth' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_XAUWRITEAUTH
value|1
end_define

begin_comment
comment|/* Define if you have the `yp_get_default_domain' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_YP_GET_DEFAULT_DOMAIN
value|1
end_define

begin_comment
comment|/* Define if you have the `_getpty' function. */
end_comment

begin_comment
comment|/* #undef HAVE__GETPTY */
end_comment

begin_comment
comment|/* Define if you have the `_scrsize' function. */
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
comment|/* define if your system declares __progname */
end_comment

begin_comment
comment|/* #undef HAVE___PROGNAME_DECLARATION */
end_comment

begin_comment
comment|/* Define if you have the hesiod package. */
end_comment

begin_comment
comment|/* #undef HESIOD */
end_comment

begin_comment
comment|/* Define if you want to use the KDC as a kaserver. */
end_comment

begin_comment
comment|/* #undef KASERVER */
end_comment

begin_comment
comment|/* Define if you want support in hprop for reading kaserver databases */
end_comment

begin_comment
comment|/* #undef KASERVER_DB */
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
comment|/* Define if krb_mk_req takes cons char * */
end_comment

begin_comment
comment|/* #undef KRB_MK_REQ_CONST */
end_comment

begin_comment
comment|/* Define to zero if your krb.h doesn't */
end_comment

begin_comment
comment|/* #undef KRB_VERIFY_NOT_SECURE */
end_comment

begin_comment
comment|/* Define to one if your krb.h doesn't */
end_comment

begin_comment
comment|/* #undef KRB_VERIFY_SECURE */
end_comment

begin_comment
comment|/* Define to two if your krb.h doesn't */
end_comment

begin_comment
comment|/* #undef KRB_VERIFY_SECURE_FAIL */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for asnprintf() */
end_comment

begin_comment
comment|/* #undef NEED_ASNPRINTF_PROTO */
end_comment

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
comment|/* define if the system is missing a prototype for mkstemp() */
end_comment

begin_comment
comment|/* #undef NEED_MKSTEMP_PROTO */
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
comment|/* define if the system is missing a prototype for strsep() */
end_comment

begin_comment
comment|/* #undef NEED_STRSEP_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for strtok_r() */
end_comment

begin_comment
comment|/* #undef NEED_STRTOK_R_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for unsetenv() */
end_comment

begin_comment
comment|/* #undef NEED_UNSETENV_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for vasnprintf() */
end_comment

begin_comment
comment|/* #undef NEED_VASNPRINTF_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for vasprintf() */
end_comment

begin_comment
comment|/* #undef NEED_VASPRINTF_PROTO */
end_comment

begin_comment
comment|/* define if the system is missing a prototype for vsnprintf() */
end_comment

begin_comment
comment|/* #undef NEED_VSNPRINTF_PROTO */
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
comment|/* Define if you have the ANSI C header files. */
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
comment|/* Define to what version of SunOS you are running. */
end_comment

begin_comment
comment|/* #undef SunOS */
end_comment

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares `struct tm'. */
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
value|"0.3e"
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
comment|/* Define if the X Window System is missing or not being used. */
end_comment

begin_comment
comment|/* #undef X_DISPLAY_MISSING */
end_comment

begin_comment
comment|/* Define if `lex' declares `yytext' as a `char *' by default, not a `char[]'.    */
end_comment

begin_define
define|#
directive|define
name|YYTEXT_POINTER
value|1
end_define

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
comment|/* Define as `__inline' if that's what the C compiler calls it, or to nothing    if it is not supported. */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define this to what the type mode_t should be. */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> does not define. */
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
comment|/* Define to `unsigned' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define this to what the type ssize_t should be. */
end_comment

begin_comment
comment|/* #undef ssize_t */
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

begin_define
define|#
directive|define
name|BINDIR
value|"/usr/heimdal/bin"
end_define

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/heimdal/lib"
end_define

begin_define
define|#
directive|define
name|LIBEXECDIR
value|"/usr/heimdal/libexec"
end_define

begin_define
define|#
directive|define
name|SBINDIR
value|"/usr/heimdal/sbin"
end_define

begin_define
define|#
directive|define
name|BINDIR
value|"/usr/heimdal/bin"
end_define

begin_define
define|#
directive|define
name|LIBDIR
value|"/usr/heimdal/lib"
end_define

begin_define
define|#
directive|define
name|LIBEXECDIR
value|"/usr/heimdal/libexec"
end_define

begin_define
define|#
directive|define
name|SBINDIR
value|"/usr/heimdal/sbin"
end_define

begin_define
define|#
directive|define
name|HAVE_INT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INT64_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT8_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT16_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT32_T
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UINT64_T
value|1
end_define

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

begin_comment
comment|/* #undef PROTOTYPES */
end_comment

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
comment|/* Set this to the default system lead string for telnetd  * can contain %-escapes: %s=sysname, %m=machine, %r=os-release  * %v=os-version, %t=tty, %h=hostname, %d=date and time  */
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

