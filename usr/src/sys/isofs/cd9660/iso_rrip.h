begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Pace Willisson (pace@blitz.com).  The Rock Ridge Extension  * Support code is derived from software contributed to Berkeley  * by Atsushi Murai (amurai@spec.co.jp).  *  * %sccs.include.redist.c%  *  *	@(#)iso_rrip.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Analyze function flag (similar to RR field bits)  */
end_comment

begin_define
define|#
directive|define
name|ISO_SUSP_ATTR
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_DEVICE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_SLINK
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_ALTNAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_CLINK
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_PLINK
value|0x0020
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_RELDIR
value|0x0040
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_TSTAMP
value|0x0080
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_IDFLAG
value|0x0100
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_EXTREF
value|0x0200
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_CONT
value|0x0400
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_OFFSET
value|0x0800
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_STOP
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISO_SUSP_UNKNOWN
value|0x8000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|iso_node
modifier|*
name|inop
decl_stmt|;
name|int
name|fields
decl_stmt|;
comment|/* interesting fields in this analysis */
name|daddr_t
name|iso_ce_blk
decl_stmt|;
comment|/* block of continuation area */
name|off_t
name|iso_ce_off
decl_stmt|;
comment|/* offset of continuation area */
name|int
name|iso_ce_len
decl_stmt|;
comment|/* length of continuation area */
name|struct
name|iso_mnt
modifier|*
name|imp
decl_stmt|;
comment|/* mount structure */
name|ino_t
modifier|*
name|inump
decl_stmt|;
comment|/* inode number pointer */
name|char
modifier|*
name|outbuf
decl_stmt|;
comment|/* name/symbolic link output area */
name|u_short
modifier|*
name|outlen
decl_stmt|;
comment|/* length of above */
name|u_short
name|maxlen
decl_stmt|;
comment|/* maximum length of above */
name|int
name|cont
decl_stmt|;
comment|/* continuation of above */
block|}
name|ISO_RRIP_ANALYZE
typedef|;
end_typedef

begin_decl_stmt
name|int
name|cd9660_rrip_analyze
name|__P
argument_list|(
operator|(
expr|struct
name|iso_directory_record
operator|*
name|isodir
operator|,
expr|struct
name|iso_node
operator|*
name|inop
operator|,
expr|struct
name|iso_mnt
operator|*
name|imp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_rrip_getname
name|__P
argument_list|(
operator|(
expr|struct
name|iso_directory_record
operator|*
name|isodir
operator|,
name|char
operator|*
name|outbuf
operator|,
name|u_short
operator|*
name|outlen
operator|,
name|ino_t
operator|*
name|inump
operator|,
expr|struct
name|iso_mnt
operator|*
name|imp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_rrip_getsymname
name|__P
argument_list|(
operator|(
expr|struct
name|iso_directory_record
operator|*
name|isodir
operator|,
name|char
operator|*
name|outbuf
operator|,
name|u_short
operator|*
name|outlen
operator|,
expr|struct
name|iso_mnt
operator|*
name|imp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_rrip_offset
name|__P
argument_list|(
operator|(
expr|struct
name|iso_directory_record
operator|*
name|isodir
operator|,
expr|struct
name|iso_mnt
operator|*
name|imp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

