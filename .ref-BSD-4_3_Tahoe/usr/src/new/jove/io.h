begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|c
parameter_list|)
value|putc(c, stdout)
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|c
parameter_list|,
name|fp
parameter_list|)
value|(--(fp)->f_cnt>= 0 ? (*(fp)->f_ptr++ = (c)) : _flush((c), fp))
end_define

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|fp
parameter_list|)
value|(((--(fp)->f_cnt< 0) ? filbuf(fp) : *(fp)->f_ptr++))
end_define

begin_typedef
typedef|typedef
struct|struct
name|File
block|{
name|int
name|f_cnt
decl_stmt|,
comment|/* number of characters left in buffer */
name|f_bufsize
decl_stmt|,
comment|/* size of what f_base points to */
name|f_fd
decl_stmt|,
comment|/* fildes */
name|f_flags
decl_stmt|;
comment|/* various flags */
name|char
modifier|*
name|f_ptr
decl_stmt|,
comment|/* current offset */
modifier|*
name|f_base
decl_stmt|;
comment|/* pointer to base */
name|char
modifier|*
name|f_name
decl_stmt|;
comment|/* name of open file */
block|}
name|File
typedef|;
end_typedef

begin_define
define|#
directive|define
name|F_READ
value|01
end_define

begin_define
define|#
directive|define
name|F_WRITE
value|02
end_define

begin_define
define|#
directive|define
name|F_APPEND
value|04
end_define

begin_define
define|#
directive|define
name|F_MODE
parameter_list|(
name|x
parameter_list|)
value|(x&07)
end_define

begin_define
define|#
directive|define
name|F_EOF
value|010
end_define

begin_define
define|#
directive|define
name|F_STRING
value|020
end_define

begin_define
define|#
directive|define
name|F_ERR
value|040
end_define

begin_define
define|#
directive|define
name|F_LOCKED
value|0100
end_define

begin_comment
comment|/* don't close this file upon error */
end_comment

begin_define
define|#
directive|define
name|F_MYBUF
value|0200
end_define

begin_comment
comment|/* f_alloc allocated the buffer, so 				   f_close knows to free it up */
end_comment

begin_define
define|#
directive|define
name|F_TELLALL
value|0400
end_define

begin_comment
comment|/* whether to display info upon close */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|io_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|io_lines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|File
modifier|*
name|stdout
decl_stmt|,
modifier|*
name|open_file
argument_list|()
decl_stmt|,
modifier|*
name|fd_open
argument_list|()
decl_stmt|,
modifier|*
name|f_open
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|MAXTTYBUF
value|2048
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXTTYBUF
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

