begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	clock.c	1.1	85/07/22	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/time.h"
end_include

begin_include
include|#
directive|include
file|"../h/kernel.h"
end_include

begin_include
include|#
directive|include
file|"../tahoe/clock.h"
end_include

begin_comment
comment|/*  * Initialze the time of day register, based on the time base which is, e.g.  * from a filesystem.  */
end_comment

begin_macro
name|inittodr
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|time_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|base
operator|<
literal|5
operator|*
name|SECYR
condition|)
block|{
name|printf
argument_list|(
literal|"WARNING: preposterous time in file system"
argument_list|)
expr_stmt|;
name|time
operator|.
name|tv_sec
operator|=
literal|6
operator|*
name|SECYR
operator|+
literal|186
operator|*
name|SECDAY
operator|+
name|SECDAY
operator|/
literal|2
expr_stmt|;
block|}
else|else
name|time
operator|.
name|tv_sec
operator|=
name|base
expr_stmt|;
name|printf
argument_list|(
literal|" CHECK AND RESET THE DATE!\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

