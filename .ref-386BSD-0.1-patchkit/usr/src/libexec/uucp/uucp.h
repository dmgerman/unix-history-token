begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* uucp.h    Header file for the UUCP package.     Copyright (C) 1991, 1992 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o AIRS, P.O. Box 520, Waltham, MA 02254.     $Log: uucp.h,v $    Revision 1.67  1992/04/02  22:51:09  ian    Add gcc 2.0 format checking to ulog, and fixed discovered problems     Revision 1.66  1992/03/30  04:49:10  ian    Niels Baggesen: added debugging types abnormal and uucp-proto     Revision 1.65  1992/03/28  22:06:38  ian    Michael I Bushnell: renamed enum tstatus to avoid header file conflict     Revision 1.64  1992/03/28  20:31:55  ian    Franc,ois Pinard: allow a name to be given to an alternate     Revision 1.63  1992/03/28  04:23:46  ian    Gerben Wierda: don't always declare bzero     Revision 1.62  1992/03/28  04:04:55  ian    Niels Baggesen: simplified debugging message macros     Revision 1.61  1992/03/17  01:33:47  ian    Move definition of const before use for non ANSI C     Revision 1.60  1992/03/17  01:28:18  ian    Undefine remove in uucp.h if ! HAVE_REMOVE     Revision 1.59  1992/03/17  00:06:56  ian    Changed HAVE_SIG_ATOMIC_T_IN_SYS_TYPES_H to HAVE_SIG_ATOMIC_T_IN_TYPES_H     Revision 1.58  1992/03/16  23:44:56  ian    Sometimes sig_atomic_t is in<sys/types.h> but not<signal.h>     Revision 1.57  1992/03/15  04:51:17  ian    Keep an array of signals we've received rather than a single variable     Revision 1.56  1992/03/12  21:58:32  ian    Added padding byte to scmd     Revision 1.55  1992/03/12  19:54:43  ian    Debugging based on types rather than number     Revision 1.54  1992/03/11  22:06:37  ian    Marty Shannon: added max-uuxqts command     Revision 1.53  1992/03/11  01:18:15  ian    Niels Baggesen: drop the connection on a write failure     Revision 1.52  1992/03/11  00:18:50  ian    Save temporary file if file send fails     Revision 1.51  1992/03/09  20:14:37  ian    Ted Lindgreen: added max-remote-debug command     Revision 1.50  1992/03/09  05:08:16  ian    Added status for wrong time to call, not used if system can't be called     Revision 1.49  1992/03/08  16:42:41  ian    Ted Lindgreen: report port and login name in log file     Revision 1.48  1992/03/07  04:58:09  ian    Eric Ziegast: some systems don't define EXIT_SUCCESS or FAILURE     Revision 1.47  1992/03/07  02:56:30  ian    Rewrote time routines     Revision 1.46  1992/03/04  01:40:51  ian    Thomas Fischer: tweaked a bit for the NeXT     Revision 1.45  1992/03/04  00:36:44  ian    Michael Richardson: better chat script debugging     Revision 1.44  1992/03/02  04:53:07  ian    Marc Unangst: added HAVE_SCO_LOCKFILES configuration parameter     Revision 1.43  1992/02/29  01:06:59  ian    Chip Salzenberg: recheck file permissions before sending     Revision 1.42  1992/02/27  05:40:54  ian    T. William Wells: detach from controlling terminal, handle signals safely     Revision 1.41  1992/02/24  18:38:42  ian    John Theus: don't declare ulog with ellipsis if we don't have vprintf     Revision 1.40  1992/02/24  04:58:47  ian    Only permit files to be received into directories that are world-writeable     Revision 1.39  1992/02/23  19:50:50  ian    Handle READ and WRITE in Permissions correctly     Revision 1.38  1992/02/23  03:26:51  ian    Overhaul to use automatic configure shell script     Revision 1.37  1992/02/08  03:54:18  ian    Include<string.h> only in<uucp.h>, added 1992 copyright     Revision 1.36  1992/01/19  21:30:21  ian    Matthew Lyle: some systems don't declare errno in<errno.h>     Revision 1.35  1992/01/19  18:29:05  ian    Added HAVE_BSEARCH configuration parameter     Revision 1.34  1992/01/18  22:48:53  ian    Reworked sending of mail and general handling of failed transfers     Revision 1.33  1992/01/15  19:53:27  ian    Mike Park: If HAVE_ALLOCA is 0 when using gcc, don't define alloca     Revision 1.32  1992/01/15  07:06:29  ian    Set configuration directory in Makefile rather than sysdep.h     Revision 1.31  1992/01/14  03:46:55  ian    Chip Salzenberg: handle invalid status values in status files     Revision 1.30  1992/01/05  03:18:54  ian    Avoid redefining SEEK_SET     Revision 1.29  1992/01/05  03:09:17  ian    Changed abProgram and abVersion to non const to avoid compiler bug     Revision 1.28  1991/12/30  04:28:30  ian    John Theus: check for EOF to work around bug in fread     Revision 1.27  1991/12/29  04:04:18  ian    Added a bunch of extern definitions     Revision 1.26  1991/12/28  06:10:50  ian    Added HAVE_STRCHR and HAVE_INDEX to conf.h     Revision 1.25  1991/12/28  03:49:23  ian    Added HAVE_MEMFNS and HAVE_BFNS; changed uses of memset to bzero     Revision 1.24  1991/12/23  05:15:54  ian    David Nugent: set debugging level for a specific system     Revision 1.23  1991/12/22  22:14:19  ian    Monty Solomon: added HAVE_UNISTD_H configuration parameter     Revision 1.22  1991/12/22  20:38:50  ian    Monty Solomon: don't define strcasecmp and strncasecmp     Revision 1.21  1991/12/21  23:10:43  ian    Terry Gardner: record failed file transfers in statistics file     Revision 1.20  1991/12/18  03:54:14  ian    Made error messages to terminal appear more normal     Revision 1.19  1991/12/17  07:09:58  ian    Record statistics in fractions of a second     Revision 1.18  1991/12/15  04:17:11  ian    Added chat-seven-bit command to control parity bit stripping     Revision 1.17  1991/12/15  03:42:33  ian    Added tprocess_chat_cmd for all chat commands, and added CMDTABTYPE_PREFIX     Revision 1.16  1991/12/11  19:35:48  ian    Mark Powell: put in my own version of strtol     Revision 1.15  1991/12/11  03:59:19  ian    Create directories when necessary; don't just assume they exist     Revision 1.14  1991/12/10  19:45:05  ian    Added ulog_device to record device name for log file     Revision 1.13  1991/12/10  19:29:02  ian    Move statistics file stuff from file.c to log.c     Revision 1.12  1991/11/21  22:17:06  ian    Add version string, print version when printing usage     Revision 1.11  1991/11/21  21:20:41  ian    Brian Campbell: offer str{n}icmp as an alternative to str{n}casecmp     Revision 1.10  1991/11/12  19:47:04  ian    Add called-chat set of commands to run a chat script on an incoming call     Revision 1.9  1991/11/11  23:47:24  ian    Added chat-program to run a program to do a chat script     Revision 1.8  1991/11/11  19:32:03  ian    Added breceive_char to read characters through protocol buffering     Revision 1.7  1991/11/10  20:05:44  ian    Changed ffilerewind to use fseek rather than rewind     Revision 1.6  1991/11/10  19:24:22  ian    Added pffile protocol entry point for file level control     Revision 1.5  1991/11/07  20:32:04  ian    Chip Salzenberg: allow ANSI_C to be defined in conf.h     Revision 1.4  1991/11/07  18:21:47  ian    Chip Salzenberg: move CMAXRETRIES to conf.h for easy configuration     Revision 1.3  1991/09/19  17:43:48  ian    Chip Salzenberg: undef TRUE and FALSE in case system defines them     Revision 1.2  1991/09/19  02:22:44  ian    Chip Salzenberg's patch to allow ";retrytime" at the end of a time string     Revision 1.1  1991/09/10  19:47:55  ian    Initial revision     */
end_comment

