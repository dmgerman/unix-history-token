begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound.h  *  * include file for kernel sources, sound driver.  *   * Copyright by Hannu Savolainen 1995  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"pcm.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPCM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NPCM
operator|>
literal|0
end_if

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
name|KERNEL
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
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

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
name|d_poll_t
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|irq_proc_t
function_decl|)
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OS_H_ */
end_comment

begin_comment
comment|/*        * descriptor of a dma buffer. See dmabuf.c for documentation.  * (rp,rl) and (fp,fl) identify the READY and FREE regions of the  * buffer. dl contains the length used for dma transfer, dl>0 also  * means that the channel is busy and there is a DMA transfer in progress.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_snd_dbuf
block|{
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|bufsize
decl_stmt|;
specifier|volatile
name|int
name|rp
decl_stmt|,
name|fp
decl_stmt|;
comment|/* pointers to the ready and free area */
specifier|volatile
name|int
name|dl
decl_stmt|;
comment|/* transfer size */
specifier|volatile
name|int
name|rl
decl_stmt|,
name|fl
decl_stmt|;
comment|/* lenght of ready and free areas. */
name|int
name|int_count
decl_stmt|;
name|int
name|chan
decl_stmt|;
comment|/* dma channel */
name|int
name|sample_size
decl_stmt|;
comment|/* 1, 2, 4 */
name|struct
name|selinfo
name|sel
decl_stmt|;
name|u_long
name|total
decl_stmt|;
comment|/* total bytes processed */
name|u_long
name|prev_total
decl_stmt|;
comment|/* copy of the above when GETxPTR called */
block|}
name|snd_dbuf
typedef|;
end_typedef

