begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_define
define|#
directive|define
name|RMSSIZ
value|256
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
name|char
modifier|*
name|_ptr
decl_stmt|;
name|char
modifier|*
name|_rms
decl_stmt|;
name|char
modifier|*
name|_base
decl_stmt|;
name|long
name|int
name|_sectr
decl_stmt|;
name|short
name|int
name|_flag
decl_stmt|;
name|short
name|int
name|_cnt
decl_stmt|;
name|char
name|_links
decl_stmt|;
name|char
name|_file
decl_stmt|;
name|short
name|int
name|_maxoffset
decl_stmt|;
name|long
name|int
name|_maxsectr
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
name|_IOBIN
value|04
end_define

begin_define
define|#
directive|define
name|_IOPRT
value|010
end_define

begin_define
define|#
directive|define
name|_IOMODE
value|014
end_define

begin_define
define|#
directive|define
name|_IOTXT
value|00
end_define

begin_define
define|#
directive|define
name|_IOMYBUF
value|002000
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
name|_IONBF
value|0200
end_define

begin_define
define|#
directive|define
name|_IOTTY
value|0400
end_define

begin_define
define|#
directive|define
name|_IODIRT
value|01000
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
value|p->_file
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
name|freopen
parameter_list|()
function_decl|;
end_function_decl

begin_struct
specifier|extern
struct|struct
name|io$head
block|{
name|int
name|initzd
decl_stmt|;
name|int
name|lobr
decl_stmt|;
name|FILE
modifier|*
name|ufiles
index|[
name|_NFILE
index|]
decl_stmt|;
name|int
name|hibr
decl_stmt|;
name|int
name|mxbr
decl_stmt|;
name|int
name|lopg
decl_stmt|;
name|int
name|hipg
decl_stmt|;
name|int
name|mxpg
decl_stmt|;
name|char
name|stinrms
index|[
name|RMSSIZ
index|]
decl_stmt|;
name|char
name|storms
index|[
name|RMSSIZ
index|]
decl_stmt|;
name|char
name|sterrms
index|[
name|RMSSIZ
index|]
decl_stmt|;
name|char
name|stinbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|char
name|stobuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|char
name|sterbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
block|}
name|io_com
struct|;
end_struct

begin_define
define|#
directive|define
name|check
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|;	if (c) {errno = s; return(-1);}
end_define

begin_define
define|#
directive|define
name|EBADF
value|9
end_define

begin_define
define|#
directive|define
name|EINVAL
value|22
end_define

begin_define
define|#
directive|define
name|EMFILE
value|24
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

end_unit

