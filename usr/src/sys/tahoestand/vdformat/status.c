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
literal|"@(#)status.c	1.3 (Berkeley/CCI) 6/7/88"
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

begin_comment
comment|/* **	These routines are used to display the status of the formatter. */
end_comment

begin_macro
name|status
argument_list|()
end_macro

begin_block
block|{
name|indent
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|cur
operator|.
name|state
condition|)
block|{
case|case
name|cmd
case|:
name|print
argument_list|(
literal|"Waiting for operator response.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|fmt
case|:
name|dump_state
argument_list|(
literal|"Formatting"
argument_list|)
expr_stmt|;
break|break;
case|case
name|vfy
case|:
name|dump_state
argument_list|(
literal|"Verifying"
argument_list|)
expr_stmt|;
break|break;
case|case
name|rel
case|:
name|dump_state
argument_list|(
literal|"Relocating"
argument_list|)
expr_stmt|;
break|break;
case|case
name|cor
case|:
name|dump_state
argument_list|(
literal|"Correcting"
argument_list|)
expr_stmt|;
break|break;
case|case
name|inf
case|:
name|dump_state
argument_list|(
literal|"Collecting information"
argument_list|)
expr_stmt|;
break|break;
case|case
name|exec
case|:
name|dump_state
argument_list|(
literal|"Exercising disk"
argument_list|)
expr_stmt|;
break|break;
case|case
name|setup
case|:
name|printf
argument_list|(
literal|"Initializing for operation "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"on controller %d, drive %d.\n"
argument_list|,
name|cur
operator|.
name|controller
argument_list|,
name|cur
operator|.
name|drive
argument_list|)
expr_stmt|;
default|default:
name|print
argument_list|(
literal|"Current state is unknown.\n"
argument_list|)
expr_stmt|;
block|}
name|exdent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ** */
end_comment

begin_macro
name|dump_state
argument_list|(
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|wait_for_char
decl_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|print
argument_list|(
literal|"%s on controller %d, drive %d.\n"
argument_list|,
name|string
argument_list|,
name|cur
operator|.
name|controller
argument_list|,
name|cur
operator|.
name|drive
argument_list|)
expr_stmt|;
if|if
condition|(
name|wait_for_char
condition|)
name|print
argument_list|(
literal|"Waiting for operator response.\n"
argument_list|)
expr_stmt|;
else|else
block|{
name|print
argument_list|(
literal|"Currently accessing cylinder %d, head %d.\n"
argument_list|,
name|cur
operator|.
name|daddr
operator|.
name|cylinder
argument_list|,
name|cur
operator|.
name|daddr
operator|.
name|track
argument_list|)
expr_stmt|;
name|print
argument_list|(
literal|"Currently "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cur
operator|.
name|substate
condition|)
block|{
case|case
name|sub_chk
case|:
name|printf
argument_list|(
literal|"determining drive state.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|sub_fmt
case|:
name|printf
argument_list|(
literal|"formatting drive surface.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|sub_vfy
case|:
name|printf
argument_list|(
literal|"verifying drive surface.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|sub_rel
case|:
name|printf
argument_list|(
literal|"performing relocation operations.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|sub_rcvr
case|:
name|printf
argument_list|(
literal|"recovering from hardware error.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|sub_wmap
case|:
name|printf
argument_list|(
literal|"writing relocation map.\n"
argument_list|)
expr_stmt|;
break|break;
default|default :
name|printf
argument_list|(
literal|"I don't know what is happening.\n"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|exdent
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

