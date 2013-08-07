begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PathDiagnosticClients.h - Path Diagnostic Clients ------*- C++ -*-===//
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
comment|//  This file defines the interface to create different path diagostic clients.
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
name|LLVM_CLANG_GR_PATH_DIAGNOSTIC_CLIENTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_PATH_DIAGNOSTIC_CLIENTS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalyzerOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|PathDiagnosticConsumer
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|PathDiagnosticConsumer
operator|*
operator|>
name|PathDiagnosticConsumers
expr_stmt|;
define|#
directive|define
name|CREATE_CONSUMER
parameter_list|(
name|NAME
parameter_list|)
define|\
value|void create ## NAME ## DiagnosticConsumer(AnalyzerOptions&AnalyzerOpts,\                                           PathDiagnosticConsumers&C,\                                           const std::string& prefix,\                                           const Preprocessor&PP);
name|CREATE_CONSUMER
argument_list|(
argument|HTML
argument_list|)
name|CREATE_CONSUMER
argument_list|(
argument|Plist
argument_list|)
name|CREATE_CONSUMER
argument_list|(
argument|PlistMultiFile
argument_list|)
name|CREATE_CONSUMER
argument_list|(
argument|TextPath
argument_list|)
undef|#
directive|undef
name|CREATE_CONSUMER
block|}
comment|// end 'ento' namespace
block|}
end_decl_stmt

begin_comment
comment|// end 'clang' namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

