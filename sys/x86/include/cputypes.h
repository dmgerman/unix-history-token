begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X86_CPUTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_X86_CPUTYPES_H_
end_define

begin_comment
comment|/*  * Vendors of processor.  */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_NSC
value|0x100b
end_define

begin_comment
comment|/* NSC */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_IBM
value|0x1014
end_define

begin_comment
comment|/* IBM */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_AMD
value|0x1022
end_define

begin_comment
comment|/* AMD */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_SIS
value|0x1039
end_define

begin_comment
comment|/* SiS */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_UMC
value|0x1060
end_define

begin_comment
comment|/* UMC */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_NEXGEN
value|0x1074
end_define

begin_comment
comment|/* Nexgen */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_CYRIX
value|0x1078
end_define

begin_comment
comment|/* Cyrix */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_IDT
value|0x111d
end_define

begin_comment
comment|/* Centaur/IDT/VIA */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_TRANSMETA
value|0x1279
end_define

begin_comment
comment|/* Transmeta */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_INTEL
value|0x8086
end_define

begin_comment
comment|/* Intel */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_RISE
value|0xdead2bad
end_define

begin_comment
comment|/* Rise */
end_comment

begin_define
define|#
directive|define
name|CPU_VENDOR_CENTAUR
value|CPU_VENDOR_IDT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_X86_CPUTYPES_H_ */
end_comment

end_unit

