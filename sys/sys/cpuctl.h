begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2008 Stanislav Sedov<stas@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPUCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CPUCTL_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|msr
decl_stmt|;
comment|/* MSR to read */
name|uint64_t
name|data
decl_stmt|;
block|}
name|cpuctl_msr_args_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|level
decl_stmt|;
comment|/* CPUID level */
name|uint32_t
name|data
index|[
literal|4
index|]
decl_stmt|;
block|}
name|cpuctl_cpuid_args_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|level
decl_stmt|;
comment|/* CPUID level */
name|int
name|level_type
decl_stmt|;
comment|/* CPUID level type */
name|uint32_t
name|data
index|[
literal|4
index|]
decl_stmt|;
block|}
name|cpuctl_cpuid_count_args_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|cpuctl_update_args_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CPUCTL_RDMSR
value|_IOWR('c', 1, cpuctl_msr_args_t)
end_define

begin_define
define|#
directive|define
name|CPUCTL_WRMSR
value|_IOWR('c', 2, cpuctl_msr_args_t)
end_define

begin_define
define|#
directive|define
name|CPUCTL_CPUID
value|_IOWR('c', 3, cpuctl_cpuid_args_t)
end_define

begin_define
define|#
directive|define
name|CPUCTL_UPDATE
value|_IOWR('c', 4, cpuctl_update_args_t)
end_define

begin_define
define|#
directive|define
name|CPUCTL_MSRSBIT
value|_IOWR('c', 5, cpuctl_msr_args_t)
end_define

begin_define
define|#
directive|define
name|CPUCTL_MSRCBIT
value|_IOWR('c', 6, cpuctl_msr_args_t)
end_define

begin_define
define|#
directive|define
name|CPUCTL_CPUID_COUNT
value|_IOWR('c', 7, cpuctl_cpuid_count_args_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPUCTL_H_ */
end_comment

end_unit

