begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System V Release 4 Unix host system */
end_comment

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
file|<utime.h>
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

begin_define
define|#
directive|define
name|POSIX_UTIME
end_define

begin_define
define|#
directive|define
name|HAVE_PROCFS
end_define

begin_comment
comment|/* This host has /proc support */
end_comment

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
name|free
argument_list|,
operator|(
name|PTR
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
name|long
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
name|getgid
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
name|getuid
argument_list|,
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|chmod
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

begin_include
include|#
directive|include
file|"fopen-same.h"
end_include

end_unit

