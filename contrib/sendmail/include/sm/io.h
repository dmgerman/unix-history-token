begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  * Copyright (c) 1990  * 	 The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: io.h,v 1.19 2001/07/10 21:56:46 gshapiro Exp $  */
end_comment

begin_comment
comment|/*-  *	@(#)stdio.h	5.17 (Berkeley) 6/3/91  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_IO_H
end_ifndef

begin_define
define|#
directive|define
name|SM_IO_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_include
include|#
directive|include
file|<sm/varargs.h>
end_include

begin_comment
comment|/* mode for sm io (exposed) */
end_comment

begin_define
define|#
directive|define
name|SM_IO_RDWR
value|1
end_define

begin_comment
comment|/* read-write */
end_comment

begin_define
define|#
directive|define
name|SM_IO_RDONLY
value|2
end_define

begin_comment
comment|/* read-only */
end_comment

begin_define
define|#
directive|define
name|SM_IO_WRONLY
value|3
end_define

begin_comment
comment|/* write-only */
end_comment

begin_define
define|#
directive|define
name|SM_IO_APPEND
value|4
end_define

begin_comment
comment|/* write-only from eof */
end_comment

begin_define
define|#
directive|define
name|SM_IO_APPENDRW
value|5
end_define

begin_comment
comment|/* read-write from eof */
end_comment

begin_define
define|#
directive|define
name|SM_IO_RDWRTR
value|6
end_define

begin_comment
comment|/* read-write with truncation indicated */
end_comment

begin_comment
comment|/* for sm_io_fseek, et al api's (exposed) */
end_comment

begin_define
define|#
directive|define
name|SM_IO_SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SM_IO_SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SM_IO_SEEK_END
value|2
end_define

begin_comment
comment|/* flags for info what's with different types (exposed) */
end_comment

begin_define
define|#
directive|define
name|SM_IO_WHAT_MODE
value|1
end_define

begin_define
define|#
directive|define
name|SM_IO_WHAT_VECTORS
value|2
end_define

begin_define
define|#
directive|define
name|SM_IO_WHAT_FD
value|3
end_define

begin_define
define|#
directive|define
name|SM_IO_WHAT_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|SM_IO_WHAT_ISTYPE
value|5
end_define

begin_define
define|#
directive|define
name|SM_IO_IS_READABLE
value|6
end_define

begin_define
define|#
directive|define
name|SM_IO_WHAT_TIMEOUT
value|7
end_define

begin_comment
comment|/* info flags (exposed) */
end_comment

begin_define
define|#
directive|define
name|SM_IO_FTYPE_CREATE
value|1
end_define

begin_define
define|#
directive|define
name|SM_IO_FTYPE_MODIFY
value|2
end_define

begin_define
define|#
directive|define
name|SM_IO_FTYPE_DELETE
value|3
end_define

begin_define
define|#
directive|define
name|SM_IO_SL_PRIO
value|1
end_define

begin_define
define|#
directive|define
name|SM_IO_OPEN_MAX
value|20
end_define

begin_comment
comment|/* for internal buffers */
end_comment

