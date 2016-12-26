begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Thunks.h --------------------------------------------------------===//
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
name|LLD_ELF_THUNKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_THUNKS_H
end_define

begin_include
include|#
directive|include
file|"Relocations.h"
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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InputSection
expr_stmt|;
comment|// Class to describe an instance of a Thunk.
comment|// A Thunk is a code-sequence inserted by the linker in between a caller and
comment|// the callee. The relocation to the callee is redirected to the Thunk, which
comment|// after executing transfers control to the callee. Typical uses of Thunks
comment|// include transferring control from non-pi to pi and changing state on
comment|// targets like ARM.
comment|//
comment|// Thunks can be created for DefinedRegular and Shared Symbols. The Thunk
comment|// is stored in a field of the Symbol Destination.
comment|// Thunks to be written to an InputSection are recorded by the InputSection.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|Thunk
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
name|public
operator|:
name|Thunk
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|Destination
argument_list|,
specifier|const
name|InputSection
operator|<
name|ELFT
operator|>
operator|&
name|Owner
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|Thunk
argument_list|()
expr_stmt|;
name|virtual
name|uint32_t
name|size
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|writeTo
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
decl|const
block|{}
name|uintX_t
name|getVA
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
specifier|const
name|SymbolBody
modifier|&
name|Destination
decl_stmt|;
specifier|const
name|InputSection
operator|<
name|ELFT
operator|>
operator|&
name|Owner
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
empty_stmt|;
comment|// For a Relocation to symbol S from InputSection Src, create a Thunk and
comment|// update the fields of S and the InputSection that the Thunk body will be
comment|// written to. At present there are implementations for ARM and Mips Thunks.
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|addThunk
argument_list|(
argument|uint32_t RelocType
argument_list|,
argument|SymbolBody&S
argument_list|,
argument|InputSection<ELFT>&Src
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace elf
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

