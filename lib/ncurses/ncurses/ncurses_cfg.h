begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/ncurses_cfg.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2004,2005 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Thomas E. Dickey<dickey@clark.net> 1997                        *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: ncurses_cfg.hin,v 1.7 2005/01/02 01:26:58 tom Exp $  *  * This is a template-file used to generate the "ncurses_cfg.h" file.  *  * Rather than list every definition, the configuration script substitutes the  * definitions that it finds using 'sed'.  You need a patch (original date  * 971222) to autoconf 2.12 or 2.13 to do this.  *  * See:  *	http://invisible-island.net/autoconf/  *	ftp://invisible-island.net/autoconf/  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NC_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|NC_CONFIG_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BSD_TPUTS
value|1
end_define

begin_define
define|#
directive|define
name|CC_HAS_INLINE_FUNCS
value|1
end_define

begin_define
define|#
directive|define
name|CC_HAS_PROTOS
value|1
end_define

begin_define
define|#
directive|define
name|CPP_HAS_STATIC_CAST
value|1
end_define

begin_define
define|#
directive|define
name|CPP_HAS_VSCAN_FUNC
value|1
end_define

begin_define
define|#
directive|define
name|ETIP_NEEDS_MATH_H
value|1
end_define

begin_define
define|#
directive|define
name|GCC_NORETURN
value|__attribute__((noreturn))
end_define

begin_define
define|#
directive|define
name|GCC_PRINTF
value|1
end_define

begin_define
define|#
directive|define
name|GCC_SCANF
value|1
end_define

begin_define
define|#
directive|define
name|GCC_UNUSED
value|__attribute__((unused))
end_define

begin_define
define|#
directive|define
name|HAVE_BIG_CORE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_CGETENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CURSES_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FORM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FSEEKO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETOPT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETTTYNAM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_HAS_KEY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ISSETUGID
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LANGINFO_CODESET
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBFORM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBMENU
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIBPANEL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LINK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MENU_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NANOSLEEP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_NC_ALLOC_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PANEL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REGEX_H_FUNCS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REMOVE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RESIZETERM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_RESIZE_TERM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETBUF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETBUFFER
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIZECHANGE
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SLK_COLOR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
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
name|HAVE_STRINGS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYMLINK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_SELECT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TCGETATTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TCGETPGRP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TIMES
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TTYENT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_TYPEINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_UNLINK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_USE_DEFAULT_COLORS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VSSCANF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WORKING_POLL
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WRESIZE
value|1
end_define

begin_define
define|#
directive|define
name|MIXEDCASE_FILENAMES
value|1
end_define

begin_define
define|#
directive|define
name|NCURSES_EXT_FUNCS
value|1
end_define

begin_define
define|#
directive|define
name|NCURSES_NO_PADDING
value|1
end_define

begin_define
define|#
directive|define
name|NCURSES_PATHSEP
value|':'
end_define

begin_define
define|#
directive|define
name|NCURSES_VERSION_STRING
value|"5.6.20061217"
end_define

begin_define
define|#
directive|define
name|NDEBUG
value|1
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|SIZEOF_SIGNED_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|SYSTEM_NAME
value|"FreeBSD"
end_define

begin_define
define|#
directive|define
name|TERMPATH
value|"/etc/termcap:/usr/share/misc/termcap"
end_define

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_define
define|#
directive|define
name|TYPEOF_CHTYPE
value|int
end_define

begin_define
define|#
directive|define
name|USE_ASSUMED_COLOR
value|1
end_define

begin_define
define|#
directive|define
name|USE_COLORFGBG
value|1
end_define

begin_define
define|#
directive|define
name|USE_GETCAP
value|1
end_define

begin_define
define|#
directive|define
name|USE_HASHMAP
value|1
end_define

begin_define
define|#
directive|define
name|USE_LINKS
value|1
end_define

begin_define
define|#
directive|define
name|USE_SIGWINCH
value|1
end_define

begin_define
define|#
directive|define
name|USE_STDIO_VSCAN
value|1
end_define

begin_define
define|#
directive|define
name|USE_SYSMOUSE
value|1
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_WIDEC
end_ifdef

begin_define
define|#
directive|define
name|USE_WIDEC_SUPPORT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PUTWC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_BTOWC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCTOB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MBTOWC
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCTOMB
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MBLEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MBRLEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MBRTOWC
value|1
end_define

begin_define
define|#
directive|define
name|NEED_WCHAR_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ncurses_def.h>
end_include

begin_comment
comment|/* The C compiler may not treat these properly but C++ has to */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|lint
argument_list|)
operator|||
name|defined
argument_list|(
name|TRACE
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|inline
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On HP-UX, the C compiler doesn't grok mbstate_t without 	   -D_XOPEN_SOURCE=500. However, this causes problems on 	   IRIX. So, we #define mbstate_t to int in configure.in 	   only for the C compiler if needed. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_MBSTATE_T_DEF
end_ifdef

begin_define
define|#
directive|define
name|mbstate_t
value|int
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

begin_comment
comment|/* NC_CONFIG_H */
end_comment

end_unit

