begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tailor.h -- target dependent definitions  * Copyright (C) 1992-1993 Jean-loup Gailly.  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_comment
comment|/* The target dependent definitions should be defined here only.  * The target dependent functions should be defined in tailor.c.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MSDOS
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
name|__OS2__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

begin_define
define|#
directive|define
name|OS2
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
name|OS2
argument_list|)
operator|&&
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_comment
comment|/* MS C under OS/2 */
end_comment

begin_undef
undef|#
directive|undef
name|MSDOS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/* DJGPP version 1.09+ on MS-DOS.       * The DJGPP 1.09 stat() function must be upgraded before gzip will       * fully work.       * No need for DIRENT, since<unistd.h> defines POSIX_SOURCE which       * implies DIRENT.       */
end_comment

begin_define
define|#
directive|define
name|near
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXSEG_64K
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_define
define|#
directive|define
name|NO_OFF_T
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_UTIME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MSC */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTIME_H
end_define

begin_define
define|#
directive|define
name|NO_UTIME_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PATH_SEP2
value|'\\'
end_define

begin_define
define|#
directive|define
name|PATH_SEP3
value|':'
end_define

begin_define
define|#
directive|define
name|MAX_PATH_LEN
value|128
end_define

begin_define
define|#
directive|define
name|NO_MULTIPLE_DOTS
end_define

begin_define
define|#
directive|define
name|MAX_EXT_CHARS
value|3
end_define

begin_define
define|#
directive|define
name|Z_SUFFIX
value|"z"
end_define

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|PROTO
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|NO_SIZE_CHECK
end_define

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|tolow(c)
end_define

begin_comment
comment|/* Force file names to lower case */
end_comment

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_define
define|#
directive|define
name|OS_CODE
value|0x00
end_define

begin_define
define|#
directive|define
name|SET_BINARY_MODE
parameter_list|(
name|fd
parameter_list|)
value|setmode(fd, O_BINARY)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ASMV
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASMV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|near
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|PATH_SEP2
value|'\\'
end_define

begin_define
define|#
directive|define
name|PATH_SEP3
value|':'
end_define

begin_define
define|#
directive|define
name|MAX_PATH_LEN
value|260
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OS2FAT
end_ifdef

begin_define
define|#
directive|define
name|NO_MULTIPLE_DOTS
end_define

begin_define
define|#
directive|define
name|MAX_EXT_CHARS
value|3
end_define

