begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2009 Ariff Abdullah<ariff@FreeBSD.org>  * Copyright (c) 1999 Cameron Grant<cg@FreeBSD.org>  * Copyright (c) 1995 Hannu Savolainen  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/selinfo.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|KOBJMETHOD_END
end_ifndef

begin_define
define|#
directive|define
name|KOBJMETHOD_END
value|{ NULL, NULL }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|<dev/sound/pcm/matrix.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/pcm/matrix_map.h>
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

begin_include
include|#
directive|include
file|<dev/sound/clone.h>
end_include

begin_include
include|#
directive|include
file|<dev/sound/unit.h>
end_include

begin_define
define|#
directive|define
name|PCM_SOFTC_SIZE
value|(sizeof(struct snddev_info))
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
value|5
end_define

begin_define
define|#
directive|define
name|SOUND_MINVER
value|SOUND_MODVER
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
value|SOUND_MODVER
end_define

begin_comment
comment|/*  * We're abusing the fact that MAXMINOR still have enough room  * for our bit twiddling and nobody ever need 512 unique soundcards,  * 32 unique device types and 1024 unique cloneable devices for the  * next 100 years...  */
end_comment

begin_define
define|#
directive|define
name|PCMMAXUNIT
value|(snd_max_u())
end_define

begin_define
define|#
directive|define
name|PCMMAXDEV
value|(snd_max_d())
end_define

begin_define
define|#
directive|define
name|PCMMAXCHAN
value|(snd_max_c())
end_define

begin_define
define|#
directive|define
name|PCMMAXCLONE
value|PCMMAXCHAN
end_define

begin_define
define|#
directive|define
name|PCMUNIT
parameter_list|(
name|x
parameter_list|)
value|(snd_unit2u(dev2unit(x)))
end_define

begin_define
define|#
directive|define
name|PCMDEV
parameter_list|(
name|x
parameter_list|)
value|(snd_unit2d(dev2unit(x)))
end_define

begin_define
define|#
directive|define
name|PCMCHAN
parameter_list|(
name|x
parameter_list|)
value|(snd_unit2c(dev2unit(x)))
end_define

begin_comment
comment|/* XXX unit2minor compat */
end_comment

begin_define
define|#
directive|define
name|PCMMINOR
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/*  * By design, limit possible channels for each direction.  */
end_comment

begin_define
define|#
directive|define
name|SND_MAXHWCHAN
value|256
end_define

begin_define
define|#
directive|define
name|SND_MAXVCHANS
value|SND_MAXHWCHAN
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

begin_comment
comment|/*  * Obsolete due to better matrixing  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SD_F_DYING
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SD_F_SUICIDE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SD_F_BUSY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SD_F_MPSAFE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SD_F_REGISTERED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SD_F_BITPERFECT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SD_F_VPC
value|0x00000200
end_define

begin_comment
comment|/* volume-per-channel */
end_comment

begin_define
define|#
directive|define
name|SD_F_EQ
value|0x00000400
end_define

begin_comment
comment|/* EQ */
end_comment

begin_define
define|#
directive|define
name|SD_F_EQ_ENABLED
value|0x00000800
end_define

begin_comment
comment|/* EQ enabled */
end_comment

begin_define
define|#
directive|define
name|SD_F_EQ_BYPASSED
value|0x00001000
end_define

begin_comment
comment|/* EQ bypassed */
end_comment

begin_define
define|#
directive|define
name|SD_F_EQ_PC
value|0x00002000
end_define

begin_comment
comment|/* EQ per-channel */
end_comment

begin_define
define|#
directive|define
name|SD_F_EQ_DEFAULT
value|(SD_F_EQ | SD_F_EQ_ENABLED)
end_define

begin_define
define|#
directive|define
name|SD_F_EQ_MASK
value|(SD_F_EQ | SD_F_EQ_ENABLED |		\ 				 SD_F_EQ_BYPASSED | SD_F_EQ_PC)
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

begin_define
define|#
directive|define
name|SD_F_BITS
value|"\020"					\ 				"\001SIMPLEX"				\ 				"\002AUTOVCHAN"				\ 				"\003SOFTPCMVOL"			\ 				"\004DYING"				\ 				"\005SUICIDE"				\ 				"\006BUSY"				\ 				"\007MPSAFE"				\ 				"\010REGISTERED"			\ 				"\011BITPERFECT"			\ 				"\012VPC"				\ 				"\013EQ"				\ 				"\014EQ_ENABLED"			\ 				"\015EQ_BYPASSED"			\ 				"\016EQ_PC"				\ 				"\035PRIO_RD"				\ 				"\036PRIO_WR"				\ 				"\037DIR_SET"
end_define

