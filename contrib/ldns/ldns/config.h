begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldns/config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* ldns/config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define if building universal (internal helper macro) */
end_comment

begin_comment
comment|/* #undef AC_APPLE_UNIVERSAL_BUILD */
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
comment|/* Define to 1 if you have the `b32_ntop' function. */
end_comment

begin_comment
comment|/* #undef HAVE_B32_NTOP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `b32_pton' function. */
end_comment

begin_comment
comment|/* #undef HAVE_B32_PTON */
end_comment

begin_comment
comment|/* Define to 1 if you have the `b64_ntop' function. */
end_comment

begin_comment
comment|/* #undef HAVE_B64_NTOP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `b64_pton' function. */
end_comment

begin_comment
comment|/* #undef HAVE_B64_PTON */
end_comment

begin_comment
comment|/* Define to 1 if you have the `bzero' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `calloc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CALLOC
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
comment|/* Is a CAFILE given at configure time */
end_comment

begin_define
define|#
directive|define
name|HAVE_DANE_CA_FILE
value|0
end_define

begin_comment
comment|/* Is a CAPATH given at configure time */
end_comment

begin_define
define|#
directive|define
name|HAVE_DANE_CA_PATH
value|0
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
comment|/* Define to 1 if you have the `EVP_sha256' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EVP_SHA256
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
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
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
comment|/* Define to 1 if you have the `gmtime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GMTIME_R
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
comment|/* define if you have inttypes.h */
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
comment|/* Define to 1 if you have the `isascii' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `isblank' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISBLANK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pcap' library (-lpcap). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPCAP */
end_comment

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
comment|/* Define to 1 if your system has a GNU libc compatible `malloc' function, and    to 0 otherwise. */
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
comment|/* Define to 1 if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
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
comment|/* Define to 1 if you have the<netinet/if_ether.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IF_ETHER_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/igmp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IGMP_H */
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

begin_comment
comment|/* #undef HAVE_NETINET_IN_SYSTM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/ip6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IP6_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/ip_compat.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IP_COMPAT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/ip.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/udp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_UDP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<net/ethernet.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_ETHERNET_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<net/if.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_IF_H */
end_comment

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
comment|/* Define to 1 if you have the<pcap.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PCAP_H */
end_comment

begin_comment
comment|/* If available, contains the Python version number currently in use. */
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
comment|/* Define to 1 if your system has a GNU libc compatible `realloc' function,    and to 0 otherwise. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALLOC
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
comment|/* Define to 1 if stdbool.h conforms to C99. */
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
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoul' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define if you have SWIG libraries and header files. */
end_comment

begin_comment
comment|/* #undef HAVE_SWIG */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/mount.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MOUNT_H
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
comment|/* define if you have sys/socket.h */
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
comment|/* define if you have sys/types.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `timegm' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEGM
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
comment|/* define if you have unistd.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
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
comment|/* Define to 1 if you have the<ws2tcpip.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WS2TCPIP_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `_Bool'. */
end_comment

begin_define
define|#
directive|define
name|HAVE__BOOL
value|1
end_define

begin_comment
comment|/* Is a CAFILE given at configure time */
end_comment

begin_comment
comment|/* #undef LDNS_DANE_CA_FILE */
end_comment

begin_comment
comment|/* Is a CAPATH given at configure time */
end_comment

begin_comment
comment|/* #undef LDNS_DANE_CA_PATH */
end_comment

begin_comment
comment|/* Default trust anchor file */
end_comment

begin_define
define|#
directive|define
name|LDNS_TRUST_ANCHOR_FILE
value|"/etc/unbound/root.key"
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
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"libdns@nlnetlabs.nl"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"ldns"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"ldns 1.6.17"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"libdns"
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
value|"1.6.17"
end_define

begin_comment
comment|/* Define this to enable RR type CDS. */
end_comment

begin_comment
comment|/* #undef RRTYPE_CDS */
end_comment

begin_comment
comment|/* Define this to enable RR type NINFO. */
end_comment

begin_comment
comment|/* #undef RRTYPE_NINFO */
end_comment

begin_comment
comment|/* Define this to enable RR type RKEY. */
end_comment

begin_comment
comment|/* #undef RRTYPE_RKEY */
end_comment

begin_comment
comment|/* Define this to enable RR type TA. */
end_comment

begin_comment
comment|/* #undef RRTYPE_TA */
end_comment

begin_comment
comment|/* Define this to enable RR type URI. */
end_comment

