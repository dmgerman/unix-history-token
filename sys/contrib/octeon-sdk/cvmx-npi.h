begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * PCI / PCIe packet engine related structures.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_NPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_NPI_H__
end_define

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
comment|/**  * PCI / PCIe packet instruction header format  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|r
range|:
literal|1
decl_stmt|;
comment|/**< Packet is RAW */
name|uint64_t
name|g
range|:
literal|1
decl_stmt|;
comment|/**< Gather list is used */
name|uint64_t
name|dlengsz
range|:
literal|14
decl_stmt|;
comment|/**< Data length / Gather list size */
name|uint64_t
name|fsz
range|:
literal|6
decl_stmt|;
comment|/**< Front data size */
name|uint64_t
name|qos
range|:
literal|3
decl_stmt|;
comment|/**< POW QoS queue */
name|uint64_t
name|grp
range|:
literal|4
decl_stmt|;
comment|/**< POW Group */
name|uint64_t
name|rs
range|:
literal|1
decl_stmt|;
comment|/**< Real short */
name|cvmx_pow_tag_type_t
name|tt
range|:
literal|2
decl_stmt|;
comment|/**< POW Tag type */
name|uint64_t
name|tag
range|:
literal|32
decl_stmt|;
comment|/**< POW 32 bit tag */
else|#
directive|else
name|uint64_t
name|tag
range|:
literal|32
decl_stmt|;
name|cvmx_pow_tag_type_t
name|tt
range|:
literal|2
decl_stmt|;
name|uint64_t
name|rs
range|:
literal|1
decl_stmt|;
name|uint64_t
name|grp
range|:
literal|4
decl_stmt|;
name|uint64_t
name|qos
range|:
literal|3
decl_stmt|;
name|uint64_t
name|fsz
range|:
literal|6
decl_stmt|;
name|uint64_t
name|dlengsz
range|:
literal|14
decl_stmt|;
name|uint64_t
name|g
range|:
literal|1
decl_stmt|;
name|uint64_t
name|r
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
block|}
name|cvmx_npi_inst_hdr_t
typedef|;
comment|/**  * PCI / PCIe packet data pointer formats 0-3  */
typedef|typedef
union|union
block|{
name|uint64_t
name|dptr0
decl_stmt|;
struct|struct
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|es
range|:
literal|2
decl_stmt|;
comment|/**< Endian swap mode */
name|uint64_t
name|ns
range|:
literal|1
decl_stmt|;
comment|/**< No snoop */
name|uint64_t
name|ro
range|:
literal|1
decl_stmt|;
comment|/**< Relaxed ordering */
name|uint64_t
name|addr
range|:
literal|60
decl_stmt|;
comment|/**< PCI/PCIe address */
else|#
directive|else
name|uint64_t
name|addr
range|:
literal|60
decl_stmt|;
name|uint64_t
name|ro
range|:
literal|1
decl_stmt|;
name|uint64_t
name|ns
range|:
literal|1
decl_stmt|;
name|uint64_t
name|es
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
name|dptr1
struct|;
struct|struct
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|pm
range|:
literal|2
decl_stmt|;
comment|/**< Parse mode */
name|uint64_t
name|sl
range|:
literal|7
decl_stmt|;
comment|/**< Skip length */
name|uint64_t
name|addr
range|:
literal|55
decl_stmt|;
comment|/**< PCI/PCIe address */
else|#
directive|else
name|uint64_t
name|addr
range|:
literal|55
decl_stmt|;
name|uint64_t
name|sl
range|:
literal|7
decl_stmt|;
name|uint64_t
name|pm
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
name|dptr2
struct|;
struct|struct
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|es
range|:
literal|2
decl_stmt|;
comment|/**< Endian swap mode */
name|uint64_t
name|ns
range|:
literal|1
decl_stmt|;
comment|/**< No snoop */
name|uint64_t
name|ro
range|:
literal|1
decl_stmt|;
comment|/**< Relaxed ordering */
name|uint64_t
name|pm
range|:
literal|2
decl_stmt|;
comment|/**< Parse mode */
name|uint64_t
name|sl
range|:
literal|7
decl_stmt|;
comment|/**< Skip length */
name|uint64_t
name|addr
range|:
literal|51
decl_stmt|;
comment|/**< PCI/PCIe address */
else|#
directive|else
name|uint64_t
name|addr
range|:
literal|51
decl_stmt|;
name|uint64_t
name|sl
range|:
literal|7
decl_stmt|;
name|uint64_t
name|pm
range|:
literal|2
decl_stmt|;
name|uint64_t
name|ro
range|:
literal|1
decl_stmt|;
name|uint64_t
name|ns
range|:
literal|1
decl_stmt|;
name|uint64_t
name|es
range|:
literal|2
decl_stmt|;
endif|#
directive|endif
block|}
name|dptr3
struct|;
block|}
name|cvmx_npi_dptr_t
typedef|;
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

begin_comment
comment|/* __CVMX_NPI_H__ */
end_comment

end_unit

