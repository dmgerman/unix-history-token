begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SDDbgValue.h - SD dbg_value handling--------*- C++ -*-===//
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
comment|// This file declares the SDDbgValue class.
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
name|LLVM_CODEGEN_SDDBGVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SDDBGVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MDNode
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// SDDbgValue - Holds the information from a dbg_value node through SDISel.
comment|/// Either Const or Node is nonzero, but not both.
comment|/// We do not use SDValue here to avoid including its header.
name|class
name|SDDbgValue
block|{
name|SDNode
modifier|*
name|Node
decl_stmt|;
comment|// valid for non-constants
name|unsigned
name|ResNo
decl_stmt|;
comment|// valid for non-constants
name|Value
modifier|*
name|Const
decl_stmt|;
comment|// valid for constants
name|MDNode
modifier|*
name|mdPtr
decl_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
name|DebugLoc
name|DL
decl_stmt|;
name|unsigned
name|Order
decl_stmt|;
name|public
label|:
comment|// Constructor for non-constants.
name|SDDbgValue
argument_list|(
argument|MDNode *mdP
argument_list|,
argument|SDNode *N
argument_list|,
argument|unsigned R
argument_list|,
argument|uint64_t off
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned O
argument_list|)
block|:
name|Node
argument_list|(
name|N
argument_list|)
operator|,
name|ResNo
argument_list|(
name|R
argument_list|)
operator|,
name|Const
argument_list|(
literal|0
argument_list|)
operator|,
name|mdPtr
argument_list|(
name|mdP
argument_list|)
operator|,
name|Offset
argument_list|(
name|off
argument_list|)
operator|,
name|DL
argument_list|(
name|dl
argument_list|)
operator|,
name|Order
argument_list|(
argument|O
argument_list|)
block|{}
comment|// Constructor for constants.
name|SDDbgValue
argument_list|(
argument|MDNode *mdP
argument_list|,
argument|Value *C
argument_list|,
argument|uint64_t off
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned O
argument_list|)
operator|:
name|Node
argument_list|(
literal|0
argument_list|)
operator|,
name|ResNo
argument_list|(
literal|0
argument_list|)
operator|,
name|Const
argument_list|(
name|C
argument_list|)
operator|,
name|mdPtr
argument_list|(
name|mdP
argument_list|)
operator|,
name|Offset
argument_list|(
name|off
argument_list|)
operator|,
name|DL
argument_list|(
name|dl
argument_list|)
operator|,
name|Order
argument_list|(
argument|O
argument_list|)
block|{}
comment|// Returns the MDNode pointer.
name|MDNode
operator|*
name|getMDPtr
argument_list|()
block|{
return|return
name|mdPtr
return|;
block|}
comment|// Returns the SDNode* (valid for non-constants only).
name|SDNode
modifier|*
name|getSDNode
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|Const
argument_list|)
expr_stmt|;
return|return
name|Node
return|;
block|}
comment|// Returns the ResNo (valid for non-constants only).
name|unsigned
name|getResNo
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|Const
argument_list|)
expr_stmt|;
return|return
name|ResNo
return|;
block|}
comment|// Returns the Value* for a constant (invalid for non-constants).
name|Value
modifier|*
name|getConst
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|Node
argument_list|)
expr_stmt|;
return|return
name|Const
return|;
block|}
comment|// Returns the offset.
name|uint64_t
name|getOffset
parameter_list|()
block|{
return|return
name|Offset
return|;
block|}
comment|// Returns the DebugLoc.
name|DebugLoc
name|getDebugLoc
parameter_list|()
block|{
return|return
name|DL
return|;
block|}
comment|// Returns the SDNodeOrder.  This is the order of the preceding node in the
comment|// input.
name|unsigned
name|getOrder
parameter_list|()
block|{
return|return
name|Order
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

