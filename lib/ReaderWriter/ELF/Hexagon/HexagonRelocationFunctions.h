begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- HexagonRelocationFunction.h ----------------------------------------===//
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
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_RELOCATION_FUNCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_RELOCATION_FUNCTIONS_H
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
comment|/// \brief HexagonInstruction which is used to store various values
typedef|typedef
struct|struct
block|{
name|uint32_t
name|insnMask
decl_stmt|;
name|uint32_t
name|insnCmpMask
decl_stmt|;
name|uint32_t
name|insnBitMask
decl_stmt|;
name|bool
name|isDuplex
decl_stmt|;
block|}
name|Instruction
typedef|;
include|#
directive|include
file|"HexagonEncodings.h"
define|#
directive|define
name|FINDV4BITMASK
parameter_list|(
name|INSN
parameter_list|)
define|\
value|findBitMask((uint32_t) * ((llvm::support::ulittle32_t *) INSN),              \               insn_encodings,                                                  \               sizeof(insn_encodings) / sizeof(Instruction))
comment|/// \brief finds the scatter Bits that need to be used to apply relocations
specifier|inline
name|uint32_t
name|findBitMask
parameter_list|(
name|uint32_t
name|insn
parameter_list|,
name|Instruction
modifier|*
name|encodings
parameter_list|,
name|int32_t
name|numInsns
parameter_list|)
block|{
for|for
control|(
name|int32_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numInsns
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|(
name|insn
operator|&
literal|0xc000
operator|)
operator|==
literal|0
operator|)
operator|&&
operator|!
operator|(
name|encodings
index|[
name|i
index|]
operator|.
name|isDuplex
operator|)
condition|)
continue|continue;
if|if
condition|(
operator|(
operator|(
name|insn
operator|&
literal|0xc000
operator|)
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|encodings
index|[
name|i
index|]
operator|.
name|isDuplex
operator|)
condition|)
continue|continue;
if|if
condition|(
operator|(
operator|(
name|encodings
index|[
name|i
index|]
operator|.
name|insnMask
operator|)
operator|&
name|insn
operator|)
operator|==
name|encodings
index|[
name|i
index|]
operator|.
name|insnCmpMask
condition|)
return|return
name|encodings
index|[
name|i
index|]
operator|.
name|insnBitMask
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"found unknown instruction"
argument_list|)
expr_stmt|;
block|}
block|}
comment|// elf
block|}
end_decl_stmt

begin_comment
comment|// lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_RELOCATION_FUNCTIONS_H
end_comment

end_unit

