begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/VectorUtils.h - Vector utilities -*- C++ -*-=====//
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
comment|// This file defines some vectorizer utilities.
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
name|LLVM_TRANSFORMS_UTILS_VECTORUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_VECTORUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Intrinsics.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Identify if the intrinsic is trivially vectorizable.
comment|/// This method returns true if the intrinsic's argument types are all
comment|/// scalars for the scalar form of the intrinsic and all vectors for
comment|/// the vector form of the intrinsic.
name|bool
name|isTriviallyVectorizable
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief Identifies if the intrinsic has a scalar operand. It checks for
comment|/// ctlz,cttz and powi special intrinsics whose argument is scalar.
name|bool
name|hasVectorInstrinsicScalarOpd
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|,
name|unsigned
name|ScalarOpdIdx
argument_list|)
decl_stmt|;
comment|/// \brief Identify if call has a unary float signature
comment|/// It returns input intrinsic ID if call has a single argument,
comment|/// argument type and call instruction type should be floating
comment|/// point type and call should only reads memory.
comment|/// else return not_intrinsic.
name|Intrinsic
operator|::
name|ID
name|checkUnaryFloatSignature
argument_list|(
argument|const CallInst&I
argument_list|,
argument|Intrinsic::ID ValidIntrinsicID
argument_list|)
expr_stmt|;
comment|/// \brief Identify if call has a binary float signature
comment|/// It returns input intrinsic ID if call has two arguments,
comment|/// arguments type and call instruction type should be floating
comment|/// point type and call should only reads memory.
comment|/// else return not_intrinsic.
name|Intrinsic
operator|::
name|ID
name|checkBinaryFloatSignature
argument_list|(
argument|const CallInst&I
argument_list|,
argument|Intrinsic::ID ValidIntrinsicID
argument_list|)
expr_stmt|;
comment|/// \brief Returns intrinsic ID for call.
comment|/// For the input call instruction it finds mapping intrinsic and returns
comment|/// its intrinsic ID, in case it does not found it return not_intrinsic.
name|Intrinsic
operator|::
name|ID
name|getIntrinsicIDForCall
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

