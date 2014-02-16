begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- Mips16HardFloat.h for Mips16 Hard Float                  --------===//
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
comment|// This file defines a phase which implements part of the floating point
end_comment

begin_comment
comment|// interoperability between Mips16 and Mips32 code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"MipsTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS16HARDFLOAT_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS16HARDFLOAT_H
end_define

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Mips16HardFloat
range|:
name|public
name|ModulePass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|Mips16HardFloat
argument_list|(
name|MipsTargetMachine
operator|&
name|TM_
argument_list|)
operator|:
name|ModulePass
argument_list|(
name|ID
argument_list|)
block|,
name|TM
argument_list|(
name|TM_
argument_list|)
block|,
name|Subtarget
argument_list|(
argument|TM.getSubtarget<MipsSubtarget>()
argument_list|)
block|{   }
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"MIPS16 Hard Float Pass"
return|;
block|}
name|virtual
name|bool
name|runOnModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|protected
operator|:
comment|/// Keep a pointer to the MipsSubtarget around so that we can make the right
comment|/// decision when generating code for different targets.
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
block|;  }
decl_stmt|;
name|ModulePass
modifier|*
name|createMips16HardFloat
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

