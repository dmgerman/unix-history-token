begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExprObjC.h - Classes for representing ObjC expressions -*- C++ -*-===//
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
comment|//  This file defines the ExprObjC interface and subclasses.
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
name|LLVM_CLANG_AST_EXPROBJC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXPROBJC_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/SelectorLocationsKind.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
comment|/// ObjCStringLiteral, used for Objective-C string literals
comment|/// i.e. @"foo".
name|class
name|ObjCStringLiteral
range|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|String
block|;
name|SourceLocation
name|AtLoc
block|;
name|public
operator|:
name|ObjCStringLiteral
argument_list|(
argument|StringLiteral *SL
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCStringLiteralClass
argument_list|,
name|T
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|String
argument_list|(
name|SL
argument_list|)
block|,
name|AtLoc
argument_list|(
argument|L
argument_list|)
block|{}
name|explicit
name|ObjCStringLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCStringLiteralClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|StringLiteral
operator|*
name|getString
argument_list|()
block|{
return|return
name|cast
operator|<
name|StringLiteral
operator|>
operator|(
name|String
operator|)
return|;
block|}
specifier|const
name|StringLiteral
operator|*
name|getString
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|StringLiteral
operator|>
operator|(
name|String
operator|)
return|;
block|}
name|void
name|setString
argument_list|(
argument|StringLiteral *S
argument_list|)
block|{
name|String
operator|=
name|S
block|; }
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|String
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCStringLiteralClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|String
argument_list|,
operator|&
name|String
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ObjCBoolLiteralExpr - Objective-C Boolean Literal.
comment|///
name|class
name|ObjCBoolLiteralExpr
operator|:
name|public
name|Expr
block|{
name|bool
name|Value
block|;
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|ObjCBoolLiteralExpr
argument_list|(
argument|bool val
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCBoolLiteralExprClass
argument_list|,
name|Ty
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|Value
argument_list|(
name|val
argument_list|)
block|,
name|Loc
argument_list|(
argument|l
argument_list|)
block|{}
name|explicit
name|ObjCBoolLiteralExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCBoolLiteralExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|bool
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
name|void
name|setValue
argument_list|(
argument|bool V
argument_list|)
block|{
name|Value
operator|=
name|V
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCBoolLiteralExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// ObjCBoxedExpr - used for generalized expression boxing.
comment|/// as in: @(strdup("hello world")) or @(random())
comment|/// Also used for boxing non-parenthesized numeric literals;
comment|/// as in: @42 or \@true (c++/objc++) or \@__yes (c/objc).
name|class
name|ObjCBoxedExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|SubExpr
block|;
name|ObjCMethodDecl
operator|*
name|BoxingMethod
block|;
name|SourceRange
name|Range
block|;
name|public
operator|:
name|ObjCBoxedExpr
argument_list|(
argument|Expr *E
argument_list|,
argument|QualType T
argument_list|,
argument|ObjCMethodDecl *method
argument_list|,
argument|SourceRange R
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCBoxedExprClass
argument_list|,
name|T
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|E
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|E
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|E
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|E
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|SubExpr
argument_list|(
name|E
argument_list|)
block|,
name|BoxingMethod
argument_list|(
name|method
argument_list|)
block|,
name|Range
argument_list|(
argument|R
argument_list|)
block|{}
name|explicit
name|ObjCBoxedExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCBoxedExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|Expr
operator|*
name|getSubExpr
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExpr
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExpr
operator|)
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getBoxingMethod
argument_list|()
specifier|const
block|{
return|return
name|BoxingMethod
return|;
block|}
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCBoxedExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|SubExpr
argument_list|,
operator|&
name|SubExpr
operator|+
literal|1
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// ObjCArrayLiteral - used for objective-c array containers; as in:
comment|/// @[@"Hello", NSApp, [NSNumber numberWithInt:42]];
name|class
name|ObjCArrayLiteral
operator|:
name|public
name|Expr
block|{
name|unsigned
name|NumElements
block|;
name|SourceRange
name|Range
block|;
name|ObjCMethodDecl
operator|*
name|ArrayWithObjectsMethod
block|;
name|ObjCArrayLiteral
argument_list|(
argument|ArrayRef<Expr *> Elements
argument_list|,
argument|QualType T
argument_list|,
argument|ObjCMethodDecl * Method
argument_list|,
argument|SourceRange SR
argument_list|)
block|;
name|explicit
name|ObjCArrayLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned NumElements
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCArrayLiteralClass
argument_list|,
name|Empty
argument_list|)
block|,
name|NumElements
argument_list|(
argument|NumElements
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCArrayLiteral
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|ArrayRef<Expr *> Elements
argument_list|,
argument|QualType T
argument_list|,
argument|ObjCMethodDecl * Method
argument_list|,
argument|SourceRange SR
argument_list|)
block|;
specifier|static
name|ObjCArrayLiteral
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumElements
argument_list|)
block|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCArrayLiteralClass
return|;
block|}
comment|/// \brief Retrieve elements of array of literals.
name|Expr
operator|*
operator|*
name|getElements
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve elements of array of literals.
specifier|const
name|Expr
operator|*
specifier|const
operator|*
name|getElements
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
comment|/// getNumElements - Return number of elements of objective-c array literal.
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumElements
return|;
block|}
comment|/// getExpr - Return the Expr at the specified index.
name|Expr
operator|*
name|getElement
argument_list|(
argument|unsigned Index
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Index
operator|<
name|NumElements
operator|)
operator|&&
literal|"Arg access out of range!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getElements
argument_list|()
index|[
name|Index
index|]
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getElement
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Index
operator|<
name|NumElements
operator|)
operator|&&
literal|"Arg access out of range!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getElements
argument_list|()
index|[
name|Index
index|]
operator|)
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getArrayWithObjectsMethod
argument_list|()
specifier|const
block|{
return|return
name|ArrayWithObjectsMethod
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|(
name|Stmt
operator|*
operator|*
operator|)
name|getElements
argument_list|()
argument_list|,
operator|(
name|Stmt
operator|*
operator|*
operator|)
name|getElements
argument_list|()
operator|+
name|NumElements
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// \brief An element in an Objective-C dictionary literal.
comment|///
block|struct
name|ObjCDictionaryElement
block|{
comment|/// \brief The key for the dictionary element.
name|Expr
operator|*
name|Key
block|;
comment|/// \brief The value of the dictionary element.
name|Expr
operator|*
name|Value
block|;
comment|/// \brief The location of the ellipsis, if this is a pack expansion.
name|SourceLocation
name|EllipsisLoc
block|;
comment|/// \brief The number of elements this pack expansion will expand to, if
comment|/// this is a pack expansion and is known.
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
block|;
comment|/// \brief Determines whether this dictionary element is a pack expansion.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
expr|}
block|; }
comment|// end namespace clang
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|ObjCDictionaryElement
operator|>
operator|:
name|llvm
operator|::
name|true_type
block|{}
block|; }
name|namespace
name|clang
block|{
comment|/// ObjCDictionaryLiteral - AST node to represent objective-c dictionary
comment|/// literals; as in:  @{@"name" : NSUserName(), @"date" : [NSDate date] };
name|class
name|ObjCDictionaryLiteral
operator|:
name|public
name|Expr
block|{
comment|/// \brief Key/value pair used to store the key and value of a given element.
comment|///
comment|/// Objects of this type are stored directly after the expression.
block|struct
name|KeyValuePair
block|{
name|Expr
operator|*
name|Key
block|;
name|Expr
operator|*
name|Value
block|;   }
block|;
comment|/// \brief Data that describes an element that is a pack expansion, used if any
comment|/// of the elements in the dictionary literal are pack expansions.
block|struct
name|ExpansionData
block|{
comment|/// \brief The location of the ellipsis, if this element is a pack
comment|/// expansion.
name|SourceLocation
name|EllipsisLoc
block|;
comment|/// \brief If non-zero, the number of elements that this pack
comment|/// expansion will expand to (+1).
name|unsigned
name|NumExpansionsPlusOne
block|;   }
block|;
comment|/// \brief The number of elements in this dictionary literal.
name|unsigned
name|NumElements
operator|:
literal|31
block|;
comment|/// \brief Determine whether this dictionary literal has any pack expansions.
comment|///
comment|/// If the dictionary literal has pack expansions, then there will
comment|/// be an array of pack expansion data following the array of
comment|/// key/value pairs, which provide the locations of the ellipses (if
comment|/// any) and number of elements in the expansion (if known). If
comment|/// there are no pack expansions, we optimize away this storage.
name|unsigned
name|HasPackExpansions
operator|:
literal|1
block|;
name|SourceRange
name|Range
block|;
name|ObjCMethodDecl
operator|*
name|DictWithObjectsMethod
block|;
name|ObjCDictionaryLiteral
argument_list|(
argument|ArrayRef<ObjCDictionaryElement> VK
argument_list|,
argument|bool HasPackExpansions
argument_list|,
argument|QualType T
argument_list|,
argument|ObjCMethodDecl *method
argument_list|,
argument|SourceRange SR
argument_list|)
block|;
name|explicit
name|ObjCDictionaryLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned NumElements
argument_list|,
argument|bool HasPackExpansions
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCDictionaryLiteralClass
argument_list|,
name|Empty
argument_list|)
block|,
name|NumElements
argument_list|(
name|NumElements
argument_list|)
block|,
name|HasPackExpansions
argument_list|(
argument|HasPackExpansions
argument_list|)
block|{}
name|KeyValuePair
operator|*
name|getKeyValues
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|KeyValuePair
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
specifier|const
name|KeyValuePair
operator|*
name|getKeyValues
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|KeyValuePair
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|ExpansionData
operator|*
name|getExpansionData
argument_list|()
block|{
if|if
condition|(
operator|!
name|HasPackExpansions
condition|)
return|return
literal|0
return|;
return|return
name|reinterpret_cast
operator|<
name|ExpansionData
operator|*
operator|>
operator|(
name|getKeyValues
argument_list|()
operator|+
name|NumElements
operator|)
return|;
block|}
specifier|const
name|ExpansionData
operator|*
name|getExpansionData
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasPackExpansions
condition|)
return|return
literal|0
return|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ExpansionData
operator|*
operator|>
operator|(
name|getKeyValues
argument_list|()
operator|+
name|NumElements
operator|)
return|;
block|}
name|public
operator|:
specifier|static
name|ObjCDictionaryLiteral
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|ArrayRef<ObjCDictionaryElement> VK
argument_list|,
argument|bool HasPackExpansions
argument_list|,
argument|QualType T
argument_list|,
argument|ObjCMethodDecl *method
argument_list|,
argument|SourceRange SR
argument_list|)
block|;
specifier|static
name|ObjCDictionaryLiteral
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumElements
argument_list|,
argument|bool HasPackExpansions
argument_list|)
block|;
comment|/// getNumElements - Return number of elements of objective-c dictionary
comment|/// literal.
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumElements
return|;
block|}
name|ObjCDictionaryElement
name|getKeyValueElement
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Index
operator|<
name|NumElements
operator|)
operator|&&
literal|"Arg access out of range!"
argument_list|)
block|;
specifier|const
name|KeyValuePair
operator|&
name|KV
operator|=
name|getKeyValues
argument_list|()
index|[
name|Index
index|]
block|;
name|ObjCDictionaryElement
name|Result
operator|=
block|{
name|KV
operator|.
name|Key
block|,
name|KV
operator|.
name|Value
block|,
name|SourceLocation
argument_list|()
block|,
name|None
block|}
block|;
if|if
condition|(
name|HasPackExpansions
condition|)
block|{
specifier|const
name|ExpansionData
modifier|&
name|Expansion
init|=
name|getExpansionData
argument_list|()
index|[
name|Index
index|]
decl_stmt|;
name|Result
operator|.
name|EllipsisLoc
operator|=
name|Expansion
operator|.
name|EllipsisLoc
expr_stmt|;
if|if
condition|(
name|Expansion
operator|.
name|NumExpansionsPlusOne
operator|>
literal|0
condition|)
name|Result
operator|.
name|NumExpansions
operator|=
name|Expansion
operator|.
name|NumExpansionsPlusOne
operator|-
literal|1
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getDictWithObjectsMethod
argument_list|()
specifier|const
block|{
return|return
name|DictWithObjectsMethod
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCDictionaryLiteralClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
comment|// Note: we're taking advantage of the layout of the KeyValuePair struct
comment|// here. If that struct changes, this code will need to change as well.
return|return
name|child_range
argument_list|(
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|+
name|NumElements
operator|*
literal|2
argument_list|)
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// ObjCEncodeExpr, used for \@encode in Objective-C.  \@encode has the same
comment|/// type and behavior as StringLiteral except that the string initializer is
comment|/// obtained from ASTContext with the encoding type as an argument.
name|class
name|ObjCEncodeExpr
operator|:
name|public
name|Expr
block|{
name|TypeSourceInfo
operator|*
name|EncodedType
block|;
name|SourceLocation
name|AtLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ObjCEncodeExpr
argument_list|(
argument|QualType T
argument_list|,
argument|TypeSourceInfo *EncodedType
argument_list|,
argument|SourceLocation at
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCEncodeExprClass
argument_list|,
name|T
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|EncodedType
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|EncodedType
operator|->
name|getType
argument_list|()
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|EncodedType
operator|->
name|getType
argument_list|()
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|EncodedType
operator|->
name|getType
argument_list|()
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|EncodedType
argument_list|(
name|EncodedType
argument_list|)
block|,
name|AtLoc
argument_list|(
name|at
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{}
name|explicit
name|ObjCEncodeExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCEncodeExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|QualType
name|getEncodedType
argument_list|()
specifier|const
block|{
return|return
name|EncodedType
operator|->
name|getType
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getEncodedTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|EncodedType
return|;
block|}
name|void
name|setEncodedTypeSourceInfo
argument_list|(
argument|TypeSourceInfo *EncType
argument_list|)
block|{
name|EncodedType
operator|=
name|EncType
block|;    }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCEncodeExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// ObjCSelectorExpr used for \@selector in Objective-C.
name|class
name|ObjCSelectorExpr
operator|:
name|public
name|Expr
block|{
name|Selector
name|SelName
block|;
name|SourceLocation
name|AtLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ObjCSelectorExpr
argument_list|(
argument|QualType T
argument_list|,
argument|Selector selInfo
argument_list|,
argument|SourceLocation at
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCSelectorExprClass
argument_list|,
name|T
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|SelName
argument_list|(
name|selInfo
argument_list|)
block|,
name|AtLoc
argument_list|(
name|at
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{}
name|explicit
name|ObjCSelectorExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCSelectorExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|Selector
name|getSelector
argument_list|()
specifier|const
block|{
return|return
name|SelName
return|;
block|}
name|void
name|setSelector
argument_list|(
argument|Selector S
argument_list|)
block|{
name|SelName
operator|=
name|S
block|; }
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
return|;
block|}
comment|/// getNumArgs - Return the number of actual arguments to this call.
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|SelName
operator|.
name|getNumArgs
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCSelectorExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// ObjCProtocolExpr used for protocol expression in Objective-C.
comment|///
comment|/// This is used as: \@protocol(foo), as in:
comment|/// \code
comment|///   [obj conformsToProtocol:@protocol(foo)]
comment|/// \endcode
comment|///
comment|/// The return type is "Protocol*".
name|class
name|ObjCProtocolExpr
operator|:
name|public
name|Expr
block|{
name|ObjCProtocolDecl
operator|*
name|TheProtocol
block|;
name|SourceLocation
name|AtLoc
block|,
name|ProtoLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ObjCProtocolExpr
argument_list|(
argument|QualType T
argument_list|,
argument|ObjCProtocolDecl *protocol
argument_list|,
argument|SourceLocation at
argument_list|,
argument|SourceLocation protoLoc
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCProtocolExprClass
argument_list|,
name|T
argument_list|,
name|VK_RValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|TheProtocol
argument_list|(
name|protocol
argument_list|)
block|,
name|AtLoc
argument_list|(
name|at
argument_list|)
block|,
name|ProtoLoc
argument_list|(
name|protoLoc
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{}
name|explicit
name|ObjCProtocolExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCProtocolExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|ObjCProtocolDecl
operator|*
name|getProtocol
argument_list|()
specifier|const
block|{
return|return
name|TheProtocol
return|;
block|}
name|void
name|setProtocol
argument_list|(
argument|ObjCProtocolDecl *P
argument_list|)
block|{
name|TheProtocol
operator|=
name|P
block|; }
name|SourceLocation
name|getProtocolIdLoc
argument_list|()
specifier|const
block|{
return|return
name|ProtoLoc
return|;
block|}
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RParenLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCProtocolExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|()
return|;
block|}
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|; }
block|;
comment|/// ObjCIvarRefExpr - A reference to an ObjC instance variable.
name|class
name|ObjCIvarRefExpr
operator|:
name|public
name|Expr
block|{
name|ObjCIvarDecl
operator|*
name|D
block|;
name|Stmt
operator|*
name|Base
block|;
name|SourceLocation
name|Loc
block|;
comment|/// OpLoc - This is the location of '.' or '->'
name|SourceLocation
name|OpLoc
block|;
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|// True if this is "X->F", false if this is "X.F".
name|bool
name|IsFreeIvar
operator|:
literal|1
block|;
comment|// True if ivar reference has no base (self assumed).
name|public
operator|:
name|ObjCIvarRefExpr
argument_list|(
argument|ObjCIvarDecl *d
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation oploc
argument_list|,
argument|Expr *base
argument_list|,
argument|bool arrow = false
argument_list|,
argument|bool freeIvar = false
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCIvarRefExprClass
argument_list|,
name|t
argument_list|,
name|VK_LValue
argument_list|,
name|d
operator|->
name|isBitField
argument_list|()
condition|?
name|OK_BitField
else|:
name|OK_Ordinary
argument_list|,
comment|/*TypeDependent=*/
name|false
argument_list|,
name|base
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|D
argument_list|(
name|d
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|OpLoc
argument_list|(
name|oploc
argument_list|)
block|,
name|IsArrow
argument_list|(
name|arrow
argument_list|)
block|,
name|IsFreeIvar
argument_list|(
argument|freeIvar
argument_list|)
block|{}
name|explicit
name|ObjCIvarRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCIvarRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|ObjCIvarDecl
operator|*
name|getDecl
argument_list|()
block|{
return|return
name|D
return|;
block|}
specifier|const
name|ObjCIvarDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|D
return|;
block|}
name|void
name|setDecl
argument_list|(
argument|ObjCIvarDecl *d
argument_list|)
block|{
name|D
operator|=
name|d
block|; }
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|Expr
operator|*
name|getBase
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|void
name|setBase
argument_list|(
argument|Expr * base
argument_list|)
block|{
name|Base
operator|=
name|base
block|; }
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
name|bool
name|isFreeIvar
argument_list|()
specifier|const
block|{
return|return
name|IsFreeIvar
return|;
block|}
name|void
name|setIsArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
name|void
name|setIsFreeIvar
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsFreeIvar
operator|=
name|A
block|; }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|isFreeIvar
argument_list|()
condition|?
name|Loc
else|:
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getOpLoc
argument_list|()
specifier|const
block|{
return|return
name|OpLoc
return|;
block|}
name|void
name|setOpLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|OpLoc
operator|=
name|L
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCIvarRefExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|Base
argument_list|,
operator|&
name|Base
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ObjCPropertyRefExpr - A dot-syntax expression to access an ObjC
comment|/// property.
name|class
name|ObjCPropertyRefExpr
operator|:
name|public
name|Expr
block|{
name|private
operator|:
comment|/// If the bool is true, this is an implicit property reference; the
comment|/// pointer is an (optional) ObjCMethodDecl and Setter may be set.
comment|/// if the bool is false, this is an explicit property reference;
comment|/// the pointer is an ObjCPropertyDecl and Setter is always null.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NamedDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|PropertyOrGetter
block|;
comment|/// \brief Indicates whether the property reference will result in a message
comment|/// to the getter, the setter, or both.
comment|/// This applies to both implicit and explicit property references.
block|enum
name|MethodRefFlags
block|{
name|MethodRef_None
operator|=
literal|0
block|,
name|MethodRef_Getter
operator|=
literal|0x1
block|,
name|MethodRef_Setter
operator|=
literal|0x2
block|}
block|;
comment|/// \brief Contains the Setter method pointer and MethodRefFlags bit flags.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ObjCMethodDecl
operator|*
block|,
literal|2
block|,
name|unsigned
operator|>
name|SetterAndMethodRefFlags
block|;
comment|// FIXME: Maybe we should store the property identifier here,
comment|// because it's not rederivable from the other data when there's an
comment|// implicit property with no getter (because the 'foo' -> 'setFoo:'
comment|// transformation is lossy on the first character).
name|SourceLocation
name|IdLoc
block|;
comment|/// \brief When the receiver in property access is 'super', this is
comment|/// the location of the 'super' keyword.  When it's an interface,
comment|/// this is that interface.
name|SourceLocation
name|ReceiverLoc
block|;
name|llvm
operator|::
name|PointerUnion3
operator|<
name|Stmt
operator|*
block|,
specifier|const
name|Type
operator|*
block|,
name|ObjCInterfaceDecl
operator|*
operator|>
name|Receiver
block|;
name|public
operator|:
name|ObjCPropertyRefExpr
argument_list|(
argument|ObjCPropertyDecl *PD
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation l
argument_list|,
argument|Expr *base
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCPropertyRefExprClass
argument_list|,
name|t
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
comment|/*TypeDependent=*/
name|false
argument_list|,
name|base
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PropertyOrGetter
argument_list|(
name|PD
argument_list|,
name|false
argument_list|)
block|,
name|SetterAndMethodRefFlags
argument_list|()
block|,
name|IdLoc
argument_list|(
name|l
argument_list|)
block|,
name|ReceiverLoc
argument_list|()
block|,
name|Receiver
argument_list|(
argument|base
argument_list|)
block|{
name|assert
argument_list|(
name|t
operator|->
name|isSpecificPlaceholderType
argument_list|(
name|BuiltinType
operator|::
name|PseudoObject
argument_list|)
argument_list|)
block|;   }
name|ObjCPropertyRefExpr
argument_list|(
argument|ObjCPropertyDecl *PD
argument_list|,
argument|QualType t
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation sl
argument_list|,
argument|QualType st
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCPropertyRefExprClass
argument_list|,
name|t
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
comment|/*TypeDependent=*/
name|false
argument_list|,
name|false
argument_list|,
name|st
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|st
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PropertyOrGetter
argument_list|(
name|PD
argument_list|,
name|false
argument_list|)
block|,
name|SetterAndMethodRefFlags
argument_list|()
block|,
name|IdLoc
argument_list|(
name|l
argument_list|)
block|,
name|ReceiverLoc
argument_list|(
name|sl
argument_list|)
block|,
name|Receiver
argument_list|(
argument|st.getTypePtr()
argument_list|)
block|{
name|assert
argument_list|(
name|t
operator|->
name|isSpecificPlaceholderType
argument_list|(
name|BuiltinType
operator|::
name|PseudoObject
argument_list|)
argument_list|)
block|;   }
name|ObjCPropertyRefExpr
argument_list|(
argument|ObjCMethodDecl *Getter
argument_list|,
argument|ObjCMethodDecl *Setter
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|Expr *Base
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCPropertyRefExprClass
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|false
argument_list|,
name|Base
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|Base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|Base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|PropertyOrGetter
argument_list|(
name|Getter
argument_list|,
name|true
argument_list|)
block|,
name|SetterAndMethodRefFlags
argument_list|(
name|Setter
argument_list|,
literal|0
argument_list|)
block|,
name|IdLoc
argument_list|(
name|IdLoc
argument_list|)
block|,
name|ReceiverLoc
argument_list|()
block|,
name|Receiver
argument_list|(
argument|Base
argument_list|)
block|{
name|assert
argument_list|(
name|T
operator|->
name|isSpecificPlaceholderType
argument_list|(
name|BuiltinType
operator|::
name|PseudoObject
argument_list|)
argument_list|)
block|;   }
name|ObjCPropertyRefExpr
argument_list|(
argument|ObjCMethodDecl *Getter
argument_list|,
argument|ObjCMethodDecl *Setter
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|SourceLocation SuperLoc
argument_list|,
argument|QualType SuperTy
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCPropertyRefExprClass
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|PropertyOrGetter
argument_list|(
name|Getter
argument_list|,
name|true
argument_list|)
block|,
name|SetterAndMethodRefFlags
argument_list|(
name|Setter
argument_list|,
literal|0
argument_list|)
block|,
name|IdLoc
argument_list|(
name|IdLoc
argument_list|)
block|,
name|ReceiverLoc
argument_list|(
name|SuperLoc
argument_list|)
block|,
name|Receiver
argument_list|(
argument|SuperTy.getTypePtr()
argument_list|)
block|{
name|assert
argument_list|(
name|T
operator|->
name|isSpecificPlaceholderType
argument_list|(
name|BuiltinType
operator|::
name|PseudoObject
argument_list|)
argument_list|)
block|;   }
name|ObjCPropertyRefExpr
argument_list|(
argument|ObjCMethodDecl *Getter
argument_list|,
argument|ObjCMethodDecl *Setter
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|SourceLocation ReceiverLoc
argument_list|,
argument|ObjCInterfaceDecl *Receiver
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCPropertyRefExprClass
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
block|,
name|PropertyOrGetter
argument_list|(
name|Getter
argument_list|,
name|true
argument_list|)
block|,
name|SetterAndMethodRefFlags
argument_list|(
name|Setter
argument_list|,
literal|0
argument_list|)
block|,
name|IdLoc
argument_list|(
name|IdLoc
argument_list|)
block|,
name|ReceiverLoc
argument_list|(
name|ReceiverLoc
argument_list|)
block|,
name|Receiver
argument_list|(
argument|Receiver
argument_list|)
block|{
name|assert
argument_list|(
name|T
operator|->
name|isSpecificPlaceholderType
argument_list|(
name|BuiltinType
operator|::
name|PseudoObject
argument_list|)
argument_list|)
block|;   }
name|explicit
name|ObjCPropertyRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCPropertyRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|bool
name|isImplicitProperty
argument_list|()
specifier|const
block|{
return|return
name|PropertyOrGetter
operator|.
name|getInt
argument_list|()
return|;
block|}
name|bool
name|isExplicitProperty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|PropertyOrGetter
operator|.
name|getInt
argument_list|()
return|;
block|}
name|ObjCPropertyDecl
operator|*
name|getExplicitProperty
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isImplicitProperty
argument_list|()
argument_list|)
block|;
return|return
name|cast
operator|<
name|ObjCPropertyDecl
operator|>
operator|(
name|PropertyOrGetter
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getImplicitPropertyGetter
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isImplicitProperty
argument_list|()
argument_list|)
block|;
return|return
name|cast_or_null
operator|<
name|ObjCMethodDecl
operator|>
operator|(
name|PropertyOrGetter
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getImplicitPropertySetter
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isImplicitProperty
argument_list|()
argument_list|)
block|;
return|return
name|SetterAndMethodRefFlags
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|Selector
name|getGetterSelector
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isImplicitProperty
argument_list|()
condition|)
return|return
name|getImplicitPropertyGetter
argument_list|()
operator|->
name|getSelector
argument_list|()
return|;
return|return
name|getExplicitProperty
argument_list|()
operator|->
name|getGetterName
argument_list|()
return|;
block|}
name|Selector
name|getSetterSelector
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isImplicitProperty
argument_list|()
condition|)
return|return
name|getImplicitPropertySetter
argument_list|()
operator|->
name|getSelector
argument_list|()
return|;
return|return
name|getExplicitProperty
argument_list|()
operator|->
name|getSetterName
argument_list|()
return|;
block|}
comment|/// \brief True if the property reference will result in a message to the
comment|/// getter.
comment|/// This applies to both implicit and explicit property references.
name|bool
name|isMessagingGetter
argument_list|()
specifier|const
block|{
return|return
name|SetterAndMethodRefFlags
operator|.
name|getInt
argument_list|()
operator|&
name|MethodRef_Getter
return|;
block|}
comment|/// \brief True if the property reference will result in a message to the
comment|/// setter.
comment|/// This applies to both implicit and explicit property references.
name|bool
name|isMessagingSetter
argument_list|()
specifier|const
block|{
return|return
name|SetterAndMethodRefFlags
operator|.
name|getInt
argument_list|()
operator|&
name|MethodRef_Setter
return|;
block|}
name|void
name|setIsMessagingGetter
argument_list|(
argument|bool val = true
argument_list|)
block|{
name|setMethodRefFlag
argument_list|(
name|MethodRef_Getter
argument_list|,
name|val
argument_list|)
block|;   }
name|void
name|setIsMessagingSetter
argument_list|(
argument|bool val = true
argument_list|)
block|{
name|setMethodRefFlag
argument_list|(
name|MethodRef_Setter
argument_list|,
name|val
argument_list|)
block|;   }
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Receiver
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|Expr
operator|*
name|getBase
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Receiver
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|IdLoc
return|;
block|}
name|SourceLocation
name|getReceiverLocation
argument_list|()
specifier|const
block|{
return|return
name|ReceiverLoc
return|;
block|}
name|QualType
name|getSuperReceiverType
argument_list|()
specifier|const
block|{
return|return
name|QualType
argument_list|(
name|Receiver
operator|.
name|get
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
operator|)
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|QualType
name|getGetterResultType
argument_list|()
specifier|const
block|{
name|QualType
name|ResultType
block|;
if|if
condition|(
name|isExplicitProperty
argument_list|()
condition|)
block|{
specifier|const
name|ObjCPropertyDecl
modifier|*
name|PDecl
init|=
name|getExplicitProperty
argument_list|()
decl_stmt|;
if|if
condition|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|Getter
init|=
name|PDecl
operator|->
name|getGetterMethodDecl
argument_list|()
condition|)
name|ResultType
operator|=
name|Getter
operator|->
name|getResultType
argument_list|()
expr_stmt|;
else|else
name|ResultType
operator|=
name|PDecl
operator|->
name|getType
argument_list|()
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|ObjCMethodDecl
modifier|*
name|Getter
init|=
name|getImplicitPropertyGetter
argument_list|()
decl_stmt|;
if|if
condition|(
name|Getter
condition|)
name|ResultType
operator|=
name|Getter
operator|->
name|getResultType
argument_list|()
expr_stmt|;
comment|// with reference!
block|}
return|return
name|ResultType
return|;
block|}
name|QualType
name|getSetterArgType
argument_list|()
specifier|const
block|{
name|QualType
name|ArgType
block|;
if|if
condition|(
name|isImplicitProperty
argument_list|()
condition|)
block|{
specifier|const
name|ObjCMethodDecl
modifier|*
name|Setter
init|=
name|getImplicitPropertySetter
argument_list|()
decl_stmt|;
name|ObjCMethodDecl
operator|::
name|param_const_iterator
name|P
operator|=
name|Setter
operator|->
name|param_begin
argument_list|()
expr_stmt|;
name|ArgType
operator|=
operator|(
operator|*
name|P
operator|)
operator|->
name|getType
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|ObjCPropertyDecl
modifier|*
name|PDecl
init|=
name|getExplicitProperty
argument_list|()
condition|)
if|if
condition|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|Setter
init|=
name|PDecl
operator|->
name|getSetterMethodDecl
argument_list|()
condition|)
block|{
name|ObjCMethodDecl
operator|::
name|param_const_iterator
name|P
operator|=
name|Setter
operator|->
name|param_begin
argument_list|()
expr_stmt|;
name|ArgType
operator|=
operator|(
operator|*
name|P
operator|)
operator|->
name|getType
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|ArgType
operator|.
name|isNull
argument_list|()
condition|)
name|ArgType
operator|=
name|getType
argument_list|()
expr_stmt|;
block|}
return|return
name|ArgType
return|;
block|}
name|ObjCInterfaceDecl
operator|*
name|getClassReceiver
argument_list|()
specifier|const
block|{
return|return
name|Receiver
operator|.
name|get
operator|<
name|ObjCInterfaceDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isObjectReceiver
argument_list|()
specifier|const
block|{
return|return
name|Receiver
operator|.
name|is
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isSuperReceiver
argument_list|()
specifier|const
block|{
return|return
name|Receiver
operator|.
name|is
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isClassReceiver
argument_list|()
specifier|const
block|{
return|return
name|Receiver
operator|.
name|is
operator|<
name|ObjCInterfaceDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|isObjectReceiver
argument_list|()
operator|?
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
operator|:
name|getReceiverLocation
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|IdLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCPropertyRefExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
if|if
condition|(
name|Receiver
operator|.
name|is
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
condition|)
block|{
name|Stmt
modifier|*
modifier|*
name|begin
init|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
operator|&
name|Receiver
operator|)
decl_stmt|;
comment|// hack!
return|return
name|child_range
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
literal|1
argument_list|)
return|;
block|}
return|return
name|child_range
argument_list|()
return|;
block|}
name|private
operator|:
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|;
name|void
name|setExplicitProperty
argument_list|(
argument|ObjCPropertyDecl *D
argument_list|,
argument|unsigned methRefFlags
argument_list|)
block|{
name|PropertyOrGetter
operator|.
name|setPointer
argument_list|(
name|D
argument_list|)
block|;
name|PropertyOrGetter
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
block|;
name|SetterAndMethodRefFlags
operator|.
name|setPointer
argument_list|(
literal|0
argument_list|)
block|;
name|SetterAndMethodRefFlags
operator|.
name|setInt
argument_list|(
name|methRefFlags
argument_list|)
block|;   }
name|void
name|setImplicitProperty
argument_list|(
argument|ObjCMethodDecl *Getter
argument_list|,
argument|ObjCMethodDecl *Setter
argument_list|,
argument|unsigned methRefFlags
argument_list|)
block|{
name|PropertyOrGetter
operator|.
name|setPointer
argument_list|(
name|Getter
argument_list|)
block|;
name|PropertyOrGetter
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|;
name|SetterAndMethodRefFlags
operator|.
name|setPointer
argument_list|(
name|Setter
argument_list|)
block|;
name|SetterAndMethodRefFlags
operator|.
name|setInt
argument_list|(
name|methRefFlags
argument_list|)
block|;   }
name|void
name|setBase
argument_list|(
argument|Expr *Base
argument_list|)
block|{
name|Receiver
operator|=
name|Base
block|; }
name|void
name|setSuperReceiver
argument_list|(
argument|QualType T
argument_list|)
block|{
name|Receiver
operator|=
name|T
operator|.
name|getTypePtr
argument_list|()
block|; }
name|void
name|setClassReceiver
argument_list|(
argument|ObjCInterfaceDecl *D
argument_list|)
block|{
name|Receiver
operator|=
name|D
block|; }
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|IdLoc
operator|=
name|L
block|; }
name|void
name|setReceiverLocation
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|ReceiverLoc
operator|=
name|Loc
block|; }
name|void
name|setMethodRefFlag
argument_list|(
argument|MethodRefFlags flag
argument_list|,
argument|bool val
argument_list|)
block|{
name|unsigned
name|f
operator|=
name|SetterAndMethodRefFlags
operator|.
name|getInt
argument_list|()
block|;
if|if
condition|(
name|val
condition|)
name|f
operator||=
name|flag
expr_stmt|;
else|else
name|f
operator|&=
operator|~
name|flag
expr_stmt|;
name|SetterAndMethodRefFlags
operator|.
name|setInt
argument_list|(
name|f
argument_list|)
block|;   }
block|}
block|;
comment|/// ObjCSubscriptRefExpr - used for array and dictionary subscripting.
comment|/// array[4] = array[3]; dictionary[key] = dictionary[alt_key];
comment|///
name|class
name|ObjCSubscriptRefExpr
operator|:
name|public
name|Expr
block|{
comment|// Location of ']' in an indexing expression.
name|SourceLocation
name|RBracket
block|;
comment|// array/dictionary base expression.
comment|// for arrays, this is a numeric expression. For dictionaries, this is
comment|// an objective-c object pointer expression.
block|enum
block|{
name|BASE
block|,
name|KEY
block|,
name|END_EXPR
block|}
block|;
name|Stmt
operator|*
name|SubExprs
index|[
name|END_EXPR
index|]
block|;
name|ObjCMethodDecl
operator|*
name|GetAtIndexMethodDecl
block|;
comment|// For immutable objects this is null. When ObjCSubscriptRefExpr is to read
comment|// an indexed object this is null too.
name|ObjCMethodDecl
operator|*
name|SetAtIndexMethodDecl
block|;
name|public
operator|:
name|ObjCSubscriptRefExpr
argument_list|(
argument|Expr *base
argument_list|,
argument|Expr *key
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|ExprObjectKind OK
argument_list|,
argument|ObjCMethodDecl *getMethod
argument_list|,
argument|ObjCMethodDecl *setMethod
argument_list|,
argument|SourceLocation RB
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCSubscriptRefExprClass
argument_list|,
name|T
argument_list|,
name|VK
argument_list|,
name|OK
argument_list|,
name|base
operator|->
name|isTypeDependent
argument_list|()
operator|||
name|key
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isValueDependent
argument_list|()
operator|||
name|key
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
operator|||
name|key
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
operator|(
name|base
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|||
name|key
operator|->
name|containsUnexpandedParameterPack
argument_list|()
operator|)
argument_list|)
block|,
name|RBracket
argument_list|(
name|RB
argument_list|)
block|,
name|GetAtIndexMethodDecl
argument_list|(
name|getMethod
argument_list|)
block|,
name|SetAtIndexMethodDecl
argument_list|(
argument|setMethod
argument_list|)
block|{
name|SubExprs
index|[
name|BASE
index|]
operator|=
name|base
block|;
name|SubExprs
index|[
name|KEY
index|]
operator|=
name|key
block|;}
name|explicit
name|ObjCSubscriptRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCSubscriptRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
specifier|static
name|ObjCSubscriptRefExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|Expr *base
argument_list|,
argument|Expr *key
argument_list|,
argument|QualType T
argument_list|,
argument|ObjCMethodDecl *getMethod
argument_list|,
argument|ObjCMethodDecl *setMethod
argument_list|,
argument|SourceLocation RB
argument_list|)
block|;
name|SourceLocation
name|getRBracket
argument_list|()
specifier|const
block|{
return|return
name|RBracket
return|;
block|}
name|void
name|setRBracket
argument_list|(
argument|SourceLocation RB
argument_list|)
block|{
name|RBracket
operator|=
name|RB
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SubExprs
index|[
name|BASE
index|]
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RBracket
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCSubscriptRefExprClass
return|;
block|}
name|Expr
operator|*
name|getBaseExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|BASE
index|]
operator|)
return|;
block|}
name|void
name|setBaseExpr
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SubExprs
index|[
name|BASE
index|]
operator|=
name|S
block|; }
name|Expr
operator|*
name|getKeyExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|KEY
index|]
operator|)
return|;
block|}
name|void
name|setKeyExpr
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SubExprs
index|[
name|KEY
index|]
operator|=
name|S
block|; }
name|ObjCMethodDecl
operator|*
name|getAtIndexMethodDecl
argument_list|()
specifier|const
block|{
return|return
name|GetAtIndexMethodDecl
return|;
block|}
name|ObjCMethodDecl
operator|*
name|setAtIndexMethodDecl
argument_list|()
specifier|const
block|{
return|return
name|SetAtIndexMethodDecl
return|;
block|}
name|bool
name|isArraySubscriptRefExpr
argument_list|()
specifier|const
block|{
return|return
name|getKeyExpr
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|isIntegralOrEnumerationType
argument_list|()
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
name|SubExprs
argument_list|,
name|SubExprs
operator|+
name|END_EXPR
argument_list|)
return|;
block|}
name|private
operator|:
name|friend
name|class
name|ASTStmtReader
block|; }
block|;
comment|/// \brief An expression that sends a message to the given Objective-C
comment|/// object or class.
comment|///
comment|/// The following contains two message send expressions:
comment|///
comment|/// \code
comment|///   [[NSString alloc] initWithString:@"Hello"]
comment|/// \endcode
comment|///
comment|/// The innermost message send invokes the "alloc" class method on the
comment|/// NSString class, while the outermost message send invokes the
comment|/// "initWithString" instance method on the object returned from
comment|/// NSString's "alloc". In all, an Objective-C message send can take
comment|/// on four different (although related) forms:
comment|///
comment|///   1. Send to an object instance.
comment|///   2. Send to a class.
comment|///   3. Send to the superclass instance of the current class.
comment|///   4. Send to the superclass of the current class.
comment|///
comment|/// All four kinds of message sends are modeled by the ObjCMessageExpr
comment|/// class, and can be distinguished via \c getReceiverKind(). Example:
comment|///
name|class
name|ObjCMessageExpr
operator|:
name|public
name|Expr
block|{
comment|/// \brief Stores either the selector that this message is sending
comment|/// to (when \c HasMethod is zero) or an \c ObjCMethodDecl pointer
comment|/// referring to the method that we type-checked against.
name|uintptr_t
name|SelectorOrMethod
block|;    enum
block|{
name|NumArgsBitWidth
operator|=
literal|16
block|}
block|;
comment|/// \brief The number of arguments in the message send, not
comment|/// including the receiver.
name|unsigned
name|NumArgs
operator|:
name|NumArgsBitWidth
block|;
name|void
name|setNumArgs
argument_list|(
argument|unsigned Num
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Num
operator|>>
name|NumArgsBitWidth
operator|)
operator|==
literal|0
operator|&&
literal|"Num of args is out of range!"
argument_list|)
block|;
name|NumArgs
operator|=
name|Num
block|;   }
comment|/// \brief The kind of message send this is, which is one of the
comment|/// ReceiverKind values.
comment|///
comment|/// We pad this out to a byte to avoid excessive masking and shifting.
name|unsigned
name|Kind
operator|:
literal|8
block|;
comment|/// \brief Whether we have an actual method prototype in \c
comment|/// SelectorOrMethod.
comment|///
comment|/// When non-zero, we have a method declaration; otherwise, we just
comment|/// have a selector.
name|unsigned
name|HasMethod
operator|:
literal|1
block|;
comment|/// \brief Whether this message send is a "delegate init call",
comment|/// i.e. a call of an init method on self from within an init method.
name|unsigned
name|IsDelegateInitCall
operator|:
literal|1
block|;
comment|/// \brief Whether this message send was implicitly generated by
comment|/// the implementation rather than explicitly written by the user.
name|unsigned
name|IsImplicit
operator|:
literal|1
block|;
comment|/// \brief Whether the locations of the selector identifiers are in a
comment|/// "standard" position, a enum SelectorLocationsKind.
name|unsigned
name|SelLocsKind
operator|:
literal|2
block|;
comment|/// \brief When the message expression is a send to 'super', this is
comment|/// the location of the 'super' keyword.
name|SourceLocation
name|SuperLoc
block|;
comment|/// \brief The source locations of the open and close square
comment|/// brackets ('[' and ']', respectively).
name|SourceLocation
name|LBracLoc
block|,
name|RBracLoc
block|;
name|ObjCMessageExpr
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned NumArgs
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCMessageExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|SelectorOrMethod
argument_list|(
literal|0
argument_list|)
block|,
name|Kind
argument_list|(
literal|0
argument_list|)
block|,
name|HasMethod
argument_list|(
literal|0
argument_list|)
block|,
name|IsDelegateInitCall
argument_list|(
literal|0
argument_list|)
block|,
name|IsImplicit
argument_list|(
literal|0
argument_list|)
block|,
name|SelLocsKind
argument_list|(
literal|0
argument_list|)
block|{
name|setNumArgs
argument_list|(
name|NumArgs
argument_list|)
block|;   }
name|ObjCMessageExpr
argument_list|(
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LBracLoc
argument_list|,
argument|SourceLocation SuperLoc
argument_list|,
argument|bool IsInstanceSuper
argument_list|,
argument|QualType SuperType
argument_list|,
argument|Selector Sel
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|SelectorLocationsKind SelLocsK
argument_list|,
argument|ObjCMethodDecl *Method
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBracLoc
argument_list|,
argument|bool isImplicit
argument_list|)
block|;
name|ObjCMessageExpr
argument_list|(
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LBracLoc
argument_list|,
argument|TypeSourceInfo *Receiver
argument_list|,
argument|Selector Sel
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|SelectorLocationsKind SelLocsK
argument_list|,
argument|ObjCMethodDecl *Method
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBracLoc
argument_list|,
argument|bool isImplicit
argument_list|)
block|;
name|ObjCMessageExpr
argument_list|(
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LBracLoc
argument_list|,
argument|Expr *Receiver
argument_list|,
argument|Selector Sel
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|SelectorLocationsKind SelLocsK
argument_list|,
argument|ObjCMethodDecl *Method
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBracLoc
argument_list|,
argument|bool isImplicit
argument_list|)
block|;
name|void
name|initArgsAndSelLocs
argument_list|(
argument|ArrayRef<Expr *> Args
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|SelectorLocationsKind SelLocsK
argument_list|)
block|;
comment|/// \brief Retrieve the pointer value of the message receiver.
name|void
operator|*
name|getReceiverPointer
argument_list|()
specifier|const
block|{
return|return
operator|*
name|const_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|void
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|)
return|;
block|}
comment|/// \brief Set the pointer value of the message receiver.
name|void
name|setReceiverPointer
argument_list|(
argument|void *Value
argument_list|)
block|{
operator|*
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|=
name|Value
block|;   }
name|SelectorLocationsKind
name|getSelLocsKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SelectorLocationsKind
operator|)
name|SelLocsKind
return|;
block|}
name|bool
name|hasStandardSelLocs
argument_list|()
specifier|const
block|{
return|return
name|getSelLocsKind
argument_list|()
operator|!=
name|SelLoc_NonStandard
return|;
block|}
comment|/// \brief Get a pointer to the stored selector identifiers locations array.
comment|/// No locations will be stored if HasStandardSelLocs is true.
name|SourceLocation
operator|*
name|getStoredSelLocs
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|SourceLocation
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|+
name|getNumArgs
argument_list|()
operator|)
return|;
block|}
specifier|const
name|SourceLocation
operator|*
name|getStoredSelLocs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|SourceLocation
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|+
name|getNumArgs
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Get the number of stored selector identifiers locations.
comment|/// No locations will be stored if HasStandardSelLocs is true.
name|unsigned
name|getNumStoredSelLocs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasStandardSelLocs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|getNumSelectorLocs
argument_list|()
return|;
block|}
specifier|static
name|ObjCMessageExpr
operator|*
name|alloc
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBraceLoc
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|Selector Sel
argument_list|,
argument|SelectorLocationsKind&SelLocsK
argument_list|)
block|;
specifier|static
name|ObjCMessageExpr
operator|*
name|alloc
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|unsigned NumStoredSelLocs
argument_list|)
block|;
name|public
operator|:
comment|/// \brief The kind of receiver this message is sending to.
expr|enum
name|ReceiverKind
block|{
comment|/// \brief The receiver is a class.
name|Class
operator|=
literal|0
block|,
comment|/// \brief The receiver is an object instance.
name|Instance
block|,
comment|/// \brief The receiver is a superclass.
name|SuperClass
block|,
comment|/// \brief The receiver is the instance of the superclass object.
name|SuperInstance
block|}
block|;
comment|/// \brief Create a message send to super.
comment|///
comment|/// \param Context The ASTContext in which this expression will be created.
comment|///
comment|/// \param T The result type of this message.
comment|///
comment|/// \param VK The value kind of this message.  A message returning
comment|/// a l-value or r-value reference will be an l-value or x-value,
comment|/// respectively.
comment|///
comment|/// \param LBracLoc The location of the open square bracket '['.
comment|///
comment|/// \param SuperLoc The location of the "super" keyword.
comment|///
comment|/// \param IsInstanceSuper Whether this is an instance "super"
comment|/// message (otherwise, it's a class "super" message).
comment|///
comment|/// \param Sel The selector used to determine which method gets called.
comment|///
comment|/// \param Method The Objective-C method against which this message
comment|/// send was type-checked. May be NULL.
comment|///
comment|/// \param Args The message send arguments.
comment|///
comment|/// \param RBracLoc The location of the closing square bracket ']'.
specifier|static
name|ObjCMessageExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LBracLoc
argument_list|,
argument|SourceLocation SuperLoc
argument_list|,
argument|bool IsInstanceSuper
argument_list|,
argument|QualType SuperType
argument_list|,
argument|Selector Sel
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|ObjCMethodDecl *Method
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBracLoc
argument_list|,
argument|bool isImplicit
argument_list|)
block|;
comment|/// \brief Create a class message send.
comment|///
comment|/// \param Context The ASTContext in which this expression will be created.
comment|///
comment|/// \param T The result type of this message.
comment|///
comment|/// \param VK The value kind of this message.  A message returning
comment|/// a l-value or r-value reference will be an l-value or x-value,
comment|/// respectively.
comment|///
comment|/// \param LBracLoc The location of the open square bracket '['.
comment|///
comment|/// \param Receiver The type of the receiver, including
comment|/// source-location information.
comment|///
comment|/// \param Sel The selector used to determine which method gets called.
comment|///
comment|/// \param Method The Objective-C method against which this message
comment|/// send was type-checked. May be NULL.
comment|///
comment|/// \param Args The message send arguments.
comment|///
comment|/// \param RBracLoc The location of the closing square bracket ']'.
specifier|static
name|ObjCMessageExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LBracLoc
argument_list|,
argument|TypeSourceInfo *Receiver
argument_list|,
argument|Selector Sel
argument_list|,
argument|ArrayRef<SourceLocation> SelLocs
argument_list|,
argument|ObjCMethodDecl *Method
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBracLoc
argument_list|,
argument|bool isImplicit
argument_list|)
block|;
comment|/// \brief Create an instance message send.
comment|///
comment|/// \param Context The ASTContext in which this expression will be created.
comment|///
comment|/// \param T The result type of this message.
comment|///
comment|/// \param VK The value kind of this message.  A message returning
comment|/// a l-value or r-value reference will be an l-value or x-value,
comment|/// respectively.
comment|///
comment|/// \param LBracLoc The location of the open square bracket '['.
comment|///
comment|/// \param Receiver The expression used to produce the object that
comment|/// will receive this message.
comment|///
comment|/// \param Sel The selector used to determine which method gets called.
comment|///
comment|/// \param Method The Objective-C method against which this message
comment|/// send was type-checked. May be NULL.
comment|///
comment|/// \param Args The message send arguments.
comment|///
comment|/// \param RBracLoc The location of the closing square bracket ']'.
specifier|static
name|ObjCMessageExpr
operator|*
name|Create
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|ExprValueKind VK
argument_list|,
argument|SourceLocation LBracLoc
argument_list|,
argument|Expr *Receiver
argument_list|,
argument|Selector Sel
argument_list|,
argument|ArrayRef<SourceLocation> SeLocs
argument_list|,
argument|ObjCMethodDecl *Method
argument_list|,
argument|ArrayRef<Expr *> Args
argument_list|,
argument|SourceLocation RBracLoc
argument_list|,
argument|bool isImplicit
argument_list|)
block|;
comment|/// \brief Create an empty Objective-C message expression, to be
comment|/// filled in by subsequent calls.
comment|///
comment|/// \param Context The context in which the message send will be created.
comment|///
comment|/// \param NumArgs The number of message arguments, not including
comment|/// the receiver.
specifier|static
name|ObjCMessageExpr
operator|*
name|CreateEmpty
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|unsigned NumArgs
argument_list|,
argument|unsigned NumStoredSelLocs
argument_list|)
block|;
comment|/// \brief Indicates whether the message send was implicitly
comment|/// generated by the implementation. If false, it was written explicitly
comment|/// in the source code.
name|bool
name|isImplicit
argument_list|()
specifier|const
block|{
return|return
name|IsImplicit
return|;
block|}
comment|/// \brief Determine the kind of receiver that this message is being
comment|/// sent to.
name|ReceiverKind
name|getReceiverKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ReceiverKind
operator|)
name|Kind
return|;
block|}
comment|/// \brief Source range of the receiver.
name|SourceRange
name|getReceiverRange
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this is an instance message to either a
comment|/// computed object or to super.
name|bool
name|isInstanceMessage
argument_list|()
specifier|const
block|{
return|return
name|getReceiverKind
argument_list|()
operator|==
name|Instance
operator|||
name|getReceiverKind
argument_list|()
operator|==
name|SuperInstance
return|;
block|}
comment|/// \brief Determine whether this is an class message to either a
comment|/// specified class or to super.
name|bool
name|isClassMessage
argument_list|()
specifier|const
block|{
return|return
name|getReceiverKind
argument_list|()
operator|==
name|Class
operator|||
name|getReceiverKind
argument_list|()
operator|==
name|SuperClass
return|;
block|}
comment|/// \brief Returns the object expression (receiver) for an instance message,
comment|/// or null for a message that is not an instance message.
name|Expr
operator|*
name|getInstanceReceiver
argument_list|()
block|{
if|if
condition|(
name|getReceiverKind
argument_list|()
operator|==
name|Instance
condition|)
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|getReceiverPointer
argument_list|()
operator|)
return|;
return|return
literal|0
return|;
block|}
specifier|const
name|Expr
operator|*
name|getInstanceReceiver
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ObjCMessageExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getInstanceReceiver
argument_list|()
return|;
block|}
comment|/// \brief Turn this message send into an instance message that
comment|/// computes the receiver object with the given expression.
name|void
name|setInstanceReceiver
parameter_list|(
name|Expr
modifier|*
name|rec
parameter_list|)
block|{
name|Kind
operator|=
name|Instance
expr_stmt|;
name|setReceiverPointer
argument_list|(
name|rec
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Returns the type of a class message send, or NULL if the
comment|/// message is not a class message.
name|QualType
name|getClassReceiver
argument_list|()
specifier|const
block|{
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TSInfo
init|=
name|getClassReceiverTypeInfo
argument_list|()
condition|)
return|return
name|TSInfo
operator|->
name|getType
argument_list|()
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns a type-source information of a class message
end_comment

begin_comment
comment|/// send, or NULL if the message is not a class message.
end_comment

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getClassReceiverTypeInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getReceiverKind
argument_list|()
operator|==
name|Class
condition|)
return|return
name|reinterpret_cast
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
name|getReceiverPointer
argument_list|()
operator|)
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_macro
unit|}    void
name|setClassReceiver
argument_list|(
argument|TypeSourceInfo *TSInfo
argument_list|)
end_macro

