begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DomPrinter.h - Dom printer external interface ------------*- C++ -*-===//
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
comment|// instantiate the dominance tree printer.
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
name|LLVM_ANALYSIS_DOMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_DOMPRINTER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|FunctionPass
modifier|*
name|createDomPrinterPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createDomOnlyPrinterPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createDomViewerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createDomOnlyViewerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPostDomPrinterPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPostDomOnlyPrinterPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPostDomViewerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPostDomOnlyViewerPass
parameter_list|()
function_decl|;
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

