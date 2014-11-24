begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AArch64.h - Top-level interface for AArch64  --------------*- C++ -*-==//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// AArch64 back-end.
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
name|TARGET_AArch64_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_AArch64_H
end_define

begin_include
include|#
directive|include
file|"Utils/AArch64BaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/AArch64MCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64TargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MachineFunctionPass
decl_stmt|;
name|FunctionPass
modifier|*
name|createAArch64DeadRegisterDefinitions
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64ConditionalCompares
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64AdvSIMDScalar
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64BranchRelaxation
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64ISelDag
argument_list|(
name|AArch64TargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
name|FunctionPass
modifier|*
name|createAArch64StorePairSuppressPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64ExpandPseudoPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64LoadStoreOptimizationPass
parameter_list|()
function_decl|;
name|ModulePass
modifier|*
name|createAArch64PromoteConstantPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64AddressTypePromotionPass
parameter_list|()
function_decl|;
comment|/// \brief Creates an ARM-specific Target Transformation Info pass.
name|ImmutablePass
modifier|*
name|createAArch64TargetTransformInfoPass
parameter_list|(
specifier|const
name|AArch64TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64CleanupLocalDynamicTLSPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAArch64CollectLOHPass
parameter_list|()
function_decl|;
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

