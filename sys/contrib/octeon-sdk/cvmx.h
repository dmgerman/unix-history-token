begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Main Octeon executive header file (This should be the second header  * file included by an application).  *  *<hr>$Revision: 70030 $<hr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_H__
end_define

begin_comment
comment|/* Control whether simple executive applications use 1-1 TLB mappings to access physical ** memory addresses.  This must be disabled to allow large programs that use more than ** the 0x10000000 - 0x20000000 virtual address range. ** ** The FreeBSD kernel ifdefs elsewhere should mean that this is never even checked, ** and so does not need to be defined. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_USE_1_TO_1_TLB_MAPPINGS
end_ifndef

begin_define
define|#
directive|define
name|CVMX_USE_1_TO_1_TLB_MAPPINGS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_ENABLE_PARAMETER_CHECKING
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|CVMX_ENABLE_PARAMETER_CHECKING
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CVMX_ENABLE_PARAMETER_CHECKING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_ENABLE_PARAMETER_CHECKING
end_ifndef

begin_define
define|#
directive|define
name|CVMX_ENABLE_PARAMETER_CHECKING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_ENABLE_DEBUG_PRINTS
end_ifndef

begin_define
define|#
directive|define
name|CVMX_ENABLE_DEBUG_PRINTS
value|1
end_define

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
include|#
directive|include
file|"cvmx-platform.h"
include|#
directive|include
file|"cvmx-access.h"
include|#
directive|include
file|"cvmx-address.h"
include|#
directive|include
file|"cvmx-asm.h"
include|#
directive|include
file|"cvmx-packet.h"
include|#
directive|include
file|"cvmx-warn.h"
include|#
directive|include
file|"cvmx-sysinfo.h"
include|#
directive|include
file|"octeon-model.h"
include|#
directive|include
file|"cvmx-csr.h"
include|#
directive|include
file|"cvmx-utils.h"
include|#
directive|include
file|"cvmx-clock.h"
include|#
directive|include
file|"octeon-feature.h"
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_HOST
argument_list|)
include|#
directive|include
file|"cvmx-access-native.h"
endif|#
directive|endif
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
comment|/*  __CVMX_H__  */
end_comment

end_unit

