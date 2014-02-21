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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::ASTContext interface.
end_comment

begin_comment
comment|///
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
file|"clang/AST/ASTTypeTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CommentCommandTraits.h"
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
file|"clang/AST/RawCommentList.h"
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
file|"clang/Basic/AddressSpaces.h"
end_include

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
file|"clang/Basic/VersionTuple.h"
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
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
file|"llvm/ADT/TinyPtrVector.h"
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
name|AtomicExpr
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
name|DiagnosticsEngine
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
name|MaterializeTemporaryExpr
decl_stmt|;
name|class
name|SelectorTable
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|CXXABI
decl_stmt|;
name|class
name|MangleNumberingContext
decl_stmt|;
comment|// Decls
name|class
name|MangleContext
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|UnresolvedSetIterator
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
name|namespace
name|comments
block|{
name|class
name|FullComment
decl_stmt|;
block|}
comment|/// \brief Holds long-lived AST nodes (such as types and decls) that can be
comment|/// referred to throughout the semantic analysis of a file.
name|class
name|ASTContext
range|:
name|public
name|RefCountedBase
operator|<
name|ASTContext
operator|>
block|{
name|ASTContext
operator|&
name|this_
argument_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
name|mutable
name|SmallVector
operator|<
name|Type
operator|*
block|,
literal|0
operator|>
name|Types
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ExtQuals
operator|>
name|ExtQualNodes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ComplexType
operator|>
name|ComplexTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|PointerType
operator|>
name|PointerTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DecayedType
operator|>
name|DecayedTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|BlockPointerType
operator|>
name|BlockPointerTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|LValueReferenceType
operator|>
name|LValueReferenceTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|RValueReferenceType
operator|>
name|RValueReferenceTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|MemberPointerType
operator|>
name|MemberPointerTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ConstantArrayType
operator|>
name|ConstantArrayTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|IncompleteArrayType
operator|>
name|IncompleteArrayTypes
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|VariableArrayType
operator|*
operator|>
name|VariableArrayTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentSizedArrayType
operator|>
name|DependentSizedArrayTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentSizedExtVectorType
operator|>
name|DependentSizedExtVectorTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|VectorType
operator|>
name|VectorTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|FunctionNoProtoType
operator|>
name|FunctionNoProtoTypes
block|;
name|mutable
name|llvm
operator|::
name|ContextualFoldingSet
operator|<
name|FunctionProtoType
block|,
name|ASTContext
operator|&
operator|>
name|FunctionProtoTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentTypeOfExprType
operator|>
name|DependentTypeOfExprTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentDecltypeType
operator|>
name|DependentDecltypeTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|TemplateTypeParmType
operator|>
name|TemplateTypeParmTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|SubstTemplateTypeParmType
operator|>
name|SubstTemplateTypeParmTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|SubstTemplateTypeParmPackType
operator|>
name|SubstTemplateTypeParmPackTypes
block|;
name|mutable
name|llvm
operator|::
name|ContextualFoldingSet
operator|<
name|TemplateSpecializationType
block|,
name|ASTContext
operator|&
operator|>
name|TemplateSpecializationTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ParenType
operator|>
name|ParenTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ElaboratedType
operator|>
name|ElaboratedTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentNameType
operator|>
name|DependentNameTypes
block|;
name|mutable
name|llvm
operator|::
name|ContextualFoldingSet
operator|<
name|DependentTemplateSpecializationType
block|,
name|ASTContext
operator|&
operator|>
name|DependentTemplateSpecializationTypes
block|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|PackExpansionType
operator|>
name|PackExpansionTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ObjCObjectTypeImpl
operator|>
name|ObjCObjectTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|ObjCObjectPointerType
operator|>
name|ObjCObjectPointerTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|AutoType
operator|>
name|AutoTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|AtomicType
operator|>
name|AtomicTypes
block|;
name|llvm
operator|::
name|FoldingSet
operator|<
name|AttributedType
operator|>
name|AttributedTypes
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|QualifiedTemplateName
operator|>
name|QualifiedTemplateNames
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|DependentTemplateName
operator|>
name|DependentTemplateNames
block|;
name|mutable
name|llvm
operator|::
name|FoldingSet
operator|<
name|SubstTemplateTemplateParmStorage
operator|>
name|SubstTemplateTemplateParms
block|;
name|mutable
name|llvm
operator|::
name|ContextualFoldingSet
operator|<
name|SubstTemplateTemplateParmPackStorage
block|,
name|ASTContext
operator|&
operator|>
name|SubstTemplateTemplateParmPacks
block|;
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
block|;
name|mutable
name|NestedNameSpecifier
operator|*
name|GlobalNestedNameSpecifier
block|;
name|friend
name|class
name|NestedNameSpecifier
block|;
comment|/// \brief A cache mapping from RecordDecls to ASTRecordLayouts.
comment|///
comment|/// This is lazily created.  This is intentionally not serialized.
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|RecordDecl
operator|*
block|,
specifier|const
name|ASTRecordLayout
operator|*
operator|>
name|ASTRecordLayouts
block|;
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ObjCContainerDecl
operator|*
block|,
specifier|const
name|ASTRecordLayout
operator|*
operator|>
name|ObjCLayouts
block|;
comment|/// \brief A cache from types to size and alignment information.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|unsigned
operator|>
expr|>
name|TypeInfoMap
expr_stmt|;
name|mutable
name|TypeInfoMap
name|MemoizedTypeInfo
decl_stmt|;
comment|/// \brief A cache mapping from CXXRecordDecls to key functions.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|LazyDeclPtr
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
comment|/// \brief Mapping from ObjCMethod to its duplicate declaration in the same
comment|/// interface.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ObjCMethodDecl
operator|*
operator|,
specifier|const
name|ObjCMethodDecl
operator|*
operator|>
name|ObjCMethodRedecls
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
comment|/// \brief Mapping from class scope functions specialization to their
comment|/// template patterns.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FunctionDecl
operator|*
operator|,
name|FunctionDecl
operator|*
operator|>
name|ClassScopeSpecializationPattern
expr_stmt|;
comment|/// \brief Mapping from materialized temporaries with static storage duration
comment|/// that appear in constant initializers to their evaluated values.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MaterializeTemporaryExpr
operator|*
operator|,
name|APValue
operator|>
name|MaterializedTemporaryValues
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
comment|/// \brief The typedef for the __int128_t type.
name|mutable
name|TypedefDecl
modifier|*
name|Int128Decl
decl_stmt|;
comment|/// \brief The typedef for the __uint128_t type.
name|mutable
name|TypedefDecl
modifier|*
name|UInt128Decl
decl_stmt|;
comment|/// \brief The typedef for the __float128 stub type.
name|mutable
name|TypeDecl
modifier|*
name|Float128StubDecl
decl_stmt|;
comment|/// \brief The typedef for the target specific predefined
comment|/// __builtin_va_list type.
name|mutable
name|TypedefDecl
modifier|*
name|BuiltinVaListDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined \c id type.
name|mutable
name|TypedefDecl
modifier|*
name|ObjCIdDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined \c SEL type.
name|mutable
name|TypedefDecl
modifier|*
name|ObjCSelDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined \c Class type.
name|mutable
name|TypedefDecl
modifier|*
name|ObjCClassDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined \c Protocol class in Objective-C.
name|mutable
name|ObjCInterfaceDecl
modifier|*
name|ObjCProtocolClassDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined 'BOOL' type.
name|mutable
name|TypedefDecl
modifier|*
name|BOOLDecl
decl_stmt|;
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
name|QualType
name|ObjCConstantStringType
decl_stmt|;
name|mutable
name|RecordDecl
modifier|*
name|CFConstantStringTypeDecl
decl_stmt|;
name|mutable
name|QualType
name|ObjCSuperType
decl_stmt|;
name|QualType
name|ObjCNSStringType
decl_stmt|;
comment|/// \brief The typedef declaration for the Objective-C "instancetype" type.
name|TypedefDecl
modifier|*
name|ObjCInstanceTypeDecl
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
comment|/// \brief The type for the C ucontext_t type.
name|TypeDecl
modifier|*
name|ucontext_tDecl
decl_stmt|;
comment|/// \brief Type for the Block descriptor for Blocks CodeGen.
comment|///
comment|/// Since this is only used for generation of debug info, it is not
comment|/// serialized.
name|mutable
name|RecordDecl
modifier|*
name|BlockDescriptorType
decl_stmt|;
comment|/// \brief Type for the Block descriptor for Blocks CodeGen.
comment|///
comment|/// Since this is only used for generation of debug info, it is not
comment|/// serialized.
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
comment|/// \brief A mapping from non-redeclarable declarations in modules that were
comment|/// merged with other declarations to the canonical declaration that they were
comment|/// merged into.
name|llvm
operator|::
name|DenseMap
operator|<
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>
name|MergedDecls
expr_stmt|;
name|public
label|:
comment|/// \brief A type synonym for the TemplateOrInstantiation mapping.
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
name|VarTemplateDecl
operator|*
operator|,
name|MemberSpecializationInfo
operator|*
operator|>
name|TemplateOrSpecializationInfo
expr_stmt|;
name|private
label|:
comment|/// \brief A mapping to contain the template or declaration that
comment|/// a variable declaration describes or was instantiated from,
comment|/// respectively.
comment|///
comment|/// For non-templates, this value will be NULL. For variable
comment|/// declarations that describe a variable template, this will be a
comment|/// pointer to a VarTemplateDecl. For static data members
comment|/// of class template specializations, this will be the
comment|/// MemberSpecializationInfo referring to the member variable that was
comment|/// instantiated or specialized. Thus, the mapping will keep track of
comment|/// the static data member templates from which static data members of
comment|/// class template specializations were instantiated.
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
name|TemplateOrSpecializationInfo
operator|>
name|TemplateOrInstantiation
expr_stmt|;
comment|/// \brief Keeps track of the declaration from which a UsingDecl was
comment|/// created during instantiation.
comment|///
comment|/// The source declaration is always a UsingDecl, an UnresolvedUsingValueDecl,
comment|/// or an UnresolvedUsingTypenameDecl.
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
name|llvm
operator|::
name|TinyPtrVector
operator|<
specifier|const
name|CXXMethodDecl
operator|*
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
comment|/// \brief Mapping from each declaration context to its corresponding
comment|/// mangling numbering context (used for constructs like lambdas which
comment|/// need to be consistently numbered for the mangler).
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|MangleNumberingContext
operator|*
operator|>
name|MangleNumberingContexts
expr_stmt|;
comment|/// \brief Side-table of mangling numbers for declarations which rarely
comment|/// need them (like static local vars).
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|NamedDecl
operator|*
operator|,
name|unsigned
operator|>
name|MangleNumbers
expr_stmt|;
comment|/// \brief Mapping that stores parameterIndex values for ParmVarDecls when
comment|/// that value exceeds the bitfield size of ParmVarDeclBits.ParameterIndex.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|unsigned
operator|>
name|ParameterIndexTable
expr_stmt|;
name|ParameterIndexTable
name|ParamIndices
decl_stmt|;
name|ImportDecl
modifier|*
name|FirstLocalImport
decl_stmt|;
name|ImportDecl
modifier|*
name|LastLocalImport
decl_stmt|;
name|TranslationUnitDecl
modifier|*
name|TUDecl
decl_stmt|;
comment|/// \brief The associated SourceManager object.a
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
comment|/// \brief The language options used to create the AST associated with
comment|///  this ASTContext object.
name|LangOptions
modifier|&
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
comment|/// \brief The logical -> physical address space map.
specifier|const
name|LangAS
operator|::
name|Map
operator|*
name|AddrSpaceMap
expr_stmt|;
comment|/// \brief Address space map mangling must be used with language specific
comment|/// address spaces (e.g. OpenCL/CUDA)
name|bool
name|AddrSpaceMapMangling
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
decl_stmt|;
name|friend
name|class
name|CXXRecordDecl
decl_stmt|;
specifier|const
name|TargetInfo
modifier|*
name|Target
decl_stmt|;
name|clang
operator|::
name|PrintingPolicy
name|PrintingPolicy
expr_stmt|;
name|public
label|:
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
comment|/// \brief Contains parents of a node.
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|ast_type_traits
operator|::
name|DynTypedNode
operator|,
literal|1
operator|>
name|ParentVector
expr_stmt|;
comment|/// \brief Maps from a node to its parents.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|void
operator|*
operator|,
name|ParentVector
operator|>
name|ParentMap
expr_stmt|;
comment|/// \brief Returns the parents of the given node.
comment|///
comment|/// Note that this will lazily compute the parents of all nodes
comment|/// and store them for later retrieval. Thus, the first call is O(n)
comment|/// in the number of AST nodes.
comment|///
comment|/// Caveats and FIXMEs:
comment|/// Calculating the parent map over all AST nodes will need to load the
comment|/// full AST. This can be undesirable in the case where the full AST is
comment|/// expensive to create (for example, when using precompiled header
comment|/// preambles). Thus, there are good opportunities for optimization here.
comment|/// One idea is to walk the given node downwards, looking for references
comment|/// to declaration contexts - once a declaration context is found, compute
comment|/// the parent map for the declaration context; if that can satisfy the
comment|/// request, loading the whole AST can be avoided. Note that this is made
comment|/// more complex by statements in templates having multiple parents - those
comment|/// problems can be solved by building closure over the templated parts of
comment|/// the AST, which also avoids touching large parts of the AST.
comment|/// Additionally, we will want to add an interface to already give a hint
comment|/// where to search for the parents, for example when looking at a statement
comment|/// inside a certain function.
comment|///
comment|/// 'NodeT' can be one of Decl, Stmt, Type, TypeLoc,
comment|/// NestedNameSpecifier or NestedNameSpecifierLoc.
name|template
operator|<
name|typename
name|NodeT
operator|>
name|ParentVector
name|getParents
argument_list|(
argument|const NodeT&Node
argument_list|)
block|{
return|return
name|getParents
argument_list|(
name|ast_type_traits
operator|::
name|DynTypedNode
operator|::
name|create
argument_list|(
name|Node
argument_list|)
argument_list|)
return|;
block|}
name|ParentVector
name|getParents
argument_list|(
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
operator|&
name|Node
argument_list|)
decl_stmt|;
specifier|const
name|clang
operator|::
name|PrintingPolicy
operator|&
name|getPrintingPolicy
argument_list|()
specifier|const
block|{
return|return
name|PrintingPolicy
return|;
block|}
name|void
name|setPrintingPolicy
argument_list|(
specifier|const
name|clang
operator|::
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
block|{
name|PrintingPolicy
operator|=
name|Policy
expr_stmt|;
block|}
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
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getAllocator
argument_list|()
specifier|const
block|{
return|return
name|BumpAlloc
return|;
block|}
name|void
modifier|*
name|Allocate
argument_list|(
name|size_t
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
comment|/// Return the total amount of physical memory allocated for representing
comment|/// AST nodes and type information.
name|size_t
name|getASTAllocatedMemory
argument_list|()
specifier|const
block|{
return|return
name|BumpAlloc
operator|.
name|getTotalMemory
argument_list|()
return|;
block|}
comment|/// Return the total memory used for various side tables.
name|size_t
name|getSideTableAllocatedMemory
argument_list|()
specifier|const
expr_stmt|;
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
name|TargetInfo
operator|&
name|getTargetInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Target
return|;
block|}
comment|/// getIntTypeForBitwidth -
comment|/// sets integer QualTy according to specified details:
comment|/// bitwidth, signed/unsigned.
comment|/// Returns empty type if there is no appropriate target types.
name|QualType
name|getIntTypeForBitwidth
argument_list|(
name|unsigned
name|DestWidth
argument_list|,
name|unsigned
name|Signed
argument_list|)
decl|const
decl_stmt|;
comment|/// getRealTypeForBitwidth -
comment|/// sets floating point QualTy according to specified bitwidth.
comment|/// Returns empty type if there is no appropriate target types.
name|QualType
name|getRealTypeForBitwidth
argument_list|(
name|unsigned
name|DestWidth
argument_list|)
decl|const
decl_stmt|;
name|bool
name|AtomicUsesUnsupportedLibcall
argument_list|(
specifier|const
name|AtomicExpr
operator|*
name|E
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
name|DiagnosticsEngine
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
comment|/// \brief All comments in this translation unit.
name|RawCommentList
name|Comments
decl_stmt|;
comment|/// \brief True if comments are already loaded from ExternalASTSource.
name|mutable
name|bool
name|CommentsLoaded
decl_stmt|;
name|class
name|RawCommentAndCacheFlags
block|{
name|public
label|:
enum|enum
name|Kind
block|{
comment|/// We searched for a comment attached to the particular declaration, but
comment|/// didn't find any.
comment|///
comment|/// getRaw() == 0.
name|NoCommentInDecl
init|=
literal|0
block|,
comment|/// We have found a comment attached to this particular declaration.
comment|///
comment|/// getRaw() != 0.
name|FromDecl
block|,
comment|/// This declaration does not have an attached comment, and we have
comment|/// searched the redeclaration chain.
comment|///
comment|/// If getRaw() == 0, the whole redeclaration chain does not have any
comment|/// comments.
comment|///
comment|/// If getRaw() != 0, it is a comment propagated from other
comment|/// redeclaration.
name|FromRedecl
block|}
enum|;
name|Kind
name|getKind
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Data
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
name|Data
operator|.
name|setInt
argument_list|(
name|K
argument_list|)
expr_stmt|;
block|}
specifier|const
name|RawComment
operator|*
name|getRaw
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Data
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setRaw
parameter_list|(
specifier|const
name|RawComment
modifier|*
name|RC
parameter_list|)
block|{
name|Data
operator|.
name|setPointer
argument_list|(
name|RC
argument_list|)
expr_stmt|;
block|}
specifier|const
name|Decl
operator|*
name|getOriginalDecl
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|OriginalDecl
return|;
block|}
name|void
name|setOriginalDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|Orig
parameter_list|)
block|{
name|OriginalDecl
operator|=
name|Orig
expr_stmt|;
block|}
name|private
label|:
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|RawComment
operator|*
operator|,
literal|2
operator|,
name|Kind
operator|>
name|Data
expr_stmt|;
specifier|const
name|Decl
modifier|*
name|OriginalDecl
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Mapping from declarations to comments attached to any
comment|/// redeclaration.
comment|///
comment|/// Raw comments are owned by Comments list.  This mapping is populated
comment|/// lazily.
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|RawCommentAndCacheFlags
operator|>
name|RedeclComments
expr_stmt|;
comment|/// \brief Mapping from declarations to parsed comments attached to any
comment|/// redeclaration.
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|comments
operator|::
name|FullComment
operator|*
operator|>
name|ParsedComments
expr_stmt|;
comment|/// \brief Return the documentation comment attached to a given declaration,
comment|/// without looking into cache.
name|RawComment
modifier|*
name|getRawCommentForDeclNoCache
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|RawCommentList
modifier|&
name|getRawCommentList
parameter_list|()
block|{
return|return
name|Comments
return|;
block|}
name|void
name|addComment
parameter_list|(
specifier|const
name|RawComment
modifier|&
name|RC
parameter_list|)
block|{
name|assert
argument_list|(
name|LangOpts
operator|.
name|RetainCommentsFromSystemHeaders
operator|||
operator|!
name|SourceMgr
operator|.
name|isInSystemHeader
argument_list|(
name|RC
operator|.
name|getSourceRange
argument_list|()
operator|.
name|getBegin
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|Comments
operator|.
name|addComment
argument_list|(
name|RC
argument_list|,
name|BumpAlloc
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return the documentation comment attached to a given declaration.
comment|/// Returns NULL if no comment is attached.
comment|///
comment|/// \param OriginalDecl if not NULL, is set to declaration AST node that had
comment|/// the comment, if the comment we found comes from a redeclaration.
specifier|const
name|RawComment
modifier|*
name|getRawCommentForAnyRedecl
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
specifier|const
name|Decl
operator|*
operator|*
name|OriginalDecl
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|/// Return parsed documentation comment attached to a given declaration.
comment|/// Returns NULL if no comment is attached.
comment|///
comment|/// \param PP the Preprocessor used with this TU.  Could be NULL if
comment|/// preprocessor is not available.
name|comments
operator|::
name|FullComment
operator|*
name|getCommentForDecl
argument_list|(
argument|const Decl *D
argument_list|,
argument|const Preprocessor *PP
argument_list|)
specifier|const
expr_stmt|;
comment|/// Return parsed documentation comment attached to a given declaration.
comment|/// Returns NULL if no comment is attached. Does not look at any
comment|/// redeclarations of the declaration.
name|comments
operator|::
name|FullComment
operator|*
name|getLocalCommentForDeclUncached
argument_list|(
argument|const Decl *D
argument_list|)
specifier|const
expr_stmt|;
name|comments
operator|::
name|FullComment
operator|*
name|cloneFullComment
argument_list|(
argument|comments::FullComment *FC
argument_list|,
argument|const Decl *D
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|mutable
name|comments
operator|::
name|CommandTraits
name|CommentCommandTraits
expr_stmt|;
name|public
label|:
name|comments
operator|::
name|CommandTraits
operator|&
name|getCommentCommandTraits
argument_list|()
specifier|const
block|{
return|return
name|CommentCommandTraits
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
comment|// FIXME: Remove ?
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
name|TemplateOrSpecializationInfo
name|getTemplateOrSpecializationInfo
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Var
parameter_list|)
function_decl|;
name|FunctionDecl
modifier|*
name|getClassScopeSpecializationPattern
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
name|void
name|setClassScopeSpecializationPattern
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|FunctionDecl
modifier|*
name|Pattern
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
name|void
name|setTemplateOrSpecializationInfo
parameter_list|(
name|VarDecl
modifier|*
name|Inst
parameter_list|,
name|TemplateOrSpecializationInfo
name|TSI
parameter_list|)
function_decl|;
comment|/// \brief If the given using decl \p Inst is an instantiation of a
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
name|const_iterator
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
comment|/// \brief Return C++ or ObjC overridden methods for the given \p Method.
comment|///
comment|/// An ObjC method is considered to override any method in the class's
comment|/// base classes, its protocols, or its categories' protocols, that has
comment|/// the same selector and is of the same kind (class or instance).
comment|/// A method in an implementation is not considered as overriding the same
comment|/// method in the interface or its categories.
name|void
name|getOverriddenMethods
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|Method
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|NamedDecl
operator|*
operator|>
operator|&
name|Overridden
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Notify the AST context that a new import declaration has been
comment|/// parsed or implicitly created within this translation unit.
name|void
name|addedLocalImportDecl
parameter_list|(
name|ImportDecl
modifier|*
name|Import
parameter_list|)
function_decl|;
specifier|static
name|ImportDecl
modifier|*
name|getNextLocalImport
parameter_list|(
name|ImportDecl
modifier|*
name|Import
parameter_list|)
block|{
return|return
name|Import
operator|->
name|NextLocalImport
return|;
block|}
comment|/// \brief Iterator that visits import declarations.
name|class
name|import_iterator
block|{
name|ImportDecl
modifier|*
name|Import
decl_stmt|;
name|public
label|:
typedef|typedef
name|ImportDecl
modifier|*
name|value_type
typedef|;
typedef|typedef
name|ImportDecl
modifier|*
name|reference
typedef|;
typedef|typedef
name|ImportDecl
modifier|*
name|pointer
typedef|;
typedef|typedef
name|int
name|difference_type
typedef|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
name|import_iterator
argument_list|()
operator|:
name|Import
argument_list|()
block|{ }
name|explicit
name|import_iterator
argument_list|(
name|ImportDecl
operator|*
name|Import
argument_list|)
operator|:
name|Import
argument_list|(
argument|Import
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Import
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Import
return|;
block|}
name|import_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|Import
operator|=
name|ASTContext
operator|::
name|getNextLocalImport
argument_list|(
name|Import
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|import_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|import_iterator
name|Other
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|Other
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|import_iterator
name|X
operator|,
name|import_iterator
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Import
operator|==
name|Y
operator|.
name|Import
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|import_iterator
name|X
operator|,
name|import_iterator
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Import
operator|!=
name|Y
operator|.
name|Import
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|import_iterator
name|local_import_begin
argument_list|()
specifier|const
block|{
return|return
name|import_iterator
argument_list|(
name|FirstLocalImport
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|import_iterator
name|local_import_end
argument_list|()
specifier|const
block|{
return|return
name|import_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|Decl
modifier|*
name|getPrimaryMergedDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|Decl
modifier|*
name|Result
init|=
name|MergedDecls
operator|.
name|lookup
argument_list|(
name|D
argument_list|)
decl_stmt|;
return|return
name|Result
condition|?
name|Result
else|:
name|D
return|;
block|}
end_function

begin_function
name|void
name|setPrimaryMergedDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|Decl
modifier|*
name|Primary
parameter_list|)
block|{
name|MergedDecls
index|[
name|D
index|]
operator|=
name|Primary
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|// Builtin Types.
end_comment

begin_decl_stmt
name|CanQualType
name|VoidTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|BoolTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|CharTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|WCharTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// [C++ 3.9.1p5].
end_comment

begin_decl_stmt
name|CanQualType
name|WideCharTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Same as WCharTy in C++, integer type in C99.
end_comment

begin_decl_stmt
name|CanQualType
name|WIntTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// [C99 7.24.1], integer type unchanged by default promotions.
end_comment

begin_decl_stmt
name|CanQualType
name|Char16Ty
decl_stmt|;
end_decl_stmt

begin_comment
comment|// [C++0x 3.9.1p5], integer type in C99.
end_comment

begin_decl_stmt
name|CanQualType
name|Char32Ty
decl_stmt|;
end_decl_stmt

begin_comment
comment|// [C++0x 3.9.1p5], integer type in C99.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|UnsignedCharTy
decl_stmt|,
name|UnsignedShortTy
decl_stmt|,
name|UnsignedIntTy
decl_stmt|,
name|UnsignedLongTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|UnsignedLongLongTy
decl_stmt|,
name|UnsignedInt128Ty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|FloatTy
decl_stmt|,
name|DoubleTy
decl_stmt|,
name|LongDoubleTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|HalfTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// [OpenCL 6.1.1.1], ARM NEON
end_comment

begin_decl_stmt
name|CanQualType
name|FloatComplexTy
decl_stmt|,
name|DoubleComplexTy
decl_stmt|,
name|LongDoubleComplexTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|VoidPtrTy
decl_stmt|,
name|NullPtrTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|DependentTy
decl_stmt|,
name|OverloadTy
decl_stmt|,
name|BoundMemberTy
decl_stmt|,
name|UnknownAnyTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|BuiltinFnTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|PseudoObjectTy
decl_stmt|,
name|ARCUnbridgedCastTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|ObjCBuiltinIdTy
decl_stmt|,
name|ObjCBuiltinClassTy
decl_stmt|,
name|ObjCBuiltinSelTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|ObjCBuiltinBoolTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|OCLImage1dTy
decl_stmt|,
name|OCLImage1dArrayTy
decl_stmt|,
name|OCLImage1dBufferTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|OCLImage2dTy
decl_stmt|,
name|OCLImage2dArrayTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|OCLImage3dTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|OCLSamplerTy
decl_stmt|,
name|OCLEventTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Types for deductions in C++0x [stmt.ranged]'s desugaring. Built on demand.
end_comment

begin_decl_stmt
name|mutable
name|QualType
name|AutoDeductTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Deduction against 'auto'.
end_comment

begin_decl_stmt
name|mutable
name|QualType
name|AutoRRefDeductTy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Deduction against 'auto&&'.
end_comment

begin_comment
comment|// Type used to help define __builtin_va_list for some targets.
end_comment

begin_comment
comment|// The type is built when constructing 'BuiltinVaListDecl'.
end_comment

begin_decl_stmt
name|mutable
name|QualType
name|VaListTagTy
decl_stmt|;
end_decl_stmt

begin_macro
name|ASTContext
argument_list|(
argument|LangOptions& LOpts
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|const TargetInfo *t
argument_list|,
argument|IdentifierTable&idents
argument_list|,
argument|SelectorTable&sels
argument_list|,
argument|Builtin::Context&builtins
argument_list|,
argument|unsigned size_reserve
argument_list|,
argument|bool DelayInitialization = false
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|ASTContext
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Attach an external AST source to the AST context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The external AST source provides the ability to load parts of
end_comment

begin_comment
comment|/// the abstract syntax tree as needed from some external storage,
end_comment

begin_comment
comment|/// e.g., a precompiled header.
end_comment

begin_decl_stmt
name|void
name|setExternalSource
argument_list|(
name|OwningPtr
operator|<
name|ExternalASTSource
operator|>
operator|&
name|Source
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve a pointer to the external AST source associated
end_comment

begin_comment
comment|/// with this AST context, if any.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Attach an AST mutation listener to the AST context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The AST mutation listener provides the ability to track modifications to
end_comment

begin_comment
comment|/// the abstract syntax tree entities committed after they were initially
end_comment

begin_comment
comment|/// created.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Retrieve a pointer to the AST mutation listener associated
end_comment

begin_comment
comment|/// with this AST context, if any.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|SmallVectorImpl
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the declaration for the 128-bit signed integer type.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getInt128Decl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the declaration for the 128-bit unsigned integer type.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getUInt128Decl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the declaration for a 128-bit float stub type.
end_comment

begin_expr_stmt
name|TypeDecl
operator|*
name|getFloat128StubType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                           Type Constructors
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Return a type with extended qualifiers.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Return the uniqued reference to the type for an address space
end_comment

begin_comment
comment|/// qualified type with the specified type and address space.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting type has a union of the qualifiers from T and the address
end_comment

begin_comment
comment|/// space. If T already has an address space specifier, it is silently
end_comment

begin_comment
comment|/// replaced.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for an Objective-C
end_comment

begin_comment
comment|/// gc-qualified type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The retulting type has a union of the qualifiers from T and the gc
end_comment

begin_comment
comment|/// attribute.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for a \c restrict
end_comment

begin_comment
comment|/// qualified type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting type has a union of the qualifiers from \p T and
end_comment

begin_comment
comment|/// \c restrict.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for a \c volatile
end_comment

begin_comment
comment|/// qualified type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting type has a union of the qualifiers from \p T and
end_comment

begin_comment
comment|/// \c volatile.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for a \c const
end_comment

begin_comment
comment|/// qualified type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting type has a union of the qualifiers from \p T and \c const.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It can be reasonably expected that this will always be equivalent to
end_comment

begin_comment
comment|/// calling T.withConst().
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Change the ExtInfo on a function type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Change the result type of a function type once it is deduced.
end_comment

begin_function_decl
name|void
name|adjustDeducedFunctionResultType
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|QualType
name|ResultType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Return the uniqued reference to the type for a complex
end_comment

begin_comment
comment|/// number with the specified element type.
end_comment

begin_decl_stmt
name|QualType
name|getComplexType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for a pointer to
end_comment

begin_comment
comment|/// the specified type.
end_comment

begin_decl_stmt
name|QualType
name|getPointerType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the decayed version of the given
end_comment

begin_comment
comment|/// type.  Can only be called on array and function types which decay to
end_comment

begin_comment
comment|/// pointer types.
end_comment

begin_decl_stmt
name|QualType
name|getDecayedType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|getDecayedType
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
name|getDecayedType
argument_list|(
operator|(
name|QualType
operator|)
name|T
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the atomic type for the specified
end_comment

begin_comment
comment|/// type.
end_comment

begin_decl_stmt
name|QualType
name|getAtomicType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for a block of the
end_comment

begin_comment
comment|/// specified type.
end_comment

begin_decl_stmt
name|QualType
name|getBlockPointerType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Gets the struct used to keep track of the descriptor for pointer to
end_comment

begin_comment
comment|/// blocks.
end_comment

begin_expr_stmt
name|QualType
name|getBlockDescriptorType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Gets the struct used to keep track of the extended descriptor for
end_comment

begin_comment
comment|/// pointer to blocks.
end_comment

begin_expr_stmt
name|QualType
name|getBlockDescriptorExtendedType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
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
end_function

begin_function
name|FunctionDecl
modifier|*
name|getcudaConfigureCallDecl
parameter_list|()
block|{
return|return
name|cudaConfigureCallDecl
return|;
block|}
end_function

begin_comment
comment|/// Returns true iff we need copy/dispose helpers for the given type.
end_comment

begin_function_decl
name|bool
name|BlockRequiresCopying
parameter_list|(
name|QualType
name|Ty
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns true, if given type has a known lifetime. HasByrefExtendedLayout is set
end_comment

begin_comment
comment|/// to false in this case. If HasByrefExtendedLayout returns true, byref variable
end_comment

begin_comment
comment|/// has extended lifetime.
end_comment

begin_decl_stmt
name|bool
name|getByrefLifetime
argument_list|(
name|QualType
name|Ty
argument_list|,
name|Qualifiers
operator|::
name|ObjCLifetime
operator|&
name|Lifetime
argument_list|,
name|bool
operator|&
name|HasByrefExtendedLayout
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for an lvalue reference
end_comment

begin_comment
comment|/// to the specified type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for an rvalue reference
end_comment

begin_comment
comment|/// to the specified type.
end_comment

begin_decl_stmt
name|QualType
name|getRValueReferenceType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the uniqued reference to the type for a member pointer to
end_comment

begin_comment
comment|/// the specified type in the specified class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The class \p Cls is a \c Type because it could be a dependent name.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return a non-unique reference to the type for a variable array of
end_comment

begin_comment
comment|/// the specified element type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return a non-unique reference to the type for a dependently-sized
end_comment

begin_comment
comment|/// array of the specified element type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: We will need these to be uniqued, or at least comparable, at some
end_comment

begin_comment
comment|/// point.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return a unique reference to the type for an incomplete array of
end_comment

begin_comment
comment|/// the specified element type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the unique reference to the type for a constant array of
end_comment

begin_comment
comment|/// the specified element type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Returns a vla type where known sizes are replaced with [*].
end_comment

begin_decl_stmt
name|QualType
name|getVariableArrayDecayedType
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the unique reference to a vector type of the specified
end_comment

begin_comment
comment|/// element type and size.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \p VectorType must be a built-in type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the unique reference to an extended vector type
end_comment

begin_comment
comment|/// of the specified element type and size.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \p VectorType must be a built-in type.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \pre Return a non-unique reference to the type for a dependently-sized
end_comment

begin_comment
comment|/// vector of the specified element type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: We will need these to be uniqued, or at least comparable, at some
end_comment

begin_comment
comment|/// point.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return a K&R style C function type like 'int()'.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return a normal function type with a typed argument list.
end_comment

begin_decl_stmt
name|QualType
name|getFunctionType
argument_list|(
name|QualType
name|ResultTy
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|Args
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
end_decl_stmt

begin_comment
comment|/// \brief Return the unique reference to the type for the specified type
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the unique reference to the type for the specified
end_comment

begin_comment
comment|/// typedef-name decl.
end_comment

begin_decl_stmt
name|QualType
name|getTypedefType
argument_list|(
specifier|const
name|TypedefNameDecl
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
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
end_function_decl

begin_decl_stmt
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
name|TemplateTypeParmDecl
operator|*
name|ParmDecl
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|QualType
name|getParenType
argument_list|(
name|QualType
name|NamedType
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|QualType
name|getPackExpansionType
argument_list|(
name|QualType
name|Pattern
argument_list|,
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|QualType
name|getObjCInterfaceType
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|Decl
argument_list|,
name|ObjCInterfaceDecl
operator|*
name|PrevDecl
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return a ObjCObjectPointerType type for the given ObjCObjectType.
end_comment

begin_decl_stmt
name|QualType
name|getObjCObjectPointerType
argument_list|(
name|QualType
name|OIT
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief GCC extension.
end_comment

begin_decl_stmt
name|QualType
name|getTypeOfExprType
argument_list|(
name|Expr
operator|*
name|e
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|QualType
name|getTypeOfType
argument_list|(
name|QualType
name|t
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief C++11 decltype.
end_comment

begin_decl_stmt
name|QualType
name|getDecltypeType
argument_list|(
name|Expr
operator|*
name|e
argument_list|,
name|QualType
name|UnderlyingType
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Unary type transforms
end_comment

begin_decl_stmt
name|QualType
name|getUnaryTransformType
argument_list|(
name|QualType
name|BaseType
argument_list|,
name|QualType
name|UnderlyingType
argument_list|,
name|UnaryTransformType
operator|::
name|UTTKind
name|UKind
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief C++11 deduced auto type.
end_comment

begin_decl_stmt
name|QualType
name|getAutoType
argument_list|(
name|QualType
name|DeducedType
argument_list|,
name|bool
name|IsDecltypeAuto
argument_list|,
name|bool
name|IsDependent
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief C++11 deduction pattern for 'auto' type.
end_comment

begin_expr_stmt
name|QualType
name|getAutoDeductType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief C++11 deduction pattern for 'auto&&' type.
end_comment

begin_expr_stmt
name|QualType
name|getAutoRRefDeductType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the unique reference to the type for the specified TagDecl
end_comment

begin_comment
comment|/// (struct/union/class/enum) decl.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Return the unique type for "size_t" (C99 7.17), defined in
end_comment

begin_comment
comment|///<stddef.h>.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The sizeof operator requires this (C99 6.5.3.4p4).
end_comment

begin_expr_stmt
name|CanQualType
name|getSizeType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the unique type for "intmax_t" (C99 7.18.1.5), defined in
end_comment

begin_comment
comment|///<stdint.h>.
end_comment

begin_expr_stmt
name|CanQualType
name|getIntMaxType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the unique type for "uintmax_t" (C99 7.18.1.5), defined in
end_comment

begin_comment
comment|///<stdint.h>.
end_comment

begin_expr_stmt
name|CanQualType
name|getUIntMaxType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the unique wchar_t type available in C++ (and available as
end_comment

begin_comment
comment|/// __wchar_t as a Microsoft extension).
end_comment

begin_expr_stmt
name|QualType
name|getWCharType
argument_list|()
specifier|const
block|{
return|return
name|WCharTy
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the type of wide characters. In C++, this returns the
end_comment

begin_comment
comment|/// unique wchar_t type. In C99, this returns a type compatible with the type
end_comment

begin_comment
comment|/// defined in<stddef.h> as defined by the target.
end_comment

begin_expr_stmt
name|QualType
name|getWideCharType
argument_list|()
specifier|const
block|{
return|return
name|WideCharTy
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the type of "signed wchar_t".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used when in C++, as a GCC extension.
end_comment

begin_expr_stmt
name|QualType
name|getSignedWCharType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the type of "unsigned wchar_t".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used when in C++, as a GCC extension.
end_comment

begin_expr_stmt
name|QualType
name|getUnsignedWCharType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief In C99, this returns a type compatible with the type
end_comment

begin_comment
comment|/// defined in<stddef.h> as defined by the target.
end_comment

begin_expr_stmt
name|QualType
name|getWIntType
argument_list|()
specifier|const
block|{
return|return
name|WIntTy
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return a type compatible with "intptr_t" (C99 7.18.1.4),
end_comment

begin_comment
comment|/// as defined by the target.
end_comment

begin_expr_stmt
name|QualType
name|getIntPtrType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return a type compatible with "uintptr_t" (C99 7.18.1.4),
end_comment

begin_comment
comment|/// as defined by the target.
end_comment

begin_expr_stmt
name|QualType
name|getUIntPtrType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the unique type for "ptrdiff_t" (C99 7.17) defined in
end_comment

begin_comment
comment|///<stddef.h>. Pointer - pointer requires this (C99 6.5.6p9).
end_comment

begin_expr_stmt
name|QualType
name|getPointerDiffType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the unique type for "pid_t" defined in
end_comment

begin_comment
comment|///<sys/types.h>. We need this to compute the correct type for vfork().
end_comment

begin_expr_stmt
name|QualType
name|getProcessIDType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the C structure type used to represent constant CFStrings.
end_comment

begin_expr_stmt
name|QualType
name|getCFConstantStringType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the C struct type for objc_super
end_comment

begin_expr_stmt
name|QualType
name|getObjCSuperType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setObjCSuperType
parameter_list|(
name|QualType
name|ST
parameter_list|)
block|{
name|ObjCSuperType
operator|=
name|ST
expr_stmt|;
block|}
end_function

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

begin_expr_stmt
name|QualType
name|getObjCNSStringType
argument_list|()
specifier|const
block|{
return|return
name|ObjCNSStringType
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setObjCNSStringType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|ObjCNSStringType
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the type that \c id has been defined to, which may be
end_comment

begin_comment
comment|/// different from the built-in \c id if \c id has been typedef'd.
end_comment

begin_expr_stmt
name|QualType
name|getObjCIdRedefinitionType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ObjCIdRedefinitionType
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|getObjCIdType
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|ObjCIdRedefinitionType
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the user-written type that redefines \c id.
end_comment

begin_macro
unit|void
name|setObjCIdRedefinitionType
argument_list|(
argument|QualType RedefType
argument_list|)
end_macro

begin_block
block|{
name|ObjCIdRedefinitionType
operator|=
name|RedefType
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the type that \c Class has been defined to, which may be
end_comment

begin_comment
comment|/// different from the built-in \c Class if \c Class has been typedef'd.
end_comment

begin_expr_stmt
name|QualType
name|getObjCClassRedefinitionType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ObjCClassRedefinitionType
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|getObjCClassType
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|ObjCClassRedefinitionType
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the user-written type that redefines 'SEL'.
end_comment

begin_macro
unit|void
name|setObjCClassRedefinitionType
argument_list|(
argument|QualType RedefType
argument_list|)
end_macro

begin_block
block|{
name|ObjCClassRedefinitionType
operator|=
name|RedefType
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the type that 'SEL' has been defined to, which may be
end_comment

begin_comment
comment|/// different from the built-in 'SEL' if 'SEL' has been typedef'd.
end_comment

begin_expr_stmt
name|QualType
name|getObjCSelRedefinitionType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ObjCSelRedefinitionType
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|getObjCSelType
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|ObjCSelRedefinitionType
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the user-written type that redefines 'SEL'.
end_comment

begin_macro
unit|void
name|setObjCSelRedefinitionType
argument_list|(
argument|QualType RedefType
argument_list|)
end_macro

begin_block
block|{
name|ObjCSelRedefinitionType
operator|=
name|RedefType
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the Objective-C "instancetype" type, if already known;
end_comment

begin_comment
comment|/// otherwise, returns a NULL type;
end_comment

begin_function
name|QualType
name|getObjCInstanceType
parameter_list|()
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getObjCInstanceTypeDecl
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the typedef declaration corresponding to the Objective-C
end_comment

begin_comment
comment|/// "instancetype" type.
end_comment

begin_function_decl
name|TypedefDecl
modifier|*
name|getObjCInstanceTypeDecl
parameter_list|()
function_decl|;
end_function_decl

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
comment|/// \brief Set the type for the C ucontext_t type.
end_comment

begin_macro
unit|void
name|setucontext_tDecl
argument_list|(
argument|TypeDecl *ucontext_tDecl
argument_list|)
end_macro

begin_block
block|{
name|this
operator|->
name|ucontext_tDecl
operator|=
name|ucontext_tDecl
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Retrieve the C ucontext_t type.
end_comment

begin_expr_stmt
name|QualType
name|getucontext_tType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ucontext_tDecl
condition|)
return|return
name|getTypeDeclType
argument_list|(
name|ucontext_tDecl
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
name|getLangOpts
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
comment|/// \brief Emit the Objective-CC type encoding for the given type \p T into
end_comment

begin_comment
comment|/// \p S.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p Field is specified then record field names are also encoded.
end_comment

begin_decl_stmt
name|void
name|getObjCEncodingForType
argument_list|(
name|QualType
name|T
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
comment|/// \brief Put the string version of the type qualifiers \p QT into \p S.
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
comment|/// \brief Emit the encoded type for the function \p Decl into \p S.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is in the same format as Objective-C method encodings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred (e.g., because one of the parameter
end_comment

begin_comment
comment|/// types is incomplete), false otherwise.
end_comment

begin_decl_stmt
name|bool
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
comment|/// \brief Emit the encoded type for the method declaration \p Decl into
end_comment

begin_comment
comment|/// \p S.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred (e.g., because one of the parameter
end_comment

begin_comment
comment|/// types is incomplete), false otherwise.
end_comment

begin_decl_stmt
name|bool
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
argument_list|,
name|bool
name|Extended
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the encoded type for this block declaration.
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
comment|/// \brief Return the size of type \p T for Objective-C encoding purpose,
end_comment

begin_comment
comment|/// in characters.
end_comment

begin_decl_stmt
name|CharUnits
name|getObjCEncodingTypeSize
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the typedef corresponding to the predefined \c id type
end_comment

begin_comment
comment|/// in Objective-C.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getObjCIdDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Represents the Objective-CC \c id type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is set up lazily, by Sema.  \c id is always a (typedef for a)
end_comment

begin_comment
comment|/// pointer type, a pointer to a struct.
end_comment

begin_expr_stmt
name|QualType
name|getObjCIdType
argument_list|()
specifier|const
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getObjCIdDecl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the typedef corresponding to the predefined 'SEL' type
end_comment

begin_comment
comment|/// in Objective-C.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getObjCSelDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the type that corresponds to the predefined Objective-C
end_comment

begin_comment
comment|/// 'SEL' type.
end_comment

begin_expr_stmt
name|QualType
name|getObjCSelType
argument_list|()
specifier|const
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getObjCSelDecl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the typedef declaration corresponding to the predefined
end_comment

begin_comment
comment|/// Objective-C 'Class' type.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getObjCClassDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Represents the Objective-C \c Class type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is set up lazily, by Sema.  \c Class is always a (typedef for a)
end_comment

begin_comment
comment|/// pointer type, a pointer to a struct.
end_comment

begin_expr_stmt
name|QualType
name|getObjCClassType
argument_list|()
specifier|const
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getObjCClassDecl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the Objective-C class declaration corresponding to
end_comment

begin_comment
comment|/// the predefined \c Protocol class.
end_comment

begin_expr_stmt
name|ObjCInterfaceDecl
operator|*
name|getObjCProtocolDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve declaration of 'BOOL' typedef
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getBOOLDecl
argument_list|()
specifier|const
block|{
return|return
name|BOOLDecl
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Save declaration of 'BOOL' typedef
end_comment

begin_function
name|void
name|setBOOLDecl
parameter_list|(
name|TypedefDecl
modifier|*
name|TD
parameter_list|)
block|{
name|BOOLDecl
operator|=
name|TD
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief type of 'BOOL' type.
end_comment

begin_expr_stmt
name|QualType
name|getBOOLType
argument_list|()
specifier|const
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getBOOLDecl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the type of the Objective-C \c Protocol class.
end_comment

begin_expr_stmt
name|QualType
name|getObjCProtoType
argument_list|()
specifier|const
block|{
return|return
name|getObjCInterfaceType
argument_list|(
name|getObjCProtocolDecl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the C type declaration corresponding to the predefined
end_comment

begin_comment
comment|/// \c __builtin_va_list type.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getBuiltinVaListDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the type of the \c __builtin_va_list type.
end_comment

begin_expr_stmt
name|QualType
name|getBuiltinVaListType
argument_list|()
specifier|const
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getBuiltinVaListDecl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the C type declaration corresponding to the predefined
end_comment

begin_comment
comment|/// \c __va_list_tag type used to help define the \c __builtin_va_list type
end_comment

begin_comment
comment|/// for some targets.
end_comment

begin_expr_stmt
name|QualType
name|getVaListTagType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return a type with additional \c const, \c volatile, or
end_comment

begin_comment
comment|/// \c restrict qualifiers.
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
comment|/// \brief Un-split a SplitQualType.
end_comment

begin_decl_stmt
name|QualType
name|getQualifiedType
argument_list|(
name|SplitQualType
name|split
argument_list|)
decl|const
block|{
return|return
name|getQualifiedType
argument_list|(
name|split
operator|.
name|Ty
argument_list|,
name|split
operator|.
name|Quals
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return a type with additional qualifiers.
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
comment|/// \brief Return a type with additional qualifiers.
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

begin_comment
comment|/// \brief Return a type with the given lifetime qualifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre Neither type.ObjCLifetime() nor \p lifetime may be \c OCL_None.
end_comment

begin_decl_stmt
name|QualType
name|getLifetimeQualifiedType
argument_list|(
name|QualType
name|type
argument_list|,
name|Qualifiers
operator|::
name|ObjCLifetime
name|lifetime
argument_list|)
block|{
name|assert
argument_list|(
name|type
operator|.
name|getObjCLifetime
argument_list|()
operator|==
name|Qualifiers
operator|::
name|OCL_None
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|lifetime
operator|!=
name|Qualifiers
operator|::
name|OCL_None
argument_list|)
expr_stmt|;
name|Qualifiers
name|qs
decl_stmt|;
name|qs
operator|.
name|addObjCLifetime
argument_list|(
name|lifetime
argument_list|)
expr_stmt|;
return|return
name|getQualifiedType
argument_list|(
name|type
argument_list|,
name|qs
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getUnqualifiedObjCPointerType - Returns version of
end_comment

begin_comment
comment|/// Objective-C pointer type with lifetime qualifier removed.
end_comment

begin_decl_stmt
name|QualType
name|getUnqualifiedObjCPointerType
argument_list|(
name|QualType
name|type
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|type
operator|.
name|getTypePtr
argument_list|()
operator|->
name|isObjCObjectPointerType
argument_list|()
operator|||
operator|!
name|type
operator|.
name|getQualifiers
argument_list|()
operator|.
name|hasObjCLifetime
argument_list|()
condition|)
return|return
name|type
return|;
name|Qualifiers
name|Qs
init|=
name|type
operator|.
name|getQualifiers
argument_list|()
decl_stmt|;
name|Qs
operator|.
name|removeObjCLifetime
argument_list|()
expr_stmt|;
return|return
name|getQualifiedType
argument_list|(
name|type
operator|.
name|getUnqualifiedType
argument_list|()
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
name|getSubstTemplateTemplateParm
argument_list|(
name|TemplateTemplateParmDecl
operator|*
name|param
argument_list|,
name|TemplateName
name|replacement
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
comment|///< No error
name|GE_Missing_stdio
block|,
comment|///< Missing a type from<stdio.h>
name|GE_Missing_setjmp
block|,
comment|///< Missing a type from<setjmp.h>
name|GE_Missing_ucontext
comment|///< Missing a type from<ucontext.h>
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Return the type for the specified builtin.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p IntegerConstantArgs is non-null, it is filled in with a bitmask of
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

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|unsigned
operator|>
name|getTypeInfoImpl
argument_list|(
argument|const Type *T
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Return one of the GCNone, Weak or Strong Objective-C garbage
end_comment

begin_comment
comment|/// collection attributes.
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
comment|/// \brief Return true if the given vector types are of the same unqualified
end_comment

begin_comment
comment|/// type or if they are equivalent to the same GCC vector type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note This ignores whether they are target-specific (AltiVec or Neon)
end_comment

begin_comment
comment|/// types.
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
comment|/// \brief Return true if this is an \c NSObject object with its \c NSObject
end_comment

begin_comment
comment|/// attribute set.
end_comment

begin_function
specifier|static
name|bool
name|isObjCNSObjectType
parameter_list|(
name|QualType
name|Ty
parameter_list|)
block|{
return|return
name|Ty
operator|->
name|isObjCNSObjectType
argument_list|()
return|;
block|}
end_function

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
comment|/// \brief Return the APFloat 'semantics' for the specified scalar floating
end_comment

begin_comment
comment|/// point type.
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
comment|/// \brief Get the size and alignment of the specified complete type in bits.
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
comment|/// \brief Return the size of the specified (complete) type \p T, in bits.
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
comment|/// \brief Return the size of the character type, in bits.
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
comment|/// \brief Convert a size in bits to a size in characters.
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
comment|/// \brief Convert a size in characters to a size in bits.
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
comment|/// \brief Return the size of the specified (complete) type \p T, in
end_comment

begin_comment
comment|/// characters.
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
comment|/// \brief Return the ABI-specified alignment of a (complete) type \p T, in
end_comment

begin_comment
comment|/// bits.
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
comment|/// \brief Return the ABI-specified alignment of a (complete) type \p T, in
end_comment

begin_comment
comment|/// characters.
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

begin_comment
comment|// getTypeInfoDataSizeInChars - Return the size of a type, in chars. If the
end_comment

begin_comment
comment|// type is a record, its data size is returned.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|CharUnits
operator|,
name|CharUnits
operator|>
name|getTypeInfoDataSizeInChars
argument_list|(
argument|QualType T
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
comment|/// \brief Return the "preferred" alignment of the specified type \p T for
end_comment

begin_comment
comment|/// the current target, in bits.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can be different than the ABI alignment in cases where it is
end_comment

begin_comment
comment|/// beneficial for performance to overalign a data type.
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
comment|/// \brief Return the alignment in bits that should be given to a
end_comment

begin_comment
comment|/// global variable with type \p T.
end_comment

begin_decl_stmt
name|unsigned
name|getAlignOfGlobalVar
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the alignment in characters that should be given to a
end_comment

begin_comment
comment|/// global variable with type \p T.
end_comment

begin_decl_stmt
name|CharUnits
name|getAlignOfGlobalVarInChars
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return a conservative estimate of the alignment of the specified
end_comment

begin_comment
comment|/// decl \p D.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \p D must not be a bitfield type, as bitfields do not have a valid
end_comment

begin_comment
comment|/// alignment.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p ForAlignof, references are treated like their underlying type
end_comment

begin_comment
comment|/// and  large arrays don't get any special treatment. If not \p ForAlignof
end_comment

begin_comment
comment|/// it computes the value expected by CodeGen: references are treated like
end_comment

begin_comment
comment|/// pointers and large arrays get extra alignment.
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
name|ForAlignof
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get or compute information about the layout of the specified
end_comment

begin_comment
comment|/// record (struct/union/class) \p D, which indicates its size and field
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

begin_decl_stmt
specifier|const
name|ASTRecordLayout
modifier|*
name|BuildMicrosoftASTRecordLayout
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
comment|/// \brief Get or compute information about the layout of the specified
end_comment

begin_comment
comment|/// Objective-C interface.
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
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|Simple
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get or compute information about the layout of the specified
end_comment

begin_comment
comment|/// Objective-C implementation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This may differ from the interface if synthesized ivars are present.
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
comment|/// \brief Get our current best idea for the key function of the
end_comment

begin_comment
comment|/// given record decl, or NULL if there isn't one.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The key function is, according to the Itanium C++ ABI section 5.2.3:
end_comment

begin_comment
comment|///   ...the first non-pure virtual function that is not inline at the
end_comment

begin_comment
comment|///   point of class definition.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Other ABIs use the same idea.  However, the ARM C++ ABI ignores
end_comment

begin_comment
comment|/// virtual functions that are defined 'inline', which means that
end_comment

begin_comment
comment|/// the result of this computation can change.
end_comment

begin_function_decl
specifier|const
name|CXXMethodDecl
modifier|*
name|getCurrentKeyFunction
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Observe that the given method cannot be a key function.
end_comment

begin_comment
comment|/// Checks the key-function cache for the method's class and clears it
end_comment

begin_comment
comment|/// if matches the given declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used in ABIs where out-of-line definitions marked
end_comment

begin_comment
comment|/// inline are not considered to be key functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param method should be the declaration from the class definition
end_comment

begin_function_decl
name|void
name|setNonKeyFunction
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the offset of a FieldDecl or IndirectFieldDecl, in bits.
end_comment

begin_decl_stmt
name|uint64_t
name|getFieldOffset
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|FD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|SmallVectorImpl
operator|<
specifier|const
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
comment|/// \brief Return the canonical (structural) type corresponding to the
end_comment

begin_comment
comment|/// specified potentially non-canonical type \p T.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The non-canonical version of a type may have many "decorated" versions of
end_comment

begin_comment
comment|/// types.  Decorators can include typedefs, 'typeof' operators, etc. The
end_comment

begin_comment
comment|/// returned type is guaranteed to be free of any of these, allowing two
end_comment

begin_comment
comment|/// canonical types to be compared for exact equality with a simple pointer
end_comment

begin_comment
comment|/// comparison.
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
comment|/// \brief Return the canonical parameter type corresponding to the specific
end_comment

begin_comment
comment|/// potentially non-canonical one.
end_comment

begin_comment
comment|///
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
comment|/// \brief Determine whether the given types \p T1 and \p T2 are equivalent.
end_comment

begin_decl_stmt
name|bool
name|hasSameType
argument_list|(
name|QualType
name|T1
argument_list|,
name|QualType
name|T2
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// \brief Return this type as a completely-unqualified array type,
end_comment

begin_comment
comment|/// capturing the qualifiers in \p Quals.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will remove the minimal amount of sugaring from the types, similar
end_comment

begin_comment
comment|/// to the behavior of QualType::getUnqualifiedType().
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

begin_decl_stmt
name|bool
name|hasSameUnqualifiedType
argument_list|(
name|QualType
name|T1
argument_list|,
name|QualType
name|T2
argument_list|)
decl|const
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
end_decl_stmt

begin_function_decl
name|bool
name|ObjCMethodsAreEqual
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|MethodDecl
parameter_list|,
specifier|const
name|ObjCMethodDecl
modifier|*
name|MethodImp
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// \brief Retrieves the default calling convention for the current target.
end_comment

begin_decl_stmt
name|CallingConv
name|getDefaultCallingConvention
argument_list|(
name|bool
name|isVariadic
argument_list|,
name|bool
name|IsCXXMethod
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
comment|/// names---std::vector, \::std::vector, vector (if vector is in
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
comment|/// \brief Return the innermost element type of an array type.
end_comment

begin_comment
comment|///
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
comment|/// \brief Return the innermost element type of a type (which needn't
end_comment

begin_comment
comment|/// actually be an array type).
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
comment|/// \brief Return number of constant array elements.
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
comment|/// \brief Perform adjustment on the parameter type of a function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine adjusts the given parameter type @p T to the actual
end_comment

begin_comment
comment|/// parameter type used by semantic analysis (C99 6.7.5.3p[7,8],
end_comment

begin_comment
comment|/// C++ [dcl.fct]p3). The adjusted parameter type is returned.
end_comment

begin_decl_stmt
name|QualType
name|getAdjustedParameterType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the parameter type as adjusted for use in the signature
end_comment

begin_comment
comment|/// of a function, decaying array and function types and removing top-level
end_comment

begin_comment
comment|/// cv-qualifiers.
end_comment

begin_decl_stmt
name|QualType
name|getSignatureParameterType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the properly qualified result of decaying the specified
end_comment

begin_comment
comment|/// array type to a pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operation is non-trivial when handling typedefs etc.  The canonical
end_comment

begin_comment
comment|/// type of \p T must be an array type, this returns a pointer to a properly
end_comment

begin_comment
comment|/// qualified element of the array.
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
comment|/// \brief Return the type that \p PromotableType will promote to: C99
end_comment

begin_comment
comment|/// 6.3.1.1p2, assuming that \p PromotableType is a promotable integer type.
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
comment|/// \brief Recurses in pointer/array types until it finds an Objective-C
end_comment

begin_comment
comment|/// retainable type and returns its ownership.
end_comment

begin_expr_stmt
name|Qualifiers
operator|::
name|ObjCLifetime
name|getInnerObjCOwnership
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Return the highest ranked integer type, see C99 6.3.1.8p1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p LHS> \p RHS, returns 1.  If \p LHS == \p RHS, returns 0.  If
end_comment

begin_comment
comment|/// \p LHS< \p RHS, return -1.
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
comment|/// \brief Compare the rank of the two specified floating point types,
end_comment

begin_comment
comment|/// ignoring the domain of the type (i.e. 'double' == '_Complex double').
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p LHS> \p RHS, returns 1.  If \p LHS == \p RHS, returns 0.  If
end_comment

begin_comment
comment|/// \p LHS< \p RHS, return -1.
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
comment|/// \brief Return a real floating point or a complex type (based on
end_comment

begin_comment
comment|/// \p typeDomain/\p typeSize).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param typeDomain a real floating point or complex type.
end_comment

begin_comment
comment|/// \param typeSize a real floating point or complex type.
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

begin_decl_stmt
name|unsigned
name|getTargetAddressSpace
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
block|{
return|return
name|getTargetAddressSpace
argument_list|(
name|T
operator|.
name|getQualifiers
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getTargetAddressSpace
argument_list|(
name|Qualifiers
name|Q
argument_list|)
decl|const
block|{
return|return
name|getTargetAddressSpace
argument_list|(
name|Q
operator|.
name|getAddressSpace
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getTargetAddressSpace
argument_list|(
name|unsigned
name|AS
argument_list|)
decl|const
block|{
if|if
condition|(
name|AS
operator|<
name|LangAS
operator|::
name|Offset
operator|||
name|AS
operator|>=
name|LangAS
operator|::
name|Offset
operator|+
name|LangAS
operator|::
name|Count
condition|)
return|return
name|AS
return|;
else|else
return|return
operator|(
operator|*
name|AddrSpaceMap
operator|)
index|[
name|AS
operator|-
name|LangAS
operator|::
name|Offset
index|]
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|addressSpaceMapManglingFor
argument_list|(
name|unsigned
name|AS
argument_list|)
decl|const
block|{
return|return
name|AddrSpaceMapMangling
operator|||
name|AS
operator|<
name|LangAS
operator|::
name|Offset
operator|||
name|AS
operator|>=
name|LangAS
operator|::
name|Offset
operator|+
name|LangAS
operator|::
name|Count
return|;
block|}
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
name|propertyTypesAreCompatible
parameter_list|(
name|QualType
parameter_list|,
name|QualType
parameter_list|)
function_decl|;
end_function_decl

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
name|getObjCIdType
argument_list|()
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
name|getObjCClassType
argument_list|()
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
name|getObjCSelType
argument_list|()
return|;
block|}
end_decl_stmt

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
parameter_list|,
name|bool
name|BlockReturnType
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
parameter_list|,
name|bool
name|BlockReturnType
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

begin_function_decl
name|bool
name|FunctionTypesMatchOnNSConsumedAttrs
parameter_list|(
specifier|const
name|FunctionProtoType
modifier|*
name|FromFunctionType
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|ToFunctionType
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

begin_decl_stmt
name|QualType
name|getCorrespondingUnsignedType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|SmallVectorImpl
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
name|SmallVectorImpl
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
comment|/// \brief Make an APSInt of the appropriate width and signedness for the
end_comment

begin_comment
comment|/// given \p Value and integer \p Type.
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
name|isSignedIntegerOrEnumerationType
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

begin_function_decl
name|bool
name|isSentinelNullExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the implementation of the ObjCInterfaceDecl \p D, or NULL if
end_comment

begin_comment
comment|/// none exists.
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
comment|/// \brief Get the implementation of the ObjCCategoryDecl \p D, or NULL if
end_comment

begin_comment
comment|/// none exists.
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
comment|/// \brief Return true if there is at least one \@implementation in the TU.
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
comment|/// \brief Get the duplicate declaration of a ObjCMethod in the same
end_comment

begin_comment
comment|/// interface, or null if none exists.
end_comment

begin_decl_stmt
specifier|const
name|ObjCMethodDecl
modifier|*
name|getObjCMethodRedeclaration
argument_list|(
specifier|const
name|ObjCMethodDecl
operator|*
name|MD
argument_list|)
decl|const
block|{
return|return
name|ObjCMethodRedecls
operator|.
name|lookup
argument_list|(
name|MD
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setObjCMethodRedeclaration
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
specifier|const
name|ObjCMethodDecl
modifier|*
name|Redecl
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|getObjCMethodRedeclaration
argument_list|(
name|MD
argument_list|)
operator|&&
literal|"MD already has a redeclaration"
argument_list|)
expr_stmt|;
name|ObjCMethodRedecls
index|[
name|MD
index|]
operator|=
name|Redecl
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns the Objective-C interface that \p ND belongs to if it is
end_comment

begin_comment
comment|/// an Objective-C method/property/ivar etc. that is part of an interface,
end_comment

begin_comment
comment|/// otherwise returns null.
end_comment

begin_decl_stmt
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|getObjContainingInterface
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|ND
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Get the copy initialization expression of the VarDecl \p VD, or
end_comment

begin_comment
comment|/// NULL if none exists.
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
comment|/// \param Callback A callback function that will be invoked on destruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Data Pointer data that will be provided to the callback function
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

begin_function_decl
name|void
name|setManglingNumber
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|ND
parameter_list|,
name|unsigned
name|Number
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|unsigned
name|getManglingNumber
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|ND
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the context for computing mangling numbers in the given
end_comment

begin_comment
comment|/// DeclContext.
end_comment

begin_function_decl
name|MangleNumberingContext
modifier|&
name|getManglingNumberContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|MangleNumberingContext
operator|*
name|createMangleNumberingContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Used by ParmVarDecl to store on the side the
end_comment

begin_comment
comment|/// index of the parameter when it exceeds the size of the normal bitfield.
end_comment

begin_function_decl
name|void
name|setParameterIndex
parameter_list|(
specifier|const
name|ParmVarDecl
modifier|*
name|D
parameter_list|,
name|unsigned
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Used by ParmVarDecl to retrieve on the side the
end_comment

begin_comment
comment|/// index of the parameter when it exceeds the size of the normal bitfield.
end_comment

begin_decl_stmt
name|unsigned
name|getParameterIndex
argument_list|(
specifier|const
name|ParmVarDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the storage for the constant value of a materialized temporary
end_comment

begin_comment
comment|/// of static storage duration.
end_comment

begin_function_decl
name|APValue
modifier|*
name|getMaterializedTemporaryValue
parameter_list|(
specifier|const
name|MaterializeTemporaryExpr
modifier|*
name|E
parameter_list|,
name|bool
name|MayCreate
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
comment|/// \brief The number of implicitly-declared move constructors.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitMoveConstructors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared move constructors for
end_comment

begin_comment
comment|/// which declarations were built.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitMoveConstructorsDeclared
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
comment|/// \brief The number of implicitly-declared move assignment operators.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitMoveAssignmentOperators
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of implicitly-declared move assignment operators for
end_comment

begin_comment
comment|/// which declarations were built.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|NumImplicitMoveAssignmentOperatorsDeclared
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

begin_macro
name|ASTContext
argument_list|(
argument|const ASTContext&
argument_list|)
end_macro

begin_expr_stmt
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTContext
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Initialize built-in types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine may only be invoked once for a given ASTContext object.
end_comment

begin_comment
comment|/// It is normally invoked by the ASTContext constructor. However, the
end_comment

begin_comment
comment|/// constructor can be asked to delay initialization, which places the burden
end_comment

begin_comment
comment|/// of calling this function on the user of that object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Target The target
end_comment

begin_function_decl
name|void
name|InitBuiltinTypes
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

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
comment|// Return the Objective-C type encoding for a given type.
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
argument_list|,
name|bool
name|StructField
operator|=
name|false
argument_list|,
name|bool
name|EncodeBlockParameters
operator|=
name|false
argument_list|,
name|bool
name|EncodeClassNames
operator|=
name|false
argument_list|,
name|bool
name|EncodePointerToObjCTypedef
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Adds the encoding of the structure's members.
end_comment

begin_decl_stmt
name|void
name|getObjCEncodingForStructureImpl
argument_list|(
name|RecordDecl
operator|*
name|RD
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
argument_list|,
name|bool
name|includeVBases
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Adds the encoding of a method parameter or return type.
end_comment

begin_decl_stmt
name|void
name|getObjCEncodingForMethodParameter
argument_list|(
name|Decl
operator|::
name|ObjCDeclQualifier
name|QT
argument_list|,
name|QualType
name|T
argument_list|,
name|std
operator|::
name|string
operator|&
name|S
argument_list|,
name|bool
name|Extended
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

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallDenseMap
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
name|llvm
operator|::
name|SmallVector
operator|<
name|void
operator|*
operator|,
literal|16
operator|>
expr|>
name|DeallocationMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|DeallocationMap
name|Deallocations
decl_stmt|;
end_decl_stmt

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

begin_expr_stmt
name|llvm
operator|::
name|OwningPtr
operator|<
name|ParentMap
operator|>
name|AllParents
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Utility function for constructing a nullary selector.
end_comment

begin_function
specifier|static
specifier|inline
name|Selector
name|GetNullarySelector
parameter_list|(
name|StringRef
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
comment|/// \brief Utility function for constructing an unary selector.
end_comment

begin_function
specifier|static
specifier|inline
name|Selector
name|GetUnarySelector
parameter_list|(
name|StringRef
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
comment|/// @brief Placement new for using the ASTContext's allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This placement form of operator new uses the ASTContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMPORTANT: These are also declared in clang/AST/AttrIterator.h! Any changes
end_comment

begin_comment
comment|/// here need to also be made there.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We intentionally avoid using a nothrow specification here so that the calls
end_comment

begin_comment
comment|/// to this operator will not perform a null check on the result -- the
end_comment

begin_comment
comment|/// underlying allocator never returns null pointers.
end_comment

begin_comment
comment|///
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
comment|/// obtaining memory.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We intentionally avoid using a nothrow specification here so that the calls
end_comment

begin_comment
comment|/// to this operator will not perform a null check on the result -- the
end_comment

begin_comment
comment|/// underlying allocator never returns null pointers.
end_comment

begin_comment
comment|///
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

