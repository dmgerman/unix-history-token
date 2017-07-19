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
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
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
file|"clang/AST/TemplateBase.h"
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
file|"clang/Basic/Linkage.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Module.h"
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
file|"clang/Basic/SanitizerBlacklist.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/XRayLists.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
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
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<utility>
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

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTMutationListener
decl_stmt|;
name|class
name|ASTRecordLayout
decl_stmt|;
name|class
name|AtomicExpr
decl_stmt|;
name|class
name|BlockExpr
decl_stmt|;
name|class
name|CharUnits
decl_stmt|;
name|class
name|CXXABI
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|MangleNumberingContext
decl_stmt|;
name|class
name|MaterializeTemporaryExpr
decl_stmt|;
name|class
name|TargetInfo
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
name|class
name|VTableContextBase
decl_stmt|;
name|namespace
name|Builtin
block|{
name|class
name|Context
decl_stmt|;
block|}
comment|// end namespace Builtin
enum_decl|enum
name|BuiltinTemplateKind
enum_decl|:
name|int
enum_decl|;
name|namespace
name|comments
block|{
name|class
name|FullComment
decl_stmt|;
block|}
comment|// end namespace comments
struct|struct
name|TypeInfo
block|{
name|uint64_t
name|Width
decl_stmt|;
name|unsigned
name|Align
decl_stmt|;
name|bool
name|AlignIsRequired
range|:
literal|1
decl_stmt|;
name|TypeInfo
argument_list|()
operator|:
name|Width
argument_list|(
literal|0
argument_list|)
operator|,
name|Align
argument_list|(
literal|0
argument_list|)
operator|,
name|AlignIsRequired
argument_list|(
argument|false
argument_list|)
block|{}
name|TypeInfo
argument_list|(
argument|uint64_t Width
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool AlignIsRequired
argument_list|)
operator|:
name|Width
argument_list|(
name|Width
argument_list|)
operator|,
name|Align
argument_list|(
name|Align
argument_list|)
operator|,
name|AlignIsRequired
argument_list|(
argument|AlignIsRequired
argument_list|)
block|{}
block|}
struct|;
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
name|AdjustedType
operator|>
name|AdjustedTypes
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
name|ObjCTypeParamType
operator|>
name|ObjCTypeParamTypes
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
name|DependentUnaryTransformType
operator|>
name|DependentUnaryTransformTypes
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
name|DeducedTemplateSpecializationType
operator|>
name|DeducedTemplateSpecializationTypes
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
name|PipeType
operator|>
name|PipeTypes
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
expr_stmt|struct
name|TypeInfo
operator|>
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
comment|/// that appear in constant initializers to their evaluated values.  These are
comment|/// allocated in a std::map because their address must be stable.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MaterializeTemporaryExpr
operator|*
operator|,
name|APValue
operator|*
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
comment|/// \brief The typedef for the target specific predefined
comment|/// __builtin_va_list type.
name|mutable
name|TypedefDecl
modifier|*
name|BuiltinVaListDecl
decl_stmt|;
comment|/// The typedef for the predefined \c __builtin_ms_va_list type.
name|mutable
name|TypedefDecl
modifier|*
name|BuiltinMSVaListDecl
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
comment|/// The identifier 'bool'.
name|mutable
name|IdentifierInfo
modifier|*
name|BoolName
init|=
name|nullptr
decl_stmt|;
comment|/// The identifier 'NSObject'.
name|IdentifierInfo
modifier|*
name|NSObjectName
init|=
name|nullptr
decl_stmt|;
comment|/// The identifier 'NSCopying'.
name|IdentifierInfo
modifier|*
name|NSCopyingName
init|=
name|nullptr
decl_stmt|;
comment|/// The identifier '__make_integer_seq'.
name|mutable
name|IdentifierInfo
modifier|*
name|MakeIntegerSeqName
init|=
name|nullptr
decl_stmt|;
comment|/// The identifier '__type_pack_element'.
name|mutable
name|IdentifierInfo
modifier|*
name|TypePackElementName
init|=
name|nullptr
decl_stmt|;
name|QualType
name|ObjCConstantStringType
decl_stmt|;
name|mutable
name|RecordDecl
modifier|*
name|CFConstantStringTagDecl
decl_stmt|;
name|mutable
name|TypedefDecl
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
comment|/// \brief A mapping from a defining declaration to a list of modules (other
comment|/// than the owning module of the declaration) that contain merged
comment|/// definitions of that entity.
name|llvm
operator|::
name|DenseMap
operator|<
name|NamedDecl
operator|*
operator|,
name|llvm
operator|::
name|TinyPtrVector
operator|<
name|Module
operator|*
operator|>>
name|MergedDefModules
expr_stmt|;
comment|/// \brief Initializers for a module, in order. Each Decl will be either
comment|/// something that has a semantic effect on startup (such as a variable with
comment|/// a non-constant initializer), or an ImportDecl (which recursively triggers
comment|/// initialization of another module).
struct|struct
name|PerModuleInitializers
block|{
name|llvm
operator|::
name|SmallVector
operator|<
name|Decl
operator|*
operator|,
literal|4
operator|>
name|Initializers
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|uint32_t
operator|,
literal|4
operator|>
name|LazyInitializers
expr_stmt|;
name|void
name|resolve
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
block|}
struct|;
name|llvm
operator|::
name|DenseMap
operator|<
name|Module
operator|*
operator|,
name|PerModuleInitializers
operator|*
operator|>
name|ModuleInitializers
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
comment|/// \brief Keeps track of the declaration from which a using declaration was
comment|/// created during instantiation.
comment|///
comment|/// The source and target declarations are always a UsingDecl, an
comment|/// UnresolvedUsingValueDecl, or an UnresolvedUsingTypenameDecl.
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
name|NamedDecl
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
name|std
operator|::
name|unique_ptr
operator|<
name|MangleNumberingContext
operator|>>
name|MangleNumberingContexts
expr_stmt|;
comment|/// \brief Side-table of mangling numbers for declarations which rarely
comment|/// need them (like static local vars).
name|llvm
operator|::
name|MapVector
operator|<
specifier|const
name|NamedDecl
operator|*
operator|,
name|unsigned
operator|>
name|MangleNumbers
expr_stmt|;
name|llvm
operator|::
name|MapVector
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|unsigned
operator|>
name|StaticLocalNumbers
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
name|mutable
name|ExternCContextDecl
modifier|*
name|ExternCContext
decl_stmt|;
name|mutable
name|BuiltinTemplateDecl
modifier|*
name|MakeIntegerSeqDecl
decl_stmt|;
name|mutable
name|BuiltinTemplateDecl
modifier|*
name|TypePackElementDecl
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
comment|/// \brief Blacklist object that is used by sanitizers to decide which
comment|/// entities should not be instrumented.
name|std
operator|::
name|unique_ptr
operator|<
name|SanitizerBlacklist
operator|>
name|SanitizerBL
expr_stmt|;
comment|/// \brief Function filtering mechanism to determine whether a given function
comment|/// should be imbued with the XRay "always" or "never" attributes.
name|std
operator|::
name|unique_ptr
operator|<
name|XRayFunctionFilter
operator|>
name|XRayFilter
expr_stmt|;
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
name|std
operator|::
name|unique_ptr
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
specifier|const
name|TargetInfo
modifier|*
name|AuxTarget
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
name|IntrusiveRefCntPtr
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
literal|2
operator|>
name|ParentVector
expr_stmt|;
comment|/// \brief Maps from a node to its parents. This is used for nodes that have
comment|/// pointer identity only, which are more common and we can save space by
comment|/// only storing a unique pointer to them.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|void
operator|*
operator|,
name|llvm
operator|::
name|PointerUnion4
operator|<
specifier|const
name|Decl
operator|*
operator|,
specifier|const
name|Stmt
operator|*
operator|,
name|ast_type_traits
operator|::
name|DynTypedNode
operator|*
operator|,
name|ParentVector
operator|*
operator|>>
name|ParentMapPointers
expr_stmt|;
comment|/// Parent map for nodes without pointer identity. We store a full
comment|/// DynTypedNode for all keys.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ast_type_traits
operator|::
name|DynTypedNode
operator|,
name|llvm
operator|::
name|PointerUnion4
operator|<
specifier|const
name|Decl
operator|*
operator|,
specifier|const
name|Stmt
operator|*
operator|,
name|ast_type_traits
operator|::
name|DynTypedNode
operator|*
operator|,
name|ParentVector
operator|*
operator|>>
name|ParentMapOtherNodes
expr_stmt|;
comment|/// Container for either a single DynTypedNode or for an ArrayRef to
comment|/// DynTypedNode. For use with ParentMap.
name|class
name|DynTypedNodeList
block|{
typedef|typedef
name|ast_type_traits
operator|::
name|DynTypedNode
name|DynTypedNode
expr_stmt|;
name|llvm
operator|::
name|AlignedCharArrayUnion
operator|<
name|ast_type_traits
operator|::
name|DynTypedNode
operator|,
name|ArrayRef
operator|<
name|DynTypedNode
operator|>>
name|Storage
expr_stmt|;
name|bool
name|IsSingleNode
decl_stmt|;
name|public
label|:
name|DynTypedNodeList
argument_list|(
specifier|const
name|DynTypedNode
operator|&
name|N
argument_list|)
operator|:
name|IsSingleNode
argument_list|(
argument|true
argument_list|)
block|{
name|new
argument_list|(
argument|Storage.buffer
argument_list|)
name|DynTypedNode
argument_list|(
name|N
argument_list|)
block|;     }
name|DynTypedNodeList
argument_list|(
name|ArrayRef
operator|<
name|DynTypedNode
operator|>
name|A
argument_list|)
operator|:
name|IsSingleNode
argument_list|(
argument|false
argument_list|)
block|{
name|new
argument_list|(
argument|Storage.buffer
argument_list|)
name|ArrayRef
operator|<
name|DynTypedNode
operator|>
operator|(
name|A
operator|)
block|;     }
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
operator|*
name|begin
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|IsSingleNode
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ArrayRef
operator|<
name|DynTypedNode
operator|>
operator|*
operator|>
operator|(
name|Storage
operator|.
name|buffer
operator|)
operator|->
name|begin
argument_list|()
return|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|DynTypedNode
operator|*
operator|>
operator|(
name|Storage
operator|.
name|buffer
operator|)
return|;
block|}
specifier|const
name|ast_type_traits
operator|::
name|DynTypedNode
operator|*
name|end
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|IsSingleNode
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ArrayRef
operator|<
name|DynTypedNode
operator|>
operator|*
operator|>
operator|(
name|Storage
operator|.
name|buffer
operator|)
operator|->
name|end
argument_list|()
return|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|DynTypedNode
operator|*
operator|>
operator|(
name|Storage
operator|.
name|buffer
operator|)
operator|+
literal|1
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|end
argument_list|()
operator|-
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|==
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|const
name|DynTypedNode
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|<
name|size
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
expr_stmt|;
return|return
operator|*
operator|(
name|begin
argument_list|()
operator|+
name|N
operator|)
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Returns the parents of the given node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this will lazily compute the parents of all nodes
end_comment

