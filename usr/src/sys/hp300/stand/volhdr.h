begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)volhdr.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * vohldr.h: volume header for "LIF" format volumes  */
end_comment

begin_struct
struct|struct
name|lifvol
block|{
name|short
name|vol_id
decl_stmt|;
name|char
name|vol_label
index|[
literal|6
index|]
decl_stmt|;
name|int
name|vol_addr
decl_stmt|;
name|short
name|vol_oct
decl_stmt|;
name|short
name|vol_dummy
decl_stmt|;
name|int
name|vol_dirsize
decl_stmt|;
name|short
name|vol_version
decl_stmt|;
name|short
name|vol_zero
decl_stmt|;
name|int
name|vol_huh1
decl_stmt|;
name|int
name|vol_huh2
decl_stmt|;
name|int
name|vol_length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lifdir
block|{
name|char
name|dir_name
index|[
literal|10
index|]
decl_stmt|;
name|short
name|dir_type
decl_stmt|;
name|int
name|dir_addr
decl_stmt|;
name|int
name|dir_length
decl_stmt|;
name|char
name|dir_toc
index|[
literal|6
index|]
decl_stmt|;
name|short
name|dir_flag
decl_stmt|;
name|int
name|dir_exec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* load header for boot rom */
end_comment

begin_struct
struct|struct
name|load
block|{
name|int
name|address
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VOL_ID
value|-32768
end_define

begin_define
define|#
directive|define
name|VOL_OCT
value|4096
end_define

begin_define
define|#
directive|define
name|DIR_TYPE
value|-5822
end_define

begin_define
define|#
directive|define
name|DIR_FLAG
value|0x8001
end_define

begin_comment
comment|/* dont ask me! */
end_comment

begin_define
define|#
directive|define
name|SECTSIZE
value|256
end_define

end_unit

