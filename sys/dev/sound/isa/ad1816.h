begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Luigi Rizzo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains information and macro definitions for  * the ad1816 chip  */
end_comment

begin_comment
comment|/* AD1816 register macros */
end_comment

begin_define
define|#
directive|define
name|AD1816_ALE
value|0
end_define

begin_comment
comment|/* indirect reg access 		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INT
value|1
end_define

begin_comment
comment|/* interupt status     		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_LOW
value|2
end_define

begin_comment
comment|/* indirect low byte   		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_HIGH
value|3
end_define

begin_comment
comment|/* indirect high byte  		*/
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|ad1816_pioD
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base+4)
end_define

begin_comment
comment|/* PIO debug		*/
end_comment

begin_define
define|#
directive|define
name|ad1816_pios
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base+5)
end_define

begin_comment
comment|/* PIO status		*/
end_comment

begin_define
define|#
directive|define
name|ad1816_piod
parameter_list|(
name|d
parameter_list|)
value|((d)->io_base+6)
end_define

begin_comment
comment|/* PIO data 		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* values for playback/capture config:    bits: 0   enable/disable          1   pio/dma          2   stereo/mono          3   companded/linearPCM          4-5 format : 00 8bit  linear (uncomp)                       00 8bit  mulaw  (comp)                       01 16bit le     (uncomp)                       01 8bit  alaw   (comp)                       11 16bit be     (uncomp) */
end_comment

begin_define
define|#
directive|define
name|AD1816_PLAY
value|8
end_define

begin_comment
comment|/* playback config     		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_CAPT
value|9
end_define

begin_comment
comment|/* capture config      		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_BUSY
value|0x80
end_define

begin_comment
comment|/* chip is busy			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_ALEMASK
value|0x3F
end_define

begin_comment
comment|/* mask for indirect adr.	*/
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AD1816_INTRSI
value|0x01
end_define

begin_comment
comment|/* sb intr			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INTRGI
value|0x02
end_define

begin_comment
comment|/* game intr			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INTRRI
value|0x04
end_define

begin_comment
comment|/* ring intr			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INTRDI
value|0x08
end_define

begin_comment
comment|/* dsp intr			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INTRVI
value|0x10
end_define

begin_comment
comment|/* vol intr			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INTRTI
value|0x20
end_define

begin_comment
comment|/* timer intr			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AD1816_INTRCI
value|0x40
end_define

begin_comment
comment|/* capture intr			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_INTRPI
value|0x80
end_define

begin_comment
comment|/* playback intr		*/
end_comment

begin_comment
comment|/* PIO stuff is not supplied here */
end_comment

begin_comment
comment|/* playback / capture config      */
end_comment

begin_define
define|#
directive|define
name|AD1816_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable pl/cp			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_PIO
value|0x02
end_define

begin_comment
comment|/* use pio			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_STEREO
value|0x04
end_define

begin_define
define|#
directive|define
name|AD1816_COMP
value|0x08
end_define

begin_comment
comment|/* data is companded		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_U8
value|0x00
end_define

begin_comment
comment|/* 8 bit linear pcm		*/
end_comment

begin_define
define|#
directive|define
name|AD1816_MULAW
value|0x08
end_define

begin_comment
comment|/* 8 bit mulaw			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_ALAW
value|0x18
end_define

begin_comment
comment|/* 8 bit alaw			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_S16LE
value|0x10
end_define

begin_comment
comment|/* 16 bit linear little endian	*/
end_comment

begin_define
define|#
directive|define
name|AD1816_S16BE
value|0x30
end_define

begin_comment
comment|/* 16 bit linear big endian	*/
end_comment

begin_define
define|#
directive|define
name|AD1816_FORMASK
value|0x38
end_define

begin_comment
comment|/* format mask			*/
end_comment

begin_define
define|#
directive|define
name|AD1816_REC_DEVICES
define|\
value|(SOUND_MASK_LINE | SOUND_MASK_MIC | SOUND_MASK_CD)
end_define

begin_define
define|#
directive|define
name|AD1816_MIXER_DEVICES
define|\
value|(SOUND_MASK_VOLUME | SOUND_MASK_PCM | SOUND_MASK_SYNTH | \      SOUND_MASK_LINE   | SOUND_MASK_MIC | SOUND_MASK_CD | SOUND_MASK_IGAIN)
end_define

end_unit

