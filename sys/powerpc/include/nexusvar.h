begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_NEXUSVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_NEXUSVAR_H_
end_define

begin_enum
enum|enum
name|nexus_ivars
block|{
name|NEXUS_IVAR_NODE
block|,
name|NEXUS_IVAR_NAME
block|,
name|NEXUS_IVAR_DEVICE_TYPE
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for nexus devices  * XXX: These should be made specializations of generic bus accessor macros  * instead of having multiple implementations around.  */
end_comment

begin_define
define|#
directive|define
name|NEXUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(nexus, var, NEXUS, ivar, type)
end_define

begin_macro
name|NEXUS_ACCESSOR
argument_list|(
argument|node
argument_list|,
argument|NODE
argument_list|,
argument|phandle_t
argument_list|)
end_macro

begin_macro
name|NEXUS_ACCESSOR
argument_list|(
argument|name
argument_list|,
argument|NAME
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|NEXUS_ACCESSOR
argument_list|(
argument|device_type
argument_list|,
argument|DEVICE_TYPE
argument_list|,
argument|char *
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|NEXUS_ACCESSOR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_NEXUSVAR_H_ */
end_comment

end_unit

