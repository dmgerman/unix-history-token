begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copy LEN bytes starting at SRCADDR to DESTADDR.  Result undefined    if the source overlaps with the destination.    Return DESTADDR. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|memcpy
parameter_list|(
name|destaddr
parameter_list|,
name|srcaddr
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|destaddr
decl_stmt|;
specifier|const
name|char
modifier|*
name|srcaddr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|char
modifier|*
name|dest
init|=
name|destaddr
decl_stmt|;
while|while
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
operator|*
name|destaddr
operator|++
operator|=
operator|*
name|srcaddr
operator|++
expr_stmt|;
return|return
name|dest
return|;
block|}
end_function

end_unit

