begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../h/config.h"
end_include

begin_comment
comment|/*  * external definitions needed throughout translator  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yychar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parser's current input token type */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yynerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors in parse */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fatalerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of fatal errors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of warnings */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nocode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true to suppress code generation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|implicit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* implicit local/error */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|silence
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbose/mute switch */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial setting of&trace */
end_comment

begin_extern
extern|extern int
specifier|inline
namespace|;
comment|/* current line number in input */
namespace|extern
name|int
name|tline
namespace|;
end_extern

begin_comment
comment|/* line number of current token */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|incol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current column number in input */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column number of current token */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peekc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one character look-ahead */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ctran
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input translation table */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|esctab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string literal escape table */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|codefile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current icode output file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|globfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current global output file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|filep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of input file names */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alclflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counter for local table overflow */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alcgflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counter for global table overflow */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alccflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* counter for constant table overflow */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string space */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|send
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pointer for string space */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ssize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial size of string space */
end_comment

end_unit

