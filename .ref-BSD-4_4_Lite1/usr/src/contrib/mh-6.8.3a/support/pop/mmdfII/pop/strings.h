begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strings.h - define standard string functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRINGS
end_ifndef

begin_comment
comment|/* once-only... */
end_comment

begin_define
define|#
directive|define
name|_STRINGS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
endif|SYS5
end_endif

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
else|SYS5
end_else

begin_function_decl
name|int
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|SYS5
end_endif

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
value|(void) memcpy (b2, b1, length)
end_define

begin_define
define|#
directive|define
name|bcpy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
value|memcmp (b1, b2, length)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|b
parameter_list|,
name|length
parameter_list|)
value|(void) memset (b, 0, length)
end_define

begin_endif
endif|#
directive|endif
endif|SYS5
end_endif

begin_endif
endif|#
directive|endif
endif|not _STRINGS
end_endif

end_unit

