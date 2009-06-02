begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetMachOWriterInfo.h - MachO Writer Info--*- C++ -*-===//
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
comment|// This file defines the TargetMachOWriterInfo class.
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
name|LLVM_TARGET_TARGETMACHOWRITERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETMACHOWRITERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRelocation.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|OutputBuffer
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//                        TargetMachOWriterInfo
comment|//===--------------------------------------------------------------------===//
name|class
name|TargetMachOWriterInfo
block|{
name|uint32_t
name|CPUType
decl_stmt|;
comment|// CPU specifier
name|uint32_t
name|CPUSubType
decl_stmt|;
comment|// Machine specifier
name|public
label|:
comment|// The various CPU_TYPE_* constants are already defined by at least one
comment|// system header file and create compilation errors if not respected.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_TYPE_I386
argument_list|)
define|#
directive|define
name|CPU_TYPE_I386
value|7
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_TYPE_X86_64
argument_list|)
define|#
directive|define
name|CPU_TYPE_X86_64
value|(CPU_TYPE_I386 | 0x1000000)
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_TYPE_ARM
argument_list|)
define|#
directive|define
name|CPU_TYPE_ARM
value|12
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_TYPE_SPARC
argument_list|)
define|#
directive|define
name|CPU_TYPE_SPARC
value|14
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_TYPE_POWERPC
argument_list|)
define|#
directive|define
name|CPU_TYPE_POWERPC
value|18
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_TYPE_POWERPC64
argument_list|)
define|#
directive|define
name|CPU_TYPE_POWERPC64
value|(CPU_TYPE_POWERPC | 0x1000000)
endif|#
directive|endif
comment|// Constants for the cputype field
comment|// see<mach/machine.h>
enum|enum
block|{
name|HDR_CPU_TYPE_I386
init|=
name|CPU_TYPE_I386
block|,
name|HDR_CPU_TYPE_X86_64
init|=
name|CPU_TYPE_X86_64
block|,
name|HDR_CPU_TYPE_ARM
init|=
name|CPU_TYPE_ARM
block|,
name|HDR_CPU_TYPE_SPARC
init|=
name|CPU_TYPE_SPARC
block|,
name|HDR_CPU_TYPE_POWERPC
init|=
name|CPU_TYPE_POWERPC
block|,
name|HDR_CPU_TYPE_POWERPC64
init|=
name|CPU_TYPE_POWERPC64
block|}
enum|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_SUBTYPE_I386_ALL
argument_list|)
define|#
directive|define
name|CPU_SUBTYPE_I386_ALL
value|3
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_SUBTYPE_X86_64_ALL
argument_list|)
define|#
directive|define
name|CPU_SUBTYPE_X86_64_ALL
value|3
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_SUBTYPE_ARM_ALL
argument_list|)
define|#
directive|define
name|CPU_SUBTYPE_ARM_ALL
value|0
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_SUBTYPE_SPARC_ALL
argument_list|)
define|#
directive|define
name|CPU_SUBTYPE_SPARC_ALL
value|0
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CPU_SUBTYPE_POWERPC_ALL
argument_list|)
define|#
directive|define
name|CPU_SUBTYPE_POWERPC_ALL
value|0
endif|#
directive|endif
comment|// Constants for the cpusubtype field
comment|// see<mach/machine.h>
enum|enum
block|{
name|HDR_CPU_SUBTYPE_I386_ALL
init|=
name|CPU_SUBTYPE_I386_ALL
block|,
name|HDR_CPU_SUBTYPE_X86_64_ALL
init|=
name|CPU_SUBTYPE_X86_64_ALL
block|,
name|HDR_CPU_SUBTYPE_ARM_ALL
init|=
name|CPU_SUBTYPE_ARM_ALL
block|,
name|HDR_CPU_SUBTYPE_SPARC_ALL
init|=
name|CPU_SUBTYPE_SPARC_ALL
block|,
name|HDR_CPU_SUBTYPE_POWERPC_ALL
init|=
name|CPU_SUBTYPE_POWERPC_ALL
block|}
enum|;
name|TargetMachOWriterInfo
argument_list|(
argument|uint32_t cputype
argument_list|,
argument|uint32_t cpusubtype
argument_list|)
block|:
name|CPUType
argument_list|(
name|cputype
argument_list|)
operator|,
name|CPUSubType
argument_list|(
argument|cpusubtype
argument_list|)
block|{}
name|virtual
operator|~
name|TargetMachOWriterInfo
argument_list|()
expr_stmt|;
name|virtual
name|MachineRelocation
name|GetJTRelocation
argument_list|(
name|unsigned
name|Offset
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|unsigned
name|GetTargetRelocation
argument_list|(
name|MachineRelocation
operator|&
name|MR
argument_list|,
name|unsigned
name|FromIdx
argument_list|,
name|unsigned
name|ToAddr
argument_list|,
name|unsigned
name|ToIdx
argument_list|,
name|OutputBuffer
operator|&
name|RelocOut
argument_list|,
name|OutputBuffer
operator|&
name|SecOut
argument_list|,
name|bool
name|Scattered
argument_list|,
name|bool
name|Extern
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
name|uint32_t
name|getCPUType
argument_list|()
specifier|const
block|{
return|return
name|CPUType
return|;
block|}
name|uint32_t
name|getCPUSubType
argument_list|()
specifier|const
block|{
return|return
name|CPUSubType
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_TARGETMACHOWRITERINFO_H
end_comment

end_unit

