begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* std.h -    Include standard header files. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STD_H
end_ifndef

begin_define
define|#
directive|define
name|STD_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUBDOC
end_ifdef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUPPORT_SUBDOC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDDEF_H_MISSING
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDDEF_H_MISSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIMITS_H_MISSING
end_ifndef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not LIMITS_H_MISSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UINT_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT_MAX
value|(sizeof(unsigned int) == 2 ? 0x7fff : \   (sizeof(unsigned int) == 4 ? 0x7fffffff : cant_guess_UINT_MAX))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_STRINGS
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|bcopy(from, to, n)
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|,
name|n
parameter_list|)
value|bcmp(p, q, n)
end_define

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|index(s, c)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|rindex(s, c)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BSD_STRINGS */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BSD_STRINGS */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|STDLIB_H_MISSING
end_ifdef

begin_function_decl
name|UNIV
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|UNIV
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|UNIV
name|realloc
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

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STDLIB_H_MISSING */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDLIB_H_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REMOVE_MISSING
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_define
define|#
directive|define
name|remove
value|unlink
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REMOVE_MISSING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RAISE_MISSING
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_define
define|#
directive|define
name|raise
parameter_list|(
name|sig
parameter_list|)
value|kill(getpid(), sig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAISE_MISSING */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((size_t)&((TYPE *)0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FPOS_MISSING
end_ifdef

begin_typedef
typedef|typedef
name|long
name|fpos_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fsetpos
parameter_list|(
name|stream
parameter_list|,
name|pos
parameter_list|)
value|fseek(stream, *(pos), SEEK_SET)
end_define

begin_define
define|#
directive|define
name|fgetpos
parameter_list|(
name|stream
parameter_list|,
name|pos
parameter_list|)
value|((*(pos) = ftell(stream)) == -1L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FPOS_MISSING */
end_comment

begin_comment
comment|/* Old BSD systems lack L_tmpnam and tmpnam().  This is a partial emulation using mktemp().  It requires that the argument to tmpnam() be non-NULL. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|L_tmpnam
end_ifndef

begin_define
define|#
directive|define
name|tmpnam_template
value|"/tmp/sgmlsXXXXXX"
end_define

begin_define
define|#
directive|define
name|L_tmpnam
value|(sizeof(tmpnam_template))
end_define

begin_undef
undef|#
directive|undef
name|tmpnam
end_undef

begin_define
define|#
directive|define
name|tmpnam
parameter_list|(
name|buf
parameter_list|)
define|\
value|(mktemp(strcpy(buf, tmpnam_template)) == 0 || (buf)[0] == '\0' ? 0 : (buf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not L_tmpnam */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STD_H */
end_comment

end_unit

