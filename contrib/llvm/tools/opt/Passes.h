begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Passes.h - Parsing, selection, and running of passes -----*- C++ -*-===//
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
comment|/// Interfaces for producing common pass manager configurations and parsing
end_comment

begin_comment
comment|/// textual pass specifications.
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
name|LLVM_TOOLS_OPT_PASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_OPT_PASSES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/CGSCCPassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Registers all available module analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c
comment|/// ModuleAnalysisManager with all registered module analyses. Callers can
comment|/// still manually register any additional analyses.
name|void
name|registerModuleAnalyses
parameter_list|(
name|ModuleAnalysisManager
modifier|&
name|MAM
parameter_list|)
function_decl|;
comment|/// \brief Registers all available CGSCC analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c CGSCCAnalysisManager
comment|/// with all registered CGSCC analyses. Callers can still manually register any
comment|/// additional analyses.
name|void
name|registerCGSCCAnalyses
parameter_list|(
name|CGSCCAnalysisManager
modifier|&
name|CGAM
parameter_list|)
function_decl|;
comment|/// \brief Registers all available function analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c
comment|/// FunctionAnalysisManager with all registered function analyses. Callers can
comment|/// still manually register any additional analyses.
name|void
name|registerFunctionAnalyses
parameter_list|(
name|FunctionAnalysisManager
modifier|&
name|FAM
parameter_list|)
function_decl|;
comment|/// \brief Parse a textual pass pipeline description into a \c ModulePassManager.
comment|///
comment|/// The format of the textual pass pipeline description looks something like:
comment|///
comment|///   module(function(instcombine,sroa),dce,cgscc(inliner,function(...)),...)
comment|///
comment|/// Pass managers have ()s describing the nest structure of passes. All passes
comment|/// are comma separated. As a special shortcut, if the very first pass is not
comment|/// a module pass (as a module pass manager is), this will automatically form
comment|/// the shortest stack of pass managers that allow inserting that first pass.
comment|/// So, assuming function passes 'fpassN', CGSCC passes 'cgpassN', and loop passes
comment|/// 'lpassN', all of these are valid:
comment|///
comment|///   fpass1,fpass2,fpass3
comment|///   cgpass1,cgpass2,cgpass3
comment|///   lpass1,lpass2,lpass3
comment|///
comment|/// And they are equivalent to the following (resp.):
comment|///
comment|///   module(function(fpass1,fpass2,fpass3))
comment|///   module(cgscc(cgpass1,cgpass2,cgpass3))
comment|///   module(function(loop(lpass1,lpass2,lpass3)))
comment|///
comment|/// This shortcut is especially useful for debugging and testing small pass
comment|/// combinations. Note that these shortcuts don't introduce any other magic. If
comment|/// the sequence of passes aren't all the exact same kind of pass, it will be
comment|/// an error. You cannot mix different levels implicitly, you must explicitly
comment|/// form a pass manager in which to nest passes.
name|bool
name|parsePassPipeline
parameter_list|(
name|ModulePassManager
modifier|&
name|MPM
parameter_list|,
name|StringRef
name|PipelineText
parameter_list|,
name|bool
name|VerifyEachPass
init|=
name|true
parameter_list|,
name|bool
name|DebugLogging
init|=
name|false
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

