begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenModule.h - Per-Module state for LLVM CodeGen ----*- C++ -*-===//
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
comment|// This is the internal per-translation-unit state used for llvm translation.
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
name|LLVM_CLANG_LIB_CODEGEN_CODEGENMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CODEGENMODULE_H
end_define

begin_include
include|#
directive|include
file|"CGVTables.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenTypeCache.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenTypes.h"
end_include

begin_include
include|#
directive|include
file|"SanitizerMetadata.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclOpenMP.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/GlobalDecl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Mangle.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SanitizerBlacklist.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/XRayLists.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/SanitizerStats.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|IndexedInstrProfReader
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
name|AtomicType
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCCategoryImplDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|ObjCEncodeExpr
decl_stmt|;
name|class
name|BlockExpr
decl_stmt|;
name|class
name|CharUnits
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|InitListExpr
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|ValueDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|AnnotateAttr
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|CoverageSourceInfo
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CallArgList
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenTBAA
decl_stmt|;
name|class
name|CGCXXABI
decl_stmt|;
name|class
name|CGDebugInfo
decl_stmt|;
name|class
name|CGObjCRuntime
decl_stmt|;
name|class
name|CGOpenCLRuntime
decl_stmt|;
name|class
name|CGOpenMPRuntime
decl_stmt|;
name|class
name|CGCUDARuntime
decl_stmt|;
name|class
name|BlockFieldFlags
decl_stmt|;
name|class
name|FunctionArgList
decl_stmt|;
name|class
name|CoverageMappingModuleGen
decl_stmt|;
name|class
name|TargetCodeGenInfo
decl_stmt|;
enum|enum
name|ForDefinition_t
enum|:
name|bool
block|{
name|NotForDefinition
init|=
name|false
block|,
name|ForDefinition
init|=
name|true
block|}
enum|;
struct|struct
name|OrderGlobalInits
block|{
name|unsigned
name|int
name|priority
decl_stmt|;
name|unsigned
name|int
name|lex_order
decl_stmt|;
name|OrderGlobalInits
argument_list|(
argument|unsigned int p
argument_list|,
argument|unsigned int l
argument_list|)
block|:
name|priority
argument_list|(
name|p
argument_list|)
operator|,
name|lex_order
argument_list|(
argument|l
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|OrderGlobalInits
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|priority
operator|==
name|RHS
operator|.
name|priority
operator|&&
name|lex_order
operator|==
name|RHS
operator|.
name|lex_order
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|OrderGlobalInits
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|priority
argument_list|,
name|lex_order
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|RHS
operator|.
name|priority
argument_list|,
name|RHS
operator|.
name|lex_order
argument_list|)
return|;
block|}
block|}
struct|;
struct|struct
name|ObjCEntrypoints
block|{
name|ObjCEntrypoints
argument_list|()
block|{
name|memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// void objc_autoreleasePoolPop(void*);
name|llvm
operator|::
name|Constant
operator|*
name|objc_autoreleasePoolPop
expr_stmt|;
comment|/// void *objc_autoreleasePoolPush(void);
name|llvm
operator|::
name|Constant
operator|*
name|objc_autoreleasePoolPush
expr_stmt|;
comment|/// id objc_autorelease(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_autorelease
expr_stmt|;
comment|/// id objc_autoreleaseReturnValue(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_autoreleaseReturnValue
expr_stmt|;
comment|/// void objc_copyWeak(id *dest, id *src);
name|llvm
operator|::
name|Constant
operator|*
name|objc_copyWeak
expr_stmt|;
comment|/// void objc_destroyWeak(id*);
name|llvm
operator|::
name|Constant
operator|*
name|objc_destroyWeak
expr_stmt|;
comment|/// id objc_initWeak(id*, id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_initWeak
expr_stmt|;
comment|/// id objc_loadWeak(id*);
name|llvm
operator|::
name|Constant
operator|*
name|objc_loadWeak
expr_stmt|;
comment|/// id objc_loadWeakRetained(id*);
name|llvm
operator|::
name|Constant
operator|*
name|objc_loadWeakRetained
expr_stmt|;
comment|/// void objc_moveWeak(id *dest, id *src);
name|llvm
operator|::
name|Constant
operator|*
name|objc_moveWeak
expr_stmt|;
comment|/// id objc_retain(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_retain
expr_stmt|;
comment|/// id objc_retainAutorelease(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_retainAutorelease
expr_stmt|;
comment|/// id objc_retainAutoreleaseReturnValue(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_retainAutoreleaseReturnValue
expr_stmt|;
comment|/// id objc_retainAutoreleasedReturnValue(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_retainAutoreleasedReturnValue
expr_stmt|;
comment|/// id objc_retainBlock(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_retainBlock
expr_stmt|;
comment|/// void objc_release(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_release
expr_stmt|;
comment|/// void objc_storeStrong(id*, id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_storeStrong
expr_stmt|;
comment|/// id objc_storeWeak(id*, id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_storeWeak
expr_stmt|;
comment|/// id objc_unsafeClaimAutoreleasedReturnValue(id);
name|llvm
operator|::
name|Constant
operator|*
name|objc_unsafeClaimAutoreleasedReturnValue
expr_stmt|;
comment|/// A void(void) inline asm to use to mark that the return value of
comment|/// a call will be immediately retain.
name|llvm
operator|::
name|InlineAsm
operator|*
name|retainAutoreleasedReturnValueMarker
expr_stmt|;
comment|/// void clang.arc.use(...);
name|llvm
operator|::
name|Constant
operator|*
name|clang_arc_use
expr_stmt|;
block|}
struct|;
comment|/// This class records statistics on instrumentation based profiling.
name|class
name|InstrProfStats
block|{
name|uint32_t
name|VisitedInMainFile
decl_stmt|;
name|uint32_t
name|MissingInMainFile
decl_stmt|;
name|uint32_t
name|Visited
decl_stmt|;
name|uint32_t
name|Missing
decl_stmt|;
name|uint32_t
name|Mismatched
decl_stmt|;
name|public
label|:
name|InstrProfStats
argument_list|()
operator|:
name|VisitedInMainFile
argument_list|(
literal|0
argument_list|)
operator|,
name|MissingInMainFile
argument_list|(
literal|0
argument_list|)
operator|,
name|Visited
argument_list|(
literal|0
argument_list|)
operator|,
name|Missing
argument_list|(
literal|0
argument_list|)
operator|,
name|Mismatched
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Record that we've visited a function and whether or not that function was
comment|/// in the main source file.
name|void
name|addVisited
argument_list|(
argument|bool MainFile
argument_list|)
block|{
if|if
condition|(
name|MainFile
condition|)
operator|++
name|VisitedInMainFile
expr_stmt|;
operator|++
name|Visited
expr_stmt|;
block|}
comment|/// Record that a function we've visited has no profile data.
name|void
name|addMissing
parameter_list|(
name|bool
name|MainFile
parameter_list|)
block|{
if|if
condition|(
name|MainFile
condition|)
operator|++
name|MissingInMainFile
expr_stmt|;
operator|++
name|Missing
expr_stmt|;
block|}
comment|/// Record that a function we've visited has mismatched profile data.
name|void
name|addMismatched
parameter_list|(
name|bool
name|MainFile
parameter_list|)
block|{
operator|++
name|Mismatched
expr_stmt|;
block|}
comment|/// Whether or not the stats we've gathered indicate any potential problems.
name|bool
name|hasDiagnostics
parameter_list|()
block|{
return|return
name|Missing
operator|||
name|Mismatched
return|;
block|}
comment|/// Report potential problems we've found to \c Diags.
name|void
name|reportDiagnostics
parameter_list|(
name|DiagnosticsEngine
modifier|&
name|Diags
parameter_list|,
name|StringRef
name|MainFile
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// A pair of helper functions for a __block variable.
name|class
name|BlockByrefHelpers
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
comment|// MSVC requires this type to be complete in order to process this
comment|// header.
name|public
operator|:
name|llvm
operator|::
name|Constant
operator|*
name|CopyHelper
block|;
name|llvm
operator|::
name|Constant
operator|*
name|DisposeHelper
block|;
comment|/// The alignment of the field.  This is important because
comment|/// different offsets to the field within the byref struct need to
comment|/// have different helper functions.
name|CharUnits
name|Alignment
block|;
name|BlockByrefHelpers
argument_list|(
argument|CharUnits alignment
argument_list|)
operator|:
name|Alignment
argument_list|(
argument|alignment
argument_list|)
block|{}
name|BlockByrefHelpers
argument_list|(
specifier|const
name|BlockByrefHelpers
operator|&
argument_list|)
operator|=
expr|default
block|;
name|virtual
operator|~
name|BlockByrefHelpers
argument_list|()
block|;
name|void
name|Profile
argument_list|(
argument|llvm::FoldingSetNodeID&id
argument_list|)
specifier|const
block|{
name|id
operator|.
name|AddInteger
argument_list|(
name|Alignment
operator|.
name|getQuantity
argument_list|()
argument_list|)
block|;
name|profileImpl
argument_list|(
name|id
argument_list|)
block|;   }
name|virtual
name|void
name|profileImpl
argument_list|(
argument|llvm::FoldingSetNodeID&id
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|needsCopy
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|emitCopy
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address dest
argument_list|,
argument|Address src
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|needsDispose
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|emitDispose
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address field
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
comment|/// This class organizes the cross-function state that is used while generating
comment|/// LLVM code.
name|class
name|CodeGenModule
range|:
name|public
name|CodeGenTypeCache
block|{
name|CodeGenModule
argument_list|(
specifier|const
name|CodeGenModule
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenModule
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
expr|struct
name|Structor
block|{
name|Structor
argument_list|()
operator|:
name|Priority
argument_list|(
literal|0
argument_list|)
block|,
name|Initializer
argument_list|(
name|nullptr
argument_list|)
block|,
name|AssociatedData
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|Structor
argument_list|(
argument|int Priority
argument_list|,
argument|llvm::Constant *Initializer
argument_list|,
argument|llvm::Constant *AssociatedData
argument_list|)
operator|:
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|Initializer
argument_list|(
name|Initializer
argument_list|)
block|,
name|AssociatedData
argument_list|(
argument|AssociatedData
argument_list|)
block|{}
name|int
name|Priority
block|;
name|llvm
operator|::
name|Constant
operator|*
name|Initializer
block|;
name|llvm
operator|::
name|Constant
operator|*
name|AssociatedData
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Structor
operator|>
name|CtorList
expr_stmt|;
name|private
operator|:
name|ASTContext
operator|&
name|Context
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
specifier|const
name|HeaderSearchOptions
modifier|&
name|HeaderSearchOpts
decl_stmt|;
comment|// Only used for debug info.
specifier|const
name|PreprocessorOptions
modifier|&
name|PreprocessorOpts
decl_stmt|;
comment|// Only used for debug info.
specifier|const
name|CodeGenOptions
modifier|&
name|CodeGenOpts
decl_stmt|;
name|llvm
operator|::
name|Module
operator|&
name|TheModule
expr_stmt|;
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
specifier|const
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CGCXXABI
operator|>
name|ABI
expr_stmt|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|VMContext
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CodeGenTBAA
operator|>
name|TBAA
expr_stmt|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|TargetCodeGenInfo
operator|>
name|TheTargetCodeGenInfo
expr_stmt|;
comment|// This should not be moved earlier, since its initialization depends on some
comment|// of the previous reference members being already initialized and also checks
comment|// if TheTargetCodeGenInfo is NULL
name|CodeGenTypes
name|Types
decl_stmt|;
comment|/// Holds information about C++ vtables.
name|CodeGenVTables
name|VTables
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CGObjCRuntime
operator|>
name|ObjCRuntime
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CGOpenCLRuntime
operator|>
name|OpenCLRuntime
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CGOpenMPRuntime
operator|>
name|OpenMPRuntime
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CGCUDARuntime
operator|>
name|CUDARuntime
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CGDebugInfo
operator|>
name|DebugInfo
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ObjCEntrypoints
operator|>
name|ObjCData
expr_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|NoObjCARCExceptionsMetadata
operator|=
name|nullptr
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|IndexedInstrProfReader
operator|>
name|PGOReader
expr_stmt|;
name|InstrProfStats
name|PGOStats
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|SanitizerStatReport
operator|>
name|SanStats
expr_stmt|;
comment|// A set of references that have only been seen via a weakref so far. This is
comment|// used to remove the weak of the reference if we ever see a direct reference
comment|// or a definition.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|llvm
operator|::
name|GlobalValue
operator|*
operator|,
literal|10
operator|>
name|WeakRefReferences
expr_stmt|;
comment|/// This contains all the decls which have definitions but/ which are deferred
comment|/// for emission and therefore should only be output if they are actually
comment|/// used. If a decl is in this, then it is known to have not been referenced
comment|/// yet.
name|std
operator|::
name|map
operator|<
name|StringRef
operator|,
name|GlobalDecl
operator|>
name|DeferredDecls
expr_stmt|;
comment|/// This is a list of deferred decls which we have seen that *are* actually
comment|/// referenced. These get code generated when the module is done.
struct|struct
name|DeferredGlobal
block|{
name|DeferredGlobal
argument_list|(
argument|llvm::GlobalValue *GV
argument_list|,
argument|GlobalDecl GD
argument_list|)
block|:
name|GV
argument_list|(
name|GV
argument_list|)
operator|,
name|GD
argument_list|(
argument|GD
argument_list|)
block|{}
name|llvm
operator|::
name|TrackingVH
operator|<
name|llvm
operator|::
name|GlobalValue
operator|>
name|GV
expr_stmt|;
name|GlobalDecl
name|GD
decl_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|DeferredGlobal
operator|>
name|DeferredDeclsToEmit
expr_stmt|;
name|void
name|addDeferredDeclToEmit
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
name|GlobalDecl
name|GD
argument_list|)
block|{
name|DeferredDeclsToEmit
operator|.
name|emplace_back
argument_list|(
name|GV
argument_list|,
name|GD
argument_list|)
expr_stmt|;
block|}
comment|/// List of alias we have emitted. Used to make sure that what they point to
comment|/// is defined once we get to the end of the of the translation unit.
name|std
operator|::
name|vector
operator|<
name|GlobalDecl
operator|>
name|Aliases
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|llvm
operator|::
name|TrackingVH
operator|<
name|llvm
operator|::
name|Constant
operator|>
expr|>
name|ReplacementsTy
expr_stmt|;
name|ReplacementsTy
name|Replacements
decl_stmt|;
comment|/// List of global values to be replaced with something else. Used when we
comment|/// want to replace a GlobalValue but can't identify it by its mangled name
comment|/// anymore (because the name is already taken).
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|GlobalValue
operator|*
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
operator|,
literal|8
operator|>
name|GlobalValReplacements
expr_stmt|;
comment|/// Set of global decls for which we already diagnosed mangled name conflict.
comment|/// Required to not issue a warning (on a mangling conflict) multiple times
comment|/// for the same decl.
name|llvm
operator|::
name|DenseSet
operator|<
name|GlobalDecl
operator|>
name|DiagnosedConflictingDefinitions
expr_stmt|;
comment|/// A queue of (optional) vtables to consider emitting.
name|std
operator|::
name|vector
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|>
name|DeferredVTables
expr_stmt|;
comment|/// List of global values which are required to be present in the object file;
comment|/// bitcast to i8*. This is used for forcing visibility of symbols which may
comment|/// otherwise be optimized out.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|WeakVH
operator|>
name|LLVMUsed
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|WeakVH
operator|>
name|LLVMCompilerUsed
expr_stmt|;
comment|/// Store the list of global constructors and their respective priorities to
comment|/// be emitted when the translation unit is complete.
name|CtorList
name|GlobalCtors
decl_stmt|;
comment|/// Store the list of global destructors and their respective priorities to be
comment|/// emitted when the translation unit is complete.
name|CtorList
name|GlobalDtors
decl_stmt|;
comment|/// An ordered map of canonical GlobalDecls to their mangled names.
name|llvm
operator|::
name|MapVector
operator|<
name|GlobalDecl
operator|,
name|StringRef
operator|>
name|MangledDeclNames
expr_stmt|;
name|llvm
operator|::
name|StringMap
operator|<
name|GlobalDecl
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|Manglings
expr_stmt|;
comment|/// Global annotations.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|Annotations
expr_stmt|;
comment|/// Map used to get unique annotation strings.
name|llvm
operator|::
name|StringMap
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|AnnotationStrings
expr_stmt|;
name|llvm
operator|::
name|StringMap
operator|<
name|llvm
operator|::
name|GlobalVariable
operator|*
operator|>
name|CFConstantStringMap
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|,
name|llvm
operator|::
name|GlobalVariable
operator|*
operator|>
name|ConstantStringMap
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
name|Constant
operator|*
operator|>
name|StaticLocalDeclMap
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
name|GlobalVariable
operator|*
operator|>
name|StaticLocalDeclGuardMap
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Expr
operator|*
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|MaterializedGlobalTemporaryMap
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|QualType
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|AtomicSetterHelperFnMap
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|QualType
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|AtomicGetterHelperFnMap
expr_stmt|;
comment|/// Map used to get unique type descriptor constants for sanitizers.
name|llvm
operator|::
name|DenseMap
operator|<
name|QualType
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|TypeDescriptorMap
expr_stmt|;
comment|/// Map used to track internal linkage functions declared within
comment|/// extern "C" regions.
typedef|typedef
name|llvm
operator|::
name|MapVector
operator|<
name|IdentifierInfo
operator|*
operator|,
name|llvm
operator|::
name|GlobalValue
operator|*
operator|>
name|StaticExternCMap
expr_stmt|;
name|StaticExternCMap
name|StaticExternCValues
decl_stmt|;
comment|/// \brief thread_local variables defined or used in this TU.
name|std
operator|::
name|vector
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|CXXThreadLocals
expr_stmt|;
comment|/// \brief thread_local variables with initializers that need to run
comment|/// before any thread_local variable in this TU is odr-used.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|>
name|CXXThreadLocalInits
expr_stmt|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|CXXThreadLocalInitVars
expr_stmt|;
comment|/// Global variables with initializers that need to run before main.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|>
name|CXXGlobalInits
expr_stmt|;
comment|/// When a C++ decl with an initializer is deferred, null is
comment|/// appended to CXXGlobalInits, and the index of that null is placed
comment|/// here so that the initializer will be performed in the correct
comment|/// order. Once the decl is emitted, the index is replaced with ~0U to ensure
comment|/// that we don't re-emit the initializer.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|unsigned
operator|>
name|DelayedCXXInitPosition
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|OrderGlobalInits
operator|,
name|llvm
operator|::
name|Function
operator|*
operator|>
name|GlobalInitData
expr_stmt|;
struct|struct
name|GlobalInitPriorityCmp
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|GlobalInitData
operator|&
name|LHS
operator|,
specifier|const
name|GlobalInitData
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|LHS
operator|.
name|first
operator|.
name|priority
operator|<
name|RHS
operator|.
name|first
operator|.
name|priority
return|;
block|}
block|}
struct|;
comment|/// Global variables with initializers whose order of initialization is set by
comment|/// init_priority attribute.
name|SmallVector
operator|<
name|GlobalInitData
operator|,
literal|8
operator|>
name|PrioritizedCXXGlobalInits
expr_stmt|;
comment|/// Global destructor functions and arguments that need to run on termination.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|WeakVH
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
expr|>
name|CXXGlobalDtors
expr_stmt|;
comment|/// \brief The complete set of modules that has been imported.
name|llvm
operator|::
name|SetVector
operator|<
name|clang
operator|::
name|Module
operator|*
operator|>
name|ImportedModules
expr_stmt|;
comment|/// \brief The set of modules for which the module initializers
comment|/// have been emitted.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|clang
operator|::
name|Module
operator|*
operator|,
literal|16
operator|>
name|EmittedModuleInitializers
expr_stmt|;
comment|/// \brief A vector of metadata strings.
name|SmallVector
operator|<
name|llvm
operator|::
name|Metadata
operator|*
operator|,
literal|16
operator|>
name|LinkerOptionsMetadata
expr_stmt|;
comment|/// @name Cache for Objective-C runtime types
comment|/// @{
comment|/// Cached reference to the class for constant strings. This value has type
comment|/// int * but is actually an Obj-C class pointer.
name|llvm
operator|::
name|WeakVH
name|CFConstantStringClassRef
expr_stmt|;
comment|/// \brief The type used to describe the state of a fast enumeration in
comment|/// Objective-C's for..in loop.
name|QualType
name|ObjCFastEnumerationStateType
decl_stmt|;
comment|/// @}
comment|/// Lazily create the Objective-C runtime
name|void
name|createObjCRuntime
parameter_list|()
function_decl|;
name|void
name|createOpenCLRuntime
parameter_list|()
function_decl|;
name|void
name|createOpenMPRuntime
parameter_list|()
function_decl|;
name|void
name|createCUDARuntime
parameter_list|()
function_decl|;
name|bool
name|isTriviallyRecursive
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|F
parameter_list|)
function_decl|;
name|bool
name|shouldEmitFunction
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// Map used to be sure we don't emit the same CompoundLiteral twice.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CompoundLiteralExpr
operator|*
operator|,
name|llvm
operator|::
name|GlobalVariable
operator|*
operator|>
name|EmittedCompoundLiterals
expr_stmt|;
comment|/// Map of the global blocks we've emitted, so that we don't have to re-emit
comment|/// them if the constexpr evaluator gets aggressive.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|BlockExpr
operator|*
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|EmittedGlobalBlocks
expr_stmt|;
comment|/// @name Cache for Blocks Runtime Globals
comment|/// @{
name|llvm
operator|::
name|Constant
operator|*
name|NSConcreteGlobalBlock
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|NSConcreteStackBlock
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|BlockObjectAssign
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|BlockObjectDispose
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|BlockDescriptorType
operator|=
name|nullptr
expr_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|GenericBlockLiteralType
operator|=
name|nullptr
expr_stmt|;
struct|struct
block|{
name|int
name|GlobalUniqueCount
decl_stmt|;
block|}
name|Block
struct|;
comment|/// void @llvm.lifetime.start(i64 %size, i8* nocapture<ptr>)
name|llvm
operator|::
name|Constant
operator|*
name|LifetimeStartFn
operator|=
name|nullptr
expr_stmt|;
comment|/// void @llvm.lifetime.end(i64 %size, i8* nocapture<ptr>)
name|llvm
operator|::
name|Constant
operator|*
name|LifetimeEndFn
operator|=
name|nullptr
expr_stmt|;
name|GlobalDecl
name|initializedGlobalDecl
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SanitizerMetadata
operator|>
name|SanitizerMD
expr_stmt|;
comment|/// @}
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|bool
operator|>
name|DeferredEmptyCoverageMappingDecls
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CoverageMappingModuleGen
operator|>
name|CoverageMapping
expr_stmt|;
comment|/// Mapping from canonical types to their metadata identifiers. We need to
comment|/// maintain this mapping because identifiers may be formed from distinct
comment|/// MDNodes.
name|llvm
operator|::
name|DenseMap
operator|<
name|QualType
operator|,
name|llvm
operator|::
name|Metadata
operator|*
operator|>
name|MetadataIdMap
expr_stmt|;
name|public
label|:
name|CodeGenModule
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
specifier|const
name|HeaderSearchOptions
operator|&
name|headersearchopts
argument_list|,
specifier|const
name|PreprocessorOptions
operator|&
name|ppopts
argument_list|,
specifier|const
name|CodeGenOptions
operator|&
name|CodeGenOpts
argument_list|,
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
name|CoverageSourceInfo
operator|*
name|CoverageInfo
operator|=
name|nullptr
argument_list|)
expr_stmt|;
operator|~
name|CodeGenModule
argument_list|()
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// Finalize LLVM code generation.
name|void
name|Release
parameter_list|()
function_decl|;
comment|/// Return a reference to the configured Objective-C runtime.
name|CGObjCRuntime
modifier|&
name|getObjCRuntime
parameter_list|()
block|{
if|if
condition|(
operator|!
name|ObjCRuntime
condition|)
name|createObjCRuntime
argument_list|()
expr_stmt|;
return|return
operator|*
name|ObjCRuntime
return|;
block|}
comment|/// Return true iff an Objective-C runtime has been configured.
name|bool
name|hasObjCRuntime
parameter_list|()
block|{
return|return
operator|!
operator|!
name|ObjCRuntime
return|;
block|}
comment|/// Return a reference to the configured OpenCL runtime.
name|CGOpenCLRuntime
modifier|&
name|getOpenCLRuntime
parameter_list|()
block|{
name|assert
argument_list|(
name|OpenCLRuntime
operator|!=
name|nullptr
argument_list|)
expr_stmt|;
return|return
operator|*
name|OpenCLRuntime
return|;
block|}
comment|/// Return a reference to the configured OpenMP runtime.
name|CGOpenMPRuntime
modifier|&
name|getOpenMPRuntime
parameter_list|()
block|{
name|assert
argument_list|(
name|OpenMPRuntime
operator|!=
name|nullptr
argument_list|)
expr_stmt|;
return|return
operator|*
name|OpenMPRuntime
return|;
block|}
comment|/// Return a reference to the configured CUDA runtime.
name|CGCUDARuntime
modifier|&
name|getCUDARuntime
parameter_list|()
block|{
name|assert
argument_list|(
name|CUDARuntime
operator|!=
name|nullptr
argument_list|)
expr_stmt|;
return|return
operator|*
name|CUDARuntime
return|;
block|}
name|ObjCEntrypoints
operator|&
name|getObjCEntrypoints
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ObjCData
operator|!=
name|nullptr
argument_list|)
block|;
return|return
operator|*
name|ObjCData
return|;
block|}
comment|// Version checking function, used to implement ObjC's @available:
comment|// i32 @__isOSVersionAtLeast(i32, i32, i32)
name|llvm
operator|::
name|Constant
operator|*
name|IsOSVersionAtLeastFn
operator|=
name|nullptr
expr_stmt|;
name|InstrProfStats
modifier|&
name|getPGOStats
parameter_list|()
block|{
return|return
name|PGOStats
return|;
block|}
name|llvm
operator|::
name|IndexedInstrProfReader
operator|*
name|getPGOReader
argument_list|()
specifier|const
block|{
return|return
name|PGOReader
operator|.
name|get
argument_list|()
return|;
block|}
name|CoverageMappingModuleGen
operator|*
name|getCoverageMapping
argument_list|()
specifier|const
block|{
return|return
name|CoverageMapping
operator|.
name|get
argument_list|()
return|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getStaticLocalDeclAddress
argument_list|(
argument|const VarDecl *D
argument_list|)
block|{
return|return
name|StaticLocalDeclMap
index|[
name|D
index|]
return|;
block|}
name|void
name|setStaticLocalDeclAddress
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
block|{
name|StaticLocalDeclMap
index|[
name|D
index|]
operator|=
name|C
expr_stmt|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getOrCreateStaticVarDecl
argument_list|(
argument|const VarDecl&D
argument_list|,
argument|llvm::GlobalValue::LinkageTypes Linkage
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|GlobalVariable
operator|*
name|getStaticLocalDeclGuardAddress
argument_list|(
argument|const VarDecl *D
argument_list|)
block|{
return|return
name|StaticLocalDeclGuardMap
index|[
name|D
index|]
return|;
block|}
name|void
name|setStaticLocalDeclGuardAddress
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|C
argument_list|)
block|{
name|StaticLocalDeclGuardMap
index|[
name|D
index|]
operator|=
name|C
expr_stmt|;
block|}
name|bool
name|lookupRepresentativeDecl
argument_list|(
name|StringRef
name|MangledName
argument_list|,
name|GlobalDecl
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|getAtomicSetterHelperFnMap
argument_list|(
argument|QualType Ty
argument_list|)
block|{
return|return
name|AtomicSetterHelperFnMap
index|[
name|Ty
index|]
return|;
block|}
name|void
name|setAtomicSetterHelperFnMap
argument_list|(
name|QualType
name|Ty
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Fn
argument_list|)
block|{
name|AtomicSetterHelperFnMap
index|[
name|Ty
index|]
operator|=
name|Fn
expr_stmt|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getAtomicGetterHelperFnMap
argument_list|(
argument|QualType Ty
argument_list|)
block|{
return|return
name|AtomicGetterHelperFnMap
index|[
name|Ty
index|]
return|;
block|}
name|void
name|setAtomicGetterHelperFnMap
argument_list|(
name|QualType
name|Ty
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Fn
argument_list|)
block|{
name|AtomicGetterHelperFnMap
index|[
name|Ty
index|]
operator|=
name|Fn
expr_stmt|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getTypeDescriptorFromMap
argument_list|(
argument|QualType Ty
argument_list|)
block|{
return|return
name|TypeDescriptorMap
index|[
name|Ty
index|]
return|;
block|}
name|void
name|setTypeDescriptorInMap
argument_list|(
name|QualType
name|Ty
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
block|{
name|TypeDescriptorMap
index|[
name|Ty
index|]
operator|=
name|C
expr_stmt|;
block|}
name|CGDebugInfo
modifier|*
name|getModuleDebugInfo
parameter_list|()
block|{
return|return
name|DebugInfo
operator|.
name|get
argument_list|()
return|;
block|}
name|llvm
operator|::
name|MDNode
operator|*
name|getNoObjCARCExceptionsMetadata
argument_list|()
block|{
if|if
condition|(
operator|!
name|NoObjCARCExceptionsMetadata
condition|)
name|NoObjCARCExceptionsMetadata
operator|=
name|llvm
operator|::
name|MDNode
operator|::
name|get
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
name|None
argument_list|)
expr_stmt|;
return|return
name|NoObjCARCExceptionsMetadata
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
end_expr_stmt

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
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
specifier|const
block|{
return|return
name|HeaderSearchOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
specifier|const
block|{
return|return
name|PreprocessorOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|CodeGenOptions
operator|&
name|getCodeGenOpts
argument_list|()
specifier|const
block|{
return|return
name|CodeGenOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|TheModule
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DiagnosticsEngine
operator|&
name|getDiags
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|TheModule
operator|.
name|getDataLayout
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|TargetInfo
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|Target
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|Target
operator|.
name|getTriple
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|supportsCOMDAT
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|maybeSetTrivialComdat
argument_list|(
specifier|const
name|Decl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalObject
operator|&
name|GO
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|CGCXXABI
operator|&
name|getCXXABI
argument_list|()
specifier|const
block|{
return|return
operator|*
name|ABI
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|LLVMContext
operator|&
name|getLLVMContext
argument_list|()
block|{
return|return
name|VMContext
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|shouldUseTBAA
argument_list|()
specifier|const
block|{
return|return
name|TBAA
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_function_decl
specifier|const
name|TargetCodeGenInfo
modifier|&
name|getTargetCodeGenInfo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|CodeGenTypes
modifier|&
name|getTypes
parameter_list|()
block|{
return|return
name|Types
return|;
block|}
end_function

begin_function
name|CodeGenVTables
modifier|&
name|getVTables
parameter_list|()
block|{
return|return
name|VTables
return|;
block|}
end_function

begin_function
name|ItaniumVTableContext
modifier|&
name|getItaniumVTableContext
parameter_list|()
block|{
return|return
name|VTables
operator|.
name|getItaniumVTableContext
argument_list|()
return|;
block|}
end_function

begin_function
name|MicrosoftVTableContext
modifier|&
name|getMicrosoftVTableContext
parameter_list|()
block|{
return|return
name|VTables
operator|.
name|getMicrosoftVTableContext
argument_list|()
return|;
block|}
end_function

begin_function
name|CtorList
modifier|&
name|getGlobalCtors
parameter_list|()
block|{
return|return
name|GlobalCtors
return|;
block|}
end_function

begin_function
name|CtorList
modifier|&
name|getGlobalDtors
parameter_list|()
block|{
return|return
name|GlobalDtors
return|;
block|}
end_function

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAInfo
argument_list|(
argument|QualType QTy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAInfoForVTablePtr
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAStructInfo
argument_list|(
argument|QualType QTy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the path-aware tag for given base type, access node and offset.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAStructTagInfo
argument_list|(
argument|QualType BaseTy
argument_list|,
argument|llvm::MDNode *AccessN
argument_list|,
argument|uint64_t O
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|isTypeConstant
parameter_list|(
name|QualType
name|QTy
parameter_list|,
name|bool
name|ExcludeCtorDtor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isPaddedAtomicType
parameter_list|(
name|QualType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isPaddedAtomicType
parameter_list|(
specifier|const
name|AtomicType
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Decorate the instruction with a TBAA tag. For scalar TBAA, the tag
end_comment

begin_comment
comment|/// is the same as the type. For struct-path aware TBAA, the tag
end_comment

begin_comment
comment|/// is different from the type: base type, access type and offset.
end_comment

begin_comment
comment|/// When ConvertTypeToTag is true, we create a tag based on the scalar type.
end_comment

begin_decl_stmt
name|void
name|DecorateInstructionWithTBAA
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|Inst
argument_list|,
name|llvm
operator|::
name|MDNode
operator|*
name|TBAAInfo
argument_list|,
name|bool
name|ConvertTypeToTag
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Adds !invariant.barrier !tag to instruction
end_comment

begin_decl_stmt
name|void
name|DecorateInstructionWithInvariantGroup
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|I
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit the given number of characters as a value of type size_t.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|ConstantInt
operator|*
name|getSize
argument_list|(
argument|CharUnits numChars
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Set the visibility for the given LLVM GlobalValue.
end_comment

begin_decl_stmt
name|void
name|setGlobalVisibility
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set the TLS mode for the given LLVM GlobalValue for the thread-local
end_comment

begin_comment
comment|/// variable declaration D.
end_comment

begin_decl_stmt
name|void
name|setTLSMode
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|VarDecl
operator|&
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|llvm
operator|::
name|GlobalValue
operator|::
name|VisibilityTypes
name|GetLLVMVisibility
argument_list|(
argument|Visibility V
argument_list|)
block|{
switch|switch
condition|(
name|V
condition|)
block|{
case|case
name|DefaultVisibility
case|:
return|return
name|llvm
operator|::
name|GlobalValue
operator|::
name|DefaultVisibility
return|;
case|case
name|HiddenVisibility
case|:
return|return
name|llvm
operator|::
name|GlobalValue
operator|::
name|HiddenVisibility
return|;
case|case
name|ProtectedVisibility
case|:
return|return
name|llvm
operator|::
name|GlobalValue
operator|::
name|ProtectedVisibility
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"unknown visibility!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobal
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|ForDefinition_t IsForDefinition                                     = NotForDefinition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Will return a global variable of the given type. If a variable with a
end_comment

begin_comment
comment|/// different type already exists then a new  variable with the right type
end_comment

begin_comment
comment|/// will be created and all uses of the old variable will be replaced with a
end_comment

begin_comment
comment|/// bitcast to the new variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|CreateOrReplaceCXXRuntimeVariable
argument_list|(
argument|StringRef Name
argument_list|,
argument|llvm::Type *Ty
argument_list|,
argument|llvm::GlobalValue::LinkageTypes Linkage
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|CreateGlobalInitOrDestructFunction
argument_list|(
argument|llvm::FunctionType *ty
argument_list|,
argument|const Twine&name
argument_list|,
argument|const CGFunctionInfo&FI
argument_list|,
argument|SourceLocation Loc = SourceLocation()
argument_list|,
argument|bool TLS = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the address space of the underlying global variable for D, as
end_comment

begin_comment
comment|/// determined by its declaration. Normally this is the same as the address
end_comment

begin_comment
comment|/// space of D's type, but in CUDA, address spaces are associated with
end_comment

begin_comment
comment|/// declarations, not types.
end_comment

begin_function_decl
name|unsigned
name|GetGlobalVarAddressSpace
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return the llvm::Constant for the address of the given global variable.
end_comment

begin_comment
comment|/// If Ty is non-null and if the global doesn't exist, then it will be created
end_comment

begin_comment
comment|/// with the specified type instead of whatever the normal requested type
end_comment

begin_comment
comment|/// would be. If IsForDefinition is true, it is guranteed that an actual
end_comment

begin_comment
comment|/// global with type Ty will be returned, not conversion of a variable with
end_comment

begin_comment
comment|/// the same mangled name but some other type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobalVar
argument_list|(
argument|const VarDecl *D
argument_list|,
argument|llvm::Type *Ty = nullptr
argument_list|,
argument|ForDefinition_t IsForDefinition                                        = NotForDefinition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the address of the given function. If Ty is non-null, then this
end_comment

begin_comment
comment|/// function will use the specified type if it has to create it.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfFunction
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|llvm::Type *Ty = nullptr
argument_list|,
argument|bool ForVTable = false
argument_list|,
argument|bool DontDefer = false
argument_list|,
argument|ForDefinition_t IsForDefinition                                       = NotForDefinition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the address of the RTTI descriptor for the given type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfRTTIDescriptor
argument_list|(
argument|QualType Ty
argument_list|,
argument|bool ForEH = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the address of a uuid descriptor .
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfUuidDescriptor
parameter_list|(
specifier|const
name|CXXUuidofExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the address of the thunk for the given global decl.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfThunk
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|const ThunkInfo&Thunk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get a reference to the target of VD.
end_comment

begin_function_decl
name|ConstantAddress
name|GetWeakRefReference
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the assumed alignment of an opaque pointer to the given class.
end_comment

begin_function_decl
name|CharUnits
name|getClassPointerAlignment
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the assumed alignment of a virtual base of a class.
end_comment

begin_function_decl
name|CharUnits
name|getVBaseAlignment
parameter_list|(
name|CharUnits
name|DerivedAlign
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|Derived
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Given a class pointer with an actual known alignment, and the
end_comment

begin_comment
comment|/// expected alignment of an object at a dynamic offset w.r.t that
end_comment

begin_comment
comment|/// pointer, return the alignment to assume at the offset.
end_comment

begin_function_decl
name|CharUnits
name|getDynamicOffsetAlignment
parameter_list|(
name|CharUnits
name|ActualAlign
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|CharUnits
name|ExpectedTargetAlign
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|CharUnits
name|computeNonVirtualBaseClassOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|DerivedClass
argument_list|,
name|CastExpr
operator|::
name|path_const_iterator
name|Start
argument_list|,
name|CastExpr
operator|::
name|path_const_iterator
name|End
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns the offset from a derived class to  a class. Returns null if the
end_comment

begin_comment
comment|/// offset is 0.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetNonVirtualBaseClassOffset
argument_list|(
argument|const CXXRecordDecl *ClassDecl
argument_list|,
argument|CastExpr::path_const_iterator PathBegin
argument_list|,
argument|CastExpr::path_const_iterator PathEnd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|FoldingSet
operator|<
name|BlockByrefHelpers
operator|>
name|ByrefHelpersCache
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Fetches the global unique block count.
end_comment

begin_function
name|int
name|getUniqueBlockCount
parameter_list|()
block|{
return|return
operator|++
name|Block
operator|.
name|GlobalUniqueCount
return|;
block|}
end_function

begin_comment
comment|/// Fetches the type of a generic block descriptor.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Type
operator|*
name|getBlockDescriptorType
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The type of a generic block literal.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Type
operator|*
name|getGenericBlockLiteralType
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Gets the address of a block which requires no captures.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobalBlock
argument_list|(
argument|const BlockExpr *BE
argument_list|,
argument|StringRef Name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns the address of a block which requires no caputres, or null if
end_comment

begin_comment
comment|/// we've yet to emit the block for BE.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getAddrOfGlobalBlockIfEmitted
argument_list|(
argument|const BlockExpr *BE
argument_list|)
block|{
return|return
name|EmittedGlobalBlocks
operator|.
name|lookup
argument_list|(
name|BE
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Notes that BE's global block is available via Addr. Asserts that BE
end_comment

begin_comment
comment|/// isn't already emitted.
end_comment

begin_decl_stmt
name|void
name|setAddrOfGlobalBlock
argument_list|(
specifier|const
name|BlockExpr
operator|*
name|BE
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a pointer to a constant CFString object for the given string.
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfConstantCFString
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|Literal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a pointer to a constant NSString object for the given string. Or a
end_comment

begin_comment
comment|/// user defined String object as defined via
end_comment

begin_comment
comment|/// -fconstant-string-class=class_name option.
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfConstantString
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|Literal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a constant array for the given string.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetConstantArrayFromStringLiteral
argument_list|(
specifier|const
name|StringLiteral
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return a pointer to a constant array for the given string literal.
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfConstantStringFromLiteral
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|S
parameter_list|,
name|StringRef
name|Name
init|=
literal|".str"
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return a pointer to a constant array for the given ObjCEncodeExpr node.
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfConstantStringFromObjCEncode
parameter_list|(
specifier|const
name|ObjCEncodeExpr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns a pointer to a character array containing the literal and a
end_comment

begin_comment
comment|/// terminating '\0' character. The result has pointer to array type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param GlobalName If provided, the name to use for the global (if one is
end_comment

begin_comment
comment|/// created).
end_comment

begin_decl_stmt
name|ConstantAddress
name|GetAddrOfConstantCString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|,
specifier|const
name|char
operator|*
name|GlobalName
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns a pointer to a constant global variable for the given file-scope
end_comment

begin_comment
comment|/// compound literal expression.
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfConstantCompoundLiteral
parameter_list|(
specifier|const
name|CompoundLiteralExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// If it's been emitted already, returns the GlobalVariable corresponding to
end_comment

begin_comment
comment|/// a compound literal. Otherwise, returns null.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|getAddrOfConstantCompoundLiteralIfEmitted
argument_list|(
specifier|const
name|CompoundLiteralExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Notes that CLE's GlobalVariable is GV. Asserts that CLE isn't already
end_comment

begin_comment
comment|/// emitted.
end_comment

begin_decl_stmt
name|void
name|setAddrOfConstantCompoundLiteral
argument_list|(
specifier|const
name|CompoundLiteralExpr
operator|*
name|CLE
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns a pointer to a global variable representing a temporary
end_comment

begin_comment
comment|/// with static or thread storage duration.
end_comment

begin_function_decl
name|ConstantAddress
name|GetAddrOfGlobalTemporary
parameter_list|(
specifier|const
name|MaterializeTemporaryExpr
modifier|*
name|E
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Inner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the record type that describes the state of an
end_comment

begin_comment
comment|/// Objective-C fast enumeration loop (for..in).
end_comment

begin_function_decl
name|QualType
name|getObjCFastEnumerationStateType
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Produce code for this constructor/destructor. This method doesn't try
end_comment

begin_comment
comment|// to apply any ABI rules about which other constructors/destructors
end_comment

begin_comment
comment|// are needed or if they are alias to each other.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|codegenCXXStructor
argument_list|(
argument|const CXXMethodDecl *MD
argument_list|,
argument|StructorType Type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the address of the constructor/destructor of the given type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getAddrOfCXXStructor
argument_list|(
argument|const CXXMethodDecl *MD
argument_list|,
argument|StructorType Type
argument_list|,
argument|const CGFunctionInfo *FnInfo = nullptr
argument_list|,
argument|llvm::FunctionType *FnType = nullptr
argument_list|,
argument|bool DontDefer = false
argument_list|,
argument|ForDefinition_t IsForDefinition = NotForDefinition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Given a builtin id for a function like "__builtin_fabsf", return a
end_comment

begin_comment
comment|/// Function* for "fabsf".
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getBuiltinLibFunction
argument_list|(
argument|const FunctionDecl *FD
argument_list|,
argument|unsigned BuiltinID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|getIntrinsic
argument_list|(
argument|unsigned IID
argument_list|,
argument|ArrayRef<llvm::Type*> Tys = None
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit code for a single top level declaration.
end_comment

begin_function_decl
name|void
name|EmitTopLevelDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Stored a deferred empty coverage mapping for an unused
end_comment

begin_comment
comment|/// and thus uninstrumented top level declaration.
end_comment

begin_function_decl
name|void
name|AddDeferredUnusedCoverageMapping
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Remove the deferred empty coverage mapping as this
end_comment

begin_comment
comment|/// declaration is actually instrumented.
end_comment

begin_function_decl
name|void
name|ClearUnusedCoverageMapping
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit all the deferred coverage mappings
end_comment

begin_comment
comment|/// for the uninstrumented functions.
end_comment

begin_function_decl
name|void
name|EmitDeferredUnusedCoverageMappings
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Tell the consumer that this variable has been instantiated.
end_comment

begin_function_decl
name|void
name|HandleCXXStaticMemberVarInstantiation
parameter_list|(
name|VarDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the declaration has internal linkage but is inside an
end_comment

begin_comment
comment|/// extern "C" linkage specification, prepare to emit an alias for it
end_comment

begin_comment
comment|/// to the expected name.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SomeDecl
operator|>
name|void
name|MaybeHandleStaticInExternC
argument_list|(
specifier|const
name|SomeDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Add a global to a list to be added to the llvm.used metadata.
end_comment

begin_decl_stmt
name|void
name|addUsedGlobal
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Add a global to a list to be added to the llvm.compiler.used metadata.
end_comment

begin_decl_stmt
name|void
name|addCompilerUsedGlobal
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Add a destructor and object to add to the C++ global destructor function.
end_comment

begin_decl_stmt
name|void
name|AddCXXDtorEntry
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|DtorFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Object
argument_list|)
block|{
name|CXXGlobalDtors
operator|.
name|emplace_back
argument_list|(
name|DtorFn
argument_list|,
name|Object
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Create a new runtime function with the specified type and name.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|CreateRuntimeFunction
argument_list|(
argument|llvm::FunctionType *Ty
argument_list|,
argument|StringRef Name
argument_list|,
argument|llvm::AttributeList ExtraAttrs = llvm::AttributeList()
argument_list|,
argument|bool Local = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create a new compiler builtin function with the specified type and name.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|CreateBuiltinFunction
argument_list|(
argument|llvm::FunctionType *Ty
argument_list|,
argument|StringRef Name
argument_list|,
argument|llvm::AttributeList ExtraAttrs = llvm::AttributeList()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create a new runtime global variable with the specified type and name.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|CreateRuntimeVariable
argument_list|(
argument|llvm::Type *Ty
argument_list|,
argument|StringRef Name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|///@name Custom Blocks Runtime Interfaces
end_comment

begin_comment
comment|///@{
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getNSConcreteGlobalBlock
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getNSConcreteStackBlock
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getBlockObjectAssign
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getBlockObjectDispose
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|///@}
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getLLVMLifetimeStartFn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getLLVMLifetimeEndFn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Make sure that this type is translated.
end_comment

begin_function_decl
name|void
name|UpdateCompletedType
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getMemberPointerConstant
argument_list|(
specifier|const
name|UnaryOperator
operator|*
name|e
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Try to emit the initializer for the given declaration as a constant;
end_comment

begin_comment
comment|/// returns 0 if the expression cannot be emitted as a constant.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitConstantInit
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|CodeGenFunction
operator|*
name|CGF
operator|=
name|nullptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Try to emit the given expression as a constant; returns 0 if the
end_comment

begin_comment
comment|/// expression cannot be emitted as a constant.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitConstantExpr
argument_list|(
argument|const Expr *E
argument_list|,
argument|QualType DestType
argument_list|,
argument|CodeGenFunction *CGF = nullptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit the given constant value as a constant, in the type's scalar
end_comment

begin_comment
comment|/// representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitConstantValue
argument_list|(
argument|const APValue&Value
argument_list|,
argument|QualType DestType
argument_list|,
argument|CodeGenFunction *CGF = nullptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit the given constant value as a constant, in the type's memory
end_comment

begin_comment
comment|/// representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitConstantValueForMemory
argument_list|(
argument|const APValue&Value
argument_list|,
argument|QualType DestType
argument_list|,
argument|CodeGenFunction *CGF = nullptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Emit type info if type of an expression is a variably modified
end_comment

begin_comment
comment|/// type. Also emit proper debug info for cast types.
end_comment

begin_function_decl
name|void
name|EmitExplicitCastExprType
parameter_list|(
specifier|const
name|ExplicitCastExpr
modifier|*
name|E
parameter_list|,
name|CodeGenFunction
modifier|*
name|CGF
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return the result of value-initializing the given type, i.e. a null
end_comment

begin_comment
comment|/// expression of the given type.  This is usually, but not always, an LLVM
end_comment

begin_comment
comment|/// null constant.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitNullConstant
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return a null constant appropriate for zero-initializing a base class with
end_comment

begin_comment
comment|/// the given type. This is usually, but not always, an LLVM null constant.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitNullConstantForBase
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Record
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit a general error that something can't be done.
end_comment

begin_function_decl
name|void
name|Error
parameter_list|(
name|SourceLocation
name|loc
parameter_list|,
name|StringRef
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Print out an error that codegen doesn't support the specified stmt yet.
end_comment

begin_function_decl
name|void
name|ErrorUnsupported
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
specifier|const
name|char
modifier|*
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Print out an error that codegen doesn't support the specified decl yet.
end_comment

begin_function_decl
name|void
name|ErrorUnsupported
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
specifier|const
name|char
modifier|*
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set the attributes on the LLVM function for the given decl and function
end_comment

begin_comment
comment|/// info. This applies attributes necessary for handling the ABI as well as
end_comment

begin_comment
comment|/// user specified attributes like section.
end_comment

begin_decl_stmt
name|void
name|SetInternalFunctionAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|FI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set the LLVM function attributes (sext, zext, etc).
end_comment

begin_decl_stmt
name|void
name|SetLLVMFunctionAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|Info
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set the LLVM function attributes which only apply to a function
end_comment

begin_comment
comment|/// definition.
end_comment

begin_decl_stmt
name|void
name|SetLLVMFunctionAttributesForDefinition
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return true iff the given type uses 'sret' when used as a return type.
end_comment

begin_function_decl
name|bool
name|ReturnTypeUsesSRet
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return true iff the given type uses an argument slot when 'sret' is used
end_comment

begin_comment
comment|/// as a return type.
end_comment

begin_function_decl
name|bool
name|ReturnSlotInterferesWithArgs
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return true iff the given type uses 'fpret' when used as a return type.
end_comment

begin_function_decl
name|bool
name|ReturnTypeUsesFPRet
parameter_list|(
name|QualType
name|ResultType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return true iff the given type uses 'fp2ret' when used as a return type.
end_comment

begin_function_decl
name|bool
name|ReturnTypeUsesFP2Ret
parameter_list|(
name|QualType
name|ResultType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the LLVM attributes and calling convention to use for a particular
end_comment

begin_comment
comment|/// function type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name - The function name.
end_comment

begin_comment
comment|/// \param Info - The function type information.
end_comment

begin_comment
comment|/// \param CalleeInfo - The callee information these attributes are being
end_comment

begin_comment
comment|/// constructed for. If valid, the attributes applied to this decl may
end_comment

begin_comment
comment|/// contribute to the function attributes and calling convention.
end_comment

begin_comment
comment|/// \param Attrs [out] - On return, the attribute list to use.
end_comment

begin_comment
comment|/// \param CallingConv [out] - On return, the LLVM calling convention to use.
end_comment

begin_decl_stmt
name|void
name|ConstructAttributeList
argument_list|(
name|StringRef
name|Name
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|Info
argument_list|,
name|CGCalleeInfo
name|CalleeInfo
argument_list|,
name|llvm
operator|::
name|AttributeList
operator|&
name|Attrs
argument_list|,
name|unsigned
operator|&
name|CallingConv
argument_list|,
name|bool
name|AttrOnCallSite
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Adds attributes to F according to our CodeGenOptions and LangOptions, as
end_comment

begin_comment
comment|/// though we had emitted it ourselves.  We remove any attributes on F that
end_comment

begin_comment
comment|/// conflict with the attributes we add here.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful for adding attrs to bitcode modules that you want to link
end_comment

begin_comment
comment|/// with but don't control, such as CUDA's libdevice.  When linking with such
end_comment

begin_comment
comment|/// a bitcode library, you might want to set e.g. its functions'
end_comment

begin_comment
comment|/// "unsafe-fp-math" attribute to match the attr of the functions you're
end_comment

begin_comment
comment|/// codegen'ing.  Otherwise, LLVM will interpret the bitcode module's lack of
end_comment

begin_comment
comment|/// unsafe-fp-math attrs as tantamount to unsafe-fp-math=false, and then LLVM
end_comment

begin_comment
comment|/// will propagate unsafe-fp-math=false up to every transitive caller of a
end_comment

begin_comment
comment|/// function in the bitcode library!
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// With the exception of fast-math attrs, this will only make the attributes
end_comment

begin_comment
comment|/// on the function more conservative.  But it's unsafe to call this on a
end_comment

begin_comment
comment|/// function which relies on particular fast-math attributes for correctness.
end_comment

begin_comment
comment|/// It's up to you to ensure that this is safe.
end_comment

begin_decl_stmt
name|void
name|AddDefaultFnAttrs
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|F
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Fills in the supplied string map with the set of target features for the
end_comment

begin_comment
comment|// passed in function.
end_comment

begin_decl_stmt
name|void
name|getFunctionFeatureMap
argument_list|(
name|llvm
operator|::
name|StringMap
operator|<
name|bool
operator|>
operator|&
name|FeatureMap
argument_list|,
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|StringRef
name|getMangledName
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StringRef
name|getBlockMangledName
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
specifier|const
name|BlockDecl
modifier|*
name|BD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitTentativeDefinition
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitVTable
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RefreshTypeCacheForClass
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Appends Opts to the "Linker Options" metadata value.
end_comment

begin_function_decl
name|void
name|AppendLinkerOptions
parameter_list|(
name|StringRef
name|Opts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Appends a detect mismatch command to the linker options.
end_comment

begin_function_decl
name|void
name|AddDetectMismatch
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Appends a dependent lib to the "Linker Options" metadata value.
end_comment

begin_function_decl
name|void
name|AddDependentLib
parameter_list|(
name|StringRef
name|Lib
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|::
name|LinkageTypes
name|getFunctionLinkage
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|setFunctionLinkage
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
block|{
name|F
operator|->
name|setLinkage
argument_list|(
name|getFunctionLinkage
argument_list|(
name|GD
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Set the DLL storage class on F.
end_comment

begin_decl_stmt
name|void
name|setFunctionDLLStorageClass
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the appropriate linkage for the vtable, VTT, and type information
end_comment

begin_comment
comment|/// of the given class.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|::
name|LinkageTypes
name|getVTableLinkage
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the store size, in character units, of the given LLVM type.
end_comment

begin_decl_stmt
name|CharUnits
name|GetTargetTypeStoreSize
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns LLVM linkage for a declarator.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|getLLVMLinkageForDeclarator
argument_list|(
argument|const DeclaratorDecl *D
argument_list|,
argument|GVALinkage Linkage
argument_list|,
argument|bool IsConstantVariable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns LLVM linkage for a declarator.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|getLLVMLinkageVarDefinition
argument_list|(
argument|const VarDecl *VD
argument_list|,
argument|bool IsConstant
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit all the global annotations.
end_comment

begin_function_decl
name|void
name|EmitGlobalAnnotations
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit an annotation string.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitAnnotationString
argument_list|(
argument|StringRef Str
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit the annotation's translation unit.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitAnnotationUnit
argument_list|(
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit the annotation line number.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitAnnotationLineNo
argument_list|(
argument|SourceLocation L
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Generate the llvm::ConstantStruct which contains the annotation
end_comment

begin_comment
comment|/// information for a given GlobalValue. The annotation struct is
end_comment

begin_comment
comment|/// {i8 *, i8 *, i8 *, i32}. The first field is a constant expression, the
end_comment

begin_comment
comment|/// GlobalValue being annotated. The second field is the constant string
end_comment

begin_comment
comment|/// created from the AnnotateAttr's annotation. The third field is a constant
end_comment

begin_comment
comment|/// string containing the name of the translation unit. The fourth field is
end_comment

begin_comment
comment|/// the line number in the file of the annotated value declaration.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitAnnotateAttr
argument_list|(
argument|llvm::GlobalValue *GV
argument_list|,
argument|const AnnotateAttr *AA
argument_list|,
argument|SourceLocation L
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Add global annotations that are set on D, for the global GV. Those
end_comment

begin_comment
comment|/// annotations are emitted during finalization of the LLVM code.
end_comment

begin_decl_stmt
name|void
name|AddGlobalAnnotations
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isInSanitizerBlacklist
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isInSanitizerBlacklist
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|QualType
name|Ty
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Imbue XRay attributes to a function, applying the always/never attribute
end_comment

begin_comment
comment|/// lists in the process. Returns true if we did imbue attributes this way,
end_comment

begin_comment
comment|/// false otherwise.
end_comment

begin_decl_stmt
name|bool
name|imbueXRayAttrs
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function
name|SanitizerMetadata
modifier|*
name|getSanitizerMetadata
parameter_list|()
block|{
return|return
name|SanitizerMD
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|addDeferredVTable
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
block|{
name|DeferredVTables
operator|.
name|push_back
argument_list|(
name|RD
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Emit code for a singal global function or var decl. Forward declarations
end_comment

begin_comment
comment|/// are emitted lazily.
end_comment

begin_function_decl
name|void
name|EmitGlobal
parameter_list|(
name|GlobalDecl
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|TryEmitDefinitionAsAlias
parameter_list|(
name|GlobalDecl
name|Alias
parameter_list|,
name|GlobalDecl
name|Target
parameter_list|,
name|bool
name|InEveryTU
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|TryEmitBaseDestructorAsAlias
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set attributes for a global definition.
end_comment

begin_decl_stmt
name|void
name|setFunctionDefinitionAttributes
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|GlobalValue
operator|*
name|GetGlobalValue
argument_list|(
argument|StringRef Ref
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Set attributes which are common to any form of a global definition (alias,
end_comment

begin_comment
comment|/// Objective-C method, function, global variable).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: This should only be called for definitions.
end_comment

begin_decl_stmt
name|void
name|SetCommonAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set attributes which must be preserved by an alias. This includes common
end_comment

begin_comment
comment|/// attributes (i.e. it includes a call to SetCommonAttributes).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: This should only be called for definitions.
end_comment

begin_decl_stmt
name|void
name|setAliasAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addReplacement
argument_list|(
name|StringRef
name|Name
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addGlobalValReplacement
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit a code for threadprivate directive.
end_comment

begin_comment
comment|/// \param D Threadprivate declaration.
end_comment

begin_function_decl
name|void
name|EmitOMPThreadPrivateDecl
parameter_list|(
specifier|const
name|OMPThreadPrivateDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit a code for declare reduction construct.
end_comment

begin_function_decl
name|void
name|EmitOMPDeclareReduction
parameter_list|(
specifier|const
name|OMPDeclareReductionDecl
modifier|*
name|D
parameter_list|,
name|CodeGenFunction
modifier|*
name|CGF
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns whether the given record has hidden LTO visibility and therefore
end_comment

begin_comment
comment|/// may participate in (single-module) CFI and whole-program vtable
end_comment

begin_comment
comment|/// optimization.
end_comment

begin_function_decl
name|bool
name|HasHiddenLTOVisibility
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit type metadata for the given vtable using the given layout.
end_comment

begin_decl_stmt
name|void
name|EmitVTableTypeMetadata
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|VTable
argument_list|,
specifier|const
name|VTableLayout
operator|&
name|VTLayout
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Generate a cross-DSO type identifier for MD.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|ConstantInt
operator|*
name|CreateCrossDsoCfiTypeId
argument_list|(
name|llvm
operator|::
name|Metadata
operator|*
name|MD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create a metadata identifier for the given type. This may either be an
end_comment

begin_comment
comment|/// MDString (for external identifiers) or a distinct unnamed MDNode (for
end_comment

begin_comment
comment|/// internal identifiers).
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Metadata
operator|*
name|CreateMetadataIdentifierForType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create and attach type metadata to the given function.
end_comment

begin_decl_stmt
name|void
name|CreateFunctionTypeMetadata
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns whether this module needs the "all-vtables" type identifier.
end_comment

begin_expr_stmt
name|bool
name|NeedAllVtablesTypeId
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create and attach type metadata for the given vtable.
end_comment

begin_decl_stmt
name|void
name|AddVTableTypeMetadata
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|VTable
argument_list|,
name|CharUnits
name|Offset
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the declaration of std::terminate for the platform.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getTerminateFn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|SanitizerStatReport
operator|&
name|getSanStats
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|createOpenCLIntToSamplerConversion
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get target specific null pointer.
end_comment

begin_comment
comment|/// \param T is the LLVM type of the null pointer.
end_comment

begin_comment
comment|/// \param QT is the clang QualType of the null pointer.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getNullPointer
argument_list|(
argument|llvm::PointerType *T
argument_list|,
argument|QualType QT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetOrCreateLLVMFunction
argument_list|(
argument|StringRef MangledName
argument_list|,
argument|llvm::Type *Ty
argument_list|,
argument|GlobalDecl D
argument_list|,
argument|bool ForVTable
argument_list|,
argument|bool DontDefer = false
argument_list|,
argument|bool IsThunk = false
argument_list|,
argument|llvm::AttributeList ExtraAttrs = llvm::AttributeList()
argument_list|,
argument|ForDefinition_t IsForDefinition = NotForDefinition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetOrCreateLLVMGlobal
argument_list|(
argument|StringRef MangledName
argument_list|,
argument|llvm::PointerType *PTy
argument_list|,
argument|const VarDecl *D
argument_list|,
argument|ForDefinition_t IsForDefinition                                           = NotForDefinition
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|setNonAliasAttributes
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalObject
operator|*
name|GO
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set function attributes for a function declaration.
end_comment

begin_decl_stmt
name|void
name|SetFunctionAttributes
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|,
name|bool
name|IsIncompleteFunction
argument_list|,
name|bool
name|IsThunk
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitGlobalDefinition
argument_list|(
name|GlobalDecl
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitGlobalFunctionDefinition
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitGlobalVarDefinition
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|,
name|bool
name|IsTentative
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAliasDefinition
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emitIFuncDefinition
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCPropertyImplementations
parameter_list|(
specifier|const
name|ObjCImplementationDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCIvarInitializations
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// C++ related functions.
end_comment

begin_function_decl
name|void
name|EmitDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitLinkageSpec
parameter_list|(
specifier|const
name|LinkageSpecDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the function that initializes C++ thread_local variables.
end_comment

begin_function_decl
name|void
name|EmitCXXThreadLocalInitFunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the function that initializes C++ globals.
end_comment

begin_function_decl
name|void
name|EmitCXXGlobalInitFunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the function that destroys C++ globals.
end_comment

begin_function_decl
name|void
name|EmitCXXGlobalDtorFunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the function that initializes the specified global (if PerformInit is
end_comment

begin_comment
comment|/// true) and registers its destructor.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGlobalVarDeclInitFunc
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|Addr
argument_list|,
name|bool
name|PerformInit
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitPointerToInitFunc
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|Addr
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|InitFunc
argument_list|,
name|InitSegAttr
operator|*
name|ISA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: Hardcoding priority here is gross.
end_comment

begin_decl_stmt
name|void
name|AddGlobalCtor
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Ctor
argument_list|,
name|int
name|Priority
operator|=
literal|65535
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|AssociatedData
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddGlobalDtor
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Dtor
argument_list|,
name|int
name|Priority
operator|=
literal|65535
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitCtorList - Generates a global array of functions and priorities using
end_comment

begin_comment
comment|/// the given list and name. This array will have appending linkage and is
end_comment

begin_comment
comment|/// suitable for use as a LLVM constructor or destructor array. Clears Fns.
end_comment

begin_function_decl
name|void
name|EmitCtorList
parameter_list|(
name|CtorList
modifier|&
name|Fns
parameter_list|,
specifier|const
name|char
modifier|*
name|GlobalName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit any needed decls for which code generation was deferred.
end_comment

begin_function_decl
name|void
name|EmitDeferred
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Call replaceAllUsesWith on all pairs in Replacements.
end_comment

begin_function_decl
name|void
name|applyReplacements
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Call replaceAllUsesWith on all pairs in GlobalValReplacements.
end_comment

begin_function_decl
name|void
name|applyGlobalValReplacements
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkAliases
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit any vtables which we deferred and still have a use for.
end_comment

begin_function_decl
name|void
name|EmitDeferredVTables
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a dummy function that reference a CoreFoundation symbol when
end_comment

begin_comment
comment|/// @available is used on Darwin.
end_comment

begin_function_decl
name|void
name|emitAtAvailableLinkGuard
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the llvm.used and llvm.compiler.used metadata.
end_comment

begin_function_decl
name|void
name|emitLLVMUsed
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the link options introduced by imported modules.
end_comment

begin_function_decl
name|void
name|EmitModuleLinkOptions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit aliases for internal-linkage declarations inside "C" language
end_comment

begin_comment
comment|/// linkage specifications, giving them the "expected" name where possible.
end_comment

begin_function_decl
name|void
name|EmitStaticExternCAliases
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDeclMetadata
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the Clang version as llvm.ident metadata.
end_comment

begin_function_decl
name|void
name|EmitVersionIdentMetadata
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emits target specific Metadata for global declarations.
end_comment

begin_function_decl
name|void
name|EmitTargetMetadata
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit the llvm.gcov metadata used to tell LLVM where to emit the .gcno and
end_comment

begin_comment
comment|/// .gcda files in a way that persists in .bc files.
end_comment

begin_function_decl
name|void
name|EmitCoverageFile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emits the initializer for a uuidof string.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitUuidofInitializer
argument_list|(
argument|StringRef uuidstr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Determine whether the definition must be emitted; if this returns \c
end_comment

begin_comment
comment|/// false, the definition can be emitted lazily if it's used.
end_comment

begin_function_decl
name|bool
name|MustBeEmitted
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine whether the definition can be emitted eagerly, or should be
end_comment

begin_comment
comment|/// delayed until the end of the translation unit. This is relevant for
end_comment

begin_comment
comment|/// definitions whose linkage can change, e.g. implicit function instantions
end_comment

begin_comment
comment|/// which may later be explicitly instantiated.
end_comment

begin_function_decl
name|bool
name|MayBeEmittedEagerly
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check whether we can use a "simpler", more core exceptions personality
end_comment

begin_comment
comment|/// function.
end_comment

begin_function_decl
name|void
name|SimplifyPersonality
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Helper function for ConstructAttributeList and AddDefaultFnAttrs.
end_comment

begin_comment
comment|/// Constructs an AttrList for a function with the given properties.
end_comment

begin_decl_stmt
name|void
name|ConstructDefaultFnAttrList
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
name|HasOptnone
argument_list|,
name|bool
name|AttrOnCallSite
argument_list|,
name|llvm
operator|::
name|AttrBuilder
operator|&
name|FuncAttrs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}; }
comment|// end namespace CodeGen
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LIB_CODEGEN_CODEGENMODULE_H
end_comment

end_unit

