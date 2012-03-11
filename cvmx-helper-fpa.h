begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Helper functions for FPA setup.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_H_FPA__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_H_FPA__
end_define

begin_comment
comment|/**  * Allocate memory and initialize the FPA pools using memory  * from cvmx-bootmem. Sizes of each element in the pools is  * controlled by the cvmx-config.h header file. Specifying  * zero for any parameter will cause that FPA pool to not be  * setup. This is useful if you aren't using some of the  * hardware and want to save memory.  *  * @param packet_buffers  *               Number of packet buffers to allocate  * @param work_queue_entries  *               Number of work queue entries  * @param pko_buffers  *               PKO Command buffers. You should at minimum have two per  *               each PKO queue.  * @param tim_buffers  *               TIM ring buffer command queues. At least two per timer bucket  *               is recommended.  * @param dfa_buffers  *               DFA command buffer. A relatively small (32 for example)  *               number should work.  * @return Zero on success, non-zero if out of memory  */
end_comment

begin_function_decl
specifier|extern
name|int
name|cvmx_helper_initialize_fpa
parameter_list|(
name|int
name|packet_buffers
parameter_list|,
name|int
name|work_queue_entries
parameter_list|,
name|int
name|pko_buffers
parameter_list|,
name|int
name|tim_buffers
parameter_list|,
name|int
name|dfa_buffers
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_HELPER_H__ */
end_comment

end_unit

