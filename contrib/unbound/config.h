begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Directory to chroot to */
end_comment

begin_define
define|#
directive|define
name|CHROOT_DIR
value|"/var/unbound"
end_define

begin_comment
comment|/* Pathname to the Unbound configuration file */
end_comment

begin_define
define|#
directive|define
name|CONFIGFILE
value|"/var/unbound/unbound.conf"
end_define

begin_comment
comment|/* Define this if on macOSX10.4-darwin8 and setreuid and setregid do not work    */
end_comment

begin_comment
comment|/* #undef DARWIN_BROKEN_SETREUID */
end_comment

begin_comment
comment|/* Whether daemon is deprecated */
end_comment

begin_comment
comment|/* #undef DEPRECATED_DAEMON */
end_comment

begin_comment
comment|/* Define if you want to use debug lock checking (slow). */
end_comment

begin_comment
comment|/* #undef ENABLE_LOCK_CHECKS */
end_comment

begin_comment
comment|/* Define this if you enabled-allsymbols from libunbound to link binaries to    it for smaller install size, but the libunbound export table is polluted by    internal symbols */
end_comment

begin_comment
comment|/* #undef EXPORT_ALL_SYMBOLS */
end_comment

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
comment|/* Whether the C compiler accepts the "format" attribute */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATTR_FORMAT
value|1
end_define

begin_comment
comment|/* Whether the C compiler accepts the "unused" attribute */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATTR_UNUSED
value|1
end_define

begin_comment
comment|/* Define to 1 if your system has a working `chown' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHOWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `chroot' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHROOT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `ctime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTIME_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `daemon' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `NID_secp384r1', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_NID_SECP384R1
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `NID_X9_62_prime256v1', and to 0    if you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_NID_X9_62_PRIME256V1
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `sk_SSL_COMP_pop_free', and to 0    if you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SK_SSL_COMP_POP_FREE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of    `SSL_COMP_get_compression_methods', and to 0 if you don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SSL_COMP_GET_COMPRESSION_METHODS
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
comment|/* Define to 1 if you have the `endprotoent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENDPROTOENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `endservent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENDSERVENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `event_base_free' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EVENT_BASE_FREE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `event_base_get_method' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EVENT_BASE_GET_METHOD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `event_base_new' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EVENT_BASE_NEW */
end_comment

begin_comment
comment|/* Define to 1 if you have the `event_base_once' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EVENT_BASE_ONCE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<event.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_EVENT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `EVP_sha1' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_SHA1
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_sha256' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_SHA256
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `EVP_sha512' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_SHA512
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `ev_default_loop' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EV_DEFAULT_LOOP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ev_loop' function. */
end_comment

begin_comment
comment|/* #undef HAVE_EV_LOOP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<expat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXPAT_H
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
comment|/* Define to 1 if you have the `FIPS_mode' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FIPS_MODE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_comment
comment|/* Whether getaddrinfo is available */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<getopt.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpwnam' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPWNAM
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
comment|/* Define to 1 if you have the `glob' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<glob.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GLOB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gmtime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GMTIME_R
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
comment|/* If you have HMAC_CTX_init */
end_comment

begin_define
define|#
directive|define
name|HAVE_HMAC_CTX_INIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_aton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_ntop' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `inet_pton' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `initgroups' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INITGROUPS
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
comment|/* if the function 'ioctlsocket' is available */
end_comment

begin_comment
comment|/* #undef HAVE_IOCTLSOCKET */
end_comment

begin_comment
comment|/* Define to 1 if you have the<iphlpapi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IPHLPAPI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `kill' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KILL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `localtime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALTIME_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<login_cap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOGIN_CAP_H
value|1
end_define

begin_comment
comment|/* If have GNU libc compatible malloc */
end_comment

begin_define
define|#
directive|define
name|HAVE_MALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memmove' function. */
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
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

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
comment|/* Use libnss for crypto */
end_comment

begin_comment
comment|/* #undef HAVE_NSS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `OPENSSL_config' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_CONFIG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<openssl/conf.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_CONF_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<openssl/engine.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_ENGINE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<openssl/err.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_ERR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<openssl/rand.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_RAND_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<openssl/ssl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENSSL_SSL_H
value|1
end_define

begin_comment
comment|/* Define if you have POSIX threads libraries and header files. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD
value|1
end_define

begin_comment
comment|/* Have PTHREAD_PRIO_INHERIT. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_PRIO_INHERIT
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `pthread_rwlock_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_RWLOCK_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `pthread_spinlock_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_SPINLOCK_T
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
comment|/* Define if you have Python libraries and header files. */
end_comment

