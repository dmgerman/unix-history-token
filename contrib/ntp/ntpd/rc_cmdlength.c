begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<rc_cmdlength.h>
end_include

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bug 2853 */
end_comment

begin_comment
comment|/* evaluate the length of the command sequence. This breaks at the first  * char that is not>= SPACE and<= 127 after trimming from the right.  */
end_comment

begin_function
name|size_t
name|remoteconfig_cmdlength
parameter_list|(
specifier|const
name|char
modifier|*
name|src_buf
parameter_list|,
specifier|const
name|char
modifier|*
name|src_end
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|scan
decl_stmt|;
name|unsigned
name|char
name|ch
decl_stmt|;
comment|/* trim whitespace& garbage from the right */
while|while
condition|(
name|src_end
operator|!=
name|src_buf
condition|)
block|{
name|ch
operator|=
name|src_end
index|[
operator|-
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|ch
operator|>
literal|' '
operator|&&
name|ch
operator|<
literal|128
condition|)
break|break;
operator|--
name|src_end
expr_stmt|;
block|}
comment|/* now do a forward scan */
for|for
control|(
name|scan
operator|=
name|src_buf
init|;
name|scan
operator|!=
name|src_end
condition|;
operator|++
name|scan
control|)
block|{
name|ch
operator|=
name|scan
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|ch
operator|<
literal|' '
operator|||
name|ch
operator|>=
literal|128
operator|)
operator|&&
name|ch
operator|!=
literal|'\t'
condition|)
break|break;
block|}
return|return
call|(
name|size_t
call|)
argument_list|(
name|scan
operator|-
name|src_buf
argument_list|)
return|;
block|}
end_function

end_unit

