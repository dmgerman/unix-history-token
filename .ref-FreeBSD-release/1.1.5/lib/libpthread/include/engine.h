begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== engine.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|"machdep.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * New types  */
end_comment

begin_typedef
typedef|typedef
name|long
name|semaphore
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIGMAX
value|31
end_define

begin_comment
comment|/*  * New Strutures  */
end_comment

begin_struct
struct|struct
name|machdep_pthread
block|{
name|void
modifier|*
function_decl|(
modifier|*
name|start_routine
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|start_argument
decl_stmt|;
name|void
modifier|*
name|machdep_stack
decl_stmt|;
name|struct
name|itimerval
name|machdep_timer
decl_stmt|;
name|jmp_buf
name|machdep_state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Static machdep_pthread initialization values.  * For initial thread only.  */
end_comment

begin_define
define|#
directive|define
name|MACHDEP_PTHREAD_INIT
define|\
value|{ NULL, NULL, NULL, { { 0, 0 }, { 0, 0 } }, 0 }
end_define

begin_comment
comment|/*  * Some fd flag defines that are necessary to distinguish between posix  * behavior and bsd4.3 behavior.  */
end_comment

begin_define
define|#
directive|define
name|__FD_NONBLOCK
value|O_NONBLOCK
end_define

begin_comment
comment|/*  * New functions  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
name|int
name|semaphore_text_and_set
name|__P
argument_list|(
operator|(
name|semaphore
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|machdep_save_state
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

end_unit

