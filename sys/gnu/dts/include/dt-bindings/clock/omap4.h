begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2017 Texas Instruments, Inc.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLK_OMAP4_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLK_OMAP4_H
end_define

begin_define
define|#
directive|define
name|OMAP4_CLKCTRL_OFFSET
value|0x20
end_define

begin_define
define|#
directive|define
name|OMAP4_CLKCTRL_INDEX
parameter_list|(
name|offset
parameter_list|)
value|((offset) - OMAP4_CLKCTRL_OFFSET)
end_define

begin_comment
comment|/* mpuss clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_MPU_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* tesla clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_DSP_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* abe clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_L4_ABE_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_AESS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCPDM_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_define
define|#
directive|define
name|OMAP4_DMIC_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x38)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCASP_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x40)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCBSP1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x48)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCBSP2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x50)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCBSP3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x58)
end_define

begin_define
define|#
directive|define
name|OMAP4_SLIMBUS1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x60)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER5_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x68)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER6_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x70)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER7_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x78)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER8_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x80)
end_define

begin_define
define|#
directive|define
name|OMAP4_WD_TIMER3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x88)
end_define

begin_comment
comment|/* l4_ao clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_SMARTREFLEX_MPU_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_SMARTREFLEX_IVA_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_define
define|#
directive|define
name|OMAP4_SMARTREFLEX_CORE_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x38)
end_define

begin_comment
comment|/* l3_1 clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_L3_MAIN_1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* l3_2 clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_L3_MAIN_2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPMC_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_OCMC_RAM_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_comment
comment|/* ducati clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_IPU_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* l3_dma clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_DMA_SYSTEM_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* l3_emif clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_DMM_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_EMIF1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_define
define|#
directive|define
name|OMAP4_EMIF2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x38)
end_define

begin_comment
comment|/* d2d clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_C2C_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* l4_cfg clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_L4_CFG_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_SPINLOCK_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_MAILBOX_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_comment
comment|/* l3_instr clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_L3_MAIN_3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_L3_INSTR_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_OCP_WP_NOC_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x40)
end_define

begin_comment
comment|/* ivahd clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_IVA_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_SL2IF_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_comment
comment|/* iss clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_ISS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_FDIF_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_comment
comment|/* l3_dss clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_DSS_CORE_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* l3_gfx clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_GPU_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_comment
comment|/* l3_init clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_MMC1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_MMC2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_define
define|#
directive|define
name|OMAP4_HSI_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x38)
end_define

begin_define
define|#
directive|define
name|OMAP4_USB_HOST_HS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x58)
end_define

begin_define
define|#
directive|define
name|OMAP4_USB_OTG_HS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x60)
end_define

begin_define
define|#
directive|define
name|OMAP4_USB_TLL_HS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x68)
end_define

begin_define
define|#
directive|define
name|OMAP4_USB_HOST_FS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xd0)
end_define

begin_define
define|#
directive|define
name|OMAP4_OCP2SCP_USB_PHY_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xe0)
end_define

begin_comment
comment|/* l4_per clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_TIMER10_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x28)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER11_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x38)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x40)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x48)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER9_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x50)
end_define

begin_define
define|#
directive|define
name|OMAP4_ELM_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x58)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPIO2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x60)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPIO3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x68)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPIO4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x70)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPIO5_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x78)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPIO6_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x80)
end_define

begin_define
define|#
directive|define
name|OMAP4_HDQ1W_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x88)
end_define

begin_define
define|#
directive|define
name|OMAP4_I2C1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xa0)
end_define

begin_define
define|#
directive|define
name|OMAP4_I2C2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xa8)
end_define

begin_define
define|#
directive|define
name|OMAP4_I2C3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xb0)
end_define

begin_define
define|#
directive|define
name|OMAP4_I2C4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xb8)
end_define

begin_define
define|#
directive|define
name|OMAP4_L4_PER_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xc0)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCBSP4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xe0)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCSPI1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xf0)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCSPI2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0xf8)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCSPI3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x100)
end_define

begin_define
define|#
directive|define
name|OMAP4_MCSPI4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x108)
end_define

begin_define
define|#
directive|define
name|OMAP4_MMC3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x120)
end_define

begin_define
define|#
directive|define
name|OMAP4_MMC4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x128)
end_define

begin_define
define|#
directive|define
name|OMAP4_SLIMBUS2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x138)
end_define

begin_define
define|#
directive|define
name|OMAP4_UART1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x140)
end_define

begin_define
define|#
directive|define
name|OMAP4_UART2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x148)
end_define

begin_define
define|#
directive|define
name|OMAP4_UART3_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x150)
end_define

begin_define
define|#
directive|define
name|OMAP4_UART4_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x158)
end_define

begin_define
define|#
directive|define
name|OMAP4_MMC5_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x160)
end_define

begin_comment
comment|/* l4_wkup clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_L4_WKUP_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_define
define|#
directive|define
name|OMAP4_WD_TIMER2_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x30)
end_define

begin_define
define|#
directive|define
name|OMAP4_GPIO1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x38)
end_define

begin_define
define|#
directive|define
name|OMAP4_TIMER1_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x40)
end_define

begin_define
define|#
directive|define
name|OMAP4_COUNTER_32K_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x50)
end_define

begin_define
define|#
directive|define
name|OMAP4_KBD_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x78)
end_define

begin_comment
comment|/* emu_sys clocks */
end_comment

begin_define
define|#
directive|define
name|OMAP4_DEBUGSS_CLKCTRL
value|OMAP4_CLKCTRL_INDEX(0x20)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

