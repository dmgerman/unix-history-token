begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDB_PCIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDB_PCIVAR_H_
end_define

begin_include
include|#
directive|include
file|"bhndbvar.h"
end_include

begin_comment
comment|/*  * bhndb(4) PCI driver subclass.  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhndb_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|bhndb_pci_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * An interconnect-specific function implementing BHNDB_SET_WINDOW_ADDR  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|bhndb_pci_set_regwin_t
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|pci_dev
parameter_list|,
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|rw
parameter_list|,
name|bhnd_addr_t
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* bhndb_pci interrupt state */
end_comment

begin_struct
struct|struct
name|bhndb_pci_intr
block|{
name|int
name|msi_count
decl_stmt|;
comment|/**< MSI count, or 0 */
name|int
name|intr_rid
decl_stmt|;
comment|/**< interrupt resource ID.*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bhndb_pci_softc
block|{
name|struct
name|bhndb_softc
name|bhndb
decl_stmt|;
comment|/**< parent softc */
name|device_t
name|dev
decl_stmt|;
comment|/**< bridge device */
name|device_t
name|parent
decl_stmt|;
comment|/**< parent PCI device */
name|bhnd_devclass_t
name|pci_devclass
decl_stmt|;
comment|/**< PCI core's devclass */
name|struct
name|bhndb_pci_intr
name|intr
decl_stmt|;
comment|/**< PCI interrupt config */
name|bhndb_pci_set_regwin_t
name|set_regwin
decl_stmt|;
comment|/**< regwin handler */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDB_PCIVAR_H_ */
end_comment

end_unit

