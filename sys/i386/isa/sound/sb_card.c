begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/sb_card.c  *   * Detection routine for the SoundBlaster cards.  *   * Copyright by Hannu Savolainen 1993  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met: 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer. 2.  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * Modified: Riccardo Facchetti  24 Mar 1995 - Added the Audio Excel DSP 16  * initialization routine.  *  * Major code cleanup - Luigi Rizzo (luigi@iet.unipi.it) 970711  */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/sound/sound_config.h>
end_include

begin_if
if|#
directive|if
name|NSB
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<i386/isa/sound/sbcard.h>
end_include

begin_function
name|void
name|attach_sb_card
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|CONFIG_AUDIO
argument_list|)
operator|||
name|defined
argument_list|(
name|CONFIG_MIDI
argument_list|)
if|#
directive|if
literal|0
comment|/* why do a detect during the attach ? XXX */
block|if (!sb_dsp_detect(hw_config)) 	return ;
endif|#
directive|endif
name|sb_dsp_init
argument_list|(
name|hw_config
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return ;
block|}
end_function

begin_function
name|int
name|probe_sb
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|CONFIG_AEDSP16
argument_list|)
operator|&&
name|defined
argument_list|(
name|AEDSP16_SBPRO
argument_list|)
comment|/*      * Initialize Audio Excel DSP 16 to SBPRO.      */
name|InitAEDSP16_SBPRO
argument_list|(
name|hw_config
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|sb_dsp_detect
argument_list|(
name|hw_config
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

