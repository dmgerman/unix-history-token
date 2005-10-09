begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Structure definitions for the Cardbus Bus driver  */
end_comment

begin_struct
struct|struct
name|cardbus_devinfo
block|{
name|struct
name|pci_devinfo
name|pci
decl_stmt|;
name|uint8_t
name|mprefetchable
decl_stmt|;
comment|/* bit mask of prefetchable BARs */
name|uint8_t
name|mbelow1mb
decl_stmt|;
comment|/* bit mask of BARs which require below 1Mb */
name|uint8_t
name|ibelow1mb
decl_stmt|;
comment|/* bit mask of BARs which require below 1Mb */
define|#
directive|define
name|BARBIT
parameter_list|(
name|RID
parameter_list|)
value|(1<<(((RID)-CARDBUS_BASE0_REG)/4))
name|uint16_t
name|mfrid
decl_stmt|;
comment|/* manufacturer id */
name|uint16_t
name|prodid
decl_stmt|;
comment|/* product id */
name|u_int
name|funcid
decl_stmt|;
comment|/* function id */
union|union
block|{
struct|struct
block|{
name|uint8_t
name|nid
index|[
literal|6
index|]
decl_stmt|;
comment|/* MAC address */
block|}
name|lan
struct|;
block|}
name|funce
union|;
name|uint32_t
name|fepresent
decl_stmt|;
comment|/* bit mask of funce values present */
block|}
struct|;
end_struct

end_unit

