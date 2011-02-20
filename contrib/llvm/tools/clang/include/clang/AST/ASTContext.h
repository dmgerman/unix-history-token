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
file|"clang/Basic/PartialDiagnostic.h"
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
file|"clang/AST/UsuallyTinyPtrVector.h"
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
file|"llvm/ADT/SmallPtrSet.h"
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
name|class
name|raw_ostream
decl_stmt|;
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
name|Diagnostic
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|ExternalASTSource
decl_stmt|;
name|class
name|ASTMutationListener
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
name|class
name|CXXABI
decl_stmt|;
comment|// Decls
name|class
name|DeclContext
decl_stmt|;
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
name|MangleContext
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
name|StoredDeclsMap
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|TemplateTemplateParmDecl
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
name|class
name|UnresolvedSetIterator
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
name|ASTContext
modifier|&
name|this_
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
name|mutable
name|std
operator|::
name|vector
operator|<
name|Type
operator|*
operator|>
name|Types
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ExtQuals
operator|>
name|ExtQualNodes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ComplexType
operator|>
name|ComplexTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|PointerType
operator|>
name|PointerTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|BlockPointerType
operator|>
name|BlockPointerTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|LValueReferenceType
operator|>
name|LValueReferenceTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|RValueReferenceType
operator|>
name|RValueReferenceTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|MemberPointerType
operator|>
name|MemberPointerTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ConstantArrayType
operator|>
name|ConstantArrayTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|IncompleteArrayType
operator|>
name|IncompleteArrayTypes
expr_stmt|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|VariableArrayType
operator|*
operator|>
name|VariableArrayTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentSizedArrayType
operator|>
name|DependentSizedArrayTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentSizedExtVectorType
operator|>
name|DependentSizedExtVectorTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|VectorType
operator|>
name|VectorTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionNoProtoType
operator|>
name|FunctionNoProtoTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionProtoType
operator|>
name|FunctionProtoTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentTypeOfExprType
operator|>
name|DependentTypeOfExprTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentDecltypeType
operator|>
name|DependentDecltypeTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|TemplateTypeParmType
operator|>
name|TemplateTypeParmTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|SubstTemplateTypeParmType
operator|>
name|SubstTemplateTypeParmTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|SubstTemplateTypeParmPackType
operator|>
name|SubstTemplateTypeParmPackTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|ContextualFoldingSet
operator|<
name|TemplateSpecializationType
operator|,
name|ASTContext
operator|&
operator|>
name|TemplateSpecializationTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ParenType
operator|>
name|ParenTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ElaboratedType
operator|>
name|ElaboratedTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentNameType
operator|>
name|DependentNameTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|ContextualFoldingSet
operator|<
name|DependentTemplateSpecializationType
operator|,
name|ASTContext
operator|&
operator|>
name|DependentTemplateSpecializationTypes
expr_stmt|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|PackExpansionType
operator|>
name|PackExpansionTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ObjCObjectTypeImpl
operator|>
name|ObjCObjectTypes
expr_stmt|;
name|mutable
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
name|AttributedType
operator|>
name|AttributedTypes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|QualifiedTemplateName
operator|>
name|QualifiedTemplateNames
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentTemplateName
operator|>
name|DependentTemplateNames
expr_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|SubstTemplateTemplateParmPackStorage
operator|>
name|SubstTemplateTemplateParmPacks
expr_stmt|;
comment|/// \brief The set of nested name specifiers.
comment|///
comment|/// This set is managed by the NestedNameSpecifier class.
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|NestedNameSpecifier
operator|>
name|NestedNameSpecifiers
expr_stmt|;
name|mutable
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
name|mutable
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
name|mutable
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
comment|/// \brief Mapping from __block VarDecls to their copy initialization expr.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|Expr
operator|*
operator|>
name|BlockVarCopyInits
expr_stmt|;
comment|/// \brief Representation of a "canonical" template template parameter that
comment|/// is used in canonical template names.
name|class
name|CanonicalTemplateTemplateParm
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
name|TemplateTemplateParmDecl
operator|*
name|Parm
block|;
name|public
operator|:
name|CanonicalTemplateTemplateParm
argument_list|(
name|TemplateTemplateParmDecl
operator|*
name|Parm
argument_list|)
operator|:
name|Parm
argument_list|(
argument|Parm
argument_list|)
block|{ }
name|TemplateTemplateParmDecl
operator|*
name|getParam
argument_list|()
specifier|const
block|{
return|return
name|Parm
return|;
block|}
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&ID
argument_list|)
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Parm
argument_list|)
block|; }
specifier|static
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|TemplateTemplateParmDecl
operator|*
name|Parm
argument_list|)
block|;   }
decl_stmt|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|CanonicalTemplateTemplateParm
operator|>
name|CanonTemplateTemplateParms
expr_stmt|;
name|TemplateTemplateParmDecl
modifier|*
name|getCanonicalTemplateTemplateParmDecl
argument_list|(
name|TemplateTemplateParmDecl
operator|*
name|TTP
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Whether __[u]int128_t identifier is installed.
name|bool
name|IsInt128Installed
decl_stmt|;
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
name|mutable
name|RecordDecl
modifier|*
name|CFConstantStringTypeDecl
decl_stmt|;
name|mutable
name|RecordDecl
modifier|*
name|NSConstantStringTypeDecl
decl_stmt|;
name|mutable
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
name|mutable
name|RecordDecl
modifier|*
name|BlockDescriptorType
decl_stmt|;
comment|/// \brief Type for the Block descriptor for Blocks CodeGen.
name|mutable
name|RecordDecl
modifier|*
name|BlockDescriptorExtendedType
decl_stmt|;
comment|/// \brief Declaration for the CUDA cudaConfigureCall function.
name|FunctionDecl
modifier|*
name|cudaConfigureCallDecl
decl_stmt|;
name|TypeSourceInfo
name|NullTypeSourceInfo
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
name|AttrVec
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
comment|/// \brief Mapping that stores the methods overridden by a given C++
comment|/// member function.
comment|///
comment|/// Since most C++ member functions aren't virtual and therefore
comment|/// don't override anything, we store the overridden functions in
comment|/// this map on the side rather than within the CXXMethodDecl structure.
typedef|typedef
name|UsuallyTinyPtrVector
operator|<
specifier|const
name|CXXMethodDecl
operator|>
name|CXXMethodVector
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXMethodDecl
operator|*
operator|,
name|CXXMethodVector
operator|>
name|OverriddenMethods
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
comment|/// \brief The allocator used to create AST objects.
comment|///
comment|/// AST objects are never destructed; rather, all memory associated with the
comment|/// AST objects will be released when the ASTContext itself is destroyed.
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|BumpAlloc
expr_stmt|;
comment|/// \brief Allocator for partial diagnostics.
name|PartialDiagnostic
operator|::
name|StorageAllocator
name|DiagAllocator
expr_stmt|;
comment|/// \brief The current C++ ABI.
name|llvm
operator|::
name|OwningPtr
operator|<
name|CXXABI
operator|>
name|ABI
expr_stmt|;
name|CXXABI
modifier|*
name|createCXXABI
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|T
parameter_list|)
function_decl|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
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
name|mutable
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
name|ASTMutationListener
modifier|*
name|Listener
decl_stmt|;
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
argument_list|(
name|unsigned
name|Size
argument_list|,
name|unsigned
name|Align
operator|=
literal|8
argument_list|)
decl|const
block|{
return|return
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
argument_list|(
name|void
operator|*
name|Ptr
argument_list|)
decl|const
block|{ }
name|PartialDiagnostic
operator|::
name|StorageAllocator
operator|&
name|getDiagAllocator
argument_list|()
block|{
return|return
name|DiagAllocator
return|;
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
name|Diagnostic
operator|&
name|getDiagnostics
argument_list|()
specifier|const
expr_stmt|;
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
name|AttrVec
modifier|&
name|getDeclAttrs
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Erase the attributes corresponding to the given declaration.
name|void
name|eraseDeclAttrs
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
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
parameter_list|,
name|SourceLocation
name|PointOfInstantiation
init|=
name|SourceLocation
argument_list|()
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
comment|// Access to the set of methods overridden by the given C++ method.
typedef|typedef
name|CXXMethodVector
operator|::
name|iterator
name|overridden_cxx_method_iterator
expr_stmt|;
name|overridden_cxx_method_iterator
name|overridden_methods_begin
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|)
decl|const
decl_stmt|;
name|overridden_cxx_method_iterator
name|overridden_methods_end
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|overridden_methods_size
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Note that the given C++ \p Method overrides the given \p
comment|/// Overridden method.
name|void
name|addOverriddenMethod
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|Overridden
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
argument|unsigned size_reserve
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
comment|/// \brief Attach an AST mutation listener to the AST context.
comment|///
comment|/// The AST mutation listener provides the ability to track modifications to
comment|/// the abstract syntax tree entities committed after they were initially
comment|/// created.
name|void
name|setASTMutationListener
parameter_list|(
name|ASTMutationListener
modifier|*
name|Listener
parameter_list|)
block|{
name|this
operator|->
name|Listener
operator|=
name|Listener
expr_stmt|;
block|}
comment|/// \brief Retrieve a pointer to the AST mutation listener associated
comment|/// with this AST context, if any.
name|ASTMutationListener
operator|*
name|getASTMutationListener
argument_list|()
specifier|const
block|{
return|return
name|Listener
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
argument_list|(
specifier|const
name|Type
operator|*
name|Base
argument_list|,
name|Qualifiers
name|Quals
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getTypeDeclTypeSlow
argument_list|(
specifier|const
name|TypeDecl
operator|*
name|Decl
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
comment|/// getAddSpaceQualType - Return the uniqued reference to the type for an
comment|/// address space qualified type with the specified type and address space.
comment|/// The resulting type has a union of the qualifiers from T and the address
comment|/// space. If T already has an address space specifier, it is silently
comment|/// replaced.
name|QualType
name|getAddrSpaceQualType
argument_list|(
name|QualType
name|T
argument_list|,
name|unsigned
name|AddressSpace
argument_list|)
decl|const
decl_stmt|;
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
decl|const
decl_stmt|;
comment|/// getRestrictType - Returns the uniqued reference to the type for a
comment|/// 'restrict' qualified type.  The resulting type has a union of the
comment|/// qualifiers from T and 'restrict'.
name|QualType
name|getRestrictType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
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
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|T
operator|.
name|withFastQualifiers
argument_list|(
name|Qualifiers
operator|::
name|Volatile
argument_list|)
return|;
block|}
comment|/// getConstType - Returns the uniqued reference to the type for a
comment|/// 'const' qualified type.  The resulting type has a union of the
comment|/// qualifiers from T and 'const'.
comment|///
comment|/// It can be reasonably expected that this will always be
comment|/// equivalent to calling T.withConst().
name|QualType
name|getConstType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|T
operator|.
name|withConst
argument_list|()
return|;
block|}
comment|/// adjustFunctionType - Change the ExtInfo on a function type.
specifier|const
name|FunctionType
modifier|*
name|adjustFunctionType
argument_list|(
specifier|const
name|FunctionType
operator|*
name|Fn
argument_list|,
name|FunctionType
operator|::
name|ExtInfo
name|EInfo
argument_list|)
decl_stmt|;
comment|/// getComplexType - Return the uniqued reference to the type for a complex
comment|/// number with the specified element type.
name|QualType
name|getComplexType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
name|CanQualType
name|getComplexType
argument_list|(
name|CanQualType
name|T
argument_list|)
decl|const
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
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
name|CanQualType
name|getPointerType
argument_list|(
name|CanQualType
name|T
argument_list|)
decl|const
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
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
comment|/// This gets the struct used to keep track of the descriptor for pointer to
comment|/// blocks.
name|QualType
name|getBlockDescriptorType
argument_list|()
specifier|const
expr_stmt|;
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
argument_list|()
specifier|const
expr_stmt|;
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
argument_list|()
specifier|const
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
name|void
name|setcudaConfigureCallDecl
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
block|{
name|cudaConfigureCallDecl
operator|=
name|FD
expr_stmt|;
block|}
name|FunctionDecl
modifier|*
name|getcudaConfigureCallDecl
parameter_list|()
block|{
return|return
name|cudaConfigureCallDecl
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
name|SmallVectorImpl
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
comment|/// This builds the struct used for __block variables.
name|QualType
name|BuildByRefType
argument_list|(
name|llvm
operator|::
name|StringRef
name|DeclName
argument_list|,
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true iff we need copy/dispose helpers for the given type.
name|bool
name|BlockRequiresCopying
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getLValueReferenceType - Return the uniqued reference to the type for an
comment|/// lvalue reference to the specified type.
name|QualType
name|getLValueReferenceType
argument_list|(
name|QualType
name|T
argument_list|,
name|bool
name|SpelledAsLValue
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// getRValueReferenceType - Return the uniqued reference to the type for an
comment|/// rvalue reference to the specified type.
name|QualType
name|getRValueReferenceType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
comment|/// getMemberPointerType - Return the uniqued reference to the type for a
comment|/// member pointer to the specified type in the specified class. The class
comment|/// is a Type because it could be a dependent name.
name|QualType
name|getMemberPointerType
argument_list|(
name|QualType
name|T
argument_list|,
specifier|const
name|Type
operator|*
name|Cls
argument_list|)
decl|const
decl_stmt|;
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
name|IndexTypeQuals
argument_list|,
name|SourceRange
name|Brackets
argument_list|)
decl|const
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
name|IndexTypeQuals
argument_list|,
name|SourceRange
name|Brackets
argument_list|)
decl|const
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
name|IndexTypeQuals
argument_list|)
decl|const
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
name|IndexTypeQuals
argument_list|)
decl|const
decl_stmt|;
comment|/// getVariableArrayDecayedType - Returns a vla type where known sizes
comment|/// are replaced with [*].
name|QualType
name|getVariableArrayDecayedType
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getVectorType - Return the unique reference to a vector type of
comment|/// the specified element type and size. VectorType must be a built-in type.
name|QualType
name|getVectorType
argument_list|(
name|QualType
name|VectorType
argument_list|,
name|unsigned
name|NumElts
argument_list|,
name|VectorType
operator|::
name|VectorKind
name|VecKind
argument_list|)
decl|const
decl_stmt|;
comment|/// getExtVectorType - Return the unique reference to an extended vector type
comment|/// of the specified element type and size.  VectorType must be a built-in
comment|/// type.
name|QualType
name|getExtVectorType
argument_list|(
name|QualType
name|VectorType
argument_list|,
name|unsigned
name|NumElts
argument_list|)
decl|const
decl_stmt|;
comment|/// getDependentSizedExtVectorType - Returns a non-unique reference to
comment|/// the type for a dependently-sized vector of the specified element
comment|/// type. FIXME: We will need these to be uniqued, or at least
comment|/// comparable, at some point.
name|QualType
name|getDependentSizedExtVectorType
argument_list|(
name|QualType
name|VectorType
argument_list|,
name|Expr
operator|*
name|SizeExpr
argument_list|,
name|SourceLocation
name|AttrLoc
argument_list|)
decl|const
decl_stmt|;
comment|/// getFunctionNoProtoType - Return a K&R style C function type like 'int()'.
comment|///
name|QualType
name|getFunctionNoProtoType
argument_list|(
name|QualType
name|ResultTy
argument_list|,
specifier|const
name|FunctionType
operator|::
name|ExtInfo
operator|&
name|Info
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getFunctionNoProtoType
argument_list|(
name|QualType
name|ResultTy
argument_list|)
decl|const
block|{
return|return
name|getFunctionNoProtoType
argument_list|(
name|ResultTy
argument_list|,
name|FunctionType
operator|::
name|ExtInfo
argument_list|()
argument_list|)
return|;
block|}
comment|/// getFunctionType - Return a normal function type with a typed
comment|/// argument list.
name|QualType
name|getFunctionType
argument_list|(
name|QualType
name|ResultTy
argument_list|,
specifier|const
name|QualType
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
specifier|const
name|FunctionProtoType
operator|::
name|ExtProtoInfo
operator|&
name|EPI
argument_list|)
decl|const
decl_stmt|;
comment|/// getTypeDeclType - Return the unique reference to the type for
comment|/// the specified type declaration.
name|QualType
name|getTypeDeclType
argument_list|(
specifier|const
name|TypeDecl
operator|*
name|Decl
argument_list|,
specifier|const
name|TypeDecl
operator|*
name|PrevDecl
operator|=
literal|0
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Decl
operator|&&
literal|"Passed null for Decl param"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Decl
operator|->
name|TypeForDecl
condition|)
return|return
name|QualType
argument_list|(
name|Decl
operator|->
name|TypeForDecl
argument_list|,
literal|0
argument_list|)
return|;
if|if
condition|(
name|PrevDecl
condition|)
block|{
name|assert
argument_list|(
name|PrevDecl
operator|->
name|TypeForDecl
operator|&&
literal|"previous decl has no TypeForDecl"
argument_list|)
expr_stmt|;
name|Decl
operator|->
name|TypeForDecl
operator|=
name|PrevDecl
operator|->
name|TypeForDecl
expr_stmt|;
return|return
name|QualType
argument_list|(
name|PrevDecl
operator|->
name|TypeForDecl
argument_list|,
literal|0
argument_list|)
return|;
block|}
return|return
name|getTypeDeclTypeSlow
argument_list|(
name|Decl
argument_list|)
return|;
block|}
comment|/// getTypedefType - Return the unique reference to the type for the
comment|/// specified typename decl.
name|QualType
name|getTypedefType
argument_list|(
specifier|const
name|TypedefDecl
operator|*
name|Decl
argument_list|,
name|QualType
name|Canon
operator|=
name|QualType
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getRecordType
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|Decl
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getEnumType
argument_list|(
specifier|const
name|EnumDecl
operator|*
name|Decl
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getInjectedClassNameType
argument_list|(
name|CXXRecordDecl
operator|*
name|Decl
argument_list|,
name|QualType
name|TST
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getAttributedType
argument_list|(
name|AttributedType
operator|::
name|Kind
name|attrKind
argument_list|,
name|QualType
name|modifiedType
argument_list|,
name|QualType
name|equivalentType
argument_list|)
decl_stmt|;
name|QualType
name|getSubstTemplateTypeParmType
argument_list|(
specifier|const
name|TemplateTypeParmType
operator|*
name|Replaced
argument_list|,
name|QualType
name|Replacement
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getSubstTemplateTypeParmPackType
parameter_list|(
specifier|const
name|TemplateTypeParmType
modifier|*
name|Replaced
parameter_list|,
specifier|const
name|TemplateArgument
modifier|&
name|ArgPack
parameter_list|)
function_decl|;
name|QualType
name|getTemplateTypeParmType
argument_list|(
name|unsigned
name|Depth
argument_list|,
name|unsigned
name|Index
argument_list|,
name|bool
name|ParameterPack
argument_list|,
name|IdentifierInfo
operator|*
name|Name
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getTemplateSpecializationType
argument_list|(
name|TemplateName
name|T
argument_list|,
specifier|const
name|TemplateArgument
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|QualType
name|Canon
operator|=
name|QualType
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getCanonicalTemplateSpecializationType
argument_list|(
name|TemplateName
name|T
argument_list|,
specifier|const
name|TemplateArgument
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getTemplateSpecializationType
argument_list|(
name|TemplateName
name|T
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|Args
argument_list|,
name|QualType
name|Canon
operator|=
name|QualType
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|TypeSourceInfo
modifier|*
name|getTemplateSpecializationTypeInfo
argument_list|(
name|TemplateName
name|T
argument_list|,
name|SourceLocation
name|TLoc
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|Args
argument_list|,
name|QualType
name|Canon
operator|=
name|QualType
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getParenType
argument_list|(
name|QualType
name|NamedType
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getElaboratedType
argument_list|(
name|ElaboratedTypeKeyword
name|Keyword
argument_list|,
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
name|QualType
name|NamedType
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getDependentNameType
argument_list|(
name|ElaboratedTypeKeyword
name|Keyword
argument_list|,
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|Name
argument_list|,
name|QualType
name|Canon
operator|=
name|QualType
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getDependentTemplateSpecializationType
argument_list|(
name|ElaboratedTypeKeyword
name|Keyword
argument_list|,
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|Name
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|Args
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getDependentTemplateSpecializationType
argument_list|(
name|ElaboratedTypeKeyword
name|Keyword
argument_list|,
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|Name
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
specifier|const
name|TemplateArgument
operator|*
name|Args
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getPackExpansionType
argument_list|(
name|QualType
name|Pattern
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|)
decl_stmt|;
name|QualType
name|getObjCInterfaceType
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|Decl
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getObjCObjectType
argument_list|(
name|QualType
name|Base
argument_list|,
name|ObjCProtocolDecl
operator|*
specifier|const
operator|*
name|Protocols
argument_list|,
name|unsigned
name|NumProtocols
argument_list|)
decl|const
decl_stmt|;
comment|/// getObjCObjectPointerType - Return a ObjCObjectPointerType type
comment|/// for the given ObjCObjectType.
name|QualType
name|getObjCObjectPointerType
argument_list|(
name|QualType
name|OIT
argument_list|)
decl|const
decl_stmt|;
comment|/// getTypeOfType - GCC extension.
name|QualType
name|getTypeOfExprType
argument_list|(
name|Expr
operator|*
name|e
argument_list|)
decl|const
decl_stmt|;
name|QualType
name|getTypeOfType
argument_list|(
name|QualType
name|t
argument_list|)
decl|const
decl_stmt|;
comment|/// getDecltypeType - C++0x decltype.
name|QualType
name|getDecltypeType
argument_list|(
name|Expr
operator|*
name|e
argument_list|)
decl|const
decl_stmt|;
comment|/// getAutoType - C++0x deduced auto type.
name|QualType
name|getAutoType
argument_list|(
name|QualType
name|DeducedType
argument_list|)
decl|const
decl_stmt|;
comment|/// getTagDeclType - Return the unique reference to the type for the
comment|/// specified TagDecl (struct/union/class/enum) decl.
name|QualType
name|getTagDeclType
argument_list|(
specifier|const
name|TagDecl
operator|*
name|Decl
argument_list|)
decl|const
decl_stmt|;
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
argument_list|()
specifier|const
expr_stmt|;
comment|// getNSConstantStringType - Return the C structure type used to represent
comment|// constant NSStrings.
name|QualType
name|getNSConstantStringType
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the structure type used to representation NSStrings, or NULL
comment|/// if it hasn't yet been built.
name|QualType
name|getRawNSConstantStringType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|NSConstantStringTypeDecl
condition|)
return|return
name|getTagDeclType
argument_list|(
name|NSConstantStringTypeDecl
argument_list|)
return|;
return|return
name|QualType
argument_list|()
return|;
block|}
end_decl_stmt

begin_function_decl
name|void
name|setNSConstantStringType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the structure type used to representation CFStrings, or NULL
end_comment

begin_comment
comment|/// if it hasn't yet been built.
end_comment

begin_expr_stmt
name|QualType
name|getRawCFConstantStringType
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
name|QualType
argument_list|()
return|;
end_return

begin_macro
unit|}   void
name|setCFConstantStringType
argument_list|(
argument|QualType T
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This setter/getter represents the ObjC type for an NSConstantString.
end_comment

begin_function_decl
name|void
name|setObjCConstantStringInterface
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|QualType
name|getObjCConstantStringInterface
argument_list|()
specifier|const
block|{
return|return
name|ObjCConstantStringType
return|;
block|}
end_expr_stmt

begin_comment
comment|//// This gets the struct used to keep track of fast enumerations.
end_comment

begin_expr_stmt
name|QualType
name|getObjCFastEnumerationStateType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the ObjCFastEnumerationState type, or NULL if it hasn't yet
end_comment

begin_comment
comment|/// been built.
end_comment

begin_expr_stmt
name|QualType
name|getRawObjCFastEnumerationStateType
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
name|QualType
argument_list|()
return|;
end_return

begin_macro
unit|}    void
name|setObjCFastEnumerationStateType
argument_list|(
argument|QualType T
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Set the type for the C FILE type.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Retrieve the C FILE type.
end_comment

begin_expr_stmt
name|QualType
name|getFILEType
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
name|QualType
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the type for the C jmp_buf type.
end_comment

begin_macro
unit|void
name|setjmp_bufDecl
argument_list|(
argument|TypeDecl *jmp_bufDecl
argument_list|)
end_macro

begin_block
block|{
name|this
operator|->
name|jmp_bufDecl
operator|=
name|jmp_bufDecl
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the C jmp_buf type.
end_comment

begin_expr_stmt
name|QualType
name|getjmp_bufType
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
name|QualType
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the type for the C sigjmp_buf type.
end_comment

begin_macro
unit|void
name|setsigjmp_bufDecl
argument_list|(
argument|TypeDecl *sigjmp_bufDecl
argument_list|)
end_macro

begin_block
block|{
name|this
operator|->
name|sigjmp_bufDecl
operator|=
name|sigjmp_bufDecl
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the C sigjmp_buf type.
end_comment

begin_expr_stmt
name|QualType
name|getsigjmp_bufType
argument_list|()
specifier|const
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
end_expr_stmt

begin_return
return|return
name|QualType
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief The result type of logical operations, '<', '>', '!=', etc.
end_comment

begin_macro
unit|QualType
name|getLogicalOperationType
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getLangOptions
argument_list|()
operator|.
name|CPlusPlus
operator|?
name|BoolTy
operator|:
name|IntTy
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getObjCEncodingForType - Emit the ObjC type encoding for the
end_comment

begin_comment
comment|/// given type into \arg S. If \arg NameFields is specified then
end_comment

begin_comment
comment|/// record field names are also encoded.
end_comment

begin_decl_stmt
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
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getLegacyIntegralTypeEncoding
argument_list|(
name|QualType
operator|&
name|t
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Put the string version of type qualifiers into S.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// getObjCEncodingForFunctionDecl - Returns the encoded type for this
end_comment

begin_comment
comment|//function.  This is in the same format as Objective-C method encodings.
end_comment

begin_decl_stmt
name|void
name|getObjCEncodingForFunctionDecl
argument_list|(
specifier|const
name|FunctionDecl
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
end_decl_stmt

begin_comment
comment|/// getObjCEncodingForMethodDecl - Return the encoded type for this method
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_decl_stmt
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
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getObjCEncodingForBlock - Return the encoded type for this block
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getObjCEncodingForBlock
argument_list|(
argument|const BlockExpr *blockExpr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getObjCEncodingForPropertyDecl - Return the encoded type for
end_comment

begin_comment
comment|/// this method declaration. If non-NULL, Container must be either
end_comment

begin_comment
comment|/// an ObjCCategoryImplDecl or ObjCImplementationDecl; it should
end_comment

begin_comment
comment|/// only be NULL when getting encodings for protocol properties.
end_comment

begin_decl_stmt
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
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ProtocolCompatibleWithProtocol
argument_list|(
name|ObjCProtocolDecl
operator|*
name|lProto
argument_list|,
name|ObjCProtocolDecl
operator|*
name|rProto
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getObjCEncodingTypeSize returns size of type for objective-c encoding
end_comment

begin_comment
comment|/// purpose in characters.
end_comment

begin_decl_stmt
name|CharUnits
name|getObjCEncodingTypeSize
argument_list|(
name|QualType
name|t
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether __[u]int128_t identifier is installed.
end_comment

begin_expr_stmt
name|bool
name|isInt128Installed
argument_list|()
specifier|const
block|{
return|return
name|IsInt128Installed
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setInt128Installed
parameter_list|()
block|{
name|IsInt128Installed
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// This setter/getter represents the ObjC 'id' type. It is setup lazily, by
end_comment

begin_comment
comment|/// Sema.  id is always a (typedef for a) pointer type, a pointer to a struct.
end_comment

begin_expr_stmt
name|QualType
name|getObjCIdType
argument_list|()
specifier|const
block|{
return|return
name|ObjCIdTypedefType
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setObjCIdType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setObjCSelType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|QualType
name|getObjCSelType
argument_list|()
specifier|const
block|{
return|return
name|ObjCSelTypedefType
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setObjCProtoType
parameter_list|(
name|QualType
name|QT
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|QualType
name|getObjCProtoType
argument_list|()
specifier|const
block|{
return|return
name|ObjCProtoType
return|;
block|}
end_expr_stmt

begin_comment
comment|/// This setter/getter repreents the ObjC 'Class' type. It is setup lazily, by
end_comment

begin_comment
comment|/// Sema.  'Class' is always a (typedef for a) pointer type, a pointer to a
end_comment

begin_comment
comment|/// struct.
end_comment

begin_expr_stmt
name|QualType
name|getObjCClassType
argument_list|()
specifier|const
block|{
return|return
name|ObjCClassTypedefType
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setObjCClassType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setBuiltinVaListType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|QualType
name|getBuiltinVaListType
argument_list|()
specifier|const
block|{
return|return
name|BuiltinVaListType
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getCVRQualifiedType - Returns a type with additional const,
end_comment

begin_comment
comment|/// volatile, or restrict qualifiers.
end_comment

begin_decl_stmt
name|QualType
name|getCVRQualifiedType
argument_list|(
name|QualType
name|T
argument_list|,
name|unsigned
name|CVR
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// getQualifiedType - Returns a type with additional qualifiers.
end_comment

begin_decl_stmt
name|QualType
name|getQualifiedType
argument_list|(
name|QualType
name|T
argument_list|,
name|Qualifiers
name|Qs
argument_list|)
decl|const
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
parameter_list|(
name|Qs
parameter_list|)
function_decl|;
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
end_decl_stmt

begin_comment
comment|/// getQualifiedType - Returns a type with additional qualifiers.
end_comment

begin_decl_stmt
name|QualType
name|getQualifiedType
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|,
name|Qualifiers
name|Qs
argument_list|)
decl|const
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
end_decl_stmt

begin_decl_stmt
name|DeclarationNameInfo
name|getNameForTemplate
argument_list|(
name|TemplateName
name|Name
argument_list|,
name|SourceLocation
name|NameLoc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateName
name|getOverloadedTemplateName
argument_list|(
name|UnresolvedSetIterator
name|Begin
argument_list|,
name|UnresolvedSetIterator
name|End
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateName
name|getQualifiedTemplateName
argument_list|(
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
name|bool
name|TemplateKeyword
argument_list|,
name|TemplateDecl
operator|*
name|Template
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateName
name|getDependentTemplateName
argument_list|(
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateName
name|getDependentTemplateName
argument_list|(
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|,
name|OverloadedOperatorKind
name|Operator
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateName
name|getSubstTemplateTemplateParmPack
argument_list|(
name|TemplateTemplateParmDecl
operator|*
name|Param
argument_list|,
specifier|const
name|TemplateArgument
operator|&
name|ArgPack
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_enum
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
end_enum

begin_comment
comment|/// GetBuiltinType - Return the type for the specified builtin.  If
end_comment

begin_comment
comment|/// IntegerConstantArgs is non-null, it is filled in with a bitmask of
end_comment

begin_comment
comment|/// arguments to the builtin that are required to be integer constant
end_comment

begin_comment
comment|/// expressions.
end_comment

begin_decl_stmt
name|QualType
name|GetBuiltinType
argument_list|(
name|unsigned
name|ID
argument_list|,
name|GetBuiltinTypeError
operator|&
name|Error
argument_list|,
name|unsigned
operator|*
name|IntegerConstantArgs
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|CanQualType
name|getFromTargetType
argument_list|(
name|unsigned
name|Type
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         Type Predicates.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|/// getObjCGCAttr - Returns one of GCNone, Weak or Strong objc's
end_comment

begin_comment
comment|/// garbage collection attribute.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|Qualifiers
operator|::
name|GC
name|getObjCGCAttrKind
argument_list|(
argument|QualType Ty
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// areCompatibleVectorTypes - Return true if the given vector types
end_comment

begin_comment
comment|/// are of the same unqualified type or if they are equivalent to the same
end_comment

begin_comment
comment|/// GCC vector type, ignoring whether they are target-specific (AltiVec or
end_comment

begin_comment
comment|/// Neon) types.
end_comment

begin_function_decl
name|bool
name|areCompatibleVectorTypes
parameter_list|(
name|QualType
name|FirstVec
parameter_list|,
name|QualType
name|SecondVec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// isObjCNSObjectType - Return true if this is an NSObject object with
end_comment

begin_comment
comment|/// its NSObject attribute set.
end_comment

begin_decl_stmt
name|bool
name|isObjCNSObjectType
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         Type Sizing and Analysis
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// getFloatTypeSemantics - Return the APFloat 'semantics' for the specified
end_comment

begin_comment
comment|/// scalar floating point type.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// getTypeInfo - Get the size and alignment of the specified complete type in
end_comment

begin_comment
comment|/// bits.
end_comment

begin_expr_stmt
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
argument|const Type *T
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
specifier|const
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
end_expr_stmt

begin_comment
comment|/// getTypeSize - Return the size of the specified type, in bits.  This method
end_comment

begin_comment
comment|/// does not work on incomplete types.
end_comment

begin_decl_stmt
name|uint64_t
name|getTypeSize
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|getTypeSize
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// getCharWidth - Return the size of the character type, in bits
end_comment

begin_expr_stmt
name|uint64_t
name|getCharWidth
argument_list|()
specifier|const
block|{
return|return
name|getTypeSize
argument_list|(
name|CharTy
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// toCharUnitsFromBits - Convert a size in bits to a size in characters.
end_comment

begin_decl_stmt
name|CharUnits
name|toCharUnitsFromBits
argument_list|(
name|int64_t
name|BitSize
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// toBits - Convert a size in characters to a size in bits.
end_comment

begin_decl_stmt
name|int64_t
name|toBits
argument_list|(
name|CharUnits
name|CharSize
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getTypeSizeInChars - Return the size of the specified type, in characters.
end_comment

begin_comment
comment|/// This method does not work on incomplete types.
end_comment

begin_decl_stmt
name|CharUnits
name|getTypeSizeInChars
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CharUnits
name|getTypeSizeInChars
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getTypeAlign - Return the ABI-specified alignment of a type, in bits.
end_comment

begin_comment
comment|/// This method does not work on incomplete types.
end_comment

begin_decl_stmt
name|unsigned
name|getTypeAlign
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getTypeAlign
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// getTypeAlignInChars - Return the ABI-specified alignment of a type, in
end_comment

begin_comment
comment|/// characters. This method does not work on incomplete types.
end_comment

begin_decl_stmt
name|CharUnits
name|getTypeAlignInChars
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CharUnits
name|getTypeAlignInChars
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|CharUnits
operator|,
name|CharUnits
operator|>
name|getTypeInfoInChars
argument_list|(
argument|const Type *T
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|CharUnits
operator|,
name|CharUnits
operator|>
name|getTypeInfoInChars
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getPreferredTypeAlign - Return the "preferred" alignment of the specified
end_comment

begin_comment
comment|/// type for the current target in bits.  This can be different than the ABI
end_comment

begin_comment
comment|/// alignment in cases where it is beneficial for performance to overalign
end_comment

begin_comment
comment|/// a data type.
end_comment

begin_decl_stmt
name|unsigned
name|getPreferredTypeAlign
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDeclAlign - Return a conservative estimate of the alignment of
end_comment

begin_comment
comment|/// the specified decl.  Note that bitfields do not have a valid alignment, so
end_comment

begin_comment
comment|/// this method will assert on them.
end_comment

begin_comment
comment|/// If @p RefAsPointee, references are treated like their underlying type
end_comment

begin_comment
comment|/// (for alignof), else they're treated like pointers (for CodeGen).
end_comment

begin_decl_stmt
name|CharUnits
name|getDeclAlign
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|bool
name|RefAsPointee
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getASTRecordLayout - Get or compute information about the layout of the
end_comment

begin_comment
comment|/// specified record (struct/union/class), which indicates its size and field
end_comment

begin_comment
comment|/// position information.
end_comment

begin_decl_stmt
specifier|const
name|ASTRecordLayout
modifier|&
name|getASTRecordLayout
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getASTObjCInterfaceLayout - Get or compute information about the
end_comment

begin_comment
comment|/// layout of the specified Objective-C interface.
end_comment

begin_decl_stmt
specifier|const
name|ASTRecordLayout
modifier|&
name|getASTObjCInterfaceLayout
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DumpRecordLayout
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getASTObjCImplementationLayout - Get or compute information about
end_comment

begin_comment
comment|/// the layout of the specified Objective-C implementation. This may
end_comment

begin_comment
comment|/// differ from the interface if synthesized ivars are present.
end_comment

begin_decl_stmt
specifier|const
name|ASTRecordLayout
modifier|&
name|getASTObjCImplementationLayout
argument_list|(
specifier|const
name|ObjCImplementationDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getKeyFunction - Get the key function for the given record decl, or NULL
end_comment

begin_comment
comment|/// if there isn't one.  The key function is, according to the Itanium C++ ABI
end_comment

begin_comment
comment|/// section 5.2.3:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ...the first non-pure virtual function that is not inline at the point
end_comment

begin_comment
comment|/// of class definition.
end_comment

begin_function_decl
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
end_function_decl

begin_decl_stmt
name|bool
name|isNearlyEmpty
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|MangleContext
modifier|*
name|createMangleContext
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
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
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DeepCollectObjCIvars
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OI
argument_list|,
name|bool
name|leafClass
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
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|CountNonClassIvars
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|SmallPtrSet
operator|<
name|ObjCProtocolDecl
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|Protocols
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                            Type Operators
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// getCanonicalType - Return the canonical (structural) type corresponding to
end_comment

begin_comment
comment|/// the specified potentially non-canonical type.  The non-canonical version
end_comment

begin_comment
comment|/// of a type may have many "decorated" versions of types.  Decorators can
end_comment

begin_comment
comment|/// include typedefs, 'typeof' operators, etc. The returned type is guaranteed
end_comment

begin_comment
comment|/// to be free of any of these, allowing two canonical types to be compared
end_comment

begin_comment
comment|/// for exact equality with a simple pointer comparison.
end_comment

begin_decl_stmt
name|CanQualType
name|getCanonicalType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
name|T
operator|.
name|getCanonicalType
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|Type
modifier|*
name|getCanonicalType
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// getCanonicalParamType - Return the canonical parameter type
end_comment

begin_comment
comment|/// corresponding to the specific potentially non-canonical one.
end_comment

begin_comment
comment|/// Qualifiers are stripped off, functions are turned into function
end_comment

begin_comment
comment|/// pointers, and arrays decay one level into pointers.
end_comment

begin_decl_stmt
name|CanQualType
name|getCanonicalParamType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether the given types are equivalent.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Returns this type as a completely-unqualified array type,
end_comment

begin_comment
comment|/// capturing the qualifiers in Quals. This will remove the minimal amount of
end_comment

begin_comment
comment|/// sugaring from the types, similar to the behavior of
end_comment

begin_comment
comment|/// QualType::getUnqualifiedType().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param T is the qualified type, which may be an ArrayType
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Quals will receive the full set of qualifiers that were
end_comment

begin_comment
comment|/// applied to the array.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns if this is an array type, the completely unqualified array type
end_comment

begin_comment
comment|/// that corresponds to it. Otherwise, returns T.getUnqualifiedType().
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Determine whether the given types are equivalent after
end_comment

begin_comment
comment|/// cvr-qualifiers have been removed.
end_comment

begin_function
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
return|return
name|getCanonicalType
argument_list|(
name|T1
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|==
name|getCanonicalType
argument_list|(
name|T2
argument_list|)
operator|.
name|getTypePtr
argument_list|()
return|;
block|}
end_function

begin_function_decl
name|bool
name|UnwrapSimilarPointerTypes
parameter_list|(
name|QualType
modifier|&
name|T1
parameter_list|,
name|QualType
modifier|&
name|T2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieves the "canonical" nested name specifier for a
end_comment

begin_comment
comment|/// given nested name specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The canonical nested name specifier is a nested name specifier
end_comment

begin_comment
comment|/// that uniquely identifies a type or namespace within the type
end_comment

begin_comment
comment|/// system. For example, given:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// namespace N {
end_comment

begin_comment
comment|///   struct S {
end_comment

begin_comment
comment|///     template<typename T> struct X { typename T* type; };
end_comment

begin_comment
comment|///   };
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// template<typename T> struct Y {
end_comment

begin_comment
comment|///   typename N::S::X<T>::type member;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Here, the nested-name-specifier for N::S::X<T>:: will be
end_comment

begin_comment
comment|/// S::X<template-param-0-0>, since 'S' and 'X' are uniquely defined
end_comment

begin_comment
comment|/// by declarations in the type system and the canonical type for
end_comment

begin_comment
comment|/// the template type parameter 'T' is template-param-0-0.
end_comment

begin_decl_stmt
name|NestedNameSpecifier
modifier|*
name|getCanonicalNestedNameSpecifier
argument_list|(
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieves the default calling convention to use for
end_comment

begin_comment
comment|/// C++ instance methods.
end_comment

begin_function_decl
name|CallingConv
name|getDefaultMethodCallConv
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieves the canonical representation of the given
end_comment

begin_comment
comment|/// calling convention.
end_comment

begin_decl_stmt
name|CallingConv
name|getCanonicalCallConv
argument_list|(
name|CallingConv
name|CC
argument_list|)
decl|const
block|{
if|if
condition|(
name|CC
operator|==
name|CC_C
condition|)
return|return
name|CC_Default
return|;
return|return
name|CC
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determines whether two calling conventions name the same
end_comment

begin_comment
comment|/// calling convention.
end_comment

begin_function
name|bool
name|isSameCallConv
parameter_list|(
name|CallingConv
name|lcc
parameter_list|,
name|CallingConv
name|rcc
parameter_list|)
block|{
return|return
operator|(
name|getCanonicalCallConv
argument_list|(
name|lcc
argument_list|)
operator|==
name|getCanonicalCallConv
argument_list|(
name|rcc
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieves the "canonical" template name that refers to a
end_comment

begin_comment
comment|/// given template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The canonical template name is the simplest expression that can
end_comment

begin_comment
comment|/// be used to refer to a given template. For most templates, this
end_comment

begin_comment
comment|/// expression is just the template declaration itself. For example,
end_comment

begin_comment
comment|/// the template std::vector can be referred to via a variety of
end_comment

begin_comment
comment|/// names---std::vector, ::std::vector, vector (if vector is in
end_comment

begin_comment
comment|/// scope), etc.---but all of these names map down to the same
end_comment

begin_comment
comment|/// TemplateDecl, which is used to form the canonical template name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Dependent template names are more interesting. Here, the
end_comment

begin_comment
comment|/// template name could be something like T::template apply or
end_comment

begin_comment
comment|/// std::allocator<T>::template rebind, where the nested name
end_comment

begin_comment
comment|/// specifier itself is dependent. In this case, the canonical
end_comment

begin_comment
comment|/// template name uses the shortest form of the dependent
end_comment

begin_comment
comment|/// nested-name-specifier, which itself contains all canonical
end_comment

begin_comment
comment|/// types, values, and templates.
end_comment

begin_decl_stmt
name|TemplateName
name|getCanonicalTemplateName
argument_list|(
name|TemplateName
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether the given template names refer to the same
end_comment

begin_comment
comment|/// template.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Retrieve the "canonical" template argument.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The canonical template argument is the simplest template argument
end_comment

begin_comment
comment|/// (which may be a type, value, expression, or declaration) that
end_comment

begin_comment
comment|/// expresses the value of the argument.
end_comment

begin_decl_stmt
name|TemplateArgument
name|getCanonicalTemplateArgument
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Arg
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Type Query functions.  If the type is an instance of the specified class,
end_comment

begin_comment
comment|/// return the Type pointer for the underlying maximally pretty type.  This
end_comment

begin_comment
comment|/// is a member of ASTContext because this may need to do some amount of
end_comment

begin_comment
comment|/// canonicalization, e.g. to move type qualifiers into the element type.
end_comment

begin_decl_stmt
specifier|const
name|ArrayType
modifier|*
name|getAsArrayType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|ConstantArrayType
modifier|*
name|getAsConstantArrayType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_decl_stmt
specifier|const
name|VariableArrayType
modifier|*
name|getAsVariableArrayType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_decl_stmt
specifier|const
name|IncompleteArrayType
modifier|*
name|getAsIncompleteArrayType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
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
end_decl_stmt

begin_decl_stmt
specifier|const
name|DependentSizedArrayType
modifier|*
name|getAsDependentSizedArrayType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|DependentSizedArrayType
operator|>
operator|(
name|getAsArrayType
argument_list|(
name|T
argument_list|)
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getBaseElementType - Returns the innermost element type of an array type.
end_comment

begin_comment
comment|/// For example, will return "int" for int[m][n]
end_comment

begin_decl_stmt
name|QualType
name|getBaseElementType
argument_list|(
specifier|const
name|ArrayType
operator|*
name|VAT
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getBaseElementType - Returns the innermost element type of a type
end_comment

begin_comment
comment|/// (which needn't actually be an array type).
end_comment

begin_decl_stmt
name|QualType
name|getBaseElementType
argument_list|(
name|QualType
name|QT
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getConstantArrayElementCount - Returns number of constant array elements.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// getArrayDecayedType - Return the properly qualified result of decaying the
end_comment

begin_comment
comment|/// specified array type to a pointer.  This operation is non-trivial when
end_comment

begin_comment
comment|/// handling typedefs etc.  The canonical type of "T" must be an array type,
end_comment

begin_comment
comment|/// this returns a pointer to a properly qualified element of the array.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See C99 6.7.5.3p7 and C99 6.3.2.1p3.
end_comment

begin_decl_stmt
name|QualType
name|getArrayDecayedType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getPromotedIntegerType - Returns the type that Promotable will
end_comment

begin_comment
comment|/// promote to: C99 6.3.1.1p2, assuming that Promotable is a promotable
end_comment

begin_comment
comment|/// integer type.
end_comment

begin_decl_stmt
name|QualType
name|getPromotedIntegerType
argument_list|(
name|QualType
name|PromotableType
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether this is a promotable bitfield reference according
end_comment

begin_comment
comment|/// to C99 6.3.1.1p2, bullet 2 (and GCC extensions).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the type this bit-field will promote to, or NULL if no
end_comment

begin_comment
comment|/// promotion occurs.
end_comment

begin_decl_stmt
name|QualType
name|isPromotableBitField
argument_list|(
name|Expr
operator|*
name|E
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getIntegerTypeOrder - Returns the highest ranked integer type:
end_comment

begin_comment
comment|/// C99 6.3.1.8p1.  If LHS> RHS, return 1.  If LHS == RHS, return 0. If
end_comment

begin_comment
comment|/// LHS< RHS, return -1.
end_comment

begin_decl_stmt
name|int
name|getIntegerTypeOrder
argument_list|(
name|QualType
name|LHS
argument_list|,
name|QualType
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getFloatingTypeOrder - Compare the rank of the two specified floating
end_comment

begin_comment
comment|/// point types, ignoring the domain of the type (i.e. 'double' ==
end_comment

begin_comment
comment|/// '_Complex double').  If LHS> RHS, return 1.  If LHS == RHS, return 0. If
end_comment

begin_comment
comment|/// LHS< RHS, return -1.
end_comment

begin_decl_stmt
name|int
name|getFloatingTypeOrder
argument_list|(
name|QualType
name|LHS
argument_list|,
name|QualType
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getFloatingTypeOfSizeWithinDomain - Returns a real floating
end_comment

begin_comment
comment|/// point or a complex type (based on typeDomain/typeSize).
end_comment

begin_comment
comment|/// 'typeDomain' is a real floating point or complex type.
end_comment

begin_comment
comment|/// 'typeSize' is a real floating point or complex type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Helper for integer ordering
end_comment

begin_decl_stmt
name|unsigned
name|getIntegerRank
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                    Type Compatibility Predicates
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Compatibility predicates used to check assignment expressions.
end_comment

begin_function_decl
name|bool
name|typesAreCompatible
parameter_list|(
name|QualType
name|T1
parameter_list|,
name|QualType
name|T2
parameter_list|,
name|bool
name|CompareUnqualified
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// C99 6.2.7p1
end_comment

begin_function_decl
name|bool
name|typesAreBlockPointerCompatible
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|bool
name|ObjCQualifiedClassTypesAreCompatible
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Check the safety of assignment from LHS to RHS
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
name|bool
name|canAssignObjCInterfaces
parameter_list|(
specifier|const
name|ObjCObjectType
modifier|*
name|LHS
parameter_list|,
specifier|const
name|ObjCObjectType
modifier|*
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|canAssignObjCInterfacesInBlockPointer
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|bool
name|canBindObjCObjectType
parameter_list|(
name|QualType
name|To
parameter_list|,
name|QualType
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Functions for calculating composite types
end_comment

begin_function_decl
name|QualType
name|mergeTypes
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|,
name|bool
name|OfBlockPointer
init|=
name|false
parameter_list|,
name|bool
name|Unqualified
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|mergeFunctionTypes
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|,
name|bool
name|OfBlockPointer
init|=
name|false
parameter_list|,
name|bool
name|Unqualified
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|mergeFunctionArgumentTypes
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|,
name|bool
name|OfBlockPointer
init|=
name|false
parameter_list|,
name|bool
name|Unqualified
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|mergeTransparentUnionType
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|,
name|bool
name|OfBlockPointer
init|=
name|false
parameter_list|,
name|bool
name|Unqualified
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|mergeObjCGCQualifiers
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ResetObjCLayout
parameter_list|(
specifier|const
name|ObjCContainerDecl
modifier|*
name|CD
parameter_list|)
block|{
name|ObjCLayouts
index|[
name|CD
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                    Integer Predicates
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// The width of an integer, as defined in C99 6.2.6.2. This is the number
end_comment

begin_comment
comment|// of bits in an integer type excluding any padding bits.
end_comment

begin_decl_stmt
name|unsigned
name|getIntWidth
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Per C99 6.2.5p6, for every signed integer type, there is a corresponding
end_comment

begin_comment
comment|// unsigned integer type.  This method takes a signed type, and returns the
end_comment

begin_comment
comment|// corresponding unsigned integer type.
end_comment

begin_function_decl
name|QualType
name|getCorrespondingUnsignedType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                    Type Iterators.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_typedef
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
end_typedef

begin_typedef
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
end_typedef

begin_function
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
end_function

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                    Integer Values
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// MakeIntValue - Make an APSInt of the appropriate width and
end_comment

begin_comment
comment|/// signedness for the given \arg Value and integer \arg Type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|APSInt
name|MakeIntValue
argument_list|(
argument|uint64_t Value
argument_list|,
argument|QualType Type
argument_list|)
specifier|const
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
end_expr_stmt

begin_comment
comment|/// \brief Get the implementation of ObjCInterfaceDecl,or NULL if none exists.
end_comment

begin_function_decl
name|ObjCImplementationDecl
modifier|*
name|getObjCImplementation
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the implementation of ObjCCategoryDecl, or NULL if none exists.
end_comment

begin_function_decl
name|ObjCCategoryImplDecl
modifier|*
name|getObjCImplementation
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief returns true if there is at lease one @implementation in TU.
end_comment

begin_function
name|bool
name|AnyObjCImplementation
parameter_list|()
block|{
return|return
operator|!
name|ObjCImpls
operator|.
name|empty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Set the implementation of ObjCInterfaceDecl.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Set the implementation of ObjCCategoryDecl.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Set the copy inialization expression of a block var decl.
end_comment

begin_function_decl
name|void
name|setBlockVarCopyInits
parameter_list|(
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the copy initialization expression of VarDecl,or NULL if
end_comment

begin_comment
comment|/// none exists.
end_comment

begin_function_decl
name|Expr
modifier|*
name|getBlockVarCopyInits
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Allocate an uninitialized TypeSourceInfo.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The caller should initialize the memory held by TypeSourceInfo using
end_comment

begin_comment
comment|/// the TypeLoc wrappers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param T the type that will be the basis for type source info. This type
end_comment

begin_comment
comment|/// should refer to how the declarator was written in source code, not to
end_comment

begin_comment
comment|/// what type semantic analysis resolved the declarator to.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Size the size of the type info to create, or 0 if the size
end_comment

begin_comment
comment|/// should be calculated based on the type.
end_comment

begin_decl_stmt
name|TypeSourceInfo
modifier|*
name|CreateTypeSourceInfo
argument_list|(
name|QualType
name|T
argument_list|,
name|unsigned
name|Size
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Allocate a TypeSourceInfo where all locations have been
end_comment

begin_comment
comment|/// initialized to a given location, which defaults to the empty
end_comment

begin_comment
comment|/// location.
end_comment

begin_decl_stmt
name|TypeSourceInfo
modifier|*
name|getTrivialTypeSourceInfo
argument_list|(
name|QualType
name|T
argument_list|,
name|SourceLocation
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function
name|TypeSourceInfo
modifier|*
name|getNullTypeSourceInfo
parameter_list|()
block|{
return|return
operator|&
name|NullTypeSourceInfo
return|;
block|}
end_function

begin_comment
comment|/// \brief Add a deallocation callback that will be invoked when the
end_comment

begin_comment
comment|/// ASTContext is destroyed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \brief Callback A callback function that will be invoked on destruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \brief Data Pointer data that will be provided to the callback function
end_comment

begin_comment
comment|/// when it is called.
end_comment

begin_function_decl
name|void
name|AddDeallocation
parameter_list|(
name|void
function_decl|(
modifier|*
name|Callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GVALinkage
name|GetGVALinkageForFunction
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GVALinkage
name|GetGVALinkageForVariable
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determines if the decl can be CodeGen'ed or deserialized from PCH
end_comment

begin_comment
comment|/// lazily, only when used; this is only relevant for function or file scoped
end_comment

begin_comment
comment|/// var definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if the function/var must be CodeGen'ed/deserialized even if
end_comment

begin_comment
comment|/// it is not used.
end_comment

begin_function_decl
name|bool
name|DeclMustBeEmitted
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                    Statistics
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief The number of implicitly-declared default constructors.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitDefaultConstructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared default constructors for
end_comment

begin_comment
comment|/// which declarations were built.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitDefaultConstructorsDeclared
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared copy constructors.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitCopyConstructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared copy constructors for
end_comment

begin_comment
comment|/// which declarations were built.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitCopyConstructorsDeclared
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared copy assignment operators.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitCopyAssignmentOperators
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared copy assignment operators for
end_comment

begin_comment
comment|/// which declarations were built.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitCopyAssignmentOperatorsDeclared
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared destructors.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitDestructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared destructors for which
end_comment

begin_comment
comment|/// declarations were built.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitDestructorsDeclared
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|ASTContext
argument_list|(
specifier|const
name|ASTContext
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// DO NOT IMPLEMENT
end_comment

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTContext
operator|&
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DO NOT IMPLEMENT
end_comment

begin_function_decl
name|void
name|InitBuiltinTypes
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|// Return the ObjC type encoding for a given type.
end_comment

begin_decl_stmt
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
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|ASTRecordLayout
modifier|&
name|getObjCLayout
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|D
argument_list|,
specifier|const
name|ObjCImplementationDecl
operator|*
name|Impl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief A set of deallocations that should be performed when the
end_comment

begin_comment
comment|/// ASTContext is destroyed.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|>
operator|,
literal|16
operator|>
name|Deallocations
expr_stmt|;
end_expr_stmt

begin_comment
comment|// FIXME: This currently contains the set of StoredDeclMaps used
end_comment

begin_comment
comment|// by DeclContext objects.  This probably should not be in ASTContext,
end_comment

begin_comment
comment|// but we include it here so that ASTContext can quickly deallocate them.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|PointerIntPair
operator|<
name|StoredDeclsMap
operator|*
operator|,
literal|1
operator|>
name|LastSDM
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A counter used to uniquely identify "blocks".
end_comment

begin_decl_stmt
name|mutable
name|unsigned
name|int
name|UniqueBlockByRefTypeID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|unsigned
name|int
name|UniqueBlockParmTypeID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|DeclContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|DeclarationNameTable
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ReleaseDeclContextMaps
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// @brief Utility function for constructing a nullary selector.
end_comment

begin_function
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
end_function

begin_comment
comment|/// @brief Utility function for constructing an unary selector.
end_comment

begin_function
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
end_function

begin_comment
unit|}
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
comment|/// // Default alignment (8)
end_comment

begin_comment
comment|/// IntegerLiteral *Ex = new (Context) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// IntegerLiteral *Ex2 = new (Context, 4) IntegerLiteral(arguments);
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
unit|inline
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|Bytes
argument_list|,
specifier|const
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
specifier|const
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
comment|/// // Default alignment (8)
end_comment

begin_comment
comment|/// char *data = new (Context) char[10];
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// char *data = new (Context, 4) char[10];
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
specifier|const
name|clang
operator|::
name|ASTContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
operator|=
literal|8
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
specifier|const
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

