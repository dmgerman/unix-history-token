begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IRPrintingPasses.h - Passes to print out IR constructs ---*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file defines passes to print out IR in various granularities. The
end_comment

begin_comment
comment|/// PrintModulePass pass simply prints out the entire module when it is
end_comment

begin_comment
comment|/// executed. The PrintFunctionPass class is designed to be pipelined with
end_comment

begin_comment
comment|/// other FunctionPass's, and prints out the functions of the module as they
end_comment

begin_comment
comment|/// are processed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_IRPRINTINGPASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_IRPRINTINGPASSES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlockPass
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|PreservedAnalyses
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Create and return a pass that writes the module to the specified
comment|/// \c raw_ostream.
name|ModulePass
modifier|*
name|createPrintModulePass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// \brief Create and return a pass that prints functions to the specified
comment|/// \c raw_ostream as they are processed.
name|FunctionPass
modifier|*
name|createPrintFunctionPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// \brief Create and return a pass that writes the BB to the specified
comment|/// \c raw_ostream.
name|BasicBlockPass
modifier|*
name|createPrintBasicBlockPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// \brief Pass for printing a Module as LLVM's text IR assembly.
comment|///
comment|/// Note: This pass is for use with the new pass manager. Use the create...Pass
comment|/// functions above to create passes for use with the legacy pass manager.
name|class
name|PrintModulePass
block|{
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|std
operator|::
name|string
name|Banner
expr_stmt|;
name|public
label|:
name|PrintModulePass
argument_list|()
expr_stmt|;
name|PrintModulePass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
expr_stmt|;
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"PrintModulePass"
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Pass for printing a Function as LLVM's text IR assembly.
comment|///
comment|/// Note: This pass is for use with the new pass manager. Use the create...Pass
comment|/// functions above to create passes for use with the legacy pass manager.
name|class
name|PrintFunctionPass
block|{
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|std
operator|::
name|string
name|Banner
expr_stmt|;
name|public
label|:
name|PrintFunctionPass
argument_list|()
expr_stmt|;
name|PrintFunctionPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
expr_stmt|;
name|PreservedAnalyses
name|run
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"PrintFunctionPass"
return|;
block|}
block|}
empty_stmt|;
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

