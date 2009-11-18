begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ChainedDiagnosticClient.h - Chain Diagnostic Clients ---*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_FRONTEND_CHAINEDDIAGNOSTICCLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_CHAINEDDIAGNOSTICCLIENT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
comment|/// ChainedDiagnosticClient - Chain two diagnostic clients so that diagnostics
comment|/// go to the first client and then the second. The first diagnostic client
comment|/// should be the "primary" client, and will be used for computing whether the
comment|/// diagnostics should be included in counts.
name|class
name|ChainedDiagnosticClient
range|:
name|public
name|DiagnosticClient
block|{
name|llvm
operator|::
name|OwningPtr
operator|<
name|DiagnosticClient
operator|>
name|Primary
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|DiagnosticClient
operator|>
name|Secondary
block|;
name|public
operator|:
name|ChainedDiagnosticClient
argument_list|(
argument|DiagnosticClient *_Primary
argument_list|,
argument|DiagnosticClient *_Secondary
argument_list|)
block|{
name|Primary
operator|.
name|reset
argument_list|(
name|_Primary
argument_list|)
block|;
name|Secondary
operator|.
name|reset
argument_list|(
name|_Secondary
argument_list|)
block|;   }
name|virtual
name|void
name|BeginSourceFile
argument_list|(
argument|const LangOptions&LO
argument_list|,
argument|const Preprocessor *PP
argument_list|)
block|{
name|Primary
operator|->
name|BeginSourceFile
argument_list|(
name|LO
argument_list|,
name|PP
argument_list|)
block|;
name|Secondary
operator|->
name|BeginSourceFile
argument_list|(
name|LO
argument_list|,
name|PP
argument_list|)
block|;   }
name|virtual
name|void
name|EndSourceFile
argument_list|()
block|{
name|Secondary
operator|->
name|EndSourceFile
argument_list|()
block|;
name|Primary
operator|->
name|EndSourceFile
argument_list|()
block|;   }
name|virtual
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
block|{
return|return
name|Primary
operator|->
name|IncludeInDiagnosticCounts
argument_list|()
return|;
block|}
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|Diagnostic::Level DiagLevel
argument_list|,
argument|const DiagnosticInfo&Info
argument_list|)
block|{
name|Primary
operator|->
name|HandleDiagnostic
argument_list|(
name|DiagLevel
argument_list|,
name|Info
argument_list|)
block|;
name|Secondary
operator|->
name|HandleDiagnostic
argument_list|(
name|DiagLevel
argument_list|,
name|Info
argument_list|)
block|;   }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namspace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