begin_define
define|#
directive|define
name|PCM_ALIVE
parameter_list|(
name|x
parameter_list|)
value|((x) != NULL&& (x)->lock != NULL&&	\ 				 !((x)->flags& SD_F_DYING))
end_define

begin_define
define|#
directive|define
name|PCM_REGISTERED
parameter_list|(
name|x
parameter_list|)
value|(PCM_ALIVE(x)&&			\ 				 ((x)->flags& SD_F_REGISTERED))
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
name|AFMT_G711
value|(AFMT_MU_LAW | AFMT_A_LAW)
end_define

begin_define
define|#
directive|define
name|AFMT_8BIT
value|(AFMT_G711 | AFMT_U8 | AFMT_S8)
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

begin_define
define|#
directive|define
name|AFMT_CONVERTIBLE
value|(AFMT_8BIT | AFMT_16BIT | AFMT_24BIT |	\ 				 AFMT_32BIT)
end_define

begin_comment
comment|/* Supported vchan mixing formats */
end_comment

begin_define
define|#
directive|define
name|AFMT_VCHAN
value|(AFMT_CONVERTIBLE& ~AFMT_G711)
end_define

begin_define
define|#
directive|define
name|AFMT_PASSTHROUGH
value|AFMT_AC3
end_define

begin_define
define|#
directive|define
name|AFMT_PASSTHROUGH_RATE
value|48000
end_define

begin_define
define|#
directive|define
name|AFMT_PASSTHROUGH_CHANNEL
value|2
end_define

begin_define
define|#
directive|define
name|AFMT_PASSTHROUGH_EXTCHANNEL
value|0
end_define

begin_comment
comment|/*  * We're simply using unused, contiguous bits from various AFMT_ definitions.  * ~(0xb00ff7ff)  */
end_comment

begin_define
define|#
directive|define
name|AFMT_ENCODING_MASK
value|0xf00fffff
end_define

begin_define
define|#
directive|define
name|AFMT_CHANNEL_MASK
value|0x01f00000
end_define

begin_define
define|#
directive|define
name|AFMT_CHANNEL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|AFMT_EXTCHANNEL_MASK
value|0x0e000000
end_define

begin_define
define|#
directive|define
name|AFMT_EXTCHANNEL_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|AFMT_ENCODING
parameter_list|(
name|v
parameter_list|)
value|((v)& AFMT_ENCODING_MASK)
end_define

