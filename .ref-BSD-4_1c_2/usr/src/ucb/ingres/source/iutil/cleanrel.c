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
file|<access.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)cleanrel.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* ** CLEANREL -- **	If there are any buffers being used by the relation described **	in the descriptor struct, flush and zap the buffer. **	This will force a UNIX disk read the next time the relation **	is accessed which is useful to get the most up-to-date **	information from a file that is being updated by another **	program. */
end_comment

begin_macro
name|cleanrel
argument_list|(
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|DESC
modifier|*
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* flush and reset all pages of this rel */
return|return
operator|(
name|flush_rel
argument_list|(
name|d
argument_list|,
name|TRUE
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

