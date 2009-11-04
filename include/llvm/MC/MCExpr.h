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
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCContext
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
comment|/// MCExpr - Base class for the full range of assembler expressions which are
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
comment|///< Unary expressions.
block|}
enum|;
name|private
label|:
name|ExprKind
name|Kind
decl_stmt|;
name|MCExpr
argument_list|(
specifier|const
name|MCExpr
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCExpr
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
name|MCExpr
argument_list|(
argument|ExprKind _Kind
argument_list|)
block|:
name|Kind
argument_list|(
argument|_Kind
argument_list|)
block|{}
name|public
label|:
comment|/// @name Accessors
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
comment|/// @}
comment|/// @name Utility Methods
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
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Expression Evaluation
comment|/// @{
comment|/// EvaluateAsAbsolute - Try to evaluate the expression to an absolute value.
comment|///
comment|/// @param Res - The absolute value, if evaluation succeeds.
comment|/// @result - True on success.
name|bool
name|EvaluateAsAbsolute
argument_list|(
name|int64_t
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
comment|/// EvaluateAsRelocatable - Try to evaluate the expression to a relocatable
comment|/// value, i.e. an expression of the fixed form (a - b + constant).
comment|///
comment|/// @param Res - The relocatable value, if evaluation succeeds.
comment|/// @result - True on success.
name|bool
name|EvaluateAsRelocatable
argument_list|(
name|MCValue
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MCExpr
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|//// MCConstantExpr - Represent a constant integer expression.
name|class
name|MCConstantExpr
range|:
name|public
name|MCExpr
block|{
name|int64_t
name|Value
block|;
name|MCConstantExpr
argument_list|(
argument|int64_t _Value
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|Constant
argument_list|)
block|,
name|Value
argument_list|(
argument|_Value
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|MCConstantExpr
operator|*
name|Create
argument_list|(
argument|int64_t Value
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// @}
comment|/// @name Accessors
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCConstantExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// MCSymbolRefExpr - Represent a reference to a symbol from inside an
comment|/// expression.
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
specifier|const
name|MCSymbol
operator|*
name|Symbol
block|;
name|MCSymbolRefExpr
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|_Symbol
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|SymbolRef
argument_list|)
block|,
name|Symbol
argument_list|(
argument|_Symbol
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|MCSymbolRefExpr
operator|*
name|Create
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Symbol
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|MCSymbolRefExpr
operator|*
name|Create
argument_list|(
specifier|const
name|StringRef
operator|&
name|Name
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
block|;
comment|/// @}
comment|/// @name Accessors
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCSymbolRefExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// MCUnaryExpr - Unary assembler expressions.
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
argument|Opcode _Op
argument_list|,
argument|const MCExpr *_Expr
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|Unary
argument_list|)
block|,
name|Op
argument_list|(
name|_Op
argument_list|)
block|,
name|Expr
argument_list|(
argument|_Expr
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|Create
argument_list|(
argument|Opcode Op
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|CreateLNot
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|LNot
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|CreateMinus
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|Minus
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|CreateNot
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|Not
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|MCUnaryExpr
operator|*
name|CreatePlus
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|Plus
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Accessors
comment|/// @{
comment|/// getOpcode - Get the kind of this unary expression.
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
comment|/// getSubExpr - Get the child of this unary expression.
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCUnaryExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// MCBinaryExpr - Binary assembler expressions.
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
comment|///< Division.
name|EQ
block|,
comment|///< Equality comparison.
name|GT
block|,
comment|///< Greater than comparison.
name|GTE
block|,
comment|///< Greater than or equal comparison.
name|LAnd
block|,
comment|///< Logical and.
name|LOr
block|,
comment|///< Logical or.
name|LT
block|,
comment|///< Less than comparison.
name|LTE
block|,
comment|///< Less than or equal comparison.
name|Mod
block|,
comment|///< Modulus.
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
comment|///< Bitwise shift left.
name|Shr
block|,
comment|///< Bitwise shift right.
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
argument|Opcode _Op
argument_list|,
argument|const MCExpr *_LHS
argument_list|,
argument|const MCExpr *_RHS
argument_list|)
operator|:
name|MCExpr
argument_list|(
name|MCExpr
operator|::
name|Binary
argument_list|)
block|,
name|Op
argument_list|(
name|_Op
argument_list|)
block|,
name|LHS
argument_list|(
name|_LHS
argument_list|)
block|,
name|RHS
argument_list|(
argument|_RHS
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|Create
argument_list|(
argument|Opcode Op
argument_list|,
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|MCBinaryExpr
operator|*
name|CreateAdd
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateAnd
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateDiv
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateEQ
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateGT
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateGTE
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateLAnd
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateLOr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateLT
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateLTE
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateMod
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateMul
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateNE
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateOr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateShl
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateShr
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|Shr
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
name|CreateSub
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
name|CreateXor
argument_list|(
argument|const MCExpr *LHS
argument_list|,
argument|const MCExpr *RHS
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
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
comment|/// @name Accessors
comment|/// @{
comment|/// getOpcode - Get the kind of this binary expression.
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
comment|/// getLHS - Get the left-hand side expression of the binary operator.
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
comment|/// getRHS - Get the right-hand side expression of the binary operator.
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCBinaryExpr *
argument_list|)
block|{
return|return
name|true
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

end_unit

