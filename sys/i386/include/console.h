begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_error
error|#
directive|error
literal|"this file includes<machine/console.h> which is deprecated, use<sys/{kb,cons,fb}io.h> instead"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

