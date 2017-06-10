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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
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
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|CodeViewContext
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCLabel
decl_stmt|;
name|class
name|MCObjectFileInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSectionCOFF
decl_stmt|;
name|class
name|MCSectionELF
decl_stmt|;
name|class
name|MCSectionMachO
decl_stmt|;
name|class
name|MCSectionWasm
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSymbolELF
decl_stmt|;
name|class
name|MCSymbolWasm
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
comment|/// Context object for machine code objects.  This class owns all of the
comment|/// sections that it creates.
comment|///
name|class
name|MCContext
block|{
name|public
label|:
name|using
name|SymbolTable
init|=
name|StringMap
operator|<
name|MCSymbol
operator|*
decl_stmt|,
name|BumpPtrAllocator
modifier|&
decl|>
decl_stmt|;
name|private
label|:
comment|/// The SourceMgr for this object, if any.
specifier|const
name|SourceMgr
modifier|*
name|SrcMgr
decl_stmt|;
comment|/// The SourceMgr for inline assembly, if any.
name|SourceMgr
modifier|*
name|InlineSrcMgr
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
name|std
operator|::
name|unique_ptr
operator|<
name|CodeViewContext
operator|>
name|CVContext
expr_stmt|;
comment|/// Allocator object used for creating machine code objects.
comment|///
comment|/// We use a bump pointer allocator to avoid the need to track all allocated
comment|/// objects.
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
name|SpecificBumpPtrAllocator
operator|<
name|MCSectionCOFF
operator|>
name|COFFAllocator
expr_stmt|;
name|SpecificBumpPtrAllocator
operator|<
name|MCSectionELF
operator|>
name|ELFAllocator
expr_stmt|;
name|SpecificBumpPtrAllocator
operator|<
name|MCSectionMachO
operator|>
name|MachOAllocator
expr_stmt|;
name|SpecificBumpPtrAllocator
operator|<
name|MCSectionWasm
operator|>
name|WasmAllocator
expr_stmt|;
comment|/// Bindings of names to symbols.
name|SymbolTable
name|Symbols
decl_stmt|;
comment|/// A mapping from a local label number and an instance count to a symbol.
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
comment|/// Keeps tracks of names that were used both for used declared and
comment|/// artificial symbols. The value is "true" if the name has been used for a
comment|/// non-section symbol (there can be at most one of those, plus an unlimited
comment|/// number of section symbols with the same name).
name|StringMap
operator|<
name|bool
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|UsedNames
expr_stmt|;
comment|/// The next ID to dole out to an unnamed assembler temporary symbol with
comment|/// a given prefix.
name|StringMap
operator|<
name|unsigned
operator|>
name|NextID
expr_stmt|;
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
name|std
operator|::
name|unique_ptr
operator|<
name|raw_fd_ostream
operator|>
name|SecureLog
expr_stmt|;
comment|/// Boolean toggled when .secure_log_unique / .secure_log_reset is seen to
comment|/// catch errors if .secure_log_unique appears twice without
comment|/// .secure_log_reset appearing between them.
name|bool
name|SecureLogUsed
init|=
name|false
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
init|=
name|false
decl_stmt|;
comment|/// Generate dwarf debugging info for assembly source files.
name|bool
name|GenDwarfForAssembly
init|=
name|false
decl_stmt|;
comment|/// The current dwarf file number when generate dwarf debugging info for
comment|/// assembly source files.
name|unsigned
name|GenDwarfFileNumber
init|=
literal|0
decl_stmt|;
comment|/// Sections for generating the .debug_ranges and .debug_aranges sections.
name|SetVector
operator|<
name|MCSection
operator|*
operator|>
name|SectionsForRanges
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
init|=
literal|4
decl_stmt|;
comment|/// Honor temporary labels, this is useful for debugging semantic
comment|/// differences between temporary and non-temporary labels (primarily on
comment|/// Darwin).
name|bool
name|AllowTemporaryLabels
init|=
name|true
decl_stmt|;
name|bool
name|UseNamesOnTempLabels
init|=
name|true
decl_stmt|;
comment|/// The Compile Unit ID that we are currently processing.
name|unsigned
name|DwarfCompileUnitID
init|=
literal|0
decl_stmt|;
struct|struct
name|ELFSectionKey
block|{
name|std
operator|::
name|string
name|SectionName
expr_stmt|;
name|StringRef
name|GroupName
decl_stmt|;
name|unsigned
name|UniqueID
decl_stmt|;
name|ELFSectionKey
argument_list|(
argument|StringRef SectionName
argument_list|,
argument|StringRef GroupName
argument_list|,
argument|unsigned UniqueID
argument_list|)
block|:
name|SectionName
argument_list|(
name|SectionName
argument_list|)
operator|,
name|GroupName
argument_list|(
name|GroupName
argument_list|)
operator|,
name|UniqueID
argument_list|(
argument|UniqueID
argument_list|)
block|{       }
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ELFSectionKey
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|SectionName
operator|!=
name|Other
operator|.
name|SectionName
condition|)
return|return
name|SectionName
operator|<
name|Other
operator|.
name|SectionName
return|;
if|if
condition|(
name|GroupName
operator|!=
name|Other
operator|.
name|GroupName
condition|)
return|return
name|GroupName
operator|<
name|Other
operator|.
name|GroupName
return|;
return|return
name|UniqueID
operator|<
name|Other
operator|.
name|UniqueID
return|;
block|}
block|}
empty_stmt|;
struct|struct
name|COFFSectionKey
block|{
name|std
operator|::
name|string
name|SectionName
expr_stmt|;
name|StringRef
name|GroupName
decl_stmt|;
name|int
name|SelectionKey
decl_stmt|;
name|unsigned
name|UniqueID
decl_stmt|;
name|COFFSectionKey
argument_list|(
argument|StringRef SectionName
argument_list|,
argument|StringRef GroupName
argument_list|,
argument|int SelectionKey
argument_list|,
argument|unsigned UniqueID
argument_list|)
block|:
name|SectionName
argument_list|(
name|SectionName
argument_list|)
operator|,
name|GroupName
argument_list|(
name|GroupName
argument_list|)
operator|,
name|SelectionKey
argument_list|(
name|SelectionKey
argument_list|)
operator|,
name|UniqueID
argument_list|(
argument|UniqueID
argument_list|)
block|{}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|COFFSectionKey
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|SectionName
operator|!=
name|Other
operator|.
name|SectionName
condition|)
return|return
name|SectionName
operator|<
name|Other
operator|.
name|SectionName
return|;
if|if
condition|(
name|GroupName
operator|!=
name|Other
operator|.
name|GroupName
condition|)
return|return
name|GroupName
operator|<
name|Other
operator|.
name|GroupName
return|;
if|if
condition|(
name|SelectionKey
operator|!=
name|Other
operator|.
name|SelectionKey
condition|)
return|return
name|SelectionKey
operator|<
name|Other
operator|.
name|SelectionKey
return|;
return|return
name|UniqueID
operator|<
name|Other
operator|.
name|UniqueID
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|WasmSectionKey
block|{
name|std
operator|::
name|string
name|SectionName
expr_stmt|;
name|StringRef
name|GroupName
decl_stmt|;
name|unsigned
name|UniqueID
decl_stmt|;
name|WasmSectionKey
argument_list|(
argument|StringRef SectionName
argument_list|,
argument|StringRef GroupName
argument_list|,
argument|unsigned UniqueID
argument_list|)
block|:
name|SectionName
argument_list|(
name|SectionName
argument_list|)
operator|,
name|GroupName
argument_list|(
name|GroupName
argument_list|)
operator|,
name|UniqueID
argument_list|(
argument|UniqueID
argument_list|)
block|{       }
name|bool
name|operator
operator|<
operator|(
specifier|const
name|WasmSectionKey
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|SectionName
operator|!=
name|Other
operator|.
name|SectionName
condition|)
return|return
name|SectionName
operator|<
name|Other
operator|.
name|SectionName
return|;
if|if
condition|(
name|GroupName
operator|!=
name|Other
operator|.
name|GroupName
condition|)
return|return
name|GroupName
operator|<
name|Other
operator|.
name|GroupName
return|;
return|return
name|UniqueID
operator|<
name|Other
operator|.
name|UniqueID
return|;
block|}
end_struct

