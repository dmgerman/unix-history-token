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
file|"llvm/Analysis/DIBuilder.h"
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
name|class
name|ClassTemplateSpecializationDecl
decl_stmt|;
name|class
name|GlobalDecl
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
name|DIBuilder
name|DBuilder
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
comment|/// TypeCache - Cache of previously constructed Types.
name|llvm
operator|::
name|DenseMap
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
comment|// LexicalBlockStack - Keep track of our current nested lexical block.
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
name|WeakVH
operator|>
name|RegionMap
expr_stmt|;
comment|// FnBeginRegionCount - Keep track of LexicalBlockStack counter at the
comment|// beginning of a function. This is used to pop unbalanced regions at
comment|// the end of a function.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FnBeginRegionCount
expr_stmt|;
comment|/// DebugInfoNames - This is a storage for names that are
comment|/// constructed on demand. For example, C++ destructors, C++ operators etc..
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
name|WeakVH
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
specifier|const
name|BuiltinType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
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
specifier|const
name|TagType
operator|*
name|Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateType
argument_list|(
specifier|const
name|RecordType
operator|*
name|Ty
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
argument|const ObjCObjectType *Ty
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
argument|const RValueReferenceType *Ty
argument_list|,
argument|llvm::DIFile Unit
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
name|CreateType
argument_list|(
argument|const AtomicType *Ty
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreateEnumType
argument_list|(
specifier|const
name|EnumDecl
operator|*
name|ED
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
name|getOrCreateFunctionType
argument_list|(
argument|const Decl *D
argument_list|,
argument|QualType FnType
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
specifier|const
name|NamespaceDecl
operator|*
name|N
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|CreatePointeeType
argument_list|(
argument|QualType PointeeTy
argument_list|,
argument|llvm::DIFile F
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
argument|llvm::DIType RecordTy
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
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DIType
name|T
argument_list|)
decl_stmt|;
name|void
name|CollectCXXFriends
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
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|EltTys
argument_list|,
name|llvm
operator|::
name|DIType
name|RecordTy
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
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|EltTys
argument_list|,
name|llvm
operator|::
name|DIType
name|RecordTy
argument_list|)
decl_stmt|;
name|llvm
operator|::
name|DIArray
name|CollectTemplateParams
argument_list|(
argument|const TemplateParameterList *TPList
argument_list|,
argument|const TemplateArgumentList&TAList
argument_list|,
argument|llvm::DIFile Unit
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIArray
name|CollectFunctionTemplateParams
argument_list|(
argument|const FunctionDecl *FD
argument_list|,
argument|llvm::DIFile Unit
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIArray
name|CollectCXXTemplateParams
argument_list|(
argument|const ClassTemplateSpecializationDecl *TS
argument_list|,
argument|llvm::DIFile F
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DIType
name|createFieldType
argument_list|(
argument|StringRef name
argument_list|,
argument|QualType type
argument_list|,
argument|uint64_t sizeInBitsOverride
argument_list|,
argument|SourceLocation loc
argument_list|,
argument|AccessSpecifier AS
argument_list|,
argument|uint64_t offsetInBits
argument_list|,
argument|llvm::DIFile tunit
argument_list|,
argument|llvm::DIDescriptor scope
argument_list|)
expr_stmt|;
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
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|E
argument_list|,
name|llvm
operator|::
name|DIType
name|RecordTy
argument_list|)
decl_stmt|;
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
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|EltTys
argument_list|)
decl_stmt|;
comment|// CreateLexicalBlock - Create a new lexical block node and push it on
comment|// the stack.
name|void
name|CreateLexicalBlock
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
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
block|{
name|DBuilder
operator|.
name|finalize
argument_list|()
expr_stmt|;
block|}
comment|/// setLocation - Update the current source location. If \arg loc is
comment|/// invalid it is ignored.
name|void
name|setLocation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// EmitLocation - Emit metadata to indicate a change in line/column
comment|/// information in the source file.
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
comment|/// EmitFunctionEnd - Constructs the debug code for exiting a function.
name|void
name|EmitFunctionEnd
parameter_list|(
name|CGBuilderTy
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// UpdateCompletedType - Update type cache because the type is now
comment|/// translated.
name|void
name|UpdateCompletedType
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
function_decl|;
comment|/// EmitLexicalBlockStart - Emit metadata to indicate the beginning of a
comment|/// new lexical block and push the block onto the stack.
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
comment|/// EmitLexicalBlockEnd - Emit metadata to indicate the end of a new lexical
comment|/// block and pop the current block.
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
name|unsigned
name|ArgNo
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
argument_list|)
decl_stmt|;
comment|/// EmitDeclareOfBlockLiteralArgVariable - Emit call to
comment|/// llvm.dbg.declare for the block-literal argument to a block
comment|/// invocation function.
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
name|addr
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
comment|/// EmitGlobalVariable - Emit global variable's debug info.
name|void
name|EmitGlobalVariable
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|VD
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Init
argument_list|)
decl_stmt|;
comment|/// getOrCreateRecordType - Emit record type's standalone debug info.
name|llvm
operator|::
name|DIType
name|getOrCreateRecordType
argument_list|(
argument|QualType Ty
argument_list|,
argument|SourceLocation L
argument_list|)
expr_stmt|;
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
name|unsigned
name|ArgNo
argument_list|,
name|CGBuilderTy
operator|&
name|Builder
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
argument_list|)
expr_stmt|;
comment|/// getCurrentDirname - Return current directory name.
name|StringRef
name|getCurrentDirname
parameter_list|()
function_decl|;
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
comment|/// getOrCreateMainFile - Get the file info for main compile unit.
name|llvm
operator|::
name|DIFile
name|getOrCreateMainFile
argument_list|()
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
comment|/// CreateMemberType - Create new member and increase Offset by FType's size.
name|llvm
operator|::
name|DIType
name|CreateMemberType
argument_list|(
argument|llvm::DIFile Unit
argument_list|,
argument|QualType FType
argument_list|,
argument|StringRef Name
argument_list|,
argument|uint64_t *Offset
argument_list|)
expr_stmt|;
comment|/// getFunctionDeclaration - Return debug info descriptor to describe method
comment|/// declaration for the given method definition.
name|llvm
operator|::
name|DISubprogram
name|getFunctionDeclaration
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// getFunctionName - Get function name for the given FunctionDecl. If the
comment|/// name is constructred on demand (e.g. C++ destructor) then the name
comment|/// is stored on the side.
name|StringRef
name|getFunctionName
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
comment|/// getObjCMethodName - Returns the unmangled name of an Objective-C method.
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
comment|/// getSelectorName - Return selector name. This is used for debugging
comment|/// info.
name|StringRef
name|getSelectorName
parameter_list|(
name|Selector
name|S
parameter_list|)
function_decl|;
comment|/// getClassName - Get class name including template argument list.
name|StringRef
name|getClassName
parameter_list|(
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// getVTableName - Get vtable name for the given Class.
name|StringRef
name|getVTableName
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|Decl
parameter_list|)
function_decl|;
comment|/// getLineNumber - Get line number for the location. If location is invalid
comment|/// then use current location.
name|unsigned
name|getLineNumber
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// getColumnNumber - Get column number for the location. If location is
comment|/// invalid then use current location.
name|unsigned
name|getColumnNumber
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
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