begin_comment
comment|/* Get the system configuration parameters.  */
end_comment

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"policy.h"
end_include

begin_comment
comment|/* We always want<stdio.h>.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* We need<signal.h> for sig_atomic_t.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* On some systems that won't get us sig_atomic_t.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIG_ATOMIC_T_IN_SIGNAL_H
end_if

begin_if
if|#
directive|if
name|HAVE_SIG_ATOMIC_T_IN_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_SIG_ATOMIC_T_IN_TYPES_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sig_atomic_t
end_ifndef

begin_comment
comment|/* There is no portable definition for sig_atomic_t.  */
end_comment

begin_define
define|#
directive|define
name|sig_atomic_t
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (sig_atomic_t) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_SIG_ATOMIC_T_IN_TYPES_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_SIG_ATOMIC_T_IN_SIGNAL_H */
end_comment

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
comment|/* Set up some definitions for both ANSI C and Classic C.     P() is used for function prototypes (e.g. extern int foo P((int)) ).    pointer is used for a generic pointer (i.e. void *).    constpointer is used for a generic pointer to constant data.    BUCHAR is used to convert a character to unsigned.  */
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
end_if

begin_error
error|#
directive|error
error|ANSI C compiler without void or unsigned char
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
comment|/* Handle uses of const, volatile and void in Classic C.  */
end_comment

begin_define
define|#
directive|define
name|const
end_define

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

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

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
name|int
name|strcmp
argument_list|()
decl_stmt|,
name|strncmp
argument_list|()
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* These should be size_t, but there's no declaration to conflict with.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
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
name|memmove
argument_list|()
decl_stmt|,
name|memchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|memcmp
parameter_list|()
function_decl|;
end_function_decl

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

begin_decl_stmt
specifier|extern
name|void
name|free
argument_list|()
decl_stmt|,
name|exit
argument_list|()
decl_stmt|,
name|perror
argument_list|()
decl_stmt|,
name|abort
argument_list|()
decl_stmt|,
name|qsort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|atol
argument_list|()
decl_stmt|,
name|strtol
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|atoi
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
comment|/* Define alloca as suggested by David MacKenzie.  AIX requires this    to be the first thing in the file.  I really hate system dependent    cruft like this (and this is the only case in which it appears),    but I guess that's the price of using alloca.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__NeXT__
end_ifndef

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

begin_comment
comment|/* ! defined (__NeXT__) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined(__GNUC__) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (sparc) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (_AIX) */
end_comment

begin_comment
comment|/* We may not be using a real alloca.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (_AIX) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (sparc) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (__GNUC__) */
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
comment|/* Make sure we have the EXIT_ macros (some versions of SunOS have<stdlib.h> but left them out).  */
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
name|ffilereaderror
parameter_list|(
name|e
parameter_list|,
name|c
parameter_list|)
value|ferror (e)
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

begin_ifdef
ifdef|#
directive|ifdef
name|SEEK_SET
end_ifdef

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(fseek (e, (long) 0, SEEK_SET) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(fseek (e, (long) 0, 0) == 0)
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

begin_decl_stmt
specifier|extern
name|int
name|fclose
argument_list|()
decl_stmt|,
name|fseek
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ferror and feof functions are often macros, so we can't safely    define them.  The fread and fwrite functions may return int or may    return size_t, so we can't safely define them.  */
end_comment

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

begin_comment
comment|/* It would be nice to provide prototypes for read, write and lseek, but    we can't because they might not return int.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|close
parameter_list|()
function_decl|;
end_function_decl

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
name|ffilereaderror
parameter_list|(
name|e
parameter_list|,
name|c
parameter_list|)
value|((c)< 0)
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

begin_ifdef
ifdef|#
directive|ifdef
name|SEEK_SET
end_ifdef

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(lseek (e, (long) 0, SEEK_SET)>= 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffilerewind
parameter_list|(
name|e
parameter_list|)
value|(lseek (e, (long) 0, 0)>= 0)
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

begin_decl_stmt
specifier|extern
name|int
name|read
argument_list|()
decl_stmt|,
name|write
argument_list|()
decl_stmt|,
name|close
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The lseek function should return off_t, but we don't want to    include sysdep.h here.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_STDIO */
end_comment

begin_comment
comment|/* Define the time_t type.  This still won't help if they don't have    time or ctime.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_TIME_T
operator|&&
operator|!
name|HAVE_SYS_TIME_T
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
comment|/* The types of entries allowed in a command table (struct scmdtab).    If CMDTABTYPE_FN is used, it should be or'ed with the number of    arguments permitted, or 0 if there is no single number.    CMDTABTYPE_PREFIX means that the string in the scmdtab table is a    prefix; any command which matches the prefix should be used to call    a function.  The number of arguments should be or'ed in as with    CMDTABTYPE_FN.  */
end_comment

begin_define
define|#
directive|define
name|CMDTABTYPE_BOOLEAN
value|(0x12)
end_define

begin_define
define|#
directive|define
name|CMDTABTYPE_INT
value|(0x22)
end_define

begin_define
define|#
directive|define
name|CMDTABTYPE_LONG
value|(0x32)
end_define

begin_define
define|#
directive|define
name|CMDTABTYPE_STRING
value|(0x40)
end_define

begin_define
define|#
directive|define
name|CMDTABTYPE_FULLSTRING
value|(0x50)
end_define

begin_define
define|#
directive|define
name|CMDTABTYPE_FN
value|(0x60)
end_define

begin_define
define|#
directive|define
name|CMDTABTYPE_PREFIX
value|(0x70)
end_define

begin_define
define|#
directive|define
name|TTYPE_CMDTABTYPE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x70)
end_define