begin_comment
comment|/* #undef HAVE_PYTHON */
end_comment

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
comment|/* Define to 1 if you have the `recvmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sbrk' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SBRK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sendmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SENDMSG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setregid' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SETREGID */
end_comment

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

begin_comment
comment|/* #undef HAVE_SETREUID */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
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
comment|/* Define to 1 if you have the `setusercontext' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigprocmask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGPROCMASK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `snprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `socketpair' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETPAIR
value|1
end_define

begin_comment
comment|/* Using Solaris threads */
end_comment

begin_comment
comment|/* #undef HAVE_SOLARIS_THREADS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `srandom' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SRANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the SSL libraries installed. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SSL
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdarg.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdbool.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

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
comment|/* Define to 1 if you have the `strftime' function. */
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
comment|/* Define to 1 if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strptime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if `ipi_spec_dst' is a member of `struct in_pktinfo'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_IN_PKTINFO_IPI_SPEC_DST */
end_comment

begin_comment
comment|/* Define if you have Swig libraries and header files. */
end_comment

begin_comment
comment|/* #undef HAVE_SWIG */
end_comment

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
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

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
comment|/* Define to 1 if you have the<sys/socket.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
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
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
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
comment|/* Define to 1 if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
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
comment|/* Define to 1 if you have the `tzset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TZSET
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
comment|/* Define to 1 if you have the `usleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_USLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vfork.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<windows.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WINDOWS_H */
end_comment

begin_comment
comment|/* Using Windows threads */
end_comment

begin_comment
comment|/* #undef HAVE_WINDOWS_THREADS */
end_comment

begin_comment
comment|/* Define to 1 if you have the<winsock2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WINSOCK2_H */
end_comment

begin_comment
comment|/* Define to 1 if `fork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `vfork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `writev' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WRITEV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ws2tcpip.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WS2TCPIP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `_beginthreadex' function. */
end_comment

begin_comment
comment|/* #undef HAVE__BEGINTHREADEX */
end_comment

begin_comment
comment|/* if lex has yylex_destroy */
end_comment

begin_define
define|#
directive|define
name|LEX_HAS_YYLEX_DESTROY
value|1
end_define

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Define to the maximum message length to pass to syslog. */
end_comment

begin_define
define|#
directive|define
name|MAXSYSLOGMSGLEN
value|10240
end_define

begin_comment
comment|/* Define if memcmp() does not compare unsigned bytes */
end_comment

begin_comment
comment|/* #undef MEMCMP_IS_BROKEN */
end_comment

begin_comment
comment|/* Define if mkdir has one argument. */
end_comment

begin_comment
comment|/* #undef MKDIR_HAS_ONE_ARG */
end_comment

begin_comment
comment|/* Define if the network stack does not fully support nonblocking io (causes    lower performance). */
end_comment

begin_comment
comment|/* #undef NONBLOCKING_IS_BROKEN */
end_comment

begin_comment
comment|/* Put -D_ALL_SOURCE define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_ALL_SOURCE */
end_comment

begin_comment
comment|/* Put -D_BSD_SOURCE define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_BSD_SOURCE */
end_comment

begin_comment
comment|/* Put -D_GNU_SOURCE define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_GNU_SOURCE */
end_comment

begin_comment
comment|/* Put -D_LARGEFILE_SOURCE=1 define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_LARGEFILE_SOURCE_1 */
end_comment

begin_comment
comment|/* Put -D_POSIX_C_SOURCE=200112 define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_POSIX_C_SOURCE_200112 */
end_comment

begin_comment
comment|/* Put -D_XOPEN_SOURCE=600 define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_XOPEN_SOURCE_600 */
end_comment

begin_comment
comment|/* Put -D_XOPEN_SOURCE_EXTENDED=1 define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D_XOPEN_SOURCE_EXTENDED_1 */
end_comment

begin_comment
comment|/* Put -D__EXTENSIONS__ define in config.h */
end_comment

begin_comment
comment|/* #undef OMITTED__D__EXTENSIONS__ */
end_comment

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"unbound-bugs@nlnetlabs.nl"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"unbound"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"unbound 1.4.22"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"unbound"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"1.4.22"
end_define

begin_comment
comment|/* default pidfile location */
end_comment

begin_define
define|#
directive|define
name|PIDFILE
value|"/var/unbound/unbound.pid"
end_define

