begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Portability cruft.  Include after config.h and sys/types.h.    Copyright (C) 1996, 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|PARAMS
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_PTR_T
end_ifndef

begin_define
define|#
directive|define
name|_PTR_T
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|ptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|_PTR_T
end_ifndef

begin_define
define|#
directive|define
name|_PTR_T
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|ptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_decl_stmt
name|int
name|open
argument_list|()
decl_stmt|,
name|read
argument_list|()
decl_stmt|,
name|close
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|E
parameter_list|)
value|(0<= (E)&& (E)< sys_nerr ? _(sys_errlist[E]) : _("Unknown system error"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some operating systems treat text and binary files differently.  */
end_comment

begin_if
if|#
directive|if
name|O_BINARY
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETMODE
end_ifdef

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|fd
parameter_list|)
value|setmode (fd, O_BINARY)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|fd
parameter_list|)
value|_setmode (fd, O_BINARY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

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

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|fd
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DOS_FILE_NAMES
end_ifdef

begin_define
define|#
directive|define
name|IS_SLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == '/' || (c) == '\\')
end_define

begin_define
define|#
directive|define
name|FILESYSTEM_PREFIX_LEN
parameter_list|(
name|f
parameter_list|)
value|((f)[0]&& (f)[1] == ':' ? 2 : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IS_SLASH
end_ifndef

begin_define
define|#
directive|define
name|IS_SLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILESYSTEM_PREFIX_LEN
end_ifndef

begin_define
define|#
directive|define
name|FILESYSTEM_PREFIX_LEN
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This assumes _WIN32, like DJGPP, has D_OK.  Does it?  In what header?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|D_OK
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|EISDIR
end_ifdef

begin_define
define|#
directive|define
name|is_EISDIR
parameter_list|(
name|e
parameter_list|,
name|f
parameter_list|)
define|\
value|((e) == EISDIR \       || ((e) == EACCES&& access (f, D_OK) == 0&& ((e) = EISDIR, 1)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|is_EISDIR
parameter_list|(
name|e
parameter_list|,
name|f
parameter_list|)
value|((e) == EACCES&& access (f, D_OK) == 0)
end_define

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
name|is_EISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|EISDIR
end_ifdef

begin_define
define|#
directive|define
name|is_EISDIR
parameter_list|(
name|e
parameter_list|,
name|f
parameter_list|)
value|((e) == EISDIR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|is_EISDIR
parameter_list|(
name|e
parameter_list|,
name|f
parameter_list|)
value|0
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
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|ptr_t
name|malloc
argument_list|()
decl_stmt|,
name|realloc
argument_list|()
decl_stmt|,
name|calloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|free
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
name|__STDC__
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

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

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
name|CHAR_BIT
end_ifndef

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The extra casts work around common compiler bugs.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (TYPE_SIGNED (t) \ 			      ? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) \ 			      : (t) 0))
end_define

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MAX
value|TYPE_MAXIMUM (char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|TYPE_MAXIMUM (int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|TYPE_MAXIMUM (unsigned char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MEMORY_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
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
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
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

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_undef
undef|#
directive|undef
name|strrchr
end_undef

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_undef
undef|#
directive|undef
name|memcpy
end_undef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|bcopy (s, d, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MEMCHR
end_ifndef

begin_function_decl
name|ptr_t
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
operator|!
name|defined
name|HAVE_MEMMOVE
operator|&&
operator|!
name|defined
name|memmove
end_if

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|bcopy (s, d, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|isgraph
end_ifndef

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|C
parameter_list|)
value|(isprint(C)&& !isspace(C))
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
name|STDC_HEADERS
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISASCII
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isalpha (C))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isupper (C))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& islower (C))
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isdigit (C))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isxdigit (C))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isspace (C))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& ispunct (C))
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isalnum (C))
end_define

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isprint (C))
end_define

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& isgraph (C))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|C
parameter_list|)
value|(IN_CTYPE_DOMAIN (C)&& iscntrl (C))
end_define

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|C
parameter_list|)
value|(ISUPPER(C) ? tolower(C) : (C))
end_define

begin_if
if|#
directive|if
name|ENABLE_NLS
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_if
if|#
directive|if
name|HAVE_SETLOCALE
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|initialize_main
end_ifndef

begin_define
define|#
directive|define
name|initialize_main
parameter_list|(
name|argcp
parameter_list|,
name|argvp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

