begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* This defines BSD */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD4_4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|index((a), (b))
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|rindex((a), (b))
end_define

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcopy((b), (a), (c))
end_define

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|bzero((a), (b))
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bcmp((a), (b), (c))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_typedef
typedef|typedef
name|void
name|sigret_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|sigret_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* system routines that don't return int */
end_comment

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|setbuffer
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|setvbuf((f), (b), (b) ? _IOFBF : _IONBF, (s))
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset((a), 0, (b))
end_define

begin_typedef
typedef|typedef
name|void
name|sigret_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

