begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_BOARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_BOARD_H_
end_define

begin_comment
comment|/*  * Engineering boards have a major/minor number in their EEPROM to   * identify their configuration  */
end_comment

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_I
value|1
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_II
value|2
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_III
value|3
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_IV
value|4
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_V
value|5
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_VI
value|6
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_VII
value|7
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_VIII
value|8
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_XI
value|11
end_define

begin_define
define|#
directive|define
name|RMI_XLR_BOARD_ARIZONA_XII
value|12
end_define

begin_comment
comment|/*  * RMI Chips - Values in Processor ID field  */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLR732
value|0x00
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR716
value|0x02
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308
value|0x06
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532
value|0x09
end_define

begin_comment
comment|/*  * XLR C revisions  */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLR308_C
value|0x0F
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR508_C
value|0x0b
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR516_C
value|0x0a
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLR532_C
value|0x08
end_define

begin_comment
comment|/*  * XLS processors  */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLS408
value|0x88
end_define

begin_comment
comment|/* Lite "Condor" */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLS608
value|0x80
end_define

begin_comment
comment|/* Internal */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLS404
value|0x8c
end_define

begin_comment
comment|/* Lite "Condor" */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLS208
value|0x8e
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS204
value|0x8f
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS108
value|0xce
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS104
value|0xcf
end_define

begin_comment
comment|/*  * XLS B revision chips  */
end_comment

begin_define
define|#
directive|define
name|RMI_CHIP_XLS616_B0
value|0x40
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS608_B0
value|0x4a
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS416_B0
value|0x44
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS412_B0
value|0x4c
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS408_B0
value|0x4e
end_define

begin_define
define|#
directive|define
name|RMI_CHIP_XLS404_B0
value|0x4f
end_define