begin_comment
comment|/// and store them for later retrieval. Thus, the first call is O(n)
end_comment

begin_comment
comment|/// in the number of AST nodes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Caveats and FIXMEs:
end_comment

begin_comment
comment|/// Calculating the parent map over all AST nodes will need to load the
end_comment

begin_comment
comment|/// full AST. This can be undesirable in the case where the full AST is
end_comment

begin_comment
comment|/// expensive to create (for example, when using precompiled header
end_comment

begin_comment
comment|/// preambles). Thus, there are good opportunities for optimization here.
end_comment

begin_comment
comment|/// One idea is to walk the given node downwards, looking for references
end_comment

begin_comment
comment|/// to declaration contexts - once a declaration context is found, compute
end_comment

begin_comment
comment|/// the parent map for the declaration context; if that can satisfy the
end_comment

begin_comment
comment|/// request, loading the whole AST can be avoided. Note that this is made
end_comment

begin_comment
comment|/// more complex by statements in templates having multiple parents - those
end_comment

begin_comment
comment|/// problems can be solved by building closure over the templated parts of
end_comment

begin_comment
comment|/// the AST, which also avoids touching large parts of the AST.
end_comment

begin_comment
comment|/// Additionally, we will want to add an interface to already give a hint
end_comment

begin_comment
comment|/// where to search for the parents, for example when looking at a statement
end_comment

