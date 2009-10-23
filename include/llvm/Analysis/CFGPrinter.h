begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFGPrinter.h - CFG printer external interface ------------*- C++ -*-===//
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
comment|// This file defines external functions that can be called to explicitly
end_comment

begin_comment
comment|// instantiate the CFG printer.
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
name|LLVM_ANALYSIS_CFGPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CFGPRINTER_H
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
file|"llvm/Assembly/Writer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GraphWriter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|DOTGraphTraits
operator|<
specifier|const
name|Function
operator|*
operator|>
operator|:
name|public
name|DefaultDOTGraphTraits
block|{
specifier|static
name|std
operator|::
name|string
name|getGraphName
argument_list|(
argument|const Function *F
argument_list|)
block|{
return|return
literal|"CFG for '"
operator|+
name|F
operator|->
name|getNameStr
argument_list|()
operator|+
literal|"' function"
return|;
block|}
specifier|static
name|std
operator|::
name|string
name|getNodeLabel
argument_list|(
argument|const BasicBlock *Node
argument_list|,
argument|const Function *Graph
argument_list|,
argument|bool ShortNames
argument_list|)
block|{
if|if
condition|(
name|ShortNames
operator|&&
operator|!
name|Node
operator|->
name|getName
argument_list|()
operator|.
name|empty
argument_list|()
condition|)
return|return
name|Node
operator|->
name|getNameStr
argument_list|()
operator|+
literal|":"
return|;
name|std
operator|::
name|string
name|Str
block|;
name|raw_string_ostream
name|OS
argument_list|(
name|Str
argument_list|)
block|;
if|if
condition|(
name|ShortNames
condition|)
block|{
name|WriteAsOperand
argument_list|(
name|OS
argument_list|,
name|Node
argument_list|,
name|false
argument_list|)
expr_stmt|;
return|return
name|OS
operator|.
name|str
argument_list|()
return|;
block|}
if|if
condition|(
name|Node
operator|->
name|getName
argument_list|()
operator|.
name|empty
argument_list|()
condition|)
block|{
name|WriteAsOperand
argument_list|(
name|OS
argument_list|,
name|Node
argument_list|,
name|false
argument_list|)
expr_stmt|;
name|OS
operator|<<
literal|":"
expr_stmt|;
block|}
name|OS
operator|<<
operator|*
name|Node
expr_stmt|;
name|std
operator|::
name|string
name|OutStr
operator|=
name|OS
operator|.
name|str
argument_list|()
expr_stmt|;
if|if
condition|(
name|OutStr
index|[
literal|0
index|]
operator|==
literal|'\n'
condition|)
name|OutStr
operator|.
name|erase
argument_list|(
name|OutStr
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
comment|// Process string output to make it nicer...
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|OutStr
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|OutStr
index|[
name|i
index|]
operator|==
literal|'\n'
condition|)
block|{
comment|// Left justify
name|OutStr
index|[
name|i
index|]
operator|=
literal|'\\'
expr_stmt|;
name|OutStr
operator|.
name|insert
argument_list|(
name|OutStr
operator|.
name|begin
argument_list|()
operator|+
name|i
operator|+
literal|1
argument_list|,
literal|'l'
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|OutStr
index|[
name|i
index|]
operator|==
literal|';'
condition|)
block|{
comment|// Delete comments!
name|unsigned
name|Idx
init|=
name|OutStr
operator|.
name|find
argument_list|(
literal|'\n'
argument_list|,
name|i
operator|+
literal|1
argument_list|)
decl_stmt|;
comment|// Find end of line
name|OutStr
operator|.
name|erase
argument_list|(
name|OutStr
operator|.
name|begin
argument_list|()
operator|+
name|i
argument_list|,
name|OutStr
operator|.
name|begin
argument_list|()
operator|+
name|Idx
argument_list|)
expr_stmt|;
operator|--
name|i
expr_stmt|;
block|}
return|return
name|OutStr
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getEdgeSourceLabel
argument_list|(
argument|const BasicBlock *Node
argument_list|,
argument|succ_const_iterator I
argument_list|)
block|{
comment|// Label source of conditional branches with "T" or "F"
if|if
condition|(
specifier|const
name|BranchInst
modifier|*
name|BI
init|=
name|dyn_cast
operator|<
name|BranchInst
operator|>
operator|(
name|Node
operator|->
name|getTerminator
argument_list|()
operator|)
condition|)
if|if
condition|(
name|BI
operator|->
name|isConditional
argument_list|()
condition|)
return|return
operator|(
name|I
operator|==
name|succ_begin
argument_list|(
name|Node
argument_list|)
operator|)
operator|?
literal|"T"
operator|:
literal|"F"
return|;
end_expr_stmt

begin_return
return|return
literal|""
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|class
name|FunctionPass
decl_stmt|;
name|FunctionPass
modifier|*
name|createCFGPrinterPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createCFGOnlyPrinterPass
parameter_list|()
function_decl|;
block|}
end_block

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

