begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)telextrn.h	4.2 (Berkeley) 4/26/91  */
end_comment

begin_comment
comment|/*  * Definitions of external routines and variables for tn3270  */
end_comment

begin_comment
comment|/*  * Pieces exported from the telnet susbsection.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
name|HaveInput
decl_stmt|,
endif|#
directive|endif
comment|/* defined(unix) */
name|tout
decl_stmt|,
name|tin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|transcom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netflush
argument_list|()
decl_stmt|,
name|quit
argument_list|()
decl_stmt|,
name|TtyChars
argument_list|()
decl_stmt|,
name|DataToTerminal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|outputPurge
argument_list|()
decl_stmt|,
name|EmptyTerminal
argument_list|()
decl_stmt|,
name|StringToTerminal
argument_list|()
decl_stmt|,
name|_putchar
argument_list|()
decl_stmt|,
name|ExitPerror
argument_list|()
decl_stmt|,
name|setcommandmode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Pieces exported from other random locations.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|()
function_decl|;
end_function_decl

end_unit

