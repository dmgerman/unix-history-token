begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)externs.h	4.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * External references from the controller.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|access_api
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|movetous
argument_list|()
decl_stmt|,
name|movetothem
argument_list|()
decl_stmt|,
name|unaccess_api
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(MSDOS) */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|memNSchr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Search for a character ANDED, increment by stride */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|DataToNetwork
argument_list|()
decl_stmt|,
name|OutputClock
decl_stmt|,
name|suspend
argument_list|()
decl_stmt|,
name|TransparentClock
decl_stmt|,
name|UnLocked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyboard is UnLocked? */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|command
argument_list|()
decl_stmt|,
name|ConnectScreen
argument_list|()
decl_stmt|,
name|ExitString
argument_list|()
decl_stmt|,
name|init_inbound
argument_list|()
decl_stmt|,
name|LocalClearScreen
argument_list|()
decl_stmt|,
name|RefreshScreen
argument_list|()
decl_stmt|,
name|RingBell
argument_list|()
decl_stmt|,
name|setconnmode
argument_list|()
decl_stmt|,
name|StopScreen
argument_list|()
decl_stmt|,
name|TransOut
argument_list|()
decl_stmt|,
name|TransStop
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

