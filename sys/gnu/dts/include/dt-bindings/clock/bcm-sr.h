begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  BSD LICENSE  *  *  Copyright(c) 2017 Broadcom. All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *    * Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    * Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in  *      the documentation and/or other materials provided with the  *      distribution.  *    * Neither the name of Broadcom Corporation nor the names of its  *      contributors may be used to endorse or promote products derived  *      from this software without specific prior written permission.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCK_BCM_SR_H
end_ifndef

begin_define
define|#
directive|define
name|_CLOCK_BCM_SR_H
end_define

begin_comment
comment|/* GENPLL 0 clock channel ID SCR HSLS FS PCIE */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0_SATA_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0_SCR_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0_250M_CLK
value|3
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0_PCIE_AXI_CLK
value|4
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0_PAXC_AXI_X2_CLK
value|5
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL0_PAXC_AXI_CLK
value|6
end_define

begin_comment
comment|/* GENPLL 1 clock channel ID MHB PCIE NITRO */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL1
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL1_PCIE_TL_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL1_MHB_APB_CLK
value|2
end_define

begin_comment
comment|/* GENPLL 2 clock channel ID NITRO MHB*/
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL2
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL2_NIC_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL2_250_NITRO_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL2_125_NITRO_CLK
value|3
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL2_CHIMP_CLK
value|4
end_define

begin_comment
comment|/* GENPLL 3 HSLS clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL3
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL3_HSLS_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL3_SDIO_CLK
value|2
end_define

begin_comment
comment|/* GENPLL 4 SCR clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL4
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL4_CCN_CLK
value|1
end_define

begin_comment
comment|/* GENPLL 5 FS4 clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL5
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL5_FS_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL5_SPU_CLK
value|2
end_define

begin_comment
comment|/* GENPLL 6 NITRO clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_GENPLL6
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_GENPLL6_48_USB_CLK
value|1
end_define

begin_comment
comment|/* LCPLL0  clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_LCPLL0
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_LCPLL0_SATA_REF_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_SR_LCPLL0_USB_REF_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_SR_LCPLL0_SATA_REFPN_CLK
value|3
end_define

begin_comment
comment|/* LCPLL1  clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_LCPLL1
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_LCPLL1_WAN_CLK
value|1
end_define

begin_comment
comment|/* LCPLL PCIE  clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_LCPLL_PCIE
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_LCPLL_PCIE_PHY_REF_CLK
value|1
end_define

begin_comment
comment|/* GENPLL EMEM0 clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_EMEMPLL0
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_EMEMPLL0_EMEM_CLK
value|1
end_define

begin_comment
comment|/* GENPLL EMEM0 clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_EMEMPLL1
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_EMEMPLL1_EMEM_CLK
value|1
end_define

begin_comment
comment|/* GENPLL EMEM0 clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_SR_EMEMPLL2
value|0
end_define

begin_define
define|#
directive|define
name|BCM_SR_EMEMPLL2_EMEM_CLK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CLOCK_BCM_SR_H */
end_comment

end_unit

