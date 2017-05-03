begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Bitcode/Reader/ValueEnumerator.h - Number values --------*- C++ -*-===//
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
comment|// This class gives values and types Unique ID's.
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
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
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
name|Constant
decl_stmt|;
name|class
name|BitcodeReaderValueList
block|{
name|std
operator|::
name|vector
operator|<
name|WeakTrackingVH
operator|>
name|ValuePtrs
expr_stmt|;
comment|/// As we resolve forward-referenced constants, we add information about them
comment|/// to this vector.  This allows us to resolve them in bulk instead of
comment|/// resolving each reference at a time.  See the code in
comment|/// ResolveConstantForwardRefs for more information about this.
comment|///
comment|/// The key of this vector is the placeholder constant, the value is the slot
comment|/// number that holds the resolved value.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|Constant
operator|*
operator|,
name|unsigned
operator|>>
name|ResolveConstantsTy
expr_stmt|;
name|ResolveConstantsTy
name|ResolveConstants
decl_stmt|;
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
name|public
label|:
name|BitcodeReaderValueList
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|Context
argument_list|(
argument|C
argument_list|)
block|{}
operator|~
name|BitcodeReaderValueList
argument_list|()
block|{
name|assert
argument_list|(
name|ResolveConstants
operator|.
name|empty
argument_list|()
operator|&&
literal|"Constants not resolved?"
argument_list|)
block|;   }
comment|// vector compatibility methods
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|ValuePtrs
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|resize
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|ValuePtrs
operator|.
name|resize
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
name|void
name|push_back
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
name|ValuePtrs
operator|.
name|emplace_back
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|assert
argument_list|(
name|ResolveConstants
operator|.
name|empty
argument_list|()
operator|&&
literal|"Constants not resolved?"
argument_list|)
expr_stmt|;
name|ValuePtrs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|Value
modifier|*
name|operator
index|[]
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|ValuePtrs
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ValuePtrs
index|[
name|i
index|]
return|;
block|}
name|Value
operator|*
name|back
argument_list|()
specifier|const
block|{
return|return
name|ValuePtrs
operator|.
name|back
argument_list|()
return|;
block|}
name|void
name|pop_back
parameter_list|()
block|{
name|ValuePtrs
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|ValuePtrs
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|shrinkTo
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|N
operator|<=
name|size
argument_list|()
operator|&&
literal|"Invalid shrinkTo request!"
argument_list|)
expr_stmt|;
name|ValuePtrs
operator|.
name|resize
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
name|Constant
modifier|*
name|getConstantFwdRef
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|Value
modifier|*
name|getValueFwdRef
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|void
name|assignValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|unsigned
name|Idx
parameter_list|)
function_decl|;
comment|/// Once all constants are read, this method bulk resolves any forward
comment|/// references.
name|void
name|resolveConstantForwardRefs
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

end_unit

