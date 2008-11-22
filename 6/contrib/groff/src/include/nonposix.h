begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.      Written by Eli Zaretskii (eliz@is.elta.co.il)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA. */
end_comment

begin_comment
comment|/* This header file compartmentalize all idiosyncrasies of non-Posix    systems, such as MS-DOS, MS-Windows, etc.  It should be loaded after    the system headers like stdio.h to protect against warnings and error    messages w.r.t. redefining macros. */
end_comment

begin_if
if|#
directive|if
name|defined
name|_MSC_VER
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_define
define|#
directive|define
name|_WIN32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__EMX__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_UWIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
end_if

begin_comment
comment|/* Binary I/O nuisances. */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRECT_H
end_ifdef

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PROCESS_H
end_ifdef

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_if

begin_define
define|#
directive|define
name|POPEN_RT
value|"rt"
end_define

begin_define
define|#
directive|define
name|POPEN_WT
value|"wt"
end_define

begin_define
define|#
directive|define
name|popen
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|_popen(c,m)
end_define

begin_define
define|#
directive|define
name|pclose
parameter_list|(
name|p
parameter_list|)
value|_pclose(p)
end_define

begin_define
define|#
directive|define
name|pipe
parameter_list|(
name|pfd
parameter_list|)
value|_pipe((pfd),0,_O_BINARY|_O_NOINHERIT)
end_define

begin_define
define|#
directive|define
name|mkdir
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|_mkdir(p)
end_define

begin_define
define|#
directive|define
name|setmode
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|_setmode(f,m)
end_define

begin_define
define|#
directive|define
name|WAIT
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|,
name|m
parameter_list|)
value|_cwait(s,p,m)
end_define

begin_define
define|#
directive|define
name|creat
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|_creat(p,m)
end_define

begin_define
define|#
directive|define
name|read
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|_read(f,b,s)
end_define

begin_define
define|#
directive|define
name|write
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|_write(f,b,s)
end_define

begin_define
define|#
directive|define
name|dup
parameter_list|(
name|f
parameter_list|)
value|_dup(f)
end_define

begin_define
define|#
directive|define
name|dup2
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
value|_dup2(f1,f2)
end_define

begin_define
define|#
directive|define
name|close
parameter_list|(
name|f
parameter_list|)
value|_close(f)
end_define

begin_define
define|#
directive|define
name|isatty
parameter_list|(
name|f
parameter_list|)
value|_isatty(f)
end_define

