begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* init.c    Initialize the system dependent routines.     Copyright (C) 1991, 1992, 1993, 1994 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uudefs.h"
end_include

begin_include
include|#
directive|include
file|"uuconf.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_FILE_H
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_GETHOSTNAME
operator|&&
name|HAVE_UNAME
end_if

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use getcwd in preference to getwd; if we have neither, we will be    using a getcwd replacement.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_GETCWD
end_if

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_define
define|#
directive|define
name|HAVE_GETWD
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_GETCWD */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_GETWD
end_if

begin_undef
undef|#
directive|undef
name|HAVE_GETCWD
end_undef

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_GETWD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_GETCWD */
end_comment

begin_if
if|#
directive|if
name|HAVE_GETWD
end_if

begin_comment
comment|/* Get a value for MAXPATHLEN.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_PARAMS_H
end_if

begin_include
include|#
directive|include
file|<sys/params.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (PATH_MAX) */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (PATH_MAX) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (MAXPATHLEN) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GETWD */
end_comment

begin_comment
comment|/* External functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|getlogin
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getlogin
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
name|GETPWNAM_DECLARATION_OK
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|getpwnam
end_ifndef

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
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

begin_if
if|#
directive|if
name|GETPWUID_DECLARATION_OK
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|getpwuid
end_ifndef

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
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

begin_if
if|#
directive|if
name|HAVE_GETCWD
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|getcwd
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
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

begin_if
if|#
directive|if
name|HAVE_GETWD
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|getwd
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
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

begin_if
if|#
directive|if
name|HAVE_SYSCONF
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|sysconf
end_ifndef

begin_function_decl
specifier|extern
name|long
name|sysconf
parameter_list|()
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

begin_escape
end_escape

begin_comment
comment|/* Initialize the system dependent routines.  We will probably be running    suid to uucp, so we make sure that nothing is obviously wrong.  We    save the login name since we will be losing the real uid.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|zSlogin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The UUCP spool directory.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|zSspooldir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The UUCP lock directory.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|zSlockdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The local UUCP name.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|zSlocalname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We save the current directory since we will do a chdir to the    spool directory.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|zScwd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The maximum length of a system name is controlled by the type of spool    directory we use.  */
end_comment

begin_if
if|#
directive|if
name|SPOOLDIR_V2
operator|||
name|SPOOLDIR_BSD42
operator|||
name|SPOOLDIR_BSD43
operator|||
name|SPOOLDIR_ULTRIX
end_if

begin_decl_stmt
name|size_t
name|cSysdep_max_name_len
init|=
literal|7
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SPOOLDIR_HDB
operator|||
name|SPOOLDIR_SVR4
end_if

begin_decl_stmt
name|size_t
name|cSysdep_max_name_len
init|=
literal|14
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SPOOLDIR_TAYLOR
end_if

begin_if
if|#
directive|if
name|HAVE_LONG_FILE_NAMES
end_if

begin_decl_stmt
name|size_t
name|cSysdep_max_name_len
init|=
literal|255
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_LONG_FILE_NAMES */
end_comment

begin_decl_stmt
name|size_t
name|cSysdep_max_name_len
init|=
literal|14
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_LONG_FILE_NAMES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPOOLDIR_TAYLOR */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Initialize the system dependent routines.  */
end_comment

