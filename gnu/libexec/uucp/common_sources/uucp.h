begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uucp.h    Header file for the UUCP package.     Copyright (C) 1991, 1992, 1993, 1994, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_comment
comment|/* Get the system configuration parameters.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"policy.h"
end_include

begin_comment
comment|/* Get a definition for ANSI_C if we weren't given one.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANSI_C
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|ANSI_C
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_define
define|#
directive|define
name|ANSI_C
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__STDC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (ANSI_C) */
end_comment

begin_comment
comment|/* Pass this definition into uuconf.h.  */
end_comment

begin_define
define|#
directive|define
name|UUCONF_ANSI_C
value|ANSI_C
end_define

begin_comment
comment|/* We always include some standard header files.  We need<signal.h>    to define sig_atomic_t.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDDEF_H
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On some systems we need<sys/types.h> to get sig_atomic_t or    size_t or time_t.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIG_ATOMIC_T_IN_SIGNAL_H
operator|&&
name|HAVE_SIG_ATOMIC_T_IN_TYPES_H
end_if

begin_define
define|#
directive|define
name|USE_TYPES_H
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|HAVE_SIZE_T_IN_STDDEF_H
operator|&&
name|HAVE_SIZE_T_IN_TYPES_H
end_if

begin_define
define|#
directive|define
name|USE_TYPES_H
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|HAVE_TIME_T_IN_TIME_H
operator|&&
name|HAVE_TIME_T_IN_TYPES_H
end_if

begin_define
define|#
directive|define
name|USE_TYPES_H
value|1
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|USE_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|USE_TYPES_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure we have sig_atomic_t.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIG_ATOMIC_T_IN_SIGNAL_H
operator|&&
operator|!
name|HAVE_SIG_ATOMIC_T_IN_TYPES_H
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_ATOMIC_T
end_ifndef

begin_comment
comment|/* There is no portable definition for sig_atomic_t.  */
end_comment

begin_define
define|#
directive|define
name|SIG_ATOMIC_T
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (SIG_ATOMIC_T) */
end_comment

begin_typedef
typedef|typedef
name|SIG_ATOMIC_T
name|sig_atomic_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_SIG_ATOMIC_T_IN_SIGNAL_H&& ! HAVE_SIG_ATOMIC_T_IN_TYPES_H */
end_comment

begin_comment
comment|/* Make sure we have size_t.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIZE_T_IN_STDDEF_H
operator|&&
operator|!
name|HAVE_SIZE_T_IN_TYPES_H
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T
value|unsigned
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (SIZE_T) */
end_comment

begin_typedef
typedef|typedef
name|SIZE_T
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_SIZE_T_IN_STDDEF_H&& ! HAVE_SIZE_T_IN_TYPES_H */
end_comment

begin_comment
comment|/* Make sure we have time_t.  We use long as the default.  We don't    bother to let conf.h override this, since on a system which doesn't    define time_t long must be correct.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_TIME_T_IN_TIME_H
operator|&&
operator|!
name|HAVE_TIME_T_IN_TYPES_H
end_if

begin_typedef
typedef|typedef
name|long
name|time_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set up some definitions for both ANSI C and Classic C.     P() -- for function prototypes (e.g. extern int foo P((int)) ).    pointer -- for a generic pointer (i.e. void *).    constpointer -- for a generic pointer to constant data.    BUCHAR -- to convert a character to unsigned.  */
end_comment

begin_if
if|#
directive|if
name|ANSI_C
end_if

begin_if
if|#
directive|if
operator|!
name|HAVE_VOID
operator|||
operator|!
name|HAVE_UNSIGNED_CHAR
operator|||
operator|!
name|HAVE_PROTOTYPES
end_if

begin_error
error|#
directive|error
error|ANSI C compiler without void or unsigned char or prototypes
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|constpointer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BUCHAR
parameter_list|(
name|b
parameter_list|)
value|((unsigned char) (b))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! ANSI_C */
end_comment

begin_comment
comment|/* Handle uses of volatile and void in Classic C.  */
end_comment

begin_define
define|#
directive|define
name|volatile
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_VOID
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_PROTOTYPES
end_if

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|constpointer
typedef|;
end_typedef