begin_struct
struct|struct
name|smbuf
block|{
name|unsigned
name|char
modifier|*
name|smb_base
decl_stmt|;
name|int
name|smb_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **  sm I/O state variables (internal only). ** **	The following always hold: ** **		if (flags&(SMLBF|SMWR)) == (SMLBF|SMWR), **			lbfsize is -bf.size, else lbfsize is 0 **		if flags&SMRD, w is 0 **		if flags&SMWR, r is 0 ** **	This ensures that the getc and putc macros (or inline functions) never **	try to write or read from a file that is in `read' or `write' mode. **	(Moreover, they can, and do, automatically switch from read mode to **	write mode, and back, on "r+" and "w+" files.) ** **	lbfsize is used only to make the inline line-buffered output stream **	code as compact as possible. ** **	ub, up, and ur are used when ungetc() pushes back more characters **	than fit in the current bf, or when ungetc() pushes back a character **	that does not match the previous one in bf.  When this happens, **	ub.base becomes non-nil (i.e., a stream has ungetc() data iff **	ub.base!=NULL) and up and ur save the current values of p and r. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sm_file
name|SM_FILE_T
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_file
block|{
specifier|const
name|char
modifier|*
name|sm_magic
decl_stmt|;
comment|/* This SM_FILE_T is free when NULL */
name|unsigned
name|char
modifier|*
name|f_p
decl_stmt|;
comment|/* current position in (some) buffer */
name|int
name|f_r
decl_stmt|;
comment|/* read space left for getc() */
name|int
name|f_w
decl_stmt|;
comment|/* write space left for putc() */
name|long
name|f_flags
decl_stmt|;
comment|/* flags, below */
name|short
name|f_file
decl_stmt|;
comment|/* fileno, if Unix fd, else -1 */
name|struct
name|smbuf
name|f_bf
decl_stmt|;
comment|/* the buffer (>= 1 byte, if !NULL) */
name|int
name|f_lbfsize
decl_stmt|;
comment|/* 0 or -bf.size, for inline putc */
comment|/* These can be used for any purpose by a file type implementation: */
name|void
modifier|*
name|f_cookie
decl_stmt|;
name|int
name|f_ival
decl_stmt|;
comment|/* operations */
name|int
argument_list|(
argument|*f_close
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
expr_stmt|;
name|ssize_t
argument_list|(
argument|*f_read
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
name|off_t
argument_list|(
argument|*f_seek
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|ssize_t
argument_list|(
argument|*f_write
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*f_open
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*f_setinfo
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*f_getinfo
argument_list|)
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
name|f_timeout
decl_stmt|;
name|int
name|f_timeoutstate
decl_stmt|;
comment|/* either blocking or non-blocking */
name|char
modifier|*
name|f_type
decl_stmt|;
comment|/* for by-type lookups */
name|void
modifier|*
name|f_self
decl_stmt|;
comment|/* self for reference */
name|struct
name|sm_file
modifier|*
name|f_flushfp
decl_stmt|;
comment|/* flush this before reading parent */
name|struct
name|sm_file
modifier|*
name|f_modefp
decl_stmt|;
comment|/* sync mode with this fp */
comment|/* separate buffer for long sequences of ungetc() */
name|struct
name|smbuf
name|f_ub
decl_stmt|;
comment|/* ungetc buffer */
name|unsigned
name|char
modifier|*
name|f_up
decl_stmt|;
comment|/* saved f_p when f_p is doing ungetc */
name|int
name|f_ur
decl_stmt|;
comment|/* saved f_r when f_r is counting ungetc */
comment|/* tricks to meet minimum requirements even when malloc() fails */
name|unsigned
name|char
name|f_ubuf
index|[
literal|3
index|]
decl_stmt|;
comment|/* guarantee an ungetc() buffer */
name|unsigned
name|char
name|f_nbuf
index|[
literal|1
index|]
decl_stmt|;
comment|/* guarantee a getc() buffer */
comment|/* separate buffer for fgetln() when line crosses buffer boundary */
name|struct
name|smbuf
name|f_lb
decl_stmt|;
comment|/* buffer for fgetln() */
comment|/* Unix stdio files get aligned to block boundaries on fseek() */
name|int
name|f_blksize
decl_stmt|;
comment|/* stat.st_blksize (may be != bf.size) */
name|off_t
name|f_lseekoff
decl_stmt|;
comment|/* current lseek offset */
name|int
name|f_dup_cnt
decl_stmt|;
comment|/* count file dup'd */
block|}
struct|;
end_struct

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|SM_FILE_T
name|SmIoF
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|SmFileMagic
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
name|SmFtStdio_def
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
name|SmFtStdiofd_def
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
name|SmFtString_def
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
name|SmFtSyslog_def
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
name|SmFtRealStdio_def
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SMIOIN_FILENO
value|0
end_define

begin_define
define|#
directive|define
name|SMIOOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|SMIOERR_FILENO
value|2
end_define

begin_define
define|#
directive|define
name|SMIOSTDIN_FILENO
value|3
end_define

begin_define
define|#
directive|define
name|SMIOSTDOUT_FILENO
value|4
end_define

begin_define
define|#
directive|define
name|SMIOSTDERR_FILENO
value|5
end_define

begin_comment
comment|/* Common predefined and already (usually) open files (exposed) */
end_comment

begin_define
define|#
directive|define
name|smioin
value|(&SmIoF[SMIOIN_FILENO])
end_define

begin_define
define|#
directive|define
name|smioout
value|(&SmIoF[SMIOOUT_FILENO])
end_define

begin_define
define|#
directive|define
name|smioerr
value|(&SmIoF[SMIOERR_FILENO])
end_define

begin_define
define|#
directive|define
name|smiostdin
value|(&SmIoF[SMIOSTDIN_FILENO])
end_define

begin_define
define|#
directive|define
name|smiostdout
value|(&SmIoF[SMIOSTDOUT_FILENO])
end_define

begin_define
define|#
directive|define
name|smiostderr
value|(&SmIoF[SMIOSTDERR_FILENO])
end_define

begin_define
define|#
directive|define
name|SmFtStdio
value|(&SmFtStdio_def)
end_define

begin_define
define|#
directive|define
name|SmFtStdiofd
value|(&SmFtStdiofd_def)
end_define

begin_define
define|#
directive|define
name|SmFtString
value|(&SmFtString_def)
end_define

begin_define
define|#
directive|define
name|SmFtSyslog
value|(&SmFtSyslog_def)
end_define

begin_define
define|#
directive|define
name|SmFtRealStdio
value|(&SmFtRealStdio_def)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|SM_IO_SET_TYPE
parameter_list|(
name|f
parameter_list|,
name|name
parameter_list|,
name|open
parameter_list|,
name|close
parameter_list|,
name|read
parameter_list|,
name|write
parameter_list|,
name|seek
parameter_list|,
name|get
parameter_list|,
name|set
parameter_list|,
name|timeout
parameter_list|)
define|\
value|(f) = {SmFileMagic, (unsigned char *) 0, 0, 0, 0L, -1, {0}, 0, (void *) 0,\ 	0, (close), (read), (seek), (write), (open), (set), (get), (timeout),\ 	0, (name)}
end_define

begin_define
define|#
directive|define
name|SM_IO_INIT_TYPE
parameter_list|(
name|f
parameter_list|,
name|name
parameter_list|,
name|open
parameter_list|,
name|close
parameter_list|,
name|read
parameter_list|,
name|write
parameter_list|,
name|seek
parameter_list|,
name|get
parameter_list|,
name|set
parameter_list|,
name|timeout
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|SM_IO_SET_TYPE
parameter_list|(
name|f
parameter_list|,
name|name
parameter_list|,
name|open
parameter_list|,
name|close
parameter_list|,
name|read
parameter_list|,
name|write
parameter_list|,
name|seek
parameter_list|,
name|get
parameter_list|,
name|set
parameter_list|,
name|timeout
parameter_list|)
value|(f)
end_define

begin_define
define|#
directive|define
name|SM_IO_INIT_TYPE
parameter_list|(
name|f
parameter_list|,
name|name
parameter_list|,
name|open
parameter_list|,
name|close
parameter_list|,
name|read
parameter_list|,
name|write
parameter_list|,
name|seek
parameter_list|,
name|get
parameter_list|,
name|set
parameter_list|,
name|timeout
parameter_list|)
define|\
value|(f).sm_magic = SmFileMagic;	\ 	(f).f_p = (unsigned char *) 0;	\ 	(f).f_r = 0;	\ 	(f).f_w = 0;	\ 	(f).f_flags = 0L;	\ 	(f).f_file = 0;	\ 	(f).f_bf.smb_base = (unsigned char *) 0;	\ 	(f).f_bf.smb_size = 0;	\ 	(f).f_lbfsize = 0;	\ 	(f).f_cookie = (void *) 0;	\ 	(f).f_ival = 0;	\ 	(f).f_close = (close);	\ 	(f).f_read = (read);	\ 	(f).f_seek = (seek);	\ 	(f).f_write = (write);	\ 	(f).f_open = (open);	\ 	(f).f_setinfo = (set);	\ 	(f).f_getinfo = (get);	\ 	(f).f_timeout = (timeout);	\ 	(f).f_timeoutstate = 0;	\ 	(f).f_type = (name);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_decl_stmt
name|__END_DECLS
comment|/* Internal flags */
define|#
directive|define
name|SMFBF
value|0x000001
comment|/* XXXX fully buffered */
define|#
directive|define
name|SMLBF
value|0x000002
comment|/* line buffered */
define|#
directive|define
name|SMNBF
value|0x000004
comment|/* unbuffered */
define|#
directive|define
name|SMNOW
value|0x000008
comment|/* Flush each write; take read now */
define|#
directive|define
name|SMRD
value|0x000010
comment|/* OK to read */
define|#
directive|define
name|SMWR
value|0x000020
comment|/* OK to write */
comment|/* RD and WR are never simultaneously asserted */
define|#
directive|define
name|SMRW
value|0x000040
comment|/* open for reading& writing */
define|#
directive|define
name|SMFEOF
value|0x000080
comment|/* found EOF */
define|#
directive|define
name|SMERR
value|0x000100
comment|/* found error */
define|#
directive|define
name|SMMBF
value|0x000200
comment|/* buf is from malloc */
define|#
directive|define
name|SMAPP
value|0x000400
comment|/* fdopen()ed in append mode */
define|#
directive|define
name|SMSTR
value|0x000800
comment|/* this is an snprintf string */
define|#
directive|define
name|SMOPT
value|0x001000
comment|/* do fseek() optimisation */
define|#
directive|define
name|SMNPT
value|0x002000
comment|/* do not do fseek() optimisation */
define|#
directive|define
name|SMOFF
value|0x004000
comment|/* set iff offset is in fact correct */
define|#
directive|define
name|SMALC
value|0x010000
comment|/* allocate string space dynamically */
define|#
directive|define
name|SMACCESSMASK
value|0x0070
define|#
directive|define
name|SMMODEMASK
value|0x011C
comment|/* defines for timeout constants */
define|#
directive|define
name|SM_TIME_IMMEDIATE
value|(0)
define|#
directive|define
name|SM_TIME_FOREVER
value|(-1)
define|#
directive|define
name|SM_TIME_DEFAULT
value|(-2)
comment|/* timeout state for blocking */
define|#
directive|define
name|SM_TIME_BLOCK
value|(0)
comment|/* XXX just bool? */
define|#
directive|define
name|SM_TIME_NONBLOCK
value|(1)
comment|/* Exposed buffering type flags */
define|#
directive|define
name|SM_IO_FBF
value|0
comment|/* setvbuf should set fully buffered */
define|#
directive|define
name|SM_IO_LBF
value|1
comment|/* setvbuf should set line buffered */
define|#
directive|define
name|SM_IO_NBF
value|2
comment|/* setvbuf should set unbuffered */
comment|/* setvbuf buffered, but through at lower file type layers */
define|#
directive|define
name|SM_IO_NOW
value|3
comment|/* **  size of buffer used by setbuf. **  If underlying filesystem blocksize is discoverable that is used instead */
define|#
directive|define
name|SM_IO_BUFSIZ
value|4096
define|#
directive|define
name|SM_IO_EOF
value|(-1)
comment|/* Functions defined in ANSI C standard.  */
name|__BEGIN_DECLS
name|SM_FILE_T
modifier|*
name|sm_io_autoflush
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_io_automode
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_io_clearerr
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_close
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_FILE_T
modifier|*
name|sm_io_dup
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_eof
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_error
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sm_io_fgets
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_flush
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PRINTFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
name|sm_io_fprintf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_fputs
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
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

begin_decl_stmt
name|int
name|SCANFLIKE
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
name|sm_io_fscanf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_getc
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_getinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_FILE_T
modifier|*
name|sm_io_open
name|__P
argument_list|(
operator|(
specifier|const
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_purge
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_putc
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|sm_io_read
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SM_FILE_T
modifier|*
name|sm_io_reopen
name|__P
argument_list|(
operator|(
specifier|const
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|,
specifier|const
name|void
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_io_rewind
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_seek
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|,
name|long
name|SM_NONVOLATILE
operator|,
name|int
name|SM_NONVOLATILE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_setinfo
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_setvbuf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SCANFLIKE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
name|sm_io_sscanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|sm_io_tell
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_ungetc
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_io_vfprintf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|sm_io_write
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sm_strio_init
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
modifier|*
name|sm_io_fopen
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_pathname
operator|,
name|int
name|_flags
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SM_FILE_T
modifier|*
name|sm_io_stdioopen
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|_stream
operator|,
name|char
operator|*
name|_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_vasprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
name|_str
operator|,
specifier|const
name|char
operator|*
name|_fmt
operator|,
name|va_list
name|_ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_vsnprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_perror
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/* ** Functions internal to the implementation. */
name|__BEGIN_DECLS
name|int
name|sm_rget
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_vfscanf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
name|SM_NONVOLATILE
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
name|SM_NONVOLATILE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sm_wbuf
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/* **  The macros are here so that we can **  define function versions in the library. */
end_comment

begin_define
define|#
directive|define
name|sm_getc
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|(--(f)->f_r< 0 ? \ 		sm_rget(f, t) : \ 		(int)(*(f)->f_p++))
end_define

begin_comment
comment|/* **  This has been tuned to generate reasonable code on the vax using pcc. **  (It also generates reasonable x86 code using gcc.) */
end_comment

begin_define
define|#
directive|define
name|sm_putc
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|)
define|\
value|(--(f)->f_w< 0 ? \ 		(f)->f_w>= (f)->f_lbfsize ? \ 			(*(f)->f_p = (c)), *(f)->f_p != '\n' ? \ 				(int)*(f)->f_p++ : \ 				sm_wbuf(f, t, '\n') : \ 			sm_wbuf(f, t, (int)(c)) : \ 		(*(f)->f_p = (c), (int)*(f)->f_p++))
end_define

begin_define
define|#
directive|define
name|sm_eof
parameter_list|(
name|p
parameter_list|)
value|(((p)->f_flags& SMFEOF) != 0)
end_define

begin_define
define|#
directive|define
name|sm_error
parameter_list|(
name|p
parameter_list|)
value|(((p)->f_flags& SMERR) != 0)
end_define

begin_define
define|#
directive|define
name|sm_clearerr
parameter_list|(
name|p
parameter_list|)
value|((void)((p)->f_flags&= ~(SMERR|SMFEOF)))
end_define

begin_define
define|#
directive|define
name|sm_io_eof
parameter_list|(
name|p
parameter_list|)
value|sm_eof(p)
end_define

begin_define
define|#
directive|define
name|sm_io_error
parameter_list|(
name|p
parameter_list|)
value|sm_error(p)
end_define

begin_define
define|#
directive|define
name|sm_io_clearerr
parameter_list|(
name|p
parameter_list|)
value|sm_clearerr(p)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|sm_io_getc
parameter_list|(
name|fp
parameter_list|,
name|t
parameter_list|)
value|sm_getc(fp, t)
end_define

begin_define
define|#
directive|define
name|sm_io_putc
parameter_list|(
name|fp
parameter_list|,
name|t
parameter_list|,
name|x
parameter_list|)
value|sm_putc(fp, t, x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_IO_H */
end_comment

end_unit

