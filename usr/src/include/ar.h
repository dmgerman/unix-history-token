begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * Hugh Smith at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)ar.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AR_H_
end_ifndef

begin_define
define|#
directive|define
name|_AR_H_
end_define

begin_comment
comment|/* Pre-4BSD archives had these magic numbers in them. */
end_comment

begin_define
define|#
directive|define
name|OARMAG1
value|0177555
end_define

begin_define
define|#
directive|define
name|OARMAG2
value|0177545
end_define

begin_define
define|#
directive|define
name|ARMAG
value|"!<arch>\n"
end_define

begin_comment
comment|/* ar "magic number" */
end_comment

begin_define
define|#
directive|define
name|SARMAG
value|8
end_define

begin_comment
comment|/* strlen(ARMAG); */
end_comment

begin_define
define|#
directive|define
name|AR_EFMT1
value|"#1/"
end_define

begin_comment
comment|/* extended format #1 */
end_comment

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
comment|/* name */
name|char
name|ar_date
index|[
literal|12
index|]
decl_stmt|;
comment|/* modification time */
name|char
name|ar_uid
index|[
literal|6
index|]
decl_stmt|;
comment|/* user id */
name|char
name|ar_gid
index|[
literal|6
index|]
decl_stmt|;
comment|/* group id */
name|char
name|ar_mode
index|[
literal|8
index|]
decl_stmt|;
comment|/* octal file permissions */
name|char
name|ar_size
index|[
literal|10
index|]
decl_stmt|;
comment|/* size in bytes */
define|#
directive|define
name|ARFMAG
value|"`\n"
name|char
name|ar_fmag
index|[
literal|2
index|]
decl_stmt|;
comment|/* consistency check */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AR_H_ */
end_comment

end_unit

