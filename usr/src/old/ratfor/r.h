begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  *  *	@(#)r.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_empty
empty|#
end_empty

begin_define
define|#
directive|define
name|putbak
parameter_list|(
name|c
parameter_list|)
value|*ip++ = c
end_define

begin_comment
comment|/*	#define	getchr()	(ip>ibuf?*--ip: getc(infile[infptr]))	*/
end_comment

begin_define
define|#
directive|define
name|LET
value|1
end_define

begin_define
define|#
directive|define
name|DIG
value|2
end_define

begin_define
define|#
directive|define
name|CRAP
value|3
end_define

begin_define
define|#
directive|define
name|COMMENT
value|'#'
end_define

begin_define
define|#
directive|define
name|QUOTE
value|'"'
end_define

begin_decl_stmt
specifier|extern
name|int
name|transfer
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INDENT
value|3
end_define

begin_comment
comment|/* indent delta */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|gcos
end_ifdef

begin_define
define|#
directive|define
name|CONTFLD
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_define
define|#
directive|define
name|CONTFLD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|contfld
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column for continuation char */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|contchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|yypv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errorflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|comment
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save input comments here */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|comptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next free slot in comment */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|printcom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print comments, etc., if on */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|indent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* level of nesting for indenting */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ibuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outfil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file id */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|infptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linect
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|fcname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|svargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|svargv
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EOS
value|0
end_define

begin_define
define|#
directive|define
name|HSHSIZ
value|101
end_define

begin_struct
struct|struct
name|nlist
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|def
decl_stmt|;
name|int
name|ydef
decl_stmt|;
name|struct
name|nlist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|nlist
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|install
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fcnloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|type
index|[]
decl_stmt|;
end_decl_stmt

end_unit

