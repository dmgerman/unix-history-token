begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mac MPW host-specific definitions. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INCLUDE_MPW_H
end_ifndef

begin_define
define|#
directive|define
name|__INCLUDE_MPW_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MPW
end_ifndef

begin_define
define|#
directive|define
name|MPW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPW C is basically ANSI, but doesn't actually enable __STDC__,    nor does it allow __STDC__ to be #defined. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALMOST_STDC
end_ifndef

begin_define
define|#
directive|define
name|ALMOST_STDC
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|HAVE_TIME_T_IN_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MW_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<unix.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|fileno
end_ifndef

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|fp
parameter_list|)
value|((fp)->_file)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stdio.h does not define this if __STDC__, so define here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|FILE
modifier|*
name|fdopen
parameter_list|(
name|int
name|fildes
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_MW_HEADERS */
end_comment

begin_comment
comment|/* Add ersatz definitions, for systems that lack them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EIO
end_ifndef

begin_define
define|#
directive|define
name|EIO
value|96
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOENT
end_ifndef

begin_define
define|#
directive|define
name|ENOENT
value|97
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EACCES
end_ifndef

begin_define
define|#
directive|define
name|EACCES
value|98
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOSYS
end_ifndef

begin_define
define|#
directive|define
name|ENOSYS
value|99
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Binary files have different characteristics; for instance, no cr/nl    translation. */
end_comment

begin_define
define|#
directive|define
name|USE_BINARY_FOPEN
end_define

begin_include
include|#
directive|include
file|<spin.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MPW_C
end_ifdef

begin_undef
undef|#
directive|undef
name|__PTR_TO_INT
end_undef

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((int)(P))
end_define

begin_undef
undef|#
directive|undef
name|__INT_TO_PTR
end_undef

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((char *)(P))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPW_C */
end_comment

begin_define
define|#
directive|define
name|NO_FCNTL
end_define

begin_function_decl
name|int
name|fstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|mpw_fopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpw_fseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpw_fread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpw_fwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpw_access
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpw_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mpw_creat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpw_abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map these standard functions to improved versions in libiberty. */
end_comment

begin_define
define|#
directive|define
name|fopen
value|mpw_fopen
end_define

begin_define
define|#
directive|define
name|fseek
value|mpw_fseek
end_define

begin_define
define|#
directive|define
name|fread
value|mpw_fread
end_define

begin_define
define|#
directive|define
name|fwrite
value|mpw_fwrite
end_define

begin_define
define|#
directive|define
name|open
value|mpw_open
end_define

begin_define
define|#
directive|define
name|access
value|mpw_access
end_define

begin_define
define|#
directive|define
name|creat
value|mpw_creat
end_define

begin_define
define|#
directive|define
name|abort
value|mpw_abort
end_define

begin_define
define|#
directive|define
name|POSIX_UTIME
end_define

begin_define
define|#
directive|define
name|LOSING_TOTALLY
end_define

begin_comment
comment|/* Define this so that files will be closed before being unlinked. */
end_comment

begin_define
define|#
directive|define
name|CLOSE_BEFORE_UNLINK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INCLUDE_MPW_H */
end_comment

end_unit

