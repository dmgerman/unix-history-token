begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System-dependent stuff, for ``normal'' systems */
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

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Needed by dirent.h */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USGr4
argument_list|)
operator|||
name|defined
argument_list|(
name|USGr3
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USGr4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG&& TIOCGWINSZ */
end_comment

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|dirent
name|dirent
typedef|;
end_typedef

end_unit

