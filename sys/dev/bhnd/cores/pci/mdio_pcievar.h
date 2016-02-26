begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCI_MDIO_PCIEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCI_MDIO_PCIEVAR_H_
end_define

begin_include
include|#
directive|include
file|<dev/mdio/mdio.h>
end_include

begin_include
include|#
directive|include
file|"mdio_if.h"
end_include

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_mdio_pcie_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|bhnd_mdio_pcie_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|mem_res
parameter_list|,
name|int
name|mem_rid
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|bool
name|c22ext
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bhnd_mdio_pcie_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< mdio device */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/**< mdio register lock */
name|struct
name|bhnd_resource
modifier|*
name|mem_res
decl_stmt|;
comment|/**< parent pcie registers */
name|int
name|mem_rid
decl_stmt|;
comment|/**< MDIO register resID, or 						     -1 if mem_res reference is 						     borrowed. */
name|bus_size_t
name|mem_off
decl_stmt|;
comment|/**< mdio register offset */
name|bool
name|c22ext
decl_stmt|;
comment|/**< automatically rewrite C45 						     register requests made 						     to the PCIe SerDes slave 						     to use its non-standard 						     C22 address extension 						     mechanism. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_MDIO_PCIE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->sc_mtx, device_get_nameunit((sc)->dev), \ 	    "bhnd_pci_mdio register lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHND_MDIO_PCIE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BHND_MDIO_PCIE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BHND_MDIO_PCIE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, what)
end_define

begin_define
define|#
directive|define
name|BHND_MDIO_PCIE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->sc_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCI_MDIO_PCIEVAR_H_ */
end_comment

end_unit

