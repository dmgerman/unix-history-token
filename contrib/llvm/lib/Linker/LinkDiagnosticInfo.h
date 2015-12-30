begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LinkDiagnosticInfo.h -------------------------------------*- C++ -*-===//
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
name|LLVM_LIB_LINKER_LINK_DIAGNOSTIC_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_LINKER_LINK_DIAGNOSTIC_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LinkDiagnosticInfo
range|:
name|public
name|DiagnosticInfo
block|{
specifier|const
name|Twine
operator|&
name|Msg
block|;
name|public
operator|:
name|LinkDiagnosticInfo
argument_list|(
argument|DiagnosticSeverity Severity
argument_list|,
argument|const Twine&Msg
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

