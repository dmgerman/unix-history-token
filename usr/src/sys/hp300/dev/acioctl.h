begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: acioctl.h 1.1 91/06/19$  *  *	@(#)acioctl.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|acinfo
block|{
name|short
name|fmte
decl_stmt|;
comment|/* 1st medium transport elt (picker) */
name|short
name|nmte
decl_stmt|;
comment|/* # medium transport elts */
name|short
name|fse
decl_stmt|;
comment|/* 1st storage elt (slot) */
name|short
name|nse
decl_stmt|;
comment|/* # storage elts */
name|short
name|fiee
decl_stmt|;
comment|/* 1st import/export elt (mailslot) */
name|short
name|niee
decl_stmt|;
comment|/* # import/export elts */
name|short
name|fdte
decl_stmt|;
comment|/* 1st data transport elt (drive) */
name|short
name|ndte
decl_stmt|;
comment|/* # data transport elts */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aceltstat
block|{
name|short
name|eaddr
decl_stmt|;
comment|/* element adress */
name|char
name|type
decl_stmt|;
comment|/* type of element */
name|char
name|flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/* types */
end_comment

begin_define
define|#
directive|define
name|AC_MTE
value|0x01
end_define

begin_comment
comment|/* picker */
end_comment

begin_define
define|#
directive|define
name|AC_SE
value|0x02
end_define

begin_comment
comment|/* slot */
end_comment

begin_define
define|#
directive|define
name|AC_IEE
value|0x03
end_define

begin_comment
comment|/* mailslot */
end_comment

begin_define
define|#
directive|define
name|AC_DTE
value|0x04
end_define

begin_comment
comment|/* drive */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|AC_FULL
value|0x01
end_define

begin_comment
comment|/* media present */
end_comment

begin_define
define|#
directive|define
name|AC_ERROR
value|0x04
end_define

begin_comment
comment|/* error accessing element */
end_comment

begin_define
define|#
directive|define
name|AC_ACCESS
value|0x08
end_define

begin_comment
comment|/* element accessible */
end_comment

begin_define
define|#
directive|define
name|AC_INVERT
value|0x80
end_define

begin_comment
comment|/* media inverted prior to insertion */
end_comment

begin_struct
struct|struct
name|acmove
block|{
name|short
name|srcelem
decl_stmt|;
name|short
name|dstelem
decl_stmt|;
name|short
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acbuffer
block|{
name|char
modifier|*
name|bufptr
decl_stmt|;
name|int
name|buflen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACIOCINIT
value|_IO('A', 0x1)
end_define

begin_comment
comment|/* init elt status */
end_comment

begin_define
define|#
directive|define
name|ACIOCGINFO
value|_IOR('A', 0x2, struct acinfo)
end_define

begin_comment
comment|/* mode sense */
end_comment

begin_define
define|#
directive|define
name|ACIOCGSTAT
value|_IOW('A', 0x3, struct acbuffer)
end_define

begin_comment
comment|/* read elem status */
end_comment

begin_define
define|#
directive|define
name|ACIOCMOVE
value|_IOW('A', 0x4, struct acmove)
end_define

begin_comment
comment|/* move elem */
end_comment

begin_define
define|#
directive|define
name|ACIOCRAWES
value|_IOW('A', 0x5, struct acbuffer)
end_define

begin_comment
comment|/* raw element stat */
end_comment

end_unit

