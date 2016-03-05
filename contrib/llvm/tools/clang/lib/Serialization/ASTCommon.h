begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASTCommon.h - Common stuff for ASTReader/ASTWriter -*- C++ -*-=========//
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
comment|//  This file defines common functions that both ASTReader and ASTWriter use.
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
name|LLVM_CLANG_LIB_SERIALIZATION_ASTCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_SERIALIZATION_ASTCOMMON_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclFriend.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|serialization
block|{
enum|enum
name|DeclUpdateKind
block|{
name|UPD_CXX_ADDED_IMPLICIT_MEMBER
block|,
name|UPD_CXX_ADDED_TEMPLATE_SPECIALIZATION
block|,
name|UPD_CXX_ADDED_ANONYMOUS_NAMESPACE
block|,
name|UPD_CXX_ADDED_FUNCTION_DEFINITION
block|,
name|UPD_CXX_INSTANTIATED_STATIC_DATA_MEMBER
block|,
name|UPD_CXX_INSTANTIATED_CLASS_DEFINITION
block|,
name|UPD_CXX_INSTANTIATED_DEFAULT_ARGUMENT
block|,
name|UPD_CXX_RESOLVED_DTOR_DELETE
block|,
name|UPD_CXX_RESOLVED_EXCEPTION_SPEC
block|,
name|UPD_CXX_DEDUCED_RETURN_TYPE
block|,
name|UPD_DECL_MARKED_USED
block|,
name|UPD_MANGLING_NUMBER
block|,
name|UPD_STATIC_LOCAL_NUMBER
block|,
name|UPD_DECL_MARKED_OPENMP_THREADPRIVATE
block|,
name|UPD_DECL_EXPORTED
block|,
name|UPD_ADDED_ATTR_TO_RECORD
block|}
enum|;
name|TypeIdx
name|TypeIdxFromBuiltin
parameter_list|(
specifier|const
name|BuiltinType
modifier|*
name|BT
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|IdxForTypeTy
operator|>
name|TypeID
name|MakeTypeID
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|QualType T
argument_list|,
argument|IdxForTypeTy IdxForType
argument_list|)
block|{
if|if
condition|(
name|T
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|PREDEF_TYPE_NULL_ID
return|;
name|unsigned
name|FastQuals
operator|=
name|T
operator|.
name|getLocalFastQualifiers
argument_list|()
expr_stmt|;
name|T
operator|.
name|removeLocalFastQualifiers
argument_list|()
expr_stmt|;
if|if
condition|(
name|T
operator|.
name|hasLocalNonFastQualifiers
argument_list|()
condition|)
return|return
name|IdxForType
argument_list|(
name|T
argument_list|)
operator|.
name|asTypeID
argument_list|(
name|FastQuals
argument_list|)
return|;
name|assert
argument_list|(
operator|!
name|T
operator|.
name|hasLocalQualifiers
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|BuiltinType
modifier|*
name|BT
init|=
name|dyn_cast
operator|<
name|BuiltinType
operator|>
operator|(
name|T
operator|.
name|getTypePtr
argument_list|()
operator|)
condition|)
return|return
name|TypeIdxFromBuiltin
argument_list|(
name|BT
argument_list|)
operator|.
name|asTypeID
argument_list|(
name|FastQuals
argument_list|)
return|;
if|if
condition|(
name|T
operator|==
name|Context
operator|.
name|AutoDeductTy
condition|)
return|return
name|TypeIdx
argument_list|(
name|PREDEF_TYPE_AUTO_DEDUCT
argument_list|)
operator|.
name|asTypeID
argument_list|(
name|FastQuals
argument_list|)
return|;
if|if
condition|(
name|T
operator|==
name|Context
operator|.
name|AutoRRefDeductTy
condition|)
return|return
name|TypeIdx
argument_list|(
name|PREDEF_TYPE_AUTO_RREF_DEDUCT
argument_list|)
operator|.
name|asTypeID
argument_list|(
name|FastQuals
argument_list|)
return|;
return|return
name|IdxForType
argument_list|(
name|T
argument_list|)
operator|.
name|asTypeID
argument_list|(
name|FastQuals
argument_list|)
return|;
block|}
name|unsigned
name|ComputeHash
parameter_list|(
name|Selector
name|Sel
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the "definitive" declaration that provides all of the
comment|/// visible entries for the given declaration context, if there is one.
comment|///
comment|/// The "definitive" declaration is the only place where we need to look to
comment|/// find information about the declarations within the given declaration
comment|/// context. For example, C++ and Objective-C classes, C structs/unions, and
comment|/// Objective-C protocols, categories, and extensions are all defined in a
comment|/// single place in the source code, so they have definitive declarations
comment|/// associated with them. C++ namespaces, on the other hand, can have
comment|/// multiple definitions.
specifier|const
name|DeclContext
modifier|*
name|getDefinitiveDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
comment|/// \brief Determine whether the given declaration kind is redeclarable.
name|bool
name|isRedeclarableDeclKind
parameter_list|(
name|unsigned
name|Kind
parameter_list|)
function_decl|;
comment|/// \brief Determine whether the given declaration needs an anonymous
comment|/// declaration number.
name|bool
name|needsAnonymousDeclarationNumber
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Visit each declaration within \c DC that needs an anonymous
comment|/// declaration number and call \p Visit with the declaration and its number.
name|template
operator|<
name|typename
name|Fn
operator|>
name|void
name|numberAnonymousDeclsWithin
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|Fn Visit
argument_list|)
block|{
name|unsigned
name|Index
operator|=
literal|0
block|;
for|for
control|(
name|Decl
modifier|*
name|LexicalD
range|:
name|DC
operator|->
name|decls
argument_list|()
control|)
block|{
comment|// For a friend decl, we care about the declaration within it, if any.
if|if
condition|(
name|auto
operator|*
name|FD
operator|=
name|dyn_cast
operator|<
name|FriendDecl
operator|>
operator|(
name|LexicalD
operator|)
condition|)
name|LexicalD
operator|=
name|FD
operator|->
name|getFriendDecl
argument_list|()
expr_stmt|;
name|auto
operator|*
name|ND
operator|=
name|dyn_cast_or_null
operator|<
name|NamedDecl
operator|>
operator|(
name|LexicalD
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|ND
operator|||
operator|!
name|needsAnonymousDeclarationNumber
argument_list|(
name|ND
argument_list|)
condition|)
continue|continue;
name|Visit
argument_list|(
name|ND
argument_list|,
name|Index
operator|++
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace serialization
end_comment

begin_comment
unit|}
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

