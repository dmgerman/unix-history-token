begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * internal include file for com_err package  */
end_comment

begin_include
include|#
directive|include
file|"mit-sipb-copyright.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
specifier|const
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
comment|/* const */
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|perror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|perror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

