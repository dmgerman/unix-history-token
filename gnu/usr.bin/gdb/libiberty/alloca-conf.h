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
comment|/* not __GNUC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNUC__ */
end_comment

end_unit

