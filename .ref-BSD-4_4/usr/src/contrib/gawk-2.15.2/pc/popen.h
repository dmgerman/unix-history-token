begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** popen.h -- prototypes for pipe functions */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FILE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|popen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

