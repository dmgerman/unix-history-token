begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gzguts.h -- zlib internal header definitions for gz* operations  * Copyright (C) 2004, 2005, 2010 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
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

begin_define
define|#
directive|define
name|ZLIB_INTERNAL
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

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
operator|&&
name|defined
name|NO_ERRNO_H
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

begin_ifdef
ifdef|#
directive|ifdef
name|STDC
end_ifdef

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
comment|/* MVS fdopen() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MVS__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|map
name|(
name|fdopen
name|,
literal|"\174\174FDOPEN"
name|)
end_pragma

begin_function_decl
name|FILE
modifier|*
name|fdopen
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LARGEFILE64_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|z_off64_t
value|off64_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|z_off64_t
value|z_off_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default i/o buffer size -- double this for output when reading */
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
name|z_off64_t
name|pos
decl_stmt|;
comment|/* current position in uncompressed data */
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
comment|/* input buffer */
name|unsigned
name|char
modifier|*
name|out
decl_stmt|;
comment|/* output buffer (double-sized when reading) */
name|unsigned
name|char
modifier|*
name|next
decl_stmt|;
comment|/* next output data to deliver or write */
comment|/* just for reading */
name|unsigned
name|have
decl_stmt|;
comment|/* amount of output data unused at next */
name|int
name|eof
decl_stmt|;
comment|/* true if end of input file reached */
name|z_off64_t
name|start
decl_stmt|;
comment|/* where the gzip data started, for rewinding */
name|z_off64_t
name|raw
decl_stmt|;
comment|/* where the raw data started, for seeking */
name|int
name|how
decl_stmt|;
comment|/* 0: get header, 1: copy, 2: decompress */
name|int
name|direct
decl_stmt|;
comment|/* true if last read direct, false if gzip */
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
name|gz_state
name|FAR
modifier|*
name|gz_statep
typedef|;
end_typedef

begin_comment
comment|/* shared functions */
end_comment

begin_decl_stmt
name|ZEXTERN
name|void
name|ZEXPORT
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
operator|&&
name|defined
name|NO_ERRNO_H
end_if

begin_decl_stmt
name|ZEXTERN
name|char
name|ZEXPORT
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
name|ZEXTERN
name|unsigned
name|ZEXPORT
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

