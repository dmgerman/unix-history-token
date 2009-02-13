begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Time-stamp:        "2006-10-14 14:55:09 bkorb"  *             by: bkorb  * Last Committed:    $Date: 2007/04/28 22:19:23 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINDOWS_CONFIG_HACKERY
end_ifndef

begin_define
define|#
directive|define
name|WINDOWS_CONFIG_HACKERY
value|1
end_define

begin_comment
comment|/*  * The definitions below have been stolen from NTP's config.h for Windows.  * However, they may be kept here in order to keep libopts independent from  * the NTP project.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__windows__
end_ifndef

begin_define
define|#
directive|define
name|__windows__
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellaneous functions that Microsoft maps  * to other names  *  * #define inline __inline  * #define vsnprintf _vsnprintf  */
end_comment

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_comment
comment|/*  * #define stricmp _stricmp  * #define strcasecmp _stricmp  * #define isascii __isascii  * #define finite _finite  * #define random      rand  * #define srandom     srand  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_CHARP
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uintptr_t
typedef|;
end_typedef

begin_comment
comment|/*  * # define HAVE_NET_IF_H  * # define QSORT_USES_VOID_P  * # define HAVE_SETVBUF  * # define HAVE_VSPRINTF  * # define HAVE_SNPRINTF  * # define HAVE_VSNPRINTF  * # define HAVE_PROTOTYPES             /* from ntpq.mak * /  * # define HAVE_MEMMOVE  * # define HAVE_TERMIOS_H  * # define HAVE_ERRNO_H  * # define HAVE_STDARG_H  * # define HAVE_NO_NICE  * # define HAVE_MKTIME  * # define TIME_WITH_SYS_TIME  * # define HAVE_IO_COMPLETION_PORT  * # define ISC_PLATFORM_NEEDNTOP  * # define ISC_PLATFORM_NEEDPTON  * # define NEED_S_CHAR_TYPEDEF  * # define USE_PROTOTYPES              /* for ntp_types.h * /  *  * #define ULONG_CONST(a) a ## UL  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/*  * VS.NET's version of wspiapi.h has a bug in it  * where it assigns a value to a variable inside  * an if statement. It should be comparing them.  * We prevent inclusion since we are not using this  * code so we don't have to see the warning messages  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WSPIAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_WSPIAPI_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prevent inclusion of winsock.h in windows.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINSOCKAPI_
end_ifndef

begin_define
define|#
directive|define
name|_WINSOCKAPI_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RPCASYNC_H__
end_ifndef

begin_define
define|#
directive|define
name|__RPCASYNC_H__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include Windows headers */
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/*  * Compatibility declarations for Windows, assuming SYS_WINNT  * has been defined.  */
end_comment

begin_define
define|#
directive|define
name|strdup
value|_strdup
end_define

begin_define
define|#
directive|define
name|stat
value|_stat
end_define

begin_comment
comment|/* struct stat from<sys/stat.h> */
end_comment

begin_define
define|#
directive|define
name|unlink
value|_unlink
end_define

begin_define
define|#
directive|define
name|fchmod
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|ssize_t
value|SSIZE_T
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|write
value|_write
end_define

begin_define
define|#
directive|define
name|lseek
value|_lseek
end_define

begin_define
define|#
directive|define
name|pipe
value|_pipe
end_define

begin_define
define|#
directive|define
name|dup2
value|_dup2
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|_O_RDWR
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
end_define

begin_define
define|#
directive|define
name|O_EXCL
value|_O_EXCL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_IFREG
value|_S_IFREG
end_define

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFREG) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_IFDIR
value|_S_IFDIR
end_define

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFDIR) == S_IFDIR)
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
comment|/* WINDOWS_CONFIG_HACKERY */
end_comment

end_unit

