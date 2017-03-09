begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_OSDEP_H_
end_define

begin_comment
comment|/*  * Defines to adjust the types that EDK2 uses for FreeBSD so we can  * use the code and headers mostly unchanged. The headers are imported  * all into one directory to avoid case issues with filenames and  * included. The actual code is heavily modified since it has too many  * annoying dependencies that are difficult to satisfy.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_typedef
typedef|typedef
name|int8_t
name|INT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|INT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|intptr_t
name|INTN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uintptr_t
name|UINTN
typedef|;
end_typedef

begin_comment
comment|//typedef uintptr_t EFI_PHYSICAL_ADDRESS;
end_comment

begin_comment
comment|//typedef uint32_t EFI_IPv4_ADDRESS;
end_comment

begin_comment
comment|//typedef uint8_t EFI_MAC_ADDRESS[6];
end_comment

begin_comment
comment|//typedef uint8_t EFI_IPv6_ADDRESS[16];
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|CHAR8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|CHAR16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VOID
typedef|;
end_typedef

begin_comment
comment|//typedef uuid_t GUID;
end_comment

begin_comment
comment|//typedef uuid_t EFI_GUID;
end_comment

begin_comment
comment|/* We can't actually call this stuff, so snip out API syntactic sugar */
end_comment

begin_define
define|#
directive|define
name|INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EFIAPI
end_define

begin_define
define|#
directive|define
name|IN
end_define

begin_define
define|#
directive|define
name|OUT
end_define

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_define
define|#
directive|define
name|OPTIONAL
end_define

begin_comment
comment|//#define TRUE 1
end_comment

begin_comment
comment|//#define FALSE 0
end_comment

begin_comment
comment|/*  * EDK2 has fine definitions for these, so let it define them.  */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_undef
undef|#
directive|undef
name|EFI_PAGE_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|EFI_PAGE_MASK
end_undef

begin_comment
comment|/*  * Note: the EDK2 code assumed #pragma packed works and PACKED is a  * workaround for some old toolchain issues for EDK2 that aren't  * relevent to FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|PACKED
end_define

begin_comment
comment|/*  * Since we're not compiling for the UEFI boot time (which use ms abi  * conventions), tell EDK2 to define VA_START correctly. For the boot  * loader, this likely needs to be different.  */
end_comment

begin_define
define|#
directive|define
name|NO_MSABI_VA_FUNCS
value|1
end_define

begin_comment
comment|/*  * Finally, we need to define the processor we are in EDK2 terms.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MDE_CPU_IA32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MDE_CPU_X64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MDE_CPU_ARM
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MDE_CPU_AARCH64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD doesn't have/use MDE_CPU_EBC or MDE_CPU_IPF (ia64) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EFI_OSDEP_H_ */
end_comment

end_unit

