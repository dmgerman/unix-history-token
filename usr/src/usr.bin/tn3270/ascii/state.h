begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)state.h	4.2 (Berkeley) 4/26/91  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_STATE
end_define

begin_comment
comment|/* this defines the state structure used by the key mapping routines */
end_comment

begin_define
define|#
directive|define
name|STATE_NULL
value|-1
end_define

begin_comment
comment|/* Falls off edge */
end_comment

begin_define
define|#
directive|define
name|STATE_GOTO
value|-2
end_define

begin_comment
comment|/* GOTO internal state */
end_comment

begin_define
define|#
directive|define
name|state
value|struct State
end_define

begin_struct
struct|struct
name|State
block|{
name|int
name|match
decl_stmt|;
comment|/* character to match */
name|int
name|result
decl_stmt|;
comment|/* 3270 control code */
name|state
modifier|*
name|next
decl_stmt|;
comment|/* next entry in this same state */
name|state
modifier|*
name|address
decl_stmt|;
comment|/* if goto, where is next state */
block|}
struct|;
end_struct

end_unit

