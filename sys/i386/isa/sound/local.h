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
name|SELECTED_SOUND_OPTIONS
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|SOUND_VERSION_STRING
value|"2.4"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DATE
value|"Mon Mar 7 23:54:09 PST 1994"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_BY
value|"swallace"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_HOST
value|"freefall.cdrom.com"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DOMAIN
value|""
end_define

end_unit

