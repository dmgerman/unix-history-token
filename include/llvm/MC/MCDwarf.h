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
comment|// .file directive and the .loc directive.
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
file|"llvm/CodeGen/MachineLocation.h"
end_include

begin_comment
comment|// FIXME
end_comment

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Dwarf.h"
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
name|MachineMove
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSectionData
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCObjectStreamer
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
comment|// Discriminator
name|unsigned
name|Discriminator
decl_stmt|;
comment|// Flag that indicates the initial value of the is_stmt_start flag.
define|#
directive|define
name|DWARF2_LINE_DEFAULT_IS_STMT
value|1
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
argument_list|,
argument|unsigned discriminator
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
name|isa
argument_list|)
operator|,
name|Discriminator
argument_list|(
argument|discriminator
argument_list|)
block|{}
comment|// Allow the default copy constructor and assignment operator to be used
comment|// for an MCDwarfLoc object.
name|public
operator|:
comment|/// getFileNum - Get the FileNum of this MCDwarfLoc.
name|unsigned
name|getFileNum
argument_list|()
specifier|const
block|{
return|return
name|FileNum
return|;
block|}
comment|/// getLine - Get the Line of this MCDwarfLoc.
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
comment|/// getColumn - Get the Column of this MCDwarfLoc.
name|unsigned
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
comment|/// getFlags - Get the Flags of this MCDwarfLoc.
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// getIsa - Get the Isa of this MCDwarfLoc.
name|unsigned
name|getIsa
argument_list|()
specifier|const
block|{
return|return
name|Isa
return|;
block|}
comment|/// getDiscriminator - Get the Discriminator of this MCDwarfLoc.
name|unsigned
name|getDiscriminator
argument_list|()
specifier|const
block|{
return|return
name|Discriminator
return|;
block|}
comment|/// setFileNum - Set the FileNum of this MCDwarfLoc.
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
comment|/// setLine - Set the Line of this MCDwarfLoc.
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
comment|/// setColumn - Set the Column of this MCDwarfLoc.
name|void
name|setColumn
parameter_list|(
name|unsigned
name|column
parameter_list|)
block|{
name|Column
operator|=
name|column
expr_stmt|;
block|}
comment|/// setFlags - Set the Flags of this MCDwarfLoc.
name|void
name|setFlags
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
name|Flags
operator|=
name|flags
expr_stmt|;
block|}
comment|/// setIsa - Set the Isa of this MCDwarfLoc.
name|void
name|setIsa
parameter_list|(
name|unsigned
name|isa
parameter_list|)
block|{
name|Isa
operator|=
name|isa
expr_stmt|;
block|}
comment|/// setDiscriminator - Set the Discriminator of this MCDwarfLoc.
name|void
name|setDiscriminator
parameter_list|(
name|unsigned
name|discriminator
parameter_list|)
block|{
name|Discriminator
operator|=
name|discriminator
expr_stmt|;
block|}
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
comment|// section and if there is information from the last .loc directive that
comment|// has yet to have a line entry made for it is made.
specifier|static
name|void
name|Make
argument_list|(
name|MCStreamer
operator|*
name|MCOS
argument_list|,
specifier|const
name|MCSection
operator|*
name|Section
argument_list|)
block|;   }
decl_stmt|;
comment|/// MCLineSection - Instances of this class represent the line information
comment|/// for a section where machine instructions have been assembled after seeing
comment|/// .loc directives.  This is the information used to build the dwarf line
comment|/// table for a section.
name|class
name|MCLineSection
block|{
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
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|MCLineEntry
operator|>
name|MCLineEntryCollection
expr_stmt|;
typedef|typedef
name|MCLineEntryCollection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|MCLineEntryCollection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|private
label|:
name|MCLineEntryCollection
name|MCLineEntries
decl_stmt|;
name|public
label|:
specifier|const
name|MCLineEntryCollection
operator|*
name|getMCLineEntries
argument_list|()
specifier|const
block|{
return|return
operator|&
name|MCLineEntries
return|;
block|}
block|}
empty_stmt|;
name|class
name|MCDwarfFileTable
block|{
name|public
label|:
comment|//
comment|// This emits the Dwarf file and the line tables.
comment|//
specifier|static
name|void
name|Emit
parameter_list|(
name|MCStreamer
modifier|*
name|MCOS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|class
name|MCDwarfLineAddr
block|{
name|public
label|:
comment|/// Utility function to encode a Dwarf pair of LineDelta and AddrDeltas.
specifier|static
name|void
name|Encode
parameter_list|(
name|int64_t
name|LineDelta
parameter_list|,
name|uint64_t
name|AddrDelta
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// Utility function to emit the encoding to a streamer.
specifier|static
name|void
name|Emit
parameter_list|(
name|MCStreamer
modifier|*
name|MCOS
parameter_list|,
name|int64_t
name|LineDelta
parameter_list|,
name|uint64_t
name|AddrDelta
parameter_list|)
function_decl|;
comment|/// Utility function to write the encoding to an object writer.
specifier|static
name|void
name|Write
parameter_list|(
name|MCObjectWriter
modifier|*
name|OW
parameter_list|,
name|int64_t
name|LineDelta
parameter_list|,
name|uint64_t
name|AddrDelta
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|class
name|MCCFIInstruction
block|{
name|public
label|:
enum|enum
name|OpType
block|{
name|Remember
block|,
name|Restore
block|,
name|Move
block|}
enum|;
name|private
label|:
name|OpType
name|Operation
decl_stmt|;
name|MCSymbol
modifier|*
name|Label
decl_stmt|;
comment|// Move to& from location.
name|MachineLocation
name|Destination
decl_stmt|;
name|MachineLocation
name|Source
decl_stmt|;
name|public
label|:
name|MCCFIInstruction
argument_list|(
argument|OpType Op
argument_list|,
argument|MCSymbol *L
argument_list|)
block|:
name|Operation
argument_list|(
name|Op
argument_list|)
operator|,
name|Label
argument_list|(
argument|L
argument_list|)
block|{
name|assert
argument_list|(
name|Op
operator|==
name|Remember
operator|||
name|Op
operator|==
name|Restore
argument_list|)
block|;     }
name|MCCFIInstruction
argument_list|(
name|MCSymbol
operator|*
name|L
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|D
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|S
argument_list|)
operator|:
name|Operation
argument_list|(
name|Move
argument_list|)
operator|,
name|Label
argument_list|(
name|L
argument_list|)
operator|,
name|Destination
argument_list|(
name|D
argument_list|)
operator|,
name|Source
argument_list|(
argument|S
argument_list|)
block|{     }
name|OpType
name|getOperation
argument_list|()
specifier|const
block|{
return|return
name|Operation
return|;
block|}
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
specifier|const
name|MachineLocation
operator|&
name|getDestination
argument_list|()
specifier|const
block|{
return|return
name|Destination
return|;
block|}
specifier|const
name|MachineLocation
operator|&
name|getSource
argument_list|()
specifier|const
block|{
return|return
name|Source
return|;
block|}
block|}
empty_stmt|;
struct|struct
name|MCDwarfFrameInfo
block|{
name|MCDwarfFrameInfo
argument_list|()
operator|:
name|Begin
argument_list|(
literal|0
argument_list|)
operator|,
name|End
argument_list|(
literal|0
argument_list|)
operator|,
name|Personality
argument_list|(
literal|0
argument_list|)
operator|,
name|Lsda
argument_list|(
literal|0
argument_list|)
operator|,
name|Instructions
argument_list|()
operator|,
name|PersonalityEncoding
argument_list|(
literal|0
argument_list|)
operator|,
name|LsdaEncoding
argument_list|(
literal|0
argument_list|)
block|{}
name|MCSymbol
operator|*
name|Begin
expr_stmt|;
name|MCSymbol
modifier|*
name|End
decl_stmt|;
specifier|const
name|MCSymbol
modifier|*
name|Personality
decl_stmt|;
specifier|const
name|MCSymbol
modifier|*
name|Lsda
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|MCCFIInstruction
operator|>
name|Instructions
expr_stmt|;
name|unsigned
name|PersonalityEncoding
decl_stmt|;
name|unsigned
name|LsdaEncoding
decl_stmt|;
block|}
struct|;
name|class
name|MCDwarfFrameEmitter
block|{
name|public
label|:
comment|//
comment|// This emits the frame info section.
comment|//
specifier|static
name|void
name|Emit
parameter_list|(
name|MCStreamer
modifier|&
name|streamer
parameter_list|)
function_decl|;
specifier|static
name|void
name|EmitAdvanceLoc
parameter_list|(
name|MCStreamer
modifier|&
name|Streamer
parameter_list|,
name|uint64_t
name|AddrDelta
parameter_list|)
function_decl|;
specifier|static
name|void
name|EncodeAdvanceLoc
parameter_list|(
name|uint64_t
name|AddrDelta
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
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

