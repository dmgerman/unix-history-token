begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *  panic.h -  header for at(1)  *  Copyright (C) 1993  Thomas Koenig  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author(s) may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|__NORETURN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
ifdef|#
directive|ifdef
name|__GNUC__
name|__NORETURN
endif|#
directive|endif
name|panic
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
ifdef|#
directive|ifdef
name|__GNUC__
name|__NORETURN
endif|#
directive|endif
name|perr
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
ifdef|#
directive|ifdef
name|__GNUC__
name|__NORETURN
endif|#
directive|endif
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

