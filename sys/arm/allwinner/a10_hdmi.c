begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Jared McNeill<jmcneill@invisible.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Allwinner A10/A20 HDMI TX   */
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
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
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
file|<dev/videomode/videomode.h>
end_include

begin_include
include|#
directive|include
file|<dev/videomode/edidvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/a10_clk.h>
end_include

begin_include
include|#
directive|include
file|"hdmi_if.h"
end_include

begin_define
define|#
directive|define
name|HDMI_CTRL
value|0x004
end_define

begin_define
define|#
directive|define
name|CTRL_MODULE_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|HDMI_INT_STATUS
value|0x008
end_define

begin_define
define|#
directive|define
name|HDMI_HPD
value|0x00c
end_define

begin_define
define|#
directive|define
name|HPD_DET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_VID_CTRL
value|0x010
end_define

begin_define
define|#
directive|define
name|VID_CTRL_VIDEO_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|VID_CTRL_HDMI_MODE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|VID_CTRL_INTERLACE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|VID_CTRL_REPEATER_2X
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_VID_TIMING0
value|0x014
end_define

begin_define
define|#
directive|define
name|VID_ACT_V
parameter_list|(
name|v
parameter_list|)
value|(((v) - 1)<< 16)
end_define

begin_define
define|#
directive|define
name|VID_ACT_H
parameter_list|(
name|h
parameter_list|)
value|(((h) - 1)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_VID_TIMING1
value|0x018
end_define

begin_define
define|#
directive|define
name|VID_VBP
parameter_list|(
name|vbp
parameter_list|)
value|(((vbp) - 1)<< 16)
end_define

begin_define
define|#
directive|define
name|VID_HBP
parameter_list|(
name|hbp
parameter_list|)
value|(((hbp) - 1)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_VID_TIMING2
value|0x01c
end_define

begin_define
define|#
directive|define
name|VID_VFP
parameter_list|(
name|vfp
parameter_list|)
value|(((vfp) - 1)<< 16)
end_define

begin_define
define|#
directive|define
name|VID_HFP
parameter_list|(
name|hfp
parameter_list|)
value|(((hfp) - 1)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_VID_TIMING3
value|0x020
end_define

begin_define
define|#
directive|define
name|VID_VSPW
parameter_list|(
name|vspw
parameter_list|)
value|(((vspw) - 1)<< 16)
end_define

begin_define
define|#
directive|define
name|VID_HSPW
parameter_list|(
name|hspw
parameter_list|)
value|(((hspw) - 1)<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_VID_TIMING4
value|0x024
end_define

begin_define
define|#
directive|define
name|TX_CLOCK_NORMAL
value|0x03e00000
end_define

begin_define
define|#
directive|define
name|VID_VSYNC_ACTSEL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VID_HSYNC_ACTSEL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CTRL
value|0x040
end_define

begin_define
define|#
directive|define
name|AUD_CTRL_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|AUD_CTRL_RST
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|HDMI_ADMA_CTRL
value|0x044
end_define

begin_define
define|#
directive|define
name|HDMI_ADMA_MODE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|HDMI_ADMA_MODE_DDMA
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|HDMI_ADMA_MODE_NDMA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_FMT
value|0x048
end_define

begin_define
define|#
directive|define
name|AUD_FMT_CH
parameter_list|(
name|n
parameter_list|)
value|((n) - 1)
end_define

begin_define
define|#
directive|define
name|HDMI_PCM_CTRL
value|0x04c
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CTS
value|0x050
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_N
value|0x054
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CH_STATUS0
value|0x058
end_define

begin_define
define|#
directive|define
name|CH_STATUS0_FS_FREQ
value|(0xf<< 24)
end_define

begin_define
define|#
directive|define
name|CH_STATUS0_FS_FREQ_48
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|HDMI_AUD_CH_STATUS1
value|0x05c
end_define

begin_define
define|#
directive|define
name|CH_STATUS1_WORD_LEN
value|(0x7<< 1)
end_define

begin_define
define|#
directive|define
name|CH_STATUS1_WORD_LEN_16
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_RESET_RETRY
value|1000
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_CHANNELS
value|2
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_CHANNELMAP
value|0x76543210
end_define

begin_define
define|#
directive|define
name|HDMI_AUDIO_N
value|6144
end_define

begin_comment
comment|/* 48 kHz */
end_comment

begin_define
define|#
directive|define
name|HDMI_AUDIO_CTS
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
value|((((r) * 10) * ((n) / 128)) / 480)
end_define

begin_define
define|#
directive|define
name|HDMI_PADCTRL0
value|0x200
end_define

begin_define
define|#
directive|define
name|PADCTRL0_BIASEN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_LDOCEN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_LDODEN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_PWENC
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_PWEND
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_PWENG
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_CKEN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_SEN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|PADCTRL0_TXEN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|HDMI_PADCTRL1
value|0x204
end_define

begin_define
define|#
directive|define
name|PADCTRL1_AMP_OPT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_AMPCK_OPT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_DMP_OPT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_EMP_OPT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_EMPCK_OPT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_PWSCK
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_PWSDT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_CSMPS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_DEN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_DENCK
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_PLRCK
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_EMP
value|(0x7<< 10)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_EMP_EN
value|(0x2<< 10)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_CD
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_CKSS
value|(0x3<< 6)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_CKSS_1X
value|(0x1<< 6)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_CKSS_2X
value|(0x0<< 6)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_AMP
value|(0x7<< 3)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_AMP_EN
value|(0x6<< 3)
end_define

begin_define
define|#
directive|define
name|PADCTRL1_REG_PLR
value|(0x7<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_PLLCTRL0
value|0x208
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_PLL_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_BWS
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_HV_IS_33
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_LDO1_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_LDO2_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_SDIV2
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_VCO_GAIN
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_S
value|(0x7<< 17)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_CP_S
value|(0xf<< 12)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_CS
value|(0x7<< 8)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_PREDIV
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|PLLCTRL0_VCO_S
value|(0x8<< 0)
end_define

begin_define
define|#
directive|define
name|HDMI_PLLDBG0
value|0x20c
end_define

begin_define
define|#
directive|define
name|PLLDBG0_CKIN_SEL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PLLDBG0_CKIN_SEL_PLL3
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|PLLDBG0_CKIN_SEL_PLL7
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|HDMI_PKTCTRL0
value|0x2f0
end_define

begin_define
define|#
directive|define
name|HDMI_PKTCTRL1
value|0x2f4
end_define

begin_define
define|#
directive|define
name|PKTCTRL_PACKET
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|((t)<< ((n)<< 2))
end_define

begin_define
define|#
directive|define
name|PKT_NULL
value|0
end_define

begin_define
define|#
directive|define
name|PKT_GC
value|1
end_define

begin_define
define|#
directive|define
name|PKT_AVI
value|2
end_define

begin_define
define|#
directive|define
name|PKT_AI
value|3
end_define

begin_define
define|#
directive|define
name|PKT_SPD
value|5
end_define

begin_define
define|#
directive|define
name|PKT_END
value|15
end_define

begin_define
define|#
directive|define
name|DDC_CTRL
value|0x500
end_define

begin_define
define|#
directive|define
name|CTRL_DDC_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|CTRL_DDC_ACMD_START
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CTRL_DDC_FIFO_DIR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CTRL_DDC_FIFO_DIR_READ
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|CTRL_DDC_FIFO_DIR_WRITE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CTRL_DDC_SWRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DDC_SLAVE_ADDR
value|0x504
end_define

begin_define
define|#
directive|define
name|SLAVE_ADDR_SEG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SLAVE_ADDR_EDDC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SLAVE_ADDR_OFFSET_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SLAVE_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DDC_INT_STATUS
value|0x50c
end_define

begin_define
define|#
directive|define
name|INT_STATUS_XFER_DONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DDC_FIFO_CTRL
value|0x510
end_define

begin_define
define|#
directive|define
name|FIFO_CTRL_CLEAR
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DDC_BYTE_COUNTER
value|0x51c
end_define

begin_define
define|#
directive|define
name|DDC_COMMAND
value|0x520
end_define

begin_define
define|#
directive|define
name|COMMAND_EOREAD
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|DDC_CLOCK
value|0x528
end_define

begin_define
define|#
directive|define
name|DDC_CLOCK_M
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DDC_CLOCK_N
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|DDC_FIFO
value|0x518
end_define

begin_define
define|#
directive|define
name|SWRST_DELAY
value|1000
end_define

begin_define
define|#
directive|define
name|DDC_DELAY
value|1000
end_define

begin_define
define|#
directive|define
name|DDC_RETRY
value|1000
end_define

begin_define
define|#
directive|define
name|DDC_BLKLEN
value|16
end_define

begin_define
define|#
directive|define
name|DDC_ADDR
value|0x50
end_define

begin_define
define|#
directive|define
name|EDDC_ADDR
value|0x60
end_define

begin_define
define|#
directive|define
name|EDID_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|HDMI_ENABLE_DELAY
value|50000
end_define

begin_define
define|#
directive|define
name|DDC_READ_RETRY
value|4
end_define

begin_define
define|#
directive|define
name|EXT_TAG
value|0x00
end_define

begin_define
define|#
directive|define
name|CEA_TAG_ID
value|0x02
end_define

begin_define
define|#
directive|define
name|CEA_DTD
value|0x03
end_define

begin_define
define|#
directive|define
name|DTD_BASIC_AUDIO
value|(1<< 6)
end_define

begin_struct
struct|struct
name|a10hdmi_softc
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|intr_config_hook
name|mode_hook
decl_stmt|;
name|uint8_t
name|edid
index|[
name|EDID_LENGTH
index|]
decl_stmt|;
name|int
name|has_audio
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|a10hdmi_spec
index|[]
init|=
block|{
block|{
name|SYS_RES_MEMORY
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HDMI_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((sc)->res, (reg))
end_define

begin_define
define|#
directive|define
name|HDMI_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((sc)->res, (reg), (val))
end_define

begin_function
specifier|static
name|void
name|a10hdmi_init
parameter_list|(
name|struct
name|a10hdmi_softc
modifier|*
name|sc
parameter_list|)
block|{
comment|/* Enable the HDMI module */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_CTRL
argument_list|,
name|CTRL_MODULE_EN
argument_list|)
expr_stmt|;
comment|/* Configure PLL/DRV settings */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PADCTRL0
argument_list|,
name|PADCTRL0_BIASEN
operator||
name|PADCTRL0_LDOCEN
operator||
name|PADCTRL0_LDODEN
operator||
name|PADCTRL0_PWENC
operator||
name|PADCTRL0_PWEND
operator||
name|PADCTRL0_PWENG
operator||
name|PADCTRL0_CKEN
operator||
name|PADCTRL0_TXEN
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PADCTRL1
argument_list|,
name|PADCTRL1_AMP_OPT
operator||
name|PADCTRL1_AMPCK_OPT
operator||
name|PADCTRL1_EMP_OPT
operator||
name|PADCTRL1_EMPCK_OPT
operator||
name|PADCTRL1_REG_DEN
operator||
name|PADCTRL1_REG_DENCK
operator||
name|PADCTRL1_REG_EMP_EN
operator||
name|PADCTRL1_REG_AMP_EN
argument_list|)
expr_stmt|;
comment|/* Select PLL3 as input clock */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PLLDBG0
argument_list|,
name|PLLDBG0_CKIN_SEL_PLL3
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|HDMI_ENABLE_DELAY
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|a10hdmi_hpd
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|a10hdmi_softc
modifier|*
name|sc
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|uint32_t
name|hpd
decl_stmt|;
name|dev
operator|=
name|arg
expr_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|hpd
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|HDMI_HPD
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|hpd
operator|&
name|HPD_DET
operator|)
operator|==
name|HPD_DET
condition|)
name|EVENTHANDLER_INVOKE
argument_list|(
name|hdmi_event
argument_list|,
name|dev
argument_list|,
name|HDMI_EVENT_CONNECTED
argument_list|)
expr_stmt|;
name|config_intrhook_disestablish
argument_list|(
operator|&
name|sc
operator|->
name|mode_hook
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_probe
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
literal|"allwinner,sun7i-a20-hdmi"
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
literal|"Allwinner HDMI TX"
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
name|a10hdmi_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|a10hdmi_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|a10hdmi_spec
argument_list|,
operator|&
name|sc
operator|->
name|res
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"cannot allocate resources for device\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|a10_clk_hdmi_activate
argument_list|()
expr_stmt|;
name|a10hdmi_init
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|mode_hook
operator|.
name|ich_func
operator|=
name|a10hdmi_hpd
expr_stmt|;
name|sc
operator|->
name|mode_hook
operator|.
name|ich_arg
operator|=
name|dev
expr_stmt|;
name|error
operator|=
name|config_intrhook_establish
argument_list|(
operator|&
name|sc
operator|->
name|mode_hook
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_ddc_xfer
parameter_list|(
name|struct
name|a10hdmi_softc
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|addr
parameter_list|,
name|uint8_t
name|seg
parameter_list|,
name|uint8_t
name|off
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
name|int
name|retry
decl_stmt|;
comment|/* Set FIFO direction to read */
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|)
expr_stmt|;
name|val
operator|&=
operator|~
name|CTRL_DDC_FIFO_DIR
expr_stmt|;
name|val
operator||=
name|CTRL_DDC_FIFO_DIR_READ
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Setup DDC slave address */
name|val
operator|=
operator|(
name|addr
operator|<<
name|SLAVE_ADDR_SHIFT
operator|)
operator||
operator|(
name|seg
operator|<<
name|SLAVE_ADDR_SEG_SHIFT
operator|)
operator||
operator|(
name|EDDC_ADDR
operator|<<
name|SLAVE_ADDR_EDDC_SHIFT
operator|)
operator||
operator|(
name|off
operator|<<
name|SLAVE_ADDR_OFFSET_SHIFT
operator|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_SLAVE_ADDR
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Clear FIFO */
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|DDC_FIFO_CTRL
argument_list|)
expr_stmt|;
name|val
operator||=
name|FIFO_CTRL_CLEAR
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_FIFO_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Set transfer length */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_BYTE_COUNTER
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* Set command to "Explicit Offset Address Read" */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_COMMAND
argument_list|,
name|COMMAND_EOREAD
argument_list|)
expr_stmt|;
comment|/* Start transfer */
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|)
expr_stmt|;
name|val
operator||=
name|CTRL_DDC_ACMD_START
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Wait for command to start */
name|retry
operator|=
name|DDC_RETRY
expr_stmt|;
while|while
condition|(
operator|--
name|retry
operator|>
literal|0
condition|)
block|{
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|CTRL_DDC_ACMD_START
operator|)
operator|==
literal|0
condition|)
break|break;
name|DELAY
argument_list|(
name|DDC_DELAY
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|retry
operator|==
literal|0
condition|)
return|return
operator|(
name|ETIMEDOUT
operator|)
return|;
comment|/* Ensure that the transfer completed */
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|DDC_INT_STATUS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|INT_STATUS_XFER_DONE
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|EIO
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_ddc_read
parameter_list|(
name|struct
name|a10hdmi_softc
modifier|*
name|sc
parameter_list|,
name|int
name|block
parameter_list|,
name|uint8_t
modifier|*
name|edid
parameter_list|)
block|{
name|int
name|resid
decl_stmt|,
name|off
decl_stmt|,
name|len
decl_stmt|,
name|error
decl_stmt|;
name|uint8_t
modifier|*
name|pbuf
decl_stmt|;
name|pbuf
operator|=
name|edid
expr_stmt|;
name|resid
operator|=
name|EDID_LENGTH
expr_stmt|;
name|off
operator|=
operator|(
name|block
operator|&
literal|1
operator|)
condition|?
name|EDID_LENGTH
else|:
literal|0
expr_stmt|;
while|while
condition|(
name|resid
operator|>
literal|0
condition|)
block|{
name|len
operator|=
name|min
argument_list|(
name|resid
argument_list|,
name|DDC_BLKLEN
argument_list|)
expr_stmt|;
name|error
operator|=
name|a10hdmi_ddc_xfer
argument_list|(
name|sc
argument_list|,
name|DDC_ADDR
argument_list|,
name|block
operator|>>
literal|1
argument_list|,
name|off
argument_list|,
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|bus_read_multi_1
argument_list|(
name|sc
operator|->
name|res
argument_list|,
name|DDC_FIFO
argument_list|,
name|pbuf
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|pbuf
operator|+=
name|len
expr_stmt|;
name|off
operator|+=
name|len
expr_stmt|;
name|resid
operator|-=
name|len
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_detect_audio
parameter_list|(
name|struct
name|a10hdmi_softc
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|edid_info
name|ei
decl_stmt|;
name|uint8_t
name|edid
index|[
name|EDID_LENGTH
index|]
decl_stmt|;
name|int
name|block
decl_stmt|;
if|if
condition|(
name|edid_parse
argument_list|(
name|sc
operator|->
name|edid
argument_list|,
operator|&
name|ei
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Scan through extension blocks, looking for a CEA-861 block. */
for|for
control|(
name|block
operator|=
literal|1
init|;
name|block
operator|<=
name|ei
operator|.
name|edid_ext_block_count
condition|;
name|block
operator|++
control|)
block|{
if|if
condition|(
name|a10hdmi_ddc_read
argument_list|(
name|sc
argument_list|,
name|block
argument_list|,
name|edid
argument_list|)
operator|!=
literal|0
condition|)
break|break;
if|if
condition|(
name|edid
index|[
name|EXT_TAG
index|]
operator|==
name|CEA_TAG_ID
condition|)
return|return
operator|(
operator|(
name|edid
index|[
name|CEA_DTD
index|]
operator|&
name|DTD_BASIC_AUDIO
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
comment|/* No CEA-861 block found */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_get_edid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|edid
parameter_list|,
name|uint32_t
modifier|*
name|edid_len
parameter_list|)
block|{
name|struct
name|a10hdmi_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|,
name|retry
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|retry
operator|=
name|DDC_READ_RETRY
expr_stmt|;
while|while
condition|(
operator|--
name|retry
operator|>
literal|0
condition|)
block|{
comment|/* I2C software reset */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_FIFO_CTRL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|,
name|CTRL_DDC_EN
operator||
name|CTRL_DDC_SWRST
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|SWRST_DELAY
argument_list|)
expr_stmt|;
if|if
condition|(
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|DDC_CTRL
argument_list|)
operator|&
name|CTRL_DDC_SWRST
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"DDC software reset failed\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Configure DDC clock */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|DDC_CLOCK
argument_list|,
name|DDC_CLOCK_M
operator||
name|DDC_CLOCK_N
argument_list|)
expr_stmt|;
comment|/* Read EDID block */
name|error
operator|=
name|a10hdmi_ddc_read
argument_list|(
name|sc
argument_list|,
literal|0
argument_list|,
name|sc
operator|->
name|edid
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
block|{
operator|*
name|edid
operator|=
name|sc
operator|->
name|edid
expr_stmt|;
operator|*
name|edid_len
operator|=
sizeof|sizeof
argument_list|(
name|sc
operator|->
name|edid
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|error
operator|==
literal|0
condition|)
name|sc
operator|->
name|has_audio
operator|=
name|a10hdmi_detect_audio
argument_list|(
name|sc
argument_list|)
expr_stmt|;
else|else
name|sc
operator|->
name|has_audio
operator|=
literal|0
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
name|void
name|a10hdmi_set_audiomode
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|videomode
modifier|*
name|mode
parameter_list|)
block|{
name|struct
name|a10hdmi_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|int
name|retry
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Disable and reset audio module and wait for reset bit to clear */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_CTRL
argument_list|,
name|AUD_CTRL_RST
argument_list|)
expr_stmt|;
for|for
control|(
name|retry
operator|=
name|HDMI_AUDIO_RESET_RETRY
init|;
name|retry
operator|>
literal|0
condition|;
name|retry
operator|--
control|)
block|{
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_CTRL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|AUD_CTRL_RST
operator|)
operator|==
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|retry
operator|==
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"timeout waiting for audio module\n"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|sc
operator|->
name|has_audio
condition|)
return|return;
comment|/* DMA and FIFO control */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_ADMA_CTRL
argument_list|,
name|HDMI_ADMA_MODE_DDMA
argument_list|)
expr_stmt|;
comment|/* Audio format control (LPCM, S16LE, stereo) */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_FMT
argument_list|,
name|AUD_FMT_CH
argument_list|(
name|HDMI_AUDIO_CHANNELS
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Channel mappings */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PCM_CTRL
argument_list|,
name|HDMI_AUDIO_CHANNELMAP
argument_list|)
expr_stmt|;
comment|/* Clocks */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_CTS
argument_list|,
name|HDMI_AUDIO_CTS
argument_list|(
name|mode
operator|->
name|dot_clock
argument_list|,
name|HDMI_AUDIO_N
argument_list|)
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_N
argument_list|,
name|HDMI_AUDIO_N
argument_list|)
expr_stmt|;
comment|/* Set sampling frequency to 48 kHz, word length to 16-bit */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_CH_STATUS0
argument_list|,
name|CH_STATUS0_FS_FREQ_48
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_CH_STATUS1
argument_list|,
name|CH_STATUS1_WORD_LEN_16
argument_list|)
expr_stmt|;
comment|/* Enable */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_AUD_CTRL
argument_list|,
name|AUD_CTRL_EN
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_set_videomode
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|videomode
modifier|*
name|mode
parameter_list|)
block|{
name|struct
name|a10hdmi_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|,
name|clk_div
decl_stmt|,
name|clk_dbl
decl_stmt|;
name|int
name|dblscan
decl_stmt|,
name|hfp
decl_stmt|,
name|hspw
decl_stmt|,
name|hbp
decl_stmt|,
name|vfp
decl_stmt|,
name|vspw
decl_stmt|,
name|vbp
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|dblscan
operator|=
operator|!
operator|!
operator|(
name|mode
operator|->
name|flags
operator|&
name|VID_DBLSCAN
operator|)
expr_stmt|;
name|hfp
operator|=
name|mode
operator|->
name|hsync_start
operator|-
name|mode
operator|->
name|hdisplay
expr_stmt|;
name|hspw
operator|=
name|mode
operator|->
name|hsync_end
operator|-
name|mode
operator|->
name|hsync_start
expr_stmt|;
name|hbp
operator|=
name|mode
operator|->
name|htotal
operator|-
name|mode
operator|->
name|hsync_start
expr_stmt|;
name|vfp
operator|=
name|mode
operator|->
name|vsync_start
operator|-
name|mode
operator|->
name|vdisplay
expr_stmt|;
name|vspw
operator|=
name|mode
operator|->
name|vsync_end
operator|-
name|mode
operator|->
name|vsync_start
expr_stmt|;
name|vbp
operator|=
name|mode
operator|->
name|vtotal
operator|-
name|mode
operator|->
name|vsync_start
expr_stmt|;
name|error
operator|=
name|a10_clk_tcon_get_config
argument_list|(
operator|&
name|clk_div
argument_list|,
operator|&
name|clk_dbl
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* Clear interrupt status */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_INT_STATUS
argument_list|,
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|HDMI_INT_STATUS
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Clock setup */
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|HDMI_PADCTRL1
argument_list|)
expr_stmt|;
name|val
operator|&=
operator|~
name|PADCTRL1_REG_CKSS
expr_stmt|;
name|val
operator||=
operator|(
name|clk_dbl
condition|?
name|PADCTRL1_REG_CKSS_2X
else|:
name|PADCTRL1_REG_CKSS_1X
operator|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PADCTRL1
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PLLCTRL0
argument_list|,
name|PLLCTRL0_PLL_EN
operator||
name|PLLCTRL0_BWS
operator||
name|PLLCTRL0_HV_IS_33
operator||
name|PLLCTRL0_LDO1_EN
operator||
name|PLLCTRL0_LDO2_EN
operator||
name|PLLCTRL0_SDIV2
operator||
name|PLLCTRL0_VCO_GAIN
operator||
name|PLLCTRL0_S
operator||
name|PLLCTRL0_CP_S
operator||
name|PLLCTRL0_CS
operator||
name|PLLCTRL0_PREDIV
argument_list|(
name|clk_div
argument_list|)
operator||
name|PLLCTRL0_VCO_S
argument_list|)
expr_stmt|;
comment|/* Setup display settings */
name|val
operator|=
name|VID_CTRL_HDMI_MODE
expr_stmt|;
if|if
condition|(
name|mode
operator|->
name|flags
operator|&
name|VID_INTERLACE
condition|)
name|val
operator||=
name|VID_CTRL_INTERLACE
expr_stmt|;
if|if
condition|(
name|mode
operator|->
name|flags
operator|&
name|VID_DBLSCAN
condition|)
name|val
operator||=
name|VID_CTRL_REPEATER_2X
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* Setup display timings */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_TIMING0
argument_list|,
name|VID_ACT_V
argument_list|(
name|mode
operator|->
name|vdisplay
argument_list|)
operator||
name|VID_ACT_H
argument_list|(
name|mode
operator|->
name|hdisplay
operator|<<
name|dblscan
argument_list|)
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_TIMING1
argument_list|,
name|VID_VBP
argument_list|(
name|vbp
argument_list|)
operator||
name|VID_HBP
argument_list|(
name|hbp
operator|<<
name|dblscan
argument_list|)
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_TIMING2
argument_list|,
name|VID_VFP
argument_list|(
name|vfp
argument_list|)
operator||
name|VID_HFP
argument_list|(
name|hfp
operator|<<
name|dblscan
argument_list|)
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_TIMING3
argument_list|,
name|VID_VSPW
argument_list|(
name|vspw
argument_list|)
operator||
name|VID_HSPW
argument_list|(
name|hspw
operator|<<
name|dblscan
argument_list|)
argument_list|)
expr_stmt|;
name|val
operator|=
name|TX_CLOCK_NORMAL
expr_stmt|;
if|if
condition|(
name|mode
operator|->
name|flags
operator|&
name|VID_PVSYNC
condition|)
name|val
operator||=
name|VID_VSYNC_ACTSEL
expr_stmt|;
if|if
condition|(
name|mode
operator|->
name|flags
operator|&
name|VID_PHSYNC
condition|)
name|val
operator||=
name|VID_HSYNC_ACTSEL
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_TIMING4
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* This is an ordered list of infoframe packets that the HDMI 	 * transmitter will send. Transmit packets in the following order: 	 *  1. General control packet 	 *  2. AVI infoframe 	 *  3. Audio infoframe 	 * There are 2 registers with 4 slots each. The list is terminated 	 * with the special PKT_END marker. 	 */
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PKTCTRL0
argument_list|,
name|PKTCTRL_PACKET
argument_list|(
literal|0
argument_list|,
name|PKT_GC
argument_list|)
operator||
name|PKTCTRL_PACKET
argument_list|(
literal|1
argument_list|,
name|PKT_AVI
argument_list|)
operator||
name|PKTCTRL_PACKET
argument_list|(
literal|2
argument_list|,
name|PKT_AI
argument_list|)
operator||
name|PKTCTRL_PACKET
argument_list|(
literal|3
argument_list|,
name|PKT_END
argument_list|)
argument_list|)
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_PKTCTRL1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Setup audio */
name|a10hdmi_set_audiomode
argument_list|(
name|dev
argument_list|,
name|mode
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|a10hdmi_enable
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|onoff
parameter_list|)
block|{
name|struct
name|a10hdmi_softc
modifier|*
name|sc
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Enable or disable video output */
name|val
operator|=
name|HDMI_READ
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_CTRL
argument_list|)
expr_stmt|;
if|if
condition|(
name|onoff
condition|)
name|val
operator||=
name|VID_CTRL_VIDEO_EN
expr_stmt|;
else|else
name|val
operator|&=
operator|~
name|VID_CTRL_VIDEO_EN
expr_stmt|;
name|HDMI_WRITE
argument_list|(
name|sc
argument_list|,
name|HDMI_VID_CTRL
argument_list|,
name|val
argument_list|)
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
name|a10hdmi_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|a10hdmi_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|a10hdmi_attach
argument_list|)
block|,
comment|/* HDMI interface */
name|DEVMETHOD
argument_list|(
name|hdmi_get_edid
argument_list|,
name|a10hdmi_get_edid
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|hdmi_set_videomode
argument_list|,
name|a10hdmi_set_videomode
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|hdmi_enable
argument_list|,
name|a10hdmi_enable
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|a10hdmi_driver
init|=
block|{
literal|"a10hdmi"
block|,
name|a10hdmi_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|a10hdmi_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|a10hdmi_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|a10hdmi
argument_list|,
name|simplebus
argument_list|,
name|a10hdmi_driver
argument_list|,
name|a10hdmi_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|a10hdmi
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

