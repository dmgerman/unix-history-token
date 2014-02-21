begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4var.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4_reg.h>
end_include

begin_comment
comment|/* Registers in the SCRM that control the AUX clocks */
end_comment

begin_define
define|#
directive|define
name|SCRM_ALTCLKSRC
value|(0x110)
end_define

begin_define
define|#
directive|define
name|SCRM_AUXCLK0
value|(0x0310)
end_define

begin_define
define|#
directive|define
name|SCRM_AUXCLK1
value|(0x0314)
end_define

begin_define
define|#
directive|define
name|SCRM_AUXCLK2
value|(0x0318)
end_define

begin_define
define|#
directive|define
name|SCRM_AUXCLK3
value|(0x031C)
end_define

begin_comment
comment|/* Some of the GPIO register set */
end_comment

begin_define
define|#
directive|define
name|GPIO1_OE
value|(0x0134)
end_define

begin_define
define|#
directive|define
name|GPIO1_CLEARDATAOUT
value|(0x0190)
end_define

begin_define
define|#
directive|define
name|GPIO1_SETDATAOUT
value|(0x0194)
end_define

begin_define
define|#
directive|define
name|GPIO2_OE
value|(0x0134)
end_define

begin_define
define|#
directive|define
name|GPIO2_CLEARDATAOUT
value|(0x0190)
end_define

begin_define
define|#
directive|define
name|GPIO2_SETDATAOUT
value|(0x0194)
end_define

begin_comment
comment|/* Some of the PADCONF register set */
end_comment

begin_define
define|#
directive|define
name|CONTROL_WKUP_PAD0_FREF_CLK3_OUT
value|(0x058)
end_define

begin_define
define|#
directive|define
name|CONTROL_CORE_PAD1_KPD_COL2
value|(0x186)
end_define

begin_define
define|#
directive|define
name|CONTROL_CORE_PAD0_GPMC_WAIT1
value|(0x08C)
end_define

begin_define
define|#
directive|define
name|REG_WRITE32
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|)
value|*((volatile uint32_t*)(r)) = (uint32_t)(x)
end_define

begin_define
define|#
directive|define
name|REG_READ32
parameter_list|(
name|r
parameter_list|)
value|*((volatile uint32_t*)(r))
end_define

begin_define
define|#
directive|define
name|REG_WRITE16
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|)
value|*((volatile uint16_t*)(r)) = (uint16_t)(x)
end_define

begin_define
define|#
directive|define
name|REG_READ16
parameter_list|(
name|r
parameter_list|)
value|*((volatile uint16_t*)(r))
end_define

begin_comment
comment|/**  *	usb_hub_init - initialises and resets the external USB hub  *	  *	The USB hub needs to be held in reset while the power is being applied  *	and the reference clock is enabled at 19.2MHz.  The following is the  *	layout of the USB hub taken from the Pandaboard reference manual.  *  *  *	   .-------------.         .--------------.         .----------------.  *	   |  OMAP4430   |         |   USB3320C   |         |    LAN9514     |  *	   |             |         |              |         | USB Hub / Eth  |  *	   |         CLK |<------ | CLKOUT       |         |                |  *	   |         STP | ------> | STP          |         |                |  *	   |         DIR |<------ | DIR          |         |                |  *	   |         NXT |<------ | NXT          |         |                |  *	   |        DAT0 |<-----> | DAT0         |         |                |  *	   |        DAT1 |<-----> | DAT1      DP |<-----> | DP             |  *	   |        DAT2 |<-----> | DAT2      DM |<-----> | DM             |  *	   |        DAT3 |<-----> | DAT3         |         |                |  *	   |        DAT4 |<-----> | DAT4         |         |                |  *	   |        DAT5 |<-----> | DAT5         |  +----> | N_RESET        |  *	   |        DAT6 |<-----> | DAT6         |  |      |                |  *	   |        DAT7 |<-----> | DAT7         |  |      |                |  *	   |             |         |              |  |  +-> | VDD33IO        |  *	   |    AUX_CLK3 | ------> | REFCLK       |  |  +-> | VDD33A         |  *	   |             |         |              |  |  |   |                |  *	   |     GPIO_62 | --+---> | RESET        |  |  |   |                |  *	   |             |   |     |              |  |  |   |                |  *	   |             |   |     '--------------'  |  |   '----------------'  *	   |             |   |     .--------------.  |  |  *	   |             |   '---->| VOLT CONVERT |--'  |  *	   |             |         '--------------'     |  *	   |             |                              |  *	   |             |         .--------------.     |  *	   |      GPIO_1 | ------> |   TPS73633   |-----'  *	   |             |         '--------------'  *	   '-------------'  *	  *  *	RETURNS:  *	nothing.  */
end_comment