begin_define
define|#
directive|define
name|AFMT_EXTCHANNEL
parameter_list|(
name|v
parameter_list|)
value|(((v)& AFMT_EXTCHANNEL_MASK)>>	\ 				AFMT_EXTCHANNEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|AFMT_CHANNEL
parameter_list|(
name|v
parameter_list|)
value|(((v)& AFMT_CHANNEL_MASK)>>		\ 				AFMT_CHANNEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|AFMT_BIT
parameter_list|(
name|v
parameter_list|)
value|(((v)& AFMT_32BIT) ? 32 :		\ 				(((v)& AFMT_24BIT) ? 24 :		\ 				((((v)& AFMT_16BIT) ||			\ 				((v)& AFMT_PASSTHROUGH)) ? 16 : 8)))
end_define

begin_define
define|#
directive|define
name|AFMT_BPS
parameter_list|(
name|v
parameter_list|)
value|(AFMT_BIT(v)>> 3)
end_define

begin_define
define|#
directive|define
name|AFMT_ALIGN
parameter_list|(
name|v
parameter_list|)
value|(AFMT_BPS(v) * AFMT_CHANNEL(v))
end_define

begin_define
define|#
directive|define
name|SND_FORMAT
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|,
name|e
parameter_list|)
value|(AFMT_ENCODING(f) |		\ 				(((c)<< AFMT_CHANNEL_SHIFT)&		\ 				AFMT_CHANNEL_MASK) |			\ 				(((e)<< AFMT_EXTCHANNEL_SHIFT)&	\ 				AFMT_EXTCHANNEL_MASK))
end_define

begin_define
define|#
directive|define
name|AFMT_U8_NE
value|AFMT_U8
end_define

begin_define
define|#
directive|define
name|AFMT_S8_NE
value|AFMT_S8
end_define

begin_define
define|#
directive|define
name|AFMT_SIGNED_NE
value|(AFMT_S8_NE | AFMT_S16_NE | AFMT_S24_NE | AFMT_S32_NE)
end_define

begin_define
define|#
directive|define
name|AFMT_NE
value|(AFMT_SIGNED_NE | AFMT_U8_NE | AFMT_U16_NE |	\ 			 AFMT_U24_NE | AFMT_U32_NE)
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
name|SND_DEV_DSPHW_PLAY
value|11
end_define

begin_comment
comment|/* specific playback channel */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSPHW_VPLAY
value|12
end_define

begin_comment
comment|/* specific virtual playback channel */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSPHW_REC
value|13
end_define

begin_comment
comment|/* specific record channel */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSPHW_VREC
value|14
end_define

begin_comment
comment|/* specific virtual record channel */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSPHW_CD
value|15
end_define

begin_comment
comment|/* s16le/stereo 44100Hz CD */
end_comment

begin_comment
comment|/*   * OSSv4 compatible device. For now, it serve no purpose and  * the cloning itself will forward the request to ordinary /dev/dsp  * instead.  */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP_MMAP
value|16
end_define

begin_comment
comment|/* /dev/dsp_mmap     */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP_AC3
value|17
end_define

begin_comment
comment|/* /dev/dsp_ac3      */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP_MULTICH
value|18
end_define

begin_comment
comment|/* /dev/dsp_multich  */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP_SPDIFOUT
value|19
end_define

begin_comment
comment|/* /dev/dsp_spdifout */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_DSP_SPDIFIN
value|20
end_define

begin_comment
comment|/* /dev/dsp_spdifin  */
end_comment

begin_define
define|#
directive|define
name|SND_DEV_LAST
value|SND_DEV_DSP_SPDIFIN
end_define

begin_define
define|#
directive|define
name|SND_DEV_MAX
value|PCMMAXDEV
end_define

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
name|int
name|pcm_setvchans
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|direction
parameter_list|,
name|int
name|newcnt
parameter_list|,
name|int
name|num
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
name|char
modifier|*
name|comm
parameter_list|,
name|int
name|devunit
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
name|int
name|num
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
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sndstat_release
parameter_list|(
name|struct
name|thread
modifier|*
name|td
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

begin_comment
comment|/*  * this is rather kludgey- we need to duplicate these struct def'ns from sound.c  * so that the macro versions of pcm_{,un}lock can dereference them.  * we also have to do this now makedev() has gone away.  */
end_comment

begin_struct
struct|struct
name|snddev_info
block|{
struct|struct
block|{
struct|struct
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcm_channel
argument_list|)
name|head
expr_stmt|;
struct|struct
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcm_channel
argument_list|)
name|head
expr_stmt|;
block|}
name|busy
struct|;
struct|struct
block|{
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|pcm_channel
argument_list|)
name|head
expr_stmt|;
block|}
name|opened
struct|;
block|}
name|pcm
struct|;
block|}
name|channels
struct|;
name|TAILQ_HEAD
argument_list|(
argument|dsp_cdevinfo_linkhead
argument_list|,
argument|dsp_cdevinfo
argument_list|)
name|dsp_cdevinfo_pool
expr_stmt|;
name|struct
name|snd_clone
modifier|*
name|clones
decl_stmt|;
name|unsigned
name|devcount
decl_stmt|,
name|playcount
decl_stmt|,
name|reccount
decl_stmt|,
name|pvchancount
decl_stmt|,
name|rvchancount
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
name|uint32_t
name|pvchanrate
decl_stmt|,
name|pvchanformat
decl_stmt|;
name|uint32_t
name|rvchanrate
decl_stmt|,
name|rvchanformat
decl_stmt|;
name|int32_t
name|eqpreamp
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|play_sysctl_ctx
decl_stmt|,
name|rec_sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|play_sysctl_tree
decl_stmt|,
modifier|*
name|rec_sysctl_tree
decl_stmt|;
name|struct
name|cv
name|cv
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

