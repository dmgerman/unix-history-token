begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grfreg.h 1.6 92/01/31$  *  *	@(#)grfreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* 300 bitmapped display hardware primary id */
end_comment

begin_define
define|#
directive|define
name|GRFHWID
value|0x39
end_define

begin_comment
comment|/* 300 internal bitmapped display address */
end_comment

begin_define
define|#
directive|define
name|GRFIADDR
value|0x560000
end_define

begin_comment
comment|/* 300 hardware secondary ids */
end_comment

begin_define
define|#
directive|define
name|GID_GATORBOX
value|1
end_define

begin_define
define|#
directive|define
name|GID_TOPCAT
value|2
end_define

begin_define
define|#
directive|define
name|GID_RENAISSANCE
value|4
end_define

begin_define
define|#
directive|define
name|GID_LRCATSEYE
value|5
end_define

begin_define
define|#
directive|define
name|GID_HRCCATSEYE
value|6
end_define

begin_define
define|#
directive|define
name|GID_HRMCATSEYE
value|7
end_define

begin_define
define|#
directive|define
name|GID_DAVINCI
value|8
end_define

begin_define
define|#
directive|define
name|GID_XXXCATSEYE
value|9
end_define

begin_define
define|#
directive|define
name|GID_XGENESIS
value|11
end_define

begin_define
define|#
directive|define
name|GID_TIGER
value|12
end_define

begin_define
define|#
directive|define
name|GID_YGENESIS
value|13
end_define

begin_define
define|#
directive|define
name|GID_HYPERION
value|14
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|grftype
typedef|;
end_typedef

begin_struct
struct|struct
name|grfreg
block|{
name|grftype
name|gr_pad0
decl_stmt|,
name|gr_id
decl_stmt|,
comment|/* +0x01 */
name|gr_pad1
index|[
literal|0x3
index|]
decl_stmt|,
name|gr_fbwidth_h
decl_stmt|,
comment|/* +0x05 */
name|gr_pad2
decl_stmt|,
name|gr_fbwidth_l
decl_stmt|,
comment|/* +0x07 */
name|gr_pad3
decl_stmt|,
name|gr_fbheight_h
decl_stmt|,
comment|/* +0x09 */
name|gr_pad4
decl_stmt|,
name|gr_fbheight_l
decl_stmt|,
comment|/* +0x0B */
name|gr_pad5
decl_stmt|,
name|gr_dwidth_h
decl_stmt|,
comment|/* +0x0D */
name|gr_pad6
decl_stmt|,
name|gr_dwidth_l
decl_stmt|,
comment|/* +0x0F */
name|gr_pad7
decl_stmt|,
name|gr_dheight_h
decl_stmt|,
comment|/* +0x11 */
name|gr_pad8
decl_stmt|,
name|gr_dheight_l
decl_stmt|,
comment|/* +0x13 */
name|gr_pad9
decl_stmt|,
name|gr_id2
decl_stmt|,
comment|/* +0x15 */
name|gr_pad10
index|[
literal|0x47
index|]
decl_stmt|,
name|gr_fbomsb
decl_stmt|,
comment|/* +0x5d */
name|gr_pad11
decl_stmt|,
name|gr_fbolsb
decl_stmt|;
comment|/* +0x5f */
block|}
struct|;
end_struct

end_unit

