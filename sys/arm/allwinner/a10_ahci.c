begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014-2015 M. Warner Losh<imp@freebsd.org>  * Copyright (c) 2015 Luiz Otavio O Souza<loos@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The magic-bit-bang sequence used in this code may be based on a linux  * platform driver in the Allwinner SDK from Allwinner Technology Co., Ltd.  * www.allwinnertech.com, by Daniel Wang<danielwang@allwinnertech.com>  * though none of the original code was copied.  */
end_comment

begin_include
include|#
directive|include
file|"opt_bus.h"
end_include

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
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<dev/ahci/ahci.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk.h>
end_include

begin_comment
comment|/*  * Allwinner a1x/a2x/a8x SATA attachment.  This is just the AHCI register  * set with a few extra implementation-specific registers that need to  * be accounted for.  There's only one PHY in the system, and it needs  * to be trained to bring the link up.  In addition, there's some DMA  * specific things that need to be done as well.  These things are also  * just about completely undocumented, except in ugly code in the Linux  * SDK Allwinner releases.  */
end_comment

begin_comment
comment|/* BITx -- Unknown bit that needs to be set/cleared at position x */
end_comment

begin_comment
comment|/* UFx -- Uknown multi-bit field frobbed during init */
end_comment

begin_define
define|#
directive|define
name|AHCI_BISTAFR
value|0x00A0
end_define

begin_define
define|#
directive|define
name|AHCI_BISTCR
value|0x00A4
end_define

begin_define
define|#
directive|define
name|AHCI_BISTFCTR
value|0x00A8
end_define

begin_define
define|#
directive|define
name|AHCI_BISTSR
value|0x00AC
end_define

begin_define
define|#
directive|define
name|AHCI_BISTDECR
value|0x00B0
end_define

begin_define
define|#
directive|define
name|AHCI_DIAGNR
value|0x00B4
end_define

begin_define
define|#
directive|define
name|AHCI_DIAGNR1
value|0x00B8
end_define

begin_define
define|#
directive|define
name|AHCI_OOBR
value|0x00BC
end_define

begin_define
define|#
directive|define
name|AHCI_PHYCS0R
value|0x00C0
end_define

begin_comment
comment|/* Bits 0..17 are a mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS0R_BIT18
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PHYCS0R_POWER_ENABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|PHYCS0R_UF1_MASK
value|(7<< 20)
end_define

begin_comment
comment|/* Unknown Field 1 */
end_comment

begin_define
define|#
directive|define
name|PHYCS0R_UF1_INIT
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|PHYCS0R_BIT23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PHYCS0R_UF2_MASK
value|(7<< 24)
end_define

begin_comment
comment|/* Uknown Field 2 */
end_comment

begin_define
define|#
directive|define
name|PHYCS0R_UF2_INIT
value|(5<< 24)
end_define

begin_comment
comment|/* Bit 27 mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS0R_POWER_STATUS_MASK
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|PHYCS0R_PS_GOOD
value|(2<< 28)
end_define

begin_comment
comment|/* Bit 31 mystery */
end_comment

begin_define
define|#
directive|define
name|AHCI_PHYCS1R
value|0x00C4
end_define

begin_comment
comment|/* Bits 0..5 are a mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS1R_UF1_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|PHYCS1R_UF1_INIT
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|PHYCS1R_UF2_MASK
value|(0x1f<< 8)
end_define

begin_define
define|#
directive|define
name|PHYCS1R_UF2_INIT
value|(6<< 8)
end_define

begin_comment
comment|/* Bits 13..14 are a mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS1R_BIT15
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PHYCS1R_UF3_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|PHYCS1R_UF3_INIT
value|(2<< 16)
end_define

begin_comment
comment|/* Bit 18 mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS1R_HIGHZ
value|(1<< 19)
end_define

begin_comment
comment|/* Bits 20..27 mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS1R_BIT28
value|(1<< 28)
end_define

begin_comment
comment|/* Bits 29..31 mystery */
end_comment

begin_define
define|#
directive|define
name|AHCI_PHYCS2R
value|0x00C8
end_define

begin_comment
comment|/* bits 0..4 mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS2R_UF1_MASK
value|(0x1f<< 5)
end_define

begin_define
define|#
directive|define
name|PHYCS2R_UF1_INIT
value|(0x19<< 5)
end_define

begin_comment
comment|/* Bits 10..23 mystery */
end_comment

