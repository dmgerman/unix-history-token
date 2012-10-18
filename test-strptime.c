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
comment|/* strptime(), getsubopt() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|struct
name|tm
name|tm
decl_stmt|;
name|strptime
argument_list|(
operator|*
name|argv
argument_list|,
literal|"%D"
argument_list|,
operator|&
name|tm
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

