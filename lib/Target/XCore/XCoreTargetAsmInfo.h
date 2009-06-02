begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- XCoreTargetAsmInfo.h - XCore asm properties ---------*- C++ -*--====//
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
comment|// This file contains the declaration of the XCoreTargetAsmInfo class.
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
name|XCORETARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|XCORETARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/ELFTargetAsmInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|XCoreTargetMachine
decl_stmt|;
name|class
name|XCoreSubtarget
decl_stmt|;
name|class
name|XCoreTargetAsmInfo
range|:
name|public
name|ELFTargetAsmInfo
block|{
name|private
operator|:
specifier|const
name|XCoreSubtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|XCoreTargetAsmInfo
argument_list|(
specifier|const
name|XCoreTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
specifier|const
name|Section
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
name|virtual
name|std
operator|::
name|string
name|printSectionFlags
argument_list|(
argument|unsigned flags
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|MergeableConstSection
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|inline
specifier|const
name|Section
operator|*
name|MergeableConstSection
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|MergeableStringSection
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|Section
operator|*
name|SelectSectionForMachineConst
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|SectionFlagsForGlobal
argument_list|(
argument|const GlobalValue *GV = NULL
argument_list|,
argument|const char* name = NULL
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

