begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Wrapper to implement ANSI C's atexit using SunOS's on_exit. */
end_comment

begin_comment
comment|/* This function is in the public domain.  --Mike Stump. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int atexit (void (*@var{f})())  Causes function @var{f} to be called at exit.  Returns 0.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ON_EXIT
end_ifdef

begin_function
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
comment|/* If the system doesn't provide a definition for atexit, use on_exit      if the system provides that.  */
name|on_exit
argument_list|(
name|f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

