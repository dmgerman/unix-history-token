begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This file defines macros for use in determining the current calling ABI.  *  *<hr>$Revision: 70030 $<hr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_ABI_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_ABI_H__
end_define

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

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__U_BOOT__
end_ifndef

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Check for N32 ABI, defined for 32-bit Simple Exec applications    and Linux N32 ABI.*/
if|#
directive|if
operator|(
name|defined
name|_ABIN32
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIN32
operator|)
define|#
directive|define
name|CVMX_ABI_N32
comment|/* Check for N64 ABI, defined for 64-bit Linux toolchain. */
elif|#
directive|elif
operator|(
name|defined
name|_ABI64
operator|&&
name|_MIPS_SIM
operator|==
name|_ABI64
operator|)
define|#
directive|define
name|CVMX_ABI_N64
comment|/* Check for O32 ABI, defined for Linux 032 ABI, not supported yet. */
elif|#
directive|elif
operator|(
name|defined
name|_ABIO32
operator|&&
name|_MIPS_SIM
operator|==
name|_ABIO32
operator|)
define|#
directive|define
name|CVMX_ABI_O32
comment|/* Check for EABI ABI, defined for 64-bit Simple Exec applications. */
else|#
directive|else
define|#
directive|define
name|CVMX_ABI_EABI
endif|#
directive|endif
ifndef|#
directive|ifndef
name|__BYTE_ORDER
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
define|#
directive|define
name|__BYTE_ORDER
value|__BIG_ENDIAN
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
define|#
directive|define
name|__BYTE_ORDER
value|__LITTLE_ENDIAN
define|#
directive|define
name|__BIG_ENDIAN
value|4321
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
define|#
directive|define
name|__BIG_ENDIAN
value|4321
define|#
directive|define
name|__BYTE_ORDER
value|__BIG_ENDIAN
else|#
directive|else
error|#
directive|error
error|Unable to determine Endian mode
endif|#
directive|endif
endif|#
directive|endif
comment|/* For compatibility with Linux definitions... */
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
ifndef|#
directive|ifndef
name|__BIG_ENDIAN_BITFIELD
define|#
directive|define
name|__BIG_ENDIAN_BITFIELD
endif|#
directive|endif
else|#
directive|else
ifndef|#
directive|ifndef
name|__LITTLE_ENDIAN_BITFIELD
define|#
directive|define
name|__LITTLE_ENDIAN_BITFIELD
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN_BITFIELD
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LITTLE_ENDIAN_BITFIELD
argument_list|)
error|#
directive|error
error|Cannot define both __BIG_ENDIAN_BITFIELD and __LITTLE_ENDIAN_BITFIELD
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
comment|/* __CVMX_ABI_H__ */
end_comment

end_unit