begin_comment
comment|/* Define to necessary symbol if this constant uses a non-standard name on    your system. */
end_comment

begin_comment
comment|/* #undef PTHREAD_CREATE_JOINABLE */
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
comment|/* default rootkey location */
end_comment

begin_define
define|#
directive|define
name|ROOT_ANCHOR_FILE
value|"/var/unbound/root.key"
end_define

begin_comment
comment|/* default rootcert location */
end_comment

begin_define
define|#
directive|define
name|ROOT_CERT_FILE
value|"/var/unbound/icannbundle.pem"
end_define

begin_comment
comment|/* version number for resource files */
end_comment

begin_define
define|#
directive|define
name|RSRC_PACKAGE_VERSION
value|1,4,22,0
end_define

begin_comment
comment|/* Directory to chdir to */
end_comment

begin_define
define|#
directive|define
name|RUN_DIR
value|"/var/unbound"
end_define

begin_comment
comment|/* Shared data */
end_comment

begin_define
define|#
directive|define
name|SHARE_DIR
value|"/var/unbound"
end_define

begin_comment
comment|/* The size of `time_t', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_TIME_T
value|8
end_define

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
comment|/* use default strptime. */
end_comment

begin_define
define|#
directive|define
name|STRPTIME_WORKS
value|1
end_define

begin_comment
comment|/* Use win32 resources and API */
end_comment

begin_comment
comment|/* #undef UB_ON_WINDOWS */
end_comment

begin_comment
comment|/* default username */
end_comment

begin_define
define|#
directive|define
name|UB_USERNAME
value|"unbound"
end_define

begin_comment
comment|/* use to enable lightweight alloc assertions, for debug use */
end_comment

begin_comment
comment|/* #undef UNBOUND_ALLOC_LITE */
end_comment

begin_comment
comment|/* use malloc not regions, for debug use */
end_comment

begin_comment
comment|/* #undef UNBOUND_ALLOC_NONREGIONAL */
end_comment

begin_comment
comment|/* use statistics for allocs and frees, for debug use */
end_comment

begin_comment
comment|/* #undef UNBOUND_ALLOC_STATS */
end_comment

begin_comment
comment|/* define this to enable debug checks. */
end_comment

begin_comment
comment|/* #undef UNBOUND_DEBUG */
end_comment

begin_comment
comment|/* Define this to enable ECDSA support. */
end_comment

begin_define
define|#
directive|define
name|USE_ECDSA
value|1
end_define

begin_comment
comment|/* Define this to enable an EVP workaround for older openssl */
end_comment

begin_comment
comment|/* #undef USE_ECDSA_EVP_WORKAROUND */
end_comment

begin_comment
comment|/* Define this to enable GOST support. */
end_comment

begin_comment
comment|/* #undef USE_GOST */
end_comment

begin_comment
comment|/* Define if you want to use internal select based events */
end_comment

begin_define
define|#
directive|define
name|USE_MINI_EVENT
value|1
end_define

begin_comment
comment|/* Define this to enable SHA256 and SHA512 support. */
end_comment

begin_define
define|#
directive|define
name|USE_SHA2
value|1
end_define

begin_comment
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable threading extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable general extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Whether the windows socket API is used */
end_comment

begin_comment
comment|/* #undef USE_WINSOCK */
end_comment

begin_comment
comment|/* the version of the windows API enabled */
end_comment

begin_define
define|#
directive|define
name|WINVER
value|0x0502
end_define

begin_comment
comment|/* Define if you want Python module. */
end_comment

begin_comment
comment|/* #undef WITH_PYTHONMODULE */
end_comment

begin_comment
comment|/* Define if you want PyUnbound. */
end_comment

begin_comment
comment|/* #undef WITH_PYUNBOUND */
end_comment

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
comment|/* Enable large inode numbers on Mac OS X 10.5.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DARWIN_USE_64_BIT_INODE
end_ifndef

begin_define
define|#
directive|define
name|_DARWIN_USE_64_BIT_INODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
end_comment

begin_comment
comment|/* #undef _LARGEFILE_SOURCE */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Enable for compile on Minix */
end_comment

begin_comment
comment|/* #undef _NETBSD_SOURCE */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
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
comment|/* in_addr_t */
end_comment

begin_comment
comment|/* #undef in_addr_t */
end_comment

begin_comment
comment|/* in_port_t */
end_comment

begin_comment
comment|/* #undef in_port_t */
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
comment|/* Define to `short' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef int16_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef int32_t */
end_comment

