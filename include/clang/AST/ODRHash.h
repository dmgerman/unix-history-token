begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ODRHash.h - Hashing to diagnose ODR failures ------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file contains the declaration of the ODRHash class, which calculates
end_comment

begin_comment
comment|/// a hash based on AST nodes, which is stable across different runs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
comment|// ODRHash is used to calculate a hash based on AST node contents that
comment|// does not rely on pointer addresses.  This allows the hash to not vary
comment|// between runs and is usable to detect ODR problems in modules.  To use,
comment|// construct an ODRHash object, then call Add* methods over the nodes that
comment|// need to be hashed.  Then call CalculateHash to get the hash value.
comment|// Typically, only one Add* call is needed.  clear can be called to reuse the
comment|// object.
name|class
name|ODRHash
block|{
comment|// Use DenseMaps to convert between Decl and Type pointers and an index value.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|unsigned
operator|>
name|DeclMap
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|unsigned
operator|>
name|TypeMap
expr_stmt|;
comment|// Save space by processing bools at the end.
name|llvm
operator|::
name|SmallVector
operator|<
name|bool
operator|,
literal|128
operator|>
name|Bools
expr_stmt|;
name|llvm
operator|::
name|FoldingSetNodeID
name|ID
expr_stmt|;
name|public
label|:
name|ODRHash
argument_list|()
block|{}
comment|// Use this for ODR checking classes between modules.  This method compares
comment|// more information than the AddDecl class.
name|void
name|AddCXXRecordDecl
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
comment|// Process SubDecls of the main Decl.  This method calls the DeclVisitor
comment|// while AddDecl does not.
name|void
name|AddSubDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|// Reset the object for reuse.
name|void
name|clear
parameter_list|()
function_decl|;
comment|// Add booleans to ID and uses it to calculate the hash.
name|unsigned
name|CalculateHash
parameter_list|()
function_decl|;
comment|// Add AST nodes that need to be processed.
name|void
name|AddDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|AddType
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|)
function_decl|;
name|void
name|AddQualType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|void
name|AddStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|AddIdentifierInfo
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
name|void
name|AddNestedNameSpecifier
parameter_list|(
specifier|const
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|)
function_decl|;
name|void
name|AddTemplateName
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
function_decl|;
name|void
name|AddDeclarationName
parameter_list|(
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
name|void
name|AddTemplateArgument
parameter_list|(
name|TemplateArgument
name|TA
parameter_list|)
function_decl|;
name|void
name|AddTemplateParameterList
parameter_list|(
specifier|const
name|TemplateParameterList
modifier|*
name|TPL
parameter_list|)
function_decl|;
comment|// Save booleans until the end to lower the size of data to process.
name|void
name|AddBoolean
parameter_list|(
name|bool
name|value
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isWhitelistedDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

end_unit

