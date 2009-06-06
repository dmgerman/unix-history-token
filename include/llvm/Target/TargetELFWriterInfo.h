begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetELFWriterInfo.h - ELF Writer Info -----*- C++ -*-===//
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
comment|// This file defines the TargetELFWriterInfo class.
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
name|LLVM_TARGET_TARGETELFWRITERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETELFWRITERINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===--------------------------------------------------------------------===//
comment|//                          TargetELFWriterInfo
comment|//===--------------------------------------------------------------------===//
name|class
name|TargetELFWriterInfo
block|{
comment|// EMachine - This field is the target specific value to emit as the
comment|// e_machine member of the ELF header.
name|unsigned
name|short
name|EMachine
decl_stmt|;
name|public
label|:
comment|// Machine architectures
enum|enum
name|MachineType
block|{
name|EM_NONE
init|=
literal|0
block|,
comment|// No machine
name|EM_M32
init|=
literal|1
block|,
comment|// AT&T WE 32100
name|EM_SPARC
init|=
literal|2
block|,
comment|// SPARC
name|EM_386
init|=
literal|3
block|,
comment|// Intel 386
name|EM_68K
init|=
literal|4
block|,
comment|// Motorola 68000
name|EM_88K
init|=
literal|5
block|,
comment|// Motorola 88000
name|EM_486
init|=
literal|6
block|,
comment|// Intel 486 (deprecated)
name|EM_860
init|=
literal|7
block|,
comment|// Intel 80860
name|EM_MIPS
init|=
literal|8
block|,
comment|// MIPS R3000
name|EM_PPC
init|=
literal|20
block|,
comment|// PowerPC
name|EM_ARM
init|=
literal|40
block|,
comment|// ARM
name|EM_ALPHA
init|=
literal|41
block|,
comment|// DEC Alpha
name|EM_SPARCV9
init|=
literal|43
block|,
comment|// SPARC V9
name|EM_X86_64
init|=
literal|62
comment|// AMD64
block|}
enum|;
name|explicit
name|TargetELFWriterInfo
argument_list|(
argument|MachineType machine
argument_list|)
block|:
name|EMachine
argument_list|(
argument|machine
argument_list|)
block|{}
name|virtual
operator|~
name|TargetELFWriterInfo
argument_list|()
block|{}
name|unsigned
name|short
name|getEMachine
argument_list|()
specifier|const
block|{
return|return
name|EMachine
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
comment|// LLVM_TARGET_TARGETELFWRITERINFO_H
end_comment

end_unit

