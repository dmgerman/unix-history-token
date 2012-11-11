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
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/LambdaMangleContext.h"
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
file|"clang/AST/RawCommentList.h"
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
name|SelectorTable
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
name|CXXConversionDecl
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
name|ParmVarDecl
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
name|TypedefNameDecl
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
name|namespace
name|comments
block|{
name|class
name|FullComment
decl_stmt|;
block|}
comment|/// ASTContext - This class holds long-lived AST nodes (such as types and
comment|/// decls) that can be referred to throughout the semantic analysis of a file.
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
name|std
operator|::
name|vector
operator|<
name|Type
operator|*
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
comment|/// TypeInfoMap - A cache from types to size and alignment information.
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
comment|///  template patterns.
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
comment|/// \brief The typedef for the target specific predefined
comment|/// __builtin_va_list type.
name|mutable
name|TypedefDecl
modifier|*
name|BuiltinVaListDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined 'id' type.
name|mutable
name|TypedefDecl
modifier|*
name|ObjCIdDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined 'SEL' type.
name|mutable
name|TypedefDecl
modifier|*
name|ObjCSelDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined 'Class' type.
name|mutable
name|TypedefDecl
modifier|*
name|ObjCClassDecl
decl_stmt|;
comment|/// \brief The typedef for the predefined 'Protocol' class in Objective-C.
name|mutable
name|ObjCInterfaceDecl
modifier|*
name|ObjCProtocolClassDecl
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
comment|/// \brief Mapping from each declaration context to its corresponding lambda
comment|/// mangling context.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|LambdaMangleContext
operator|>
name|LambdaMangleContexts
expr_stmt|;
comment|/// \brief Mapping that stores parameterIndex values for ParmVarDecls
comment|/// when that value exceeds the bitfield size of
comment|/// ParmVarDeclBits.ParameterIndex.
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
comment|/// SourceMgr - The associated SourceManager object.
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
comment|/// LangOpts - The language options used to create the AST associated with
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
name|clang
operator|::
name|PrintingPolicy
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
name|clang
operator|::
name|PrintingPolicy
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
name|comments
operator|::
name|FullComment
operator|*
name|getCommentForDecl
argument_list|(
argument|const Decl *D
argument_list|)
specifier|const
expr_stmt|;
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
comment|/// ZeroBitfieldFollowsNonBitfield - return 'true" if 'FD' is a zero-length
comment|/// bitfield which follows the non-bitfield 'LastFD'.
name|bool
name|ZeroBitfieldFollowsNonBitfield
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|LastFD
argument_list|)
decl|const
decl_stmt|;
comment|/// ZeroBitfieldFollowsBitfield - return 'true" if 'FD' is a zero-length
comment|/// bitfield which follows the bitfield 'LastFD'.
name|bool
name|ZeroBitfieldFollowsBitfield
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|LastFD
argument_list|)
decl|const
decl_stmt|;
comment|/// BitfieldFollowsBitfield - return 'true" if 'FD' is a
comment|/// bitfield which follows the bitfield 'LastFD'.
name|bool
name|BitfieldFollowsBitfield
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|LastFD
argument_list|)
decl|const
decl_stmt|;
comment|/// NonBitfieldFollowsBitfield - return 'true" if 'FD' is not a
comment|/// bitfield which follows the bitfield 'LastFD'.
name|bool
name|NonBitfieldFollowsBitfield
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|LastFD
argument_list|)
decl|const
decl_stmt|;
comment|/// BitfieldFollowsNonBitfield - return 'true" if 'FD' is a
comment|/// bitfield which follows the none bitfield 'LastFD'.
name|bool
name|BitfieldFollowsNonBitfield
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|LastFD
argument_list|)
decl|const
decl_stmt|;
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
comment|// [C++ 3.9.1p5], integer type in C99.
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
comment|/// getExtQualType - Return a type with extended qualifiers.
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
comment|/// getAddSpaceQualType - Return the uniqued reference to the type for an
end_comment

begin_comment
comment|/// address space qualified type with the specified type and address space.
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
comment|/// getObjCGCQualType - Returns the uniqued reference to the type for an
end_comment

begin_comment
comment|/// objc gc qualified type. The retulting type has a union of the qualifiers
end_comment

begin_comment
comment|/// from T and the gc attribute.
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
comment|/// getRestrictType - Returns the uniqued reference to the type for a
end_comment

begin_comment
comment|/// 'restrict' qualified type.  The resulting type has a union of the
end_comment

begin_comment
comment|/// qualifiers from T and 'restrict'.
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
comment|/// getVolatileType - Returns the uniqued reference to the type for a
end_comment

begin_comment
comment|/// 'volatile' qualified type.  The resulting type has a union of the
end_comment

