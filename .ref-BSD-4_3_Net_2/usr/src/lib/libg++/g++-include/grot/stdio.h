begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_comment
comment|/*  *  Please check the following before installing this file:  *  *  Make sure USG is #defined if you are on a USG system!  *  *  Check the value of _NFILE against the one in your /usr/include/stdio.h.  *  (USG only)  *  *  Check whether your libc.a sprintf function returns  *  an int (as do most) versus a char* (BSD), and (un)comment  *  the corresponding SPRINTF_RETURNS_INT line.  *  *  Check the value of BUFSIZ against the one in your /usr/include/stdio.h.  *  *  Carefully check the fields and order of _iobuf declaration against  *  the one in your /usr/include/stdio.h. Xenix-based systems  *  may need some re-ordering of _iobuf. fields.  *  *  Note that some _IOXXX #defines may not be present in your   *  /usr/include/stdio.h. This is ok, so long as the ones that  *  are present in both are set to the same values.  *  *  Some of the prototypes refer to functions that may not be  *  present in your libc.a. This is ok so long as you do not  *  actually call such functions.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_stdio_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_stdio_h
value|1
end_define

begin_comment
comment|/*    HAVE_VPRINTF should be set if vprintf is in libc.a    HAVE_SETVBUF should be set if setvbuf is in libc.a    HAVE_SETLINEBUF should be set if setlinebuf in libc.a     The following are probably correct for the listed systems  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM_FIVE
end_ifdef

begin_define
define|#
directive|define
name|USG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
end_define

begin_comment
comment|//#define  HAVE_SETLINEBUF
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|VMS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
end_define

begin_comment
comment|//#define  HAVE_SETLINEBUF
end_comment

begin_define
define|#
directive|define
name|NO_LIBGXX_MALLOC
end_define

begin_define
define|#
directive|define
name|_NFILE
value|20
end_define

begin_define
define|#
directive|define
name|IOBUF_FLAG_TYPE
value|char
end_define

begin_define
define|#
directive|define
name|IOBUF_BUFSIZ_FIELD
end_define

begin_comment
comment|/* we aint got one either*/
end_comment

begin_elif
elif|#
directive|elif
name|masscomp
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|_NFILE
end_ifndef

begin_define
define|#
directive|define
name|_NFILE
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_ATT
end_ifdef

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
end_define

begin_define
define|#
directive|define
name|USG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_UCB
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_VPRINTF
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_SETLINEBUF
end_undef

begin_define
define|#
directive|define
name|IOBUF_BUFSIZ_FIELD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|sony
argument_list|)
end_elif

begin_comment
comment|//#define HAVE_VPRINTF
end_comment

begin_comment
comment|//#define  HAVE_SETVBUF
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sequent
argument_list|)
end_elif

begin_comment
comment|//#define  HAVE_VPRINTF
end_comment

begin_comment
comment|//#define  HAVE_SETVBUF
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DGUX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|IOBUF_FLAG_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|IOBUF_FILE_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|_NFILE
value|64
end_define

begin_define
define|#
directive|define
name|IOBUF_EXTRA_FIELDS
value|int _reserve[27];
end_define

begin_define
define|#
directive|define
name|SPRINTF_RETURNS_INT
end_define

begin_define
define|#
directive|define
name|BUFEND_ENTRY_TYPE
value|unsigned char *
end_define

begin_define
define|#
directive|define
name|USG
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TEKTRONIX_SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000s300
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SETVBUF
end_define

begin_comment
comment|//#define HAVE_SETLINEBUF
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|convex
argument_list|)
end_elif

begin_comment
comment|//#define HAVE_VPRINTF
end_comment

begin_comment
comment|//#define HAVE_SETVBUF
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|IOBUF_FILE_TYPE
value|unsigned char
end_define

begin_define
define|#
directive|define
name|HAVE_VOID_DOPRNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|IOBUF_FLAG_TYPE
value|short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_define
define|#
directive|define
name|IOBUF_FLAG_TYPE
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_define
define|#
directive|define
name|IOBUF_BUFSIZ_FIELD
end_define

begin_comment
comment|/* System V ain't got one */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some default definitions for things not defined machine-specifically    above.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOBUF_BUFSIZ_FIELD
end_ifndef

begin_define
define|#
directive|define
name|IOBUF_BUFSIZ_FIELD
value|int _bufsiz;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IOBUF_FLAG_TYPE
end_ifndef

begin_define
define|#
directive|define
name|IOBUF_FLAG_TYPE
value|short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IOBUF_FILE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|IOBUF_FILE_TYPE
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IOBUF_EXTRA_FIELDS
end_ifndef

