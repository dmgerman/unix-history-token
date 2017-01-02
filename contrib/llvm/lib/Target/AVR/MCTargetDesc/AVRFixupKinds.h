begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRFixupKinds.h - AVR Specific Fixup Entries ------------*- C++ -*-===//
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
name|LLVM_AVR_FIXUP_KINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_FIXUP_KINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AVR
block|{
comment|/// The set of supported fixups.
comment|///
comment|/// Although most of the current fixup types reflect a unique relocation
comment|/// one can have multiple fixup types for a given relocation and thus need
comment|/// to be uniquely named.
comment|///
comment|/// \note This table *must* be in the same order of
comment|///       MCFixupKindInfo Infos[AVR::NumTargetFixupKinds]
comment|///       in `AVRAsmBackend.cpp`.
enum|enum
name|Fixups
block|{
comment|/// A 32-bit AVR fixup.
name|fixup_32
init|=
name|FirstTargetFixupKind
block|,
comment|/// A 7-bit PC-relative fixup for the family of conditional
comment|/// branches which take 7-bit targets (BRNE,BRGT,etc).
name|fixup_7_pcrel
block|,
comment|/// A 12-bit PC-relative fixup for the family of branches
comment|/// which take 12-bit targets (RJMP,RCALL,etc).
comment|/// \note Although the fixup is labelled as 13 bits, it
comment|///       is actually only encoded in 12. The reason for
comment|///       The nonmenclature is that AVR branch targets are
comment|///       rightshifted by 1, because instructions are always
comment|///       aligned to 2 bytes, so the 0'th bit is always 0.
comment|///       This way there is 13-bits of precision.
name|fixup_13_pcrel
block|,
comment|/// A 16-bit address.
name|fixup_16
block|,
comment|/// A 16-bit program memory address.
name|fixup_16_pm
block|,
comment|/// Replaces the 8-bit immediate with another value.
name|fixup_ldi
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the lower 8 bits of a 16-bit value (bits 0-7).
name|fixup_lo8_ldi
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a 16-bit value (bits 8-15).
name|fixup_hi8_ldi
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a 24-bit value (bits 16-23).
name|fixup_hh8_ldi
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a 32-bit value (bits 24-31).
name|fixup_ms8_ldi
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the lower 8 bits of a negated 16-bit value (bits 0-7).
name|fixup_lo8_ldi_neg
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a negated 16-bit value (bits 8-15).
name|fixup_hi8_ldi_neg
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a negated negated 24-bit value (bits 16-23).
name|fixup_hh8_ldi_neg
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a negated negated 32-bit value (bits 24-31).
name|fixup_ms8_ldi_neg
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the lower 8 bits of a 16-bit program memory address value (bits 0-7).
name|fixup_lo8_ldi_pm
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a 16-bit program memory address value (bits
comment|/// 8-15).
name|fixup_hi8_ldi_pm
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a 24-bit program memory address value (bits
comment|/// 16-23).
name|fixup_hh8_ldi_pm
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the lower 8 bits of a negated 16-bit program memory address value
comment|/// (bits 0-7).
name|fixup_lo8_ldi_pm_neg
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a negated 16-bit program memory address value
comment|/// (bits 8-15).
name|fixup_hi8_ldi_pm_neg
block|,
comment|/// Replaces the immediate operand of a 16-bit `Rd, K` instruction
comment|/// with the upper 8 bits of a negated 24-bit program memory address value
comment|/// (bits 16-23).
name|fixup_hh8_ldi_pm_neg
block|,
comment|/// A 22-bit fixup for the target of a `CALL k` or `JMP k` instruction.
name|fixup_call
block|,
name|fixup_6
block|,
comment|/// A symbol+addr fixup for the `LDD<x>+<n>,<r>" family of instructions.
name|fixup_6_adiw
block|,
name|fixup_lo8_ldi_gs
block|,
name|fixup_hi8_ldi_gs
block|,
name|fixup_8
block|,
name|fixup_8_lo8
block|,
name|fixup_8_hi8
block|,
name|fixup_8_hlo8
block|,
comment|/// Fixup to calculate the difference between two symbols.
comment|/// Is the only stateful fixup. We do not support it yet.
name|fixup_sym_diff
block|,
name|fixup_16_ldst
block|,
name|fixup_lds_sts_16
block|,
comment|/// A 6-bit port address.
name|fixup_port6
block|,
comment|/// A 5-bit port address.
name|fixup_port5
block|,
comment|// Marker
name|LastTargetFixupKind
block|,
name|NumTargetFixupKinds
init|=
name|LastTargetFixupKind
operator|-
name|FirstTargetFixupKind
block|}
enum|;
name|namespace
name|fixups
block|{
comment|/// Adjusts the value of a branch target.
comment|/// All branch targets in AVR are rightshifted by 1 to take advantage
comment|/// of the fact that all instructions are aligned to addresses of size
comment|/// 2, so bit 0 of an address is always 0. This gives us another bit
comment|/// of precision.
comment|/// \param[in,out] The target to adjust.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|adjustBranchTarget
argument_list|(
argument|T&val
argument_list|)
block|{
name|val
operator|>>=
literal|1
block|; }
block|}
comment|// end of namespace fixups
block|}
block|}
end_decl_stmt

begin_comment
comment|// end of namespace llvm::AVR
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AVR_FIXUP_KINDS_H
end_comment

end_unit

