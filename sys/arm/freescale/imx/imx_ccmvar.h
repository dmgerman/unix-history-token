begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX_CCMVAR_H
end_ifndef

begin_define
define|#
directive|define
name|IMX_CCMVAR_H
end_define

begin_comment
comment|/*  * We need a clock management system that works across unrelated SoCs and  * devices.  For now, to keep imx development moving, define some barebones  * functionality that can be shared within the imx family by having each SoC  * implement functions with a common name.  *  * The usb enable functions are best-effort.  They turn on the usb otg, host,  * and phy clocks in a SoC-specific manner, but it may take a lot more than that  * to make usb work on a given board.  In particular, it can require specific  * pinmux setup of gpio pins connected to external phy parts, voltage regulators  * and overcurrent detectors, and so on.  On such boards, u-boot or other early  * board setup code has to handle those things.  */
end_comment

begin_function_decl
name|uint32_t
name|imx_ccm_ipg_hz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|imx_ccm_perclk_hz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|imx_ccm_sdhci_hz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|imx_ccm_uart_hz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|imx_ccm_ahb_hz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_ccm_usb_enable
parameter_list|(
name|device_t
name|_usbdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_ccm_usbphy_enable
parameter_list|(
name|device_t
name|_phydev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_ccm_ssi_configure
parameter_list|(
name|device_t
name|_ssidev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_ccm_hdmi_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_ccm_ipu_enable
parameter_list|(
name|int
name|ipu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|imx6_ccm_sata_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines to get and set the arm clock root divisor register. */
end_comment

begin_function_decl
name|uint32_t
name|imx_ccm_get_cacrr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx_ccm_set_cacrr
parameter_list|(
name|uint32_t
name|_divisor
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

