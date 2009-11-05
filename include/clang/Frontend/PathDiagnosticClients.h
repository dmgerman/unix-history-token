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
name|LLVM_CLANG_FRONTEND_PATH_DIAGNOSTIC_CLIENTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PATH_DIAGNOSTIC_CLiENTS_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PathDiagnosticClient
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|PathDiagnosticClient
modifier|*
name|CreateHTMLDiagnosticClient
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|prefix
argument_list|,
specifier|const
name|Preprocessor
operator|&
name|PP
argument_list|)
decl_stmt|;
name|PathDiagnosticClient
modifier|*
name|CreatePlistDiagnosticClient
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|prefix
argument_list|,
specifier|const
name|Preprocessor
operator|&
name|PP
argument_list|,
name|PathDiagnosticClient
operator|*
name|SubPD
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

