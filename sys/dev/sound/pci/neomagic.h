begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * All rights reserved.  *  * Derived from the public domain Linux driver  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHERIN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THEPOSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NM256_H_
end_ifndef

begin_define
define|#
directive|define
name|_NM256_H_
end_define

begin_comment
comment|/* The BIOS signature. */
end_comment

begin_define
define|#
directive|define
name|NM_SIGNATURE
value|0x4e4d0000
end_define

begin_comment
comment|/* Signature mask. */
end_comment

begin_define
define|#
directive|define
name|NM_SIG_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Size of the second memory area. */
end_comment

begin_define
define|#
directive|define
name|NM_PORT2_SIZE
value|4096
end_define

begin_comment
comment|/* The base offset of the mixer in the second memory area. */
end_comment

begin_define
define|#
directive|define
name|NM_MIXER_OFFSET
value|0x600
end_define

begin_comment
comment|/* The base offset for the AC97 test */
end_comment

begin_define
define|#
directive|define
name|NM_MIXER_PRESENCE
value|0xa06
end_define

begin_define
define|#
directive|define
name|NM_PRESENCE_MASK
value|0x050
end_define

begin_define
define|#
directive|define
name|NM_PRESENCE_VALUE
value|0x040
end_define

begin_comment
comment|/* The maximum size of a coefficient entry. */
end_comment

begin_define
define|#
directive|define
name|NM_MAX_COEFFICIENT
value|0x5000
end_define

begin_comment
comment|/* The interrupt register. */
end_comment

begin_define
define|#
directive|define
name|NM_INT_REG
value|0xa04
end_define

begin_comment
comment|/* And its bits. */
end_comment

begin_define
define|#
directive|define
name|NM_PLAYBACK_INT
value|0x40
end_define

begin_define
define|#
directive|define
name|NM_RECORD_INT
value|0x100
end_define

begin_define
define|#
directive|define
name|NM_MISC_INT_1
value|0x4000
end_define

begin_define
define|#
directive|define
name|NM_MISC_INT_2
value|0x1
end_define

begin_comment
comment|/* The AV's "mixer ready" status bit and location. */
end_comment

begin_define
define|#
directive|define
name|NM_MIXER_STATUS_OFFSET
value|0xa04
end_define

begin_define
define|#
directive|define
name|NM_MIXER_READY_MASK
value|0x0800
end_define

begin_comment
comment|/*  * For the ZX.  It uses the same interrupt register, but it holds 32  * bits instead of 16.  */
end_comment

begin_define
define|#
directive|define
name|NM2_PLAYBACK_INT
value|0x10000
end_define

begin_define
define|#
directive|define
name|NM2_RECORD_INT
value|0x80000
end_define

begin_define
define|#
directive|define
name|NM2_MISC_INT_1
value|0x8
end_define

begin_define
define|#
directive|define
name|NM2_MISC_INT_2
value|0x2
end_define

begin_comment
comment|/* The ZX's "mixer ready" status bit and location. */
end_comment

begin_define
define|#
directive|define
name|NM2_MIXER_STATUS_OFFSET
value|0xa06
end_define

begin_define
define|#
directive|define
name|NM2_MIXER_READY_MASK
value|0x0800
end_define

begin_comment
comment|/* The playback registers start from here. */
end_comment

begin_define
define|#
directive|define
name|NM_PLAYBACK_REG_OFFSET
value|0x0
end_define

begin_comment
comment|/* The record registers start from here. */
end_comment

begin_define
define|#
directive|define
name|NM_RECORD_REG_OFFSET
value|0x200
end_define

begin_comment
comment|/* The rate register is located 2 bytes from the start of the register area. */
end_comment

begin_define
define|#
directive|define
name|NM_RATE_REG_OFFSET
value|2
end_define

begin_comment
comment|/* Mono/stereo flag, number of bits on playback, and rate mask. */
end_comment

begin_define
define|#
directive|define
name|NM_RATE_STEREO
value|1
end_define

begin_define
define|#
directive|define
name|NM_RATE_BITS_16
value|2
end_define

begin_define
define|#
directive|define
name|NM_RATE_MASK
value|0xf0
end_define

begin_comment
comment|/* Playback enable register. */
end_comment

begin_define
define|#
directive|define
name|NM_PLAYBACK_ENABLE_REG
value|(NM_PLAYBACK_REG_OFFSET + 0x1)
end_define

begin_define
define|#
directive|define
name|NM_PLAYBACK_ENABLE_FLAG
value|1
end_define

begin_define
define|#
directive|define
name|NM_PLAYBACK_ONESHOT
value|2
end_define

begin_define
define|#
directive|define
name|NM_PLAYBACK_FREERUN
value|4
end_define

begin_comment
comment|/* Mutes the audio output. */
end_comment

begin_define
define|#
directive|define
name|NM_AUDIO_MUTE_REG
value|(NM_PLAYBACK_REG_OFFSET + 0x18)
end_define

begin_define
define|#
directive|define
name|NM_AUDIO_MUTE_LEFT
value|0x8000
end_define

begin_define
define|#
directive|define
name|NM_AUDIO_MUTE_RIGHT
value|0x0080
end_define

begin_define
define|#
directive|define
name|NM_AUDIO_MUTE_BOTH
value|0x8080
end_define

begin_comment
comment|/* Recording enable register. */
end_comment

begin_define
define|#
directive|define
name|NM_RECORD_ENABLE_REG
value|(NM_RECORD_REG_OFFSET + 0)
end_define

begin_define
define|#
directive|define
name|NM_RECORD_ENABLE_FLAG
value|1
end_define

begin_define
define|#
directive|define
name|NM_RECORD_FREERUN
value|2
end_define

begin_define
define|#
directive|define
name|NM_RBUFFER_START
value|(NM_RECORD_REG_OFFSET + 0x4)
end_define

begin_define
define|#
directive|define
name|NM_RBUFFER_END
value|(NM_RECORD_REG_OFFSET + 0x10)
end_define

begin_define
define|#
directive|define
name|NM_RBUFFER_WMARK
value|(NM_RECORD_REG_OFFSET + 0xc)
end_define

begin_define
define|#
directive|define
name|NM_RBUFFER_CURRP
value|(NM_RECORD_REG_OFFSET + 0x8)
end_define

begin_define
define|#
directive|define
name|NM_PBUFFER_START
value|(NM_PLAYBACK_REG_OFFSET + 0x4)
end_define

begin_define
define|#
directive|define
name|NM_PBUFFER_END
value|(NM_PLAYBACK_REG_OFFSET + 0x14)
end_define

begin_define
define|#
directive|define
name|NM_PBUFFER_WMARK
value|(NM_PLAYBACK_REG_OFFSET + 0xc)
end_define

begin_define
define|#
directive|define
name|NM_PBUFFER_CURRP
value|(NM_PLAYBACK_REG_OFFSET + 0x8)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

