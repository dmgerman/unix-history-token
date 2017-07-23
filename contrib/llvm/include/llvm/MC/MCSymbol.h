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
file|"llvm/ADT/PointerIntPair.h"
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
file|"llvm/MC/MCFragment.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
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
block|,
name|SymbolKindWasm
block|,   }
enum|;
comment|/// A symbol can contain an Offset, or Value, or be Common, but never more
comment|/// than one of these.
enum|enum
name|Contents
enum|:
name|uint8_t
block|{
name|SymContentsUnset
block|,
name|SymContentsOffset
block|,
name|SymContentsVariable
block|,
name|SymContentsCommon
block|,   }
enum|;
comment|// Special sentinal value for the absolute pseudo fragment.
specifier|static
name|MCFragment
modifier|*
name|AbsolutePseudoFragment
decl_stmt|;
comment|/// If a symbol has a Fragment, the section is implied, so we only need
comment|/// one pointer.
comment|/// The special AbsolutePseudoFragment value is for absolute symbols.
comment|/// If this is a variable symbol, this caches the variable value's fragment.
comment|/// FIXME: We might be able to simplify this by having the asm streamer create
comment|/// dummy fragments.
comment|/// If this is a section, then it gives the symbol is defined in. This is null
comment|/// for undefined symbols.
comment|///
comment|/// If this is a fragment, then it gives the fragment this symbol's value is
comment|/// relative to, if any.
comment|///
comment|/// For the 'HasName' integer, this is true if this symbol is named.
comment|/// A named symbol will have a pointer to the name allocated in the bytes
comment|/// immediately prior to the MCSymbol.
name|mutable
name|PointerIntPair
operator|<
name|MCFragment
operator|*
operator|,
literal|1
operator|>
name|FragmentAndHasName
expr_stmt|;
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
name|unsigned
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
comment|/// LLVM RTTI discriminator. This is actually a SymbolKind enumerator, but is
comment|/// unsigned to avoid sign extension and achieve better bitpacking with MSVC.
name|unsigned
name|Kind
range|:
literal|3
decl_stmt|;
comment|/// True if we have created a relocation that uses this symbol.
name|mutable
name|unsigned
name|IsUsedInReloc
range|:
literal|1
decl_stmt|;
comment|/// This is actually a Contents enumerator, but is unsigned to avoid sign
comment|/// extension and achieve better bitpacking with MSVC.
name|unsigned
name|SymbolContents
range|:
literal|2
decl_stmt|;
comment|/// The alignment of the symbol, if it is 'common', or -1.
comment|///
comment|/// The alignment is stored as log2(align) + 1.  This allows all values from
comment|/// 0 to 2^31 to be stored which is every power of 2 representable by an
comment|/// unsigned.
enum_decl|enum :
name|unsigned
block|{
name|NumCommonAlignmentBits
init|=
literal|5
block|}
enum_decl|;
name|unsigned
name|CommonAlignLog2
range|:
name|NumCommonAlignmentBits
decl_stmt|;
comment|/// The Flags field is used by object file implementations to store
comment|/// additional per symbol information which is not easily classified.
enum_decl|enum :
name|unsigned
block|{
name|NumFlagsBits
init|=
literal|16
block|}
enum_decl|;
name|mutable
name|uint32_t
name|Flags
range|:
name|NumFlagsBits
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
comment|/// If non-null, the value for a variable symbol.
specifier|const
name|MCExpr
modifier|*
name|Value
decl_stmt|;
block|}
union|;
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
name|using
name|NameEntryStorageTy
init|=
expr|union
block|{
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
name|NameEntry
block|;
name|uint64_t
name|AlignmentPadding
block|;   }
decl_stmt|;
name|MCSymbol
argument_list|(
argument|SymbolKind Kind
argument_list|,
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
block|:
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
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|IsUsedInReloc
argument_list|(
name|false
argument_list|)
operator|,
name|SymbolContents
argument_list|(
name|SymContentsUnset
argument_list|)
operator|,
name|CommonAlignLog2
argument_list|(
literal|0
argument_list|)
operator|,
name|Flags
argument_list|(
literal|0
argument_list|)
block|{
name|Offset
operator|=
literal|0
block|;
name|FragmentAndHasName
operator|.
name|setInt
argument_list|(
operator|!
operator|!
name|Name
argument_list|)
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
name|MCSection
modifier|*
name|getSectionPtr
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
if|if
condition|(
name|MCFragment
modifier|*
name|F
init|=
name|getFragment
argument_list|(
name|SetUsed
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|F
operator|!=
name|AbsolutePseudoFragment
argument_list|)
expr_stmt|;
return|return
name|F
operator|->
name|getParent
argument_list|()
return|;
block|}
return|return
name|nullptr
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
name|FragmentAndHasName
operator|.
name|getInt
argument_list|()
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
name|MCSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCSymbol
modifier|&
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
comment|/// getName - Get the symbol name.
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|FragmentAndHasName
operator|.
name|getInt
argument_list|()
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
name|bool
name|isRegistered
argument_list|()
specifier|const
block|{
return|return
name|IsRegistered
return|;
block|}
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
comment|/// \name Accessors
comment|/// @{
comment|/// isTemporary - Check if this is an assembler temporary symbol.
name|bool
name|isTemporary
argument_list|()
specifier|const
block|{
return|return
name|IsTemporary
return|;
block|}
comment|/// isUsed - Check if this is used.
name|bool
name|isUsed
argument_list|()
specifier|const
block|{
return|return
name|IsUsed
return|;
block|}
name|void
name|setUsed
argument_list|(
name|bool
name|Value
argument_list|)
decl|const
block|{
name|IsUsed
operator||=
name|Value
expr_stmt|;
block|}
comment|/// \brief Check if this symbol is redefinable.
name|bool
name|isRedefinable
argument_list|()
specifier|const
block|{
return|return
name|IsRedefinable
return|;
block|}
comment|/// \brief Mark this symbol as redefinable.
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
comment|/// \brief Prepare this symbol to be redefined.
name|void
name|redefineIfPossible
parameter_list|()
block|{
if|if
condition|(
name|IsRedefinable
condition|)
block|{
if|if
condition|(
name|SymbolContents
operator|==
name|SymContentsVariable
condition|)
block|{
name|Value
operator|=
name|nullptr
expr_stmt|;
name|SymbolContents
operator|=
name|SymContentsUnset
expr_stmt|;
block|}
name|setUndefined
argument_list|()
expr_stmt|;
name|IsRedefinable
operator|=
name|false
expr_stmt|;
block|}
block|}
comment|/// @}
comment|/// \name Associated Sections
comment|/// @{
comment|/// isDefined - Check if this symbol is defined (i.e., it has an address).
comment|///
comment|/// Defined symbols are either absolute or in some section.
name|bool
name|isDefined
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
return|return
name|getFragment
argument_list|(
name|SetUsed
argument_list|)
operator|!=
name|nullptr
return|;
block|}
comment|/// isInSection - Check if this symbol is defined in some section (i.e., it
comment|/// is defined but not absolute).
name|bool
name|isInSection
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
return|return
name|isDefined
argument_list|(
name|SetUsed
argument_list|)
operator|&&
operator|!
name|isAbsolute
argument_list|(
name|SetUsed
argument_list|)
return|;
block|}
comment|/// isUndefined - Check if this symbol undefined (i.e., implicitly defined).
name|bool
name|isUndefined
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
return|return
operator|!
name|isDefined
argument_list|(
name|SetUsed
argument_list|)
return|;
block|}
comment|/// isAbsolute - Check if this is an absolute symbol.
name|bool
name|isAbsolute
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
return|return
name|getFragment
argument_list|(
name|SetUsed
argument_list|)
operator|==
name|AbsolutePseudoFragment
return|;
block|}
comment|/// Get the section associated with a defined, non-absolute symbol.
name|MCSection
modifier|&
name|getSection
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isInSection
argument_list|(
name|SetUsed
argument_list|)
operator|&&
literal|"Invalid accessor!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|getSectionPtr
argument_list|(
name|SetUsed
argument_list|)
return|;
block|}
comment|/// Mark the symbol as defined in the fragment \p F.
name|void
name|setFragment
argument_list|(
name|MCFragment
operator|*
name|F
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|!
name|isVariable
argument_list|()
operator|&&
literal|"Cannot set fragment of variable"
argument_list|)
expr_stmt|;
name|FragmentAndHasName
operator|.
name|setPointer
argument_list|(
name|F
argument_list|)
expr_stmt|;
block|}
comment|/// Mark the symbol as undefined.
name|void
name|setUndefined
parameter_list|()
block|{
name|FragmentAndHasName
operator|.
name|setPointer
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
block|}
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
name|bool
name|isWasm
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SymbolKindWasm
return|;
block|}
comment|/// @}
comment|/// \name Variable Symbols
comment|/// @{
comment|/// isVariable - Check if this is a variable symbol.
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|SymbolContents
operator|==
name|SymContentsVariable
return|;
block|}
comment|/// getVariableValue - Get the value for variable symbols.
specifier|const
name|MCExpr
modifier|*
name|getVariableValue
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isVariable
argument_list|()
operator|&&
literal|"Invalid accessor!"
argument_list|)
expr_stmt|;
name|IsUsed
operator||=
name|SetUsed
expr_stmt|;
return|return
name|Value
return|;
block|}
name|void
name|setVariableValue
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// @}
comment|/// Get the (implementation defined) index.
name|uint32_t
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
comment|/// Set the (implementation defined) index.
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
name|uint64_t
name|getOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|SymbolContents
operator|==
name|SymContentsUnset
operator|||
name|SymbolContents
operator|==
name|SymContentsOffset
operator|)
operator|&&
literal|"Cannot get offset for a common/variable symbol"
argument_list|)
block|;
return|return
name|Offset
return|;
block|}
name|void
name|setOffset
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|SymbolContents
operator|==
name|SymContentsUnset
operator|||
name|SymbolContents
operator|==
name|SymContentsOffset
operator|)
operator|&&
literal|"Cannot set offset for a common/variable symbol"
argument_list|)
expr_stmt|;
name|Offset
operator|=
name|Value
expr_stmt|;
name|SymbolContents
operator|=
name|SymContentsOffset
expr_stmt|;
block|}
comment|/// Return the size of a 'common' symbol.
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
comment|/// Mark this symbol as being 'common'.
comment|///
comment|/// \param Size - The size of the symbol.
comment|/// \param Align - The alignment of the symbol.
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
name|SymbolContents
operator|=
name|SymContentsCommon
expr_stmt|;
name|assert
argument_list|(
operator|(
operator|!
name|Align
operator|||
name|isPowerOf2_32
argument_list|(
name|Align
argument_list|)
operator|)
operator|&&
literal|"Alignment must be a power of 2"
argument_list|)
expr_stmt|;
name|unsigned
name|Log2Align
init|=
name|Log2_32
argument_list|(
name|Align
argument_list|)
operator|+
literal|1
decl_stmt|;
name|assert
argument_list|(
name|Log2Align
operator|<
operator|(
literal|1U
operator|<<
name|NumCommonAlignmentBits
operator|)
operator|&&
literal|"Out of range alignment"
argument_list|)
expr_stmt|;
name|CommonAlignLog2
operator|=
name|Log2Align
expr_stmt|;
block|}
comment|///  Return the alignment of a 'common' symbol.
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
name|CommonAlignLog2
condition|?
operator|(
literal|1U
operator|<<
operator|(
name|CommonAlignLog2
operator|-
literal|1
operator|)
operator|)
else|:
literal|0
return|;
block|}
comment|/// Declare this symbol as being 'common'.
comment|///
comment|/// \param Size - The size of the symbol.
comment|/// \param Align - The alignment of the symbol.
comment|/// \return True if symbol was already declared as a different type
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
name|getCommonAlignment
argument_list|()
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
comment|/// Is this a 'common' symbol.
name|bool
name|isCommon
argument_list|()
specifier|const
block|{
return|return
name|SymbolContents
operator|==
name|SymContentsCommon
return|;
block|}
name|MCFragment
modifier|*
name|getFragment
argument_list|(
name|bool
name|SetUsed
operator|=
name|true
argument_list|)
decl|const
block|{
name|MCFragment
modifier|*
name|Fragment
init|=
name|FragmentAndHasName
operator|.
name|getPointer
argument_list|()
decl_stmt|;
if|if
condition|(
name|Fragment
operator|||
operator|!
name|isVariable
argument_list|()
condition|)
return|return
name|Fragment
return|;
name|Fragment
operator|=
name|getVariableValue
argument_list|(
name|SetUsed
argument_list|)
operator|->
name|findAssociatedFragment
argument_list|()
expr_stmt|;
name|FragmentAndHasName
operator|.
name|setPointer
argument_list|(
name|Fragment
argument_list|)
expr_stmt|;
return|return
name|Fragment
return|;
block|}
name|bool
name|isExternal
argument_list|()
specifier|const
block|{
return|return
name|IsExternal
return|;
block|}
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
name|bool
name|isPrivateExtern
argument_list|()
specifier|const
block|{
return|return
name|IsPrivateExtern
return|;
block|}
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
comment|/// print - Print the value to the stream \p OS.
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
comment|/// dump - Print the value to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|/// Get the (implementation defined) symbol flags.
name|uint32_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// Set the (implementation defined) symbol flags.
name|void
name|setFlags
argument_list|(
name|uint32_t
name|Value
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Value
operator|<
operator|(
literal|1U
operator|<<
name|NumFlagsBits
operator|)
operator|&&
literal|"Out of range flags"
argument_list|)
expr_stmt|;
name|Flags
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Modify the flags via a mask
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
name|assert
argument_list|(
name|Value
operator|<
operator|(
literal|1U
operator|<<
name|NumFlagsBits
operator|)
operator|&&
literal|"Out of range flags"
argument_list|)
expr_stmt|;
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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

begin_comment
comment|// LLVM_MC_MCSYMBOL_H
end_comment

end_unit

