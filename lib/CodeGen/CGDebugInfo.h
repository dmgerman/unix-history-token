begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CGDebugInfo.h - DebugInfo for LLVM CodeGen -------------*- C++ -*-===//
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
comment|// This is the source-level debug info generator for llvm translation.
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
name|LLVM_CLANG_LIB_CODEGEN_CGDEBUGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGDEBUGINFO_H
end_define

begin_include
include|#
directive|include
file|"CGBuilder.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DIBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|ClassTemplateSpecializationDecl
decl_stmt|;
name|class
name|GlobalDecl
decl_stmt|;
name|class
name|ModuleMap
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|UsingDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CGBlockInfo
decl_stmt|;
comment|/// This class gathers all debug information during compilation and is
comment|/// responsible for emitting to llvm globals or pass directly to the
comment|/// backend.
name|class
name|CGDebugInfo
block|{
name|friend
name|class
name|ApplyDebugLocation
decl_stmt|;
name|friend
name|class
name|SaveAndRestoreLocation
decl_stmt|;
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
specifier|const
name|codegenoptions
operator|::
name|DebugInfoKind
name|DebugKind
expr_stmt|;
name|bool
name|DebugTypeExtRefs
decl_stmt|;
name|llvm
operator|::
name|DIBuilder
name|DBuilder
expr_stmt|;
name|llvm
operator|::
name|DICompileUnit
operator|*
name|TheCU
operator|=
name|nullptr
expr_stmt|;
name|ModuleMap
modifier|*
name|ClangModuleMap
init|=
name|nullptr
decl_stmt|;
name|ExternalASTSource
operator|::
name|ASTSourceDescriptor
name|PCHDescriptor
expr_stmt|;
name|SourceLocation
name|CurLoc
decl_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|CurInlinedAt
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|VTablePtrType
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|ClassTy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DICompositeType
operator|*
name|ObjTy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|SelTy
operator|=
name|nullptr
expr_stmt|;
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
value|llvm::DIType *SingletonId = nullptr;
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
name|llvm
operator|::
name|DIType
operator|*
name|OCLSamplerDITy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|OCLEventDITy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|OCLClkEventDITy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|OCLQueueDITy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|OCLNDRangeDITy
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|OCLReserveIDDITy
operator|=
name|nullptr
expr_stmt|;
comment|/// Cache of previously constructed Types.
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
name|TrackingMDRef
operator|>
name|TypeCache
expr_stmt|;
name|llvm
operator|::
name|SmallDenseMap
operator|<
name|llvm
operator|::
name|StringRef
operator|,
name|llvm
operator|::
name|StringRef
operator|>
name|DebugPrefixMap
expr_stmt|;
struct|struct
name|ObjCInterfaceCacheEntry
block|{
specifier|const
name|ObjCInterfaceType
modifier|*
name|Type
decl_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|Decl
expr_stmt|;
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
expr_stmt|;
name|ObjCInterfaceCacheEntry
argument_list|(
specifier|const
name|ObjCInterfaceType
operator|*
name|Type
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|)
operator|:
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Decl
argument_list|(
name|Decl
argument_list|)
operator|,
name|Unit
argument_list|(
argument|Unit
argument_list|)
block|{}
block|}
struct|;
comment|/// Cache of previously constructed interfaces which may change.
name|llvm
operator|::
name|SmallVector
operator|<
name|ObjCInterfaceCacheEntry
operator|,
literal|32
operator|>
name|ObjCInterfaceCache
expr_stmt|;
comment|/// Cache of references to clang modules and precompiled headers.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Module
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|ModuleCache
expr_stmt|;
comment|/// List of interfaces we want to keep even if orphaned.
name|std
operator|::
name|vector
operator|<
name|void
operator|*
operator|>
name|RetainedTypes
expr_stmt|;
comment|/// Cache of forward declared types to RAUW at the end of compilation.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|TagType
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>>
name|ReplaceMap
expr_stmt|;
comment|/// Cache of replaceable forward declarations (functions and
comment|/// variables) to RAUW at the end of compilation.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|DeclaratorDecl
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>>
name|FwdDeclReplaceMap
expr_stmt|;
comment|/// Keep track of our current nested lexical block.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|TypedTrackingMDRef
operator|<
name|llvm
operator|::
name|DIScope
operator|>>
name|LexicalBlockStack
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|RegionMap
expr_stmt|;
comment|/// Keep track of LexicalBlockStack counter at the beginning of a
comment|/// function. This is used to pop unbalanced regions at the end of a
comment|/// function.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FnBeginRegionCount
expr_stmt|;
comment|/// This is a storage for names that are constructed on demand. For
comment|/// example, C++ destructors, C++ operators etc..
name|llvm
operator|::
name|BumpPtrAllocator
name|DebugInfoNames
expr_stmt|;
name|StringRef
name|CWDName
decl_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|char
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|DIFileCache
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FunctionDecl
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|SPCache
expr_stmt|;
comment|/// Cache declarations relevant to DW_TAG_imported_declarations (C++
comment|/// using declarations) that aren't covered by other more specific caches.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|DeclCache
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|NamespaceDecl
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|NamespaceCache
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|NamespaceAliasDecl
operator|*
operator|,
name|llvm
operator|::
name|TrackingMDRef
operator|>
name|NamespaceAliasCache
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|TypedTrackingMDRef
operator|<
name|llvm
operator|::
name|DIDerivedType
operator|>>
name|StaticDataMemberCache
expr_stmt|;
comment|/// Helper functions for getOrCreateType.
comment|/// @{
comment|/// Currently the checksum of an interface includes the number of
comment|/// ivars and property accessors.
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|BuiltinType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|ComplexType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateQualifiedType
argument_list|(
argument|QualType Ty
argument_list|,
argument|llvm::DIFile *Fg
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|TypedefType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Fg
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|TemplateSpecializationType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Fg
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|ObjCObjectPointerType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|PointerType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|BlockPointerType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|FunctionType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
comment|/// Get structure or union type.
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|RecordType
operator|*
name|Tyg
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateTypeDefinition
argument_list|(
specifier|const
name|RecordType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DICompositeType
operator|*
name|CreateLimitedType
argument_list|(
specifier|const
name|RecordType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|void
name|CollectContainingType
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|DICompositeType
operator|*
name|CT
argument_list|)
decl_stmt|;
comment|/// Get Objective-C interface type.
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|ObjCInterfaceType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateTypeDefinition
argument_list|(
specifier|const
name|ObjCInterfaceType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
comment|/// Get Objective-C object type.
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|ObjCObjectType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|ObjCTypeParamType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|VectorType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|ArrayType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|LValueReferenceType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|RValueReferenceType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|MemberPointerType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|AtomicType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateType
argument_list|(
specifier|const
name|PipeType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
comment|/// Get enumeration type.
name|llvm
operator|::
name|DIType
operator|*
name|CreateEnumType
argument_list|(
specifier|const
name|EnumType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreateTypeDefinition
argument_list|(
specifier|const
name|EnumType
operator|*
name|Ty
argument_list|)
expr_stmt|;
comment|/// Look up the completed type for a self pointer in the TypeCache and
comment|/// create a copy of it with the ObjectPointer and Artificial flags
comment|/// set. If the type is not cached, a new one is created. This should
comment|/// never happen though, since creating a type for the implicit self
comment|/// argument implies that we already parsed the interface definition
comment|/// and the ivar declarations in the implementation.
name|llvm
operator|::
name|DIType
operator|*
name|CreateSelfType
argument_list|(
specifier|const
name|QualType
operator|&
name|QualTy
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|Ty
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// Get the type from the cache or return null type if it doesn't
comment|/// exist.
name|llvm
operator|::
name|DIType
operator|*
name|getTypeOrNull
argument_list|(
specifier|const
name|QualType
argument_list|)
expr_stmt|;
comment|/// Return the debug type for a C++ method.
comment|/// \arg CXXMethodDecl is of FunctionType. This function type is
comment|/// not updated to include implicit \c this pointer. Use this routine
comment|/// to get a method type which includes \c this pointer.
name|llvm
operator|::
name|DISubroutineType
operator|*
name|getOrCreateMethodType
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DISubroutineType
operator|*
name|getOrCreateInstanceMethodType
argument_list|(
argument|QualType ThisPtr
argument_list|,
argument|const FunctionProtoType *Func
argument_list|,
argument|llvm::DIFile *Unit
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DISubroutineType
operator|*
name|getOrCreateFunctionType
argument_list|(
argument|const Decl *D
argument_list|,
argument|QualType FnType
argument_list|,
argument|llvm::DIFile *F
argument_list|)
expr_stmt|;
comment|/// \return debug info descriptor for vtable.
name|llvm
operator|::
name|DIType
operator|*
name|getOrCreateVTablePtrType
argument_list|(
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
comment|/// \return namespace descriptor for the given namespace decl.
name|llvm
operator|::
name|DINamespace
operator|*
name|getOrCreateNamespace
argument_list|(
specifier|const
name|NamespaceDecl
operator|*
name|N
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|CreatePointerLikeType
argument_list|(
argument|llvm::dwarf::Tag Tag
argument_list|,
argument|const Type *Ty
argument_list|,
argument|QualType PointeeTy
argument_list|,
argument|llvm::DIFile *F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|getOrCreateStructPtrType
argument_list|(
argument|StringRef Name
argument_list|,
argument|llvm::DIType *&Cache
argument_list|)
expr_stmt|;
comment|/// A helper function to create a subprogram for a single member
comment|/// function GlobalDecl.
name|llvm
operator|::
name|DISubprogram
operator|*
name|CreateCXXMemberFunction
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|RecordTy
argument_list|)
expr_stmt|;
comment|/// A helper function to collect debug info for C++ member
comment|/// functions. This is used while creating debug info entry for a
comment|/// Record.
name|void
name|CollectCXXMemberFunctions
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|T
argument_list|)
decl_stmt|;
comment|/// A helper function to collect debug info for C++ base
comment|/// classes. This is used while creating debug info entry for a
comment|/// Record.
name|void
name|CollectCXXBases
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|EltTys
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|RecordTy
argument_list|)
decl_stmt|;
comment|/// Helper function for CollectCXXBases.
comment|/// Adds debug info entries for types in Bases that are not in SeenTypes.
name|void
name|CollectCXXBasesAux
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|EltTys
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|RecordTy
argument_list|,
specifier|const
name|CXXRecordDecl
operator|::
name|base_class_const_range
operator|&
name|Bases
argument_list|,
name|llvm
operator|::
name|DenseSet
operator|<
name|CanonicalDeclPtr
operator|<
specifier|const
name|CXXRecordDecl
operator|>>
operator|&
name|SeenTypes
argument_list|,
name|llvm
operator|::
name|DINode
operator|::
name|DIFlags
name|StartingFlags
argument_list|)
decl_stmt|;
comment|/// A helper function to collect template parameters.
name|llvm
operator|::
name|DINodeArray
name|CollectTemplateParams
argument_list|(
specifier|const
name|TemplateParameterList
operator|*
name|TPList
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|TAList
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|)
expr_stmt|;
comment|/// A helper function to collect debug info for function template
comment|/// parameters.
name|llvm
operator|::
name|DINodeArray
name|CollectFunctionTemplateParams
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|)
expr_stmt|;
comment|/// A helper function to collect debug info for template
comment|/// parameters.
name|llvm
operator|::
name|DINodeArray
name|CollectCXXTemplateParams
argument_list|(
specifier|const
name|ClassTemplateSpecializationDecl
operator|*
name|TS
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|createFieldType
argument_list|(
argument|StringRef name
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation loc
argument_list|,
argument|AccessSpecifier AS
argument_list|,
argument|uint64_t offsetInBits
argument_list|,
argument|uint32_t AlignInBits
argument_list|,
argument|llvm::DIFile *tunit
argument_list|,
argument|llvm::DIScope *scope
argument_list|,
argument|const RecordDecl *RD = nullptr
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
operator|*
name|createFieldType
argument_list|(
argument|StringRef name
argument_list|,
argument|QualType type
argument_list|,
argument|SourceLocation loc
argument_list|,
argument|AccessSpecifier AS
argument_list|,
argument|uint64_t offsetInBits
argument_list|,
argument|llvm::DIFile *tunit
argument_list|,
argument|llvm::DIScope *scope
argument_list|,
argument|const RecordDecl *RD = nullptr
argument_list|)
block|{
return|return
name|createFieldType
argument_list|(
name|name
argument_list|,
name|type
argument_list|,
name|loc
argument_list|,
name|AS
argument_list|,
name|offsetInBits
argument_list|,
literal|0
argument_list|,
name|tunit
argument_list|,
name|scope
argument_list|,
name|RD
argument_list|)
return|;
block|}
comment|/// Create new bit field member.
name|llvm
operator|::
name|DIType
operator|*
name|createBitFieldType
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|BitFieldDecl
argument_list|,
name|llvm
operator|::
name|DIScope
operator|*
name|RecordTy
argument_list|,
specifier|const
name|RecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// Helpers for collecting fields of a record.
comment|/// @{
name|void
name|CollectRecordLambdaFields
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|CXXDecl
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|RecordTy
argument_list|)
decl_stmt|;
name|llvm
operator|::
name|DIDerivedType
operator|*
name|CreateRecordStaticField
argument_list|(
specifier|const
name|VarDecl
operator|*
name|Var
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|RecordTy
argument_list|,
specifier|const
name|RecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
name|void
name|CollectRecordNormalField
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|uint64_t
name|OffsetInBits
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DIType
operator|*
name|RecordTy
argument_list|,
specifier|const
name|RecordDecl
operator|*
name|RD
argument_list|)
decl_stmt|;
name|void
name|CollectRecordNestedRecord
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|RD
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|E
argument_list|)
decl_stmt|;
name|void
name|CollectRecordFields
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DICompositeType
operator|*
name|RecordTy
argument_list|)
decl_stmt|;
comment|/// If the C++ class has vtable info then insert appropriate debug
comment|/// info entry in EltTys vector.
name|void
name|CollectVTableInfo
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|>
operator|&
name|EltTys
argument_list|,
name|llvm
operator|::
name|DICompositeType
operator|*
name|RecordTy
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// Create a new lexical block node and push it on the stack.
name|void
name|CreateLexicalBlock
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// If target-specific LLVM \p AddressSpace directly maps to target-specific
comment|/// DWARF address space, appends extended dereferencing mechanism to complex
comment|/// expression \p Expr. Otherwise, does nothing.
comment|///
comment|/// Extended dereferencing mechanism is has the following format:
comment|///     DW_OP_constu<DWARF Address Space> DW_OP_swap DW_OP_xderef
name|void
name|AppendAddressSpaceXDeref
argument_list|(
name|unsigned
name|AddressSpace
argument_list|,
name|SmallVectorImpl
operator|<
name|int64_t
operator|>
operator|&
name|Expr
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|CGDebugInfo
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
expr_stmt|;
operator|~
name|CGDebugInfo
argument_list|()
expr_stmt|;
name|void
name|finalize
parameter_list|()
function_decl|;
comment|/// Module debugging: Support for building PCMs.
comment|/// @{
comment|/// Set the main CU's DwoId field to \p Signature.
name|void
name|setDwoId
parameter_list|(
name|uint64_t
name|Signature
parameter_list|)
function_decl|;
comment|/// When generating debug information for a clang module or
comment|/// precompiled header, this module map will be used to determine
comment|/// the module of origin of each Decl.
name|void
name|setModuleMap
parameter_list|(
name|ModuleMap
modifier|&
name|MMap
parameter_list|)
block|{
name|ClangModuleMap
operator|=
operator|&
name|MMap
expr_stmt|;
block|}
comment|/// When generating debug information for a clang module or
comment|/// precompiled header, this module map will be used to determine
comment|/// the module of origin of each Decl.
name|void
name|setPCHDescriptor
argument_list|(
name|ExternalASTSource
operator|::
name|ASTSourceDescriptor
name|PCH
argument_list|)
block|{
name|PCHDescriptor
operator|=
name|PCH
expr_stmt|;
block|}
comment|/// @}
comment|/// Update the current source location. If \arg loc is invalid it is
comment|/// ignored.
name|void
name|setLocation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Return the current source location. This does not necessarily correspond
comment|/// to the IRBuilder's current DebugLoc.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|CurLoc
return|;
block|}
comment|/// Update the current inline scope. All subsequent calls to \p EmitLocation
comment|/// will create a location with this inlinedAt field.
name|void
name|setInlinedAt
argument_list|(
name|llvm
operator|::
name|MDNode
operator|*
name|InlinedAt
argument_list|)
block|{
name|CurInlinedAt
operator|=
name|InlinedAt
expr_stmt|;
block|}
comment|/// \return the current inline scope.
name|llvm
operator|::
name|MDNode
operator|*
name|getInlinedAt
argument_list|()
specifier|const
block|{
return|return
name|CurInlinedAt
return|;
block|}
comment|// Converts a SourceLocation to a DebugLoc
name|llvm
operator|::
name|DebugLoc
name|SourceLocToDebugLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// Emit metadata to indicate a change in line/column information in
comment|/// the source file. If the location is invalid, the previous
comment|/// location will be reused.
name|void
name|EmitLocation
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Emit a call to llvm.dbg.function.start to indicate
comment|/// start of a new function.
comment|/// \param Loc       The location of the function header.
comment|/// \param ScopeLoc  The location of the function body.
name|void
name|EmitFunctionStart
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|SourceLocation
name|ScopeLoc
argument_list|,
name|QualType
name|FnType
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// Start a new scope for an inlined function.
name|void
name|EmitInlineFunctionStart
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|,
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// End an inlined function scope.
name|void
name|EmitInlineFunctionEnd
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// Emit debug info for a function declaration.
name|void
name|EmitFunctionDecl
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|FnType
parameter_list|)
function_decl|;
comment|/// Constructs the debug code for exiting a function.
name|void
name|EmitFunctionEnd
argument_list|(
name|CGBuilderTy
operator|&
name|Builder
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
comment|/// Emit metadata to indicate the beginning of a new lexical block
comment|/// and push the block onto the stack.
name|void
name|EmitLexicalBlockStart
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Emit metadata to indicate the end of a new lexical block and pop
comment|/// the current block.
name|void
name|EmitLexicalBlockEnd
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Emit call to \c llvm.dbg.declare for an automatic variable
comment|/// declaration.
name|void
name|EmitDeclareOfAutoVariable
argument_list|(
specifier|const
name|VarDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AI
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// Emit call to \c llvm.dbg.declare for an imported variable
comment|/// declaration in a block.
name|void
name|EmitDeclareOfBlockDeclRefVariable
argument_list|(
specifier|const
name|VarDecl
operator|*
name|variable
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|storage
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|,
specifier|const
name|CGBlockInfo
operator|&
name|blockInfo
argument_list|,
name|llvm
operator|::
name|Instruction
operator|*
name|InsertPoint
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// Emit call to \c llvm.dbg.declare for an argument variable
comment|/// declaration.
name|void
name|EmitDeclareOfArgVariable
argument_list|(
specifier|const
name|VarDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AI
argument_list|,
name|unsigned
name|ArgNo
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// Emit call to \c llvm.dbg.declare for the block-literal argument
comment|/// to a block invocation function.
name|void
name|EmitDeclareOfBlockLiteralArgVariable
argument_list|(
specifier|const
name|CGBlockInfo
operator|&
name|block
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Arg
argument_list|,
name|unsigned
name|ArgNo
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|LocalAddr
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// Emit information about a global variable.
name|void
name|EmitGlobalVariable
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|,
specifier|const
name|VarDecl
operator|*
name|Decl
argument_list|)
decl_stmt|;
comment|/// Emit a constant global variable's debug info.
name|void
name|EmitGlobalVariable
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|VD
parameter_list|,
specifier|const
name|APValue
modifier|&
name|Init
parameter_list|)
function_decl|;
comment|/// Emit C++ using directive.
name|void
name|EmitUsingDirective
parameter_list|(
specifier|const
name|UsingDirectiveDecl
modifier|&
name|UD
parameter_list|)
function_decl|;
comment|/// Emit the type explicitly casted to.
name|void
name|EmitExplicitCastType
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// Emit C++ using declaration.
name|void
name|EmitUsingDecl
parameter_list|(
specifier|const
name|UsingDecl
modifier|&
name|UD
parameter_list|)
function_decl|;
comment|/// Emit an @import declaration.
name|void
name|EmitImportDecl
parameter_list|(
specifier|const
name|ImportDecl
modifier|&
name|ID
parameter_list|)
function_decl|;
comment|/// Emit C++ namespace alias.
name|llvm
operator|::
name|DIImportedEntity
operator|*
name|EmitNamespaceAlias
argument_list|(
specifier|const
name|NamespaceAliasDecl
operator|&
name|NA
argument_list|)
expr_stmt|;
comment|/// Emit record type's standalone debug info.
name|llvm
operator|::
name|DIType
operator|*
name|getOrCreateRecordType
argument_list|(
argument|QualType Ty
argument_list|,
argument|SourceLocation L
argument_list|)
expr_stmt|;
comment|/// Emit an Objective-C interface type standalone debug info.
name|llvm
operator|::
name|DIType
operator|*
name|getOrCreateInterfaceType
argument_list|(
argument|QualType Ty
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// Emit standalone debug info for a type.
name|llvm
operator|::
name|DIType
operator|*
name|getOrCreateStandaloneType
argument_list|(
argument|QualType Ty
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
name|void
name|completeType
parameter_list|(
specifier|const
name|EnumDecl
modifier|*
name|ED
parameter_list|)
function_decl|;
name|void
name|completeType
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|completeRequiredType
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|completeClassData
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|completeClass
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|completeTemplateDefinition
parameter_list|(
specifier|const
name|ClassTemplateSpecializationDecl
modifier|&
name|SD
parameter_list|)
function_decl|;
name|void
name|completeUnusedClass
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// Create debug info for a macro defined by a #define directive or a macro
comment|/// undefined by a #undef directive.
name|llvm
operator|::
name|DIMacro
operator|*
name|CreateMacro
argument_list|(
argument|llvm::DIMacroFile *Parent
argument_list|,
argument|unsigned MType
argument_list|,
argument|SourceLocation LineLoc
argument_list|,
argument|StringRef Name
argument_list|,
argument|StringRef Value
argument_list|)
expr_stmt|;
comment|/// Create debug info for a file referenced by an #include directive.
name|llvm
operator|::
name|DIMacroFile
operator|*
name|CreateTempMacroFile
argument_list|(
argument|llvm::DIMacroFile *Parent
argument_list|,
argument|SourceLocation LineLoc
argument_list|,
argument|SourceLocation FileLoc
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// Emit call to llvm.dbg.declare for a variable declaration.
name|void
name|EmitDeclare
argument_list|(
specifier|const
name|VarDecl
operator|*
name|decl
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AI
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|ArgNo
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// Build up structure info for the byref.  See \a BuildByRefType.
name|llvm
operator|::
name|DIType
operator|*
name|EmitTypeForVarWithBlocksAttr
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|,
name|uint64_t
operator|*
name|OffSet
argument_list|)
expr_stmt|;
comment|/// Get context info for the DeclContext of \p Decl.
name|llvm
operator|::
name|DIScope
operator|*
name|getDeclContextDescriptor
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// Get context info for a given DeclContext \p Decl.
name|llvm
operator|::
name|DIScope
operator|*
name|getContextDescriptor
argument_list|(
specifier|const
name|Decl
operator|*
name|Context
argument_list|,
name|llvm
operator|::
name|DIScope
operator|*
name|Default
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIScope
operator|*
name|getCurrentContextDescriptor
argument_list|(
specifier|const
name|Decl
operator|*
name|Decl
argument_list|)
expr_stmt|;
comment|/// Create a forward decl for a RecordType in a given context.
name|llvm
operator|::
name|DICompositeType
operator|*
name|getOrCreateRecordFwdDecl
argument_list|(
specifier|const
name|RecordType
operator|*
argument_list|,
name|llvm
operator|::
name|DIScope
operator|*
argument_list|)
expr_stmt|;
comment|/// Return current directory name.
name|StringRef
name|getCurrentDirname
parameter_list|()
function_decl|;
comment|/// Create new compile unit.
name|void
name|CreateCompileUnit
parameter_list|()
function_decl|;
comment|/// Remap a given path with the current debug prefix map
name|std
operator|::
name|string
name|remapDIPath
argument_list|(
argument|StringRef
argument_list|)
specifier|const
expr_stmt|;
comment|/// Compute the file checksum debug info for input file ID.
name|llvm
operator|::
name|DIFile
operator|::
name|ChecksumKind
name|computeChecksum
argument_list|(
argument|FileID FID
argument_list|,
argument|SmallString<
literal|32
argument|>&Checksum
argument_list|)
specifier|const
expr_stmt|;
comment|/// Get the file debug info descriptor for the input location.
name|llvm
operator|::
name|DIFile
operator|*
name|getOrCreateFile
argument_list|(
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// Get the file info for main compile unit.
name|llvm
operator|::
name|DIFile
operator|*
name|getOrCreateMainFile
argument_list|()
expr_stmt|;
comment|/// Get the type from the cache or create a new type if necessary.
name|llvm
operator|::
name|DIType
operator|*
name|getOrCreateType
argument_list|(
argument|QualType Ty
argument_list|,
argument|llvm::DIFile *Fg
argument_list|)
expr_stmt|;
comment|/// Get a reference to a clang module.  If \p CreateSkeletonCU is true,
comment|/// this also creates a split dwarf skeleton compile unit.
name|llvm
operator|::
name|DIModule
operator|*
name|getOrCreateModuleRef
argument_list|(
argument|ExternalASTSource::ASTSourceDescriptor Mod
argument_list|,
argument|bool CreateSkeletonCU
argument_list|)
expr_stmt|;
comment|/// DebugTypeExtRefs: If \p D originated in a clang module, return it.
name|llvm
operator|::
name|DIModule
operator|*
name|getParentModuleOrNull
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// Get the type from the cache or create a new partial type if
comment|/// necessary.
name|llvm
operator|::
name|DICompositeType
operator|*
name|getOrCreateLimitedType
argument_list|(
specifier|const
name|RecordType
operator|*
name|Ty
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|F
argument_list|)
expr_stmt|;
comment|/// Create type metadata for a source language type.
name|llvm
operator|::
name|DIType
operator|*
name|CreateTypeNode
argument_list|(
argument|QualType Ty
argument_list|,
argument|llvm::DIFile *Fg
argument_list|)
expr_stmt|;
comment|/// Create new member and increase Offset by FType's size.
name|llvm
operator|::
name|DIType
operator|*
name|CreateMemberType
argument_list|(
argument|llvm::DIFile *Unit
argument_list|,
argument|QualType FType
argument_list|,
argument|StringRef Name
argument_list|,
argument|uint64_t *Offset
argument_list|)
expr_stmt|;
comment|/// Retrieve the DIDescriptor, if any, for the canonical form of this
comment|/// declaration.
name|llvm
operator|::
name|DINode
operator|*
name|getDeclarationOrDefinition
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// \return debug info descriptor to describe method
comment|/// declaration for the given method definition.
name|llvm
operator|::
name|DISubprogram
operator|*
name|getFunctionDeclaration
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// \return debug info descriptor to describe in-class static data
comment|/// member declaration for the given out-of-class definition.  If D
comment|/// is an out-of-class definition of a static data member of a
comment|/// class, find its corresponding in-class declaration.
name|llvm
operator|::
name|DIDerivedType
operator|*
name|getOrCreateStaticDataMemberDeclarationOrNull
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// Helper that either creates a forward declaration or a stub.
name|llvm
operator|::
name|DISubprogram
operator|*
name|getFunctionFwdDeclOrStub
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|bool Stub
argument_list|)
expr_stmt|;
comment|/// Create a subprogram describing the forward declaration
comment|/// represented in the given FunctionDecl wrapped in a GlobalDecl.
name|llvm
operator|::
name|DISubprogram
operator|*
name|getFunctionForwardDeclaration
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
comment|/// Create a DISubprogram describing the function
comment|/// represented in the given FunctionDecl wrapped in a GlobalDecl.
name|llvm
operator|::
name|DISubprogram
operator|*
name|getFunctionStub
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
comment|/// Create a global variable describing the forward declaration
comment|/// represented in the given VarDecl.
name|llvm
operator|::
name|DIGlobalVariable
operator|*
name|getGlobalVariableForwardDeclaration
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
expr_stmt|;
comment|/// Return a global variable that represents one of the collection of global
comment|/// variables created for an anonmyous union.
comment|///
comment|/// Recursively collect all of the member fields of a global
comment|/// anonymous decl and create static variables for them. The first
comment|/// time this is called it needs to be on a union and then from
comment|/// there we can have additional unnamed fields.
name|llvm
operator|::
name|DIGlobalVariableExpression
operator|*
name|CollectAnonRecordDecls
argument_list|(
argument|const RecordDecl *RD
argument_list|,
argument|llvm::DIFile *Unit
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|StringRef LinkageName
argument_list|,
argument|llvm::GlobalVariable *Var
argument_list|,
argument|llvm::DIScope *DContext
argument_list|)
expr_stmt|;
comment|/// Get function name for the given FunctionDecl. If the name is
comment|/// constructed on demand (e.g., C++ destructor) then the name is
comment|/// stored on the side.
name|StringRef
name|getFunctionName
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
comment|/// Returns the unmangled name of an Objective-C method.
comment|/// This is the display name for the debugging info.
name|StringRef
name|getObjCMethodName
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
comment|/// Return selector name. This is used for debugging
comment|/// info.
name|StringRef
name|getSelectorName
parameter_list|(
name|Selector
name|S
parameter_list|)
function_decl|;
comment|/// Get class name including template argument list.
name|StringRef
name|getClassName
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// Get the vtable name for the given class.
name|StringRef
name|getVTableName
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
comment|/// Get line number for the location. If location is invalid
comment|/// then use current location.
name|unsigned
name|getLineNumber
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// Get column number for the location. If location is
comment|/// invalid then use current location.
comment|/// \param Force  Assume DebugColumnInfo option is true.
name|unsigned
name|getColumnNumber
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|Force
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Collect various properties of a FunctionDecl.
comment|/// \param GD  A GlobalDecl whose getDecl() must return a FunctionDecl.
name|void
name|collectFunctionDeclProps
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
name|Unit
argument_list|,
name|StringRef
operator|&
name|Name
argument_list|,
name|StringRef
operator|&
name|LinkageName
argument_list|,
name|llvm
operator|::
name|DIScope
operator|*
operator|&
name|FDContext
argument_list|,
name|llvm
operator|::
name|DINodeArray
operator|&
name|TParamsArray
argument_list|,
name|llvm
operator|::
name|DINode
operator|::
name|DIFlags
operator|&
name|Flags
argument_list|)
decl_stmt|;
comment|/// Collect various properties of a VarDecl.
name|void
name|collectVarDeclProps
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|,
name|llvm
operator|::
name|DIFile
operator|*
operator|&
name|Unit
argument_list|,
name|unsigned
operator|&
name|LineNo
argument_list|,
name|QualType
operator|&
name|T
argument_list|,
name|StringRef
operator|&
name|Name
argument_list|,
name|StringRef
operator|&
name|LinkageName
argument_list|,
name|llvm
operator|::
name|DIScope
operator|*
operator|&
name|VDContext
argument_list|)
decl_stmt|;
comment|/// Allocate a copy of \p A using the DebugInfoNames allocator
comment|/// and return a reference to it. If multiple arguments are given the strings
comment|/// are concatenated.
name|StringRef
name|internString
parameter_list|(
name|StringRef
name|A
parameter_list|,
name|StringRef
name|B
init|=
name|StringRef
argument_list|()
parameter_list|)
block|{
name|char
modifier|*
name|Data
init|=
name|DebugInfoNames
operator|.
name|Allocate
operator|<
name|char
operator|>
operator|(
name|A
operator|.
name|size
argument_list|()
operator|+
name|B
operator|.
name|size
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|A
operator|.
name|empty
argument_list|()
condition|)
name|std
operator|::
name|memcpy
argument_list|(
name|Data
argument_list|,
name|A
operator|.
name|data
argument_list|()
argument_list|,
name|A
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|B
operator|.
name|empty
argument_list|()
condition|)
name|std
operator|::
name|memcpy
argument_list|(
name|Data
operator|+
name|A
operator|.
name|size
argument_list|()
argument_list|,
name|B
operator|.
name|data
argument_list|()
argument_list|,
name|B
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|StringRef
argument_list|(
name|Data
argument_list|,
name|A
operator|.
name|size
argument_list|()
operator|+
name|B
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// A scoped helper to set the current debug location to the specified
comment|/// location or preferred location of the specified Expr.
name|class
name|ApplyDebugLocation
block|{
name|private
label|:
name|void
name|init
parameter_list|(
name|SourceLocation
name|TemporaryLocation
parameter_list|,
name|bool
name|DefaultToEmpty
init|=
name|false
parameter_list|)
function_decl|;
name|ApplyDebugLocation
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|bool DefaultToEmpty
argument_list|,
argument|SourceLocation TemporaryLocation
argument_list|)
empty_stmt|;
name|llvm
operator|::
name|DebugLoc
name|OriginalLocation
expr_stmt|;
name|CodeGenFunction
modifier|*
name|CGF
decl_stmt|;
name|public
label|:
comment|/// Set the location to the (valid) TemporaryLocation.
name|ApplyDebugLocation
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceLocation TemporaryLocation
argument_list|)
empty_stmt|;
name|ApplyDebugLocation
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
name|ApplyDebugLocation
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|llvm::DebugLoc Loc
argument_list|)
empty_stmt|;
name|ApplyDebugLocation
argument_list|(
name|ApplyDebugLocation
operator|&&
name|Other
argument_list|)
operator|:
name|CGF
argument_list|(
argument|Other.CGF
argument_list|)
block|{
name|Other
operator|.
name|CGF
operator|=
name|nullptr
block|;   }
operator|~
name|ApplyDebugLocation
argument_list|()
expr_stmt|;
comment|/// \brief Apply TemporaryLocation if it is valid. Otherwise switch
comment|/// to an artificial debug location that has a valid scope, but no
comment|/// line information.
comment|///
comment|/// Artificial locations are useful when emitting compiler-generated
comment|/// helper functions that have no source location associated with
comment|/// them. The DWARF specification allows the compiler to use the
comment|/// special line number 0 to indicate code that can not be
comment|/// attributed to any source location. Note that passing an empty
comment|/// SourceLocation to CGDebugInfo::setLocation() will result in the
comment|/// last valid location being reused.
specifier|static
name|ApplyDebugLocation
name|CreateArtificial
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
return|return
name|ApplyDebugLocation
argument_list|(
name|CGF
argument_list|,
name|false
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Apply TemporaryLocation if it is valid. Otherwise switch
comment|/// to an artificial debug location that has a valid scope, but no
comment|/// line information.
specifier|static
name|ApplyDebugLocation
name|CreateDefaultArtificial
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|SourceLocation
name|TemporaryLocation
parameter_list|)
block|{
return|return
name|ApplyDebugLocation
argument_list|(
name|CGF
argument_list|,
name|false
argument_list|,
name|TemporaryLocation
argument_list|)
return|;
block|}
comment|/// Set the IRBuilder to not attach debug locations.  Note that
comment|/// passing an empty SourceLocation to \a CGDebugInfo::setLocation()
comment|/// will result in the last valid location being reused.  Note that
comment|/// all instructions that do not have a location at the beginning of
comment|/// a function are counted towards to function prologue.
specifier|static
name|ApplyDebugLocation
name|CreateEmpty
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
return|return
name|ApplyDebugLocation
argument_list|(
name|CGF
argument_list|,
name|true
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// A scoped helper to set the current debug location to an inlined location.
name|class
name|ApplyInlineDebugLocation
block|{
name|SourceLocation
name|SavedLocation
decl_stmt|;
name|CodeGenFunction
modifier|*
name|CGF
decl_stmt|;
name|public
label|:
comment|/// Set up the CodeGenFunction's DebugInfo to produce inline locations for the
comment|/// function \p InlinedFn. The current debug location becomes the inlined call
comment|/// site of the inlined function.
name|ApplyInlineDebugLocation
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|GlobalDecl InlinedFn
argument_list|)
empty_stmt|;
comment|/// Restore everything back to the orginial state.
operator|~
name|ApplyInlineDebugLocation
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LIB_CODEGEN_CGDEBUGINFO_H
end_comment

end_unit

