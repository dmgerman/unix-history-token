begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rmp.h 1.3 89/06/07$  *  *	@(#)rmp.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  Define MIN/MAX sizes of RMP (ethernet) packet.  For ease of computation,  *  the 4 octet CRC field is not included.  */
end_comment

begin_define
define|#
directive|define
name|RMP_MAX_PACKET
value|1514
end_define

begin_define
define|#
directive|define
name|RMP_MIN_PACKET
value|60
end_define

begin_comment
comment|/*  *  Define IEEE802.2 (Logical Link Control) information.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IEEE
value|0
end_define

begin_comment
comment|/* hack hack hack */
end_comment

begin_define
define|#
directive|define
name|IEEE802LEN_MIN
value|40
end_define

begin_define
define|#
directive|define
name|IEEE802LEN_MAX
value|1500
end_define

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
comment|/*  * HP uses 802.2 LLC with their own local extensions.  This struct makes  * sence out of this data (encapsulated in the 802.3 packet).  */
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

begin_comment
comment|/*  * Protocol(s)  */
end_comment

begin_define
define|#
directive|define
name|RMPPROTO_BOOT
value|1
end_define

begin_comment
comment|/* RMP boot protocol */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&
name|defined
argument_list|(
name|RMP
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|rmpdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|rmpsw
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

