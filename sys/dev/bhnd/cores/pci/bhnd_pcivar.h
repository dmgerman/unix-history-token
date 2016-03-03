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

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_mdio_pci_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device register families. */
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
comment|/* Common BHND_PCI_*_REG_(EXTRACT|INSERT) implementation */
end_comment

begin_define
define|#
directive|define
name|_BHND_PCI_REG_EXTRACT
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
name|_BHND_PCI_REG_INSERT
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
name|BHND_PCI_REG_EXTRACT
parameter_list|(
name|_regv
parameter_list|,
name|_attr
parameter_list|)
define|\
value|_BHND_PCI_REG_EXTRACT(_regv, _attr ## _MASK, _attr ## _SHIFT)
end_define

begin_comment
comment|/**  * Insert a value in @p _regv by applying _MASK and _SHIFT defines.  *   * @param _regv The current register value.  * @param _attr The register attribute name to which to append `_MASK`/`_SHIFT`  * suffixes.  * @param _val The value to be set in @p _regv.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_REG_INSERT
parameter_list|(
name|_regv
parameter_list|,
name|_attr
parameter_list|,
name|_val
parameter_list|)
define|\
value|_BHND_PCI_REG_INSERT(_regv, _attr ## _MASK, _attr ## _SHIFT, _val)
end_define

begin_comment
comment|/**  * Extract a value by applying _MASK and _SHIFT defines to the common  * PCI/PCIe register definition @p _regv  *   * @param _regf The PCI core register format (BHNDB_PCI_REGFMT_*).  * @param _regv The register value containing the desired attribute  * @param _attr The register attribute name to which to prepend the register  * definition prefix and append `_MASK`/`_SHIFT` suffixes.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_COMMON_REG_EXTRACT
parameter_list|(
name|_regf
parameter_list|,
name|_regv
parameter_list|,
name|_attr
parameter_list|)
define|\
value|_BHND_PCI_REG_EXTRACT(_regv,				\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _MASK),	\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _SHIFT))
end_define

begin_comment
comment|/**  * Insert a register value by applying _MASK and _SHIFT defines to the common  * PCI/PCIe register definition @p _regv  *   * @param _regf The PCI core register format (BHNDB_PCI_REGFMT_*).  * @param _regv The register value containing the desired attribute  * @param _attr The register attribute name to which to prepend the register  * definition prefix and append `_MASK`/`_SHIFT` suffixes.  * @param _val The value to bet set in @p _regv.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_COMMON_REG_INSERT
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
value|_BHND_PCI_REG_INSERT(_regv,				\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _MASK),	\ 	    BHND_PCI_COMMON_REG((_regf), _attr ## _SHIFT),	\ 	    _val)
end_define

begin_comment
comment|/**  * Evaluates to the offset of a common PCI/PCIe register definition.   *   * This will trigger a compile-time error if the register is not defined  * for all supported PCI/PCIe cores.  *   * This should be optimized down to a constant value if the register constant  * is the same across the register definitions.  *   * @param _regf The PCI core register format (BHNDB_PCI_REGFMT_*).  * @param _name The base name of the register.  */
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
value|(			\ 	(_regf) == BHND_PCI_REGFMT_PCI ? BHND_PCI_ ## _name :	\ 	BHND_PCIE_ ## _name						\ )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCI_BHND_PCIVAR_H_ */
end_comment

end_unit