begin_block
block|{
name|Kind
operator|=
name|Class
expr_stmt|;
name|setReceiverPointer
argument_list|(
name|TSInfo
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the location of the 'super' keyword for a class
end_comment

begin_comment
comment|/// or instance message to 'super', otherwise an invalid source location.
end_comment

begin_expr_stmt
name|SourceLocation
name|getSuperLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getReceiverKind
argument_list|()
operator|==
name|SuperInstance
operator|||
name|getReceiverKind
argument_list|()
operator|==
name|SuperClass
condition|)
return|return
name|SuperLoc
return|;
end_expr_stmt

begin_return
return|return
name|SourceLocation
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the receiver type to which this message is being directed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine cross-cuts all of the different kinds of message
end_comment

begin_comment
comment|/// sends to determine what the underlying (statically known) type
end_comment

begin_comment
comment|/// of the receiver will be; use \c getReceiverKind() to determine
end_comment

begin_comment
comment|/// whether the message is a class or an instance method, whether it
end_comment

begin_comment
comment|/// is a send to super or not, etc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The type of the receiver.
end_comment

begin_macro
unit|QualType
name|getReceiverType
argument_list|()
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the Objective-C interface to which this message
end_comment

begin_comment
comment|/// is being directed, if known.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine cross-cuts all of the different kinds of message
end_comment

begin_comment
comment|/// sends to determine what the underlying (statically known) type
end_comment

begin_comment
comment|/// of the receiver will be; use \c getReceiverKind() to determine
end_comment

begin_comment
comment|/// whether the message is a class or an instance method, whether it
end_comment

begin_comment
comment|/// is a send to super or not, etc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The Objective-C interface if known, otherwise NULL.
end_comment

begin_expr_stmt
name|ObjCInterfaceDecl
operator|*
name|getReceiverInterface
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the type referred to by 'super'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The returned type will either be an ObjCInterfaceType (for an
end_comment

begin_comment
comment|/// class message to super) or an ObjCObjectPointerType that refers
end_comment

begin_comment
comment|/// to a class (for an instance message to super);
end_comment

begin_expr_stmt
name|QualType
name|getSuperType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getReceiverKind
argument_list|()
operator|==
name|SuperInstance
operator|||
name|getReceiverKind
argument_list|()
operator|==
name|SuperClass
condition|)
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|getReceiverPointer
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|QualType
argument_list|()
return|;
end_return

begin_macro
unit|}    void
name|setSuper
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|,
argument|bool IsInstanceSuper
argument_list|)
end_macro

