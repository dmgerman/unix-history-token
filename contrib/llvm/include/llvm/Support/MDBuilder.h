begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/Support/MDBuilder.h - Builder for LLVM metadata --*- C++ -*-===//
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
comment|// This file defines the MDBuilder class, which is used as a convenient way to
end_comment

begin_comment
comment|// create LLVM metadata with a consistent and simplified interface.
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
name|LLVM_SUPPORT_MDBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MDBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Constants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MDBuilder
block|{
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
name|public
label|:
name|MDBuilder
argument_list|(
name|LLVMContext
operator|&
name|context
argument_list|)
operator|:
name|Context
argument_list|(
argument|context
argument_list|)
block|{}
comment|/// \brief Return the given string as metadata.
name|MDString
operator|*
name|createString
argument_list|(
argument|StringRef Str
argument_list|)
block|{
return|return
name|MDString
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Str
argument_list|)
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// FPMath metadata.
comment|//===------------------------------------------------------------------===//
comment|/// \brief Return metadata with the given settings.  The special value 0.0
comment|/// for the Accuracy parameter indicates the default (maximal precision)
comment|/// setting.
name|MDNode
modifier|*
name|createFPMath
parameter_list|(
name|float
name|Accuracy
parameter_list|)
block|{
if|if
condition|(
name|Accuracy
operator|==
literal|0.0
condition|)
return|return
literal|0
return|;
name|assert
argument_list|(
name|Accuracy
operator|>
literal|0.0
operator|&&
literal|"Invalid fpmath accuracy!"
argument_list|)
expr_stmt|;
name|Value
modifier|*
name|Op
init|=
name|ConstantFP
operator|::
name|get
argument_list|(
name|Type
operator|::
name|getFloatTy
argument_list|(
name|Context
argument_list|)
argument_list|,
name|Accuracy
argument_list|)
decl_stmt|;
return|return
name|MDNode
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Op
argument_list|)
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Range metadata.
comment|//===------------------------------------------------------------------===//
comment|/// \brief Return metadata describing the range [Lo, Hi).
name|MDNode
modifier|*
name|createRange
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Lo
parameter_list|,
specifier|const
name|APInt
modifier|&
name|Hi
parameter_list|)
block|{
name|assert
argument_list|(
name|Lo
operator|.
name|getBitWidth
argument_list|()
operator|==
name|Hi
operator|.
name|getBitWidth
argument_list|()
operator|&&
literal|"Mismatched bitwidths!"
argument_list|)
expr_stmt|;
comment|// If the range is everything then it is useless.
if|if
condition|(
name|Hi
operator|==
name|Lo
condition|)
return|return
literal|0
return|;
comment|// Return the range [Lo, Hi).
name|Type
modifier|*
name|Ty
init|=
name|IntegerType
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Lo
operator|.
name|getBitWidth
argument_list|()
argument_list|)
decl_stmt|;
name|Value
modifier|*
name|Range
index|[
literal|2
index|]
init|=
block|{
name|ConstantInt
operator|::
name|get
argument_list|(
name|Ty
argument_list|,
name|Lo
argument_list|)
block|,
name|ConstantInt
operator|::
name|get
argument_list|(
argument|Ty
argument_list|,
argument|Hi
argument_list|)
block|}
decl_stmt|;
return|return
name|MDNode
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Range
argument_list|)
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// TBAA metadata.
comment|//===------------------------------------------------------------------===//
comment|/// \brief Return metadata appropriate for a TBAA root node.  Each returned
comment|/// node is distinct from all other metadata and will never be identified
comment|/// (uniqued) with anything else.
name|MDNode
modifier|*
name|createAnonymousTBAARoot
parameter_list|()
block|{
comment|// To ensure uniqueness the root node is self-referential.
name|MDNode
modifier|*
name|Dummy
init|=
name|MDNode
operator|::
name|getTemporary
argument_list|(
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
name|MDNode
modifier|*
name|Root
init|=
name|MDNode
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Dummy
argument_list|)
decl_stmt|;
comment|// At this point we have
comment|//   !0 = metadata !{}<- dummy
comment|//   !1 = metadata !{metadata !0}<- root
comment|// Replace the dummy operand with the root node itself and delete the dummy.
name|Root
operator|->
name|replaceOperandWith
argument_list|(
literal|0
argument_list|,
name|Root
argument_list|)
expr_stmt|;
name|MDNode
operator|::
name|deleteTemporary
argument_list|(
name|Dummy
argument_list|)
expr_stmt|;
comment|// We now have
comment|//   !1 = metadata !{metadata !1}<- self-referential root
return|return
name|Root
return|;
block|}
comment|/// \brief Return metadata appropriate for a TBAA root node with the given
comment|/// name.  This may be identified (uniqued) with other roots with the same
comment|/// name.
name|MDNode
modifier|*
name|createTBAARoot
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
return|return
name|MDNode
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|createString
argument_list|(
name|Name
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Return metadata for a non-root TBAA node with the given name,
comment|/// parent in the TBAA tree, and value for 'pointsToConstantMemory'.
name|MDNode
modifier|*
name|createTBAANode
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|MDNode
modifier|*
name|Parent
parameter_list|,
name|bool
name|isConstant
init|=
name|false
parameter_list|)
block|{
if|if
condition|(
name|isConstant
condition|)
block|{
name|Constant
modifier|*
name|Flags
init|=
name|ConstantInt
operator|::
name|get
argument_list|(
name|Type
operator|::
name|getInt64Ty
argument_list|(
name|Context
argument_list|)
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|Value
modifier|*
name|Ops
index|[
literal|3
index|]
init|=
block|{
name|createString
argument_list|(
name|Name
argument_list|)
block|,
name|Parent
block|,
name|Flags
block|}
decl_stmt|;
return|return
name|MDNode
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Ops
argument_list|)
return|;
block|}
else|else
block|{
name|Value
modifier|*
name|Ops
index|[
literal|2
index|]
init|=
block|{
name|createString
argument_list|(
name|Name
argument_list|)
block|,
name|Parent
block|}
decl_stmt|;
return|return
name|MDNode
operator|::
name|get
argument_list|(
name|Context
argument_list|,
name|Ops
argument_list|)
return|;
block|}
block|}
block|}
empty_stmt|;
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

