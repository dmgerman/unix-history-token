begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)fio.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_comment
comment|/*  * f77 file i/o common definitions  */
end_comment

begin_include
include|#
directive|include
file|"fiodefs.h"
end_include

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_define
define|#
directive|define
name|err
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|)
value|{if(f) return(errno=n); else fatal(n,s);}
end_define

begin_define
define|#
directive|define
name|not_legal
parameter_list|(
name|u
parameter_list|)
value|(u>=MXUNIT || u<0)
end_define

begin_define
define|#
directive|define
name|GET
parameter_list|(
name|x
parameter_list|)
value|if((x=(*getn)())<0) return(x)
end_define

begin_define
define|#
directive|define
name|VAL
parameter_list|(
name|x
parameter_list|)
value|(x!='\n'?x:' ')
end_define

begin_define
define|#
directive|define
name|PUT
parameter_list|(
name|x
parameter_list|)
value|{if(n=(*putn)(x)) return(n);}
end_define

begin_define
define|#
directive|define
name|lcase
parameter_list|(
name|s
parameter_list|)
value|((s>= 'A')&& (s<= 'Z') ? s+('a'-'A') : s)
end_define

begin_define
define|#
directive|define
name|MAXINTLENGTH
value|32
end_define

begin_comment
comment|/* to accomodate binary format */
end_comment

begin_function_decl
name|long
name|ftell
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ioflag
name|init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|reading
decl_stmt|,
name|external
decl_stmt|,
name|sequential
decl_stmt|,
name|formatted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|getn
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|putn
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|ungetn
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*for formatted io*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|cf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current file structure*/
end_comment

begin_decl_stmt
specifier|extern
name|unit
modifier|*
name|curunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current unit structure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current logical unit*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lfname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current filename*/
end_comment

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*logical units table*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|recpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*position in current record*/
end_comment

begin_decl_stmt
specifier|extern
name|ftnint
name|recnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current record number*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reclen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current record length */
end_comment

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|doed
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|doned
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
argument_list|(
operator|*
name|dorevert
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|donewrec
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|doend
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|dotab
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ioflag
name|cblank
decl_stmt|,
name|cplus
decl_stmt|,
name|tab
decl_stmt|,
name|elist
decl_stmt|,
name|signit
decl_stmt|,
name|errflag
decl_stmt|,
name|endflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fmtbuf
decl_stmt|,
modifier|*
name|icptr
decl_stmt|,
modifier|*
name|icend
decl_stmt|,
modifier|*
name|fmtptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|radix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ioiflg
name|ioiflg_
decl_stmt|;
end_decl_stmt

end_unit

