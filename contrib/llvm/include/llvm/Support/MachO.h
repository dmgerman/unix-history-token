begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/MachO.h - The MachO file format ------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines manifest constants for the MachO object file format.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_MACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MACHO_H
end_define

begin_comment
comment|// NOTE: The enums in this file are intentially named to be different than those
end_comment

begin_comment
comment|// in the headers in /usr/include/mach (on darwin systems) to avoid conflicts
end_comment

begin_comment
comment|// with those macros.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|MachO
block|{
comment|// Enums from<mach/machine.h>
enum|enum
block|{
comment|// Capability bits used in the definition of cpu_type.
name|CPUArchMask
init|=
literal|0xff000000
block|,
comment|// Mask for architecture bits
name|CPUArchABI64
init|=
literal|0x01000000
block|,
comment|// 64 bit ABI
comment|// Constants for the cputype field.
name|CPUTypeI386
init|=
literal|7
block|,
name|CPUTypeX86_64
init|=
name|CPUTypeI386
operator||
name|CPUArchABI64
block|,
name|CPUTypeARM
init|=
literal|12
block|,
name|CPUTypeSPARC
init|=
literal|14
block|,
name|CPUTypePowerPC
init|=
literal|18
block|,
name|CPUTypePowerPC64
init|=
name|CPUTypePowerPC
operator||
name|CPUArchABI64
block|,
comment|// Constants for the cpusubtype field.
comment|// X86
name|CPUSubType_I386_ALL
init|=
literal|3
block|,
name|CPUSubType_X86_64_ALL
init|=
literal|3
block|,
comment|// ARM
name|CPUSubType_ARM_ALL
init|=
literal|0
block|,
name|CPUSubType_ARM_V4T
init|=
literal|5
block|,
name|CPUSubType_ARM_V6
init|=
literal|6
block|,
comment|// PowerPC
name|CPUSubType_POWERPC_ALL
init|=
literal|0
block|,
name|CPUSubType_SPARC_ALL
init|=
literal|0
block|}
enum|;
block|}
comment|// end namespace MachO
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

