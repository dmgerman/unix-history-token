begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dummy swapgeneric.c: not used in new config system.  *  *	@(#)swapgeneric.c	7.1 (Berkeley) %G%  */
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
name|NODEV
block|,
literal|0
block|,
literal|0
block|}
block|,
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

