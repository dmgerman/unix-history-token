begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  BSD LICENSE  *  *  Copyright(c) 2015 Broadcom Corporation.  All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *    * Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    * Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in  *      the documentation and/or other materials provided with the  *      distribution.  *    * Neither the name of Broadcom Corporation nor the names of its  *      contributors may be used to endorse or promote products derived  *      from this software without specific prior written permission.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCK_BCM_NS2_H
end_ifndef

begin_define
define|#
directive|define
name|_CLOCK_BCM_NS2_H
end_define

begin_comment
comment|/* GENPLL SCR clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR_SCR_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR_FS_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR_AUDIO_CLK
value|3
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR_CH3_UNUSED
value|4
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR_CH4_UNUSED
value|5
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SCR_CH5_UNUSED
value|6
end_define

begin_comment
comment|/* GENPLL SW clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW_RPE_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW_250_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW_NIC_CLK
value|3
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW_CHIMP_CLK
value|4
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW_PORT_CLK
value|5
end_define

begin_define
define|#
directive|define
name|BCM_NS2_GENPLL_SW_SDIO_CLK
value|6
end_define

begin_comment
comment|/* LCPLL DDR clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR_PCIE_SATA_USB_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR_DDR_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR_CH2_UNUSED
value|3
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR_CH3_UNUSED
value|4
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR_CH4_UNUSED
value|5
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_DDR_CH5_UNUSED
value|6
end_define

begin_comment
comment|/* LCPLL PORTS clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS_WAN_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS_RGMII_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS_CH2_UNUSED
value|3
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS_CH3_UNUSED
value|4
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS_CH4_UNUSED
value|5
end_define

begin_define
define|#
directive|define
name|BCM_NS2_LCPLL_PORTS_CH5_UNUSED
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CLOCK_BCM_NS2_H */
end_comment

end_unit

