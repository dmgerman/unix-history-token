begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* for FreeBSD */
end_comment

begin_comment
comment|/*  * local.h,v 1.11 1994/11/01 17:26:50 ache Exp  */
end_comment

begin_include
include|#
directive|include
file|"snd.h"
end_include

begin_include
include|#
directive|include
file|<param.h>
end_include

begin_include
include|#
directive|include
file|<systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_UART6850
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_UART6850
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|SOUND_VERSION_STRING
value|"2.90-2"
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
value|"smpatel"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_HOST
value|"xi.dorm.umd.edu"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DOMAIN
value|"dorm.umd.edu"
end_define

begin_comment
comment|/* Reversed the VoxWare EXCLUDE options -Sujal Patel (smpatel@wam.umd.edu) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_PAS
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_PAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_SB
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_SB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_ADLIB
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_ADLIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_GUS
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_GUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_MPU401
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_MPU401
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_UART6850
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_UART6850
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_GUS16
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_GUS16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_GUSMAX
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_GUSMAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_MSS
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_MSS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_SBPRO
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_SBPRO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXCLUDE_SB16
end_ifndef

begin_define
define|#
directive|define
name|EXCLUDE_SB16
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

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_PAS
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_PAS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_SB
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_SB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_ADLIB
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_ADLIB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_GUS
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_GUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_MPU401
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_MPU401
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_UART6850
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_UART6850
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_PSS
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_PSS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_GUS16
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_GUS16
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_GUSMAX
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_GUSMAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_MSS
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_MSS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_SBPRO
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_SBPRO
end_undef

begin_undef
undef|#
directive|undef
name|EXCLUDE_SB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_SB16
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_SB16
end_undef

begin_undef
undef|#
directive|undef
name|EXCLUDE_SB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUDIO_YM3812
end_ifdef

begin_undef
undef|#
directive|undef
name|EXCLUDE_YM3812
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

