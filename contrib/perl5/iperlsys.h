begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iperlsys.h - Perl's interface to the system  *  * This file defines the system level functionality that perl needs.  *  * When using C, this definition is in the form of a set of macros  * that can be #defined to the system-level function (or a wrapper  * provided elsewhere).  *  * When using C++ with -DPERL_OBJECT, this definition is in the  * form of a set of virtual base classes which must be subclassed to  * provide a real implementation.  The Perl Object will use instances  * of this implementation to use the system-level functionality.  *  * GSAR 21-JUN-98  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__Inc__IPerl___
end_ifndef

begin_define
define|#
directive|define
name|__Inc__IPerl___
end_define

begin_comment
comment|/*  *	PerlXXX_YYY explained - DickH and DougL @ ActiveState.com  *  * XXX := functional group  * YYY := stdlib/OS function name  *  * Continuing with the theme of PerlIO, all OS functionality was  * encapsulated into one of several interfaces.  *  * PerlIO - stdio  * PerlLIO - low level I/O  * PerlMem - malloc, realloc, free  * PerlDir - directory related  * PerlEnv - process environment handling  * PerlProc - process control  * PerlSock - socket functions  *  *  * The features of this are:  * 1. All OS dependant code is in the Perl Host and not the Perl Core.  *    (At least this is the holy grail goal of this work)  * 2. The Perl Host (see perl.h for description) can provide a new and  *    improved interface to OS functionality if required.  * 3. Developers can easily hook into the OS calls for instrumentation  *    or diagnostic purposes.  *  * What was changed to do this:  * 1. All calls to OS functions were replaced with PerlXXX_YYY  *  */
end_comment

begin_comment
comment|/*     Interface for perl stdio functions */
end_comment

begin_comment
comment|/* Clean up (or at least document) the various possible #defines.    This section attempts to match the 5.003_03 Configure variables    onto the 5.003_02 header file values.    I can't figure out where USE_STDIO was supposed to be set.    --AD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_PERLIO
end_ifndef

begin_define
define|#
directive|define
name|PERLIO_IS_STDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Below is the 5.003_02 stuff. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDIO
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PERLIO_IS_STDIO
end_ifndef

begin_define
define|#
directive|define
name|PERLIO_IS_STDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|PerlIO_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Sighandler_t
end_ifndef

begin_typedef
typedef|typedef
name|Signal_t
function_decl|(
modifier|*
name|Sighandler_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|_PerlIO
name|PerlIO
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPerlStdIO		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlStdIO
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlStdIOInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPStdin
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPStdout
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPStderr
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPOpen
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPClose
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPEof
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPError
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPClearerr
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetc
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPGetBase
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetBufsiz
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetCnt
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPGetPtr
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPGets
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPPutc
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPPuts
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPFlush
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPUngetc
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPFileno
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPFdopen
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPReopen
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|SSize_t
function_decl|(
modifier|*
name|LPRead
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|Size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|SSize_t
function_decl|(
modifier|*
name|LPWrite
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|Size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetBuf
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSetVBuf
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetCnt
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetPtrCnt
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetlinebuf
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPPrintf
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPVprintf
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|long
function_decl|(
modifier|*
name|LPTell
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSeek
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|Off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPRewind
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPTmpfile
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetpos
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
name|Fpos_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSetpos
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|Fpos_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPInit
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPInitOSExtras
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPFdupopen
function_decl|)
parameter_list|(
name|struct
name|IPerlStdIO
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|IPerlStdIO
block|{
name|LPStdin
name|pStdin
decl_stmt|;
name|LPStdout
name|pStdout
decl_stmt|;
name|LPStderr
name|pStderr
decl_stmt|;
name|LPOpen
name|pOpen
decl_stmt|;
name|LPClose
name|pClose
decl_stmt|;
name|LPEof
name|pEof
decl_stmt|;
name|LPError
name|pError
decl_stmt|;
name|LPClearerr
name|pClearerr
decl_stmt|;
name|LPGetc
name|pGetc
decl_stmt|;
name|LPGetBase
name|pGetBase
decl_stmt|;
name|LPGetBufsiz
name|pGetBufsiz
decl_stmt|;
name|LPGetCnt
name|pGetCnt
decl_stmt|;
name|LPGetPtr
name|pGetPtr
decl_stmt|;
name|LPGets
name|pGets
decl_stmt|;
name|LPPutc
name|pPutc
decl_stmt|;
name|LPPuts
name|pPuts
decl_stmt|;
name|LPFlush
name|pFlush
decl_stmt|;
name|LPUngetc
name|pUngetc
decl_stmt|;
name|LPFileno
name|pFileno
decl_stmt|;
name|LPFdopen
name|pFdopen
decl_stmt|;
name|LPReopen
name|pReopen
decl_stmt|;
name|LPRead
name|pRead
decl_stmt|;
name|LPWrite
name|pWrite
decl_stmt|;
name|LPSetBuf
name|pSetBuf
decl_stmt|;
name|LPSetVBuf
name|pSetVBuf
decl_stmt|;
name|LPSetCnt
name|pSetCnt
decl_stmt|;
name|LPSetPtrCnt
name|pSetPtrCnt
decl_stmt|;
name|LPSetlinebuf
name|pSetlinebuf
decl_stmt|;
name|LPPrintf
name|pPrintf
decl_stmt|;
name|LPVprintf
name|pVprintf
decl_stmt|;
name|LPTell
name|pTell
decl_stmt|;
name|LPSeek
name|pSeek
decl_stmt|;
name|LPRewind
name|pRewind
decl_stmt|;
name|LPTmpfile
name|pTmpfile
decl_stmt|;
name|LPGetpos
name|pGetpos
decl_stmt|;
name|LPSetpos
name|pSetpos
decl_stmt|;
name|LPInit
name|pInit
decl_stmt|;
name|LPInitOSExtras
name|pInitOSExtras
decl_stmt|;
name|LPFdupopen
name|pFdupopen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlStdIOInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlStdIO
name|perlStdIOList
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDIO_PTR
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_has_cntptr
parameter_list|(
name|f
parameter_list|)
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO_PTR_LVALUE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO_CNT_LVALUE
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_canset_cnt
parameter_list|(
name|f
parameter_list|)
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO_PTR_LVAL_NOCHANGE_CNT
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_fast_gets
parameter_list|(
name|f
parameter_list|)
value|1
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
comment|/* STDIO_CNT_LVALUE */
end_comment

begin_define
define|#
directive|define
name|PerlIO_canset_cnt
parameter_list|(
name|f
parameter_list|)
value|0
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
comment|/* STDIO_PTR_LVALUE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO_PTR_LVAL_SETS_CNT
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_fast_gets
parameter_list|(
name|f
parameter_list|)
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_STDIO_PTR */
end_comment

