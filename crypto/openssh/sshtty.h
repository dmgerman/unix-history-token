begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: sshtty.h,v 1.1 2001/04/14 16:33:20 stevesk Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  * Copyright (c) 2001 Kevin Steves.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSHTTY_H
end_ifndef

begin_define
define|#
directive|define
name|SSHTTY_H
end_define

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/*  * Accessor function indicating whether we are in raw mode.  Set by  * enter_raw_mode() and leave_raw_mode().  */
end_comment

begin_function_decl
name|int
name|in_raw_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return terminal modes, as saved by enter_raw_mode().  */
end_comment

begin_function_decl
name|struct
name|termios
name|get_saved_tio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the user's terminal to normal mode if it had been  * put in raw mode.  */
end_comment

begin_function_decl
name|void
name|leave_raw_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Puts the user's terminal in raw mode.  */
end_comment

begin_function_decl
name|void
name|enter_raw_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

