begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Cameron Grant<cg@freebsd.org>  * Copyright by Hannu Savolainen 1995  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * first, include kernel header files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* for DATA_SET */
end_comment

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/soundcard.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_undef
undef|#
directive|undef
name|USING_MUTEX
end_undef

begin_undef
undef|#
directive|undef
name|USING_DEVFS
end_undef

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_define
define|#
directive|define
name|USING_MUTEX
end_define

begin_define
define|#
directive|define
name|USING_DEVFS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INTR_TYPE_AV
value|INTR_TYPE_TTY
end_define

begin_define
define|#
directive|define
name|INTR_MPSAFE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SND_DYNSYSCTL
end_define

begin_struct_decl
struct_decl|struct
name|pcm_channel
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pcm_feeder
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|snd_dbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|snd_mixer
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<dev/sound/pcm/buffer.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/channel.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/feeder.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/mixer.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/dsp.h>
end_include

begin_define
define|#
directive|define
name|PCM_SOFTC_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|SND_STATUSLEN
value|64
end_define

begin_define
define|#
directive|define
name|SOUND_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|SOUND_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|SOUND_PREFVER
value|SOUND_MODVER
end_define

begin_define
define|#
directive|define
name|SOUND_MAXVER
value|1
end_define

begin_comment
comment|/* PROPOSAL: each unit needs: status, mixer, dsp, dspW, audio, sequencer, midi-in, seq2, sndproc = 9 devices dspW and audio are deprecated. dsp needs min 64 channels, will give it 256  minor = (unit<< 20) + (dev<< 16) + channel currently minor = (channel<< 16) + (unit<< 4) + dev  nomenclature: 	/dev/pcmX/dsp.(0..255) 	/dev/pcmX/dspW 	/dev/pcmX/audio 	/dev/pcmX/status 	/dev/pcmX/mixer 	[etc.] */
end_comment

begin_define
define|#
directive|define
name|PCMMAXCHAN
value|0xff
end_define

begin_define
define|#
directive|define
name|PCMMAXDEV
value|0x0f
end_define

begin_define
define|#
directive|define
name|PCMMAXUNIT
value|0x0f
end_define

begin_define
define|#
directive|define
name|PCMMINOR
parameter_list|(
name|x
parameter_list|)
value|(minor(x))
end_define

begin_define
define|#
directive|define
name|PCMCHAN
parameter_list|(
name|x
parameter_list|)
value|((PCMMINOR(x)>> 16)& PCMMAXCHAN)
end_define

begin_define
define|#
directive|define
name|PCMUNIT
parameter_list|(
name|x
parameter_list|)
value|((PCMMINOR(x)>> 4)& PCMMAXUNIT)
end_define

begin_define
define|#
directive|define
name|PCMDEV
parameter_list|(
name|x
parameter_list|)
value|(PCMMINOR(x)& PCMMAXDEV)
end_define

