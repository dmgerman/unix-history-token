begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)fio.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
name|long
name|ftnint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ftnint
name|flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ftnlen
typedef|;
end_typedef

begin_comment
comment|/*external read, write*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|cierr
decl_stmt|;
name|ftnint
name|ciunit
decl_stmt|;
name|flag
name|ciend
decl_stmt|;
name|char
modifier|*
name|cifmt
decl_stmt|;
name|ftnint
name|cirec
decl_stmt|;
block|}
name|cilist
typedef|;
end_typedef

begin_comment
comment|/*internal read, write*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|icierr
decl_stmt|;
name|char
modifier|*
name|iciunit
decl_stmt|;
name|flag
name|iciend
decl_stmt|;
name|char
modifier|*
name|icifmt
decl_stmt|;
name|ftnint
name|icirlen
decl_stmt|;
name|ftnint
name|icirnum
decl_stmt|;
block|}
name|icilist
typedef|;
end_typedef

begin_comment
comment|/*open*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|oerr
decl_stmt|;
name|ftnint
name|ounit
decl_stmt|;
name|char
modifier|*
name|ofnm
decl_stmt|;
name|ftnlen
name|ofnmlen
decl_stmt|;
name|char
modifier|*
name|osta
decl_stmt|;
name|char
modifier|*
name|oacc
decl_stmt|;
name|char
modifier|*
name|ofm
decl_stmt|;
name|ftnint
name|orl
decl_stmt|;
name|char
modifier|*
name|oblnk
decl_stmt|;
block|}
name|olist
typedef|;
end_typedef

begin_comment
comment|/*close*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|cerr
decl_stmt|;
name|ftnint
name|cunit
decl_stmt|;
name|char
modifier|*
name|csta
decl_stmt|;
block|}
name|cllist
typedef|;
end_typedef

begin_comment
comment|/*rewind, backspace, endfile*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|aerr
decl_stmt|;
name|ftnint
name|aunit
decl_stmt|;
block|}
name|alist
typedef|;
end_typedef

begin_comment
comment|/*units*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FILE
modifier|*
name|ufd
decl_stmt|;
comment|/*0=unconnected*/
name|char
modifier|*
name|ufnm
decl_stmt|;
name|long
name|uinode
decl_stmt|;
name|int
name|url
decl_stmt|;
comment|/*0=sequential*/
name|flag
name|useek
decl_stmt|;
comment|/*true=can backspace, use dir, ...*/
name|flag
name|ufmt
decl_stmt|;
name|flag
name|uprnt
decl_stmt|;
name|flag
name|ublnk
decl_stmt|;
name|flag
name|uend
decl_stmt|;
name|flag
name|uwrt
decl_stmt|;
comment|/*last io was write*/
name|flag
name|uscrtch
decl_stmt|;
block|}
name|unit
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|inerr
decl_stmt|;
name|ftnint
name|inunit
decl_stmt|;
name|char
modifier|*
name|infile
decl_stmt|;
name|ftnlen
name|infilen
decl_stmt|;
name|ftnint
modifier|*
name|inex
decl_stmt|;
comment|/*parameters in standard's order*/
name|ftnint
modifier|*
name|inopen
decl_stmt|;
name|ftnint
modifier|*
name|innum
decl_stmt|;
name|ftnint
modifier|*
name|innamed
decl_stmt|;
name|char
modifier|*
name|inname
decl_stmt|;
name|ftnlen
name|innamlen
decl_stmt|;
name|char
modifier|*
name|inacc
decl_stmt|;
name|ftnlen
name|inacclen
decl_stmt|;
name|char
modifier|*
name|inseq
decl_stmt|;
name|ftnlen
name|inseqlen
decl_stmt|;
name|char
modifier|*
name|indir
decl_stmt|;
name|ftnlen
name|indirlen
decl_stmt|;
name|char
modifier|*
name|infmt
decl_stmt|;
name|ftnlen
name|infmtlen
decl_stmt|;
name|char
modifier|*
name|inform
decl_stmt|;
name|ftnint
name|informlen
decl_stmt|;
name|char
modifier|*
name|inunf
decl_stmt|;
name|ftnlen
name|inunflen
decl_stmt|;
name|ftnint
modifier|*
name|inrecl
decl_stmt|;
name|ftnint
modifier|*
name|innrec
decl_stmt|;
name|char
modifier|*
name|inblank
decl_stmt|;
name|ftnlen
name|inblanklen
decl_stmt|;
block|}
name|inlist
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flag
name|init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cilist
modifier|*
name|elist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*active external io list*/
end_comment

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
comment|/*current file*/
end_comment

begin_decl_stmt
specifier|extern
name|unit
modifier|*
name|curunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current unit*/
end_comment

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

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
value|{if(f) errno= n; else fatal(n,s); return(n);}
end_define

begin_comment
comment|/*Table sizes*/
end_comment

begin_define
define|#
directive|define
name|MXUNIT
value|10
end_define

begin_decl_stmt
specifier|extern
name|int
name|recpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*position in current record*/
end_comment

end_unit

