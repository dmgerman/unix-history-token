begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: erro.h,v 2.2 84/07/11 15:14:16 guido Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- User (error) messages collected together.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ERROR
end_ifndef

begin_define
define|#
directive|define
name|_ERROR
parameter_list|(
name|name
parameter_list|,
name|message
parameter_list|)
value|extern char name[]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|_ERROR
argument_list|(
name|COPY_EMPTY
argument_list|,
literal|"Empty copy buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|DEL_REM
argument_list|,
literal|"The remains wouldn't fit"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|EDIT_BAD
argument_list|,
literal|"Trouble reading your unit, see last line. Hit break if you don't want this"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|EDIT_TABS
argument_list|,
literal|"Spaces and tabs mixed for indentation; check your program layout"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|EXIT_HOLES
argument_list|,
literal|"There are still holes left.  Please fill or delete these first."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|GOTO_BAD
argument_list|,
literal|"Sorry -- bad reply from terminal for cursor sense"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|GOTO_NO
argument_list|,
literal|"Sorry -- your terminal does not support the control-G command"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|GOTO_OUT
argument_list|,
literal|"The cursor isn't pointing at a part of the buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|GOTO_REC
argument_list|,
literal|"You can't use control-G in recording mode (it wouldn't work in playback)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|GOTO_TAH
argument_list|,
literal|"Type-ahead lost"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|GOTO_TO
argument_list|,
literal|"Cursor sense time-out"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|INS_BAD
argument_list|,
literal|"Cannot insert '%c'"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|PLB_NOK
argument_list|,
literal|"No keystrokes recorded"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|REC_OK
argument_list|,
literal|"Keystrokes recorded, use control-P to play back"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_ERROR
argument_list|(
name|REDO_OLD
argument_list|,
literal|"This redo brought you to an older version.  Type backspace to undo"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