begin_comment
comment|/*  * descriptor of audio operations ...  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_snddev_info
name|snddev_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|snd_callback_t
function_decl|)
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_snddev_info
block|{
comment|/*      * the first part of the descriptor is filled up from a      * template.      */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|d_open_t
modifier|*
name|open
decl_stmt|;
name|d_close_t
modifier|*
name|close
decl_stmt|;
name|d_read_t
modifier|*
name|read
decl_stmt|;
name|d_write_t
modifier|*
name|write
decl_stmt|;
name|d_ioctl_t
modifier|*
name|ioctl
decl_stmt|;
name|d_poll_t
modifier|*
name|poll
decl_stmt|;
name|irq_proc_t
modifier|*
name|isr
decl_stmt|;
name|snd_callback_t
modifier|*
name|callback
decl_stmt|;
name|int
name|bufsize
decl_stmt|;
comment|/* space used for buffers */
name|u_long
name|audio_fmt
decl_stmt|;
comment|/* supported audio formats */
comment|/*      * combinations of the following flags are used as second argument in      * the callback from the dma module to the device-specific routines.      */
define|#
directive|define
name|SND_CB_RD
value|0x100
comment|/* read callback */
define|#
directive|define
name|SND_CB_WR
value|0x200
comment|/* write callback */
define|#
directive|define
name|SND_CB_REASON_MASK
value|0xff
define|#
directive|define
name|SND_CB_START
value|0x01
comment|/* start dma op */
define|#
directive|define
name|SND_CB_STOP
value|0x03
comment|/* stop dma op */
define|#
directive|define
name|SND_CB_ABORT
value|0x04
comment|/* abort dma op */
define|#
directive|define
name|SND_CB_INIT
value|0x05
comment|/* init board parameters */
comment|/* init can only be called with int enabled and 	 * no pending DMA activity. 	 */
comment|/*      * whereas from here, parameters are set at runtime.      */
name|int
name|io_base
decl_stmt|;
comment|/* primary I/O address for the board */
name|int
name|alt_base
decl_stmt|;
comment|/* some codecs are accessible as SB+WSS... */
name|int
name|conf_base
decl_stmt|;
comment|/* and the opti931 also has a config space */
name|int
name|mix_base
decl_stmt|;
comment|/* base for the mixer... */
name|int
name|midi_base
decl_stmt|;
comment|/* base for the midi */
name|int
name|synth_base
decl_stmt|;
comment|/* base for the synth */
name|int
name|irq
decl_stmt|;
name|int
name|bd_id
decl_stmt|;
comment|/* used to hold board-id info, eg. sb version, 		     * mss codec type, etc. etc. 		     */
name|snd_dbuf
name|dbuf_out
decl_stmt|,
name|dbuf_in
decl_stmt|;
name|int
name|status_ptr
decl_stmt|;
comment|/* used to implement sndstat */
comment|/*          * these parameters describe the operation of the board.          * Generic things like busy flag, speed, etc are here.          */
specifier|volatile
name|u_long
name|flags
decl_stmt|;
comment|/* 32 bits, used for various purposes. */
comment|/*      * we have separate flags for read and write, although in some      * cases this is probably not necessary (e.g. because we cannot      * know how many processes are using the device, we cannot      * distinguish if open, close, abort are for a write or for a      * read).      */
comment|/*      * the following flag is used by open-close routines      * to mark the status of the device.      */
define|#
directive|define
name|SND_F_BUSY
value|0x0001
comment|/* has been opened 	*/
comment|/*      * Only the last close for a device will propagate to the driver.      * Unfortunately, voxware uses 3 different minor numbers      * (dsp, dsp16 and audio) to access the same unit. So, if      * we want to support multiple opens and still keep track of      * what is happening, we also need a separate flag for each minor      * number. These are below...      */
define|#
directive|define
name|SND_F_BUSY_AUDIO
value|0x10000000
define|#
directive|define
name|SND_F_BUSY_DSP
value|0x20000000
define|#
directive|define
name|SND_F_BUSY_DSP16
value|0x40000000
define|#
directive|define
name|SND_F_BUSY_ANY
value|0x70000000
comment|/*      * the next two are used to allow only one pending operation of      * each type.      */
define|#
directive|define
name|SND_F_READING
value|0x0004
comment|/* have a pending read */
define|#
directive|define
name|SND_F_WRITING
value|0x0008
comment|/* have a pending write */
comment|/*      * these mark pending DMA operations. When you have pending dma ops,      * you might get interrupts, so some manipulations of the      * descriptors must be done with interrupts blocked.      */
if|#
directive|if
literal|0
define|#
directive|define
name|SND_F_RD_DMA
value|0x0010
comment|/* read-dma active */
define|#
directive|define
name|SND_F_WR_DMA
value|0x0020
comment|/* write-dma active */
define|#
directive|define
name|SND_F_PENDING_IN
value|(SND_F_READING | SND_F_RD_DMA)
define|#
directive|define
name|SND_F_PENDING_OUT
value|(SND_F_WRITING | SND_F_WR_DMA)
endif|#
directive|endif
define|#
directive|define
name|SND_F_PENDING_IO
value|(SND_F_READING | SND_F_WRITING)
comment|/*      * flag used to mark a pending close.      */
define|#
directive|define
name|SND_F_CLOSING
value|0x0040
comment|/* a pending close */
comment|/*      * if user has not set block size, then make it adaptive      * (0.25s, or the perhaps last read/write ?)      */
define|#
directive|define
name|SND_F_HAS_SIZE
value|0x0080
comment|/* user set block size */
comment|/*      * assorted flags related to operating mode.      */
define|#
directive|define
name|SND_F_STEREO
value|0x0100
comment|/* doing stereo */
define|#
directive|define
name|SND_F_NBIO
value|0x0200
comment|/* do non-blocking i/o */
comment|/*      * the user requested ulaw, but the board does not support it      * natively, so a (software) format conversion is necessary.      * The kernel is not really the place to do this, but since      * many applications expect to use /dev/audio , we do it for      * portability.      */
define|#
directive|define
name|SND_F_XLAT8
value|0x0400
comment|/* u-law<--> 8-bit unsigned */
define|#
directive|define
name|SND_F_XLAT16
value|0x0800
comment|/* u-law<--> 16-bit signed */
comment|/*      * these flags mark a pending abort on a r/w operation.      */
define|#
directive|define
name|SND_F_ABORTING
value|0x1000
comment|/* a pending abort */
comment|/*      * this is used to mark that board initialization is needed, e.g.      * because of a change in sampling rate, format, etc. -- It will      * be done at the next convenient time.      */
define|#
directive|define
name|SND_F_INIT
value|0x4000
comment|/* changed parameters. need init */
name|u_long
name|bd_flags
decl_stmt|;
comment|/* board-specific flags */
name|int
name|play_speed
decl_stmt|,
name|rec_speed
decl_stmt|;
name|int
name|play_blocksize
decl_stmt|,
name|rec_blocksize
decl_stmt|;
comment|/* blocksize for io and dma ops */
name|u_long
name|play_fmt
decl_stmt|,
name|rec_fmt
decl_stmt|;
comment|/* current audio format */
comment|/*      * mixer parameters      */
name|u_long
name|mix_devs
decl_stmt|;
comment|/* existing devices for mixer */
name|u_long
name|mix_rec_devs
decl_stmt|;
comment|/* possible recording sources */
name|u_long
name|mix_recsrc
decl_stmt|;
comment|/* current recording source(s) */
name|u_short
name|mix_levels
index|[
literal|32
index|]
decl_stmt|;
define|#
directive|define
name|wsel
value|dbuf_out.sel
define|#
directive|define
name|rsel
value|dbuf_in.sel
name|u_long
name|interrupts
decl_stmt|;
comment|/* counter of interrupts */
name|u_long
name|magic
decl_stmt|;
define|#
directive|define
name|MAGIC
parameter_list|(
name|unit
parameter_list|)
value|( 0xa4d10de0 + unit )
name|void
modifier|*
name|device_data
decl_stmt|;
comment|/* just in case it is needed...*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * then ioctls and other stuff  */
end_comment

