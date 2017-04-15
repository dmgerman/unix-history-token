begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gzguts.h contains minimal changes required to be compiled with zlibWrapper:  * - #include "zlib.h" was changed to #include "zstd_zlibwrapper.h"          * - gz_statep was converted to union to work with -Wstrict-aliasing=1      */
end_comment

begin_comment
comment|/* gzguts.h -- zlib internal header definitions for gz* operations  * Copyright (C) 2004, 2005, 2010, 2011, 2012, 2013, 2016 Mark Adler  * For conditions of distribution and use, see http://www.zlib.net/zlib_license.html  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LARGEFILE64_SOURCE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_LARGEFILE_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_LARGEFILE_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_FILE_OFFSET_BITS
end_ifdef

begin_undef
undef|#
directive|undef
name|_FILE_OFFSET_BITS
end_undef

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
name|HAVE_HIDDEN
end_ifdef

begin_define
define|#
directive|define
name|ZLIB_INTERNAL
value|__attribute__((visibility ("hidden")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZLIB_INTERNAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"zstd_zlibwrapper.h"
end_include

begin_include
include|#
directive|include
file|"gzcompatibility.h"
end_include

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
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
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
name|__TURBOC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<io.h>
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
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIDECHAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WINAPI_FAMILY
end_ifdef

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|write
value|_write
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_DEFLATE
end_ifdef

begin_comment
comment|/* for compatibility with old definition */
end_comment

