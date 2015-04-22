begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* zutil.h -- internal interface and configuration of the compression library  * Copyright (C) 1995-1996 Jean-loup Gailly.  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_comment
comment|/* From: zutil.h,v 1.16 1996/07/24 13:41:13 me Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Z_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_Z_UTIL_H
end_define

begin_define
define|#
directive|define
name|ZEXPORT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/zlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"zlib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Assume this is a *BSD or SVR4 kernel */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_define
define|#
directive|define
name|HAVE_MEMCPY
end_define

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
value|bcopy((s), (d), (n))
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|)
value|bzero((d), (n))
end_define

begin_define
define|#
directive|define
name|memcmp
value|bcmp
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_comment
comment|/* Assume this is a Linux kernel */
end_comment

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_define
define|#
directive|define
name|HAVE_MEMCPY
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not kernel */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|RISCOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_else
else|#
directive|else
end_else

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

begin_ifdef
ifdef|#
directive|ifdef
name|STDC
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
value|return (strm->msg = (const char*)ERR_MSG(err), (err))
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

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_define
define|#
directive|define
name|OS_CODE
value|0x00
end_define

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
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|OS_CODE
value|0x06
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
comment|/* Window 95& Windows NT */
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
name|FOPEN
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
name|MACOS
end_ifdef

begin_define
define|#
directive|define
name|OS_CODE
value|0x07
end_define

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
value|0x0F
end_define

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
name|FOPEN
end_ifndef

begin_define
define|#
directive|define
name|FOPEN
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRERROR
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|OF
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|zstrerror
parameter_list|(
name|errnum
parameter_list|)
value|strerror(errnum)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|zstrerror
parameter_list|(
name|errnum
parameter_list|)
value|""
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
operator|(
name|defined
argument_list|(
name|M_I86SM
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I86MM
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|/* Use our own functions for small and medium model with MSC<= 5.0.   * You may have to use the same strategy for Borland C (untested).   */
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
name|Bytef
operator|*
name|dest
operator|,
name|Bytef
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
name|Bytef
operator|*
name|s1
operator|,
name|Bytef
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
name|Bytef
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
name|DEBUG_ZLIB
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|verbose
end_ifndef

begin_define
define|#
directive|define
name|verbose
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|fprintf x
end_define

begin_define
define|#
directive|define
name|Tracev
parameter_list|(
name|x
parameter_list|)
value|{if (verbose) fprintf x ;}
end_define

begin_define
define|#
directive|define
name|Tracevv
parameter_list|(
name|x
parameter_list|)
value|{if (verbose>1) fprintf x ;}
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
value|{if (verbose&& (c)) fprintf x ;}
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
value|{if (verbose>1&& (c)) fprintf x ;}
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

begin_typedef
typedef|typedef
name|uLong
argument_list|(
argument|*check_func
argument_list|)
name|OF
argument_list|(
operator|(
name|uLong
name|check
operator|,
specifier|const
name|Bytef
operator|*
name|buf
operator|,
name|uInt
name|len
operator|)
argument_list|)
expr_stmt|;
end_typedef

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
comment|/* _Z_UTIL_H */
end_comment

end_unit

