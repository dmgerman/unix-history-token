begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Joerg Wunsch  *  * All rights reserved.  *  * This program is free software.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Joerg Wunsch  * 4. The name of the developer may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* the V7-style interface to modify the terminals characteristics */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* these functions are just in case someone even did not get the macros... */
end_comment

begin_undef
undef|#
directive|undef
name|stty
end_undef

begin_undef
undef|#
directive|undef
name|gtty
end_undef

begin_function
name|int
if|#
directive|if
name|__STDC__
name|stty
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|sgttyb
modifier|*
name|s
parameter_list|)
else|#
directive|else
function|stty
parameter_list|(
name|fd
parameter_list|,
name|s
parameter_list|)
name|int
name|fd
decl_stmt|;
name|struct
name|sgttyb
modifier|*
name|s
decl_stmt|;
endif|#
directive|endif
block|{
return|return
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSETP
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

begin_function
name|int
if|#
directive|if
name|__STDC__
name|gtty
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|sgttyb
modifier|*
name|s
parameter_list|)
else|#
directive|else
function|gtty
parameter_list|(
name|fd
parameter_list|,
name|s
parameter_list|)
name|int
name|fd
decl_stmt|;
name|struct
name|sgttyb
modifier|*
name|s
decl_stmt|;
endif|#
directive|endif
block|{
return|return
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCGETP
argument_list|,
name|s
argument_list|)
return|;
block|}
end_function

end_unit

