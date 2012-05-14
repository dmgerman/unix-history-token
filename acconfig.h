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
comment|/* define if libpcap has pcap_dump_ftell() */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCAP_DUMP_FTELL
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

