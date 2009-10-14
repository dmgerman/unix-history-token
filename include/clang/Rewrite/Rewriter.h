begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Rewriter.h - Code rewriting interface ------------------*- C++ -*-===//
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
comment|//  This file defines the Rewriter class, which is used for code
end_comment

begin_comment
comment|//  transformations.
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
name|LLVM_CLANG_REWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/RewriteRope.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/DeltaTree.h"
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
name|SourceManager
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Rewriter
decl_stmt|;
name|class
name|Stmt
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
comment|/// Buffer - This is the actual buffer itself.  Note that using a vector or
comment|/// string is a horribly inefficient way to do this, we should use a rope
comment|/// instead.
typedef|typedef
name|RewriteRope
name|BufferTy
typedef|;
name|BufferTy
name|Buffer
decl_stmt|;
name|public
label|:
typedef|typedef
name|BufferTy
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
comment|/// RemoveText - Remove the specified text.
name|void
name|RemoveText
parameter_list|(
name|unsigned
name|OrigOffset
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// InsertText - Insert some text at the specified point, where the offset in
comment|/// the buffer is specified relative to the original SourceBuffer.  The
comment|/// text is inserted after the specified location.
comment|///
name|void
name|InsertText
argument_list|(
name|unsigned
name|OrigOffset
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Str
argument_list|,
name|bool
name|InsertAfter
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// InsertTextBefore - Insert some text before the specified point, where the
comment|/// offset in the buffer is specified relative to the original
comment|/// SourceBuffer. The text is inserted before the specified location.  This is
comment|/// method is the same as InsertText with "InsertAfter == false".
name|void
name|InsertTextBefore
argument_list|(
name|unsigned
name|OrigOffset
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Str
argument_list|)
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
argument_list|(
name|unsigned
name|OrigOffset
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Str
argument_list|)
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
argument_list|(
name|unsigned
name|OrigOffset
argument_list|,
name|unsigned
name|OrigLength
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|NewStr
argument_list|)
decl_stmt|;
name|private
label|:
comment|// Methods only usable by Rewriter.
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
comment|/// Rewriter - This is the main interface to the rewrite buffers.  Its primary
comment|/// job is to dispatch high-level requests to the low-level RewriteBuffers that
comment|/// are involved.
name|class
name|Rewriter
block|{
name|SourceManager
modifier|*
name|SourceMgr
decl_stmt|;
specifier|const
name|LangOptions
modifier|*
name|LangOpts
decl_stmt|;
name|std
operator|::
name|map
operator|<
name|FileID
operator|,
name|RewriteBuffer
operator|>
name|RewriteBuffers
expr_stmt|;
name|public
label|:
name|explicit
name|Rewriter
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LO
argument_list|)
operator|:
name|SourceMgr
argument_list|(
operator|&
name|SM
argument_list|)
operator|,
name|LangOpts
argument_list|(
argument|&LO
argument_list|)
block|{}
name|explicit
name|Rewriter
argument_list|()
operator|:
name|SourceMgr
argument_list|(
literal|0
argument_list|)
operator|,
name|LangOpts
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setSourceMgr
argument_list|(
argument|SourceManager&SM
argument_list|,
argument|const LangOptions&LO
argument_list|)
block|{
name|SourceMgr
operator|=
operator|&
name|SM
block|;
name|LangOpts
operator|=
operator|&
name|LO
block|;   }
name|SourceManager
operator|&
name|getSourceMgr
argument_list|()
block|{
return|return
operator|*
name|SourceMgr
return|;
block|}
specifier|const
name|LangOptions
modifier|&
name|getLangOpts
parameter_list|()
block|{
return|return
operator|*
name|LangOpts
return|;
block|}
comment|/// isRewritable - Return true if this location is a raw file location, which
comment|/// is rewritable.  Locations from macros, etc are not rewritable.
specifier|static
name|bool
name|isRewritable
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
return|return
name|Loc
operator|.
name|isFileID
argument_list|()
return|;
block|}
comment|/// getRangeSize - Return the size in bytes of the specified range if they
comment|/// are in the same file.  If not, this returns -1.
name|int
name|getRangeSize
argument_list|(
name|SourceRange
name|Range
argument_list|)
decl|const
decl_stmt|;
comment|/// getRewritenText - Return the rewritten form of the text in the specified
comment|/// range.  If the start or end of the range was unrewritable or if they are
comment|/// in different buffers, this returns an empty string.
comment|///
comment|/// Note that this method is not particularly efficient.
comment|///
name|std
operator|::
name|string
name|getRewritenText
argument_list|(
argument|SourceRange Range
argument_list|)
specifier|const
expr_stmt|;
comment|/// InsertText - Insert the specified string at the specified location in the
comment|/// original buffer.  This method returns true (and does nothing) if the input
comment|/// location was not rewritable, false otherwise.
name|bool
name|InsertText
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Str
argument_list|,
name|bool
name|InsertAfter
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// InsertTextAfter - Insert the specified string at the specified location in
comment|///  the original buffer.  This method returns true (and does nothing) if
comment|///  the input location was not rewritable, false otherwise.  Text is
comment|///  inserted after any other text that has been previously inserted
comment|///  at the some point (the default behavior for InsertText).
name|bool
name|InsertTextAfter
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Str
argument_list|)
block|{
return|return
name|InsertText
argument_list|(
name|Loc
argument_list|,
name|Str
argument_list|)
return|;
block|}
comment|/// InsertText - Insert the specified string at the specified location in the
comment|/// original buffer.  This method returns true (and does nothing) if the input
comment|/// location was not rewritable, false otherwise.  Text is
comment|/// inserted before any other text that has been previously inserted
comment|/// at the some point.
name|bool
name|InsertTextBefore
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Str
argument_list|)
block|{
return|return
name|InsertText
argument_list|(
name|Loc
argument_list|,
name|Str
argument_list|,
name|false
argument_list|)
return|;
block|}
comment|/// RemoveText - Remove the specified text region.
name|bool
name|RemoveText
parameter_list|(
name|SourceLocation
name|Start
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
comment|/// ReplaceText - This method replaces a range of characters in the input
comment|/// buffer with a new string.  This is effectively a combined "remove/insert"
comment|/// operation.
name|bool
name|ReplaceText
argument_list|(
name|SourceLocation
name|Start
argument_list|,
name|unsigned
name|OrigLength
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|NewStr
argument_list|)
decl_stmt|;
comment|/// ReplaceStmt - This replaces a Stmt/Expr with another, using the pretty
comment|/// printer to generate the replacement code.  This returns true if the input
comment|/// could not be rewritten, or false if successful.
name|bool
name|ReplaceStmt
parameter_list|(
name|Stmt
modifier|*
name|From
parameter_list|,
name|Stmt
modifier|*
name|To
parameter_list|)
function_decl|;
comment|/// getRewriteBufferFor - Return the rewrite buffer for the specified FileID.
comment|/// If no modification has been made to it, return null.
specifier|const
name|RewriteBuffer
modifier|*
name|getRewriteBufferFor
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|std
operator|::
name|map
operator|<
name|FileID
operator|,
name|RewriteBuffer
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|RewriteBuffers
operator|.
name|find
argument_list|(
name|FID
argument_list|)
expr_stmt|;
return|return
name|I
operator|==
name|RewriteBuffers
operator|.
name|end
argument_list|()
condition|?
literal|0
else|:
operator|&
name|I
operator|->
name|second
return|;
block|}
comment|/// getEditBuffer - This is like getRewriteBufferFor, but always returns a
comment|/// buffer, and allows you to write on it directly.  This is useful if you
comment|/// want efficient low-level access to apis for scribbling on one specific
comment|/// FileID's buffer.
name|RewriteBuffer
modifier|&
name|getEditBuffer
parameter_list|(
name|FileID
name|FID
parameter_list|)
function_decl|;
name|private
label|:
name|unsigned
name|getLocationOffsetAndFileID
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|FileID
operator|&
name|FID
argument_list|)
decl|const
decl_stmt|;
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

