begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *  *	@(#)nvram.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * OMRON: $Id: nvram.h,v 1.1 92/05/27 14:32:51 moti Exp $  * by Shigeto Mochida  */
end_comment

begin_comment
comment|/*  * Non Volatile RAM  */
end_comment

begin_define
define|#
directive|define
name|NVRAMSZ
value|2040
end_define

begin_comment
comment|/* Size of NVRAM. (Total 2040 bytes) */
end_comment

begin_define
define|#
directive|define
name|NVSYMSZ
value|16
end_define

begin_define
define|#
directive|define
name|NVVALSZ
value|16
end_define

begin_define
define|#
directive|define
name|NVSYSSZ
value|42
end_define

begin_define
define|#
directive|define
name|NVUSRSZ
value|512
end_define

begin_comment
comment|/*  * Battery back-up memory space.  */
end_comment

begin_struct
struct|struct
name|nvram
block|{
name|char
name|nv_testwrite
index|[
literal|4
index|]
decl_stmt|;
comment|/* for battery check */
name|char
name|nv_hdr
index|[
literal|4
index|]
decl_stmt|;
comment|/* header name */
name|long
name|nv_machtype
decl_stmt|;
comment|/* machine-type ID */
name|long
name|nv_machno
decl_stmt|;
comment|/* machine number */
name|char
name|nv_calclock
index|[
literal|12
index|]
decl_stmt|;
comment|/* RTC initialize */
name|char
name|nv_checksum
index|[
literal|4
index|]
decl_stmt|;
comment|/* check sum for "nv_system" */
struct|struct
name|nv_system
block|{
name|char
name|nv_symbol
index|[
name|NVSYMSZ
index|]
decl_stmt|;
name|char
name|nv_value
index|[
name|NVVALSZ
index|]
decl_stmt|;
block|}
name|nv_system
index|[
name|NVSYSSZ
index|]
struct|;
comment|/* system define */
name|char
name|nv_reserve
index|[
literal|152
index|]
decl_stmt|;
comment|/* reserved */
name|char
name|nv_user
index|[
name|NVUSRSZ
index|]
decl_stmt|;
comment|/* user avail area */
block|}
struct|;
end_struct

end_unit

