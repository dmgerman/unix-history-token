begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  Sendmail **  Copyright (c) 1983  Eric P. Allman **  Berkeley, California ** **  Copyright (c) 1983 Regents of the University of California. **  All rights reserved.  The Berkeley software License Agreement **  specifies the terms and conditions for redistribution. ** **	"@(#)mailstats.h	5.1 (Berkeley) 5/2/86"; ** */
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

