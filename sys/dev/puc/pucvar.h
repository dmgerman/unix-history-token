begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pucvar.h,v 1.2 1999/02/06 06:29:54 cgd Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 JF Hay.  All rights reserved.  * Copyright (c) 2000 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998, 1999 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Exported (or conveniently located) PCI "universal" communications card  * software structures.  *  * Author: Christopher G. Demetriou, May 14, 1998.  */
end_comment

begin_define
define|#
directive|define
name|PUC_MAX_PORTS
value|8
end_define

begin_struct
struct|struct
name|puc_device_description
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uint32_t
name|rval
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|rmask
index|[
literal|4
index|]
decl_stmt|;
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|int
name|bar
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|u_int
name|serialfreq
decl_stmt|;
block|}
name|ports
index|[
name|PUC_MAX_PORTS
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PUC_REG_VEND
value|0
end_define

begin_define
define|#
directive|define
name|PUC_REG_PROD
value|1
end_define

begin_define
define|#
directive|define
name|PUC_REG_SVEND
value|2
end_define

begin_define
define|#
directive|define
name|PUC_REG_SPROD
value|3
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_COM
value|1
end_define

begin_define
define|#
directive|define
name|PUC_PORT_TYPE_LPT
value|2
end_define

begin_define
define|#
directive|define
name|PUC_PORT_VALID
parameter_list|(
name|desc
parameter_list|,
name|port
parameter_list|)
define|\
value|((port)< PUC_MAX_PORTS&& (desc)->ports[(port)].type != PUC_PORT_TYPE_NONE)
end_define

begin_define
define|#
directive|define
name|PUC_PORT_BAR_INDEX
parameter_list|(
name|bar
parameter_list|)
value|(((bar) - PCIR_MAPS) / 4)
end_define

begin_define
define|#
directive|define
name|PUC_MAX_BAR
value|6
end_define

begin_enum
enum|enum
name|puc_device_ivars
block|{
name|PUC_IVAR_FREQ
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|puc_device_description
name|puc_devices
index|[]
decl_stmt|;
end_decl_stmt

end_unit

