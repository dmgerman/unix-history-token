begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Platform.h ----------------------------------------------*- C++ -*-===//
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
name|lldb_Platform_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Platform_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|// this will stop signal.h being included
end_comment

begin_define
define|#
directive|define
name|_INC_SIGNAL
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<eh.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|"lldb/Host/windows/Windows.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostGetOpt.h"
end_include

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|winsize
block|{
name|long
name|ws_col
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|tcflag_t
typedef|;
end_typedef

begin_comment
comment|// fcntl.h
end_comment

begin_define
define|#
directive|define
name|O_NOCTTY
value|0400
end_define

begin_comment
comment|// ioctls.h
end_comment

begin_define
define|#
directive|define
name|TIOCGWINSZ
value|0x5413
end_define

begin_comment
comment|// signal.h
end_comment

begin_define
define|#
directive|define
name|SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|SIGCONT
value|18
end_define

begin_define
define|#
directive|define
name|SIGTSTP
value|20
end_define

begin_define
define|#
directive|define
name|SIGWINCH
value|28
end_define

begin_comment
comment|// tcsetattr arguments
end_comment

begin_define
define|#
directive|define
name|TCSANOW
value|0
end_define

begin_define
define|#
directive|define
name|NCCS
value|32
end_define

begin_struct
struct|struct
name|termios
block|{
name|tcflag_t
name|c_iflag
decl_stmt|;
comment|// input mode flags
name|tcflag_t
name|c_oflag
decl_stmt|;
comment|// output mode flags
name|tcflag_t
name|c_cflag
decl_stmt|;
comment|// control mode flags
name|tcflag_t
name|c_lflag
decl_stmt|;
comment|// local mode flags
name|cc_t
name|c_line
decl_stmt|;
comment|// line discipline
name|cc_t
name|c_cc
index|[
name|NCCS
index|]
decl_stmt|;
comment|// control characters
name|speed_t
name|c_ispeed
decl_stmt|;
comment|// input speed
name|speed_t
name|c_ospeed
decl_stmt|;
comment|// output speed
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|long
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_define
define|#
directive|define
name|PATH_MAX
value|MAX_PATH
end_define

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_function_decl
specifier|extern
name|int
name|ioctl
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|request
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kill
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcsetattr
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|optional_actions
parameter_list|,
specifier|const
name|struct
name|termios
modifier|*
name|termios_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcgetattr
parameter_list|(
name|int
name|fildes
parameter_list|,
name|struct
name|termios
modifier|*
name|termios_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// signal handler function pointer type
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sighandler_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// signal.h
end_comment

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_comment
comment|// default handler
end_comment

begin_define
define|#
directive|define
name|SIG_DFL
value|( (sighandler_t) -1 )
end_define

begin_comment
comment|// ignored
end_comment

begin_define
define|#
directive|define
name|SIG_IGN
value|( (sighandler_t) -2 )
end_define

begin_function_decl
specifier|extern
name|sighandler_t
name|signal
parameter_list|(
name|int
name|sig
parameter_list|,
name|sighandler_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_include
include|#
directive|include
file|<libgen.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<histedit.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<readline/readline.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<editline/readline.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_Platform_h_
end_comment

end_unit

