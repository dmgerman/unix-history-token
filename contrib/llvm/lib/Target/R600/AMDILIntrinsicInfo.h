begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDILIntrinsicInfo.h - AMDGPU Intrinsic Information ------*- C++ -*-===//
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
comment|//==-----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Interface for the AMDGPU Implementation of the Intrinsic Info class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===-----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDIL_INTRINSICS_H
end_ifndef

begin_define
define|#
directive|define
name|AMDIL_INTRINSICS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Intrinsics.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetIntrinsicInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetMachine
decl_stmt|;
name|namespace
name|AMDGPUIntrinsic
block|{
enum|enum
name|ID
block|{
name|last_non_AMDGPU_intrinsic
init|=
name|Intrinsic
operator|::
name|num_intrinsics
operator|-
literal|1
block|,
define|#
directive|define
name|GET_INTRINSIC_ENUM_VALUES
include|#
directive|include
file|"AMDGPUGenIntrinsics.inc"
undef|#
directive|undef
name|GET_INTRINSIC_ENUM_VALUES
block|,
name|num_AMDGPU_intrinsics
block|}
enum|;
block|}
comment|// end namespace AMDGPUIntrinsic
name|class
name|AMDGPUIntrinsicInfo
range|:
name|public
name|TargetIntrinsicInfo
block|{
name|public
operator|:
name|AMDGPUIntrinsicInfo
argument_list|(
name|TargetMachine
operator|*
name|tm
argument_list|)
block|;
name|std
operator|::
name|string
name|getName
argument_list|(
argument|unsigned int IntrId
argument_list|,
argument|Type **Tys =
literal|0
argument_list|,
argument|unsigned int numTys =
literal|0
argument_list|)
specifier|const
block|;
name|unsigned
name|int
name|lookupName
argument_list|(
argument|const char *Name
argument_list|,
argument|unsigned int Len
argument_list|)
specifier|const
block|;
name|bool
name|isOverloaded
argument_list|(
argument|unsigned int IID
argument_list|)
specifier|const
block|;
name|Function
operator|*
name|getDeclaration
argument_list|(
argument|Module *M
argument_list|,
argument|unsigned int ID
argument_list|,
argument|Type **Tys =
literal|0
argument_list|,
argument|unsigned int numTys =
literal|0
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDIL_INTRINSICS_H
end_comment

end_unit

