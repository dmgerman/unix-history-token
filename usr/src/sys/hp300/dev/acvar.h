begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: acvar.h 1.1 91/06/19$  *  *	@(#)acvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|ac_softc
block|{
name|struct
name|hp_device
modifier|*
name|sc_hd
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
name|struct
name|buf
modifier|*
name|sc_bp
decl_stmt|;
name|struct
name|scsi_fmt_cdb
modifier|*
name|sc_cmd
decl_stmt|;
name|struct
name|acinfo
name|sc_einfo
decl_stmt|;
name|short
name|sc_punit
decl_stmt|;
name|short
name|sc_picker
decl_stmt|;
name|struct
name|devqueue
name|sc_dq
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACF_ALIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACF_OPEN
value|0x02
end_define

begin_define
define|#
directive|define
name|ACF_ACTIVE
value|0x04
end_define

begin_define
define|#
directive|define
name|ACCMD_INITES
value|0x07
end_define

begin_define
define|#
directive|define
name|ACCMD_MODESENSE
value|0x1A
end_define

begin_define
define|#
directive|define
name|ACCMD_READES
value|0xB8
end_define

begin_define
define|#
directive|define
name|ACCMD_MOVEM
value|0xA5
end_define

begin_struct
struct|struct
name|ac_restathdr
block|{
name|short
name|ac_felt
decl_stmt|;
comment|/* first element reported */
name|short
name|ac_nelt
decl_stmt|;
comment|/* number of elements reported */
name|long
name|ac_bcount
decl_stmt|;
comment|/* length of report (really only 24 bits) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ac_restatphdr
block|{
name|char
name|ac_type
decl_stmt|;
comment|/* type code */
name|char
name|ac_res
decl_stmt|;
name|short
name|ac_dlen
decl_stmt|;
comment|/* element descriptor length */
name|long
name|ac_bcount
decl_stmt|;
comment|/* byte count (really only 24 bits) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ac_restatdb
block|{
name|short
name|ac_eaddr
decl_stmt|;
comment|/* element address */
name|u_int
name|ac_res1
range|:
literal|2
decl_stmt|,
name|ac_ie
range|:
literal|1
decl_stmt|,
comment|/* import enabled (IEE only) */
name|ac_ee
range|:
literal|1
decl_stmt|,
comment|/* export enabled (IEE only) */
name|ac_acc
range|:
literal|1
decl_stmt|,
comment|/* accessible from MTE */
name|ac_exc
range|:
literal|1
decl_stmt|,
comment|/* element in abnormal state */
name|ac_imp
range|:
literal|1
decl_stmt|,
comment|/* 1 == user inserted medium (IEE only) */
name|ac_full
range|:
literal|1
decl_stmt|;
comment|/* element contains media */
block|}
struct|;
end_struct

end_unit