begin_define
define|#
directive|define
name|PHYCS2R_CALIBRATE
value|(1<< 24)
end_define

begin_comment
comment|/* Bits 25..31 mystery */
end_comment

begin_define
define|#
directive|define
name|AHCI_TIMER1MS
value|0x00E0
end_define

begin_define
define|#
directive|define
name|AHCI_GPARAM1R
value|0x00E8
end_define

begin_define
define|#
directive|define
name|AHCI_GPARAM2R
value|0x00EC
end_define

begin_define
define|#
directive|define
name|AHCI_PPARAMR
value|0x00F0
end_define

begin_define
define|#
directive|define
name|AHCI_TESTR
value|0x00F4
end_define

begin_define
define|#
directive|define
name|AHCI_VERSIONR
value|0x00F8
end_define

begin_define
define|#
directive|define
name|AHCI_IDR
value|0x00FC
end_define

begin_define
define|#
directive|define
name|AHCI_RWCR
value|0x00FC
end_define

begin_define
define|#
directive|define
name|AHCI_P0DMACR
value|0x0070
end_define

begin_define
define|#
directive|define
name|AHCI_P0PHYCR
value|0x0078
end_define

begin_define
define|#
directive|define
name|AHCI_P0PHYSR
value|0x007C
end_define

begin_define
define|#
directive|define
name|PLL_FREQ
value|100000000
end_define