begin_define
define|#
directive|define
name|IOBUF_EXTRA_FIELDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_NFILE
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|_NFILE
value|60
end_define

begin_elif
elif|#
directive|elif
end_elif

begin_define
define|#
directive|define
name|_NFILE
value|20
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
name|USG
end_ifdef

begin_define
define|#
directive|define
name|_bufend
parameter_list|(
name|p
parameter_list|)
value|_bufendtab[(p)->_file]
end_define

begin_define
define|#
directive|define
name|_bufsiz
parameter_list|(
name|p
parameter_list|)
value|(_bufend(p) - (p)->_base)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BUFEND_ENTRY_TYPE
end_ifndef

begin_define
define|#
directive|define
name|BUFEND_ENTRY_TYPE
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
block|{
name|BUFEND_ENTRY_TYPE
name|_bufendtab
index|[]
decl_stmt|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* check this -- hardly any systems need this these days */
end_comment

begin_comment
comment|/* #define SPRINTF_RETURNS_INT */
end_comment

begin_comment
comment|/* check and possibly redefine the following */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|masscomp
end_ifdef

begin_struct
specifier|extern
struct|struct
name|_iobuf
block|{
ifdef|#
directive|ifdef
name|BUFSIZ
undef|#
directive|undef
name|BUFSIZ
endif|#
directive|endif
define|#
directive|define
name|BUFSIZ
value|4096
ifdef|#
directive|ifdef
name|mc68000
name|unsigned
name|char
modifier|*
name|_ptr
decl_stmt|;
name|int
name|_cnt
decl_stmt|;
endif|#
directive|endif
name|char
modifier|*
name|_base
decl_stmt|;
name|IOBUF_BUFSIZ_FIELD
name|IOBUF_FLAG_TYPE
name|_flag
decl_stmt|;
name|IOBUF_FILE_TYPE
name|_file
decl_stmt|;
name|IOBUF_EXTRA_FIELDS
block|}
name|_iob
index|[]
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not masscomp */
end_comment

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
name|IOBUF_BUFSIZ_FIELD
name|IOBUF_FLAG_TYPE
name|_flag
decl_stmt|;
name|IOBUF_FILE_TYPE
name|_file
decl_stmt|;
name|IOBUF_EXTRA_FIELDS
block|}
name|_iob
index|[]
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|_iobuf
name|FILE
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|_iobuf
modifier|*
name|FILE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|FILE
modifier|*
name|VMS_FILE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IOFBF
value|00000
end_define

begin_define
define|#
directive|define
name|_IOREAD
value|00001
end_define

begin_define
define|#
directive|define
name|_IOWRT
value|00002
end_define

begin_define
define|#
directive|define
name|_IONBF
value|00004
end_define

begin_define
define|#
directive|define
name|_IOMYBUF
value|00010
end_define

begin_define
define|#
directive|define
name|_IOEOF
value|00020
end_define

begin_define
define|#
directive|define
name|_IOERR
value|00040
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|_IOSTRG
value|00000
end_define

begin_comment
comment|/* faked out for USG */
end_comment

begin_define
define|#
directive|define
name|_IOLBF
value|00100
end_define

begin_define
define|#
directive|define
name|_IORW
value|00200
end_define

begin_define
define|#
directive|define
name|_IOAPPEND
value|00000
end_define

begin_comment
comment|/* faked out for USG */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|masscomp
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_IOSTRG
value|0x00
end_define

begin_comment
comment|/* not used in this version of stdio */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IOERR
end_ifdef

begin_undef
undef|#
directive|undef
name|_IOERR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IOERR
value|0x40
end_define

begin_comment
comment|/* i/o error on buffer */
end_comment

begin_define
define|#
directive|define
name|_IOLBF
value|0x80
end_define

begin_comment
comment|/* buffering is by line */
end_comment

begin_define
define|#
directive|define
name|_IORW
value|0x100
end_define

begin_comment
comment|/* read or write ok */
end_comment

begin_define
define|#
directive|define
name|_IOAPPEND
value|0x00
end_define

begin_comment
comment|/* not used in this version of stdio */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|hpux
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_IOSTRG
value|00000
end_define

begin_comment
comment|/* faked out for USG */
end_comment

begin_define
define|#
directive|define
name|_IOLBF
value|00200
end_define

begin_define
define|#
directive|define
name|_IORW
value|00400
end_define

begin_define
define|#
directive|define
name|_IOAPPEND
value|00000
end_define

begin_comment
comment|/* faked out for USG */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|VMS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_IOSTRG
value|0100
end_define

begin_comment
comment|/* Doing I/O to a string */
end_comment

