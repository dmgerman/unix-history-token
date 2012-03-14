begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Packet buffer defines.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_PACKET_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_PACKET_H__
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
comment|/**  * This structure defines a buffer pointer on Octeon  */
union|union
name|cvmx_buf_ptr
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|i
range|:
literal|1
decl_stmt|;
comment|/**< if set, invert the "free" pick of the overall packet. HW always sets this bit to 0 on inbound packet */
name|uint64_t
name|back
range|:
literal|4
decl_stmt|;
comment|/**< Indicates the amount to back up to get to the buffer start in cache lines. In most cases                                 this is less than one complete cache line, so the value is zero */
name|uint64_t
name|pool
range|:
literal|3
decl_stmt|;
comment|/**< The pool that the buffer came from / goes to */
name|uint64_t
name|size
range|:
literal|16
decl_stmt|;
comment|/**< The size of the segment pointed to by addr (in bytes) */
name|uint64_t
name|addr
range|:
literal|40
decl_stmt|;
comment|/**< Pointer to the first byte of the data, NOT buffer */
block|}
name|s
struct|;
block|}
union|;
typedef|typedef
name|union
name|cvmx_buf_ptr
name|cvmx_buf_ptr_t
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
comment|/*  __CVMX_PACKET_H__ */
end_comment

end_unit

