begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Cameron Grant<gandalf@vilnya.demon.co.uk>  * Copyright by Hannu Savolainen 1995  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
operator|>
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

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
file|<isa/isavar.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SND_DYNSYSCTL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INTR_MPSAFE
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|isa_device
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|d_open_t
value|void
end_define

begin_define
define|#
directive|define
name|d_close_t
value|void
end_define

begin_define
define|#
directive|define
name|d_read_t
value|void
end_define

begin_define
define|#
directive|define
name|d_write_t
value|void
end_define

begin_define
define|#
directive|define
name|d_ioctl_t
value|void
end_define

begin_define
define|#
directive|define
name|d_select_t
value|void
end_define

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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SND_STATUSLEN
value|64
end_define

begin_comment
comment|/* descriptor of audio device */
end_comment

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
name|chancount
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
name|int
name|inprog
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
name|sysctl_ctx_list
name|sysctl_tree
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree_top
decl_stmt|;
name|void
modifier|*
name|lock
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|ISADMA_WRITE
end_ifndef

begin_define
define|#
directive|define
name|ISADMA_WRITE
value|B_WRITE
end_define

begin_define
define|#
directive|define
name|ISADMA_READ
value|B_READ
end_define

begin_define
define|#
directive|define
name|ISADMA_RAW
value|B_RAW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCM_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|PCM_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|PCM_PREFVER
value|PCM_MODVER
end_define

begin_define
define|#
directive|define
name|PCM_MAXVER
value|1
end_define

begin_comment
comment|/* PROPOSAL: each unit needs: status, mixer, dsp, dspW, audio, sequencer, midi-in, seq2, sndproc = 9 devices dspW and audio are deprecated. dsp needs min 64 channels, will give it 256  minor = (unit<< 20) + (dev<< 16) + channel currently minor = (channel<< 16) + (unit<< 4) + dev  nomenclature: 	/dev/pcmX/dsp.(0..255) 	/dev/pcmX/dspW 	/dev/pcmX/audio 	/dev/pcmX/status 	/dev/pcmX/mixer 	[etc.] */
end_comment

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
value|((PCMMINOR(x)& 0x00ff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|PCMUNIT
parameter_list|(
name|x
parameter_list|)
value|((PCMMINOR(x)& 0x000000f0)>> 4)
end_define

begin_define
define|#
directive|define
name|PCMDEV
parameter_list|(
name|x
parameter_list|)
value|(PCMMINOR(x)& 0x0000000f)
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
value|((((c)& 0xff)<< 16) | (((u)& 0x0f)<< 4) | ((d)& 0x0f))
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
name|AFMT_16BIT
value|(AFMT_S16_LE | AFMT_S16_BE | AFMT_U16_LE | AFMT_U16_BE)
end_define

begin_define
define|#
directive|define
name|AFMT_8BIT
value|(AFMT_U8 | AFMT_S8)
end_define

begin_define
define|#
directive|define
name|AFMT_SIGNED
value|(AFMT_S16_LE | AFMT_S16_BE | AFMT_S8)
end_define

begin_define
define|#
directive|define
name|AFMT_BIGENDIAN
value|(AFMT_S16_BE | AFMT_U16_BE)
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
comment|/*  * Major nuber for the sound driver.  */
end_comment

begin_define
define|#
directive|define
name|SND_CDEV_MAJOR
value|30
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|snd_unit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|pcm_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * some macros for debugging purposes  * DDB/DEB to enable/disable debugging stuff  * BVDDB   to enable debugging when bootverbose  */
end_comment

begin_define
define|#
directive|define
name|DDB
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/* XXX */
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
name|pcm_chnalloc
parameter_list|(
name|struct
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|direction
parameter_list|,
name|pid_t
name|pid
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

begin_function_decl
name|void
name|snd_mtxlock
parameter_list|(
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_mtxunlock
parameter_list|(
name|void
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
comment|/* ought to be made obsolete */
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

end_unit