begin_define
define|#
directive|define
name|CARGS_CMDTABTYPE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0x0f)
end_define

begin_comment
comment|/* These flags are or'red together to form an argument to    uprocesscmds.  */
end_comment

begin_define
define|#
directive|define
name|CMDFLAG_WARNUNRECOG
value|(0x1)
end_define

begin_define
define|#
directive|define
name|CMDFLAG_CASESIGNIFICANT
value|(0x2)
end_define

begin_define
define|#
directive|define
name|CMDFLAG_BACKSLASH
value|(0x4)
end_define

begin_comment
comment|/* The enumeration returned by functions called by uprocesscmds.  */
end_comment

begin_enum
enum|enum
name|tcmdtabret
block|{
name|CMDTABRET_CONTINUE
block|,
name|CMDTABRET_FREE
block|,
name|CMDTABRET_EXIT
block|,
name|CMDTABRET_FREE_AND_EXIT
block|}
enum|;
end_enum

begin_comment
comment|/* This structure holds the argument to uprocesscmds.  */
end_comment

begin_struct
struct|struct
name|scmdtab
block|{
comment|/* Command name.  */
specifier|const
name|char
modifier|*
name|zcmd
decl_stmt|;
comment|/* Command type (one of CMDTABTYPE_...).  */
name|int
name|itype
decl_stmt|;
comment|/* This is the address of the variable if not CMDTABTYPE_FN.  */
name|pointer
name|pvar
decl_stmt|;
comment|/* This is used if CMDTABTYPE_FN.  */
name|enum
name|tcmdtabret
argument_list|(
operator|*
name|ptfn
argument_list|)
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
operator|,
name|pointer
name|par
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure holds the information we need for a chat script.  */
end_comment

begin_struct
struct|struct
name|schat_info
block|{
comment|/* The script itself, if any.  */
name|char
modifier|*
name|zchat
decl_stmt|;
comment|/* The program to run, if any.  */
name|char
modifier|*
name|zprogram
decl_stmt|;
comment|/* The timeout for the chat script.  */
name|int
name|ctimeout
decl_stmt|;
comment|/* The list of failure strings.  */
name|char
modifier|*
name|zfail
decl_stmt|;
comment|/* Whether to strip incoming characters to seven bits.  */
name|boolean
name|fstrip
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This macro is used to initialize the entries of an schat_info    structure to the correct default values.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CHAT
parameter_list|(
name|q
parameter_list|)
define|\
value|((q)->zchat = NULL, \    (q)->zprogram = NULL, \    (q)->ctimeout = 60, \    (q)->zfail = NULL, \    (q)->fstrip = TRUE)
end_define

begin_comment
comment|/* This structure holds a set of special commands executed for    particular protocols.  */
end_comment

begin_struct
struct|struct
name|sproto_param
block|{
comment|/* Protocol.  */
name|char
name|bproto
decl_stmt|;
comment|/* Number of entries.  */
name|int
name|centries
decl_stmt|;
comment|/* Specific entries.  */
struct|struct
name|sproto_param_entry
block|{
name|int
name|cargs
decl_stmt|;
name|char
modifier|*
modifier|*
name|azargs
decl_stmt|;
block|}
modifier|*
name|qentries
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* The ssysteminfo structure holds information about a remote system.  */
end_comment

begin_struct
struct|struct
name|ssysteminfo
block|{
comment|/* System name.  */
specifier|const
name|char
modifier|*
name|zname
decl_stmt|;
comment|/* List of aliases separated by ' '.  */
name|char
modifier|*
name|zalias
decl_stmt|;
comment|/* Linked list of alternate sets of call information.  */
name|struct
name|ssysteminfo
modifier|*
name|qalternate
decl_stmt|;
comment|/* Name for this alternate (may be NULL).  */
name|char
modifier|*
name|zalternate
decl_stmt|;
comment|/* Legal times to call.  A grade, a time string, an optional ';' and      retry time, ' ', repeated.  */
name|char
modifier|*
name|ztime
decl_stmt|;
comment|/* Grade to request of other system and associated time.  A grade, a      time string, ' ', repeated.  */
name|char
modifier|*
name|zcalltimegrade
decl_stmt|;
comment|/* Sizes for local requests and calls.  A size, ' ', a time string,      ' ', repeated.  */
name|char
modifier|*
name|zcall_local_size
decl_stmt|;
comment|/* Sizes for remote requests and local calls.  */
name|char
modifier|*
name|zcall_remote_size
decl_stmt|;
comment|/* Sizes for local requests when called.  */
name|char
modifier|*
name|zcalled_local_size
decl_stmt|;
comment|/* Sizes for remote requests when called.  */
name|char
modifier|*
name|zcalled_remote_size
decl_stmt|;
comment|/* Baud rate (all right, so it's really bps).  */
name|long
name|ibaud
decl_stmt|;
comment|/* High baud rate, if a range is permitted (0 if no range).  */
name|long
name|ihighbaud
decl_stmt|;
comment|/* Port name, if qport is not used.  */
name|char
modifier|*
name|zport
decl_stmt|;
comment|/* Specific port information, if zport is not used.  */
name|struct
name|sport
modifier|*
name|qport
decl_stmt|;
comment|/* Phone number.  */
name|char
modifier|*
name|zphone
decl_stmt|;
comment|/* Chat script information.  */
name|struct
name|schat_info
name|schat
decl_stmt|;
comment|/* Login name to use when calling the remote system.  */
specifier|const
name|char
modifier|*
name|zcall_login
decl_stmt|;
comment|/* Password to use when calling the remote system.  */
specifier|const
name|char
modifier|*
name|zcall_password
decl_stmt|;
comment|/* Login name that must be used by the other system when calling in.  */
specifier|const
name|char
modifier|*
name|zcalled_login
decl_stmt|;
comment|/* Whether to call back the remote system.  */
name|boolean
name|fcallback
decl_stmt|;
comment|/* Whether system uses sequencing.  */
name|boolean
name|fsequence
decl_stmt|;
comment|/* List of protocols to use for this system (may be NULL).  */
specifier|const
name|char
modifier|*
name|zprotocols
decl_stmt|;
comment|/* Number of entries in protocol parameters array.  */
name|int
name|cproto_params
decl_stmt|;
comment|/* Protocol parameters array.  */
name|struct
name|sproto_param
modifier|*
name|qproto_params
decl_stmt|;
comment|/* Chat to run when called.  */
name|struct
name|schat_info
name|scalled_chat
decl_stmt|;
if|#
directive|if
name|DEBUG
operator|>
literal|1
comment|/* Debugging level to set during a call.  */
name|int
name|idebug
decl_stmt|;
comment|/* Maximum remote debugging level.  */
name|int
name|imax_remote_debug
decl_stmt|;
endif|#
directive|endif
comment|/* Whether the other system may request things when we call them.  */
name|boolean
name|fcall_request
decl_stmt|;
comment|/* Whether the other system may request things when they call us.  */
name|boolean
name|fcalled_request
decl_stmt|;
comment|/* Whether we may request things when we call.  */
name|boolean
name|fcall_transfer
decl_stmt|;
comment|/* Whether we may request things when they call.  */
name|boolean
name|fcalled_transfer
decl_stmt|;
comment|/* List of directories that may be sent by local request.  */
specifier|const
name|char
modifier|*
name|zlocal_send
decl_stmt|;
comment|/* List of directories that may be sent by local request when the      other system placed the call (if NULL, use zlocal_send).  This is      actually never used currently.  */
specifier|const
name|char
modifier|*
name|zcalled_local_send
decl_stmt|;
comment|/* List of directories that may be sent by remote request.  */
specifier|const
name|char
modifier|*
name|zremote_send
decl_stmt|;
comment|/* List of directories that may be sent by remote request when the      other system placed the call (if NULL, use zremote_send).  This      is currently only used by HAVE_BNU_CONFIG.  */
specifier|const
name|char
modifier|*
name|zcalled_remote_send
decl_stmt|;
comment|/* List of directories that may be received into by local request.  */
specifier|const
name|char
modifier|*
name|zlocal_receive
decl_stmt|;
comment|/* List of directories that may be received into by local request      when the other system placed the call (if NULL, use      zlocal_receive).  This is currently only used under      HAVE_BNU_CONFIG.  */
specifier|const
name|char
modifier|*
name|zcalled_local_receive
decl_stmt|;
comment|/* List of directories that may be received into by remote request.  */
specifier|const
name|char
modifier|*
name|zremote_receive
decl_stmt|;
comment|/* List of directories that may be received into by remote request      when the other system placed the call (if NULL, use      zremote_receive).  This is currently only used by      HAVE_BNU_CONFIG.  */
specifier|const
name|char
modifier|*
name|zcalled_remote_receive
decl_stmt|;
comment|/* Path to use for command execution.  */
specifier|const
name|char
modifier|*
name|zpath
decl_stmt|;
comment|/* List of commands that may be executed.  */
specifier|const
name|char
modifier|*
name|zcmds
decl_stmt|;
comment|/* Amount of free space to leave.  */
name|long
name|cfree_space
decl_stmt|;
comment|/* List of systems that may be forwarded to.  */
specifier|const
name|char
modifier|*
name|zforwardto
decl_stmt|;
comment|/* The public directory to use for this sytem.  */
specifier|const
name|char
modifier|*
name|zpubdir
decl_stmt|;
comment|/* The local name to use for this remote system.  */
specifier|const
name|char
modifier|*
name|zlocalname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The tfailure enumeration holds reasons for failure to be passed to    the pffail function of a protocol.  */
end_comment

begin_enum
enum|enum
name|tfailure
block|{
comment|/* No failure.  */
name|FAILURE_NONE
block|,
comment|/* No permission for operation.  */
name|FAILURE_PERM
block|,
comment|/* Can't open necessary file.  */
name|FAILURE_OPEN
block|,
comment|/* Not enough space to receive file.  */
name|FAILURE_SIZE
block|}
enum|;
end_enum

begin_comment
comment|/* The tlog enumeration holds the different types of logging.  */
end_comment

begin_enum
enum|enum
name|tlog
block|{
comment|/* Normal log entry.  */
name|LOG_NORMAL
block|,
comment|/* Error log entry.  */
name|LOG_ERROR
block|,
comment|/* Fatal log entry.  */
name|LOG_FATAL
if|#
directive|if
name|DEBUG
operator|>
literal|1
block|,
comment|/* Debugging log entry.  */
name|LOG_DEBUG
block|,
comment|/* Start debugging log entry.  */
name|LOG_DEBUG_START
block|,
comment|/* Continue debugging log entry.  */
name|LOG_DEBUG_CONTINUE
block|,
comment|/* End debugging log entry.  */
name|LOG_DEBUG_END
endif|#
directive|endif
block|}
enum|;
end_enum

begin_comment
comment|/* The tstatus_type enumeration holds the kinds of status information    we put in the status file.  The order of entries here corresponds    to the order of entries in the azStatus array.  */
end_comment

begin_enum
enum|enum
name|tstatus_type
block|{
comment|/* Conversation complete.  */
name|STATUS_COMPLETE
block|,
comment|/* Port unavailable.  */
name|STATUS_PORT_FAILED
block|,
comment|/* Dial failed.  */
name|STATUS_DIAL_FAILED
block|,
comment|/* Login failed.  */
name|STATUS_LOGIN_FAILED
block|,
comment|/* Handshake failed.  */
name|STATUS_HANDSHAKE_FAILED
block|,
comment|/* Failed after logging in.  */
name|STATUS_FAILED
block|,
comment|/* Talking to remote system.  */
name|STATUS_TALKING
block|,
comment|/* Wrong time to call.  */
name|STATUS_WRONG_TIME
block|,
comment|/* Number of status values.  */
name|STATUS_VALUES
block|}
enum|;
end_enum

begin_comment
comment|/* An array to convert status entries to strings.  If more status entries    are added, this array must be extended.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|azStatus
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The sstatus structure holds the contents of a system status file.  */
end_comment

begin_struct
struct|struct
name|sstatus
block|{
comment|/* Current status of conversation.  */
name|enum
name|tstatus_type
name|ttype
decl_stmt|;
comment|/* Number of failed retries.  */
name|int
name|cretries
decl_stmt|;
comment|/* Time of last call in seconds since epoch (determined by      isysdep_time).  */
name|long
name|ilast
decl_stmt|;
comment|/* Number of seconds until a retry is permitted.  */
name|int
name|cwait
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How long we have to wait for the next call, given the number of retries    we have already made.  This should probably be configurable.  */
end_comment

begin_define
define|#
directive|define
name|CRETRY_WAIT
parameter_list|(
name|c
parameter_list|)
value|((c) * 10 * 60)
end_define

begin_comment
comment|/* The scmd structure holds a complete UUCP command.  */
end_comment

begin_struct
struct|struct
name|scmd
block|{
comment|/* Command ('S' for send, 'R' for receive, 'X' for execute, 'H' for      hangup, 'Y' for hangup confirm, 'N' for hangup deny).  */
name|char
name|bcmd
decl_stmt|;
comment|/* At least one compiler needs an explicit padding byte here.  */
name|char
name|bdummy
decl_stmt|;
comment|/* Sequence handle for fsysdep_did_work.  */
name|pointer
name|pseq
decl_stmt|;
comment|/* File name to transfer from.  */
specifier|const
name|char
modifier|*
name|zfrom
decl_stmt|;
comment|/* File name to transfer to.  */
specifier|const
name|char
modifier|*
name|zto
decl_stmt|;
comment|/* User who requested transfer.  */
specifier|const
name|char
modifier|*
name|zuser
decl_stmt|;
comment|/* Options.  */
specifier|const
name|char
modifier|*
name|zoptions
decl_stmt|;
comment|/* Temporary file name ('S' and pfreceive protocol function).  */
specifier|const
name|char
modifier|*
name|ztemp
decl_stmt|;
comment|/* Mode to give newly created file ('S' and pfreceive protocol fn).  */
name|unsigned
name|int
name|imode
decl_stmt|;
comment|/* User to notify on remote system (optional; 'S' only).  */
specifier|const
name|char
modifier|*
name|znotify
decl_stmt|;
comment|/* File size (-1 if not supplied) ('S' and pfreceive protocol fn).  */
name|long
name|cbytes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The highest grade.  */
end_comment

begin_define
define|#
directive|define
name|BGRADE_HIGH
value|('0')
end_define

begin_comment
comment|/* The lowest grade.  */
end_comment

begin_define
define|#
directive|define
name|BGRADE_LOW
value|('z')
end_define

begin_comment
comment|/* Whether a character is a legal grade.  */
end_comment

begin_define
define|#
directive|define
name|FGRADE_LEGAL
parameter_list|(
name|b
parameter_list|)
value|(isalnum (BUCHAR (b)))
end_define

begin_if
if|#
directive|if
name|DEBUG
operator|>
literal|1
end_if

begin_comment
comment|/* We allow independent control over several different types of    debugging output, using a bit string with individual bits dedicated    to particular debugging types.  */
end_comment

begin_comment
comment|/* The bit string is stored in iDebug.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iDebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug abnormal events.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_ABNORMAL
value|(01)
end_define

begin_comment
comment|/* Debug chat scripts.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_CHAT
value|(02)
end_define

begin_comment
comment|/* Debug initial handshake.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_HANDSHAKE
value|(04)
end_define

begin_comment
comment|/* Debug UUCP protocol.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_UUCP_PROTO
value|(010)
end_define

begin_comment
comment|/* Debug protocols.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PROTO
value|(020)
end_define

begin_comment
comment|/* Debug port actions.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PORT
value|(040)
end_define

begin_comment
comment|/* Debug configuration files.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_CONFIG
value|(0100)
end_define

begin_comment
comment|/* Debug spool directory actions.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_SPOOLDIR
value|(0200)
end_define

begin_comment
comment|/* Debug executions.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_EXECUTE
value|(0400)
end_define

begin_comment
comment|/* Debug incoming data.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_INCOMING
value|(01000)
end_define

begin_comment
comment|/* Debug outgoing data.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_OUTGOING
value|(02000)
end_define

begin_comment
comment|/* Maximum possible value for iDebug.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MAX
value|(03777)
end_define

begin_comment
comment|/* Intializer for array of debug names.  The index of the name in the    array is the corresponding bit position in iDebug.  We only check    for prefixes, so these names only need to be long enough to    distinguish each name from every other.  The last entry must be    NULL.  The string "all" is also recognized to turn on all    debugging.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_NAMES
define|\
value|{ "a", "ch", "h", "u", "pr", "po", "co", "s", "e", "i", "o", NULL }
end_define

begin_comment
comment|/* The prefix to use to turn off all debugging.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_NONE
value|"n"
end_define

begin_comment
comment|/* Check whether a particular type of debugging is being done.  */
end_comment

begin_define
define|#
directive|define
name|FDEBUGGING
parameter_list|(
name|i
parameter_list|)
value|((iDebug& (i)) != 0)
end_define

begin_comment
comment|/* These macros are used to output debugging information.  I use    several different macros depending on the number of arguments    because no macro can take a variable number of arguments and I    don't want to use double parentheses.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MESSAGE0
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|)
define|\
value|do { if (FDEBUGGING (i)) ulog (LOG_DEBUG, (z)); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE1
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|)
define|\
value|do { if (FDEBUGGING (i)) ulog (LOG_DEBUG, (z), (a1)); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE2
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|do { if (FDEBUGGING (i)) ulog (LOG_DEBUG, (z), (a1), (a2)); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE3
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|do \     { \       if (FDEBUGGING (i)) \ 	ulog (LOG_DEBUG, (z), (a1), (a2), (a3)); \     } \   while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE4
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
define|\
value|do \     { \       if (FDEBUGGING (i)) \ 	ulog (LOG_DEBUG, (z), (a1), (a2), (a3), (a4)); \     } \   while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_comment
comment|/* If debugging information is not being compiled, provide versions of    the debugging macros which just disappear.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MESSAGE0
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE1
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE2
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE3
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_MESSAGE4
parameter_list|(
name|i
parameter_list|,
name|z
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Functions.  */
end_comment

begin_comment
comment|/* Read the configuration file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uread_config
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read information about all systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uread_all_system_info
name|P
argument_list|(
operator|(
name|int
operator|*
name|pc
operator|,
expr|struct
name|ssysteminfo
operator|*
operator|*
name|ppas
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read information about a specific system.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fread_system_info
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|,
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the default values for an uninitialized system.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uset_system_defaults
name|P
argument_list|(
operator|(
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start getting commands for unknown systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uiunknown_start
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a command defining unknown systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tcmdtabret
name|tiunknown
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
operator|,
name|pointer
name|pvar
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish getting commands for unknown systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uiunknown_end
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up the sLocalsys structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uisetup_localsys
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open a set of files and pretend that they were all catenated    together.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|smulti_file
modifier|*
name|qmulti_open
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|znames
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close a set of files opened by qmulti_open.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fmulti_close
name|P
argument_list|(
operator|(
expr|struct
name|smulti_file
operator|*
name|q
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a set of commands.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uprocesscmds
name|P
argument_list|(
operator|(
name|FILE
operator|*
name|e
operator|,
expr|struct
name|smulti_file
operator|*
name|qmulti
operator|,
specifier|const
expr|struct
name|scmdtab
operator|*
name|qcmds
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|,
name|int
name|iflags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a single command.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tcmdtabret
name|tprocess_one_cmd
name|P
argument_list|(
operator|(
name|int
name|cargs
operator|,
name|char
operator|*
operator|*
name|azargs
operator|,
specifier|const
expr|struct
name|scmdtab
operator|*
name|qcmds
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|,
name|int
name|iflags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Translate an unknown system name into something acceptable for the    spool directory stuff.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ztranslate_system
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check login name and password.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fcheck_login
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
name|zpass
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get one character from the remote system, going through the    procotol buffering.  The ctimeout argument is the timeout in    seconds, and the freport argument is TRUE if errors should be    reported (when closing a connection it is pointless to report    errors).  This returns a character or -1 on a timeout or -2 on an    error.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|breceive_char
name|P
argument_list|(
operator|(
name|int
name|ctimeout
operator|,
name|boolean
name|freport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a file belongs in the spool directory.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fspool_file
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

begin_comment
comment|/* Store information about a file being sent.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fstore_sendfile
name|P
argument_list|(
operator|(
name|openfile_t
name|e
operator|,
name|pointer
name|pseq
operator|,
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztosys
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
name|zmail
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish sending a file.  The zwhy and fnever arguments are used    if the file was not received correctly.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsent_file
name|P
argument_list|(
operator|(
name|boolean
name|freceived
operator|,
name|long
name|cbytes
operator|,
specifier|const
name|char
operator|*
name|zwhy
operator|,
name|boolean
name|fnever
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Note an error sending a file.  The function fsent_file must still    be called after this is called.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usendfile_error
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Store information about a file being received.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fstore_recfile
name|P
argument_list|(
operator|(
name|openfile_t
name|e
operator|,
name|pointer
name|pseq
operator|,
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|zfromsys
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
name|unsigned
name|int
name|imode
operator|,
specifier|const
name|char
operator|*
name|zmail
operator|,
specifier|const
name|char
operator|*
name|ztemp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish receiving a file.  The zwhy and fnever arguments are used    if the file was not received correctly.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|freceived_file
name|P
argument_list|(
operator|(
name|boolean
name|fsent
operator|,
name|long
name|cbytes
operator|,
specifier|const
name|char
operator|*
name|zwhy
operator|,
name|boolean
name|fnever
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Note an error receiving a file.  The function freceived_file must    still be called after this is called.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|urecfile_error
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare to receive a file again by discarding the previous    contents.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|frecfile_rewind
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send mail about a file transfer.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fmail_transfer
name|P
argument_list|(
operator|(
name|boolean
name|fok
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
name|zmail
operator|,
specifier|const
name|char
operator|*
name|zwhy
operator|,
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zfromsys
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
specifier|const
name|char
operator|*
name|ztosys
operator|,
specifier|const
name|char
operator|*
name|zsaved
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether a file is in one of a list of directories.  The qsys    argument are passed down to allow ~ expansion.  If fcheck is FALSE,    this does not check accessibility.  Otherwise, if freadable is    TRUE, the user zuser must have read access to the file and all    appropriate directories; if freadable is FALSE zuser must have    write access to the appropriate directories.  The zuser argument    may be NULL, in which case all users must have the appropriate    access (this is used for a remote request).  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fin_directory_list
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|,
specifier|const
name|char
operator|*
name|zdirs
operator|,
name|boolean
name|fcheck
operator|,
name|boolean
name|freadable
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the login name and password to use when calling a system out    of the call out login file.  The pzlog and pzpass arguments are set    to point to malloc'ed strings which must be freed after they have    been used.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fcallout_login
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|ssysteminfo
operator|*
name|qsys
operator|,
name|char
operator|*
operator|*
name|pzlog
operator|,
name|char
operator|*
operator|*
name|pzpass
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a string to the end of another.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uadd_string
name|P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|pz
operator|,
specifier|const
name|char
operator|*
name|z
operator|,
name|int
name|bsep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process a chat command.  These are handled using CMDTABTYPE_PREFIX.    This function switches off on argv[0].  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tcmdtabret
name|tprocess_chat_cmd
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
operator|,
name|pointer
name|pvar
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a protocol parameter entry.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tcmdtabret
name|tadd_proto_param
name|P
argument_list|(
operator|(
name|int
operator|*
name|pc
operator|,
expr|struct
name|sproto_param
operator|*
operator|*
name|pq
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|,
name|int
name|cargs
operator|,
name|char
operator|*
operator|*
name|azargs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Apply protocol parameters.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uapply_proto_params
name|P
argument_list|(
operator|(
name|int
name|bproto
operator|,
expr|struct
name|scmdtab
operator|*
name|qcmds
operator|,
name|int
name|c
operator|,
expr|struct
name|sproto_param
operator|*
name|pas
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a command string.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fparse_cmd
name|P
argument_list|(
operator|(
name|char
operator|*
name|zcmd
operator|,
expr|struct
name|scmd
operator|*
name|qcmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specify which machines may be accepted for a login name.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uadd_validate
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zlogname
operator|,
name|int
name|cmachines
operator|,
specifier|const
name|char
operator|*
operator|*
name|pazmachines
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check whether a login name/machine name pair is acceptable.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fcheck_validate
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zlogname
operator|,
specifier|const
name|char
operator|*
name|zmachine
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compare the execution times of two grades.  Return< 0 if the first    argument should be executed first, 0 if they are the same,> 0 if    the second argument should be executed first.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|igradecmp
name|P
argument_list|(
operator|(
name|int
name|b1
operator|,
name|int
name|b2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a log entry.  */
end_comment

begin_if
if|#
directive|if
name|ANSI_C
operator|&&
name|HAVE_VFPRINTF
end_if

begin_decl_stmt
specifier|extern
name|void
name|ulog
name|P
argument_list|(
operator|(
expr|enum
name|tlog
name|ttype
operator|,
specifier|const
name|char
operator|*
name|zfmt
operator|,
operator|...
operator|)
argument_list|)
if|#
directive|if
name|__GNUC__
operator|>
literal|1
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|ulog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the function to call if a fatal error occurs.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_fatal_fn
name|P
argument_list|(
operator|(
name|void
argument_list|(
argument|*pfn
argument_list|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If ffile is TRUE, send log entries to the log file rather than to    stderr.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_to_file
name|P
argument_list|(
operator|(
name|boolean
name|ffile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the ID number used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_id
name|P
argument_list|(
operator|(
name|int
name|iid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the system name used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_system
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the system and user name used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_user
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the device name used by the logging functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_device
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdevice
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close the log file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ulog_close
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an entry in the statistics file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ustats
name|P
argument_list|(
operator|(
name|boolean
name|fsucceeded
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
name|boolean
name|fsent
operator|,
name|long
name|cbytes
operator|,
name|long
name|csecs
operator|,
name|long
name|cmicros
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We have lost the connection; record any in progress file transfers    in the statistics file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ustats_failed
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Close the statistics file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ustats_close
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DEBUG
operator|>
literal|1
end_if

begin_comment
comment|/* A debugging routine to output a buffer.  This outputs zhdr, the    buffer length clen, and the contents of the buffer in quotation    marks.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|udebug_buffer
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zhdr
operator|,
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|int
name|clen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A debugging routine to make a readable version of a character.    This takes a buffer at least 5 bytes long, and returns the length    of the string it put into it (not counting the null byte).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cdebug_char
name|P
argument_list|(
operator|(
name|char
operator|*
name|z
operator|,
name|int
name|ichar
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a debugging option string.  This can either be a number or a    comma separated list of debugging names.  If the code is compiled    without debugging this is a dummy function.  This returns a value    for iDebug.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|idebug_parse
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse a debugging option in a configuration file.  This is used for    the ``debug'' command.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|tcmdtabret
name|tidebug_parse
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
operator|,
name|pointer
name|pvar
operator|,
specifier|const
name|char
operator|*
name|zerr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_comment
comment|/* Dummy version of idebug_parse.  This makes the option processing    look a little neater.  */
end_comment

begin_define
define|#
directive|define
name|idebug_parse
parameter_list|(
name|z
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG<= 1 */
end_comment

begin_comment
comment|/* Copy one file to another.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fcopy_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfrom
operator|,
specifier|const
name|char
operator|*
name|zto
operator|,
name|boolean
name|fpublic
operator|,
name|boolean
name|fmkdirs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read a line from a set of files opened by qmulti_open.  The return    value is an malloc'ed buffer.  This will return NULL when all the    files have been exhausted.  If pffirst is not NULL, it will be set    to TRUE if this is the first line of a file.  If pzname is not    NULL, it will be set to the file name from which the line was read.    If fbackslash is TRUE, lines may be continued by using a backslash    as the last character before the newline.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zmulti_gets
name|P
argument_list|(
operator|(
expr|struct
name|smulti_file
operator|*
name|q
operator|,
name|boolean
operator|*
name|pffirst
operator|,
specifier|const
name|char
operator|*
operator|*
name|pzname
operator|,
name|boolean
name|fbackslash
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read an arbitrary length string from a file, returning an malloc'ed    buffer.  If the fbackslash argument is true, lines may be continued    by using a backslash as the last character before the newline.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zfgets
name|P
argument_list|(
operator|(
name|FILE
operator|*
name|e
operator|,
name|boolean
name|fbackslash
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy a string into memory without fail.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xstrdup
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate memory without fail.  */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|xmalloc
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Realloc memory without fail.  */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|xrealloc
name|P
argument_list|(
operator|(
name|pointer
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free memory (accepts NULL pointers, which some libraries erroneously    do not).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|xfree
name|P
argument_list|(
operator|(
name|pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* Use macros to access stricmp and strnicmp as strcasecmp and    strncasecmp.  */
end_comment

begin_define
define|#
directive|define
name|strcasecmp
value|stricmp
end_define

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
comment|/* ! HAVE_STRICMP */
end_comment

begin_comment
comment|/* Use our own case insensitive string comparisons.  */
end_comment

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
name|int
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
name|HAVE_STRERROR
end_if

begin_comment
comment|/* Get a string corresponding to an error message.  */
end_comment

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
comment|/* Get the appropriate definitions for memcmp, memcpy, memchr and    bzero.  Hopefully the declarations of bzero, bcmp and bcopy will    not cause any trouble.  */
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

begin_function_decl
specifier|extern
name|int
name|bcmp
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

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

begin_if
if|#
directive|if
name|HAVE_BZERO
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|bzero
end_ifndef

begin_comment
comment|/* bzero is sometimes a macro.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bzero
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_BZERO */
end_comment

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
comment|/* Move a memory block safely.  Go through xmemmove to allow for    systems which have the prototype (using size_t, which we don't want    to use since some systems won't have it) but not the function.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_MEMMOVE
end_if

begin_define
define|#
directive|define
name|xmemmove
value|memmove
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_MEMMOVE */
end_comment

begin_decl_stmt
specifier|extern
name|pointer
name|xmemmove
name|P
argument_list|(
operator|(
name|pointer
operator|,
name|constpointer
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
comment|/* ! HAVE_MEMMOVE */
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
name|int
name|celes
operator|,
name|int
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

begin_comment
comment|/* Convert a string to lower case.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_STRLWR
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strlwr
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Global variables.  */
end_comment

begin_comment
comment|/* The name of the program being run.  This is statically initialized,    although it should perhaps be set from argv[0].  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|abProgram
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Version number string.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|abVersion
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local UUCP name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zLocalname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System information file names.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zSysfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port information file names.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zPortfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dialer information file names.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zDialfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local spool directory.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zSpooldir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Public directory.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zPubdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Log file name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zLogfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Statistics file name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zStatfile
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DEBUG
operator|>
literal|1
end_if

begin_comment
comment|/* Debugging file name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zDebugfile
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Files containing login names and passwords to use when calling out.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zCallfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Files containing login names and passwords to check when somebody    calls in.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zPwdfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Files containing dialcodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zDialcodefile
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HAVE_V2_CONFIG
end_if

begin_comment
comment|/* TRUE if we should read V2 configuration files.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fV2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read the V2 L.sys file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|uv2_read_systems
name|P
argument_list|(
operator|(
name|int
operator|*
name|pc
operator|,
expr|struct
name|ssysteminfo
operator|*
operator|*
name|ppas
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_V2_CONFIG */
end_comment

begin_if
if|#
directive|if
name|HAVE_BNU_CONFIG
end_if

begin_comment
comment|/* TRUE if we should read BNU configuration files.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fBnu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The names of the BNU system files to read.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zBnu_systems
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The names of the BNU dialers files to read.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zBnu_dialers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The names of the BNU devices files to read.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zBnu_devices
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines to read BNU files.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ubnu_read_sysfiles
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ubnu_read_systems
name|P
argument_list|(
operator|(
name|int
operator|*
name|pc
operator|,
expr|struct
name|ssysteminfo
operator|*
operator|*
name|ppas
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BNU_CONFIG */
end_comment

begin_comment
comment|/* TRUE if we accept calls from unknown system.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fUnknown_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ssysteminfo structure we use for unknown systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ssysteminfo
name|sUnknown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The ssysteminfo structure we use for the local system.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ssysteminfo
name|sLocalsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The maximum number of uuxqt processes which may be running at one    time.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cMaxuuxqts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When a signal occurs, the signal handlers sets the appropriate    element of the arrays afSignal and afLog_signal to TRUE.  The    afSignal array is used to check whether a signal occurred.  The    afLog_signal array tells ulog to log the signal; ulog will clear    the element after logging it, which means that if a signal comes in    at just the right moment it will not be logged.  It will always be    recorded in afSignal, though.  At the moment we handle 5 signals:    SIGHUP, SIGINT, SIGQUIT, SIGTERM and SIGPIPE (the Unix code also    handles SIGALRM).  If we want to handle more, the afSignal array    must be extended; I see little point to handling any of the other    ANSI C or POSIX signals, as they are either unlikely to occur    (SIGABRT, SIGUSR1) or nearly impossible to handle cleanly (SIGILL,    SIGSEGV).  */
end_comment

begin_define
define|#
directive|define
name|INDEXSIG_SIGHUP
value|(0)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGINT
value|(1)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGQUIT
value|(2)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGTERM
value|(3)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_SIGPIPE
value|(4)
end_define

begin_define
define|#
directive|define
name|INDEXSIG_COUNT
value|(5)
end_define

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|afSignal
index|[
name|INDEXSIG_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|afLog_signal
index|[
name|INDEXSIG_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The names of the signals to use in error messages, as an    initializer for an array.  */
end_comment

begin_define
define|#
directive|define
name|INDEXSIG_NAMES
define|\
value|{ "hangup", "interrupt", "quit", "termination", "SIGPIPE" }
end_define

begin_comment
comment|/* Check to see whether we've received a signal.  It would be nice if    we could use a single variable for this, but we sometimes want to    clear our knowledge of a signal and that would cause race    conditions (clearing a single element of the array is not a race    assuming that we don't care about a particular signal, even if it    occurs after we've examined the array).  */
end_comment

begin_define
define|#
directive|define
name|FGOT_SIGNAL
parameter_list|()
define|\
value|(afSignal[INDEXSIG_SIGHUP] || afSignal[INDEXSIG_SIGINT] \    || afSignal[INDEXSIG_SIGQUIT] || afSignal[INDEXSIG_SIGTERM] \    || afSignal[INDEXSIG_SIGPIPE])
end_define

begin_comment
comment|/* If we get a SIGINT in uucico, we continue the current communication    session but don't start any new ones.  This macros checks for any    signal other than SIGINT, which means we should get out    immediately.  */
end_comment

begin_define
define|#
directive|define
name|FGOT_QUIT_SIGNAL
parameter_list|()
define|\
value|(afSignal[INDEXSIG_SIGHUP] || afSignal[INDEXSIG_SIGQUIT] \    || afSignal[INDEXSIG_SIGTERM] || afSignal[INDEXSIG_SIGPIPE])
end_define

begin_comment
comment|/* File being sent.  */
end_comment

begin_decl_stmt
specifier|extern
name|openfile_t
name|eSendfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File being received.  */
end_comment

begin_decl_stmt
specifier|extern
name|openfile_t
name|eRecfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device name to log.  This is set by fport_open.  It may be NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zLdevice
decl_stmt|;
end_decl_stmt

end_unit

