begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/adlib_card.c  *   * Detection routine for the AdLib card.  *   * Copyright by Hannu Savolainen 1993  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/sound/sound_config.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONFIG_YM3812
argument_list|)
end_if

begin_function
name|void
name|attach_adlib_card
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
name|opl3_init
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
name|hw_config
operator|->
name|osp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|probe_adlib
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
return|return
name|opl3_detect
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
name|hw_config
operator|->
name|osp
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

