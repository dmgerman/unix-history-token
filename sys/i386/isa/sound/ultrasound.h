begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_ULTRASOUND_H_
end_ifndef

begin_define
define|#
directive|define
name|_ULTRASOUND_H_
end_define

begin_comment
comment|/*  * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  *	ultrasound.h - Macros for programming the Gravis Ultrasound  *			These macros are extremely device dependent  *			and not portable.  */
end_comment

begin_comment
comment|/*  *	Private events for Gravis Ultrasound (GUS)  *  *	Format:  *		byte 0 		- SEQ_PRIVATE (0xfe)  *		byte 1 		- Synthesizer device number (0-N)  *		byte 2 		- Command (see below)  *		byte 3 		- Voice number (0-31)  *		bytes 4 and 5	- parameter P1 (u_short)  *		bytes 6 and 7	- parameter P2 (u_short)  *  *	Commands:  *		Each command affects one voice defined in byte 3.  *		Unused parameters (P1 and/or P2 *MUST* be initialized to zero).  *		_GUS_NUMVOICES	- Sets max. number of concurrent voices (P1=14-31, default 16)  *		_GUS_VOICESAMPLE- ************ OBSOLETE *************  *		_GUS_VOICEON	- Starts voice (P1=voice mode)  *		_GUS_VOICEOFF	- Stops voice (no parameters)  *		_GUS_VOICEFADE	- Stops the voice smoothly.  *		_GUS_VOICEMODE	- Alters the voice mode, don't start or stop voice (P1=voice mode)  *		_GUS_VOICEBALA	- Sets voice balence (P1, 0=left, 7=middle and 15=right, default 7)  *		_GUS_VOICEFREQ	- Sets voice (sample) playback frequency (P1=Hz)  *		_GUS_VOICEVOL	- Sets voice volume (P1=volume, 0xfff=max, 0xeff=half, 0x000=off)  *		_GUS_VOICEVOL2	- Sets voice volume (P1=volume, 0xfff=max, 0xeff=half, 0x000=off)  *				  (Like GUS_VOICEVOL but doesn't change the hw  *				  volume. It just updates volume in the voice table).  *  *		_GUS_RAMPRANGE	- Sets limits for volume ramping (P1=low volume, P2=high volume)  *		_GUS_RAMPRATE	- Sets the speed for volume ramping (P1=scale, P2=rate)  *		_GUS_RAMPMODE	- Sets the volume ramping mode (P1=ramping mode)  *		_GUS_RAMPON	- Starts volume ramping (no parameters)  *		_GUS_RAMPOFF	- Stops volume ramping (no parameters)  *		_GUS_VOLUME_SCALE - Changes the volume calculation constants  *				  for all voices.  */
end_comment

begin_define
define|#
directive|define
name|_GUS_NUMVOICES
value|0x00
end_define

begin_define
define|#
directive|define
name|_GUS_VOICESAMPLE
value|0x01
end_define

begin_comment
comment|/* OBSOLETE */
end_comment

begin_define
define|#
directive|define
name|_GUS_VOICEON
value|0x02
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEOFF
value|0x03
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEMODE
value|0x04
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEBALA
value|0x05
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEFREQ
value|0x06
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEVOL
value|0x07
end_define

begin_define
define|#
directive|define
name|_GUS_RAMPRANGE
value|0x08
end_define

begin_define
define|#
directive|define
name|_GUS_RAMPRATE
value|0x09
end_define

begin_define
define|#
directive|define
name|_GUS_RAMPMODE
value|0x0a
end_define

begin_define
define|#
directive|define
name|_GUS_RAMPON
value|0x0b
end_define

begin_define
define|#
directive|define
name|_GUS_RAMPOFF
value|0x0c
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEFADE
value|0x0d
end_define

begin_define
define|#
directive|define
name|_GUS_VOLUME_SCALE
value|0x0e
end_define

begin_define
define|#
directive|define
name|_GUS_VOICEVOL2
value|0x0f
end_define

begin_define
define|#
directive|define
name|_GUS_VOICE_POS
value|0x10
end_define

begin_comment
comment|/*  *	GUS API macros  */
end_comment

begin_define
define|#
directive|define
name|_GUS_CMD
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|cmd
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|{\ 	_SEQ_NEEDBUF(8); _seqbuf[_seqbufptr] = SEQ_PRIVATE;\ 	_seqbuf[_seqbufptr+1] = (chn); _seqbuf[_seqbufptr+2] = cmd;\ 	_seqbuf[_seqbufptr+3] = voice;\ 	*(u_short*)&_seqbuf[_seqbufptr+4] = p1;\ 	*(u_short*)&_seqbuf[_seqbufptr+6] = p2;\ 	_SEQ_ADVBUF(8);}
end_define

begin_define
define|#
directive|define
name|GUS_NUMVOICES
parameter_list|(
name|chn
parameter_list|,
name|p1
parameter_list|)
value|_GUS_CMD(chn, 0, _GUS_NUMVOICES, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICESAMPLE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICESAMPLE, (p1), 0)
end_define

begin_comment
comment|/* OBSOLETE */
end_comment

begin_define
define|#
directive|define
name|GUS_VOICEON
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEON, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEOFF
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEOFF, 0, 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEFADE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEFADE, 0, 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEMODE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEMODE, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEBALA
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEBALA, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEFREQ
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEFREQ, \ 	(p)& 0xffff, ((p)>> 16)& 0xffff)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEVOL
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEVOL, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOICEVOL2
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICEVOL2, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_RAMPRANGE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|low
parameter_list|,
name|high
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_RAMPRANGE, (low), (high))
end_define

begin_define
define|#
directive|define
name|GUS_RAMPRATE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_RAMPRATE, (p1), (p2))
end_define

begin_define
define|#
directive|define
name|GUS_RAMPMODE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_RAMPMODE, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_RAMPON
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_RAMPON, (p1), 0)
end_define

begin_define
define|#
directive|define
name|GUS_RAMPOFF
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_RAMPOFF, 0, 0)
end_define

begin_define
define|#
directive|define
name|GUS_VOLUME_SCALE
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOLUME_SCALE, (p1), (p2))
end_define

begin_define
define|#
directive|define
name|GUS_VOICE_POS
parameter_list|(
name|chn
parameter_list|,
name|voice
parameter_list|,
name|p
parameter_list|)
define|\
value|_GUS_CMD(chn, voice, _GUS_VOICE_POS, \ 	(p)& 0xffff, ((p)>> 16)& 0xffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

