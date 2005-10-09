begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2002 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACIO_MACIOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACIO_MACIOVAR_H_
end_define

begin_comment
comment|/*  * The addr space size  * XXX it would be better if this could be determined by querying the  *     PCI device, but there isn't an access method for this  */
end_comment

begin_define
define|#
directive|define
name|MACIO_REG_SIZE
value|0x7ffff
end_define

begin_comment
comment|/*  * Format of a macio reg property entry.  */
end_comment

begin_struct
struct|struct
name|macio_reg
block|{
name|u_int32_t
name|mr_base
decl_stmt|;
name|u_int32_t
name|mr_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per macio device structure.  */
end_comment

begin_struct
struct|struct
name|macio_devinfo
block|{
name|char
modifier|*
name|mdi_compat
decl_stmt|;
name|char
modifier|*
name|mdi_model
decl_stmt|;
name|char
modifier|*
name|mdi_name
decl_stmt|;
name|phandle_t
name|mdi_node
decl_stmt|;
name|char
modifier|*
name|mdi_type
decl_stmt|;
name|int
name|mdi_interrupts
index|[
literal|5
index|]
decl_stmt|;
name|int
name|mdi_ninterrupts
decl_stmt|;
name|int
name|mdi_base
decl_stmt|;
name|struct
name|resource_list
name|mdi_resources
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACIO_MACIOVAR_H_ */
end_comment

end_unit

