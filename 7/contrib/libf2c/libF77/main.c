begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* STARTUP PROCEDURE FOR UNIX FORTRAN PROGRAMS */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"signal1.h"
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ONEXIT
end_ifndef

begin_define
define|#
directive|define
name|ONEXIT
value|atexit
end_define

begin_function_decl
specifier|extern
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|f_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|MAIN__
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|f_setarg
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|f_setsig
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|f_setarg
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|f_setsig
argument_list|()
expr_stmt|;
name|f_init
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|NO_ONEXIT
name|ONEXIT
argument_list|(
name|f_exit
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|MAIN__
argument_list|()
expr_stmt|;
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
literal|0
argument_list|)
expr_stmt|;
comment|/* exit(0) rather than return(0) to bypass Cray bug */
return|return
literal|0
return|;
comment|/* For compilers that complain of missing return values; */
comment|/* others will complain that this is unreachable code. */
block|}
end_function

end_unit

