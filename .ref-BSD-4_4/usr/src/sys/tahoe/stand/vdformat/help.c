begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)help.c	1.1 (Berkeley/CCI) 7/5/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"vdfmt.h"
end_include

begin_include
include|#
directive|include
file|"cmd.h"
end_include

begin_comment
comment|/* **	These routines are used to display all the system help messages ** that the operator requests.  They look through the system command  ** tables to print the commands and the help messages in a neat mannor. ** **	The only break in this rule is the help processor for digit entry ** Which informs the operator what numeric range is valid. */
end_comment

begin_macro
name|help_text
argument_list|(
argument|tbl
argument_list|)
end_macro

begin_decl_stmt
name|cmd_text_element
modifier|*
name|tbl
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|indent
argument_list|()
expr_stmt|;
name|print_common_help
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
while|while
condition|(
name|tbl
operator|->
name|cmd_token
operator|!=
literal|0
condition|)
block|{
specifier|register
name|int
name|count
decl_stmt|;
name|count
operator|=
literal|9
operator|-
name|strlen
argument_list|(
name|tbl
operator|->
name|cmd_text
argument_list|)
expr_stmt|;
name|print
argument_list|(
literal|"%s"
argument_list|,
name|tbl
operator|->
name|cmd_text
argument_list|)
expr_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"- %s.\n"
argument_list|,
name|tbl
operator|->
name|cmd_help
argument_list|)
expr_stmt|;
name|tbl
operator|++
expr_stmt|;
block|}
name|exdent
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|print
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ** */
end_comment

begin_macro
name|print_common_help
argument_list|()
end_macro

begin_block
block|{
name|print
argument_list|(
literal|"The following commands are available:\n"
argument_list|)
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|print
argument_list|(
literal|"%s - %s.\n"
argument_list|,
literal|"KILL    "
argument_list|,
literal|"Abort all operations"
argument_list|)
expr_stmt|;
name|print
argument_list|(
literal|"%s - %s.\n"
argument_list|,
literal|"STATus  "
argument_list|,
literal|"Display formatter state"
argument_list|)
expr_stmt|;
name|exdent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

