begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ASSYM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ASSYM_H_
end_define

begin_define
define|#
directive|define
name|ASSYM_ABS
parameter_list|(
name|value
parameter_list|)
value|((value)< 0 ? -((value) + 1) + 1ULL : (value))
end_define

begin_define
define|#
directive|define
name|ASSYM
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|char name ## sign[(value)< 0 ? 1 : 0];				\ char name ## w0[ASSYM_ABS(value)& 0xFFFFU];			\ char name ## w1[(ASSYM_ABS(value)& 0xFFFF0000UL)>> 16];	\ char name ## w2[(ASSYM_ABS(value)& 0xFFFF00000000ULL)>> 32];	\ char name ## w3[(ASSYM_ABS(value)& 0xFFFF000000000000ULL)>> 48]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ASSYM_H_ */
end_comment

end_unit

