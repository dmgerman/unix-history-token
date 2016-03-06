begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegionPrinter.h - Region printer external interface -----*- C++ -*-===//
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
comment|// instantiate the region printer.
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
name|LLVM_ANALYSIS_REGIONPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_REGIONPRINTER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|RegionInfo
decl_stmt|;
name|FunctionPass
modifier|*
name|createRegionViewerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createRegionOnlyViewerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createRegionPrinterPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createRegionOnlyPrinterPass
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// @brief Open a viewer to display the GraphViz vizualization of the analysis
comment|/// result.
comment|///
comment|/// Practical to call in the debugger.
comment|/// Includes the instructions in each BasicBlock.
comment|///
comment|/// @param RI The analysis to display.
name|void
name|viewRegion
argument_list|(
name|llvm
operator|::
name|RegionInfo
operator|*
name|RI
argument_list|)
decl_stmt|;
comment|/// @brief Analyze the regions of a function and open its GraphViz
comment|/// visualization in a viewer.
comment|///
comment|/// Useful to call in the debugger.
comment|/// Includes the instructions in each BasicBlock.
comment|/// The result of a new analysis may differ from the RegionInfo the pass
comment|/// manager currently holds.
comment|///
comment|/// @param F Function to analyze.
name|void
name|viewRegion
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
comment|/// @brief Open a viewer to display the GraphViz vizualization of the analysis
comment|/// result.
comment|///
comment|/// Useful to call in the debugger.
comment|/// Shows only the BasicBlock names without their instructions.
comment|///
comment|/// @param RI The analysis to display.
name|void
name|viewRegionOnly
argument_list|(
name|llvm
operator|::
name|RegionInfo
operator|*
name|RI
argument_list|)
decl_stmt|;
comment|/// @brief Analyze the regions of a function and open its GraphViz
comment|/// visualization in a viewer.
comment|///
comment|/// Useful to call in the debugger.
comment|/// Shows only the BasicBlock names without their instructions.
comment|/// The result of a new analysis may differ from the RegionInfo the pass
comment|/// manager currently holds.
comment|///
comment|/// @param F Function to analyze.
name|void
name|viewRegionOnly
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
endif|#
directive|endif
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