begin_if
if|#
directive|if
name|HAVE_UNSIGNED_CHAR
end_if

begin_define
define|#
directive|define
name|BUCHAR
parameter_list|(
name|b
parameter_list|)
value|((unsigned char) (b))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_UNSIGNED_CHAR */
end_comment

begin_comment
comment|/* This should work on most systems, but not necessarily all.  */
end_comment

begin_define
define|#
directive|define
name|BUCHAR
parameter_list|(
name|b
parameter_list|)
value|((b)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_UNSIGNED_CHAR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ANSI_C */
end_comment

begin_comment
comment|/* Make sure we have a definition for offsetof.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|((size_t) ((char *)&(((type *) 0)->field) - (char *) (type *) 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Only use inline with gcc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|__inline__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the string functions, which are used throughout the code.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_MEMORY_H
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We really need a definition for memchr, and this should not    conflict with anything in<string.h>.  I hope.  */
end_comment

begin_function_decl
specifier|extern
name|pointer
name|memchr
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
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STRING_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_STRINGS_H
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STRINGS_H */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|,
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|,
modifier|*
name|strtok
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strerror
argument_list|()
decl_stmt|,
modifier|*
name|strstr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|strlen
argument_list|()
decl_stmt|,
name|strspn
argument_list|()
decl_stmt|,
name|strcspn
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMORY_H
end_if

begin_decl_stmt
specifier|extern
name|pointer
name|memcpy
argument_list|()
decl_stmt|,
name|memchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_MEMORY_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRINGS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRING_H */
end_comment

begin_comment
comment|/* Get what we need from<stdlib.h>.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STDLIB_H */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|malloc
argument_list|()
decl_stmt|,
name|realloc
argument_list|()
decl_stmt|,
name|bsearch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|strtol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|strtoul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STDLIB_H */
end_comment

begin_comment
comment|/* NeXT uses<libc.h> to declare a bunch of functions.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_LIBC_H
end_if

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure we have the EXIT_ macros.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we need to declare errno, do so.  I don't want to always do    this, because some system might theoretically have a different    declaration for errno.  On a POSIX system this is sure to work.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_ERRNO_DECLARATION
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the system has the socket call, guess that we can compile the    TCP code.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCP
value|HAVE_SOCKET
end_define

begin_comment
comment|/* If the system has the t_open call, guess that we can compile the    TLI code.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TLI
value|HAVE_T_OPEN
end_define

begin_comment
comment|/* The boolean type holds boolean values.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_comment
comment|/* The openfile_t type holds an open file.  This depends on whether we    are using stdio or not.  */
end_comment

begin_if
if|#
directive|if
name|USE_STDIO
end_if

begin_typedef
typedef|typedef
name|FILE
modifier|*
name|openfile_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFILECLOSED
value|((FILE *) NULL)
end_define

begin_define
define|#
directive|define
name|ffileisopen
parameter_list|(
name|e
parameter_list|)
value|((e) != NULL)
end_define

begin_define
define|#
directive|define
name|ffileeof
parameter_list|(
name|e
parameter_list|)
value|feof (e)
end_define

begin_define
define|#
directive|define
name|cfileread
parameter_list|(
name|e
parameter_list|,
name|z
parameter_list|,
name|c
parameter_list|)
value|fread ((z), 1, (c), (e))
end_define

begin_define
define|#
directive|define
name|cfilewrite
parameter_list|(
name|e
parameter_list|,
name|z
parameter_list|,
name|c
parameter_list|)
value|fwrite ((z), 1, (c), (e))
end_define

begin_define
define|#
directive|define
name|ffileioerror
parameter_list|(
name|e
parameter_list|,
name|c
parameter_list|)
value|ferror (e)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SEEK_SET
end_ifdef

begin_define
define|#
directive|define
name|ffileseek
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(fseek ((e), (long) (i), SEEK_SET) == 0)
end_define

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(fseek ((e), (long) 0, SEEK_SET) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffileseek
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(fseek ((e), (long) (i), 0) == 0)
end_define

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(fseek ((e), (long) 0, 0) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SEEK_END
end_ifdef

begin_define
define|#
directive|define
name|ffileseekend
parameter_list|(
name|e
parameter_list|)
value|(fseek ((e), (long) 0, SEEK_END) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffileseekend
parameter_list|(
name|e
parameter_list|)
value|(fseek ((e), (long) 0, 2) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffileclose
parameter_list|(
name|e
parameter_list|)
value|(fclose (e) == 0)
end_define

begin_define
define|#
directive|define
name|fstdiosync
parameter_list|(
name|e
parameter_list|,
name|z
parameter_list|)
value|(fsysdep_sync (e, z))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! USE_STDIO */
end_comment

begin_if
if|#
directive|if
operator|!
name|USE_TYPES_H
end_if

begin_undef
undef|#
directive|undef
name|USE_TYPES_H
end_undef

begin_define
define|#
directive|define
name|USE_TYPES_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
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

begin_ifdef
ifdef|#
directive|ifdef
name|OFF_T
end_ifdef

begin_typedef
typedef|typedef
name|OFF_T
name|off_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|OFF_T
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|openfile_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFILECLOSED
value|(-1)
end_define

begin_define
define|#
directive|define
name|ffileisopen
parameter_list|(
name|e
parameter_list|)
value|((e)>= 0)
end_define

begin_define
define|#
directive|define
name|ffileeof
parameter_list|(
name|e
parameter_list|)
value|(FALSE)
end_define

begin_define
define|#
directive|define
name|cfileread
parameter_list|(
name|e
parameter_list|,
name|z
parameter_list|,
name|c
parameter_list|)
value|read ((e), (z), (c))
end_define

begin_define
define|#
directive|define
name|cfilewrite
parameter_list|(
name|e
parameter_list|,
name|z
parameter_list|,
name|c
parameter_list|)
value|write ((e), (z), (c))
end_define

begin_define
define|#
directive|define
name|ffileioerror
parameter_list|(
name|e
parameter_list|,
name|c
parameter_list|)
value|((c)< 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SEEK_SET
end_ifdef

begin_define
define|#
directive|define
name|ffileseek
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(lseek ((e), (off_t) i, SEEK_SET)>= 0)
end_define

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(lseek ((e), (off_t) 0, SEEK_SET)>= 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffileseek
parameter_list|(
name|e
parameter_list|,
name|i
parameter_list|)
value|(lseek ((e), (off_t) i, 0)>= 0)
end_define

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(lseek ((e), (off_t) 0, 0)>= 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SEEK_END
end_ifdef

begin_define
define|#
directive|define
name|ffileseekend
parameter_list|(
name|e
parameter_list|)
value|(lseek ((e), (off_t) 0, SEEK_END)>= 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffileseekend
parameter_list|(
name|e
parameter_list|)
value|(lseek ((e), (off_t) 0, 2)>= 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffileclose
parameter_list|(
name|e
parameter_list|)
value|(close (e)>= 0)
end_define

begin_define
define|#
directive|define
name|fstdiosync
parameter_list|(
name|e
parameter_list|,
name|z
parameter_list|)
value|(fsysdep_sync (fileno (e), z))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_STDIO */
end_comment

begin_escape
end_escape

begin_comment
comment|/* A prototype for main to avoid warnings from gcc 2.0    -Wmissing-prototype option.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
decl|main
name|P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some standard routines which we only define if they are not present    on the system we are compiling on.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_GETLINE
end_if

begin_comment
comment|/* Read a line from a file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|getline
name|P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|pz
operator|,
name|size_t
operator|*
name|pc
operator|,
name|FILE
operator|*
name|e
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_REMOVE
end_if

begin_comment
comment|/* Erase a file.  */
end_comment

begin_undef
undef|#
directive|undef
name|remove
end_undef

begin_decl_stmt
specifier|extern
name|int
name|remove
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRDUP
end_if

begin_comment
comment|/* Copy a string into memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRSTR
end_if

begin_comment
comment|/* Look for one string within another.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strstr
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zouter
operator|,
specifier|const
name|char
operator|*
name|zinner
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRCASECMP
end_if

begin_if
if|#
directive|if
name|HAVE_STRICMP
end_if

begin_define
define|#
directive|define
name|strcasecmp
value|stricmp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STRICMP */
end_comment

begin_comment
comment|/* Rename strcasecmp to avoid ANSI C name space.  */
end_comment

begin_define
define|#
directive|define
name|strcasecmp
value|xstrcasecmp
end_define

begin_decl_stmt
specifier|extern
name|int
name|strcasecmp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z1
operator|,
specifier|const
name|char
operator|*
name|z2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRICMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRCASECMP */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRNCASECMP
end_if

begin_if
if|#
directive|if
name|HAVE_STRNICMP
end_if

begin_define
define|#
directive|define
name|strncasecmp
value|strnicmp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STRNICMP */
end_comment

begin_comment
comment|/* Rename strncasecmp to avoid ANSI C name space.  */
end_comment

begin_define
define|#
directive|define
name|strncasecmp
value|xstrncasecmp
end_define

begin_decl_stmt
specifier|extern
name|int
name|strncasecmp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z1
operator|,
specifier|const
name|char
operator|*
name|z2
operator|,
name|size_t
name|clen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRNICMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRNCASECMP */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRERROR
end_if

begin_comment
comment|/* Get a string corresponding to an error message.  */
end_comment

begin_undef
undef|#
directive|undef
name|strerror
end_undef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|P
argument_list|(
operator|(
name|int
name|ierr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the appropriate definitions for memcmp, memcpy, memchr and    bzero.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMCMP
end_if

begin_if
if|#
directive|if
name|HAVE_BCMP
end_if

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|,
name|c
parameter_list|)
value|bcmp ((p1), (p2), (c))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_BCMP */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|memcmp
name|P
argument_list|(
operator|(
name|constpointer
name|p1
operator|,
name|constpointer
name|p2
operator|,
name|size_t
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_BCMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_MEMCMP */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMCPY
end_if

begin_if
if|#
directive|if
name|HAVE_BCOPY
end_if

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|pto
parameter_list|,
name|pfrom
parameter_list|,
name|c
parameter_list|)
value|bcopy ((pfrom), (pto), (c))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_BCOPY */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|memcpy
name|P
argument_list|(
operator|(
name|pointer
name|pto
operator|,
name|constpointer
name|pfrom
operator|,
name|size_t
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_BCOPY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_MEMCPY */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_MEMCHR
end_if

begin_decl_stmt
specifier|extern
name|pointer
name|memchr
name|P
argument_list|(
operator|(
name|constpointer
name|p
operator|,
name|int
name|b
operator|,
name|size_t
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_BZERO
end_if

begin_if
if|#
directive|if
name|HAVE_MEMSET
end_if

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|memset ((p), 0, (c))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_MEMSET */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bzero
name|P
argument_list|(
operator|(
name|pointer
name|p
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_MEMSET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_BZERO */
end_comment

begin_comment
comment|/* Look up a character in a string.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRCHR
end_if

begin_if
if|#
directive|if
name|HAVE_INDEX
end_if

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_INDEX */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strchr
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z
operator|,
name|int
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_INDEX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRCHR */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRRCHR
end_if

begin_if
if|#
directive|if
name|HAVE_RINDEX
end_if

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_RINDEX */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strrchr
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z
operator|,
name|int
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_RINDEX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_STRRCHR */
end_comment

begin_comment
comment|/* Turn a string into a long integer.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRTOL
end_if

begin_decl_stmt
specifier|extern
name|long
name|strtol
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Turn a string into a long unsigned integer.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRTOUL
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|strtoul
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Lookup a key in a sorted array.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_BSEARCH
end_if

begin_decl_stmt
specifier|extern
name|pointer
name|bsearch
name|P
argument_list|(
operator|(
name|constpointer
name|pkey
operator|,
name|constpointer
name|parray
operator|,
name|size_t
name|celes
operator|,
name|size_t
name|cbytes
operator|,
name|int
argument_list|(
argument|*pficmp
argument_list|)
name|P
argument_list|(
operator|(
name|constpointer
operator|,
name|constpointer
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

