begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|Original
name|BTL
name|Ratfor
name|System
end_expr_stmt

begin_for
for|for 4.2
comment|/*	r.h	1.2	83/08/11	*/
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|"y.tab.h"
empty|#
define|#
directive|define
name|putbak
parameter_list|(
name|c
parameter_list|)
value|*ip++ = c
comment|/*	#define	getchr()	(ip>ibuf?*--ip: getc(infile[infptr]))	*/
define|#
directive|define
name|LET
value|1
define|#
directive|define
name|DIG
value|2
define|#
directive|define
name|CRAP
value|3
define|#
directive|define
name|COMMENT
value|'#'
define|#
directive|define
name|QUOTE
value|'"'
for|extern int	transfer
empty_stmt|;
end_for

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

