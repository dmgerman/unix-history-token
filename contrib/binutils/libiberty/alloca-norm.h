begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "Normal" configuration for alloca.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__GNUC__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
modifier|*
name|__builtin_alloca
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|__builtin_alloca
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Stupid include file doesn't declare it */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (sparc) || ! defined (sun) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|PTR
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_function_decl
name|PTR
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* must agree with functions.def */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (sparc) || ! defined (sun) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__GNUC__) */
end_comment

end_unit

