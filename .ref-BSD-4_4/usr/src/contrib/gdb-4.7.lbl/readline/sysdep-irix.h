begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System-dependent stuff, for SGI irix */
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

begin_function_decl
specifier|extern
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|direct
name|dirent
typedef|;
end_typedef

end_unit

