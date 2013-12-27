begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulate vfork using just plain fork, for systems without a real vfork.    This function is in the public domain. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int vfork (void)  Emulates @code{vfork} by calling @code{fork} and returning its value.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_function_decl
specifier|extern
name|int
name|fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|vfork
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|fork
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

