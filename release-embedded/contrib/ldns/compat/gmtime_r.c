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
name|struct
name|tm
modifier|*
name|gmtime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|,
name|struct
name|tm
modifier|*
name|result
parameter_list|)
block|{
comment|/* no thread safety. */
operator|*
name|result
operator|=
operator|*
name|gmtime
argument_list|(
name|timep
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