begin_define
define|#
directive|define
name|NO_GZCOMPRESS
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|&&
operator|(
name|BORLANDC
operator|>
literal|0x410
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
comment|/* vsnprintf may exist on some MS-DOS compilers (DJGPP?),    but for now we just assume it doesn't. */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1500
operator|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__OS400__
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
name|__MVS__
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

begin_comment
comment|/* unlike snprintf (which is required in C99), _snprintf does not guarantee    null termination of the result -- however this is only used in gzlib.c where    the result is assured to fit in the space provided */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1900
end_if

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

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
comment|/* since "static" is used to mean two completely different things in C, we    define "local" for the non-static meaning of "static", for readability    (compile with -Dlocal if your debugger can't find static symbols) */
end_comment

begin_comment
comment|/* gz* functions always use library allocation functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDC
end_ifndef

begin_decl_stmt
specifier|extern
name|voidp
name|malloc
name|OF
argument_list|(
operator|(
name|uInt
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free
name|OF
argument_list|(
operator|(
name|voidpf
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* get errno and strerror definition */
end_comment

begin_if
if|#
directive|if
name|defined
name|UNDER_CE
end_if

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_define
define|#
directive|define
name|zstrerror
parameter_list|()
value|gz_strwinerror((DWORD)GetLastError())
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STRERROR
end_ifndef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|zstrerror
parameter_list|()
value|strerror(errno)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|zstrerror
parameter_list|()
value|"stdio error (consult errno)"
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
comment|/* provide prototypes for these when building zlib without LFS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LARGEFILE64_SOURCE
argument_list|)
operator|||
name|_LFS64_LARGEFILE
operator|-
literal|0
operator|==
literal|0
end_if

begin_decl_stmt
name|ZEXTERN
name|gzFile
name|ZEXPORT
name|gzopen64
name|OF
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|z_off64_t
name|ZEXPORT
name|gzseek64
name|OF
argument_list|(
operator|(
name|gzFile
operator|,
name|z_off64_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|z_off64_t
name|ZEXPORT
name|gztell64
name|OF
argument_list|(
operator|(
name|gzFile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZEXTERN
name|z_off64_t
name|ZEXPORT
name|gzoffset64
name|OF
argument_list|(
operator|(
name|gzFile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default memLevel */
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
comment|/* default i/o buffer size -- double this for output when reading (this and    twice this must be able to fit in an unsigned type) */
end_comment

begin_define
define|#
directive|define
name|GZBUFSIZE
value|8192
end_define

begin_comment
comment|/* gzip modes, also provide a little integrity check on the passed structure */
end_comment

begin_define
define|#
directive|define
name|GZ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|GZ_READ
value|7247
end_define

begin_define
define|#
directive|define
name|GZ_WRITE
value|31153
end_define

begin_define
define|#
directive|define
name|GZ_APPEND
value|1
end_define

begin_comment
comment|/* mode set to GZ_WRITE after the file is opened */
end_comment

begin_comment
comment|/* values for gz_state how */
end_comment

begin_define
define|#
directive|define
name|LOOK
value|0
end_define

begin_comment
comment|/* look for a gzip header */
end_comment

begin_define
define|#
directive|define
name|COPY
value|1
end_define

begin_comment
comment|/* copy input directly */
end_comment

begin_define
define|#
directive|define
name|GZIP
value|2
end_define

begin_comment
comment|/* decompress a gzip stream */
end_comment

begin_comment
comment|/* internal gzip file state data structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* exposed contents for gzgetc() macro */
name|struct
name|gzFile_s
name|x
decl_stmt|;
comment|/* "x" for exposed */
comment|/* x.have: number of bytes available at x.next */
comment|/* x.next: next output data to deliver or write */
comment|/* x.pos: current position in uncompressed data */
comment|/* used for both reading and writing */
name|int
name|mode
decl_stmt|;
comment|/* see gzip modes above */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* path or fd for error messages */
name|unsigned
name|size
decl_stmt|;
comment|/* buffer size, zero if not allocated yet */
name|unsigned
name|want
decl_stmt|;
comment|/* requested buffer size, default is GZBUFSIZE */
name|unsigned
name|char
modifier|*
name|in
decl_stmt|;
comment|/* input buffer (double-sized when writing) */
name|unsigned
name|char
modifier|*
name|out
decl_stmt|;
comment|/* output buffer (double-sized when reading) */
name|int
name|direct
decl_stmt|;
comment|/* 0 if processing gzip, 1 if transparent */
comment|/* just for reading */
name|int
name|how
decl_stmt|;
comment|/* 0: get header, 1: copy, 2: decompress */
name|z_off64_t
name|start
decl_stmt|;
comment|/* where the gzip data started, for rewinding */
name|int
name|eof
decl_stmt|;
comment|/* true if end of input file reached */
name|int
name|past
decl_stmt|;
comment|/* true if read requested past end */
comment|/* just for writing */
name|int
name|level
decl_stmt|;
comment|/* compression level */
name|int
name|strategy
decl_stmt|;
comment|/* compression strategy */
comment|/* seek request */
name|z_off64_t
name|skip
decl_stmt|;
comment|/* amount to skip (already rewound if backwards) */
name|int
name|seek
decl_stmt|;
comment|/* true if seek request pending */
comment|/* error information */
name|int
name|err
decl_stmt|;
comment|/* error code */
name|char
modifier|*
name|msg
decl_stmt|;
comment|/* error message */
comment|/* zlib inflate or deflate stream */
name|z_stream
name|strm
decl_stmt|;
comment|/* stream structure in-place (not a pointer) */
block|}
name|gz_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|gz_state
name|FAR
modifier|*
name|state
decl_stmt|;
name|gzFile
name|file
decl_stmt|;
block|}
name|gz_statep
typedef|;
end_typedef

begin_comment
comment|/* shared functions */
end_comment

begin_decl_stmt
name|void
name|ZLIB_INTERNAL
name|gz_error
name|OF
argument_list|(
operator|(
name|gz_statep
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
name|UNDER_CE
end_if

begin_decl_stmt
name|char
name|ZLIB_INTERNAL
modifier|*
name|gz_strwinerror
name|OF
argument_list|(
operator|(
name|DWORD
name|error
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GT_OFF(x), where x is an unsigned value, is true if x> maximum z_off64_t    value -- needed when comparing unsigned to z_off64_t, which is signed    (possible z_off64_t types off_t, off64_t, and long are all signed) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT_MAX
end_ifdef

begin_define
define|#
directive|define
name|GT_OFF
parameter_list|(
name|x
parameter_list|)
value|(sizeof(int) == sizeof(z_off64_t)&& (x)> INT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|unsigned
name|ZLIB_INTERNAL
name|gz_intmax
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GT_OFF
parameter_list|(
name|x
parameter_list|)
value|(sizeof(int) == sizeof(z_off64_t)&& (x)> gz_intmax())
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

