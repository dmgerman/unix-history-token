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
file|"llvm/MC/MCExpr.h"
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
comment|// TODO: Merge completely with MCSymbol.
name|class
name|MCSymbolData
block|{
comment|/// Fragment - The fragment this symbol's value is relative to, if any. Also
comment|/// stores if this symbol is visible outside this translation unit (bit 0) or
comment|/// if it is private extern (bit 1).
name|PointerIntPair
operator|<
name|MCFragment
operator|*
operator|,
literal|2
operator|>
name|Fragment
expr_stmt|;
union|union
block|{
comment|/// Offset - The offset to apply to the fragment address to form this
comment|/// symbol's value.
name|uint64_t
name|Offset
decl_stmt|;
comment|/// CommonSize - The size of the symbol, if it is 'common'.
name|uint64_t
name|CommonSize
decl_stmt|;
block|}
union|;
comment|/// SymbolSize - An expression describing how to calculate the size of
comment|/// a symbol. If a symbol has no size this field will be NULL.
specifier|const
name|MCExpr
modifier|*
name|SymbolSize
init|=
name|nullptr
decl_stmt|;
comment|/// CommonAlign - The alignment of the symbol, if it is 'common', or -1.
comment|//
comment|// FIXME: Pack this in with other fields?
name|unsigned
name|CommonAlign
init|=
operator|-
literal|1U
decl_stmt|;
comment|/// Flags - The Flags field is used by object file implementations to store
comment|/// additional per symbol information which is not easily classified.
name|uint32_t
name|Flags
init|=
literal|0
decl_stmt|;
name|public
label|:
name|MCSymbolData
argument_list|()
block|{
name|Offset
operator|=
literal|0
expr_stmt|;
block|}
name|MCFragment
operator|*
name|getFragment
argument_list|()
specifier|const
block|{
return|return
name|Fragment
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setFragment
parameter_list|(
name|MCFragment
modifier|*
name|Value
parameter_list|)
block|{
name|Fragment
operator|.
name|setPointer
argument_list|(
name|Value
argument_list|)
expr_stmt|;
block|}
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
comment|/// @}
comment|/// \name Symbol Attributes
comment|/// @{
name|bool
name|isExternal
argument_list|()
specifier|const
block|{
return|return
name|Fragment
operator|.
name|getInt
argument_list|()
operator|&
literal|1
return|;
block|}
name|void
name|setExternal
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|Fragment
operator|.
name|setInt
argument_list|(
operator|(
name|Fragment
operator|.
name|getInt
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
name|unsigned
argument_list|(
name|Value
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|isPrivateExtern
argument_list|()
specifier|const
block|{
return|return
name|Fragment
operator|.
name|getInt
argument_list|()
operator|&
literal|2
return|;
block|}
name|void
name|setPrivateExtern
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|Fragment
operator|.
name|setInt
argument_list|(
operator|(
name|Fragment
operator|.
name|getInt
argument_list|()
operator|&
operator|~
literal|2
operator|)
operator||
operator|(
name|unsigned
argument_list|(
name|Value
argument_list|)
operator|<<
literal|1
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/// isCommon - Is this a 'common' symbol.
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
comment|/// setCommon - Mark this symbol as being 'common'.
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
name|CommonAlign
operator|=
name|Align
expr_stmt|;
block|}
comment|/// getCommonSize - Return the size of a 'common' symbol.
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
name|void
name|setSize
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|SS
parameter_list|)
block|{
name|SymbolSize
operator|=
name|SS
expr_stmt|;
block|}
specifier|const
name|MCExpr
operator|*
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|SymbolSize
return|;
block|}
comment|/// getCommonAlignment - Return the alignment of a 'common' symbol.
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
comment|/// getFlags - Get the (implementation defined) symbol flags.
name|uint32_t
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
comment|/// setFlags - Set the (implementation defined) symbol flags.
name|void
name|setFlags
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
name|Flags
operator|=
name|Value
expr_stmt|;
block|}
comment|/// modifyFlags - Modify the flags via a mask
name|void
name|modifyFlags
parameter_list|(
name|uint32_t
name|Value
parameter_list|,
name|uint32_t
name|Mask
parameter_list|)
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
comment|/// @}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
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
comment|// Special sentinal value for the absolute pseudo section.
comment|//
comment|// FIXME: Use a PointerInt wrapper for this?
specifier|static
name|MCSection
modifier|*
name|AbsolutePseudoSection
decl_stmt|;
comment|/// Name - The name of the symbol.  The referred-to string data is actually
comment|/// held by the StringMap that lives in MCContext.
specifier|const
name|StringMapEntry
operator|<
name|bool
operator|>
operator|*
name|Name
expr_stmt|;
comment|/// The section the symbol is defined in. This is null for undefined symbols,
comment|/// and the special AbsolutePseudoSection value for absolute symbols. If this
comment|/// is a variable symbol, this caches the variable value's section.
name|mutable
name|MCSection
modifier|*
name|Section
decl_stmt|;
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
name|HasData
range|:
literal|1
decl_stmt|;
comment|/// Index field, for use by the object file implementation.
name|mutable
name|uint64_t
name|Index
range|:
literal|60
decl_stmt|;
name|mutable
name|MCSymbolData
name|Data
decl_stmt|;
name|private
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
name|MCSymbol
argument_list|(
argument|const StringMapEntry<bool> *Name
argument_list|,
argument|bool isTemporary
argument_list|)
block|:
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|Section
argument_list|(
name|nullptr
argument_list|)
operator|,
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
name|HasData
argument_list|(
name|false
argument_list|)
operator|,
name|Index
argument_list|(
literal|0
argument_list|)
block|{}
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
name|FindAssociatedSection
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
return|return
name|Name
operator|?
name|Name
operator|->
name|first
argument_list|()
operator|:
literal|""
return|;
block|}
name|bool
name|hasData
argument_list|()
specifier|const
block|{
return|return
name|HasData
return|;
block|}
comment|/// Get associated symbol data.
name|MCSymbolData
operator|&
name|getData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|HasData
operator|&&
literal|"Missing symbol data!"
argument_list|)
block|;
return|return
name|Data
return|;
block|}
comment|/// Initialize symbol data.
comment|///
comment|/// Nothing really to do here, but this is enables an assertion that \a
comment|/// MCAssembler::getOrCreateSymbolData() has actually been called before
comment|/// anyone calls \a getData().
name|void
name|initializeData
argument_list|()
specifier|const
block|{
name|HasData
operator|=
name|true
block|; }
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
operator|=
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
name|Value
operator|=
name|nullptr
expr_stmt|;
name|Section
operator|=
name|nullptr
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
comment|/// isInSection - Check if this symbol is defined in some section (i.e., it
comment|/// is defined but not absolute).
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
comment|/// isUndefined - Check if this symbol undefined (i.e., implicitly defined).
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
comment|/// isAbsolute - Check if this is an absolute symbol.
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
comment|/// Get the section associated with a defined, non-absolute symbol.
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
comment|/// Mark the symbol as defined in the section \p S.
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
name|Section
operator|=
operator|&
name|S
expr_stmt|;
block|}
comment|/// setUndefined - Mark the symbol as undefined.
name|void
name|setUndefined
parameter_list|()
block|{
name|Section
operator|=
name|nullptr
expr_stmt|;
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
name|Value
operator|!=
name|nullptr
return|;
block|}
comment|/// getVariableValue() - Get the value for variable symbols.
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
name|uint64_t
name|getIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|HasData
operator|&&
literal|"Uninitialized symbol data"
argument_list|)
block|;
return|return
name|Index
return|;
block|}
comment|/// Set the (implementation defined) index.
name|void
name|setIndex
argument_list|(
name|uint64_t
name|Value
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|HasData
operator|&&
literal|"Uninitialized symbol data"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
operator|(
name|Value
operator|>>
literal|60
operator|)
operator|&&
literal|"Not enough bits for value"
argument_list|)
expr_stmt|;
name|Index
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

