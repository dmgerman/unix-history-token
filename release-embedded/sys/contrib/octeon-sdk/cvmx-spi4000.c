begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Support library for the SPI4000 card  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-spi.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-twsi.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-gmxx-defs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-spi.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-twsi.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If someone is using an old config, make the SPI4000 act like RGMII for backpressure */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_DISABLE_SPI4000_BACKPRESSURE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_DISABLE_RGMII_BACKPRESSURE
end_ifndef

begin_define
define|#
directive|define
name|CVMX_HELPER_DISABLE_RGMII_BACKPRESSURE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CVMX_HELPER_DISABLE_SPI4000_BACKPRESSURE
value|CVMX_HELPER_DISABLE_RGMII_BACKPRESSURE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPI4000_READ_ADDRESS_HIGH
value|0xf0
end_define

begin_define
define|#
directive|define
name|SPI4000_READ_ADDRESS_LOW
value|0xf1
end_define

begin_define
define|#
directive|define
name|SPI4000_WRITE_ADDRESS_HIGH
value|0xf2
end_define

begin_define
define|#
directive|define
name|SPI4000_WRITE_ADDRESS_LOW
value|0xf3
end_define

begin_define
define|#
directive|define
name|SPI4000_READ_DATA0
value|0xf4
end_define

begin_comment
comment|/* High byte */
end_comment

begin_define
define|#
directive|define
name|SPI4000_READ_DATA1
value|0xf5
end_define

begin_define
define|#
directive|define
name|SPI4000_READ_DATA2
value|0xf6
end_define

begin_define
define|#
directive|define
name|SPI4000_READ_DATA3
value|0xf7
end_define

begin_comment
comment|/* Low byte */
end_comment

begin_define
define|#
directive|define
name|SPI4000_WRITE_DATA0
value|0xf8
end_define

begin_comment
comment|/* High byte */
end_comment

begin_define
define|#
directive|define
name|SPI4000_WRITE_DATA1
value|0xf9
end_define

begin_define
define|#
directive|define
name|SPI4000_WRITE_DATA2
value|0xfa
end_define

begin_define
define|#
directive|define
name|SPI4000_WRITE_DATA3
value|0xfb
end_define

begin_comment
comment|/* Low byte */
end_comment

begin_define
define|#
directive|define
name|SPI4000_DO_READ
value|0xfc
end_define

begin_comment
comment|/* Issue a read, returns read status */
end_comment

begin_define
define|#
directive|define
name|SPI4000_GET_READ_STATUS
value|0xfd
end_define

begin_comment
comment|/* 0xff: initial state, 2: Read failed, 1: Read pending, 0: Read success */
end_comment

begin_define
define|#
directive|define
name|SPI4000_DO_WRITE
value|0xfe
end_define

begin_comment
comment|/* Issue a write, returns write status */
end_comment

begin_define
define|#
directive|define
name|SPI4000_GET_WRITE_STATUS
value|0xff
end_define

begin_comment
comment|/* 0xff: initial state, 6: Write failed, 5: Write pending, 4: Write success */
end_comment

begin_define
define|#
directive|define
name|SPI4000_TWSI_ID
parameter_list|(
name|interface
parameter_list|)
value|(0x66 + interface)
end_define

begin_comment
comment|/* MDI Single Command (register 0x680) */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint32_t
name|u32
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|reserved_21_31
range|:
literal|11
decl_stmt|;
name|uint32_t
name|mdi_command
range|:
literal|1
decl_stmt|;
comment|/**< Performs an MDIO access. When set, this bit                                             self clears upon completion of the access. */
name|uint32_t
name|reserved_18_19
range|:
literal|2
decl_stmt|;
name|uint32_t
name|op_code
range|:
literal|2
decl_stmt|;
comment|/**< MDIO Op Code                                             00 = Reserved                                             01 = Write Access                                             10 = Read Access                                             11 = Reserved */
name|uint32_t
name|reserved_13_15
range|:
literal|3
decl_stmt|;
name|uint32_t
name|phy_address
range|:
literal|5
decl_stmt|;
comment|/**< Address of external PHY device */
name|uint32_t
name|reserved_5_7
range|:
literal|3
decl_stmt|;
name|uint32_t
name|reg_address
range|:
literal|5
decl_stmt|;
comment|/**< Address of register within external PHY */
block|}
name|s
struct|;
block|}
name|mdio_single_command_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|CVMX_SHARED
name|int
name|interface_is_spi4000
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * @INTERNAL  * Write data to the specified SPI4000 address  *  * @param interface Interface the SPI4000 is on. (0 or 1)  * @param address   Address to write to  * @param data      Data to write  */
end_comment

