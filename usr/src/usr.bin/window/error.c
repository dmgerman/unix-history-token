begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)error.c	1.1 83/07/28"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_function_decl
name|struct
name|ww
modifier|*
name|openwin
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in source file */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source file name */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|ww
modifier|*
name|errwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* window for error reporting */
end_comment

begin_decl_stmt
specifier|static
name|int
name|errlineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lineno in errwin */
end_comment

begin_decl_stmt
specifier|static
name|char
name|baderror
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* can't open the error window */
end_comment

begin_define
define|#
directive|define
name|ERRLINES
value|10
end_define

begin_comment
comment|/* number of lines in errwin */
end_comment

begin_comment
comment|/*VARARGS1*/
end_comment

begin_macro
name|error
argument_list|(
argument|fmt
argument_list|,
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|,
argument|d
argument_list|,
argument|e
argument_list|,
argument|f
argument_list|,
argument|g
argument_list|,
argument|h
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|filename
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|terse
condition|)
name|Ding
argument_list|()
expr_stmt|;
else|else
block|{
name|wwprintf
argument_list|(
name|cmdwin
argument_list|,
name|fmt
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|f
argument_list|,
name|g
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|wwputs
argument_list|(
literal|"  "
argument_list|,
name|cmdwin
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
if|if
condition|(
name|baderror
condition|)
return|return;
if|if
condition|(
name|errwin
operator|==
literal|0
condition|)
block|{
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"Errors from %s"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|errwin
operator|=
name|openwin
argument_list|(
name|ERRLINES
argument_list|,
name|buf
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|wwprintf
argument_list|(
name|cmdwin
argument_list|,
literal|"Can't open error window.  "
argument_list|)
expr_stmt|;
name|baderror
operator|++
expr_stmt|;
return|return;
block|}
name|errlineno
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|errlineno
operator|++
operator|>
name|ERRLINES
operator|-
literal|4
condition|)
block|{
name|waitnl
argument_list|(
name|errwin
argument_list|)
expr_stmt|;
name|errlineno
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|lineno
operator|!=
literal|0
condition|)
name|wwprintf
argument_list|(
name|errwin
argument_list|,
literal|"line %d: "
argument_list|,
name|lineno
argument_list|)
expr_stmt|;
name|wwprintf
argument_list|(
name|errwin
argument_list|,
name|fmt
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|f
argument_list|,
name|g
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|wwprintf
argument_list|(
name|errwin
argument_list|,
literal|"\r\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|beginerror
argument_list|(
argument|fn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fn
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|filename
operator|=
name|fn
expr_stmt|;
block|}
end_block

begin_macro
name|enderror
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|errwin
operator|!=
literal|0
condition|)
block|{
name|waitnl
argument_list|(
name|errwin
argument_list|)
expr_stmt|;
name|closewin
argument_list|(
name|errwin
argument_list|)
expr_stmt|;
name|errwin
operator|=
literal|0
expr_stmt|;
block|}
name|baderror
operator|=
literal|0
expr_stmt|;
name|filename
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

