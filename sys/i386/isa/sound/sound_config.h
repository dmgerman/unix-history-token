begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sound_config.h  *  * A driver for Soundcards, misc configuration parameters.  *  *   * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EXCLUDE_SEQUENCER
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_MIDI
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_MIDI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_YM3812
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_YM3812
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_OPL3
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_OPL3
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
comment|/** UWM - new MIDI stuff **/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXCLUDE_CHIP_MIDI
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_PRO_MIDI
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_PRO_MIDI
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
comment|/** UWM - stuff **/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXCLUDE_SEQUENCER
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_AUDIO
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|CONFIGURE_SOUNDCARD
end_undef

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

begin_ifndef
ifndef|#
directive|ifndef
name|SBC_IRQ
end_ifndef

begin_define
define|#
directive|define
name|SBC_IRQ
value|7
end_define

begin_comment
comment|/* IQR7 is the factory default.	 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SBC_DMA
end_ifndef

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

begin_define
define|#
directive|define
name|SND_MAJOR
value|14
end_define

begin_define
define|#
directive|define
name|FM_MONO
value|0x388
end_define

begin_comment
comment|/* This is the I/O address used by AdLib */
end_comment

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
comment|/* Size of the FM Instrument 						   bank				 */
end_comment

begin_comment
comment|/* 128 instruments for general MIDI setup and 16 unassigned	 */
end_comment

begin_define
define|#
directive|define
name|SND_NDEVS
value|50
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
comment|/* MIDI input /dev/midin (not implemented 				   yet) */
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
comment|/* /dev/sndstatus */
end_comment

begin_comment
comment|/* UWM ... note add new MIDI devices here..    *  Also do not forget to add table midi_supported[]  *  Minor numbers for on-chip midi devices start from 15.. and   *  should be contiguous.. viz. 15,16,17....  * ERROR!!!!!!!!! NO NO. Minor numbers above 15 are reserved!!!!!! Hannu  *  Also note the max # of midi devices as MAX_MIDI_DEV  */
end_comment

begin_define
define|#
directive|define
name|CMIDI_DEV_PRO
value|15
end_define

begin_comment
comment|/* Chip midi device == /dev/pro_midi */
end_comment

begin_comment
comment|/*  *  Add other midis here... 		. 		. 		. 		.  */
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

begin_define
define|#
directive|define
name|MAX_DSP_DEV
value|3
end_define

begin_define
define|#
directive|define
name|MAX_MIXER_DEV
value|1
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
block|}
struct|;
end_struct

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
file|"os.h"
end_include

begin_include
include|#
directive|include
file|"sound_calls.h"
end_include

begin_include
include|#
directive|include
file|"dev_table.h"
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