begin_function
name|void
name|usysdep_initialize
parameter_list|(
name|puuconf
parameter_list|,
name|iflags
parameter_list|)
name|pointer
name|puuconf
decl_stmt|;
name|int
name|iflags
decl_stmt|;
block|{
name|int
name|iuuconf
decl_stmt|;
name|char
modifier|*
name|z
decl_stmt|;
name|struct
name|passwd
modifier|*
name|q
decl_stmt|;
name|ulog_id
argument_list|(
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|iflags
operator|&
name|INIT_NOCLOSE
operator|)
operator|==
literal|0
condition|)
block|{
name|int
name|cdescs
decl_stmt|;
name|int
name|o
decl_stmt|;
comment|/* Close everything but stdin, stdout and stderr.  */
if|#
directive|if
name|HAVE_GETDTABLESIZE
name|cdescs
operator|=
name|getdtablesize
argument_list|()
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|HAVE_SYSCONF
name|cdescs
operator|=
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|OPEN_MAX
name|cdescs
operator|=
name|OPEN_MAX
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|NOFILE
name|cdescs
operator|=
name|NOFILE
expr_stmt|;
else|#
directive|else
name|cdescs
operator|=
literal|20
expr_stmt|;
endif|#
directive|endif
comment|/* ! defined (NOFILE) */
endif|#
directive|endif
comment|/* ! defined (OPEN_MAX) */
endif|#
directive|endif
comment|/* ! HAVE_SYSCONF */
endif|#
directive|endif
comment|/* ! HAVE_GETDTABLESIZE */
for|for
control|(
name|o
operator|=
literal|3
init|;
name|o
operator|<
name|cdescs
condition|;
name|o
operator|++
control|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|o
argument_list|)
expr_stmt|;
block|}
comment|/* Make sure stdin, stdout and stderr are open.  */
if|if
condition|(
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_GETFD
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
operator|&&
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_DEVNULL
argument_list|,
name|O_RDONLY
argument_list|,
literal|0
argument_list|)
operator|!=
literal|0
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
if|if
condition|(
name|fcntl
argument_list|(
literal|1
argument_list|,
name|F_GETFD
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
operator|&&
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_DEVNULL
argument_list|,
name|O_WRONLY
argument_list|,
literal|0
argument_list|)
operator|!=
literal|1
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
if|if
condition|(
name|fcntl
argument_list|(
literal|2
argument_list|,
name|F_GETFD
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
operator|&&
name|open
argument_list|(
operator|(
name|char
operator|*
operator|)
name|_PATH_DEVNULL
argument_list|,
name|O_WRONLY
argument_list|,
literal|0
argument_list|)
operator|!=
literal|2
condition|)
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
name|iuuconf
operator|=
name|uuconf_spooldir
argument_list|(
name|puuconf
argument_list|,
operator|&
name|zSspooldir
argument_list|)
expr_stmt|;
if|if
condition|(
name|iuuconf
operator|!=
name|UUCONF_SUCCESS
condition|)
name|ulog_uuconf
argument_list|(
name|LOG_FATAL
argument_list|,
name|puuconf
argument_list|,
name|iuuconf
argument_list|)
expr_stmt|;
name|iuuconf
operator|=
name|uuconf_lockdir
argument_list|(
name|puuconf
argument_list|,
operator|&
name|zSlockdir
argument_list|)
expr_stmt|;
if|if
condition|(
name|iuuconf
operator|!=
name|UUCONF_SUCCESS
condition|)
name|ulog_uuconf
argument_list|(
name|LOG_FATAL
argument_list|,
name|puuconf
argument_list|,
name|iuuconf
argument_list|)
expr_stmt|;
name|iuuconf
operator|=
name|uuconf_localname
argument_list|(
name|puuconf
argument_list|,
operator|&
name|zSlocalname
argument_list|)
expr_stmt|;
if|if
condition|(
name|iuuconf
operator|==
name|UUCONF_NOT_FOUND
condition|)
block|{
if|#
directive|if
name|HAVE_GETHOSTNAME
name|char
name|ab
index|[
literal|256
index|]
decl_stmt|;
if|if
condition|(
name|gethostname
argument_list|(
name|ab
argument_list|,
sizeof|sizeof
name|ab
operator|-
literal|1
argument_list|)
operator|<
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"gethostname: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|ab
index|[
sizeof|sizeof
name|ab
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|ab
index|[
name|strcspn
argument_list|(
name|ab
argument_list|,
literal|"."
argument_list|)
index|]
operator|=
literal|'\0'
expr_stmt|;
name|zSlocalname
operator|=
name|zbufcpy
argument_list|(
name|ab
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ! HAVE_GETHOSTNAME */
if|#
directive|if
name|HAVE_UNAME
name|struct
name|utsname
name|s
decl_stmt|;
if|if
condition|(
name|uname
argument_list|(
operator|&
name|s
argument_list|)
operator|<
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"uname: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|zSlocalname
operator|=
name|zbufcpy
argument_list|(
name|s
operator|.
name|nodename
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ! HAVE_UNAME */
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"Don't know how to get local node name"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* ! HAVE_UNAME */
endif|#
directive|endif
comment|/* ! HAVE_GETHOSTNAME */
block|}
elseif|else
if|if
condition|(
name|iuuconf
operator|!=
name|UUCONF_SUCCESS
condition|)
name|ulog_uuconf
argument_list|(
name|LOG_FATAL
argument_list|,
name|puuconf
argument_list|,
name|iuuconf
argument_list|)
expr_stmt|;
comment|/* We always set our file modes to exactly what we want.  */
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Get the login name, making sure that it matches the uid.  Many      systems truncate the getlogin return value to 8 characters, but      keep the full name in the password file, so we prefer the name in      the password file.  */
name|z
operator|=
name|getenv
argument_list|(
literal|"LOGNAME"
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|==
name|NULL
condition|)
name|z
operator|=
name|getenv
argument_list|(
literal|"USER"
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|==
name|NULL
condition|)
name|z
operator|=
name|getlogin
argument_list|()
expr_stmt|;
if|if
condition|(
name|z
operator|==
name|NULL
condition|)
name|q
operator|=
name|NULL
expr_stmt|;
else|else
block|{
name|q
operator|=
name|getpwnam
argument_list|(
name|z
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|!=
name|NULL
condition|)
name|z
operator|=
name|q
operator|->
name|pw_name
expr_stmt|;
block|}
if|if
condition|(
name|q
operator|==
name|NULL
operator|||
name|q
operator|->
name|pw_uid
operator|!=
name|getuid
argument_list|()
condition|)
block|{
name|q
operator|=
name|getpwuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|==
name|NULL
condition|)
name|z
operator|=
name|NULL
expr_stmt|;
else|else
name|z
operator|=
name|q
operator|->
name|pw_name
expr_stmt|;
block|}
if|if
condition|(
name|z
operator|!=
name|NULL
condition|)
name|zSlogin
operator|=
name|zbufcpy
argument_list|(
name|z
argument_list|)
expr_stmt|;
comment|/* On some old systems, an suid program run by root is started with      an euid of 0.  If this happens, we look up the uid we should have      and set ourselves to it manually.  This means that on such a      system root will not be able to uucp or uux files that are not      readable by uucp.  */
if|if
condition|(
operator|(
name|iflags
operator|&
name|INIT_SUID
operator|)
operator|!=
literal|0
operator|&&
name|geteuid
argument_list|()
operator|==
literal|0
condition|)
block|{
name|q
operator|=
name|getpwnam
argument_list|(
name|OWNER
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|!=
name|NULL
condition|)
name|setuid
argument_list|(
name|q
operator|->
name|pw_uid
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|iflags
operator|&
name|INIT_GETCWD
operator|)
operator|!=
literal|0
condition|)
block|{
specifier|const
name|char
modifier|*
name|zenv
decl_stmt|;
name|struct
name|stat
name|senv
decl_stmt|,
name|sdot
decl_stmt|;
comment|/* Get the current working directory.  We have to get it now, 	 since we're about to do a chdir.  We use PWD if it's defined 	 and if it really names the working directory, since if it's 	 not the same as whatever getcwd returns it's probably more 	 appropriate.  */
name|zenv
operator|=
name|getenv
argument_list|(
literal|"PWD"
argument_list|)
expr_stmt|;
if|if
condition|(
name|zenv
operator|!=
name|NULL
operator|&&
name|stat
argument_list|(
operator|(
name|char
operator|*
operator|)
name|zenv
argument_list|,
operator|&
name|senv
argument_list|)
operator|==
literal|0
operator|&&
name|stat
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|"."
argument_list|,
operator|&
name|sdot
argument_list|)
operator|==
literal|0
operator|&&
name|senv
operator|.
name|st_ino
operator|==
name|sdot
operator|.
name|st_ino
operator|&&
name|senv
operator|.
name|st_dev
operator|==
name|sdot
operator|.
name|st_dev
condition|)
name|zScwd
operator|=
name|zbufcpy
argument_list|(
name|zenv
argument_list|)
expr_stmt|;
else|else
block|{
if|#
directive|if
name|HAVE_GETCWD
block|{
name|size_t
name|c
decl_stmt|;
name|c
operator|=
literal|128
expr_stmt|;
while|while
condition|(
name|TRUE
condition|)
block|{
name|zScwd
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|getcwd
argument_list|(
name|zScwd
argument_list|,
name|c
argument_list|)
operator|!=
name|NULL
condition|)
break|break;
name|xfree
argument_list|(
operator|(
name|pointer
operator|)
name|zScwd
argument_list|)
expr_stmt|;
name|zScwd
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
name|ERANGE
condition|)
break|break;
name|c
operator|<<=
literal|1
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* HAVE_GETCWD */
if|#
directive|if
name|HAVE_GETWD
name|zScwd
operator|=
operator|(
name|char
operator|*
operator|)
name|xmalloc
argument_list|(
name|MAXPATHLEN
argument_list|)
expr_stmt|;
if|if
condition|(
name|getwd
argument_list|(
name|zScwd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|xfree
argument_list|(
operator|(
name|pointer
operator|)
name|zScwd
argument_list|)
expr_stmt|;
name|zScwd
operator|=
name|NULL
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* HAVE_GETWD */
if|if
condition|(
name|zScwd
operator|!=
name|NULL
condition|)
name|zScwd
operator|=
operator|(
name|char
operator|*
operator|)
name|xrealloc
argument_list|(
operator|(
name|pointer
operator|)
name|zScwd
argument_list|,
name|strlen
argument_list|(
name|zScwd
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|iflags
operator|&
name|INIT_NOCHDIR
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Connect to the spool directory, and create it if it doesn't 	 exist.  */
if|if
condition|(
name|chdir
argument_list|(
name|zSspooldir
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|ENOENT
operator|&&
name|mkdir
argument_list|(
operator|(
name|char
operator|*
operator|)
name|zSspooldir
argument_list|,
name|IDIRECTORY_MODE
argument_list|)
operator|<
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"mkdir (%s): %s"
argument_list|,
name|zSspooldir
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|chdir
argument_list|(
name|zSspooldir
argument_list|)
operator|<
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"chdir (%s): %s"
argument_list|,
name|zSspooldir
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* Exit the program.  */
end_comment

begin_function
name|void
name|usysdep_exit
parameter_list|(
name|fsuccess
parameter_list|)
name|boolean
name|fsuccess
decl_stmt|;
block|{
name|exit
argument_list|(
name|fsuccess
condition|?
name|EXIT_SUCCESS
else|:
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* This is called when a non-standard configuration file is used, to    make sure the program doesn't hand out privileged file access.    This means that to test non-standard configuration files, you    should be logged in as uucp.  This is called before    usysdep_initialize.  It ensures that someone can't simply use an    alternate configuration file to steal UUCP transfers from other    systems.  This will still permit people to set up their own    configuration file and pretend to be whatever system they choose.    The only real security is to use a high level of protection on the    modem ports.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|boolean
name|fsysdep_other_config
parameter_list|(
name|z
parameter_list|)
specifier|const
name|char
modifier|*
name|z
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|setuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|setgid
argument_list|(
name|getgid
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Get the node name to use if it was not specified in the configuration    file.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|zsysdep_localname
parameter_list|()
block|{
return|return
name|zSlocalname
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Get the login name.  We actually get the login name in    usysdep_initialize, because after that we may switch away from the    real uid.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|zsysdep_login_name
parameter_list|()
block|{
if|if
condition|(
name|zSlogin
operator|==
name|NULL
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"Can't get login name"
argument_list|)
expr_stmt|;
return|return
name|zSlogin
return|;
block|}
end_function

end_unit

