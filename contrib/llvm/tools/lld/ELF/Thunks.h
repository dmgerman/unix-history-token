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
name|class
name|ThunkSection
decl_stmt|;
comment|// Class to describe an instance of a Thunk.
comment|// A Thunk is a code-sequence inserted by the linker in between a caller and
comment|// the callee. The relocation to the callee is redirected to the Thunk, which
comment|// after executing transfers control to the callee. Typical uses of Thunks
comment|// include transferring control from non-pi to pi and changing state on
comment|// targets like ARM.
comment|//
comment|// Thunks can be created for DefinedRegular, Shared and Undefined Symbols.
comment|// Thunks are assigned to synthetic ThunkSections
name|class
name|Thunk
block|{
name|public
label|:
name|Thunk
argument_list|(
specifier|const
name|SymbolBody
operator|&
name|Destination
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
argument_list|,
name|ThunkSection
operator|&
name|IS
argument_list|)
decl|const
block|{}
comment|// All Thunks must define at least one symbol ThunkSym so that we can
comment|// redirect relocations to it.
name|virtual
name|void
name|addSymbols
parameter_list|(
name|ThunkSection
modifier|&
name|IS
parameter_list|)
block|{}
comment|// Some Thunks must be placed immediately before their Target as they elide
comment|// a branch and fall through to the first Symbol in the Target.
name|virtual
name|InputSection
operator|*
name|getTargetInputSection
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|// To reuse a Thunk the caller as identified by the RelocType must be
comment|// compatible with it.
name|virtual
name|bool
name|isCompatibleWith
argument_list|(
name|uint32_t
name|RelocType
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|// The alignment requirement for this Thunk, defaults to the size of the
comment|// typical code section alignment.
specifier|const
name|SymbolBody
modifier|&
name|Destination
decl_stmt|;
name|SymbolBody
modifier|*
name|ThunkSym
decl_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
name|uint32_t
name|alignment
init|=
literal|4
decl_stmt|;
block|}
empty_stmt|;
comment|// For a Relocation to symbol S create a Thunk to be added to a synthetic
comment|// ThunkSection. At present there are implementations for ARM and Mips Thunks.
name|Thunk
modifier|*
name|addThunk
parameter_list|(
name|uint32_t
name|RelocType
parameter_list|,
name|SymbolBody
modifier|&
name|S
parameter_list|)
function_decl|;
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

