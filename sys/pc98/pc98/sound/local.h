begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* for FreeBSD */
end_comment

begin_comment
comment|/*  * $Id: local.h,v 1.11 1994/11/01 17:26:50 ache Exp  */
end_comment

begin_define
define|#
directive|define
name|DSP_BUFFSIZE
value|65536
end_define

begin_define
define|#
directive|define
name|SELECTED_SOUND_OPTIONS
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DATE
value|"Sun Feb 5 14:38:12 EST 1995"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_BY
value|"freebsd-hackers"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_HOST
value|"freefall"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DOMAIN
value|"cdrom.com"
end_define

begin_comment
comment|/* determine if sound code should be compiled */
end_comment

begin_include
include|#
directive|include
file|"snd.h"
end_include

begin_if
if|#
directive|if
name|NSND
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|KERNEL_SOUNDCARD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ALLOW_SELECT
end_define

begin_comment
comment|/* PSS code does not work */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_PSS
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_PSS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gus.h"
end_include

begin_if
if|#
directive|if
name|NGUS
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_GUS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_GUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gusxvi.h"
end_include

begin_if
if|#
directive|if
name|NGUSXVI
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_GUS16
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_GUS16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mss.h"
end_include

begin_if
if|#
directive|if
name|NMSS
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_MSS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_MSS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"trix.h"
end_include

begin_if
if|#
directive|if
name|NTRIX
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_TRIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_TRIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sscape.h"
end_include

begin_if
if|#
directive|if
name|NSSCAPE
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_SSCAPE
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_SSCAPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NGUS
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_GUSMAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_GUSMAX
end_define

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
operator|!
name|defined
argument_list|(
name|EXCLUDE_AD1848
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GUSMAX_MIXER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sb.h"
end_include

begin_if
if|#
directive|if
name|NSB
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_SB
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_SB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sbxvi.h"
end_include

begin_if
if|#
directive|if
name|NSBXVI
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_SB16
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_SB16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sbmidi.h"
end_include

begin_if
if|#
directive|if
name|NSBMIDI
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_SB16MIDI
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_SB16MIDI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pas.h"
end_include

begin_if
if|#
directive|if
name|NPAS
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_PAS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_PAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mpu.h"
end_include

begin_if
if|#
directive|if
name|NMPU
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_MPU401
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_MPU401
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"opl.h"
end_include

begin_if
if|#
directive|if
name|NOPL
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_YM3812
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_YM3812
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uart.h"
end_include

begin_if
if|#
directive|if
name|NUART
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_UART6850
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_UART6850
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|"pcm.h"
end_include

begin_if
if|#
directive|if
name|NPCM
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_PCM86
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_PCM86
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
comment|/* nothing but a sequencer (Adlib/OPL) ? */
end_comment

begin_if
if|#
directive|if
name|NGUS
operator|==
literal|0
operator|&&
name|NSB
operator|==
literal|0
operator|&&
name|NSBMIDI
operator|==
literal|0
operator|&&
name|NPAS
operator|==
literal|0
operator|&&
name|NMPU
operator|==
literal|0
operator|&&
expr|\
name|NUART
operator|==
literal|0
operator|&&
name|NMSS
operator|==
literal|0
end_if

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
name|EXCLUDE_AUDIO
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC98
argument_list|)
operator|||
name|defined
argument_list|(
name|EXCLUDE_PCM86
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_MSS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_AUDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nothing but a Midi (MPU/UART) ? */
end_comment

begin_if
if|#
directive|if
name|NGUS
operator|==
literal|0
operator|&&
name|NSB
operator|==
literal|0
operator|&&
name|NSBMIDI
operator|==
literal|0
operator|&&
name|NPAS
operator|==
literal|0
operator|&&
name|NOPL
operator|==
literal|0
operator|&&
expr|\
name|NMSS
operator|==
literal|0
end_if

begin_comment
comment|/* MPU depends on sequencer timer */
end_comment

begin_if
if|#
directive|if
name|NMPU
operator|==
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_SEQUENCER
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_SEQUENCER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_AUDIO
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC98
argument_list|)
operator|||
name|defined
argument_list|(
name|EXCLUDE_PCM86
argument_list|)
operator|&&
name|defined
argument_list|(
name|EXCLUDE_MSS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCLUDE_AUDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

