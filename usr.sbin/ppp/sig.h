begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997  *	Brian Somers<brian@awfulhak.demon.co.uk>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: sig.h,v 1.8 1997/06/09 03:27:37 brian Exp $  *  *  TODO:  *  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sig_type
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Call this instead of signal() */
end_comment

begin_function_decl
specifier|extern
name|sig_type
name|pending_signal
parameter_list|(
name|int
parameter_list|,
name|sig_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this when you want things to *actually* happen */
end_comment

begin_function_decl
specifier|extern
name|void
name|handle_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