begin_define
define|#
directive|define
name|_IORW
value|0200
end_define

begin_comment
comment|/* Open for read/write	 */
end_comment

begin_define
define|#
directive|define
name|_IOAPPEND
value|00
end_define

begin_comment
comment|/* VMS does not actually have this */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_IOSTRG
value|00100
end_define

begin_define
define|#
directive|define
name|_IOLBF
value|00200
end_define

begin_define
define|#
directive|define
name|_IORW
value|00400
end_define

begin_define
define|#
directive|define
name|_IOAPPEND
value|01000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX
end_ifdef

begin_define
define|#
directive|define
name|_IOPBF
value|00400
end_define

begin_comment
comment|/* Boolean - ungetc() not called since fill/flush */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

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
value|(--(p)->_cnt>=0?(int)(*(unsigned char*)(p)->_ptr++):_filbuf(p))
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
value|(--(p)->_cnt>=0? ((int)((unsigned char)((*(p)->_ptr++=(unsigned)(x))))):_flsbuf((unsigned)(x),p))
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
value|((p)->_file)
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|_IOFBF
end_undef

begin_define
define|#
directive|define
name|_IOLBF
value|1
end_define

begin_define
define|#
directive|define
name|_IOFBF
value|2
end_define

begin_define
define|#
directive|define
name|F_RDLCK
end_define

begin_comment
comment|/*	Also, stdin/stdout/stderr need to be defined  *	[We also use a hack here that makes the GCC assembler modify  *	 the psect attributes to match those of the VAX-11 "C" runtime]  */
end_comment

begin_define
define|#
directive|define
name|stdin
value|$$PsectAttributes_NOSHR$$stdin
end_define

begin_define
define|#
directive|define
name|stdout
value|$$PsectAttributes_NOSHR$$stdout
end_define

begin_define
define|#
directive|define
name|stderr
value|$$PsectAttributes_NOSHR$$stderr
end_define

begin_decl_stmt
specifier|extern
name|VMS_FILE
name|stdin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VMS_FILE
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VMS_FILE
name|stderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// 	Define the stdio macros
end_comment

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|p
parameter_list|)
value|fgetc(p)
end_define

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|fgetc(stdin)
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
value|fputc(x,p)
end_define

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|x
parameter_list|)
value|fputc(x,stdout)
end_define

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|p
parameter_list|)
value|(((*p)->_flag&_IOEOF)!=0)
end_define

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|p
parameter_list|)
value|(((*p)->_flag&_IOERR)!=0)
end_define

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|p
parameter_list|)
value|((*p)->_file)
end_define

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|p
parameter_list|)
value|((*p)->_flag&= ~(_IOERR|_IOEOF))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
block|{
ifdef|#
directive|ifdef
name|VMS
name|int
name|c$$doprint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|c$$doscan
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|c$$filbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|c$$flsbuf
parameter_list|(
name|unsigned
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
name|int
name|_doprnt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|_doscan
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
name|_filbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|_flsbuf
parameter_list|(
name|unsigned
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
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
name|int
name|fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|fgetc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|char
modifier|*
name|fgets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|fopen
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
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|int
name|fputc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|fputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|fread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|VMS
name|FILE
modifier|*
name|freopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
modifier|...
parameter_list|)
function_decl|;
else|#
directive|else
name|FILE
modifier|*
name|freopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|int
name|fscanf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|int
name|fseek
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|long
name|ftell
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|fwrite
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|char
modifier|*
name|gets
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|getw
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|popen
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
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|int
name|puts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|putw
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|rewind
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|int
name|setbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|setbuffer
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|setlinebuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|setvbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|sscanf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|tmpfile
parameter_list|()
function_decl|;
name|int
name|ungetc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|// Third arg to vprintf must be '...' for some machines,& doesn't
comment|// hurt for others.
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|SPRINTF_RETURNS_INT
name|int
name|sprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
else|#
directive|else
name|char
modifier|*
name|sprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|...
parameter_list|)
function_decl|;
name|char
modifier|*
name|vsprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
end_extern

begin_ifndef
ifndef|#
directive|ifndef
name|L_ctermid
end_ifndef

begin_define
define|#
directive|define
name|L_ctermid
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|L_cuserid
end_ifndef

begin_define
define|#
directive|define
name|L_cuserid
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|P_tmpdir
end_ifndef

begin_define
define|#
directive|define
name|P_tmpdir
value|"/tmp/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|L_tmpnam
end_ifndef

begin_define
define|#
directive|define
name|L_tmpnam
value|(sizeof(P_tmpdir) + 15)
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
comment|// _stdio_h
end_comment

end_unit

