begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: hpux_exec.h 1.4 88/05/24$  *  *	@(#)hpux_exec.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * HPUX a.out header format  */
end_comment

begin_struct
struct|struct
name|hpux_exec
block|{
name|long
name|ha_magic
decl_stmt|;
comment|/* magic number */
name|short
name|ha_version
decl_stmt|;
comment|/* version ID */
name|short
name|ha_pad0
decl_stmt|;
comment|/* doesn't matter */
name|long
name|ha_pad1
decl_stmt|;
comment|/* ditto */
name|unsigned
name|long
name|ha_text
decl_stmt|;
comment|/* size of text segment */
name|unsigned
name|long
name|ha_data
decl_stmt|;
comment|/* size of initialized data */
name|unsigned
name|long
name|ha_bss
decl_stmt|;
comment|/* size of uninitialized data */
name|unsigned
name|long
name|ha_pad2
index|[
literal|5
index|]
decl_stmt|;
comment|/* doesn't matter */
name|unsigned
name|long
name|ha_entry
decl_stmt|;
comment|/* entry point */
name|unsigned
name|long
name|ha_pad3
index|[
literal|4
index|]
decl_stmt|;
comment|/* doesn't matter */
block|}
struct|;
end_struct

begin_comment
comment|/*  * If the HPUX object file version number is BSDVNUM the file was built  * with the HPUX SGS but linked with the BSD libraries.  */
end_comment

begin_define
define|#
directive|define
name|BSDVNUM
value|0x2BAD
end_define

end_unit

