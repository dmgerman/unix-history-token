begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  *  *	@(#)refer..c	4.5 (Berkeley) 4/18/91  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|FLAG
value|003
end_define

begin_define
define|#
directive|define
name|AFLAG
value|007
end_define

begin_define
define|#
directive|define
name|NRFTXT
value|10000
end_define

begin_define
define|#
directive|define
name|NRFTBL
value|500
end_define

begin_define
define|#
directive|define
name|NTFILE
value|20
end_define

begin_define
define|#
directive|define
name|QLEN
value|512
end_define

begin_define
define|#
directive|define
name|ANSLEN
value|1024
end_define

begin_define
define|#
directive|define
name|TAGLEN
value|400
end_define

begin_define
define|#
directive|define
name|NSERCH
value|20
end_define

begin_define
define|#
directive|define
name|MXSIG
value|200
end_define

begin_comment
comment|/* max bytes in aggregate signal */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|endpush
decl_stmt|,
name|sort
decl_stmt|,
name|labels
decl_stmt|,
name|keywant
decl_stmt|,
name|bare
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|biblio
decl_stmt|,
name|science
decl_stmt|,
name|postpunct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|smallcaps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|comname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|keystr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|convert
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authrev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nmlen
decl_stmt|,
name|dtlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rdata
index|[]
decl_stmt|,
modifier|*
modifier|*
name|search
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|refnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|reftable
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rtp
decl_stmt|,
name|reftext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|gfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ofile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hidenam
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Ifile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Iline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fo
decl_stmt|,
modifier|*
name|ftemp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input
argument_list|()
decl_stmt|,
modifier|*
name|lookat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|class
argument_list|()
decl_stmt|,
modifier|*
name|caps
argument_list|()
decl_stmt|,
modifier|*
name|revauth
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|artskp
argument_list|()
decl_stmt|,
modifier|*
name|fpar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|trimnl
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

