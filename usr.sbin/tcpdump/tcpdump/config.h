begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* "generated automatically" means DO NOT MAKE CHANGES TO config.h.in --  * make them to acconfig.h and rerun autoheader */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your processor stores words with the most significant    byte first (like Motorola and SPARC, unlike Intel and VAX).  */
end_comment

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/* Define if you have SSLeay XXX why isn't this HAVE_LIBCRYPTO? */
end_comment

begin_comment
comment|/* #undef CRYPTO */
end_comment

begin_comment
comment|/* Define if you have SSLeay 0.9.0b with the buggy cast128. */
end_comment

begin_comment
comment|/* #undef HAVE_BUGGY_CAST128 */
end_comment

begin_comment
comment|/* Define both to enable IPv6 support XXX why 2? ENABLE_IPV6 is not used. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_IPV6
value|1
end_define

begin_define
define|#
directive|define
name|INET6
value|1
end_define

begin_comment
comment|/* Define if you enable support for the libsmi. */
end_comment

begin_comment
comment|/* #undef LIBSMI */
end_comment

begin_comment
comment|/* Is T_AAAA predefined? */
end_comment

begin_define
define|#
directive|define
name|HAVE_AAAA
value|1
end_define

begin_comment
comment|/* Fallback definition if not in headers */
end_comment

begin_comment
comment|/* XXX why is this not #ifndef HAVE_AAA #define T_AAAA ... ? */
end_comment

begin_comment
comment|/* XXX or even #ifndef T_AAAA ... */
end_comment

begin_comment
comment|/* #undef T_AAAA */
end_comment

begin_comment
comment|/* define if you have struct __res_state_ext */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_STATE_EXT
value|1
end_define

begin_comment
comment|/* define if your struct __res_state has the nsort member */
end_comment

begin_define
define|#
directive|define
name|HAVE_NEW_RES_STATE
value|1
end_define

begin_comment
comment|/*  * define if struct ether_header.ether_dhost is a struct with ether_addr_octet  */
end_comment

begin_comment
comment|/* #undef ETHER_HEADER_HAS_EA */
end_comment

begin_comment
comment|/*  * define if struct ether_arp.arp_sha is a struct with ether_addr_octet  */
end_comment

begin_comment
comment|/* #undef ETHER_ARP_HAS_EA */
end_comment

begin_comment
comment|/* define if struct ether_arp contains arp_xsha */
end_comment

begin_comment
comment|/* #undef ETHER_ARP_HAS_X */
end_comment

begin_comment
comment|/* define if you have the addrinfo function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ADDRINFO
value|1
end_define

begin_comment
comment|/* define if you need to include missing/addrinfoh.h. */
end_comment

begin_comment
comment|/* #undef NEED_ADDRINFO_H */
end_comment

begin_comment
comment|/* define ifyou have the h_errno variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_H_ERRNO
value|1
end_define

begin_comment
comment|/* define if IN6ADDRSZ is defined (XXX not used!) */
end_comment

begin_define
define|#
directive|define
name|HAVE_IN6ADDRSZ
value|1
end_define

begin_comment
comment|/* define if INADDRSZ is defined (XXX not used!) */
end_comment

begin_define
define|#
directive|define
name|HAVE_INADDRSZ
value|1
end_define

begin_comment
comment|/* define if you have<net/slip.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_SLIP_H
value|1
end_define

begin_comment
comment|/* define if this is a development version, to use additional prototypes. */
end_comment

begin_comment
comment|/* #undef HAVE_OS_PROTO_H */
end_comment

begin_comment
comment|/* define if<unistd.h> defines __P() */
end_comment

begin_define
define|#
directive|define
name|HAVE_PORTABLE_PROTOTYPE
value|1
end_define

begin_comment
comment|/* define if RES_USE_INET6 is defined */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_USE_INET6
value|1
end_define

begin_comment
comment|/* define if struct sockaddr has the sa_len member */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_SA_LEN
value|1
end_define

begin_comment
comment|/* define if you have struct sockaddr_storage */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_STORAGE
value|1
end_define

begin_comment
comment|/* define if unaligned memory accesses fail */
end_comment

begin_comment
comment|/* #undef LBL_ALIGN */
end_comment

begin_comment
comment|/* The successful return value from signal (?)XXX */
end_comment

begin_define
define|#
directive|define
name|RETSIGVAL
end_define

begin_comment
comment|/* Define this on IRIX */
end_comment

begin_comment
comment|/* #undef _BSD_SIGNALS */
end_comment

begin_comment
comment|/* For HP/UX ANSI compiler? */
end_comment

begin_comment
comment|/* #undef _HPUX_SOURCE */
end_comment

begin_comment
comment|/* AIX hack. */
end_comment

begin_comment
comment|/* #undef _SUN */
end_comment

begin_comment
comment|/* OSF hack: "Workaround around ip_hl vs. ip_vhl problem in netinet/ip.h" */
end_comment

begin_comment
comment|/* #undef __STDC__ */
end_comment

begin_comment
comment|/* Workaround for missing sized types */
end_comment

begin_comment
comment|/* XXX this should move to the more standard uint*_t */
end_comment

begin_comment
comment|/* #undef int16_t */
end_comment

begin_comment
comment|/* #undef int32_t */
end_comment

begin_comment
comment|/* #undef u_int16_t */
end_comment

begin_comment
comment|/* #undef u_int32_t */
end_comment

begin_comment
comment|/* #undef u_int8_t */
end_comment

begin_comment
comment|/* The number of bytes in a char.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_CHAR
value|1
end_define

begin_comment
comment|/* The number of bytes in a int.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_comment
comment|/* The number of bytes in a long.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_comment
comment|/* The number of bytes in a short.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_comment
comment|/* Define if you have the ether_ntohost function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ETHER_NTOHOST
value|1
end_define

begin_comment
comment|/* Define if you have the getaddrinfo function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define if you have the gethostbyname2 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME2
value|1
end_define

begin_comment
comment|/* Define if you have the getnameinfo function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define if you have the inet_aton function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_ATON
value|1
end_define

begin_comment
comment|/* Define if you have the inet_ntop function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_NTOP
value|1
end_define

begin_comment
comment|/* Define if you have the inet_pton function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INET_PTON
value|1
end_define

begin_comment
comment|/* Define if you have the pfopen function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PFOPEN */
end_comment

begin_comment
comment|/* Define if you have the setlinebuf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
value|1
end_define

begin_comment
comment|/* Define if you have the sigaction function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the sigset function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SIGSET */
end_comment

begin_comment
comment|/* Define if you have the strcasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the vfprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the<cast.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_CAST_H */
end_comment

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/slip.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_SLIP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<rc5.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_RC5_H */
end_comment

begin_comment
comment|/* Define if you have the<rpc/rpcent.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_RPC_RPCENT_H */
end_comment

begin_comment
comment|/* Define if you have the<smi.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SMI_H */
end_comment

begin_comment
comment|/* Define if you have the<zlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ZLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the crypto library (-lcrypto).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCRYPTO */
end_comment

begin_comment
comment|/* Define if you have the dnet library (-ldnet).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBDNET */
end_comment

begin_comment
comment|/* Define if you have the resolv library (-lresolv).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBRESOLV */
end_comment

begin_comment
comment|/* Define if you have the rpc library (-lrpc).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBRPC */
end_comment

begin_comment
comment|/* Define if you have the smi library (-lsmi).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSMI */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define if you have the str library (-lstr).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSTR */
end_comment

begin_comment
comment|/* Define if you have the z library (-lz).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBZ
value|1
end_define

end_unit