begin_comment
comment|/* Define to `long long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef int64_t */
end_comment

begin_comment
comment|/* Define to `signed char' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef int8_t */
end_comment

begin_comment
comment|/* Define if replacement function should be used. */
end_comment

begin_comment
comment|/* #undef malloc */
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
comment|/* Define to 'int' if not defined */
end_comment

begin_comment
comment|/* #undef rlim_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to 'int' if not defined */
end_comment

begin_comment
comment|/* #undef socklen_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define to 'unsigned char if not defined */
end_comment

begin_comment
comment|/* #undef u_char */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define to `unsigned short' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef uint16_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef uint32_t */
end_comment

begin_comment
comment|/* Define to `unsigned long long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef uint64_t */
end_comment

begin_comment
comment|/* Define to `unsigned char' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef uint8_t */
end_comment

begin_comment
comment|/* Define as `fork' if `vfork' does not work. */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OMITTED__D_GNU_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GNU_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
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
name|OMITTED__D_BSD_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_BSD_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_BSD_SOURCE
value|1
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
name|OMITTED__D__EXTENSIONS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__EXTENSIONS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
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
name|OMITTED__D_POSIX_C_SOURCE_200112
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|200112
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
name|OMITTED__D_XOPEN_SOURCE_600
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
value|600
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
name|OMITTED__D_XOPEN_SOURCE_EXTENDED_1
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_XOPEN_SOURCE_EXTENDED
argument_list|)
end_if

begin_define
define|#
directive|define
name|_XOPEN_SOURCE_EXTENDED
value|1
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
name|OMITTED__D_ALL_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ALL_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
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
name|OMITTED__D_LARGEFILE_SOURCE_1
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LARGEFILE_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LARGEFILE_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNBOUND_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|NDEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Use small-ldns codebase */
end_comment

begin_define
define|#
directive|define
name|USE_SLDNS
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SSL
end_ifdef

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_SSL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDARG_H
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WINSOCK2_H
end_ifdef

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WS2TCPIP_H
end_ifdef

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_WINSOCK
end_ifndef

begin_define
define|#
directive|define
name|ARG_LL
value|"%ll"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARG_LL
value|"%I64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATTR_FORMAT
end_ifdef

