begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"vchiq_connected.h"
end_include

begin_include
include|#
directive|include
file|"vchiq_core.h"
end_include

begin_define
define|#
directive|define
name|MAX_CALLBACKS
value|10
end_define

begin_decl_stmt
specifier|static
name|int
name|g_connected
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|g_num_deferred_callbacks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|VCHIQ_CONNECTED_CALLBACK_T
name|g_deferred_callback
index|[
name|MAX_CALLBACKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|g_once_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mutex
name|g_connected_mutex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**************************************************************************** * * Function to initialize our lock. * ***************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|connected_init
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|g_once_init
condition|)
block|{
name|lmutex_init
argument_list|(
operator|&
name|g_connected_mutex
argument_list|)
expr_stmt|;
name|g_once_init
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/**************************************************************************** * * This function is used to defer initialization until the vchiq stack is * initialized. If the stack is already initialized, then the callback will * be made immediately, otherwise it will be deferred until * vchiq_call_connected_callbacks is called. * ***************************************************************************/
end_comment

begin_function
name|void
name|vchiq_add_connected_callback
parameter_list|(
name|VCHIQ_CONNECTED_CALLBACK_T
name|callback
parameter_list|)
block|{
name|connected_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|lmutex_lock_interruptible
argument_list|(
operator|&
name|g_connected_mutex
argument_list|)
operator|!=
literal|0
condition|)
return|return;
if|if
condition|(
name|g_connected
condition|)
comment|/* We're already connected. Call the callback immediately. */
name|callback
argument_list|()
expr_stmt|;
else|else
block|{
if|if
condition|(
name|g_num_deferred_callbacks
operator|>=
name|MAX_CALLBACKS
condition|)
name|vchiq_log_error
argument_list|(
name|vchiq_core_log_level
argument_list|,
literal|"There are already %d callbacks registered - "
literal|"please increase MAX_CALLBACKS"
argument_list|,
name|g_num_deferred_callbacks
argument_list|)
expr_stmt|;
else|else
block|{
name|g_deferred_callback
index|[
name|g_num_deferred_callbacks
index|]
operator|=
name|callback
expr_stmt|;
name|g_num_deferred_callbacks
operator|++
expr_stmt|;
block|}
block|}
name|lmutex_unlock
argument_list|(
operator|&
name|g_connected_mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************** * * This function is called by the vchiq stack once it has been connected to * the videocore and clients can start to use the stack. * ***************************************************************************/
end_comment

begin_function
name|void
name|vchiq_call_connected_callbacks
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|connected_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|lmutex_lock_interruptible
argument_list|(
operator|&
name|g_connected_mutex
argument_list|)
operator|!=
literal|0
condition|)
return|return;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|g_num_deferred_callbacks
condition|;
name|i
operator|++
control|)
name|g_deferred_callback
index|[
name|i
index|]
operator|(
operator|)
expr_stmt|;
name|g_num_deferred_callbacks
operator|=
literal|0
expr_stmt|;
name|g_connected
operator|=
literal|1
expr_stmt|;
name|lmutex_unlock
argument_list|(
operator|&
name|g_connected_mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|vchiq_add_connected_callback
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

