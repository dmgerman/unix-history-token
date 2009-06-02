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
enum|enum
name|MachineType
block|{
name|NoMachine
block|,
name|EM_386
init|=
literal|3
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

