begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ar.h	5.1 (Berkeley) 5/30/85  */
end_comment

begin_define
define|#
directive|define
name|ARMAG
value|"!<arch>\n"
end_define

begin_define
define|#
directive|define
name|SARMAG
value|8
end_define

begin_define
define|#
directive|define
name|ARFMAG
value|"`\n"
end_define

begin_struct
struct|struct
name|ar_hdr
block|{
name|char
name|ar_name
index|[
literal|16
index|]
decl_stmt|;
name|char
name|ar_date
index|[
literal|12
index|]
decl_stmt|;
name|char
name|ar_uid
index|[
literal|6
index|]
decl_stmt|;
name|char
name|ar_gid
index|[
literal|6
index|]
decl_stmt|;
name|char
name|ar_mode
index|[
literal|8
index|]
decl_stmt|;
name|char
name|ar_size
index|[
literal|10
index|]
decl_stmt|;
name|char
name|ar_fmag
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

