begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SIGIOT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SIGABRT
end_ifdef

begin_define
define|#
directive|define
name|SIGIOT
value|SIGABRT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
specifier|extern
name|void
name|f_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|sig_die
parameter_list|(
specifier|register
name|char
modifier|*
name|s
parameter_list|,
name|int
name|kill
parameter_list|)
block|{
comment|/* print error message, then clear buffers */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|kill
condition|)
block|{
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
comment|/* now get a core */
ifdef|#
directive|ifdef
name|SIGIOT
name|signal
argument_list|(
name|SIGIOT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|abort
argument_list|()
expr_stmt|;
block|}
else|else
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
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