begin_define
define|#
directive|define
name|PerlIO_has_cntptr
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|PerlIO_canset_cnt
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
comment|/* USE_STDIO_PTR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_fast_gets
end_ifndef

begin_define
define|#
directive|define
name|PerlIO_fast_gets
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FILE_base
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_has_base
parameter_list|(
name|f
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
name|PerlIO_has_base
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlIO_stdin
parameter_list|()
define|\
value|(*PL_StdIO->pStdin)(PL_StdIO)
end_define

begin_define
define|#
directive|define
name|PerlIO_stdout
parameter_list|()
define|\
value|(*PL_StdIO->pStdout)(PL_StdIO)
end_define

begin_define
define|#
directive|define
name|PerlIO_stderr
parameter_list|()
define|\
value|(*PL_StdIO->pStderr)(PL_StdIO)
end_define

begin_define
define|#
directive|define
name|PerlIO_open
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(*PL_StdIO->pOpen)(PL_StdIO, (x),(y))
end_define

begin_define
define|#
directive|define
name|PerlIO_close
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pClose)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_eof
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pEof)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_error
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pError)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_clearerr
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pClearerr)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_getc
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pGetc)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_get_base
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pGetBase)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_get_bufsiz
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pGetBufsiz)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_get_cnt
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pGetCnt)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_get_ptr
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pGetPtr)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_putc
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
define|\
value|(*PL_StdIO->pPutc)(PL_StdIO, (f),(c))
end_define

begin_define
define|#
directive|define
name|PerlIO_puts
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(*PL_StdIO->pPuts)(PL_StdIO, (f),(s))
end_define

begin_define
define|#
directive|define
name|PerlIO_flush
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pFlush)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_gets
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|fp
parameter_list|)
define|\
value|(*PL_StdIO->pGets)(PL_StdIO, (fp), s, n)
end_define

begin_define
define|#
directive|define
name|PerlIO_ungetc
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
define|\
value|(*PL_StdIO->pUngetc)(PL_StdIO, (f),(c))
end_define

begin_define
define|#
directive|define
name|PerlIO_fileno
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pFileno)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_fdopen
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(*PL_StdIO->pFdopen)(PL_StdIO, (f),(s))
end_define

begin_define
define|#
directive|define
name|PerlIO_reopen
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pReopen)(PL_StdIO, (p), (m), (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_read
parameter_list|(
name|f
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
define|\
value|(SSize_t)(*PL_StdIO->pRead)(PL_StdIO, (f), (buf), (count))
end_define

begin_define
define|#
directive|define
name|PerlIO_write
parameter_list|(
name|f
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
define|\
value|(*PL_StdIO->pWrite)(PL_StdIO, (f), (buf), (count))
end_define

begin_define
define|#
directive|define
name|PerlIO_setbuf
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
define|\
value|(*PL_StdIO->pSetBuf)(PL_StdIO, (f), (b))
end_define

begin_define
define|#
directive|define
name|PerlIO_setvbuf
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|)
define|\
value|(*PL_StdIO->pSetVBuf)(PL_StdIO, (f),(b),(t),(s))
end_define

begin_define
define|#
directive|define
name|PerlIO_set_cnt
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
define|\
value|(*PL_StdIO->pSetCnt)(PL_StdIO, (f), (c))
end_define

begin_define
define|#
directive|define
name|PerlIO_set_ptrcnt
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|,
name|c
parameter_list|)
define|\
value|(*PL_StdIO->pSetPtrCnt)(PL_StdIO, (f), (p), (c))
end_define

begin_define
define|#
directive|define
name|PerlIO_setlinebuf
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pSetlinebuf)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_printf
value|Perl_fprintf_nocontext
end_define

begin_define
define|#
directive|define
name|PerlIO_stdoutf
value|Perl_printf_nocontext
end_define

begin_define
define|#
directive|define
name|PerlIO_vprintf
parameter_list|(
name|f
parameter_list|,
name|fmt
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_StdIO->pVprintf)(PL_StdIO, (f),(fmt),a)
end_define

begin_define
define|#
directive|define
name|PerlIO_tell
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pTell)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_seek
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
define|\
value|(*PL_StdIO->pSeek)(PL_StdIO, (f),(o),(w))
end_define

begin_define
define|#
directive|define
name|PerlIO_getpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|(*PL_StdIO->pGetpos)(PL_StdIO, (f),(p))
end_define

begin_define
define|#
directive|define
name|PerlIO_setpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|(*PL_StdIO->pSetpos)(PL_StdIO, (f),(p))
end_define

begin_define
define|#
directive|define
name|PerlIO_rewind
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pRewind)(PL_StdIO, (f))
end_define

begin_define
define|#
directive|define
name|PerlIO_tmpfile
parameter_list|()
define|\
value|(*PL_StdIO->pTmpfile)(PL_StdIO)
end_define

begin_define
define|#
directive|define
name|PerlIO_init
parameter_list|()
define|\
value|(*PL_StdIO->pInit)(PL_StdIO)
end_define

begin_undef
undef|#
directive|undef
name|init_os_extras
end_undef

begin_define
define|#
directive|define
name|init_os_extras
parameter_list|()
define|\
value|(*PL_StdIO->pInitOSExtras)(PL_StdIO)
end_define

begin_define
define|#
directive|define
name|PerlIO_fdupopen
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_StdIO->pFdupopen)(PL_StdIO, (f))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_include
include|#
directive|include
file|"perlsdio.h"
end_include

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_define
define|#
directive|define
name|PerlIO_fdupopen
parameter_list|(
name|f
parameter_list|)
value|(f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERLIO_IS_STDIO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SFIO
end_ifdef

begin_include
include|#
directive|include
file|"perlsfio.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SFIO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERLIO_IS_STDIO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EOF
end_ifndef

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is to catch case with no stdio */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO
end_ifndef

begin_struct_decl
struct_decl|struct
name|_PerlIO
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|PerlIO
value|struct _PerlIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No PerlIO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Fpos_t
end_ifndef

begin_define
define|#
directive|define
name|Fpos_t
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEXT30_NO_ATTRIBUTE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HASATTRIBUTE
end_ifndef

begin_comment
comment|/* disable GNU-cc attribute checking? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__attribute__
end_ifdef

begin_comment
comment|/* Avoid possible redefinition errors */
end_comment

