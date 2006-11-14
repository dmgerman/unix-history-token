begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for the Cardbus Bus  */
end_comment

begin_comment
comment|/* Cardbus bus constants */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_SLOTMAX
value|0
end_define

begin_define
define|#
directive|define
name|CARDBUS_FUNCMAX
value|7
end_define

begin_comment
comment|/* Cardbus configuration header registers */
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
name|CARDBUS_CIS_ASI_TUPLE
value|0x00
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR0
value|0x01
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR1
value|0x02
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR2
value|0x03
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR3
value|0x04
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR4
value|0x05
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR5
value|0x06
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_ROM
value|0x07
end_define

begin_define
define|#
directive|define
name|CARDBUS_ROM_REG
value|0x30
end_define

begin_define
define|#
directive|define
name|CARDBUS_ROM_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CARDBUS_ROM_ADDRMASK
value|0xfffff800
end_define

begin_comment
comment|/* EXROM offsets for reading CIS */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_SIGNATURE
value|0x00
end_define

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_PTR
value|0x18
end_define

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_SIGNATURE
value|0x00
end_define

begin_comment
comment|/* Signature ("PCIR") */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_VENDOR_ID
value|0x04
end_define

begin_comment
comment|/* Vendor Identification */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_DEVICE_ID
value|0x06
end_define

begin_comment
comment|/* Device Identification */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_LENGTH
value|0x0a
end_define

begin_comment
comment|/* PCI Data Structure Length */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_REV
value|0x0c
end_define

begin_comment
comment|/* PCI Data Structure Revision */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_CLASS_CODE
value|0x0d
end_define

begin_comment
comment|/* Class Code */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_IMAGE_LENGTH
value|0x10
end_define

begin_comment
comment|/* Image Length */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_DATA_REV
value|0x12
end_define

begin_comment
comment|/* Revision Level of Code/Data */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_CODE_TYPE
value|0x14
end_define

begin_comment
comment|/* Code Type */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_EXROM_DATA_INDICATOR
value|0x15
end_define

begin_comment
comment|/* Indicator */
end_comment

begin_comment
comment|/* useful macros */
end_comment

begin_define
define|#
directive|define
name|CARDBUS_CIS_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(CARDBUS_CIS_ADDRMASK& (x))
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_SPACE
parameter_list|(
name|x
parameter_list|)
define|\
value|(CARDBUS_CIS_ASIMASK& (x))
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_BAR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((CARDBUS_CIS_ASIMASK& (x))-1)*4+0x10)
end_define

begin_define
define|#
directive|define
name|CARDBUS_CIS_ASI_ROM_IMAGE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> 28)& 0xf)
end_define

begin_define
define|#
directive|define
name|CARDBUS_MAPREG_MEM_ADDR_MASK
value|0x0ffffff0
end_define

begin_define
define|#
directive|define
name|CARDBUS_MAPREG_MEM_ADDR
parameter_list|(
name|mr
parameter_list|)
define|\
value|((mr)& CARDBUS_MAPREG_MEM_ADDR_MASK)
end_define

begin_define
define|#
directive|define
name|CARDBUS_MAPREG_MEM_SIZE
parameter_list|(
name|mr
parameter_list|)
define|\
value|(CARDBUS_MAPREG_MEM_ADDR(mr)& (~CARDBUS_MAPREG_MEM_ADDR(mr) + 1))
end_define

end_unit

