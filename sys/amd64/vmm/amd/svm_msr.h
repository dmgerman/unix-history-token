begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Anish Gupta (akgupt3@gmail.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_SVM_MSR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVM_MSR_H_
end_define

begin_comment
comment|/*  * SVM CPUID function, address 0x8000_000A edx bit decoding.  */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_NP
value|BIT(0)
end_define

begin_comment
comment|/* Nested paging or RVI */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_LBR
value|BIT(1)
end_define

begin_comment
comment|/* Last branch virtualization */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_SVML
value|BIT(2)
end_define

begin_comment
comment|/* SVM lock */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_NRIP_SAVE
value|BIT(3)
end_define

begin_comment
comment|/* Next RIP is saved */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_TSC_RATE
value|BIT(4)
end_define

begin_comment
comment|/* TSC rate control. */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_VMCB_CLEAN
value|BIT(5)
end_define

begin_comment
comment|/* VMCB state caching */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_ASID_FLUSH
value|BIT(6)
end_define

begin_comment
comment|/* Flush by ASID */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_DECODE_ASSIST
value|BIT(7)
end_define

begin_comment
comment|/* Decode assist */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_PAUSE_INC
value|BIT(10)
end_define

begin_comment
comment|/* Pause intercept filter. */
end_comment

begin_define
define|#
directive|define
name|AMD_CPUID_SVM_PAUSE_FTH
value|BIT(12)
end_define

begin_comment
comment|/* Pause filter threshold */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SVM_MSR_H_ */
end_comment

end_unit

