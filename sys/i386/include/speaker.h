begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SPEAKER_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SPEAKER_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__CC_SUPPORTS_WARNING
end_ifdef

begin_warning
warning|#
directive|warning
literal|"machine/speaker.h is deprecated.  Include dev/speaker/speaker.h instead."
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/speaker/speaker.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SPEAKER_H_ */
end_comment

end_unit