begin_function
specifier|static
name|void
name|usb_hub_init
parameter_list|(
name|void
parameter_list|)
block|{
name|bus_space_handle_t
name|scrm_addr
decl_stmt|,
name|gpio1_addr
decl_stmt|,
name|gpio2_addr
decl_stmt|,
name|scm_addr
decl_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|OMAP44XX_SCRM_HWBASE
argument_list|,
name|OMAP44XX_SCRM_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|scrm_addr
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map SCRM registers"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|OMAP44XX_GPIO1_HWBASE
argument_list|,
name|OMAP44XX_GPIO1_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|gpio1_addr
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map GPIO1 registers"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|OMAP44XX_GPIO2_HWBASE
argument_list|,
name|OMAP44XX_GPIO2_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|gpio2_addr
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map GPIO2 registers"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|OMAP44XX_SCM_PADCONF_HWBASE
argument_list|,
name|OMAP44XX_SCM_PADCONF_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|scm_addr
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map SCM Padconf registers"
argument_list|)
expr_stmt|;
comment|/* Need to set FREF_CLK3_OUT to 19.2 MHz and pump it out on pin GPIO_WK31. 	 * We know the SYS_CLK is 38.4Mhz and therefore to get the needed 19.2Mhz, 	 * just use a 2x divider and ensure the SYS_CLK is used as the source. 	 */
name|REG_WRITE32
argument_list|(
name|scrm_addr
operator|+
name|SCRM_AUXCLK3
argument_list|,
operator|(
literal|1
operator|<<
literal|16
operator|)
operator||
comment|/* Divider of 2 */
operator|(
literal|0
operator|<<
literal|1
operator|)
operator||
comment|/* Use the SYS_CLK as the source */
operator|(
literal|1
operator|<<
literal|8
operator|)
argument_list|)
expr_stmt|;
comment|/* Enable the clock */
comment|/* Enable the clock out to the pin (GPIO_WK31).  	 *   muxmode=fref_clk3_out, pullup/down=disabled, input buffer=disabled, 	 *   wakeup=disabled. 	 */
name|REG_WRITE16
argument_list|(
name|scm_addr
operator|+
name|CONTROL_WKUP_PAD0_FREF_CLK3_OUT
argument_list|,
literal|0x0000
argument_list|)
expr_stmt|;
comment|/* Disable the power to the USB hub, drive GPIO1 low */
name|REG_WRITE32
argument_list|(
name|gpio1_addr
operator|+
name|GPIO1_OE
argument_list|,
name|REG_READ32
argument_list|(
name|gpio1_addr
operator|+
name|GPIO1_OE
argument_list|)
operator|&
operator|~
operator|(
literal|1UL
operator|<<
literal|1
operator|)
argument_list|)
expr_stmt|;
name|REG_WRITE32
argument_list|(
name|gpio1_addr
operator|+
name|GPIO1_CLEARDATAOUT
argument_list|,
operator|(
literal|1UL
operator|<<
literal|1
operator|)
argument_list|)
expr_stmt|;
name|REG_WRITE16
argument_list|(
name|scm_addr
operator|+
name|CONTROL_CORE_PAD1_KPD_COL2
argument_list|,
literal|0x0003
argument_list|)
expr_stmt|;
comment|/* Reset the USB PHY and Hub using GPIO_62 */
name|REG_WRITE32
argument_list|(
name|gpio2_addr
operator|+
name|GPIO2_OE
argument_list|,
name|REG_READ32
argument_list|(
name|gpio2_addr
operator|+
name|GPIO2_OE
argument_list|)
operator|&
operator|~
operator|(
literal|1UL
operator|<<
literal|30
operator|)
argument_list|)
expr_stmt|;
name|REG_WRITE32
argument_list|(
name|gpio2_addr
operator|+
name|GPIO2_CLEARDATAOUT
argument_list|,
operator|(
literal|1UL
operator|<<
literal|30
operator|)
argument_list|)
expr_stmt|;
name|REG_WRITE16
argument_list|(
name|scm_addr
operator|+
name|CONTROL_CORE_PAD0_GPMC_WAIT1
argument_list|,
literal|0x0003
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|REG_WRITE32
argument_list|(
name|gpio2_addr
operator|+
name|GPIO2_SETDATAOUT
argument_list|,
operator|(
literal|1UL
operator|<<
literal|30
operator|)
argument_list|)
expr_stmt|;
comment|/* Enable power to the hub (GPIO_1) */
name|REG_WRITE32
argument_list|(
name|gpio1_addr
operator|+
name|GPIO1_SETDATAOUT
argument_list|,
operator|(
literal|1UL
operator|<<
literal|1
operator|)
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scrm_addr
argument_list|,
name|OMAP44XX_SCRM_SIZE
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|gpio1_addr
argument_list|,
name|OMAP44XX_GPIO1_SIZE
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|gpio2_addr
argument_list|,
name|OMAP44XX_GPIO2_SIZE
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scm_addr
argument_list|,
name|OMAP44XX_SCM_PADCONF_SIZE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  *	board_init - initialises the pandaboard  *	@dummy: ignored  *   *	This function is called before any of the driver are initialised, which is  *	annoying because it means we can't use the SCM, PRCM and GPIO modules which  *	would really be useful.  *  *	So we don't have:  *	   - any drivers  *	   - no interrupts  *  *	What we do have:  *	   - virt/phys mappings from the devmap (see omap4.c)  *	   -   *  *  *	So we are hamstrung without the useful drivers and we have to go back to  *	direct register manupulation. Luckly we don't have to do to much, basically  *	just setup the usb hub/ethernet.  *  */
end_comment

begin_function
specifier|static
name|void
name|board_init
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
comment|/* Initialise the USB phy and hub */
name|usb_hub_init
argument_list|()
expr_stmt|;
comment|/* 	 * XXX Board identification e.g. read out from FPGA or similar should 	 * go here 	 */
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|board_init
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_THIRD
argument_list|,
name|board_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