begin_function_decl
name|int
name|sound_oss_card_info
parameter_list|(
name|oss_card_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PCM_LOCKOWNED
parameter_list|(
name|d
parameter_list|)
value|mtx_owned((d)->lock)
end_define

begin_define
define|#
directive|define
name|PCM_LOCK
parameter_list|(
name|d
parameter_list|)
value|mtx_lock((d)->lock)
end_define

begin_define
define|#
directive|define
name|PCM_UNLOCK
parameter_list|(
name|d
parameter_list|)
value|mtx_unlock((d)->lock)
end_define

begin_define
define|#
directive|define
name|PCM_TRYLOCK
parameter_list|(
name|d
parameter_list|)
value|mtx_trylock((d)->lock)
end_define

begin_define
define|#
directive|define
name|PCM_LOCKASSERT
parameter_list|(
name|d
parameter_list|)
value|mtx_assert((d)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|PCM_UNLOCKASSERT
parameter_list|(
name|d
parameter_list|)
value|mtx_assert((d)->lock, MA_NOTOWNED)
end_define

begin_comment
comment|/*  * For PCM_[WAIT | ACQUIRE | RELEASE], be sure to surround these  * with PCM_LOCK/UNLOCK() sequence, or I'll come to gnaw upon you!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SND_DIAGNOSTIC
end_ifdef

begin_define
define|#
directive|define
name|PCM_WAIT
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (!PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [PCM WAIT] Mutex not owned!",		\ 		    __func__, __LINE__);				\ 	while ((x)->flags& SD_F_BUSY) {				\ 		if (snd_verbose> 3)					\ 			device_printf((x)->dev,				\ 			    "%s(%d): [PCM WAIT] calling cv_wait().\n",	\ 			    __func__, __LINE__);			\ 		cv_wait(&(x)->cv, (x)->lock);				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_ACQUIRE
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (!PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [PCM ACQUIRE] Mutex not owned!",		\ 		    __func__, __LINE__);				\ 	if ((x)->flags& SD_F_BUSY)					\ 		panic("%s(%d): [PCM ACQUIRE] "				\ 		    "Trying to acquire BUSY cv!", __func__, __LINE__);	\ 	(x)->flags |= SD_F_BUSY;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_RELEASE
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (!PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [PCM RELEASE] Mutex not owned!",		\ 		    __func__, __LINE__);				\ 	if ((x)->flags& SD_F_BUSY) {					\ 		(x)->flags&= ~SD_F_BUSY;				\ 		if ((x)->cv.cv_waiters != 0) {				\ 			if ((x)->cv.cv_waiters> 1&& snd_verbose> 3)	\ 				device_printf((x)->dev,			\ 				    "%s(%d): [PCM RELEASE] "		\ 				    "cv_waiters=%d> 1!\n",		\ 				    __func__, __LINE__,			\ 				    (x)->cv.cv_waiters);		\ 			cv_broadcast(&(x)->cv);				\ 		}							\ 	} else								\ 		panic("%s(%d): [PCM RELEASE] Releasing non-BUSY cv!",	\ 		    __func__, __LINE__);				\ } while (0)
end_define

begin_comment
comment|/* Quick version, for shorter path. */
end_comment

begin_define
define|#
directive|define
name|PCM_ACQUIRE_QUICK
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [PCM ACQUIRE QUICK] Mutex owned!",	\ 		    __func__, __LINE__);				\ 	PCM_LOCK(x);							\ 	PCM_WAIT(x);							\ 	PCM_ACQUIRE(x);							\ 	PCM_UNLOCK(x);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_RELEASE_QUICK
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [PCM RELEASE QUICK] Mutex owned!",	\ 		    __func__, __LINE__);				\ 	PCM_LOCK(x);							\ 	PCM_RELEASE(x);							\ 	PCM_UNLOCK(x);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_BUSYASSERT
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (!((x) != NULL&& ((x)->flags& SD_F_BUSY)))			\ 		panic("%s(%d): [PCM BUSYASSERT] "			\ 		    "Failed, snddev_info=%p", __func__, __LINE__, x);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_GIANT_ENTER
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	int _pcm_giant = 0;						\ 	if (PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [GIANT ENTER] PCM lock owned!",		\ 		    __func__, __LINE__);				\ 	if (mtx_owned(&Giant) != 0&& snd_verbose> 3)			\ 		device_printf((x)->dev,					\ 		    "%s(%d): [GIANT ENTER] Giant owned!\n",		\ 		    __func__, __LINE__);				\ 	if (!((x)->flags& SD_F_MPSAFE)&& mtx_owned(&Giant) == 0)	\ 		do {							\ 			mtx_lock(&Giant);				\ 			_pcm_giant = 1;					\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|PCM_GIANT_EXIT
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	if (PCM_LOCKOWNED(x))						\ 		panic("%s(%d): [GIANT EXIT] PCM lock owned!",		\ 		    __func__, __LINE__);				\ 	if (!(_pcm_giant == 0 || _pcm_giant == 1))			\ 		panic("%s(%d): [GIANT EXIT] _pcm_giant screwed!",	\ 		    __func__, __LINE__);				\ 	if ((x)->flags& SD_F_MPSAFE) {					\ 		if (_pcm_giant == 1)					\ 			panic("%s(%d): [GIANT EXIT] MPSAFE Giant?",	\ 			    __func__, __LINE__);			\ 		if (mtx_owned(&Giant) != 0&& snd_verbose> 3)		\ 			device_printf((x)->dev,				\ 			    "%s(%d): [GIANT EXIT] Giant owned!\n",	\ 			    __func__, __LINE__);			\ 	}								\ 	if (_pcm_giant != 0) {						\ 		if (mtx_owned(&Giant) == 0)				\ 			panic("%s(%d): [GIANT EXIT] Giant not owned!",	\ 			    __func__, __LINE__);			\ 		_pcm_giant = 0;						\ 		mtx_unlock(&Giant);					\ 	}								\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SND_DIAGNOSTIC */
end_comment

begin_define
define|#
directive|define
name|PCM_WAIT
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	PCM_LOCKASSERT(x);						\ 	while ((x)->flags& SD_F_BUSY)					\ 		cv_wait(&(x)->cv, (x)->lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_ACQUIRE
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	PCM_LOCKASSERT(x);						\ 	KASSERT(!((x)->flags& SD_F_BUSY),				\ 	    ("%s(%d): [PCM ACQUIRE] Trying to acquire BUSY cv!",	\ 	    __func__, __LINE__));					\ 	(x)->flags |= SD_F_BUSY;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_RELEASE
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	PCM_LOCKASSERT(x);						\ 	KASSERT((x)->flags& SD_F_BUSY,					\ 	    ("%s(%d): [PCM RELEASE] Releasing non-BUSY cv!",		\ 	    __func__, __LINE__));					\ 	(x)->flags&= ~SD_F_BUSY;					\ 	if ((x)->cv.cv_waiters != 0)					\ 		cv_broadcast(&(x)->cv);					\ } while (0)
end_define

begin_comment
comment|/* Quick version, for shorter path. */
end_comment

begin_define
define|#
directive|define
name|PCM_ACQUIRE_QUICK
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	PCM_UNLOCKASSERT(x);						\ 	PCM_LOCK(x);							\ 	PCM_WAIT(x);							\ 	PCM_ACQUIRE(x);							\ 	PCM_UNLOCK(x);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_RELEASE_QUICK
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	PCM_UNLOCKASSERT(x);						\ 	PCM_LOCK(x);							\ 	PCM_RELEASE(x);							\ 	PCM_UNLOCK(x);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|PCM_BUSYASSERT
parameter_list|(
name|x
parameter_list|)
value|KASSERT(x != NULL&&			\ 				    ((x)->flags& SD_F_BUSY),		\ 				    ("%s(%d): [PCM BUSYASSERT] "	\ 				    "Failed, snddev_info=%p",		\ 				    __func__, __LINE__, x))
end_define

begin_define
define|#
directive|define
name|PCM_GIANT_ENTER
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	int _pcm_giant = 0;						\ 	PCM_UNLOCKASSERT(x);						\ 	if (!((x)->flags& SD_F_MPSAFE)&& mtx_owned(&Giant) == 0)	\ 		do {							\ 			mtx_lock(&Giant);				\ 			_pcm_giant = 1;					\ 		} while (0)
end_define

begin_define
define|#
directive|define
name|PCM_GIANT_EXIT
parameter_list|(
name|x
parameter_list|)
value|do {					\ 	PCM_UNLOCKASSERT(x);						\ 	KASSERT(_pcm_giant == 0 || _pcm_giant == 1,			\ 	    ("%s(%d): [GIANT EXIT] _pcm_giant screwed!",		\ 	    __func__, __LINE__));					\ 	KASSERT(!((x)->flags& SD_F_MPSAFE) ||				\ 	    (((x)->flags& SD_F_MPSAFE)&& _pcm_giant == 0),		\ 	    ("%s(%d): [GIANT EXIT] MPSAFE Giant?",			\ 	    __func__, __LINE__));					\ 	if (_pcm_giant != 0) {						\ 		mtx_assert(&Giant, MA_OWNED);				\ 		_pcm_giant = 0;						\ 		mtx_unlock(&Giant);					\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SND_DIAGNOSTIC */
end_comment

begin_define
define|#
directive|define
name|PCM_GIANT_LEAVE
parameter_list|(
name|x
parameter_list|)
define|\
value|PCM_GIANT_EXIT(x);						\ } while (0)
end_define

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

