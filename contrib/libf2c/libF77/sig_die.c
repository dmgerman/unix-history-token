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

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|void
name|sig_die
argument_list|(
name|s
argument_list|,
name|kill
argument_list|)
decl|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kill
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

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
endif|#
directive|endif
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

