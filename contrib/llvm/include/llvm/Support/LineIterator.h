begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LineIterator.h - Iterator to read a text buffer's lines --*- C++ -*-===//
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
name|LLVM_SUPPORT_LINEITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_LINEITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
comment|/// \brief A forward iterator which reads text lines from a buffer.
comment|///
comment|/// This class provides a forward iterator interface for reading one line at
comment|/// a time from a buffer. When default constructed the iterator will be the
comment|/// "end" iterator.
comment|///
comment|/// The iterator is aware of what line number it is currently processing. It
comment|/// strips blank lines by default, and comment lines given a comment-starting
comment|/// character.
comment|///
comment|/// Note that this iterator requires the buffer to be nul terminated.
name|class
name|line_iterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
decl_stmt|,
name|StringRef
decl|>
block|{
specifier|const
name|MemoryBuffer
modifier|*
name|Buffer
decl_stmt|;
name|char
name|CommentMarker
decl_stmt|;
name|bool
name|SkipBlanks
decl_stmt|;
name|unsigned
name|LineNumber
decl_stmt|;
name|StringRef
name|CurrentLine
decl_stmt|;
name|public
label|:
comment|/// \brief Default construct an "end" iterator.
name|line_iterator
argument_list|()
operator|:
name|Buffer
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Construct a new iterator around some memory buffer.
name|explicit
name|line_iterator
argument_list|(
argument|const MemoryBuffer&Buffer
argument_list|,
argument|bool SkipBlanks = true
argument_list|,
argument|char CommentMarker =
literal|'\0'
argument_list|)
expr_stmt|;
comment|/// \brief Return true if we've reached EOF or are an "end" iterator.
name|bool
name|is_at_eof
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Buffer
return|;
block|}
comment|/// \brief Return true if we're an "end" iterator or have reached EOF.
name|bool
name|is_at_end
argument_list|()
specifier|const
block|{
return|return
name|is_at_eof
argument_list|()
return|;
block|}
comment|/// \brief Return the current line number. May return any number at EOF.
name|int64_t
name|line_number
argument_list|()
specifier|const
block|{
return|return
name|LineNumber
return|;
block|}
comment|/// \brief Advance to the next (non-empty, non-comment) line.
name|line_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|advance
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|line_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|line_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|advance
argument_list|()
block|;
return|return
name|tmp
return|;
block|}
comment|/// \brief Get the current line as a \c StringRef.
name|StringRef
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|CurrentLine
return|;
block|}
specifier|const
name|StringRef
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|CurrentLine
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|line_iterator
operator|&
name|LHS
operator|,
specifier|const
name|line_iterator
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Buffer
operator|==
name|RHS
operator|.
name|Buffer
operator|&&
name|LHS
operator|.
name|CurrentLine
operator|.
name|begin
argument_list|()
operator|==
name|RHS
operator|.
name|CurrentLine
operator|.
name|begin
argument_list|()
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|line_iterator
operator|&
name|LHS
operator|,
specifier|const
name|line_iterator
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
name|private
label|:
comment|/// \brief Advance the iterator to the next line.
name|void
name|advance
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

