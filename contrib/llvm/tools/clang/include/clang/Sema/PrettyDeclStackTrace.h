begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PrettyDeclStackTrace.h - Stack trace for decl processing -*- C++ -*-===//
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
comment|// This file defines an llvm::PrettyStackTraceEntry object for showing
end_comment

begin_comment
comment|// that a particular declaration was being processed when a crash
end_comment

begin_comment
comment|// occurred.
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
name|LLVM_CLANG_SEMA_PRETTYDECLSTACKTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_PRETTYDECLSTACKTRACE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PrettyStackTrace.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
comment|/// PrettyDeclStackTraceEntry - If a crash occurs in the parser while
comment|/// parsing something related to a declaration, include that
comment|/// declaration in the stack trace.
name|class
name|PrettyDeclStackTraceEntry
range|:
name|public
name|llvm
operator|::
name|PrettyStackTraceEntry
block|{
name|Sema
operator|&
name|S
block|;
name|Decl
operator|*
name|TheDecl
block|;
name|SourceLocation
name|Loc
block|;
specifier|const
name|char
operator|*
name|Message
block|;
name|public
operator|:
name|PrettyDeclStackTraceEntry
argument_list|(
argument|Sema&S
argument_list|,
argument|Decl *D
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const char *Msg
argument_list|)
operator|:
name|S
argument_list|(
name|S
argument_list|)
block|,
name|TheDecl
argument_list|(
name|D
argument_list|)
block|,
name|Loc
argument_list|(
name|Loc
argument_list|)
block|,
name|Message
argument_list|(
argument|Msg
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
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

