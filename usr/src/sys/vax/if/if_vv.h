begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_vv.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * ECO 176-748 changed the braodcast address from 0 to 0xff, at  * CTL (p1002) serial number around 150.  * It was implemented in August, 1982. This is a field-installable ECO,  * which improves net reliability. If the broadcast address has not been  * changed, comment out the following line.  */
end_comment

begin_define
define|#
directive|define
name|NEW_BROADCAST
end_define

begin_comment
comment|/* new chip for broadcast problem */
end_comment

begin_comment
comment|/*  * Local network header for proNET Ring  * This is arbitrated by "jas@proteon"  * (aka John Shriver, 617-655-3340)  */
end_comment

begin_struct
struct|struct
name|vv_header
block|{
comment|/* the first two fields are required by the hardware */
name|u_char
name|vh_dhost
decl_stmt|;
comment|/* destination address */
name|u_char
name|vh_shost
decl_stmt|;
comment|/* source address */
comment|/* the next three fields are the local network header */
name|u_char
name|vh_version
decl_stmt|;
comment|/* header version */
name|u_char
name|vh_type
decl_stmt|;
comment|/* packet type => protocol number */
name|short
name|vh_info
decl_stmt|;
comment|/* protocol-specific information */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RING_VERSION
value|2
end_define

begin_comment
comment|/* current version of v2lni header */
end_comment

begin_comment
comment|/*  * Packet types (protocol numbers) in proNET protocol header  * Other types are defined, but are proprietary.  */
end_comment

begin_define
define|#
directive|define
name|RING_IP
value|1
end_define

begin_define
define|#
directive|define
name|RING_TRAILER
value|2
end_define

begin_comment
comment|/* offset now in vh_info only */
end_comment

begin_define
define|#
directive|define
name|RING_ARP
value|3
end_define

begin_define
define|#
directive|define
name|RING_HDLC
value|4
end_define

begin_define
define|#
directive|define
name|RING_VAXDB
value|5
end_define

begin_define
define|#
directive|define
name|RING_RINGWAY
value|6
end_define

begin_define
define|#
directive|define
name|RING_RINGWAYM
value|8
end_define

begin_define
define|#
directive|define
name|RING_NOVELL
value|10
end_define

begin_define
define|#
directive|define
name|RING_PUP
value|12
end_define

begin_define
define|#
directive|define
name|RING_XNS
value|14
end_define

begin_define
define|#
directive|define
name|RING_DIAGNOSTICS
value|15
end_define

begin_comment
comment|/* protocol type for testing */
end_comment

begin_define
define|#
directive|define
name|RING_ECHO
value|16
end_define

begin_define
define|#
directive|define
name|RING_8022
value|23
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NEW_BROADCAST
end_ifdef

begin_define
define|#
directive|define
name|VV_BROADCAST
value|0xff
end_define

begin_comment
comment|/* hardware-defined broadcast address */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VV_BROADCAST
value|0x00
end_define

begin_comment
comment|/* hardware-defined broadcast address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Proteon proNET Hardware definitions  * register bit definitions  */
end_comment

begin_define
define|#
directive|define
name|VV_ENB
value|01
end_define

begin_comment
comment|/* Enable Operation */
end_comment

begin_define
define|#
directive|define
name|VV_DEN
value|02
end_define

begin_comment
comment|/* Enable DMA */
end_comment

begin_define
define|#
directive|define
name|VV_HEN
value|04
end_define

begin_comment
comment|/* Host Relay Enable (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_CPB
value|04
end_define

begin_comment
comment|/* Clear Packet Buffer (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_STE
value|010
end_define

begin_comment
comment|/* Self Test Enable (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_UT1
value|010
end_define

begin_comment
comment|/* Unused (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_LPB
value|020
end_define

begin_comment
comment|/* Modem Disable (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_INR
value|020
end_define

begin_comment
comment|/* Initialize Ring (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_RST
value|040
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|VV_IEN
value|0100
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|VV_RDY
value|0200
end_define

begin_comment
comment|/* Done */
end_comment

begin_define
define|#
directive|define
name|VV_DPR
value|0400
end_define

begin_comment
comment|/* Data Present (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_RFS
value|0400
end_define

begin_comment
comment|/* Refused (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_NXM
value|01000
end_define

begin_comment
comment|/* Non Existent Memory */
end_comment

begin_define
define|#
directive|define
name|VV_OVR
value|02000
end_define

begin_comment
comment|/* Overrun */
end_comment

begin_define
define|#
directive|define
name|VV_ODB
value|04000
end_define

begin_comment
comment|/* Odd Byte (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_UT2
value|04000
end_define

begin_comment
comment|/* Unused (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_LDE
value|010000
end_define

begin_comment
comment|/* Parity on 10 megabit (Rcv), */
end_comment

begin_comment
comment|/* Link Data Error on 80 megabit (Rcv) */
end_comment

begin_define
define|#
directive|define
name|VV_OPT
value|010000
end_define

begin_comment
comment|/* Output Timeout (Xmit) */
end_comment

begin_define
define|#
directive|define
name|VV_NOK
value|020000
end_define

begin_comment
comment|/* Ring Not OK */
end_comment

begin_define
define|#
directive|define
name|VV_BDF
value|040000
end_define

begin_comment
comment|/* Bad Format in Operation */
end_comment

begin_define
define|#
directive|define
name|VV_NIR
value|0100000
end_define

begin_comment
comment|/* Not in Ring */
end_comment

begin_define
define|#
directive|define
name|VVXERR
value|(VV_NXM|VV_OVR|VV_OPT|VV_BDF)
end_define

begin_comment
comment|/* Xmit errs */
end_comment

begin_define
define|#
directive|define
name|VVRERR
value|(VV_NXM|VV_OVR|VV_ODB|VV_BDF|VV_DPR)
end_define

begin_comment
comment|/* Rcv errs */
end_comment

begin_define
define|#
directive|define
name|VVFE
value|(VV_NXM|VV_OVR)
end_define

begin_comment
comment|/* Fatal errors */
end_comment

begin_define
define|#
directive|define
name|VV_IBITS
define|\
value|"\10\20NIR\17BDF\16NOK\15LDE\14ODB\13OVR\12NXM\11DPR\10RDY\7IEN\6RST\5LPB\4STE\3HEN\2DEN\1ENB"
end_define

begin_define
define|#
directive|define
name|VV_OBITS
define|\
value|"\10\20NIR\17BDF\16NOK\15OPT\13OVR\12NXM\11RFS\10RDY\7IEN\6RST\5INR\3HEN\2DEN\1ENB"
end_define

begin_comment
comment|/* device registers */
end_comment

begin_struct
struct|struct
name|vvreg
block|{
name|short
name|vvicsr
decl_stmt|;
comment|/* input csr */
name|u_short
name|vviwc
decl_stmt|;
comment|/* input word count */
name|u_short
name|vviba
decl_stmt|;
comment|/* input addr lo */
name|u_short
name|vviea
decl_stmt|;
comment|/* input addr hi */
name|short
name|vvocsr
decl_stmt|;
comment|/* output csr */
name|u_short
name|vvowc
decl_stmt|;
comment|/* output word count */
name|u_short
name|vvoba
decl_stmt|;
comment|/* output addr lo */
name|u_short
name|vvoea
decl_stmt|;
comment|/* output addr hi */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VVRETRY
value|7
end_define

begin_comment
comment|/* output retry limit */
end_comment

begin_define
define|#
directive|define
name|VVIDENTSUCC
value|5
end_define

begin_comment
comment|/* number of successes required in self-test */
end_comment

begin_define
define|#
directive|define
name|VVIDENTRETRY
value|10
end_define

begin_comment
comment|/* identify loop attempt limit */
end_comment

begin_define
define|#
directive|define
name|VVTIMEOUT
value|60
end_define

begin_comment
comment|/* seconds before a transmit timeout */
end_comment

end_unit

