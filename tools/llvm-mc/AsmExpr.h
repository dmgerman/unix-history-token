begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmExpr.h - Assembly file expressions --------------------*- C++ -*-===//
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
name|ASMEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|ASMEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
comment|/// AsmExpr - Base class for the full range of assembler expressions which are
comment|/// needed for parsing.
name|class
name|AsmExpr
block|{
name|public
label|:
enum|enum
name|AsmExprKind
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
name|AsmExprKind
name|Kind
decl_stmt|;
name|protected
label|:
name|AsmExpr
argument_list|(
argument|AsmExprKind _Kind
argument_list|)
block|:
name|Kind
argument_list|(
argument|_Kind
argument_list|)
block|{}
name|public
label|:
name|virtual
operator|~
name|AsmExpr
argument_list|()
expr_stmt|;
name|AsmExprKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// EvaluateAsAbsolute - Try to evaluate the expression to an absolute value.
comment|///
comment|/// @param Res - The absolute value, if evaluation succeeds.
comment|/// @result - True on success.
name|bool
name|EvaluateAsAbsolute
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
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
name|MCContext
operator|&
name|Ctx
argument_list|,
name|MCValue
operator|&
name|Res
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|AsmExpr
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|//// AsmConstantExpr - Represent a constant integer expression.
name|class
name|AsmConstantExpr
range|:
name|public
name|AsmExpr
block|{
name|int64_t
name|Value
block|;
name|public
operator|:
name|AsmConstantExpr
argument_list|(
argument|int64_t _Value
argument_list|)
operator|:
name|AsmExpr
argument_list|(
name|AsmExpr
operator|::
name|Constant
argument_list|)
block|,
name|Value
argument_list|(
argument|_Value
argument_list|)
block|{}
name|int64_t
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmExpr *E
argument_list|)
block|{
return|return
name|E
operator|->
name|getKind
argument_list|()
operator|==
name|AsmExpr
operator|::
name|Constant
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmConstantExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// AsmSymbolRefExpr - Represent a reference to a symbol from inside an
comment|/// expression.
comment|///
comment|/// A symbol reference in an expression may be a use of a label, a use of an
comment|/// assembler variable (defined constant), or constitute an implicit definition
comment|/// of the symbol as external.
name|class
name|AsmSymbolRefExpr
operator|:
name|public
name|AsmExpr
block|{
name|MCSymbol
operator|*
name|Symbol
block|;
name|public
operator|:
name|AsmSymbolRefExpr
argument_list|(
name|MCSymbol
operator|*
name|_Symbol
argument_list|)
operator|:
name|AsmExpr
argument_list|(
name|AsmExpr
operator|::
name|SymbolRef
argument_list|)
block|,
name|Symbol
argument_list|(
argument|_Symbol
argument_list|)
block|{}
name|MCSymbol
operator|*
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
name|Symbol
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmExpr *E
argument_list|)
block|{
return|return
name|E
operator|->
name|getKind
argument_list|()
operator|==
name|AsmExpr
operator|::
name|SymbolRef
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmSymbolRefExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// AsmUnaryExpr - Unary assembler expressions.
name|class
name|AsmUnaryExpr
operator|:
name|public
name|AsmExpr
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
name|AsmExpr
operator|*
name|Expr
block|;
name|public
operator|:
name|AsmUnaryExpr
argument_list|(
argument|Opcode _Op
argument_list|,
argument|AsmExpr *_Expr
argument_list|)
operator|:
name|AsmExpr
argument_list|(
name|AsmExpr
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
operator|~
name|AsmUnaryExpr
argument_list|()
block|{
name|delete
name|Expr
block|;   }
name|Opcode
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
name|AsmExpr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|Expr
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmExpr *E
argument_list|)
block|{
return|return
name|E
operator|->
name|getKind
argument_list|()
operator|==
name|AsmExpr
operator|::
name|Unary
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmUnaryExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// AsmBinaryExpr - Binary assembler expressions.
name|class
name|AsmBinaryExpr
operator|:
name|public
name|AsmExpr
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
name|AsmExpr
operator|*
name|LHS
block|,
operator|*
name|RHS
block|;
name|public
operator|:
name|AsmBinaryExpr
argument_list|(
argument|Opcode _Op
argument_list|,
argument|AsmExpr *_LHS
argument_list|,
argument|AsmExpr *_RHS
argument_list|)
operator|:
name|AsmExpr
argument_list|(
name|AsmExpr
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
operator|~
name|AsmBinaryExpr
argument_list|()
block|{
name|delete
name|LHS
block|;
name|delete
name|RHS
block|;   }
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
name|AsmExpr
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
name|AsmExpr
operator|*
name|getRHS
argument_list|()
specifier|const
block|{
return|return
name|RHS
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmExpr *E
argument_list|)
block|{
return|return
name|E
operator|->
name|getKind
argument_list|()
operator|==
name|AsmExpr
operator|::
name|Binary
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AsmBinaryExpr *
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

