begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mailstats.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* **  Statistics structure. */
end_comment

begin_struct
struct|struct
name|statistics
block|{
name|time_t
name|stat_itime
decl_stmt|;
comment|/* file initialization time */
name|short
name|stat_size
decl_stmt|;
comment|/* size of this structure */
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
block|}
struct|;
end_struct

end_unit

