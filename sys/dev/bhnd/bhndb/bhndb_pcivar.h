begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
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
comment|/**  * PCI/PCIe bridge-level device quirks  */
end_comment

begin_enum
enum|enum
block|{
comment|/** No quirks */
name|BHNDB_PCI_QUIRK_NONE
init|=
literal|0
block|,
comment|/** 	 * The core requires fixup of the BAR0 SROM shadow to point at the 	 * current PCI core. 	 */
name|BHNDB_PCI_QUIRK_SRSH_WAR
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/** 	 * The PCI (rev<= 5) core does not provide interrupt status/mask 	 * registers; these siba-only devices require routing backplane 	 * interrupt flags via the SIBA_CFG0_INTVEC register. 	 */
name|BHNDB_PCI_QUIRK_SIBA_INTVEC
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/** bhndb_pci quirk table entry */
end_comment

begin_struct
struct|struct
name|bhndb_pci_quirk
block|{
name|struct
name|bhnd_chip_match
name|chip_desc
decl_stmt|;
comment|/**< chip match descriptor */
name|struct
name|bhnd_core_match
name|core_desc
decl_stmt|;
comment|/**< core match descriptor */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< quirk flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHNDB_PCI_QUIRK
parameter_list|(
name|_rev
parameter_list|,
name|_flags
parameter_list|)
value|{			\ 	{ BHND_MATCH_ANY },						\ 	{ BHND_MATCH_CORE_REV(_rev) },					\ 	_flags,								\ }
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_QUIRK_END
define|\
value|{ { BHND_MATCH_ANY },  { BHND_MATCH_ANY }, 0 }
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_IS_QUIRK_END
parameter_list|(
name|_q
parameter_list|)
define|\
value|(BHND_MATCH_IS_ANY(&(_q)->core_desc)&&	\ 	 BHND_MATCH_IS_ANY(&(_q)->chip_desc)&&	\ 	 (_q)->quirks == 0)
end_define

begin_comment
comment|/** bhndb_pci core table entry */
end_comment

begin_struct
struct|struct
name|bhndb_pci_core
block|{
name|struct
name|bhnd_core_match
name|match
decl_stmt|;
comment|/**< core match descriptor */
name|bus_size_t
name|srsh_offset
decl_stmt|;
comment|/**< offset to SRSH_PI register, if any */
name|struct
name|bhndb_pci_quirk
modifier|*
name|quirks
decl_stmt|;
comment|/**< quirk table */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHNDB_PCI_CORE
parameter_list|(
name|_device
parameter_list|,
name|_srsh
parameter_list|,
name|_quirks
parameter_list|)
value|{			\ 	{ BHND_MATCH_CORE(BHND_MFGID_BCM, BHND_COREID_ ## _device) },	\ 	_srsh,								\ 	_quirks								\ }
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_CORE_END
value|{ { BHND_MATCH_ANY }, 0, NULL }
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_IS_CORE_END
parameter_list|(
name|_c
parameter_list|)
value|BHND_MATCH_IS_ANY(&(_c)->match)
end_define

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
name|uint32_t
name|pci_quirks
decl_stmt|;
comment|/**< PCI bridge-level quirks */
name|int
name|msi_count
decl_stmt|;
comment|/**< MSI count, or 0 */
name|struct
name|bhndb_intr_isrc
modifier|*
name|isrc
decl_stmt|;
comment|/**< host interrupt source */
name|struct
name|mtx
name|mtx
decl_stmt|;
name|bhndb_pci_set_regwin_t
name|set_regwin
decl_stmt|;
comment|/**< regwin handler */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHNDB_PCI_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), \ 	    "bhndb_pc state", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDB_PCIVAR_H_ */
end_comment

end_unit

