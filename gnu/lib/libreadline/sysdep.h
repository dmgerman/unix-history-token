begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System-dependent stuff, for ``normal'' systems */
end_comment

begin_comment
comment|/* If you think you need to change this file, then you are wrong.  In order to    avoid a huge ugly mass of nested #ifdefs, you should create a new file just    for your system, which contains exactly those #includes and definitions that    your system needs, AND NOTHING MORE!  Then, add that file to the appropriate    place in configure.in, and viola, you are done.  sysdep-sunos4.h is a good    example of how to do this. */
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

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_comment
comment|/* May be a macro, with args. */
end_comment

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

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* Needed for TIOC?WINSZ */
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

begin_comment
comment|/* SVR4 systems should use<termios.h> rather than<termio.h>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USGr4
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_VERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

