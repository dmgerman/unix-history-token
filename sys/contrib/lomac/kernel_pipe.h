begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL_PIPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_KERNEL_PIPE_H_
end_define

begin_comment
comment|/******************************************************************  *  * kernel_pipe.h  *  * LOMAC - Low Water-Mark Mandatory Access Control  * Copyright (c) 1999-2001 Networks Associates, Inc.  All rights reserved.  *  *   Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  *   *   Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in the  *   documentation and/or other materials provided with the distribution.  *   *   Neither the name of NAI Labs, Inc. nor the names of its contributors  *   may be used to endorse or promote products derived from this software  *   without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Id: kernel_pipe.h,v 1.1 2001/09/20 21:29:21 tfraser Exp $  *  * Public interface to kernel_pipe.c, the part of the LOMAC kernel  * interface that takes control of operations on unnamed pipes.  *  */
end_comment

begin_function_decl
name|int
name|lomac_initialize_pipes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lomac_uninitialize_pipes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL_PIPE_H_ */
end_comment

end_unit

