begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sound_config.h  *  * A driver for Soundcards, misc configuration parameters.  *  *   * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/sound/local.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/sound/os.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/sound/soundvers.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PSS_MPU_BASE
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_SSCAPE
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_TRIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_MPU_EMU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ISC
argument_list|)
operator|||
name|defined
argument_list|(
name|SCO
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR42
argument_list|)
end_if

begin_define
define|#
directive|define
name|GENERIC_SYSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Disable the AD1848 driver if there are no other drivers requiring it.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXCLUDE_GUS16
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_MSS
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_PSS
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_GUSMAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_SSCAPE
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_TRIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_AD1848
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PSS_MSS_BASE
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_AD1848
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CONFIGURE_SOUNDCARD
end_undef

begin_undef
undef|#
directive|undef
name|DYNAMIC_BUFFER
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_SOUNDCARD
end_ifdef

begin_define
define|#
directive|define
name|CONFIGURE_SOUNDCARD
end_define

begin_define
define|#
directive|define
name|DYNAMIC_BUFFER
end_define

begin_undef
undef|#
directive|undef
name|LOADABLE_SOUNDCARD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EXCLUDE_SEQUENCER
end_ifdef

begin_define
define|#
directive|define
name|EXCLUDE_MIDI
end_define

begin_define
define|#
directive|define
name|EXCLUDE_YM3812
end_define

begin_define
define|#
directive|define
name|EXCLUDE_OPL3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SND_DEFAULT_ENABLE
end_ifndef

begin_define
define|#
directive|define
name|SND_DEFAULT_ENABLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIGURE_SOUNDCARD
end_ifdef

begin_comment
comment|/* ****** IO-address, DMA and IRQ settings ****  If your card has nonstandard I/O address or IRQ number, change defines    for the following settings in your kernel Makefile */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SBC_BASE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SBC_BASE
value|0x20d2
end_define

begin_comment
comment|/* 0x20d2 is the factory default. */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SBC_BASE
value|0x220
end_define

begin_comment
comment|/* 0x220 is the factory default. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SBC_IRQ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SBC_IRQ
value|10
end_define

begin_comment
comment|/* IQR10 is not the factory default on PC9821.	 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SBC_IRQ
value|5
end_define

begin_comment
comment|/* IQR5 is the factory default.	 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SBC_DMA
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SBC_DMA
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SBC_DMA
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

begin_ifndef
ifndef|#
directive|ifndef
name|SB16_DMA
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SB16_DMA
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SB16_DMA
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SB16MIDI_BASE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SB16MIDI_BASE
value|0x80d2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SB16MIDI_BASE
value|0x300
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AWE32_BASE
end_ifndef

begin_define
define|#
directive|define
name|AWE32_BASE
value|0x620
end_define

begin_comment
comment|/* Default = 0x620-3, 0xA20-3, 0xE20-3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PAS_BASE
end_ifndef

begin_define
define|#
directive|define
name|PAS_BASE
value|0x388
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PAS_IRQ
end_ifndef

begin_define
define|#
directive|define
name|PAS_IRQ
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PAS_DMA
end_ifndef

begin_define
define|#
directive|define
name|PAS_DMA
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS_BASE
end_ifndef

begin_define
define|#
directive|define
name|GUS_BASE
value|0x220
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS_IRQ
end_ifndef

begin_define
define|#
directive|define
name|GUS_IRQ
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS_MIDI_IRQ
end_ifndef

begin_define
define|#
directive|define
name|GUS_MIDI_IRQ
value|GUS_IRQ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS_DMA
end_ifndef

begin_define
define|#
directive|define
name|GUS_DMA
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS_DMA_READ
end_ifndef

begin_define
define|#
directive|define
name|GUS_DMA_READ
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MPU_BASE
end_ifndef

begin_define
define|#
directive|define
name|MPU_BASE
value|0x330
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MPU_IRQ
end_ifndef

begin_define
define|#
directive|define
name|MPU_IRQ
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Echo Personal Sound System */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PSS_BASE
end_ifndef

begin_define
define|#
directive|define
name|PSS_BASE
value|0x220
end_define

begin_comment
comment|/* 0x240 or */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PSS_IRQ
end_ifndef

begin_define
define|#
directive|define
name|PSS_IRQ
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PSS_DMA
end_ifndef

begin_define
define|#
directive|define
name|PSS_DMA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSS_BASE
end_ifndef

begin_define
define|#
directive|define
name|MSS_BASE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSS_DMA
end_ifndef

begin_define
define|#
directive|define
name|MSS_DMA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSS_IRQ
end_ifndef

begin_define
define|#
directive|define
name|MSS_IRQ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS16_BASE
end_ifndef

begin_define
define|#
directive|define
name|GUS16_BASE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS16_DMA
end_ifndef

begin_define
define|#
directive|define
name|GUS16_DMA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GUS16_IRQ
end_ifndef

begin_define
define|#
directive|define
name|GUS16_IRQ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSCAPE_BASE
end_ifndef

begin_define
define|#
directive|define
name|SSCAPE_BASE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSCAPE_DMA
end_ifndef

begin_define
define|#
directive|define
name|SSCAPE_DMA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSCAPE_IRQ
end_ifndef

begin_define
define|#
directive|define
name|SSCAPE_IRQ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSCAPE_MSS_BASE
end_ifndef

