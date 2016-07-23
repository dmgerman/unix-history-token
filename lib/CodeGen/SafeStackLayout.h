begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SafeStackLayout.h - SafeStack frame layout -------------*- C++ -*--===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_CODEGEN_SAFESTACKLAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_SAFESTACKLAYOUT_H
end_define

begin_include
include|#
directive|include
file|"SafeStackColoring.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|safestack
block|{
comment|/// Compute the layout of an unsafe stack frame.
name|class
name|StackLayout
block|{
name|unsigned
name|MaxAlignment
decl_stmt|;
struct|struct
name|StackRegion
block|{
name|unsigned
name|Start
decl_stmt|;
name|unsigned
name|End
decl_stmt|;
name|StackColoring
operator|::
name|LiveRange
name|Range
expr_stmt|;
name|StackRegion
argument_list|(
argument|unsigned Start
argument_list|,
argument|unsigned End
argument_list|,
argument|const StackColoring::LiveRange&Range
argument_list|)
block|:
name|Start
argument_list|(
name|Start
argument_list|)
operator|,
name|End
argument_list|(
name|End
argument_list|)
operator|,
name|Range
argument_list|(
argument|Range
argument_list|)
block|{}
block|}
struct|;
comment|/// The list of current stack regions, sorted by StackRegion::Start.
name|SmallVector
operator|<
name|StackRegion
operator|,
literal|16
operator|>
name|Regions
expr_stmt|;
struct|struct
name|StackObject
block|{
specifier|const
name|Value
modifier|*
name|Handle
decl_stmt|;
name|unsigned
name|Size
decl_stmt|,
name|Alignment
decl_stmt|;
name|StackColoring
operator|::
name|LiveRange
name|Range
expr_stmt|;
block|}
struct|;
name|SmallVector
operator|<
name|StackObject
operator|,
literal|8
operator|>
name|StackObjects
expr_stmt|;
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|unsigned
operator|>
name|ObjectOffsets
expr_stmt|;
name|void
name|layoutObject
parameter_list|(
name|StackObject
modifier|&
name|Obj
parameter_list|)
function_decl|;
name|public
label|:
name|StackLayout
argument_list|(
argument|unsigned StackAlignment
argument_list|)
block|:
name|MaxAlignment
argument_list|(
argument|StackAlignment
argument_list|)
block|{}
comment|/// Add an object to the stack frame. Value pointer is opaque and used as a
comment|/// handle to retrieve the object's offset in the frame later.
name|void
name|addObject
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
name|unsigned
name|Size
argument_list|,
name|unsigned
name|Alignment
argument_list|,
specifier|const
name|StackColoring
operator|::
name|LiveRange
operator|&
name|Range
argument_list|)
decl_stmt|;
comment|/// Run the layout computation for all previously added objects.
name|void
name|computeLayout
parameter_list|()
function_decl|;
comment|/// Returns the offset to the object start in the stack frame.
name|unsigned
name|getObjectOffset
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|ObjectOffsets
index|[
name|V
index|]
return|;
block|}
comment|/// Returns the size of the entire frame.
name|unsigned
name|getFrameSize
parameter_list|()
block|{
return|return
name|Regions
operator|.
name|empty
argument_list|()
condition|?
literal|0
else|:
name|Regions
operator|.
name|back
argument_list|()
operator|.
name|End
return|;
block|}
comment|/// Returns the alignment of the frame.
name|unsigned
name|getFrameAlignment
parameter_list|()
block|{
return|return
name|MaxAlignment
return|;
block|}
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// namespace safestack
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_CODEGEN_SAFESTACKLAYOUT_H
end_comment

end_unit

