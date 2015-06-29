begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is in the public domain.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<x86/frame.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__I386_FRAME_H__
end_ifndef

begin_define
define|#
directive|define
name|__i386_FRAME_H__
end_define

begin_define
define|#
directive|define
name|CS_SECURE
parameter_list|(
name|cs
parameter_list|)
value|(ISPL(cs) == SEL_UPL)
end_define

begin_define
define|#
directive|define
name|EFL_SECURE
parameter_list|(
name|ef
parameter_list|,
name|oef
parameter_list|)
value|((((ef) ^ (oef))& ~PSL_USERCHANGE) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

