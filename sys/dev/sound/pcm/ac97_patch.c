begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2002 FreeBSD, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<dev/sound/pcm/sound.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/ac97.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/ac97_patch.h>
end_include

begin_expr_stmt
name|SND_DECLARE_FILE
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|ad1886_patch
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
block|{
define|#
directive|define
name|AC97_AD_JACK_SPDIF
value|0x72
comment|/* 	 *    Presario700 workaround 	 *     for Jack Sense/SPDIF Register misetting causing 	 *    no audible output 	 *    by Santiago Nullo 04/05/2002 	 */
name|ac97_wrcd
argument_list|(
name|codec
argument_list|,
name|AC97_AD_JACK_SPDIF
argument_list|,
literal|0x0010
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ad198x_patch
parameter_list|(
name|struct
name|ac97_info
modifier|*
name|codec
parameter_list|)
block|{
name|ac97_wrcd
argument_list|(
name|codec
argument_list|,
literal|0x76
argument_list|,
name|ac97_rdcd
argument_list|(
name|codec
argument_list|,
literal|0x76
argument_list|)
operator||
literal|0x0420
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

