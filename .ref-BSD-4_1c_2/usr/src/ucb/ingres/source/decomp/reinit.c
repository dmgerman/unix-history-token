begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|<lock.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)reinit.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* ** REINIT -- reinitialize decomp upon end of query, error, or interrupt. **	All open relations are closed, temp relations destroyed, **	and relation locks released. */
end_comment

begin_macro
name|reinit
argument_list|()
end_macro

begin_block
block|{
name|closers
argument_list|()
expr_stmt|;
if|if
condition|(
name|Lockrel
condition|)
comment|/* release all relation locks */
name|unlall
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

