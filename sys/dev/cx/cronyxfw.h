begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Cronyx firmware definitions.  *  * Copyright (C) 1996 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: cronyxfw.h,v 1.1.2.1 2003/11/12 17:09:49 rik Exp $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CRONYX_DAT_MAGIC
value|2001107011L
end_define

begin_comment
comment|/* firmware file magic */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cr_dat_tst
block|{
name|long
name|start
decl_stmt|;
comment|/* verify start */
name|long
name|end
decl_stmt|;
comment|/* verify end */
block|}
name|cr_dat_tst_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* firmware file header */
name|unsigned
name|long
name|magic
decl_stmt|;
comment|/* firmware magic */
name|long
name|hdrsz
decl_stmt|;
comment|/* header size in bytes */
name|long
name|len
decl_stmt|;
comment|/* firmware data size in bits */
name|long
name|ntest
decl_stmt|;
comment|/* number of tests */
name|unsigned
name|long
name|sum
decl_stmt|;
comment|/* header+tests+data checksum */
name|char
name|version
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware version number */
name|char
name|date
index|[
literal|8
index|]
decl_stmt|;
comment|/* date when compiled */
block|}
name|cr_dat_t
typedef|;
end_typedef

end_unit

