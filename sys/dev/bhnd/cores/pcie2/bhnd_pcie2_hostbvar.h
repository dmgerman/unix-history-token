begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCIE2_BHND_PCI_HOSTBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCIE2_BHND_PCI_HOSTBVAR_H_
end_define

begin_comment
comment|/*  * PCIe-Gen2 Host Bridge definitions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pcie2_var.h"
end_include

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_pcie2_hostb_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * PCIe-Gen2 endpoint-mode device quirks  */
end_comment

begin_enum
enum|enum
block|{
comment|/** 	 * The PCIe SerDes output should be configured with an amplitude of 	 * 1214mVpp and a differential output de-emphasis of -8.46dB. 	 * 	 * The exact issue this workaround resolves is unknown. 	 */
name|BHND_PCIE2_QUIRK_SERDES_TXDRV_DEEMPH
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * bhnd_pci_hostb driver instance state.  */
end_comment

begin_struct
struct|struct
name|bhnd_pcie2hb_softc
block|{
name|struct
name|bhnd_pcie2_softc
name|common
decl_stmt|;
comment|/**< common bhnd_pcie2 state */
name|device_t
name|dev
decl_stmt|;
name|device_t
name|pci_dev
decl_stmt|;
comment|/**< host PCI device */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< hostb device quirks */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCIE2_BHND_PCI_HOSTBVAR_H_ */
end_comment

end_unit