begin_function
specifier|static
name|void
name|__cvmx_spi4000_write
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|address
parameter_list|,
name|uint32_t
name|data
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
name|cvmx_twsix_write_ia
argument_list|(
literal|0
argument_list|,
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_WRITE_ADDRESS_HIGH
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
name|address
argument_list|)
expr_stmt|;
name|cvmx_twsix_write_ia
argument_list|(
literal|0
argument_list|,
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_WRITE_DATA0
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|status
operator|=
name|cvmx_twsi_read8
argument_list|(
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_DO_WRITE
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|status
operator|==
literal|5
operator|)
operator|||
operator|(
name|status
operator|==
literal|0xff
operator|)
condition|)
name|status
operator|=
name|cvmx_twsi_read8
argument_list|(
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_GET_WRITE_STATUS
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|4
condition|)
name|cvmx_dprintf
argument_list|(
literal|"SPI4000: write failed with status=0x%x\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Read data from the SPI4000.  *  * @param interface Interface the SPI4000 is on. (0 or 1)  * @param address   Address to read from  *  * @return Value at the specified address  */
end_comment

begin_function
specifier|static
name|uint32_t
name|__cvmx_spi4000_read
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|address
parameter_list|)
block|{
name|int
name|status
decl_stmt|;
name|uint64_t
name|data
decl_stmt|;
name|cvmx_twsix_write_ia
argument_list|(
literal|0
argument_list|,
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_READ_ADDRESS_HIGH
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
name|address
argument_list|)
expr_stmt|;
name|status
operator|=
name|cvmx_twsi_read8
argument_list|(
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_DO_READ
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|status
operator|==
literal|1
operator|)
operator|||
operator|(
name|status
operator|==
literal|0xff
operator|)
condition|)
name|status
operator|=
name|cvmx_twsi_read8
argument_list|(
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_GET_READ_STATUS
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|cvmx_dprintf
argument_list|(
literal|"SPI4000: read failed with %d\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|status
operator|=
name|cvmx_twsix_read_ia
argument_list|(
literal|0
argument_list|,
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_READ_DATA0
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
operator|&
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|4
condition|)
block|{
name|cvmx_dprintf
argument_list|(
literal|"SPI4000: read failed with %d\n"
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|data
return|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Write to a PHY using MDIO on the SPI4000  *  * @param interface Interface the SPI4000 is on. (0 or 1)  * @param port      SPI4000 RGMII port to write to. (0-9)  * @param location  MDIO register to write  * @param val       Value to write  */
end_comment

begin_function
specifier|static
name|void
name|__cvmx_spi4000_mdio_write
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|location
parameter_list|,
name|int
name|val
parameter_list|)
block|{
specifier|static
name|int
name|last_value
init|=
operator|-
literal|1
decl_stmt|;
name|mdio_single_command_t
name|mdio
decl_stmt|;
name|mdio
operator|.
name|u32
operator|=
literal|0
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|mdi_command
operator|=
literal|1
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|op_code
operator|=
literal|1
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|phy_address
operator|=
name|port
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|reg_address
operator|=
name|location
expr_stmt|;
comment|/* Since the TWSI accesses are very slow, don't update the write value         if it is the same as the last value */
if|if
condition|(
name|val
operator|!=
name|last_value
condition|)
block|{
name|last_value
operator|=
name|val
expr_stmt|;
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0681
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0680
argument_list|,
name|mdio
operator|.
name|u32
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Read from a PHY using MDIO on the SPI4000  *  * @param interface Interface the SPI4000 is on. (0 or 1)  * @param port      SPI4000 RGMII port to read from. (0-9)  * @param location  MDIO register to read  * @return The MDI read result  */
end_comment

begin_function
specifier|static
name|int
name|__cvmx_spi4000_mdio_read
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|location
parameter_list|)
block|{
name|mdio_single_command_t
name|mdio
decl_stmt|;
name|mdio
operator|.
name|u32
operator|=
literal|0
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|mdi_command
operator|=
literal|1
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|op_code
operator|=
literal|2
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|phy_address
operator|=
name|port
expr_stmt|;
name|mdio
operator|.
name|s
operator|.
name|reg_address
operator|=
name|location
expr_stmt|;
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0680
argument_list|,
name|mdio
operator|.
name|u32
argument_list|)
expr_stmt|;
do|do
block|{
name|mdio
operator|.
name|u32
operator|=
name|__cvmx_spi4000_read
argument_list|(
name|interface
argument_list|,
literal|0x0680
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|mdio
operator|.
name|s
operator|.
name|mdi_command
condition|)
do|;
return|return
name|__cvmx_spi4000_read
argument_list|(
name|interface
argument_list|,
literal|0x0681
argument_list|)
operator|>>
literal|16
return|;
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Configure the SPI4000 MACs  */
end_comment

begin_function
specifier|static
name|void
name|__cvmx_spi4000_configure_mac
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
name|int
name|port
decl_stmt|;
comment|// IXF1010 configuration
comment|// ---------------------
comment|//
comment|// Step 1: Apply soft reset to TxFIFO and MAC
comment|//         MAC soft reset register. address=0x505
comment|//         TxFIFO soft reset. address=0x620
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0505
argument_list|,
literal|0x3ff
argument_list|)
expr_stmt|;
comment|// reset all the MACs
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0620
argument_list|,
literal|0x3ff
argument_list|)
expr_stmt|;
comment|// reset the TX FIFOs
comment|//         Global address and Configuration Register. address=0x500
comment|//
comment|// Step 2: Apply soft reset to RxFIFO and SPI.
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x059e
argument_list|,
literal|0x3ff
argument_list|)
expr_stmt|;
comment|// reset the RX FIFOs
comment|// Step 3a: Take the MAC out of softreset
comment|//          MAC soft reset register. address=0x505
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0505
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
comment|// reset all the MACs
comment|// Step 3b: De-assert port enables.
comment|//          Global address and Configuration Register. address=0x500
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0500
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
comment|// disable all ports
comment|// Step 4: Assert Clock mode change En.
comment|//         Clock and interface mode Change En. address=Serdes base + 0x14
comment|//         Serdes (Serializer/de-serializer). address=0x780
comment|//         [Can't find this one]
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
literal|10
condition|;
name|port
operator|++
control|)
block|{
name|int
name|port_offset
init|=
name|port
operator|<<
literal|7
decl_stmt|;
comment|// Step 5: Set MAC interface mode GMII speed.
comment|//         MAC interface mode and RGMII speed register.
comment|//             address=port_index+0x10
comment|//
comment|//         OUT port_index+0x10, 0x07     //RGMII 1000 Mbps operation.
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0010
argument_list|,
literal|0x3
argument_list|)
expr_stmt|;
comment|// Set the max packet size to 16383 bytes, including the CRC
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x000f
argument_list|,
literal|0x3fff
argument_list|)
expr_stmt|;
comment|// Step 6: Change Interface to Copper mode
comment|//         Interface mode register. address=0x501
comment|//         [Can't find this]
comment|// Step 7: MAC configuration
comment|//         Station address configuration.
comment|//         Source MAC address low register. Source MAC address 31-0.
comment|//             address=port_index+0x00
comment|//         Source MAC address high register. Source MAC address 47-32.
comment|//             address=port_index+0x01
comment|//         where Port index is 0x0 to 0x5.
comment|//         This address is inserted in the source address filed when
comment|//         transmitting pause frames, and is also used to compare against
comment|//         unicast pause frames at the receiving side.
comment|//
comment|//         OUT port_index+0x00, source MAC address low.
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0000
argument_list|,
literal|0x0000
argument_list|)
expr_stmt|;
comment|//         OUT port_index+0x01, source MAC address high.
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0001
argument_list|,
literal|0x0000
argument_list|)
expr_stmt|;
comment|// Step 8: Set desired duplex mode
comment|//         Desired duplex register. address=port_index+0x02
comment|//         [Reserved]
comment|// Step 9: Other configuration.
comment|//         FC Enable Register.             address=port_index+0x12
comment|//         Discard Unknown Control Frame.  address=port_index+0x15
comment|//         Diverse config write register.  address=port_index+0x18
comment|//         RX Packet Filter register.      address=port_index+0x19
comment|//
comment|// Step 9a: Tx FD FC Enabled / Rx FD FC Enabled
if|if
condition|(
name|CVMX_HELPER_DISABLE_SPI4000_BACKPRESSURE
condition|)
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0012
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0012
argument_list|,
literal|0x7
argument_list|)
expr_stmt|;
comment|// Step 9b: Discard unknown control frames
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0015
argument_list|,
literal|0x1
argument_list|)
expr_stmt|;
comment|// Step 9c: Enable auto-CRC and auto-padding
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0018
argument_list|,
literal|0x11cd
argument_list|)
expr_stmt|;
comment|//??
comment|// Step 9d: Drop bad CRC / Drop Pause / No DAF
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port_offset
operator||
literal|0x0019
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
block|}
comment|// Step 9d: Drop frames
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x059f
argument_list|,
literal|0x03ff
argument_list|)
expr_stmt|;
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
literal|10
condition|;
name|port
operator|++
control|)
block|{
comment|// Step 9e: Set the TX FIFO marks
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port
operator|+
literal|0x0600
argument_list|,
literal|0x0900
argument_list|)
expr_stmt|;
comment|// TXFIFO High watermark
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port
operator|+
literal|0x060a
argument_list|,
literal|0x0800
argument_list|)
expr_stmt|;
comment|// TXFIFO Low watermark
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
name|port
operator|+
literal|0x0614
argument_list|,
literal|0x0380
argument_list|)
expr_stmt|;
comment|// TXFIFO threshold
block|}
comment|// Step 12: De-assert RxFIFO and SPI Rx/Tx reset
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x059e
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
comment|// reset the RX FIFOs
comment|// Step 13: De-assert TxFIFO and MAC reset
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0620
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
comment|// reset the TX FIFOs
comment|// Step 14: Assert port enable
comment|//          Global address and Configuration Register. address=0x500
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
literal|0x0500
argument_list|,
literal|0x03ff
argument_list|)
expr_stmt|;
comment|// enable all ports
comment|// Step 15: Disable loopback
comment|//          [Can't find this one]
block|}
end_function

