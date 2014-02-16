begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenTBAA.h - TBAA information for LLVM CodeGen ------*- C++ -*-===//
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
comment|// This is the code that manages TBAA information and defines the TBAA policy
end_comment

begin_comment
comment|// for the optimizer to use.
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
name|CLANG_CODEGEN_CODEGENTBAA_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CODEGENTBAA_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/MDBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|MangleContext
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGRecordLayout
decl_stmt|;
struct|struct
name|TBAAPathTag
block|{
name|TBAAPathTag
argument_list|(
argument|const Type *B
argument_list|,
argument|const llvm::MDNode *A
argument_list|,
argument|uint64_t O
argument_list|)
block|:
name|BaseT
argument_list|(
name|B
argument_list|)
operator|,
name|AccessN
argument_list|(
name|A
argument_list|)
operator|,
name|Offset
argument_list|(
argument|O
argument_list|)
block|{}
specifier|const
name|Type
operator|*
name|BaseT
expr_stmt|;
specifier|const
name|llvm
operator|::
name|MDNode
operator|*
name|AccessN
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
comment|/// CodeGenTBAA - This class organizes the cross-module state that is used
comment|/// while lowering AST types to LLVM types.
name|class
name|CodeGenTBAA
block|{
name|ASTContext
modifier|&
name|Context
decl_stmt|;
specifier|const
name|CodeGenOptions
modifier|&
name|CodeGenOpts
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|Features
decl_stmt|;
name|MangleContext
modifier|&
name|MContext
decl_stmt|;
comment|// MDHelper - Helper for creating metadata.
name|llvm
operator|::
name|MDBuilder
name|MDHelper
expr_stmt|;
comment|/// MetadataCache - This maps clang::Types to scalar llvm::MDNodes describing
comment|/// them.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|llvm
operator|::
name|MDNode
operator|*
operator|>
name|MetadataCache
expr_stmt|;
comment|/// This maps clang::Types to a struct node in the type DAG.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|llvm
operator|::
name|MDNode
operator|*
operator|>
name|StructTypeMetadataCache
expr_stmt|;
comment|/// This maps TBAAPathTags to a tag node.
name|llvm
operator|::
name|DenseMap
operator|<
name|TBAAPathTag
operator|,
name|llvm
operator|::
name|MDNode
operator|*
operator|>
name|StructTagMetadataCache
expr_stmt|;
comment|/// This maps a scalar type to a scalar tag node.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|llvm
operator|::
name|MDNode
operator|*
operator|,
name|llvm
operator|::
name|MDNode
operator|*
operator|>
name|ScalarTagMetadataCache
expr_stmt|;
comment|/// StructMetadataCache - This maps clang::Types to llvm::MDNodes describing
comment|/// them for struct assignments.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|llvm
operator|::
name|MDNode
operator|*
operator|>
name|StructMetadataCache
expr_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|Root
expr_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|Char
expr_stmt|;
comment|/// getRoot - This is the mdnode for the root of the metadata type graph
comment|/// for this translation unit.
name|llvm
operator|::
name|MDNode
operator|*
name|getRoot
argument_list|()
expr_stmt|;
comment|/// getChar - This is the mdnode for "char", which is special, and any types
comment|/// considered to be equivalent to it.
name|llvm
operator|::
name|MDNode
operator|*
name|getChar
argument_list|()
expr_stmt|;
comment|/// CollectFields - Collect information about the fields of a type for
comment|/// !tbaa.struct metadata formation. Return false for an unsupported type.
name|bool
name|CollectFields
argument_list|(
name|uint64_t
name|BaseOffset
argument_list|,
name|QualType
name|Ty
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|MDBuilder
operator|::
name|TBAAStructField
operator|>
operator|&
name|Fields
argument_list|,
name|bool
name|MayAlias
argument_list|)
decl_stmt|;
comment|/// A wrapper function to create a scalar type. For struct-path aware TBAA,
comment|/// the scalar type has the same format as the struct type: name, offset,
comment|/// pointer to another node in the type DAG.
name|llvm
operator|::
name|MDNode
operator|*
name|createTBAAScalarType
argument_list|(
argument|StringRef Name
argument_list|,
argument|llvm::MDNode *Parent
argument_list|)
expr_stmt|;
name|public
label|:
name|CodeGenTBAA
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|llvm
operator|::
name|LLVMContext
operator|&
name|VMContext
argument_list|,
specifier|const
name|CodeGenOptions
operator|&
name|CGO
argument_list|,
specifier|const
name|LangOptions
operator|&
name|Features
argument_list|,
name|MangleContext
operator|&
name|MContext
argument_list|)
expr_stmt|;
operator|~
name|CodeGenTBAA
argument_list|()
expr_stmt|;
comment|/// getTBAAInfo - Get the TBAA MDNode to be used for a dereference
comment|/// of the given type.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAInfo
argument_list|(
argument|QualType QTy
argument_list|)
expr_stmt|;
comment|/// getTBAAInfoForVTablePtr - Get the TBAA MDNode to be used for a
comment|/// dereference of a vtable pointer.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAInfoForVTablePtr
argument_list|()
expr_stmt|;
comment|/// getTBAAStructInfo - Get the TBAAStruct MDNode to be used for a memcpy of
comment|/// the given type.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAStructInfo
argument_list|(
argument|QualType QTy
argument_list|)
expr_stmt|;
comment|/// Get the MDNode in the type DAG for given struct type QType.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAStructTypeInfo
argument_list|(
argument|QualType QType
argument_list|)
expr_stmt|;
comment|/// Get the tag MDNode for a given base type, the actual scalar access MDNode
comment|/// and offset into the base type.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAStructTagInfo
argument_list|(
argument|QualType BaseQType
argument_list|,
argument|llvm::MDNode *AccessNode
argument_list|,
argument|uint64_t Offset
argument_list|)
expr_stmt|;
comment|/// Get the scalar tag MDNode for a given scalar type.
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAScalarTagInfo
argument_list|(
name|llvm
operator|::
name|MDNode
operator|*
name|AccessNode
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|CodeGen
operator|::
name|TBAAPathTag
operator|>
block|{
specifier|static
name|clang
operator|::
name|CodeGen
operator|::
name|TBAAPathTag
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CodeGen
operator|::
name|TBAAPathTag
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|Type
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
name|DenseMapInfo
operator|<
specifier|const
name|MDNode
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|clang
operator|::
name|CodeGen
operator|::
name|TBAAPathTag
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CodeGen
operator|::
name|TBAAPathTag
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|Type
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
name|DenseMapInfo
operator|<
specifier|const
name|MDNode
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const clang::CodeGen::TBAAPathTag&Val
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|Type
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|BaseT
argument_list|)
operator|^
name|DenseMapInfo
operator|<
specifier|const
name|MDNode
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|AccessN
argument_list|)
operator|^
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|Offset
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const clang::CodeGen::TBAAPathTag&LHS
argument_list|,
argument|const clang::CodeGen::TBAAPathTag&RHS
argument_list|)
block|{
return|return
name|LHS
operator|.
name|BaseT
operator|==
name|RHS
operator|.
name|BaseT
operator|&&
name|LHS
operator|.
name|AccessN
operator|==
name|RHS
operator|.
name|AccessN
operator|&&
name|LHS
operator|.
name|Offset
operator|==
name|RHS
operator|.
name|Offset
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

