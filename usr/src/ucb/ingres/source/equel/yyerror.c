begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"constants.h"
end_include

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)yyerror.c
literal|7.2
literal|4
argument|/
literal|7
argument|/
literal|82
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|int
name|Exit_val
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value to exit with */
end_comment

begin_comment
comment|/* **  YYERROR -- Yacc error reporting routine. **	Yyerror reports on syntax errors encountered by  **	the yacc parser. Also increments Exit_val. ** **	Parameters: **		s -- a string explaining the error ** **	Returns: **		none */
end_comment

begin_macro
name|yyerror
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|file_spec
argument_list|()
expr_stmt|;
if|if
condition|(
name|yychar
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"EOF = "
argument_list|)
expr_stmt|;
if|if
condition|(
name|yylval
operator|.
name|u_dn
condition|)
name|printf
argument_list|(
literal|"'%s' : "
argument_list|,
name|yylval
operator|.
name|u_dn
operator|->
name|d_elm
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"line %d, %s\n"
argument_list|,
name|yyline
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|Exit_val
operator|++
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  YYSEMERR -- scanner error reporter **		Also increments Error_val. ** **	Parameters: **		s -- string explaining the error **		i -- if !0 a string which caused the error ** **	Returns: **		none ** **	Called By: **		lexical analysis routines -- if called from somewhere else, **			the line number is likely to be wrong. */
end_comment

begin_macro
name|yysemerr
argument_list|(
argument|s
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|file_spec
argument_list|()
expr_stmt|;
if|if
condition|(
name|i
condition|)
name|printf
argument_list|(
literal|"'%s' : "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"line %d, %s\n"
argument_list|,
name|yyline
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|Exit_val
operator|++
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  YYSERROR -- Semantic error reportin routine **	reports on an error on an entry in the symbol space, **	using the line number built into the entry. Increments **	Exit_val. ** **	Parameters: **		s -- a string explaining the error **		d -- a symbol space node ** **	Returns: **		none ** **	Called By: **		semantic productions */
end_comment

begin_macro
name|yyserror
argument_list|(
argument|s
argument_list|,
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|disp_node
modifier|*
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|file_spec
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"'%s' : line %d, %s\n"
argument_list|,
name|d
operator|->
name|d_elm
argument_list|,
name|d
operator|->
name|d_line
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|Exit_val
operator|++
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  FILE_SPEC -- If in an included file, specify the name of that file. */
end_comment

begin_macro
name|file_spec
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|Inc_files
condition|)
name|printf
argument_list|(
literal|"** %s : "
argument_list|,
name|Input_file_name
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

