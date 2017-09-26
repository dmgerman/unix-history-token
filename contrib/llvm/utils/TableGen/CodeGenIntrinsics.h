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
name|LLVM_UTILS_TABLEGEN_CODEGENINTRINSICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_CODEGENINTRINSICS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
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
name|MSBuiltinName
expr_stmt|;
comment|// Name of the corresponding MS builtin, or "".
name|std
operator|::
name|string
name|TargetPrefix
expr_stmt|;
comment|// Target prefix, e.g. "ppc" for t-s intrinsics.
comment|/// This structure holds the return values and parameter values of an
comment|/// intrinsic. If the number of return values is> 1, then the intrinsic
comment|/// implicitly returns a first-class aggregate. The numbering of the types
comment|/// starts at 0 with the first return value and continues from there through
comment|/// the parameter list. This is useful for "matching" types.
struct|struct
name|IntrinsicSignature
block|{
comment|/// The MVT::SimpleValueType for each return type. Note that this list is
comment|/// only populated when in the context of a target .td file. When building
comment|/// Intrinsics.td, this isn't available, because we don't know the target
comment|/// pointer size.
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
comment|/// The records for each return type.
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|RetTypeDefs
expr_stmt|;
comment|/// The MVT::SimpleValueType for each parameter type. Note that this list is
comment|/// only populated when in the context of a target .td file.  When building
comment|/// Intrinsics.td, this isn't available, because we don't know the target
comment|/// pointer size.
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
comment|/// The records for each parameter type.
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
comment|/// Bit flags describing the type (ref/mod) and location of memory
comment|/// accesses that may be performed by the intrinsics. Analogous to
comment|/// \c FunctionModRefBehaviour.
enum|enum
name|ModRefBits
block|{
comment|/// The intrinsic may access memory that is otherwise inaccessible via
comment|/// LLVM IR.
name|MR_InaccessibleMem
init|=
literal|1
block|,
comment|/// The intrinsic may access memory through pointer arguments.
comment|/// LLVM IR.
name|MR_ArgMem
init|=
literal|2
block|,
comment|/// The intrinsic may access memory anywhere, i.e. it is not restricted
comment|/// to access through pointer arguments.
name|MR_Anywhere
init|=
literal|4
operator||
name|MR_ArgMem
operator||
name|MR_InaccessibleMem
block|,
comment|/// The intrinsic may read memory.
name|MR_Ref
init|=
literal|8
block|,
comment|/// The intrinsic may write memory.
name|MR_Mod
init|=
literal|16
block|,
comment|/// The intrinsic may both read and write memory.
name|MR_ModRef
init|=
name|MR_Ref
operator||
name|MR_Mod
block|,   }
enum|;
comment|/// Memory mod/ref behavior of this intrinsic, corresponding to intrinsic
comment|/// properties (IntrReadMem, IntrArgMemOnly, etc.).
enum|enum
name|ModRefBehavior
block|{
name|NoMem
init|=
literal|0
block|,
name|ReadArgMem
init|=
name|MR_Ref
operator||
name|MR_ArgMem
block|,
name|ReadInaccessibleMem
init|=
name|MR_Ref
operator||
name|MR_InaccessibleMem
block|,
name|ReadInaccessibleMemOrArgMem
init|=
name|MR_Ref
operator||
name|MR_ArgMem
operator||
name|MR_InaccessibleMem
block|,
name|ReadMem
init|=
name|MR_Ref
operator||
name|MR_Anywhere
block|,
name|WriteArgMem
init|=
name|MR_Mod
operator||
name|MR_ArgMem
block|,
name|WriteInaccessibleMem
init|=
name|MR_Mod
operator||
name|MR_InaccessibleMem
block|,
name|WriteInaccessibleMemOrArgMem
init|=
name|MR_Mod
operator||
name|MR_ArgMem
operator||
name|MR_InaccessibleMem
block|,
name|WriteMem
init|=
name|MR_Mod
operator||
name|MR_Anywhere
block|,
name|ReadWriteArgMem
init|=
name|MR_ModRef
operator||
name|MR_ArgMem
block|,
name|ReadWriteInaccessibleMem
init|=
name|MR_ModRef
operator||
name|MR_InaccessibleMem
block|,
name|ReadWriteInaccessibleMemOrArgMem
init|=
name|MR_ModRef
operator||
name|MR_ArgMem
operator||
name|MR_InaccessibleMem
block|,
name|ReadWriteMem
init|=
name|MR_ModRef
operator||
name|MR_Anywhere
block|,   }
enum|;
name|ModRefBehavior
name|ModRef
decl_stmt|;
comment|/// This is set to true if the intrinsic is overloaded by its argument
comment|/// types.
name|bool
name|isOverloaded
decl_stmt|;
comment|/// True if the intrinsic is commutative.
name|bool
name|isCommutative
decl_stmt|;
comment|/// True if the intrinsic can throw.
name|bool
name|canThrow
decl_stmt|;
comment|/// True if the intrinsic is marked as noduplicate.
name|bool
name|isNoDuplicate
decl_stmt|;
comment|/// True if the intrinsic is no-return.
name|bool
name|isNoReturn
decl_stmt|;
comment|/// True if the intrinsic is marked as convergent.
name|bool
name|isConvergent
decl_stmt|;
comment|/// True if the intrinsic has side effects that aren't captured by any
comment|/// of the other flags.
name|bool
name|hasSideEffects
decl_stmt|;
comment|// True if the intrinsic is marked as speculatable.
name|bool
name|isSpeculatable
decl_stmt|;
enum|enum
name|ArgAttribute
block|{
name|NoCapture
block|,
name|Returned
block|,
name|ReadOnly
block|,
name|WriteOnly
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
operator|>>
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
name|class
name|CodeGenIntrinsicTable
block|{
name|std
operator|::
name|vector
operator|<
name|CodeGenIntrinsic
operator|>
name|Intrinsics
expr_stmt|;
name|public
label|:
struct|struct
name|TargetSet
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|size_t
name|Offset
decl_stmt|;
name|size_t
name|Count
decl_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|TargetSet
operator|>
name|Targets
expr_stmt|;
name|explicit
name|CodeGenIntrinsicTable
parameter_list|(
specifier|const
name|RecordKeeper
modifier|&
name|RC
parameter_list|,
name|bool
name|TargetOnly
parameter_list|)
function_decl|;
name|CodeGenIntrinsicTable
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Intrinsics
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Intrinsics
operator|.
name|size
argument_list|()
return|;
block|}
name|CodeGenIntrinsic
modifier|&
name|operator
function|[]
parameter_list|(
name|size_t
name|Pos
parameter_list|)
block|{
return|return
name|Intrinsics
index|[
name|Pos
index|]
return|;
block|}
specifier|const
name|CodeGenIntrinsic
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|Pos
argument_list|)
decl|const
block|{
return|return
name|Intrinsics
index|[
name|Pos
index|]
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

