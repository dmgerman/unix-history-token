begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: mailstats.h,v 8.13 1999/05/22 02:29:10 ca Exp $  */
end_comment

begin_define
define|#
directive|define
name|STAT_VERSION
value|3
end_define

begin_define
define|#
directive|define
name|STAT_MAGIC
value|0x1B1DE
end_define

begin_comment
comment|/* **  Statistics structure. */
end_comment

begin_struct
struct|struct
name|statistics
block|{
name|int
name|stat_magic
decl_stmt|;
comment|/* magic number */
name|int
name|stat_version
decl_stmt|;
comment|/* stat file version */
name|time_t
name|stat_itime
decl_stmt|;
comment|/* file initialization time */
name|short
name|stat_size
decl_stmt|;
comment|/* size of this structure */
name|long
name|stat_cf
decl_stmt|;
comment|/* # from connections */
name|long
name|stat_ct
decl_stmt|;
comment|/* # to connections */
name|long
name|stat_cr
decl_stmt|;
comment|/* # rejected connections */
name|long
name|stat_nf
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* # msgs from each mailer */
name|long
name|stat_bf
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* kbytes from each mailer */
name|long
name|stat_nt
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* # msgs to each mailer */
name|long
name|stat_bt
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* kbytes to each mailer */
name|long
name|stat_nr
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* # rejects by each mailer */
name|long
name|stat_nd
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* # discards by each mailer */
block|}
struct|;
end_struct

end_unit

