begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rominfo.h 1.2 88/05/24$  *  *	@(#)rominfo.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|ROMADDR
value|0xFFFFF000
end_define

begin_struct
struct|struct
name|jmpvec
block|{
name|short
name|op
decl_stmt|;
comment|/* jmp instruction */
name|long
name|addr
decl_stmt|;
comment|/* address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rominfo
block|{
name|char
name|p1
index|[
literal|0xDC0
index|]
decl_stmt|;
name|short
name|boottype
decl_stmt|;
comment|/* ??                           (FFFFFDC0) */
name|char
name|name
index|[
literal|10
index|]
decl_stmt|;
comment|/* HP system name, e.g. SYSHPUX (FFFFFDC2) */
name|short
name|p2
decl_stmt|;
comment|/* ??                           (FFFFFDCC) */
name|long
name|lowram
decl_stmt|;
comment|/* lowest useable RAM location  (FFFFFDCE) */
name|char
name|p3
index|[
literal|0x100
index|]
decl_stmt|;
comment|/* ??                           (FFFFFDD2) */
name|char
name|sysflag
decl_stmt|;
comment|/* HP system flags              (FFFFFED2) */
name|char
name|p4
decl_stmt|;
comment|/* ??                           (FFFFFED3) */
name|long
name|rambase
decl_stmt|;
comment|/* physaddr of lowest RAM       (FFFFFED4) */
name|char
name|ndrives
decl_stmt|;
comment|/* number of drives             (FFFFFED8) */
name|char
name|p5
decl_stmt|;
comment|/* ??                           (FFFFFED9) */
name|char
name|sysflag2
decl_stmt|;
comment|/* more system flags            (FFFFFEDA) */
name|char
name|p6
decl_stmt|;
comment|/* ??                           (FFFFFEDB) */
name|long
name|msus
decl_stmt|;
comment|/* ??                           (FFFFFEDC) */
name|struct
name|jmpvec
name|jvec
index|[
literal|48
index|]
decl_stmt|;
comment|/* jump vectors                 (FFFFFEE0) */
block|}
struct|;
end_struct

end_unit

