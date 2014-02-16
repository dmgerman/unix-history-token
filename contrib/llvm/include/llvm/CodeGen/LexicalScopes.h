begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LexicalScopes.cpp - Collecting lexical scope info -*- C++ -*--------===//
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
comment|// This file implements LexicalScopes analysis.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass collects lexical scope information and maps machine instructions
end_comment

begin_comment
comment|// to respective lexical scopes.
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
name|LLVM_CODEGEN_LEXICALSCOPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LEXICALSCOPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|LexicalScope
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// InsnRange - This is used to track range of instructions with identical
comment|/// lexical scope.
comment|///
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
specifier|const
name|MachineInstr
operator|*
operator|>
name|InsnRange
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// LexicalScopes -  This class provides interface to collect and use lexical
comment|/// scoping information from machine instruction.
comment|///
name|class
name|LexicalScopes
block|{
name|public
label|:
name|LexicalScopes
argument_list|()
operator|:
name|MF
argument_list|(
name|NULL
argument_list|)
operator|,
name|CurrentFnLexicalScope
argument_list|(
argument|NULL
argument_list|)
block|{ }
name|virtual
operator|~
name|LexicalScopes
argument_list|()
expr_stmt|;
comment|/// initialize - Scan machine function and constuct lexical scope nest.
name|virtual
name|void
name|initialize
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
comment|/// releaseMemory - release memory.
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
comment|/// empty - Return true if there is any lexical scope information available.
name|bool
name|empty
parameter_list|()
block|{
return|return
name|CurrentFnLexicalScope
operator|==
name|NULL
return|;
block|}
comment|/// isCurrentFunctionScope - Return true if given lexical scope represents
comment|/// current function.
name|bool
name|isCurrentFunctionScope
parameter_list|(
specifier|const
name|LexicalScope
modifier|*
name|LS
parameter_list|)
block|{
return|return
name|LS
operator|==
name|CurrentFnLexicalScope
return|;
block|}
comment|/// getCurrentFunctionScope - Return lexical scope for the current function.
name|LexicalScope
operator|*
name|getCurrentFunctionScope
argument_list|()
specifier|const
block|{
return|return
name|CurrentFnLexicalScope
return|;
block|}
comment|/// getMachineBasicBlocks - Populate given set using machine basic blocks
comment|/// which have machine instructions that belong to lexical scope identified by
comment|/// DebugLoc.
name|void
name|getMachineBasicBlocks
argument_list|(
name|DebugLoc
name|DL
argument_list|,
name|SmallPtrSet
operator|<
specifier|const
name|MachineBasicBlock
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|MBBs
argument_list|)
decl_stmt|;
comment|/// dominates - Return true if DebugLoc's lexical scope dominates at least one
comment|/// machine instruction's lexical scope in a given machine basic block.
name|bool
name|dominates
parameter_list|(
name|DebugLoc
name|DL
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
comment|/// findLexicalScope - Find lexical scope, either regular or inlined, for the
comment|/// given DebugLoc. Return NULL if not found.
name|LexicalScope
modifier|*
name|findLexicalScope
parameter_list|(
name|DebugLoc
name|DL
parameter_list|)
function_decl|;
comment|/// getAbstractScopesList - Return a reference to list of abstract scopes.
name|ArrayRef
operator|<
name|LexicalScope
operator|*
operator|>
name|getAbstractScopesList
argument_list|()
specifier|const
block|{
return|return
name|AbstractScopesList
return|;
block|}
comment|/// findAbstractScope - Find an abstract scope or return NULL.
name|LexicalScope
modifier|*
name|findAbstractScope
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
block|{
return|return
name|AbstractScopeMap
operator|.
name|lookup
argument_list|(
name|N
argument_list|)
return|;
block|}
comment|/// findInlinedScope - Find an inlined scope for the given DebugLoc or return
comment|/// NULL.
name|LexicalScope
modifier|*
name|findInlinedScope
parameter_list|(
name|DebugLoc
name|DL
parameter_list|)
block|{
return|return
name|InlinedLexicalScopeMap
operator|.
name|lookup
argument_list|(
name|DL
argument_list|)
return|;
block|}
comment|/// findLexicalScope - Find regular lexical scope or return NULL.
name|LexicalScope
modifier|*
name|findLexicalScope
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
block|{
return|return
name|LexicalScopeMap
operator|.
name|lookup
argument_list|(
name|N
argument_list|)
return|;
block|}
comment|/// dump - Print data structures to dbgs().
name|void
name|dump
parameter_list|()
function_decl|;
name|private
label|:
comment|/// getOrCreateLexicalScope - Find lexical scope for the given DebugLoc. If
comment|/// not available then create new lexical scope.
name|LexicalScope
modifier|*
name|getOrCreateLexicalScope
parameter_list|(
name|DebugLoc
name|DL
parameter_list|)
function_decl|;
comment|/// getOrCreateRegularScope - Find or create a regular lexical scope.
name|LexicalScope
modifier|*
name|getOrCreateRegularScope
parameter_list|(
name|MDNode
modifier|*
name|Scope
parameter_list|)
function_decl|;
comment|/// getOrCreateInlinedScope - Find or create an inlined lexical scope.
name|LexicalScope
modifier|*
name|getOrCreateInlinedScope
parameter_list|(
name|MDNode
modifier|*
name|Scope
parameter_list|,
name|MDNode
modifier|*
name|InlinedAt
parameter_list|)
function_decl|;
comment|/// getOrCreateAbstractScope - Find or create an abstract lexical scope.
name|LexicalScope
modifier|*
name|getOrCreateAbstractScope
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// extractLexicalScopes - Extract instruction ranges for each lexical scopes
comment|/// for the given machine function.
name|void
name|extractLexicalScopes
argument_list|(
name|SmallVectorImpl
operator|<
name|InsnRange
operator|>
operator|&
name|MIRanges
argument_list|,
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
argument_list|,
name|LexicalScope
operator|*
operator|>
operator|&
name|M
argument_list|)
decl_stmt|;
name|void
name|constructScopeNest
parameter_list|(
name|LexicalScope
modifier|*
name|Scope
parameter_list|)
function_decl|;
name|void
name|assignInstructionRanges
argument_list|(
name|SmallVectorImpl
operator|<
name|InsnRange
operator|>
operator|&
name|MIRanges
argument_list|,
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
argument_list|,
name|LexicalScope
operator|*
operator|>
operator|&
name|M
argument_list|)
decl_stmt|;
name|private
label|:
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// LexicalScopeMap - Tracks the scopes in the current function.  Owns the
comment|/// contained LexicalScope*s.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|LexicalScope
operator|*
operator|>
name|LexicalScopeMap
expr_stmt|;
comment|/// InlinedLexicalScopeMap - Tracks inlined function scopes in current function.
name|DenseMap
operator|<
name|DebugLoc
operator|,
name|LexicalScope
operator|*
operator|>
name|InlinedLexicalScopeMap
expr_stmt|;
comment|/// AbstractScopeMap - These scopes are  not included LexicalScopeMap.
comment|/// AbstractScopes owns its LexicalScope*s.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|LexicalScope
operator|*
operator|>
name|AbstractScopeMap
expr_stmt|;
comment|/// AbstractScopesList - Tracks abstract scopes constructed while processing
comment|/// a function.
name|SmallVector
operator|<
name|LexicalScope
operator|*
operator|,
literal|4
operator|>
name|AbstractScopesList
expr_stmt|;
comment|/// CurrentFnLexicalScope - Top level scope for the current function.
comment|///
name|LexicalScope
modifier|*
name|CurrentFnLexicalScope
decl_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// LexicalScope - This class is used to track scope information.
comment|///
name|class
name|LexicalScope
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|LexicalScope
argument_list|(
argument|LexicalScope *P
argument_list|,
argument|const MDNode *D
argument_list|,
argument|const MDNode *I
argument_list|,
argument|bool A
argument_list|)
block|:
name|Parent
argument_list|(
name|P
argument_list|)
operator|,
name|Desc
argument_list|(
name|D
argument_list|)
operator|,
name|InlinedAtLocation
argument_list|(
name|I
argument_list|)
operator|,
name|AbstractScope
argument_list|(
name|A
argument_list|)
operator|,
name|LastInsn
argument_list|(
literal|0
argument_list|)
operator|,
name|FirstInsn
argument_list|(
literal|0
argument_list|)
operator|,
name|DFSIn
argument_list|(
literal|0
argument_list|)
operator|,
name|DFSOut
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|Parent
condition|)
name|Parent
operator|->
name|addChild
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|virtual
operator|~
name|LexicalScope
argument_list|()
block|{}
comment|// Accessors.
name|LexicalScope
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
specifier|const
name|MDNode
operator|*
name|getDesc
argument_list|()
specifier|const
block|{
return|return
name|Desc
return|;
block|}
specifier|const
name|MDNode
operator|*
name|getInlinedAt
argument_list|()
specifier|const
block|{
return|return
name|InlinedAtLocation
return|;
block|}
specifier|const
name|MDNode
operator|*
name|getScopeNode
argument_list|()
specifier|const
block|{
return|return
name|Desc
return|;
block|}
name|bool
name|isAbstractScope
argument_list|()
specifier|const
block|{
return|return
name|AbstractScope
return|;
block|}
name|SmallVectorImpl
operator|<
name|LexicalScope
operator|*
operator|>
operator|&
name|getChildren
argument_list|()
block|{
return|return
name|Children
return|;
block|}
name|SmallVectorImpl
operator|<
name|InsnRange
operator|>
operator|&
name|getRanges
argument_list|()
block|{
return|return
name|Ranges
return|;
block|}
comment|/// addChild - Add a child scope.
name|void
name|addChild
parameter_list|(
name|LexicalScope
modifier|*
name|S
parameter_list|)
block|{
name|Children
operator|.
name|push_back
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
comment|/// openInsnRange - This scope covers instruction range starting from MI.
name|void
name|openInsnRange
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
if|if
condition|(
operator|!
name|FirstInsn
condition|)
name|FirstInsn
operator|=
name|MI
expr_stmt|;
if|if
condition|(
name|Parent
condition|)
name|Parent
operator|->
name|openInsnRange
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
comment|/// extendInsnRange - Extend the current instruction range covered by
comment|/// this scope.
name|void
name|extendInsnRange
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|assert
argument_list|(
name|FirstInsn
operator|&&
literal|"MI Range is not open!"
argument_list|)
expr_stmt|;
name|LastInsn
operator|=
name|MI
expr_stmt|;
if|if
condition|(
name|Parent
condition|)
name|Parent
operator|->
name|extendInsnRange
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
comment|/// closeInsnRange - Create a range based on FirstInsn and LastInsn collected
comment|/// until now. This is used when a new scope is encountered while walking
comment|/// machine instructions.
name|void
name|closeInsnRange
parameter_list|(
name|LexicalScope
modifier|*
name|NewScope
init|=
name|NULL
parameter_list|)
block|{
name|assert
argument_list|(
name|LastInsn
operator|&&
literal|"Last insn missing!"
argument_list|)
expr_stmt|;
name|Ranges
operator|.
name|push_back
argument_list|(
name|InsnRange
argument_list|(
name|FirstInsn
argument_list|,
name|LastInsn
argument_list|)
argument_list|)
expr_stmt|;
name|FirstInsn
operator|=
name|NULL
expr_stmt|;
name|LastInsn
operator|=
name|NULL
expr_stmt|;
comment|// If Parent dominates NewScope then do not close Parent's instruction
comment|// range.
if|if
condition|(
name|Parent
operator|&&
operator|(
operator|!
name|NewScope
operator|||
operator|!
name|Parent
operator|->
name|dominates
argument_list|(
name|NewScope
argument_list|)
operator|)
condition|)
name|Parent
operator|->
name|closeInsnRange
argument_list|(
name|NewScope
argument_list|)
expr_stmt|;
block|}
comment|/// dominates - Return true if current scope dominates given lexical scope.
name|bool
name|dominates
argument_list|(
specifier|const
name|LexicalScope
operator|*
name|S
argument_list|)
decl|const
block|{
if|if
condition|(
name|S
operator|==
name|this
condition|)
return|return
name|true
return|;
if|if
condition|(
name|DFSIn
operator|<
name|S
operator|->
name|getDFSIn
argument_list|()
operator|&&
name|DFSOut
operator|>
name|S
operator|->
name|getDFSOut
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|// Depth First Search support to walk and manipulate LexicalScope hierarchy.
name|unsigned
name|getDFSOut
argument_list|()
specifier|const
block|{
return|return
name|DFSOut
return|;
block|}
name|void
name|setDFSOut
parameter_list|(
name|unsigned
name|O
parameter_list|)
block|{
name|DFSOut
operator|=
name|O
expr_stmt|;
block|}
name|unsigned
name|getDFSIn
argument_list|()
specifier|const
block|{
return|return
name|DFSIn
return|;
block|}
name|void
name|setDFSIn
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
name|DFSIn
operator|=
name|I
expr_stmt|;
block|}
comment|/// dump - print lexical scope.
name|void
name|dump
argument_list|(
name|unsigned
name|Indent
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|LexicalScope
modifier|*
name|Parent
decl_stmt|;
comment|// Parent to this scope.
name|AssertingVH
operator|<
specifier|const
name|MDNode
operator|>
name|Desc
expr_stmt|;
comment|// Debug info descriptor.
name|AssertingVH
operator|<
specifier|const
name|MDNode
operator|>
name|InlinedAtLocation
expr_stmt|;
comment|// Location at which this
comment|// scope is inlined.
name|bool
name|AbstractScope
decl_stmt|;
comment|// Abstract Scope
name|SmallVector
operator|<
name|LexicalScope
operator|*
operator|,
literal|4
operator|>
name|Children
expr_stmt|;
comment|// Scopes defined in scope.
comment|// Contents not owned.
name|SmallVector
operator|<
name|InsnRange
operator|,
literal|4
operator|>
name|Ranges
expr_stmt|;
specifier|const
name|MachineInstr
modifier|*
name|LastInsn
decl_stmt|;
comment|// Last instruction of this scope.
specifier|const
name|MachineInstr
modifier|*
name|FirstInsn
decl_stmt|;
comment|// First instruction of this scope.
name|unsigned
name|DFSIn
decl_stmt|,
name|DFSOut
decl_stmt|;
comment|// In& Out Depth use to determine
comment|// scope nesting.
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

