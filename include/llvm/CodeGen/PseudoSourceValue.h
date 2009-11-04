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
file|"llvm/Value.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// PseudoSourceValue - Special value supplied for machine level alias
comment|/// analysis. It indicates that the a memory access references the functions
comment|/// stack frame (e.g., a spill slot), below the stack frame (e.g., argument
comment|/// space), or constant pool.
name|class
name|PseudoSourceValue
range|:
name|public
name|Value
block|{
name|private
operator|:
comment|/// printCustom - Implement printing for PseudoSourceValue. This is called
comment|/// from Value::print or Value's operator<<.
comment|///
name|virtual
name|void
name|printCustom
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|public
operator|:
name|PseudoSourceValue
argument_list|()
block|;
comment|/// isConstant - Test whether the memory pointed to by this
comment|/// PseudoSourceValue has a constant value.
comment|///
name|virtual
name|bool
name|isConstant
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
block|;
comment|/// isAliased - Test whether the memory pointed to by this
comment|/// PseudoSourceValue may also be pointed to by an LLVM IR Value.
name|virtual
name|bool
name|isAliased
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
block|;
comment|/// mayAlias - Return true if the memory pointed to by this
comment|/// PseudoSourceValue can ever alias a LLVM IR Value.
name|virtual
name|bool
name|mayAlias
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
block|;
comment|/// classof - Methods for support type inquiry through isa, cast, and
comment|/// dyn_cast:
comment|///
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const PseudoSourceValue *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|PseudoSourceValueVal
return|;
block|}
comment|/// A pseudo source value referencing a fixed stack frame entry,
comment|/// e.g., a spill slot.
specifier|static
specifier|const
name|PseudoSourceValue
operator|*
name|getFixedStack
argument_list|(
argument|int FI
argument_list|)
block|;
comment|/// A pseudo source value referencing the area below the stack frame of
comment|/// a function, e.g., the argument space.
specifier|static
specifier|const
name|PseudoSourceValue
operator|*
name|getStack
argument_list|()
block|;
comment|/// A pseudo source value referencing the global offset table
comment|/// (or something the like).
specifier|static
specifier|const
name|PseudoSourceValue
operator|*
name|getGOT
argument_list|()
block|;
comment|/// A pseudo source value referencing the constant pool. Since constant
comment|/// pools are constant, this doesn't need to identify a specific constant
comment|/// pool entry.
specifier|static
specifier|const
name|PseudoSourceValue
operator|*
name|getConstantPool
argument_list|()
block|;
comment|/// A pseudo source value referencing a jump table. Since jump tables are
comment|/// constant, this doesn't need to identify a specific jump table.
specifier|static
specifier|const
name|PseudoSourceValue
operator|*
name|getJumpTable
argument_list|()
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

