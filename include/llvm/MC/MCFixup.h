begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCFixup.h - Instruction Relocation and Patching -*- C++ -*-===//
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
name|LLVM_MC_MCFIXUP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCFIXUP_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCExpr
decl_stmt|;
comment|// Private constants, do not use.
comment|//
comment|// This is currently laid out so that the MCFixup fields can be efficiently
comment|// accessed, while keeping the offset field large enough that the assembler
comment|// backend can reasonably use the MCFixup representation for an entire fragment
comment|// (splitting any overly large fragments).
comment|//
comment|// The division of bits between the kind and the opindex can be tweaked if we
comment|// end up needing more bits for target dependent kinds.
enum|enum
block|{
name|MCFIXUP_NUM_GENERIC_KINDS
init|=
literal|128
block|,
name|MCFIXUP_NUM_KIND_BITS
init|=
literal|16
block|,
name|MCFIXUP_NUM_OFFSET_BITS
init|=
operator|(
literal|32
operator|-
name|MCFIXUP_NUM_KIND_BITS
operator|)
block|}
enum|;
comment|/// MCFixupKind - Extensible enumeration to represent the type of a fixup.
enum|enum
name|MCFixupKind
block|{
name|FK_Data_1
init|=
literal|0
block|,
comment|///< A one-byte fixup.
name|FK_Data_2
block|,
comment|///< A two-byte fixup.
name|FK_Data_4
block|,
comment|///< A four-byte fixup.
name|FK_Data_8
block|,
comment|///< A eight-byte fixup.
name|FirstTargetFixupKind
init|=
name|MCFIXUP_NUM_GENERIC_KINDS
block|,
name|MaxTargetFixupKind
init|=
operator|(
literal|1
operator|<<
name|MCFIXUP_NUM_KIND_BITS
operator|)
block|}
enum|;
comment|/// MCFixup - Encode information on a single operation to perform on an byte
comment|/// sequence (e.g., an encoded instruction) which requires assemble- or run-
comment|/// time patching.
comment|///
comment|/// Fixups are used any time the target instruction encoder needs to represent
comment|/// some value in an instruction which is not yet concrete. The encoder will
comment|/// encode the instruction assuming the value is 0, and emit a fixup which
comment|/// communicates to the assembler backend how it should rewrite the encoded
comment|/// value.
comment|///
comment|/// During the process of relaxation, the assembler will apply fixups as
comment|/// symbolic values become concrete. When relaxation is complete, any remaining
comment|/// fixups become relocations in the object file (or errors, if the fixup cannot
comment|/// be encoded on the target).
name|class
name|MCFixup
block|{
specifier|static
specifier|const
name|unsigned
name|MaxOffset
init|=
literal|1
operator|<<
name|MCFIXUP_NUM_KIND_BITS
decl_stmt|;
comment|/// The value to put into the fixup location. The exact interpretation of the
comment|/// expression is target dependent, usually it will one of the operands to an
comment|/// instruction or an assembler directive.
specifier|const
name|MCExpr
modifier|*
name|Value
decl_stmt|;
comment|/// The byte index of start of the relocation inside the encoded instruction.
name|unsigned
name|Offset
range|:
name|MCFIXUP_NUM_OFFSET_BITS
decl_stmt|;
comment|/// The target dependent kind of fixup item this is. The kind is used to
comment|/// determine how the operand value should be encoded into the instruction.
name|unsigned
name|Kind
range|:
name|MCFIXUP_NUM_KIND_BITS
decl_stmt|;
name|public
label|:
specifier|static
name|MCFixup
name|Create
parameter_list|(
name|unsigned
name|Offset
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|,
name|MCFixupKind
name|Kind
parameter_list|)
block|{
name|MCFixup
name|FI
decl_stmt|;
name|FI
operator|.
name|Value
operator|=
name|Value
expr_stmt|;
name|FI
operator|.
name|Offset
operator|=
name|Offset
expr_stmt|;
name|FI
operator|.
name|Kind
operator|=
name|unsigned
argument_list|(
name|Kind
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Offset
operator|==
name|FI
operator|.
name|getOffset
argument_list|()
operator|&&
literal|"Offset out of range!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Kind
operator|==
name|FI
operator|.
name|getKind
argument_list|()
operator|&&
literal|"Kind out of range!"
argument_list|)
expr_stmt|;
return|return
name|FI
return|;
block|}
name|MCFixupKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|MCFixupKind
argument_list|(
name|Kind
argument_list|)
return|;
block|}
name|unsigned
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
specifier|const
name|MCExpr
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
comment|/// getKindForSize - Return the generic fixup kind for a value with the given
comment|/// size. It is an error to pass an unsupported size.
specifier|static
name|MCFixupKind
name|getKindForSize
parameter_list|(
name|unsigned
name|Size
parameter_list|)
block|{
switch|switch
condition|(
name|Size
condition|)
block|{
default|default:
name|assert
argument_list|(
literal|0
operator|&&
literal|"Invalid generic fixup size!"
argument_list|)
expr_stmt|;
case|case
literal|1
case|:
return|return
name|FK_Data_1
return|;
case|case
literal|2
case|:
return|return
name|FK_Data_2
return|;
case|case
literal|4
case|:
return|return
name|FK_Data_4
return|;
case|case
literal|8
case|:
return|return
name|FK_Data_8
return|;
block|}
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

