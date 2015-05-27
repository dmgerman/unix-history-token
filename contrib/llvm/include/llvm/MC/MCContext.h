begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCContext.h - Machine Code Context -----------------------*- C++ -*-===//
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
name|LLVM_MC_MCCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// FIXME: Shouldn't be needed.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCLabel
decl_stmt|;
struct_decl|struct
name|MCDwarfFile
struct_decl|;
name|class
name|MCDwarfLoc
decl_stmt|;
name|class
name|MCObjectFileInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCLineSection
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|MCSectionMachO
decl_stmt|;
name|class
name|MCSectionELF
decl_stmt|;
name|class
name|MCSectionCOFF
decl_stmt|;
comment|/// MCContext - Context object for machine code objects.  This class owns all
comment|/// of the sections that it creates.
comment|///
name|class
name|MCContext
block|{
name|MCContext
argument_list|(
argument|const MCContext&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|MCContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCContext
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
typedef|typedef
name|StringMap
operator|<
name|MCSymbol
operator|*
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|SymbolTable
expr_stmt|;
name|private
label|:
comment|/// The SourceMgr for this object, if any.
specifier|const
name|SourceMgr
modifier|*
name|SrcMgr
decl_stmt|;
comment|/// The MCAsmInfo for this target.
specifier|const
name|MCAsmInfo
modifier|*
name|MAI
decl_stmt|;
comment|/// The MCRegisterInfo for this target.
specifier|const
name|MCRegisterInfo
modifier|*
name|MRI
decl_stmt|;
comment|/// The MCObjectFileInfo for this target.
specifier|const
name|MCObjectFileInfo
modifier|*
name|MOFI
decl_stmt|;
comment|/// Allocator - Allocator object used for creating machine code objects.
comment|///
comment|/// We use a bump pointer allocator to avoid the need to track all allocated
comment|/// objects.
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
comment|/// Symbols - Bindings of names to symbols.
name|SymbolTable
name|Symbols
decl_stmt|;
comment|/// ELF sections can have a corresponding symbol. This maps one to the
comment|/// other.
name|DenseMap
operator|<
specifier|const
name|MCSectionELF
operator|*
operator|,
name|MCSymbol
operator|*
operator|>
name|SectionSymbols
expr_stmt|;
comment|/// A maping from a local label number and an instance count to a symbol.
comment|/// For example, in the assembly
comment|///     1:
comment|///     2:
comment|///     1:
comment|/// We have three labels represented by the pairs (1, 0), (2, 0) and (1, 1)
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
operator|,
name|MCSymbol
operator|*
operator|>
name|LocalSymbols
expr_stmt|;
comment|/// UsedNames - Keeps tracks of names that were used both for used declared
comment|/// and artificial symbols.
name|StringMap
operator|<
name|bool
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|UsedNames
expr_stmt|;
comment|/// NextUniqueID - The next ID to dole out to an unnamed assembler temporary
comment|/// symbol.
name|unsigned
name|NextUniqueID
decl_stmt|;
comment|/// Instances of directional local labels.
name|DenseMap
operator|<
name|unsigned
operator|,
name|MCLabel
operator|*
operator|>
name|Instances
expr_stmt|;
comment|/// NextInstance() creates the next instance of the directional local label
comment|/// for the LocalLabelVal and adds it to the map if needed.
name|unsigned
name|NextInstance
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|)
function_decl|;
comment|/// GetInstance() gets the current instance of the directional local label
comment|/// for the LocalLabelVal and adds it to the map if needed.
name|unsigned
name|GetInstance
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|)
function_decl|;
comment|/// The file name of the log file from the environment variable
comment|/// AS_SECURE_LOG_FILE.  Which must be set before the .secure_log_unique
comment|/// directive is used or it is an error.
name|char
modifier|*
name|SecureLogFile
decl_stmt|;
comment|/// The stream that gets written to for the .secure_log_unique directive.
name|raw_ostream
modifier|*
name|SecureLog
decl_stmt|;
comment|/// Boolean toggled when .secure_log_unique / .secure_log_reset is seen to
comment|/// catch errors if .secure_log_unique appears twice without
comment|/// .secure_log_reset appearing between them.
name|bool
name|SecureLogUsed
decl_stmt|;
comment|/// The compilation directory to use for DW_AT_comp_dir.
name|SmallString
operator|<
literal|128
operator|>
name|CompilationDir
expr_stmt|;
comment|/// The main file name if passed in explicitly.
name|std
operator|::
name|string
name|MainFileName
expr_stmt|;
comment|/// The dwarf file and directory tables from the dwarf .file directive.
comment|/// We now emit a line table for each compile unit. To reduce the prologue
comment|/// size of each line table, the files and directories used by each compile
comment|/// unit are separated.
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|MCDwarfLineTable
operator|>
name|MCDwarfLineTablesCUMap
expr_stmt|;
comment|/// The current dwarf line information from the last dwarf .loc directive.
name|MCDwarfLoc
name|CurrentDwarfLoc
decl_stmt|;
name|bool
name|DwarfLocSeen
decl_stmt|;
comment|/// Generate dwarf debugging info for assembly source files.
name|bool
name|GenDwarfForAssembly
decl_stmt|;
comment|/// The current dwarf file number when generate dwarf debugging info for
comment|/// assembly source files.
name|unsigned
name|GenDwarfFileNumber
decl_stmt|;
comment|/// Symbols created for the start and end of each section, used for
comment|/// generating the .debug_ranges and .debug_aranges sections.
name|MapVector
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
operator|,
name|MCSymbol
operator|*
operator|>
expr|>
name|SectionStartEndSyms
expr_stmt|;
comment|/// The information gathered from labels that will have dwarf label
comment|/// entries when generating dwarf assembly source files.
name|std
operator|::
name|vector
operator|<
name|MCGenDwarfLabelEntry
operator|>
name|MCGenDwarfLabelEntries
expr_stmt|;
comment|/// The string to embed in the debug information for the compile unit, if
comment|/// non-empty.
name|StringRef
name|DwarfDebugFlags
decl_stmt|;
comment|/// The string to embed in as the dwarf AT_producer for the compile unit, if
comment|/// non-empty.
name|StringRef
name|DwarfDebugProducer
decl_stmt|;
comment|/// The maximum version of dwarf that we should emit.
name|uint16_t
name|DwarfVersion
decl_stmt|;
comment|/// Honor temporary labels, this is useful for debugging semantic
comment|/// differences between temporary and non-temporary labels (primarily on
comment|/// Darwin).
name|bool
name|AllowTemporaryLabels
decl_stmt|;
comment|/// The Compile Unit ID that we are currently processing.
name|unsigned
name|DwarfCompileUnitID
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
name|SectionGroupPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|tuple
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|,
name|int
operator|>
name|SectionGroupTriple
expr_stmt|;
name|StringMap
operator|<
specifier|const
name|MCSectionMachO
operator|*
operator|>
name|MachOUniquingMap
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|SectionGroupPair
operator|,
specifier|const
name|MCSectionELF
operator|*
operator|>
name|ELFUniquingMap
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|SectionGroupTriple
operator|,
specifier|const
name|MCSectionCOFF
operator|*
operator|>
name|COFFUniquingMap
expr_stmt|;
comment|/// Do automatic reset in destructor
name|bool
name|AutoReset
decl_stmt|;
name|MCSymbol
modifier|*
name|CreateSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|MCSymbol
modifier|*
name|getOrCreateDirectionalLocalSymbol
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|,
name|unsigned
name|Instance
parameter_list|)
function_decl|;
name|public
label|:
name|explicit
name|MCContext
parameter_list|(
specifier|const
name|MCAsmInfo
modifier|*
name|MAI
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|*
name|MRI
parameter_list|,
specifier|const
name|MCObjectFileInfo
modifier|*
name|MOFI
parameter_list|,
specifier|const
name|SourceMgr
modifier|*
name|Mgr
init|=
name|nullptr
parameter_list|,
name|bool
name|DoAutoReset
init|=
name|true
parameter_list|)
function_decl|;
operator|~
name|MCContext
argument_list|()
expr_stmt|;
specifier|const
name|SourceMgr
operator|*
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SrcMgr
return|;
block|}
specifier|const
name|MCAsmInfo
operator|*
name|getAsmInfo
argument_list|()
specifier|const
block|{
return|return
name|MAI
return|;
block|}
specifier|const
name|MCRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|MRI
return|;
block|}
specifier|const
name|MCObjectFileInfo
operator|*
name|getObjectFileInfo
argument_list|()
specifier|const
block|{
return|return
name|MOFI
return|;
block|}
name|void
name|setAllowTemporaryLabels
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|AllowTemporaryLabels
operator|=
name|Value
expr_stmt|;
block|}
comment|/// @name Module Lifetime Management
comment|/// @{
comment|/// reset - return object to right after construction state to prepare
comment|/// to process a new module
name|void
name|reset
parameter_list|()
function_decl|;
comment|/// @}
comment|/// @name Symbol Management
comment|/// @{
comment|/// CreateLinkerPrivateTempSymbol - Create and return a new linker temporary
comment|/// symbol with a unique but unspecified name.
name|MCSymbol
modifier|*
name|CreateLinkerPrivateTempSymbol
parameter_list|()
function_decl|;
comment|/// CreateTempSymbol - Create and return a new assembler temporary symbol
comment|/// with a unique but unspecified name.
name|MCSymbol
modifier|*
name|CreateTempSymbol
parameter_list|()
function_decl|;
comment|/// getUniqueSymbolID() - Return a unique identifier for use in constructing
comment|/// symbol names.
name|unsigned
name|getUniqueSymbolID
parameter_list|()
block|{
return|return
name|NextUniqueID
operator|++
return|;
block|}
comment|/// Create the definition of a directional local symbol for numbered label
comment|/// (used for "1:" definitions).
name|MCSymbol
modifier|*
name|CreateDirectionalLocalSymbol
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|)
function_decl|;
comment|/// Create and return a directional local symbol for numbered label (used
comment|/// for "1b" or 1f" references).
name|MCSymbol
modifier|*
name|GetDirectionalLocalSymbol
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|,
name|bool
name|Before
parameter_list|)
function_decl|;
comment|/// GetOrCreateSymbol - Lookup the symbol inside with the specified
comment|/// @p Name.  If it exists, return it.  If not, create a forward
comment|/// reference and return it.
comment|///
comment|/// @param Name - The symbol name, which must be unique across all symbols.
name|MCSymbol
modifier|*
name|GetOrCreateSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|MCSymbol
modifier|*
name|GetOrCreateSymbol
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|)
function_decl|;
name|MCSymbol
modifier|*
name|getOrCreateSectionSymbol
parameter_list|(
specifier|const
name|MCSectionELF
modifier|&
name|Section
parameter_list|)
function_decl|;
name|MCSymbol
modifier|*
name|getOrCreateFrameAllocSymbol
parameter_list|(
name|StringRef
name|FuncName
parameter_list|)
function_decl|;
comment|/// LookupSymbol - Get the symbol for \p Name, or null.
name|MCSymbol
modifier|*
name|LookupSymbol
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|LookupSymbol
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// getSymbols - Get a reference for the symbol table for clients that
comment|/// want to, for example, iterate over all symbols. 'const' because we
comment|/// still want any modifications to the table itself to use the MCContext
comment|/// APIs.
specifier|const
name|SymbolTable
operator|&
name|getSymbols
argument_list|()
specifier|const
block|{
return|return
name|Symbols
return|;
block|}
comment|/// @}
comment|/// @name Section Management
comment|/// @{
comment|/// getMachOSection - Return the MCSection for the specified mach-o section.
comment|/// This requires the operands to be valid.
specifier|const
name|MCSectionMachO
modifier|*
name|getMachOSection
parameter_list|(
name|StringRef
name|Segment
parameter_list|,
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|TypeAndAttributes
parameter_list|,
name|unsigned
name|Reserved2
parameter_list|,
name|SectionKind
name|K
parameter_list|)
function_decl|;
specifier|const
name|MCSectionMachO
modifier|*
name|getMachOSection
parameter_list|(
name|StringRef
name|Segment
parameter_list|,
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|TypeAndAttributes
parameter_list|,
name|SectionKind
name|K
parameter_list|)
block|{
return|return
name|getMachOSection
argument_list|(
name|Segment
argument_list|,
name|Section
argument_list|,
name|TypeAndAttributes
argument_list|,
literal|0
argument_list|,
name|K
argument_list|)
return|;
block|}
specifier|const
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|SectionKind
name|Kind
parameter_list|)
function_decl|;
specifier|const
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|SectionKind
name|Kind
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
name|StringRef
name|Group
parameter_list|)
function_decl|;
name|void
name|renameELFSection
parameter_list|(
specifier|const
name|MCSectionELF
modifier|*
name|Section
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
specifier|const
name|MCSectionELF
modifier|*
name|CreateELFGroupSection
parameter_list|()
function_decl|;
specifier|const
name|MCSectionCOFF
modifier|*
name|getCOFFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|Characteristics
parameter_list|,
name|SectionKind
name|Kind
parameter_list|,
name|StringRef
name|COMDATSymName
parameter_list|,
name|int
name|Selection
parameter_list|)
function_decl|;
specifier|const
name|MCSectionCOFF
modifier|*
name|getCOFFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|Characteristics
parameter_list|,
name|SectionKind
name|Kind
parameter_list|)
function_decl|;
specifier|const
name|MCSectionCOFF
modifier|*
name|getCOFFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|)
function_decl|;
comment|/// Gets or creates a section equivalent to Sec that is associated with the
comment|/// section containing KeySym. For example, to create a debug info section
comment|/// associated with an inline function, pass the normal debug info section
comment|/// as Sec and the function symbol as KeySym.
specifier|const
name|MCSectionCOFF
modifier|*
name|getAssociativeCOFFSection
parameter_list|(
specifier|const
name|MCSectionCOFF
modifier|*
name|Sec
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|KeySym
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Dwarf Management
comment|/// @{
comment|/// \brief Get the compilation directory for DW_AT_comp_dir
comment|/// This can be overridden by clients which want to control the reported
comment|/// compilation directory and have it be something other than the current
comment|/// working directory.
comment|/// Returns an empty string if the current directory cannot be determined.
name|StringRef
name|getCompilationDir
argument_list|()
specifier|const
block|{
return|return
name|CompilationDir
return|;
block|}
comment|/// \brief Set the compilation directory for DW_AT_comp_dir
comment|/// Override the default (CWD) compilation directory.
name|void
name|setCompilationDir
parameter_list|(
name|StringRef
name|S
parameter_list|)
block|{
name|CompilationDir
operator|=
name|S
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Get the main file name for use in error messages and debug
comment|/// info. This can be set to ensure we've got the correct file name
comment|/// after preprocessing or for -save-temps.
specifier|const
name|std
operator|::
name|string
operator|&
name|getMainFileName
argument_list|()
specifier|const
block|{
return|return
name|MainFileName
return|;
block|}
comment|/// \brief Set the main file name and override the default.
name|void
name|setMainFileName
parameter_list|(
name|StringRef
name|S
parameter_list|)
block|{
name|MainFileName
operator|=
name|S
expr_stmt|;
block|}
comment|/// GetDwarfFile - creates an entry in the dwarf file and directory tables.
name|unsigned
name|GetDwarfFile
parameter_list|(
name|StringRef
name|Directory
parameter_list|,
name|StringRef
name|FileName
parameter_list|,
name|unsigned
name|FileNumber
parameter_list|,
name|unsigned
name|CUID
parameter_list|)
function_decl|;
name|bool
name|isValidDwarfFileNumber
parameter_list|(
name|unsigned
name|FileNumber
parameter_list|,
name|unsigned
name|CUID
init|=
literal|0
parameter_list|)
function_decl|;
specifier|const
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|MCDwarfLineTable
operator|>
operator|&
name|getMCDwarfLineTables
argument_list|()
specifier|const
block|{
return|return
name|MCDwarfLineTablesCUMap
return|;
block|}
name|MCDwarfLineTable
modifier|&
name|getMCDwarfLineTable
parameter_list|(
name|unsigned
name|CUID
parameter_list|)
block|{
return|return
name|MCDwarfLineTablesCUMap
index|[
name|CUID
index|]
return|;
block|}
specifier|const
name|MCDwarfLineTable
modifier|&
name|getMCDwarfLineTable
argument_list|(
name|unsigned
name|CUID
argument_list|)
decl|const
block|{
name|auto
name|I
init|=
name|MCDwarfLineTablesCUMap
operator|.
name|find
argument_list|(
name|CUID
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|MCDwarfLineTablesCUMap
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|MCDwarfFile
operator|>
operator|&
name|getMCDwarfFiles
argument_list|(
argument|unsigned CUID =
literal|0
argument_list|)
block|{
return|return
name|getMCDwarfLineTable
argument_list|(
name|CUID
argument_list|)
operator|.
name|getMCDwarfFiles
argument_list|()
return|;
block|}
specifier|const
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|getMCDwarfDirs
argument_list|(
argument|unsigned CUID =
literal|0
argument_list|)
block|{
return|return
name|getMCDwarfLineTable
argument_list|(
name|CUID
argument_list|)
operator|.
name|getMCDwarfDirs
argument_list|()
return|;
block|}
name|bool
name|hasMCLineSections
argument_list|()
specifier|const
block|{
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Table
range|:
name|MCDwarfLineTablesCUMap
control|)
if|if
condition|(
operator|!
name|Table
operator|.
name|second
operator|.
name|getMCDwarfFiles
argument_list|()
operator|.
name|empty
argument_list|()
operator|||
name|Table
operator|.
name|second
operator|.
name|getLabel
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
name|unsigned
name|getDwarfCompileUnitID
parameter_list|()
block|{
return|return
name|DwarfCompileUnitID
return|;
block|}
name|void
name|setDwarfCompileUnitID
parameter_list|(
name|unsigned
name|CUIndex
parameter_list|)
block|{
name|DwarfCompileUnitID
operator|=
name|CUIndex
expr_stmt|;
block|}
name|void
name|setMCLineTableCompilationDir
parameter_list|(
name|unsigned
name|CUID
parameter_list|,
name|StringRef
name|CompilationDir
parameter_list|)
block|{
name|getMCDwarfLineTable
argument_list|(
name|CUID
argument_list|)
operator|.
name|setCompilationDir
argument_list|(
name|CompilationDir
argument_list|)
expr_stmt|;
block|}
comment|/// setCurrentDwarfLoc - saves the information from the currently parsed
comment|/// dwarf .loc directive and sets DwarfLocSeen.  When the next instruction
comment|/// is assembled an entry in the line number table with this information and
comment|/// the address of the instruction will be created.
name|void
name|setCurrentDwarfLoc
parameter_list|(
name|unsigned
name|FileNum
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Column
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|Isa
parameter_list|,
name|unsigned
name|Discriminator
parameter_list|)
block|{
name|CurrentDwarfLoc
operator|.
name|setFileNum
argument_list|(
name|FileNum
argument_list|)
expr_stmt|;
name|CurrentDwarfLoc
operator|.
name|setLine
argument_list|(
name|Line
argument_list|)
expr_stmt|;
name|CurrentDwarfLoc
operator|.
name|setColumn
argument_list|(
name|Column
argument_list|)
expr_stmt|;
name|CurrentDwarfLoc
operator|.
name|setFlags
argument_list|(
name|Flags
argument_list|)
expr_stmt|;
name|CurrentDwarfLoc
operator|.
name|setIsa
argument_list|(
name|Isa
argument_list|)
expr_stmt|;
name|CurrentDwarfLoc
operator|.
name|setDiscriminator
argument_list|(
name|Discriminator
argument_list|)
expr_stmt|;
name|DwarfLocSeen
operator|=
name|true
expr_stmt|;
block|}
name|void
name|ClearDwarfLocSeen
parameter_list|()
block|{
name|DwarfLocSeen
operator|=
name|false
expr_stmt|;
block|}
name|bool
name|getDwarfLocSeen
parameter_list|()
block|{
return|return
name|DwarfLocSeen
return|;
block|}
specifier|const
name|MCDwarfLoc
modifier|&
name|getCurrentDwarfLoc
parameter_list|()
block|{
return|return
name|CurrentDwarfLoc
return|;
block|}
name|bool
name|getGenDwarfForAssembly
parameter_list|()
block|{
return|return
name|GenDwarfForAssembly
return|;
block|}
name|void
name|setGenDwarfForAssembly
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|GenDwarfForAssembly
operator|=
name|Value
expr_stmt|;
block|}
name|unsigned
name|getGenDwarfFileNumber
parameter_list|()
block|{
return|return
name|GenDwarfFileNumber
return|;
block|}
name|void
name|setGenDwarfFileNumber
parameter_list|(
name|unsigned
name|FileNumber
parameter_list|)
block|{
name|GenDwarfFileNumber
operator|=
name|FileNumber
expr_stmt|;
block|}
name|MapVector
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
operator|,
name|MCSymbol
operator|*
operator|>
expr|>
operator|&
name|getGenDwarfSectionSyms
argument_list|()
block|{
return|return
name|SectionStartEndSyms
return|;
block|}
name|std
operator|::
name|pair
operator|<
name|MapVector
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
operator|,
name|MCSymbol
operator|*
operator|>
expr|>
operator|::
name|iterator
operator|,
name|bool
operator|>
name|addGenDwarfSection
argument_list|(
argument|const MCSection *Sec
argument_list|)
block|{
return|return
name|SectionStartEndSyms
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Sec
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|nullptr
argument_list|,
name|nullptr
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
name|void
name|finalizeDwarfSections
parameter_list|(
name|MCStreamer
modifier|&
name|MCOS
parameter_list|)
function_decl|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|MCGenDwarfLabelEntry
operator|>
operator|&
name|getMCGenDwarfLabelEntries
argument_list|()
specifier|const
block|{
return|return
name|MCGenDwarfLabelEntries
return|;
block|}
name|void
name|addMCGenDwarfLabelEntry
parameter_list|(
specifier|const
name|MCGenDwarfLabelEntry
modifier|&
name|E
parameter_list|)
block|{
name|MCGenDwarfLabelEntries
operator|.
name|push_back
argument_list|(
name|E
argument_list|)
expr_stmt|;
block|}
name|void
name|setDwarfDebugFlags
parameter_list|(
name|StringRef
name|S
parameter_list|)
block|{
name|DwarfDebugFlags
operator|=
name|S
expr_stmt|;
block|}
name|StringRef
name|getDwarfDebugFlags
parameter_list|()
block|{
return|return
name|DwarfDebugFlags
return|;
block|}
name|void
name|setDwarfDebugProducer
parameter_list|(
name|StringRef
name|S
parameter_list|)
block|{
name|DwarfDebugProducer
operator|=
name|S
expr_stmt|;
block|}
name|StringRef
name|getDwarfDebugProducer
parameter_list|()
block|{
return|return
name|DwarfDebugProducer
return|;
block|}
name|void
name|setDwarfVersion
parameter_list|(
name|uint16_t
name|v
parameter_list|)
block|{
name|DwarfVersion
operator|=
name|v
expr_stmt|;
block|}
name|uint16_t
name|getDwarfVersion
argument_list|()
specifier|const
block|{
return|return
name|DwarfVersion
return|;
block|}
comment|/// @}
name|char
modifier|*
name|getSecureLogFile
parameter_list|()
block|{
return|return
name|SecureLogFile
return|;
block|}
name|raw_ostream
modifier|*
name|getSecureLog
parameter_list|()
block|{
return|return
name|SecureLog
return|;
block|}
name|bool
name|getSecureLogUsed
parameter_list|()
block|{
return|return
name|SecureLogUsed
return|;
block|}
name|void
name|setSecureLog
parameter_list|(
name|raw_ostream
modifier|*
name|Value
parameter_list|)
block|{
name|SecureLog
operator|=
name|Value
expr_stmt|;
block|}
name|void
name|setSecureLogUsed
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|SecureLogUsed
operator|=
name|Value
expr_stmt|;
block|}
name|void
modifier|*
name|Allocate
parameter_list|(
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|Align
init|=
literal|8
parameter_list|)
block|{
return|return
name|Allocator
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
return|;
block|}
name|void
name|Deallocate
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{     }
comment|// Unrecoverable error has occurred. Display the best diagnostic we can
comment|// and bail via exit(1). For now, most MC backend errors are unrecoverable.
comment|// FIXME: We should really do something about that.
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|FatalError
argument_list|(
name|SMLoc
name|L
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
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
comment|// end namespace llvm
end_comment

begin_comment
comment|// operator new and delete aren't allowed inside namespaces.
end_comment

begin_comment
comment|// The throw specifications are mandated by the standard.
end_comment

begin_comment
comment|/// @brief Placement new for using the MCContext's allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This placement form of operator new uses the MCContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory. It is a non-throwing new, which means that it returns
end_comment

begin_comment
comment|/// null on error. (If that is what the allocator does. The current does, so if
end_comment

begin_comment
comment|/// this ever changes, this operator will have to be changed, too.)
end_comment

begin_comment
comment|/// Usage looks like this (assuming there's an MCContext 'Context' in scope):
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// // Default alignment (16)
end_comment

begin_comment
comment|/// IntegerLiteral *Ex = new (Context) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// IntegerLiteral *Ex2 = new (Context, 8) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// @c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// @param C The MCContext that provides the allocator.
end_comment

begin_comment
comment|/// @param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// @return The allocated memory. Could be NULL.
end_comment

begin_decl_stmt
unit|inline
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|Bytes
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
operator|=
literal|16
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|C
operator|.
name|Allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Placement delete companion to the new above.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operator is just a companion to the new above. There is no way of
end_comment

begin_comment
comment|/// invoking it directly; see the new operator for more details. This operator
end_comment

begin_comment
comment|/// is called implicitly by the compiler if a placement new expression using
end_comment

begin_comment
comment|/// the MCContext throws in the object constructor.
end_comment

begin_decl_stmt
specifier|inline
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|Ptr
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|,
name|size_t
argument_list|)
name|throw
argument_list|()
block|{
name|C
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// This placement form of operator new[] uses the MCContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory. It is a non-throwing new[], which means that it returns
end_comment

begin_comment
comment|/// null on error.
end_comment

begin_comment
comment|/// Usage looks like this (assuming there's an MCContext 'Context' in scope):
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// // Default alignment (16)
end_comment

begin_comment
comment|/// char *data = new (Context) char[10];
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// char *data = new (Context, 8) char[10];
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// @c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// @param C The MCContext that provides the allocator.
end_comment

begin_comment
comment|/// @param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// @return The allocated memory. Could be NULL.
end_comment

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
index|[]
argument_list|(
name|size_t
name|Bytes
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
operator|=
literal|16
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|C
operator|.
name|Allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Placement delete[] companion to the new[] above.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operator is just a companion to the new[] above. There is no way of
end_comment

begin_comment
comment|/// invoking it directly; see the new[] operator for more details. This operator
end_comment

begin_comment
comment|/// is called implicitly by the compiler if a placement new[] expression using
end_comment

begin_comment
comment|/// the MCContext throws in the object constructor.
end_comment

begin_decl_stmt
specifier|inline
name|void
name|operator
name|delete
index|[]
argument_list|(
name|void
operator|*
name|Ptr
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|)
name|throw
argument_list|()
block|{
name|C
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

