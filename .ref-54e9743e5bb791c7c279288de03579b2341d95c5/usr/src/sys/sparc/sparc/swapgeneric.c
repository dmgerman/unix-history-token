begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)swapgeneric.c	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * fake swapgeneric.c -- should do this differently.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_decl_stmt
name|dev_t
name|rootdev
init|=
name|NODEV
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|dumpdev
init|=
name|NODEV
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|swdevt
name|swdevt
index|[]
init|=
block|{
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd0b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|9
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd1b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|17
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd2b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|25
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd3b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|33
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd4b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|41
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd5b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|49
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd6b */
block|{
name|makedev
argument_list|(
literal|7
argument_list|,
literal|57
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* sd7b */
block|{
name|NODEV
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

