begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	stdio.h	1.5	83/08/11	*/
end_comment

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_define
define|#
directive|define
name|_NFILE
value|20
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FILE
end_ifndef

begin_struct
specifier|extern
struct|struct
name|_iobuf
block|{
name|int
name|_cnt
decl_stmt|;
name|char
modifier|*
name|_ptr
decl_stmt|;
name|char
modifier|*
name|_base
decl_stmt|;
name|int
name|_bufsiz
decl_stmt|;
name|short
name|_flag
decl_stmt|;
name|char
name|_file
decl_stmt|;
block|}
name|_iob
index|[
name|_NFILE
index|]
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IOREAD
value|01
end_define

begin_define
define|#
directive|define
name|_IOWRT
value|02
end_define

begin_define
define|#
directive|define
name|_IONBF
value|04
end_define

begin_define
define|#
directive|define
name|_IOMYBUF
value|010
end_define

begin_define
define|#
directive|define
name|_IOEOF
value|020
end_define

begin_define
define|#
directive|define
name|_IOERR
value|040
end_define

begin_define
define|#
directive|define
name|_IOSTRG
value|0100
end_define

begin_define
define|#
directive|define
name|_IOLBF
value|0200
end_define

begin_define
define|#
directive|define
name|_IORW
value|0400
end_define

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|FILE
value|struct _iobuf
end_define

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_define
define|#
directive|define
name|stdin
value|(&_iob[0])
end_define

begin_define
define|#
directive|define
name|stdout
value|(&_iob[1])
end_define

begin_define
define|#
directive|define
name|stderr
value|(&_iob[2])
end_define

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|p
parameter_list|)
value|(--(p)->_cnt>=0? *(p)->_ptr++&0377:_filbuf(p))
end_define

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|getc(stdin)
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|x
parameter_list|,
name|p
parameter_list|)
value|(--(p)->_cnt>=0? ((int)(*(p)->_ptr++=(unsigned)(x))):_flsbuf((unsigned)(x),p))
end_define

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|x
parameter_list|)
value|putc(x,stdout)
end_define

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|p
parameter_list|)
value|(((p)->_flag&_IOEOF)!=0)
end_define

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|p
parameter_list|)
value|(((p)->_flag&_IOERR)!=0)
end_define

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|p
parameter_list|)
value|((p)->_file)
end_define

begin_function_decl
name|FILE
modifier|*
name|fopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fdopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|freopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ftell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fgets
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_function_decl
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* too painful to do right */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

