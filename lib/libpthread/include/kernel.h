begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== kernel.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : mutex header.  *  *  1.00 93/07/22 proven  *      -Started coding this file.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 by Chris Provenzano and contributors, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano,  *	the University of California, Berkeley, and contributors.  * 4. Neither the name of Chris Provenzano, the University, nor the names of  *	  contributors may be used to endorse or promote products derived  *	  from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO, THE REGENTS OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Defines only for the pthread user kernel.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|PANIC
parameter_list|()
value|abort()
end_define

begin_comment
comment|/* Time each rr thread gets */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_RR_TIMEOUT
value|100000000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

