begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SequenceToOffsetTable.h - Compress similar sequences ----*- C++ -*-===//
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
comment|// SequenceToOffsetTable can be used to emit a number of null-terminated
end_comment

begin_comment
comment|// sequences as one big array.  Use the same memory when a sequence is a suffix
end_comment

begin_comment
comment|// of another.
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
name|TBLGEN_SEQUENCE_TO_OFFSET_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|TBLGEN_SEQUENCE_TO_OFFSET_TABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cctype>
end_include

begin_include
include|#
directive|include
file|<functional>
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SequenceToOffsetTable - Collect a number of terminated sequences of T.
comment|/// Compute the layout of a table that contains all the sequences, possibly by
comment|/// reusing entries.
comment|///
comment|/// @tparam SeqT The sequence container. (vector or string).
comment|/// @tparam Less A stable comparator for SeqT elements.
name|template
operator|<
name|typename
name|SeqT
operator|,
name|typename
name|Less
operator|=
name|std
operator|::
name|less
operator|<
name|typename
name|SeqT
operator|::
name|value_type
operator|>
expr|>
name|class
name|SequenceToOffsetTable
block|{
typedef|typedef
name|typename
name|SeqT
operator|::
name|value_type
name|ElemT
expr_stmt|;
comment|// Define a comparator for SeqT that sorts a suffix immediately before a
comment|// sequence with that suffix.
block|struct
name|SeqLess
operator|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|SeqT
operator|,
name|SeqT
operator|,
name|bool
operator|>
block|{
name|Less
name|L
block|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|SeqT
operator|&
name|A
operator|,
specifier|const
name|SeqT
operator|&
name|B
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|lexicographical_compare
argument_list|(
name|A
operator|.
name|rbegin
argument_list|()
argument_list|,
name|A
operator|.
name|rend
argument_list|()
argument_list|,
name|B
operator|.
name|rbegin
argument_list|()
argument_list|,
name|B
operator|.
name|rend
argument_list|()
argument_list|,
name|L
argument_list|)
return|;
block|}
expr|}
block|;
comment|// Keep sequences ordered according to SeqLess so suffixes are easy to find.
comment|// Map each sequence to its offset in the table.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|SeqT
operator|,
name|unsigned
operator|,
name|SeqLess
operator|>
name|SeqMap
expr_stmt|;
comment|// Sequences added so far, with suffixes removed.
name|SeqMap
name|Seqs
expr_stmt|;
comment|// Entries in the final table, or 0 before layout was called.
name|unsigned
name|Entries
decl_stmt|;
comment|// isSuffix - Returns true if A is a suffix of B.
specifier|static
name|bool
name|isSuffix
parameter_list|(
specifier|const
name|SeqT
modifier|&
name|A
parameter_list|,
specifier|const
name|SeqT
modifier|&
name|B
parameter_list|)
block|{
return|return
name|A
operator|.
name|size
argument_list|()
operator|<=
name|B
operator|.
name|size
argument_list|()
operator|&&
name|std
operator|::
name|equal
argument_list|(
name|A
operator|.
name|rbegin
argument_list|()
argument_list|,
name|A
operator|.
name|rend
argument_list|()
argument_list|,
name|B
operator|.
name|rbegin
argument_list|()
argument_list|)
return|;
block|}
name|public
label|:
name|SequenceToOffsetTable
argument_list|()
operator|:
name|Entries
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// add - Add a sequence to the table.
comment|/// This must be called before layout().
name|void
name|add
argument_list|(
argument|const SeqT&Seq
argument_list|)
block|{
name|assert
argument_list|(
name|Entries
operator|==
literal|0
operator|&&
literal|"Cannot call add() after layout()"
argument_list|)
block|;
name|typename
name|SeqMap
operator|::
name|iterator
name|I
operator|=
name|Seqs
operator|.
name|lower_bound
argument_list|(
name|Seq
argument_list|)
block|;
comment|// If SeqMap contains a sequence that has Seq as a suffix, I will be
comment|// pointing to it.
if|if
condition|(
name|I
operator|!=
name|Seqs
operator|.
name|end
argument_list|()
operator|&&
name|isSuffix
argument_list|(
name|Seq
argument_list|,
name|I
operator|->
name|first
argument_list|)
condition|)
return|return;
name|I
operator|=
name|Seqs
operator|.
name|insert
argument_list|(
name|I
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|Seq
argument_list|,
literal|0u
argument_list|)
argument_list|)
expr_stmt|;
comment|// The entry before I may be a suffix of Seq that can now be erased.
if|if
condition|(
name|I
operator|!=
name|Seqs
operator|.
name|begin
argument_list|()
operator|&&
name|isSuffix
argument_list|(
operator|(
operator|--
name|I
operator|)
operator|->
name|first
argument_list|,
name|Seq
argument_list|)
condition|)
name|Seqs
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Seqs
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// layout - Computes the final table layout.
end_comment

