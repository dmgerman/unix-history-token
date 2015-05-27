begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RewriteBuffer.h - Buffer rewriting interface -----------*- C++ -*-===//
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
name|LLVM_CLANG_REWRITE_CORE_REWRITEBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_CORE_REWRITEBUFFER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/Core/DeltaTree.h"
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/Core/RewriteRope.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Rewriter
decl_stmt|;
comment|/// RewriteBuffer - As code is rewritten, SourceBuffer's from the original
comment|/// input with modifications get a new RewriteBuffer associated with them.  The
comment|/// RewriteBuffer captures the modified text itself as well as information used
comment|/// to map between SourceLocation's in the original input and offsets in the
comment|/// RewriteBuffer.  For example, if text is inserted into the buffer, any
comment|/// locations after the insertion point have to be mapped.
name|class
name|RewriteBuffer
block|{
name|friend
name|class
name|Rewriter
decl_stmt|;
comment|/// Deltas - Keep track of all the deltas in the source code due to insertions
comment|/// and deletions.
name|DeltaTree
name|Deltas
decl_stmt|;
name|RewriteRope
name|Buffer
decl_stmt|;
name|public
label|:
typedef|typedef
name|RewriteRope
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Initialize - Start this rewrite buffer out with a copy of the unmodified
comment|/// input buffer.
name|void
name|Initialize
parameter_list|(
specifier|const
name|char
modifier|*
name|BufStart
parameter_list|,
specifier|const
name|char
modifier|*
name|BufEnd
parameter_list|)
block|{
name|Buffer
operator|.
name|assign
argument_list|(
name|BufStart
argument_list|,
name|BufEnd
argument_list|)
expr_stmt|;
block|}
name|void
name|Initialize
parameter_list|(
name|StringRef
name|Input
parameter_list|)
block|{
name|Initialize
argument_list|(
name|Input
operator|.
name|begin
argument_list|()
argument_list|,
name|Input
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Write to \p Stream the result of applying all changes to the
comment|/// original buffer.
comment|/// Note that it isn't safe to use this function to overwrite memory mapped
comment|/// files in-place (PR17960). Consider using a higher-level utility such as
comment|/// Rewriter::overwriteChangedFiles() instead.
comment|///
comment|/// The original buffer is not actually changed.
name|raw_ostream
modifier|&
name|write
argument_list|(
name|raw_ostream
operator|&
name|Stream
argument_list|)
decl|const
decl_stmt|;
comment|/// RemoveText - Remove the specified text.
name|void
name|RemoveText
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|bool
name|removeLineIfEmpty
init|=
name|false
parameter_list|)
function_decl|;
comment|/// InsertText - Insert some text at the specified point, where the offset in
comment|/// the buffer is specified relative to the original SourceBuffer.  The
comment|/// text is inserted after the specified location.
comment|///
name|void
name|InsertText
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|StringRef
name|Str
parameter_list|,
name|bool
name|InsertAfter
init|=
name|true
parameter_list|)
function_decl|;
comment|/// InsertTextBefore - Insert some text before the specified point, where the
comment|/// offset in the buffer is specified relative to the original
comment|/// SourceBuffer. The text is inserted before the specified location.  This is
comment|/// method is the same as InsertText with "InsertAfter == false".
name|void
name|InsertTextBefore
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|StringRef
name|Str
parameter_list|)
block|{
name|InsertText
argument_list|(
name|OrigOffset
argument_list|,
name|Str
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
comment|/// InsertTextAfter - Insert some text at the specified point, where the
comment|/// offset in the buffer is specified relative to the original SourceBuffer.
comment|/// The text is inserted after the specified location.
name|void
name|InsertTextAfter
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|StringRef
name|Str
parameter_list|)
block|{
name|InsertText
argument_list|(
name|OrigOffset
argument_list|,
name|Str
argument_list|)
expr_stmt|;
block|}
comment|/// ReplaceText - This method replaces a range of characters in the input
comment|/// buffer with a new string.  This is effectively a combined "remove/insert"
comment|/// operation.
name|void
name|ReplaceText
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|unsigned
name|OrigLength
parameter_list|,
name|StringRef
name|NewStr
parameter_list|)
function_decl|;
name|private
label|:
comment|// Methods only usable by Rewriter.
comment|/// getMappedOffset - Given an offset into the original SourceBuffer that this
comment|/// RewriteBuffer is based on, map it into the offset space of the
comment|/// RewriteBuffer.  If AfterInserts is true and if the OrigOffset indicates a
comment|/// position where text is inserted, the location returned will be after any
comment|/// inserted text at the position.
name|unsigned
name|getMappedOffset
argument_list|(
name|unsigned
name|OrigOffset
argument_list|,
name|bool
name|AfterInserts
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|Deltas
operator|.
name|getDeltaAt
argument_list|(
literal|2
operator|*
name|OrigOffset
operator|+
name|AfterInserts
argument_list|)
operator|+
name|OrigOffset
return|;
block|}
comment|/// AddInsertDelta - When an insertion is made at a position, this
comment|/// method is used to record that information.
name|void
name|AddInsertDelta
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|int
name|Change
parameter_list|)
block|{
return|return
name|Deltas
operator|.
name|AddDelta
argument_list|(
literal|2
operator|*
name|OrigOffset
argument_list|,
name|Change
argument_list|)
return|;
block|}
comment|/// AddReplaceDelta - When a replacement/deletion is made at a position, this
comment|/// method is used to record that information.
name|void
name|AddReplaceDelta
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|int
name|Change
parameter_list|)
block|{
return|return
name|Deltas
operator|.
name|AddDelta
argument_list|(
literal|2
operator|*
name|OrigOffset
operator|+
literal|1
argument_list|,
name|Change
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

