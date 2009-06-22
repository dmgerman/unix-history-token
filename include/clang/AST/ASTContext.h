begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTContext.h - Context to hold long-lived AST nodes ----*- C++ -*-===//
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
comment|//  This file defines the ASTContext interface.
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
name|LLVM_CLANG_AST_ASTCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/NestedNameSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/PrettyPrinter.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|fltSemantics
struct_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FileManager
decl_stmt|;
name|class
name|ASTRecordLayout
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|ExternalASTSource
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|SelectorTable
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
comment|// Decls
name|class
name|Decl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|TranslationUnitDecl
decl_stmt|;
name|class
name|TypeDecl
decl_stmt|;
name|class
name|TypedefDecl
decl_stmt|;
name|class
name|TemplateTypeParmDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|ObjCIvarRefExpr
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|namespace
name|Builtin
block|{
name|class
name|Context
decl_stmt|;
block|}
comment|/// ASTContext - This class holds long-lived AST nodes (such as types and
comment|/// decls) that can be referred to throughout the semantic analysis of a file.
name|class
name|ASTContext
block|{
name|std
operator|::
name|vector
operator|<
name|Type
operator|*
operator|>
name|Types
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|ExtQualType
operator|>
name|ExtQualTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|ComplexType
operator|>
name|ComplexTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|PointerType
operator|>
name|PointerTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|BlockPointerType
operator|>
name|BlockPointerTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|LValueReferenceType
operator|>
name|LValueReferenceTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|RValueReferenceType
operator|>
name|RValueReferenceTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|MemberPointerType
operator|>
name|MemberPointerTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|ConstantArrayType
operator|>
name|ConstantArrayTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|IncompleteArrayType
operator|>
name|IncompleteArrayTypes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|VariableArrayType
operator|*
operator|>
name|VariableArrayTypes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|DependentSizedArrayType
operator|*
operator|>
name|DependentSizedArrayTypes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|DependentSizedExtVectorType
operator|*
operator|>
name|DependentSizedExtVectorTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|VectorType
operator|>
name|VectorTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionNoProtoType
operator|>
name|FunctionNoProtoTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionProtoType
operator|>
name|FunctionProtoTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|TemplateTypeParmType
operator|>
name|TemplateTypeParmTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|TemplateSpecializationType
operator|>
name|TemplateSpecializationTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|QualifiedNameType
operator|>
name|QualifiedNameTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|TypenameType
operator|>
name|TypenameTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|ObjCQualifiedInterfaceType
operator|>
name|ObjCQualifiedInterfaceTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|ObjCObjectPointerType
operator|>
name|ObjCObjectPointerTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|QualifiedTemplateName
operator|>
name|QualifiedTemplateNames
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentTemplateName
operator|>
name|DependentTemplateNames
expr_stmt|;
comment|/// \brief The set of nested name specifiers.
comment|///
comment|/// This set is managed by the NestedNameSpecifier class.
name|llvm
operator|::
name|FoldingSet
operator|<
name|NestedNameSpecifier
operator|>
name|NestedNameSpecifiers
expr_stmt|;
name|NestedNameSpecifier
modifier|*
name|GlobalNestedNameSpecifier
decl_stmt|;
name|friend
name|class
name|NestedNameSpecifier
decl_stmt|;
comment|/// ASTRecordLayouts - A cache mapping from RecordDecls to ASTRecordLayouts.
comment|///  This is lazily created.  This is intentionally not serialized.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|RecordDecl
operator|*
operator|,
specifier|const
name|ASTRecordLayout
operator|*
operator|>
name|ASTRecordLayouts
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ObjCContainerDecl
operator|*
operator|,
specifier|const
name|ASTRecordLayout
operator|*
operator|>
name|ObjCLayouts
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|FixedWidthIntType
operator|*
operator|>
name|SignedFixedWidthIntTypes
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|FixedWidthIntType
operator|*
operator|>
name|UnsignedFixedWidthIntTypes
expr_stmt|;
comment|/// BuiltinVaListType - built-in va list type.
comment|/// This is initially null and set by Sema::LazilyCreateBuiltin when
comment|/// a builtin that takes a valist is encountered.
name|QualType
name|BuiltinVaListType
decl_stmt|;
comment|/// ObjCIdType - a pseudo built-in typedef type (set by Sema).
name|QualType
name|ObjCIdType
decl_stmt|;
specifier|const
name|RecordType
modifier|*
name|IdStructType
decl_stmt|;
comment|/// ObjCSelType - another pseudo built-in typedef type (set by Sema).
name|QualType
name|ObjCSelType
decl_stmt|;
specifier|const
name|RecordType
modifier|*
name|SelStructType
decl_stmt|;
comment|/// ObjCProtoType - another pseudo built-in typedef type (set by Sema).
name|QualType
name|ObjCProtoType
decl_stmt|;
specifier|const
name|RecordType
modifier|*
name|ProtoStructType
decl_stmt|;
comment|/// ObjCClassType - another pseudo built-in typedef type (set by Sema).
name|QualType
name|ObjCClassType
decl_stmt|;
specifier|const
name|RecordType
modifier|*
name|ClassStructType
decl_stmt|;
name|QualType
name|ObjCConstantStringType
decl_stmt|;
name|RecordDecl
modifier|*
name|CFConstantStringTypeDecl
decl_stmt|;
name|RecordDecl
modifier|*
name|ObjCFastEnumerationStateTypeDecl
decl_stmt|;
comment|/// \brief Keeps track of all declaration attributes.
comment|///
comment|/// Since so few decls have attrs, we keep them in a hash map instead of
comment|/// wasting space in the Decl class.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|Attr
operator|*
operator|>
name|DeclAttrs
expr_stmt|;
name|TranslationUnitDecl
modifier|*
name|TUDecl
decl_stmt|;
comment|/// SourceMgr - The associated SourceManager object.
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
comment|/// LangOpts - The language options used to create the AST associated with
comment|///  this ASTContext object.
name|LangOptions
name|LangOpts
decl_stmt|;
comment|/// MallocAlloc/BumpAlloc - The allocator objects used to create AST objects.
name|bool
name|FreeMemory
decl_stmt|;
name|llvm
operator|::
name|MallocAllocator
name|MallocAlloc
expr_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|BumpAlloc
expr_stmt|;
name|public
label|:
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|IdentifierTable
modifier|&
name|Idents
decl_stmt|;
name|SelectorTable
modifier|&
name|Selectors
decl_stmt|;
name|Builtin
operator|::
name|Context
operator|&
name|BuiltinInfo
expr_stmt|;
name|DeclarationNameTable
name|DeclarationNames
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|ExternalASTSource
operator|>
name|ExternalSource
expr_stmt|;
name|clang
operator|::
name|PrintingPolicy
name|PrintingPolicy
expr_stmt|;
name|SourceManager
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
name|SourceMgr
return|;
block|}
specifier|const
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
return|;
block|}
name|void
modifier|*
name|Allocate
parameter_list|(
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|Align
init|=
literal|8
parameter_list|)
block|{
return|return
name|FreeMemory
condition|?
name|MallocAlloc
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
else|:
name|BumpAlloc
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
return|;
block|}
name|void
name|Deallocate
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
if|if
condition|(
name|FreeMemory
condition|)
name|MallocAlloc
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOptions
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
name|FullSourceLoc
name|getFullLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|FullSourceLoc
argument_list|(
name|Loc
argument_list|,
name|SourceMgr
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the attributes for the given declaration.
name|Attr
modifier|*
modifier|&
name|getDeclAttrs
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|DeclAttrs
index|[
name|D
index|]
return|;
block|}
comment|/// \brief Erase the attributes corresponding to the given declaration.
name|void
name|eraseDeclAttrs
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|DeclAttrs
operator|.
name|erase
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|TranslationUnitDecl
operator|*
name|getTranslationUnitDecl
argument_list|()
specifier|const
block|{
return|return
name|TUDecl
return|;
block|}
comment|// Builtin Types.
name|QualType
name|VoidTy
decl_stmt|;
name|QualType
name|BoolTy
decl_stmt|;
name|QualType
name|CharTy
decl_stmt|;
name|QualType
name|WCharTy
decl_stmt|;
comment|// [C++ 3.9.1p5], integer type in C99.
name|QualType
name|SignedCharTy
decl_stmt|,
name|ShortTy
decl_stmt|,
name|IntTy
decl_stmt|,
name|LongTy
decl_stmt|,
name|LongLongTy
decl_stmt|,
name|Int128Ty
decl_stmt|;
name|QualType
name|UnsignedCharTy
decl_stmt|,
name|UnsignedShortTy
decl_stmt|,
name|UnsignedIntTy
decl_stmt|,
name|UnsignedLongTy
decl_stmt|;
name|QualType
name|UnsignedLongLongTy
decl_stmt|,
name|UnsignedInt128Ty
decl_stmt|;
name|QualType
name|FloatTy
decl_stmt|,
name|DoubleTy
decl_stmt|,
name|LongDoubleTy
decl_stmt|;
name|QualType
name|FloatComplexTy
decl_stmt|,
name|DoubleComplexTy
decl_stmt|,
name|LongDoubleComplexTy
decl_stmt|;
name|QualType
name|VoidPtrTy
decl_stmt|,
name|NullPtrTy
decl_stmt|;
name|QualType
name|OverloadTy
decl_stmt|;
name|QualType
name|DependentTy
decl_stmt|;
name|ASTContext
argument_list|(
argument|const LangOptions& LOpts
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|TargetInfo&t
argument_list|,
argument|IdentifierTable&idents
argument_list|,
argument|SelectorTable&sels
argument_list|,
argument|Builtin::Context&builtins
argument_list|,
argument|bool FreeMemory = true
argument_list|,
argument|unsigned size_reserve=
literal|0
argument_list|)
empty_stmt|;
operator|~
name|ASTContext
argument_list|()
expr_stmt|;
comment|/// \brief Attach an external AST source to the AST context.
comment|///
comment|/// The external AST source provides the ability to load parts of
comment|/// the abstract syntax tree as needed from some external storage,
comment|/// e.g., a precompiled header.
name|void
name|setExternalSource
argument_list|(
name|llvm
operator|::
name|OwningPtr
operator|<
name|ExternalASTSource
operator|>
operator|&
name|Source
argument_list|)
decl_stmt|;
comment|/// \brief Retrieve a pointer to the external AST source associated
comment|/// with this AST context, if any.
name|ExternalASTSource
operator|*
name|getExternalSource
argument_list|()
specifier|const
block|{
return|return
name|ExternalSource
operator|.
name|get
argument_list|()
return|;
block|}
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|Type
operator|*
operator|>
operator|&
name|getTypes
argument_list|()
specifier|const
block|{
return|return
name|Types
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//                           Type Constructors
comment|//===--------------------------------------------------------------------===//
comment|/// getAddSpaceQualType - Return the uniqued reference to the type for an
comment|/// address space qualified type with the specified type and address space.
comment|/// The resulting type has a union of the qualifiers from T and the address
comment|/// space. If T already has an address space specifier, it is silently
comment|/// replaced.
name|QualType
name|getAddrSpaceQualType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|unsigned
name|AddressSpace
parameter_list|)
function_decl|;
comment|/// getObjCGCQualType - Returns the uniqued reference to the type for an
comment|/// objc gc qualified type. The retulting type has a union of the qualifiers
comment|/// from T and the gc attribute.
name|QualType
name|getObjCGCQualType
argument_list|(
name|QualType
name|T
argument_list|,
name|QualType
operator|::
name|GCAttrTypes
name|gcAttr
argument_list|)
decl_stmt|;
comment|/// getComplexType - Return the uniqued reference to the type for a complex
comment|/// number with the specified element type.
name|QualType
name|getComplexType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getPointerType - Return the uniqued reference to the type for a pointer to
comment|/// the specified type.
name|QualType
name|getPointerType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getBlockPointerType - Return the uniqued reference to the type for a block
comment|/// of the specified type.
name|QualType
name|getBlockPointerType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getLValueReferenceType - Return the uniqued reference to the type for an
comment|/// lvalue reference to the specified type.
name|QualType
name|getLValueReferenceType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getRValueReferenceType - Return the uniqued reference to the type for an
comment|/// rvalue reference to the specified type.
name|QualType
name|getRValueReferenceType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getMemberPointerType - Return the uniqued reference to the type for a
comment|/// member pointer to the specified type in the specified class. The class
comment|/// is a Type because it could be a dependent name.
name|QualType
name|getMemberPointerType
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|Type
modifier|*
name|Cls
parameter_list|)
function_decl|;
comment|/// getVariableArrayType - Returns a non-unique reference to the type for a
comment|/// variable array of the specified element type.
name|QualType
name|getVariableArrayType
argument_list|(
name|QualType
name|EltTy
argument_list|,
name|Expr
operator|*
name|NumElts
argument_list|,
name|ArrayType
operator|::
name|ArraySizeModifier
name|ASM
argument_list|,
name|unsigned
name|EltTypeQuals
argument_list|)
decl_stmt|;
comment|/// getDependentSizedArrayType - Returns a non-unique reference to
comment|/// the type for a dependently-sized array of the specified element
comment|/// type. FIXME: We will need these to be uniqued, or at least
comment|/// comparable, at some point.
name|QualType
name|getDependentSizedArrayType
argument_list|(
name|QualType
name|EltTy
argument_list|,
name|Expr
operator|*
name|NumElts
argument_list|,
name|ArrayType
operator|::
name|ArraySizeModifier
name|ASM
argument_list|,
name|unsigned
name|EltTypeQuals
argument_list|)
decl_stmt|;
comment|/// getIncompleteArrayType - Returns a unique reference to the type for a
comment|/// incomplete array of the specified element type.
name|QualType
name|getIncompleteArrayType
argument_list|(
name|QualType
name|EltTy
argument_list|,
name|ArrayType
operator|::
name|ArraySizeModifier
name|ASM
argument_list|,
name|unsigned
name|EltTypeQuals
argument_list|)
decl_stmt|;
comment|/// getConstantArrayType - Return the unique reference to the type for a
comment|/// constant array of the specified element type.
name|QualType
name|getConstantArrayType
argument_list|(
name|QualType
name|EltTy
argument_list|,
specifier|const
name|llvm
operator|::
name|APInt
operator|&
name|ArySize
argument_list|,
name|ArrayType
operator|::
name|ArraySizeModifier
name|ASM
argument_list|,
name|unsigned
name|EltTypeQuals
argument_list|)
decl_stmt|;
comment|/// getVectorType - Return the unique reference to a vector type of
comment|/// the specified element type and size. VectorType must be a built-in type.
name|QualType
name|getVectorType
parameter_list|(
name|QualType
name|VectorType
parameter_list|,
name|unsigned
name|NumElts
parameter_list|)
function_decl|;
comment|/// getExtVectorType - Return the unique reference to an extended vector type
comment|/// of the specified element type and size.  VectorType must be a built-in
comment|/// type.
name|QualType
name|getExtVectorType
parameter_list|(
name|QualType
name|VectorType
parameter_list|,
name|unsigned
name|NumElts
parameter_list|)
function_decl|;
comment|/// getDependentSizedExtVectorType - Returns a non-unique reference to
comment|/// the type for a dependently-sized vector of the specified element
comment|/// type. FIXME: We will need these to be uniqued, or at least
comment|/// comparable, at some point.
name|QualType
name|getDependentSizedExtVectorType
parameter_list|(
name|QualType
name|VectorType
parameter_list|,
name|Expr
modifier|*
name|SizeExpr
parameter_list|,
name|SourceLocation
name|AttrLoc
parameter_list|)
function_decl|;
comment|/// getFunctionNoProtoType - Return a K&R style C function type like 'int()'.
comment|///
name|QualType
name|getFunctionNoProtoType
parameter_list|(
name|QualType
name|ResultTy
parameter_list|)
function_decl|;
comment|/// getFunctionType - Return a normal function type with a typed argument
comment|/// list.  isVariadic indicates whether the argument list includes '...'.
name|QualType
name|getFunctionType
parameter_list|(
name|QualType
name|ResultTy
parameter_list|,
specifier|const
name|QualType
modifier|*
name|ArgArray
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|bool
name|isVariadic
parameter_list|,
name|unsigned
name|TypeQuals
parameter_list|,
name|bool
name|hasExceptionSpec
init|=
name|false
parameter_list|,
name|bool
name|hasAnyExceptionSpec
init|=
name|false
parameter_list|,
name|unsigned
name|NumExs
init|=
literal|0
parameter_list|,
specifier|const
name|QualType
modifier|*
name|ExArray
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getTypeDeclType - Return the unique reference to the type for
comment|/// the specified type declaration.
name|QualType
name|getTypeDeclType
parameter_list|(
name|TypeDecl
modifier|*
name|Decl
parameter_list|,
name|TypeDecl
modifier|*
name|PrevDecl
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getTypedefType - Return the unique reference to the type for the
comment|/// specified typename decl.
name|QualType
name|getTypedefType
parameter_list|(
name|TypedefDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
name|QualType
name|getObjCInterfaceType
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
name|QualType
name|getTemplateTypeParmType
parameter_list|(
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Index
parameter_list|,
name|bool
name|ParameterPack
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
init|=
literal|0
parameter_list|)
function_decl|;
name|QualType
name|getTemplateSpecializationType
parameter_list|(
name|TemplateName
name|T
parameter_list|,
specifier|const
name|TemplateArgument
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|QualType
name|Canon
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
name|QualType
name|getQualifiedNameType
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
name|QualType
name|NamedType
parameter_list|)
function_decl|;
name|QualType
name|getTypenameType
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|QualType
name|Canon
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
name|QualType
name|getTypenameType
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
specifier|const
name|TemplateSpecializationType
modifier|*
name|TemplateId
parameter_list|,
name|QualType
name|Canon
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
comment|/// getObjCObjectPointerType - Return a ObjCObjectPointerType type for the
comment|/// given interface decl and the conforming protocol list.
name|QualType
name|getObjCObjectPointerType
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|,
name|ObjCProtocolDecl
modifier|*
modifier|*
name|ProtocolList
init|=
literal|0
parameter_list|,
name|unsigned
name|NumProtocols
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getObjCQualifiedInterfaceType - Return a
comment|/// ObjCQualifiedInterfaceType type for the given interface decl and
comment|/// the conforming protocol list.
name|QualType
name|getObjCQualifiedInterfaceType
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|,
name|ObjCProtocolDecl
modifier|*
modifier|*
name|ProtocolList
parameter_list|,
name|unsigned
name|NumProtocols
parameter_list|)
function_decl|;
comment|/// getObjCQualifiedIdType - Return an ObjCQualifiedIdType for a
comment|/// given 'id' and conforming protocol list.
name|QualType
name|getObjCQualifiedIdType
parameter_list|(
name|ObjCProtocolDecl
modifier|*
modifier|*
name|ProtocolList
parameter_list|,
name|unsigned
name|NumProtocols
parameter_list|)
function_decl|;
comment|/// getTypeOfType - GCC extension.
name|QualType
name|getTypeOfExprType
parameter_list|(
name|Expr
modifier|*
name|e
parameter_list|)
function_decl|;
name|QualType
name|getTypeOfType
parameter_list|(
name|QualType
name|t
parameter_list|)
function_decl|;
comment|/// getTagDeclType - Return the unique reference to the type for the
comment|/// specified TagDecl (struct/union/class/enum) decl.
name|QualType
name|getTagDeclType
parameter_list|(
name|TagDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
comment|/// getSizeType - Return the unique type for "size_t" (C99 7.17), defined
comment|/// in<stddef.h>. The sizeof operator requires this (C99 6.5.3.4p4).
name|QualType
name|getSizeType
argument_list|()
specifier|const
expr_stmt|;
comment|/// getWCharType - In C++, this returns the unique wchar_t type.  In C99, this
comment|/// returns a type compatible with the type defined in<stddef.h> as defined
comment|/// by the target.
name|QualType
name|getWCharType
argument_list|()
specifier|const
block|{
return|return
name|WCharTy
return|;
block|}
comment|/// getSignedWCharType - Return the type of "signed wchar_t".
comment|/// Used when in C++, as a GCC extension.
name|QualType
name|getSignedWCharType
argument_list|()
specifier|const
expr_stmt|;
comment|/// getUnsignedWCharType - Return the type of "unsigned wchar_t".
comment|/// Used when in C++, as a GCC extension.
name|QualType
name|getUnsignedWCharType
argument_list|()
specifier|const
expr_stmt|;
comment|/// getPointerDiffType - Return the unique type for "ptrdiff_t" (ref?)
comment|/// defined in<stddef.h>. Pointer - pointer requires this (C99 6.5.6p9).
name|QualType
name|getPointerDiffType
argument_list|()
specifier|const
expr_stmt|;
comment|// getCFConstantStringType - Return the C structure type used to represent
comment|// constant CFStrings.
name|QualType
name|getCFConstantStringType
parameter_list|()
function_decl|;
comment|/// Get the structure type used to representation CFStrings, or NULL
comment|/// if it hasn't yet been built.
name|QualType
name|getRawCFConstantStringType
parameter_list|()
block|{
if|if
condition|(
name|CFConstantStringTypeDecl
condition|)
return|return
name|getTagDeclType
argument_list|(
name|CFConstantStringTypeDecl
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
name|void
name|setCFConstantStringType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|// This setter/getter represents the ObjC type for an NSConstantString.
name|void
name|setObjCConstantStringInterface
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
name|QualType
name|getObjCConstantStringInterface
argument_list|()
specifier|const
block|{
return|return
name|ObjCConstantStringType
return|;
block|}
comment|//// This gets the struct used to keep track of fast enumerations.
name|QualType
name|getObjCFastEnumerationStateType
parameter_list|()
function_decl|;
comment|/// Get the ObjCFastEnumerationState type, or NULL if it hasn't yet
comment|/// been built.
name|QualType
name|getRawObjCFastEnumerationStateType
parameter_list|()
block|{
if|if
condition|(
name|ObjCFastEnumerationStateTypeDecl
condition|)
return|return
name|getTagDeclType
argument_list|(
name|ObjCFastEnumerationStateTypeDecl
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
name|void
name|setObjCFastEnumerationStateType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getObjCEncodingForType - Emit the ObjC type encoding for the
comment|/// given type into \arg S. If \arg NameFields is specified then
comment|/// record field names are also encoded.
name|void
name|getObjCEncodingForType
argument_list|(
name|QualType
name|t
argument_list|,
name|std
operator|::
name|string
operator|&
name|S
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
operator|=
literal|0
argument_list|)
decl_stmt|;
name|void
name|getLegacyIntegralTypeEncoding
argument_list|(
name|QualType
operator|&
name|t
argument_list|)
decl|const
decl_stmt|;
comment|// Put the string version of type qualifiers into S.
name|void
name|getObjCEncodingForTypeQualifier
argument_list|(
name|Decl
operator|::
name|ObjCDeclQualifier
name|QT
argument_list|,
name|std
operator|::
name|string
operator|&
name|S
argument_list|)
decl|const
decl_stmt|;
comment|/// getObjCEncodingForMethodDecl - Return the encoded type for this method
comment|/// declaration.
name|void
name|getObjCEncodingForMethodDecl
argument_list|(
specifier|const
name|ObjCMethodDecl
operator|*
name|Decl
argument_list|,
name|std
operator|::
name|string
operator|&
name|S
argument_list|)
decl_stmt|;
comment|/// getObjCEncodingForPropertyDecl - Return the encoded type for
comment|/// this method declaration. If non-NULL, Container must be either
comment|/// an ObjCCategoryImplDecl or ObjCImplementationDecl; it should
comment|/// only be NULL when getting encodings for protocol properties.
name|void
name|getObjCEncodingForPropertyDecl
argument_list|(
specifier|const
name|ObjCPropertyDecl
operator|*
name|PD
argument_list|,
specifier|const
name|Decl
operator|*
name|Container
argument_list|,
name|std
operator|::
name|string
operator|&
name|S
argument_list|)
decl_stmt|;
comment|/// getObjCEncodingTypeSize returns size of type for objective-c encoding
comment|/// purpose.
name|int
name|getObjCEncodingTypeSize
parameter_list|(
name|QualType
name|t
parameter_list|)
function_decl|;
comment|/// This setter/getter represents the ObjC 'id' type. It is setup lazily, by
comment|/// Sema.  id is always a (typedef for a) pointer type, a pointer to a struct.
name|QualType
name|getObjCIdType
argument_list|()
specifier|const
block|{
return|return
name|ObjCIdType
return|;
block|}
name|void
name|setObjCIdType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|void
name|setObjCSelType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|QualType
name|getObjCSelType
argument_list|()
specifier|const
block|{
return|return
name|ObjCSelType
return|;
block|}
name|void
name|setObjCProtoType
parameter_list|(
name|QualType
name|QT
parameter_list|)
function_decl|;
name|QualType
name|getObjCProtoType
argument_list|()
specifier|const
block|{
return|return
name|ObjCProtoType
return|;
block|}
comment|/// This setter/getter repreents the ObjC 'Class' type. It is setup lazily, by
comment|/// Sema.  'Class' is always a (typedef for a) pointer type, a pointer to a
comment|/// struct.
name|QualType
name|getObjCClassType
argument_list|()
specifier|const
block|{
return|return
name|ObjCClassType
return|;
block|}
name|void
name|setObjCClassType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|void
name|setBuiltinVaListType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|QualType
name|getBuiltinVaListType
argument_list|()
specifier|const
block|{
return|return
name|BuiltinVaListType
return|;
block|}
name|QualType
name|getFixedWidthIntType
parameter_list|(
name|unsigned
name|Width
parameter_list|,
name|bool
name|Signed
parameter_list|)
function_decl|;
name|TemplateName
name|getQualifiedTemplateName
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
name|bool
name|TemplateKeyword
parameter_list|,
name|TemplateDecl
modifier|*
name|Template
parameter_list|)
function_decl|;
name|TemplateName
name|getDependentTemplateName
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Name
parameter_list|)
function_decl|;
enum|enum
name|GetBuiltinTypeError
block|{
name|GE_None
block|,
comment|//< No error
name|GE_Missing_FILE
comment|//< Missing the FILE type from<stdio.h>
block|}
enum|;
comment|/// GetBuiltinType - Return the type for the specified builtin.
name|QualType
name|GetBuiltinType
parameter_list|(
name|unsigned
name|ID
parameter_list|,
name|GetBuiltinTypeError
modifier|&
name|Error
parameter_list|)
function_decl|;
name|private
label|:
name|QualType
name|getFromTargetType
argument_list|(
name|unsigned
name|Type
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//                         Type Predicates.
comment|//===--------------------------------------------------------------------===//
name|public
label|:
comment|/// isObjCObjectPointerType - Returns true if type is an Objective-C pointer
comment|/// to an object type.  This includes "id" and "Class" (two 'special' pointers
comment|/// to struct), Interface* (pointer to ObjCInterfaceType) and id<P> (qualified
comment|/// ID type).
name|bool
name|isObjCObjectPointerType
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getObjCGCAttr - Returns one of GCNone, Weak or Strong objc's
comment|/// garbage collection attribute.
comment|///
name|QualType
operator|::
name|GCAttrTypes
name|getObjCGCAttrKind
argument_list|(
argument|const QualType&Ty
argument_list|)
specifier|const
expr_stmt|;
comment|/// isObjCNSObjectType - Return true if this is an NSObject object with
comment|/// its NSObject attribute set.
name|bool
name|isObjCNSObjectType
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//                         Type Sizing and Analysis
comment|//===--------------------------------------------------------------------===//
comment|/// getFloatTypeSemantics - Return the APFloat 'semantics' for the specified
comment|/// scalar floating point type.
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|getFloatTypeSemantics
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
comment|/// getTypeInfo - Get the size and alignment of the specified complete type in
comment|/// bits.
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|unsigned
operator|>
name|getTypeInfo
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|unsigned
operator|>
name|getTypeInfo
argument_list|(
argument|QualType T
argument_list|)
block|{
return|return
name|getTypeInfo
argument_list|(
name|T
operator|.
name|getTypePtr
argument_list|()
argument_list|)
return|;
block|}
comment|/// getTypeSize - Return the size of the specified type, in bits.  This method
comment|/// does not work on incomplete types.
name|uint64_t
name|getTypeSize
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|getTypeInfo
argument_list|(
name|T
argument_list|)
operator|.
name|first
return|;
block|}
name|uint64_t
name|getTypeSize
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|)
block|{
return|return
name|getTypeInfo
argument_list|(
name|T
argument_list|)
operator|.
name|first
return|;
block|}
comment|/// getTypeAlign - Return the ABI-specified alignment of a type, in bits.
comment|/// This method does not work on incomplete types.
name|unsigned
name|getTypeAlign
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|getTypeInfo
argument_list|(
name|T
argument_list|)
operator|.
name|second
return|;
block|}
name|unsigned
name|getTypeAlign
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|)
block|{
return|return
name|getTypeInfo
argument_list|(
name|T
argument_list|)
operator|.
name|second
return|;
block|}
comment|/// getPreferredTypeAlign - Return the "preferred" alignment of the specified
comment|/// type for the current target in bits.  This can be different than the ABI
comment|/// alignment in cases where it is beneficial for performance to overalign
comment|/// a data type.
name|unsigned
name|getPreferredTypeAlign
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|)
function_decl|;
comment|/// getDeclAlignInBytes - Return the alignment of the specified decl
comment|/// that should be returned by __alignof().  Note that bitfields do
comment|/// not have a valid alignment, so this method will assert on them.
name|unsigned
name|getDeclAlignInBytes
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// getASTRecordLayout - Get or compute information about the layout of the
comment|/// specified record (struct/union/class), which indicates its size and field
comment|/// position information.
specifier|const
name|ASTRecordLayout
modifier|&
name|getASTRecordLayout
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// getASTObjCInterfaceLayout - Get or compute information about the
comment|/// layout of the specified Objective-C interface.
specifier|const
name|ASTRecordLayout
modifier|&
name|getASTObjCInterfaceLayout
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// getASTObjCImplementationLayout - Get or compute information about
comment|/// the layout of the specified Objective-C implementation. This may
comment|/// differ from the interface if synthesized ivars are present.
specifier|const
name|ASTRecordLayout
modifier|&
name|getASTObjCImplementationLayout
parameter_list|(
specifier|const
name|ObjCImplementationDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|CollectObjCIvars
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OI
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|FieldDecl
operator|*
operator|>
operator|&
name|Fields
argument_list|)
decl_stmt|;
name|void
name|ShallowCollectObjCIvars
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OI
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ObjCIvarDecl
operator|*
operator|>
operator|&
name|Ivars
argument_list|,
name|bool
name|CollectSynthesized
operator|=
name|true
argument_list|)
decl_stmt|;
name|void
name|CollectSynthesizedIvars
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OI
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ObjCIvarDecl
operator|*
operator|>
operator|&
name|Ivars
argument_list|)
decl_stmt|;
name|void
name|CollectProtocolSynthesizedIvars
argument_list|(
specifier|const
name|ObjCProtocolDecl
operator|*
name|PD
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ObjCIvarDecl
operator|*
operator|>
operator|&
name|Ivars
argument_list|)
decl_stmt|;
name|unsigned
name|CountSynthesizedIvars
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|OI
parameter_list|)
function_decl|;
name|unsigned
name|CountProtocolSynthesizedIvars
parameter_list|(
specifier|const
name|ObjCProtocolDecl
modifier|*
name|PD
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//                            Type Operators
comment|//===--------------------------------------------------------------------===//
comment|/// getCanonicalType - Return the canonical (structural) type corresponding to
comment|/// the specified potentially non-canonical type.  The non-canonical version
comment|/// of a type may have many "decorated" versions of types.  Decorators can
comment|/// include typedefs, 'typeof' operators, etc. The returned type is guaranteed
comment|/// to be free of any of these, allowing two canonical types to be compared
comment|/// for exact equality with a simple pointer comparison.
name|QualType
name|getCanonicalType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
specifier|const
name|Type
modifier|*
name|getCanonicalType
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getCanonicalTypeInternal
argument_list|()
operator|.
name|getTypePtr
argument_list|()
return|;
block|}
comment|/// \brief Determine whether the given types are equivalent.
name|bool
name|hasSameType
parameter_list|(
name|QualType
name|T1
parameter_list|,
name|QualType
name|T2
parameter_list|)
block|{
return|return
name|getCanonicalType
argument_list|(
name|T1
argument_list|)
operator|==
name|getCanonicalType
argument_list|(
name|T2
argument_list|)
return|;
block|}
comment|/// \brief Determine whether the given types are equivalent after
comment|/// cvr-qualifiers have been removed.
name|bool
name|hasSameUnqualifiedType
parameter_list|(
name|QualType
name|T1
parameter_list|,
name|QualType
name|T2
parameter_list|)
block|{
name|T1
operator|=
name|getCanonicalType
argument_list|(
name|T1
argument_list|)
expr_stmt|;
name|T2
operator|=
name|getCanonicalType
argument_list|(
name|T2
argument_list|)
expr_stmt|;
return|return
name|T1
operator|.
name|getUnqualifiedType
argument_list|()
operator|==
name|T2
operator|.
name|getUnqualifiedType
argument_list|()
return|;
block|}
comment|/// \brief Retrieves the "canonical" declaration of the given declaration.
name|Decl
modifier|*
name|getCanonicalDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Retrieves the "canonical" declaration of the given tag
comment|/// declaration.
comment|///
comment|/// The canonical declaration for the given tag declaration is
comment|/// either the definition of the tag (if it is a complete type) or
comment|/// the first declaration of that tag.
name|TagDecl
modifier|*
name|getCanonicalDecl
parameter_list|(
name|TagDecl
modifier|*
name|Tag
parameter_list|)
block|{
return|return
name|cast
operator|<
name|TagDecl
operator|>
operator|(
name|getCanonicalDecl
argument_list|(
operator|(
name|Decl
operator|*
operator|)
name|Tag
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Retrieves the "canonical" declaration of
comment|/// \brief Retrieves the "canonical" nested name specifier for a
comment|/// given nested name specifier.
comment|///
comment|/// The canonical nested name specifier is a nested name specifier
comment|/// that uniquely identifies a type or namespace within the type
comment|/// system. For example, given:
comment|///
comment|/// \code
comment|/// namespace N {
comment|///   struct S {
comment|///     template<typename T> struct X { typename T* type; };
comment|///   };
comment|/// }
comment|///
comment|/// template<typename T> struct Y {
comment|///   typename N::S::X<T>::type member;
comment|/// };
comment|/// \endcode
comment|///
comment|/// Here, the nested-name-specifier for N::S::X<T>:: will be
comment|/// S::X<template-param-0-0>, since 'S' and 'X' are uniquely defined
comment|/// by declarations in the type system and the canonical type for
comment|/// the template type parameter 'T' is template-param-0-0.
name|NestedNameSpecifier
modifier|*
name|getCanonicalNestedNameSpecifier
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|)
function_decl|;
comment|/// \brief Retrieves the "canonical" template name that refers to a
comment|/// given template.
comment|///
comment|/// The canonical template name is the simplest expression that can
comment|/// be used to refer to a given template. For most templates, this
comment|/// expression is just the template declaration itself. For example,
comment|/// the template std::vector can be referred to via a variety of
comment|/// names---std::vector, ::std::vector, vector (if vector is in
comment|/// scope), etc.---but all of these names map down to the same
comment|/// TemplateDecl, which is used to form the canonical template name.
comment|///
comment|/// Dependent template names are more interesting. Here, the
comment|/// template name could be something like T::template apply or
comment|/// std::allocator<T>::template rebind, where the nested name
comment|/// specifier itself is dependent. In this case, the canonical
comment|/// template name uses the shortest form of the dependent
comment|/// nested-name-specifier, which itself contains all canonical
comment|/// types, values, and templates.
name|TemplateName
name|getCanonicalTemplateName
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
function_decl|;
comment|/// Type Query functions.  If the type is an instance of the specified class,
comment|/// return the Type pointer for the underlying maximally pretty type.  This
comment|/// is a member of ASTContext because this may need to do some amount of
comment|/// canonicalization, e.g. to move type qualifiers into the element type.
specifier|const
name|ArrayType
modifier|*
name|getAsArrayType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
specifier|const
name|ConstantArrayType
modifier|*
name|getAsConstantArrayType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|dyn_cast_or_null
operator|<
name|ConstantArrayType
operator|>
operator|(
name|getAsArrayType
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
specifier|const
name|VariableArrayType
modifier|*
name|getAsVariableArrayType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|dyn_cast_or_null
operator|<
name|VariableArrayType
operator|>
operator|(
name|getAsArrayType
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
specifier|const
name|IncompleteArrayType
modifier|*
name|getAsIncompleteArrayType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|dyn_cast_or_null
operator|<
name|IncompleteArrayType
operator|>
operator|(
name|getAsArrayType
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
comment|/// getBaseElementType - Returns the innermost element type of a variable
comment|/// length array type. For example, will return "int" for int[m][n]
name|QualType
name|getBaseElementType
parameter_list|(
specifier|const
name|VariableArrayType
modifier|*
name|VAT
parameter_list|)
function_decl|;
comment|/// getArrayDecayedType - Return the properly qualified result of decaying the
comment|/// specified array type to a pointer.  This operation is non-trivial when
comment|/// handling typedefs etc.  The canonical type of "T" must be an array type,
comment|/// this returns a pointer to a properly qualified element of the array.
comment|///
comment|/// See C99 6.7.5.3p7 and C99 6.3.2.1p3.
name|QualType
name|getArrayDecayedType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getIntegerTypeOrder - Returns the highest ranked integer type:
comment|/// C99 6.3.1.8p1.  If LHS> RHS, return 1.  If LHS == RHS, return 0. If
comment|/// LHS< RHS, return -1.
name|int
name|getIntegerTypeOrder
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|)
function_decl|;
comment|/// getFloatingTypeOrder - Compare the rank of the two specified floating
comment|/// point types, ignoring the domain of the type (i.e. 'double' ==
comment|/// '_Complex double').  If LHS> RHS, return 1.  If LHS == RHS, return 0. If
comment|/// LHS< RHS, return -1.
name|int
name|getFloatingTypeOrder
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|)
function_decl|;
comment|/// getFloatingTypeOfSizeWithinDomain - Returns a real floating
comment|/// point or a complex type (based on typeDomain/typeSize).
comment|/// 'typeDomain' is a real floating point or complex type.
comment|/// 'typeSize' is a real floating point or complex type.
name|QualType
name|getFloatingTypeOfSizeWithinDomain
argument_list|(
name|QualType
name|typeSize
argument_list|,
name|QualType
name|typeDomain
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// Helper for integer ordering
name|unsigned
name|getIntegerRank
parameter_list|(
name|Type
modifier|*
name|T
parameter_list|)
function_decl|;
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|//                    Type Compatibility Predicates
comment|//===--------------------------------------------------------------------===//
comment|/// Compatibility predicates used to check assignment expressions.
name|bool
name|typesAreCompatible
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|)
function_decl|;
comment|// C99 6.2.7p1
name|bool
name|isObjCIdType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|T
operator|==
name|ObjCIdType
return|;
block|}
name|bool
name|isObjCIdStructType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|IdStructType
condition|)
comment|// ObjC isn't enabled
return|return
name|false
return|;
return|return
name|T
operator|->
name|getAsStructureType
argument_list|()
operator|==
name|IdStructType
return|;
block|}
name|bool
name|isObjCClassType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|T
operator|==
name|ObjCClassType
return|;
block|}
name|bool
name|isObjCClassStructType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|ClassStructType
condition|)
comment|// ObjC isn't enabled
return|return
name|false
return|;
return|return
name|T
operator|->
name|getAsStructureType
argument_list|()
operator|==
name|ClassStructType
return|;
block|}
name|bool
name|isObjCSelType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|SelStructType
operator|&&
literal|"isObjCSelType used before 'SEL' type is built"
argument_list|)
expr_stmt|;
return|return
name|T
operator|->
name|getAsStructureType
argument_list|()
operator|==
name|SelStructType
return|;
block|}
comment|// Check the safety of assignment from LHS to RHS
name|bool
name|canAssignObjCInterfaces
parameter_list|(
specifier|const
name|ObjCInterfaceType
modifier|*
name|LHS
parameter_list|,
specifier|const
name|ObjCInterfaceType
modifier|*
name|RHS
parameter_list|)
function_decl|;
name|bool
name|areComparableObjCPointerTypes
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|)
function_decl|;
comment|// Functions for calculating composite types
name|QualType
name|mergeTypes
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|)
function_decl|;
name|QualType
name|mergeFunctionTypes
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//                    Integer Predicates
comment|//===--------------------------------------------------------------------===//
comment|// The width of an integer, as defined in C99 6.2.6.2. This is the number
comment|// of bits in an integer type excluding any padding bits.
name|unsigned
name|getIntWidth
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|// Per C99 6.2.5p6, for every signed integer type, there is a corresponding
comment|// unsigned integer type.  This method takes a signed type, and returns the
comment|// corresponding unsigned integer type.
name|QualType
name|getCorrespondingUnsignedType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//                    Type Iterators.
comment|//===--------------------------------------------------------------------===//
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Type
operator|*
operator|>
operator|::
name|iterator
name|type_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Type
operator|*
operator|>
operator|::
name|const_iterator
name|const_type_iterator
expr_stmt|;
name|type_iterator
name|types_begin
parameter_list|()
block|{
return|return
name|Types
operator|.
name|begin
argument_list|()
return|;
block|}
name|type_iterator
name|types_end
parameter_list|()
block|{
return|return
name|Types
operator|.
name|end
argument_list|()
return|;
block|}
name|const_type_iterator
name|types_begin
argument_list|()
specifier|const
block|{
return|return
name|Types
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_type_iterator
name|types_end
argument_list|()
specifier|const
block|{
return|return
name|Types
operator|.
name|end
argument_list|()
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//                    Integer Values
comment|//===--------------------------------------------------------------------===//
comment|/// MakeIntValue - Make an APSInt of the appropriate width and
comment|/// signedness for the given \arg Value and integer \arg Type.
name|llvm
operator|::
name|APSInt
name|MakeIntValue
argument_list|(
argument|uint64_t Value
argument_list|,
argument|QualType Type
argument_list|)
block|{
name|llvm
operator|::
name|APSInt
name|Res
argument_list|(
name|getIntWidth
argument_list|(
name|Type
argument_list|)
argument_list|,
operator|!
name|Type
operator|->
name|isSignedIntegerType
argument_list|()
argument_list|)
block|;
name|Res
operator|=
name|Value
block|;
return|return
name|Res
return|;
block|}
name|private
label|:
name|ASTContext
argument_list|(
specifier|const
name|ASTContext
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTContext
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|InitBuiltinTypes
parameter_list|()
function_decl|;
name|void
name|InitBuiltinType
argument_list|(
name|QualType
operator|&
name|R
argument_list|,
name|BuiltinType
operator|::
name|Kind
name|K
argument_list|)
decl_stmt|;
comment|// Return the ObjC type encoding for a given type.
name|void
name|getObjCEncodingForTypeImpl
argument_list|(
name|QualType
name|t
argument_list|,
name|std
operator|::
name|string
operator|&
name|S
argument_list|,
name|bool
name|ExpandPointedToStructures
argument_list|,
name|bool
name|ExpandStructures
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|bool
name|OutermostType
operator|=
name|false
argument_list|,
name|bool
name|EncodingProperty
operator|=
name|false
argument_list|)
decl_stmt|;
specifier|const
name|ASTRecordLayout
modifier|&
name|getObjCLayout
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|ObjCImplementationDecl
modifier|*
name|Impl
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_comment
comment|// operator new and delete aren't allowed inside namespaces.
end_comment

begin_comment
comment|// The throw specifications are mandated by the standard.
end_comment

begin_comment
comment|/// @brief Placement new for using the ASTContext's allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This placement form of operator new uses the ASTContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory. It is a non-throwing new, which means that it returns
end_comment

begin_comment
comment|/// null on error. (If that is what the allocator does. The current does, so if
end_comment

begin_comment
comment|/// this ever changes, this operator will have to be changed, too.)
end_comment

begin_comment
comment|/// Usage looks like this (assuming there's an ASTContext 'Context' in scope):
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// // Default alignment (16)
end_comment

begin_comment
comment|/// IntegerLiteral *Ex = new (Context) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// IntegerLiteral *Ex2 = new (Context, 8) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// @c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// @param C The ASTContext that provides the allocator.
end_comment

begin_comment
comment|/// @param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// @return The allocated memory. Could be NULL.
end_comment

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|Bytes
argument_list|,
name|clang
operator|::
name|ASTContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|C
operator|.
name|Allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Placement delete companion to the new above.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operator is just a companion to the new above. There is no way of
end_comment

begin_comment
comment|/// invoking it directly; see the new operator for more details. This operator
end_comment

begin_comment
comment|/// is called implicitly by the compiler if a placement new expression using
end_comment

begin_comment
comment|/// the ASTContext throws in the object constructor.
end_comment

begin_decl_stmt
specifier|inline
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|Ptr
argument_list|,
name|clang
operator|::
name|ASTContext
operator|&
name|C
argument_list|,
name|size_t
argument_list|)
name|throw
argument_list|()
block|{
name|C
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// This placement form of operator new[] uses the ASTContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory. It is a non-throwing new[], which means that it returns
end_comment

begin_comment
comment|/// null on error.
end_comment

begin_comment
comment|/// Usage looks like this (assuming there's an ASTContext 'Context' in scope):
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// // Default alignment (16)
end_comment

begin_comment
comment|/// char *data = new (Context) char[10];
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// char *data = new (Context, 8) char[10];
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// @c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// @param C The ASTContext that provides the allocator.
end_comment

begin_comment
comment|/// @param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// @return The allocated memory. Could be NULL.
end_comment

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
index|[]
argument_list|(
name|size_t
name|Bytes
argument_list|,
name|clang
operator|::
name|ASTContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
operator|=
literal|16
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|C
operator|.
name|Allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Placement delete[] companion to the new[] above.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operator is just a companion to the new[] above. There is no way of
end_comment

begin_comment
comment|/// invoking it directly; see the new[] operator for more details. This operator
end_comment

begin_comment
comment|/// is called implicitly by the compiler if a placement new[] expression using
end_comment

begin_comment
comment|/// the ASTContext throws in the object constructor.
end_comment

begin_decl_stmt
specifier|inline
name|void
name|operator
name|delete
index|[]
argument_list|(
name|void
operator|*
name|Ptr
argument_list|,
name|clang
operator|::
name|ASTContext
operator|&
name|C
argument_list|)
name|throw
argument_list|()
block|{
name|C
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