begin_define
define|#
directive|define
name|NPCM_MAX
value|8
end_define

begin_comment
comment|/* Number of supported devices */
end_comment

begin_comment
comment|/*  * Supported card ID numbers (were in soundcard.h...)  */
end_comment

begin_define
define|#
directive|define
name|SNDCARD_ADLIB
value|1
end_define

begin_define
define|#
directive|define
name|SNDCARD_SB
value|2
end_define

begin_define
define|#
directive|define
name|SNDCARD_PAS
value|3
end_define

begin_define
define|#
directive|define
name|SNDCARD_GUS
value|4
end_define

begin_define
define|#
directive|define
name|SNDCARD_MPU401
value|5
end_define

begin_define
define|#
directive|define
name|SNDCARD_SB16
value|6
end_define

begin_define
define|#
directive|define
name|SNDCARD_SB16MIDI
value|7
end_define

begin_define
define|#
directive|define
name|SNDCARD_UART6850
value|8
end_define

begin_define
define|#
directive|define
name|SNDCARD_GUS16
value|9
end_define

begin_define
define|#
directive|define
name|SNDCARD_MSS
value|10
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSS
value|11
end_define

begin_define
define|#
directive|define
name|SNDCARD_SSCAPE
value|12
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSS_MPU
value|13
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSS_MSS
value|14
end_define

begin_define
define|#
directive|define
name|SNDCARD_SSCAPE_MSS
value|15
end_define

begin_define
define|#
directive|define
name|SNDCARD_TRXPRO
value|16
end_define

begin_define
define|#
directive|define
name|SNDCARD_TRXPRO_SB
value|17
end_define

begin_define
define|#
directive|define
name|SNDCARD_TRXPRO_MPU
value|18
end_define

begin_define
define|#
directive|define
name|SNDCARD_MAD16
value|19
end_define

begin_define
define|#
directive|define
name|SNDCARD_MAD16_MPU
value|20
end_define

begin_define
define|#
directive|define
name|SNDCARD_CS4232
value|21
end_define

begin_define
define|#
directive|define
name|SNDCARD_CS4232_MPU
value|22
end_define

begin_define
define|#
directive|define
name|SNDCARD_MAUI
value|23
end_define

begin_define
define|#
directive|define
name|SNDCARD_PSEUDO_MSS
value|24
end_define

begin_comment
comment|/* MSS without WSS regs.*/
end_comment

begin_define
define|#
directive|define
name|SNDCARD_AWE32
value|25
end_define

begin_comment
comment|/*  * values used in bd_id for the mss boards  */
end_comment