begin_comment
comment|/// inside a certain function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 'NodeT' can be one of Decl, Stmt, Type, TypeLoc,
end_comment

begin_comment
comment|/// NestedNameSpecifier or NestedNameSpecifierLoc.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeT
operator|>
name|DynTypedNodeList
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
end_expr_stmt

begin_decl_stmt
name|DynTypedNodeList
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
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
end_decl_stmt

begin_function
name|SourceManager
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
name|SourceMgr
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
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
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Allocate
argument_list|(
argument|size_t Num =
literal|1
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Allocate
argument_list|(
name|Num
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|alignof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|Deallocate
argument_list|(
name|void
operator|*
name|Ptr
argument_list|)
decl|const
block|{ }
end_decl_stmt

begin_comment
comment|/// Return the total amount of physical memory allocated for representing
end_comment

begin_comment
comment|/// AST nodes and type information.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Return the total memory used for various side tables.
end_comment

begin_expr_stmt
name|size_t
name|getSideTableAllocatedMemory
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
specifier|const
name|TargetInfo
operator|*
name|getAuxTargetInfo
argument_list|()
specifier|const
block|{
return|return
name|AuxTarget
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getIntTypeForBitwidth -
end_comment

begin_comment
comment|/// sets integer QualTy according to specified details:
end_comment

begin_comment
comment|/// bitwidth, signed/unsigned.
end_comment

begin_comment
comment|/// Returns empty type if there is no appropriate target types.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// getRealTypeForBitwidth -
end_comment

begin_comment
comment|/// sets floating point QualTy according to specified bitwidth.
end_comment

begin_comment
comment|/// Returns empty type if there is no appropriate target types.
end_comment

begin_decl_stmt
name|QualType
name|getRealTypeForBitwidth
argument_list|(
name|unsigned
name|DestWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
specifier|const
name|SanitizerBlacklist
operator|&
name|getSanitizerBlacklist
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SanitizerBL
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|XRayFunctionFilter
operator|&
name|getXRayFilter
argument_list|()
specifier|const
block|{
return|return
operator|*
name|XRayFilter
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DiagnosticsEngine
operator|&
name|getDiagnostics
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief All comments in this translation unit.
end_comment

begin_decl_stmt
name|RawCommentList
name|Comments
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief True if comments are already loaded from ExternalASTSource.
end_comment

begin_decl_stmt
name|mutable
name|bool
name|CommentsLoaded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Mapping from declarations to comments attached to any
end_comment

begin_comment
comment|/// redeclaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Raw comments are owned by Comments list.  This mapping is populated
end_comment

begin_comment
comment|/// lazily.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Mapping from declarations to parsed comments attached to any
end_comment

begin_comment
comment|/// redeclaration.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Return the documentation comment attached to a given declaration,
end_comment

begin_comment
comment|/// without looking into cache.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function
name|RawCommentList
modifier|&
name|getRawCommentList
parameter_list|()
block|{
return|return
name|Comments
return|;
block|}
end_function

begin_function
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
end_function

begin_comment
comment|/// \brief Return the documentation comment attached to a given declaration.
end_comment

begin_comment
comment|/// Returns NULL if no comment is attached.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OriginalDecl if not NULL, is set to declaration AST node that had
end_comment

begin_comment
comment|/// the comment, if the comment we found comes from a redeclaration.
end_comment

begin_decl_stmt
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
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return parsed documentation comment attached to a given declaration.
end_comment

begin_comment
comment|/// Returns NULL if no comment is attached.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PP the Preprocessor used with this TU.  Could be NULL if
end_comment

begin_comment
comment|/// preprocessor is not available.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Return parsed documentation comment attached to a given declaration.
end_comment

begin_comment
comment|/// Returns NULL if no comment is attached. Does not look at any
end_comment

begin_comment
comment|/// redeclarations of the declaration.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|mutable
name|comments
operator|::
name|CommandTraits
name|CommentCommandTraits
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Iterator that visits import declarations.
end_comment

begin_decl_stmt
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
block|{}
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
block|{}
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_label
unit|};
name|public
label|:
end_label

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the attributes for the given declaration.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Erase the attributes corresponding to the given declaration.
end_comment

begin_function_decl
name|void
name|eraseDeclAttrs
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If this variable is an instantiated static data member of a
end_comment

begin_comment
comment|/// class template specialization, returns the templated static data member
end_comment

begin_comment
comment|/// from which it was instantiated.
end_comment

begin_comment
comment|// FIXME: Remove ?
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
name|TemplateOrSpecializationInfo
name|getTemplateOrSpecializationInfo
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Note that the static data member \p Inst is an instantiation of
end_comment

begin_comment
comment|/// the static data member template \p Tmpl of a class template.
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief If the given using decl \p Inst is an instantiation of a
end_comment

begin_comment
comment|/// (possibly unresolved) using decl from a template instantiation,
end_comment

begin_comment
comment|/// return it.
end_comment

begin_function_decl
name|NamedDecl
modifier|*
name|getInstantiatedFromUsingDecl
parameter_list|(
name|NamedDecl
modifier|*
name|Inst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Remember that the using decl \p Inst is an instantiation
end_comment

begin_comment
comment|/// of the using decl \p Pattern of a class template.
end_comment

begin_function_decl
name|void
name|setInstantiatedFromUsingDecl
parameter_list|(
name|NamedDecl
modifier|*
name|Inst
parameter_list|,
name|NamedDecl
modifier|*
name|Pattern
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
name|UsingShadowDecl
modifier|*
name|getInstantiatedFromUsingShadowDecl
parameter_list|(
name|UsingShadowDecl
modifier|*
name|Inst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FieldDecl
modifier|*
name|getInstantiatedFromUnnamedFieldDecl
parameter_list|(
name|FieldDecl
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
end_function_decl

begin_comment
comment|// Access to the set of methods overridden by the given C++ method.
end_comment

begin_typedef
typedef|typedef
name|CXXMethodVector
operator|::
name|const_iterator
name|overridden_cxx_method_iterator
expr_stmt|;
end_typedef

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|overridden_cxx_method_iterator
operator|>
name|overridden_method_range
expr_stmt|;
end_typedef

begin_decl_stmt
name|overridden_method_range
name|overridden_methods
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Note that the given C++ \p Method overrides the given \p
end_comment

begin_comment
comment|/// Overridden method.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Return C++ or ObjC overridden methods for the given \p Method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An ObjC method is considered to override any method in the class's
end_comment

begin_comment
comment|/// base classes, its protocols, or its categories' protocols, that has
end_comment

begin_comment
comment|/// the same selector and is of the same kind (class or instance).
end_comment

begin_comment
comment|/// A method in an implementation is not considered as overriding the same
end_comment

begin_comment
comment|/// method in the interface or its categories.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Notify the AST context that a new import declaration has been
end_comment

begin_comment
comment|/// parsed or implicitly created within this translation unit.
end_comment

begin_function_decl
name|void
name|addedLocalImportDecl
parameter_list|(
name|ImportDecl
modifier|*
name|Import
parameter_list|)
function_decl|;
end_function_decl

begin_function
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
end_function

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|import_iterator
operator|>
name|import_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|import_range
name|local_imports
argument_list|()
specifier|const
block|{
return|return
name|import_range
argument_list|(
name|import_iterator
argument_list|(
name|FirstLocalImport
argument_list|)
argument_list|,
name|import_iterator
argument_list|()
argument_list|)
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

begin_comment
comment|/// \brief Note that the definition \p ND has been merged into module \p M,
end_comment

begin_comment
comment|/// and should be visible whenever \p M is visible.
end_comment

begin_function_decl
name|void
name|mergeDefinitionIntoModule
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|,
name|Module
modifier|*
name|M
parameter_list|,
name|bool
name|NotifyListeners
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Clean up the merged definition list. Call this if you might have
end_comment

begin_comment
comment|/// added duplicates into the list.
end_comment

begin_function_decl
name|void
name|deduplicateMergedDefinitonsFor
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the additional modules in which the definition \p Def has
end_comment

begin_comment
comment|/// been merged.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
name|Module
operator|*
operator|>
name|getModulesWithMergedDefinition
argument_list|(
argument|const NamedDecl *Def
argument_list|)
block|{
name|auto
name|MergedIt
operator|=
name|MergedDefModules
operator|.
name|find
argument_list|(
name|Def
argument_list|)
block|;
if|if
condition|(
name|MergedIt
operator|==
name|MergedDefModules
operator|.
name|end
argument_list|()
condition|)
return|return
name|None
return|;
end_expr_stmt

begin_return
return|return
name|MergedIt
operator|->
name|second
return|;
end_return

begin_comment
unit|}
comment|/// Add a declaration to the list of declarations that are initialized
end_comment

begin_comment
comment|/// for a module. This will typically be a global variable (with internal
end_comment

begin_comment
comment|/// linkage) that runs module initializers, such as the iostream initializer,
end_comment

begin_comment
comment|/// or an ImportDecl nominating another module that has initializers.
end_comment

begin_expr_stmt
unit|void
name|addModuleInitializer
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|Decl
operator|*
name|Init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|addLazyModuleInitializers
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|IDs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get the initializations to perform when importing a module, if any.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|getModuleInitializers
argument_list|(
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
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

begin_expr_stmt
name|ExternCContextDecl
operator|*
name|getExternCContextDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BuiltinTemplateDecl
operator|*
name|getMakeIntegerSeqDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|BuiltinTemplateDecl
modifier|*
name|getTypePackElementDecl
parameter_list|()
function_decl|const;
end_function_decl

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
decl_stmt|,
name|Float128Ty
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
name|Float128ComplexTy
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

begin_define
define|#
directive|define
name|IMAGE_TYPE
parameter_list|(
name|ImgType
parameter_list|,
name|Id
parameter_list|,
name|SingletonId
parameter_list|,
name|Access
parameter_list|,
name|Suffix
parameter_list|)
define|\
value|CanQualType SingletonId;
end_define

begin_include
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
end_include

begin_decl_stmt
name|CanQualType
name|OCLSamplerTy
decl_stmt|,
name|OCLEventTy
decl_stmt|,
name|OCLClkEventTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|OCLQueueTy
decl_stmt|,
name|OCLReserveIDTy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|OMPArraySectionTy
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
comment|// Decl used to help define __builtin_va_list for some targets.
end_comment

begin_comment
comment|// The decl is built when constructing 'BuiltinVaListDecl'.
end_comment

begin_decl_stmt
name|mutable
name|Decl
modifier|*
name|VaListTagDecl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ASTContext
argument_list|(
name|LangOptions
operator|&
name|LOpts
argument_list|,
name|SourceManager
operator|&
name|SM
argument_list|,
name|IdentifierTable
operator|&
name|idents
argument_list|,
name|SelectorTable
operator|&
name|sels
argument_list|,
name|Builtin
operator|::
name|Context
operator|&
name|builtins
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASTContext
argument_list|(
specifier|const
name|ASTContext
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ASTContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ASTContext
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

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
name|IntrusiveRefCntPtr
operator|<
name|ExternalASTSource
operator|>
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

begin_decl_stmt
name|BuiltinTemplateDecl
modifier|*
name|buildBuiltinTemplateDecl
argument_list|(
name|BuiltinTemplateKind
name|BTK
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Create a new implicit TU-level CXXRecordDecl or RecordDecl
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_decl_stmt
name|RecordDecl
modifier|*
name|buildImplicitRecord
argument_list|(
name|StringRef
name|Name
argument_list|,
name|RecordDecl
operator|::
name|TagKind
name|TK
operator|=
name|TTK_Struct
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Create a new implicit TU-level typedef declaration.
end_comment

begin_decl_stmt
name|TypedefDecl
modifier|*
name|buildImplicitTypedef
argument_list|(
name|QualType
name|T
argument_list|,
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|QualType
name|getPipeType
argument_list|(
name|QualType
name|T
argument_list|,
name|bool
name|ReadOnly
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
comment|/// \brief Apply Objective-C protocol qualifiers to the given type.
end_comment

begin_comment
comment|/// \param allowOnPointerType specifies if we can apply protocol
end_comment

begin_comment
comment|/// qualifiers on ObjCObjectPointerType. It can be set to true when
end_comment

begin_comment
comment|/// contructing the canonical type of a Objective-C type parameter.
end_comment

begin_decl_stmt
name|QualType
name|applyObjCProtocolQualifiers
argument_list|(
name|QualType
name|type
argument_list|,
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|protocols
argument_list|,
name|bool
operator|&
name|hasError
argument_list|,
name|bool
name|allowOnPointerType
operator|=
name|false
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
comment|/// Adjust the given function result type.
end_comment

begin_decl_stmt
name|CanQualType
name|getCanonicalFunctionResultType
argument_list|(
name|QualType
name|ResultType
argument_list|)
decl|const
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
comment|/// \brief Determine whether two function types are the same, ignoring
end_comment

begin_comment
comment|/// exception specifications in cases where they're part of the type.
end_comment

begin_function_decl
name|bool
name|hasSameFunctionTypeIgnoringExceptionSpec
parameter_list|(
name|QualType
name|T
parameter_list|,
name|QualType
name|U
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Change the exception specification on a function once it is
end_comment

begin_comment
comment|/// delay-parsed, instantiated, or computed.
end_comment

begin_decl_stmt
name|void
name|adjustExceptionSpec
argument_list|(
name|FunctionDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
operator|&
name|ESI
argument_list|,
name|bool
name|AsWritten
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Return the uniqued reference to a type adjusted from the original
end_comment

begin_comment
comment|/// type to a new type.
end_comment

begin_decl_stmt
name|QualType
name|getAdjustedType
argument_list|(
name|QualType
name|Orig
argument_list|,
name|QualType
name|New
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CanQualType
name|getAdjustedType
argument_list|(
name|CanQualType
name|Orig
argument_list|,
name|CanQualType
name|New
argument_list|)
decl|const
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
name|getAdjustedType
argument_list|(
operator|(
name|QualType
operator|)
name|Orig
argument_list|,
operator|(
name|QualType
operator|)
name|New
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
comment|/// \brief Return a read_only pipe type for the specified type.
end_comment

begin_decl_stmt
name|QualType
name|getReadPipeType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return a write_only pipe type for the specified type.
end_comment

begin_decl_stmt
name|QualType
name|getWritePipeType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
block|{
return|return
name|getFunctionTypeInternal
argument_list|(
name|ResultTy
argument_list|,
name|Args
argument_list|,
name|EPI
argument_list|,
name|false
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Return a normal function type with a typed argument list.
end_comment

begin_decl_stmt
name|QualType
name|getFunctionTypeInternal
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
argument_list|,
name|bool
name|OnlyWantCanonical
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

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
name|nullptr
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
name|nullptr
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
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
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
name|getCanonicalTemplateSpecializationType
argument_list|(
name|TemplateName
name|T
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
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
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|TemplateArgument
name|getInjectedTemplateArg
parameter_list|(
name|NamedDecl
modifier|*
name|ParamDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get a template argument list with one argument per template parameter
end_comment

begin_comment
comment|/// in a template parameter list, such as for the injected class name of
end_comment

begin_comment
comment|/// a class template.
end_comment

begin_decl_stmt
name|void
name|getInjectedTemplateArgs
argument_list|(
specifier|const
name|TemplateParameterList
operator|*
name|Params
argument_list|,
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Args
argument_list|)
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
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Legacy interface: cannot provide type arguments or __kindof.
end_comment

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

begin_decl_stmt
name|QualType
name|getObjCObjectType
argument_list|(
name|QualType
name|Base
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|typeArgs
argument_list|,
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|protocols
argument_list|,
name|bool
name|isKindOf
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|QualType
name|getObjCTypeParamType
argument_list|(
specifier|const
name|ObjCTypeParamDecl
operator|*
name|Decl
argument_list|,
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|protocols
argument_list|,
name|QualType
name|Canonical
operator|=
name|QualType
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|ObjCObjectAdoptsQTypeProtocols
parameter_list|(
name|QualType
name|QT
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// QIdProtocolsAdoptObjCObjectProtocols - Checks that protocols in
end_comment

begin_comment
comment|/// QT's qualified-id protocol list adopt all protocols in IDecl's list
end_comment

begin_comment
comment|/// of protocols.
end_comment

begin_function_decl
name|bool
name|QIdProtocolsAdoptObjCObjectProtocols
parameter_list|(
name|QualType
name|QT
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

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
name|AutoTypeKeyword
name|Keyword
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
comment|/// \brief C++1z deduced class template specialization type.
end_comment

begin_decl_stmt
name|QualType
name|getDeducedTemplateSpecializationType
argument_list|(
name|TemplateName
name|Template
argument_list|,
name|QualType
name|DeducedType
argument_list|,
name|bool
name|IsDependent
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Return the unique signed counterpart of
end_comment

begin_comment
comment|/// the integer type corresponding to size_t.
end_comment

begin_expr_stmt
name|CanQualType
name|getSignedSizeType
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
name|getTypedefType
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

begin_expr_stmt
name|TypedefDecl
operator|*
name|getCFConstantStringDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RecordDecl
operator|*
name|getCFConstantStringTagDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// Retrieve the identifier 'NSObject'.
end_comment

begin_function
name|IdentifierInfo
modifier|*
name|getNSObjectName
parameter_list|()
block|{
if|if
condition|(
operator|!
name|NSObjectName
condition|)
block|{
name|NSObjectName
operator|=
operator|&
name|Idents
operator|.
name|get
argument_list|(
literal|"NSObject"
argument_list|)
expr_stmt|;
block|}
return|return
name|NSObjectName
return|;
block|}
end_function

begin_comment
comment|/// Retrieve the identifier 'NSCopying'.
end_comment

begin_function
name|IdentifierInfo
modifier|*
name|getNSCopyingName
parameter_list|()
block|{
if|if
condition|(
operator|!
name|NSCopyingName
condition|)
block|{
name|NSCopyingName
operator|=
operator|&
name|Idents
operator|.
name|get
argument_list|(
literal|"NSCopying"
argument_list|)
expr_stmt|;
block|}
return|return
name|NSCopyingName
return|;
block|}
end_function

begin_comment
comment|/// Retrieve the identifier 'bool'.
end_comment

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getBoolName
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|BoolName
condition|)
name|BoolName
operator|=
operator|&
name|Idents
operator|.
name|get
argument_list|(
literal|"bool"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|BoolName
return|;
end_return

begin_expr_stmt
unit|}    IdentifierInfo
operator|*
name|getMakeIntegerSeqName
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|MakeIntegerSeqName
condition|)
name|MakeIntegerSeqName
operator|=
operator|&
name|Idents
operator|.
name|get
argument_list|(
literal|"__make_integer_seq"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|MakeIntegerSeqName
return|;
end_return

begin_expr_stmt
unit|}    IdentifierInfo
operator|*
name|getTypePackElementName
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|TypePackElementName
condition|)
name|TypePackElementName
operator|=
operator|&
name|Idents
operator|.
name|get
argument_list|(
literal|"__type_pack_element"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|TypePackElementName
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the Objective-C "instancetype" type, if already known;
end_comment

begin_comment
comment|/// otherwise, returns a NULL type;
end_comment

begin_macro
unit|QualType
name|getObjCInstanceType
argument_list|()
end_macro

begin_block
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getObjCInstanceTypeDecl
argument_list|()
argument_list|)
return|;
block|}
end_block

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
name|nullptr
argument_list|,
name|QualType
operator|*
name|NotEncodedT
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit the Objective-C property type encoding for the given
end_comment

begin_comment
comment|/// type \p T into \p S.
end_comment

begin_decl_stmt
name|void
name|getObjCEncodingForPropertyType
argument_list|(
name|QualType
name|T
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

begin_expr_stmt
name|std
operator|::
name|string
name|getObjCEncodingForFunctionDecl
argument_list|(
argument|const FunctionDecl *Decl
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Emit the encoded type for the method declaration \p Decl into
end_comment

begin_comment
comment|/// \p S.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getObjCEncodingForMethodDecl
argument_list|(
argument|const ObjCMethodDecl *Decl
argument_list|,
argument|bool Extended = false
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|std
operator|::
name|string
name|getObjCEncodingForPropertyDecl
argument_list|(
argument|const ObjCPropertyDecl *PD
argument_list|,
argument|const Decl *Container
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

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

begin_decl_stmt
name|ObjCPropertyImplDecl
modifier|*
name|getObjCPropertyImplDeclForPropertyDecl
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
name|Decl
operator|*
name|getVaListTagDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Retrieve the C type declaration corresponding to the predefined
end_comment

begin_comment
comment|/// \c __builtin_ms_va_list type.
end_comment

begin_expr_stmt
name|TypedefDecl
operator|*
name|getBuiltinMSVaListDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Retrieve the type of the \c __builtin_ms_va_list type.
end_comment

begin_expr_stmt
name|QualType
name|getBuiltinMSVaListType
argument_list|()
specifier|const
block|{
return|return
name|getTypeDeclType
argument_list|(
name|getBuiltinMSVaListDecl
argument_list|()
argument_list|)
return|;
block|}
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
name|nullptr
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

begin_decl_stmt
name|TypeInfo
name|getTypeInfoImpl
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

begin_decl_stmt
name|TypeInfo
name|getTypeInfo
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TypeInfo
name|getTypeInfo
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
operator|.
name|getTypePtr
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Get default simd alignment of the specified complete type in bits.
end_comment

begin_decl_stmt
name|unsigned
name|getOpenMPDefaultSimdAlign
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|Width
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
name|Width
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
name|Align
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
name|Align
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the ABI-specified alignment of a type, in bits, or 0 if
end_comment

begin_comment
comment|/// the type is incomplete and we cannot determine the alignment (for
end_comment

begin_comment
comment|/// example, from alignment attributes).
end_comment

begin_decl_stmt
name|unsigned
name|getTypeAlignIfKnown
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
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
comment|/// \brief Determine if the alignment the type has was required using an
end_comment

begin_comment
comment|/// alignment attribute.
end_comment

begin_decl_stmt
name|bool
name|isAlignmentRequired
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isAlignmentRequired
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Return the default alignment for __attribute__((aligned)) on
end_comment

begin_comment
comment|/// this target, to be used if no alignment value is specified.
end_comment

begin_expr_stmt
name|unsigned
name|getTargetDefaultAlignForAttributeAligned
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// Loading virtual member pointers using the virtual inheritance model
end_comment

begin_comment
comment|/// always results in an adjustment using the vbtable even if the index is
end_comment

begin_comment
comment|/// zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is usually OK because the first slot in the vbtable points
end_comment

begin_comment
comment|/// backwards to the top of the MDC.  However, the MDC might be reusing a
end_comment

begin_comment
comment|/// vbptr from an nv-base.  In this case, the first slot in the vbtable
end_comment

begin_comment
comment|/// points to the start of the nv-base which introduced the vbptr and *not*
end_comment

begin_comment
comment|/// the MDC.  Modify the NonVirtualBaseAdjustment to account for this.
end_comment

begin_decl_stmt
name|CharUnits
name|getOffsetOfBaseWithVBPtr
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/// Get the offset of an ObjCIvarDecl in bits.
end_comment

begin_decl_stmt
name|uint64_t
name|lookupFieldBitOffset
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OID
argument_list|,
specifier|const
name|ObjCImplementationDecl
operator|*
name|ID
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
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
name|VTableContextBase
modifier|*
name|getVTableContext
parameter_list|()
function_decl|;
end_function_decl

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

begin_decl_stmt
name|bool
name|hasSameType
argument_list|(
specifier|const
name|Type
operator|*
name|T1
argument_list|,
specifier|const
name|Type
operator|*
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

begin_decl_stmt
name|bool
name|hasSameNullabilityTypeQualifier
argument_list|(
name|QualType
name|SubT
argument_list|,
name|QualType
name|SuperT
argument_list|,
name|bool
name|IsParam
argument_list|)
decl|const
block|{
name|auto
name|SubTnullability
init|=
name|SubT
operator|->
name|getNullability
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|auto
name|SuperTnullability
init|=
name|SuperT
operator|->
name|getNullability
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|SubTnullability
operator|.
name|hasValue
argument_list|()
operator|==
name|SuperTnullability
operator|.
name|hasValue
argument_list|()
condition|)
block|{
comment|// Neither has nullability; return true
if|if
condition|(
operator|!
name|SubTnullability
condition|)
return|return
name|true
return|;
comment|// Both have nullability qualifier.
if|if
condition|(
operator|*
name|SubTnullability
operator|==
operator|*
name|SuperTnullability
operator|||
operator|*
name|SubTnullability
operator|==
name|NullabilityKind
operator|::
name|Unspecified
operator|||
operator|*
name|SuperTnullability
operator|==
name|NullabilityKind
operator|::
name|Unspecified
condition|)
return|return
name|true
return|;
if|if
condition|(
name|IsParam
condition|)
block|{
comment|// Ok for the superclass method parameter to be "nonnull" and the subclass
comment|// method parameter to be "nullable"
return|return
operator|(
operator|*
name|SuperTnullability
operator|==
name|NullabilityKind
operator|::
name|NonNull
operator|&&
operator|*
name|SubTnullability
operator|==
name|NullabilityKind
operator|::
name|Nullable
operator|)
return|;
block|}
else|else
block|{
comment|// For the return type, it's okay for the superclass method to specify
comment|// "nullable" and the subclass method specify "nonnull"
return|return
operator|(
operator|*
name|SuperTnullability
operator|==
name|NullabilityKind
operator|::
name|Nullable
operator|&&
operator|*
name|SubTnullability
operator|==
name|NullabilityKind
operator|::
name|NonNull
operator|)
return|;
block|}
block|}
return|return
name|true
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

begin_decl_stmt
name|QualType
name|getExceptionObjectType
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get target-dependent integer value for null pointer which is used for
end_comment

begin_comment
comment|/// constant folding.
end_comment

begin_decl_stmt
name|uint64_t
name|getTargetNullPointerValue
argument_list|(
name|QualType
name|QT
argument_list|)
decl|const
decl_stmt|;
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
operator|>=
name|LangAS
operator|::
name|FirstTargetAddressSpace
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
name|mergeFunctionParameterTypes
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
name|doFunctionTypesMatchOnExtParameterInfos
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

begin_function_decl
name|void
name|ResetObjCLayout
parameter_list|(
specifier|const
name|ObjCContainerDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

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
comment|// If Type is a signed integer type larger than 64 bits, we need to be sure
comment|// to sign extend Res appropriately.
name|llvm
operator|::
name|APSInt
name|Res
argument_list|(
literal|64
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
name|unsigned
name|Width
operator|=
name|getIntWidth
argument_list|(
name|Type
argument_list|)
block|;
if|if
condition|(
name|Width
operator|!=
name|Res
operator|.
name|getBitWidth
argument_list|()
condition|)
return|return
name|Res
operator|.
name|extOrTrunc
argument_list|(
name|Width
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|Res
return|;
end_return

begin_expr_stmt
unit|}    bool
name|isSentinelNullExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

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
decl_stmt|;
end_decl_stmt

begin_function_decl
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
function_decl|;
end_function_decl

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

begin_comment
comment|/// If T isn't trivially destructible, calls AddDeallocation to register it
end_comment

begin_comment
comment|/// for destruction.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|addDestruction
argument_list|(
argument|T *Ptr
argument_list|)
block|{
if|if
condition|(
operator|!
name|std
operator|::
name|is_trivially_destructible
operator|<
name|T
operator|>
operator|::
name|value
condition|)
block|{
name|auto
name|DestroyPtr
init|=
index|[]
operator|(
name|void
operator|*
name|V
operator|)
block|{
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|V
operator|)
operator|->
expr|~
name|T
argument_list|()
block|; }
decl_stmt|;
name|AddDeallocation
argument_list|(
name|DestroyPtr
argument_list|,
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_macro
unit|}    GVALinkage
name|GetGVALinkageForFunction
argument_list|(
argument|const FunctionDecl *FD
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

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
specifier|const
name|CXXConstructorDecl
modifier|*
name|getCopyConstructorForExceptionObject
parameter_list|(
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addCopyConstructorForExceptionObject
parameter_list|(
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addTypedefNameForUnnamedTagDecl
parameter_list|(
name|TagDecl
modifier|*
name|TD
parameter_list|,
name|TypedefNameDecl
modifier|*
name|TND
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypedefNameDecl
modifier|*
name|getTypedefNameForUnnamedTagDecl
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addDeclaratorForUnnamedTagDecl
parameter_list|(
name|TagDecl
modifier|*
name|TD
parameter_list|,
name|DeclaratorDecl
modifier|*
name|DD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclaratorDecl
modifier|*
name|getDeclaratorForUnnamedTagDecl
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
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

begin_function_decl
name|void
name|setStaticLocalNumber
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|unsigned
name|Number
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|unsigned
name|getStaticLocalNumber
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
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
name|std
operator|::
name|unique_ptr
operator|<
name|MangleNumberingContext
operator|>
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
comment|/// It is normally invoked after ASTContext construction.
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
parameter_list|,
specifier|const
name|TargetInfo
modifier|*
name|AuxTarget
init|=
name|nullptr
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
argument_list|,
name|QualType
operator|*
name|NotEncodedT
operator|=
name|nullptr
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
argument_list|,
name|QualType
operator|*
name|NotEncodedT
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

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

begin_comment
comment|/// \brief Returns true if this is an inline-initialized static data member
end_comment

begin_comment
comment|/// which is treated as a definition for MSVC compatibility.
end_comment

begin_decl_stmt
name|bool
name|isMSStaticDataMemberInlineDefinition
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|class
name|InlineVariableDefinitionKind
block|{
name|None
operator|,
comment|///< Not an inline variable.
name|Weak
operator|,
comment|///< Weak definition of inline variable.
name|WeakUnknown
operator|,
comment|///< Weak for now, might become strong later in this TU.
name|Strong
comment|///< Strong definition.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Determine whether a definition of this inline variable should
end_comment

begin_comment
comment|/// be treated as a weak or strong definition. For compatibility with
end_comment

begin_comment
comment|/// C++14 and before, for a constexpr static data member, if there is an
end_comment

begin_comment
comment|/// out-of-line declaration of the member, we may promote it from weak to
end_comment

begin_comment
comment|/// strong.
end_comment

begin_decl_stmt
name|InlineVariableDefinitionKind
name|getInlineVariableDefinitionKind
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

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

begin_comment
comment|/// \brief A set of deallocations that should be performed when the
end_comment

begin_comment
comment|/// ASTContext is destroyed.
end_comment

begin_comment
comment|// FIXME: We really should have a better mechanism in the ASTContext to
end_comment

begin_comment
comment|// manage running destructors for types which do variable sized allocation
end_comment

begin_comment
comment|// within the AST. In some places we thread the AST bump pointer allocator
end_comment

begin_comment
comment|// into the datastructures which avoids this mess during deallocation but is
end_comment

begin_comment
comment|// wasteful of memory, and here we require a lot of error prone book keeping
end_comment

begin_comment
comment|// in order to track and run destructors while we're tearing things down.
end_comment

begin_typedef
typedef|typedef
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
name|DeallocationFunctionsAndArguments
expr_stmt|;
end_typedef

begin_decl_stmt
name|DeallocationFunctionsAndArguments
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

begin_function_decl
name|void
name|ReleaseParentMapEntries
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ParentMapPointers
operator|>
name|PointerParents
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ParentMapOtherNodes
operator|>
name|OtherParents
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|VTableContextBase
operator|>
name|VTContext
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_enum
enum|enum
name|PragmaSectionFlag
enum|:
name|unsigned
block|{
name|PSF_None
init|=
literal|0
block|,
name|PSF_Read
init|=
literal|0x1
block|,
name|PSF_Write
init|=
literal|0x2
block|,
name|PSF_Execute
init|=
literal|0x4
block|,
name|PSF_Implicit
init|=
literal|0x8
block|,
name|PSF_Invalid
init|=
literal|0x80000000U
block|,   }
enum|;
end_enum

begin_struct
struct|struct
name|SectionInfo
block|{
name|DeclaratorDecl
modifier|*
name|Decl
decl_stmt|;
name|SourceLocation
name|PragmaSectionLocation
decl_stmt|;
name|int
name|SectionFlags
decl_stmt|;
name|SectionInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|SectionInfo
argument_list|(
argument|DeclaratorDecl *Decl
argument_list|,
argument|SourceLocation PragmaSectionLocation
argument_list|,
argument|int SectionFlags
argument_list|)
block|:
name|Decl
argument_list|(
name|Decl
argument_list|)
operator|,
name|PragmaSectionLocation
argument_list|(
name|PragmaSectionLocation
argument_list|)
operator|,
name|SectionFlags
argument_list|(
argument|SectionFlags
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_expr_stmt
name|llvm
operator|::
name|StringMap
operator|<
name|SectionInfo
operator|>
name|SectionInfos
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
comment|/// Memory allocated through this placement new operator does not need to be
end_comment

begin_comment
comment|/// explicitly freed, as ASTContext will free all of this memory when it gets
end_comment

begin_comment
comment|/// destroyed. Please note that you cannot use delete on the pointer.
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
comment|/// Memory allocated through this placement new[] operator does not need to be
end_comment

begin_comment
comment|/// explicitly freed, as ASTContext will free all of this memory when it gets
end_comment

begin_comment
comment|/// destroyed. Please note that you cannot use delete on the pointer.
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

begin_comment
comment|/// \brief Create the representation of a LazyGenerationalUpdatePtr.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Owner
operator|,
name|typename
name|T
operator|,
name|void
argument_list|(
name|clang
operator|::
name|ExternalASTSource
operator|::
operator|*
name|Update
argument_list|)
argument_list|(
name|Owner
argument_list|)
operator|>
name|typename
name|clang
operator|::
name|LazyGenerationalUpdatePtr
operator|<
name|Owner
operator|,
name|T
operator|,
name|Update
operator|>
operator|::
name|ValueType
name|clang
operator|::
name|LazyGenerationalUpdatePtr
operator|<
name|Owner
operator|,
name|T
operator|,
name|Update
operator|>
operator|::
name|makeValue
argument_list|(
argument|const clang::ASTContext&Ctx
argument_list|,
argument|T Value
argument_list|)
block|{
comment|// Note, this is implemented here so that ExternalASTSource.h doesn't need to
comment|// include ASTContext.h. We explicitly instantiate it for all relevant types
comment|// in ASTContext.cpp.
if|if
condition|(
name|auto
operator|*
name|Source
operator|=
name|Ctx
operator|.
name|getExternalSource
argument_list|()
condition|)
return|return
name|new
argument_list|(
argument|Ctx
argument_list|)
name|LazyData
argument_list|(
name|Source
argument_list|,
name|Value
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|Value
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_ASTCONTEXT_H
end_comment

end_unit

