begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CONSOLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CONSOLE_H_
end_define

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_warning
warning|#
directive|warning
literal|"this file includes<machine/console.h> which is deprecated, use<sys/{kb,cons,fb}io.h> instead"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/fbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CONSOLE_H_ */
end_comment

end_unit

