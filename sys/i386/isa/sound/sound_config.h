begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sound_config.h  *  * A driver for Soundcards, misc configuration parameters.  *  * Copyright by Hannu Savolainen 1995  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

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
value|(var) = \                               ((var)<(low)?(low) : (var)>(high)?(high) : (var))
end_define

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

begin_include
include|#
directive|include
file|<i386/isa/sound/local.h>
end_include

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
comment|/* If you are using high playback or recording speeds, the default buffersize    is too small. DSP_BUFFSIZE must be 64k or less.     A rule of thumb is 64k for PAS16, 32k for PAS+, 16k for SB Pro and    4k for SB.     If you change the DSP_BUFFSIZE, don't modify this file.    Use the make config command instead. Seems to allow only 4K, 16K,    32K, 64K.  */
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
value|(32760)
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
value|1
end_define

begin_comment
comment|/* 1 is recommended. */
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

begin_comment
comment|/* XXX never used */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|JAZZ16
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JAZZ_DMA16
end_ifndef

begin_define
define|#
directive|define
name|JAZZ_DMA16
value|5
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
name|int
name|flags
decl_stmt|;
name|int
name|dummy
decl_stmt|;
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
name|int
name|dma2
decl_stmt|;
name|int
name|always_detect
decl_stmt|;
comment|/* 1=Trust me, it's there */
name|char
modifier|*
name|name
decl_stmt|;
name|sound_os_info
modifier|*
name|osp
decl_stmt|;
comment|/* OS specific info */
name|int
name|card_subtype
decl_stmt|;
comment|/* Driver specific. Usually 0 */
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
value|PCM_ENABLE_INPUT
end_define

begin_define
define|#
directive|define
name|OPEN_WRITE
value|PCM_ENABLE_OUTPUT
end_define

begin_define
define|#
directive|define
name|OPEN_READWRITE
value|(OPEN_READ|OPEN_WRITE)
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
name|DDB
end_ifndef

begin_comment
comment|/* #define DDB(x)	x	 XXX */
end_comment

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