begin_function
specifier|static
name|void
specifier|inline
name|ahci_set
parameter_list|(
name|struct
name|resource
modifier|*
name|m
parameter_list|,
name|bus_size_t
name|off
parameter_list|,
name|uint32_t
name|set
parameter_list|)
block|{
name|uint32_t
name|val
init|=
name|ATA_INL
argument_list|(
name|m
argument_list|,
name|off
argument_list|)
decl_stmt|;
name|val
operator||=
name|set
expr_stmt|;
name|ATA_OUTL
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
specifier|inline
name|ahci_clr
parameter_list|(
name|struct
name|resource
modifier|*
name|m
parameter_list|,
name|bus_size_t
name|off
parameter_list|,
name|uint32_t
name|clr
parameter_list|)
block|{
name|uint32_t
name|val
init|=
name|ATA_INL
argument_list|(
name|m
argument_list|,
name|off
argument_list|)
decl_stmt|;
name|val
operator|&=
operator|~
name|clr
expr_stmt|;
name|ATA_OUTL
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
specifier|inline
name|ahci_mask_set
parameter_list|(
name|struct
name|resource
modifier|*
name|m
parameter_list|,
name|bus_size_t
name|off
parameter_list|,
name|uint32_t
name|mask
parameter_list|,
name|uint32_t
name|set
parameter_list|)
block|{
name|uint32_t
name|val
init|=
name|ATA_INL
argument_list|(
name|m
argument_list|,
name|off
argument_list|)
decl_stmt|;
name|val
operator|&=
name|mask
expr_stmt|;
name|val
operator||=
name|set
expr_stmt|;
name|ATA_OUTL
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Should this be phy_reset or phy_init  */
end_comment

begin_define
define|#
directive|define
name|PHY_RESET_TIMEOUT
value|1000
end_define

begin_function
specifier|static
name|void
name|ahci_a10_phy_reset
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|uint32_t
name|to
decl_stmt|,
name|val
decl_stmt|;
name|struct
name|ahci_controller
modifier|*
name|ctlr
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
comment|/* 	 * Here starts the magic -- most of the comments are based 	 * on guesswork, names of routines and printf error 	 * messages.  The code works, but it will do that even if the 	 * comments are 100% BS. 	 */
comment|/* 	 * Lock out other access while we initialize.  Or at least that 	 * seems to be the case based on Linux SDK #defines.  Maybe this 	 * put things into reset? 	 */
name|ATA_OUTL
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_RWCR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|/* 	 * Set bit 19 in PHYCS1R.  Guessing this disables driving the PHY 	 * port for a bit while we reset things. 	 */
name|ahci_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS1R
argument_list|,
name|PHYCS1R_HIGHZ
argument_list|)
expr_stmt|;
comment|/* 	 * Frob PHYCS0R... 	 */
name|ahci_mask_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS0R
argument_list|,
operator|~
name|PHYCS0R_UF2_MASK
argument_list|,
name|PHYCS0R_UF2_INIT
operator||
name|PHYCS0R_BIT23
operator||
name|PHYCS0R_BIT18
argument_list|)
expr_stmt|;
comment|/* 	 * Set three fields in PHYCS1R 	 */
name|ahci_mask_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS1R
argument_list|,
operator|~
operator|(
name|PHYCS1R_UF1_MASK
operator||
name|PHYCS1R_UF2_MASK
operator||
name|PHYCS1R_UF3_MASK
operator|)
argument_list|,
name|PHYCS1R_UF1_INIT
operator||
name|PHYCS1R_UF2_INIT
operator||
name|PHYCS1R_UF3_INIT
argument_list|)
expr_stmt|;
comment|/* 	 * Two more mystery bits in PHYCS1R. -- can these be combined above? 	 */
name|ahci_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS1R
argument_list|,
name|PHYCS1R_BIT15
operator||
name|PHYCS1R_BIT28
argument_list|)
expr_stmt|;
comment|/* 	 * Now clear that first mysery bit.  Perhaps this starts 	 * driving the PHY again so we can power it up and start 	 * talking to the SATA drive, if any below. 	 */
name|ahci_clr
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS1R
argument_list|,
name|PHYCS1R_HIGHZ
argument_list|)
expr_stmt|;
comment|/* 	 * Frob PHYCS0R again... 	 */
name|ahci_mask_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS0R
argument_list|,
operator|~
name|PHYCS0R_UF1_MASK
argument_list|,
name|PHYCS0R_UF1_INIT
argument_list|)
expr_stmt|;
comment|/* 	 * Frob PHYCS2R, because 25 means something? 	 */
name|ahci_mask_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS2R
argument_list|,
operator|~
name|PHYCS2R_UF1_MASK
argument_list|,
name|PHYCS2R_UF1_INIT
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|/* WAG */
comment|/* 	 * Turn on the power to the PHY and wait for it to report back 	 * good? 	 */
name|ahci_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS0R
argument_list|,
name|PHYCS0R_POWER_ENABLE
argument_list|)
expr_stmt|;
for|for
control|(
name|to
operator|=
name|PHY_RESET_TIMEOUT
init|;
name|to
operator|>
literal|0
condition|;
name|to
operator|--
control|)
block|{
name|val
operator|=
name|ATA_INL
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS0R
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|PHYCS0R_POWER_STATUS_MASK
operator|)
operator|==
name|PHYCS0R_PS_GOOD
condition|)
break|break;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|to
operator|==
literal|0
operator|&&
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"PHY Power Failed PHYCS0R = %#x\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* 	 * Calibrate the clocks between the device and the host.  This appears 	 * to be an automated process that clears the bit when it is done. 	 */
name|ahci_set
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS2R
argument_list|,
name|PHYCS2R_CALIBRATE
argument_list|)
expr_stmt|;
for|for
control|(
name|to
operator|=
name|PHY_RESET_TIMEOUT
init|;
name|to
operator|>
literal|0
condition|;
name|to
operator|--
control|)
block|{
name|val
operator|=
name|ATA_INL
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_PHYCS2R
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|PHYCS2R_CALIBRATE
operator|)
operator|==
literal|0
condition|)
break|break;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|to
operator|==
literal|0
operator|&&
name|bootverbose
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"PHY Cal Failed PHYCS2R %#x\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* 	 * OK, let things settle down a bit. 	 */
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* 	 * Go back into normal mode now that we've calibrated the PHY. 	 */
name|ATA_OUTL
argument_list|(
name|ctlr
operator|->
name|r_mem
argument_list|,
name|AHCI_RWCR
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ahci_a10_ch_start
parameter_list|(
name|struct
name|ahci_channel
modifier|*
name|ch
parameter_list|)
block|{
name|uint32_t
name|reg
decl_stmt|;
comment|/* 	 * Magical values from Allwinner SDK, setup the DMA before start 	 * operations on this channel. 	 */
name|reg
operator|=
name|ATA_INL
argument_list|(
name|ch
operator|->
name|r_mem
argument_list|,
name|AHCI_P0DMACR
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
literal|0xff00
expr_stmt|;
name|reg
operator||=
literal|0x4400
expr_stmt|;
name|ATA_OUTL
argument_list|(
name|ch
operator|->
name|r_mem
argument_list|,
name|AHCI_P0DMACR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|ahci_a10_ctlr_reset
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|ahci_a10_phy_reset
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|ahci_ctlr_reset
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ahci_a10_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"allwinner,sun4i-a10-ahci"
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
literal|"Allwinner Integrated AHCI controller"
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
name|ahci_a10_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|struct
name|ahci_controller
modifier|*
name|ctlr
decl_stmt|;
name|clk_t
name|clk_pll
decl_stmt|,
name|clk_gate
decl_stmt|;
name|ctlr
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|clk_pll
operator|=
name|clk_gate
operator|=
name|NULL
expr_stmt|;
name|ctlr
operator|->
name|quirks
operator|=
name|AHCI_Q_NOPMP
expr_stmt|;
name|ctlr
operator|->
name|vendorid
operator|=
literal|0
expr_stmt|;
name|ctlr
operator|->
name|deviceid
operator|=
literal|0
expr_stmt|;
name|ctlr
operator|->
name|subvendorid
operator|=
literal|0
expr_stmt|;
name|ctlr
operator|->
name|subdeviceid
operator|=
literal|0
expr_stmt|;
name|ctlr
operator|->
name|r_rid
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ctlr
operator|->
name|r_mem
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|ctlr
operator|->
name|r_rid
argument_list|,
name|RF_ACTIVE
argument_list|)
operator|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* Enable clocks */
name|error
operator|=
name|clk_get_by_ofw_index
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|clk_pll
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot get PLL clock\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
name|error
operator|=
name|clk_get_by_ofw_index
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
operator|&
name|clk_gate
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot get gate clock\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
name|error
operator|=
name|clk_set_freq
argument_list|(
name|clk_pll
argument_list|,
name|PLL_FREQ
argument_list|,
name|CLK_SET_ROUND_DOWN
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot set PLL frequency\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
name|error
operator|=
name|clk_enable
argument_list|(
name|clk_pll
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot enable PLL\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
name|error
operator|=
name|clk_enable
argument_list|(
name|clk_gate
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Cannot enable clk gate\n"
argument_list|)
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* Reset controller */
if|if
condition|(
operator|(
name|error
operator|=
name|ahci_a10_ctlr_reset
argument_list|(
name|dev
argument_list|)
operator|)
operator|!=
literal|0
condition|)
goto|goto
name|fail
goto|;
comment|/* 	 * No MSI registers on this platform. 	 */
name|ctlr
operator|->
name|msi
operator|=
literal|0
expr_stmt|;
name|ctlr
operator|->
name|numirqs
operator|=
literal|1
expr_stmt|;
comment|/* Channel start callback(). */
name|ctlr
operator|->
name|ch_start
operator|=
name|ahci_a10_ch_start
expr_stmt|;
comment|/* 	 * Note: ahci_attach will release ctlr->r_mem on errors automatically 	 */
return|return
operator|(
name|ahci_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
name|fail
label|:
if|if
condition|(
name|clk_gate
operator|!=
name|NULL
condition|)
name|clk_release
argument_list|(
name|clk_gate
argument_list|)
expr_stmt|;
if|if
condition|(
name|clk_pll
operator|!=
name|NULL
condition|)
name|clk_release
argument_list|(
name|clk_pll
argument_list|)
expr_stmt|;
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
name|ctlr
operator|->
name|r_rid
argument_list|,
name|ctlr
operator|->
name|r_mem
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ahci_a10_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|ahci_detach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|ahci_ata_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ahci_a10_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ahci_a10_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|ahci_a10_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|ahci_print_child
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_alloc_resource
argument_list|,
name|ahci_alloc_resource
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_release_resource
argument_list|,
name|ahci_release_resource
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_setup_intr
argument_list|,
name|ahci_setup_intr
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_teardown_intr
argument_list|,
name|ahci_teardown_intr
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_child_location_str
argument_list|,
name|ahci_child_location_str
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|ahci_ata_driver
init|=
block|{
literal|"ahci"
block|,
name|ahci_ata_methods
block|,
expr|sizeof
operator|(
expr|struct
name|ahci_controller
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ahci
argument_list|,
name|simplebus
argument_list|,
name|ahci_ata_driver
argument_list|,
name|ahci_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

