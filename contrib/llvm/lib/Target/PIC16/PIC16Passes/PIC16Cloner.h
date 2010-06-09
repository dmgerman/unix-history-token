begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16Cloner.h - PIC16 LLVM Cloner for shared functions --*- C++ -*-===//
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
comment|// This file contains declaration of a cloner class clone all functions that
end_comment

begin_comment
comment|// are shared between the main line code (ML) and interrupt line code (IL).
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
name|PIC16CLONER_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16CLONER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|vector
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|string
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|map
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// forward classes.
name|class
name|Value
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|CallGraph
decl_stmt|;
name|class
name|CallGraphNode
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|PIC16Cloner
range|:
name|public
name|ModulePass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification
name|PIC16Cloner
argument_list|()
operator|:
name|ModulePass
argument_list|(
argument|&ID
argument_list|)
block|{}
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|{
name|AU
operator|.
name|addRequired
operator|<
name|CallGraph
operator|>
operator|(
operator|)
block|;     }
name|virtual
name|bool
name|runOnModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
comment|// Functions
comment|// Mark reachable functions for the MainLine or InterruptLine.
name|void
name|markCallGraph
argument_list|(
argument|CallGraphNode *CGN
argument_list|,
argument|string StringMark
argument_list|)
block|;
comment|// Clone auto variables of function specified.
name|void
name|CloneAutos
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
comment|// Clone the body of a function.
name|Function
operator|*
name|cloneFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
comment|// Clone all shared functions.
name|void
name|cloneSharedFunctions
argument_list|(
name|CallGraphNode
operator|*
name|isrCGN
argument_list|)
block|;
comment|// Remap all call sites to the shared function.
name|void
name|remapAllSites
argument_list|(
name|Function
operator|*
name|Caller
argument_list|,
name|Function
operator|*
name|OrgF
argument_list|,
name|Function
operator|*
name|Clone
argument_list|)
block|;
comment|// Error reporting for PIC16Pass
name|void
name|reportError
argument_list|(
argument|string ErrorString
argument_list|,
argument|vector<string>&Values
argument_list|)
block|;
name|void
name|reportError
argument_list|(
argument|string ErrorString
argument_list|)
block|;
name|private
operator|:
comment|//data
comment|// Records if the interrupt function has already been found.
comment|// If more than one interrupt function is found then an error
comment|// should be thrown.
name|bool
name|foundISR
block|;
comment|// This ValueMap maps the auto variables of the original functions with
comment|// the corresponding cloned auto variable of the cloned function.
comment|// This value map is passed during the function cloning so that all the
comment|// uses of auto variables be updated properly.
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
block|,
name|Value
operator|*
operator|>
name|ValueMap
block|;
comment|// Map of a already cloned functions.
name|map
operator|<
name|Function
operator|*
block|,
name|Function
operator|*
operator|>
name|ClonedFunctionMap
block|;
typedef|typedef
name|map
operator|<
name|Function
operator|*
operator|,
name|Function
operator|*
operator|>
operator|::
name|iterator
name|cloned_map_iterator
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of anonymous namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

