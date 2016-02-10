begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  BSD LICENSE  *  *  Copyright(c) 2015 Broadcom Corporation.  All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *	* Redistributions of source code must retain the above copyright  *	  notice, this list of conditions and the following disclaimer.  *	* Redistributions in binary form must reproduce the above copyright  *	  notice, this list of conditions and the following disclaimer in  *	  the documentation and/or other materials provided with the  *	  distribution.  *	* Neither the name of Broadcom Corporation nor the names of its  *	  contributors may be used to endorse or promote products derived  *	  from this software without specific prior written permission.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCK_BCM_NSP_H
end_ifndef

begin_define
define|#
directive|define
name|_CLOCK_BCM_NSP_H
end_define

begin_comment
comment|/* GENPLL clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL_PHY_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL_ENET_SW_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL_USB_PHY_REF_CLK
value|3
end_define

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL_IPROCFAST_CLK
value|4
end_define

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL_SATA1_CLK
value|5
end_define

begin_define
define|#
directive|define
name|BCM_NSP_GENPLL_SATA2_CLK
value|6
end_define

begin_comment
comment|/* LCPLL0 clock channel ID */
end_comment

begin_define
define|#
directive|define
name|BCM_NSP_LCPLL0
value|0
end_define

begin_define
define|#
directive|define
name|BCM_NSP_LCPLL0_PCIE_PHY_REF_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BCM_NSP_LCPLL0_SDIO_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BCM_NSP_LCPLL0_DDR_PHY_CLK
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CLOCK_BCM_NSP_H */
end_comment

end_unit

