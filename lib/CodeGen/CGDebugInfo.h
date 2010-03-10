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
comment|// This is the source level debug info generator for llvm translation.
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
name|CLANG_CODEGEN_CGDEBUGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGDEBUGINFO_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"CGBuilder.h"
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
name|VarDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
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
name|GlobalDecl
decl_stmt|;
comment|/// CGDebugInfo - This class gathers all debug information during compilation
comment|/// and is responsible for emitting to llvm globals or pass directly to
comment|/// the backend.
name|class
name|CGDebugInfo
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|llvm
operator|::
name|DIFactory
name|DebugFactory
expr_stmt|;
name|llvm
operator|::
name|DICompileUnit
name|TheCU
expr_stmt|;
name|SourceLocation
name|CurLoc
decl_stmt|,
name|PrevLoc
decl_stmt|;
name|llvm
operator|::
name|DIType
name|VTablePtrType
expr_stmt|;
comment|/// FwdDeclCount - This counter is used to ensure unique names for forward
comment|/// record decls.
name|unsigned
name|FwdDeclCount
decl_stmt|;
comment|/// TypeCache - Cache of previously constructed Types.
comment|// FIXME: Eliminate this map.  Be careful of iterator invalidation.
name|std
operator|::
name|map
operator|<
name|void
operator|*
operator|,
name|llvm
operator|::
name|WeakVH
operator|>
name|TypeCache
expr_stmt|;
name|bool
name|BlockLiteralGenericSet
decl_stmt|;
name|llvm
operator|::
name|DIType
name|BlockLiteralGeneric
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|TrackingVH
operator|<
name|llvm
operator|::
name|MDNode
operator|>
expr|>
name|RegionStack
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
name|WeakVH
operator|>
name|RegionMap
expr_stmt|;
comment|/// DebugInfoNames - This is a storage for names that are
comment|/// constructed on demand. For example, C++ destructors, C++ operators etc..
name|llvm
operator|::
name|BumpPtrAllocator
name|DebugInfoNames
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
name|WeakVH
operator|>
name|SPCache
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
name|WeakVH
operator|>
name|NameSpaceCache
expr_stmt|;
comment|/// Helper functions for getOrCreateType.
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const BuiltinType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const ComplexType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateQualifiedType
argument_list|(
argument|QualType Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const TypedefType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const ObjCObjectPointerType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const PointerType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const BlockPointerType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const FunctionType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const TagType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const RecordType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const ObjCInterfaceType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const EnumType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const VectorType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const ArrayType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const LValueReferenceType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
argument|const MemberPointerType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|getOrCreateMethodType
argument_list|(
argument|const CXXMethodDecl *Method
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|getOrCreateVTablePtrType
argument_list|(
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DINameSpace
name|getOrCreateNameSpace
argument_list|(
argument|const NamespaceDecl *N
argument_list|,
argument|llvm::DIDescriptor Unit
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreatePointerLikeType
argument_list|(
argument|unsigned Tag
argument_list|,
argument|const Type *Ty
argument_list|,
argument|QualType PointeeTy
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DISubprogram
name|CreateCXXMemberFunction
argument_list|(
argument|const CXXMethodDecl *Method
argument_list|,
argument|llvm::DIFile F
argument_list|,
argument|llvm::DICompositeType&RecordTy
argument_list|)
expr_stmt|;
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
name|F
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|DIDescriptor
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DICompositeType
operator|&
name|T
argument_list|)
decl_stmt|;
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
name|F
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|DIDescriptor
operator|>
operator|&
name|EltTys
argument_list|,
name|llvm
operator|::
name|DICompositeType
operator|&
name|RecordTy
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
name|F
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|DIDescriptor
operator|>
operator|&
name|E
argument_list|)
decl_stmt|;
name|void
name|CollectVtableInfo
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIFile
name|F
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|DIDescriptor
operator|>
operator|&
name|EltTys
argument_list|)
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
comment|/// setLocation - Update the current source location. If \arg loc is
comment|/// invalid it is ignored.
name|void
name|setLocation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// EmitStopPoint - Emit a call to llvm.dbg.stoppoint to indicate a change of
comment|/// source line.
name|void
name|EmitStopPoint
argument_list|(
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
comment|/// EmitFunctionStart - Emit a call to llvm.dbg.function.start to indicate
comment|/// start of a new function.
name|void
name|EmitFunctionStart
argument_list|(
name|GlobalDecl
name|GD
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
comment|/// EmitRegionStart - Emit a call to llvm.dbg.region.start to indicate start
comment|/// of a new block.
name|void
name|EmitRegionStart
argument_list|(
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
comment|/// EmitRegionEnd - Emit call to llvm.dbg.region.end to indicate end of a
comment|/// block.
name|void
name|EmitRegionEnd
argument_list|(
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
comment|/// EmitDeclareOfAutoVariable - Emit call to llvm.dbg.declare for an automatic
comment|/// variable declaration.
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
comment|/// EmitDeclareOfBlockDeclRefVariable - Emit call to llvm.dbg.declare for an
comment|/// imported variable declaration in a block.
name|void
name|EmitDeclareOfBlockDeclRefVariable
argument_list|(
specifier|const
name|BlockDeclRefExpr
operator|*
name|BDRE
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
argument_list|,
name|CodeGenFunction
operator|*
name|CGF
argument_list|)
decl_stmt|;
comment|/// EmitDeclareOfArgVariable - Emit call to llvm.dbg.declare for an argument
comment|/// variable declaration.
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
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// EmitGlobalVariable - Emit information about a global variable.
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
comment|/// EmitGlobalVariable - Emit information about an objective-c interface.
name|void
name|EmitGlobalVariable
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|,
name|ObjCInterfaceDecl
operator|*
name|Decl
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// EmitDeclare - Emit call to llvm.dbg.declare for a variable declaration.
name|void
name|EmitDeclare
argument_list|(
specifier|const
name|VarDecl
operator|*
name|decl
argument_list|,
name|unsigned
name|Tag
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
comment|/// EmitDeclare - Emit call to llvm.dbg.declare for a variable declaration.
name|void
name|EmitDeclare
argument_list|(
specifier|const
name|BlockDeclRefExpr
operator|*
name|BDRE
argument_list|,
name|unsigned
name|Tag
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
argument_list|,
name|CodeGenFunction
operator|*
name|CGF
argument_list|)
decl_stmt|;
comment|// EmitTypeForVarWithBlocksAttr - Build up structure info for the byref.
comment|// See BuildByRefType.
name|llvm
operator|::
name|DIType
name|EmitTypeForVarWithBlocksAttr
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|VD
argument_list|,
name|uint64_t
operator|*
name|OffSet
argument_list|)
expr_stmt|;
comment|/// getContextDescriptor - Get context info for the decl.
name|llvm
operator|::
name|DIDescriptor
name|getContextDescriptor
argument_list|(
specifier|const
name|Decl
operator|*
name|Decl
argument_list|,
name|llvm
operator|::
name|DIDescriptor
operator|&
name|CU
argument_list|)
expr_stmt|;
comment|/// CreateCompileUnit - Create new compile unit.
name|void
name|CreateCompileUnit
parameter_list|()
function_decl|;
comment|/// getOrCreateFile - Get the file debug info descriptor for the input
comment|/// location.
name|llvm
operator|::
name|DIFile
name|getOrCreateFile
argument_list|(
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
comment|/// getOrCreateType - Get the type from the cache or create a new type if
comment|/// necessary.
name|llvm
operator|::
name|DIType
name|getOrCreateType
argument_list|(
argument|QualType Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
comment|/// CreateTypeNode - Create type metadata for a source language type.
name|llvm
operator|::
name|DIType
name|CreateTypeNode
argument_list|(
argument|QualType Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
comment|/// getFunctionName - Get function name for the given FunctionDecl. If the
comment|/// name is constructred on demand (e.g. C++ destructor) then the name
comment|/// is stored on the side.
name|llvm
operator|::
name|StringRef
name|getFunctionName
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|)
expr_stmt|;
comment|/// getVtableName - Get vtable name for the given Class.
name|llvm
operator|::
name|StringRef
name|getVtableName
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Decl
argument_list|)
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

end_unit

