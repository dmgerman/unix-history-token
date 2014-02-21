begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<ldns/config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|ctime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
block|{
comment|/* no thread safety. */
name|char
modifier|*
name|result
init|=
name|ctime
argument_list|(
name|timep
argument_list|)
decl_stmt|;
if|if
condition|(
name|buf
operator|&&
name|result
condition|)
name|strcpy
argument_list|(
name|buf
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

