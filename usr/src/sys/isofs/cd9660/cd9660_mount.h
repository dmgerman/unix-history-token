begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Pace Willisson (pace@blitz.com).  The Rock Ridge Extension  * Support code is derived from software contributed to Berkeley  * by Atsushi Murai (amurai@spec.co.jp).  *  * %sccs.include.redist.c%  *  *	@(#)cd9660_mount.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Arguments to mount ISO 9660 filesystems.  */
end_comment

begin_struct
struct|struct
name|iso_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* block special device to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export info */
name|int
name|flags
decl_stmt|;
comment|/* mounting flags, see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISOFSMNT_NORRIP
value|0x00000001
end_define

begin_comment
comment|/* disable Rock Ridge Ext.*/
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_GENS
value|0x00000002
end_define

begin_comment
comment|/* enable generation numbers */
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_EXTATT
value|0x00000004
end_define

begin_comment
comment|/* enable extended attributes */
end_comment

end_unit