begin_define
define|#
directive|define
name|PCMMKMINOR
parameter_list|(
name|u
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|((((c)& PCMMAXCHAN)<< 16) | \ 				(((u)& PCMMAXUNIT)<< 4) | ((d)& PCMMAXDEV))
end_define

begin_define
define|#
directive|define
name|SD_F_SIMPLEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SD_F_AUTOVCHAN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SD_F_SOFTPCMVOL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SD_F_PSWAPLR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SD_F_RSWAPLR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SD_F_PRIO_RD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SD_F_PRIO_WR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SD_F_PRIO_SET
value|(SD_F_PRIO_RD | SD_F_PRIO_WR)
end_define

begin_define
define|#
directive|define
name|SD_F_DIR_SET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SD_F_TRANSIENT
value|0xf0000000
end_define

begin_comment
comment|/* many variables should be reduced to a range. Here define a macro */
end_comment

begin_define
define|#
directive|define
name|RANGE
parameter_list|(
name|var
parameter_list|,
name|low
parameter_list|,
name|high
parameter_list|)
value|(var) = \ 	(((var)<(low))? (low) : ((var)>(high))? (high) : (var))
end_define

begin_define
define|#
directive|define
name|DSP_BUFFSIZE
value|(8192)
end_define

begin_comment
comment|/*  * Macros for reading/writing PCM sample / int values from bytes array.  * Since every process is done using signed integer (and to make our life  * less miserable), unsigned sample will be converted to its signed  * counterpart and restored during writing back. To avoid overflow,  * we truncate 32bit (and only 32bit) samples down to 24bit (see below  * for the reason), unless PCM_USE_64BIT_ARITH is defined.  */
end_comment

begin_comment
comment|/*  * Automatically turn on 64bit arithmetic on suitable archs  * (amd64 64bit, ia64, etc..) for wider 32bit samples / integer processing.  */
end_comment

begin_if
if|#
directive|if
name|LONG_BIT
operator|>=
literal|64
end_if

begin_undef
undef|#
directive|undef
name|PCM_USE_64BIT_ARITH
end_undef

begin_define
define|#
directive|define
name|PCM_USE_64BIT_ARITH
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|PCM_USE_64BIT_ARITH
end_undef

begin_define
define|#
directive|define
name|PCM_USE_64BIT_ARITH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PCM_USE_64BIT_ARITH
end_ifdef

begin_typedef
typedef|typedef
name|int64_t
name|intpcm_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int32_t
name|intpcm_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 32bit fixed point shift */
end_comment

begin_define
define|#
directive|define
name|PCM_FXSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCM_S8_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|PCM_S8_MIN
value|-0x80
end_define

begin_define
define|#
directive|define
name|PCM_S16_MAX
value|0x7fff
end_define

begin_define
define|#
directive|define
name|PCM_S16_MIN
value|-0x8000
end_define

begin_define
define|#
directive|define
name|PCM_S24_MAX
value|0x7fffff
end_define

begin_define
define|#
directive|define
name|PCM_S24_MIN
value|-0x800000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCM_USE_64BIT_ARITH
end_ifdef

begin_if
if|#
directive|if
name|LONG_BIT
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|PCM_S32_MAX
value|0x7fffffffL
end_define

begin_define
define|#
directive|define
name|PCM_S32_MIN
value|-0x80000000L
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCM_S32_MAX
value|0x7fffffffLL
end_define

begin_define
define|#
directive|define
name|PCM_S32_MIN
value|-0x80000000LL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCM_S32_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|PCM_S32_MIN
value|(-0x7fffffff - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bytes-per-sample definition */
end_comment

begin_define
define|#
directive|define
name|PCM_8_BPS
value|1
end_define

begin_define
define|#
directive|define
name|PCM_16_BPS
value|2
end_define

begin_define
define|#
directive|define
name|PCM_24_BPS
value|3
end_define

begin_define
define|#
directive|define
name|PCM_32_BPS
value|4
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|PCM_READ_S16_LE
parameter_list|(
name|b8
parameter_list|)
value|*((int16_t *)(b8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
value|*((int32_t *)(b8))
end_define

begin_define
define|#
directive|define
name|PCM_READ_S16_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[1] | ((int8_t)((b8)[0]))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[3] | (b8)[2]<< 8 | (b8)[1]<< 16 | \ 			((int8_t)((b8)[0]))<< 24))
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((int16_t *)(b8)) = (val)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((int32_t *)(b8)) = (val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[1] = val; \ 			b8[0] = val>> 8; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[3] = val; \ 			b8[2] = val>> 8; \ 			b8[1] = val>> 16; \ 			b8[0] = val>> 24; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_LE
parameter_list|(
name|b8
parameter_list|)
value|((int16_t)(*((uint16_t *)(b8)) ^ 0x8000))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
value|((int32_t)(*((uint32_t *)(b8)) ^ 0x80000000))
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[1] | ((int8_t)((b8)[0] ^ 0x80))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[3] | (b8)[2]<< 8 | (b8)[1]<< 16 | \ 			((int8_t)((b8)[0] ^ 0x80))<< 24))
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((uint16_t *)(b8)) = (val) ^ 0x8000
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((uint32_t *)(b8)) = (val) ^ 0x80000000
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[1] = val; \ 			b8[0] = (val>> 8) ^ 0x80; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[3] = val; \ 			b8[2] = val>> 8; \ 			b8[1] = val>> 16; \ 			b8[0] = (val>> 24) ^ 0x80; \ 		} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S16_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[0] | ((int8_t)((b8)[1]))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[0] | (b8)[1]<< 8 | (b8)[2]<< 16 | \ 			((int8_t)((b8)[3]))<< 24))
end_define

