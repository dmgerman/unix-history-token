begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h -- Configuration file for bash. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VOID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NO_VOID
end_ifdef

begin_define
define|#
directive|define
name|VOID
value|char
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
value|void
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
name|__GNUC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ALLOCA
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUILDING_MAKEFILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ALLOCA
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUILDING_MAKEFILE
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|UNIXPC
argument_list|)
operator|||
name|defined
argument_list|(
name|Xenix
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_define
define|#
directive|define
name|USG
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
name|HAVE_UNISTD_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BUILDING_MAKEFILE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define JOB_CONTROL if your operating system supports    BSD-like job control. */
end_comment

begin_define
define|#
directive|define
name|JOB_CONTROL
end_define

begin_comment
comment|/* Note that vanilla System V machines don't support BSD job control,    although some do support Posix job control. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_JOB_CONTROL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|JOB_CONTROL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_comment
comment|/* Define ALIAS if you want the alias features. */
end_comment

begin_define
define|#
directive|define
name|ALIAS
end_define

begin_comment
comment|/* Define PUSHD_AND_POPD if you want those commands to be compiled in.    (Also the `dirs' commands.) */
end_comment

begin_define
define|#
directive|define
name|PUSHD_AND_POPD
end_define

begin_comment
comment|/* Define READLINE to get the nifty/glitzy editing features.    This is on by default.  You can turn it off interactively    with the -nolineediting flag. */
end_comment

begin_define
define|#
directive|define
name|READLINE
end_define

begin_comment
comment|/* If READLINE is defined, right now we assume that you have the full    source code.  If you simply have the library and header files installed,    then undefine HAVE_READLINE_SOURCE. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_READLINE_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READLINE */
end_comment

begin_comment
comment|/* The default value of the PATH variable. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PATH_VALUE
define|\
value|":/usr/gnu/bin:/usr/local/bin:/usr/ucb:/bin:/usr/bin:/etc:/usr/etc"
end_define

begin_comment
comment|/* The value for PATH when invoking `command -p'.  This is only used when    the Posix.2 confstr () function, or CS_PATH define are not present. */
end_comment

begin_define
define|#
directive|define
name|STANDARD_UTILS_PATH
define|\
value|"/bin:/usr/bin:/usr/ucb:/usr/sbin:/etc:/usr/etc"
end_define

begin_comment
comment|/* Define V9_ECHO if you want to give the echo builtin backslash-escape    interpretation using the -e option, in the style of the Bell Labs 9th    Edition version of echo. */
end_comment

begin_define
define|#
directive|define
name|V9_ECHO
end_define

begin_comment
comment|/* Define CONTINUE_AFTER_KILL_ERROR if you want the kill command to    continue processing arguments after one of them fails. */
end_comment

begin_define
define|#
directive|define
name|CONTINUE_AFTER_KILL_ERROR
end_define

begin_comment
comment|/* Define BREAK_COMPLAINS if you want the non-standard, but useful    error messages about `break' and `continue' out of context. */
end_comment

begin_define
define|#
directive|define
name|BREAK_COMPLAINS
end_define

begin_comment
comment|/* Define GETOPTS_BUILTIN if you want the Posix.2 `getopts' shell builtin    compiled into the shell. */
end_comment

begin_define
define|#
directive|define
name|GETOPTS_BUILTIN
end_define

begin_comment
comment|/* When ALLOW_RIGID_POSIX_COMPLIANCE is defined, you can turn on strictly    Posix compliant behaviour by setting the environment variable    POSIX_PEDANTIC. */
end_comment

begin_define
define|#
directive|define
name|ALLOW_RIGID_POSIX_COMPLIANCE
end_define

begin_comment
comment|/* Define DISABLED_BUILTINS if you want "builtin foo" to always run the    shell builtin "foo", even if it has been disabled with "enable -n foo". */
end_comment

begin_comment
comment|/* #define DISABLED_BUILTINS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONFIG_ */
end_comment

end_unit

