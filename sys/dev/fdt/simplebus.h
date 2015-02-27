begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FDT_SIMPLEBUS_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|_FDT_SIMPLEBUS_PRIVATE_H
end_define

begin_comment
comment|/* FDT simplebus */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|simplebus_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|simplebus_range
block|{
name|uint64_t
name|bus
decl_stmt|;
name|uint64_t
name|host
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* devinfo and softc */
end_comment

begin_struct
struct|struct
name|simplebus_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|phandle_t
name|node
decl_stmt|;
name|struct
name|simplebus_range
modifier|*
name|ranges
decl_stmt|;
name|int
name|nranges
decl_stmt|;
name|pcell_t
name|acells
decl_stmt|,
name|scells
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|simplebus_devinfo
block|{
name|struct
name|ofw_bus_devinfo
name|obdinfo
decl_stmt|;
name|struct
name|resource_list
name|rl
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FDT_SIMPLEBUS_PRIVATE_H */
end_comment

end_unit