begin_comment
comment|/**  * @INTERNAL  * Configure the SPI4000 PHYs  */
end_comment

begin_function
specifier|static
name|void
name|__cvmx_spi4000_configure_phy
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
name|int
name|port
decl_stmt|;
comment|/* We use separate loops below since it allows us to save a write         to the SPI4000 for each repeated value. This adds up to a couple         of seconds */
comment|/* Update the link state before resets. It takes a while for the links to         come back after the resets. Most likely they'll come back the same as         they are now */
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
literal|10
condition|;
name|port
operator|++
control|)
name|cvmx_spi4000_check_speed
argument_list|(
name|interface
argument_list|,
name|port
argument_list|)
expr_stmt|;
comment|/* Enable RGMII DELAYS for TX_CLK and RX_CLK (see spec) */
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
literal|10
condition|;
name|port
operator|++
control|)
name|__cvmx_spi4000_mdio_write
argument_list|(
name|interface
argument_list|,
name|port
argument_list|,
literal|0x14
argument_list|,
literal|0x00e2
argument_list|)
expr_stmt|;
comment|/* Advertise pause and 100 Full Duplex. Don't advertise half duplex or 10Mbpa */
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
literal|10
condition|;
name|port
operator|++
control|)
name|__cvmx_spi4000_mdio_write
argument_list|(
name|interface
argument_list|,
name|port
argument_list|,
literal|0x4
argument_list|,
literal|0x0d01
argument_list|)
expr_stmt|;
comment|/* Enable PHY reset */
for|for
control|(
name|port
operator|=
literal|0
init|;
name|port
operator|<
literal|10
condition|;
name|port
operator|++
control|)
name|__cvmx_spi4000_mdio_write
argument_list|(
name|interface
argument_list|,
name|port
argument_list|,
literal|0x0
argument_list|,
literal|0x9140
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Poll all the SPI4000 port and check its speed  *  * @param interface Interface the SPI4000 is on  * @param port      Port to poll (0-9)  * @return Status of the port. 0=down. All other values the port is up.  */
end_comment

begin_function
name|cvmx_gmxx_rxx_rx_inbnd_t
name|cvmx_spi4000_check_speed
parameter_list|(
name|int
name|interface
parameter_list|,
name|int
name|port
parameter_list|)
block|{
specifier|static
name|int
name|phy_status
index|[
literal|10
index|]
init|=
block|{
literal|0
block|,}
decl_stmt|;
name|cvmx_gmxx_rxx_rx_inbnd_t
name|link
decl_stmt|;
name|int
name|read_status
decl_stmt|;
name|link
operator|.
name|u64
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|interface_is_spi4000
index|[
name|interface
index|]
condition|)
return|return
name|link
return|;
if|if
condition|(
name|port
operator|>=
literal|10
condition|)
return|return
name|link
return|;
comment|/* Register 0x11: PHY Specific Status Register          Register   Function         Setting                     Mode   HW Rst SW Rst Notes                                                                  RO     00     Retain note          17.15:14   Speed            11 = Reserved                                                                                       17.a                                      10 = 1000 Mbps                                      01 = 100 Mbps                                      00 = 10 Mbps          17.13      Duplex           1 = Full-duplex             RO     0      Retain note                                      0 = Half-duplex                                  17.a          17.12      Page Received    1 = Page received           RO, LH 0      0                                      0 = Page not received                                      1 = Resolved                RO     0      0      note          17.11      Speed and                                      0 = Not resolved                                 17.a                     Duplex                     Resolved          17.10      Link (real time) 1 = Link up                 RO     0      0                                      0 = Link down                                                                  RO     000    000    note                                      000 =< 50m          17.9:7     Cable Length                                      001 = 50 - 80m                                   17.b                     (100/1000                                      010 = 80 - 110m                     modes only)                                      011 = 110 - 140m                                      100 =>140m          17.6       MDI Crossover    1 = MDIX                    RO     0      0      note                     Status           0 = MDI                                          17.a          17.5       Downshift Sta-   1 = Downshift               RO     0      0                     tus              0 = No Downshift          17.4       Energy Detect    1 = Sleep                   RO     0      0                     Status           0 = Active          17.3       Transmit Pause   1 = Transmit pause enabled  RO     0      0      note17.                     Enabled          0 = Transmit pause disabled                      a, 17.c          17.2       Receive Pause    1 = Receive pause enabled   RO     0      0      note17.                     Enabled          0 = Receive pause disabled                       a, 17.c          17.1       Polarity (real   1 = Reversed                RO     0      0                     time)            0 = Normal          17.0       Jabber (real     1 = Jabber                  RO     0      Retain                     time)            0 = No jabber     */
name|read_status
operator|=
name|__cvmx_spi4000_mdio_read
argument_list|(
name|interface
argument_list|,
name|port
argument_list|,
literal|0x11
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|read_status
operator|&
operator|(
literal|1
operator|<<
literal|10
operator|)
operator|)
operator|==
literal|0
condition|)
name|read_status
operator|=
literal|0
expr_stmt|;
comment|/* If the link is down, force zero */
else|else
name|read_status
operator|&=
literal|0xe400
expr_stmt|;
comment|/* Strip off all the don't care bits */
if|if
condition|(
name|read_status
operator|!=
name|phy_status
index|[
name|port
index|]
condition|)
block|{
name|phy_status
index|[
name|port
index|]
operator|=
name|read_status
expr_stmt|;
if|if
condition|(
name|read_status
operator|&
operator|(
literal|1
operator|<<
literal|10
operator|)
condition|)
block|{
comment|/* If the link is up, we need to set the speed based on the PHY status */
if|if
condition|(
name|read_status
operator|&
operator|(
literal|1
operator|<<
literal|15
operator|)
condition|)
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
operator|(
name|port
operator|<<
literal|7
operator|)
operator||
literal|0x0010
argument_list|,
literal|0x3
argument_list|)
expr_stmt|;
comment|/* 1Gbps */
else|else
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
operator|(
name|port
operator|<<
literal|7
operator|)
operator||
literal|0x0010
argument_list|,
literal|0x1
argument_list|)
expr_stmt|;
comment|/* 100Mbps */
block|}
else|else
block|{
comment|/* If the link is down, force 1Gbps so TX traffic dumps fast */
name|__cvmx_spi4000_write
argument_list|(
name|interface
argument_list|,
operator|(
name|port
operator|<<
literal|7
operator|)
operator||
literal|0x0010
argument_list|,
literal|0x3
argument_list|)
expr_stmt|;
comment|/* 1Gbps */
block|}
block|}
if|if
condition|(
name|read_status
operator|&
operator|(
literal|1
operator|<<
literal|10
operator|)
condition|)
block|{
name|link
operator|.
name|s
operator|.
name|status
operator|=
literal|1
expr_stmt|;
comment|/* Link up */
if|if
condition|(
name|read_status
operator|&
operator|(
literal|1
operator|<<
literal|15
operator|)
condition|)
name|link
operator|.
name|s
operator|.
name|speed
operator|=
literal|2
expr_stmt|;
else|else
name|link
operator|.
name|s
operator|.
name|speed
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|link
operator|.
name|s
operator|.
name|speed
operator|=
literal|2
expr_stmt|;
comment|/* Use 1Gbps when down */
name|link
operator|.
name|s
operator|.
name|status
operator|=
literal|0
expr_stmt|;
comment|/* Link Down */
block|}
name|link
operator|.
name|s
operator|.
name|duplex
operator|=
operator|(
operator|(
name|read_status
operator|&
operator|(
literal|1
operator|<<
literal|13
operator|)
operator|)
operator|!=
literal|0
operator|)
expr_stmt|;
return|return
name|link
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|cvmx_spi4000_check_speed
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Return non-zero if the SPI interface has a SPI4000 attached  *  * @param interface SPI interface the SPI4000 is connected to  *  * @return  */
end_comment

begin_function
name|int
name|cvmx_spi4000_is_present
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN38XX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN58XX
argument_list|)
operator|)
condition|)
return|return
literal|0
return|;
comment|// Check for the presence of a SPI4000. If it isn't there,
comment|// these writes will timeout.
if|if
condition|(
name|cvmx_twsi_write8
argument_list|(
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_WRITE_ADDRESS_HIGH
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|cvmx_twsi_write8
argument_list|(
name|SPI4000_TWSI_ID
argument_list|(
name|interface
argument_list|)
argument_list|,
name|SPI4000_WRITE_ADDRESS_LOW
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|0
return|;
name|interface_is_spi4000
index|[
name|interface
index|]
operator|=
literal|1
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/**  * Initialize the SPI4000 for use  *  * @param interface SPI interface the SPI4000 is connected to  */
end_comment

begin_function
name|int
name|cvmx_spi4000_initialize
parameter_list|(
name|int
name|interface
parameter_list|)
block|{
if|if
condition|(
operator|!
name|cvmx_spi4000_is_present
argument_list|(
name|interface
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|__cvmx_spi4000_configure_mac
argument_list|(
name|interface
argument_list|)
expr_stmt|;
name|__cvmx_spi4000_configure_phy
argument_list|(
name|interface
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