begin_define
define|#
directive|define
name|Z_SUFFIX
value|"z"
end_define

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|tolow(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|PROTO
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_define
define|#
directive|define
name|OS_CODE
value|0x06
end_define

begin_define
define|#
directive|define
name|SET_BINARY_MODE
parameter_list|(
name|fd
parameter_list|)
value|setmode(fd, O_BINARY)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SYS_UTIME_H
end_define

begin_define
define|#
directive|define
name|NO_UTIME_H
end_define

begin_define
define|#
directive|define
name|MAXSEG_64K
end_define

begin_undef
undef|#
directive|undef
name|near
end_undef

begin_define
define|#
directive|define
name|near
value|_near
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SYS_UTIME_H
end_define

begin_define
define|#
directive|define
name|NO_UTIME_H
end_define

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_define
define|#
directive|define
name|EXPAND
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
define|\
value|{_response(&argc,&argv); _wildcard(&argc,&argv);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ZTC__
end_ifdef

begin_define
define|#
directive|define
name|NO_DIR
end_define

begin_define
define|#
directive|define
name|NO_UTIME_H
end_define

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_define
define|#
directive|define
name|EXPAND
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
define|\
value|{response_expand(&argc,&argv);}
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
name|WIN32
end_ifdef

begin_comment
comment|/* Windows NT */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UTIME_H
end_define

begin_define
define|#
directive|define
name|NO_UTIME_H
end_define

begin_define
define|#
directive|define
name|PATH_SEP2
value|'\\'
end_define

begin_define
define|#
directive|define
name|PATH_SEP3
value|':'
end_define

begin_define
define|#
directive|define
name|MAX_PATH_LEN
value|260
end_define

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|PROTO
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|SET_BINARY_MODE
parameter_list|(
name|fd
parameter_list|)
value|setmode(fd, O_BINARY)
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NTFAT
end_ifdef

begin_define
define|#
directive|define
name|NO_MULTIPLE_DOTS
end_define

begin_define
define|#
directive|define
name|MAX_EXT_CHARS
value|3
end_define

begin_define
define|#
directive|define
name|Z_SUFFIX
value|"z"
end_define

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|tolow(c)
end_define

begin_comment
comment|/* Force file names to lower case */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OS_CODE
value|0x0b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_include
include|#
directive|include
file|<alloc.h>
end_include

begin_define
define|#
directive|define
name|DYN_ALLOC
end_define

begin_comment
comment|/* Turbo C 2.0 does not accept static allocations of large arrays */
end_comment

begin_function_decl
name|void
modifier|*
name|fcalloc
parameter_list|(
name|unsigned
name|items
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fcfree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MSC */
end_comment

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_define
define|#
directive|define
name|fcalloc
parameter_list|(
name|nitems
parameter_list|,
name|itemsize
parameter_list|)
value|halloc((long)(nitems),(itemsize))
end_define

begin_define
define|#
directive|define
name|fcfree
parameter_list|(
name|ptr
parameter_list|)
value|hfree(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXSEG_64K
end_ifdef

begin_define
define|#
directive|define
name|fcalloc
parameter_list|(
name|items
parameter_list|,
name|size
parameter_list|)
value|calloc((items),(size))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fcalloc
parameter_list|(
name|items
parameter_list|,
name|size
parameter_list|)
value|malloc((size_t)(items)*(size_t)(size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|fcfree
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
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
name|VAXC
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PATH_SEP
value|']'
end_define

begin_define
define|#
directive|define
name|PATH_SEP2
value|':'
end_define

begin_define
define|#
directive|define
name|SUFFIX_SEP
value|';'
end_define

begin_define
define|#
directive|define
name|NO_MULTIPLE_DOTS
end_define

begin_define
define|#
directive|define
name|Z_SUFFIX
value|"-gz"
end_define

begin_define
define|#
directive|define
name|RECORD_IO
value|1
end_define

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|tolow(c)
end_define

begin_define
define|#
directive|define
name|OS_CODE
value|0x02
end_define

begin_define
define|#
directive|define
name|OPTIONS_VAR
value|"GZIP_OPT"
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|NO_UTIME
end_define

begin_define
define|#
directive|define
name|EXPAND
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
value|vms_expand_args(&argc,&argv);
end_define

begin_include
include|#
directive|include
file|<file.h>
end_include

begin_define
define|#
directive|define
name|unlink
value|delete
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VAXC
end_ifdef

begin_define
define|#
directive|define
name|NO_FCNTL_H
end_define

begin_include
include|#
directive|include
file|<unixio.h>
end_include

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
name|AMIGA
end_ifdef

begin_define
define|#
directive|define
name|PATH_SEP2
value|':'
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|OS_CODE
value|0x01
end_define

begin_define
define|#
directive|define
name|ASMV
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SASC */
end_comment

begin_define
define|#
directive|define
name|NO_STDIN_FSTAT
end_define

begin_define
define|#
directive|define
name|SYSDIR
end_define

begin_define
define|#
directive|define
name|NO_SYMLINK
end_define

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|NO_FCNTL_H
end_define

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* for read() and write() */
end_comment

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_function_decl
specifier|extern
name|void
name|_expand_args
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|EXPAND
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
value|_expand_args(&argc,&argv);
end_define

begin_undef
undef|#
directive|undef
name|O_BINARY
end_undef

begin_comment
comment|/* disable useless --ascii option */
end_comment

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
name|ATARI
argument_list|)
operator|||
name|defined
argument_list|(
name|atarist
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|STDC_HEADERS
end_ifndef

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
end_define

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASMV
end_define

begin_define
define|#
directive|define
name|OS_CODE
value|0x05
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TOSFS
end_ifdef

begin_define
define|#
directive|define
name|PATH_SEP2
value|'\\'
end_define

begin_define
define|#
directive|define
name|PATH_SEP3
value|':'
end_define

begin_define
define|#
directive|define
name|MAX_PATH_LEN
value|128
end_define

begin_define
define|#
directive|define
name|NO_MULTIPLE_DOTS
end_define

begin_define
define|#
directive|define
name|MAX_EXT_CHARS
value|3
end_define

begin_define
define|#
directive|define
name|Z_SUFFIX
value|"z"
end_define

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|tolow(c)
end_define

begin_comment
comment|/* Force file names to lower case */
end_comment

begin_define
define|#
directive|define
name|NO_SYMLINK
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
name|MACOS
end_ifdef

begin_define
define|#
directive|define
name|PATH_SEP
value|':'
end_define

begin_define
define|#
directive|define
name|DYN_ALLOC
end_define

begin_define
define|#
directive|define
name|PROTO
end_define

begin_define
define|#
directive|define
name|NO_STDIN_FSTAT
end_define

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|NO_UTIME
end_define

begin_define
define|#
directive|define
name|chmod
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name, flags)
end_define

begin_define
define|#
directive|define
name|OS_CODE
value|0x07
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MPW
end_ifdef

begin_define
define|#
directive|define
name|isatty
parameter_list|(
name|fd
parameter_list|)
value|((fd)<= 2)
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
name|__50SERIES
end_ifdef

begin_comment
comment|/* Prime/PRIMOS */
end_comment

begin_define
define|#
directive|define
name|PATH_SEP
value|'>'
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_define
define|#
directive|define
name|NO_MEMORY_H
end_define

begin_define
define|#
directive|define
name|NO_UTIME_H
end_define

begin_define
define|#
directive|define
name|NO_UTIME
end_define

begin_define
define|#
directive|define
name|NO_CHOWN
end_define

begin_define
define|#
directive|define
name|NO_STDIN_FSTAT
end_define

begin_define
define|#
directive|define
name|NO_SIZE_CHECK
end_define

begin_define
define|#
directive|define
name|NO_SYMLINK
end_define

begin_define
define|#
directive|define
name|RECORD_IO
value|1
end_define

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|tolow(c)
end_define

begin_comment
comment|/* Force file names to lower case */
end_comment

begin_define
define|#
directive|define
name|put_char
parameter_list|(
name|c
parameter_list|)
value|put_byte((c)& 0x7F)
end_define

begin_define
define|#
directive|define
name|get_char
parameter_list|(
name|c
parameter_list|)
value|ascii2pascii(get_byte())
end_define

begin_define
define|#
directive|define
name|OS_CODE
value|0x0F
end_define

begin_comment
comment|/* temporary, subject to change */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTERM
end_ifdef

begin_undef
undef|#
directive|undef
name|SIGTERM
end_undef

begin_comment
comment|/* We don't want a signal handler for SIGTERM */
end_comment

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
name|pyr
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NOMEMCPY
argument_list|)
end_if

begin_comment
comment|/* Pyramid */
end_comment

begin_define
define|#
directive|define
name|NOMEMCPY
end_define

begin_comment
comment|/* problem with overlapping copies */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TOPS20
end_ifdef

begin_define
define|#
directive|define
name|OS_CODE
value|0x0a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|unix
end_ifndef

begin_define
define|#
directive|define
name|NO_ST_INO
end_define

begin_comment
comment|/* don't rely on inode numbers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common defaults */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OS_CODE
end_ifndef

begin_define
define|#
directive|define
name|OS_CODE
value|0x03
end_define

begin_comment
comment|/* assume Unix */
end_comment

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
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|casemap
end_ifndef

begin_define
define|#
directive|define
name|casemap
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPTIONS_VAR
end_ifndef

begin_define
define|#
directive|define
name|OPTIONS_VAR
value|"GZIP"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Z_SUFFIX
end_ifndef

begin_define
define|#
directive|define
name|Z_SUFFIX
value|".gz"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAX_EXT_CHARS
end_ifdef

begin_define
define|#
directive|define
name|MAX_SUFFIX
value|MAX_EXT_CHARS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_SUFFIX
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAKE_LEGAL_NAME
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NO_MULTIPLE_DOTS
end_ifdef

begin_define
define|#
directive|define
name|MAKE_LEGAL_NAME
parameter_list|(
name|name
parameter_list|)
value|make_simple_name(name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAKE_LEGAL_NAME
parameter_list|(
name|name
parameter_list|)
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
name|MIN_PART
end_ifndef

begin_define
define|#
directive|define
name|MIN_PART
value|3
end_define

begin_comment
comment|/* keep at least MIN_PART chars between dots in a file name. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXPAND
end_ifndef

begin_define
define|#
directive|define
name|EXPAND
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RECORD_IO
end_ifndef

begin_define
define|#
directive|define
name|RECORD_IO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SET_BINARY_MODE
end_ifndef

begin_define
define|#
directive|define
name|SET_BINARY_MODE
parameter_list|(
name|fd
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPEN
end_ifndef

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name, flags, mode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|get_char
end_ifndef

begin_define
define|#
directive|define
name|get_char
parameter_list|()
value|get_byte()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|put_char
end_ifndef

begin_define
define|#
directive|define
name|put_char
parameter_list|(
name|c
parameter_list|)
value|put_byte(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

