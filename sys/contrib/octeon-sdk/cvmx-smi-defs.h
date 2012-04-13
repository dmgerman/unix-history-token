begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2012  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * cvmx-smi-defs.h  *  * Configuration and status register (CSR) type definitions for  * Octeon smi.  *  * This file is auto generated. Do not edit.  *  *<hr>$Revision$<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_SMI_DEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_SMI_DEFS_H__
end_define

begin_if
if|#
directive|if
name|CVMX_ENABLE_CSR_ADDRESS_CHECKING
end_if

begin_define
define|#
directive|define
name|CVMX_SMI_DRV_CTL
value|CVMX_SMI_DRV_CTL_FUNC()
end_define

begin_function
specifier|static
specifier|inline
name|uint64_t
name|CVMX_SMI_DRV_CTL_FUNC
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN61XX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN63XX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN66XX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN68XX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CNF71XX
argument_list|)
operator|)
condition|)
name|cvmx_warn
argument_list|(
literal|"CVMX_SMI_DRV_CTL not supported on this chip\n"
argument_list|)
expr_stmt|;
return|return
name|CVMX_ADD_IO_SEG
argument_list|(
literal|0x0001180000001828ull
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CVMX_SMI_DRV_CTL
value|(CVMX_ADD_IO_SEG(0x0001180000001828ull))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * cvmx_smi_drv_ctl  *  * SMI_DRV_CTL = SMI Drive Strength Control  *  */
end_comment

begin_union
union|union
name|cvmx_smi_drv_ctl
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
name|cvmx_smi_drv_ctl_s
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|reserved_14_63
range|:
literal|50
decl_stmt|;
name|uint64_t
name|pctl
range|:
literal|6
decl_stmt|;
comment|/**< PCTL Drive strength control bits                                                          Assuming a 50ohm termination                                                          3.3v supply = 19                                                          2.5v supply = TBD */
name|uint64_t
name|reserved_6_7
range|:
literal|2
decl_stmt|;
name|uint64_t
name|nctl
range|:
literal|6
decl_stmt|;
comment|/**< NCTL Drive strength control bits                                                          Assuming a 50ohm termination                                                          3.3v supply = 15                                                          2.5v supply = TBD */
else|#
directive|else
name|uint64_t
name|nctl
range|:
literal|6
decl_stmt|;
name|uint64_t
name|reserved_6_7
range|:
literal|2
decl_stmt|;
name|uint64_t
name|pctl
range|:
literal|6
decl_stmt|;
name|uint64_t
name|reserved_14_63
range|:
literal|50
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cn61xx
decl_stmt|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cn63xx
decl_stmt|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cn63xxp1
decl_stmt|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cn66xx
decl_stmt|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cn68xx
decl_stmt|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cn68xxp1
decl_stmt|;
name|struct
name|cvmx_smi_drv_ctl_s
name|cnf71xx
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|cvmx_smi_drv_ctl
name|cvmx_smi_drv_ctl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

