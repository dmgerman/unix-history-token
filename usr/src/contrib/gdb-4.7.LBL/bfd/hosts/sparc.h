begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
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
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY | O_WRONLY | O_RDWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_define
define|#
directive|define
name|abort
value|__hide_abort
end_define

begin_define
define|#
directive|define
name|exit
value|__hide_exit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_undef
undef|#
directive|undef
name|exit
end_undef

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|EXFUN
argument_list|(
name|mktemp
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|fflush
argument_list|,
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|write
argument_list|,
operator|(
name|int
operator|,
name|CONST
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|index
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|,
name|char
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|abort
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|close
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|fcntl
argument_list|,
operator|(
name|int
name|des
operator|,
name|int
name|cmd
operator|,
name|int
name|e
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|fprintf
argument_list|,
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|printf
argument_list|,
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|qsort
argument_list|,
operator|(
name|void
operator|*
name|data
operator|,
name|int
name|els
operator|,
name|int
name|siz
operator|,
name|int
name|func
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|exit
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|fseek
argument_list|,
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|fclose
argument_list|,
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|bcopy
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|bcmp
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|bzero
argument_list|,
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|memset
argument_list|,
operator|(
name|PTR
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|puts
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|fputs
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|rmdir
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|getuid
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|getgid
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|rename
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|,
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|etuid
argument_list|,
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|etgid
argument_list|,
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|perror
argument_list|,
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DONTDECLARE_MALLOC
end_ifndef

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|malloc
argument_list|,
operator|(
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|realloc
argument_list|,
operator|(
name|PTR
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|memcpy
argument_list|,
operator|(
name|PTR
operator|,
name|CONST
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* char * EXFUN( memcpy,(char *,CONST char *,unsigned int)); */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|memchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sscanf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strtol
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|free
argument_list|,
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_flsbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|utimes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vfprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fputc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unlink
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* EXACT TYPES */
end_comment

begin_typedef
typedef|typedef
name|char
name|int8e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32e_type
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64e_type
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32e_type
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
name|uint64e_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CORRECT SIZE OR GREATER */
end_comment

begin_typedef
typedef|typedef
name|char
name|int8_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_type
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int64_type
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32e_type
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
name|uint64_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32e_type
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
name|int64_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BYTES_IN_PRINTF_INT
value|4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|uint64_typeLOW
parameter_list|(
name|x
parameter_list|)
value|(uint32_type)(((x).low))
end_define

begin_define
define|#
directive|define
name|uint64_typeHIGH
parameter_list|(
name|x
parameter_list|)
value|(uint32_type)(((x).high))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|uint64_typeLOW
parameter_list|(
name|x
parameter_list|)
value|(uint32_type)(((x)& 0xffffffff))
end_define

begin_define
define|#
directive|define
name|uint64_typeHIGH
parameter_list|(
name|x
parameter_list|)
value|(uint32_type)(((x)>> 32)& 0xffffffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"fopen-same.h"
end_include

end_unit