begin_undef
undef|#
directive|undef
name|__attribute__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|attr
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
name|PerlIO_stdoutf
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_stdoutf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_puts
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_puts
parameter_list|(
name|PerlIO
modifier|*
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

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_open
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_open
parameter_list|(
specifier|const
name|char
modifier|*
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

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_close
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_close
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_eof
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_eof
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_error
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_error
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_clearerr
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PerlIO_clearerr
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_getc
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_getc
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_putc
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_putc
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_flush
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_flush
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_ungetc
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_ungetc
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_fileno
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_fileno
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_fdopen
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_fdopen
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

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_importFILE
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_importFILE
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_exportFILE
end_ifndef

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|PerlIO_exportFILE
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_findFILE
end_ifndef

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|PerlIO_findFILE
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_releaseFILE
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PerlIO_releaseFILE
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_read
end_ifndef

begin_function_decl
specifier|extern
name|SSize_t
name|PerlIO_read
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|Size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_write
end_ifndef

begin_function_decl
specifier|extern
name|SSize_t
name|PerlIO_write
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|Size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_setlinebuf
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PerlIO_setlinebuf
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_printf
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_printf
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_sprintf
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_sprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_vprintf
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_vprintf
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_tell
end_ifndef

begin_function_decl
specifier|extern
name|Off_t
name|PerlIO_tell
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_seek
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_seek
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|Off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_rewind
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PerlIO_rewind
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_has_base
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_has_base
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_has_cntptr
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_has_cntptr
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_fast_gets
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_fast_gets
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_canset_cnt
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_canset_cnt
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_get_ptr
end_ifndef

begin_function_decl
specifier|extern
name|STDCHAR
modifier|*
name|PerlIO_get_ptr
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_get_cnt
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_get_cnt
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_set_cnt
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PerlIO_set_cnt
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_set_ptrcnt
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PerlIO_set_ptrcnt
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|STDCHAR
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_get_base
end_ifndef

begin_function_decl
specifier|extern
name|STDCHAR
modifier|*
name|PerlIO_get_base
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_get_bufsiz
end_ifndef

begin_function_decl
specifier|extern
name|int
name|PerlIO_get_bufsiz
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_tmpfile
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_tmpfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_stdin
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_stdin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_stdout
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_stdout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_stderr
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_stderr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PerlIO_getpos
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SFIO
end_ifdef

begin_function_decl
specifier|extern
name|int
name|PerlIO_getpos
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|Off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|PerlIO_getpos
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
name|Fpos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|PerlIO_setpos
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SFIO
end_ifdef

begin_function_decl
specifier|extern
name|int
name|PerlIO_setpos
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|Off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|PerlIO_setpos
parameter_list|(
name|PerlIO
modifier|*
parameter_list|,
specifier|const
name|Fpos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|PerlIO_fdupopen
end_ifndef

begin_function_decl
specifier|extern
name|PerlIO
modifier|*
name|PerlIO_fdupopen
parameter_list|(
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *   Interface for directory functions  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_comment
comment|/* IPerlDir		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlDir
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlDirInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPMakedir
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPChdir
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPRmdir
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPDirClose
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|DIR
modifier|*
function_decl|(
modifier|*
name|LPDirOpen
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|direct
modifier|*
function_decl|(
modifier|*
name|LPDirRead
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPDirRewind
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPDirSeek
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
name|DIR
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|long
function_decl|(
modifier|*
name|LPDirTell
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPDirMapPathA
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|WCHAR
modifier|*
function_decl|(
modifier|*
name|LPDirMapPathW
function_decl|)
parameter_list|(
name|struct
name|IPerlDir
modifier|*
parameter_list|,
specifier|const
name|WCHAR
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|IPerlDir
block|{
name|LPMakedir
name|pMakedir
decl_stmt|;
name|LPChdir
name|pChdir
decl_stmt|;
name|LPRmdir
name|pRmdir
decl_stmt|;
name|LPDirClose
name|pClose
decl_stmt|;
name|LPDirOpen
name|pOpen
decl_stmt|;
name|LPDirRead
name|pRead
decl_stmt|;
name|LPDirRewind
name|pRewind
decl_stmt|;
name|LPDirSeek
name|pSeek
decl_stmt|;
name|LPDirTell
name|pTell
decl_stmt|;
ifdef|#
directive|ifdef
name|WIN32
name|LPDirMapPathA
name|pMapPathA
decl_stmt|;
name|LPDirMapPathW
name|pMapPathW
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlDirInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlDir
name|perlDirList
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PerlDir_mkdir
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*PL_Dir->pMakedir)(PL_Dir, (name), (mode))
end_define

begin_define
define|#
directive|define
name|PerlDir_chdir
parameter_list|(
name|name
parameter_list|)
define|\
value|(*PL_Dir->pChdir)(PL_Dir, (name))
end_define

begin_define
define|#
directive|define
name|PerlDir_rmdir
parameter_list|(
name|name
parameter_list|)
define|\
value|(*PL_Dir->pRmdir)(PL_Dir, (name))
end_define

begin_define
define|#
directive|define
name|PerlDir_close
parameter_list|(
name|dir
parameter_list|)
define|\
value|(*PL_Dir->pClose)(PL_Dir, (dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_open
parameter_list|(
name|name
parameter_list|)
define|\
value|(*PL_Dir->pOpen)(PL_Dir, (name))
end_define

begin_define
define|#
directive|define
name|PerlDir_read
parameter_list|(
name|dir
parameter_list|)
define|\
value|(*PL_Dir->pRead)(PL_Dir, (dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_rewind
parameter_list|(
name|dir
parameter_list|)
define|\
value|(*PL_Dir->pRewind)(PL_Dir, (dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_seek
parameter_list|(
name|dir
parameter_list|,
name|loc
parameter_list|)
define|\
value|(*PL_Dir->pSeek)(PL_Dir, (dir), (loc))
end_define

begin_define
define|#
directive|define
name|PerlDir_tell
parameter_list|(
name|dir
parameter_list|)
define|\
value|(*PL_Dir->pTell)(PL_Dir, (dir))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlDir_mapA
parameter_list|(
name|dir
parameter_list|)
define|\
value|(*PL_Dir->pMapPathA)(PL_Dir, (dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_mapW
parameter_list|(
name|dir
parameter_list|)
define|\
value|(*PL_Dir->pMapPathW)(PL_Dir, (dir))
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_define
define|#
directive|define
name|PerlDir_mkdir
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|)
value|Mkdir((name), (mode))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|PerlDir_chdir
parameter_list|(
name|n
parameter_list|)
value|Chdir(((n)&& *(n)) ? (n) : "SYS$LOGIN")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlDir_chdir
parameter_list|(
name|name
parameter_list|)
value|chdir((name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlDir_rmdir
parameter_list|(
name|name
parameter_list|)
value|rmdir((name))
end_define

begin_define
define|#
directive|define
name|PerlDir_close
parameter_list|(
name|dir
parameter_list|)
value|closedir((dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_open
parameter_list|(
name|name
parameter_list|)
value|opendir((name))
end_define

begin_define
define|#
directive|define
name|PerlDir_read
parameter_list|(
name|dir
parameter_list|)
value|readdir((dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_rewind
parameter_list|(
name|dir
parameter_list|)
value|rewinddir((dir))
end_define

begin_define
define|#
directive|define
name|PerlDir_seek
parameter_list|(
name|dir
parameter_list|,
name|loc
parameter_list|)
value|seekdir((dir), (loc))
end_define

begin_define
define|#
directive|define
name|PerlDir_tell
parameter_list|(
name|dir
parameter_list|)
value|telldir((dir))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlDir_mapA
parameter_list|(
name|dir
parameter_list|)
value|dir
end_define

begin_define
define|#
directive|define
name|PerlDir_mapW
parameter_list|(
name|dir
parameter_list|)
value|dir
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_comment
comment|/*     Interface for perl environment functions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_comment
comment|/* IPerlEnv		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlEnv
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlEnvInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPEnvGetenv
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPEnvPutenv
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPEnvGetenv_len
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|varname
parameter_list|,
name|unsigned
name|long
modifier|*
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPEnvUname
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
name|struct
name|utsname
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEnvClearenv
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|LPEnvGetChildenv
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEnvFreeChildenv
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
name|void
modifier|*
name|env
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPEnvGetChilddir
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEnvFreeChilddir
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
name|char
modifier|*
name|dir
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ENVGETENV
end_ifdef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPENVGetenv
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|varname
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPENVGetenv_len
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|varname
parameter_list|,
name|unsigned
name|long
modifier|*
name|len
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
function_decl|(
modifier|*
name|LPEnvOsID
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPEnvLibPath
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPEnvSiteLibPath
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPEnvVendorLibPath
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEnvGetChildIO
function_decl|)
parameter_list|(
name|struct
name|IPerlEnv
modifier|*
parameter_list|,
name|child_IO_table
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|IPerlEnv
block|{
name|LPEnvGetenv
name|pGetenv
decl_stmt|;
name|LPEnvPutenv
name|pPutenv
decl_stmt|;
name|LPEnvGetenv_len
name|pGetenv_len
decl_stmt|;
name|LPEnvUname
name|pEnvUname
decl_stmt|;
name|LPEnvClearenv
name|pClearenv
decl_stmt|;
name|LPEnvGetChildenv
name|pGetChildenv
decl_stmt|;
name|LPEnvFreeChildenv
name|pFreeChildenv
decl_stmt|;
name|LPEnvGetChilddir
name|pGetChilddir
decl_stmt|;
name|LPEnvFreeChilddir
name|pFreeChilddir
decl_stmt|;
ifdef|#
directive|ifdef
name|HAS_ENVGETENV
name|LPENVGetenv
name|pENVGetenv
decl_stmt|;
name|LPENVGetenv_len
name|pENVGetenv_len
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WIN32
name|LPEnvOsID
name|pEnvOsID
decl_stmt|;
name|LPEnvLibPath
name|pLibPath
decl_stmt|;
name|LPEnvSiteLibPath
name|pSiteLibPath
decl_stmt|;
name|LPEnvVendorLibPath
name|pVendorLibPath
decl_stmt|;
name|LPEnvGetChildIO
name|pGetChildIO
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlEnvInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlEnv
name|perlEnvList
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PerlEnv_putenv
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_Env->pPutenv)(PL_Env,(str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_getenv
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_Env->pGetenv)(PL_Env,(str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_getenv_len
parameter_list|(
name|str
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Env->pGetenv_len)(PL_Env,(str), (l))
end_define

begin_define
define|#
directive|define
name|PerlEnv_clearenv
parameter_list|()
define|\
value|(*PL_Env->pClearenv)(PL_Env)
end_define

begin_define
define|#
directive|define
name|PerlEnv_get_childenv
parameter_list|()
define|\
value|(*PL_Env->pGetChildenv)(PL_Env)
end_define

begin_define
define|#
directive|define
name|PerlEnv_free_childenv
parameter_list|(
name|e
parameter_list|)
define|\
value|(*PL_Env->pFreeChildenv)(PL_Env, (e))
end_define

begin_define
define|#
directive|define
name|PerlEnv_get_childdir
parameter_list|()
define|\
value|(*PL_Env->pGetChilddir)(PL_Env)
end_define

begin_define
define|#
directive|define
name|PerlEnv_free_childdir
parameter_list|(
name|d
parameter_list|)
define|\
value|(*PL_Env->pFreeChilddir)(PL_Env, (d))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ENVGETENV
end_ifdef

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_Env->pENVGetenv)(PL_Env,(str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv_len
parameter_list|(
name|str
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Env->pENVGetenv_len)(PL_Env,(str), (l))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv
parameter_list|(
name|str
parameter_list|)
define|\
value|PerlEnv_getenv((str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv_len
parameter_list|(
name|str
parameter_list|,
name|l
parameter_list|)
define|\
value|PerlEnv_getenv_len((str),(l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlEnv_uname
parameter_list|(
name|name
parameter_list|)
define|\
value|(*PL_Env->pEnvUname)(PL_Env,(name))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlEnv_os_id
parameter_list|()
define|\
value|(*PL_Env->pEnvOsID)(PL_Env)
end_define

begin_define
define|#
directive|define
name|PerlEnv_lib_path
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_Env->pLibPath)(PL_Env,(str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_sitelib_path
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_Env->pSiteLibPath)(PL_Env,(str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_vendorlib_path
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_Env->pVendorLibPath)(PL_Env,(str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_get_child_IO
parameter_list|(
name|ptr
parameter_list|)
define|\
value|(*PL_Env->pGetChildIO)(PL_Env, ptr)
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_define
define|#
directive|define
name|PerlEnv_putenv
parameter_list|(
name|str
parameter_list|)
value|putenv((str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_getenv
parameter_list|(
name|str
parameter_list|)
value|getenv((str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_getenv_len
parameter_list|(
name|str
parameter_list|,
name|l
parameter_list|)
value|getenv_len((str), (l))
end_define

begin_define
define|#
directive|define
name|PerlEnv_clearenv
parameter_list|()
value|clearenv()
end_define

begin_define
define|#
directive|define
name|PerlEnv_get_childenv
parameter_list|()
value|get_childenv()
end_define

begin_define
define|#
directive|define
name|PerlEnv_free_childenv
parameter_list|(
name|e
parameter_list|)
value|free_childenv((e))
end_define

begin_define
define|#
directive|define
name|PerlEnv_get_childdir
parameter_list|()
value|get_childdir()
end_define

begin_define
define|#
directive|define
name|PerlEnv_free_childdir
parameter_list|(
name|d
parameter_list|)
value|free_childdir((d))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ENVGETENV
end_ifdef

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv
parameter_list|(
name|str
parameter_list|)
value|ENVgetenv((str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv_len
parameter_list|(
name|str
parameter_list|,
name|l
parameter_list|)
value|ENVgetenv_len((str), (l))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv
parameter_list|(
name|str
parameter_list|)
value|PerlEnv_getenv((str))
end_define

begin_define
define|#
directive|define
name|PerlEnv_ENVgetenv_len
parameter_list|(
name|str
parameter_list|,
name|l
parameter_list|)
value|PerlEnv_getenv_len((str), (l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlEnv_uname
parameter_list|(
name|name
parameter_list|)
value|uname((name))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlEnv_os_id
parameter_list|()
value|win32_os_id()
end_define

begin_define
define|#
directive|define
name|PerlEnv_lib_path
parameter_list|(
name|str
parameter_list|)
value|win32_get_privlib(str)
end_define

begin_define
define|#
directive|define
name|PerlEnv_sitelib_path
parameter_list|(
name|str
parameter_list|)
value|win32_get_sitelib(str)
end_define

begin_define
define|#
directive|define
name|PerlEnv_vendorlib_path
parameter_list|(
name|str
parameter_list|)
value|win32_get_vendorlib(str)
end_define

begin_define
define|#
directive|define
name|PerlEnv_get_child_IO
parameter_list|(
name|ptr
parameter_list|)
value|win32_get_child_IO(ptr)
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_comment
comment|/*     Interface for perl low-level IO functions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_comment
comment|/* IPerlLIO		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlLIO
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlLIOInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOAccess
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOChmod
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOChown
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOChsize
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOClose
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIODup
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIODup2
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOFlock
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOFileStat
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOIOCtl
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOIsatty
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOLink
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|long
function_decl|(
modifier|*
name|LPLIOLseek
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOLstat
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPLIOMktemp
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOOpen
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOOpen3
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIORead
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIORename
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOSetmode
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIONameStat
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPLIOTmpnam
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOUmask
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOUnlink
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOUtime
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|utimbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPLIOWrite
function_decl|)
parameter_list|(
name|struct
name|IPerlLIO
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|IPerlLIO
block|{
name|LPLIOAccess
name|pAccess
decl_stmt|;
name|LPLIOChmod
name|pChmod
decl_stmt|;
name|LPLIOChown
name|pChown
decl_stmt|;
name|LPLIOChsize
name|pChsize
decl_stmt|;
name|LPLIOClose
name|pClose
decl_stmt|;
name|LPLIODup
name|pDup
decl_stmt|;
name|LPLIODup2
name|pDup2
decl_stmt|;
name|LPLIOFlock
name|pFlock
decl_stmt|;
name|LPLIOFileStat
name|pFileStat
decl_stmt|;
name|LPLIOIOCtl
name|pIOCtl
decl_stmt|;
name|LPLIOIsatty
name|pIsatty
decl_stmt|;
name|LPLIOLink
name|pLink
decl_stmt|;
name|LPLIOLseek
name|pLseek
decl_stmt|;
name|LPLIOLstat
name|pLstat
decl_stmt|;
name|LPLIOMktemp
name|pMktemp
decl_stmt|;
name|LPLIOOpen
name|pOpen
decl_stmt|;
name|LPLIOOpen3
name|pOpen3
decl_stmt|;
name|LPLIORead
name|pRead
decl_stmt|;
name|LPLIORename
name|pRename
decl_stmt|;
name|LPLIOSetmode
name|pSetmode
decl_stmt|;
name|LPLIONameStat
name|pNameStat
decl_stmt|;
name|LPLIOTmpnam
name|pTmpnam
decl_stmt|;
name|LPLIOUmask
name|pUmask
decl_stmt|;
name|LPLIOUnlink
name|pUnlink
decl_stmt|;
name|LPLIOUtime
name|pUtime
decl_stmt|;
name|LPLIOWrite
name|pWrite
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlLIOInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlLIO
name|perlLIOList
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PerlLIO_access
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*PL_LIO->pAccess)(PL_LIO, (file), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_chmod
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*PL_LIO->pChmod)(PL_LIO, (file), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_chown
parameter_list|(
name|file
parameter_list|,
name|owner
parameter_list|,
name|group
parameter_list|)
define|\
value|(*PL_LIO->pChown)(PL_LIO, (file), (owner), (group))
end_define

begin_define
define|#
directive|define
name|PerlLIO_chsize
parameter_list|(
name|fd
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_LIO->pChsize)(PL_LIO, (fd), (size))
end_define

begin_define
define|#
directive|define
name|PerlLIO_close
parameter_list|(
name|fd
parameter_list|)
define|\
value|(*PL_LIO->pClose)(PL_LIO, (fd))
end_define

begin_define
define|#
directive|define
name|PerlLIO_dup
parameter_list|(
name|fd
parameter_list|)
define|\
value|(*PL_LIO->pDup)(PL_LIO, (fd))
end_define

begin_define
define|#
directive|define
name|PerlLIO_dup2
parameter_list|(
name|fd1
parameter_list|,
name|fd2
parameter_list|)
define|\
value|(*PL_LIO->pDup2)(PL_LIO, (fd1), (fd2))
end_define

begin_define
define|#
directive|define
name|PerlLIO_flock
parameter_list|(
name|fd
parameter_list|,
name|op
parameter_list|)
define|\
value|(*PL_LIO->pFlock)(PL_LIO, (fd), (op))
end_define

begin_define
define|#
directive|define
name|PerlLIO_fstat
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|)
define|\
value|(*PL_LIO->pFileStat)(PL_LIO, (fd), (buf))
end_define

begin_define
define|#
directive|define
name|PerlLIO_ioctl
parameter_list|(
name|fd
parameter_list|,
name|u
parameter_list|,
name|buf
parameter_list|)
define|\
value|(*PL_LIO->pIOCtl)(PL_LIO, (fd), (u), (buf))
end_define

begin_define
define|#
directive|define
name|PerlLIO_isatty
parameter_list|(
name|fd
parameter_list|)
define|\
value|(*PL_LIO->pIsatty)(PL_LIO, (fd))
end_define

begin_define
define|#
directive|define
name|PerlLIO_link
parameter_list|(
name|oldname
parameter_list|,
name|newname
parameter_list|)
define|\
value|(*PL_LIO->pLink)(PL_LIO, (oldname), (newname))
end_define

begin_define
define|#
directive|define
name|PerlLIO_lseek
parameter_list|(
name|fd
parameter_list|,
name|offset
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*PL_LIO->pLseek)(PL_LIO, (fd), (offset), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_lstat
parameter_list|(
name|name
parameter_list|,
name|buf
parameter_list|)
define|\
value|(*PL_LIO->pLstat)(PL_LIO, (name), (buf))
end_define

begin_define
define|#
directive|define
name|PerlLIO_mktemp
parameter_list|(
name|file
parameter_list|)
define|\
value|(*PL_LIO->pMktemp)(PL_LIO, (file))
end_define

begin_define
define|#
directive|define
name|PerlLIO_open
parameter_list|(
name|file
parameter_list|,
name|flag
parameter_list|)
define|\
value|(*PL_LIO->pOpen)(PL_LIO, (file), (flag))
end_define

begin_define
define|#
directive|define
name|PerlLIO_open3
parameter_list|(
name|file
parameter_list|,
name|flag
parameter_list|,
name|perm
parameter_list|)
define|\
value|(*PL_LIO->pOpen3)(PL_LIO, (file), (flag), (perm))
end_define

begin_define
define|#
directive|define
name|PerlLIO_read
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
define|\
value|(*PL_LIO->pRead)(PL_LIO, (fd), (buf), (count))
end_define

begin_define
define|#
directive|define
name|PerlLIO_rename
parameter_list|(
name|oname
parameter_list|,
name|newname
parameter_list|)
define|\
value|(*PL_LIO->pRename)(PL_LIO, (oname), (newname))
end_define

begin_define
define|#
directive|define
name|PerlLIO_setmode
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*PL_LIO->pSetmode)(PL_LIO, (fd), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_stat
parameter_list|(
name|name
parameter_list|,
name|buf
parameter_list|)
define|\
value|(*PL_LIO->pNameStat)(PL_LIO, (name), (buf))
end_define

begin_define
define|#
directive|define
name|PerlLIO_tmpnam
parameter_list|(
name|str
parameter_list|)
define|\
value|(*PL_LIO->pTmpnam)(PL_LIO, (str))
end_define

begin_define
define|#
directive|define
name|PerlLIO_umask
parameter_list|(
name|mode
parameter_list|)
define|\
value|(*PL_LIO->pUmask)(PL_LIO, (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_unlink
parameter_list|(
name|file
parameter_list|)
define|\
value|(*PL_LIO->pUnlink)(PL_LIO, (file))
end_define

begin_define
define|#
directive|define
name|PerlLIO_utime
parameter_list|(
name|file
parameter_list|,
name|time
parameter_list|)
define|\
value|(*PL_LIO->pUtime)(PL_LIO, (file), (time))
end_define

begin_define
define|#
directive|define
name|PerlLIO_write
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
define|\
value|(*PL_LIO->pWrite)(PL_LIO, (fd), (buf), (count))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_define
define|#
directive|define
name|PerlLIO_access
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
value|access((file), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_chmod
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
value|chmod((file), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_chown
parameter_list|(
name|file
parameter_list|,
name|owner
parameter_list|,
name|grp
parameter_list|)
value|chown((file), (owner), (grp))
end_define

begin_define
define|#
directive|define
name|PerlLIO_chsize
parameter_list|(
name|fd
parameter_list|,
name|size
parameter_list|)
value|chsize((fd), (size))
end_define

begin_define
define|#
directive|define
name|PerlLIO_close
parameter_list|(
name|fd
parameter_list|)
value|close((fd))
end_define

begin_define
define|#
directive|define
name|PerlLIO_dup
parameter_list|(
name|fd
parameter_list|)
value|dup((fd))
end_define

begin_define
define|#
directive|define
name|PerlLIO_dup2
parameter_list|(
name|fd1
parameter_list|,
name|fd2
parameter_list|)
value|dup2((fd1), (fd2))
end_define

begin_define
define|#
directive|define
name|PerlLIO_flock
parameter_list|(
name|fd
parameter_list|,
name|op
parameter_list|)
value|FLOCK((fd), (op))
end_define

begin_define
define|#
directive|define
name|PerlLIO_fstat
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|)
value|Fstat((fd), (buf))
end_define

begin_define
define|#
directive|define
name|PerlLIO_ioctl
parameter_list|(
name|fd
parameter_list|,
name|u
parameter_list|,
name|buf
parameter_list|)
value|ioctl((fd), (u), (buf))
end_define

begin_define
define|#
directive|define
name|PerlLIO_isatty
parameter_list|(
name|fd
parameter_list|)
value|isatty((fd))
end_define

begin_define
define|#
directive|define
name|PerlLIO_link
parameter_list|(
name|oldname
parameter_list|,
name|newname
parameter_list|)
value|link((oldname), (newname))
end_define

begin_define
define|#
directive|define
name|PerlLIO_lseek
parameter_list|(
name|fd
parameter_list|,
name|offset
parameter_list|,
name|mode
parameter_list|)
value|lseek((fd), (offset), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_stat
parameter_list|(
name|name
parameter_list|,
name|buf
parameter_list|)
value|Stat((name), (buf))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_LSTAT
end_ifdef

begin_define
define|#
directive|define
name|PerlLIO_lstat
parameter_list|(
name|name
parameter_list|,
name|buf
parameter_list|)
value|lstat((name), (buf))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlLIO_lstat
parameter_list|(
name|name
parameter_list|,
name|buf
parameter_list|)
value|PerlLIO_stat((name), (buf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlLIO_mktemp
parameter_list|(
name|file
parameter_list|)
value|mktemp((file))
end_define

begin_define
define|#
directive|define
name|PerlLIO_mkstemp
parameter_list|(
name|file
parameter_list|)
value|mkstemp((file))
end_define

begin_define
define|#
directive|define
name|PerlLIO_open
parameter_list|(
name|file
parameter_list|,
name|flag
parameter_list|)
value|open((file), (flag))
end_define

begin_define
define|#
directive|define
name|PerlLIO_open3
parameter_list|(
name|file
parameter_list|,
name|flag
parameter_list|,
name|perm
parameter_list|)
value|open((file), (flag), (perm))
end_define

begin_define
define|#
directive|define
name|PerlLIO_read
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
value|read((fd), (buf), (count))
end_define

begin_define
define|#
directive|define
name|PerlLIO_rename
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|)
value|rename((old), (new))
end_define

begin_define
define|#
directive|define
name|PerlLIO_setmode
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
value|setmode((fd), (mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_tmpnam
parameter_list|(
name|str
parameter_list|)
value|tmpnam((str))
end_define

begin_define
define|#
directive|define
name|PerlLIO_umask
parameter_list|(
name|mode
parameter_list|)
value|umask((mode))
end_define

begin_define
define|#
directive|define
name|PerlLIO_unlink
parameter_list|(
name|file
parameter_list|)
value|unlink((file))
end_define

begin_define
define|#
directive|define
name|PerlLIO_utime
parameter_list|(
name|file
parameter_list|,
name|time
parameter_list|)
value|utime((file), (time))
end_define

begin_define
define|#
directive|define
name|PerlLIO_write
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|)
value|write((fd), (buf), (count))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_comment
comment|/*     Interface for perl memory allocation */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_comment
comment|/* IPerlMem		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlMem
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlMemInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|LPMemMalloc
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|LPMemRealloc
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPMemFree
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|LPMemCalloc
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPMemGetLock
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPMemFreeLock
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPMemIsLocked
function_decl|)
parameter_list|(
name|struct
name|IPerlMem
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|IPerlMem
block|{
name|LPMemMalloc
name|pMalloc
decl_stmt|;
name|LPMemRealloc
name|pRealloc
decl_stmt|;
name|LPMemFree
name|pFree
decl_stmt|;
name|LPMemCalloc
name|pCalloc
decl_stmt|;
name|LPMemGetLock
name|pGetLock
decl_stmt|;
name|LPMemFreeLock
name|pFreeLock
decl_stmt|;
name|LPMemIsLocked
name|pIsLocked
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlMemInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlMem
name|perlMemList
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interpreter specific memory macros */
end_comment

begin_define
define|#
directive|define
name|PerlMem_malloc
parameter_list|(
name|size
parameter_list|)
define|\
value|(*PL_Mem->pMalloc)(PL_Mem, (size))
end_define

begin_define
define|#
directive|define
name|PerlMem_realloc
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_Mem->pRealloc)(PL_Mem, (buf), (size))
end_define

begin_define
define|#
directive|define
name|PerlMem_free
parameter_list|(
name|buf
parameter_list|)
define|\
value|(*PL_Mem->pFree)(PL_Mem, (buf))
end_define

begin_define
define|#
directive|define
name|PerlMem_calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_Mem->pCalloc)(PL_Mem, (num), (size))
end_define

begin_define
define|#
directive|define
name|PerlMem_get_lock
parameter_list|()
define|\
value|(*PL_Mem->pGetLock)(PL_Mem)
end_define

begin_define
define|#
directive|define
name|PerlMem_free_lock
parameter_list|()
define|\
value|(*PL_Mem->pFreeLock)(PL_Mem)
end_define

begin_define
define|#
directive|define
name|PerlMem_is_locked
parameter_list|()
define|\
value|(*PL_Mem->pIsLocked)(PL_Mem)
end_define

begin_comment
comment|/* Shared memory macros */
end_comment

begin_define
define|#
directive|define
name|PerlMemShared_malloc
parameter_list|(
name|size
parameter_list|)
define|\
value|(*PL_MemShared->pMalloc)(PL_Mem, (size))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_realloc
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_MemShared->pRealloc)(PL_Mem, (buf), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_free
parameter_list|(
name|buf
parameter_list|)
define|\
value|(*PL_MemShared->pFree)(PL_Mem, (buf))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_MemShared->pCalloc)(PL_Mem, (num), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_get_lock
parameter_list|()
define|\
value|(*PL_MemShared->pGetLock)(PL_Mem)
end_define

begin_define
define|#
directive|define
name|PerlMemShared_free_lock
parameter_list|()
define|\
value|(*PL_MemShared->pFreeLock)(PL_Mem)
end_define

begin_define
define|#
directive|define
name|PerlMemShared_is_locked
parameter_list|()
define|\
value|(*PL_MemShared->pIsLocked)(PL_Mem)
end_define

begin_comment
comment|/* Parse tree memory macros */
end_comment

begin_define
define|#
directive|define
name|PerlMemParse_malloc
parameter_list|(
name|size
parameter_list|)
define|\
value|(*PL_MemParse->pMalloc)(PL_Mem, (size))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_realloc
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_MemParse->pRealloc)(PL_Mem, (buf), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_free
parameter_list|(
name|buf
parameter_list|)
define|\
value|(*PL_MemParse->pFree)(PL_Mem, (buf))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
define|\
value|(*PL_MemParse->pCalloc)(PL_Mem, (num), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_get_lock
parameter_list|()
define|\
value|(*PL_MemParse->pGetLock)(PL_Mem)
end_define

begin_define
define|#
directive|define
name|PerlMemParse_free_lock
parameter_list|()
define|\
value|(*PL_MemParse->pFreeLock)(PL_Mem)
end_define

begin_define
define|#
directive|define
name|PerlMemParse_is_locked
parameter_list|()
define|\
value|(*PL_MemParse->pIsLocked)(PL_Mem)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_comment
comment|/* Interpreter specific memory macros */
end_comment

begin_define
define|#
directive|define
name|PerlMem_malloc
parameter_list|(
name|size
parameter_list|)
value|malloc((size))
end_define

begin_define
define|#
directive|define
name|PerlMem_realloc
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|realloc((buf), (size))
end_define

begin_define
define|#
directive|define
name|PerlMem_free
parameter_list|(
name|buf
parameter_list|)
value|free((buf))
end_define

begin_define
define|#
directive|define
name|PerlMem_calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
value|calloc((num), (size))
end_define

begin_define
define|#
directive|define
name|PerlMem_get_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PerlMem_free_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PerlMem_is_locked
parameter_list|()
value|0
end_define

begin_comment
comment|/* Shared memory macros */
end_comment

begin_define
define|#
directive|define
name|PerlMemShared_malloc
parameter_list|(
name|size
parameter_list|)
value|malloc((size))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_realloc
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|realloc((buf), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_free
parameter_list|(
name|buf
parameter_list|)
value|free((buf))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
value|calloc((num), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemShared_get_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PerlMemShared_free_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PerlMemShared_is_locked
parameter_list|()
value|0
end_define

begin_comment
comment|/* Parse tree memory macros */
end_comment

begin_define
define|#
directive|define
name|PerlMemParse_malloc
parameter_list|(
name|size
parameter_list|)
value|malloc((size))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_realloc
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|realloc((buf), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_free
parameter_list|(
name|buf
parameter_list|)
value|free((buf))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
value|calloc((num), (size))
end_define

begin_define
define|#
directive|define
name|PerlMemParse_get_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PerlMemParse_free_lock
parameter_list|()
end_define

begin_define
define|#
directive|define
name|PerlMemParse_is_locked
parameter_list|()
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_comment
comment|/*     Interface for perl process functions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|jmp_buf
end_ifndef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPerlProc		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlProc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlProcInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPProcAbort
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPProcCrypt
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPProcExit
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPProc_Exit
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcExecl
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcExecv
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcExecvp
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uid_t
function_decl|(
modifier|*
name|LPProcGetuid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uid_t
function_decl|(
modifier|*
name|LPProcGeteuid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|gid_t
function_decl|(
modifier|*
name|LPProcGetgid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|gid_t
function_decl|(
modifier|*
name|LPProcGetegid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPProcGetlogin
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcKill
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcKillpg
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcPauseProc
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PerlIO
modifier|*
function_decl|(
modifier|*
name|LPProcPopen
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcPclose
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|PerlIO
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcPipe
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcSetuid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcSetgid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcSleep
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcTimes
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|struct
name|tms
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcWait
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcWaitpid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|Sighandler_t
function_decl|(
modifier|*
name|LPProcSignal
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Sighandler_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcFork
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcGetpid
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|LPProcDynaLoader
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPProcGetOSError
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|SV
modifier|*
name|sv
parameter_list|,
name|DWORD
name|dwErr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPProcFreeBuf
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
modifier|*
name|LPProcDoCmd
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcSpawn
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcSpawnvp
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPProcASpawn
function_decl|)
parameter_list|(
name|struct
name|IPerlProc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|IPerlProc
block|{
name|LPProcAbort
name|pAbort
decl_stmt|;
name|LPProcCrypt
name|pCrypt
decl_stmt|;
name|LPProcExit
name|pExit
decl_stmt|;
name|LPProc_Exit
name|p_Exit
decl_stmt|;
name|LPProcExecl
name|pExecl
decl_stmt|;
name|LPProcExecv
name|pExecv
decl_stmt|;
name|LPProcExecvp
name|pExecvp
decl_stmt|;
name|LPProcGetuid
name|pGetuid
decl_stmt|;
name|LPProcGeteuid
name|pGeteuid
decl_stmt|;
name|LPProcGetgid
name|pGetgid
decl_stmt|;
name|LPProcGetegid
name|pGetegid
decl_stmt|;
name|LPProcGetlogin
name|pGetlogin
decl_stmt|;
name|LPProcKill
name|pKill
decl_stmt|;
name|LPProcKillpg
name|pKillpg
decl_stmt|;
name|LPProcPauseProc
name|pPauseProc
decl_stmt|;
name|LPProcPopen
name|pPopen
decl_stmt|;
name|LPProcPclose
name|pPclose
decl_stmt|;
name|LPProcPipe
name|pPipe
decl_stmt|;
name|LPProcSetuid
name|pSetuid
decl_stmt|;
name|LPProcSetgid
name|pSetgid
decl_stmt|;
name|LPProcSleep
name|pSleep
decl_stmt|;
name|LPProcTimes
name|pTimes
decl_stmt|;
name|LPProcWait
name|pWait
decl_stmt|;
name|LPProcWaitpid
name|pWaitpid
decl_stmt|;
name|LPProcSignal
name|pSignal
decl_stmt|;
name|LPProcFork
name|pFork
decl_stmt|;
name|LPProcGetpid
name|pGetpid
decl_stmt|;
ifdef|#
directive|ifdef
name|WIN32
name|LPProcDynaLoader
name|pDynaLoader
decl_stmt|;
name|LPProcGetOSError
name|pGetOSError
decl_stmt|;
name|LPProcDoCmd
name|pDoCmd
decl_stmt|;
name|LPProcSpawn
name|pSpawn
decl_stmt|;
name|LPProcSpawnvp
name|pSpawnvp
decl_stmt|;
name|LPProcASpawn
name|pASpawn
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlProcInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlProc
name|perlProcList
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PerlProc_abort
parameter_list|()
define|\
value|(*PL_Proc->pAbort)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_crypt
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|(*PL_Proc->pCrypt)(PL_Proc, (c), (s))
end_define

begin_define
define|#
directive|define
name|PerlProc_exit
parameter_list|(
name|s
parameter_list|)
define|\
value|(*PL_Proc->pExit)(PL_Proc, (s))
end_define

begin_define
define|#
directive|define
name|PerlProc__exit
parameter_list|(
name|s
parameter_list|)
define|\
value|(*PL_Proc->p_Exit)(PL_Proc, (s))
end_define

begin_define
define|#
directive|define
name|PerlProc_execl
parameter_list|(
name|c
parameter_list|,
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|(*PL_Proc->pExecl)(PL_Proc, (c), (w), (x), (y), (z))
end_define

begin_define
define|#
directive|define
name|PerlProc_execv
parameter_list|(
name|c
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_Proc->pExecv)(PL_Proc, (c), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_execvp
parameter_list|(
name|c
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_Proc->pExecvp)(PL_Proc, (c), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_getuid
parameter_list|()
define|\
value|(*PL_Proc->pGetuid)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_geteuid
parameter_list|()
define|\
value|(*PL_Proc->pGeteuid)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_getgid
parameter_list|()
define|\
value|(*PL_Proc->pGetgid)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_getegid
parameter_list|()
define|\
value|(*PL_Proc->pGetegid)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_getlogin
parameter_list|()
define|\
value|(*PL_Proc->pGetlogin)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_kill
parameter_list|(
name|i
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_Proc->pKill)(PL_Proc, (i), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_killpg
parameter_list|(
name|i
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_Proc->pKillpg)(PL_Proc, (i), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_pause
parameter_list|()
define|\
value|(*PL_Proc->pPauseProc)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_popen
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
define|\
value|(*PL_Proc->pPopen)(PL_Proc, (c), (m))
end_define

begin_define
define|#
directive|define
name|PerlProc_pclose
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_Proc->pPclose)(PL_Proc, (f))
end_define

begin_define
define|#
directive|define
name|PerlProc_pipe
parameter_list|(
name|fd
parameter_list|)
define|\
value|(*PL_Proc->pPipe)(PL_Proc, (fd))
end_define

begin_define
define|#
directive|define
name|PerlProc_setuid
parameter_list|(
name|u
parameter_list|)
define|\
value|(*PL_Proc->pSetuid)(PL_Proc, (u))
end_define

begin_define
define|#
directive|define
name|PerlProc_setgid
parameter_list|(
name|g
parameter_list|)
define|\
value|(*PL_Proc->pSetgid)(PL_Proc, (g))
end_define

begin_define
define|#
directive|define
name|PerlProc_sleep
parameter_list|(
name|t
parameter_list|)
define|\
value|(*PL_Proc->pSleep)(PL_Proc, (t))
end_define

begin_define
define|#
directive|define
name|PerlProc_times
parameter_list|(
name|t
parameter_list|)
define|\
value|(*PL_Proc->pTimes)(PL_Proc, (t))
end_define

begin_define
define|#
directive|define
name|PerlProc_wait
parameter_list|(
name|t
parameter_list|)
define|\
value|(*PL_Proc->pWait)(PL_Proc, (t))
end_define

begin_define
define|#
directive|define
name|PerlProc_waitpid
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|(*PL_Proc->pWaitpid)(PL_Proc, (p), (s), (f))
end_define

begin_define
define|#
directive|define
name|PerlProc_signal
parameter_list|(
name|n
parameter_list|,
name|h
parameter_list|)
define|\
value|(*PL_Proc->pSignal)(PL_Proc, (n), (h))
end_define

begin_define
define|#
directive|define
name|PerlProc_fork
parameter_list|()
define|\
value|(*PL_Proc->pFork)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_getpid
parameter_list|()
define|\
value|(*PL_Proc->pGetpid)(PL_Proc)
end_define

begin_define
define|#
directive|define
name|PerlProc_setjmp
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|Sigsetjmp((b), (n))
end_define

begin_define
define|#
directive|define
name|PerlProc_longjmp
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|Siglongjmp((b), (n))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlProc_DynaLoad
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_Proc->pDynaLoader)(PL_Proc, (f))
end_define

begin_define
define|#
directive|define
name|PerlProc_GetOSError
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
define|\
value|(*PL_Proc->pGetOSError)(PL_Proc, (s), (e))
end_define

begin_define
define|#
directive|define
name|PerlProc_Cmd
parameter_list|(
name|s
parameter_list|)
define|\
value|(*PL_Proc->pDoCmd)(PL_Proc, (s))
end_define

begin_define
define|#
directive|define
name|do_spawn
parameter_list|(
name|s
parameter_list|)
define|\
value|(*PL_Proc->pSpawn)(PL_Proc, (s))
end_define

begin_define
define|#
directive|define
name|do_spawnvp
parameter_list|(
name|m
parameter_list|,
name|c
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_Proc->pSpawnvp)(PL_Proc, (m), (c), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_aspawn
parameter_list|(
name|m
parameter_list|,
name|c
parameter_list|,
name|a
parameter_list|)
define|\
value|(*PL_Proc->pASpawn)(PL_Proc, (m), (c), (a))
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_define
define|#
directive|define
name|PerlProc_abort
parameter_list|()
value|abort()
end_define

begin_define
define|#
directive|define
name|PerlProc_crypt
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|crypt((c), (s))
end_define

begin_define
define|#
directive|define
name|PerlProc_exit
parameter_list|(
name|s
parameter_list|)
value|exit((s))
end_define

begin_define
define|#
directive|define
name|PerlProc__exit
parameter_list|(
name|s
parameter_list|)
value|_exit((s))
end_define

begin_define
define|#
directive|define
name|PerlProc_execl
parameter_list|(
name|c
parameter_list|,
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|execl((c), (w), (x), (y), (z))
end_define

begin_define
define|#
directive|define
name|PerlProc_execv
parameter_list|(
name|c
parameter_list|,
name|a
parameter_list|)
value|execv((c), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_execvp
parameter_list|(
name|c
parameter_list|,
name|a
parameter_list|)
value|execvp((c), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_getuid
parameter_list|()
value|getuid()
end_define

begin_define
define|#
directive|define
name|PerlProc_geteuid
parameter_list|()
value|geteuid()
end_define

begin_define
define|#
directive|define
name|PerlProc_getgid
parameter_list|()
value|getgid()
end_define

begin_define
define|#
directive|define
name|PerlProc_getegid
parameter_list|()
value|getegid()
end_define

begin_define
define|#
directive|define
name|PerlProc_getlogin
parameter_list|()
value|getlogin()
end_define

begin_define
define|#
directive|define
name|PerlProc_kill
parameter_list|(
name|i
parameter_list|,
name|a
parameter_list|)
value|kill((i), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_killpg
parameter_list|(
name|i
parameter_list|,
name|a
parameter_list|)
value|killpg((i), (a))
end_define

begin_define
define|#
directive|define
name|PerlProc_pause
parameter_list|()
value|Pause()
end_define

begin_define
define|#
directive|define
name|PerlProc_popen
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|my_popen((c), (m))
end_define

begin_define
define|#
directive|define
name|PerlProc_pclose
parameter_list|(
name|f
parameter_list|)
value|my_pclose((f))
end_define

begin_define
define|#
directive|define
name|PerlProc_pipe
parameter_list|(
name|fd
parameter_list|)
value|pipe((fd))
end_define

begin_define
define|#
directive|define
name|PerlProc_setuid
parameter_list|(
name|u
parameter_list|)
value|setuid((u))
end_define

begin_define
define|#
directive|define
name|PerlProc_setgid
parameter_list|(
name|g
parameter_list|)
value|setgid((g))
end_define

begin_define
define|#
directive|define
name|PerlProc_sleep
parameter_list|(
name|t
parameter_list|)
value|sleep((t))
end_define

begin_define
define|#
directive|define
name|PerlProc_times
parameter_list|(
name|t
parameter_list|)
value|times((t))
end_define

begin_define
define|#
directive|define
name|PerlProc_wait
parameter_list|(
name|t
parameter_list|)
value|wait((t))
end_define

begin_define
define|#
directive|define
name|PerlProc_waitpid
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|waitpid((p), (s), (f))
end_define

begin_define
define|#
directive|define
name|PerlProc_setjmp
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|Sigsetjmp((b), (n))
end_define

begin_define
define|#
directive|define
name|PerlProc_longjmp
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|Siglongjmp((b), (n))
end_define

begin_define
define|#
directive|define
name|PerlProc_signal
parameter_list|(
name|n
parameter_list|,
name|h
parameter_list|)
value|signal((n), (h))
end_define

begin_define
define|#
directive|define
name|PerlProc_fork
parameter_list|()
value|fork()
end_define

begin_define
define|#
directive|define
name|PerlProc_getpid
parameter_list|()
value|getpid()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlProc_DynaLoad
parameter_list|(
name|f
parameter_list|)
define|\
value|win32_dynaload((f))
end_define

begin_define
define|#
directive|define
name|PerlProc_GetOSError
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
define|\
value|win32_str_os_error((s), (e))
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_comment
comment|/*     Interface for perl socket functions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_comment
comment|/* PerlSock		*/
end_comment

begin_struct_decl
struct_decl|struct
name|IPerlSock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|IPerlSockInfo
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|u_long
function_decl|(
modifier|*
name|LPHtonl
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
function_decl|(
modifier|*
name|LPHtons
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
function_decl|(
modifier|*
name|LPNtohl
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
function_decl|(
modifier|*
name|LPNtohs
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|SOCKET
function_decl|(
modifier|*
name|LPAccept
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPBind
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPConnect
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEndhostent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEndnetent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEndprotoent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPEndservent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGethostname
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetpeername
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hostent
modifier|*
function_decl|(
modifier|*
name|LPGethostbyaddr
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hostent
modifier|*
function_decl|(
modifier|*
name|LPGethostbyname
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hostent
modifier|*
function_decl|(
modifier|*
name|LPGethostent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|netent
modifier|*
function_decl|(
modifier|*
name|LPGetnetbyaddr
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|netent
modifier|*
function_decl|(
modifier|*
name|LPGetnetbyname
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|netent
modifier|*
function_decl|(
modifier|*
name|LPGetnetent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|protoent
modifier|*
function_decl|(
modifier|*
name|LPGetprotobyname
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|protoent
modifier|*
function_decl|(
modifier|*
name|LPGetprotobynumber
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|protoent
modifier|*
function_decl|(
modifier|*
name|LPGetprotoent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|servent
modifier|*
function_decl|(
modifier|*
name|LPGetservbyname
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|servent
modifier|*
function_decl|(
modifier|*
name|LPGetservbyport
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|servent
modifier|*
function_decl|(
modifier|*
name|LPGetservent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetsockname
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPGetsockopt
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
function_decl|(
modifier|*
name|LPInetAddr
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|LPInetNtoa
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPListen
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPRecv
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPRecvfrom
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSelect
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSend
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSendto
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSethostent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetnetent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetprotoent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LPSetservent
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSetsockopt
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPShutdown
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|SOCKET
function_decl|(
modifier|*
name|LPSocket
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPSocketpair
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|LPClosesocket
function_decl|)
parameter_list|(
name|struct
name|IPerlSock
modifier|*
parameter_list|,
name|SOCKET
name|s
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|IPerlSock
block|{
name|LPHtonl
name|pHtonl
decl_stmt|;
name|LPHtons
name|pHtons
decl_stmt|;
name|LPNtohl
name|pNtohl
decl_stmt|;
name|LPNtohs
name|pNtohs
decl_stmt|;
name|LPAccept
name|pAccept
decl_stmt|;
name|LPBind
name|pBind
decl_stmt|;
name|LPConnect
name|pConnect
decl_stmt|;
name|LPEndhostent
name|pEndhostent
decl_stmt|;
name|LPEndnetent
name|pEndnetent
decl_stmt|;
name|LPEndprotoent
name|pEndprotoent
decl_stmt|;
name|LPEndservent
name|pEndservent
decl_stmt|;
name|LPGethostname
name|pGethostname
decl_stmt|;
name|LPGetpeername
name|pGetpeername
decl_stmt|;
name|LPGethostbyaddr
name|pGethostbyaddr
decl_stmt|;
name|LPGethostbyname
name|pGethostbyname
decl_stmt|;
name|LPGethostent
name|pGethostent
decl_stmt|;
name|LPGetnetbyaddr
name|pGetnetbyaddr
decl_stmt|;
name|LPGetnetbyname
name|pGetnetbyname
decl_stmt|;
name|LPGetnetent
name|pGetnetent
decl_stmt|;
name|LPGetprotobyname
name|pGetprotobyname
decl_stmt|;
name|LPGetprotobynumber
name|pGetprotobynumber
decl_stmt|;
name|LPGetprotoent
name|pGetprotoent
decl_stmt|;
name|LPGetservbyname
name|pGetservbyname
decl_stmt|;
name|LPGetservbyport
name|pGetservbyport
decl_stmt|;
name|LPGetservent
name|pGetservent
decl_stmt|;
name|LPGetsockname
name|pGetsockname
decl_stmt|;
name|LPGetsockopt
name|pGetsockopt
decl_stmt|;
name|LPInetAddr
name|pInetAddr
decl_stmt|;
name|LPInetNtoa
name|pInetNtoa
decl_stmt|;
name|LPListen
name|pListen
decl_stmt|;
name|LPRecv
name|pRecv
decl_stmt|;
name|LPRecvfrom
name|pRecvfrom
decl_stmt|;
name|LPSelect
name|pSelect
decl_stmt|;
name|LPSend
name|pSend
decl_stmt|;
name|LPSendto
name|pSendto
decl_stmt|;
name|LPSethostent
name|pSethostent
decl_stmt|;
name|LPSetnetent
name|pSetnetent
decl_stmt|;
name|LPSetprotoent
name|pSetprotoent
decl_stmt|;
name|LPSetservent
name|pSetservent
decl_stmt|;
name|LPSetsockopt
name|pSetsockopt
decl_stmt|;
name|LPShutdown
name|pShutdown
decl_stmt|;
name|LPSocket
name|pSocket
decl_stmt|;
name|LPSocketpair
name|pSocketpair
decl_stmt|;
ifdef|#
directive|ifdef
name|WIN32
name|LPClosesocket
name|pClosesocket
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IPerlSockInfo
block|{
name|unsigned
name|long
name|nCount
decl_stmt|;
comment|/* number of entries expected */
name|struct
name|IPerlSock
name|perlSockList
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PerlSock_htonl
parameter_list|(
name|x
parameter_list|)
define|\
value|(*PL_Sock->pHtonl)(PL_Sock, x)
end_define

begin_define
define|#
directive|define
name|PerlSock_htons
parameter_list|(
name|x
parameter_list|)
define|\
value|(*PL_Sock->pHtons)(PL_Sock, x)
end_define

begin_define
define|#
directive|define
name|PerlSock_ntohl
parameter_list|(
name|x
parameter_list|)
define|\
value|(*PL_Sock->pNtohl)(PL_Sock, x)
end_define

begin_define
define|#
directive|define
name|PerlSock_ntohs
parameter_list|(
name|x
parameter_list|)
define|\
value|(*PL_Sock->pNtohs)(PL_Sock, x)
end_define

begin_define
define|#
directive|define
name|PerlSock_accept
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Sock->pAccept)(PL_Sock, s, a, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_bind
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Sock->pBind)(PL_Sock, s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_connect
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Sock->pConnect)(PL_Sock, s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_endhostent
parameter_list|()
define|\
value|(*PL_Sock->pEndhostent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_endnetent
parameter_list|()
define|\
value|(*PL_Sock->pEndnetent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_endprotoent
parameter_list|()
define|\
value|(*PL_Sock->pEndprotoent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_endservent
parameter_list|()
define|\
value|(*PL_Sock->pEndservent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostbyaddr
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|,
name|t
parameter_list|)
define|\
value|(*PL_Sock->pGethostbyaddr)(PL_Sock, a, l, t)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostbyname
parameter_list|(
name|n
parameter_list|)
define|\
value|(*PL_Sock->pGethostbyname)(PL_Sock, n)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostent
parameter_list|()
define|\
value|(*PL_Sock->pGethostent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostname
parameter_list|(
name|n
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Sock->pGethostname)(PL_Sock, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_getnetbyaddr
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|(*PL_Sock->pGetnetbyaddr)(PL_Sock, n, t)
end_define

begin_define
define|#
directive|define
name|PerlSock_getnetbyname
parameter_list|(
name|c
parameter_list|)
define|\
value|(*PL_Sock->pGetnetbyname)(PL_Sock, c)
end_define

begin_define
define|#
directive|define
name|PerlSock_getnetent
parameter_list|()
define|\
value|(*PL_Sock->pGetnetent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_getpeername
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Sock->pGetpeername)(PL_Sock, s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_getprotobyname
parameter_list|(
name|n
parameter_list|)
define|\
value|(*PL_Sock->pGetprotobyname)(PL_Sock, n)
end_define

begin_define
define|#
directive|define
name|PerlSock_getprotobynumber
parameter_list|(
name|n
parameter_list|)
define|\
value|(*PL_Sock->pGetprotobynumber)(PL_Sock, n)
end_define

begin_define
define|#
directive|define
name|PerlSock_getprotoent
parameter_list|()
define|\
value|(*PL_Sock->pGetprotoent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_getservbyname
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|(*PL_Sock->pGetservbyname)(PL_Sock, n, p)
end_define

begin_define
define|#
directive|define
name|PerlSock_getservbyport
parameter_list|(
name|port
parameter_list|,
name|p
parameter_list|)
define|\
value|(*PL_Sock->pGetservbyport)(PL_Sock, port, p)
end_define

begin_define
define|#
directive|define
name|PerlSock_getservent
parameter_list|()
define|\
value|(*PL_Sock->pGetservent)(PL_Sock)
end_define

begin_define
define|#
directive|define
name|PerlSock_getsockname
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
define|\
value|(*PL_Sock->pGetsockname)(PL_Sock, s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_getsockopt
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|,
name|i
parameter_list|)
define|\
value|(*PL_Sock->pGetsockopt)(PL_Sock, s, l, n, v, i)
end_define

begin_define
define|#
directive|define
name|PerlSock_inet_addr
parameter_list|(
name|c
parameter_list|)
define|\
value|(*PL_Sock->pInetAddr)(PL_Sock, c)
end_define

begin_define
define|#
directive|define
name|PerlSock_inet_ntoa
parameter_list|(
name|i
parameter_list|)
define|\
value|(*PL_Sock->pInetNtoa)(PL_Sock, i)
end_define

begin_define
define|#
directive|define
name|PerlSock_listen
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
define|\
value|(*PL_Sock->pListen)(PL_Sock, s, b)
end_define

begin_define
define|#
directive|define
name|PerlSock_recv
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
define|\
value|(*PL_Sock->pRecv)(PL_Sock, s, b, l, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_recvfrom
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|,
name|from
parameter_list|,
name|fromlen
parameter_list|)
define|\
value|(*PL_Sock->pRecvfrom)(PL_Sock, s, b, l, f, from, fromlen)
end_define

begin_define
define|#
directive|define
name|PerlSock_select
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|w
parameter_list|,
name|e
parameter_list|,
name|t
parameter_list|)
define|\
value|(*PL_Sock->pSelect)(PL_Sock, n, (char*)r, (char*)w, (char*)e, t)
end_define

begin_define
define|#
directive|define
name|PerlSock_send
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
define|\
value|(*PL_Sock->pSend)(PL_Sock, s, b, l, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_sendto
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|,
name|tlen
parameter_list|)
define|\
value|(*PL_Sock->pSendto)(PL_Sock, s, b, l, f, t, tlen)
end_define

begin_define
define|#
directive|define
name|PerlSock_sethostent
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_Sock->pSethostent)(PL_Sock, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setnetent
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_Sock->pSetnetent)(PL_Sock, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setprotoent
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_Sock->pSetprotoent)(PL_Sock, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setservent
parameter_list|(
name|f
parameter_list|)
define|\
value|(*PL_Sock->pSetservent)(PL_Sock, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setsockopt
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|,
name|len
parameter_list|)
define|\
value|(*PL_Sock->pSetsockopt)(PL_Sock, s, l, n, v, len)
end_define

begin_define
define|#
directive|define
name|PerlSock_shutdown
parameter_list|(
name|s
parameter_list|,
name|h
parameter_list|)
define|\
value|(*PL_Sock->pShutdown)(PL_Sock, s, h)
end_define

begin_define
define|#
directive|define
name|PerlSock_socket
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|)
define|\
value|(*PL_Sock->pSocket)(PL_Sock, a, t, p)
end_define

begin_define
define|#
directive|define
name|PerlSock_socketpair
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|,
name|f
parameter_list|)
define|\
value|(*PL_Sock->pSocketpair)(PL_Sock, a, t, p, f)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlSock_closesocket
parameter_list|(
name|s
parameter_list|)
define|\
value|(*PL_Sock->pClosesocket)(PL_Sock, s)
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_define
define|#
directive|define
name|PerlSock_htonl
parameter_list|(
name|x
parameter_list|)
value|htonl(x)
end_define

begin_define
define|#
directive|define
name|PerlSock_htons
parameter_list|(
name|x
parameter_list|)
value|htons(x)
end_define

begin_define
define|#
directive|define
name|PerlSock_ntohl
parameter_list|(
name|x
parameter_list|)
value|ntohl(x)
end_define

begin_define
define|#
directive|define
name|PerlSock_ntohs
parameter_list|(
name|x
parameter_list|)
value|ntohs(x)
end_define

begin_define
define|#
directive|define
name|PerlSock_accept
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|accept(s, a, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_bind
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
value|bind(s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_connect
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
value|connect(s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostbyaddr
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|,
name|t
parameter_list|)
value|gethostbyaddr(a, l, t)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostbyname
parameter_list|(
name|n
parameter_list|)
value|gethostbyname(n)
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostent
value|gethostent
end_define

begin_define
define|#
directive|define
name|PerlSock_endhostent
value|endhostent
end_define

begin_define
define|#
directive|define
name|PerlSock_gethostname
parameter_list|(
name|n
parameter_list|,
name|l
parameter_list|)
value|gethostname(n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_getnetbyaddr
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|getnetbyaddr(n, t)
end_define

begin_define
define|#
directive|define
name|PerlSock_getnetbyname
parameter_list|(
name|n
parameter_list|)
value|getnetbyname(n)
end_define

begin_define
define|#
directive|define
name|PerlSock_getnetent
value|getnetent
end_define

begin_define
define|#
directive|define
name|PerlSock_endnetent
value|endnetent
end_define

begin_define
define|#
directive|define
name|PerlSock_getpeername
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
value|getpeername(s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_getprotobyname
parameter_list|(
name|n
parameter_list|)
value|getprotobyname(n)
end_define

begin_define
define|#
directive|define
name|PerlSock_getprotobynumber
parameter_list|(
name|n
parameter_list|)
value|getprotobynumber(n)
end_define

begin_define
define|#
directive|define
name|PerlSock_getprotoent
value|getprotoent
end_define

begin_define
define|#
directive|define
name|PerlSock_endprotoent
value|endprotoent
end_define

begin_define
define|#
directive|define
name|PerlSock_getservbyname
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|getservbyname(n, p)
end_define

begin_define
define|#
directive|define
name|PerlSock_getservbyport
parameter_list|(
name|port
parameter_list|,
name|p
parameter_list|)
value|getservbyport(port, p)
end_define

begin_define
define|#
directive|define
name|PerlSock_getservent
value|getservent
end_define

begin_define
define|#
directive|define
name|PerlSock_endservent
value|endservent
end_define

begin_define
define|#
directive|define
name|PerlSock_getsockname
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
value|getsockname(s, n, l)
end_define

begin_define
define|#
directive|define
name|PerlSock_getsockopt
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|,
name|i
parameter_list|)
value|getsockopt(s, l, n, v, i)
end_define

begin_define
define|#
directive|define
name|PerlSock_inet_addr
parameter_list|(
name|c
parameter_list|)
value|inet_addr(c)
end_define

begin_define
define|#
directive|define
name|PerlSock_inet_ntoa
parameter_list|(
name|i
parameter_list|)
value|inet_ntoa(i)
end_define

begin_define
define|#
directive|define
name|PerlSock_listen
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|listen(s, b)
end_define

begin_define
define|#
directive|define
name|PerlSock_recv
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
value|recv(s, b, l, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_recvfrom
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|,
name|from
parameter_list|,
name|fromlen
parameter_list|)
define|\
value|recvfrom(s, b, l, f, from, fromlen)
end_define

begin_define
define|#
directive|define
name|PerlSock_select
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|w
parameter_list|,
name|e
parameter_list|,
name|t
parameter_list|)
value|select(n, r, w, e, t)
end_define

begin_define
define|#
directive|define
name|PerlSock_send
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
value|send(s, b, l, f)
end_define

begin_define
define|#
directive|define
name|PerlSock_sendto
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|,
name|tlen
parameter_list|)
define|\
value|sendto(s, b, l, f, t, tlen)
end_define

begin_define
define|#
directive|define
name|PerlSock_sethostent
parameter_list|(
name|f
parameter_list|)
value|sethostent(f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setnetent
parameter_list|(
name|f
parameter_list|)
value|setnetent(f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setprotoent
parameter_list|(
name|f
parameter_list|)
value|setprotoent(f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setservent
parameter_list|(
name|f
parameter_list|)
value|setservent(f)
end_define

begin_define
define|#
directive|define
name|PerlSock_setsockopt
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|,
name|len
parameter_list|)
define|\
value|setsockopt(s, l, n, v, len)
end_define

begin_define
define|#
directive|define
name|PerlSock_shutdown
parameter_list|(
name|s
parameter_list|,
name|h
parameter_list|)
value|shutdown(s, h)
end_define

begin_define
define|#
directive|define
name|PerlSock_socket
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|)
value|socket(a, t, p)
end_define

begin_define
define|#
directive|define
name|PerlSock_socketpair
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|,
name|f
parameter_list|)
value|socketpair(a, t, p, f)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PerlSock_closesocket
parameter_list|(
name|s
parameter_list|)
value|closesocket(s)
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
comment|/* PERL_IMPLICIT_SYS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __Inc__IPerl___ */
end_comment

end_unit

