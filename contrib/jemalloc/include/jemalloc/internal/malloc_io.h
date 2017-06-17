begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_MALLOC_IO_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_MALLOC_IO_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_define
define|#
directive|define
name|FMT64_PREFIX
value|"ll"
end_define

begin_define
define|#
directive|define
name|FMTPTR_PREFIX
value|"ll"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FMT64_PREFIX
value|"ll"
end_define

begin_define
define|#
directive|define
name|FMTPTR_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FMTd32
value|"d"
end_define

begin_define
define|#
directive|define
name|FMTu32
value|"u"
end_define

begin_define
define|#
directive|define
name|FMTx32
value|"x"
end_define

begin_define
define|#
directive|define
name|FMTd64
value|FMT64_PREFIX "d"
end_define

begin_define
define|#
directive|define
name|FMTu64
value|FMT64_PREFIX "u"
end_define

begin_define
define|#
directive|define
name|FMTx64
value|FMT64_PREFIX "x"
end_define

begin_define
define|#
directive|define
name|FMTdPTR
value|FMTPTR_PREFIX "d"
end_define

begin_define
define|#
directive|define
name|FMTuPTR
value|FMTPTR_PREFIX "u"
end_define

begin_define
define|#
directive|define
name|FMTxPTR
value|FMTPTR_PREFIX "x"
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_define
define|#
directive|define
name|FMTd32
value|PRId32
end_define

begin_define
define|#
directive|define
name|FMTu32
value|PRIu32
end_define

begin_define
define|#
directive|define
name|FMTx32
value|PRIx32
end_define

begin_define
define|#
directive|define
name|FMTd64
value|PRId64
end_define

begin_define
define|#
directive|define
name|FMTu64
value|PRIu64
end_define

begin_define
define|#
directive|define
name|FMTx64
value|PRIx64
end_define

begin_define
define|#
directive|define
name|FMTdPTR
value|PRIdPTR
end_define

begin_define
define|#
directive|define
name|FMTuPTR
value|PRIuPTR
end_define

begin_define
define|#
directive|define
name|FMTxPTR
value|PRIxPTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Size of stack-allocated buffer passed to buferror(). */
end_comment

begin_define
define|#
directive|define
name|BUFERROR_BUF
value|64
end_define

begin_comment
comment|/*  * Size of stack-allocated buffer used by malloc_{,v,vc}printf().  This must be  * large enough for all possible uses within jemalloc.  */
end_comment

begin_define
define|#
directive|define
name|MALLOC_PRINTF_BUFSIZE
value|4096
end_define

begin_function_decl
name|int
name|buferror
parameter_list|(
name|int
name|err
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintmax_t
name|malloc_strtoumax
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
specifier|restrict
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_write
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * malloc_vsnprintf() supports a subset of snprintf(3) that avoids floating  * point math.  */
end_comment

begin_function_decl
name|size_t
name|malloc_vsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|malloc_snprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|JEMALLOC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|malloc_vcprintf
parameter_list|(
name|void
function_decl|(
modifier|*
name|write_cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbopaque
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_cprintf
parameter_list|(
name|void
function_decl|(
modifier|*
name|write_cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbopaque
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|JEMALLOC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|malloc_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|JEMALLOC_FORMAT_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_MALLOC_IO_H */
end_comment

end_unit