begin_block
block|{
name|Kind
operator|=
name|IsInstanceSuper
condition|?
name|SuperInstance
else|:
name|SuperClass
expr_stmt|;
name|SuperLoc
operator|=
name|Loc
expr_stmt|;
name|setReceiverPointer
argument_list|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|Selector
name|getSelector
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setSelector
parameter_list|(
name|Selector
name|S
parameter_list|)
block|{
name|HasMethod
operator|=
name|false
expr_stmt|;
name|SelectorOrMethod
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|S
operator|.
name|getAsOpaquePtr
argument_list|()
operator|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|const
name|ObjCMethodDecl
operator|*
name|getMethodDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|HasMethod
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ObjCMethodDecl
operator|*
operator|>
operator|(
name|SelectorOrMethod
operator|)
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_expr_stmt
unit|}    ObjCMethodDecl
operator|*
name|getMethodDecl
argument_list|()
block|{
if|if
condition|(
name|HasMethod
condition|)
return|return
name|reinterpret_cast
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|(
name|SelectorOrMethod
operator|)
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_macro
unit|}    void
name|setMethodDecl
argument_list|(
argument|ObjCMethodDecl *MD
argument_list|)
end_macro

begin_block
block|{
name|HasMethod
operator|=
name|true
expr_stmt|;
name|SelectorOrMethod
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|MD
operator|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ObjCMethodFamily
name|getMethodFamily
argument_list|()
specifier|const
block|{
if|if
condition|(
name|HasMethod
condition|)
return|return
name|getMethodDecl
argument_list|()
operator|->
name|getMethodFamily
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getSelector
argument_list|()
operator|.
name|getMethodFamily
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Return the number of actual arguments in this message,
end_comment

begin_comment
comment|/// not counting the receiver.
end_comment

begin_macro
unit|unsigned
name|getNumArgs
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the arguments to this message, not including the
end_comment

begin_comment
comment|/// receiver.
end_comment

begin_function
name|Expr
modifier|*
modifier|*
name|getArgs
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|+
literal|1
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|Expr
operator|*
specifier|const
operator|*
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|Expr
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getArg - Return the specified argument.
end_comment

begin_function
name|Expr
modifier|*
name|getArg
parameter_list|(
name|unsigned
name|Arg
parameter_list|)
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
expr_stmt|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getArgs
argument_list|()
index|[
name|Arg
index|]
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|Expr
modifier|*
name|getArg
argument_list|(
name|unsigned
name|Arg
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
expr_stmt|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|getArgs
argument_list|()
index|[
name|Arg
index|]
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// setArg - Set the specified argument.
end_comment

begin_function
name|void
name|setArg
parameter_list|(
name|unsigned
name|Arg
parameter_list|,
name|Expr
modifier|*
name|ArgExpr
parameter_list|)
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
expr_stmt|;
name|getArgs
argument_list|()
index|[
name|Arg
index|]
operator|=
name|ArgExpr
expr_stmt|;
block|}
end_function

begin_comment
comment|/// isDelegateInitCall - Answers whether this message send has been
end_comment

begin_comment
comment|/// tagged as a "delegate init call", i.e. a call to a method in the
end_comment

begin_comment
comment|/// -init family on self from within an -init method implementation.
end_comment

begin_expr_stmt
name|bool
name|isDelegateInitCall
argument_list|()
specifier|const
block|{
return|return
name|IsDelegateInitCall
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDelegateInitCall
parameter_list|(
name|bool
name|isDelegate
parameter_list|)
block|{
name|IsDelegateInitCall
operator|=
name|isDelegate
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getLeftLoc
argument_list|()
specifier|const
block|{
return|return
name|LBracLoc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getRightLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracLoc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getSelectorStartLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isImplicit
argument_list|()
condition|)
return|return
name|getLocStart
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getSelectorLoc
argument_list|(
literal|0
argument_list|)
return|;
end_return

begin_macro
unit|}   SourceLocation
name|getSelectorLoc
argument_list|(
argument|unsigned Index
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|getNumSelectorLocs
argument_list|()
operator|&&
literal|"Index out of range!"
argument_list|)
block|;
if|if
condition|(
name|hasStandardSelLocs
argument_list|()
condition|)
return|return
name|getStandardSelectorLoc
argument_list|(
name|Index
argument_list|,
name|getSelector
argument_list|()
argument_list|,
name|getSelLocsKind
argument_list|()
operator|==
name|SelLoc_StandardWithSpace
argument_list|,
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|const_cast
operator|<
name|Expr
operator|*
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|)
argument_list|,
name|getNumArgs
argument_list|()
argument_list|)
argument_list|,
name|RBracLoc
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|getStoredSelLocs
argument_list|()
index|[
name|Index
index|]
return|;
end_return

begin_macro
unit|}    void
name|getSelectorLocs
argument_list|(
argument|SmallVectorImpl<SourceLocation>&SelLocs
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getNumSelectorLocs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isImplicit
argument_list|()
condition|)
return|return
literal|0
return|;
name|Selector
name|Sel
operator|=
name|getSelector
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Sel
operator|.
name|isUnarySelector
argument_list|()
condition|)
return|return
literal|1
return|;
end_if

begin_return
return|return
name|Sel
operator|.
name|getNumArgs
argument_list|()
return|;
end_return

begin_macro
unit|}    void
name|setSourceRange
argument_list|(
argument|SourceRange R
argument_list|)
end_macro

