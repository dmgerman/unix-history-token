begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_DEBUG_MONITOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_DEBUG_MONITOR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_enum
enum|enum
name|dbg_access_t
block|{
name|HW_BREAKPOINT_X
init|=
literal|0
block|,
name|HW_WATCHPOINT_R
init|=
literal|1
block|,
name|HW_WATCHPOINT_W
init|=
literal|2
block|,
name|HW_WATCHPOINT_RW
init|=
name|HW_WATCHPOINT_R
operator||
name|HW_WATCHPOINT_W
block|, }
enum|;
end_enum

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_function_decl
name|void
name|dbg_monitor_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_monitor_init_secondary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_show_watchpoint
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbg_setup_watchpoint
parameter_list|(
name|db_expr_t
parameter_list|,
name|db_expr_t
parameter_list|,
name|enum
name|dbg_access_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbg_remove_watchpoint
parameter_list|(
name|db_expr_t
parameter_list|,
name|db_expr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_resume_dbreg
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ARM_ARCH>= 6 */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|dbg_show_watchpoint
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|int
name|dbg_setup_watchpoint
parameter_list|(
name|db_expr_t
name|addr
name|__unused
parameter_list|,
name|db_expr_t
name|size
name|__unused
parameter_list|,
name|enum
name|dbg_access_t
name|access
name|__unused
parameter_list|)
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|dbg_remove_watchpoint
parameter_list|(
name|db_expr_t
name|addr
name|__unused
parameter_list|,
name|db_expr_t
name|size
name|__unused
parameter_list|)
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|dbg_monitor_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|dbg_monitor_init_secondary
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|dbg_resume_dbreg
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARM_ARCH< 6 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DDB */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|dbg_monitor_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_DEBUG_MONITOR_H_ */
end_comment

end_unit

