begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOID
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_H
end_ifndef

begin_define
define|#
directive|define
name|STDIO_H
end_define

begin_decl_stmt
specifier|static
name|char
name|stdiohid
index|[]
init|=
literal|"@(#)stdio.h	4.2"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined STDIO_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO_RECURSING
end_ifdef

begin_include
include|#
directive|include
file|"/usr/include/stdio.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined STDIO_RECURSING */
end_comment

begin_define
define|#
directive|define
name|STDIO_RECURSING
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|STDIO_RECURSING
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined STDIO_RECURSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILENAME_MAX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined unix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_define
define|#
directive|define
name|FILENAME_MAX
value|MAXPATHLEN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_define
define|#
directive|define
name|FILENAME_MAX
value|1024
end_define

begin_comment
comment|/* Pure guesswork */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined FILENAME_MAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|remove
end_ifndef

begin_define
define|#
directive|define
name|remove
parameter_list|(
name|name
parameter_list|)
value|unlink(name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined remove */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_function_decl
specifier|extern
name|void
name|perror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined BSD */
end_comment

begin_define
define|#
directive|define
name|remove
parameter_list|(
name|name
parameter_list|)
value|unlink(name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined unix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_comment
comment|/* ** UNIX is a registered trademark of AT&T. */
end_comment

end_unit

