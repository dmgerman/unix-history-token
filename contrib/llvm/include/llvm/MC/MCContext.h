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
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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
name|class
name|MCDwarfFile
decl_stmt|;
name|class
name|MCDwarfLoc
decl_stmt|;
name|class
name|MCLineSection
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|TargetAsmInfo
decl_stmt|;
name|class
name|MCSectionMachO
decl_stmt|;
name|class
name|MCSectionELF
decl_stmt|;
comment|/// MCContext - Context object for machine code objects.  This class owns all
comment|/// of the sections that it creates.
comment|///
name|class
name|MCContext
block|{
name|MCContext
argument_list|(
specifier|const
name|MCContext
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|MCContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCContext
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
comment|/// The MCAsmInfo for this target.
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
decl_stmt|;
specifier|const
name|TargetAsmInfo
modifier|*
name|TAI
decl_stmt|;
comment|/// Allocator - Allocator object used for creating machine code objects.
comment|///
comment|/// We use a bump pointer allocator to avoid the need to track all allocated
comment|/// objects.
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
comment|/// Symbols - Bindings of names to symbols.
name|StringMap
operator|<
name|MCSymbol
operator|*
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|Symbols
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
name|int64_t
name|LocalLabelVal
parameter_list|)
function_decl|;
comment|/// GetInstance() gets the current instance of the directional local label
comment|/// for the LocalLabelVal and adds it to the map if needed.
name|unsigned
name|GetInstance
parameter_list|(
name|int64_t
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
comment|/// The dwarf file and directory tables from the dwarf .file directive.
name|std
operator|::
name|vector
operator|<
name|MCDwarfFile
operator|*
operator|>
name|MCDwarfFiles
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|MCDwarfDirs
expr_stmt|;
comment|/// The current dwarf line information from the last dwarf .loc directive.
name|MCDwarfLoc
name|CurrentDwarfLoc
decl_stmt|;
name|bool
name|DwarfLocSeen
decl_stmt|;
comment|/// Honor temporary labels, this is useful for debugging semantic
comment|/// differences between temporary and non-temporary labels (primarily on
comment|/// Darwin).
name|bool
name|AllowTemporaryLabels
decl_stmt|;
comment|/// The dwarf line information from the .loc directives for the sections
comment|/// with assembled machine instructions have after seeing .loc directives.
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|MCLineSection
operator|*
operator|>
name|MCLineSections
expr_stmt|;
comment|/// We need a deterministic iteration order, so we remember the order
comment|/// the elements were added.
name|std
operator|::
name|vector
operator|<
specifier|const
name|MCSection
operator|*
operator|>
name|MCLineSectionOrder
expr_stmt|;
name|void
modifier|*
name|MachOUniquingMap
decl_stmt|,
modifier|*
name|ELFUniquingMap
decl_stmt|,
modifier|*
name|COFFUniquingMap
decl_stmt|;
name|MCSymbol
modifier|*
name|CreateSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|public
label|:
name|explicit
name|MCContext
parameter_list|(
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
parameter_list|,
specifier|const
name|TargetAsmInfo
modifier|*
name|TAI
parameter_list|)
function_decl|;
operator|~
name|MCContext
argument_list|()
expr_stmt|;
specifier|const
name|MCAsmInfo
operator|&
name|getAsmInfo
argument_list|()
specifier|const
block|{
return|return
name|MAI
return|;
block|}
specifier|const
name|TargetAsmInfo
operator|&
name|getTargetAsmInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TAI
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
comment|/// @name Symbol Management
comment|/// @{
comment|/// CreateTempSymbol - Create and return a new assembler temporary symbol
comment|/// with a unique but unspecified name.
name|MCSymbol
modifier|*
name|CreateTempSymbol
parameter_list|()
function_decl|;
comment|/// CreateDirectionalLocalSymbol - Create the definition of a directional
comment|/// local symbol for numbered label (used for "1:" definitions).
name|MCSymbol
modifier|*
name|CreateDirectionalLocalSymbol
parameter_list|(
name|int64_t
name|LocalLabelVal
parameter_list|)
function_decl|;
comment|/// GetDirectionalLocalSymbol - Create and return a directional local
comment|/// symbol for numbered label (used for "1b" or 1f" references).
name|MCSymbol
modifier|*
name|GetDirectionalLocalSymbol
parameter_list|(
name|int64_t
name|LocalLabelVal
parameter_list|,
name|int
name|bORf
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
specifier|const
name|MCSectionELF
modifier|*
name|CreateELFGroupSection
parameter_list|()
function_decl|;
specifier|const
name|MCSection
modifier|*
name|getCOFFSection
parameter_list|(
name|StringRef
name|Section
parameter_list|,
name|unsigned
name|Characteristics
parameter_list|,
name|int
name|Selection
parameter_list|,
name|SectionKind
name|Kind
parameter_list|)
function_decl|;
specifier|const
name|MCSection
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
block|{
return|return
name|getCOFFSection
argument_list|(
name|Section
argument_list|,
name|Characteristics
argument_list|,
literal|0
argument_list|,
name|Kind
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Dwarf Management
comment|/// @{
comment|/// GetDwarfFile - creates an entry in the dwarf file and directory tables.
name|unsigned
name|GetDwarfFile
parameter_list|(
name|StringRef
name|FileName
parameter_list|,
name|unsigned
name|FileNumber
parameter_list|)
function_decl|;
name|bool
name|isValidDwarfFileNumber
parameter_list|(
name|unsigned
name|FileNumber
parameter_list|)
function_decl|;
name|bool
name|hasDwarfFiles
argument_list|()
specifier|const
block|{
return|return
operator|!
name|MCDwarfFiles
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|MCDwarfFile
operator|*
operator|>
operator|&
name|getMCDwarfFiles
argument_list|()
block|{
return|return
name|MCDwarfFiles
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
operator|&
name|getMCDwarfDirs
argument_list|()
block|{
return|return
name|MCDwarfDirs
return|;
block|}
specifier|const
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
operator|,
name|MCLineSection
operator|*
operator|>
operator|&
name|getMCLineSections
argument_list|()
specifier|const
block|{
return|return
name|MCLineSections
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|MCSection
operator|*
operator|>
operator|&
name|getMCLineSectionOrder
argument_list|()
specifier|const
block|{
return|return
name|MCLineSectionOrder
return|;
block|}
name|void
name|addMCLineSection
parameter_list|(
specifier|const
name|MCSection
modifier|*
name|Sec
parameter_list|,
name|MCLineSection
modifier|*
name|Line
parameter_list|)
block|{
name|MCLineSections
index|[
name|Sec
index|]
operator|=
name|Line
expr_stmt|;
name|MCLineSectionOrder
operator|.
name|push_back
argument_list|(
name|Sec
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
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
specifier|inline
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

