begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUTYPES_H_
value|1
end_define

begin_comment
comment|/*  *	Classes of Processor  */
end_comment

begin_define
define|#
directive|define
name|CPUCLASS_286
value|0
end_define

begin_define
define|#
directive|define
name|CPUCLASS_386
value|1
end_define

begin_define
define|#
directive|define
name|CPUCLASS_486
value|2
end_define

begin_define
define|#
directive|define
name|CPUCLASS_586
value|3
end_define

begin_comment
comment|/*  *	Kinds of Processor  */
end_comment

begin_define
define|#
directive|define
name|CPU_286
value|0
end_define

begin_comment
comment|/* Intel 80286 */
end_comment

begin_define
define|#
directive|define
name|CPU_386SX
value|1
end_define

begin_comment
comment|/* Intel 80386SX */
end_comment

begin_define
define|#
directive|define
name|CPU_386
value|2
end_define

begin_comment
comment|/* Intel 80386DX */
end_comment

begin_define
define|#
directive|define
name|CPU_486SX
value|3
end_define

begin_comment
comment|/* Intel 80486SX */
end_comment

begin_define
define|#
directive|define
name|CPU_486
value|4
end_define

begin_comment
comment|/* Intel 80486DX */
end_comment

begin_define
define|#
directive|define
name|CPU_586
value|5
end_define

begin_comment
comment|/* Intel P.....m (I hate lawyers; it's TM) */
end_comment

begin_define
define|#
directive|define
name|CPU_486DLC
value|6
end_define

begin_comment
comment|/* Cyrix 486DLC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CPUTYPES_H_ */
end_comment

end_unit

