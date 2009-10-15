begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_IOMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_IOMAP_H_
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|DEFAULT_XLR_IO_BASE
value|0xffffffffbef00000ULL
end_define

begin_define
define|#
directive|define
name|XLR_IO_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|XLR_IO_BRIDGE_OFFSET
value|0x00000
end_define

begin_define
define|#
directive|define
name|XLR_IO_DDR2_CHN0_OFFSET
value|0x01000
end_define

begin_define
define|#
directive|define
name|XLR_IO_DDR2_CHN1_OFFSET
value|0x02000
end_define

begin_define
define|#
directive|define
name|XLR_IO_DDR2_CHN2_OFFSET
value|0x03000
end_define

begin_define
define|#
directive|define
name|XLR_IO_DDR2_CHN3_OFFSET
value|0x04000
end_define

begin_define
define|#
directive|define
name|XLR_IO_RLD2_CHN0_OFFSET
value|0x05000
end_define

begin_define
define|#
directive|define
name|XLR_IO_RLD2_CHN1_OFFSET
value|0x06000
end_define

begin_define
define|#
directive|define
name|XLR_IO_SRAM_OFFSET
value|0x07000
end_define

begin_define
define|#
directive|define
name|XLR_IO_PIC_OFFSET
value|0x08000
end_define

begin_define
define|#
directive|define
name|XLR_IO_PCIX_OFFSET
value|0x09000
end_define

begin_define
define|#
directive|define
name|XLR_IO_HT_OFFSET
value|0x0A000
end_define

begin_define
define|#
directive|define
name|XLR_IO_SECURITY_OFFSET
value|0x0B000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_0_OFFSET
value|0x0C000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_1_OFFSET
value|0x0D000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_2_OFFSET
value|0x0E000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_3_OFFSET
value|0x0F000
end_define

begin_define
define|#
directive|define
name|XLR_IO_SPI4_0_OFFSET
value|0x10000
end_define

begin_define
define|#
directive|define
name|XLR_IO_XGMAC_0_OFFSET
value|0x11000
end_define

begin_define
define|#
directive|define
name|XLR_IO_SPI4_1_OFFSET
value|0x12000
end_define

begin_define
define|#
directive|define
name|XLR_IO_XGMAC_1_OFFSET
value|0x13000
end_define

begin_define
define|#
directive|define
name|XLR_IO_UART_0_OFFSET
value|0x14000
end_define

begin_define
define|#
directive|define
name|XLR_IO_UART_1_OFFSET
value|0x15000
end_define

begin_define
define|#
directive|define
name|XLR_IO_I2C_0_OFFSET
value|0x16000
end_define

begin_define
define|#
directive|define
name|XLR_IO_I2C_1_OFFSET
value|0x17000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GPIO_OFFSET
value|0x18000
end_define

begin_define
define|#
directive|define
name|XLR_IO_FLASH_OFFSET
value|0x19000
end_define

begin_define
define|#
directive|define
name|XLR_IO_TB_OFFSET
value|0x1C000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_4_OFFSET
value|0x20000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_5_OFFSET
value|0x21000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_6_OFFSET
value|0x22000
end_define

begin_define
define|#
directive|define
name|XLR_IO_GMAC_7_OFFSET
value|0x23000
end_define

begin_define
define|#
directive|define
name|XLR_IO_PCIE_0_OFFSET
value|0x1E000
end_define

begin_define
define|#
directive|define
name|XLR_IO_PCIE_1_OFFSET
value|0x1F000
end_define

begin_define
define|#
directive|define
name|XLR_IO_USB_0_OFFSET
value|0x24000
end_define

begin_define
define|#
directive|define
name|XLR_IO_USB_1_OFFSET
value|0x25000
end_define

begin_define
define|#
directive|define
name|XLR_IO_COMP_OFFSET
value|0x1d000
end_define

begin_comment
comment|/* Base Address (Virtual) of the PCI Config address space  * For now, choose 256M phys in kseg1 = 0xA0000000 + (1<<28)  * Config space spans 256 (num of buses) * 256 (num functions) * 256 bytes  * ie 1<<24 = 16M  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCI_CONFIG_BASE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|DEFAULT_HT_TYPE0_CFG_BASE
value|0x16000000
end_define

begin_define
define|#
directive|define
name|DEFAULT_HT_TYPE1_CFG_BASE
value|0x17000000
end_define

begin_typedef
typedef|typedef
specifier|volatile
name|__uint32_t
name|xlr_reg_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|xlr_io_base
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|xlr_io_mmio
parameter_list|(
name|offset
parameter_list|)
value|((xlr_reg_t *)(xlr_io_base+(offset)))
end_define

begin_define
define|#
directive|define
name|xlr_read_reg
parameter_list|(
name|base
parameter_list|,
name|offset
parameter_list|)
value|(__ntohl((base)[(offset)]))
end_define

begin_define
define|#
directive|define
name|xlr_write_reg
parameter_list|(
name|base
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
value|((base)[(offset)] = __htonl((value)))
end_define

begin_function_decl
specifier|extern
name|void
name|on_chip_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RMI_IOMAP_H_ */
end_comment

end_unit

