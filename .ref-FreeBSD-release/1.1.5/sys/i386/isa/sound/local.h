begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* for FreeBSD */
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
name|DSP_BUFFSIZE
value|65536
end_define

begin_define
define|#
directive|define
name|NO_AUTODMA
end_define

begin_comment
comment|/* still */
end_comment

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
value|"2.5"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DATE
value|"Sat Apr 23 07:45:17 MSD 1994"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_BY
value|"ache"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_HOST
value|"dream.demos.su"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DOMAIN
value|""
end_define

end_unit

