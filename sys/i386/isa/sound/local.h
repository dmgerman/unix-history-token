begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* for FreeBSD */
end_comment

begin_comment
comment|/*  * $Id: local.h,v 1.9 1994/09/27 17:58:19 davidg Exp $  */
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
value|"2.90-2"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DATE
value|"Thu Sep 29 15:33:39 PDT 1994"
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
value|"pal-r32-a07b.slip.nts.uci.edu"
end_define

begin_define
define|#
directive|define
name|SOUND_CONFIG_DOMAIN
value|""
end_define

end_unit

