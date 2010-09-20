begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCDwarf.h - Machine Code Dwarf support -------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCDwarfFile to support the dwarf
end_comment

begin_comment
comment|// .file directive.
end_comment

begin_comment
comment|// TODO: add the support needed for the .loc directive.
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
name|LLVM_MC_MCDWARF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCDWARF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|MCSection
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCDwarfFile - Instances of this class represent the name of the dwarf
comment|/// .file directive and its associated dwarf file number in the MC file,
comment|/// and MCDwarfFile's are created and unique'd by the MCContext class where
comment|/// the file number for each is its index into the vector of DwarfFiles (note
comment|/// index 0 is not used and not a valid dwarf file number).
name|class
name|MCDwarfFile
block|{
comment|// Name - the base name of the file without its directory path.
comment|// The StringRef references memory allocated in the MCContext.
name|StringRef
name|Name
decl_stmt|;
comment|// DirIndex - the index into the list of directory names for this file name.
name|unsigned
name|DirIndex
decl_stmt|;
name|private
label|:
comment|// MCContext creates and uniques these.
name|friend
name|class
name|MCContext
decl_stmt|;
name|MCDwarfFile
argument_list|(
argument|StringRef name
argument_list|,
argument|unsigned dirIndex
argument_list|)
block|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|DirIndex
argument_list|(
argument|dirIndex
argument_list|)
block|{}
name|MCDwarfFile
argument_list|(
specifier|const
name|MCDwarfFile
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCDwarfFile
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
comment|/// getName - Get the base name of this MCDwarfFile.
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getDirIndex - Get the dirIndex of this MCDwarfFile.
name|unsigned
name|getDirIndex
argument_list|()
specifier|const
block|{
return|return
name|DirIndex
return|;
block|}
comment|/// print - Print the value to the stream \arg OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Print the value to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MCDwarfFile
operator|&
name|DwarfFile
operator|)
block|{
name|DwarfFile
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
comment|/// MCDwarfLoc - Instances of this class represent the information from a
comment|/// dwarf .loc directive.
name|class
name|MCDwarfLoc
block|{
comment|// FileNum - the file number.
name|unsigned
name|FileNum
decl_stmt|;
comment|// Line - the line number.
name|unsigned
name|Line
decl_stmt|;
comment|// Column - the column position.
name|unsigned
name|Column
decl_stmt|;
comment|// Flags (see #define's below)
name|unsigned
name|Flags
decl_stmt|;
comment|// Isa
name|unsigned
name|Isa
decl_stmt|;
define|#
directive|define
name|DWARF2_FLAG_IS_STMT
value|(1<< 0)
define|#
directive|define
name|DWARF2_FLAG_BASIC_BLOCK
value|(1<< 1)
define|#
directive|define
name|DWARF2_FLAG_PROLOGUE_END
value|(1<< 2)
define|#
directive|define
name|DWARF2_FLAG_EPILOGUE_BEGIN
value|(1<< 3)
name|private
label|:
comment|// MCContext manages these
name|friend
name|class
name|MCContext
decl_stmt|;
name|friend
name|class
name|MCLineEntry
decl_stmt|;
name|MCDwarfLoc
argument_list|(
argument|unsigned fileNum
argument_list|,
argument|unsigned line
argument_list|,
argument|unsigned column
argument_list|,
argument|unsigned flags
argument_list|,
argument|unsigned isa
argument_list|)
block|:
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
name|Flags
argument_list|(
name|flags
argument_list|)
operator|,
name|Isa
argument_list|(
argument|isa
argument_list|)
block|{}
comment|// Allow the default copy constructor and assignment operator to be used
comment|// for an MCDwarfLoc object.
name|public
operator|:
comment|/// setFileNum - Set the FileNum of this MCDwarfLoc.
name|void
name|setFileNum
argument_list|(
argument|unsigned fileNum
argument_list|)
block|{
name|FileNum
operator|=
name|fileNum
block|; }
comment|/// setLine - Set the Line of this MCDwarfLoc.
name|void
name|setLine
argument_list|(
argument|unsigned line
argument_list|)
block|{
name|Line
operator|=
name|line
block|; }
comment|/// setColumn - Set the Column of this MCDwarfLoc.
name|void
name|setColumn
argument_list|(
argument|unsigned column
argument_list|)
block|{
name|Column
operator|=
name|column
block|; }
comment|/// setFlags - Set the Flags of this MCDwarfLoc.
name|void
name|setFlags
argument_list|(
argument|unsigned flags
argument_list|)
block|{
name|Flags
operator|=
name|flags
block|; }
comment|/// setIsa - Set the Isa of this MCDwarfLoc.
name|void
name|setIsa
argument_list|(
argument|unsigned isa
argument_list|)
block|{
name|Isa
operator|=
name|isa
block|; }
block|}
empty_stmt|;
comment|/// MCLineEntry - Instances of this class represent the line information for
comment|/// the dwarf line table entries.  Which is created after a machine
comment|/// instruction is assembled and uses an address from a temporary label
comment|/// created at the current address in the current section and the info from
comment|/// the last .loc directive seen as stored in the context.
name|class
name|MCLineEntry
range|:
name|public
name|MCDwarfLoc
block|{
name|MCSymbol
operator|*
name|Label
block|;
name|private
operator|:
comment|// Allow the default copy constructor and assignment operator to be used
comment|// for an MCLineEntry object.
name|public
operator|:
comment|// Constructor to create an MCLineEntry given a symbol and the dwarf loc.
name|MCLineEntry
argument_list|(
argument|MCSymbol *label
argument_list|,
argument|const MCDwarfLoc loc
argument_list|)
operator|:
name|MCDwarfLoc
argument_list|(
name|loc
argument_list|)
block|,
name|Label
argument_list|(
argument|label
argument_list|)
block|{}
block|}
decl_stmt|;
comment|/// MCLineSection - Instances of this class represent the line information
comment|/// for a section where machine instructions have been assembled after seeing
comment|/// .loc directives.  This is the information used to build the dwarf line
comment|/// table for a section.
name|class
name|MCLineSection
block|{
name|std
operator|::
name|vector
operator|<
name|MCLineEntry
operator|>
name|MCLineEntries
expr_stmt|;
name|private
label|:
name|MCLineSection
argument_list|(
specifier|const
name|MCLineSection
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCLineSection
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
comment|// Constructor to create an MCLineSection with an empty MCLineEntries
comment|// vector.
name|MCLineSection
argument_list|()
block|{}
comment|// addLineEntry - adds an entry to this MCLineSection's line entries
name|void
name|addLineEntry
parameter_list|(
specifier|const
name|MCLineEntry
modifier|&
name|LineEntry
parameter_list|)
block|{
name|MCLineEntries
operator|.
name|push_back
argument_list|(
name|LineEntry
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

