begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Although we may not want stdio to be used including<stdio.h> here   * avoids issues where stdio.h has strange side effects  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PERLIO_IS_STDIO
end_ifdef

begin_comment
comment|/*  * Make this as close to original stdio as possible.  */
end_comment

begin_define
define|#
directive|define
name|PerlIO
value|FILE
end_define

begin_define
define|#
directive|define
name|PerlIO_stderr
parameter_list|()
value|stderr
end_define

begin_define
define|#
directive|define
name|PerlIO_stdout
parameter_list|()
value|stdout
end_define

begin_define
define|#
directive|define
name|PerlIO_stdin
parameter_list|()
value|stdin
end_define

begin_define
define|#
directive|define
name|PerlIO_printf
value|fprintf
end_define

begin_define
define|#
directive|define
name|PerlIO_stdoutf
value|printf
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
value|vfprintf(f,fmt,a)
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
value|fwrite1(buf,1,count,f)
end_define

begin_define
define|#
directive|define
name|PerlIO_open
value|fopen
end_define

begin_define
define|#
directive|define
name|PerlIO_fdopen
value|fdopen
end_define

begin_define
define|#
directive|define
name|PerlIO_reopen
value|freopen
end_define

begin_define
define|#
directive|define
name|PerlIO_close
parameter_list|(
name|f
parameter_list|)
value|fclose(f)
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
value|fputs(s,f)
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
value|fputc(c,f)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DECC
argument_list|)
end_if

begin_comment
comment|/* Unusual definition of ungetc() here to accomodate fast_sv_gets()'       * belief that it can mix getc/ungetc with reads from stdio buffer */
end_comment