begin_define
define|#
directive|define
name|MD_AD1848
value|0x91
end_define

begin_define
define|#
directive|define
name|MD_AD1845
value|0x92
end_define

begin_define
define|#
directive|define
name|MD_CS4248
value|0xA1
end_define

begin_define
define|#
directive|define
name|MD_CS4231
value|0xA2
end_define

begin_define
define|#
directive|define
name|MD_CS4231A
value|0xA3
end_define

begin_define
define|#
directive|define
name|MD_CS4232
value|0xA4
end_define

begin_define
define|#
directive|define
name|MD_CS4232A
value|0xA5
end_define

begin_define
define|#
directive|define
name|MD_CS4236
value|0xA6
end_define

begin_define
define|#
directive|define
name|MD_CS4237
value|0xA7
end_define

begin_define
define|#
directive|define
name|MD_OPTI931
value|0xB1
end_define

begin_define
define|#
directive|define
name|MD_GUSPNP
value|0xB8
end_define

begin_define
define|#
directive|define
name|MD_YM0020
value|0xC1
end_define

begin_define
define|#
directive|define
name|MD_VIVO
value|0xD1
end_define

begin_comment
comment|/*  * TODO: add some card classes rather than specific types.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/snd/soundcard.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|</sys/i386/isa/snd/soundcard.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * many variables should be reduced to a range. Here define a macro  */
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
value|(var) = \ 	((var)<(low)?(low) : (var)>(high)?(high) : (var))
end_define

begin_comment
comment|/*  * finally, all default parameters  */
end_comment

begin_define
define|#
directive|define
name|DSP_BUFFSIZE
value|(65536 - 256)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * the last 256 bytes are room for buggy soundcard to overflow.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"pnp.h"
end_include

begin_if
if|#
directive|if
name|NPNP
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<i386/isa/pnp.h>
end_include

begin_comment
comment|/* XXX pnp support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

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
comment|/* Sequencer output /dev/sequencer (FM 				   synthesizer and MIDI output) */
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
comment|/* #7 not in use now. Was in 2.4. Free for use after v3.0. */
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

begin_define
define|#
directive|define
name|SYNTH_MAX_VOICES
value|32
end_define

