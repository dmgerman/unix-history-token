begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)length.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  FIND STRING LENGTH ** **	The length of string `s' (excluding the null byte which **		terminates the string) is returned. */
end_comment

begin_macro
name|length
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|l
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|l
operator|=
literal|0
expr_stmt|;
name|p
operator|=
name|s
expr_stmt|;
while|while
condition|(
operator|*
name|p
operator|++
condition|)
name|l
operator|++
expr_stmt|;
return|return
operator|(
name|l
operator|)
return|;
block|}
end_block

end_unit