begin_function_decl
name|int
name|decc$ungetc
parameter_list|(
name|int
name|__c
parameter_list|,
name|FILE
modifier|*
name|__stream
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PerlIO_ungetc
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|((c) == EOF ? EOF : \             ((*(f)&& !((*(f))->_flag& _IONBF)&& \             ((*(f))->_ptr> (*(f))->_base)) ? \             ((*(f))->_cnt++, *(--(*(f))->_ptr) = (c)) : decc$ungetc(c,f)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlIO_ungetc
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|ungetc(c,f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Work around bug in DECCRTL/AXP (DECC v5.x) and some versions of old     * VAXCRTL which causes read from a pipe after EOF has been returned     * once to hang.     */
end_comment

begin_define
define|#
directive|define
name|PerlIO_getc
parameter_list|(
name|f
parameter_list|)
define|\
value|(feof(f) ? EOF : getc(f))
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
value|(feof(f) ? 0 : (SSize_t)fread(buf,1,count,f))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlIO_ungetc
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|ungetc(c,f)
end_define

begin_define
define|#
directive|define
name|PerlIO_getc
parameter_list|(
name|f
parameter_list|)
value|getc(f)
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
value|(SSize_t)fread(buf,1,count,f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlIO_eof
parameter_list|(
name|f
parameter_list|)
value|feof(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_getname
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|fgetname(f,b)
end_define

begin_define
define|#
directive|define
name|PerlIO_error
parameter_list|(
name|f
parameter_list|)
value|ferror(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_fileno
parameter_list|(
name|f
parameter_list|)
value|fileno(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_clearerr
parameter_list|(
name|f
parameter_list|)
value|clearerr(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_flush
parameter_list|(
name|f
parameter_list|)
value|Fflush(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_tell
parameter_list|(
name|f
parameter_list|)
value|ftell(f)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__DECC
argument_list|)
end_if

begin_comment
comment|/* Old VAXC RTL doesn't reset EOF on seek; Perl folk seem to expect this */
end_comment

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
value|(((f)&& (*f)&& ((*f)->_flag&= ~_IOEOF)),fseek(f,o,w))
end_define

begin_else
else|#
directive|else
end_else

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
value|fseek(f,o,w)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_FGETPOS
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_getpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
value|fgetpos(f,p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_FSETPOS
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_setpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
value|fsetpos(f,p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PerlIO_rewind
parameter_list|(
name|f
parameter_list|)
value|rewind(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_tmpfile
parameter_list|()
value|tmpfile()
end_define

begin_define
define|#
directive|define
name|PerlIO_importFILE
parameter_list|(
name|f
parameter_list|,
name|fl
parameter_list|)
value|(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_exportFILE
parameter_list|(
name|f
parameter_list|,
name|fl
parameter_list|)
value|(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_findFILE
parameter_list|(
name|f
parameter_list|)
value|(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_releaseFILE
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|((void) 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETLINEBUF
end_ifdef

begin_define
define|#
directive|define
name|PerlIO_setlinebuf
parameter_list|(
name|f
parameter_list|)
value|setlinebuf(f);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlIO_setlinebuf
parameter_list|(
name|f
parameter_list|)
value|setvbuf(f, Nullch, _IOLBF, 0);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now our interface to Configure's FILE_xxx macros */
end_comment

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

begin_define
define|#
directive|define
name|PerlIO_get_ptr
parameter_list|(
name|f
parameter_list|)
value|FILE_ptr(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_get_cnt
parameter_list|(
name|f
parameter_list|)
value|FILE_cnt(f)
end_define

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
name|STDIO_PTR_LVALUE
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

begin_define
define|#
directive|define
name|PerlIO_set_cnt
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|(FILE_cnt(f) = (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PerlIO_canset_cnt
parameter_list|(
name|f
parameter_list|)
value|0
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
value|abort()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STDIO_PTR_LVALUE
end_ifdef

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
value|(FILE_ptr(f) = (p), PerlIO_set_cnt(f,c))
end_define

begin_else
else|#
directive|else
end_else

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
value|abort()
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

begin_define
define|#
directive|define
name|PerlIO_get_cnt
parameter_list|(
name|f
parameter_list|)
value|(abort(),0)
end_define

begin_define
define|#
directive|define
name|PerlIO_get_ptr
parameter_list|(
name|f
parameter_list|)
value|(abort(),(void *)0)
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
value|abort()
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
value|abort()
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

begin_define
define|#
directive|define
name|PerlIO_get_base
parameter_list|(
name|f
parameter_list|)
value|FILE_base(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_get_bufsiz
parameter_list|(
name|f
parameter_list|)
value|FILE_bufsiz(f)
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

begin_define
define|#
directive|define
name|PerlIO_get_base
parameter_list|(
name|f
parameter_list|)
value|(abort(),(void *)0)
end_define

begin_define
define|#
directive|define
name|PerlIO_get_bufsiz
parameter_list|(
name|f
parameter_list|)
value|(abort(),0)
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
comment|/* PERLIO_IS_STDIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_CORE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PERLIO_NOT_STDIO
end_ifndef

begin_define
define|#
directive|define
name|PERLIO_NOT_STDIO
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

begin_ifdef
ifdef|#
directive|ifdef
name|PERLIO_NOT_STDIO
end_ifdef

begin_if
if|#
directive|if
name|PERLIO_NOT_STDIO
end_if

begin_comment
comment|/*  * Strong denial of stdio - make all stdio calls (we can think of) errors  */
end_comment

begin_include
include|#
directive|include
file|"nostdio.h"
end_include

begin_undef
undef|#
directive|undef
name|fprintf
end_undef

begin_undef
undef|#
directive|undef
name|tmpfile
end_undef

begin_undef
undef|#
directive|undef
name|fclose
end_undef

begin_undef
undef|#
directive|undef
name|fopen
end_undef

begin_undef
undef|#
directive|undef
name|vfprintf
end_undef

begin_undef
undef|#
directive|undef
name|fgetc
end_undef

begin_undef
undef|#
directive|undef
name|fputc
end_undef

begin_undef
undef|#
directive|undef
name|fputs
end_undef

begin_undef
undef|#
directive|undef
name|ungetc
end_undef

begin_undef
undef|#
directive|undef
name|fread
end_undef

begin_undef
undef|#
directive|undef
name|fwrite
end_undef

begin_undef
undef|#
directive|undef
name|fgetpos
end_undef

begin_undef
undef|#
directive|undef
name|fseek
end_undef

begin_undef
undef|#
directive|undef
name|fsetpos
end_undef

begin_undef
undef|#
directive|undef
name|ftell
end_undef

begin_undef
undef|#
directive|undef
name|rewind
end_undef

begin_undef
undef|#
directive|undef
name|fdopen
end_undef

begin_undef
undef|#
directive|undef
name|popen
end_undef

begin_undef
undef|#
directive|undef
name|pclose
end_undef

begin_undef
undef|#
directive|undef
name|getw
end_undef

begin_undef
undef|#
directive|undef
name|putw
end_undef

begin_undef
undef|#
directive|undef
name|freopen
end_undef

begin_undef
undef|#
directive|undef
name|setbuf
end_undef

begin_undef
undef|#
directive|undef
name|setvbuf
end_undef

begin_undef
undef|#
directive|undef
name|fscanf
end_undef

begin_undef
undef|#
directive|undef
name|fgets
end_undef

begin_undef
undef|#
directive|undef
name|getc_unlocked
end_undef

begin_undef
undef|#
directive|undef
name|putc_unlocked
end_undef

begin_define
define|#
directive|define
name|fprintf
value|_CANNOT _fprintf_
end_define

begin_define
define|#
directive|define
name|stdin
value|_CANNOT _stdin_
end_define

begin_define
define|#
directive|define
name|stdout
value|_CANNOT _stdout_
end_define

begin_define
define|#
directive|define
name|stderr
value|_CANNOT _stderr_
end_define

begin_define
define|#
directive|define
name|tmpfile
parameter_list|()
value|_CANNOT _tmpfile_
end_define

begin_define
define|#
directive|define
name|fclose
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _fclose_
end_define

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _fflush_
end_define

begin_define
define|#
directive|define
name|fopen
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|_CANNOT _fopen_
end_define

begin_define
define|#
directive|define
name|freopen
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _freopen_
end_define

begin_define
define|#
directive|define
name|setbuf
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|_CANNOT _setbuf_
end_define

begin_define
define|#
directive|define
name|setvbuf
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|_CANNOT _setvbuf_
end_define

begin_define
define|#
directive|define
name|fscanf
value|_CANNOT _fscanf_
end_define

begin_define
define|#
directive|define
name|vfprintf
parameter_list|(
name|f
parameter_list|,
name|fmt
parameter_list|,
name|a
parameter_list|)
value|_CANNOT _vfprintf_
end_define

begin_define
define|#
directive|define
name|fgetc
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _fgetc_
end_define

begin_define
define|#
directive|define
name|fgets
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _fgets_
end_define

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _fputc_
end_define

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _fputs_
end_define

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _getc_
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _putc_
end_define

begin_define
define|#
directive|define
name|ungetc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _ungetc_
end_define

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _fread_
end_define

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _fwrite_
end_define

begin_define
define|#
directive|define
name|fgetpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
value|_CANNOT _fgetpos_
end_define

begin_define
define|#
directive|define
name|fseek
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
value|_CANNOT _fseek_
end_define

begin_define
define|#
directive|define
name|fsetpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
value|_CANNOT _fsetpos_
end_define

begin_define
define|#
directive|define
name|ftell
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _ftell_
end_define

begin_define
define|#
directive|define
name|rewind
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _rewind_
end_define

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _clearerr_
end_define

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _feof_
end_define

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _ferror_
end_define

begin_define
define|#
directive|define
name|__filbuf
parameter_list|(
name|f
parameter_list|)
value|_CANNOT __filbuf_
end_define

begin_define
define|#
directive|define
name|__flsbuf
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT __flsbuf_
end_define

begin_define
define|#
directive|define
name|_filbuf
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _filbuf_
end_define

begin_define
define|#
directive|define
name|_flsbuf
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _flsbuf_
end_define

begin_define
define|#
directive|define
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|p
parameter_list|)
value|_CANNOT _fdopen_
end_define

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _fileno_
end_define

begin_define
define|#
directive|define
name|flockfile
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _flockfile_
end_define

begin_define
define|#
directive|define
name|ftrylockfile
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _ftrylockfile_
end_define

begin_define
define|#
directive|define
name|funlockfile
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _funlockfile_
end_define

begin_define
define|#
directive|define
name|getc_unlocked
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _getc_unlocked_
end_define

begin_define
define|#
directive|define
name|putc_unlocked
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _putc_unlocked_
end_define

begin_define
define|#
directive|define
name|popen
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|_CANNOT _popen_
end_define

begin_define
define|#
directive|define
name|getw
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _getw_
end_define

begin_define
define|#
directive|define
name|putw
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _putw_
end_define

begin_define
define|#
directive|define
name|pclose
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _pclose_
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* if PERLIO_NOT_STDIO */
end_comment

begin_comment
comment|/*  * PERLIO_NOT_STDIO defined as 0   * Declares that both PerlIO and stdio can be used  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if PERLIO_NOT_STDIO */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ifdef PERLIO_NOT_STDIO */
end_comment

begin_comment
comment|/*  * PERLIO_NOT_STDIO not defined   * This is "source level" stdio compatibility mode.  */
end_comment

begin_include
include|#
directive|include
file|"nostdio.h"
end_include

begin_undef
undef|#
directive|undef
name|FILE
end_undef

begin_define
define|#
directive|define
name|FILE
value|PerlIO
end_define

begin_undef
undef|#
directive|undef
name|fprintf
end_undef

begin_undef
undef|#
directive|undef
name|tmpfile
end_undef

begin_undef
undef|#
directive|undef
name|fclose
end_undef

begin_undef
undef|#
directive|undef
name|fopen
end_undef

begin_undef
undef|#
directive|undef
name|vfprintf
end_undef

begin_undef
undef|#
directive|undef
name|fgetc
end_undef

begin_undef
undef|#
directive|undef
name|getc_unlocked
end_undef

begin_undef
undef|#
directive|undef
name|fputc
end_undef

begin_undef
undef|#
directive|undef
name|putc_unlocked
end_undef

begin_undef
undef|#
directive|undef
name|fputs
end_undef

begin_undef
undef|#
directive|undef
name|ungetc
end_undef

begin_undef
undef|#
directive|undef
name|fread
end_undef

begin_undef
undef|#
directive|undef
name|fwrite
end_undef

begin_undef
undef|#
directive|undef
name|fgetpos
end_undef

begin_undef
undef|#
directive|undef
name|fseek
end_undef

begin_undef
undef|#
directive|undef
name|fsetpos
end_undef

begin_undef
undef|#
directive|undef
name|ftell
end_undef

begin_undef
undef|#
directive|undef
name|rewind
end_undef

begin_undef
undef|#
directive|undef
name|fdopen
end_undef

begin_undef
undef|#
directive|undef
name|popen
end_undef

begin_undef
undef|#
directive|undef
name|pclose
end_undef

begin_undef
undef|#
directive|undef
name|getw
end_undef

begin_undef
undef|#
directive|undef
name|putw
end_undef

begin_undef
undef|#
directive|undef
name|freopen
end_undef

begin_undef
undef|#
directive|undef
name|setbuf
end_undef

begin_undef
undef|#
directive|undef
name|setvbuf
end_undef

begin_undef
undef|#
directive|undef
name|fscanf
end_undef

begin_undef
undef|#
directive|undef
name|fgets
end_undef

begin_define
define|#
directive|define
name|fprintf
value|PerlIO_printf
end_define

begin_define
define|#
directive|define
name|stdin
value|PerlIO_stdin()
end_define

begin_define
define|#
directive|define
name|stdout
value|PerlIO_stdout()
end_define

begin_define
define|#
directive|define
name|stderr
value|PerlIO_stderr()
end_define

begin_define
define|#
directive|define
name|tmpfile
parameter_list|()
value|PerlIO_tmpfile()
end_define

begin_define
define|#
directive|define
name|fclose
parameter_list|(
name|f
parameter_list|)
value|PerlIO_close(f)
end_define

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|f
parameter_list|)
value|PerlIO_flush(f)
end_define

begin_define
define|#
directive|define
name|fopen
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|PerlIO_open(p,m)
end_define

begin_define
define|#
directive|define
name|vfprintf
parameter_list|(
name|f
parameter_list|,
name|fmt
parameter_list|,
name|a
parameter_list|)
value|PerlIO_vprintf(f,fmt,a)
end_define

begin_define
define|#
directive|define
name|fgetc
parameter_list|(
name|f
parameter_list|)
value|PerlIO_getc(f)
end_define

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_putc(f,c)
end_define

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|PerlIO_puts(f,s)
end_define

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|f
parameter_list|)
value|PerlIO_getc(f)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getc_unlocked
end_ifdef

begin_undef
undef|#
directive|undef
name|getc_unlocked
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getc_unlocked
parameter_list|(
name|f
parameter_list|)
value|PerlIO_getc(f)
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_putc(f,c)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|putc_unlocked
end_ifdef

begin_undef
undef|#
directive|undef
name|putc_unlocked
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|putc_unlocked
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_putc(c,f)
end_define

begin_define
define|#
directive|define
name|ungetc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_ungetc(f,c)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* return values of read/write need work */
end_comment

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_read(f,b,(s*c))
end_define

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_write(f,b,(s*c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT fread
end_define

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT fwrite
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|fgetpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
value|PerlIO_getpos(f,p)
end_define

begin_define
define|#
directive|define
name|fseek
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
value|PerlIO_seek(f,o,w)
end_define

begin_define
define|#
directive|define
name|fsetpos
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
value|PerlIO_setpos(f,p)
end_define

begin_define
define|#
directive|define
name|ftell
parameter_list|(
name|f
parameter_list|)
value|PerlIO_tell(f)
end_define

begin_define
define|#
directive|define
name|rewind
parameter_list|(
name|f
parameter_list|)
value|PerlIO_rewind(f)
end_define

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|f
parameter_list|)
value|PerlIO_clearerr(f)
end_define

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|f
parameter_list|)
value|PerlIO_eof(f)
end_define

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|f
parameter_list|)
value|PerlIO_error(f)
end_define

begin_define
define|#
directive|define
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|p
parameter_list|)
value|PerlIO_fdopen(fd,p)
end_define

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|f
parameter_list|)
value|PerlIO_fileno(f)
end_define

begin_define
define|#
directive|define
name|popen
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|my_popen(c,m)
end_define

begin_define
define|#
directive|define
name|pclose
parameter_list|(
name|f
parameter_list|)
value|my_pclose(f)
end_define

begin_define
define|#
directive|define
name|__filbuf
parameter_list|(
name|f
parameter_list|)
value|_CANNOT __filbuf_
end_define

begin_define
define|#
directive|define
name|_filbuf
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _filbuf_
end_define

begin_define
define|#
directive|define
name|__flsbuf
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT __flsbuf_
end_define

begin_define
define|#
directive|define
name|_flsbuf
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _flsbuf_
end_define

begin_define
define|#
directive|define
name|getw
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _getw_
end_define

begin_define
define|#
directive|define
name|putw
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _putw_
end_define

begin_define
define|#
directive|define
name|flockfile
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _flockfile_
end_define

begin_define
define|#
directive|define
name|ftrylockfile
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _ftrylockfile_
end_define

begin_define
define|#
directive|define
name|funlockfile
parameter_list|(
name|f
parameter_list|)
value|_CANNOT _funlockfile_
end_define

begin_define
define|#
directive|define
name|freopen
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _freopen_
end_define

begin_define
define|#
directive|define
name|setbuf
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|_CANNOT _setbuf_
end_define

begin_define
define|#
directive|define
name|setvbuf
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|_CANNOT _setvbuf_
end_define

begin_define
define|#
directive|define
name|fscanf
value|_CANNOT _fscanf_
end_define

begin_define
define|#
directive|define
name|fgets
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
value|_CANNOT _fgets_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef PERLIO_NOT_STDIO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERLIO_IS_STDIO */
end_comment

end_unit

