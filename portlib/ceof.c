begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"iodec.h"
end_include

begin_comment
comment|/**  **	report end of file conditions  **/
end_comment

begin_macro
name|ceof
argument_list|(
argument|fn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fn
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|fileps
modifier|*
name|fp
decl_stmt|;
if|if
condition|(
name|fn
operator|<
literal|0
operator|||
name|fn
operator|>=
name|MAXFILES
condition|)
name|__error
argument_list|(
literal|"ceof: bad file number %d"
argument_list|,
name|fn
argument_list|)
expr_stmt|;
name|fp
operator|=
operator|&
name|__filehdr
index|[
name|fn
index|]
expr_stmt|;
if|if
condition|(
name|fp
operator|->
name|eoferr
operator|>
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

