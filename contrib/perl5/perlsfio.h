begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The next #ifdef should be redundant if Configure behaves ... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_SFIO
end_ifdef

begin_include
include|#
directive|include
file|<sfio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|Sfio_t
modifier|*
name|_stdopen
name|_ARG_
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_stdprintf
name|_ARG_
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PerlIO
value|Sfio_t
end_define

begin_define
define|#
directive|define
name|PerlIO_stderr
parameter_list|()
value|sfstderr
end_define

begin_define
define|#
directive|define
name|PerlIO_stdout
parameter_list|()
value|sfstdout
end_define

begin_define
define|#
directive|define
name|PerlIO_stdin
parameter_list|()
value|sfstdin
end_define

begin_define
define|#
directive|define
name|PerlIO_printf
value|sfprintf
end_define

begin_define
define|#
directive|define
name|PerlIO_stdoutf
value|_stdprintf
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
value|sfvprintf(f,fmt,a)
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
value|sfread(f,buf,count)
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
value|sfwrite(f,buf,count)
end_define

begin_define
define|#
directive|define
name|PerlIO_open
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
value|sfopen(NULL,path,mode)
end_define

begin_define
define|#
directive|define
name|PerlIO_fdopen
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
value|_stdopen(fd,mode)
end_define

begin_define
define|#
directive|define
name|PerlIO_close
parameter_list|(
name|f
parameter_list|)
value|sfclose(f)
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
value|sfputr(f,s,-1)
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
value|sfputc(f,c)
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
value|sfungetc(f,c)
end_define

begin_define
define|#
directive|define
name|PerlIO_sprintf
value|sfsprintf
end_define

begin_define
define|#
directive|define
name|PerlIO_getc
parameter_list|(
name|f
parameter_list|)
value|sfgetc(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_eof
parameter_list|(
name|f
parameter_list|)
value|sfeof(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_error
parameter_list|(
name|f
parameter_list|)
value|sferror(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_fileno
parameter_list|(
name|f
parameter_list|)
value|sffileno(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_clearerr
parameter_list|(
name|f
parameter_list|)
value|sfclrerr(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_flush
parameter_list|(
name|f
parameter_list|)
value|sfsync(f)
end_define

begin_define
define|#
directive|define
name|PerlIO_tell
parameter_list|(
name|f
parameter_list|)
value|sftell(f)
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
value|sfseek(f,o,w)
end_define

begin_define
define|#
directive|define
name|PerlIO_rewind
parameter_list|(
name|f
parameter_list|)
value|(void) sfseek((f),0L,0)
end_define

begin_define
define|#
directive|define
name|PerlIO_tmpfile
parameter_list|()
value|sftmp(0)
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
value|croak("Import from FILE * unimplemeted")
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
value|croak("Export to FILE * unimplemeted")
end_define

begin_define
define|#
directive|define
name|PerlIO_findFILE
parameter_list|(
name|f
parameter_list|)
value|NULL
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
value|croak("Release of FILE * unimplemeted")
end_define

begin_define
define|#
directive|define
name|PerlIO_setlinebuf
parameter_list|(
name|f
parameter_list|)
value|sfset(f,SF_LINE,1)
end_define

begin_comment
comment|/* Now our interface to equivalent of Configure's FILE_xxx macros */
end_comment

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
value|((f)->next)
end_define

begin_define
define|#
directive|define
name|PerlIO_get_cnt
parameter_list|(
name|f
parameter_list|)
value|((f)->endr - (f)->next)
end_define

begin_define
define|#
directive|define
name|PerlIO_canset_cnt
parameter_list|(
name|f
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|PerlIO_fast_gets
parameter_list|(
name|f
parameter_list|)
value|1
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
value|((f)->next = (p))
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
value|1
end_define

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
value|((f)->data)
end_define

begin_define
define|#
directive|define
name|PerlIO_get_bufsiz
parameter_list|(
name|f
parameter_list|)
value|((f)->endr - (f)->data)
end_define

end_unit

