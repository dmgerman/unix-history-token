begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- MipsOs16.h for Mips Option -Os16                         --------===//
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
comment|// This file defines an optimization phase for the MIPS target.
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
name|LLVM_LIB_TARGET_MIPS_MIPSOS16_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSOS16_H
end_define

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
name|MipsOs16
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
name|MipsOs16
argument_list|()
operator|:
name|ModulePass
argument_list|(
argument|ID
argument_list|)
block|{    }
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"MIPS Os16 Optimization"
return|;
block|}
name|bool
name|runOnModule
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;  }
decl_stmt|;
name|ModulePass
modifier|*
name|createMipsOs16
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

