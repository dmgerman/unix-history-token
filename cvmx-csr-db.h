begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_CSR_DB_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_CSR_DB_H__
end_define

begin_comment
comment|/**  * @file  * Interface for the Octeon CSR database.  *  *  *<hr>$Revision: 49507 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|"cvmx-platform.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
enum|enum
block|{
name|CVMX_CSR_DB_TYPE_RSL
block|,
comment|/**< Octeon internal address, but indirect and slow (not used for addresses) */
name|CVMX_CSR_DB_TYPE_NCB
block|,
comment|/**< Octeon internal address */
name|CVMX_CSR_DB_TYPE_PCI_NCB
block|,
comment|/**< Can be accessed through PCI BAR0, also an NCB alias (not used for addresses) */
name|CVMX_CSR_DB_TYPE_PCICONFIG
block|,
comment|/**< PCI Config, also an NCB alias */
name|CVMX_CSR_DB_TYPE_PCI
block|,
comment|/**< PCI BAR0 (only) */
name|CVMX_CSR_DB_TYPE_PEXP
block|,
comment|/**< PCIe BAR 0 address only */
name|CVMX_CSR_DB_TYPE_PEXP_NCB
block|,
comment|/**< NCB-direct and PCIe BAR0 address */
name|CVMX_CSR_DB_TYPE_PCICONFIGEP
block|,
comment|/**< PCIe config address (EP mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
name|CVMX_CSR_DB_TYPE_PCICONFIGRC
block|,
comment|/**< PCICONFIGRC - PCIe config address (RC mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
name|CVMX_CSR_DB_TYPE_SRIOMAINT
comment|/**< SRIOMAINT - SRIO maintenance registers */
block|}
name|CVMX_CSR_DB_TYPE_FIELD
typedef|;
comment|/**  * the structure for the cvmx_csr_db_addresses[] array that  * holds all possible Octeon CSR addresses  */
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< CSR name at the supplied address */
name|uint64_t
name|address
decl_stmt|;
comment|/**< Address = octeon internal, PCI BAR0 relative, PCI CONFIG relative */
name|CVMX_CSR_DB_TYPE_FIELD
name|type
range|:
literal|8
decl_stmt|;
comment|/**< the type */
name|uint8_t
name|widthbits
decl_stmt|;
comment|/**< the width of the CSR in bits */
name|uint16_t
name|csroff
decl_stmt|;
comment|/**< position of the CSR in cvmx_csr_db[] */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|CVMX_CSR_DB_ADDRESS_TYPE
typedef|;
comment|/**  * the structure for the cvmx_csr_db_fields[] array that  * holds all possible Octeon CSR fields  */
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< name of the field */
name|uint8_t
name|startbit
decl_stmt|;
comment|/**< starting bit position of the field */
name|uint8_t
name|sizebits
decl_stmt|;
comment|/**< the size of the field in bits */
name|uint16_t
name|csroff
decl_stmt|;
comment|/**< position of the CSR containing the field in cvmx_csr_db[] (get alias from there) */
name|char
modifier|*
name|type
decl_stmt|;
comment|/**< the type of the field R/W, R/W1C, ... */
name|uint8_t
name|rst_unp
decl_stmt|;
comment|/**< set if the reset value is unknown */
name|uint8_t
name|typ_unp
decl_stmt|;
comment|/**< set if the typical value is unknown */
name|uint64_t
name|rst_val
decl_stmt|;
comment|/**< the reset value of the field */
name|uint64_t
name|typ_val
decl_stmt|;
comment|/**< the typical value of the field */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|CVMX_CSR_DB_FIELD_TYPE
typedef|;
comment|/**  * the structure for the cvmx_csr_db[] array that holds all  * possible Octeon CSR forms  */
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|basename
decl_stmt|;
comment|/**< the base name of the CSR */
name|CVMX_CSR_DB_TYPE_FIELD
name|type
range|:
literal|8
decl_stmt|;
comment|/**< the type */
name|uint8_t
name|widthbits
decl_stmt|;
comment|/**< the width of the CSR in bits */
name|uint16_t
name|addoff
decl_stmt|;
comment|/**< the position of the first address in cvmx_csr_db_csr_addresses[] (numblocks*indexnum is #) */
name|uint8_t
name|numfields
decl_stmt|;
comment|/**< the number of fields in the CSR (and in cvmx_csr_db_csr_fields[]) */
name|uint16_t
name|fieldoff
decl_stmt|;
comment|/**< the position of the first field in cvmx_csr_db_csr_fields[] */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|CVMX_CSR_DB_TYPE
typedef|;
comment|/**  * This NULL terminated array contains the CVMX_CSR_DB_TYPE  * arrays for each chip. Each array entry is another NULL  * terminated array of CSRs.  */
specifier|extern
specifier|const
name|CVMX_CSR_DB_TYPE
modifier|*
name|cvmx_csr_db
index|[]
decl_stmt|;
comment|/**  * This NULL terminated array contains the CVMX_CSR_DB_ADDRESS_TYPE  * arrays for each chip. Each array entry is another NULL  * terminated array of CSR addresses.  */
specifier|extern
specifier|const
name|CVMX_CSR_DB_ADDRESS_TYPE
modifier|*
name|cvmx_csr_db_addresses
index|[]
decl_stmt|;
comment|/**  * This NULL terminated array contains the CVMX_CSR_DB_FIELD_TYPE  * arrays for each chip. Each array entry is another NULL  * terminated array of CSR fields.  */
specifier|extern
specifier|const
name|CVMX_CSR_DB_FIELD_TYPE
modifier|*
name|cvmx_csr_db_fields
index|[]
decl_stmt|;
comment|/**  * Figure out which database to use for this chip. The passed  * identifier can be a processor ID or a PCI ID.  *  * @param identifier processor ID or a PCI ID  *  * @return index into the csr db  */
specifier|extern
name|int
name|cvmx_db_get_chipindex
parameter_list|(
name|int
name|identifier
parameter_list|)
function_decl|;
comment|/**  * Get the CSR DB entry for the passed Octeon model and CSR name. The  * model can either be specified as a processor id or PCI id.  *  * @param identifier Identifer to choose the CSR DB with  * @param name       CSR name to lookup  *  * @return CSR DB entry or NULL on failure  */
specifier|extern
specifier|const
name|CVMX_CSR_DB_ADDRESS_TYPE
modifier|*
name|cvmx_csr_db_get
parameter_list|(
name|int
name|identifier
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * Decode a CSR value into named bitfields. The model can either  * be specified as a processor id or PCI id.  *  * @param identifier Identifer to choose the CSR DB with  * @param address    CSR address being decoded  * @param value      Value to decode  */
specifier|extern
name|void
name|cvmx_csr_db_decode
parameter_list|(
name|int
name|identifier
parameter_list|,
name|uint64_t
name|address
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
comment|/**  * Decode a CSR value into named bitfields. The model can either  * be specified as a processor id or PCI id.  *  * @param identifier Identifer to choose the CSR DB with  * @param name       CSR name to decode  * @param value      Value to decode  */
specifier|extern
name|void
name|cvmx_csr_db_decode_by_name
parameter_list|(
name|int
name|identifier
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
comment|/**  * Print a list of csrs begimning with a prefix. The  * model can either be specified as a processor id or PCI id.  *  * @param identifier Identifer to choose the CSR DB with  * @param prefix     Beginning prefix to look for  */
specifier|extern
name|void
name|cvmx_csr_db_display_list
parameter_list|(
name|int
name|identifier
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

