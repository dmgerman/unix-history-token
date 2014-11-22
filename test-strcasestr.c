begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* strcasestr() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|big
init|=
literal|"BigString"
decl_stmt|;
name|char
modifier|*
name|cp
init|=
name|strcasestr
argument_list|(
name|big
argument_list|,
literal|"Gst"
argument_list|)
decl_stmt|;
return|return
operator|(
name|big
operator|+
literal|2
operator|!=
name|cp
operator|)
return|;
block|}
end_function

end_unit

