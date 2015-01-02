begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* arc4_lock.c - global lock for arc4random *  * Copyright (c) 2014, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_define
define|#
directive|define
name|LOCKRET
parameter_list|(
name|func
parameter_list|)
value|func
end_define

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_function_decl
name|void
name|_ARC4_LOCK
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_ARC4_UNLOCK
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|THREADS_DISABLED
end_ifdef

begin_function
name|void
name|_ARC4_LOCK
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|_ARC4_UNLOCK
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !THREADS_DISABLED */
end_comment

begin_decl_stmt
specifier|static
name|lock_quick_t
name|arc4lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|arc4lockinit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_ARC4_LOCK
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|arc4lockinit
condition|)
name|lock_quick_init
argument_list|(
operator|&
name|arc4lock
argument_list|)
expr_stmt|;
name|lock_quick_lock
argument_list|(
operator|&
name|arc4lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_ARC4_UNLOCK
parameter_list|(
name|void
parameter_list|)
block|{
name|lock_quick_unlock
argument_list|(
operator|&
name|arc4lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THREADS_DISABLED */
end_comment

end_unit

