begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-debug.h>
end_include

begin_define
define|#
directive|define
name|cvmx_interrupt_in_isr
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-debug.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_TOOLCHAIN
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|cvmx_interrupt_in_isr
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cvmx_interrupt_in_isr
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

begin_function
specifier|static
name|void
name|cvmx_debug_remote_mem_wait_for_resume
parameter_list|(
specifier|volatile
name|cvmx_debug_core_context_t
modifier|*
name|context
parameter_list|,
name|cvmx_debug_state_t
name|state
parameter_list|)
block|{
comment|//
comment|// If we are stepping and not stepping into an interrupt and the debug
comment|// exception happened in an interrupt, continue the execution.
comment|//
if|if
condition|(
operator|!
name|state
operator|.
name|step_isr
operator|&&
operator|(
name|context
operator|->
name|cop0
operator|.
name|debug
operator|&
literal|0x1
operator|)
operator|&&
comment|/* Single stepping */
operator|!
operator|(
name|context
operator|->
name|cop0
operator|.
name|debug
operator|&
literal|0x1e
operator|)
operator|&&
comment|/* Did not hit a breakpoint */
operator|(
operator|(
name|context
operator|->
name|cop0
operator|.
name|status
operator|&
literal|0x2
operator|)
operator|||
name|cvmx_interrupt_in_isr
operator|)
condition|)
return|return;
name|context
operator|->
name|remote_controlled
operator|=
literal|1
expr_stmt|;
name|CVMX_SYNCW
expr_stmt|;
while|while
condition|(
name|context
operator|->
name|remote_controlled
condition|)
empty_stmt|;
name|CVMX_SYNCW
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|cvmx_debug_memory_change_core
parameter_list|(
name|int
name|oldcore
parameter_list|,
name|int
name|newcore
parameter_list|)
block|{
comment|/* FIXME, this should change the core on the host side too. */
block|}
end_function

begin_decl_stmt
name|cvmx_debug_comm_t
name|cvmx_debug_remote_comm
init|=
block|{
operator|.
name|init
operator|=
name|NULL
block|,
operator|.
name|install_break_handler
operator|=
name|NULL
block|,
operator|.
name|needs_proxy
operator|=
literal|0
block|,
operator|.
name|getpacket
operator|=
name|NULL
block|,
operator|.
name|putpacket
operator|=
name|NULL
block|,
operator|.
name|wait_for_resume
operator|=
name|cvmx_debug_remote_mem_wait_for_resume
block|,
operator|.
name|change_core
operator|=
name|cvmx_debug_memory_change_core
block|, }
decl_stmt|;
end_decl_stmt

end_unit

