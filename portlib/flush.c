begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"iodec.h"
end_include

begin_comment
comment|/**  **	flush all i/o buffers  **/
end_comment

begin_macro
name|flush
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXFILES
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|__filehdr
index|[
name|i
index|]
operator|.
name|wrflag
condition|)
name|cflush
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

