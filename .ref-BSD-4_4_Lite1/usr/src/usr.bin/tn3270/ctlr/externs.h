begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)externs.h	8.1 (Berkeley) 6/6/93  */
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