begin_define
define|#
directive|define
name|ATTR_FORMAT
parameter_list|(
name|archetype
parameter_list|,
name|string_index
parameter_list|,
name|first_to_check
parameter_list|)
define|\
value|__attribute__ ((format (archetype, string_index, first_to_check)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_ATTR_FORMAT */
end_comment

begin_define
define|#
directive|define
name|ATTR_FORMAT
parameter_list|(
name|archetype
parameter_list|,
name|string_index
parameter_list|,
name|first_to_check
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_ATTR_FORMAT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_ATTR_UNUSED
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
value|x __attribute__((unused))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_ATTR_UNUSED */
end_comment

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_ATTR_UNUSED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSEEKO
end_ifndef

begin_define
define|#
directive|define
name|fseeko
value|fseek
end_define

begin_define
define|#
directive|define
name|ftello
value|ftell
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FSEEKO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|snprintf
value|snprintf_unbound
end_define

begin_define
define|#
directive|define
name|vsnprintf
value|vsnprintf_unbound
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SNPRINTF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INET_PTON
end_ifndef

begin_define
define|#
directive|define
name|inet_pton
value|inet_pton_unbound
end_define

begin_function_decl
name|int
name|inet_pton
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_INET_PTON */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INET_NTOP
end_ifndef

begin_define
define|#
directive|define
name|inet_ntop
value|inet_ntop_unbound
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|inet_ntop
parameter_list|(
name|int
name|af
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INET_ATON
end_ifndef

begin_define
define|#
directive|define
name|inet_aton
value|inet_aton_unbound
end_define

begin_function_decl
name|int
name|inet_aton
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMMOVE
end_ifndef

begin_define
define|#
directive|define
name|memmove
value|memmove_unbound
end_define

begin_function_decl
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
name|dest
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCAT
end_ifndef

begin_define
define|#
directive|define
name|strlcat
value|strlcat_unbound
end_define

begin_function_decl
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_define
define|#
directive|define
name|strlcpy
value|strlcpy_unbound
end_define

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GMTIME_R
end_ifndef

begin_define
define|#
directive|define
name|gmtime_r
value|gmtime_r_unbound
end_define

begin_function_decl
name|struct
name|tm
modifier|*
name|gmtime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|,
name|struct
name|tm
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SLEEP
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_WINDOWS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|sleep
parameter_list|(
name|x
parameter_list|)
value|Sleep((x)*1000)
end_define

begin_comment
comment|/* on win32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SLEEP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_USLEEP
end_ifndef

begin_define
define|#
directive|define
name|usleep
parameter_list|(
name|x
parameter_list|)
value|Sleep((x)/1000 + 1)
end_define

begin_comment
comment|/* on win32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_USLEEP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RANDOM
end_ifndef

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_comment
comment|/* on win32, for tests only (bad random) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RANDOM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SRANDOM
end_ifndef

begin_define
define|#
directive|define
name|srandom
parameter_list|(
name|x
parameter_list|)
value|srand(x)
end_define

begin_comment
comment|/* on win32, for tests only (bad random) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SRANDOM */
end_comment

begin_comment
comment|/* detect if we need to cast to unsigned int for FD_SET to avoid warnings */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_WINSOCK2_H
end_ifdef

begin_define
define|#
directive|define
name|FD_SET_T
value|(u_int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FD_SET_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IPV6_MIN_MTU
end_ifndef

begin_define
define|#
directive|define
name|IPV6_MIN_MTU
value|1280
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPV6_MIN_MTU */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMCMP_IS_BROKEN
end_ifdef

begin_include
include|#
directive|include
file|"compat/memcmp.h"
end_include

begin_define
define|#
directive|define
name|memcmp
value|memcmp_unbound
end_define

begin_function_decl
name|int
name|memcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|,
specifier|const
name|void
modifier|*
name|y
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_CTIME_R
end_ifndef

begin_define
define|#
directive|define
name|ctime_r
value|unbound_ctime_r
end_define

begin_function_decl
name|char
modifier|*
name|ctime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRPTIME
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|STRPTIME_WORKS
argument_list|)
end_if

begin_define
define|#
directive|define
name|strptime
value|unbound_strptime
end_define

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|strptime
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|struct
name|tm
modifier|*
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_EVENT_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_EVENT_BASE_ONCE
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|HAVE_EV_LOOP
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_EV_DEFAULT_LOOP
argument_list|)
operator|)
operator|&&
operator|(
name|defined
argument_list|(
name|HAVE_PTHREAD
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SOLARIS_THREADS
argument_list|)
operator|)
end_if

begin_comment
comment|/* using version of libevent that is not threadsafe. */
end_comment

begin_define
define|#
directive|define
name|LIBEVENT_SIGNAL_PROBLEM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHECKED_INET6
end_ifndef

begin_define
define|#
directive|define
name|CHECKED_INET6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AF_INET6
end_ifdef

begin_define
define|#
directive|define
name|INET6
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AF_INET6
value|28
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
comment|/* CHECKED_INET6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETADDRINFO
end_ifndef

begin_struct_decl
struct_decl|struct
name|sockaddr_storage
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"compat/fake-rfc2553.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNBOUND_ALLOC_STATS
end_ifdef

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|s
parameter_list|)
value|unbound_stat_malloc_log(s, __FILE__, __LINE__, __func__)
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|unbound_stat_calloc_log(n, s, __FILE__, __LINE__, __func__)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|p
parameter_list|)
value|unbound_stat_free_log(p, __FILE__, __LINE__, __func__)
end_define

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|unbound_stat_realloc_log(p, s, __FILE__, __LINE__, __func__)
end_define

begin_function_decl
name|void
modifier|*
name|unbound_stat_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_calloc
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unbound_stat_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_malloc_log
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_calloc_log
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unbound_stat_free_log
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|unbound_stat_realloc_log
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|UNBOUND_ALLOC_LITE
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"util/alloc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNBOUND_ALLOC_LITE and UNBOUND_ALLOC_STATS */
end_comment

begin_comment
comment|/** default port for DNS traffic. */
end_comment

begin_define
define|#
directive|define
name|UNBOUND_DNS_PORT
value|53
end_define

begin_comment
comment|/** default port for unbound control traffic, registered port with IANA,     ub-dns-control  8953/tcp    unbound dns nameserver control */
end_comment

begin_define
define|#
directive|define
name|UNBOUND_CONTROL_PORT
value|8953
end_define

begin_comment
comment|/** the version of unbound-control that this software implements */
end_comment

begin_define
define|#
directive|define
name|UNBOUND_CONTROL_VERSION
value|1
end_define

end_unit