begin_comment
comment|/// qualifiers from T and 'volatile'.
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
comment|/// getConstType - Returns the uniqued reference to the type for a
end_comment

begin_comment
comment|/// 'const' qualified type.  The resulting type has a union of the
end_comment

begin_comment
comment|/// qualifiers from T and 'const'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It can be reasonably expected that this will always be
end_comment

begin_comment
comment|/// equivalent to calling T.withConst().
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
comment|/// adjustFunctionType - Change the ExtInfo on a function type.
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
comment|/// getComplexType - Return the uniqued reference to the type for a complex
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
comment|/// getPointerType - Return the uniqued reference to the type for a pointer to
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
comment|/// getAtomicType - Return the uniqued reference to the atomic type for
end_comment

begin_comment
comment|/// the specified type.
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
comment|/// getBlockPointerType - Return the uniqued reference to the type for a block
end_comment

begin_comment
comment|/// of the specified type.
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
comment|/// This gets the struct used to keep track of the descriptor for pointer to
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
comment|/// This gets the struct used to keep track of the extended descriptor for
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
comment|/// This builds the struct used for __block variables.
end_comment

begin_decl_stmt
name|QualType
name|BuildByRefType
argument_list|(
name|StringRef
name|DeclName
argument_list|,
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns true iff we need copy/dispose helpers for the given type.
end_comment

begin_decl_stmt
name|bool
name|BlockRequiresCopying
argument_list|(
name|QualType
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getLValueReferenceType - Return the uniqued reference to the type for an
end_comment

begin_comment
comment|/// lvalue reference to the specified type.
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
comment|/// getRValueReferenceType - Return the uniqued reference to the type for an
end_comment

begin_comment
comment|/// rvalue reference to the specified type.
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
comment|/// getMemberPointerType - Return the uniqued reference to the type for a
end_comment

begin_comment
comment|/// member pointer to the specified type in the specified class. The class
end_comment

begin_comment
comment|/// is a Type because it could be a dependent name.
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
comment|/// getVariableArrayType - Returns a non-unique reference to the type for a
end_comment

begin_comment
comment|/// variable array of the specified element type.
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
comment|/// getDependentSizedArrayType - Returns a non-unique reference to
end_comment

begin_comment
comment|/// the type for a dependently-sized array of the specified element
end_comment

begin_comment
comment|/// type. FIXME: We will need these to be uniqued, or at least
end_comment

begin_comment
comment|/// comparable, at some point.
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
comment|/// getIncompleteArrayType - Returns a unique reference to the type for a
end_comment

begin_comment
comment|/// incomplete array of the specified element type.
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
comment|/// getConstantArrayType - Return the unique reference to the type for a
end_comment

begin_comment
comment|/// constant array of the specified element type.
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
comment|/// getVariableArrayDecayedType - Returns a vla type where known sizes
end_comment

begin_comment
comment|/// are replaced with [*].
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
comment|/// getVectorType - Return the unique reference to a vector type of
end_comment

begin_comment
comment|/// the specified element type and size. VectorType must be a built-in type.
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
comment|/// getExtVectorType - Return the unique reference to an extended vector type
end_comment

begin_comment
comment|/// of the specified element type and size.  VectorType must be a built-in
end_comment

begin_comment
comment|/// type.
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
comment|/// getDependentSizedExtVectorType - Returns a non-unique reference to
end_comment

begin_comment
comment|/// the type for a dependently-sized vector of the specified element
end_comment

begin_comment
comment|/// type. FIXME: We will need these to be uniqued, or at least
end_comment

begin_comment
comment|/// comparable, at some point.
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
comment|/// getFunctionNoProtoType - Return a K&R style C function type like 'int()'.
end_comment

begin_comment
comment|///
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
comment|/// getFunctionType - Return a normal function type with a typed
end_comment

begin_comment
comment|/// argument list.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// getTypeDeclType - Return the unique reference to the type for
end_comment

begin_comment
comment|/// the specified type declaration.
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
comment|/// getTypedefType - Return the unique reference to the type for the
end_comment

begin_comment
comment|/// specified typedef-name decl.
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
name|llvm
operator|::
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
comment|/// getObjCObjectPointerType - Return a ObjCObjectPointerType type
end_comment

begin_comment
comment|/// for the given ObjCObjectType.
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
comment|/// getTypeOfType - GCC extension.
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
comment|/// getDecltypeType - C++0x decltype.
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
comment|/// getUnaryTransformType - unary type transforms
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
comment|/// getAutoType - C++0x deduced auto type.
end_comment

begin_decl_stmt
name|QualType
name|getAutoType
argument_list|(
name|QualType
name|DeducedType
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getAutoDeductType - C++0x deduction pattern for 'auto' type.
end_comment

begin_expr_stmt
name|QualType
name|getAutoDeductType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getAutoRRefDeductType - C++0x deduction pattern for 'auto&&' type.
end_comment

begin_expr_stmt
name|QualType
name|getAutoRRefDeductType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getTagDeclType - Return the unique reference to the type for the
end_comment

begin_comment
comment|/// specified TagDecl (struct/union/class/enum) decl.
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
comment|/// getSizeType - Return the unique type for "size_t" (C99 7.17), defined
end_comment

begin_comment
comment|/// in<stddef.h>. The sizeof operator requires this (C99 6.5.3.4p4).
end_comment

begin_expr_stmt
name|CanQualType
name|getSizeType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getIntMaxType - Return the unique type for "intmax_t" (C99 7.18.1.5),
end_comment

begin_comment
comment|/// defined in<stdint.h>.
end_comment

begin_expr_stmt
name|CanQualType
name|getIntMaxType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getUIntMaxType - Return the unique type for "uintmax_t" (C99 7.18.1.5),
end_comment

begin_comment
comment|/// defined in<stdint.h>.
end_comment

begin_expr_stmt
name|CanQualType
name|getUIntMaxType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getWCharType - In C++, this returns the unique wchar_t type.  In C99, this
end_comment

begin_comment
comment|/// returns a type compatible with the type defined in<stddef.h> as defined
end_comment

begin_comment
comment|/// by the target.
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
comment|/// getSignedWCharType - Return the type of "signed wchar_t".
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
comment|/// getUnsignedWCharType - Return the type of "unsigned wchar_t".
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
comment|/// getWIntType - In C99, this returns a type compatible with the type
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
comment|/// getPointerDiffType - Return the unique type for "ptrdiff_t" (C99 7.17)
end_comment

begin_comment
comment|/// defined in<stddef.h>. Pointer - pointer requires this (C99 6.5.6p9).
end_comment

begin_expr_stmt
name|QualType
name|getPointerDiffType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// getCFConstantStringType - Return the C structure type used to represent
end_comment

begin_comment
comment|// constant CFStrings.
end_comment

begin_expr_stmt
name|QualType
name|getCFConstantStringType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Retrieve the type that 'id' has been defined to, which may be
end_comment

begin_comment
comment|/// different from the built-in 'id' if 'id' has been typedef'd.
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
comment|/// \brief Set the user-written type that redefines 'id'.
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
comment|/// \brief Retrieve the type that 'Class' has been defined to, which may be
end_comment

begin_comment
comment|/// different from the built-in 'Class' if 'Class' has been typedef'd.
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
comment|/// function.  This is in the same format as Objective-C method encodings.
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
comment|/// getObjCEncodingForMethodDecl - Return the encoded type for this method
end_comment

begin_comment
comment|/// declaration.
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
comment|/// \brief Retrieve the typedef corresponding to the predefined 'id' type
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
comment|/// the predefined 'Protocol' class.
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
comment|/// \brief Retrieve the type of the Objective-C "Protocol" class.
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
comment|/// __builtin_va_list type.
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
comment|/// \brief Retrieve the type of the __builtin_va_list type.
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
comment|/// __va_list_tag type used to help define the __builtin_va_list type for
end_comment

begin_comment
comment|/// some targets.
end_comment

begin_expr_stmt
name|QualType
name|getVaListTagType
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// getQualifiedType - Un-split a SplitQualType.
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

begin_comment
comment|/// getLifetimeQualifiedType - Returns a type with the given
end_comment

begin_comment
comment|/// lifetime qualifier.
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
name|getDefaultCXXMethodCallConv
parameter_list|(
name|bool
name|isVariadic
parameter_list|)
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
decl_stmt|;
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
comment|/// \brief Recurses in pointer/array types until it finds an objc retainable
end_comment

begin_comment
comment|/// type and returns its ownership.
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
comment|/// \brief returns true if there is at least one \@implementation in TU.
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
comment|/// interface, or null if non exists.
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
comment|/// \brief Returns the objc interface that \arg ND belongs to if it is a
end_comment

begin_comment
comment|/// objc method/property/ivar etc. that is part of an interface,
end_comment

begin_comment
comment|/// otherwise returns null.
end_comment

begin_decl_stmt
name|ObjCInterfaceDecl
modifier|*
name|getObjContainingInterface
argument_list|(
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
comment|/// \brief Retrieve the lambda mangling number for a lambda expression.
end_comment

begin_function_decl
name|unsigned
name|getLambdaManglingNumber
parameter_list|(
name|CXXMethodDecl
modifier|*
name|CallOperator
parameter_list|)
function_decl|;
end_function_decl

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

begin_expr_stmt
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
comment|/// @brief Utility function for constructing an unary selector.
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
comment|/// IMPORTANT: These are also declared in clang/AST/Attr.h! Any changes here
end_comment

begin_comment
comment|/// need to also be made there.
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

