begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/libpcap/ppp.h,v 1.8 1999/10/19 15:18:31 itojun Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Point to Point Protocol (PPP) RFC1331  *  * Copyright 1989 by Carnegie Mellon.  *  * Permission to use, copy, modify, and distribute this program for any  * purpose and without fee is hereby granted, provided that this copyright  * and permission notice appear on all copies and supporting documentation,  * the name of Carnegie Mellon not be used in advertising or publicity  * pertaining to distribution of the program without specific prior  * permission, and notice be given in supporting documentation that copying  * and distribution is by permission of Carnegie Mellon and Stanford  * University.  Carnegie Mellon makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_define
define|#
directive|define
name|PPP_ADDRESS
value|0xff
end_define

begin_comment
comment|/* The address byte value */
end_comment

begin_define
define|#
directive|define
name|PPP_CONTROL
value|0x03
end_define

begin_comment
comment|/* The control byte value */
end_comment

begin_comment
comment|/* Protocol numbers */
end_comment

begin_define
define|#
directive|define
name|PPP_IP
value|0x0021
end_define

begin_comment
comment|/* Raw IP */
end_comment

begin_define
define|#
directive|define
name|PPP_OSI
value|0x0023
end_define

begin_comment
comment|/* OSI Network Layer */
end_comment

begin_define
define|#
directive|define
name|PPP_NS
value|0x0025
end_define

begin_comment
comment|/* Xerox NS IDP */
end_comment

begin_define
define|#
directive|define
name|PPP_DECNET
value|0x0027
end_define

begin_comment
comment|/* DECnet Phase IV */
end_comment

begin_define
define|#
directive|define
name|PPP_APPLE
value|0x0029
end_define

begin_comment
comment|/* Appletalk */
end_comment

begin_define
define|#
directive|define
name|PPP_IPX
value|0x002b
end_define

begin_comment
comment|/* Novell IPX */
end_comment

begin_define
define|#
directive|define
name|PPP_VJC
value|0x002d
end_define

begin_comment
comment|/* Van Jacobson Compressed TCP/IP */
end_comment

begin_define
define|#
directive|define
name|PPP_VJNC
value|0x002f
end_define

begin_comment
comment|/* Van Jacobson Uncompressed TCP/IP */
end_comment

begin_define
define|#
directive|define
name|PPP_BRPDU
value|0x0031
end_define

begin_comment
comment|/* Bridging PDU */
end_comment

begin_define
define|#
directive|define
name|PPP_STII
value|0x0033
end_define

begin_comment
comment|/* Stream Protocol (ST-II) */
end_comment

begin_define
define|#
directive|define
name|PPP_VINES
value|0x0035
end_define

begin_comment
comment|/* Banyan Vines */
end_comment

begin_define
define|#
directive|define
name|PPP_IPV6
value|0x0057
end_define

begin_comment
comment|/* Internet Protocol version 6 */
end_comment

begin_define
define|#
directive|define
name|PPP_HELLO
value|0x0201
end_define

begin_comment
comment|/* 802.1d Hello Packets */
end_comment

begin_define
define|#
directive|define
name|PPP_LUXCOM
value|0x0231
end_define

begin_comment
comment|/* Luxcom */
end_comment

begin_define
define|#
directive|define
name|PPP_SNS
value|0x0233
end_define

begin_comment
comment|/* Sigma Network Systems */
end_comment

begin_define
define|#
directive|define
name|PPP_IPCP
value|0x8021
end_define

begin_comment
comment|/* IP Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_OSICP
value|0x8023
end_define

begin_comment
comment|/* OSI Network Layer Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_NSCP
value|0x8025
end_define

begin_comment
comment|/* Xerox NS IDP Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_DECNETCP
value|0x8027
end_define

begin_comment
comment|/* DECnet Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_APPLECP
value|0x8029
end_define

begin_comment
comment|/* Appletalk Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_IPXCP
value|0x802b
end_define

begin_comment
comment|/* Novell IPX Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_STIICP
value|0x8033
end_define

begin_comment
comment|/* Strean Protocol Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_VINESCP
value|0x8035
end_define

begin_comment
comment|/* Banyan Vines Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_IPV6CP
value|0x8057
end_define

begin_comment
comment|/* IPv6 Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_LCP
value|0xc021
end_define

begin_comment
comment|/* Link Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_PAP
value|0xc023
end_define

begin_comment
comment|/* Password Authentication Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_LQM
value|0xc025
end_define

begin_comment
comment|/* Link Quality Monitoring */
end_comment

begin_define
define|#
directive|define
name|PPP_CHAP
value|0xc223
end_define

begin_comment
comment|/* Challenge Handshake Authentication Protocol */
end_comment

end_unit

