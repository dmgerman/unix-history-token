begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)sun_disklabel.h	7.3 (Berkeley) %G%  *  * from: $Header: sun_disklabel.h,v 1.4 92/06/17 07:04:13 torek Exp $  */
end_comment

begin_comment
comment|/*  * SunOS disk label layout (only relevant portions discovered here).  */
end_comment

begin_define
define|#
directive|define
name|SUN_DKMAGIC
value|55998
end_define

begin_comment
comment|/* These are the guys that Sun's dkinfo needs... */
end_comment

begin_define
define|#
directive|define
name|DKIOCGGEOM
value|_IOR('d', 2, struct sun_dkgeom)
end_define

begin_comment
comment|/* geometry info */
end_comment

begin_define
define|#
directive|define
name|DKIOCINFO
value|_IOR('d', 8, struct sun_dkctlr)
end_define

begin_comment
comment|/* controller info */
end_comment

begin_define
define|#
directive|define
name|DKIOCGPART
value|_IOR('d', 4, struct sun_dkpart)
end_define

begin_comment
comment|/* partition info */
end_comment

begin_comment
comment|/* geometry info */
end_comment

begin_struct
struct|struct
name|sun_dkgeom
block|{
name|u_short
name|sdkc_ncylinders
decl_stmt|;
comment|/* data cylinders */
name|u_short
name|sdkc_acylinders
decl_stmt|;
comment|/* alternate cylinders */
name|u_short
name|sdkc_xxx1
decl_stmt|;
name|u_short
name|sdkc_ntracks
decl_stmt|;
comment|/* tracks per cylinder */
name|u_short
name|sdkc_xxx2
decl_stmt|;
name|u_short
name|sdkc_nsectors
decl_stmt|;
comment|/* sectors per track */
name|u_short
name|sdkc_interleave
decl_stmt|;
comment|/* interleave factor */
name|u_short
name|sdkc_xxx3
decl_stmt|;
name|u_short
name|sdkc_xxx4
decl_stmt|;
name|u_short
name|sdkc_sparespercyl
decl_stmt|;
comment|/* spare sectors per cylinder */
name|u_short
name|sdkc_rpm
decl_stmt|;
comment|/* rotational speed */
name|u_short
name|sdkc_pcylinders
decl_stmt|;
comment|/* physical cylinders */
name|u_short
name|sdkc_xxx5
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* controller info */
end_comment

begin_struct
struct|struct
name|sun_dkctlr
block|{
name|int
name|sdkc_addr
decl_stmt|;
comment|/* controller address */
name|short
name|sdkc_unit
decl_stmt|;
comment|/* unit (slave) address */
name|short
name|sdkc_type
decl_stmt|;
comment|/* controller type */
name|short
name|sdkc_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/* partition info */
end_comment

begin_struct
struct|struct
name|sun_dkpart
block|{
name|long
name|sdkp_cyloffset
decl_stmt|;
comment|/* starting cylinder */
name|long
name|sdkp_nsectors
decl_stmt|;
comment|/* number of sectors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sun_disklabel
block|{
comment|/* total size = 512 bytes */
name|char
name|sl_text
index|[
literal|128
index|]
decl_stmt|;
name|char
name|sl_xxx1
index|[
literal|292
index|]
decl_stmt|;
name|u_short
name|sl_rpm
decl_stmt|;
comment|/* rotational speed */
name|char
name|sl_xxx2
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|sl_sparespercyl
decl_stmt|;
comment|/* spare sectors per cylinder */
name|char
name|sl_xxx3
index|[
literal|4
index|]
decl_stmt|;
name|u_short
name|sl_interleave
decl_stmt|;
comment|/* interleave factor */
name|u_short
name|sl_ncylinders
decl_stmt|;
comment|/* data cylinders */
name|u_short
name|sl_acylinders
decl_stmt|;
comment|/* alternate cylinders */
name|u_short
name|sl_ntracks
decl_stmt|;
comment|/* tracks per cylinder */
name|u_short
name|sl_nsectors
decl_stmt|;
comment|/* sectors per track */
name|char
name|sl_xxx4
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|sun_dkpart
name|sl_part
index|[
literal|8
index|]
decl_stmt|;
comment|/* partition layout */
name|u_short
name|sl_magic
decl_stmt|;
comment|/* == SUN_DKMAGIC */
name|u_short
name|sl_cksum
decl_stmt|;
comment|/* xor checksum of all shorts */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* reads sun label in sector at [cp..cp+511] and sets *lp to BSD label */
end_comment

begin_decl_stmt
name|int
name|sun_disklabel
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
expr|struct
name|disklabel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true on success */
end_comment

begin_comment
comment|/* compatability dk ioctl's */
end_comment

begin_decl_stmt
name|int
name|sun_dkioctl
name|__P
argument_list|(
operator|(
expr|struct
name|dkdevice
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

