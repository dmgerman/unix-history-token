begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)stdio.h	5.4 (Berkeley) 10/22/87  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

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
comment|/* should be unsigned char */
name|char
modifier|*
name|_base
decl_stmt|;
comment|/* ditto */
name|int
name|_bufsiz
decl_stmt|;
name|short
name|_flag
decl_stmt|;
name|char
name|_file
decl_stmt|;
comment|/* should be short */
block|}
name|_iob
index|[]
struct|;
end_struct

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

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|p
parameter_list|)
value|(--(p)->_cnt>=0? (int)(*(unsigned char *)(p)->_ptr++):_filbuf(p))
end_define

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|getc(stdin)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|x
parameter_list|,
name|p
parameter_list|)
value|(--(p)->_cnt>= 0 ?\ 	(int)(*(unsigned char *)(p)->_ptr++ = (x)) :\ 	(((p)->_flag& _IOLBF)&& -(p)->_cnt< (p)->_bufsiz ?\ 		((*(p)->_ptr = (x)) != '\n' ?\ 			(int)(*(unsigned char *)(p)->_ptr++) :\ 			_flsbuf(*(unsigned char *)(p)->_ptr, p)) :\ 		_flsbuf((unsigned char)(x), p)))
end_define

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|p
parameter_list|)
value|((p)->_flag&= ~(_IOERR|_IOEOF))
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
name|FILE
modifier|*
name|popen
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

begin_function_decl
name|char
modifier|*
name|gets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* here until everyone does it right */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

