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
name|STDLIB_H
end_ifndef

begin_define
define|#
directive|define
name|STDLIB_H
end_define

begin_decl_stmt
specifier|static
name|char
name|stdlibhid
index|[]
init|=
literal|"@(#)stdlib.h	4.5"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined STDLIB_H */
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
name|__STDC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|LOOK_FOR_STDLIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LOOK_FOR_STDLIB
end_ifdef

begin_undef
undef|#
directive|undef
name|LOOK_FOR_STDLIB
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|STDLIB_RECURSING
end_ifdef

begin_include
include|#
directive|include
file|"/usr/include/stdlib.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined STDLIB_RECURSING */
end_comment

begin_define
define|#
directive|define
name|STDLIB_RECURSING
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_undef
undef|#
directive|undef
name|STDLIB_RECURSING
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined STDLIB_RECURSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_comment
comment|/* ** Stupid Turbo C doesn't define NULL in stdlib.h */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NULL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined LOOK_FOR_STDLIB */
end_comment

begin_comment
comment|/* ** size_t */
end_comment

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined EXIT_SUCCESS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined EXIT_FAILURE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NULL */
end_comment

begin_comment
comment|/* ** String conversion functions */
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/* ** Memory management functions */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined USG */
end_comment

begin_comment
comment|/* ** Communication with the environment */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined USG */
end_comment

begin_comment
comment|/* ** Searching and sorting functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|qsort
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined LOOK_FOR_STDLIB */
end_comment

end_unit

