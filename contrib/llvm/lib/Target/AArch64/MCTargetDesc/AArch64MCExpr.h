begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=--- AArch64MCExpr.h - AArch64 specific MC expression classes ---*- C++ -*-=//
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
comment|// This file describes AArch64-specific MCExprs, used for modifiers like
end_comment

begin_comment
comment|// ":lo12:" or ":gottprel_g1:".
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
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64MCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64MCEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64MCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_NONE
operator|=
literal|0x000
block|,
comment|// Symbol locations specifying (roughly speaking) what calculation should be
comment|// performed to construct the final address for the relocated
comment|// symbol. E.g. direct, via the GOT, ...
name|VK_ABS
operator|=
literal|0x001
block|,
name|VK_SABS
operator|=
literal|0x002
block|,
name|VK_GOT
operator|=
literal|0x003
block|,
name|VK_DTPREL
operator|=
literal|0x004
block|,
name|VK_GOTTPREL
operator|=
literal|0x005
block|,
name|VK_TPREL
operator|=
literal|0x006
block|,
name|VK_TLSDESC
operator|=
literal|0x007
block|,
name|VK_SymLocBits
operator|=
literal|0x00f
block|,
comment|// Variants specifying which part of the final address calculation is
comment|// used. E.g. the low 12 bits for an ADD/LDR, the middle 16 bits for a
comment|// MOVZ/MOVK.
name|VK_PAGE
operator|=
literal|0x010
block|,
name|VK_PAGEOFF
operator|=
literal|0x020
block|,
name|VK_HI12
operator|=
literal|0x030
block|,
name|VK_G0
operator|=
literal|0x040
block|,
name|VK_G1
operator|=
literal|0x050
block|,
name|VK_G2
operator|=
literal|0x060
block|,
name|VK_G3
operator|=
literal|0x070
block|,
name|VK_AddressFragBits
operator|=
literal|0x0f0
block|,
comment|// Whether the final relocation is a checked one (where a linker should
comment|// perform a range-check on the final address) or not. Note that this field
comment|// is unfortunately sometimes omitted from the assembly syntax. E.g. :lo12:
comment|// on its own is a non-checked relocation. We side with ELF on being
comment|// explicit about this!
name|VK_NC
operator|=
literal|0x100
block|,
comment|// Convenience definitions for referring to specific textual representations
comment|// of relocation specifiers. Note that this means the "_NC" is sometimes
comment|// omitted in line with assembly syntax here (VK_LO12 rather than VK_LO12_NC
comment|// since a user would write ":lo12:").
name|VK_CALL
operator|=
name|VK_ABS
block|,
name|VK_ABS_PAGE
operator|=
name|VK_ABS
operator||
name|VK_PAGE
block|,
name|VK_ABS_PAGE_NC
operator|=
name|VK_ABS
operator||
name|VK_PAGE
operator||
name|VK_NC
block|,
name|VK_ABS_G3
operator|=
name|VK_ABS
operator||
name|VK_G3
block|,
name|VK_ABS_G2
operator|=
name|VK_ABS
operator||
name|VK_G2
block|,
name|VK_ABS_G2_S
operator|=
name|VK_SABS
operator||
name|VK_G2
block|,
name|VK_ABS_G2_NC
operator|=
name|VK_ABS
operator||
name|VK_G2
operator||
name|VK_NC
block|,
name|VK_ABS_G1
operator|=
name|VK_ABS
operator||
name|VK_G1
block|,
name|VK_ABS_G1_S
operator|=
name|VK_SABS
operator||
name|VK_G1
block|,
name|VK_ABS_G1_NC
operator|=
name|VK_ABS
operator||
name|VK_G1
operator||
name|VK_NC
block|,
name|VK_ABS_G0
operator|=
name|VK_ABS
operator||
name|VK_G0
block|,
name|VK_ABS_G0_S
operator|=
name|VK_SABS
operator||
name|VK_G0
block|,
name|VK_ABS_G0_NC
operator|=
name|VK_ABS
operator||
name|VK_G0
operator||
name|VK_NC
block|,
name|VK_LO12
operator|=
name|VK_ABS
operator||
name|VK_PAGEOFF
operator||
name|VK_NC
block|,
name|VK_GOT_LO12
operator|=
name|VK_GOT
operator||
name|VK_PAGEOFF
operator||
name|VK_NC
block|,
name|VK_GOT_PAGE
operator|=
name|VK_GOT
operator||
name|VK_PAGE
block|,
name|VK_DTPREL_G2
operator|=
name|VK_DTPREL
operator||
name|VK_G2
block|,
name|VK_DTPREL_G1
operator|=
name|VK_DTPREL
operator||
name|VK_G1
block|,
name|VK_DTPREL_G1_NC
operator|=
name|VK_DTPREL
operator||
name|VK_G1
operator||
name|VK_NC
block|,
name|VK_DTPREL_G0
operator|=
name|VK_DTPREL
operator||
name|VK_G0
block|,
name|VK_DTPREL_G0_NC
operator|=
name|VK_DTPREL
operator||
name|VK_G0
operator||
name|VK_NC
block|,
name|VK_DTPREL_HI12
operator|=
name|VK_DTPREL
operator||
name|VK_HI12
block|,
name|VK_DTPREL_LO12
operator|=
name|VK_DTPREL
operator||
name|VK_PAGEOFF
block|,
name|VK_DTPREL_LO12_NC
operator|=
name|VK_DTPREL
operator||
name|VK_PAGEOFF
operator||
name|VK_NC
block|,
name|VK_GOTTPREL_PAGE
operator|=
name|VK_GOTTPREL
operator||
name|VK_PAGE
block|,
name|VK_GOTTPREL_LO12_NC
operator|=
name|VK_GOTTPREL
operator||
name|VK_PAGEOFF
operator||
name|VK_NC
block|,
name|VK_GOTTPREL_G1
operator|=
name|VK_GOTTPREL
operator||
name|VK_G1
block|,
name|VK_GOTTPREL_G0_NC
operator|=
name|VK_GOTTPREL
operator||
name|VK_G0
operator||
name|VK_NC
block|,
name|VK_TPREL_G2
operator|=
name|VK_TPREL
operator||
name|VK_G2
block|,
name|VK_TPREL_G1
operator|=
name|VK_TPREL
operator||
name|VK_G1
block|,
name|VK_TPREL_G1_NC
operator|=
name|VK_TPREL
operator||
name|VK_G1
operator||
name|VK_NC
block|,
name|VK_TPREL_G0
operator|=
name|VK_TPREL
operator||
name|VK_G0
block|,
name|VK_TPREL_G0_NC
operator|=
name|VK_TPREL
operator||
name|VK_G0
operator||
name|VK_NC
block|,
name|VK_TPREL_HI12
operator|=
name|VK_TPREL
operator||
name|VK_HI12
block|,
name|VK_TPREL_LO12
operator|=
name|VK_TPREL
operator||
name|VK_PAGEOFF
block|,
name|VK_TPREL_LO12_NC
operator|=
name|VK_TPREL
operator||
name|VK_PAGEOFF
operator||
name|VK_NC
block|,
name|VK_TLSDESC_LO12
operator|=
name|VK_TLSDESC
operator||
name|VK_PAGEOFF
block|,
name|VK_TLSDESC_PAGE
operator|=
name|VK_TLSDESC
operator||
name|VK_PAGE
block|,
name|VK_INVALID
operator|=
literal|0xfff
block|}
block|;
name|private
operator|:
specifier|const
name|MCExpr
operator|*
name|Expr
block|;
specifier|const
name|VariantKind
name|Kind
block|;
name|explicit
name|AArch64MCExpr
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|VariantKind Kind
argument_list|)
operator|:
name|Expr
argument_list|(
name|Expr
argument_list|)
block|,
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|create
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|VariantKind Kind
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
comment|/// Get the kind of this expression.
name|VariantKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// Get the expression this modifier applies to.
specifier|const
name|MCExpr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|Expr
return|;
block|}
comment|/// @}
comment|/// @name VariantKind information extractors.
comment|/// @{
specifier|static
name|VariantKind
name|getSymbolLoc
argument_list|(
argument|VariantKind Kind
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|VariantKind
operator|>
operator|(
name|Kind
operator|&
name|VK_SymLocBits
operator|)
return|;
block|}
specifier|static
name|VariantKind
name|getAddressFrag
argument_list|(
argument|VariantKind Kind
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|VariantKind
operator|>
operator|(
name|Kind
operator|&
name|VK_AddressFragBits
operator|)
return|;
block|}
specifier|static
name|bool
name|isNotChecked
argument_list|(
argument|VariantKind Kind
argument_list|)
block|{
return|return
name|Kind
operator|&
name|VK_NC
return|;
block|}
comment|/// @}
comment|/// Convert the variant kind into an ELF-appropriate modifier
comment|/// (e.g. ":got:", ":lo12:").
name|StringRef
name|getVariantKindName
argument_list|()
specifier|const
block|;
name|void
name|printImpl
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const MCAsmInfo *MAI
argument_list|)
specifier|const
name|override
block|;
name|void
name|visitUsedExpr
argument_list|(
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|;
name|MCFragment
operator|*
name|findAssociatedFragment
argument_list|()
specifier|const
name|override
block|;
name|bool
name|evaluateAsRelocatableImpl
argument_list|(
argument|MCValue&Res
argument_list|,
argument|const MCAsmLayout *Layout
argument_list|,
argument|const MCFixup *Fixup
argument_list|)
specifier|const
name|override
block|;
name|void
name|fixELFSymbolsInTLSFixups
argument_list|(
argument|MCAssembler&Asm
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCExpr *E
argument_list|)
block|{
return|return
name|E
operator|->
name|getKind
argument_list|()
operator|==
name|MCExpr
operator|::
name|Target
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AArch64MCExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