begin_define
define|#
directive|define
name|SSCAPE_MSS_BASE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSCAPE_MSS_DMA
end_ifndef

begin_define
define|#
directive|define
name|SSCAPE_MSS_DMA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SSCAPE_MSS_IRQ
end_ifndef

begin_define
define|#
directive|define
name|SSCAPE_MSS_IRQ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRIX_BASE
end_ifndef

begin_define
define|#
directive|define
name|TRIX_BASE
value|0x530
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRIX_IRQ
end_ifndef

begin_define
define|#
directive|define
name|TRIX_IRQ
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRIX_DMA
end_ifndef

begin_define
define|#
directive|define
name|TRIX_DMA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U6850_BASE
end_ifndef

begin_define
define|#
directive|define
name|U6850_BASE
value|0x330
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U6850_IRQ
end_ifndef

begin_define
define|#
directive|define
name|U6850_IRQ
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U6850_DMA
end_ifndef

begin_define
define|#
directive|define
name|U6850_DMA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_REALTIME_FACTOR
end_ifndef

begin_define
define|#
directive|define
name|MAX_REALTIME_FACTOR
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************* PCM DMA buffer sizes *******************/
end_comment

begin_comment
comment|/* If you are using high playback or recording speeds, the default buffersize    is too small. DSP_BUFFSIZE must be 64k or less.     A rule of thumb is 64k for PAS16, 32k for PAS+, 16k for SB Pro and    4k for SB.     If you change the DSP_BUFFSIZE, don't modify this file.    Use the make config command instead. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DSP_BUFFSIZE
end_ifndef

begin_define
define|#
directive|define
name|DSP_BUFFSIZE
value|(4096)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DSP_BUFFCOUNT
end_ifndef

begin_define
define|#
directive|define
name|DSP_BUFFCOUNT
value|2
end_define

begin_comment
comment|/* 2 is recommended. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DMA_AUTOINIT
value|0x10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|FM_MONO
value|0x28d2
end_define

begin_comment
comment|/* This is the I/O address used by AdLib */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FM_MONO
value|0x388
end_define

begin_comment
comment|/* This is the I/O address used by AdLib */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SEQ_MAX_QUEUE is the maximum number of sequencer events buffered by the    driver. (There is no need to alter this) */
end_comment

begin_define
define|#
directive|define
name|SEQ_MAX_QUEUE
value|1024
end_define

begin_define
define|#
directive|define
name|SBFM_MAXINSTR
value|(256)
end_define

begin_comment
comment|/* Size of the FM Instrument bank */
end_comment

begin_comment
comment|/* 128 instruments for general MIDI setup and 16 unassigned	 */
end_comment

begin_comment
comment|/*  * Minor numbers for the sound driver.  *  * Unfortunately Creative called the codec chip of SB as a DSP. For this  * reason the /dev/dsp is reserved for digitized audio use. There is a  * device for true DSP processors but it will be called something else.  * In v3.0 it's /dev/sndproc but this could be a temporary solution.  */
end_comment

begin_define
define|#
directive|define
name|SND_NDEVS
value|256
end_define

begin_comment
comment|/* Number of supported devices */
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
comment|/* /dev/sequecer, level 2 interface */
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
name|MAX_AUDIO_DEV
value|5
end_define

begin_define
define|#
directive|define
name|MAX_MIXER_DEV
value|5
end_define

begin_define
define|#
directive|define
name|MAX_SYNTH_DEV
value|3
end_define

begin_define
define|#
directive|define
name|MAX_MIDI_DEV
value|6
end_define

begin_define
define|#
directive|define
name|MAX_TIMER_DEV
value|3
end_define

begin_struct
struct|struct
name|fileinfo
block|{
name|int
name|mode
decl_stmt|;
comment|/* Open mode */
name|DECLARE_FILE
argument_list|()
expr_stmt|;
comment|/* Reference to file-flags. OS-dependent. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|address_info
block|{
name|int
name|io_base
decl_stmt|;
name|int
name|irq
decl_stmt|;
name|int
name|dma
decl_stmt|;
comment|/* write dma channel */
name|int
name|dma_read
decl_stmt|;
comment|/* read dma channel */
name|int
name|always_detect
decl_stmt|;
comment|/* 1=Trust me, it's there */
block|}
struct|;
end_struct

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
name|unsigned
name|short
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
name|unsigned
name|char
name|controllers
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Process wakeup reasons  */
end_comment

begin_define
define|#
directive|define
name|WK_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|WK_WAKEUP
value|0x01
end_define

begin_define
define|#
directive|define
name|WK_TIMEOUT
value|0x02
end_define

begin_define
define|#
directive|define
name|WK_SIGNAL
value|0x04
end_define

begin_define
define|#
directive|define
name|WK_SLEEP
value|0x08
end_define

begin_define
define|#
directive|define
name|OPEN_READ
value|1
end_define

begin_define
define|#
directive|define
name|OPEN_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|OPEN_READWRITE
value|3
end_define

begin_include
include|#
directive|include
file|<i386/isa/sound/sound_calls.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/sound/dev_table.h>
end_include

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
name|AUDIO_DDB
end_ifndef

begin_define
define|#
directive|define
name|AUDIO_DDB
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIMER_ARMED
value|121234
end_define

begin_define
define|#
directive|define
name|TIMER_NOT_ARMED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