begin_comment
comment|/*   * The XLS product line has chip versions 0x4x and 0x8x  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|xlr_is_xls
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|prid
init|=
name|mips_rd_prid
argument_list|()
decl_stmt|;
return|return
operator|(
operator|(
name|prid
operator|&
literal|0xf000
operator|)
operator|==
literal|0x8000
operator|||
operator|(
name|prid
operator|&
literal|0xf000
operator|)
operator|==
literal|0x4000
operator|||
operator|(
name|prid
operator|&
literal|0xf000
operator|)
operator|==
literal|0xc000
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The last byte of the processor id field is revision  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|xlr_revision
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|mips_rd_prid
argument_list|()
operator|&
literal|0xff
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The 15:8 byte of the PR Id register is the Processor ID  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|xlr_processor_id
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|mips_rd_prid
argument_list|()
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The processor is XLR and C-Series  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|xlr_is_c_revision
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|processor_id
init|=
name|xlr_processor_id
argument_list|()
decl_stmt|;
name|int
name|revision_id
init|=
name|xlr_revision
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|processor_id
condition|)
block|{
comment|/*  	 * These are the relevant PIDs for XLR 	 * steppings (hawk and above). For these, 	 * PIDs, Rev-Ids of [5-9] indicate 'C'. 	 */
case|case
name|RMI_CHIP_XLR308_C
case|:
case|case
name|RMI_CHIP_XLR508_C
case|:
case|case
name|RMI_CHIP_XLR516_C
case|:
case|case
name|RMI_CHIP_XLR532_C
case|:
case|case
name|RMI_CHIP_XLR716
case|:
case|case
name|RMI_CHIP_XLR732
case|:
if|if
condition|(
name|revision_id
operator|>=
literal|5
operator|&&
name|revision_id
operator|<=
literal|9
condition|)
return|return
operator|(
literal|1
operator|)
return|;
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * RMI Engineering boards which are PCI cards  * These should come up in PCI device mode (not yet)  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|xlr_board_pci
parameter_list|(
name|int
name|board_major
parameter_list|)
block|{
return|return
operator|(
operator|(
name|board_major
operator|==
name|RMI_XLR_BOARD_ARIZONA_III
operator|)
operator|||
operator|(
name|board_major
operator|==
name|RMI_XLR_BOARD_ARIZONA_V
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|xlr_is_xls1xx
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|chipid
init|=
name|xlr_processor_id
argument_list|()
decl_stmt|;
return|return
operator|(
name|chipid
operator|==
literal|0xce
operator|||
name|chipid
operator|==
literal|0xcf
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|xlr_is_xls2xx
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|chipid
init|=
name|xlr_processor_id
argument_list|()
decl_stmt|;
return|return
operator|(
name|chipid
operator|==
literal|0x8e
operator|||
name|chipid
operator|==
literal|0x8f
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|xlr_is_xls4xx_lite
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|chipid
init|=
name|xlr_processor_id
argument_list|()
decl_stmt|;
return|return
operator|(
name|chipid
operator|==
literal|0x88
operator|||
name|chipid
operator|==
literal|0x8c
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|xlr_is_xls_b0
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|chipid
init|=
name|xlr_processor_id
argument_list|()
decl_stmt|;
return|return
operator|(
name|chipid
operator|>=
literal|0x40
operator|&&
name|chipid
operator|<=
literal|0x4f
operator|)
return|;
block|}
end_function

begin_comment
comment|/* SPI-4 --> 8 ports, 1G MAC --> 4 ports and 10G MAC --> 1 port */
end_comment

begin_define
define|#
directive|define
name|MAX_NA_PORTS
value|8
end_define

begin_comment
comment|/* all our knowledge of chip and board that cannot be detected run-time goes here */
end_comment

begin_enum
enum|enum
name|gmac_block_types
block|{
name|XLR_GMAC
block|,
name|XLR_XGMAC
block|,
name|XLR_SPI4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|gmac_port_types
block|{
name|XLR_RGMII
block|,
name|XLR_SGMII
block|,
name|XLR_PORT0_RGMII
block|,
name|XLR_XGMII
block|,
name|XLR_XAUI
block|}
enum|;
end_enum

begin_enum
enum|enum
name|i2c_dev_types
block|{
name|I2C_RTC
block|,
name|I2C_THERMAL
block|,
name|I2C_EEPROM
block|}
enum|;
end_enum

begin_struct
struct|struct
name|xlr_board_info
block|{
name|int
name|is_xls
decl_stmt|;
name|int
name|nr_cpus
decl_stmt|;
name|int
name|usb
decl_stmt|;
comment|/* usb enabled ? */
name|int
name|cfi
decl_stmt|;
comment|/* compact flash driver for NOR? */
name|int
name|ata
decl_stmt|;
comment|/* ata driver */
name|int
name|pci_irq
decl_stmt|;
name|struct
name|stn_cc
modifier|*
modifier|*
name|credit_configs
decl_stmt|;
comment|/* pointer to Core station credits */
name|struct
name|bucket_size
modifier|*
name|bucket_sizes
decl_stmt|;
comment|/* pointer to Core station bucket */
name|int
modifier|*
name|msgmap
decl_stmt|;
comment|/* mapping of message station to devices */
name|int
name|gmacports
decl_stmt|;
comment|/* number of gmac ports on the board */
struct|struct
name|xlr_i2c_dev_t
block|{
name|uint32_t
name|addr
decl_stmt|;
name|unsigned
name|int
name|enabled
decl_stmt|;
comment|/* mask of devs enabled */
name|int
name|type
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|char
modifier|*
name|dev_name
decl_stmt|;
block|}
name|xlr_i2c_device
index|[
literal|3
index|]
struct|;
struct|struct
name|xlr_gmac_block_t
block|{
comment|/* refers to the set of GMACs controlled by a                                                    network accelarator */
name|int
name|type
decl_stmt|;
comment|/* see  enum gmac_block_types */
name|unsigned
name|int
name|enabled
decl_stmt|;
comment|/* mask of ports enabled */
name|struct
name|stn_cc
modifier|*
name|credit_config
decl_stmt|;
comment|/* credit configuration */
name|int
name|station_id
decl_stmt|;
comment|/* station id for sending msgs */
name|int
name|station_txbase
decl_stmt|;
comment|/* station id for tx */
name|int
name|station_rfr
decl_stmt|;
comment|/* free desc bucket */
name|int
name|mode
decl_stmt|;
comment|/* see gmac_block_modes */
name|uint32_t
name|baseaddr
decl_stmt|;
comment|/* IO base */
name|int
name|baseirq
decl_stmt|;
comment|/* first irq for this block, the rest are in sequence */
name|int
name|baseinst
decl_stmt|;
comment|/* the first rge unit for this block */
name|int
name|num_ports
decl_stmt|;
struct|struct
name|xlr_gmac_port
block|{
name|int
name|valid
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* see enum gmac_port_types */
name|uint32_t
name|instance
decl_stmt|;
comment|/* identifies the GMAC to which 						   this port is bound to. */
name|uint32_t
name|phy_addr
decl_stmt|;
name|uint32_t
name|base_addr
decl_stmt|;
name|uint32_t
name|mii_addr
decl_stmt|;
name|uint32_t
name|pcs_addr
decl_stmt|;
name|uint32_t
name|serdes_addr
decl_stmt|;
name|uint32_t
name|tx_bucket_id
decl_stmt|;
name|uint32_t
name|mdint_id
decl_stmt|;
block|}
name|gmac_port
index|[
name|MAX_NA_PORTS
index|]
struct|;
block|}
name|gmac_block
index|[
literal|3
index|]
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|xlr_board_info
name|xlr_board_info
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|xlr_board_info_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

