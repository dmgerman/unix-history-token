begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_warning
warning|#
directive|warning
literal|"this file includes<machine/mouse.h> which is deprecated, use<sys/mouse.h> instead"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mouse.h>
end_include

end_unit

