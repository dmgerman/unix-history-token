begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* sccsid[] = "@(#)h00vars.h 1.11 4/7/87"; */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_define
define|#
directive|define
name|PXPFILE
value|"pmon.out"
end_define

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_define
define|#
directive|define
name|BITSPERLONG
value|(BITSPERBYTE * sizeof(long))
end_define

begin_define
define|#
directive|define
name|LG2BITSBYTE
value|03
end_define

begin_define
define|#
directive|define
name|MSKBITSBYTE
value|07
end_define

begin_define
define|#
directive|define
name|LG2BITSLONG
value|05
end_define

begin_define
define|#
directive|define
name|MSKBITSLONG
value|037
end_define

begin_define
define|#
directive|define
name|HZ
value|60
end_define

begin_define
define|#
directive|define
name|MAXLVL
value|20
end_define

begin_define
define|#
directive|define
name|MAXERRS
value|75
end_define

begin_define
define|#
directive|define
name|NAMSIZ
value|76
end_define

begin_define
define|#
directive|define
name|MAXFILES
value|32
end_define

begin_define
define|#
directive|define
name|PREDEF
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|tahoe
end_ifndef

begin_define
define|#
directive|define
name|STDLVL
value|((struct iorec *)(0x7ffffff1))
end_define

begin_define
define|#
directive|define
name|GLVL
value|((struct iorec *)(0x7ffffff0))
end_define

begin_else
else|#
directive|else
else|tahoe
end_else

begin_define
define|#
directive|define
name|STDLVL
value|((struct iorec *)(0xbffffff1))
end_define

begin_define
define|#
directive|define
name|GLVL
value|((struct iorec *)(0xbffffff0))
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|STDLVL
value|((struct iorec *)(0xfff1))
end_define

begin_define
define|#
directive|define
name|GLVL
value|((struct iorec *)(0xfff0))
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

begin_define
define|#
directive|define
name|FILNIL
value|((struct iorec *)(0))
end_define

begin_define
define|#
directive|define
name|INPUT
value|((struct iorec *)(&input))
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|((struct iorec *)(&output))
end_define

begin_define
define|#
directive|define
name|ERR
value|((struct iorec *)(&_err))
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|FALSE
block|,
name|TRUE
block|}
name|bool
typedef|;
end_typedef

begin_comment
comment|/*  * runtime display structure  */
end_comment

begin_struct
struct|struct
name|display
block|{
name|char
modifier|*
name|ap
decl_stmt|;
name|char
modifier|*
name|fp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * formal routine structure  */
end_comment

begin_struct
struct|struct
name|formalrtn
block|{
name|long
function_decl|(
modifier|*
name|fentryaddr
function_decl|)
parameter_list|()
function_decl|;
comment|/* formal entry point */
name|long
name|fbn
decl_stmt|;
comment|/* block number of function */
name|struct
name|display
name|fdisp
index|[
name|MAXLVL
index|]
decl_stmt|;
comment|/* saved at first passing */
block|}
struct|;
end_struct

begin_comment
comment|/*  * program variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|display
name|_disply
index|[
name|MAXLVL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* runtime display */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_argc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of passed args */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|_argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* values of passed args */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_stlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statement limit */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_stcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statement count */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_seed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* random number seed */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_maxptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum valid pointer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_minptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum valid pointer */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_pcpcount
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pxp buffer */
end_comment

begin_comment
comment|/*  * file structures  */
end_comment

begin_struct
struct|struct
name|iorechd
block|{
name|char
modifier|*
name|fileptr
decl_stmt|;
comment|/* ptr to file window */
name|long
name|lcount
decl_stmt|;
comment|/* number of lines printed */
name|long
name|llimit
decl_stmt|;
comment|/* maximum number of text lines */
name|FILE
modifier|*
name|fbuf
decl_stmt|;
comment|/* FILE ptr */
name|struct
name|iorec
modifier|*
name|fchain
decl_stmt|;
comment|/* chain to next file */
name|struct
name|iorec
modifier|*
name|flev
decl_stmt|;
comment|/* ptr to associated file variable */
name|char
modifier|*
name|pfname
decl_stmt|;
comment|/* ptr to name of file */
name|short
name|funit
decl_stmt|;
comment|/* file status flags */
name|unsigned
name|short
name|fblk
decl_stmt|;
comment|/* index into active file table */
name|long
name|fsize
decl_stmt|;
comment|/* size of elements in the file */
name|char
name|fname
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* name of associated UNIX file */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iorec
block|{
name|char
modifier|*
name|fileptr
decl_stmt|;
comment|/* ptr to file window */
name|long
name|lcount
decl_stmt|;
comment|/* number of lines printed */
name|long
name|llimit
decl_stmt|;
comment|/* maximum number of text lines */
name|FILE
modifier|*
name|fbuf
decl_stmt|;
comment|/* FILE ptr */
name|struct
name|iorec
modifier|*
name|fchain
decl_stmt|;
comment|/* chain to next file */
name|struct
name|iorec
modifier|*
name|flev
decl_stmt|;
comment|/* ptr to associated file variable */
name|char
modifier|*
name|pfname
decl_stmt|;
comment|/* ptr to name of file */
name|short
name|funit
decl_stmt|;
comment|/* file status flags */
name|unsigned
name|short
name|fblk
decl_stmt|;
comment|/* index into active file table */
name|long
name|fsize
decl_stmt|;
comment|/* size of elements in the file */
name|char
name|fname
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* name of associated UNIX file */
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* I/O buffer */
name|char
name|window
index|[
literal|1
index|]
decl_stmt|;
comment|/* file window element */
block|}
struct|;
end_struct

begin_comment
comment|/*  * unit flags  */
end_comment

begin_define
define|#
directive|define
name|SPEOLN
value|0x100
end_define

begin_comment
comment|/* 1 => pseudo EOLN char read at EOF */
end_comment

begin_define
define|#
directive|define
name|FDEF
value|0x080
end_define

begin_comment
comment|/* 1 => reserved file name */
end_comment

begin_define
define|#
directive|define
name|FTEXT
value|0x040
end_define

begin_comment
comment|/* 1 => text file, process EOLN */
end_comment

begin_define
define|#
directive|define
name|FWRITE
value|0x020
end_define

begin_comment
comment|/* 1 => open for writing */
end_comment

begin_define
define|#
directive|define
name|FREAD
value|0x010
end_define

begin_comment
comment|/* 1 => open for reading */
end_comment

begin_define
define|#
directive|define
name|TEMP
value|0x008
end_define

begin_comment
comment|/* 1 => temporary file */
end_comment

begin_define
define|#
directive|define
name|SYNC
value|0x004
end_define

begin_comment
comment|/* 1 => window is out of sync */
end_comment

begin_define
define|#
directive|define
name|EOLN
value|0x002
end_define

begin_comment
comment|/* 1 => at end of line */
end_comment

begin_define
define|#
directive|define
name|EOFF
value|0x001
end_define

begin_comment
comment|/* 1 => at end of file */
end_comment

begin_comment
comment|/*  * file routines  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|iorec
modifier|*
name|GETNAME
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|MKTEMP
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|PALLOC
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * file record variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|_fchain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of active file chain */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iorec
modifier|*
name|_actfile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of active files */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_filefre
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last used entry in _actfile */
end_comment

begin_comment
comment|/*  * standard files  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|iorechd
name|_err
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * seek pointer struct for TELL, SEEK extensions  */
end_comment

begin_struct
struct|struct
name|seekptr
block|{
name|long
name|cnt
decl_stmt|;
block|}
struct|;
end_struct

end_unit

