begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1993 John Brezak  *  All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may be used to endorse or promote products  *     derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR `AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: insque.c,v 1.2 1993/08/13 12:54:10 brezak Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_struct
struct|struct
name|qelem
block|{
name|struct
name|qelem
modifier|*
name|q_forw
decl_stmt|;
name|struct
name|qelem
modifier|*
name|q_back
decl_stmt|;
name|char
modifier|*
name|q_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Link p before s.  */
end_comment

begin_define
define|#
directive|define
name|reque
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|(p)->q_forw = (s), (s)->q_back = (p)
end_define

begin_comment
comment|/*  * Insert entry in circular queue after pred.  */
end_comment

begin_function
name|struct
name|qelem
modifier|*
name|insque
parameter_list|(
name|entry
parameter_list|,
name|pred
parameter_list|)
name|struct
name|qelem
modifier|*
name|entry
decl_stmt|,
decl|*
name|pred
decl_stmt|;
end_function

begin_block
block|{
name|reque
argument_list|(
name|entry
argument_list|,
name|pred
operator|->
name|q_forw
argument_list|)
expr_stmt|;
name|reque
argument_list|(
name|pred
argument_list|,
name|entry
argument_list|)
expr_stmt|;
return|return
operator|(
name|entry
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Remove entry from circular queue.  */
end_comment

begin_function
name|struct
name|qelem
modifier|*
name|remque
parameter_list|(
name|entry
parameter_list|)
name|struct
name|qelem
modifier|*
name|entry
decl_stmt|;
block|{
name|reque
argument_list|(
name|entry
operator|->
name|q_back
argument_list|,
name|entry
operator|->
name|q_forw
argument_list|)
expr_stmt|;
return|return
operator|(
name|entry
operator|)
return|;
block|}
end_function

end_unit

