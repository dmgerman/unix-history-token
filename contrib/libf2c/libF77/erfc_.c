begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function_decl
specifier|extern
name|double
name|erfc
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|G77_erfc_0
parameter_list|(
name|real
modifier|*
name|x
parameter_list|)
block|{
return|return
operator|(
name|erfc
argument_list|(
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

