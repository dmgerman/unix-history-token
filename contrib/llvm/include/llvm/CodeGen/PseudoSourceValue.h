begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/PseudoSourceValue.h ------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the PseudoSourceValue class.
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
name|LLVM_CODEGEN_PSEUDOSOURCEVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PSEUDOSOURCEVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineMemOperand
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineMemOperand
operator|&
name|MMO
operator|)
expr_stmt|;
name|class
name|PseudoSourceValue
decl_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|PseudoSourceValue
operator|*
name|PSV
operator|)
expr_stmt|;
comment|/// Special value supplied for machine level alias analysis. It indicates that
comment|/// a memory access references the functions stack frame (e.g., a spill slot),
comment|/// below the stack frame (e.g., argument space), or constant pool.
name|class
name|PseudoSourceValue
block|{
name|public
label|:
enum|enum
name|PSVKind
block|{
name|Stack
block|,
name|GOT
block|,
name|JumpTable
block|,
name|ConstantPool
block|,
name|FixedStack
block|,
name|GlobalValueCallEntry
block|,
name|ExternalSymbolCallEntry
block|,
name|TargetCustom
block|}
enum|;
name|private
label|:
name|PSVKind
name|Kind
decl_stmt|;
name|friend
name|raw_ostream
operator|&
name|llvm
operator|::
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|PseudoSourceValue
operator|*
name|PSV
operator|)
expr_stmt|;
name|friend
name|class
name|MachineMemOperand
decl_stmt|;
comment|// For printCustom().
comment|/// Implement printing for PseudoSourceValue. This is called from
comment|/// Value::print or Value's operator<<.
name|virtual
name|void
name|printCustom
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|explicit
name|PseudoSourceValue
parameter_list|(
name|PSVKind
name|Kind
parameter_list|)
function_decl|;
name|virtual
operator|~
name|PseudoSourceValue
argument_list|()
expr_stmt|;
name|PSVKind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|bool
name|isStack
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Stack
return|;
block|}
name|bool
name|isGOT
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|GOT
return|;
block|}
name|bool
name|isConstantPool
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ConstantPool
return|;
block|}
name|bool
name|isJumpTable
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|JumpTable
return|;
block|}
name|unsigned
name|getTargetCustom
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Kind
operator|>=
name|TargetCustom
operator|)
operator|?
operator|(
operator|(
name|Kind
operator|+
literal|1
operator|)
operator|-
name|TargetCustom
operator|)
operator|:
literal|0
return|;
block|}
comment|/// Test whether the memory pointed to by this PseudoSourceValue has a
comment|/// constant value.
name|virtual
name|bool
name|isConstant
argument_list|(
specifier|const
name|MachineFrameInfo
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// Test whether the memory pointed to by this PseudoSourceValue may also be
comment|/// pointed to by an LLVM IR Value.
name|virtual
name|bool
name|isAliased
argument_list|(
specifier|const
name|MachineFrameInfo
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the memory pointed to by this PseudoSourceValue can ever
comment|/// alias an LLVM IR Value.
name|virtual
name|bool
name|mayAlias
argument_list|(
specifier|const
name|MachineFrameInfo
operator|*
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// A specialized PseudoSourceValue for holding FixedStack values, which must
comment|/// include a frame index.
name|class
name|FixedStackPseudoSourceValue
range|:
name|public
name|PseudoSourceValue
block|{
specifier|const
name|int
name|FI
block|;
name|public
operator|:
name|explicit
name|FixedStackPseudoSourceValue
argument_list|(
argument|int FI
argument_list|)
operator|:
name|PseudoSourceValue
argument_list|(
name|FixedStack
argument_list|)
block|,
name|FI
argument_list|(
argument|FI
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const PseudoSourceValue *V
argument_list|)
block|{
return|return
name|V
operator|->
name|kind
argument_list|()
operator|==
name|FixedStack
return|;
block|}
name|bool
name|isConstant
argument_list|(
argument|const MachineFrameInfo *MFI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isAliased
argument_list|(
argument|const MachineFrameInfo *MFI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|mayAlias
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
name|override
block|;
name|void
name|printCustom
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
name|int
name|getFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|FI
return|;
block|}
expr|}
block|;
name|class
name|CallEntryPseudoSourceValue
operator|:
name|public
name|PseudoSourceValue
block|{
name|protected
operator|:
name|CallEntryPseudoSourceValue
argument_list|(
argument|PSVKind Kind
argument_list|)
block|;
name|public
operator|:
name|bool
name|isConstant
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isAliased
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
name|override
block|;
name|bool
name|mayAlias
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
name|override
block|; }
block|;
comment|/// A specialized pseudo soruce value for holding GlobalValue values.
name|class
name|GlobalValuePseudoSourceValue
operator|:
name|public
name|CallEntryPseudoSourceValue
block|{
specifier|const
name|GlobalValue
operator|*
name|GV
block|;
name|public
operator|:
name|GlobalValuePseudoSourceValue
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PseudoSourceValue *V
argument_list|)
block|{
return|return
name|V
operator|->
name|kind
argument_list|()
operator|==
name|GlobalValueCallEntry
return|;
block|}
specifier|const
name|GlobalValue
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|GV
return|;
block|}
expr|}
block|;
comment|/// A specialized pseudo source value for holding external symbol values.
name|class
name|ExternalSymbolPseudoSourceValue
operator|:
name|public
name|CallEntryPseudoSourceValue
block|{
specifier|const
name|char
operator|*
name|ES
block|;
name|public
operator|:
name|ExternalSymbolPseudoSourceValue
argument_list|(
specifier|const
name|char
operator|*
name|ES
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PseudoSourceValue *V
argument_list|)
block|{
return|return
name|V
operator|->
name|kind
argument_list|()
operator|==
name|ExternalSymbolCallEntry
return|;
block|}
specifier|const
name|char
operator|*
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
name|ES
return|;
block|}
expr|}
block|;
comment|/// Manages creation of pseudo source values.
name|class
name|PseudoSourceValueManager
block|{
specifier|const
name|PseudoSourceValue
name|StackPSV
block|,
name|GOTPSV
block|,
name|JumpTablePSV
block|,
name|ConstantPoolPSV
block|;
name|std
operator|::
name|map
operator|<
name|int
block|,
name|std
operator|::
name|unique_ptr
operator|<
name|FixedStackPseudoSourceValue
operator|>>
name|FSValues
block|;
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|ExternalSymbolPseudoSourceValue
operator|>>
name|ExternalCallEntries
block|;
name|ValueMap
operator|<
specifier|const
name|GlobalValue
operator|*
block|,
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|GlobalValuePseudoSourceValue
operator|>>
name|GlobalCallEntries
block|;
name|public
operator|:
name|PseudoSourceValueManager
argument_list|()
block|;
comment|/// Return a pseudo source value referencing the area below the stack frame of
comment|/// a function, e.g., the argument space.
specifier|const
name|PseudoSourceValue
operator|*
name|getStack
argument_list|()
block|;
comment|/// Return a pseudo source value referencing the global offset table
comment|/// (or something the like).
specifier|const
name|PseudoSourceValue
operator|*
name|getGOT
argument_list|()
block|;
comment|/// Return a pseudo source value referencing the constant pool. Since constant
comment|/// pools are constant, this doesn't need to identify a specific constant
comment|/// pool entry.
specifier|const
name|PseudoSourceValue
operator|*
name|getConstantPool
argument_list|()
block|;
comment|/// Return a pseudo source value referencing a jump table. Since jump tables
comment|/// are constant, this doesn't need to identify a specific jump table.
specifier|const
name|PseudoSourceValue
operator|*
name|getJumpTable
argument_list|()
block|;
comment|/// Return a pseudo source value referencing a fixed stack frame entry,
comment|/// e.g., a spill slot.
specifier|const
name|PseudoSourceValue
operator|*
name|getFixedStack
argument_list|(
argument|int FI
argument_list|)
block|;
specifier|const
name|PseudoSourceValue
operator|*
name|getGlobalValueCallEntry
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
block|;
specifier|const
name|PseudoSourceValue
operator|*
name|getExternalSymbolCallEntry
argument_list|(
specifier|const
name|char
operator|*
name|ES
argument_list|)
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

