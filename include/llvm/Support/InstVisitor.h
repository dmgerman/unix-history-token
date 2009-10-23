begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/InstVisitor.h - Define instruction visitors -*- C++ -*-===//
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
name|LLVM_SUPPORT_INSTVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_INSTVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// We operate on opaque instruction classes, so forward declare all instruction
comment|// types now...
comment|//
define|#
directive|define
name|HANDLE_INST
parameter_list|(
name|NUM
parameter_list|,
name|OPCODE
parameter_list|,
name|CLASS
parameter_list|)
value|class CLASS;
include|#
directive|include
file|"llvm/Instruction.def"
define|#
directive|define
name|DELEGATE
parameter_list|(
name|CLASS_TO_VISIT
parameter_list|)
define|\
value|return static_cast<SubClass*>(this)-> \                visit##CLASS_TO_VISIT(static_cast<CLASS_TO_VISIT&>(I))
comment|/// @brief Base class for instruction visitors
comment|///
comment|/// Instruction visitors are used when you want to perform different actions
comment|/// for different kinds of instructions without having to use lots of casts
comment|/// and a big switch statement (in your code, that is).
comment|///
comment|/// To define your own visitor, inherit from this class, specifying your
comment|/// new type for the 'SubClass' template parameter, and "override" visitXXX
comment|/// functions in your class. I say "override" because this class is defined
comment|/// in terms of statically resolved overloading, not virtual functions.
comment|///
comment|/// For example, here is a visitor that counts the number of malloc
comment|/// instructions processed:
comment|///
comment|///  /// Declare the class.  Note that we derive from InstVisitor instantiated
comment|///  /// with _our new subclasses_ type.
comment|///  ///
comment|///  struct CountAllocaVisitor : public InstVisitor<CountAllocaVisitor> {
comment|///    unsigned Count;
comment|///    CountAllocaVisitor() : Count(0) {}
comment|///
comment|///    void visitAllocaInst(AllocaInst&AI) { ++Count; }
comment|///  };
comment|///
comment|///  And this class would be used like this:
comment|///    CountAllocaVisitor CAV;
comment|///    CAV.visit(function);
comment|///    NumAllocas = CAV.Count;
comment|///
comment|/// The defined has 'visit' methods for Instruction, and also for BasicBlock,
comment|/// Function, and Module, which recursively process all contained instructions.
comment|///
comment|/// Note that if you don't implement visitXXX for some instruction type,
comment|/// the visitXXX method for instruction superclass will be invoked. So
comment|/// if instructions are added in the future, they will be automatically
comment|/// supported, if you handle one of their superclasses.
comment|///
comment|/// The optional second template argument specifies the type that instruction
comment|/// visitation functions should return. If you specify this, you *MUST* provide
comment|/// an implementation of visitInstruction though!.
comment|///
comment|/// Note that this class is specifically designed as a template to avoid
comment|/// virtual function call overhead.  Defining and using an InstVisitor is just
comment|/// as efficient as having your own switch statement over the instruction
comment|/// opcode.
name|template
operator|<
name|typename
name|SubClass
operator|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|InstVisitor
block|{
comment|//===--------------------------------------------------------------------===//
comment|// Interface code - This is the public interface of the InstVisitor that you
comment|// use to visit instructions...
comment|//
name|public
operator|:
comment|// Generic visit method - Allow visitation to all instructions in a range
name|template
operator|<
name|class
name|Iterator
operator|>
name|void
name|visit
argument_list|(
argument|Iterator Start
argument_list|,
argument|Iterator End
argument_list|)
block|{
while|while
condition|(
name|Start
operator|!=
name|End
condition|)
name|static_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|visit
argument_list|(
operator|*
name|Start
operator|++
argument_list|)
expr_stmt|;
block|}
comment|// Define visitors for functions and basic blocks...
comment|//
name|void
name|visit
argument_list|(
argument|Module&M
argument_list|)
block|{
name|static_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|visitModule
argument_list|(
name|M
argument_list|)
block|;
name|visit
argument_list|(
name|M
operator|.
name|begin
argument_list|()
argument_list|,
name|M
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
name|void
name|visit
argument_list|(
argument|Function&F
argument_list|)
block|{
name|static_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|visitFunction
argument_list|(
name|F
argument_list|)
block|;
name|visit
argument_list|(
name|F
operator|.
name|begin
argument_list|()
argument_list|,
name|F
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
name|void
name|visit
argument_list|(
argument|BasicBlock&BB
argument_list|)
block|{
name|static_cast
operator|<
name|SubClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|visitBasicBlock
argument_list|(
name|BB
argument_list|)
block|;
name|visit
argument_list|(
name|BB
operator|.
name|begin
argument_list|()
argument_list|,
name|BB
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|// Forwarding functions so that the user can visit with pointers AND refs.
name|void
name|visit
argument_list|(
argument|Module       *M
argument_list|)
block|{
name|visit
argument_list|(
operator|*
name|M
argument_list|)
block|; }
name|void
name|visit
argument_list|(
argument|Function     *F
argument_list|)
block|{
name|visit
argument_list|(
operator|*
name|F
argument_list|)
block|; }
name|void
name|visit
argument_list|(
argument|BasicBlock   *BB
argument_list|)
block|{
name|visit
argument_list|(
operator|*
name|BB
argument_list|)
block|; }
name|RetTy
name|visit
argument_list|(
argument|Instruction *I
argument_list|)
block|{
return|return
name|visit
argument_list|(
operator|*
name|I
argument_list|)
return|;
block|}
comment|// visit - Finally, code to visit an instruction...
comment|//
name|RetTy
name|visit
argument_list|(
argument|Instruction&I
argument_list|)
block|{
switch|switch
condition|(
name|I
operator|.
name|getOpcode
argument_list|()
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown instruction type encountered!"
argument_list|)
expr_stmt|;
comment|// Build the switch statement using the Instruction.def file...
define|#
directive|define
name|HANDLE_INST
parameter_list|(
name|NUM
parameter_list|,
name|OPCODE
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|case Instruction::OPCODE: return \            static_cast<SubClass*>(this)-> \                       visit##OPCODE(static_cast<CLASS&>(I));
include|#
directive|include
file|"llvm/Instruction.def"
block|}
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Visitation functions... these functions provide default fallbacks in case
comment|// the user does not specify what to do for a particular instruction type.
comment|// The default behavior is to generalize the instruction type to its subtype
comment|// and try visiting the subtype.  All of this should be inlined perfectly,
comment|// because there are no virtual functions to get in the way.
comment|//
comment|// When visiting a module, function or basic block directly, these methods get
comment|// called to indicate when transitioning into a new unit.
comment|//
name|void
name|visitModule
argument_list|(
argument|Module&M
argument_list|)
block|{}
name|void
name|visitFunction
argument_list|(
argument|Function&F
argument_list|)
block|{}
name|void
name|visitBasicBlock
argument_list|(
argument|BasicBlock&BB
argument_list|)
block|{}
comment|// Define instruction specific visitor functions that can be overridden to
comment|// handle SPECIFIC instructions.  These functions automatically define
comment|// visitMul to proxy to visitBinaryOperator for instance in case the user does
comment|// not need this generality.
comment|//
comment|// The one problem case we have to handle here though is that the PHINode
comment|// class and opcode name are the exact same.  Because of this, we cannot
comment|// define visitPHINode (the inst version) to forward to visitPHINode (the
comment|// generic version) without multiply defined symbols and recursion.  To handle
comment|// this, we do not autoexpand "Other" instructions, we do it manually.
comment|//
define|#
directive|define
name|HANDLE_INST
parameter_list|(
name|NUM
parameter_list|,
name|OPCODE
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|RetTy visit##OPCODE(CLASS&I) { DELEGATE(CLASS); }
include|#
directive|include
file|"llvm/Instruction.def"
comment|// Specific Instruction type classes... note that all of the casts are
comment|// necessary because we use the instruction classes as opaque types...
comment|//
name|RetTy
name|visitReturnInst
argument_list|(
argument|ReturnInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|TerminatorInst
argument_list|)
block|;}
name|RetTy
name|visitBranchInst
argument_list|(
argument|BranchInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|TerminatorInst
argument_list|)
block|;}
name|RetTy
name|visitSwitchInst
argument_list|(
argument|SwitchInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|TerminatorInst
argument_list|)
block|;}
name|RetTy
name|visitInvokeInst
argument_list|(
argument|InvokeInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|TerminatorInst
argument_list|)
block|;}
name|RetTy
name|visitUnwindInst
argument_list|(
argument|UnwindInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|TerminatorInst
argument_list|)
block|;}
name|RetTy
name|visitUnreachableInst
argument_list|(
argument|UnreachableInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|TerminatorInst
argument_list|)
block|;}
name|RetTy
name|visitICmpInst
argument_list|(
argument|ICmpInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CmpInst
argument_list|)
block|;}
name|RetTy
name|visitFCmpInst
argument_list|(
argument|FCmpInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CmpInst
argument_list|)
block|;}
name|RetTy
name|visitAllocaInst
argument_list|(
argument|AllocaInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|AllocationInst
argument_list|)
block|;}
name|RetTy
name|visitFreeInst
argument_list|(
argument|FreeInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitLoadInst
argument_list|(
argument|LoadInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitStoreInst
argument_list|(
argument|StoreInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitGetElementPtrInst
argument_list|(
argument|GetElementPtrInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitPHINode
argument_list|(
argument|PHINode&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitTruncInst
argument_list|(
argument|TruncInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitZExtInst
argument_list|(
argument|ZExtInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitSExtInst
argument_list|(
argument|SExtInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitFPTruncInst
argument_list|(
argument|FPTruncInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitFPExtInst
argument_list|(
argument|FPExtInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitFPToUIInst
argument_list|(
argument|FPToUIInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitFPToSIInst
argument_list|(
argument|FPToSIInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitUIToFPInst
argument_list|(
argument|UIToFPInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitSIToFPInst
argument_list|(
argument|SIToFPInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitPtrToIntInst
argument_list|(
argument|PtrToIntInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitIntToPtrInst
argument_list|(
argument|IntToPtrInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitBitCastInst
argument_list|(
argument|BitCastInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|CastInst
argument_list|)
block|; }
name|RetTy
name|visitSelectInst
argument_list|(
argument|SelectInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitCallInst
argument_list|(
argument|CallInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitVAArgInst
argument_list|(
argument|VAArgInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitExtractElementInst
argument_list|(
argument|ExtractElementInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|;}
name|RetTy
name|visitInsertElementInst
argument_list|(
argument|InsertElementInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitShuffleVectorInst
argument_list|(
argument|ShuffleVectorInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitExtractValueInst
argument_list|(
argument|ExtractValueInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|;}
name|RetTy
name|visitInsertValueInst
argument_list|(
argument|InsertValueInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
comment|// Next level propagators: If the user does not overload a specific
comment|// instruction type, they can overload one of these to get the whole class
comment|// of instructions...
comment|//
name|RetTy
name|visitTerminatorInst
argument_list|(
argument|TerminatorInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitBinaryOperator
argument_list|(
argument|BinaryOperator&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitAllocationInst
argument_list|(
argument|AllocationInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitCmpInst
argument_list|(
argument|CmpInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
name|RetTy
name|visitCastInst
argument_list|(
argument|CastInst&I
argument_list|)
block|{
name|DELEGATE
argument_list|(
name|Instruction
argument_list|)
block|; }
comment|// If the user wants a 'default' case, they can choose to override this
comment|// function.  If this function is not overloaded in the user's subclass, then
comment|// this instruction just gets ignored.
comment|//
comment|// Note that you MUST override this function if your return type is not void.
comment|//
name|void
name|visitInstruction
argument_list|(
argument|Instruction&I
argument_list|)
block|{}
comment|// Ignore unhandled instructions
expr|}
block|;
undef|#
directive|undef
name|DELEGATE
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

