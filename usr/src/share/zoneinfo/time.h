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
name|TIME_H
end_ifndef

begin_define
define|#
directive|define
name|TIME_H
end_define

begin_decl_stmt
specifier|static
name|char
name|timehid
index|[]
init|=
literal|"@(#)time.h	4.2"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TIME_H */
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
name|TIME_RECURSING
end_ifdef

begin_include
include|#
directive|include
file|"/usr/include/time.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined TIME_RECURSING */
end_comment

begin_define
define|#
directive|define
name|TIME_RECURSING
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_undef
undef|#
directive|undef
name|TIME_RECURSING
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined TIME_RECURSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|time_t
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined unix */
end_comment

begin_typedef
typedef|typedef
name|long
name|time_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined unix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined time_t */
end_comment

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|time_t
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined unix */
end_comment

begin_typedef
typedef|typedef
name|long
name|time_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined unix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined time_t */
end_comment

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __GNUC__ */
end_comment

begin_comment
comment|/* ** UNIX is a registered trademark of AT&T. */
end_comment

end_unit

