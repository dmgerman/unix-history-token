begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This gives the effect of  	subroutine exit(rc) 	integer*4 rc 	stop 	end   * with the added side effect of supplying rc as the program's exit code.  */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|KR_headers
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|void
name|f_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
ifdef|#
directive|ifdef
name|KR_headers
name|G77_exit_0
parameter_list|(
name|rc
parameter_list|)
name|integer
modifier|*
name|rc
decl_stmt|;
else|#
directive|else
function|G77_exit_0
parameter_list|(
name|integer
modifier|*
name|rc
parameter_list|)
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|NO_ONEXIT
name|f_exit
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
operator|*
name|rc
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

