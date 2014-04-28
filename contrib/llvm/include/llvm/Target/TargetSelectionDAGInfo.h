begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/Target/TargetSelectionDAGInfo.h - SelectionDAG Info --*- C++ -*-==//
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
comment|// This file declares the TargetSelectionDAGInfo class, which targets can
end_comment

begin_comment
comment|// subclass to parameterize the SelectionDAG lowering and instruction
end_comment

begin_comment
comment|// selection process.
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
name|LLVM_TARGET_TARGETSELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETSELECTIONDAGINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// TargetSelectionDAGInfo - Targets can subclass this to parameterize the
comment|/// SelectionDAG lowering and instruction selection process.
comment|///
name|class
name|TargetSelectionDAGInfo
block|{
name|TargetSelectionDAGInfo
argument_list|(
argument|const TargetSelectionDAGInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetSelectionDAGInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
specifier|const
name|DataLayout
modifier|*
name|TD
decl_stmt|;
name|protected
label|:
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
name|public
label|:
name|explicit
name|TargetSelectionDAGInfo
parameter_list|(
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|virtual
operator|~
name|TargetSelectionDAGInfo
argument_list|()
expr_stmt|;
comment|/// EmitTargetCodeForMemcpy - Emit target-specific code that performs a
comment|/// memcpy. This can be used by targets to provide code sequences for cases
comment|/// that don't fit the target's parameters for simple loads/stores and can be
comment|/// more efficient than using a library call. This function can return a null
comment|/// SDValue if the target declines to use custom code and a different
comment|/// lowering strategy should be used.
comment|///
comment|/// If AlwaysInline is true, the size is constant and the target should not
comment|/// emit any calls and is strongly encouraged to attempt to emit inline code
comment|/// even if it is beyond the usual threshold because this intrinsic is being
comment|/// expanded in a place where calls are not feasible (e.g. within the prologue
comment|/// for another call). If the target chooses to decline an AlwaysInline
comment|/// request here, legalize will resort to using simple loads and stores.
name|virtual
name|SDValue
name|EmitTargetCodeForMemcpy
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Op1
argument_list|,
name|SDValue
name|Op2
argument_list|,
name|SDValue
name|Op3
argument_list|,
name|unsigned
name|Align
argument_list|,
name|bool
name|isVolatile
argument_list|,
name|bool
name|AlwaysInline
argument_list|,
name|MachinePointerInfo
name|DstPtrInfo
argument_list|,
name|MachinePointerInfo
name|SrcPtrInfo
argument_list|)
decl|const
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|/// EmitTargetCodeForMemmove - Emit target-specific code that performs a
comment|/// memmove. This can be used by targets to provide code sequences for cases
comment|/// that don't fit the target's parameters for simple loads/stores and can be
comment|/// more efficient than using a library call. This function can return a null
comment|/// SDValue if the target declines to use custom code and a different
comment|/// lowering strategy should be used.
name|virtual
name|SDValue
name|EmitTargetCodeForMemmove
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Op1
argument_list|,
name|SDValue
name|Op2
argument_list|,
name|SDValue
name|Op3
argument_list|,
name|unsigned
name|Align
argument_list|,
name|bool
name|isVolatile
argument_list|,
name|MachinePointerInfo
name|DstPtrInfo
argument_list|,
name|MachinePointerInfo
name|SrcPtrInfo
argument_list|)
decl|const
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|/// EmitTargetCodeForMemset - Emit target-specific code that performs a
comment|/// memset. This can be used by targets to provide code sequences for cases
comment|/// that don't fit the target's parameters for simple stores and can be more
comment|/// efficient than using a library call. This function can return a null
comment|/// SDValue if the target declines to use custom code and a different
comment|/// lowering strategy should be used.
name|virtual
name|SDValue
name|EmitTargetCodeForMemset
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Op1
argument_list|,
name|SDValue
name|Op2
argument_list|,
name|SDValue
name|Op3
argument_list|,
name|unsigned
name|Align
argument_list|,
name|bool
name|isVolatile
argument_list|,
name|MachinePointerInfo
name|DstPtrInfo
argument_list|)
decl|const
block|{
return|return
name|SDValue
argument_list|()
return|;
block|}
comment|/// EmitTargetCodeForMemcmp - Emit target-specific code that performs a
comment|/// memcmp, in cases where that is faster than a libcall.  The first
comment|/// returned SDValue is the result of the memcmp and the second is
comment|/// the chain.  Both SDValues can be null if a normal libcall should
comment|/// be used.
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|EmitTargetCodeForMemcmp
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Op1
argument_list|,
argument|SDValue Op2
argument_list|,
argument|SDValue Op3
argument_list|,
argument|MachinePointerInfo Op1PtrInfo
argument_list|,
argument|MachinePointerInfo Op2PtrInfo
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SDValue
argument_list|()
argument_list|,
name|SDValue
argument_list|()
argument_list|)
return|;
block|}
comment|/// EmitTargetCodeForMemchr - Emit target-specific code that performs a
comment|/// memchr, in cases where that is faster than a libcall.  The first
comment|/// returned SDValue is the result of the memchr and the second is
comment|/// the chain.  Both SDValues can be null if a normal libcall should
comment|/// be used.
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|EmitTargetCodeForMemchr
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue Char
argument_list|,
argument|SDValue Length
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SDValue
argument_list|()
argument_list|,
name|SDValue
argument_list|()
argument_list|)
return|;
block|}
comment|/// EmitTargetCodeForStrcpy - Emit target-specific code that performs a
comment|/// strcpy or stpcpy, in cases where that is faster than a libcall.
comment|/// The first returned SDValue is the result of the copy (the start
comment|/// of the destination string for strcpy, a pointer to the null terminator
comment|/// for stpcpy) and the second is the chain.  Both SDValues can be null
comment|/// if a normal libcall should be used.
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|EmitTargetCodeForStrcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dest
argument_list|,
argument|SDValue Src
argument_list|,
argument|MachinePointerInfo DestPtrInfo
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|,
argument|bool isStpcpy
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SDValue
argument_list|()
argument_list|,
name|SDValue
argument_list|()
argument_list|)
return|;
block|}
comment|/// EmitTargetCodeForStrcmp - Emit target-specific code that performs a
comment|/// strcmp, in cases where that is faster than a libcall.  The first
comment|/// returned SDValue is the result of the strcmp and the second is
comment|/// the chain.  Both SDValues can be null if a normal libcall should
comment|/// be used.
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|EmitTargetCodeForStrcmp
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Op1
argument_list|,
argument|SDValue Op2
argument_list|,
argument|MachinePointerInfo Op1PtrInfo
argument_list|,
argument|MachinePointerInfo Op2PtrInfo
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SDValue
argument_list|()
argument_list|,
name|SDValue
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|EmitTargetCodeForStrlen
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SDValue
argument_list|()
argument_list|,
name|SDValue
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
name|SDValue
operator|>
name|EmitTargetCodeForStrnlen
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue MaxLength
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SDValue
argument_list|()
argument_list|,
name|SDValue
argument_list|()
argument_list|)
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