begin_expr_stmt
unit|};
name|StringMap
operator|<
name|MCSectionMachO
operator|*
operator|>
name|MachOUniquingMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|ELFSectionKey
operator|,
name|MCSectionELF
operator|*
operator|>
name|ELFUniquingMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|COFFSectionKey
operator|,
name|MCSectionCOFF
operator|*
operator|>
name|COFFUniquingMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|WasmSectionKey
operator|,
name|MCSectionWasm
operator|*
operator|>
name|WasmUniquingMap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|StringMap
operator|<
name|bool
operator|>
name|RelSecNames
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SpecificBumpPtrAllocator
operator|<
name|MCSubtargetInfo
operator|>
name|MCSubtargetAllocator
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Do automatic reset in destructor
end_comment

begin_decl_stmt
name|bool
name|AutoReset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|HadError
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MCSymbol
modifier|*
name|createSymbolImpl
argument_list|(
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
name|Name
argument_list|,
name|bool
name|CanBeUnnamed
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|MCSymbol
modifier|*
name|createSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|AlwaysAddSuffix
parameter_list|,
name|bool
name|IsTemporary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|MCSectionELF
modifier|*
name|createELFSectionImpl
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
name|K
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
specifier|const
name|MCSymbolELF
modifier|*
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|,
specifier|const
name|MCSymbolELF
modifier|*
name|Associated
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_function_decl
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
end_function_decl

begin_expr_stmt
name|MCContext
argument_list|(
specifier|const
name|MCContext
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|MCContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCContext
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|~
name|MCContext
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setInlineSourceManager
parameter_list|(
name|SourceMgr
modifier|*
name|SM
parameter_list|)
block|{
name|InlineSrcMgr
operator|=
name|SM
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|CodeViewContext
modifier|&
name|getCVContext
parameter_list|()
function_decl|;
end_function_decl

begin_function
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
end_function

begin_function
name|void
name|setUseNamesOnTempLabels
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|UseNamesOnTempLabels
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \name Module Lifetime Management
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// reset - return object to right after construction state to prepare
end_comment

begin_comment
comment|/// to process a new module
end_comment

begin_function_decl
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Symbol Management
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Create and return a new linker temporary symbol with a unique but
end_comment

begin_comment
comment|/// unspecified name.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|createLinkerPrivateTempSymbol
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Create and return a new assembler temporary symbol with a unique but
end_comment

begin_comment
comment|/// unspecified name.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|createTempSymbol
parameter_list|(
name|bool
name|CanBeUnnamed
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSymbol
modifier|*
name|createTempSymbol
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|bool
name|AlwaysAddSuffix
parameter_list|,
name|bool
name|CanBeUnnamed
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Create the definition of a directional local symbol for numbered label
end_comment

begin_comment
comment|/// (used for "1:" definitions).
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|createDirectionalLocalSymbol
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Create and return a directional local symbol for numbered label (used
end_comment

begin_comment
comment|/// for "1b" or 1f" references).
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|getDirectionalLocalSymbol
parameter_list|(
name|unsigned
name|LocalLabelVal
parameter_list|,
name|bool
name|Before
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Lookup the symbol inside with the specified \p Name.  If it exists,
end_comment

begin_comment
comment|/// return it.  If not, create a forward reference and return it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name - The symbol name, which must be unique across all symbols.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|getOrCreateSymbol
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Gets a symbol that will be defined to the final stack offset of a local
end_comment

begin_comment
comment|/// variable after codegen.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Idx - The index of a local variable passed to @llvm.localescape.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|getOrCreateFrameAllocSymbol
parameter_list|(
name|StringRef
name|FuncName
parameter_list|,
name|unsigned
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSymbol
modifier|*
name|getOrCreateParentFrameOffsetSymbol
parameter_list|(
name|StringRef
name|FuncName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSymbol
modifier|*
name|getOrCreateLSDASymbol
parameter_list|(
name|StringRef
name|FuncName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the symbol for \p Name, or null.
end_comment

begin_decl_stmt
name|MCSymbol
modifier|*
name|lookupSymbol
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set value for a symbol.
end_comment

begin_function_decl
name|void
name|setSymbolValue
parameter_list|(
name|MCStreamer
modifier|&
name|Streamer
parameter_list|,
name|StringRef
name|Sym
parameter_list|,
name|uint64_t
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getSymbols - Get a reference for the symbol table for clients that
end_comment

begin_comment
comment|/// want to, for example, iterate over all symbols. 'const' because we
end_comment

begin_comment
comment|/// still want any modifications to the table itself to use the MCContext
end_comment

begin_comment
comment|/// APIs.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Section Management
end_comment

begin_comment
comment|/// @{
end_comment

begin_enum_decl
enum_decl|enum :
name|unsigned
block|{
comment|/// Pass this value as the UniqueID during section creation to get the
comment|/// generic section with the given name and characteristics. The usual
comment|/// sections such as .text use this ID.
name|GenericSectionID
init|=
operator|~
literal|0U
block|}
enum_decl|;
end_enum_decl

begin_comment
comment|/// Return the MCSection for the specified mach-o section.  This requires
end_comment

begin_comment
comment|/// the operands to be valid.
end_comment

begin_function_decl
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
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function
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
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
init|=
name|nullptr
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
argument_list|,
name|BeginSymName
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|)
block|{
return|return
name|getELFSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|)
block|{
return|return
name|getELFSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|EntrySize
argument_list|,
name|Group
argument_list|,
operator|~
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|)
block|{
return|return
name|getELFSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|EntrySize
argument_list|,
name|Group
argument_list|,
name|UniqueID
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|,
specifier|const
name|MCSymbolELF
modifier|*
name|Associated
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSectionELF
modifier|*
name|getELFSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
specifier|const
name|MCSymbolELF
modifier|*
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|,
specifier|const
name|MCSymbolELF
modifier|*
name|Associated
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get a section with the provided group identifier. This section is
end_comment

begin_comment
comment|/// named by concatenating \p Prefix with '.' then \p Suffix. The \p Type
end_comment

begin_comment
comment|/// describes the type of the section and \p Flags are used to further
end_comment

begin_comment
comment|/// configure this named section.
end_comment

begin_function_decl
name|MCSectionELF
modifier|*
name|getELFNamedSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Prefix
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Suffix
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|EntrySize
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSectionELF
modifier|*
name|createELFRelSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
name|unsigned
name|EntrySize
parameter_list|,
specifier|const
name|MCSymbolELF
modifier|*
name|Group
parameter_list|,
specifier|const
name|MCSectionELF
modifier|*
name|RelInfoSection
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|renameELFSection
parameter_list|(
name|MCSectionELF
modifier|*
name|Section
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSectionELF
modifier|*
name|createELFGroupSection
parameter_list|(
specifier|const
name|MCSymbolELF
modifier|*
name|Group
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
parameter_list|,
name|unsigned
name|UniqueID
init|=
name|GenericSectionID
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
specifier|const
name|char
modifier|*
name|BeginSymName
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSectionCOFF
modifier|*
name|getCOFFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Gets or creates a section equivalent to Sec that is associated with the
end_comment

begin_comment
comment|/// section containing KeySym. For example, to create a debug info section
end_comment

begin_comment
comment|/// associated with an inline function, pass the normal debug info section
end_comment

begin_comment
comment|/// as Sec and the function symbol as KeySym.
end_comment

begin_function_decl
name|MCSectionCOFF
modifier|*
name|getAssociativeCOFFSection
parameter_list|(
name|MCSectionCOFF
modifier|*
name|Sec
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|KeySym
parameter_list|,
name|unsigned
name|UniqueID
init|=
name|GenericSectionID
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|)
block|{
return|return
name|getWasmSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
parameter_list|)
block|{
return|return
name|getWasmSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
literal|""
argument_list|,
name|BeginSymName
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|)
block|{
return|return
name|getWasmSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|Group
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
parameter_list|)
block|{
return|return
name|getWasmSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|Group
argument_list|,
operator|~
literal|0
argument_list|,
name|BeginSymName
argument_list|)
return|;
block|}
end_function

begin_function
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|)
block|{
return|return
name|getWasmSection
argument_list|(
name|Section
argument_list|,
name|Type
argument_list|,
name|Flags
argument_list|,
name|Group
argument_list|,
name|UniqueID
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSectionWasm
modifier|*
name|getWasmSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Section
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|MCSymbolWasm
modifier|*
name|Group
parameter_list|,
name|unsigned
name|UniqueID
parameter_list|,
specifier|const
name|char
modifier|*
name|BeginSymName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get a section with the provided group identifier. This section is
end_comment

begin_comment
comment|/// named by concatenating \p Prefix with '.' then \p Suffix. The \p Type
end_comment

begin_comment
comment|/// describes the type of the section and \p Flags are used to further
end_comment

begin_comment
comment|/// configure this named section.
end_comment

begin_function_decl
name|MCSectionWasm
modifier|*
name|getWasmNamedSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Prefix
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Suffix
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MCSectionWasm
modifier|*
name|createWasmRelSection
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
name|unsigned
name|Type
parameter_list|,
name|unsigned
name|Flags
parameter_list|,
specifier|const
name|MCSymbolWasm
modifier|*
name|Group
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|renameWasmSection
parameter_list|(
name|MCSectionWasm
modifier|*
name|Section
parameter_list|,
name|StringRef
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Create and save a copy of STI and return a reference to the copy.
end_comment

begin_function_decl
name|MCSubtargetInfo
modifier|&
name|getSubtargetCopy
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Dwarf Management
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// \brief Get the compilation directory for DW_AT_comp_dir
end_comment

begin_comment
comment|/// The compilation directory should be set with \c setCompilationDir before
end_comment

begin_comment
comment|/// calling this function. If it is unset, an empty string will be returned.
end_comment

begin_expr_stmt
name|StringRef
name|getCompilationDir
argument_list|()
specifier|const
block|{
return|return
name|CompilationDir
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the compilation directory for DW_AT_comp_dir
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Get the main file name for use in error messages and debug
end_comment

begin_comment
comment|/// info. This can be set to ensure we've got the correct file name
end_comment

begin_comment
comment|/// after preprocessing or for -save-temps.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Set the main file name and override the default.
end_comment

begin_function
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
end_function

begin_comment
comment|/// Creates an entry in the dwarf file and directory tables.
end_comment

begin_function_decl
name|unsigned
name|getDwarfFile
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_decl_stmt
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_macro
unit|}      unsigned
name|getDwarfCompileUnitID
argument_list|()
end_macro

begin_block
block|{
return|return
name|DwarfCompileUnitID
return|;
block|}
end_block

begin_function
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
end_function

begin_function
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
end_function

begin_comment
comment|/// Saves the information from the currently parsed dwarf .loc directive
end_comment

begin_comment
comment|/// and sets DwarfLocSeen.  When the next instruction is assembled an entry
end_comment

begin_comment
comment|/// in the line number table with this information and the address of the
end_comment

begin_comment
comment|/// instruction will be created.
end_comment

begin_function
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
end_function

begin_function
name|void
name|clearDwarfLocSeen
parameter_list|()
block|{
name|DwarfLocSeen
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_function
name|bool
name|getDwarfLocSeen
parameter_list|()
block|{
return|return
name|DwarfLocSeen
return|;
block|}
end_function

begin_function
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
end_function

begin_function
name|bool
name|getGenDwarfForAssembly
parameter_list|()
block|{
return|return
name|GenDwarfForAssembly
return|;
block|}
end_function

begin_function
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
end_function

begin_function
name|unsigned
name|getGenDwarfFileNumber
parameter_list|()
block|{
return|return
name|GenDwarfFileNumber
return|;
block|}
end_function

begin_function
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
end_function

begin_expr_stmt
specifier|const
name|SetVector
operator|<
name|MCSection
operator|*
operator|>
operator|&
name|getGenDwarfSectionSyms
argument_list|()
block|{
return|return
name|SectionsForRanges
return|;
block|}
end_expr_stmt

begin_function
name|bool
name|addGenDwarfSection
parameter_list|(
name|MCSection
modifier|*
name|Sec
parameter_list|)
block|{
return|return
name|SectionsForRanges
operator|.
name|insert
argument_list|(
name|Sec
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|void
name|finalizeDwarfSections
parameter_list|(
name|MCStreamer
modifier|&
name|MCOS
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_function
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
end_function

begin_function
name|StringRef
name|getDwarfDebugFlags
parameter_list|()
block|{
return|return
name|DwarfDebugFlags
return|;
block|}
end_function

begin_function
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
end_function

begin_function
name|StringRef
name|getDwarfDebugProducer
parameter_list|()
block|{
return|return
name|DwarfDebugProducer
return|;
block|}
end_function

begin_expr_stmt
name|dwarf
operator|::
name|DwarfFormat
name|getDwarfFormat
argument_list|()
specifier|const
block|{
comment|// TODO: Support DWARF64
return|return
name|dwarf
operator|::
name|DWARF32
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|uint16_t
name|getDwarfVersion
argument_list|()
specifier|const
block|{
return|return
name|DwarfVersion
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_function
name|char
modifier|*
name|getSecureLogFile
parameter_list|()
block|{
return|return
name|SecureLogFile
return|;
block|}
end_function

begin_function
name|raw_fd_ostream
modifier|*
name|getSecureLog
parameter_list|()
block|{
return|return
name|SecureLog
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|void
name|setSecureLog
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|raw_fd_ostream
operator|>
name|Value
argument_list|)
block|{
name|SecureLog
operator|=
name|std
operator|::
name|move
argument_list|(
name|Value
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|bool
name|getSecureLogUsed
parameter_list|()
block|{
return|return
name|SecureLogUsed
return|;
block|}
end_function

begin_function
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
end_function

begin_function
name|void
modifier|*
name|allocate
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
end_function

begin_function
name|void
name|deallocate
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{}
end_function

begin_function
name|bool
name|hadError
parameter_list|()
block|{
return|return
name|HadError
return|;
block|}
end_function

begin_function_decl
name|void
name|reportError
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Unrecoverable error has occurred. Display the best diagnostic we can
end_comment

begin_comment
comment|// and bail via exit(1). For now, most MC backend errors are unrecoverable.
end_comment

begin_comment
comment|// FIXME: We should really do something about that.
end_comment

begin_function_decl
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|reportFatalError
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_comment
comment|// operator new and delete aren't allowed inside namespaces.
end_comment

begin_comment
comment|// The throw specifications are mandated by the standard.
end_comment

begin_comment
comment|/// \brief Placement new for using the MCContext's allocator.
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
comment|/// \code
end_comment

begin_comment
comment|/// // Default alignment (8)
end_comment

begin_comment
comment|/// IntegerLiteral *Ex = new (Context) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// IntegerLiteral *Ex2 = new (Context, 4) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// \c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// \param C The MCContext that provides the allocator.
end_comment

begin_comment
comment|/// \param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// \return The allocated memory. Could be NULL.
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
literal|8
argument_list|)
name|noexcept
block|{
return|return
name|C
operator|.
name|allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Placement delete companion to the new above.
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
name|noexcept
block|{
name|C
operator|.
name|deallocate
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
comment|/// \code
end_comment

begin_comment
comment|/// // Default alignment (8)
end_comment

begin_comment
comment|/// char *data = new (Context) char[10];
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// char *data = new (Context, 4) char[10];
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// \c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// \param C The MCContext that provides the allocator.
end_comment

begin_comment
comment|/// \param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// \return The allocated memory. Could be NULL.
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
literal|8
argument_list|)
name|noexcept
block|{
return|return
name|C
operator|.
name|allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Placement delete[] companion to the new[] above.
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
name|noexcept
block|{
name|C
operator|.
name|deallocate
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

begin_comment
comment|// LLVM_MC_MCCONTEXT_H
end_comment

end_unit