begin_define
define|#
directive|define
name|access
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|_access(p,m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|do {if (!isatty(f)) setmode(f,O_BINARY);} while(0)
end_define

begin_define
define|#
directive|define
name|FOPEN_RB
value|"rb"
end_define

begin_define
define|#
directive|define
name|FOPEN_WB
value|"wb"
end_define

begin_define
define|#
directive|define
name|FOPEN_RWB
value|"wb+"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_O_BINARY
end_ifdef

begin_define
define|#
directive|define
name|O_BINARY
value|(_O_BINARY)
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
comment|/* The system shell.  Groff assumes a Unixy shell, but non-Posix    systems don't have standard places where it lives, and might not    have it installed to begin with.  We want to give them some leeway.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_define
define|#
directive|define
name|getcwd
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|_getcwd2(b,s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BSHELL
value|(system_shell_name())
end_define

begin_define
define|#
directive|define
name|BSHELL_DASH_C
value|(system_shell_dash_c())
end_define

begin_define
define|#
directive|define
name|IS_BSHELL
parameter_list|(
name|s
parameter_list|)
value|(is_system_shell(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The separator for directories in PATH and other environment    variables.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SEP
value|";"
end_define

begin_define
define|#
directive|define
name|PATH_SEP_CHAR
value|';'
end_define

begin_comment
comment|/* Characters that separate directories in a path name.  */
end_comment

begin_define
define|#
directive|define
name|DIR_SEPS
value|"/\\:"
end_define

begin_comment
comment|/* How to tell if the argument is an absolute file name.  */
end_comment

begin_define
define|#
directive|define
name|IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
define|\
value|((f)[0] == '/' || (f)[0] == '\\' || (f)[0]&& (f)[1] == ':')
end_define

begin_comment
comment|/* The executable extension.  */
end_comment

begin_define
define|#
directive|define
name|EXE_EXT
value|".exe"
end_define

begin_comment
comment|/* Possible executable extensions.  */
end_comment

begin_define
define|#
directive|define
name|PATH_EXT
value|".com;.exe;.bat;.cmd"
end_define

begin_comment
comment|/* The system null device.  */
end_comment

begin_define
define|#
directive|define
name|NULL_DEV
value|"NUL"
end_define

begin_comment
comment|/* The default place to create temporary files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P_tmpdir
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_P_tmpdir
end_ifdef

begin_define
define|#
directive|define
name|P_tmpdir
value|_P_tmpdir
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P_tmpdir
value|"c:/temp"
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
comment|/* Prototypes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|char
modifier|*
name|system_shell_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|system_shell_dash_c
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|is_system_shell
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_UWIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_comment
comment|/* Win32 implementations which use the Microsoft runtime library  * are prone to hanging when a pipe reader quits with unread data in the pipe.  * `gtroff' avoids this, by invoking `FLUSH_INPUT_PIPE()', defined as ... */
end_comment

begin_define
define|#
directive|define
name|FLUSH_INPUT_PIPE
parameter_list|(
name|fd
parameter_list|)
define|\
value|do if (!isatty(fd))			      \  {					      \    char drain[BUFSIZ];			      \    while (read(fd, drain, sizeof(drain))> 0) \      ;					      \  } while (0)
end_define

begin_comment
comment|/* The Microsoft runtime library also has a broken argument passing mechanism,  * which may result in improper grouping of arguments passed to a child process  * by the `spawn()' family of functions.  In `groff', only the `spawnvp()'  * function is affected; we work around this defect, by substituting a  * wrapper function in place of `spawnvp()' calls. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|int
name|spawnvp_wrapper
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SPAWN_FUNCTION_WRAPPERS
end_ifndef

begin_undef
undef|#
directive|undef
name|spawnvp
end_undef

begin_define
define|#
directive|define
name|spawnvp
value|spawnvp_wrapper
end_define

begin_undef
undef|#
directive|undef
name|_spawnvp
end_undef

begin_define
define|#
directive|define
name|_spawnvp
value|spawnvp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPAWN_FUNCTION_WRAPPERS */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Other implementations do not suffer from Microsoft runtime bugs,  * but `gtroff' requires a dummy definition for FLUSH_INPUT_PIPE() */
end_comment

begin_define
define|#
directive|define
name|FLUSH_INPUT_PIPE
parameter_list|(
name|fd
parameter_list|)
value|do {} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defaults, for Posix systems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SET_BINARY
end_ifndef

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|do {} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_RB
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_RB
value|"r"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_WB
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_WB
value|"w"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_RWB
end_ifndef

begin_define
define|#
directive|define
name|FOPEN_RWB
value|"w+"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|POPEN_RT
end_ifndef

begin_define
define|#
directive|define
name|POPEN_RT
value|"r"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|POPEN_WT
end_ifndef

begin_define
define|#
directive|define
name|POPEN_WT
value|"w"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSHELL
end_ifndef

begin_define
define|#
directive|define
name|BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSHELL_DASH_C
end_ifndef

begin_define
define|#
directive|define
name|BSHELL_DASH_C
value|"-c"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IS_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|IS_BSHELL
parameter_list|(
name|s
parameter_list|)
value|((s)&& strcmp(s,BSHELL) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_SEP
end_ifndef

begin_define
define|#
directive|define
name|PATH_SEP
value|":"
end_define

begin_define
define|#
directive|define
name|PATH_SEP_CHAR
value|':'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPS
end_ifndef

begin_define
define|#
directive|define
name|DIR_SEPS
value|"/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IS_ABSOLUTE
end_ifndef

begin_define
define|#
directive|define
name|IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
value|((f)[0] == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXE_EXT
end_ifndef

begin_define
define|#
directive|define
name|EXE_EXT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_EXT
end_ifndef

begin_define
define|#
directive|define
name|PATH_EXT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_DEV
end_ifndef

begin_define
define|#
directive|define
name|NULL_DEV
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GS_NAME
end_ifndef

begin_define
define|#
directive|define
name|GS_NAME
value|"gs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WAIT
end_ifndef

begin_define
define|#
directive|define
name|WAIT
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|,
name|m
parameter_list|)
value|wait(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WAIT_CHILD
end_ifndef

begin_define
define|#
directive|define
name|_WAIT_CHILD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

