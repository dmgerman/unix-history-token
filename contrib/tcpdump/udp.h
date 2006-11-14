begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/udp.h,v 1.8 2005/04/06 21:33:28 mcr Exp $ (LBL) */
end_comment

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
name|u_int16_t
name|uh_sport
decl_stmt|;
comment|/* source port */
name|u_int16_t
name|uh_dport
decl_stmt|;
comment|/* destination port */
name|u_int16_t
name|uh_ulen
decl_stmt|;
comment|/* udp length */
name|u_int16_t
name|uh_sum
decl_stmt|;
comment|/* udp checksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TFTP_PORT
value|69
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|KERBEROS_PORT
value|88
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|SUNRPC_PORT
value|111
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|SNMP_PORT
value|161
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|NTP_PORT
value|123
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|SNMPTRAP_PORT
value|162
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|ISAKMP_PORT
value|500
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|SYSLOG_PORT
value|514
end_define

begin_comment
comment|/* rfc3164 */
end_comment

begin_define
define|#
directive|define
name|TIMED_PORT
value|525
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|RIP_PORT
value|520
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|LDP_PORT
value|646
end_define

begin_define
define|#
directive|define
name|AODV_PORT
value|654
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|KERBEROS_SEC_PORT
value|750
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|L2TP_PORT
value|1701
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|SIP_PORT
value|5060
end_define

begin_define
define|#
directive|define
name|ISAKMP_PORT_NATT
value|4500
end_define

begin_comment
comment|/* rfc3948 */
end_comment

begin_define
define|#
directive|define
name|ISAKMP_PORT_USER1
value|7500
end_define

begin_comment
comment|/*XXX - nonstandard*/
end_comment

begin_define
define|#
directive|define
name|ISAKMP_PORT_USER2
value|8500
end_define

begin_comment
comment|/*XXX - nonstandard*/
end_comment

begin_define
define|#
directive|define
name|RX_PORT_LOW
value|7000
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|RX_PORT_HIGH
value|7009
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|NETBIOS_NS_PORT
value|137
end_define

begin_define
define|#
directive|define
name|NETBIOS_DGRAM_PORT
value|138
end_define

begin_define
define|#
directive|define
name|CISCO_AUTORP_PORT
value|496
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|RADIUS_PORT
value|1645
end_define

begin_define
define|#
directive|define
name|RADIUS_NEW_PORT
value|1812
end_define

begin_define
define|#
directive|define
name|RADIUS_ACCOUNTING_PORT
value|1646
end_define

begin_define
define|#
directive|define
name|RADIUS_NEW_ACCOUNTING_PORT
value|1813
end_define

begin_define
define|#
directive|define
name|HSRP_PORT
value|1985
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|LWRES_PORT
value|921
end_define

begin_define
define|#
directive|define
name|ZEPHYR_SRV_PORT
value|2103
end_define

begin_define
define|#
directive|define
name|ZEPHYR_CLT_PORT
value|2104
end_define

begin_define
define|#
directive|define
name|MPLS_LSP_PING_PORT
value|3503
end_define

begin_comment
comment|/* draft-ietf-mpls-lsp-ping-02.txt */
end_comment

begin_define
define|#
directive|define
name|BFD_CONTROL_PORT
value|3784
end_define

begin_comment
comment|/* draft-katz-ward-bfd-v4v6-1hop-00.txt */
end_comment

begin_define
define|#
directive|define
name|BFD_ECHO_PORT
value|3785
end_define

begin_comment
comment|/* draft-katz-ward-bfd-v4v6-1hop-00.txt */
end_comment

begin_define
define|#
directive|define
name|LMP_PORT
value|49998
end_define

begin_comment
comment|/* unofficial - no IANA assignment yet */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|RIPNG_PORT
value|521
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|DHCP6_SERV_PORT
value|546
end_define

begin_comment
comment|/*XXX*/
end_comment

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

end_unit

