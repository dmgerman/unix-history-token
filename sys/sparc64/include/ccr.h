begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2001 by Thomas Moestl<tmm@FreeBSD.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CCR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CCR_H_
end_define

begin_define
define|#
directive|define
name|ICC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ICC_BITS
value|4
end_define

begin_define
define|#
directive|define
name|ICC_MASK
value|((1UL<< ICC_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|ICC_C
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|ICC_V
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|ICC_Z
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|ICC_N
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|XCC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|XCC_BITS
value|4
end_define

begin_define
define|#
directive|define
name|XCC_MASK
value|(((1UL<< XCC_BITS) - 1)<< XCC_SHIFT)
end_define

begin_define
define|#
directive|define
name|XCC_C
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|XCC_V
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|XCC_Z
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|XCC_N
value|(1UL<< 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CCR_H_ */
end_comment

end_unit

