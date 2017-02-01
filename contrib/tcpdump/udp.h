begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)udp.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Udp protocol header.  * Per RFC 768, September, 1981.  */
end_comment

begin_struct
struct|struct
name|udphdr
block|{
name|uint16_t
name|uh_sport
decl_stmt|;
comment|/* source port */
name|uint16_t
name|uh_dport
decl_stmt|;
comment|/* destination port */
name|uint16_t
name|uh_ulen
decl_stmt|;
comment|/* udp length */
name|uint16_t
name|uh_sum
decl_stmt|;
comment|/* udp checksum */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NAMESERVER_PORT
end_ifndef

begin_define
define|#
directive|define
name|NAMESERVER_PORT
value|53
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TACACS_DB_PORT
end_ifndef

begin_define
define|#
directive|define
name|TACACS_DB_PORT
value|65
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ORACLE_SQLNET_PORT
end_ifndef

begin_define
define|#
directive|define
name|ORACLE_SQLNET_PORT
value|66
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BOOTPS_PORT
end_ifndef

begin_define
define|#
directive|define
name|BOOTPS_PORT
value|67
end_define

begin_comment
comment|/* RFC951 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BOOTPC_PORT
end_ifndef

begin_define
define|#
directive|define
name|BOOTPC_PORT
value|68
end_define

begin_comment
comment|/* RFC951 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TFTP_PORT
end_ifndef

begin_define
define|#
directive|define
name|TFTP_PORT
value|69
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS_PORT
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS_PORT
value|88
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUNRPC_PORT
end_ifndef

begin_define
define|#
directive|define
name|SUNRPC_PORT
value|111
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_PORT
end_ifndef

begin_define
define|#
directive|define
name|NTP_PORT
value|123
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NETBIOS_NS_PORT
end_ifndef

begin_define
define|#
directive|define
name|NETBIOS_NS_PORT
value|137
end_define

begin_comment
comment|/* RFC 1001, RFC 1002 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NETBIOS_DGRAM_PORT
end_ifndef

begin_define
define|#
directive|define
name|NETBIOS_DGRAM_PORT
value|138
end_define

begin_comment
comment|/* RFC 1001, RFC 1002 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NETBIOS_SSN_PORT
end_ifndef

begin_define
define|#
directive|define
name|NETBIOS_SSN_PORT
value|139
end_define

begin_comment
comment|/* RFC 1001, RFC 1002 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SNMP_PORT
end_ifndef

begin_define
define|#
directive|define
name|SNMP_PORT
value|161
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SNMPTRAP_PORT
end_ifndef

begin_define
define|#
directive|define
name|SNMPTRAP_PORT
value|162
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BGP_PORT
end_ifndef

begin_define
define|#
directive|define
name|BGP_PORT
value|179
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|APPLETALK_RTMP_PORT
end_ifndef

begin_define
define|#
directive|define
name|APPLETALK_RTMP_PORT
value|201
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|APPLETALK_NB_PORT
end_ifndef

begin_define
define|#
directive|define
name|APPLETALK_NB_PORT
value|202
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|APPLETALK_ECHO
end_ifndef

begin_define
define|#
directive|define
name|APPLETALK_ECHO
value|204
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|APPLETALK_ZONE_INFO_PORT
end_ifndef

begin_define
define|#
directive|define
name|APPLETALK_ZONE_INFO_PORT
value|206
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDAP_PORT
end_ifndef

begin_define
define|#
directive|define
name|LDAP_PORT
value|389
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HTTPS_PORT
end_ifndef

begin_define
define|#
directive|define
name|HTTPS_PORT
value|443
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MICROSOFT_DS_PORT
end_ifndef

begin_define
define|#
directive|define
name|MICROSOFT_DS_PORT
value|445
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS5_PASSWD_PORT
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS5_PASSWD_PORT
value|464
end_define

begin_comment
comment|/* PER IANA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CISCO_AUTORP_PORT
end_ifndef

begin_define
define|#
directive|define
name|CISCO_AUTORP_PORT
value|496
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISAKMP_PORT
end_ifndef

begin_define
define|#
directive|define
name|ISAKMP_PORT
value|500
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_PORT
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_PORT
value|514
end_define

begin_comment
comment|/* rfc3164 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RIP_PORT
end_ifndef

begin_define
define|#
directive|define
name|RIP_PORT
value|520
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RIPNG_PORT
end_ifndef

begin_define
define|#
directive|define
name|RIPNG_PORT
value|521
end_define

begin_comment
comment|/* RFC 2080 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMED_PORT
end_ifndef

begin_define
define|#
directive|define
name|TIMED_PORT
value|525
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS_LOGIN_PORT
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS_LOGIN_PORT
value|543
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS_SHELL_PORT
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS_SHELL_PORT
value|544
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DHCP6_SERV_PORT
end_ifndef

begin_define
define|#
directive|define
name|DHCP6_SERV_PORT
value|546
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DHCP6_CLI_PORT
end_ifndef

begin_define
define|#
directive|define
name|DHCP6_CLI_PORT
value|547
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDAPS_PORT
end_ifndef

begin_define
define|#
directive|define
name|LDAPS_PORT
value|636
end_define

begin_comment
comment|/*XXX - LDAP over TLS/SSL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LDP_PORT
end_ifndef

begin_define
define|#
directive|define
name|LDP_PORT
value|646
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DHCP_FAILOVER_PORT
end_ifndef

begin_define
define|#
directive|define
name|DHCP_FAILOVER_PORT
value|647
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AQDV_PORT
end_ifndef

begin_define
define|#
directive|define
name|AODV_PORT
value|654
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OLSR_PORT
end_ifndef

begin_define
define|#
directive|define
name|OLSR_PORT
value|698
end_define

begin_comment
comment|/* rfc3626 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LMP_PORT
end_ifndef

begin_define
define|#
directive|define
name|LMP_PORT
value|701
end_define

begin_comment
comment|/* rfc4204 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CISCO_TDP_PORT
end_ifndef

begin_define
define|#
directive|define
name|CISCO_TDP_PORT
value|711
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS_ADM_PORT
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS_ADM_PORT
value|749
end_define

begin_comment
comment|/*XXX - Kerberos v5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERBEROS_SEC_PORT
end_ifndef

begin_define
define|#
directive|define
name|KERBEROS_SEC_PORT
value|750
end_define

begin_comment
comment|/*XXX - Kerberos v4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RSYNC_PORT
end_ifndef

begin_define
define|#
directive|define
name|RSYNC_PORT
value|873
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_PORT
end_ifndef

begin_define
define|#
directive|define
name|LWRES_PORT
value|921
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_PORT
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_PORT
value|1194
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOTUS_NOTES_PORT
end_ifndef

begin_define
define|#
directive|define
name|LOTUS_NOTES_PORT
value|1352
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MS_SQL_SERVER_PORT
end_ifndef

begin_define
define|#
directive|define
name|MS_SQL_SERVER_PORT
value|1433
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MS_SQL_SERVER_MONITOR
end_ifndef

begin_define
define|#
directive|define
name|MS_SQL_SERVER_MONITOR
value|1434
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INGRESLOCK_PORT
end_ifndef

begin_define
define|#
directive|define
name|INGRESLOCK_PORT
value|1524
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VQP_PORT
end_ifndef

begin_define
define|#
directive|define
name|VQP_PORT
value|1589
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_PORT
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_PORT
value|1645
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_ACCOUNTING_PORT
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_ACCOUNTING_PORT
value|1646
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_CISCO_COA_PORT
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_CISCO_COA_PORT
value|1700
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|L2TP_PORT
end_ifndef

begin_define
define|#
directive|define
name|L2TP_PORT
value|1701
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_NEW_PORT
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_NEW_PORT
value|1812
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_NEW_ACCOUNTING_PORT
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_NEW_ACCOUNTING_PORT
value|1813
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HSRP_PORT
end_ifndef

begin_define
define|#
directive|define
name|HSRP_PORT
value|1985
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_DAEMON_PORT
end_ifndef

begin_define
define|#
directive|define
name|NFS_DAEMON_PORT
value|2049
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZEPHYR_SRV_PORT
end_ifndef

begin_define
define|#
directive|define
name|ZEPHYR_SRV_PORT
value|2103
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ZEPHYR_CLI_PORT
end_ifndef

begin_define
define|#
directive|define
name|ZEPHYR_CLT_PORT
value|2104
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MYSQL_PORT
end_ifndef

begin_define
define|#
directive|define
name|MYSQL_PORT
value|3306
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MS_RDP_PORT
end_ifndef

begin_define
define|#
directive|define
name|MS_RDP_PORT
value|3389
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VAT_PORT
end_ifndef

begin_define
define|#
directive|define
name|VAT_PORT
value|3456
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MPLS_LSP_PING_PORT
end_ifndef

begin_define
define|#
directive|define
name|MPLS_LSP_PING_PORT
value|3503
end_define

begin_comment
comment|/* draft-ietf-mpls-lsp-ping-02.txt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBVERSION_PORT
end_ifndef

begin_define
define|#
directive|define
name|SUBVERSION_PORT
value|3690
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_CONTROL_PORT
end_ifndef

begin_define
define|#
directive|define
name|BFD_CONTROL_PORT
value|3784
end_define

begin_comment
comment|/* RFC 5881 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ECHO_PORT
end_ifndef

begin_define
define|#
directive|define
name|BFD_ECHO_PORT
value|3785
end_define

begin_comment
comment|/* RFC 5881 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RADIUS_COA_PORT
end_ifndef

begin_define
define|#
directive|define
name|RADIUS_COA_PORT
value|3799
end_define

begin_comment
comment|/* RFC 5176 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_LOCK_DAEMON_PORT
end_ifndef

begin_define
define|#
directive|define
name|NFS_LOCK_DAEMON_PORT
value|4045
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LISP_CONTROL_PORT
end_ifndef

begin_define
define|#
directive|define
name|LISP_CONTROL_PORT
value|4342
end_define

begin_comment
comment|/* RFC 6830 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISAKMP_PORT_NATT
end_ifndef

begin_define
define|#
directive|define
name|ISAKMP_PORT_NATT
value|4500
end_define

begin_comment
comment|/* rfc3948 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WB_PORT
end_ifndef

begin_define
define|#
directive|define
name|WB_PORT
value|4567
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VXLAN_PORT
end_ifndef

begin_define
define|#
directive|define
name|VXLAN_PORT
value|4789
end_define

begin_comment
comment|/* RFC 7348 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VXLAN_GPE_PORT
end_ifndef

begin_define
define|#
directive|define
name|VXLAN_GPE_PORT
value|4790
end_define

begin_comment
comment|/* draft-ietf-nvo3-vxlan-gpe-01 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIP_DS_PORT
end_ifndef

begin_define
define|#
directive|define
name|SIP_DS_PORT
value|5059
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIP_PORT
end_ifndef

begin_define
define|#
directive|define
name|SIP_PORT
value|5060
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MULTICASTDNS_PORT
end_ifndef

begin_define
define|#
directive|define
name|MULTICASTDNS_PORT
value|5353
end_define

begin_comment
comment|/* RFC 6762 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AHCP_PORT
end_ifndef

begin_define
define|#
directive|define
name|AHCP_PORT
value|5359
end_define

begin_comment
comment|/* draft-chroboczek-ahcp-00 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GENEVE_PORT
end_ifndef

begin_define
define|#
directive|define
name|GENEVE_PORT
value|6081
end_define

begin_comment
comment|/* draft-gross-geneve-02 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SFLOW_PORT
end_ifndef

begin_define
define|#
directive|define
name|SFLOW_PORT
value|6343
end_define

begin_comment
comment|/* http://www.sflow.org/developers/specifications.php */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BABEL_PORT
end_ifndef

begin_define
define|#
directive|define
name|BABEL_PORT
value|6696
end_define

begin_comment
comment|/* RFC 6126 errata */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BABEL_PORT_OLD
end_ifndef

begin_define
define|#
directive|define
name|BABEL_PORT_OLD
value|6697
end_define

begin_comment
comment|/* RFC 6126 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RX_PORT_LOW
end_ifndef

begin_define
define|#
directive|define
name|RX_PORT_LOW
value|7000
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RX_PORT_HIGH
end_ifndef

begin_define
define|#
directive|define
name|RX_PORT_HIGH
value|7009
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISAKMP_PORT_USER1
end_ifndef

begin_define
define|#
directive|define
name|ISAKMP_PORT_USER1
value|7500
end_define

begin_comment
comment|/*XXX - nonstandard*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HNCP_PORT
end_ifndef

begin_define
define|#
directive|define
name|HNCP_PORT
value|8231
end_define

begin_comment
comment|/* RFC 7788 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OTV_PORT
end_ifndef

begin_define
define|#
directive|define
name|OTV_PORT
value|8472
end_define

begin_comment
comment|/* draft-hasmit-otv-04 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISAKMP_PORT_USER2
end_ifndef

begin_define
define|#
directive|define
name|ISAKMP_PORT_USER2
value|8500
end_define

begin_comment
comment|/*XXX - nonstandard*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LWAPP_DATA_PORT
end_ifndef

begin_define
define|#
directive|define
name|LWAPP_DATA_PORT
value|12222
end_define

begin_comment
comment|/* RFC 5412 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LWAPP_CONTROL_PORT
end_ifndef

begin_define
define|#
directive|define
name|LWAPP_CONTROL_PORT
value|12223
end_define

begin_comment
comment|/* RFC 5412 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

