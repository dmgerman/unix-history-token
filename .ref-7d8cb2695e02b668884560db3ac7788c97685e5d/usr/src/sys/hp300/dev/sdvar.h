begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Van Jacobson of Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)sdvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|sdinfo
block|{
name|struct
name|disklabel
name|si_label
decl_stmt|;
comment|/* label */
name|int
name|si_bopen
decl_stmt|;
comment|/* mask of open block devs */
name|int
name|si_copen
decl_stmt|;
comment|/* mask of open char devs */
name|int
name|si_open
decl_stmt|;
comment|/* composite mask of open devs */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sd_softc
block|{
name|struct
name|hp_device
modifier|*
name|sc_hd
decl_stmt|;
name|struct
name|devqueue
name|sc_dq
decl_stmt|;
name|int
name|sc_format_pid
decl_stmt|;
comment|/* process using "format" mode */
name|short
name|sc_flags
decl_stmt|;
name|short
name|sc_type
decl_stmt|;
comment|/* drive type */
name|short
name|sc_punit
decl_stmt|;
comment|/* physical unit (scsi lun) */
name|u_short
name|sc_bshift
decl_stmt|;
comment|/* convert device blocks to DEV_BSIZE blks */
name|u_int
name|sc_blks
decl_stmt|;
comment|/* number of blocks on device */
name|int
name|sc_blksize
decl_stmt|;
comment|/* device block size in bytes */
name|u_int
name|sc_wpms
decl_stmt|;
comment|/* average xfer rate in 16 bit wds/sec. */
name|struct
name|sdinfo
name|sc_info
decl_stmt|;
comment|/* disklabel and related info */
block|}
struct|;
end_struct

begin_comment
comment|/* sc_flags values */
end_comment

begin_define
define|#
directive|define
name|SDF_ALIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|SDF_OPENING
value|0x02
end_define

begin_define
define|#
directive|define
name|SDF_CLOSING
value|0x04
end_define

begin_define
define|#
directive|define
name|SDF_WANTED
value|0x08
end_define

begin_define
define|#
directive|define
name|SDF_WLABEL
value|0x10
end_define

begin_define
define|#
directive|define
name|SDF_RMEDIA
value|0x20
end_define

begin_define
define|#
directive|define
name|SDF_ERROR
value|0x40
end_define

begin_struct
struct|struct
name|sdstats
block|{
name|long
name|sdresets
decl_stmt|;
name|long
name|sdtransfers
decl_stmt|;
name|long
name|sdpartials
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sdunit
parameter_list|(
name|x
parameter_list|)
value|(minor(x)>> 3)
end_define

begin_define
define|#
directive|define
name|sdpart
parameter_list|(
name|x
parameter_list|)
value|(minor(x)& 0x7)
end_define

begin_define
define|#
directive|define
name|sdpunit
parameter_list|(
name|x
parameter_list|)
value|((x)& 7)
end_define

begin_define
define|#
directive|define
name|sdlabdev
parameter_list|(
name|d
parameter_list|)
value|(dev_t)(((int)(d)&~7)|2)
end_define

begin_comment
comment|/* sd?c */
end_comment

begin_define
define|#
directive|define
name|b_cylin
value|b_resid
end_define

begin_define
define|#
directive|define
name|SDRETRY
value|2
end_define

end_unit

