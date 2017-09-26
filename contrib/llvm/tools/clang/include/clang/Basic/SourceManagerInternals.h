begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SourceManagerInternals.h - SourceManager Internals -----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines implementation details of the clang::SourceManager class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_SOURCEMANAGERINTERNALS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_SOURCEMANAGERINTERNALS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|//===----------------------------------------------------------------------===//
comment|// Line Table Implementation
comment|//===----------------------------------------------------------------------===//
struct|struct
name|LineEntry
block|{
comment|/// \brief The offset in this file that the line entry occurs at.
name|unsigned
name|FileOffset
decl_stmt|;
comment|/// \brief The presumed line number of this line entry: \#line 4.
name|unsigned
name|LineNo
decl_stmt|;
comment|/// \brief The ID of the filename identified by this line entry:
comment|/// \#line 4 "foo.c".  This is -1 if not specified.
name|int
name|FilenameID
decl_stmt|;
comment|/// \brief Set the 0 if no flags, 1 if a system header,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileKind
expr_stmt|;
comment|/// \brief The offset of the virtual include stack location,
comment|/// which is manipulated by GNU linemarker directives.
comment|///
comment|/// If this is 0 then there is no virtual \#includer.
name|unsigned
name|IncludeOffset
decl_stmt|;
specifier|static
name|LineEntry
name|get
argument_list|(
name|unsigned
name|Offs
argument_list|,
name|unsigned
name|Line
argument_list|,
name|int
name|Filename
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileKind
argument_list|,
name|unsigned
name|IncludeOffset
argument_list|)
block|{
name|LineEntry
name|E
decl_stmt|;
name|E
operator|.
name|FileOffset
operator|=
name|Offs
expr_stmt|;
name|E
operator|.
name|LineNo
operator|=
name|Line
expr_stmt|;
name|E
operator|.
name|FilenameID
operator|=
name|Filename
expr_stmt|;
name|E
operator|.
name|FileKind
operator|=
name|FileKind
expr_stmt|;
name|E
operator|.
name|IncludeOffset
operator|=
name|IncludeOffset
expr_stmt|;
return|return
name|E
return|;
block|}
block|}
struct|;
comment|// needed for FindNearestLineEntry (upper_bound of LineEntry)
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LineEntry
operator|&
name|lhs
operator|,
specifier|const
name|LineEntry
operator|&
name|rhs
operator|)
block|{
comment|// FIXME: should check the other field?
return|return
name|lhs
operator|.
name|FileOffset
operator|<
name|rhs
operator|.
name|FileOffset
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LineEntry
operator|&
name|E
operator|,
name|unsigned
name|Offset
operator|)
block|{
return|return
name|E
operator|.
name|FileOffset
operator|<
name|Offset
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|unsigned
name|Offset
operator|,
specifier|const
name|LineEntry
operator|&
name|E
operator|)
block|{
return|return
name|Offset
operator|<
name|E
operator|.
name|FileOffset
return|;
block|}
comment|/// \brief Used to hold and unique data used to represent \#line information.
name|class
name|LineTableInfo
block|{
comment|/// \brief Map used to assign unique IDs to filenames in \#line directives.
comment|///
comment|/// This allows us to unique the filenames that
comment|/// frequently reoccur and reference them with indices.  FilenameIDs holds
comment|/// the mapping from string -> ID, and FilenamesByID holds the mapping of ID
comment|/// to string.
name|llvm
operator|::
name|StringMap
operator|<
name|unsigned
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|FilenameIDs
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|StringMapEntry
operator|<
name|unsigned
operator|>
operator|*
operator|>
name|FilenamesByID
expr_stmt|;
comment|/// \brief Map from FileIDs to a list of line entries (sorted by the offset
comment|/// at which they occur in the file).
name|std
operator|::
name|map
operator|<
name|FileID
operator|,
name|std
operator|::
name|vector
operator|<
name|LineEntry
operator|>
expr|>
name|LineEntries
expr_stmt|;
name|public
label|:
name|void
name|clear
parameter_list|()
block|{
name|FilenameIDs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|FilenamesByID
operator|.
name|clear
argument_list|()
expr_stmt|;
name|LineEntries
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|unsigned
name|getLineTableFilenameID
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
name|StringRef
name|getFilename
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ID
operator|<
name|FilenamesByID
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid FilenameID"
argument_list|)
expr_stmt|;
return|return
name|FilenamesByID
index|[
name|ID
index|]
operator|->
name|getKey
argument_list|()
return|;
block|}
name|unsigned
name|getNumFilenames
argument_list|()
specifier|const
block|{
return|return
name|FilenamesByID
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|AddLineNote
argument_list|(
name|FileID
name|FID
argument_list|,
name|unsigned
name|Offset
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|int
name|FilenameID
argument_list|,
name|unsigned
name|EntryExit
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileKind
argument_list|)
decl_stmt|;
comment|/// \brief Find the line entry nearest to FID that is before it.
comment|///
comment|/// If there is no line entry before \p Offset in \p FID, returns null.
specifier|const
name|LineEntry
modifier|*
name|FindNearestLineEntry
parameter_list|(
name|FileID
name|FID
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
comment|// Low-level access
typedef|typedef
name|std
operator|::
name|map
operator|<
name|FileID
operator|,
name|std
operator|::
name|vector
operator|<
name|LineEntry
operator|>
expr|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|LineEntries
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|LineEntries
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Add a new line entry that has already been encoded into
comment|/// the internal representation of the line table.
name|void
name|AddEntry
argument_list|(
name|FileID
name|FID
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|LineEntry
operator|>
operator|&
name|Entries
argument_list|)
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

