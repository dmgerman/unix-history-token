begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- windows/PosixApi.h --------------------------------------*- C++ -*-===//
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
name|liblldb_Host_windows_PosixApi_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_windows_PosixApi_h
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"windows/PosixApi.h being #included on non Windows system!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// va_start, va_end, etc macros.
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// time_t, timespec, etc.
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

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

begin_comment
comment|// PRIxxx format macros for printf()
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|// open(), close(), creat(), etc.
end_comment

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

begin_comment
comment|// pyconfig.h typedefs this.  We require python headers to be included before
end_comment

begin_comment
comment|// any LLDB headers, but there's no way to prevent python's pid_t definition
end_comment

begin_comment
comment|// from leaking, so this is the best option.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_PID_T
end_ifndef

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
name|S_IFDIR
value|_S_IFDIR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)&S_IFMT) == S_IFDIR)
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
comment|// _MSC_VER
end_comment

begin_comment
comment|// Various useful posix functions that are not present in Windows.  We provide
end_comment

begin_comment
comment|// custom implementations.
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

begin_comment
comment|// empty functions
end_comment

begin_function
specifier|inline
name|int
name|posix_openpt
parameter_list|(
name|int
name|flag
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|int
name|strerror_r
parameter_list|(
name|int
name|errnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|int
name|unlockpt
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|int
name|grantpt
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|char
modifier|*
name|ptsname
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|pid_t
name|fork
parameter_list|(
name|void
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|pid_t
name|setsid
parameter_list|(
name|void
parameter_list|)
block|{
name|LLVM_BUILTIN_UNREACHABLE
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

