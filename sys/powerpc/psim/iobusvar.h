begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2002 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSIM_IOBUSVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_PSIM_IOBUSVAR_H_
end_define

begin_comment
comment|/*   * Accessors for iobus devices  */
end_comment

begin_enum
enum|enum
name|iobus_ivars
block|{
name|IOBUS_IVAR_NODE
block|,
name|IOBUS_IVAR_NAME
block|,
name|IOBUS_IVAR_NREGS
block|,
name|IOBUS_IVAR_REGS
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IOBUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(iobus, var, IOBUS, ivar, type)
end_define

begin_macro
name|IOBUS_ACCESSOR
argument_list|(
argument|node
argument_list|,
argument|NODE
argument_list|,
argument|phandle_t
argument_list|)
end_macro

begin_macro
name|IOBUS_ACCESSOR
argument_list|(
argument|name
argument_list|,
argument|NAME
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|IOBUS_ACCESSOR
argument_list|(
argument|nregs
argument_list|,
argument|NREGS
argument_list|,
argument|u_int
argument_list|)
end_macro

begin_macro
name|IOBUS_ACCESSOR
argument_list|(
argument|regs
argument_list|,
argument|REGS
argument_list|,
argument|u_int *
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|IOBUS_ACCESSOR
end_undef

begin_comment
comment|/*  * Per-device structure.  */
end_comment

begin_struct
struct|struct
name|iobus_devinfo
block|{
name|phandle_t
name|id_node
decl_stmt|;
name|char
modifier|*
name|id_name
decl_stmt|;
name|int
name|id_interrupt
decl_stmt|;
name|u_int
name|id_nregs
decl_stmt|;
name|u_int
name|id_reg
index|[
literal|24
index|]
decl_stmt|;
name|struct
name|resource_list
name|id_resources
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PSIM_IOBUSVAR_H_ */
end_comment

end_unit

