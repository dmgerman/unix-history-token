begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sound/awe_config.h  *  * Configuration of AWE32 sound driver  *   version 0.4.2; Sep. 15, 1997  *  * Copyright (C) 1996 Takashi Iwai  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AWE_CONFIG_H_DEF
end_ifndef

begin_define
define|#
directive|define
name|AWE_CONFIG_H_DEF
end_define

begin_comment
comment|/*----------------------------------------------------------------  * system configuration  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* if you're using obsolete VoxWare 3.0.x on Linux 1.2.x (or FreeBSD),  * define the following line.  */
end_comment

begin_undef
undef|#
directive|undef
name|AWE_OBSOLETE_VOXWARE
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|AWE_OBSOLETE_VOXWARE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if you're using OSS-Lite on Linux 2.1.6 or later, define the  * following line.  */
end_comment

begin_undef
undef|#
directive|undef
name|AWE_NEW_KERNEL_INTERFACE
end_undef

begin_comment
comment|/* if you have lowlevel.h in the lowlevel directory (OSS-Lite), define  * the following line.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAS_LOWLEVEL_H
end_undef

begin_comment
comment|/* if your system doesn't support patch manager (OSS 3.7 or newer),  * define the following line.  */
end_comment

begin_undef
undef|#
directive|undef
name|AWE_NO_PATCHMGR
end_undef

begin_comment
comment|/* if your system has an additional parameter (OSS 3.8b5 or newer),  * define this.  */
end_comment

begin_undef
undef|#
directive|undef
name|AWE_OSS38
end_undef

begin_comment
comment|/*----------------------------------------------------------------  * AWE32 card configuration:  * uncomment the following lines only when auto detection doesn't  * work properly on your machine.  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/*#define AWE_DEFAULT_BASE_ADDR	0x620*/
end_comment

begin_comment
comment|/* base port address */
end_comment

begin_comment
comment|/*#define AWE_DEFAULT_MEM_SIZE	512*/
end_comment

begin_comment
comment|/* kbytes */
end_comment

begin_comment
comment|/*----------------------------------------------------------------  * maximum size of soundfont list table:  * you usually don't need to touch this value.  *----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|AWE_MAX_SF_LISTS
value|16
end_define

begin_comment
comment|/*----------------------------------------------------------------  * chunk size of sample and voice tables:  * you usually don't need to touch these values.  *----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|AWE_MAX_SAMPLES
value|400
end_define

begin_define
define|#
directive|define
name|AWE_MAX_INFOS
value|800
end_define

begin_comment
comment|/*----------------------------------------------------------------  * chorus& reverb effects send for FM chip: from 0 to 0xff  * larger numbers often cause weird sounds.  *----------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DEF_FM_CHORUS_DEPTH
value|0x10
end_define

begin_define
define|#
directive|define
name|DEF_FM_REVERB_DEPTH
value|0x10
end_define

begin_comment
comment|/*----------------------------------------------------------------*  * other compile conditions  *----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* initialize FM passthrough even without extended RAM */
end_comment

begin_undef
undef|#
directive|undef
name|AWE_ALWAYS_INIT_FM
end_undef

begin_comment
comment|/* debug on */
end_comment

begin_define
define|#
directive|define
name|AWE_DEBUG_ON
end_define

begin_comment
comment|/* GUS compatible mode */
end_comment

begin_define
define|#
directive|define
name|AWE_HAS_GUS_COMPATIBILITY
end_define

begin_comment
comment|/* accept all notes/sounds off controls */
end_comment

begin_define
define|#
directive|define
name|AWE_ACCEPT_ALL_SOUNDS_CONTROL
end_define

begin_comment
comment|/* add mixer control of emu8000 equalizer */
end_comment

begin_define
define|#
directive|define
name|CONFIG_AWE32_MIXER
end_define

begin_comment
comment|/* look up voices according to MIDI channel priority */
end_comment

begin_define
define|#
directive|define
name|AWE_LOOKUP_MIDI_PRIORITY
end_define

begin_comment
comment|/*----------------------------------------------------------------*/
end_comment

begin_comment
comment|/* reading configuration of sound driver */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AWE_OBSOLETE_VOXWARE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/sound/sound_config.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"sound_config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONFIGURE_SOUNDCARD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_AWE32
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONFIG_AWE32_SYNTH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* AWE_OBSOLETE_VOXWARE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_LOWLEVEL_H
end_ifdef

begin_include
include|#
directive|include
file|"lowlevel.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../sound_config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AWE_OBSOLETE_VOXWARE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AWE_CONFIG_H_DEF */
end_comment

end_unit

