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
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

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
comment|/// \brief Extensible enumeration to represent the type of a fixup.
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
name|FK_PCRel_1
block|,
comment|///< A one-byte pc relative fixup.
name|FK_PCRel_2
block|,
comment|///< A two-byte pc relative fixup.
name|FK_PCRel_4
block|,
comment|///< A four-byte pc relative fixup.
name|FK_PCRel_8
block|,
comment|///< A eight-byte pc relative fixup.
name|FK_GPRel_1
block|,
comment|///< A one-byte gp relative fixup.
name|FK_GPRel_2
block|,
comment|///< A two-byte gp relative fixup.
name|FK_GPRel_4
block|,
comment|///< A four-byte gp relative fixup.
name|FK_GPRel_8
block|,
comment|///< A eight-byte gp relative fixup.
name|FK_DTPRel_4
block|,
comment|///< A four-byte dtp relative fixup.
name|FK_DTPRel_8
block|,
comment|///< A eight-byte dtp relative fixup.
name|FK_TPRel_4
block|,
comment|///< A four-byte tp relative fixup.
name|FK_TPRel_8
block|,
comment|///< A eight-byte tp relative fixup.
name|FK_SecRel_1
block|,
comment|///< A one-byte section relative fixup.
name|FK_SecRel_2
block|,
comment|///< A two-byte section relative fixup.
name|FK_SecRel_4
block|,
comment|///< A four-byte section relative fixup.
name|FK_SecRel_8
block|,
comment|///< A eight-byte section relative fixup.
name|FirstTargetFixupKind
init|=
literal|128
block|,
comment|// Limit range of target fixups, in case we want to pack more efficiently
comment|// later.
name|MaxTargetFixupKind
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|}
enum|;
comment|/// \brief Encode information on a single operation to perform on a byte
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
comment|/// The value to put into the fixup location. The exact interpretation of the
comment|/// expression is target dependent, usually it will be one of the operands to
comment|/// an instruction or an assembler directive.
specifier|const
name|MCExpr
modifier|*
name|Value
decl_stmt|;
comment|/// The byte index of start of the relocation inside the MCFragment.
name|uint32_t
name|Offset
decl_stmt|;
comment|/// The target dependent kind of fixup item this is. The kind is used to
comment|/// determine how the operand value should be encoded into the instruction.
name|unsigned
name|Kind
decl_stmt|;
comment|/// The source location which gave rise to the fixup, if any.
name|SMLoc
name|Loc
decl_stmt|;
name|public
label|:
specifier|static
name|MCFixup
name|create
parameter_list|(
name|uint32_t
name|Offset
parameter_list|,
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|,
name|MCFixupKind
name|Kind
parameter_list|,
name|SMLoc
name|Loc
init|=
name|SMLoc
argument_list|()
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|Kind
argument_list|)
operator|<
name|MaxTargetFixupKind
operator|&&
literal|"Kind out of range!"
argument_list|)
expr_stmt|;
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
name|FI
operator|.
name|Loc
operator|=
name|Loc
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
name|uint32_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|void
name|setOffset
parameter_list|(
name|uint32_t
name|Value
parameter_list|)
block|{
name|Offset
operator|=
name|Value
expr_stmt|;
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
comment|/// \brief Return the generic fixup kind for a value with the given size. It
comment|/// is an error to pass an unsupported size.
specifier|static
name|MCFixupKind
name|getKindForSize
parameter_list|(
name|unsigned
name|Size
parameter_list|,
name|bool
name|isPCRel
parameter_list|)
block|{
switch|switch
condition|(
name|Size
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Invalid generic fixup size!"
argument_list|)
expr_stmt|;
case|case
literal|1
case|:
return|return
name|isPCRel
condition|?
name|FK_PCRel_1
else|:
name|FK_Data_1
return|;
case|case
literal|2
case|:
return|return
name|isPCRel
condition|?
name|FK_PCRel_2
else|:
name|FK_Data_2
return|;
case|case
literal|4
case|:
return|return
name|isPCRel
condition|?
name|FK_PCRel_4
else|:
name|FK_Data_4
return|;
case|case
literal|8
case|:
return|return
name|isPCRel
condition|?
name|FK_PCRel_8
else|:
name|FK_Data_8
return|;
block|}
block|}
name|SMLoc
name|getLoc
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
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