begin_define
define|#
directive|define
name|PCM_READ_S16_BE
parameter_list|(
name|b8
parameter_list|)
value|*((int16_t *)(b8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
value|*((int32_t *)(b8))
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[0] = val; \ 			b8[1] = val>> 8; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[0] = val; \ 			b8[1] = val>> 8; \ 			b8[2] = val>> 16; \ 			b8[3] = val>> 24; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S16_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((int16_t *)(b8)) = (val)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_S32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((int32_t *)(b8)) = (val)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[0] | ((int8_t)((b8)[1] ^ 0x80))<< 8))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[0] | (b8)[1]<< 8 | (b8)[2]<< 16 | \ 			((int8_t)((b8)[3] ^ 0x80))<< 24))
end_define

begin_define
define|#
directive|define
name|PCM_READ_U16_BE
parameter_list|(
name|b8
parameter_list|)
value|((int16_t)(*((uint16_t *)(b8)) ^ 0x8000))
end_define

begin_define
define|#
directive|define
name|_PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
value|((int32_t)(*((uint32_t *)(b8)) ^ 0x80000000))
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[0] = val; \ 			b8[1] = (val>> 8) ^ 0x80; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[0] = val; \ 			b8[1] = val>> 8; \ 			b8[2] = val>> 16; \ 			b8[3] = (val>> 24) ^ 0x80; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U16_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((uint16_t *)(b8)) = (val) ^ 0x8000
end_define

begin_define
define|#
directive|define
name|_PCM_WRITE_U32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((uint32_t *)(b8)) = (val) ^ 0x80000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCM_READ_S24_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[0] | (b8)[1]<< 8 | ((int8_t)((b8)[2]))<< 16))
end_define

begin_define
define|#
directive|define
name|PCM_READ_S24_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[2] | (b8)[1]<< 8 | ((int8_t)((b8)[0]))<< 16))
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S24_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[0] = val; \ 			b8[1] = val>> 8; \ 			b8[2] = val>> 16; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S24_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[2] = val; \ 			b8[1] = val>> 8; \ 			b8[0] = val>> 16; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U24_LE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[0] | (b8)[1]<< 8 | \ 			((int8_t)((b8)[2] ^ 0x80))<< 16))
end_define

