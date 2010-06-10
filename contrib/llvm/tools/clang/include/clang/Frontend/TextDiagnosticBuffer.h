begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TextDiagnosticBuffer.h - Buffer Text Diagnostics -------*- C++ -*-===//
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
comment|// This is a concrete diagnostic client, which buffers the diagnostic messages.
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
name|LLVM_CLANG_FRONTEND_TEXT_DIAGNOSTIC_BUFFER_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_TEXT_DIAGNOSTIC_BUFFER_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
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
name|Preprocessor
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TextDiagnosticBuffer
range|:
name|public
name|DiagnosticClient
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|std
operator|::
name|string
operator|>
expr|>
name|DiagList
expr_stmt|;
typedef|typedef
name|DiagList
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|DiagList
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|private
label|:
name|DiagList
name|Errors
decl_stmt|,
name|Warnings
decl_stmt|,
name|Notes
decl_stmt|;
name|public
label|:
name|const_iterator
name|err_begin
argument_list|()
specifier|const
block|{
return|return
name|Errors
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|err_end
argument_list|()
specifier|const
block|{
return|return
name|Errors
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|warn_begin
argument_list|()
specifier|const
block|{
return|return
name|Warnings
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|warn_end
argument_list|()
specifier|const
block|{
return|return
name|Warnings
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|note_begin
argument_list|()
specifier|const
block|{
return|return
name|Notes
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|note_end
argument_list|()
specifier|const
block|{
return|return
name|Notes
operator|.
name|end
argument_list|()
return|;
block|}
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
name|Diagnostic
operator|::
name|Level
name|DiagLevel
argument_list|,
specifier|const
name|DiagnosticInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
comment|/// FlushDiagnostics - Flush the buffered diagnostics to an given
comment|/// diagnostic engine.
name|void
name|FlushDiagnostics
argument_list|(
name|Diagnostic
operator|&
name|Diags
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namspace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

