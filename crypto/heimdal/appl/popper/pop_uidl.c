begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<popper.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: pop_uidl.c,v 1.9 1999/12/02 16:58:33 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|UIDL
end_ifdef

begin_comment
comment|/*   *  uidl:   Uidl the contents of a POP maildrop  */
end_comment

begin_function
name|int
name|pop_uidl
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
block|{
name|MsgInfoList
modifier|*
name|mp
decl_stmt|;
comment|/*  Pointer to message info list */
name|int
name|i
decl_stmt|;
name|int
name|msg_num
decl_stmt|;
comment|/*  Was a message number provided? */
if|if
condition|(
name|p
operator|->
name|parm_count
operator|>
literal|0
condition|)
block|{
name|msg_num
operator|=
name|atoi
argument_list|(
name|p
operator|->
name|pop_parm
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/*  Is requested message out of range? */
if|if
condition|(
operator|(
name|msg_num
operator|<
literal|1
operator|)
operator|||
operator|(
name|msg_num
operator|>
name|p
operator|->
name|msg_count
operator|)
condition|)
return|return
operator|(
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_FAILURE
argument_list|,
literal|"Message %d does not exist."
argument_list|,
name|msg_num
argument_list|)
operator|)
return|;
comment|/*  Get a pointer to the message in the message list */
name|mp
operator|=
operator|&
name|p
operator|->
name|mlp
index|[
name|msg_num
operator|-
literal|1
index|]
expr_stmt|;
comment|/*  Is the message already flagged for deletion? */
if|if
condition|(
name|mp
operator|->
name|flags
operator|&
name|DEL_FLAG
condition|)
return|return
operator|(
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_FAILURE
argument_list|,
literal|"Message %d has been deleted."
argument_list|,
name|msg_num
argument_list|)
operator|)
return|;
comment|/*  Display message information */
return|return
operator|(
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_SUCCESS
argument_list|,
literal|"%u %s"
argument_list|,
name|msg_num
argument_list|,
name|mp
operator|->
name|msg_id
argument_list|)
operator|)
return|;
block|}
comment|/*  Display the entire list of messages */
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_SUCCESS
argument_list|,
literal|"%d messages (%ld octets)"
argument_list|,
name|p
operator|->
name|msg_count
operator|-
name|p
operator|->
name|msgs_deleted
argument_list|,
name|p
operator|->
name|drop_size
operator|-
name|p
operator|->
name|bytes_deleted
argument_list|)
expr_stmt|;
comment|/*  Loop through the message information list.  Skip deleted messages */
for|for
control|(
name|i
operator|=
name|p
operator|->
name|msg_count
operator|,
name|mp
operator|=
name|p
operator|->
name|mlp
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
operator|,
name|mp
operator|++
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|mp
operator|->
name|flags
operator|&
name|DEL_FLAG
operator|)
condition|)
name|fprintf
argument_list|(
name|p
operator|->
name|output
argument_list|,
literal|"%u %s\r\n"
argument_list|,
name|mp
operator|->
name|number
argument_list|,
name|mp
operator|->
name|msg_id
argument_list|)
expr_stmt|;
block|}
comment|/*  "." signals the end of a multi-line transmission */
name|fprintf
argument_list|(
name|p
operator|->
name|output
argument_list|,
literal|".\r\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|p
operator|->
name|output
argument_list|)
expr_stmt|;
return|return
operator|(
name|POP_SUCCESS
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UIDL */
end_comment

end_unit

