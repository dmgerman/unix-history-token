begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is needed by libio to define various configuration parameters.    These are always the same in the GNU C library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_config_h
end_ifndef

begin_define
define|#
directive|define
name|_G_config_h
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC
end_ifndef

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|_IO_MTSAFE_IO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define types for libio in terms of the standard internal type names.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|__need_size_t
end_define

begin_define
define|#
directive|define
name|__need_wchar_t
end_define

begin_define
define|#
directive|define
name|__need_wint_t
end_define

begin_define
define|#
directive|define
name|__need_NULL
end_define

begin_define
define|#
directive|define
name|__need_ptrdiff_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WINT_T
end_ifndef

begin_comment
comment|/* Integral type unchanged by default argument promotions that can    hold any value corresponding to members of the extended character    set, as well as at least one value that does not correspond to any    member of the extended character set.  */
end_comment

begin_define
define|#
directive|define
name|_WINT_T
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|wint_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For use as part of glibc (native) or as part of libstdc++ (maybe    not glibc) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__c_mbstate_t_defined
end_ifndef

begin_define
define|#
directive|define
name|__c_mbstate_t_defined
value|1
end_define

begin_comment
comment|/*# ifdef _GLIBCPP_USE_WCHAR_T*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|count
decl_stmt|;
name|wint_t
name|value
decl_stmt|;
block|}
name|__c_mbstate_t
typedef|;
end_typedef

begin_comment
comment|/*# endif*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__need_mbstate_t
end_undef

begin_typedef
typedef|typedef
name|size_t
name|_G_size_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|_GLIBCPP_USE_WCHAR_T
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
name|__off_t
name|__pos
decl_stmt|;
name|__c_mbstate_t
name|__state
decl_stmt|;
block|}
name|_G_fpos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__off64_t
name|__pos
decl_stmt|;
name|__c_mbstate_t
name|__state
decl_stmt|;
block|}
name|_G_fpos64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__off_t
name|_G_fpos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__off64_t
name|_G_fpos64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_G_ssize_t
value|__ssize_t
end_define

begin_define
define|#
directive|define
name|_G_off_t
value|__off_t
end_define

begin_define
define|#
directive|define
name|_G_off64_t
value|__off64_t
end_define

begin_define
define|#
directive|define
name|_G_pid_t
value|__pid_t
end_define

begin_define
define|#
directive|define
name|_G_uid_t
value|__uid_t
end_define

begin_define
define|#
directive|define
name|_G_wchar_t
value|wchar_t
end_define

begin_define
define|#
directive|define
name|_G_wint_t
value|wint_t
end_define

begin_define
define|#
directive|define
name|_G_stat64
value|stat64
end_define

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|_GLIBCPP_USE_WCHAR_T
end_if

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_typedef
typedef|typedef
name|iconv_t
name|_G_iconv_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|_G_int16_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|_G_int32_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__SI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint16_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_G_uint32_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__SI__
typedef|)));
end_typedef

begin_define
define|#
directive|define
name|_G_HAVE_BOOL
value|1
end_define

begin_comment
comment|/* These library features are always available in the GNU C library.  */
end_comment

begin_define
define|#
directive|define
name|_G_HAVE_ATEXIT
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_SYS_CDEFS
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_SYS_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|_G_NEED_STDARG_H
value|1
end_define

begin_define
define|#
directive|define
name|_G_va_list
value|__gnuc_va_list
end_define

begin_define
define|#
directive|define
name|_G_HAVE_PRINTF_FP
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_MMAP
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_LONG_DOUBLE_IO
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_IO_FILE_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|_G_HAVE_IO_GETLINE_INFO
value|1
end_define

begin_define
define|#
directive|define
name|_G_IO_IO_FILE_VERSION
value|0x20001
end_define

begin_comment
comment|//#define _G_OPEN64	__open64
end_comment

begin_comment
comment|//#define _G_LSEEK64	__lseek64
end_comment

begin_comment
comment|//#define _G_FSTAT64(fd,buf) __fxstat64 (_STAT_VER, fd, buf)
end_comment

begin_comment
comment|/* This is defined by<bits/stat.h> if `st_blksize' exists.  */
end_comment

begin_comment
comment|/*#define _G_HAVE_ST_BLKSIZE defined (_STATBUF_ST_BLKSIZE)*/
end_comment

begin_define
define|#
directive|define
name|_G_BUFSIZ
value|8192
end_define

begin_comment
comment|/* These are the vtbl details for ELF.  */
end_comment

begin_define
define|#
directive|define
name|_G_NAMES_HAVE_UNDERSCORE
value|0
end_define

begin_define
define|#
directive|define
name|_G_VTABLE_LABEL_HAS_LENGTH
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_G_USING_THUNKS
end_ifndef

begin_define
define|#
directive|define
name|_G_USING_THUNKS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_USING_THUNKS */
end_comment

begin_define
define|#
directive|define
name|_G_VTABLE_LABEL_PREFIX
value|"__vt_"
end_define

begin_define
define|#
directive|define
name|_G_VTABLE_LABEL_PREFIX_ID
value|__vt_
end_define

begin_define
define|#
directive|define
name|_G_INTERNAL_CCS
value|"UCS4"
end_define

begin_define
define|#
directive|define
name|_G_HAVE_WEAK_SYMBOL
value|1
end_define

begin_define
define|#
directive|define
name|_G_STDIO_USES_LIBIO
value|1
end_define

begin_if
if|#
directive|if
name|defined
name|__cplusplus
operator|||
name|defined
name|__STDC__
end_if

begin_define
define|#
directive|define
name|_G_ARGS
parameter_list|(
name|ARGLIST
parameter_list|)
value|ARGLIST
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_G_ARGS
parameter_list|(
name|ARGLIST
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_config.h */
end_comment

end_unit

