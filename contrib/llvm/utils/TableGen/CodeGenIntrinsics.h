begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGenIntrinsic.h - Intrinsic Class Wrapper ------------*- C++ -*--===//
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
comment|// This file defines a wrapper class for the 'Intrinsic' TableGen class.
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
name|CODEGEN_INTRINSIC_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_INTRINSIC_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Record
decl_stmt|;
name|class
name|RecordKeeper
decl_stmt|;
name|class
name|CodeGenTarget
decl_stmt|;
struct|struct
name|CodeGenIntrinsic
block|{
name|Record
modifier|*
name|TheDef
decl_stmt|;
comment|// The actual record defining this intrinsic.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|// The name of the LLVM function "llvm.bswap.i32"
name|std
operator|::
name|string
name|EnumName
expr_stmt|;
comment|// The name of the enum "bswap_i32"
name|std
operator|::
name|string
name|GCCBuiltinName
expr_stmt|;
comment|// Name of the corresponding GCC builtin, or "".
name|std
operator|::
name|string
name|TargetPrefix
expr_stmt|;
comment|// Target prefix, e.g. "ppc" for t-s intrinsics.
comment|/// IntrinsicSignature - This structure holds the return values and
comment|/// parameter values of an intrinsic. If the number of return values is> 1,
comment|/// then the intrinsic implicitly returns a first-class aggregate. The
comment|/// numbering of the types starts at 0 with the first return value and
comment|/// continues from there through the parameter list. This is useful for
comment|/// "matching" types.
struct|struct
name|IntrinsicSignature
block|{
comment|/// RetVTs - The MVT::SimpleValueType for each return type. Note that this
comment|/// list is only populated when in the context of a target .td file. When
comment|/// building Intrinsics.td, this isn't available, because we don't know
comment|/// the target pointer size.
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|RetVTs
expr_stmt|;
comment|/// RetTypeDefs - The records for each return type.
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|RetTypeDefs
expr_stmt|;
comment|/// ParamVTs - The MVT::SimpleValueType for each parameter type. Note that
comment|/// this list is only populated when in the context of a target .td file.
comment|/// When building Intrinsics.td, this isn't available, because we don't
comment|/// know the target pointer size.
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|ParamVTs
expr_stmt|;
comment|/// ParamTypeDefs - The records for each parameter type.
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|ParamTypeDefs
expr_stmt|;
block|}
struct|;
name|IntrinsicSignature
name|IS
decl_stmt|;
comment|// Memory mod/ref behavior of this intrinsic.
enum|enum
block|{
name|NoMem
block|,
name|ReadArgMem
block|,
name|ReadMem
block|,
name|ReadWriteArgMem
block|,
name|ReadWriteMem
block|}
name|ModRef
enum|;
comment|/// This is set to true if the intrinsic is overloaded by its argument
comment|/// types.
name|bool
name|isOverloaded
decl_stmt|;
comment|/// isCommutative - True if the intrinsic is commutative.
name|bool
name|isCommutative
decl_stmt|;
comment|/// canThrow - True if the intrinsic can throw.
name|bool
name|canThrow
decl_stmt|;
comment|/// isNoReturn - True if the intrinsic is no-return.
name|bool
name|isNoReturn
decl_stmt|;
enum|enum
name|ArgAttribute
block|{
name|NoCapture
block|,
name|ReadOnly
block|,
name|ReadNone
block|}
enum|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|ArgAttribute
operator|>
expr|>
name|ArgumentAttributes
expr_stmt|;
name|CodeGenIntrinsic
argument_list|(
name|Record
operator|*
name|R
argument_list|)
expr_stmt|;
block|}
struct|;
comment|/// LoadIntrinsics - Read all of the intrinsics defined in the specified
comment|/// .td file.
name|std
operator|::
name|vector
operator|<
name|CodeGenIntrinsic
operator|>
name|LoadIntrinsics
argument_list|(
argument|const RecordKeeper&RC
argument_list|,
argument|bool TargetOnly
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

