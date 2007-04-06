begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/* zutil.h -- internal interface and configuration of the compression library  * Copyright (C) 1995-2005 Jean-loup Gailly.  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_ZUTIL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_define
define|#
directive|define
name|ZLIB_INTERNAL
end_define

begin_include
include|#
directive|include
file|"zlib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STDC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_ERRNO_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WCE
end_ifdef

begin_comment
comment|/* The Microsoft C Run-Time Library for Windows CE doesn't have        * errno.  We define it as a global variable to simplify porting.        * Its value is always 0 and should not be used.  We rename it to        * avoid conflict with other libraries that use the same workaround.        */
end_comment

begin_define
define|#
directive|define
name|errno
value|z_errno
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/errno.h>
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
name|local
end_ifndef

begin_define
define|#
directive|define
name|local
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* compile with -Dlocal if your debugger can't find static symbols */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uch
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uch
name|FAR
name|uchf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ush
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ush
name|FAR
name|ushf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulg
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|z_errmsg
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indexed by 2-zlib_error */
end_comment

begin_comment
comment|/* (size given to avoid silly warnings with Visual C++) */
end_comment

begin_define
define|#
directive|define
name|ERR_MSG
parameter_list|(
name|err
parameter_list|)
value|z_errmsg[Z_NEED_DICT-(err)]
end_define

begin_define
define|#
directive|define
name|ERR_RETURN
parameter_list|(
name|strm
parameter_list|,
name|err
parameter_list|)
define|\
value|return (strm->msg = (char*)ERR_MSG(err), (err))
end_define

begin_comment
comment|/* To be used only when the state is known to be valid */
end_comment

begin_comment
comment|/* common constants */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEF_WBITS
end_ifndef

begin_define
define|#
directive|define
name|DEF_WBITS
value|MAX_WBITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default windowBits for decompression. MAX_WBITS is for compression only */
end_comment

begin_if
if|#
directive|if
name|MAX_MEM_LEVEL
operator|>=
literal|8
end_if

begin_define
define|#
directive|define
name|DEF_MEM_LEVEL
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEF_MEM_LEVEL
value|MAX_MEM_LEVEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default memLevel */
end_comment

begin_define
define|#
directive|define
name|STORED_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|STATIC_TREES
value|1
end_define

begin_define
define|#
directive|define
name|DYN_TREES
value|2
end_define

begin_comment
comment|/* The three kinds of block type */
end_comment

begin_define
define|#
directive|define
name|MIN_MATCH
value|3
end_define

begin_define
define|#
directive|define
name|MAX_MATCH
value|258
end_define

begin_comment
comment|/* The minimum and maximum match lengths */
end_comment

begin_define
define|#
directive|define
name|PRESET_DICT
value|0x20
end_define

begin_comment
comment|/* preset dictionary flag in zlib header */
end_comment

begin_comment
comment|/* target dependencies */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|WINDOWS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|OS_CODE
value|0x00
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|__STDC__
operator|==
literal|1
operator|)
operator|&&
operator|(
name|defined
argument_list|(
name|__LARGE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__COMPACT__
argument_list|)
operator|)
end_if

begin_comment
comment|/* Allow compilation with ANSI keywords only enabled */
end_comment

begin_function_decl
name|void
name|_Cdecl
name|farfree
parameter_list|(
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_Cdecl
name|farmalloc
parameter_list|(
name|unsigned
name|long
name|nbytes
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
file|<alloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MSC or DJGPP */
end_comment

begin_include
include|#
directive|include
file|<malloc.h>
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
name|OS_CODE
value|0x01
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
name|OS_CODE
value|0x02
end_define

begin_define
define|#
directive|define
name|F_OPEN
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|)
define|\
value|fopen((name), (mode), "mbc=60", "ctx=stm", "rfm=fix", "mrs=512")
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
name|ATARI
argument_list|)
operator|||
name|defined
argument_list|(
name|atarist
argument_list|)
end_if

begin_define
define|#
directive|define
name|OS_CODE
value|0x05
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
name|OS_CODE
value|0x06
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M_I86
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

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
name|MACOS
argument_list|)
operator|||
name|defined
argument_list|(
name|TARGET_OS_MAC
argument_list|)
end_if

begin_define
define|#
directive|define
name|OS_CODE
value|0x07
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
name|__dest_os
operator|!=
name|__be_os
operator|&&
name|__dest_os
operator|!=
name|__win32_os
end_if

begin_include
include|#
directive|include
file|<unix.h>
end_include

begin_comment
comment|/* for fdopen */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|fdopen
end_ifndef

begin_define
define|#
directive|define
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
value|NULL
end_define

begin_comment
comment|/* No fdopen() */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__CYGWIN__
end_ifndef

