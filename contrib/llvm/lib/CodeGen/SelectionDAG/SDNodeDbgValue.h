begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SDNodeDbgValue.h - SelectionDAG dbg_value --*- C++ -*-===//
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
name|LLVM_CODEGEN_SDNODEDBGVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SDNODEDBGVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
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
name|MDNode
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// SDDbgValue - Holds the information from a dbg_value node through SDISel.
comment|/// We do not use SDValue here to avoid including its header.
name|class
name|SDDbgValue
block|{
name|public
label|:
enum|enum
name|DbgValueKind
block|{
name|SDNODE
init|=
literal|0
block|,
comment|// value is the result of an expression
name|CONST
init|=
literal|1
block|,
comment|// value is a constant
name|FRAMEIX
init|=
literal|2
comment|// value is contents of a stack location
block|}
enum|;
name|private
label|:
name|enum
name|DbgValueKind
name|kind
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|SDNode
modifier|*
name|Node
decl_stmt|;
comment|// valid for expressions
name|unsigned
name|ResNo
decl_stmt|;
comment|// valid for expressions
block|}
name|s
struct|;
specifier|const
name|Value
modifier|*
name|Const
decl_stmt|;
comment|// valid for constants
name|unsigned
name|FrameIx
decl_stmt|;
comment|// valid for stack objects
block|}
name|u
union|;
name|MDNode
modifier|*
name|mdPtr
decl_stmt|;
name|bool
name|IsIndirect
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
name|bool
name|Invalid
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
argument|bool indir
argument_list|,
argument|uint64_t off
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned O
argument_list|)
block|:
name|mdPtr
argument_list|(
name|mdP
argument_list|)
operator|,
name|IsIndirect
argument_list|(
name|indir
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
name|O
argument_list|)
operator|,
name|Invalid
argument_list|(
argument|false
argument_list|)
block|{
name|kind
operator|=
name|SDNODE
block|;
name|u
operator|.
name|s
operator|.
name|Node
operator|=
name|N
block|;
name|u
operator|.
name|s
operator|.
name|ResNo
operator|=
name|R
block|;   }
comment|// Constructor for constants.
name|SDDbgValue
argument_list|(
argument|MDNode *mdP
argument_list|,
argument|const Value *C
argument_list|,
argument|uint64_t off
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned O
argument_list|)
operator|:
name|mdPtr
argument_list|(
name|mdP
argument_list|)
operator|,
name|IsIndirect
argument_list|(
name|false
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
name|O
argument_list|)
operator|,
name|Invalid
argument_list|(
argument|false
argument_list|)
block|{
name|kind
operator|=
name|CONST
block|;
name|u
operator|.
name|Const
operator|=
name|C
block|;   }
comment|// Constructor for frame indices.
name|SDDbgValue
argument_list|(
argument|MDNode *mdP
argument_list|,
argument|unsigned FI
argument_list|,
argument|uint64_t off
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|unsigned O
argument_list|)
operator|:
name|mdPtr
argument_list|(
name|mdP
argument_list|)
operator|,
name|IsIndirect
argument_list|(
name|false
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
name|O
argument_list|)
operator|,
name|Invalid
argument_list|(
argument|false
argument_list|)
block|{
name|kind
operator|=
name|FRAMEIX
block|;
name|u
operator|.
name|FrameIx
operator|=
name|FI
block|;   }
comment|// Returns the kind.
name|DbgValueKind
name|getKind
argument_list|()
block|{
return|return
name|kind
return|;
block|}
comment|// Returns the MDNode pointer.
name|MDNode
modifier|*
name|getMDPtr
parameter_list|()
block|{
return|return
name|mdPtr
return|;
block|}
comment|// Returns the SDNode* for a register ref
name|SDNode
modifier|*
name|getSDNode
parameter_list|()
block|{
name|assert
argument_list|(
name|kind
operator|==
name|SDNODE
argument_list|)
expr_stmt|;
return|return
name|u
operator|.
name|s
operator|.
name|Node
return|;
block|}
comment|// Returns the ResNo for a register ref
name|unsigned
name|getResNo
parameter_list|()
block|{
name|assert
argument_list|(
name|kind
operator|==
name|SDNODE
argument_list|)
expr_stmt|;
return|return
name|u
operator|.
name|s
operator|.
name|ResNo
return|;
block|}
comment|// Returns the Value* for a constant
specifier|const
name|Value
modifier|*
name|getConst
parameter_list|()
block|{
name|assert
argument_list|(
name|kind
operator|==
name|CONST
argument_list|)
expr_stmt|;
return|return
name|u
operator|.
name|Const
return|;
block|}
comment|// Returns the FrameIx for a stack object
name|unsigned
name|getFrameIx
parameter_list|()
block|{
name|assert
argument_list|(
name|kind
operator|==
name|FRAMEIX
argument_list|)
expr_stmt|;
return|return
name|u
operator|.
name|FrameIx
return|;
block|}
comment|// Returns whether this is an indirect value.
name|bool
name|isIndirect
parameter_list|()
block|{
return|return
name|IsIndirect
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
comment|// setIsInvalidated / isInvalidated - Setter / getter of the "Invalidated"
comment|// property. A SDDbgValue is invalid if the SDNode that produces the value is
comment|// deleted.
name|void
name|setIsInvalidated
parameter_list|()
block|{
name|Invalid
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|isInvalidated
parameter_list|()
block|{
return|return
name|Invalid
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

