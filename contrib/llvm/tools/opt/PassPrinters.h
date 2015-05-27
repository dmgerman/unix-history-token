begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PassPrinters.h - Utilities to print analysis info for passes -------===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Utilities to print analysis info for various kinds of passes.
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
name|LLVM_TOOLS_OPT_PASSPRINTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_OPT_PASSPRINTERS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlockPass
decl_stmt|;
name|class
name|CallGraphSCCPass
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|LoopPass
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
name|class
name|RegionPass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createFunctionPassPrinter
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|raw_ostream
modifier|&
name|out
parameter_list|,
name|bool
name|Quiet
parameter_list|)
function_decl|;
name|CallGraphSCCPass
modifier|*
name|createCallGraphPassPrinter
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|raw_ostream
modifier|&
name|out
parameter_list|,
name|bool
name|Quiet
parameter_list|)
function_decl|;
name|ModulePass
modifier|*
name|createModulePassPrinter
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|raw_ostream
modifier|&
name|out
parameter_list|,
name|bool
name|Quiet
parameter_list|)
function_decl|;
name|LoopPass
modifier|*
name|createLoopPassPrinter
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|raw_ostream
modifier|&
name|out
parameter_list|,
name|bool
name|Quiet
parameter_list|)
function_decl|;
name|RegionPass
modifier|*
name|createRegionPassPrinter
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|raw_ostream
modifier|&
name|out
parameter_list|,
name|bool
name|Quiet
parameter_list|)
function_decl|;
name|BasicBlockPass
modifier|*
name|createBasicBlockPassPrinter
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|PI
parameter_list|,
name|raw_ostream
modifier|&
name|out
parameter_list|,
name|bool
name|Quiet
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_OPT_PASSPRINTERS_H
end_comment

end_unit

