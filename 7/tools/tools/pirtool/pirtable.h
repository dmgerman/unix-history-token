begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2006 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Bruce M. Simpson nor the names of  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRUCE M. SIMPSON AND AFFILIATES  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * All fields and quantities in this file are in little-endian byte order,  * unless otherwise specified.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PIRTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|_PIRTABLE_H
end_define

begin_define
define|#
directive|define
name|PIR_BASE
value|0xF0000
end_define

begin_define
define|#
directive|define
name|PIR_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|PIR_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|PIR_DEV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF8)>> 3)
end_define

begin_define
define|#
directive|define
name|PIR_FUNC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|bus
decl_stmt|;
comment|/* bus number of this device */
name|uint8_t
name|devfunc
decl_stmt|;
comment|/* only upper 5 device bits valid */
name|uint8_t
name|inta_link
decl_stmt|;
comment|/* how INTA is linked */
name|uint16_t
name|inta_irqs
decl_stmt|;
comment|/* how INTA may be routed (bitset) */
name|uint8_t
name|intb_link
decl_stmt|;
name|uint16_t
name|intb_irqs
decl_stmt|;
name|uint8_t
name|intc_link
decl_stmt|;
name|uint16_t
name|intc_irqs
decl_stmt|;
name|uint8_t
name|intd_link
decl_stmt|;
name|uint16_t
name|intd_irqs
decl_stmt|;
comment|/* how this pin may be routed */
name|uint8_t
name|slot
decl_stmt|;
comment|/* physical slot number on bus, 					 * slot 0 if motherboard */
name|uint8_t
name|reserved00
decl_stmt|;
comment|/* must be zero */
block|}
name|__packed
name|pir_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|signature
decl_stmt|;
comment|/* $PIR */
name|uint8_t
name|minor
decl_stmt|;
comment|/* minor version (0) */
name|uint8_t
name|major
decl_stmt|;
comment|/* major version (1) */
name|uint16_t
name|size
decl_stmt|;
comment|/* total size of table */
name|uint8_t
name|bus
decl_stmt|;
comment|/* Bus number of router */
name|uint8_t
name|devfunc
decl_stmt|;
comment|/* Dev/Func of router */
name|uint16_t
name|excl_irqs
decl_stmt|;
comment|/* PCI Exclusive IRQs */
name|uint32_t
name|compatible
decl_stmt|;
comment|/* Device/Vendor ID of a register 					 * compatible PCI IRQ router device */
name|uint32_t
name|miniport_data
decl_stmt|;
comment|/* Windows specific */
name|uint8_t
name|reserved00
index|[
literal|11
index|]
decl_stmt|;
comment|/* Must be zero */
name|uint8_t
name|checksum
decl_stmt|;
comment|/* Inverse mod-256 sum of table bytes */
name|pir_entry_t
name|entry
index|[
literal|1
index|]
decl_stmt|;
comment|/* 1..N device entries */
block|}
name|__packed
name|pir_table_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PIRTABLE_H */
end_comment

end_unit