begin_comment
comment|/* #undef RRTYPE_URI */
end_comment

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
comment|/* Define this to enable messages to stderr. */
end_comment

begin_comment
comment|/* #undef STDERR_MSGS */
end_comment

begin_comment
comment|/* System configuration dir */
end_comment

begin_define
define|#
directive|define
name|SYSCONFDIR
value|sysconfdir
end_define

begin_comment
comment|/* Define this to enable DANE support. */
end_comment

begin_define
define|#
directive|define
name|USE_DANE
value|1
end_define

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
comment|/* Define this to enable GOST support. */
end_comment

begin_define
define|#
directive|define
name|USE_GOST
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
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment

begin_if
if|#
directive|if
name|defined
name|AC_APPLE_UNIVERSAL_BUILD
end_if

begin_if
if|#
directive|if
name|defined
name|__BIG_ENDIAN__
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

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|WORDS_BIGENDIAN
end_ifndef

begin_comment
comment|/* #  undef WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
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
comment|/* Define to `char' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef int8_t */
end_comment

begin_comment
comment|/* Define to `size_t' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef intptr_t */
end_comment

begin_comment
comment|/* Define to rpl_malloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef malloc */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to rpl_realloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef realloc */
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
comment|/* Fallback member name for socket family in struct sockaddr_storage */
end_comment

begin_comment
comment|/* #undef ss_family */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef ssize_t */
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

begin_ifndef
ifndef|#
directive|ifndef
name|LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|int
name|ldns_b64_ntop
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|src
parameter_list|,
name|size_t
name|srclength
parameter_list|,
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
comment|/**  * calculates the size needed to store the result of b64_ntop  */
comment|/*@unused@*/
specifier|static
specifier|inline
name|size_t
name|ldns_b64_ntop_calculate_size
parameter_list|(
name|size_t
name|srcsize
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
operator|(
name|srcsize
operator|+
literal|2
operator|)
operator|/
literal|3
operator|)
operator|*
literal|4
operator|)
operator|+
literal|1
operator|)
return|;
block|}
name|int
name|ldns_b64_pton
parameter_list|(
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|uint8_t
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
comment|/**  * calculates the size needed to store the result of ldns_b64_pton  */
comment|/*@unused@*/
specifier|static
specifier|inline
name|size_t
name|ldns_b64_pton_calculate_size
parameter_list|(
name|size_t
name|srcsize
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
operator|(
operator|(
name|srcsize
operator|+
literal|3
operator|)
operator|/
literal|4
operator|)
operator|*
literal|3
operator|)
operator|)
operator|+
literal|1
operator|)
return|;
block|}
comment|/**  * Given in dnssec_zone.c, also used in dnssec_sign.c:w   */
name|int
name|ldns_dname_compare_v
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|HAVE_SLEEP
comment|/* use windows sleep, in millisecs, instead */
define|#
directive|define
name|sleep
parameter_list|(
name|x
parameter_list|)
value|Sleep((x)*1000)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_RANDOM
define|#
directive|define
name|srandom
parameter_list|(
name|x
parameter_list|)
value|srand(x)
define|#
directive|define
name|random
parameter_list|(
name|x
parameter_list|)
value|rand(x)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_TIMEGM
include|#
directive|include
file|<time.h>
name|time_t
name|timegm
parameter_list|(
name|struct
name|tm
modifier|*
name|tm
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* !TIMEGM */
ifndef|#
directive|ifndef
name|HAVE_GMTIME_R
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
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_LOCALTIME_R
name|struct
name|tm
modifier|*
name|localtime_r
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
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_ISBLANK
name|int
name|isblank
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* !HAVE_ISBLANK */
ifndef|#
directive|ifndef
name|HAVE_ISASCII
name|int
name|isascii
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* !HAVE_ISASCII */
ifndef|#
directive|ifndef
name|HAVE_SNPRINTF
include|#
directive|include
file|<stdarg.h>
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
endif|#
directive|endif
comment|/* HAVE_SNPRINTF */
ifndef|#
directive|ifndef
name|HAVE_INET_PTON
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
endif|#
directive|endif
comment|/* HAVE_INET_PTON */
ifndef|#
directive|ifndef
name|HAVE_INET_NTOP
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
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_INET_ATON
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
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_MEMMOVE
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
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETADDRINFO
end_ifndef

begin_include
include|#
directive|include
file|"compat/fake-rfc2553.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRTOUL
end_ifndef

begin_define
define|#
directive|define
name|strtoul
value|(unsigned long)strtol
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

