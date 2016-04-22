begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCI_BHND_PCIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCI_BHND_PCIVAR_H_
end_define

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

begin_comment
comment|/*  * Shared PCI Bridge/PCI Host Bridge definitions.  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|bhnd_pci_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|bhnd_pci_generic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pci_generic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pci_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pci_generic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pci_generic_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pcie_read_proto_reg
parameter_list|(
name|struct
name|bhnd_pci_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pcie_write_proto_reg
parameter_list|(
name|struct
name|bhnd_pci_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie_mdio_read
parameter_list|(
name|struct
name|bhnd_pci_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie_mdio_write
parameter_list|(
name|struct
name|bhnd_pci_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie_mdio_read_ext
parameter_list|(
name|struct
name|bhnd_pci_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|devaddr
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie_mdio_write_ext
parameter_list|(
name|struct
name|bhnd_pci_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|devaddr
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** PCI register block layouts. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_PCI_REGFMT_PCI
init|=
literal|0
block|,
comment|/* PCI register definitions */
name|BHND_PCI_REGFMT_PCIE
init|=
literal|1
block|,
comment|/* PCIe-Gen1 register definitions */
block|}
name|bhnd_pci_regfmt_t
typedef|;
end_typedef

begin_comment
comment|/** PCI (base driver) quirks */
end_comment

begin_enum
enum|enum
block|{
comment|/** 	 * The PCIe SerDes requires use of a non-standard Clause 22 	 * address extension mechanism to access extended MDIO registers. 	 */
name|BHND_PCI_QUIRK_SD_C22_EXTADDR
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
comment|/**  * bhnd_pci child device info  */
end_comment

begin_struct
struct|struct
name|bhnd_pci_devinfo
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Generic PCI bridge/end-point driver state.  *   * Must be first member of all subclass softc structures.  */
end_comment

begin_struct
struct|struct
name|bhnd_pci_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< pci device */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< quirk flags */
name|bhnd_pci_regfmt_t
name|regfmt
decl_stmt|;
comment|/**< register format */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/**< state mutex used to protect 						     interdependent register 						     accesses. */
name|struct
name|bhnd_resource
modifier|*
name|mem_res
decl_stmt|;
comment|/**< device register block. */
name|int
name|mem_rid
decl_stmt|;
comment|/**< register block RID */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_PCI_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), \ 	    "BHND PCI driver lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHND_PCI_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_PCI_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_PCI_LOCK_ASSERT
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
name|BHND_PCI_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_comment
comment|/* BHND_PCI_*_REG_(GET|SET) implementation */
end_comment

begin_define
define|#
directive|define
name|_BHND_PCI_REG_GET
parameter_list|(
name|_regval
parameter_list|,
name|_mask
parameter_list|,
name|_shift
parameter_list|)
define|\
value|((_regval& _mask)>> _shift)
end_define

begin_define
define|#
directive|define
name|_BHND_PCI_REG_SET
parameter_list|(
name|_regval
parameter_list|,
name|_mask
parameter_list|,
name|_shift
parameter_list|,
name|_setval
parameter_list|)
define|\
value|(((_regval)& ~ _mask) | (((_setval)<< _shift)& _mask))
end_define

begin_comment
comment|/**  * Extract a register value by applying _MASK and _SHIFT defines.  *   * @param _regv The register value containing the desired attribute  * @param _attr The register attribute name to which to append `_MASK`/`_SHIFT`  * suffixes.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_REG_GET
parameter_list|(
name|_regv
parameter_list|,
name|_attr
parameter_list|)
define|\
value|_BHND_PCI_REG_GET(_regv, _attr ## _MASK, _attr ## _SHIFT)
end_define

begin_comment
comment|/**  * Insert a value in @p _regv by applying _MASK and _SHIFT defines.  *   * @param _regv The current register value.  * @param _attr The register attribute name to which to append `_MASK`/`_SHIFT`  * suffixes.  * @param _val The value to be set in @p _regv.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_REG_SET
parameter_list|(
name|_regv
parameter_list|,
name|_attr
parameter_list|,
name|_val
parameter_list|)
define|\
value|_BHND_PCI_REG_SET(_regv, _attr ## _MASK, _attr ## _SHIFT, _val)
end_define

begin_comment
comment|/**  * Extract a value by applying _MASK and _SHIFT defines to the common  * PCI/PCIe register definition @p _regv  *   * @param _regf The PCI core register format (BHND_PCI_REGFMT_*).  * @param _regv The register value containing the desired attribute  * @param _attr The register attribute name to which to prepend the register  * definition prefix and append `_MASK`/`_SHIFT` suffixes.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CMN_REG_GET
parameter_list|(
name|_regf
parameter_list|,
name|_regv
parameter_list|,
name|_attr
parameter_list|)
define|\
value|_BHND_PCI_REG_GET(_regv,				\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _MASK),	\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _SHIFT))
end_define

begin_comment
comment|/**  * Insert a register value by applying _MASK and _SHIFT defines to the common  * PCI/PCIe register definition @p _regv  *   * @param _regf The PCI core register format (BHND_PCI_REGFMT_*).  * @param _regv The register value containing the desired attribute  * @param _attr The register attribute name to which to prepend the register  * definition prefix and append `_MASK`/`_SHIFT` suffixes.  * @param _val The value to bet set in @p _regv.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CMN_REG_SET
parameter_list|(
name|_regf
parameter_list|,
name|_regv
parameter_list|,
name|_attr
parameter_list|,
name|_val
parameter_list|)
define|\
value|_BHND_PCI_REG_SET(_regv,				\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _MASK),	\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _SHIFT),	\ 	    _val)
end_define

begin_comment
comment|/**  * Evaluates to the offset of a common PCI/PCIe register definition.   *   * This will trigger a compile-time error if the register is not defined  * for all supported PCI/PCIe cores.  *   * This should be optimized down to a constant value if the register constant  * is the same across the register definitions.  *   * @param _regf The PCI core register format (BHND_PCI_REGFMT_*).  * @param _name The base name of the register.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_COMMON_REG
parameter_list|(
name|_regf
parameter_list|,
name|_name
parameter_list|)
value|(			\ 	(_regf) == BHND_PCI_REGFMT_PCI ? BHND_PCI_ ## _name :		\ 	BHND_PCIE_ ## _name						\ )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCI_BHND_PCIVAR_H_ */
end_comment

end_unit

