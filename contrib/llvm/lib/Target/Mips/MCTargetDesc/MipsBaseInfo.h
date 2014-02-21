begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsBaseInfo.h - Top level definitions for MIPS MC ------*- C++ -*-===//
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
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the Mips target useful for the compiler back-end and the MC libraries.
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
name|MIPSBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSBASEINFO_H
end_define

begin_include
include|#
directive|include
file|"MipsFixupKinds.h"
end_include

begin_include
include|#
directive|include
file|"MipsMCTargetDesc.h"
end_include

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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MipsII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|MipsII
block|{
comment|/// Target Operand Flag enum.
enum|enum
name|TOF
block|{
comment|//===------------------------------------------------------------------===//
comment|// Mips Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|/// MO_GOT16 - Represents the offset into the global offset table at which
comment|/// the address the relocation entry symbol resides during execution.
name|MO_GOT16
block|,
name|MO_GOT
block|,
comment|/// MO_GOT_CALL - Represents the offset into the global offset table at
comment|/// which the address of a call site relocation entry symbol resides
comment|/// during execution. This is different from the above since this flag
comment|/// can only be present in call instructions.
name|MO_GOT_CALL
block|,
comment|/// MO_GPREL - Represents the offset from the current gp value to be used
comment|/// for the relocatable object file being produced.
name|MO_GPREL
block|,
comment|/// MO_ABS_HI/LO - Represents the hi or low part of an absolute symbol
comment|/// address.
name|MO_ABS_HI
block|,
name|MO_ABS_LO
block|,
comment|/// MO_TLSGD - Represents the offset into the global offset table at which
comment|// the module ID and TSL block offset reside during execution (General
comment|// Dynamic TLS).
name|MO_TLSGD
block|,
comment|/// MO_TLSLDM - Represents the offset into the global offset table at which
comment|// the module ID and TSL block offset reside during execution (Local
comment|// Dynamic TLS).
name|MO_TLSLDM
block|,
name|MO_DTPREL_HI
block|,
name|MO_DTPREL_LO
block|,
comment|/// MO_GOTTPREL - Represents the offset from the thread pointer (Initial
comment|// Exec TLS).
name|MO_GOTTPREL
block|,
comment|/// MO_TPREL_HI/LO - Represents the hi and low part of the offset from
comment|// the thread pointer (Local Exec TLS).
name|MO_TPREL_HI
block|,
name|MO_TPREL_LO
block|,
comment|// N32/64 Flags.
name|MO_GPOFF_HI
block|,
name|MO_GPOFF_LO
block|,
name|MO_GOT_DISP
block|,
name|MO_GOT_PAGE
block|,
name|MO_GOT_OFST
block|,
comment|/// MO_HIGHER/HIGHEST - Represents the highest or higher half word of a
comment|/// 64-bit symbol address.
name|MO_HIGHER
block|,
name|MO_HIGHEST
block|,
comment|/// MO_GOT_HI16/LO16, MO_CALL_HI16/LO16 - Relocations used for large GOTs.
name|MO_GOT_HI16
block|,
name|MO_GOT_LO16
block|,
name|MO_CALL_HI16
block|,
name|MO_CALL_LO16
block|}
enum|;
enum|enum
block|{
comment|//===------------------------------------------------------------------===//
comment|// Instruction encodings.  These are the standard/most common forms for
comment|// Mips instructions.
comment|//
comment|// Pseudo - This represents an instruction that is a pseudo instruction
comment|// or one that has not been implemented yet.  It is illegal to code generate
comment|// it, but tolerated for intermediate implementation stages.
name|Pseudo
init|=
literal|0
block|,
comment|/// FrmR - This form is for instructions of the format R.
name|FrmR
init|=
literal|1
block|,
comment|/// FrmI - This form is for instructions of the format I.
name|FrmI
init|=
literal|2
block|,
comment|/// FrmJ - This form is for instructions of the format J.
name|FrmJ
init|=
literal|3
block|,
comment|/// FrmFR - This form is for instructions of the format FR.
name|FrmFR
init|=
literal|4
block|,
comment|/// FrmFI - This form is for instructions of the format FI.
name|FrmFI
init|=
literal|5
block|,
comment|/// FrmOther - This form is for instructions that have no specific format.
name|FrmOther
init|=
literal|6
block|,
name|FormMask
init|=
literal|15
block|}
enum|;
block|}
specifier|inline
specifier|static
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSymbolRefExpr
operator|*
operator|,
name|int64_t
operator|>
name|MipsGetSymAndOffset
argument_list|(
argument|const MCFixup&Fixup
argument_list|)
block|{
name|MCFixupKind
name|FixupKind
operator|=
name|Fixup
operator|.
name|getKind
argument_list|()
block|;
if|if
condition|(
operator|(
name|FixupKind
operator|<
name|FirstTargetFixupKind
operator|)
operator|||
operator|(
name|FixupKind
operator|>=
name|MCFixupKind
argument_list|(
name|Mips
operator|::
name|LastTargetFixupKind
argument_list|)
operator|)
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|(
specifier|const
name|MCSymbolRefExpr
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|int64_t
operator|)
literal|0
argument_list|)
return|;
specifier|const
name|MCExpr
operator|*
name|Expr
operator|=
name|Fixup
operator|.
name|getValue
argument_list|()
expr_stmt|;
name|MCExpr
operator|::
name|ExprKind
name|Kind
operator|=
name|Expr
operator|->
name|getKind
argument_list|()
expr_stmt|;
if|if
condition|(
name|Kind
operator|==
name|MCExpr
operator|::
name|Binary
condition|)
block|{
specifier|const
name|MCBinaryExpr
modifier|*
name|BE
init|=
name|static_cast
operator|<
specifier|const
name|MCBinaryExpr
operator|*
operator|>
operator|(
name|Expr
operator|)
decl_stmt|;
specifier|const
name|MCExpr
modifier|*
name|LHS
init|=
name|BE
operator|->
name|getLHS
argument_list|()
decl_stmt|;
specifier|const
name|MCConstantExpr
modifier|*
name|CE
init|=
name|dyn_cast
operator|<
name|MCConstantExpr
operator|>
operator|(
name|BE
operator|->
name|getRHS
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
operator|(
name|LHS
operator|->
name|getKind
argument_list|()
operator|!=
name|MCExpr
operator|::
name|SymbolRef
operator|)
operator|||
operator|!
name|CE
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|(
specifier|const
name|MCSymbolRefExpr
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|int64_t
operator|)
literal|0
argument_list|)
return|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|cast
operator|<
name|MCSymbolRefExpr
operator|>
operator|(
name|LHS
operator|)
argument_list|,
name|CE
operator|->
name|getValue
argument_list|()
argument_list|)
return|;
block|}
if|if
condition|(
name|Kind
operator|!=
name|MCExpr
operator|::
name|SymbolRef
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
operator|(
specifier|const
name|MCSymbolRefExpr
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|int64_t
operator|)
literal|0
argument_list|)
return|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|cast
operator|<
name|MCSymbolRefExpr
operator|>
operator|(
name|Expr
operator|)
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

