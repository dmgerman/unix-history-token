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
file|"clang/Basic/OperatorKinds.h"
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
file|"clang/AST/CanonicalType.h"
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
name|BlockExpr
decl_stmt|;
name|class
name|CharUnits
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
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCIvarRefExpr
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
name|TemplateTypeParmDecl
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
name|UsingDecl
decl_stmt|;
name|class
name|UsingShadowDecl
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
name|ExtQuals
operator|>
name|ExtQualNodes
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
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentSizedArrayType
operator|>
name|DependentSizedArrayTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentSizedExtVectorType
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
name|DependentTypeOfExprType
operator|>
name|DependentTypeOfExprTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentDecltypeType
operator|>
name|DependentDecltypeTypes
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
name|SubstTemplateTypeParmType
operator|>
name|SubstTemplateTypeParmTypes
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
name|ObjCInterfaceType
operator|>
name|ObjCInterfaceTypes
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
name|ElaboratedType
operator|>
name|ElaboratedTypes
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
comment|/// KeyFunctions - A cache mapping from CXXRecordDecls to key functions.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
specifier|const
name|CXXMethodDecl
operator|*
operator|>
name|KeyFunctions
expr_stmt|;
comment|/// \brief Mapping from ObjCContainers to their ObjCImplementations.
name|llvm
operator|::
name|DenseMap
operator|<
name|ObjCContainerDecl
operator|*
operator|,
name|ObjCImplDecl
operator|*
operator|>
name|ObjCImpls
expr_stmt|;
comment|/// BuiltinVaListType - built-in va list type.
comment|/// This is initially null and set by Sema::LazilyCreateBuiltin when
comment|/// a builtin that takes a valist is encountered.
name|QualType
name|BuiltinVaListType
decl_stmt|;
comment|/// ObjCIdType - a pseudo built-in typedef type (set by Sema).
name|QualType
name|ObjCIdTypedefType
decl_stmt|;
comment|/// ObjCSelType - another pseudo built-in typedef type (set by Sema).
name|QualType
name|ObjCSelTypedefType
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
name|ObjCClassTypedefType
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
comment|/// \brief The type for the C FILE type.
name|TypeDecl
modifier|*
name|FILEDecl
decl_stmt|;
comment|/// \brief The type for the C jmp_buf type.
name|TypeDecl
modifier|*
name|jmp_bufDecl
decl_stmt|;
comment|/// \brief The type for the C sigjmp_buf type.
name|TypeDecl
modifier|*
name|sigjmp_bufDecl
decl_stmt|;
comment|/// \brief Type for the Block descriptor for Blocks CodeGen.
name|RecordDecl
modifier|*
name|BlockDescriptorType
decl_stmt|;
comment|/// \brief Type for the Block descriptor for Blocks CodeGen.
name|RecordDecl
modifier|*
name|BlockDescriptorExtendedType
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
comment|/// \brief Keeps track of the static data member templates from which
comment|/// static data members of class template specializations were instantiated.
comment|///
comment|/// This data structure stores the mapping from instantiations of static
comment|/// data members to the static data member representations within the
comment|/// class template from which they were instantiated along with the kind
comment|/// of instantiation or specialization (a TemplateSpecializationKind - 1).
comment|///
comment|/// Given the following example:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   static T value;
comment|/// };
comment|///
comment|/// template<typename T>
comment|///   T X<T>::value = T(17);
comment|///
comment|/// int *x =&X<int>::value;
comment|/// \endcode
comment|///
comment|/// This mapping will contain an entry that maps from the VarDecl for
comment|/// X<int>::value to the corresponding VarDecl for X<T>::value (within the
comment|/// class template X) and will be marked TSK_ImplicitInstantiation.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|MemberSpecializationInfo
operator|*
operator|>
name|InstantiatedFromStaticDataMember
expr_stmt|;
comment|/// \brief Keeps track of the declaration from which a UsingDecl was
comment|/// created during instantiation.  The source declaration is always
comment|/// a UsingDecl, an UnresolvedUsingValueDecl, or an
comment|/// UnresolvedUsingTypenameDecl.
comment|///
comment|/// For example:
comment|/// \code
comment|/// template<typename T>
comment|/// struct A {
comment|///   void f();
comment|/// };
comment|///
comment|/// template<typename T>
comment|/// struct B : A<T> {
comment|///   using A<T>::f;
comment|/// };
comment|///
comment|/// template struct B<int>;
comment|/// \endcode
comment|///
comment|/// This mapping will contain an entry that maps from the UsingDecl in
comment|/// B<int> to the UnresolvedUsingDecl in B<T>.
name|llvm
operator|::
name|DenseMap
operator|<
name|UsingDecl
operator|*
operator|,
name|NamedDecl
operator|*
operator|>
name|InstantiatedFromUsingDecl
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|UsingShadowDecl
operator|*
operator|,
name|UsingShadowDecl
operator|*
operator|>
name|InstantiatedFromUsingShadowDecl
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|FieldDecl
operator|*
operator|,
name|FieldDecl
operator|*
operator|>
name|InstantiatedFromUnnamedFieldDecl
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
comment|/// \brief Whether we have already loaded comment source ranges from an
comment|/// external source.
name|bool
name|LoadedExternalComments
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
comment|/// \brief Mapping from declarations to their comments, once we have
comment|/// already looked up the comment associated with a given declaration.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|std
operator|::
name|string
operator|>
name|DeclComments
expr_stmt|;
name|public
label|:
specifier|const
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
comment|// Typedefs which may be provided defining the structure of Objective-C
comment|// pseudo-builtins
name|QualType
name|ObjCIdRedefinitionType
decl_stmt|;
name|QualType
name|ObjCClassRedefinitionType
decl_stmt|;
name|QualType
name|ObjCSelRedefinitionType
decl_stmt|;
comment|/// \brief Source ranges for all of the comments in the source file,
comment|/// sorted in order of appearance in the translation unit.
name|std
operator|::
name|vector
operator|<
name|SourceRange
operator|>
name|Comments
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
comment|/// \brief If this variable is an instantiated static data member of a
comment|/// class template specialization, returns the templated static data member
comment|/// from which it was instantiated.
name|MemberSpecializationInfo
modifier|*
name|getInstantiatedFromStaticDataMember
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Var
parameter_list|)
function_decl|;
comment|/// \brief Note that the static data member \p Inst is an instantiation of
comment|/// the static data member template \p Tmpl of a class template.
name|void
name|setInstantiatedFromStaticDataMember
parameter_list|(
name|VarDecl
modifier|*
name|Inst
parameter_list|,
name|VarDecl
modifier|*
name|Tmpl
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
comment|/// \brief If the given using decl is an instantiation of a
comment|/// (possibly unresolved) using decl from a template instantiation,
comment|/// return it.
name|NamedDecl
modifier|*
name|getInstantiatedFromUsingDecl
parameter_list|(
name|UsingDecl
modifier|*
name|Inst
parameter_list|)
function_decl|;
comment|/// \brief Remember that the using decl \p Inst is an instantiation
comment|/// of the using decl \p Pattern of a class template.
name|void
name|setInstantiatedFromUsingDecl
parameter_list|(
name|UsingDecl
modifier|*
name|Inst
parameter_list|,
name|NamedDecl
modifier|*
name|Pattern
parameter_list|)
function_decl|;
name|void
name|setInstantiatedFromUsingShadowDecl
parameter_list|(
name|UsingShadowDecl
modifier|*
name|Inst
parameter_list|,
name|UsingShadowDecl
modifier|*
name|Pattern
parameter_list|)
function_decl|;
name|UsingShadowDecl
modifier|*
name|getInstantiatedFromUsingShadowDecl
parameter_list|(
name|UsingShadowDecl
modifier|*
name|Inst
parameter_list|)
function_decl|;
name|FieldDecl
modifier|*
name|getInstantiatedFromUnnamedFieldDecl
parameter_list|(
name|FieldDecl
modifier|*
name|Field
parameter_list|)
function_decl|;
name|void
name|setInstantiatedFromUnnamedFieldDecl
parameter_list|(
name|FieldDecl
modifier|*
name|Inst
parameter_list|,
name|FieldDecl
modifier|*
name|Tmpl
parameter_list|)
function_decl|;
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
specifier|const
name|char
modifier|*
name|getCommentForDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|// Builtin Types.
name|CanQualType
name|VoidTy
decl_stmt|;
name|CanQualType
name|BoolTy
decl_stmt|;
name|CanQualType
name|CharTy
decl_stmt|;
name|CanQualType
name|WCharTy
decl_stmt|;
comment|// [C++ 3.9.1p5], integer type in C99.
name|CanQualType
name|Char16Ty
decl_stmt|;
comment|// [C++0x 3.9.1p5], integer type in C99.
name|CanQualType
name|Char32Ty
decl_stmt|;
comment|// [C++0x 3.9.1p5], integer type in C99.
name|CanQualType
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
name|CanQualType
name|UnsignedCharTy
decl_stmt|,
name|UnsignedShortTy
decl_stmt|,
name|UnsignedIntTy
decl_stmt|,
name|UnsignedLongTy
decl_stmt|;
name|CanQualType
name|UnsignedLongLongTy
decl_stmt|,
name|UnsignedInt128Ty
decl_stmt|;
name|CanQualType
name|FloatTy
decl_stmt|,
name|DoubleTy
decl_stmt|,
name|LongDoubleTy
decl_stmt|;
name|CanQualType
name|FloatComplexTy
decl_stmt|,
name|DoubleComplexTy
decl_stmt|,
name|LongDoubleComplexTy
decl_stmt|;
name|CanQualType
name|VoidPtrTy
decl_stmt|,
name|NullPtrTy
decl_stmt|;
name|CanQualType
name|OverloadTy
decl_stmt|;
name|CanQualType
name|DependentTy
decl_stmt|;
name|CanQualType
name|UndeducedAutoTy
decl_stmt|;
name|CanQualType
name|ObjCBuiltinIdTy
decl_stmt|,
name|ObjCBuiltinClassTy
decl_stmt|,
name|ObjCBuiltinSelTy
decl_stmt|;
name|ASTContext
argument_list|(
argument|const LangOptions& LOpts
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|const TargetInfo&t
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
name|private
label|:
comment|/// getExtQualType - Return a type with extended qualifiers.
name|QualType
name|getExtQualType
parameter_list|(
specifier|const
name|Type
modifier|*
name|Base
parameter_list|,
name|Qualifiers
name|Quals
parameter_list|)
function_decl|;
name|public
label|:
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
name|Qualifiers
operator|::
name|GC
name|gcAttr
argument_list|)
decl_stmt|;
comment|/// getRestrictType - Returns the uniqued reference to the type for a
comment|/// 'restrict' qualified type.  The resulting type has a union of the
comment|/// qualifiers from T and 'restrict'.
name|QualType
name|getRestrictType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|T
operator|.
name|withFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Restrict
argument_list|)
return|;
block|}
comment|/// getVolatileType - Returns the uniqued reference to the type for a
comment|/// 'volatile' qualified type.  The resulting type has a union of the
comment|/// qualifiers from T and 'volatile'.
name|QualType
name|getVolatileType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// getConstType - Returns the uniqued reference to the type for a
comment|/// 'const' qualified type.  The resulting type has a union of the
comment|/// qualifiers from T and 'const'.
comment|///
comment|/// It can be reasonably expected that this will always be
comment|/// equivalent to calling T.withConst().
name|QualType
name|getConstType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|T
operator|.
name|withConst
argument_list|()
return|;
block|}
comment|/// getNoReturnType - Add or remove the noreturn attribute to the given type
comment|/// which must be a FunctionType or a pointer to an allowable type or a
comment|/// BlockPointer.
name|QualType
name|getNoReturnType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|AddNoReturn
init|=
name|true
parameter_list|)
function_decl|;
comment|/// getComplexType - Return the uniqued reference to the type for a complex
comment|/// number with the specified element type.
name|QualType
name|getComplexType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|CanQualType
name|getComplexType
parameter_list|(
name|CanQualType
name|T
parameter_list|)
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
name|getComplexType
argument_list|(
operator|(
name|QualType
operator|)
name|T
argument_list|)
argument_list|)
return|;
block|}
comment|/// getPointerType - Return the uniqued reference to the type for a pointer to
comment|/// the specified type.
name|QualType
name|getPointerType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|CanQualType
name|getPointerType
parameter_list|(
name|CanQualType
name|T
parameter_list|)
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
name|getPointerType
argument_list|(
operator|(
name|QualType
operator|)
name|T
argument_list|)
argument_list|)
return|;
block|}
comment|/// getBlockPointerType - Return the uniqued reference to the type for a block
comment|/// of the specified type.
name|QualType
name|getBlockPointerType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// This gets the struct used to keep track of the descriptor for pointer to
comment|/// blocks.
name|QualType
name|getBlockDescriptorType
parameter_list|()
function_decl|;
comment|// Set the type for a Block descriptor type.
name|void
name|setBlockDescriptorType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// Get the BlockDescriptorType type, or NULL if it hasn't yet been built.
name|QualType
name|getRawBlockdescriptorType
parameter_list|()
block|{
if|if
condition|(
name|BlockDescriptorType
condition|)
return|return
name|getTagDeclType
argument_list|(
name|BlockDescriptorType
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
comment|/// This gets the struct used to keep track of the extended descriptor for
comment|/// pointer to blocks.
name|QualType
name|getBlockDescriptorExtendedType
parameter_list|()
function_decl|;
comment|// Set the type for a Block descriptor extended type.
name|void
name|setBlockDescriptorExtendedType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// Get the BlockDescriptorExtendedType type, or NULL if it hasn't yet been
comment|/// built.
name|QualType
name|getRawBlockdescriptorExtendedType
parameter_list|()
block|{
if|if
condition|(
name|BlockDescriptorExtendedType
condition|)
return|return
name|getTagDeclType
argument_list|(
name|BlockDescriptorExtendedType
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
comment|/// This gets the struct used to keep track of pointer to blocks, complete
comment|/// with captured variables.
name|QualType
name|getBlockParmType
argument_list|(
name|bool
name|BlockHasCopyDispose
argument_list|,
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|BDRDs
argument_list|)
decl_stmt|;
comment|/// This builds the struct used for __block variables.
name|QualType
name|BuildByRefType
parameter_list|(
specifier|const
name|char
modifier|*
name|DeclName
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// Returns true iff we need copy/dispose helpers for the given type.
name|bool
name|BlockRequiresCopying
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// getLValueReferenceType - Return the uniqued reference to the type for an
comment|/// lvalue reference to the specified type.
name|QualType
name|getLValueReferenceType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|SpelledAsLValue
init|=
name|true
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
argument_list|,
name|SourceRange
name|Brackets
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
argument_list|,
name|SourceRange
name|Brackets
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
parameter_list|,
name|bool
name|NoReturn
init|=
name|false
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
parameter_list|,
name|bool
name|NoReturn
init|=
name|false
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
name|getSubstTemplateTypeParmType
parameter_list|(
specifier|const
name|TemplateTypeParmType
modifier|*
name|Replaced
parameter_list|,
name|QualType
name|Replacement
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
name|getTemplateSpecializationType
parameter_list|(
name|TemplateName
name|T
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|Args
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
name|QualType
name|getElaboratedType
argument_list|(
name|QualType
name|UnderlyingType
argument_list|,
name|ElaboratedType
operator|::
name|TagKind
name|Tag
argument_list|)
decl_stmt|;
name|QualType
name|getObjCInterfaceType
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|,
name|ObjCProtocolDecl
modifier|*
modifier|*
name|Protocols
init|=
literal|0
parameter_list|,
name|unsigned
name|NumProtocols
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getObjCObjectPointerType - Return a ObjCObjectPointerType type for the
comment|/// given interface decl and the conforming protocol list.
name|QualType
name|getObjCObjectPointerType
parameter_list|(
name|QualType
name|OIT
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
comment|/// getDecltypeType - C++0x decltype.
name|QualType
name|getDecltypeType
parameter_list|(
name|Expr
modifier|*
name|e
parameter_list|)
function_decl|;
comment|/// getTagDeclType - Return the unique reference to the type for the
comment|/// specified TagDecl (struct/union/class/enum) decl.
name|QualType
name|getTagDeclType
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
comment|/// getSizeType - Return the unique type for "size_t" (C99 7.17), defined
comment|/// in<stddef.h>. The sizeof operator requires this (C99 6.5.3.4p4).
name|CanQualType
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
comment|/// \brief Set the type for the C FILE type.
name|void
name|setFILEDecl
parameter_list|(
name|TypeDecl
modifier|*
name|FILEDecl
parameter_list|)
block|{
name|this
operator|->
name|FILEDecl
operator|=
name|FILEDecl
expr_stmt|;
block|}
comment|/// \brief Retrieve the C FILE type.
name|QualType
name|getFILEType
parameter_list|()
block|{
if|if
condition|(
name|FILEDecl
condition|)
return|return
name|getTypeDeclType
argument_list|(
name|FILEDecl
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
comment|/// \brief Set the type for the C jmp_buf type.
name|void
name|setjmp_bufDecl
parameter_list|(
name|TypeDecl
modifier|*
name|jmp_bufDecl
parameter_list|)
block|{
name|this
operator|->
name|jmp_bufDecl
operator|=
name|jmp_bufDecl
expr_stmt|;
block|}
comment|/// \brief Retrieve the C jmp_buf type.
name|QualType
name|getjmp_bufType
parameter_list|()
block|{
if|if
condition|(
name|jmp_bufDecl
condition|)
return|return
name|getTypeDeclType
argument_list|(
name|jmp_bufDecl
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
comment|/// \brief Set the type for the C sigjmp_buf type.
name|void
name|setsigjmp_bufDecl
parameter_list|(
name|TypeDecl
modifier|*
name|sigjmp_bufDecl
parameter_list|)
block|{
name|this
operator|->
name|sigjmp_bufDecl
operator|=
name|sigjmp_bufDecl
expr_stmt|;
block|}
comment|/// \brief Retrieve the C sigjmp_buf type.
name|QualType
name|getsigjmp_bufType
parameter_list|()
block|{
if|if
condition|(
name|sigjmp_bufDecl
condition|)
return|return
name|getTypeDeclType
argument_list|(
name|sigjmp_bufDecl
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
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
comment|/// getObjCEncodingForBlockDecl - Return the encoded type for this block
comment|/// declaration.
name|void
name|getObjCEncodingForBlock
argument_list|(
specifier|const
name|BlockExpr
operator|*
name|Expr
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
name|bool
name|ProtocolCompatibleWithProtocol
parameter_list|(
name|ObjCProtocolDecl
modifier|*
name|lProto
parameter_list|,
name|ObjCProtocolDecl
modifier|*
name|rProto
parameter_list|)
function_decl|;
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
name|ObjCIdTypedefType
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
name|ObjCSelTypedefType
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
name|ObjCClassTypedefType
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
comment|/// getCVRQualifiedType - Returns a type with additional const,
comment|/// volatile, or restrict qualifiers.
name|QualType
name|getCVRQualifiedType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|unsigned
name|CVR
parameter_list|)
block|{
return|return
name|getQualifiedType
argument_list|(
name|T
argument_list|,
name|Qualifiers
operator|::
name|fromCVRMask
argument_list|(
name|CVR
argument_list|)
argument_list|)
return|;
block|}
comment|/// getQualifiedType - Returns a type with additional qualifiers.
name|QualType
name|getQualifiedType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|Qualifiers
name|Qs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Qs
operator|.
name|hasNonFastQualifiers
argument_list|()
condition|)
return|return
name|T
operator|.
name|withFastQualifiers
argument_list|(
name|Qs
operator|.
name|getFastQualifiers
argument_list|()
argument_list|)
return|;
name|QualifierCollector
name|Qc
argument_list|(
name|Qs
argument_list|)
decl_stmt|;
specifier|const
name|Type
modifier|*
name|Ptr
init|=
name|Qc
operator|.
name|strip
argument_list|(
name|T
argument_list|)
decl_stmt|;
return|return
name|getExtQualType
argument_list|(
name|Ptr
argument_list|,
name|Qc
argument_list|)
return|;
block|}
comment|/// getQualifiedType - Returns a type with additional qualifiers.
name|QualType
name|getQualifiedType
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|,
name|Qualifiers
name|Qs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Qs
operator|.
name|hasNonFastQualifiers
argument_list|()
condition|)
return|return
name|QualType
argument_list|(
name|T
argument_list|,
name|Qs
operator|.
name|getFastQualifiers
argument_list|()
argument_list|)
return|;
return|return
name|getExtQualType
argument_list|(
name|T
argument_list|,
name|Qs
argument_list|)
return|;
block|}
name|DeclarationName
name|getNameForTemplate
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
function_decl|;
name|TemplateName
name|getOverloadedTemplateName
parameter_list|(
name|NamedDecl
modifier|*
specifier|const
modifier|*
name|Begin
parameter_list|,
name|NamedDecl
modifier|*
specifier|const
modifier|*
name|End
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
name|TemplateName
name|getDependentTemplateName
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
name|OverloadedOperatorKind
name|Operator
parameter_list|)
function_decl|;
enum|enum
name|GetBuiltinTypeError
block|{
name|GE_None
block|,
comment|//< No error
name|GE_Missing_stdio
block|,
comment|//< Missing a type from<stdio.h>
name|GE_Missing_setjmp
comment|//< Missing a type from<setjmp.h>
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
name|CanQualType
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
comment|/// getObjCGCAttr - Returns one of GCNone, Weak or Strong objc's
comment|/// garbage collection attribute.
comment|///
name|Qualifiers
operator|::
name|GC
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
comment|/// getCharWidth - Return the size of the character type, in bits
name|uint64_t
name|getCharWidth
parameter_list|()
block|{
return|return
name|getTypeSize
argument_list|(
name|CharTy
argument_list|)
return|;
block|}
comment|/// getTypeSizeInChars - Return the size of the specified type, in characters.
comment|/// This method does not work on incomplete types.
name|CharUnits
name|getTypeSizeInChars
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|CharUnits
name|getTypeSizeInChars
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|)
function_decl|;
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
name|unsigned
name|getDeclAlignInBytes
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|bool
name|RefAsPointee
init|=
name|false
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
comment|/// getKeyFunction - Get the key function for the given record decl.
comment|/// The key function is, according to the Itanium C++ ABI section 5.2.3:
comment|///
comment|/// ...the first non-pure virtual function that is not inline at the point
comment|/// of class definition.
specifier|const
name|CXXMethodDecl
modifier|*
name|getKeyFunction
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
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
name|void
name|CollectInheritedProtocols
argument_list|(
specifier|const
name|Decl
operator|*
name|CDecl
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
operator|&
name|Protocols
argument_list|)
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//                            Type Operators
comment|//===--------------------------------------------------------------------===//
comment|/// getCanonicalType - Return the canonical (structural) type corresponding to
comment|/// the specified potentially non-canonical type.  The non-canonical version
comment|/// of a type may have many "decorated" versions of types.  Decorators can
comment|/// include typedefs, 'typeof' operators, etc. The returned type is guaranteed
comment|/// to be free of any of these, allowing two canonical types to be compared
comment|/// for exact equality with a simple pointer comparison.
name|CanQualType
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
comment|/// getCanonicalParamType - Return the canonical parameter type
comment|/// corresponding to the specific potentially non-canonical one.
comment|/// Qualifiers are stripped off, functions are turned into function
comment|/// pointers, and arrays decay one level into pointers.
name|CanQualType
name|getCanonicalParamType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
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
comment|/// \brief Returns this type as a completely-unqualified array type, capturing
comment|/// the qualifiers in Quals. This only operates on canonical types in order
comment|/// to ensure the ArrayType doesn't itself have qualifiers.
comment|///
comment|/// \param T is the canonicalized QualType, which may be an ArrayType
comment|///
comment|/// \param Quals will receive the full set of qualifiers that were
comment|/// applied to the element type of the array.
comment|///
comment|/// \returns if this is an array type, the completely unqualified array type
comment|/// that corresponds to it. Otherwise, returns this->getUnqualifiedType().
name|QualType
name|getUnqualifiedArrayType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|Qualifiers
modifier|&
name|Quals
parameter_list|)
function_decl|;
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
name|CanQualType
name|CT1
init|=
name|getCanonicalType
argument_list|(
name|T1
argument_list|)
decl_stmt|;
name|CanQualType
name|CT2
init|=
name|getCanonicalType
argument_list|(
name|T2
argument_list|)
decl_stmt|;
name|Qualifiers
name|Quals
decl_stmt|;
name|QualType
name|UnqualT1
init|=
name|getUnqualifiedArrayType
argument_list|(
name|CT1
argument_list|,
name|Quals
argument_list|)
decl_stmt|;
name|QualType
name|UnqualT2
init|=
name|getUnqualifiedArrayType
argument_list|(
name|CT2
argument_list|,
name|Quals
argument_list|)
decl_stmt|;
return|return
name|UnqualT1
operator|==
name|UnqualT2
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
comment|/// \brief Determine whether the given template names refer to the same
comment|/// template.
name|bool
name|hasSameTemplateName
parameter_list|(
name|TemplateName
name|X
parameter_list|,
name|TemplateName
name|Y
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the "canonical" template argument.
comment|///
comment|/// The canonical template argument is the simplest template argument
comment|/// (which may be a type, value, expression, or declaration) that
comment|/// expresses the value of the argument.
name|TemplateArgument
name|getCanonicalTemplateArgument
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
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
comment|/// getBaseElementType - Returns the innermost element type of an array type.
comment|/// For example, will return "int" for int[m][n]
name|QualType
name|getBaseElementType
parameter_list|(
specifier|const
name|ArrayType
modifier|*
name|VAT
parameter_list|)
function_decl|;
comment|/// getBaseElementType - Returns the innermost element type of a type
comment|/// (which needn't actually be an array type).
name|QualType
name|getBaseElementType
parameter_list|(
name|QualType
name|QT
parameter_list|)
function_decl|;
comment|/// getConstantArrayElementCount - Returns number of constant array elements.
name|uint64_t
name|getConstantArrayElementCount
argument_list|(
specifier|const
name|ConstantArrayType
operator|*
name|CA
argument_list|)
decl|const
decl_stmt|;
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
comment|/// getPromotedIntegerType - Returns the type that Promotable will
comment|/// promote to: C99 6.3.1.1p2, assuming that Promotable is a promotable
comment|/// integer type.
name|QualType
name|getPromotedIntegerType
parameter_list|(
name|QualType
name|PromotableType
parameter_list|)
function_decl|;
comment|/// \brief Whether this is a promotable bitfield reference according
comment|/// to C99 6.3.1.1p2, bullet 2 (and GCC extensions).
comment|///
comment|/// \returns the type this bit-field will promote to, or NULL if no
comment|/// promotion occurs.
name|QualType
name|isPromotableBitField
parameter_list|(
name|Expr
modifier|*
name|E
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
name|ObjCIdTypedefType
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
name|ObjCClassTypedefType
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
return|return
name|T
operator|==
name|ObjCSelTypedefType
return|;
block|}
name|bool
name|QualifiedIdConformsQualifiedId
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|)
function_decl|;
name|bool
name|ObjCQualifiedIdTypesAreCompatible
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|,
name|bool
name|ForCompare
parameter_list|)
function_decl|;
comment|// Check the safety of assignment from LHS to RHS
name|bool
name|canAssignObjCInterfaces
parameter_list|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|LHSOPT
parameter_list|,
specifier|const
name|ObjCObjectPointerType
modifier|*
name|RHSOPT
parameter_list|)
function_decl|;
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
name|QualType
name|areCommonBaseCompatible
parameter_list|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|LHSOPT
parameter_list|,
specifier|const
name|ObjCObjectPointerType
modifier|*
name|RHSOPT
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
comment|/// UsualArithmeticConversionsType - handles the various conversions
comment|/// that are common to binary operators (C99 6.3.1.8, C++ [expr]p9)
comment|/// and returns the result type of that conversion.
name|QualType
name|UsualArithmeticConversionsType
parameter_list|(
name|QualType
name|lhs
parameter_list|,
name|QualType
name|rhs
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
comment|/// \brief Get the implementation of ObjCInterfaceDecl,or NULL if none exists.
name|ObjCImplementationDecl
modifier|*
name|getObjCImplementation
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Get the implementation of ObjCCategoryDecl, or NULL if none exists.
name|ObjCCategoryImplDecl
modifier|*
name|getObjCImplementation
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Set the implementation of ObjCInterfaceDecl.
name|void
name|setObjCImplementation
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|IFaceD
parameter_list|,
name|ObjCImplementationDecl
modifier|*
name|ImplD
parameter_list|)
function_decl|;
comment|/// \brief Set the implementation of ObjCCategoryDecl.
name|void
name|setObjCImplementation
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|CatD
parameter_list|,
name|ObjCCategoryImplDecl
modifier|*
name|ImplD
parameter_list|)
function_decl|;
comment|/// \brief Allocate an uninitialized TypeSourceInfo.
comment|///
comment|/// The caller should initialize the memory held by TypeSourceInfo using
comment|/// the TypeLoc wrappers.
comment|///
comment|/// \param T the type that will be the basis for type source info. This type
comment|/// should refer to how the declarator was written in source code, not to
comment|/// what type semantic analysis resolved the declarator to.
comment|///
comment|/// \param Size the size of the type info to create, or 0 if the size
comment|/// should be calculated based on the type.
name|TypeSourceInfo
modifier|*
name|CreateTypeSourceInfo
parameter_list|(
name|QualType
name|T
parameter_list|,
name|unsigned
name|Size
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Allocate a TypeSourceInfo where all locations have been
comment|/// initialized to a given location, which defaults to the empty
comment|/// location.
name|TypeSourceInfo
modifier|*
name|getTrivialTypeSourceInfo
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
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
name|CanQualType
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
comment|/// @brief Utility function for constructing a nullary selector.
specifier|static
specifier|inline
name|Selector
name|GetNullarySelector
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
block|{
name|IdentifierInfo
modifier|*
name|II
init|=
operator|&
name|Ctx
operator|.
name|Idents
operator|.
name|get
argument_list|(
name|name
argument_list|)
decl_stmt|;
return|return
name|Ctx
operator|.
name|Selectors
operator|.
name|getSelector
argument_list|(
literal|0
argument_list|,
operator|&
name|II
argument_list|)
return|;
block|}
comment|/// @brief Utility function for constructing an unary selector.
specifier|static
specifier|inline
name|Selector
name|GetUnarySelector
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
block|{
name|IdentifierInfo
modifier|*
name|II
init|=
operator|&
name|Ctx
operator|.
name|Idents
operator|.
name|get
argument_list|(
name|name
argument_list|)
decl_stmt|;
return|return
name|Ctx
operator|.
name|Selectors
operator|.
name|getSelector
argument_list|(
literal|1
argument_list|,
operator|&
name|II
argument_list|)
return|;
block|}
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

