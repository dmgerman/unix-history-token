begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to Core, IO and DDR Clock.  *  *<hr>$Revision: 45089 $<hr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_CLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_CLOCK_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/octeon.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-lmcx-defs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx.h"
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
comment|/**  * Enumeration of different Clocks in Octeon.  */
typedef|typedef
enum|enum
block|{
name|CVMX_CLOCK_RCLK
block|,
comment|/**< Clock used by cores, coherent bus and L2 cache. */
name|CVMX_CLOCK_SCLK
block|,
comment|/**< Clock used by IO blocks. */
name|CVMX_CLOCK_DDR
block|,
comment|/**< Clock used by DRAM */
name|CVMX_CLOCK_CORE
block|,
comment|/**< Alias for CVMX_CLOCK_RCLK */
name|CVMX_CLOCK_TIM
block|,
comment|/**< Alias for CVMX_CLOCK_SCLK */
name|CVMX_CLOCK_IPD
block|,
comment|/**< Alias for CVMX_CLOCK_SCLK */
block|}
name|cvmx_clock_t
typedef|;
comment|/**  * Get cycle count based on the clock type.  *  * @param clock - Enumeration of the clock type.  * @return      - Get the number of cycles executed so far.  */
specifier|static
specifier|inline
name|uint64_t
name|cvmx_clock_get_count
parameter_list|(
name|cvmx_clock_t
name|clock
parameter_list|)
block|{
switch|switch
condition|(
name|clock
condition|)
block|{
case|case
name|CVMX_CLOCK_RCLK
case|:
case|case
name|CVMX_CLOCK_CORE
case|:
block|{
ifndef|#
directive|ifndef
name|__mips__
return|return
name|cvmx_read_csr
argument_list|(
name|CVMX_IPD_CLK_COUNT
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_ABI_O32
argument_list|)
name|uint32_t
name|tmp_low
decl_stmt|,
name|tmp_hi
decl_stmt|;
asm|asm
specifier|volatile
asm|(                "   .set push                    \n"                "   .set mips64r2                \n"                "   .set noreorder               \n"                "   rdhwr %[tmpl], $31           \n"                "   dsrl  %[tmph], %[tmpl], 32   \n"                "   sll   %[tmpl], 0             \n"                "   sll   %[tmph], 0             \n"                "   .set pop                 \n"                   : [tmpl] "=&r" (tmp_low), [tmph] "=&r" (tmp_hi) : );
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|tmp_hi
operator|<<
literal|32
operator|)
operator|+
name|tmp_low
operator|)
return|;
else|#
directive|else
name|uint64_t
name|cycle
decl_stmt|;
name|CVMX_RDHWR
argument_list|(
name|cycle
argument_list|,
literal|31
argument_list|)
expr_stmt|;
return|return
operator|(
name|cycle
operator|)
return|;
endif|#
directive|endif
block|}
case|case
name|CVMX_CLOCK_SCLK
case|:
case|case
name|CVMX_CLOCK_TIM
case|:
case|case
name|CVMX_CLOCK_IPD
case|:
return|return
name|cvmx_read_csr
argument_list|(
name|CVMX_IPD_CLK_COUNT
argument_list|)
return|;
case|case
name|CVMX_CLOCK_DDR
case|:
if|if
condition|(
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CN6XXX
argument_list|)
operator|||
name|OCTEON_IS_MODEL
argument_list|(
name|OCTEON_CNF7XXX
argument_list|)
condition|)
return|return
name|cvmx_read_csr
argument_list|(
name|CVMX_LMCX_DCLK_CNT
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
else|else
return|return
operator|(
operator|(
name|cvmx_read_csr
argument_list|(
name|CVMX_LMCX_DCLK_CNT_HI
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|32
operator|)
operator||
name|cvmx_read_csr
argument_list|(
name|CVMX_LMCX_DCLK_CNT_LO
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|)
return|;
block|}
name|cvmx_dprintf
argument_list|(
literal|"cvmx_clock_get_count: Unknown clock type\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
specifier|extern
name|uint64_t
name|cvmx_clock_get_rate
parameter_list|(
name|cvmx_clock_t
name|clock
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

begin_comment
comment|/* __CVMX_CLOCK_H__ */
end_comment

end_unit

