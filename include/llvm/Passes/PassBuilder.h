begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Parsing, selection, and construction of pass pipelines --*- C++ -*--===//
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
comment|/// Interfaces for registering analysis passes, producing common pass manager
end_comment

begin_comment
comment|/// configurations, and parsing of pass pipelines.
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
name|LLVM_PASSES_PASSBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PASSES_PASSBUILDER_H
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
name|class
name|TargetMachine
decl_stmt|;
comment|/// \brief This class provides access to building LLVM's passes.
comment|///
comment|/// It's members provide the baseline state available to passes during their
comment|/// construction. The \c PassRegistry.def file specifies how to construct all
comment|/// of the built-in passes, and those may reference these members during
comment|/// construction.
name|class
name|PassBuilder
block|{
name|TargetMachine
modifier|*
name|TM
decl_stmt|;
name|public
label|:
name|explicit
name|PassBuilder
argument_list|(
name|TargetMachine
operator|*
name|TM
operator|=
name|nullptr
argument_list|)
operator|:
name|TM
argument_list|(
argument|TM
argument_list|)
block|{}
comment|/// \brief Registers all available module analysis passes.
comment|///
comment|/// This is an interface that can be used to populate a \c
comment|/// ModuleAnalysisManager with all registered module analyses. Callers can
comment|/// still manually register any additional analyses.
name|void
name|registerModuleAnalyses
argument_list|(
name|ModuleAnalysisManager
operator|&
name|MAM
argument_list|)
expr_stmt|;
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
name|private
label|:
name|bool
name|parseModulePassName
parameter_list|(
name|ModulePassManager
modifier|&
name|MPM
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|bool
name|parseCGSCCPassName
parameter_list|(
name|CGSCCPassManager
modifier|&
name|CGPM
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|bool
name|parseFunctionPassName
parameter_list|(
name|FunctionPassManager
modifier|&
name|FPM
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|bool
name|parseFunctionPassPipeline
parameter_list|(
name|FunctionPassManager
modifier|&
name|FPM
parameter_list|,
name|StringRef
modifier|&
name|PipelineText
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
name|bool
name|parseCGSCCPassPipeline
parameter_list|(
name|CGSCCPassManager
modifier|&
name|CGPM
parameter_list|,
name|StringRef
modifier|&
name|PipelineText
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
name|bool
name|parseModulePassPipeline
parameter_list|(
name|ModulePassManager
modifier|&
name|MPM
parameter_list|,
name|StringRef
modifier|&
name|PipelineText
parameter_list|,
name|bool
name|VerifyEachPass
parameter_list|,
name|bool
name|DebugLogging
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