begin_block
block|{
name|LBracLoc
operator|=
name|R
operator|.
name|getBegin
argument_list|()
expr_stmt|;
name|RBracLoc
operator|=
name|R
operator|.
name|getEnd
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LBracLoc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|RBracLoc
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCMessageExprClass
return|;
block|}
end_function

begin_comment
comment|// Iterators
end_comment

begin_function_decl
name|child_range
name|children
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|ExprIterator
name|arg_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ConstExprIterator
name|const_arg_iterator
typedef|;
end_typedef

begin_function
name|arg_iterator
name|arg_begin
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
name|arg_iterator
name|arg_end
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|+
name|NumArgs
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|const_arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
specifier|const
operator|*
specifier|const
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|Stmt
specifier|const
operator|*
specifier|const
operator|*
operator|>
operator|(
name|getArgs
argument_list|()
operator|+
name|NumArgs
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTStmtWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// ObjCIsaExpr - Represent X->isa and X.isa when X is an ObjC 'id' type.
end_comment

begin_comment
comment|/// (similar in spirit to MemberExpr).
end_comment

begin_decl_stmt
name|class
name|ObjCIsaExpr
range|:
name|public
name|Expr
block|{
comment|/// Base - the expression for the base object pointer.
name|Stmt
operator|*
name|Base
block|;
comment|/// IsaMemberLoc - This is the location of the 'isa'.
name|SourceLocation
name|IsaMemberLoc
block|;
comment|/// OpLoc - This is the location of '.' or '->'
name|SourceLocation
name|OpLoc
block|;
comment|/// IsArrow - True if this is "X->F", false if this is "X.F".
name|bool
name|IsArrow
block|;
name|public
operator|:
name|ObjCIsaExpr
argument_list|(
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|SourceLocation l
argument_list|,
argument|SourceLocation oploc
argument_list|,
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCIsaExprClass
argument_list|,
name|ty
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
comment|/*TypeDependent=*/
name|false
argument_list|,
name|base
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|base
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
comment|/*ContainsUnexpandedParameterPack=*/
name|false
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|IsaMemberLoc
argument_list|(
name|l
argument_list|)
block|,
name|OpLoc
argument_list|(
name|oploc
argument_list|)
block|,
name|IsArrow
argument_list|(
argument|isarrow
argument_list|)
block|{}
comment|/// \brief Build an empty expression.
name|explicit
name|ObjCIsaExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCIsaExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|void
name|setBase
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Base
operator|=
name|E
block|; }
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
name|void
name|setArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
comment|/// getMemberLoc - Return the location of the "member", in X->F, it is the
comment|/// location of 'F'.
name|SourceLocation
name|getIsaMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|IsaMemberLoc
return|;
block|}
name|void
name|setIsaMemberLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|IsaMemberLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getOpLoc
argument_list|()
specifier|const
block|{
return|return
name|OpLoc
return|;
block|}
name|void
name|setOpLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|OpLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getBaseLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getBase
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|IsaMemberLoc
return|;
block|}
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|IsaMemberLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCIsaExprClass
return|;
block|}
comment|// Iterators
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|Base
argument_list|,
operator|&
name|Base
operator|+
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ObjCIndirectCopyRestoreExpr - Represents the passing of a function
comment|/// argument by indirect copy-restore in ARC.  This is used to support
comment|/// passing indirect arguments with the wrong lifetime, e.g. when
comment|/// passing the address of a __strong local variable to an 'out'
comment|/// parameter.  This expression kind is only valid in an "argument"
comment|/// position to some sort of call expression.
comment|///
comment|/// The parameter must have type 'pointer to T', and the argument must
comment|/// have type 'pointer to U', where T and U agree except possibly in
comment|/// qualification.  If the argument value is null, then a null pointer
comment|/// is passed;  otherwise it points to an object A, and:
comment|/// 1. A temporary object B of type T is initialized, either by
comment|///    zero-initialization (used when initializing an 'out' parameter)
comment|///    or copy-initialization (used when initializing an 'inout'
comment|///    parameter).
comment|/// 2. The address of the temporary is passed to the function.
comment|/// 3. If the call completes normally, A is move-assigned from B.
comment|/// 4. Finally, A is destroyed immediately.
comment|///
comment|/// Currently 'T' must be a retainable object lifetime and must be
comment|/// __autoreleasing;  this qualifier is ignored when initializing
comment|/// the value.
name|class
name|ObjCIndirectCopyRestoreExpr
operator|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|Operand
block|;
comment|// unsigned ObjCIndirectCopyRestoreBits.ShouldCopy : 1;
name|friend
name|class
name|ASTReader
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|void
name|setShouldCopy
argument_list|(
argument|bool shouldCopy
argument_list|)
block|{
name|ObjCIndirectCopyRestoreExprBits
operator|.
name|ShouldCopy
operator|=
name|shouldCopy
block|;   }
name|explicit
name|ObjCIndirectCopyRestoreExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCIndirectCopyRestoreExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|public
operator|:
name|ObjCIndirectCopyRestoreExpr
argument_list|(
argument|Expr *operand
argument_list|,
argument|QualType type
argument_list|,
argument|bool shouldCopy
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCIndirectCopyRestoreExprClass
argument_list|,
name|type
argument_list|,
name|VK_LValue
argument_list|,
name|OK_Ordinary
argument_list|,
name|operand
operator|->
name|isTypeDependent
argument_list|()
argument_list|,
name|operand
operator|->
name|isValueDependent
argument_list|()
argument_list|,
name|operand
operator|->
name|isInstantiationDependent
argument_list|()
argument_list|,
name|operand
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|Operand
argument_list|(
argument|operand
argument_list|)
block|{
name|setShouldCopy
argument_list|(
name|shouldCopy
argument_list|)
block|;   }
name|Expr
operator|*
name|getSubExpr
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Operand
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Operand
operator|)
return|;
block|}
comment|/// shouldCopy - True if we should do the 'copy' part of the
comment|/// copy-restore.  If false, the temporary will be zero-initialized.
name|bool
name|shouldCopy
argument_list|()
specifier|const
block|{
return|return
name|ObjCIndirectCopyRestoreExprBits
operator|.
name|ShouldCopy
return|;
block|}
name|child_range
name|children
argument_list|()
block|{
return|return
name|child_range
argument_list|(
operator|&
name|Operand
argument_list|,
operator|&
name|Operand
operator|+
literal|1
argument_list|)
return|;
block|}
comment|// Source locations are determined by the subexpression.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Operand
operator|->
name|getLocStart
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Operand
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getSubExpr
argument_list|()
operator|->
name|getExprLoc
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *s
argument_list|)
block|{
return|return
name|s
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCIndirectCopyRestoreExprClass
return|;
block|}
expr|}
block|;
comment|/// \brief An Objective-C "bridged" cast expression, which casts between
comment|/// Objective-C pointers and C pointers, transferring ownership in the process.
comment|///
comment|/// \code
comment|/// NSString *str = (__bridge_transfer NSString *)CFCreateString();
comment|/// \endcode
name|class
name|ObjCBridgedCastExpr
operator|:
name|public
name|ExplicitCastExpr
block|{
name|SourceLocation
name|LParenLoc
block|;
name|SourceLocation
name|BridgeKeywordLoc
block|;
name|unsigned
name|Kind
operator|:
literal|2
block|;
name|friend
name|class
name|ASTStmtReader
block|;
name|friend
name|class
name|ASTStmtWriter
block|;
name|public
operator|:
name|ObjCBridgedCastExpr
argument_list|(
argument|SourceLocation LParenLoc
argument_list|,
argument|ObjCBridgeCastKind Kind
argument_list|,
argument|CastKind CK
argument_list|,
argument|SourceLocation BridgeKeywordLoc
argument_list|,
argument|TypeSourceInfo *TSInfo
argument_list|,
argument|Expr *Operand
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
name|ObjCBridgedCastExprClass
argument_list|,
name|TSInfo
operator|->
name|getType
argument_list|()
argument_list|,
name|VK_RValue
argument_list|,
name|CK
argument_list|,
name|Operand
argument_list|,
literal|0
argument_list|,
name|TSInfo
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLoc
argument_list|)
block|,
name|BridgeKeywordLoc
argument_list|(
name|BridgeKeywordLoc
argument_list|)
block|,
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{ }
comment|/// \brief Construct an empty Objective-C bridged cast.
name|explicit
name|ObjCBridgedCastExpr
argument_list|(
argument|EmptyShell Shell
argument_list|)
operator|:
name|ExplicitCastExpr
argument_list|(
argument|ObjCBridgedCastExprClass
argument_list|,
argument|Shell
argument_list|,
literal|0
argument_list|)
block|{ }
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
comment|/// \brief Determine which kind of bridge is being performed via this cast.
name|ObjCBridgeCastKind
name|getBridgeKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ObjCBridgeCastKind
operator|>
operator|(
name|Kind
operator|)
return|;
block|}
comment|/// \brief Retrieve the kind of bridge being performed as a string.
name|StringRef
name|getBridgeKindName
argument_list|()
specifier|const
block|;
comment|/// \brief The location of the bridge keyword.
name|SourceLocation
name|getBridgeKeywordLoc
argument_list|()
specifier|const
block|{
return|return
name|BridgeKeywordLoc
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LParenLoc
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getSubExpr
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCBridgedCastExprClass
return|;
block|}
expr|}
block|;    }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

