begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SemaFixItUtils.h - Sema FixIts -----------------------------------===//
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
comment|//  This file defines helper classes for generation of Sema FixItHints.
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
name|LLVM_CLANG_SEMA_SEMAFIXITUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SEMAFIXITUTILS_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
enum|enum
name|OverloadFixItKind
block|{
name|OFIK_Undefined
init|=
literal|0
block|,
name|OFIK_Dereference
block|,
name|OFIK_TakeAddress
block|,
name|OFIK_RemoveDereference
block|,
name|OFIK_RemoveTakeAddress
block|}
enum|;
name|class
name|Sema
decl_stmt|;
comment|/// The class facilities generation and storage of conversion FixIts. Hints for
comment|/// new conversions are added using TryToFixConversion method. The default type
comment|/// conversion checker can be reset.
struct|struct
name|ConversionFixItGenerator
block|{
comment|/// Performs a simple check to see if From type can be converted to To type.
specifier|static
name|bool
name|compareTypesSimple
parameter_list|(
name|CanQualType
name|From
parameter_list|,
name|CanQualType
name|To
parameter_list|,
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ExprValueKind
name|FromVK
parameter_list|)
function_decl|;
comment|/// The list of Hints generated so far.
name|std
operator|::
name|vector
operator|<
name|FixItHint
operator|>
name|Hints
expr_stmt|;
comment|/// The number of Conversions fixed. This can be different from the size
comment|/// of the Hints vector since we allow multiple FixIts per conversion.
name|unsigned
name|NumConversionsFixed
decl_stmt|;
comment|/// The type of fix applied. If multiple conversions are fixed, corresponds
comment|/// to the kid of the very first conversion.
name|OverloadFixItKind
name|Kind
decl_stmt|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|TypeComparisonFuncTy
function_decl|)
parameter_list|(
specifier|const
name|CanQualType
name|FromTy
parameter_list|,
specifier|const
name|CanQualType
name|ToTy
parameter_list|,
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ExprValueKind
name|FromVK
parameter_list|)
function_decl|;
comment|/// The type comparison function used to decide if expression FromExpr of
comment|/// type FromTy can be converted to ToTy. For example, one could check if
comment|/// an implicit conversion exists. Returns true if comparison exists.
name|TypeComparisonFuncTy
name|CompareTypes
decl_stmt|;
name|ConversionFixItGenerator
argument_list|(
argument|TypeComparisonFuncTy Foo
argument_list|)
block|:
name|NumConversionsFixed
argument_list|(
literal|0
argument_list|)
operator|,
name|Kind
argument_list|(
name|OFIK_Undefined
argument_list|)
operator|,
name|CompareTypes
argument_list|(
argument|Foo
argument_list|)
block|{}
name|ConversionFixItGenerator
argument_list|()
operator|:
name|NumConversionsFixed
argument_list|(
literal|0
argument_list|)
operator|,
name|Kind
argument_list|(
name|OFIK_Undefined
argument_list|)
operator|,
name|CompareTypes
argument_list|(
argument|compareTypesSimple
argument_list|)
block|{}
comment|/// Resets the default conversion checker method.
name|void
name|setConversionChecker
argument_list|(
argument|TypeComparisonFuncTy Foo
argument_list|)
block|{
name|CompareTypes
operator|=
name|Foo
block|;   }
comment|/// If possible, generates and stores a fix for the given conversion.
name|bool
name|tryToFixConversion
argument_list|(
argument|const Expr *FromExpr
argument_list|,
argument|const QualType FromQTy
argument_list|,
argument|const QualType ToQTy
argument_list|,
argument|Sema&S
argument_list|)
expr_stmt|;
name|void
name|clear
parameter_list|()
block|{
name|Hints
operator|.
name|clear
argument_list|()
expr_stmt|;
name|NumConversionsFixed
operator|=
literal|0
expr_stmt|;
block|}
name|bool
name|isNull
parameter_list|()
block|{
return|return
operator|(
name|NumConversionsFixed
operator|==
literal|0
operator|)
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// endof namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

