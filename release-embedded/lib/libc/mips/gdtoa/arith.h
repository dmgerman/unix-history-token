begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: arith.h,v 1.1 2006/01/25 15:33:28 kleink Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|IEEE_BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IEEE_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

