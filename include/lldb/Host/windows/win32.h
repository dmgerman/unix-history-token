begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-win32.h --------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_lldb_win32_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_win32_h_
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|// posix utilities
end_comment

begin_function_decl
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcasestr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|find
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realpath
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|resolved
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|32768
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_NOCTTY
value|0
end_define

begin_define
define|#
directive|define
name|O_NONBLOCK
value|0
end_define

begin_define
define|#
directive|define
name|SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|SIGSTOP
value|20
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_comment
comment|/* read, user */
end_comment

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_comment
comment|/* write, user */
end_comment

begin_define
define|#
directive|define
name|S_IXUSR
value|0
end_define

begin_comment
comment|/* execute, user */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_IRGRP
value|0
end_define

begin_comment
comment|/* read, group */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|0
end_define

begin_comment
comment|/* write, group */
end_comment

begin_define
define|#
directive|define
name|S_IXGRP
value|0
end_define

begin_comment
comment|/* execute, group */
end_comment

begin_define
define|#
directive|define
name|S_IROTH
value|0
end_define

begin_comment
comment|/* read, others */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|0
end_define

begin_comment
comment|/* write, others */
end_comment

begin_define
define|#
directive|define
name|S_IXOTH
value|0
end_define

begin_comment
comment|/* execute, others */
end_comment

begin_define
define|#
directive|define
name|S_IRWXU
value|0
end_define

begin_define
define|#
directive|define
name|S_IRWXG
value|0
end_define

begin_define
define|#
directive|define
name|S_IRWXO
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|short
name|mode_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|LLDB_DISABLE_PYTHON
end_ifdef

begin_typedef
typedef|typedef
name|uint32_t
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_DISABLE_PYTHON
end_comment

begin_function_decl
name|int
name|usleep
parameter_list|(
name|uint32_t
name|useconds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chdir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dirname
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncasecmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1900
end_if

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|argptr
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// inline to avoid linkage conflicts
end_comment

begin_function
name|int
specifier|inline
name|snprintf
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|count
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|argptr
decl_stmt|;
name|va_start
argument_list|(
name|argptr
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|int
name|r
init|=
name|lldb_private
operator|::
name|vsnprintf
argument_list|(
name|buffer
argument_list|,
name|count
argument_list|,
name|format
argument_list|,
name|argptr
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|argptr
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_define
define|#
directive|define
name|__PRETTY_FUNCTION__
value|__FUNCSIG__
end_define

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
value|(((mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_comment
comment|// timespec
end_comment

begin_comment
comment|// MSVC 2015 and higher have timespec.  Otherwise we need to define it ourselves.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1900
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
name|long
name|tv_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_win32_h_
end_comment

end_unit

