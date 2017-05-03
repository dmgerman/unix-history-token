begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCExpr.h - Assembly Level Expressions --------------------*- C++ -*-===//
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
name|LLVM_MC_MCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCAsmLayout
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|using
name|SectionAddrMap
init|=
name|DenseMap
operator|<
specifier|const
name|MCSection
operator|*
decl_stmt|,
name|uint64_t
decl|>
decl_stmt|;
comment|/// \brief Base class for the full range of assembler expressions which are
comment|/// needed for parsing.
name|class
name|MCExpr
block|{
name|public
label|:
enum|enum
name|ExprKind
block|{
name|Binary
block|,
comment|///< Binary expressions.
name|Constant
block|,
comment|///< Constant expressions.
name|SymbolRef
block|,
comment|///< References to labels and assigned expressions.
name|Unary
block|,
comment|///< Unary expressions.
name|Target
comment|///< Target specific expression.
block|}
enum|;
name|private
label|:
name|ExprKind
name|Kind
decl_stmt|;
name|SMLoc
name|Loc
decl_stmt|;
name|bool
name|evaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|,
specifier|const
name|MCAssembler
operator|*
name|Asm
argument_list|,
specifier|const
name|MCAsmLayout
operator|*
name|Layout
argument_list|,
specifier|const
name|SectionAddrMap
operator|*
name|Addrs
argument_list|)
decl|const
decl_stmt|;
name|bool
name|evaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|,
specifier|const
name|MCAssembler
operator|*
name|Asm
argument_list|,
specifier|const
name|MCAsmLayout
operator|*
name|Layout
argument_list|,
specifier|const
name|SectionAddrMap
operator|*
name|Addrs
argument_list|,
name|bool
name|InSet
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|explicit
name|MCExpr
argument_list|(
argument|ExprKind Kind
argument_list|,
argument|SMLoc Loc
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{}
name|bool
name|evaluateAsRelocatableImpl
argument_list|(
argument|MCValue&Res
argument_list|,
argument|const MCAssembler *Asm
argument_list|,
argument|const MCAsmLayout *Layout
argument_list|,
argument|const MCFixup *Fixup
argument_list|,
argument|const SectionAddrMap *Addrs
argument_list|,
argument|bool InSet
argument_list|)
specifier|const
expr_stmt|;
name|public
label|:
name|MCExpr
argument_list|(
specifier|const
name|MCExpr
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCExpr
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCExpr
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// \name Accessors
comment|/// @{
name|ExprKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
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
comment|/// @}
comment|/// \name Utility Methods
comment|/// @{
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|MAI
argument_list|,
name|bool
name|InParens
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// \name Expression Evaluation
comment|/// @{
comment|/// \brief Try to evaluate the expression to an absolute value.
comment|///
comment|/// \param Res - The absolute value, if evaluation succeeds.
comment|/// \param Layout - The assembler layout object to use for evaluating symbol
comment|/// values. If not given, then only non-symbolic expressions will be
comment|/// evaluated.
comment|/// \return - True on success.
name|bool
name|evaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|,
specifier|const
name|SectionAddrMap
operator|&
name|Addrs
argument_list|)
decl|const
decl_stmt|;
name|bool
name|evaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
name|bool
name|evaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|,
specifier|const
name|MCAssembler
operator|&
name|Asm
argument_list|)
decl|const
decl_stmt|;
name|bool
name|evaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
name|bool
name|evaluateKnownAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Try to evaluate the expression to a relocatable value, i.e. an
comment|/// expression of the fixed form (a - b + constant).
comment|///
comment|/// \param Res - The relocatable value, if evaluation succeeds.
comment|/// \param Layout - The assembler layout object to use for evaluating values.
comment|/// \param Fixup - The Fixup object if available.
comment|/// \return - True on success.
name|bool
name|evaluateAsRelocatable
argument_list|(
name|MCValue
operator|&
name|Res
argument_list|,
specifier|const
name|MCAsmLayout
operator|*
name|Layout
argument_list|,
specifier|const
name|MCFixup
operator|*
name|Fixup
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Try to evaluate the expression to the form (a - b + constant) where
comment|/// neither a nor b are variables.
comment|///
comment|/// This is a more aggressive variant of evaluateAsRelocatable. The intended
comment|/// use is for when relocations are not available, like the .size directive.
name|bool
name|evaluateAsValue
argument_list|(
name|MCValue
operator|&
name|Res
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Find the "associated section" for this expression, which is
comment|/// currently defined as the absolute section for constants, or
comment|/// otherwise the section associated with the first defined symbol in the
comment|/// expression.
name|MCFragment
operator|*
name|findAssociatedFragment
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
block|}
empty_stmt|;
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
name|MCExpr
operator|&
name|E
operator|)
block|{
name|E
operator|.
name|print
argument_list|(
name|OS
argument_list|,
name|nullptr
argument_list|)
block|;
return|return
name|OS
return|;
block|}
comment|//// \brief  Represent a constant integer expression.
name|class
name|MCConstantExpr
range|:
name|public
name|MCExpr
block|{
name|int64_t
name|Value
block|;
name|explicit
name|MCConstantExpr
argument_list|(
argument|int64_t Value
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|Constant
argument_list|,
name|SMLoc
argument_list|()
argument_list|)
block|,
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|public
operator|:
comment|/// \name Construction
comment|/// @{
specifier|static
specifier|const
name|MCConstantExpr
operator|*
name|create
argument_list|(
argument|int64_t Value
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// @}
comment|/// \name Accessors
comment|/// @{
name|int64_t
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
comment|/// @}
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
name|Constant
return|;
block|}
expr|}
block|;
comment|/// \brief  Represent a reference to a symbol from inside an expression.
comment|///
comment|/// A symbol reference in an expression may be a use of a label, a use of an
comment|/// assembler variable (defined constant), or constitute an implicit definition
comment|/// of the symbol as external.
name|class
name|MCSymbolRefExpr
operator|:
name|public
name|MCExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
operator|:
name|uint16_t
block|{
name|VK_None
block|,
name|VK_Invalid
block|,
name|VK_GOT
block|,
name|VK_GOTOFF
block|,
name|VK_GOTREL
block|,
name|VK_GOTPCREL
block|,
name|VK_GOTTPOFF
block|,
name|VK_INDNTPOFF
block|,
name|VK_NTPOFF
block|,
name|VK_GOTNTPOFF
block|,
name|VK_PLT
block|,
name|VK_TLSGD
block|,
name|VK_TLSLD
block|,
name|VK_TLSLDM
block|,
name|VK_TPOFF
block|,
name|VK_DTPOFF
block|,
name|VK_TLSCALL
block|,
comment|// symbol(tlscall)
name|VK_TLSDESC
block|,
comment|// symbol(tlsdesc)
name|VK_TLVP
block|,
comment|// Mach-O thread local variable relocations
name|VK_TLVPPAGE
block|,
name|VK_TLVPPAGEOFF
block|,
name|VK_PAGE
block|,
name|VK_PAGEOFF
block|,
name|VK_GOTPAGE
block|,
name|VK_GOTPAGEOFF
block|,
name|VK_SECREL
block|,
name|VK_SIZE
block|,
comment|// symbol@SIZE
name|VK_WEAKREF
block|,
comment|// The link between the symbols in .weakref foo, bar
name|VK_X86_ABS8
block|,
name|VK_ARM_NONE
block|,
name|VK_ARM_GOT_PREL
block|,
name|VK_ARM_TARGET1
block|,
name|VK_ARM_TARGET2
block|,
name|VK_ARM_PREL31
block|,
name|VK_ARM_SBREL
block|,
comment|// symbol(sbrel)
name|VK_ARM_TLSLDO
block|,
comment|// symbol(tlsldo)
name|VK_ARM_TLSDESCSEQ
block|,
name|VK_PPC_LO
block|,
comment|// symbol@l
name|VK_PPC_HI
block|,
comment|// symbol@h
name|VK_PPC_HA
block|,
comment|// symbol@ha
name|VK_PPC_HIGHER
block|,
comment|// symbol@higher
name|VK_PPC_HIGHERA
block|,
comment|// symbol@highera
name|VK_PPC_HIGHEST
block|,
comment|// symbol@highest
name|VK_PPC_HIGHESTA
block|,
comment|// symbol@highesta
name|VK_PPC_GOT_LO
block|,
comment|// symbol@got@l
name|VK_PPC_GOT_HI
block|,
comment|// symbol@got@h
name|VK_PPC_GOT_HA
block|,
comment|// symbol@got@ha
name|VK_PPC_TOCBASE
block|,
comment|// symbol@tocbase
name|VK_PPC_TOC
block|,
comment|// symbol@toc
name|VK_PPC_TOC_LO
block|,
comment|// symbol@toc@l
name|VK_PPC_TOC_HI
block|,
comment|// symbol@toc@h
name|VK_PPC_TOC_HA
block|,
comment|// symbol@toc@ha
name|VK_PPC_DTPMOD
block|,
comment|// symbol@dtpmod
name|VK_PPC_TPREL_LO
block|,
comment|// symbol@tprel@l
name|VK_PPC_TPREL_HI
block|,
comment|// symbol@tprel@h
name|VK_PPC_TPREL_HA
block|,
comment|// symbol@tprel@ha
name|VK_PPC_TPREL_HIGHER
block|,
comment|// symbol@tprel@higher
name|VK_PPC_TPREL_HIGHERA
block|,
comment|// symbol@tprel@highera
name|VK_PPC_TPREL_HIGHEST
block|,
comment|// symbol@tprel@highest
name|VK_PPC_TPREL_HIGHESTA
block|,
comment|// symbol@tprel@highesta
name|VK_PPC_DTPREL_LO
block|,
comment|// symbol@dtprel@l
name|VK_PPC_DTPREL_HI
block|,
comment|// symbol@dtprel@h
name|VK_PPC_DTPREL_HA
block|,
comment|// symbol@dtprel@ha
name|VK_PPC_DTPREL_HIGHER
block|,
comment|// symbol@dtprel@higher
name|VK_PPC_DTPREL_HIGHERA
block|,
comment|// symbol@dtprel@highera
name|VK_PPC_DTPREL_HIGHEST
block|,
comment|// symbol@dtprel@highest
name|VK_PPC_DTPREL_HIGHESTA
block|,
comment|// symbol@dtprel@highesta
name|VK_PPC_GOT_TPREL
block|,
comment|// symbol@got@tprel
name|VK_PPC_GOT_TPREL_LO
block|,
comment|// symbol@got@tprel@l
name|VK_PPC_GOT_TPREL_HI
block|,
comment|// symbol@got@tprel@h
name|VK_PPC_GOT_TPREL_HA
block|,
comment|// symbol@got@tprel@ha
name|VK_PPC_GOT_DTPREL
block|,
comment|// symbol@got@dtprel
name|VK_PPC_GOT_DTPREL_LO
block|,
comment|// symbol@got@dtprel@l
name|VK_PPC_GOT_DTPREL_HI
block|,
comment|// symbol@got@dtprel@h
name|VK_PPC_GOT_DTPREL_HA
block|,
comment|// symbol@got@dtprel@ha
name|VK_PPC_TLS
block|,
comment|// symbol@tls
name|VK_PPC_GOT_TLSGD
block|,
comment|// symbol@got@tlsgd
name|VK_PPC_GOT_TLSGD_LO
block|,
comment|// symbol@got@tlsgd@l
name|VK_PPC_GOT_TLSGD_HI
block|,
comment|// symbol@got@tlsgd@h
name|VK_PPC_GOT_TLSGD_HA
block|,
comment|// symbol@got@tlsgd@ha
name|VK_PPC_TLSGD
block|,
comment|// symbol@tlsgd
name|VK_PPC_GOT_TLSLD
block|,
comment|// symbol@got@tlsld
name|VK_PPC_GOT_TLSLD_LO
block|,
comment|// symbol@got@tlsld@l
name|VK_PPC_GOT_TLSLD_HI
block|,
comment|// symbol@got@tlsld@h
name|VK_PPC_GOT_TLSLD_HA
block|,
comment|// symbol@got@tlsld@ha
name|VK_PPC_TLSLD
block|,
comment|// symbol@tlsld
name|VK_PPC_LOCAL
block|,
comment|// symbol@local
name|VK_COFF_IMGREL32
block|,
comment|// symbol@imgrel (image-relative)
name|VK_Hexagon_PCREL
block|,
name|VK_Hexagon_LO16
block|,
name|VK_Hexagon_HI16
block|,
name|VK_Hexagon_GPREL
block|,
name|VK_Hexagon_GD_GOT
block|,
name|VK_Hexagon_LD_GOT
block|,
name|VK_Hexagon_GD_PLT
block|,
name|VK_Hexagon_LD_PLT
block|,
name|VK_Hexagon_IE
block|,
name|VK_Hexagon_IE_GOT
block|,
name|VK_WebAssembly_FUNCTION
block|,
comment|// Function table index, rather than virtual addr
name|VK_WebAssembly_TYPEINDEX
block|,
comment|// Type table index
name|VK_AMDGPU_GOTPCREL32_LO
block|,
comment|// symbol@gotpcrel32@lo
name|VK_AMDGPU_GOTPCREL32_HI
block|,
comment|// symbol@gotpcrel32@hi
name|VK_AMDGPU_REL32_LO
block|,
comment|// symbol@rel32@lo
name|VK_AMDGPU_REL32_HI
block|,
comment|// symbol@rel32@hi
name|VK_TPREL
block|,
name|VK_DTPREL
block|}
block|;
name|private
operator|:
comment|/// The symbol reference modifier.
specifier|const
name|VariantKind
name|Kind
block|;
comment|/// Specifies how the variant kind should be printed.
specifier|const
name|unsigned
name|UseParensForSymbolVariant
operator|:
literal|1
block|;
comment|// FIXME: Remove this bit.
specifier|const
name|unsigned
name|HasSubsectionsViaSymbols
operator|:
literal|1
block|;
comment|/// The symbol being referenced.
specifier|const
name|MCSymbol
operator|*
name|Symbol
block|;
name|explicit
name|MCSymbolRefExpr
argument_list|(
argument|const MCSymbol *Symbol
argument_list|,
argument|VariantKind Kind
argument_list|,
argument|const MCAsmInfo *MAI
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|;
name|public
operator|:
comment|/// \name Construction
comment|/// @{
specifier|static
specifier|const
name|MCSymbolRefExpr
operator|*
name|create
argument_list|(
argument|const MCSymbol *Symbol
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|MCSymbolRefExpr
operator|::
name|create
argument_list|(
name|Symbol
argument_list|,
name|VK_None
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCSymbolRefExpr
operator|*
name|create
argument_list|(
argument|const MCSymbol *Symbol
argument_list|,
argument|VariantKind Kind
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|;
specifier|static
specifier|const
name|MCSymbolRefExpr
operator|*
name|create
argument_list|(
argument|StringRef Name
argument_list|,
argument|VariantKind Kind
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// @}
comment|/// \name Accessors
comment|/// @{
specifier|const
name|MCSymbol
operator|&
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Symbol
return|;
block|}
name|VariantKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|void
name|printVariantKind
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|bool
name|hasSubsectionsViaSymbols
argument_list|()
specifier|const
block|{
return|return
name|HasSubsectionsViaSymbols
return|;
block|}
comment|/// @}
comment|/// \name Static Utility Functions
comment|/// @{
specifier|static
name|StringRef
name|getVariantKindName
argument_list|(
argument|VariantKind Kind
argument_list|)
block|;
specifier|static
name|VariantKind
name|getVariantKindForName
argument_list|(
argument|StringRef Name
argument_list|)
block|;
comment|/// @}
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
name|SymbolRef
return|;
block|}
expr|}
block|;
comment|/// \brief Unary assembler expressions.
name|class
name|MCUnaryExpr
operator|:
name|public
name|MCExpr
block|{
name|public
operator|:
expr|enum
name|Opcode
block|{
name|LNot
block|,
comment|///< Logical negation.
name|Minus
block|,
comment|///< Unary minus.
name|Not
block|,
comment|///< Bitwise negation.
name|Plus
comment|///< Unary plus.
block|}
block|;
name|private
operator|:
name|Opcode
name|Op
block|;
specifier|const
name|MCExpr
operator|*
name|Expr
block|;
name|MCUnaryExpr
argument_list|(
argument|Opcode Op
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|SMLoc Loc
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|Unary
argument_list|,
name|Loc
argument_list|)
block|,
name|Op
argument_list|(
name|Op
argument_list|)
block|,
name|Expr
argument_list|(
argument|Expr
argument_list|)
block|{}
name|public
operator|:
comment|/// \name Construction
comment|/// @{
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|create
argument_list|(
argument|Opcode Op
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|;
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|createLNot
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|{
return|return
name|create
argument_list|(
name|LNot
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|,
name|Loc
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|createMinus
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Minus
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|,
name|Loc
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|createNot
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Not
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|,
name|Loc
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|createPlus
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Plus
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|,
name|Loc
argument_list|)
return|;
block|}
comment|/// @}
comment|/// \name Accessors
comment|/// @{
comment|/// \brief Get the kind of this unary expression.
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
comment|/// \brief Get the child of this unary expression.
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
name|Unary
return|;
block|}
expr|}
block|;
comment|/// \brief Binary assembler expressions.
name|class
name|MCBinaryExpr
operator|:
name|public
name|MCExpr
block|{
name|public
operator|:
expr|enum
name|Opcode
block|{
name|Add
block|,
comment|///< Addition.
name|And
block|,
comment|///< Bitwise and.
name|Div
block|,
comment|///< Signed division.
name|EQ
block|,
comment|///< Equality comparison.
name|GT
block|,
comment|///< Signed greater than comparison (result is either 0 or some
comment|///< target-specific non-zero value)
name|GTE
block|,
comment|///< Signed greater than or equal comparison (result is either 0 or
comment|///< some target-specific non-zero value).
name|LAnd
block|,
comment|///< Logical and.
name|LOr
block|,
comment|///< Logical or.
name|LT
block|,
comment|///< Signed less than comparison (result is either 0 or
comment|///< some target-specific non-zero value).
name|LTE
block|,
comment|///< Signed less than or equal comparison (result is either 0 or
comment|///< some target-specific non-zero value).
name|Mod
block|,
comment|///< Signed remainder.
name|Mul
block|,
comment|///< Multiplication.
name|NE
block|,
comment|///< Inequality comparison.
name|Or
block|,
comment|///< Bitwise or.
name|Shl
block|,
comment|///< Shift left.
name|AShr
block|,
comment|///< Arithmetic shift right.
name|LShr
block|,
comment|///< Logical shift right.
name|Sub
block|,
comment|///< Subtraction.
name|Xor
comment|///< Bitwise exclusive or.
block|}
block|;
name|private
operator|:
name|Opcode
name|Op
block|;
specifier|const
name|MCExpr
operator|*
name|LHS
block|,
operator|*
name|RHS
block|;
name|MCBinaryExpr
argument_list|(
argument|Opcode Op
argument_list|,
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|Binary
argument_list|,
name|Loc
argument_list|)
block|,
name|Op
argument_list|(
name|Op
argument_list|)
block|,
name|LHS
argument_list|(
name|LHS
argument_list|)
block|,
name|RHS
argument_list|(
argument|RHS
argument_list|)
block|{}
name|public
operator|:
comment|/// \name Construction
comment|/// @{
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|create
argument_list|(
argument|Opcode Op
argument_list|,
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
block|;
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createAdd
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Add
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createAnd
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|And
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createDiv
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Div
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createEQ
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|EQ
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createGT
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|GT
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createGTE
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|GTE
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createLAnd
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|LAnd
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createLOr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|LOr
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createLT
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|LT
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createLTE
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|LTE
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createMod
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Mod
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createMul
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Mul
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createNE
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|NE
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createOr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Or
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createShl
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Shl
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createAShr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|AShr
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createLShr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|LShr
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createSub
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Sub
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|createXor
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|Xor
argument_list|,
name|LHS
argument_list|,
name|RHS
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
comment|/// @}
comment|/// \name Accessors
comment|/// @{
comment|/// \brief Get the kind of this binary expression.
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
comment|/// \brief Get the left-hand side expression of the binary operator.
specifier|const
name|MCExpr
operator|*
name|getLHS
argument_list|()
specifier|const
block|{
return|return
name|LHS
return|;
block|}
comment|/// \brief Get the right-hand side expression of the binary operator.
specifier|const
name|MCExpr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|RHS
return|;
block|}
comment|/// @}
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
name|Binary
return|;
block|}
expr|}
block|;
comment|/// \brief This is an extension point for target-specific MCExpr subclasses to
comment|/// implement.
comment|///
comment|/// NOTE: All subclasses are required to have trivial destructors because
comment|/// MCExprs are bump pointer allocated and not destructed.
name|class
name|MCTargetExpr
operator|:
name|public
name|MCExpr
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|MCTargetExpr
argument_list|()
operator|:
name|MCExpr
argument_list|(
argument|Target
argument_list|,
argument|SMLoc()
argument_list|)
block|{}
name|virtual
operator|~
name|MCTargetExpr
argument_list|()
operator|=
expr|default
block|;
name|public
operator|:
name|virtual
name|void
name|printImpl
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const MCAsmInfo *MAI
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|void
name|visitUsedExpr
argument_list|(
argument|MCStreamer& Streamer
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|MCFragment
operator|*
name|findAssociatedFragment
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|fixELFSymbolsInTLSFixups
argument_list|(
argument|MCAssembler&
argument_list|)
specifier|const
operator|=
literal|0
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
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCEXPR_H
end_comment

end_unit

