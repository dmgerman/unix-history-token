begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strings.h - define standard string functions */
end_comment

begin_comment
comment|/* @(#)$Id: strings.h,v 1.19 1993/02/26 21:54:00 jromine Exp $ */
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
name|AUX
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
value|memcmp(b1, b2, length)
end_define

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _AIX */
end_comment

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
end_endif

begin_comment
comment|/* SYS5 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD42
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__386BSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD44
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BSD42 || SVR4 */
end_comment

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
name|SPRINTFTYPE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|ncr
end_ifndef

begin_comment
comment|/* NCR compiler complains about re-declaration */
end_comment

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* I guess this is the new standard */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function_decl
name|SPRINTFTYPE
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__386BSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD44
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__HIGHC__
argument_list|)
operator|||
name|__GNUC__
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|memcpy(d,s,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
value|memcmp(b1, b2, length)
end_define

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
end_endif

begin_comment
comment|/* SYS5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _STRINGS */
end_comment

end_unit

