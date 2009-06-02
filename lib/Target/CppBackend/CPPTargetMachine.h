begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CPPTargetMachine.h - TargetMachine for the C++ backend --*- C++ -*-===//
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
comment|// This file declares the TargetMachine that is used by the C++ backend.
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
name|CPPTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|CPPTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetData.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|struct
name|CPPTargetMachine
range|:
name|public
name|TargetMachine
block|{
specifier|const
name|TargetData
name|DataLayout
block|;
comment|// Calculates type size& alignment
name|CPPTargetMachine
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|)
operator|:
name|DataLayout
argument_list|(
argument|&M
argument_list|)
block|{}
name|virtual
name|bool
name|WantsWholeFile
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|addPassesToEmitWholeFile
argument_list|(
argument|PassManager&PM
argument_list|,
argument|raw_ostream&Out
argument_list|,
argument|CodeGenFileType FileType
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
comment|// This class always works, but shouldn't be the default in most cases.
specifier|static
name|unsigned
name|getModuleMatchQuality
argument_list|(
argument|const Module&M
argument_list|)
block|{
return|return
literal|1
return|;
block|}
name|virtual
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DataLayout
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