begin_comment
comment|/* Cygwin is Unix, not Win32 */
end_comment

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
name|OS_CODE
value|0x0f
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
name|_BEOS_
argument_list|)
operator|||
name|defined
argument_list|(
name|RISCOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
value|NULL
end_define

begin_comment
comment|/* No fdopen() */
end_comment

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
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>
literal|600
operator|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
value|NULL
end_define

begin_comment
comment|/* No fdopen() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRDIFF_T_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|int
name|ptrdiff_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PTRDIFF_T_DEFINED
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
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|type
parameter_list|)
value|_fdopen(fd,type)
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
comment|/* common defaults */
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
name|F_OPEN
end_ifndef

begin_define
define|#
directive|define
name|F_OPEN
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|)
value|fopen((name), (mode))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* functions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC99
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
name|__TURBOC__
operator|>=
literal|0x550
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VSNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
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
name|__CYGWIN__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VSNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
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
name|HAVE_VSNPRINTF
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_comment
comment|/* vsnprintf may exist on some MS-DOS compilers (DJGPP?),         but for now we just assume it doesn't. */
end_comment

begin_define
define|#
directive|define
name|NO_vsnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_define
define|#
directive|define
name|NO_vsnprintf
end_define

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
comment|/* In Win32, vsnprintf is available as the "non-ANSI" _vsnprintf. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vsnprintf
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_vsnprintf
argument_list|)
end_if

begin_define
define|#
directive|define
name|vsnprintf
value|_vsnprintf
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
name|__SASC
end_ifdef

begin_define
define|#
directive|define
name|NO_vsnprintf
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
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|NO_vsnprintf
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
name|pyr
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_MEMCPY
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
name|SMALL_MEDIUM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__SC__
argument_list|)
end_if

begin_comment
comment|/* Use our own functions for small and medium model with MSC<= 5.0.   * You may have to use the same strategy for Borland C (untested).   * The __SC__ check is for Symantec.   */
end_comment

begin_define
define|#
directive|define
name|NO_MEMCPY
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
name|STDC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_MEMCPY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_MEMCPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_MEMCPY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMCPY
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL_MEDIUM
end_ifdef

begin_comment
comment|/* MSDOS small or medium model */
end_comment

begin_define
define|#
directive|define
name|zmemcpy
value|_fmemcpy
end_define

begin_define
define|#
directive|define
name|zmemcmp
value|_fmemcmp
end_define

begin_define
define|#
directive|define
name|zmemzero
parameter_list|(
name|dest
parameter_list|,
name|len
parameter_list|)
value|_fmemset(dest, 0, len)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|zmemcpy
value|memcpy
end_define

begin_define
define|#
directive|define
name|zmemcmp
value|memcmp
end_define

begin_define
define|#
directive|define
name|zmemzero
parameter_list|(
name|dest
parameter_list|,
name|len
parameter_list|)
value|memset(dest, 0, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|zmemcpy
name|OF
argument_list|(
operator|(
name|void
operator|*
name|dest
operator|,
specifier|const
name|void
operator|*
name|source
operator|,
name|uInt
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zmemcmp
name|OF
argument_list|(
operator|(
specifier|const
name|void
operator|*
name|s1
operator|,
specifier|const
name|void
operator|*
name|s2
operator|,
name|uInt
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|zmemzero
name|OF
argument_list|(
operator|(
name|void
operator|*
name|dest
operator|,
name|uInt
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Diagnostic functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|z_verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|z_error
name|OF
argument_list|(
operator|(
name|char
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
value|{if(!(cond)) z_error(msg);}
end_define

begin_define
define|#
directive|define
name|Trace
parameter_list|(
name|x
parameter_list|)
value|{if (z_verbose>=0) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracev
parameter_list|(
name|x
parameter_list|)
value|{if (z_verbose>0) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracevv
parameter_list|(
name|x
parameter_list|)
value|{if (z_verbose>1) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracec
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
value|{if (z_verbose>0&& (c)) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracecv
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
value|{if (z_verbose>1&& (c)) fprintf x ;}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Assert
parameter_list|(
name|cond
parameter_list|,
name|msg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Trace
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracev
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracevv
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracec
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Tracecv
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|voidpf
name|zcalloc
name|OF
argument_list|(
operator|(
name|voidpf
name|opaque
operator|,
name|unsigned
name|items
operator|,
name|unsigned
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|zcfree
name|OF
argument_list|(
operator|(
name|voidpf
name|opaque
operator|,
name|voidpf
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ZALLOC
parameter_list|(
name|strm
parameter_list|,
name|items
parameter_list|,
name|size
parameter_list|)
define|\
value|(*((strm)->zalloc))((strm)->opaque, (items), (size))
end_define

begin_define
define|#
directive|define
name|ZFREE
parameter_list|(
name|strm
parameter_list|,
name|addr
parameter_list|)
value|(*((strm)->zfree))((strm)->opaque, (voidpf)(addr))
end_define

begin_define
define|#
directive|define
name|TRY_FREE
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|{if (p) ZFREE(s, p);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ZUTIL_H */
end_comment

end_unit

