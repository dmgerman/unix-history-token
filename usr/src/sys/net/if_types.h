begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_types.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Interface types for benefit of parsing media address headers.  * This list is derived from the SNMP list of ifTypes, currently  * documented in RFC1123.  */
end_comment

begin_define
define|#
directive|define
name|IFT_OTHER
value|0x1
end_define

begin_comment
comment|/* none of the following */
end_comment

begin_define
define|#
directive|define
name|IFT_1822
value|0x2
end_define

begin_comment
comment|/* old-style arpanet imp */
end_comment

begin_define
define|#
directive|define
name|IFT_HDH1822
value|0x3
end_define

begin_comment
comment|/* HDH arpanet imp */
end_comment

begin_define
define|#
directive|define
name|IFT_X25DDN
value|0x4
end_define

begin_comment
comment|/* x25 to imp */
end_comment

begin_define
define|#
directive|define
name|IFT_X25
value|0x5
end_define

begin_comment
comment|/* PDN X25 interface (RFC877) */
end_comment

begin_define
define|#
directive|define
name|IFT_ETHER
value|0x6
end_define

begin_comment
comment|/* Ethernet CSMACD */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88023
value|0x7
end_define

begin_comment
comment|/* CMSA CD */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88024
value|0x8
end_define

begin_comment
comment|/* Token Bus */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88025
value|0x9
end_define

begin_comment
comment|/* Token Ring */
end_comment

begin_define
define|#
directive|define
name|IFT_ISO88026
value|0xa
end_define

begin_comment
comment|/* MAN */
end_comment

begin_define
define|#
directive|define
name|IFT_STARLAN
value|0xb
end_define

begin_define
define|#
directive|define
name|IFT_P10
value|0xc
end_define

begin_comment
comment|/* Proteon 10MBit ring */
end_comment

begin_define
define|#
directive|define
name|IFT_P80
value|0xd
end_define

begin_comment
comment|/* Proteon 10MBit ring */
end_comment

begin_define
define|#
directive|define
name|IFT_HY
value|0xe
end_define

begin_comment
comment|/* Hyperchannel */
end_comment

begin_define
define|#
directive|define
name|IFT_FDDI
value|0xf
end_define

begin_define
define|#
directive|define
name|IFT_LAPB
value|0x10
end_define

begin_define
define|#
directive|define
name|IFT_SDLC
value|0x11
end_define

begin_define
define|#
directive|define
name|IFT_T1
value|0x12
end_define

begin_define
define|#
directive|define
name|IFT_CEPT
value|0x13
end_define

begin_comment
comment|/* E1 - european T1 */
end_comment

begin_define
define|#
directive|define
name|IFT_ISDNBASIC
value|0x14
end_define

begin_define
define|#
directive|define
name|IFT_ISDNPRIMARY
value|0x15
end_define

begin_define
define|#
directive|define
name|IFT_PTPSERIAL
value|0x16
end_define

begin_comment
comment|/* Proprietary PTP serial */
end_comment

begin_define
define|#
directive|define
name|IFT_PPP
value|0x17
end_define

begin_comment
comment|/* RFC 1331 */
end_comment

begin_define
define|#
directive|define
name|IFT_LOOP
value|0x18
end_define

begin_comment
comment|/* loopback */
end_comment

begin_define
define|#
directive|define
name|IFT_EON
value|0x19
end_define

begin_comment
comment|/* ISO over IP */
end_comment

begin_define
define|#
directive|define
name|IFT_XETHER
value|0x1a
end_define

begin_comment
comment|/* obsolete 3MB experimental ethernet */
end_comment

begin_define
define|#
directive|define
name|IFT_NSIP
value|0x1b
end_define

begin_comment
comment|/* XNS over IP */
end_comment

begin_define
define|#
directive|define
name|IFT_SLIP
value|0x1c
end_define

begin_comment
comment|/* IP over generic TTY */
end_comment

begin_define
define|#
directive|define
name|IFT_ULTRA
value|0x1d
end_define

begin_comment
comment|/* Ultra Technologies */
end_comment

begin_define
define|#
directive|define
name|IFT_DS3
value|0x1e
end_define

begin_comment
comment|/* Generic T3 */
end_comment

begin_define
define|#
directive|define
name|IFT_SIP
value|0x1f
end_define

begin_comment
comment|/* SMDS */
end_comment

begin_define
define|#
directive|define
name|IFT_FRELAY
value|0x20
end_define

begin_comment
comment|/* Frame Relay */
end_comment

begin_define
define|#
directive|define
name|IFT_RS232
value|0x21
end_define

begin_comment
comment|/* Used elsewhere by SNMP as index */
end_comment

end_unit

