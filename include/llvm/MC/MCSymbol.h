begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbol.h - Machine Code Symbols ------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCSymbol class.
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
name|LLVM_MC_MCSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAssembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

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
name|MCSymbol
decl_stmt|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCSymbol - Instances of this class represent a symbol name in the MC file,
comment|/// and MCSymbols are created and uniqued by the MCContext class.  MCSymbols
comment|/// should only be constructed with valid names for the object file.
comment|///
comment|/// If the symbol is defined/emitted into the current translation unit, the
comment|/// Section member is set to indicate what section it lives in.  Otherwise, if
comment|/// it is a reference to an external entity, it has a null section.
name|class
name|MCSymbol
block|{
name|protected
label|:
comment|/// The kind of the symbol.  If it is any value other than unset then this
comment|/// class is actually one of the appropriate subclasses of MCSymbol.
enum|enum
name|SymbolKind
block|{
name|SymbolKindUnset
block|,
name|SymbolKindCOFF
block|,
name|SymbolKindELF
block|,
name|SymbolKindMachO
block|,   }
enum|;
comment|// Special sentinal value for the absolute pseudo section.
comment|//
comment|// FIXME: Use a PointerInt wrapper for this?
specifier|static
name|MCSection
modifier|*
name|AbsolutePseudoSection
decl_stmt|;
comment|/// If a symbol has a Fragment, the section is implied, so we only need
comment|/// one pointer.
comment|/// FIXME: We might be able to simplify this by having the asm streamer create
comment|/// dummy fragments.
comment|/// If this is a section, then it gives the symbol is defined in. This is null
comment|/// for undefined symbols, and the special AbsolutePseudoSection value for
comment|/// absolute symbols. If this is a variable symbol, this caches the variable
comment|/// value's section.
comment|///
comment|/// If this is a fragment, then it gives the fragment this symbol's value is
comment|/// relative to, if any.
name|mutable
name|PointerUnion
operator|<
name|MCSection
operator|*
operator|,
name|MCFragment
operator|*
operator|>
name|SectionOrFragment
expr_stmt|;
comment|/// Value - If non-null, the value for a variable symbol.
specifier|const
name|MCExpr
modifier|*
name|Value
decl_stmt|;
comment|/// IsTemporary - True if this is an assembler temporary label, which
comment|/// typically does not survive in the .o file's symbol table.  Usually
comment|/// "Lfoo" or ".foo".
name|unsigned
name|IsTemporary
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this symbol can be redefined.
name|unsigned
name|IsRedefinable
range|:
literal|1
decl_stmt|;
comment|/// IsUsed - True if this symbol has been used.
name|mutable
name|unsigned
name|IsUsed
range|:
literal|1
decl_stmt|;
name|mutable
name|bool
name|IsRegistered
range|:
literal|1
decl_stmt|;
comment|/// This symbol is visible outside this translation unit.
name|mutable
name|unsigned
name|IsExternal
range|:
literal|1
decl_stmt|;
comment|/// This symbol is private extern.
name|mutable
name|unsigned
name|IsPrivateExtern
range|:
literal|1
decl_stmt|;
comment|/// True if this symbol is named.
comment|/// A named symbol will have a pointer to the name allocated in the bytes
comment|/// immediately prior to the MCSymbol.
name|unsigned
name|HasName
range|:
literal|1
decl_stmt|;
comment|/// LLVM RTTI discriminator. This is actually a SymbolKind enumerator, but is
comment|/// unsigned to avoid sign extension and achieve better bitpacking with MSVC.
name|unsigned
name|Kind
range|:
literal|2
decl_stmt|;
comment|/// True if we have created a relocation that uses this symbol.
name|mutable
name|unsigned
name|IsUsedInReloc
range|:
literal|1
decl_stmt|;
comment|/// Index field, for use by the object file implementation.
name|mutable
name|uint32_t
name|Index
init|=
literal|0
decl_stmt|;
union|union
block|{
comment|/// The offset to apply to the fragment address to form this symbol's value.
name|uint64_t
name|Offset
decl_stmt|;
comment|/// The size of the symbol, if it is 'common'.
name|uint64_t
name|CommonSize
decl_stmt|;
block|}
union|;
comment|/// The alignment of the symbol, if it is 'common', or -1.
comment|//
comment|// FIXME: Pack this in with other fields?
name|unsigned
name|CommonAlign
init|=
operator|-
literal|1U
decl_stmt|;
comment|/// The Flags field is used by object file implementations to store
comment|/// additional per symbol information which is not easily classified.
name|mutable
name|uint32_t
name|Flags
init|=
literal|0
decl_stmt|;
name|protected
label|:
comment|// MCContext creates and uniques these.
name|friend
name|class
name|MCExpr
decl_stmt|;
name|friend
name|class
name|MCContext
decl_stmt|;
comment|/// \brief The name for a symbol.
comment|/// MCSymbol contains a uint64_t so is probably aligned to 8.  On a 32-bit
comment|/// system, the name is a pointer so isn't going to satisfy the 8 byte
comment|/// alignment of uint64_t.  Account for that here.
typedef|typedef
union|union
block|{
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
name|NameEntry
expr_stmt|;
name|uint64_t
name|AlignmentPadding
decl_stmt|;
block|}
name|NameEntryStorageTy
typedef|;
name|MCSymbol
argument_list|(
argument|SymbolKind Kind
argument_list|,
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
block|:
name|Value
argument_list|(
name|nullptr
argument_list|)
operator|,
name|IsTemporary
argument_list|(
name|isTemporary
argument_list|)
operator|,
name|IsRedefinable
argument_list|(
name|false
argument_list|)
operator|,
name|IsUsed
argument_list|(
name|false
argument_list|)
operator|,
name|IsRegistered
argument_list|(
name|false
argument_list|)
operator|,
name|IsExternal
argument_list|(
name|false
argument_list|)
operator|,
name|IsPrivateExtern
argument_list|(
name|false
argument_list|)
operator|,
name|HasName
argument_list|(
operator|!
operator|!
name|Name
argument_list|)
operator|,
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|IsUsedInReloc
argument_list|(
argument|false
argument_list|)
block|{
name|Offset
operator|=
literal|0
block|;
if|if
condition|(
name|Name
condition|)
name|getNameEntryPtr
argument_list|()
operator|=
name|Name
expr_stmt|;
block|}
comment|// Provide custom new/delete as we will only allocate space for a name
comment|// if we need one.
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|s
argument_list|,
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
name|Name
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/// \brief Placement delete - required by std, but never called.
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Constructor throws?"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Placement delete - required by std, but never called.
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|bool
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Constructor throws?"
argument_list|)
expr_stmt|;
block|}
name|MCSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MCSymbol
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|MCSection
operator|*
name|getSectionPtr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|MCFragment
modifier|*
name|F
init|=
name|getFragment
argument_list|()
condition|)
return|return
name|F
operator|->
name|getParent
argument_list|()
return|;
name|assert
argument_list|(
operator|!
name|SectionOrFragment
operator|.
name|is
operator|<
name|MCFragment
operator|*
operator|>
operator|(
operator|)
operator|&&
literal|"Section or null expected"
argument_list|)
expr_stmt|;
name|MCSection
modifier|*
name|Section
init|=
name|SectionOrFragment
operator|.
name|dyn_cast
operator|<
name|MCSection
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
name|Section
operator|||
operator|!
name|Value
condition|)
return|return
name|Section
return|;
return|return
name|Section
operator|=
name|Value
operator|->
name|findAssociatedSection
argument_list|()
return|;
block|}
comment|/// \brief Get a reference to the name field.  Requires that we have a name
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
operator|&
name|getNameEntryPtr
argument_list|()
block|{
name|assert
argument_list|(
name|HasName
operator|&&
literal|"Name is required"
argument_list|)
block|;
name|NameEntryStorageTy
operator|*
name|Name
operator|=
name|reinterpret_cast
operator|<
name|NameEntryStorageTy
operator|*
operator|>
operator|(
name|this
operator|)
block|;
return|return
operator|(
operator|*
operator|(
name|Name
operator|-
literal|1
operator|)
operator|)
operator|.
name|NameEntry
return|;
block|}
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
operator|&
name|getNameEntryPtr
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MCSymbol
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNameEntryPtr
argument_list|()
return|;
block|}
name|public
label|:
comment|/// getName - Get the symbol name.
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasName
condition|)
return|return
name|StringRef
argument_list|()
return|;
return|return
name|getNameEntryPtr
argument_list|()
operator|->
name|first
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|isRegistered
argument_list|()
specifier|const
block|{
return|return
name|IsRegistered
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setIsRegistered
argument_list|(
name|bool
name|Value
argument_list|)
decl|const
block|{
name|IsRegistered
operator|=
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
name|setUsedInReloc
argument_list|()
specifier|const
block|{
name|IsUsedInReloc
operator|=
name|true
block|; }
name|bool
name|isUsedInReloc
argument_list|()
specifier|const
block|{
return|return
name|IsUsedInReloc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \name Accessors
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// isTemporary - Check if this is an assembler temporary symbol.
end_comment

begin_expr_stmt
name|bool
name|isTemporary
argument_list|()
specifier|const
block|{
return|return
name|IsTemporary
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isUsed - Check if this is used.
end_comment

begin_expr_stmt
name|bool
name|isUsed
argument_list|()
specifier|const
block|{
return|return
name|IsUsed
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setUsed
argument_list|(
name|bool
name|Value
argument_list|)
decl|const
block|{
name|IsUsed
operator|=
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Check if this symbol is redefinable.
end_comment

begin_expr_stmt
name|bool
name|isRedefinable
argument_list|()
specifier|const
block|{
return|return
name|IsRedefinable
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Mark this symbol as redefinable.
end_comment

begin_function
name|void
name|setRedefinable
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|IsRedefinable
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Prepare this symbol to be redefined.
end_comment

begin_function
name|void
name|redefineIfPossible
parameter_list|()
block|{
if|if
condition|(
name|IsRedefinable
condition|)
block|{
name|Value
operator|=
name|nullptr
expr_stmt|;
name|SectionOrFragment
operator|=
name|nullptr
expr_stmt|;
name|IsRedefinable
operator|=
name|false
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Associated Sections
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// isDefined - Check if this symbol is defined (i.e., it has an address).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Defined symbols are either absolute or in some section.
end_comment

begin_expr_stmt
name|bool
name|isDefined
argument_list|()
specifier|const
block|{
return|return
name|getSectionPtr
argument_list|()
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isInSection - Check if this symbol is defined in some section (i.e., it
end_comment

begin_comment
comment|/// is defined but not absolute).
end_comment

begin_expr_stmt
name|bool
name|isInSection
argument_list|()
specifier|const
block|{
return|return
name|isDefined
argument_list|()
operator|&&
operator|!
name|isAbsolute
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isUndefined - Check if this symbol undefined (i.e., implicitly defined).
end_comment

begin_expr_stmt
name|bool
name|isUndefined
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDefined
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isAbsolute - Check if this is an absolute symbol.
end_comment

begin_expr_stmt
name|bool
name|isAbsolute
argument_list|()
specifier|const
block|{
return|return
name|getSectionPtr
argument_list|()
operator|==
name|AbsolutePseudoSection
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Get the section associated with a defined, non-absolute symbol.
end_comment

begin_expr_stmt
name|MCSection
operator|&
name|getSection
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isInSection
argument_list|()
operator|&&
literal|"Invalid accessor!"
argument_list|)
block|;
return|return
operator|*
name|getSectionPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Mark the symbol as defined in the section \p S.
end_comment

begin_function
name|void
name|setSection
parameter_list|(
name|MCSection
modifier|&
name|S
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isVariable
argument_list|()
operator|&&
literal|"Cannot set section of variable"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|SectionOrFragment
operator|.
name|is
operator|<
name|MCFragment
operator|*
operator|>
operator|(
operator|)
operator|&&
literal|"Section or null expected"
argument_list|)
expr_stmt|;
name|SectionOrFragment
operator|=
operator|&
name|S
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Mark the symbol as undefined.
end_comment

begin_function
name|void
name|setUndefined
parameter_list|()
block|{
name|SectionOrFragment
operator|=
name|nullptr
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isELF
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SymbolKindELF
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isCOFF
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SymbolKindCOFF
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isMachO
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SymbolKindMachO
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// \name Variable Symbols
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// isVariable - Check if this is a variable symbol.
end_comment

begin_expr_stmt
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getVariableValue() - Get the value for variable symbols.
end_comment

begin_expr_stmt
specifier|const
name|MCExpr
operator|*
name|getVariableValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isVariable
argument_list|()
operator|&&
literal|"Invalid accessor!"
argument_list|)
block|;
name|IsUsed
operator|=
name|true
block|;
return|return
name|Value
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setVariableValue
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// Get the (implementation defined) index.
end_comment

begin_expr_stmt
name|uint32_t
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Set the (implementation defined) index.
end_comment

begin_decl_stmt
name|void
name|setIndex
argument_list|(
name|uint32_t
name|Value
argument_list|)
decl|const
block|{
name|Index
operator|=
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isCommon
argument_list|()
argument_list|)
block|;
return|return
name|Offset
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setOffset
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isCommon
argument_list|()
argument_list|)
expr_stmt|;
name|Offset
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Return the size of a 'common' symbol.
end_comment

begin_expr_stmt
name|uint64_t
name|getCommonSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCommon
argument_list|()
operator|&&
literal|"Not a 'common' symbol!"
argument_list|)
block|;
return|return
name|CommonSize
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Mark this symbol as being 'common'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Size - The size of the symbol.
end_comment

begin_comment
comment|/// \param Align - The alignment of the symbol.
end_comment

begin_function
name|void
name|setCommon
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|unsigned
name|Align
parameter_list|)
block|{
name|assert
argument_list|(
name|getOffset
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|CommonSize
operator|=
name|Size
expr_stmt|;
name|CommonAlign
operator|=
name|Align
expr_stmt|;
block|}
end_function

begin_comment
comment|///  Return the alignment of a 'common' symbol.
end_comment

begin_expr_stmt
name|unsigned
name|getCommonAlignment
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCommon
argument_list|()
operator|&&
literal|"Not a 'common' symbol!"
argument_list|)
block|;
return|return
name|CommonAlign
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Declare this symbol as being 'common'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Size - The size of the symbol.
end_comment

begin_comment
comment|/// \param Align - The alignment of the symbol.
end_comment

begin_comment
comment|/// \return True if symbol was already declared as a different type
end_comment

begin_function
name|bool
name|declareCommon
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|unsigned
name|Align
parameter_list|)
block|{
name|assert
argument_list|(
name|isCommon
argument_list|()
operator|||
name|getOffset
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|isCommon
argument_list|()
condition|)
block|{
if|if
condition|(
name|CommonSize
operator|!=
name|Size
operator|||
name|CommonAlign
operator|!=
name|Align
condition|)
return|return
name|true
return|;
block|}
else|else
name|setCommon
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/// Is this a 'common' symbol.
end_comment

begin_expr_stmt
name|bool
name|isCommon
argument_list|()
specifier|const
block|{
return|return
name|CommonAlign
operator|!=
operator|-
literal|1U
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MCFragment
operator|*
name|getFragment
argument_list|()
specifier|const
block|{
return|return
name|SectionOrFragment
operator|.
name|dyn_cast
operator|<
name|MCFragment
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setFragment
argument_list|(
name|MCFragment
operator|*
name|Value
argument_list|)
decl|const
block|{
name|SectionOrFragment
operator|=
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|isExternal
argument_list|()
specifier|const
block|{
return|return
name|IsExternal
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setExternal
argument_list|(
name|bool
name|Value
argument_list|)
decl|const
block|{
name|IsExternal
operator|=
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|isPrivateExtern
argument_list|()
specifier|const
block|{
return|return
name|IsPrivateExtern
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPrivateExtern
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|IsPrivateExtern
operator|=
name|Value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// print - Print the value to the stream \p OS.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|MAI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// dump - Print the value to stderr.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// Get the (implementation defined) symbol flags.
end_comment

begin_expr_stmt
name|uint32_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Set the (implementation defined) symbol flags.
end_comment

begin_decl_stmt
name|void
name|setFlags
argument_list|(
name|uint32_t
name|Value
argument_list|)
decl|const
block|{
name|Flags
operator|=
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Modify the flags via a mask
end_comment

begin_decl_stmt
name|void
name|modifyFlags
argument_list|(
name|uint32_t
name|Value
argument_list|,
name|uint32_t
name|Mask
argument_list|)
decl|const
block|{
name|Flags
operator|=
operator|(
name|Flags
operator|&
operator|~
name|Mask
operator|)
operator||
name|Value
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
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
name|MCSymbol
operator|&
name|Sym
operator|)
block|{
name|Sym
operator|.
name|print
argument_list|(
name|OS
argument_list|,
name|nullptr
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

