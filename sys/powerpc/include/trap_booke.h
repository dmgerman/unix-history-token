begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006 Semihalf, Rafal Jaworowski<raj@semihalf.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_TRAP_H_
end_define

begin_define
define|#
directive|define
name|EXC_CRIT
value|0
end_define

begin_define
define|#
directive|define
name|EXC_MCHK
value|1
end_define

begin_define
define|#
directive|define
name|EXC_DSI
value|2
end_define

begin_define
define|#
directive|define
name|EXC_ISI
value|3
end_define

begin_define
define|#
directive|define
name|EXC_EXI
value|4
end_define

begin_define
define|#
directive|define
name|EXC_ALI
value|5
end_define

begin_define
define|#
directive|define
name|EXC_PGM
value|6
end_define

begin_define
define|#
directive|define
name|EXC_FPU
value|7
end_define

begin_comment
comment|/* e500: not supported */
end_comment

begin_define
define|#
directive|define
name|EXC_SC
value|8
end_define

begin_define
define|#
directive|define
name|EXC_APU
value|9
end_define

begin_comment
comment|/* e500: not supported */
end_comment

begin_define
define|#
directive|define
name|EXC_DECR
value|10
end_define

begin_define
define|#
directive|define
name|EXC_FIT
value|11
end_define

begin_define
define|#
directive|define
name|EXC_WDOG
value|12
end_define

begin_define
define|#
directive|define
name|EXC_DTMISS
value|13
end_define

begin_define
define|#
directive|define
name|EXC_ITMISS
value|14
end_define

begin_define
define|#
directive|define
name|EXC_DEBUG
value|15
end_define

begin_define
define|#
directive|define
name|EXC_SAU
value|32
end_define

begin_comment
comment|/* e500-specific: SPE APU unavailable */
end_comment

begin_define
define|#
directive|define
name|EXC_PERF
value|35
end_define

begin_comment
comment|/* e500-specific: Performance monitor */
end_comment

begin_define
define|#
directive|define
name|EXC_LAST
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_TRAP_H_ */
end_comment

end_unit

