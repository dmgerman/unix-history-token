begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * random.h -- A strong random number generator  *  * $FreeBSD$  *  * Version 0.95, last modified 18-Oct-95  *   * Copyright Theodore Ts'o, 1994, 1995.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Many kernel routines will have a use for good random numbers,  * for example, for truely random TCP sequence numbers, which prevent  * certain forms of TCP spoofing attacks.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RANDOM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RANDOM_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|MEM_SETIRQ
value|_IOW('r', 1, u_int16_t)
end_define

begin_comment
comment|/* set interrupt */
end_comment

begin_define
define|#
directive|define
name|MEM_CLEARIRQ
value|_IOW('r', 2, u_int16_t)
end_define

begin_comment
comment|/* clear interrupt */
end_comment

begin_define
define|#
directive|define
name|MEM_RETURNIRQ
value|_IOR('r', 3, u_int16_t)
end_define

begin_comment
comment|/* return interrupt */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Type of the cookie passed to add_interrupt_randomness. */
end_comment

begin_struct
struct|struct
name|random_softc
block|{
name|inthand2_t
modifier|*
name|sc_handler
decl_stmt|;
name|void
modifier|*
name|sc_arg
decl_stmt|;
name|int
name|sc_intr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Exported functions */
end_comment

begin_function_decl
name|void
name|rand_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_keyboard_randomness
parameter_list|(
name|u_char
name|scancode
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|inthand2_t
name|add_interrupt_randomness
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_function_decl
name|void
name|add_blkdev_randomness
parameter_list|(
name|int
name|major
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_function_decl
name|void
name|get_random_bytes
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|u_int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_int
name|read_random
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|u_int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|read_random_unlimited
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|u_int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_function_decl
name|u_int
name|write_random
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|random_poll
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|events
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_RANDOM_H_ */
end_comment

end_unit

