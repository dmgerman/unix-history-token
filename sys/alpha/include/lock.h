begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: lock.h,v 1.1.1.1 1998/03/09 05:43:16 jb Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_LOCK_H_
end_define

begin_comment
comment|/*  * Simple spin lock.  * It is an error to hold one of these locks while a process is sleeping.  */
end_comment

begin_struct
struct|struct
name|simplelock
block|{
specifier|volatile
name|int
name|lock_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|simple_lock_init
parameter_list|(
name|alp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|simple_lock
parameter_list|(
name|alp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|simple_lock_try
parameter_list|(
name|alp
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|simple_unlock
parameter_list|(
name|alp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_LOCK_H_ */
end_comment

end_unit

