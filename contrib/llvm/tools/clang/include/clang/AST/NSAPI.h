begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- NSAPI.h - NSFoundation APIs ----------------------------*- C++ -*-===//
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
name|LLVM_CLANG_AST_NSAPI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_NSAPI_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|QualType
decl_stmt|;
comment|// \brief Provides info and caches identifiers/selectors for NSFoundation API.
name|class
name|NSAPI
block|{
name|public
label|:
name|explicit
name|NSAPI
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
return|return
name|Ctx
return|;
block|}
enum|enum
name|NSClassIdKindKind
block|{
name|ClassId_NSObject
block|,
name|ClassId_NSString
block|,
name|ClassId_NSArray
block|,
name|ClassId_NSMutableArray
block|,
name|ClassId_NSDictionary
block|,
name|ClassId_NSMutableDictionary
block|,
name|ClassId_NSNumber
block|}
enum|;
specifier|static
specifier|const
name|unsigned
name|NumClassIds
init|=
literal|7
decl_stmt|;
enum|enum
name|NSStringMethodKind
block|{
name|NSStr_stringWithString
block|,
name|NSStr_initWithString
block|}
enum|;
specifier|static
specifier|const
name|unsigned
name|NumNSStringMethods
init|=
literal|2
decl_stmt|;
name|IdentifierInfo
modifier|*
name|getNSClassId
argument_list|(
name|NSClassIdKindKind
name|K
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief The Objective-C NSString selectors.
name|Selector
name|getNSStringSelector
argument_list|(
name|NSStringMethodKind
name|MK
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Enumerates the NSArray methods used to generate literals.
enum|enum
name|NSArrayMethodKind
block|{
name|NSArr_array
block|,
name|NSArr_arrayWithArray
block|,
name|NSArr_arrayWithObject
block|,
name|NSArr_arrayWithObjects
block|,
name|NSArr_arrayWithObjectsCount
block|,
name|NSArr_initWithArray
block|,
name|NSArr_initWithObjects
block|,
name|NSArr_objectAtIndex
block|,
name|NSMutableArr_replaceObjectAtIndex
block|}
enum|;
specifier|static
specifier|const
name|unsigned
name|NumNSArrayMethods
init|=
literal|9
decl_stmt|;
comment|/// \brief The Objective-C NSArray selectors.
name|Selector
name|getNSArraySelector
argument_list|(
name|NSArrayMethodKind
name|MK
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return NSArrayMethodKind if \arg Sel is such a selector.
name|llvm
operator|::
name|Optional
operator|<
name|NSArrayMethodKind
operator|>
name|getNSArrayMethodKind
argument_list|(
argument|Selector Sel
argument_list|)
expr_stmt|;
comment|/// \brief Enumerates the NSDictionary methods used to generate literals.
enum|enum
name|NSDictionaryMethodKind
block|{
name|NSDict_dictionary
block|,
name|NSDict_dictionaryWithDictionary
block|,
name|NSDict_dictionaryWithObjectForKey
block|,
name|NSDict_dictionaryWithObjectsForKeys
block|,
name|NSDict_dictionaryWithObjectsForKeysCount
block|,
name|NSDict_dictionaryWithObjectsAndKeys
block|,
name|NSDict_initWithDictionary
block|,
name|NSDict_initWithObjectsAndKeys
block|,
name|NSDict_objectForKey
block|,
name|NSMutableDict_setObjectForKey
block|}
enum|;
specifier|static
specifier|const
name|unsigned
name|NumNSDictionaryMethods
init|=
literal|10
decl_stmt|;
comment|/// \brief The Objective-C NSDictionary selectors.
name|Selector
name|getNSDictionarySelector
argument_list|(
name|NSDictionaryMethodKind
name|MK
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return NSDictionaryMethodKind if \arg Sel is such a selector.
name|llvm
operator|::
name|Optional
operator|<
name|NSDictionaryMethodKind
operator|>
name|getNSDictionaryMethodKind
argument_list|(
argument|Selector Sel
argument_list|)
expr_stmt|;
comment|/// \brief Enumerates the NSNumber methods used to generate literals.
enum|enum
name|NSNumberLiteralMethodKind
block|{
name|NSNumberWithChar
block|,
name|NSNumberWithUnsignedChar
block|,
name|NSNumberWithShort
block|,
name|NSNumberWithUnsignedShort
block|,
name|NSNumberWithInt
block|,
name|NSNumberWithUnsignedInt
block|,
name|NSNumberWithLong
block|,
name|NSNumberWithUnsignedLong
block|,
name|NSNumberWithLongLong
block|,
name|NSNumberWithUnsignedLongLong
block|,
name|NSNumberWithFloat
block|,
name|NSNumberWithDouble
block|,
name|NSNumberWithBool
block|,
name|NSNumberWithInteger
block|,
name|NSNumberWithUnsignedInteger
block|}
enum|;
specifier|static
specifier|const
name|unsigned
name|NumNSNumberLiteralMethods
init|=
literal|15
decl_stmt|;
comment|/// \brief The Objective-C NSNumber selectors used to create NSNumber literals.
comment|/// \param Instance if true it will return the selector for the init* method
comment|/// otherwise it will return the selector for the number* method.
name|Selector
name|getNSNumberLiteralSelector
argument_list|(
name|NSNumberLiteralMethodKind
name|MK
argument_list|,
name|bool
name|Instance
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isNSNumberLiteralSelector
argument_list|(
name|NSNumberLiteralMethodKind
name|MK
argument_list|,
name|Selector
name|Sel
argument_list|)
decl|const
block|{
return|return
name|Sel
operator|==
name|getNSNumberLiteralSelector
argument_list|(
name|MK
argument_list|,
name|false
argument_list|)
operator|||
name|Sel
operator|==
name|getNSNumberLiteralSelector
argument_list|(
name|MK
argument_list|,
name|true
argument_list|)
return|;
block|}
comment|/// \brief Return NSNumberLiteralMethodKind if \arg Sel is such a selector.
name|llvm
operator|::
name|Optional
operator|<
name|NSNumberLiteralMethodKind
operator|>
name|getNSNumberLiteralMethodKind
argument_list|(
argument|Selector Sel
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Determine the appropriate NSNumber factory method kind for a
comment|/// literal of the given type.
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|NSNumberLiteralMethodKind
operator|>
name|getNSNumberFactoryMethodKind
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
name|private
label|:
name|ASTContext
modifier|&
name|Ctx
decl_stmt|;
name|mutable
name|IdentifierInfo
modifier|*
name|ClassIds
index|[
name|NumClassIds
index|]
decl_stmt|;
name|mutable
name|Selector
name|NSStringSelectors
index|[
name|NumNSStringMethods
index|]
decl_stmt|;
comment|/// \brief The selectors for Objective-C NSArray methods.
name|mutable
name|Selector
name|NSArraySelectors
index|[
name|NumNSArrayMethods
index|]
decl_stmt|;
comment|/// \brief The selectors for Objective-C NSDictionary methods.
name|mutable
name|Selector
name|NSDictionarySelectors
index|[
name|NumNSDictionaryMethods
index|]
decl_stmt|;
comment|/// \brief The Objective-C NSNumber selectors used to create NSNumber literals.
name|mutable
name|Selector
name|NSNumberClassSelectors
index|[
name|NumNSNumberLiteralMethods
index|]
decl_stmt|;
name|mutable
name|Selector
name|NSNumberInstanceSelectors
index|[
name|NumNSNumberLiteralMethods
index|]
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_NSAPI_H
end_comment

end_unit

