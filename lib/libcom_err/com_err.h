begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file for common error description library.  *  * Copyright 1988, Student Information Processing Board of the  * Massachusetts Institute of Technology.  *  * For copyright and distribution info, see the documentation supplied  * with this package.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COM_ERR_H
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__HIGHC__
end_ifndef

begin_comment
comment|/* gives us STDC but not stdarg */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI C -- use prototypes etc */
end_comment

begin_function_decl
name|void
name|com_err
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
specifier|const
modifier|*
name|error_message
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|com_err_hook
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|void
argument_list|(
operator|*
name|set_com_err_hook
argument_list|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|long
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|va_list
argument_list|)
argument_list|)
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|long
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|va_list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
operator|*
name|reset_com_err_hook
argument_list|()
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|long
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|va_list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no prototypes */
end_comment

begin_function_decl
name|void
name|com_err
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|error_message
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|com_err_hook
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|void
argument_list|(
operator|*
name|set_com_err_hook
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
operator|*
name|reset_com_err_hook
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__COM_ERR_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined(__COM_ERR_H) */
end_comment

end_unit

