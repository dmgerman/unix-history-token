begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1992 The University of Utah and the Center  *	for Software Science (CSS).  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Center for Software Science of the University of Utah Computer  * Science Department.  CSS requests users of this software to return  * to css-dist@cs.utah.edu any improvements that they make and grant  * CSS redistribution rights.  *  * %sccs.include.redist.c%  *  *	@(#)rmp.h	8.1 (Berkeley) %G%  *  * Utah $Hdr: rmp.h 3.1 92/07/06$  * Author: Jeff Forys, University of Utah CSS  */
end_comment

begin_comment
comment|/*  *  Define MIN/MAX sizes of RMP (ethernet) packet.  *  For ease of computation, the 4 octet CRC field is not included.  *  *  MCLBYTES is for bpfwrite(); it is adamant about using a cluster.  */
end_comment

begin_define
define|#
directive|define
name|RMP_MAX_PACKET
value|MIN(1514,MCLBYTES)
end_define

begin_define
define|#
directive|define
name|RMP_MIN_PACKET
value|60
end_define

begin_comment
comment|/*  *  Define RMP/Ethernet Multicast address (9:0:9:0:0:4) and its length.  */
end_comment

begin_define
define|#
directive|define
name|RMP_ADDR
value|{ 0x9, 0x0, 0x9, 0x0, 0x0, 0x4 }
end_define

begin_define
define|#
directive|define
name|RMP_ADDRLEN
value|6
end_define

begin_comment
comment|/*  *  Define IEEE802.2 (Logical Link Control) information.  */
end_comment

begin_define
define|#
directive|define
name|IEEE_DSAP_HP
value|0xF8
end_define

begin_comment
comment|/* Destination Service Access Point */
end_comment

begin_define
define|#
directive|define
name|IEEE_SSAP_HP
value|0xF8
end_define

begin_comment
comment|/* Source Service Access Point */
end_comment

begin_define
define|#
directive|define
name|IEEE_CNTL_HP
value|0x0300
end_define

begin_comment
comment|/* Type 1 / I format control information */
end_comment

begin_define
define|#
directive|define
name|HPEXT_DXSAP
value|0x608
end_define

begin_comment
comment|/* HP Destination Service Access Point */
end_comment

begin_define
define|#
directive|define
name|HPEXT_SXSAP
value|0x609
end_define

begin_comment
comment|/* HP Source Service Access Point */
end_comment

begin_comment
comment|/*  *  802.3-style "Ethernet" header.  */
end_comment

begin_struct
struct|struct
name|hp_hdr
block|{
name|u_char
name|daddr
index|[
name|RMP_ADDRLEN
index|]
decl_stmt|;
name|u_char
name|saddr
index|[
name|RMP_ADDRLEN
index|]
decl_stmt|;
name|u_short
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * HP uses 802.2 LLC with their own local extensions.  This struct makes  * sence out of this data (encapsulated in the above 802.3 packet).  */
end_comment

begin_struct
struct|struct
name|hp_llc
block|{
name|u_char
name|dsap
decl_stmt|;
comment|/* 802.2 DSAP */
name|u_char
name|ssap
decl_stmt|;
comment|/* 802.2 SSAP */
name|u_short
name|cntrl
decl_stmt|;
comment|/* 802.2 control field */
name|u_short
name|filler
decl_stmt|;
comment|/* HP filler (must be zero) */
name|u_short
name|dxsap
decl_stmt|;
comment|/* HP extended DSAP */
name|u_short
name|sxsap
decl_stmt|;
comment|/* HP extended SSAP */
block|}
struct|;
end_struct

end_unit

