begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Relocations.h -------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_ELF_RELOCATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_RELOCATIONS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|SymbolBody
decl_stmt|;
name|class
name|InputSection
decl_stmt|;
name|class
name|InputSectionBase
decl_stmt|;
name|class
name|OutputSection
decl_stmt|;
struct_decl|struct
name|OutputSectionCommand
struct_decl|;
comment|// List of target-independent relocation types. Relocations read
comment|// from files are converted to these types so that the main code
comment|// doesn't have to know about architecture-specific details.
enum|enum
name|RelExpr
block|{
name|R_ABS
block|,
name|R_ARM_SBREL
block|,
name|R_GOT
block|,
name|R_GOTONLY_PC
block|,
name|R_GOTONLY_PC_FROM_END
block|,
name|R_GOTREL
block|,
name|R_GOTREL_FROM_END
block|,
name|R_GOT_FROM_END
block|,
name|R_GOT_OFF
block|,
name|R_GOT_PAGE_PC
block|,
name|R_GOT_PC
block|,
name|R_HINT
block|,
name|R_MIPS_GOTREL
block|,
name|R_MIPS_GOT_GP
block|,
name|R_MIPS_GOT_GP_PC
block|,
name|R_MIPS_GOT_LOCAL_PAGE
block|,
name|R_MIPS_GOT_OFF
block|,
name|R_MIPS_GOT_OFF32
block|,
name|R_MIPS_TLSGD
block|,
name|R_MIPS_TLSLD
block|,
name|R_NEG_TLS
block|,
name|R_NONE
block|,
name|R_PAGE_PC
block|,
name|R_PC
block|,
name|R_PLT
block|,
name|R_PLT_PAGE_PC
block|,
name|R_PLT_PC
block|,
name|R_PPC_OPD
block|,
name|R_PPC_PLT_OPD
block|,
name|R_PPC_TOC
block|,
name|R_RELAX_GOT_PC
block|,
name|R_RELAX_GOT_PC_NOPIC
block|,
name|R_RELAX_TLS_GD_TO_IE
block|,
name|R_RELAX_TLS_GD_TO_IE_ABS
block|,
name|R_RELAX_TLS_GD_TO_IE_END
block|,
name|R_RELAX_TLS_GD_TO_IE_PAGE_PC
block|,
name|R_RELAX_TLS_GD_TO_LE
block|,
name|R_RELAX_TLS_GD_TO_LE_NEG
block|,
name|R_RELAX_TLS_IE_TO_LE
block|,
name|R_RELAX_TLS_LD_TO_LE
block|,
name|R_SIZE
block|,
name|R_TLS
block|,
name|R_TLSDESC
block|,
name|R_TLSDESC_CALL
block|,
name|R_TLSDESC_PAGE
block|,
name|R_TLSGD
block|,
name|R_TLSGD_PC
block|,
name|R_TLSLD
block|,
name|R_TLSLD_PC
block|, }
enum|;
comment|// Build a bitmask with one bit set for each RelExpr.
comment|//
comment|// Constexpr function arguments can't be used in static asserts, so we
comment|// use template arguments to build the mask.
comment|// But function template partial specializations don't exist (needed
comment|// for base case of the recursion), so we need a dummy struct.
name|template
operator|<
name|RelExpr
operator|...
name|Exprs
operator|>
expr|struct
name|RelExprMaskBuilder
block|{
specifier|static
specifier|inline
name|uint64_t
name|build
argument_list|()
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;
comment|// Specialization for recursive case.
name|template
operator|<
name|RelExpr
name|Head
block|,
name|RelExpr
operator|...
name|Tail
operator|>
expr|struct
name|RelExprMaskBuilder
operator|<
name|Head
block|,
name|Tail
operator|...
operator|>
block|{
specifier|static
specifier|inline
name|uint64_t
name|build
argument_list|()
block|{
name|static_assert
argument_list|(
literal|0
operator|<=
name|Head
operator|&&
name|Head
operator|<
literal|64
argument_list|,
literal|"RelExpr is too large for 64-bit mask!"
argument_list|)
block|;
return|return
operator|(
name|uint64_t
argument_list|(
literal|1
argument_list|)
operator|<<
name|Head
operator|)
operator||
name|RelExprMaskBuilder
operator|<
name|Tail
operator|...
operator|>
operator|::
name|build
argument_list|()
return|;
block|}
expr|}
block|;
comment|// Return true if `Expr` is one of `Exprs`.
comment|// There are fewer than 64 RelExpr's, so we can represent any set of
comment|// RelExpr's as a constant bit mask and test for membership with a
comment|// couple cheap bitwise operations.
name|template
operator|<
name|RelExpr
operator|...
name|Exprs
operator|>
name|bool
name|isRelExprOneOf
argument_list|(
argument|RelExpr Expr
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|<=
name|Expr
operator|&&
operator|(
name|int
operator|)
name|Expr
operator|<
literal|64
operator|&&
literal|"RelExpr is too large for 64-bit mask!"
argument_list|)
block|;
return|return
operator|(
name|uint64_t
argument_list|(
literal|1
argument_list|)
operator|<<
name|Expr
operator|)
operator|&
name|RelExprMaskBuilder
operator|<
name|Exprs
operator|...
operator|>
operator|::
name|build
argument_list|()
return|;
block|}
comment|// Architecture-neutral representation of relocation.
expr|struct
name|Relocation
block|{
name|RelExpr
name|Expr
block|;
name|uint32_t
name|Type
block|;
name|uint64_t
name|Offset
block|;
name|int64_t
name|Addend
block|;
name|SymbolBody
operator|*
name|Sym
block|; }
block|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|scanRelocations
argument_list|(
name|InputSectionBase
operator|&
argument_list|)
block|;
name|class
name|ThunkSection
block|;
name|class
name|Thunk
block|;
name|class
name|ThunkCreator
block|{
name|public
operator|:
comment|// Return true if Thunks have been added to OutputSections
name|bool
name|createThunks
argument_list|(
name|ArrayRef
operator|<
name|OutputSectionCommand
operator|*
operator|>
name|OutputSections
argument_list|)
block|;
comment|// The number of completed passes of createThunks this permits us
comment|// to do one time initialization on Pass 0 and put a limit on the
comment|// number of times it can be called to prevent infinite loops.
name|uint32_t
name|Pass
operator|=
literal|0
block|;
name|private
operator|:
name|void
name|mergeThunks
argument_list|()
block|;
name|ThunkSection
operator|*
name|getOSThunkSec
argument_list|(
name|OutputSection
operator|*
name|OS
argument_list|,
name|std
operator|::
name|vector
operator|<
name|InputSection
operator|*
operator|>
operator|*
name|ISR
argument_list|)
block|;
name|ThunkSection
operator|*
name|getISThunkSec
argument_list|(
name|InputSection
operator|*
name|IS
argument_list|,
name|OutputSection
operator|*
name|OS
argument_list|)
block|;
name|void
name|forEachExecInputSection
argument_list|(
name|ArrayRef
operator|<
name|OutputSectionCommand
operator|*
operator|>
name|OutputSections
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|OutputSection
operator|*
argument_list|,
name|std
operator|::
name|vector
operator|<
name|InputSection
operator|*
operator|>
operator|*
argument_list|,
name|InputSection
operator|*
argument_list|)
operator|>
name|Fn
argument_list|)
block|;
name|std
operator|::
name|pair
operator|<
name|Thunk
operator|*
block|,
name|bool
operator|>
name|getThunk
argument_list|(
argument|SymbolBody&Body
argument_list|,
argument|uint32_t Type
argument_list|)
block|;
name|ThunkSection
operator|*
name|addThunkSection
argument_list|(
argument|OutputSection *OS
argument_list|,
argument|std::vector<InputSection *> *
argument_list|,
argument|uint64_t Off
argument_list|)
block|;
comment|// Track Symbols that already have a Thunk
name|llvm
operator|::
name|DenseMap
operator|<
name|SymbolBody
operator|*
block|,
name|Thunk
operator|*
operator|>
name|ThunkedSymbols
block|;
comment|// Find a Thunk from the Thunks symbol definition, we can use this to find
comment|// the Thunk from a relocation to the Thunks symbol definition.
name|llvm
operator|::
name|DenseMap
operator|<
name|SymbolBody
operator|*
block|,
name|Thunk
operator|*
operator|>
name|Thunks
block|;
comment|// Track InputSections that have a ThunkSection placed in front
name|llvm
operator|::
name|DenseMap
operator|<
name|InputSection
operator|*
block|,
name|ThunkSection
operator|*
operator|>
name|ThunkedSections
block|;
comment|// All the ThunkSections that we have created, organised by OutputSection
comment|// will contain a mix of ThunkSections that have been created this pass, and
comment|// ThunkSections that have been merged into the OutputSection on previous
comment|// passes
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|vector
operator|<
name|InputSection
operator|*
operator|>
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|ThunkSection
operator|*
operator|>>
name|ThunkSections
block|;
comment|// The ThunkSection for this vector of InputSections
name|ThunkSection
operator|*
name|CurTS
block|; }
block|;
comment|// Return a int64_t to make sure we get the sign extension out of the way as
comment|// early as possible.
name|template
operator|<
name|class
name|ELFT
operator|>
specifier|static
specifier|inline
name|int64_t
name|getAddend
argument_list|(
argument|const typename ELFT::Rel&Rel
argument_list|)
block|{
return|return
literal|0
return|;
block|}
name|template
operator|<
name|class
name|ELFT
operator|>
specifier|static
specifier|inline
name|int64_t
name|getAddend
argument_list|(
argument|const typename ELFT::Rela&Rel
argument_list|)
block|{
return|return
name|Rel
operator|.
name|r_addend
return|;
block|}
expr|} }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

