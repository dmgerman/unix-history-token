begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_comment
comment|/* Stupid SunOS 4 doesn't have prototypes in the header files */
end_comment

begin_comment
comment|/* Some includes just to make the compiler be quiet */
end_comment

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
file|<sys/socket.h>
end_include

begin_function_decl
specifier|extern
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_flsbuf
parameter_list|(
name|unsigned
name|char
name|c
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|puts
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|bufsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|perror
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|socket
parameter_list|(
name|int
name|af
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|protocol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bind
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__svr4__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NEED_GETHOSTNAME
end_define

begin_define
define|#
directive|define
name|NEED_SVCSOC_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux__
argument_list|)
end_if

begin_comment
comment|/* HP is really... Ah well. */
end_comment

begin_define
define|#
directive|define
name|_INCLUDE_HPUX_SOURCE
end_define

begin_define
define|#
directive|define
name|_INCLUDE_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_INCLUDE_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|_INCLUDE_AES_SOURCE
end_define

begin_function_decl
specifier|extern
name|void
name|svcerr_systemerr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_comment
comment|/* Need this because some header files doesn't check for __linux__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|linux
argument_list|)
end_if

begin_define
define|#
directive|define
name|linux
value|linux
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Needed for non-ANSI prototypes */
end_comment

begin_define
define|#
directive|define
name|_SVID_SOURCE
end_define

begin_comment
comment|/* Needed for gethostname() */
end_comment

begin_define
define|#
directive|define
name|_BSD_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

