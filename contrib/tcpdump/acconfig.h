begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "generated automatically" means DO NOT MAKE CHANGES TO config.h.in --  * make them to acconfig.h and rerun autoheader */
end_comment

begin_expr_stmt
unit|@
name|TOP
expr|@
end_expr_stmt

begin_comment
comment|/* Define if you have SSLeay 0.9.0b with the buggy cast128. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_BUGGY_CAST128
end_undef

begin_comment
comment|/* Define if you enable IPv6 support */
end_comment

begin_undef
undef|#
directive|undef
name|INET6
end_undef

begin_comment
comment|/* Define if you enable support for the libsmi. */
end_comment

begin_undef
undef|#
directive|undef
name|LIBSMI
end_undef

begin_comment
comment|/* Define if you have the<smi.h> header file.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SMI_H
end_undef

begin_comment
comment|/* define if you have struct __res_state_ext */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_RES_STATE_EXT
end_undef

begin_comment
comment|/* define if your struct __res_state has the nsort member */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_NEW_RES_STATE
end_undef

begin_comment
comment|/* define if<inttypes.h> defines PRI[doxu]64 macros */
end_comment

begin_undef
undef|#
directive|undef
name|INTTYPES_H_DEFINES_FORMATS
end_undef

begin_comment
comment|/*  * define if struct ether_header.ether_dhost is a struct with ether_addr_octet  */
end_comment

begin_undef
undef|#
directive|undef
name|ETHER_HEADER_HAS_EA
end_undef

begin_comment
comment|/* define if struct ether_arp contains arp_xsha */
end_comment

begin_undef
undef|#
directive|undef
name|ETHER_ARP_HAS_X
end_undef

begin_comment
comment|/* define if you have the addrinfo function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ADDRINFO
end_undef

begin_comment
comment|/* define if you need to include missing/addrinfoh.h. */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_ADDRINFO_H
end_undef

begin_comment
comment|/* define ifyou have the h_errno variable. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_ERRNO
end_undef

begin_comment
comment|/* define if IN6ADDRSZ is defined (XXX not used!) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_IN6ADDRSZ
end_undef

begin_comment
comment|/* define if INADDRSZ is defined (XXX not used!) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_INADDRSZ
end_undef

begin_comment
comment|/* define if this is a development version, to use additional prototypes. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OS_PROTO_H
end_undef

begin_comment
comment|/* define if<unistd.h> defines __P() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PORTABLE_PROTOTYPE
end_undef

begin_comment
comment|/* define if RES_USE_INET6 is defined */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_RES_USE_INET6
end_undef

begin_comment
comment|/* define if struct sockaddr has the sa_len member */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SOCKADDR_SA_LEN
end_undef

begin_comment
comment|/* define if you have struct sockaddr_storage */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SOCKADDR_STORAGE
end_undef

begin_comment
comment|/* define if you have both getipnodebyname() and getipnodebyaddr() */
end_comment

begin_undef
undef|#
directive|undef
name|USE_GETIPNODEBY
end_undef

begin_comment
comment|/* define if you have ether_ntohost() and it works */
end_comment

begin_undef
undef|#
directive|undef
name|USE_ETHER_NTOHOST
end_undef

begin_comment
comment|/* define if libpcap has pcap_version */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_VERSION
end_undef

begin_comment
comment|/* define if libpcap has pcap_debug */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_DEBUG
end_undef

begin_comment
comment|/* define if libpcap has yydebug */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_YYDEBUG
end_undef

begin_comment
comment|/* define if libpcap has pcap_list_datalinks() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_LIST_DATALINKS
end_undef

begin_comment
comment|/* define if libpcap has pcap_set_datalink() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_SET_DATALINK
end_undef

begin_comment
comment|/* define if libpcap has pcap_datalink_name_to_val() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_DATALINK_NAME_TO_VAL
end_undef

begin_comment
comment|/* define if libpcap has pcap_datalink_val_to_description() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_DATALINK_VAL_TO_DESCRIPTION
end_undef

begin_comment
comment|/* define if you have getrpcbynumber() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETRPCBYNUMBER
end_undef

begin_comment
comment|/* define if unaligned memory accesses fail */
end_comment

begin_undef
undef|#
directive|undef
name|LBL_ALIGN
end_undef

begin_comment
comment|/* The successful return value from signal (?)XXX */
end_comment

begin_undef
undef|#
directive|undef
name|RETSIGVAL
end_undef

begin_comment
comment|/* Define this on IRIX */
end_comment

begin_undef
undef|#
directive|undef
name|_BSD_SIGNALS
end_undef

begin_comment
comment|/* For HP/UX ANSI compiler? */
end_comment

begin_undef
undef|#
directive|undef
name|_HPUX_SOURCE
end_undef

begin_comment
comment|/* AIX hack. */
end_comment

begin_undef
undef|#
directive|undef
name|_SUN
end_undef

begin_comment
comment|/* Workaround for missing sized types */
end_comment

begin_comment
comment|/* XXX this should move to the more standard uint*_t */
end_comment

begin_undef
undef|#
directive|undef
name|int8_t
end_undef

begin_undef
undef|#
directive|undef
name|int16_t
end_undef

begin_undef
undef|#
directive|undef
name|int32_t
end_undef

begin_undef
undef|#
directive|undef
name|int64_t
end_undef

begin_undef
undef|#
directive|undef
name|u_int8_t
end_undef

begin_undef
undef|#
directive|undef
name|u_int16_t
end_undef

begin_undef
undef|#
directive|undef
name|u_int32_t
end_undef

begin_undef
undef|#
directive|undef
name|u_int64_t
end_undef

begin_comment
comment|/* Workaround for missing 64-bit formats */
end_comment

begin_undef
undef|#
directive|undef
name|PRId64
end_undef

begin_undef
undef|#
directive|undef
name|PRIo64
end_undef

begin_undef
undef|#
directive|undef
name|PRIx64
end_undef

begin_undef
undef|#
directive|undef
name|PRIu64
end_undef

begin_comment
comment|/* Whether or not to include the possibly-buggy SMB printer */
end_comment

begin_undef
undef|#
directive|undef
name|TCPDUMP_DO_SMB
end_undef

begin_comment
comment|/* Long story short: aclocal.m4 depends on autoconf 2.13  * implementation details wrt "const"; newer versions  * have different implementation details so for now we  * put "const" here.  This may cause duplicate definitions  * in config.h but that should be OK since they're the same.  */
end_comment

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_comment
comment|/* Define if you have the dnet_htoa function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_DNET_HTOA
end_undef

begin_comment
comment|/* Define if you have a dnet_htoa declaration in<netdnet/dnetdb.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_NETDNET_DNETDB_H_DNET_HTOA
end_undef

begin_comment
comment|/* define if should drop privileges by default */
end_comment

begin_undef
undef|#
directive|undef
name|WITH_USER
end_undef

begin_comment
comment|/* define if should chroot when dropping privileges */
end_comment

begin_undef
undef|#
directive|undef
name|WITH_CHROOT
end_undef

end_unit

