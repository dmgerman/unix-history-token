begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 HAYAKAWA Koichi.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the author.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|cardbusreg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cardbus_intr_line_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|cardbus_chipset_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|cardbus_intr_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|cardbus_vendor_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|cardbus_product_id_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CARDBUS_ID_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CARDBUS_VENDOR_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CARDBUS_VENDOR
parameter_list|(
name|id
parameter_list|)
define|\
value|(((id)>> CARDBUS_VENDOR_SHIFT)& CARDBUS_VENDOR_MASK)
end_define

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CARDBUS_PRODUCT
parameter_list|(
name|id
parameter_list|)
define|\
value|(((id)>> CARDBUS_PRODUCT_SHIFT)& CARDBUS_PRODUCT_MASK)
end_define

begin_define
define|#
directive|define
name|CARDBUS_COMMAND_STATUS_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|CARDBUS_COMMAND_IO_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CARDBUS_COMMAND_MEM_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CARDBUS_COMMAND_MASTER_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CARDBUS_CLASS_REG
value|0x08
end_define

begin_comment
comment|/* BIST, Header Type, Latency Timer, Cache Line Size */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_BHLC_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|CARDBUS_BIST_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CARDBUS_BIST_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CARDBUS_BIST
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|(((bhlcr)>> CARDBUS_BIST_SHIFT)& CARDBUS_BIST_MASK)
end_define

begin_define
define|#
directive|define
name|CARDBUS_HDRTYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CARDBUS_HDRTYPE_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CARDBUS_HDRTYPE
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|(((bhlcr)>> CARDBUS_HDRTYPE_SHIFT)& CARDBUS_HDRTYPE_MASK)
end_define

begin_define
define|#
directive|define
name|CARDBUS_HDRTYPE_TYPE
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|(CARDBUS_HDRTYPE(bhlcr)& 0x7f)
end_define

begin_define
define|#
directive|define
name|CARDBUS_HDRTYPE_MULTIFN
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|((CARDBUS_HDRTYPE(bhlcr)& 0x80) != 0)
end_define

begin_define
define|#
directive|define
name|CARDBUS_LATTIMER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CARDBUS_LATTIMER_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CARDBUS_LATTIMER
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|(((bhlcr)>> CARDBUS_LATTIMER_SHIFT)& CARDBUS_LATTIMER_MASK)
end_define

begin_define
define|#
directive|define
name|CARDBUS_CACHELINE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CARDBUS_CACHELINE_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CARDBUS_CACHELINE
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|(((bhlcr)>> CARDBUS_CACHELINE_SHIFT)& CARDBUS_CACHELINE_MASK)
end_define

begin_comment
comment|/* Base Resisters */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_BASE0_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|CARDBUS_BASE1_REG
value|0x14
end_define

begin_define
define|#
directive|define
name|CARDBUS_BASE2_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|CARDBUS_BASE3_REG
value|0x1C
end_define

begin_define
define|#
directive|define
name|CARDBUS_BASE4_REG
value|0x20
end_define

begin_define
define|#
directive|define
name|CARDBUS_BASE5_REG
value|0x24
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_REG
value|0x28
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASIMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ADDRMASK
value|0x0ffffff8
end_define

begin_define
define|#
directive|define
name|CARDBUS_INTERRUPT_REG
value|0x3c
end_define

end_unit