begin_define
define|#
directive|define
name|PCM_READ_U24_BE
parameter_list|(
name|b8
parameter_list|)
define|\
value|((int32_t)((b8)[2] | (b8)[1]<< 8 | \ 			((int8_t)((b8)[0] ^ 0x80))<< 16))
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U24_LE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[0] = val; \ 			b8[1] = val>> 8; \ 			b8[2] = (val>> 16) ^ 0x80; \ 		} while(0)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U24_BE
parameter_list|(
name|bb8
parameter_list|,
name|vval
parameter_list|)
value|do { \ 			int32_t val = (vval); \ 			uint8_t *b8 = (bb8); \ 			b8[2] = val; \ 			b8[1] = val>> 8; \ 			b8[0] = (val>> 16) ^ 0x80; \ 		} while(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCM_USE_64BIT_ARITH
end_ifdef

begin_define
define|#
directive|define
name|PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_S32_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S32_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S32_BE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_LE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
value|_PCM_READ_U32_BE(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U32_LE(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U32_BE(b8, val)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PCM_USE_64BIT_ARITH */
end_comment

begin_comment
comment|/*  * 24bit integer ?!? This is quite unfortunate, eh? Get the fact straight:  * Dynamic range for:  *	1) Human =~ 140db  *	2) 16bit = 96db (close enough)  *	3) 24bit = 144db (perfect)  *	4) 32bit = 196db (way too much)  *	5) Bugs Bunny = Gazillion!@%$Erbzzztt-EINVAL db  * Since we're not Bugs Bunny ..uh..err.. avoiding 64bit arithmetic, 24bit  * is pretty much sufficient for our signed integer processing.  */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S32_LE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_S32_LE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_S32_BE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_S32_BE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S32_LE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_S32_BE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_LE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_U32_LE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U32_BE
parameter_list|(
name|b8
parameter_list|)
value|(_PCM_READ_U32_BE(b8)>> PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_LE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U32_LE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U32_BE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|_PCM_WRITE_U32_BE(b8, (val)<< PCM_FXSHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 8bit sample is pretty much useless since it doesn't provide  * sufficient dynamic range throughout our filtering process.  * For the sake of completeness, declare it anyway.  */
end_comment

begin_define
define|#
directive|define
name|PCM_READ_S8
parameter_list|(
name|b8
parameter_list|)
value|*((int8_t *)(b8))
end_define

begin_define
define|#
directive|define
name|PCM_READ_S8_NE
parameter_list|(
name|b8
parameter_list|)
value|PCM_READ_S8(b8)
end_define

begin_define
define|#
directive|define
name|PCM_READ_U8
parameter_list|(
name|b8
parameter_list|)
value|((int8_t)(*((uint8_t *)(b8)) ^ 0x80))
end_define

begin_define
define|#
directive|define
name|PCM_READ_U8_NE
parameter_list|(
name|b8
parameter_list|)
value|PCM_READ_U8(b8)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S8
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((int8_t *)(b8)) = (val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_S8_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|PCM_WRITE_S8(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U8
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|*((uint8_t *)(b8)) = (val) ^ 0x80
end_define

begin_define
define|#
directive|define
name|PCM_WRITE_U8_NE
parameter_list|(
name|b8
parameter_list|,
name|val
parameter_list|)
value|PCM_WRITE_U8(b8, val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_S8
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S8_MAX) ? PCM_S8_MAX : \ 			(((val)< PCM_S8_MIN) ? PCM_S8_MIN : (val)))
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_S16
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S16_MAX) ? PCM_S16_MAX : \ 			(((val)< PCM_S16_MIN) ? PCM_S16_MIN : (val)))
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_S24
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S24_MAX) ? PCM_S24_MAX : \ 			(((val)< PCM_S24_MIN) ? PCM_S24_MIN : (val)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCM_USE_64BIT_ARITH
end_ifdef

begin_define
define|#
directive|define
name|PCM_CLAMP_S32
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S32_MAX) ? PCM_S32_MAX : \ 			(((val)< PCM_S32_MIN) ? PCM_S32_MIN : (val)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCM_CLAMP_S32
parameter_list|(
name|val
parameter_list|)
define|\
value|(((val)> PCM_S24_MAX) ? PCM_S32_MAX : \ 			(((val)< PCM_S24_MIN) ? PCM_S32_MIN : \ 			((val)<< PCM_FXSHIFT)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCM_CLAMP_U8
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S8(val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_U16
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S16(val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_U24
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S24(val)
end_define

begin_define
define|#
directive|define
name|PCM_CLAMP_U32
parameter_list|(
name|val
parameter_list|)
value|PCM_CLAMP_S32(val)
end_define

begin_comment
comment|/* make figuring out what a format is easier. got AFMT_STEREO already */
end_comment

begin_define
define|#
directive|define
name|AFMT_32BIT
value|(AFMT_S32_LE | AFMT_S32_BE | AFMT_U32_LE | AFMT_U32_BE)
end_define

begin_define
define|#
directive|define
name|AFMT_24BIT
value|(AFMT_S24_LE | AFMT_S24_BE | AFMT_U24_LE | AFMT_U24_BE)
end_define

begin_define
define|#
directive|define
name|AFMT_16BIT
value|(AFMT_S16_LE | AFMT_S16_BE | AFMT_U16_LE | AFMT_U16_BE)
end_define

begin_define
define|#
directive|define
name|AFMT_8BIT
value|(AFMT_MU_LAW | AFMT_A_LAW | AFMT_U8 | AFMT_S8)
end_define

begin_define
define|#
directive|define
name|AFMT_SIGNED
value|(AFMT_S32_LE | AFMT_S32_BE | AFMT_S24_LE | AFMT_S24_BE | \ 			AFMT_S16_LE | AFMT_S16_BE | AFMT_S8)
end_define

begin_define
define|#
directive|define
name|AFMT_BIGENDIAN
value|(AFMT_S32_BE | AFMT_U32_BE | AFMT_S24_BE | AFMT_U24_BE | \ 			AFMT_S16_BE | AFMT_U16_BE)
end_define

begin_function_decl
name|struct
name|pcm_channel
modifier|*
name|fkchan_setup
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fkchan_kill
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX Flawed definition. I'll fix it someday. */
end_comment

begin_define
define|#
directive|define
name|SND_MAXVCHANS
value|PCMMAXCHAN
end_define

begin_comment
comment|/*  * Minor numbers for the sound driver.  *  * Unfortunately Creative called the codec chip of SB as a DSP. For this  * reason the /dev/dsp is reserved for digitized audio use. There is a  * device for true DSP processors but it will be called something else.  * In v3.0 it's /dev/sndproc but this could be a temporary solution.  */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_CTL
value|0
end_define

begin_comment
comment|/* Control port /dev/mixer */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_SEQ
value|1
end_define

begin_comment
comment|/* Sequencer /dev/sequencer */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_MIDIN
value|2
end_define

begin_comment
comment|/* Raw midi access */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP
value|3
end_define

begin_comment
comment|/* Digitized voice /dev/dsp */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_AUDIO
value|4
end_define

begin_comment
comment|/* Sparc compatible /dev/audio */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP16
value|5
end_define

begin_comment
comment|/* Like /dev/dsp but 16 bits/sample */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_STATUS
value|6
end_define

begin_comment
comment|/* /dev/sndstat */
end_comment

begin_comment
comment|/* #7 not in use now. */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_SEQ2
value|8
end_define

begin_comment
comment|/* /dev/sequencer, level 2 interface */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_SNDPROC
value|9
end_define

begin_comment
comment|/* /dev/sndproc for programmable devices */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_PSS
value|SND_DEV_SNDPROC
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_NORESET
value|10
end_define

begin_define
define|#
directive|define
name|SND_DEV_DSPHW
value|11
end_define

begin_comment
comment|/* specific channel request */
end_comment

begin_define
define|#
directive|define
name|DSP_DEFAULT_SPEED
value|8000
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_decl_stmt
specifier|extern
name|int
name|pcm_veto_load
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|snd_unit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|snd_maxautovchans
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|snd_verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|pcm_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|unrhdr
modifier|*
name|pcmsg_unrhdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * some macros for debugging purposes  * DDB/DEB to enable/disable debugging stuff  * BVDDB   to enable debugging when bootverbose  */
end_comment

begin_define
define|#
directive|define
name|BVDDB
parameter_list|(
name|x
parameter_list|)
value|if (bootverbose) x
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEB
end_ifndef

begin_define
define|#
directive|define
name|DEB
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_snd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|struct
name|pcm_channel
modifier|*
name|pcm_getfakechan
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_chnalloc
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|struct
name|pcm_channel
modifier|*
modifier|*
name|ch
parameter_list|,
name|int
name|direction
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|int
name|chnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_chnrelease
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_chnref
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|c
parameter_list|,
name|int
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_inprog
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|delta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcm_channel
modifier|*
name|pcm_chn_create
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|struct
name|pcm_channel
modifier|*
name|parent
parameter_list|,
name|kobj_class_t
name|cls
parameter_list|,
name|int
name|dir
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_chn_destroy
parameter_list|(
name|struct
name|pcm_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_chn_add
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|struct
name|pcm_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_chn_remove
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|struct
name|pcm_channel
modifier|*
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_addchan
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|dir
parameter_list|,
name|kobj_class_t
name|cls
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|pcm_getbuffersize
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|unsigned
name|int
name|minbufsz
parameter_list|,
name|unsigned
name|int
name|deflt
parameter_list|,
name|unsigned
name|int
name|maxbufsz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|devinfo
parameter_list|,
name|int
name|numplay
parameter_list|,
name|int
name|numrec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_unregister
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcm_setstatus
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|pcm_getflags
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcm_setflags
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|pcm_getdevinfo
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|,
name|int
name|flags
parameter_list|,
name|driver_intr_t
name|hand
parameter_list|,
name|void
modifier|*
name|param
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|snd_mtxcreate
parameter_list|(
specifier|const
name|char
modifier|*
name|desc
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_mtxfree
parameter_list|(
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_mtxassert
parameter_list|(
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|snd_mtxlock
parameter_list|(
name|m
parameter_list|)
value|mtx_lock(m)
end_define

begin_define
define|#
directive|define
name|snd_mtxunlock
parameter_list|(
name|m
parameter_list|)
value|mtx_unlock(m)
end_define

begin_function_decl
name|int
name|sysctl_hw_snd_vchans
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sndstat_handler
function_decl|)
parameter_list|(
name|struct
name|sbuf
modifier|*
name|s
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|sndstat_acquire
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sndstat_release
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sndstat_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|sndstat_handler
name|handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sndstat_registerfile
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sndstat_unregister
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sndstat_unregisterfile
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SND_DECLARE_FILE
parameter_list|(
name|version
parameter_list|)
define|\
value|_SND_DECLARE_FILE(__LINE__, version)
end_define

begin_define
define|#
directive|define
name|_SND_DECLARE_FILE
parameter_list|(
name|uniq
parameter_list|,
name|version
parameter_list|)
define|\
value|__SND_DECLARE_FILE(uniq, version)
end_define

begin_define
define|#
directive|define
name|__SND_DECLARE_FILE
parameter_list|(
name|uniq
parameter_list|,
name|version
parameter_list|)
define|\
value|static char sndstat_vinfo[] = version; \ 	SYSINIT(sdf_ ## uniq, SI_SUB_DRIVERS, SI_ORDER_MIDDLE, sndstat_registerfile, sndstat_vinfo); \ 	SYSUNINIT(sdf_ ## uniq, SI_SUB_DRIVERS, SI_ORDER_MIDDLE, sndstat_unregisterfile, sndstat_vinfo);
end_define

begin_comment
comment|/* usage of flags in device config entry (config file) */
end_comment

begin_define
define|#
directive|define
name|DV_F_DRQ_MASK
value|0x00000007
end_define

begin_comment
comment|/* mask for secondary drq */
end_comment

begin_define
define|#
directive|define
name|DV_F_DUAL_DMA
value|0x00000010
end_define

begin_comment
comment|/* set to use secondary dma channel */
end_comment

begin_comment
comment|/* ought to be made obsolete but still used by mss */
end_comment

begin_define
define|#
directive|define
name|DV_F_DEV_MASK
value|0x0000ff00
end_define

begin_comment
comment|/* force device type/class */
end_comment

begin_define
define|#
directive|define
name|DV_F_DEV_SHIFT
value|8
end_define

begin_comment
comment|/* force device type/class */
end_comment

begin_define
define|#
directive|define
name|PCM_DEBUG_MTX
end_define

begin_comment
comment|/*  * this is rather kludgey- we need to duplicate these struct def'ns from sound.c  * so that the macro versions of pcm_{,un}lock can dereference them.  * we also have to do this now makedev() has gone away.  */
end_comment

begin_struct
struct|struct
name|snddev_channel
block|{
name|SLIST_ENTRY
argument_list|(
argument|snddev_channel
argument_list|)
name|link
expr_stmt|;
name|struct
name|pcm_channel
modifier|*
name|channel
decl_stmt|;
name|int
name|chan_num
decl_stmt|;
name|struct
name|cdev
modifier|*
name|dsp_devt
decl_stmt|;
name|struct
name|cdev
modifier|*
name|dspW_devt
decl_stmt|;
name|struct
name|cdev
modifier|*
name|audio_devt
decl_stmt|;
name|struct
name|cdev
modifier|*
name|dspHW_devt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|snddev_info
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|snddev_channel
argument_list|)
name|channels
expr_stmt|;
name|struct
name|pcm_channel
modifier|*
name|fakechan
decl_stmt|;
name|unsigned
name|devcount
decl_stmt|,
name|playcount
decl_stmt|,
name|reccount
decl_stmt|,
name|vchancount
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
name|int
name|inprog
decl_stmt|;
name|unsigned
name|int
name|bufsz
decl_stmt|;
name|void
modifier|*
name|devinfo
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|char
name|status
index|[
name|SND_STATUSLEN
index|]
decl_stmt|;
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
name|struct
name|cdev
modifier|*
name|mixer_dev
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|sound_oss_sysinfo
parameter_list|(
name|oss_sysinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PCM_DEBUG_MTX
end_ifdef

begin_define
define|#
directive|define
name|pcm_lock
parameter_list|(
name|d
parameter_list|)
value|mtx_lock(((struct snddev_info *)(d))->lock)
end_define

begin_define
define|#
directive|define
name|pcm_unlock
parameter_list|(
name|d
parameter_list|)
value|mtx_unlock(((struct snddev_info *)(d))->lock)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|pcm_lock
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcm_unlock
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_MODULE
end_ifdef

begin_define
define|#
directive|define
name|PCM_KLDSTRING
parameter_list|(
name|a
parameter_list|)
value|("kld " # a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCM_KLDSTRING
parameter_list|(
name|a
parameter_list|)
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OS_H_ */
end_comment

end_unit

