begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define malloc and friends.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_MALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_MALLOC_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MALLOC_H
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Deal with platform differences declaring alloca()  * This comes nearly verbatim from:  *  * http://www.gnu.org/software/autoconf/manual/autoconf.html#Particular-Functions  *  * The only modifications were to remove C++ support and guard against  * redefining alloca.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ALLOCA_H
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
name|__GNUC__
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
name|_AIX
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_define
define|#
directive|define
name|alloca
value|__alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
name|_MSC_VER
end_elif

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_define
define|#
directive|define
name|alloca
value|_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EREALLOC_IMPL
end_ifdef

begin_define
define|#
directive|define
name|EREALLOC_CALLSITE
end_define

begin_comment
comment|/* preserve __FILE__ and __LINE__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EREALLOC_IMPL
parameter_list|(
name|ptr
parameter_list|,
name|newsz
parameter_list|,
name|filenm
parameter_list|,
name|loc
parameter_list|)
define|\
value|realloc(ptr, (newsz))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|bzero(p, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|zero_mem
end_ifndef

begin_define
define|#
directive|define
name|zero_mem
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|memset(p, 0, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZERO
parameter_list|(
name|var
parameter_list|)
value|zero_mem(&(var), sizeof(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_MALLOC_H */
end_comment

end_unit

