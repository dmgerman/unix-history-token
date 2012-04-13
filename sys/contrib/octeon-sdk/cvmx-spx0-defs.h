begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2012  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * cvmx-spx0-defs.h  *  * Configuration and status register (CSR) type definitions for  * Octeon spx0.  *  * This file is auto generated. Do not edit.  *  *<hr>$Revision$<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_SPX0_DEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_SPX0_DEFS_H__
end_define

begin_if
if|#
directive|if
name|CVMX_ENABLE_CSR_ADDRESS_CHECKING
end_if

begin_define
define|#
directive|define
name|CVMX_SPX0_PLL_BW_CTL
value|CVMX_SPX0_PLL_BW_CTL_FUNC()
end_define

begin_function
specifier|static
specifier|inline
name|uint64_t
name|CVMX_SPX0_PLL_BW_CTL_FUNC
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
name|OCTEON_CN38XX
argument_list|)
operator|)
condition|)
name|cvmx_warn
argument_list|(
literal|"CVMX_SPX0_PLL_BW_CTL not supported on this chip\n"
argument_list|)
expr_stmt|;
return|return
name|CVMX_ADD_IO_SEG
argument_list|(
literal|0x0001180090000388ull
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
name|CVMX_SPX0_PLL_BW_CTL
value|(CVMX_ADD_IO_SEG(0x0001180090000388ull))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CVMX_ENABLE_CSR_ADDRESS_CHECKING
end_if

begin_define
define|#
directive|define
name|CVMX_SPX0_PLL_SETTING
value|CVMX_SPX0_PLL_SETTING_FUNC()
end_define

begin_function
specifier|static
specifier|inline
name|uint64_t
name|CVMX_SPX0_PLL_SETTING_FUNC
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
name|OCTEON_CN38XX
argument_list|)
operator|)
condition|)
name|cvmx_warn
argument_list|(
literal|"CVMX_SPX0_PLL_SETTING not supported on this chip\n"
argument_list|)
expr_stmt|;
return|return
name|CVMX_ADD_IO_SEG
argument_list|(
literal|0x0001180090000380ull
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
name|CVMX_SPX0_PLL_SETTING
value|(CVMX_ADD_IO_SEG(0x0001180090000380ull))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * cvmx_spx0_pll_bw_ctl  */
end_comment

begin_union
union|union
name|cvmx_spx0_pll_bw_ctl
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
name|cvmx_spx0_pll_bw_ctl_s
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|reserved_5_63
range|:
literal|59
decl_stmt|;
name|uint64_t
name|bw_ctl
range|:
literal|5
decl_stmt|;
comment|/**< Core PLL bandwidth control */
else|#
directive|else
name|uint64_t
name|bw_ctl
range|:
literal|5
decl_stmt|;
name|uint64_t
name|reserved_5_63
range|:
literal|59
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
name|struct
name|cvmx_spx0_pll_bw_ctl_s
name|cn38xx
decl_stmt|;
name|struct
name|cvmx_spx0_pll_bw_ctl_s
name|cn38xxp2
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|cvmx_spx0_pll_bw_ctl
name|cvmx_spx0_pll_bw_ctl_t
typedef|;
end_typedef

begin_comment
comment|/**  * cvmx_spx0_pll_setting  */
end_comment

begin_union
union|union
name|cvmx_spx0_pll_setting
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
name|cvmx_spx0_pll_setting_s
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN_BITFIELD
name|uint64_t
name|reserved_17_63
range|:
literal|47
decl_stmt|;
name|uint64_t
name|setting
range|:
literal|17
decl_stmt|;
comment|/**< Core PLL setting */
else|#
directive|else
name|uint64_t
name|setting
range|:
literal|17
decl_stmt|;
name|uint64_t
name|reserved_17_63
range|:
literal|47
decl_stmt|;
endif|#
directive|endif
block|}
name|s
struct|;
name|struct
name|cvmx_spx0_pll_setting_s
name|cn38xx
decl_stmt|;
name|struct
name|cvmx_spx0_pll_setting_s
name|cn38xxp2
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|cvmx_spx0_pll_setting
name|cvmx_spx0_pll_setting_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

