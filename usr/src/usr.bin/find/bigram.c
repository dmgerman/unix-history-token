begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)bigram.c	4.2	(Berkeley)	7/21/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  *  bigram< text> bigrams  *   * List bigrams for 'updatedb' script.  * Use 'code' to encode a file using this output.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MAXPATH
value|1024
end_define

begin_comment
comment|/* maximum pathname length */
end_comment

begin_decl_stmt
name|char
name|path
index|[
name|MAXPATH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|oldpath
index|[
name|MAXPATH
index|]
init|=
literal|" "
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|( )
block|{
specifier|register
name|int
name|count
decl_stmt|,
name|j
decl_stmt|;
while|while
condition|(
name|gets
argument_list|(
name|path
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|count
operator|=
name|prefix_length
argument_list|(
name|oldpath
argument_list|,
name|path
argument_list|)
expr_stmt|;
comment|/* 		   output post-residue bigrams only 		*/
for|for
control|(
name|j
operator|=
name|count
init|;
name|path
index|[
name|j
index|]
operator|!=
name|NULL
condition|;
name|j
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|path
index|[
name|j
operator|+
literal|1
index|]
operator|==
name|NULL
condition|)
break|break;
name|putchar
argument_list|(
name|path
index|[
name|j
index|]
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|path
index|[
name|j
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|oldpath
argument_list|,
name|path
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_macro
name|prefix_length
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_comment
comment|/* return length of longest common prefix */
end_comment

begin_decl_stmt
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ... of strings s1 and s2 */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|start
decl_stmt|;
for|for
control|(
name|start
operator|=
name|s1
init|;
operator|*
name|s1
operator|==
operator|*
name|s2
condition|;
name|s1
operator|++
operator|,
name|s2
operator|++
control|)
if|if
condition|(
operator|*
name|s1
operator|==
name|NULL
condition|)
break|break;
return|return
operator|(
name|s1
operator|-
name|start
operator|)
return|;
block|}
end_block

end_unit