begin_function
name|void
name|layout
parameter_list|()
block|{
name|assert
argument_list|(
name|Entries
operator|==
literal|0
operator|&&
literal|"Can only call layout() once"
argument_list|)
expr_stmt|;
comment|// Lay out the table in Seqs iteration order.
for|for
control|(
name|typename
name|SeqMap
operator|::
name|iterator
name|I
operator|=
name|Seqs
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Seqs
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|I
operator|->
name|second
operator|=
name|Entries
expr_stmt|;
comment|// Include space for a terminator.
name|Entries
operator|+=
name|I
operator|->
name|first
operator|.
name|size
argument_list|()
operator|+
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// get - Returns the offset of Seq in the final table.
end_comment

begin_decl_stmt
name|unsigned
name|get
argument_list|(
specifier|const
name|SeqT
operator|&
name|Seq
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Entries
operator|&&
literal|"Call layout() before get()"
argument_list|)
expr_stmt|;
name|typename
name|SeqMap
operator|::
name|const_iterator
name|I
operator|=
name|Seqs
operator|.
name|lower_bound
argument_list|(
name|Seq
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|Seqs
operator|.
name|end
argument_list|()
operator|&&
name|isSuffix
argument_list|(
name|Seq
argument_list|,
name|I
operator|->
name|first
argument_list|)
operator|&&
literal|"get() called with sequence that wasn't added first"
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
operator|+
operator|(
name|I
operator|->
name|first
operator|.
name|size
argument_list|()
operator|-
name|Seq
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// emit - Print out the table as the body of an array initializer.
end_comment

begin_comment
comment|/// Use the Print function to print elements.
end_comment

begin_decl_stmt
name|void
name|emit
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|void
argument_list|(
operator|*
name|Print
argument_list|)
argument_list|(
name|raw_ostream
operator|&
argument_list|,
name|ElemT
argument_list|)
argument_list|,
specifier|const
name|char
operator|*
name|Term
operator|=
literal|"0"
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Entries
operator|&&
literal|"Call layout() before emit()"
argument_list|)
expr_stmt|;
for|for
control|(
name|typename
name|SeqMap
operator|::
name|const_iterator
name|I
operator|=
name|Seqs
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Seqs
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|OS
operator|<<
literal|"  /* "
operator|<<
name|I
operator|->
name|second
operator|<<
literal|" */ "
expr_stmt|;
for|for
control|(
name|typename
name|SeqT
operator|::
name|const_iterator
name|SI
operator|=
name|I
operator|->
name|first
operator|.
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|I
operator|->
name|first
operator|.
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
block|{
name|Print
argument_list|(
name|OS
argument_list|,
operator|*
name|SI
argument_list|)
expr_stmt|;
name|OS
operator|<<
literal|", "
expr_stmt|;
block|}
name|OS
operator|<<
name|Term
operator|<<
literal|",\n"
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
unit|};
comment|// Helper function for SequenceToOffsetTable<string>.
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|printChar
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|char
name|C
parameter_list|)
block|{
name|unsigned
name|char
name|UC
argument_list|(
name|C
argument_list|)
decl_stmt|;
if|if
condition|(
name|isalnum
argument_list|(
name|UC
argument_list|)
operator|||
name|ispunct
argument_list|(
name|UC
argument_list|)
condition|)
block|{
name|OS
operator|<<
literal|'\''
expr_stmt|;
if|if
condition|(
name|C
operator|==
literal|'\\'
operator|||
name|C
operator|==
literal|'\''
condition|)
name|OS
operator|<<
literal|'\\'
expr_stmt|;
name|OS
operator|<<
name|C
operator|<<
literal|'\''
expr_stmt|;
block|}
else|else
block|{
name|OS
operator|<<
name|unsigned
argument_list|(
name|UC
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

