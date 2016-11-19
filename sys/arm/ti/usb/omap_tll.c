begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_prcm.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/usb/omap_usb.h>
end_include

begin_comment
comment|/*  * USB TLL Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP_USBTLL_REVISION
value|0x0000
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_SYSCONFIG
value|0x0010
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_SYSSTATUS
value|0x0014
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_IRQSTATUS
value|0x0018
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_IRQENABLE
value|0x001C
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_TLL_SHARED_CONF
value|0x0030
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_TLL_CHANNEL_CONF
parameter_list|(
name|i
parameter_list|)
value|(0x0040 + (0x04 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_SAR_CNTX
parameter_list|(
name|i
parameter_list|)
value|(0x0400 + (0x04 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_ID_LO
parameter_list|(
name|i
parameter_list|)
value|(0x0800 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_ID_HI
parameter_list|(
name|i
parameter_list|)
value|(0x0801 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_PRODUCT_ID_LO
parameter_list|(
name|i
parameter_list|)
value|(0x0802 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_PRODUCT_ID_HI
parameter_list|(
name|i
parameter_list|)
value|(0x0803 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_FUNCTION_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0804 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_FUNCTION_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0805 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_FUNCTION_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0806 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_INTERFACE_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0807 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_INTERFACE_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0808 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_INTERFACE_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0809 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_OTG_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x080A + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_OTG_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x080B + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_OTG_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x080C + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_RISE
parameter_list|(
name|i
parameter_list|)
value|(0x080D + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_RISE_SET
parameter_list|(
name|i
parameter_list|)
value|(0x080E + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_RISE_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x080F + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_FALL
parameter_list|(
name|i
parameter_list|)
value|(0x0810 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_FALL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0811 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_FALL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0812 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0813 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x0814 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_DEBUG
parameter_list|(
name|i
parameter_list|)
value|(0x0815 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_SCRATCH_REGISTER
parameter_list|(
name|i
parameter_list|)
value|(0x0816 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_SCRATCH_REGISTER_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0817 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_SCRATCH_REGISTER_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0818 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_EXTENDED_SET_ACCESS
parameter_list|(
name|i
parameter_list|)
value|(0x082F + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_EN
parameter_list|(
name|i
parameter_list|)
value|(0x0830 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_EN_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0831 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_EN_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0832 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0833 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x0834 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VSTATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0835 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VSTATUS_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0836 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VSTATUS_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0837 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_LATCH_NOCLR
parameter_list|(
name|i
parameter_list|)
value|(0x0838 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_EN
parameter_list|(
name|i
parameter_list|)
value|(0x083B + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_EN_SET
parameter_list|(
name|i
parameter_list|)
value|(0x083C + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_EN_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x083D + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x083E + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x083F + (0x100 * (i)))
end_define

begin_comment
comment|/* TLL Register Set */
end_comment

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_CACTIVITY
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SIDLE_SMART_IDLE
value|(2UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SIDLE_NO_IDLE
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SIDLE_FORCED_IDLE
value|(0UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_ENAWAKEUP
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SOFTRESET
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_AUTOIDLE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TLL_SYSSTATUS_RESETDONE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_90D_DDR_EN
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_180D_SDR_EN
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_MASK
value|(7UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_128
value|(7UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_64
value|(6UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_32
value|(5UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_16
value|(4UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_8
value|(3UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_4
value|(2UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_2
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_1
value|(0UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_FCLK_REQ
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_FCLK_IS_ON
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_DRVVBUS
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_CHRGVBUS
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPINOBITSTUFF
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPIAUTOIDLE
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_UTMIAUTOIDLE
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPIDDRMODE
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPIOUTCLKMODE
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_TLLFULLSPEED
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_TLLCONNECT
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_TLLATTACH
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_UTMIISADEV
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_CHANEN
value|(1UL<< 0)
end_define

begin_struct
struct|struct
name|omap_tll_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* TLL register set */
name|struct
name|resource
modifier|*
name|tll_mem_res
decl_stmt|;
name|int
name|tll_mem_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|omap_tll_softc
modifier|*
name|omap_tll_sc
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|omap_tll_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|omap_tll_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|uint32_t
name|omap_tll_read_4
parameter_list|(
name|struct
name|omap_tll_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|off
parameter_list|)
block|{
return|return
name|bus_read_4
argument_list|(
name|sc
operator|->
name|tll_mem_res
argument_list|,
name|off
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|omap_tll_write_4
parameter_list|(
name|struct
name|omap_tll_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|off
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_write_4
argument_list|(
name|sc
operator|->
name|tll_mem_res
argument_list|,
name|off
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|omap_tll_utmi_enable
parameter_list|(
name|unsigned
name|int
name|en_mask
parameter_list|)
block|{
name|struct
name|omap_tll_softc
modifier|*
name|sc
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|sc
operator|=
name|omap_tll_sc
expr_stmt|;
if|if
condition|(
name|sc
operator|==
name|NULL
condition|)
return|return;
comment|/* There are 3 TLL channels, one per USB controller so set them all up the 	 * same, SDR mode, bit stuffing and no autoidle. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|reg
operator|=
name|omap_tll_read_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_TLL_CHANNEL_CONF
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|TLL_CHANNEL_CONF_UTMIAUTOIDLE
operator||
name|TLL_CHANNEL_CONF_ULPINOBITSTUFF
operator||
name|TLL_CHANNEL_CONF_ULPIDDRMODE
operator|)
expr_stmt|;
name|omap_tll_write_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_TLL_CHANNEL_CONF
argument_list|(
name|i
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
comment|/* Program the common TLL register */
name|reg
operator|=
name|omap_tll_read_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_TLL_SHARED_CONF
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|TLL_SHARED_CONF_USB_90D_DDR_EN
operator||
name|TLL_SHARED_CONF_USB_DIVRATIO_MASK
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|TLL_SHARED_CONF_FCLK_IS_ON
operator||
name|TLL_SHARED_CONF_USB_DIVRATIO_2
operator||
name|TLL_SHARED_CONF_USB_180D_SDR_EN
operator|)
expr_stmt|;
name|omap_tll_write_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_TLL_SHARED_CONF
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Enable channels now */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|reg
operator|=
name|omap_tll_read_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_TLL_CHANNEL_CONF
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Enable only the reg that is needed */
if|if
condition|(
operator|(
name|en_mask
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
operator|)
operator|==
literal|0
condition|)
continue|continue;
name|reg
operator||=
name|TLL_CHANNEL_CONF_CHANEN
expr_stmt|;
name|omap_tll_write_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_TLL_CHANNEL_CONF
argument_list|(
name|i
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|omap_tll_init
parameter_list|(
name|struct
name|omap_tll_softc
modifier|*
name|sc
parameter_list|)
block|{
name|unsigned
name|long
name|timeout
decl_stmt|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
comment|/* Enable the USB TLL */
name|ti_prcm_clk_enable
argument_list|(
name|USBTLL_CLK
argument_list|)
expr_stmt|;
comment|/* Perform TLL soft reset, and wait until reset is complete */
name|omap_tll_write_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_SYSCONFIG
argument_list|,
name|TLL_SYSCONFIG_SOFTRESET
argument_list|)
expr_stmt|;
comment|/* Set the timeout to 100ms*/
name|timeout
operator|=
operator|(
name|hz
operator|<
literal|10
operator|)
condition|?
literal|1
else|:
operator|(
operator|(
literal|100
operator|*
name|hz
operator|)
operator|/
literal|1000
operator|)
expr_stmt|;
comment|/* Wait for TLL reset to complete */
while|while
condition|(
operator|(
name|omap_tll_read_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_SYSSTATUS
argument_list|)
operator|&
name|TLL_SYSSTATUS_RESETDONE
operator|)
operator|==
literal|0x00
condition|)
block|{
comment|/* Sleep for a tick */
name|pause
argument_list|(
literal|"USBRESET"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|timeout
operator|--
operator|==
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"TLL reset operation timed out\n"
argument_list|)
expr_stmt|;
name|ret
operator|=
name|EINVAL
expr_stmt|;
goto|goto
name|err_sys_status
goto|;
block|}
block|}
comment|/* CLOCKACTIVITY = 1 : OCP-derived internal clocks ON during idle 	 * SIDLEMODE = 2     : Smart-idle mode. Sidleack asserted after Idlereq 	 *                     assertion when no more activity on the USB. 	 * ENAWAKEUP = 1     : Wakeup generation enabled 	 */
name|omap_tll_write_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_SYSCONFIG
argument_list|,
name|TLL_SYSCONFIG_ENAWAKEUP
operator||
name|TLL_SYSCONFIG_AUTOIDLE
operator||
name|TLL_SYSCONFIG_SIDLE_SMART_IDLE
operator||
name|TLL_SYSCONFIG_CACTIVITY
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|err_sys_status
label|:
comment|/* Disable the TLL clocks */
name|ti_prcm_clk_disable
argument_list|(
name|USBTLL_CLK
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|omap_tll_disable
parameter_list|(
name|struct
name|omap_tll_softc
modifier|*
name|sc
parameter_list|)
block|{
name|unsigned
name|long
name|timeout
decl_stmt|;
name|timeout
operator|=
operator|(
name|hz
operator|<
literal|10
operator|)
condition|?
literal|1
else|:
operator|(
operator|(
literal|100
operator|*
name|hz
operator|)
operator|/
literal|1000
operator|)
expr_stmt|;
comment|/* Reset the TLL module */
name|omap_tll_write_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_SYSCONFIG
argument_list|,
literal|0x0002
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|omap_tll_read_4
argument_list|(
name|sc
argument_list|,
name|OMAP_USBTLL_SYSSTATUS
argument_list|)
operator|&
operator|(
literal|0x01
operator|)
operator|)
operator|==
literal|0x00
condition|)
block|{
comment|/* Sleep for a tick */
name|pause
argument_list|(
literal|"USBRESET"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|timeout
operator|--
operator|==
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|,
literal|"operation timed out\n"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* Disable functional and interface clocks for the TLL and HOST modules */
name|ti_prcm_clk_disable
argument_list|(
name|USBTLL_CLK
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|omap_tll_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"ti,usbhs-tll"
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"TI OMAP USB 2.0 TLL module"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|omap_tll_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|omap_tll_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* save the device */
name|sc
operator|->
name|sc_dev
operator|=
name|dev
expr_stmt|;
comment|/* Allocate resource for the TLL register set */
name|sc
operator|->
name|tll_mem_rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|tll_mem_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|sc
operator|->
name|tll_mem_rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sc
operator|->
name|tll_mem_res
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Error: Could not map TLL memory\n"
argument_list|)
expr_stmt|;
goto|goto
name|error
goto|;
block|}
name|omap_tll_init
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|omap_tll_sc
operator|=
name|sc
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|error
label|:
name|omap_tll_detach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|omap_tll_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|omap_tll_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|omap_tll_disable
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* Release the other register set memory maps */
if|if
condition|(
name|sc
operator|->
name|tll_mem_res
condition|)
block|{
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
name|sc
operator|->
name|tll_mem_rid
argument_list|,
name|sc
operator|->
name|tll_mem_res
argument_list|)
expr_stmt|;
name|sc
operator|->
name|tll_mem_res
operator|=
name|NULL
expr_stmt|;
block|}
name|omap_tll_sc
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|omap_tll_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|omap_tll_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|omap_tll_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|omap_tll_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|bus_generic_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|bus_generic_resume
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|bus_generic_shutdown
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|omap_tll_driver
init|=
block|{
literal|"omap_tll"
block|,
name|omap_tll_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|omap_tll_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|omap_tll_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|omap_tll
argument_list|,
name|simplebus
argument_list|,
name|omap_tll_driver
argument_list|,
name|omap_tll_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

