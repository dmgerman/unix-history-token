begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_if
if|#
directive|if
name|_G_HAVE_ATEXIT
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*voidfunc
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_function
specifier|static
name|void
name|_IO_register_cleanup
parameter_list|()
block|{
name|atexit
argument_list|(
operator|(
name|voidfunc
operator|)
name|_IO_cleanup
argument_list|)
expr_stmt|;
name|_IO_cleanup_registration_needed
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
function_decl|(
modifier|*
name|_IO_cleanup_registration_needed
function_decl|)
parameter_list|()
init|=
name|_IO_register_cleanup
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
function_decl|(
modifier|*
name|_IO_cleanup_registration_needed
function_decl|)
parameter_list|()
init|=
name|NULL
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_HAVE_ATEXIT */
end_comment

end_unit

