begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)min.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  MIN -- return the minimum of two integers. ** **	Why should I even have to write this???? */
end_comment

begin_macro
name|min
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|b
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|a
operator|<
name|b
operator|)
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_block

end_unit