begin_struct
struct|struct
name|voice_alloc_info
block|{
name|int
name|max_voice
decl_stmt|;
name|int
name|used_voices
decl_stmt|;
name|int
name|ptr
decl_stmt|;
comment|/* For device specific use */
name|u_short
name|map
index|[
name|SYNTH_MAX_VOICES
index|]
decl_stmt|;
comment|/* (ch<< 8) | (note+1) */
name|int
name|timestamp
decl_stmt|;
name|int
name|alloc_times
index|[
name|SYNTH_MAX_VOICES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|channel_info
block|{
name|int
name|pgm_num
decl_stmt|;
name|int
name|bender_value
decl_stmt|;
name|u_char
name|controllers
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * mixer description structure and macros  */
end_comment

begin_struct
struct|struct
name|mixer_def
block|{
name|u_int
name|regno
range|:
literal|7
decl_stmt|;
name|u_int
name|polarity
range|:
literal|1
decl_stmt|;
comment|/* 1 means reversed */
name|u_int
name|bitoffs
range|:
literal|4
decl_stmt|;
name|u_int
name|nbits
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mixer_def
name|mixer_ent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mixer_def
name|mixer_tab
index|[
literal|32
index|]
index|[
literal|2
index|]
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|FULL_DUPLEX
parameter_list|(
name|d
parameter_list|)
value|(d->dbuf_out.chan != d->dbuf_in.chan)
end_define

begin_define
define|#
directive|define
name|MIX_ENT
parameter_list|(
name|name
parameter_list|,
name|reg_l
parameter_list|,
name|pol_l
parameter_list|,
name|pos_l
parameter_list|,
name|len_l
parameter_list|,
name|reg_r
parameter_list|,
name|pol_r
parameter_list|,
name|pos_r
parameter_list|,
name|len_r
parameter_list|)
define|\
value|{{reg_l, pol_l, pos_l, len_l}, {reg_r, pol_r, pos_r, len_r}}
end_define

begin_define
define|#
directive|define
name|PMIX_ENT
parameter_list|(
name|name
parameter_list|,
name|reg_l
parameter_list|,
name|pos_l
parameter_list|,
name|len_l
parameter_list|,
name|reg_r
parameter_list|,
name|pos_r
parameter_list|,
name|len_r
parameter_list|)
define|\
value|{{reg_l, 0, pos_l, len_l}, {reg_r, 0, pos_r, len_r}}
end_define

begin_define
define|#
directive|define
name|MIX_NONE
parameter_list|(
name|name
parameter_list|)
value|MIX_ENT(name, 0,0,0,0, 0,0,0,0)
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|DDB
end_ifndef

begin_define
define|#
directive|define
name|DDB
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|snddev_info
name|pcm_info
index|[
name|NPCM_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|snddev_info
name|midi_info
index|[
name|NPCM_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|snddev_info
name|synth_info
index|[
name|NPCM_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|nsnd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|snddev_info
modifier|*
name|snddev_last_probed
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|pcmprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midiprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|synthprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcmattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|midiattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|synthattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *      DMA buffer calls  */
end_comment

begin_function_decl
name|void
name|dsp_wrintr
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsp_rdintr
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsp_write_body
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|,
name|struct
name|uio
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsp_read_body
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|,
name|struct
name|uio
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alloc_dbuf
parameter_list|(
name|snd_dbuf
modifier|*
name|d
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_flush
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the following parameters are used in snd_sync and reset_dbuf  * to decide whether or not to restart a channel  */
end_comment

begin_define
define|#
directive|define
name|SND_CHAN_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|SND_CHAN_WR
value|0x1
end_define

begin_define
define|#
directive|define
name|SND_CHAN_RD
value|0x2
end_define

begin_function_decl
name|void
name|reset_dbuf
parameter_list|(
name|snd_dbuf
modifier|*
name|b
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_sync
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|chan
parameter_list|,
name|int
name|threshold
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsp_wrabort
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|restart
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsp_rdabort
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|,
name|int
name|restart
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsp_wr_dmaupdate
parameter_list|(
name|snd_dbuf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsp_rd_dmaupdate
parameter_list|(
name|snd_dbuf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|d_poll_t
name|sndpoll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * library functions (in sound.c)  */
end_comment

begin_function_decl
name|int
name|ask_init
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|translate_bytes
parameter_list|(
name|u_char
modifier|*
name|table
parameter_list|,
name|u_char
modifier|*
name|buff
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_bits
parameter_list|(
name|mixer_tab
modifier|*
name|t
parameter_list|,
name|u_char
modifier|*
name|regval
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
name|chn
parameter_list|,
name|int
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_conflict
parameter_list|(
name|int
name|io_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_set_blocksize
parameter_list|(
name|snddev_info
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_dmastatus1
parameter_list|(
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * routines in ad1848.c and sb_dsp.c which others might use  */
end_comment

begin_function_decl
name|int
name|mss_detect
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_cmd
parameter_list|(
name|int
name|io_base
parameter_list|,
name|u_char
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_cmd2
parameter_list|(
name|int
name|io_base
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_cmd3
parameter_list|(
name|int
name|io_base
parameter_list|,
name|u_char
name|cmd
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_reset_dsp
parameter_list|(
name|int
name|io_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sb_setmixer
parameter_list|(
name|int
name|io_base
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_getmixer
parameter_list|(
name|int
name|io_base
parameter_list|,
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * usage of flags in device config entry (config file)  */
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
comment|/*  * some flags are used in a device-specific manner, so that values can  * be used multiple times.  */
end_comment

begin_define
define|#
directive|define
name|DV_F_TRUE_MSS
value|0x00010000
end_define

begin_comment
comment|/* mss _with_ base regs */
end_comment

begin_comment
comment|/* almost all modern cards do not have this set of registers,      * so it is better to make this the default behaviour      */
end_comment

begin_comment
comment|/*  * the following flags are for PnP cards only and are undocumented  */
end_comment

begin_define
define|#
directive|define
name|DV_PNP_SBCODEC
value|0x1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

