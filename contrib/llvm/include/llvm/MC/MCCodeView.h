begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCCodeView.h - Machine Code CodeView support -------------*- C++ -*-===//
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
comment|// Holds state from .cv_file and .cv_loc directives for later emission.
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
name|LLVM_MC_MCCODEVIEW_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCCODEVIEW_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCFragment.h"
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
name|class
name|MCContext
decl_stmt|;
name|class
name|MCObjectStreamer
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
comment|/// \brief Instances of this class represent the information from a
comment|/// .cv_loc directive.
name|class
name|MCCVLoc
block|{
name|uint32_t
name|FunctionId
decl_stmt|;
name|uint32_t
name|FileNum
decl_stmt|;
name|uint32_t
name|Line
decl_stmt|;
name|uint16_t
name|Column
decl_stmt|;
name|uint16_t
name|PrologueEnd
range|:
literal|1
decl_stmt|;
name|uint16_t
name|IsStmt
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|// MCContext manages these
name|friend
name|class
name|MCContext
decl_stmt|;
name|MCCVLoc
argument_list|(
argument|unsigned functionid
argument_list|,
argument|unsigned fileNum
argument_list|,
argument|unsigned line
argument_list|,
argument|unsigned column
argument_list|,
argument|bool prologueend
argument_list|,
argument|bool isstmt
argument_list|)
block|:
name|FunctionId
argument_list|(
name|functionid
argument_list|)
operator|,
name|FileNum
argument_list|(
name|fileNum
argument_list|)
operator|,
name|Line
argument_list|(
name|line
argument_list|)
operator|,
name|Column
argument_list|(
name|column
argument_list|)
operator|,
name|PrologueEnd
argument_list|(
name|prologueend
argument_list|)
operator|,
name|IsStmt
argument_list|(
argument|isstmt
argument_list|)
block|{}
comment|// Allow the default copy constructor and assignment operator to be used
comment|// for an MCCVLoc object.
name|public
operator|:
name|unsigned
name|getFunctionId
argument_list|()
specifier|const
block|{
return|return
name|FunctionId
return|;
block|}
comment|/// \brief Get the FileNum of this MCCVLoc.
name|unsigned
name|getFileNum
argument_list|()
specifier|const
block|{
return|return
name|FileNum
return|;
block|}
comment|/// \brief Get the Line of this MCCVLoc.
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
comment|/// \brief Get the Column of this MCCVLoc.
name|unsigned
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
name|bool
name|isPrologueEnd
argument_list|()
specifier|const
block|{
return|return
name|PrologueEnd
return|;
block|}
name|bool
name|isStmt
argument_list|()
specifier|const
block|{
return|return
name|IsStmt
return|;
block|}
name|void
name|setFunctionId
parameter_list|(
name|unsigned
name|FID
parameter_list|)
block|{
name|FunctionId
operator|=
name|FID
expr_stmt|;
block|}
comment|/// \brief Set the FileNum of this MCCVLoc.
name|void
name|setFileNum
parameter_list|(
name|unsigned
name|fileNum
parameter_list|)
block|{
name|FileNum
operator|=
name|fileNum
expr_stmt|;
block|}
comment|/// \brief Set the Line of this MCCVLoc.
name|void
name|setLine
parameter_list|(
name|unsigned
name|line
parameter_list|)
block|{
name|Line
operator|=
name|line
expr_stmt|;
block|}
comment|/// \brief Set the Column of this MCCVLoc.
name|void
name|setColumn
parameter_list|(
name|unsigned
name|column
parameter_list|)
block|{
name|assert
argument_list|(
name|column
operator|<=
name|UINT16_MAX
argument_list|)
expr_stmt|;
name|Column
operator|=
name|column
expr_stmt|;
block|}
name|void
name|setPrologueEnd
parameter_list|(
name|bool
name|PE
parameter_list|)
block|{
name|PrologueEnd
operator|=
name|PE
expr_stmt|;
block|}
name|void
name|setIsStmt
parameter_list|(
name|bool
name|IS
parameter_list|)
block|{
name|IsStmt
operator|=
name|IS
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// \brief Instances of this class represent the line information for
comment|/// the CodeView line table entries.  Which is created after a machine
comment|/// instruction is assembled and uses an address from a temporary label
comment|/// created at the current address in the current section and the info from
comment|/// the last .cv_loc directive seen as stored in the context.
name|class
name|MCCVLineEntry
range|:
name|public
name|MCCVLoc
block|{
specifier|const
name|MCSymbol
operator|*
name|Label
block|;
name|private
operator|:
comment|// Allow the default copy constructor and assignment operator to be used
comment|// for an MCCVLineEntry object.
name|public
operator|:
comment|// Constructor to create an MCCVLineEntry given a symbol and the dwarf loc.
name|MCCVLineEntry
argument_list|(
argument|const MCSymbol *Label
argument_list|,
argument|const MCCVLoc loc
argument_list|)
operator|:
name|MCCVLoc
argument_list|(
name|loc
argument_list|)
block|,
name|Label
argument_list|(
argument|Label
argument_list|)
block|{}
specifier|const
name|MCSymbol
operator|*
name|getLabel
argument_list|()
specifier|const
block|{
return|return
name|Label
return|;
block|}
comment|// This is called when an instruction is assembled into the specified
comment|// section and if there is information from the last .cv_loc directive that
comment|// has yet to have a line entry made for it is made.
specifier|static
name|void
name|Make
argument_list|(
name|MCObjectStreamer
operator|*
name|MCOS
argument_list|)
block|; }
decl_stmt|;
comment|/// Holds state from .cv_file and .cv_loc directives for later emission.
name|class
name|CodeViewContext
block|{
name|public
label|:
name|CodeViewContext
argument_list|()
expr_stmt|;
operator|~
name|CodeViewContext
argument_list|()
expr_stmt|;
name|bool
name|isValidFileNumber
argument_list|(
name|unsigned
name|FileNumber
argument_list|)
decl|const
decl_stmt|;
name|bool
name|addFile
parameter_list|(
name|unsigned
name|FileNumber
parameter_list|,
name|StringRef
name|Filename
parameter_list|)
function_decl|;
name|ArrayRef
operator|<
name|StringRef
operator|>
name|getFilenames
argument_list|()
block|{
return|return
name|Filenames
return|;
block|}
comment|/// \brief Add a line entry.
name|void
name|addLineEntry
parameter_list|(
specifier|const
name|MCCVLineEntry
modifier|&
name|LineEntry
parameter_list|)
block|{
name|size_t
name|Offset
init|=
name|MCCVLines
operator|.
name|size
argument_list|()
decl_stmt|;
name|auto
name|I
init|=
name|MCCVLineStartStop
operator|.
name|insert
argument_list|(
block|{
name|LineEntry
operator|.
name|getFunctionId
argument_list|()
block|,
block|{
name|Offset
block|,
name|Offset
operator|+
literal|1
block|}
block|}
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|I
operator|.
name|second
condition|)
name|I
operator|.
name|first
operator|->
name|second
operator|.
name|second
operator|=
name|Offset
operator|+
literal|1
expr_stmt|;
name|MCCVLines
operator|.
name|push_back
argument_list|(
name|LineEntry
argument_list|)
expr_stmt|;
block|}
name|std
operator|::
name|vector
operator|<
name|MCCVLineEntry
operator|>
name|getFunctionLineEntries
argument_list|(
argument|unsigned FuncId
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|MCCVLineEntry
operator|>
name|FilteredLines
block|;
name|auto
name|I
operator|=
name|MCCVLineStartStop
operator|.
name|find
argument_list|(
name|FuncId
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|MCCVLineStartStop
operator|.
name|end
argument_list|()
condition|)
for|for
control|(
name|size_t
name|Idx
init|=
name|I
operator|->
name|second
operator|.
name|first
init|,
name|End
init|=
name|I
operator|->
name|second
operator|.
name|second
init|;
name|Idx
operator|!=
name|End
condition|;
operator|++
name|Idx
control|)
if|if
condition|(
name|MCCVLines
index|[
name|Idx
index|]
operator|.
name|getFunctionId
argument_list|()
operator|==
name|FuncId
condition|)
name|FilteredLines
operator|.
name|push_back
argument_list|(
name|MCCVLines
index|[
name|Idx
index|]
argument_list|)
expr_stmt|;
return|return
name|FilteredLines
return|;
block|}
name|std
operator|::
name|pair
operator|<
name|size_t
operator|,
name|size_t
operator|>
name|getLineExtent
argument_list|(
argument|unsigned FuncId
argument_list|)
block|{
name|auto
name|I
operator|=
name|MCCVLineStartStop
operator|.
name|find
argument_list|(
name|FuncId
argument_list|)
block|;
comment|// Return an empty extent if there are no cv_locs for this function id.
if|if
condition|(
name|I
operator|==
name|MCCVLineStartStop
operator|.
name|end
argument_list|()
condition|)
return|return
block|{
operator|~
literal|0ULL
block|,
literal|0
block|}
return|;
return|return
name|I
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|ArrayRef
operator|<
name|MCCVLineEntry
operator|>
name|getLinesForExtent
argument_list|(
argument|size_t L
argument_list|,
argument|size_t R
argument_list|)
block|{
if|if
condition|(
name|R
operator|<=
name|L
condition|)
return|return
name|None
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|L
operator|>=
name|MCCVLines
operator|.
name|size
argument_list|()
condition|)
return|return
name|None
return|;
end_if

begin_return
return|return
name|makeArrayRef
argument_list|(
operator|&
name|MCCVLines
index|[
name|L
index|]
argument_list|,
name|R
operator|-
name|L
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Emits a line table substream.
end_comment

begin_macro
unit|void
name|emitLineTableForFunction
argument_list|(
argument|MCObjectStreamer&OS
argument_list|,
argument|unsigned FuncId
argument_list|,
argument|const MCSymbol *FuncBegin
argument_list|,
argument|const MCSymbol *FuncEnd
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|emitInlineLineTableForFunction
argument_list|(
name|MCObjectStreamer
operator|&
name|OS
argument_list|,
name|unsigned
name|PrimaryFunctionId
argument_list|,
name|unsigned
name|SourceFileId
argument_list|,
name|unsigned
name|SourceLineNum
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|FnStartSym
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|FnEndSym
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|SecondaryFunctionIds
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Encodes the binary annotations once we have a layout.
end_comment

begin_function_decl
name|void
name|encodeInlineLineTable
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCCVInlineLineTableFragment
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|emitDefRange
argument_list|(
name|MCObjectStreamer
operator|&
name|OS
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSymbol
operator|*
argument_list|,
specifier|const
name|MCSymbol
operator|*
operator|>>
name|Ranges
argument_list|,
name|StringRef
name|FixedSizePortion
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|encodeDefRange
parameter_list|(
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
name|MCCVDefRangeFragment
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emits the string table substream.
end_comment

begin_function_decl
name|void
name|emitStringTable
parameter_list|(
name|MCObjectStreamer
modifier|&
name|OS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emits the file checksum substream.
end_comment

begin_function_decl
name|void
name|emitFileChecksums
parameter_list|(
name|MCObjectStreamer
modifier|&
name|OS
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Map from string to string table offset.
end_comment

begin_expr_stmt
name|StringMap
operator|<
name|unsigned
operator|>
name|StringTable
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The fragment that ultimately holds our strings.
end_comment

begin_decl_stmt
name|MCDataFragment
modifier|*
name|StrTabFragment
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|InsertedStrTabFragment
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function_decl
name|MCDataFragment
modifier|*
name|getStringTableFragment
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Add something to the string table.
end_comment

begin_function_decl
name|StringRef
name|addToStringTable
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get a string table offset.
end_comment

begin_function_decl
name|unsigned
name|getStringTableOffset
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// An array of absolute paths. Eventually this may include the file checksum.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|StringRef
operator|,
literal|4
operator|>
name|Filenames
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The offset of the first and last .cv_loc directive for a given function
end_comment

begin_comment
comment|/// id.
end_comment

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|std
operator|::
name|pair
operator|<
name|size_t
operator|,
name|size_t
operator|>>
name|MCCVLineStartStop
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A collection of MCCVLineEntry for each section.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|MCCVLineEntry
operator|>
name|MCCVLines
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

