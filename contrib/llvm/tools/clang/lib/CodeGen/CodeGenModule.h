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
name|CLANG_CODEGEN_CODEGENMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CODEGENMODULE_H
end_define

begin_include
include|#
directive|include
file|"CGVTables.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenTypes.h"
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
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/SpecialCaseList.h"
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
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|TargetCodeGenInfo
decl_stmt|;
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
name|DiagnosticsEngine
decl_stmt|;
name|class
name|AnnotateAttr
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|MangleBuffer
decl_stmt|;
name|class
name|Module
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
name|CGCUDARuntime
decl_stmt|;
name|class
name|BlockFieldFlags
decl_stmt|;
name|class
name|FunctionArgList
decl_stmt|;
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
if|if
condition|(
name|priority
operator|<
name|RHS
operator|.
name|priority
condition|)
return|return
name|true
return|;
return|return
name|priority
operator|==
name|RHS
operator|.
name|priority
operator|&&
name|lex_order
operator|<
name|RHS
operator|.
name|lex_order
return|;
block|}
block|}
empty_stmt|;
struct|struct
name|CodeGenTypeCache
block|{
comment|/// void
name|llvm
operator|::
name|Type
operator|*
name|VoidTy
expr_stmt|;
comment|/// i8, i16, i32, and i64
name|llvm
operator|::
name|IntegerType
operator|*
name|Int8Ty
operator|,
operator|*
name|Int16Ty
operator|,
operator|*
name|Int32Ty
operator|,
operator|*
name|Int64Ty
expr_stmt|;
comment|/// float, double
name|llvm
operator|::
name|Type
operator|*
name|FloatTy
operator|,
operator|*
name|DoubleTy
expr_stmt|;
comment|/// int
name|llvm
operator|::
name|IntegerType
operator|*
name|IntTy
expr_stmt|;
comment|/// intptr_t, size_t, and ptrdiff_t, which we assume are the same size.
union|union
block|{
name|llvm
operator|::
name|IntegerType
operator|*
name|IntPtrTy
expr_stmt|;
name|llvm
operator|::
name|IntegerType
operator|*
name|SizeTy
expr_stmt|;
name|llvm
operator|::
name|IntegerType
operator|*
name|PtrDiffTy
expr_stmt|;
block|}
union|;
comment|/// void* in address space 0
union|union
block|{
name|llvm
operator|::
name|PointerType
operator|*
name|VoidPtrTy
expr_stmt|;
name|llvm
operator|::
name|PointerType
operator|*
name|Int8PtrTy
expr_stmt|;
block|}
union|;
comment|/// void** in address space 0
union|union
block|{
name|llvm
operator|::
name|PointerType
operator|*
name|VoidPtrPtrTy
expr_stmt|;
name|llvm
operator|::
name|PointerType
operator|*
name|Int8PtrPtrTy
expr_stmt|;
block|}
union|;
comment|/// The width of a pointer into the generic address space.
name|unsigned
name|char
name|PointerWidthInBits
decl_stmt|;
comment|/// The size and alignment of a pointer into the generic address
comment|/// space.
union|union
block|{
name|unsigned
name|char
name|PointerAlignInBytes
decl_stmt|;
name|unsigned
name|char
name|PointerSizeInBytes
decl_stmt|;
name|unsigned
name|char
name|SizeSizeInBytes
decl_stmt|;
comment|// sizeof(size_t)
block|}
union|;
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|RuntimeCC
expr_stmt|;
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|getRuntimeCC
argument_list|()
specifier|const
block|{
return|return
name|RuntimeCC
return|;
block|}
block|}
struct|;
struct|struct
name|RREntrypoints
block|{
name|RREntrypoints
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
block|}
struct|;
struct|struct
name|ARCEntrypoints
block|{
name|ARCEntrypoints
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
comment|/// id objc_storeStrong(id*, id);
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
comment|/// CodeGenModule - This class organizes the cross-function state that is used
comment|/// while generating LLVM code.
name|class
name|CodeGenModule
range|:
name|public
name|CodeGenTypeCache
block|{
name|CodeGenModule
argument_list|(
argument|const CodeGenModule&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenModule
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
typedef|typedef
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
name|Constant
operator|*
operator|,
name|int
operator|>
expr|>
name|CtorList
expr_stmt|;
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
name|llvm
operator|::
name|DataLayout
operator|&
name|TheDataLayout
expr_stmt|;
specifier|const
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|CGCXXABI
modifier|&
name|ABI
decl_stmt|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|VMContext
expr_stmt|;
name|CodeGenTBAA
modifier|*
name|TBAA
decl_stmt|;
name|mutable
specifier|const
name|TargetCodeGenInfo
modifier|*
name|TheTargetCodeGenInfo
decl_stmt|;
comment|// This should not be moved earlier, since its initialization depends on some
comment|// of the previous reference members being already initialized and also checks
comment|// if TheTargetCodeGenInfo is NULL
name|CodeGenTypes
name|Types
decl_stmt|;
comment|/// VTables - Holds information about C++ vtables.
name|CodeGenVTables
name|VTables
decl_stmt|;
name|CGObjCRuntime
modifier|*
name|ObjCRuntime
decl_stmt|;
name|CGOpenCLRuntime
modifier|*
name|OpenCLRuntime
decl_stmt|;
name|CGCUDARuntime
modifier|*
name|CUDARuntime
decl_stmt|;
name|CGDebugInfo
modifier|*
name|DebugInfo
decl_stmt|;
name|ARCEntrypoints
modifier|*
name|ARCData
decl_stmt|;
name|llvm
operator|::
name|MDNode
operator|*
name|NoObjCARCExceptionsMetadata
expr_stmt|;
name|RREntrypoints
modifier|*
name|RRData
decl_stmt|;
comment|// WeakRefReferences - A set of references that have only been seen via
comment|// a weakref so far. This is used to remove the weak of the reference if we
comment|// ever see a direct reference or a definition.
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
comment|/// DeferredDecls - This contains all the decls which have definitions but
comment|/// which are deferred for emission and therefore should only be output if
comment|/// they are actually used.  If a decl is in this, then it is known to have
comment|/// not been referenced yet.
name|llvm
operator|::
name|StringMap
operator|<
name|GlobalDecl
operator|>
name|DeferredDecls
expr_stmt|;
comment|/// DeferredDeclsToEmit - This is a list of deferred decls which we have seen
comment|/// that *are* actually referenced.  These get code generated when the module
comment|/// is done.
name|std
operator|::
name|vector
operator|<
name|GlobalDecl
operator|>
name|DeferredDeclsToEmit
expr_stmt|;
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
comment|/// DeferredVTables - A queue of (optional) vtables to consider emitting.
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
comment|/// LLVMUsed - List of global values which are required to be
comment|/// present in the object file; bitcast to i8*. This is used for
comment|/// forcing visibility of symbols which may otherwise be optimized
comment|/// out.
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
comment|/// GlobalCtors - Store the list of global constructors and their respective
comment|/// priorities to be emitted when the translation unit is complete.
name|CtorList
name|GlobalCtors
decl_stmt|;
comment|/// GlobalDtors - Store the list of global destructors and their respective
comment|/// priorities to be emitted when the translation unit is complete.
name|CtorList
name|GlobalDtors
decl_stmt|;
comment|/// MangledDeclNames - A map of canonical GlobalDecls to their mangled names.
name|llvm
operator|::
name|DenseMap
operator|<
name|GlobalDecl
operator|,
name|StringRef
operator|>
name|MangledDeclNames
expr_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|MangledNamesAllocator
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
name|Constant
operator|*
operator|>
name|CFConstantStringMap
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
name|std
operator|::
name|pair
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|llvm
operator|::
name|GlobalVariable
operator|*
operator|>
expr|>
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
name|Constant
operator|*
operator|>
name|CXXThreadLocalInits
expr_stmt|;
comment|/// CXXGlobalInits - Global variables with initializers that need to run
comment|/// before main.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|CXXGlobalInits
expr_stmt|;
comment|/// When a C++ decl with an initializer is deferred, null is
comment|/// appended to CXXGlobalInits, and the index of that null is placed
comment|/// here so that the initializer will be performed in the correct
comment|/// order.
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
comment|/// - Global variables with initializers whose order of initialization
comment|/// is set by init_priority attribute.
name|SmallVector
operator|<
name|GlobalInitData
operator|,
literal|8
operator|>
name|PrioritizedCXXGlobalInits
expr_stmt|;
comment|/// CXXGlobalDtors - Global destructor functions and arguments that need to
comment|/// run on termination.
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
comment|/// \brief A vector of metadata strings.
name|SmallVector
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|16
operator|>
name|LinkerOptionsMetadata
expr_stmt|;
comment|/// @name Cache for Objective-C runtime types
comment|/// @{
comment|/// CFConstantStringClassRef - Cached reference to the class for constant
comment|/// strings. This value has type int * but is actually an Obj-C class pointer.
name|llvm
operator|::
name|WeakVH
name|CFConstantStringClassRef
expr_stmt|;
comment|/// ConstantStringClassRef - Cached reference to the class for constant
comment|/// strings. This value has type int * but is actually an Obj-C class pointer.
name|llvm
operator|::
name|WeakVH
name|ConstantStringClassRef
expr_stmt|;
comment|/// \brief The LLVM type corresponding to NSConstantString.
name|llvm
operator|::
name|StructType
operator|*
name|NSConstantStringType
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
comment|/// @name Cache for Blocks Runtime Globals
comment|/// @{
name|llvm
operator|::
name|Constant
operator|*
name|NSConcreteGlobalBlock
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|NSConcreteStackBlock
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|BlockObjectAssign
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|BlockObjectDispose
expr_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|BlockDescriptorType
expr_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|GenericBlockLiteralType
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
expr_stmt|;
comment|/// void @llvm.lifetime.end(i64 %size, i8* nocapture<ptr>)
name|llvm
operator|::
name|Constant
operator|*
name|LifetimeEndFn
expr_stmt|;
name|GlobalDecl
name|initializedGlobalDecl
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|SpecialCaseList
operator|>
name|SanitizerBlacklist
expr_stmt|;
specifier|const
name|SanitizerOptions
modifier|&
name|SanOpts
decl_stmt|;
comment|/// @}
name|public
label|:
name|CodeGenModule
argument_list|(
name|ASTContext
operator|&
name|C
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
specifier|const
name|llvm
operator|::
name|DataLayout
operator|&
name|TD
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
expr_stmt|;
operator|~
name|CodeGenModule
argument_list|()
expr_stmt|;
comment|/// Release - Finalize LLVM code generation.
name|void
name|Release
parameter_list|()
function_decl|;
comment|/// getObjCRuntime() - Return a reference to the configured
comment|/// Objective-C runtime.
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
comment|/// hasObjCRuntime() - Return true iff an Objective-C runtime has
comment|/// been configured.
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
comment|/// getOpenCLRuntime() - Return a reference to the configured OpenCL runtime.
name|CGOpenCLRuntime
modifier|&
name|getOpenCLRuntime
parameter_list|()
block|{
name|assert
argument_list|(
name|OpenCLRuntime
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
operator|*
name|OpenCLRuntime
return|;
block|}
comment|/// getCUDARuntime() - Return a reference to the configured CUDA runtime.
name|CGCUDARuntime
modifier|&
name|getCUDARuntime
parameter_list|()
block|{
name|assert
argument_list|(
name|CUDARuntime
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
operator|*
name|CUDARuntime
return|;
block|}
name|ARCEntrypoints
operator|&
name|getARCEntrypoints
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getLangOpts
argument_list|()
operator|.
name|ObjCAutoRefCount
operator|&&
name|ARCData
operator|!=
literal|0
argument_list|)
block|;
return|return
operator|*
name|ARCData
return|;
block|}
name|RREntrypoints
operator|&
name|getRREntrypoints
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RRData
operator|!=
literal|0
argument_list|)
block|;
return|return
operator|*
name|RRData
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
name|getTypeDescriptor
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
name|setTypeDescriptor
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
name|SmallVector
operator|<
name|llvm
operator|::
name|Value
operator|*
argument_list|,
literal|1
operator|>
operator|(
operator|)
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
name|TheDataLayout
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

begin_function
name|CGCXXABI
modifier|&
name|getCXXABI
parameter_list|()
block|{
return|return
name|ABI
return|;
block|}
end_function

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
literal|0
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
comment|/// Return the MDNode in the type DAG for the given struct type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|getTBAAStructTypeInfo
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
name|DecorateInstruction
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
comment|/// getSize - Emit the given number of characters as a value of type size_t.
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
comment|/// setGlobalVisibility - Set the visibility for the given LLVM
end_comment

begin_comment
comment|/// GlobalValue.
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
comment|/// setTLSMode - Set the TLS mode for the given LLVM GlobalVariable
end_comment

begin_comment
comment|/// for the thread-local variable declaration D.
end_comment

begin_decl_stmt
name|void
name|setTLSMode
argument_list|(
name|llvm
operator|::
name|GlobalVariable
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

begin_comment
comment|/// TypeVisibilityKind - The kind of global variable that is passed to
end_comment

begin_comment
comment|/// setTypeVisibility
end_comment

begin_enum
enum|enum
name|TypeVisibilityKind
block|{
name|TVK_ForVTT
block|,
name|TVK_ForVTable
block|,
name|TVK_ForConstructionVTable
block|,
name|TVK_ForRTTI
block|,
name|TVK_ForRTTIName
block|}
enum|;
end_enum

begin_comment
comment|/// setTypeVisibility - Set the visibility for the given global
end_comment

begin_comment
comment|/// value which holds information about a type.
end_comment

begin_decl_stmt
name|void
name|setTypeVisibility
argument_list|(
name|llvm
operator|::
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|D
argument_list|,
name|TypeVisibilityKind
name|TVK
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
argument_list|)
block|{
if|if
condition|(
name|isa
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
condition|)
return|return
name|GetAddrOfCXXConstructor
argument_list|(
name|cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
argument_list|,
name|GD
operator|.
name|getCtorType
argument_list|()
argument_list|)
return|;
elseif|else
if|if
condition|(
name|isa
operator|<
name|CXXDestructorDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
condition|)
return|return
name|GetAddrOfCXXDestructor
argument_list|(
name|cast
operator|<
name|CXXDestructorDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
argument_list|,
name|GD
operator|.
name|getDtorType
argument_list|()
argument_list|)
return|;
elseif|else
if|if
condition|(
name|isa
operator|<
name|FunctionDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
condition|)
return|return
name|GetAddrOfFunction
argument_list|(
name|GD
argument_list|)
return|;
else|else
return|return
name|GetAddrOfGlobalVar
argument_list|(
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// CreateOrReplaceCXXRuntimeVariable - Will return a global variable of the
end_comment

begin_comment
comment|/// given type. If a variable with a different type already exists then a new
end_comment

begin_comment
comment|/// variable with the right type will be created and all uses of the old
end_comment

begin_comment
comment|/// variable will be replaced with a bitcast to the new variable.
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

begin_comment
comment|/// GetGlobalVarAddressSpace - Return the address space of the underlying
end_comment

begin_comment
comment|/// global variable for D, as determined by its declaration.  Normally this
end_comment

begin_comment
comment|/// is the same as the address space of D's type, but in CUDA, address spaces
end_comment

begin_comment
comment|/// are associated with declarations, not types.
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
comment|/// GetAddrOfGlobalVar - Return the llvm::Constant for the address of the
end_comment

begin_comment
comment|/// given global variable.  If Ty is non-null and if the global doesn't exist,
end_comment

begin_comment
comment|/// then it will be greated with the specified type instead of whatever the
end_comment

begin_comment
comment|/// normal requested type would be.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobalVar
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|Ty
operator|=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfFunction - Return the address of the given function.  If Ty is
end_comment

begin_comment
comment|/// non-null, then this function will use the specified type if it has to
end_comment

begin_comment
comment|/// create it.
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
argument|llvm::Type *Ty =
literal|0
argument_list|,
argument|bool ForVTable = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfRTTIDescriptor - Get the address of the RTTI descriptor
end_comment

begin_comment
comment|/// for the given type.
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
comment|/// GetAddrOfUuidDescriptor - Get the address of a uuid descriptor .
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfUuidDescriptor
argument_list|(
specifier|const
name|CXXUuidofExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfThunk - Get the address of the thunk for the given global decl.
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
comment|/// GetWeakRefReference - Get a reference to the target of VD.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetWeakRefReference
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|VD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetNonVirtualBaseClassOffset - Returns the offset from a derived class to
end_comment

begin_comment
comment|/// a class. Returns null if the offset is 0.
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

begin_comment
comment|/// A pair of helper functions for a __block variable.
end_comment

begin_decl_stmt
name|class
name|ByrefHelpers
range|:
name|public
name|llvm
operator|::
name|FoldingSetNode
block|{
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
name|ByrefHelpers
argument_list|(
argument|CharUnits alignment
argument_list|)
operator|:
name|Alignment
argument_list|(
argument|alignment
argument_list|)
block|{}
name|virtual
operator|~
name|ByrefHelpers
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
block|;     }
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
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|dest
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
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
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|field
argument_list|)
operator|=
literal|0
block|;   }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|FoldingSet
operator|<
name|ByrefHelpers
operator|>
name|ByrefHelpersCache
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getUniqueBlockCount - Fetches the global unique block count.
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
comment|/// getBlockDescriptorType - Fetches the type of a generic block
end_comment

begin_comment
comment|/// descriptor.
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
comment|/// getGenericBlockLiteralType - The type of a generic block literal.
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
comment|/// GetAddrOfGlobalBlock - Gets the address of a block which
end_comment

begin_comment
comment|/// requires no captures.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobalBlock
argument_list|(
specifier|const
name|BlockExpr
operator|*
name|BE
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfConstantCFString - Return a pointer to a constant CFString object
end_comment

begin_comment
comment|/// for the given string.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantCFString
argument_list|(
specifier|const
name|StringLiteral
operator|*
name|Literal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfConstantString - Return a pointer to a constant NSString object
end_comment

begin_comment
comment|/// for the given string. Or a user defined String object as defined via
end_comment

begin_comment
comment|/// -fconstant-string-class=class_name option.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantString
argument_list|(
specifier|const
name|StringLiteral
operator|*
name|Literal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetConstantArrayFromStringLiteral - Return a constant array for the given
end_comment

begin_comment
comment|/// string.
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
comment|/// GetAddrOfConstantStringFromLiteral - Return a pointer to a constant array
end_comment

begin_comment
comment|/// for the given string literal.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantStringFromLiteral
argument_list|(
specifier|const
name|StringLiteral
operator|*
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfConstantStringFromObjCEncode - Return a pointer to a constant
end_comment

begin_comment
comment|/// array for the given ObjCEncodeExpr node.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantStringFromObjCEncode
argument_list|(
specifier|const
name|ObjCEncodeExpr
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfConstantString - Returns a pointer to a character array
end_comment

begin_comment
comment|/// containing the literal. This contents are exactly that of the given
end_comment

begin_comment
comment|/// string, i.e. it will not be null terminated automatically; see
end_comment

begin_comment
comment|/// GetAddrOfConstantCString. Note that whether the result is actually a
end_comment

begin_comment
comment|/// pointer to an LLVM constant depends on Feature.WriteableStrings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The result has pointer to array type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param GlobalName If provided, the name to use for the global
end_comment

begin_comment
comment|/// (if one is created).
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantString
argument_list|(
argument|StringRef Str
argument_list|,
argument|const char *GlobalName=
literal|0
argument_list|,
argument|unsigned Alignment=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfConstantCString - Returns a pointer to a character array
end_comment

begin_comment
comment|/// containing the literal and a terminating '\0' character. The result has
end_comment

begin_comment
comment|/// pointer to array type.
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

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantCString
argument_list|(
argument|const std::string&str
argument_list|,
argument|const char *GlobalName=
literal|0
argument_list|,
argument|unsigned Alignment=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfConstantCompoundLiteral - Returns a pointer to a constant global
end_comment

begin_comment
comment|/// variable for the given file-scope compound literal expression.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantCompoundLiteral
argument_list|(
specifier|const
name|CompoundLiteralExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns a pointer to a global variable representing a temporary
end_comment

begin_comment
comment|/// with static or thread storage duration.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobalTemporary
argument_list|(
specifier|const
name|MaterializeTemporaryExpr
operator|*
name|E
argument_list|,
specifier|const
name|Expr
operator|*
name|Inner
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/// GetAddrOfCXXConstructor - Return the address of the constructor of the
end_comment

begin_comment
comment|/// given type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalValue
operator|*
name|GetAddrOfCXXConstructor
argument_list|(
argument|const CXXConstructorDecl *ctor
argument_list|,
argument|CXXCtorType ctorType
argument_list|,
argument|const CGFunctionInfo *fnInfo =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddrOfCXXDestructor - Return the address of the constructor of the
end_comment

begin_comment
comment|/// given type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalValue
operator|*
name|GetAddrOfCXXDestructor
argument_list|(
argument|const CXXDestructorDecl *dtor
argument_list|,
argument|CXXDtorType dtorType
argument_list|,
argument|const CGFunctionInfo *fnInfo =
literal|0
argument_list|,
argument|llvm::FunctionType *fnType =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getBuiltinLibFunction - Given a builtin id for a function like
end_comment

begin_comment
comment|/// "__builtin_fabsf", return a Function* for "fabsf".
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
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
comment|/// EmitTopLevelDecl - Emit code for a single top level declaration.
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
comment|/// HandleCXXStaticMemberVarInstantiation - Tell the consumer that this
end_comment

begin_comment
comment|// variable has been instantiated.
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
comment|/// AddUsedGlobal - Add a global which should be forced to be
end_comment

begin_comment
comment|/// present in the object file; these are emitted to the llvm.used
end_comment

begin_comment
comment|/// metadata global.
end_comment

begin_decl_stmt
name|void
name|AddUsedGlobal
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
comment|/// AddCXXDtorEntry - Add a destructor and object to add to the C++ global
end_comment

begin_comment
comment|/// destructor function.
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
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|DtorFn
argument_list|,
name|Object
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// CreateRuntimeFunction - Create a new runtime function with the specified
end_comment

begin_comment
comment|/// type and name.
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
argument|llvm::AttributeSet ExtraAttrs =                                           llvm::AttributeSet()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CreateRuntimeVariable - Create a new runtime global variable with the
end_comment

begin_comment
comment|/// specified type and name.
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
comment|// UpdateCompleteType - Make sure that this type is translated.
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
comment|/// EmitConstantInit - Try to emit the initializer for the given declaration
end_comment

begin_comment
comment|/// as a constant; returns 0 if the expression cannot be emitted as a
end_comment

begin_comment
comment|/// constant.
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
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitConstantExpr - Try to emit the given expression as a
end_comment

begin_comment
comment|/// constant; returns 0 if the expression cannot be emitted as a
end_comment

begin_comment
comment|/// constant.
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
argument|CodeGenFunction *CGF =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitConstantValue - Emit the given constant value as a constant, in the
end_comment

begin_comment
comment|/// type's scalar representation.
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
argument|CodeGenFunction *CGF =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitConstantValueForMemory - Emit the given constant value as a constant,
end_comment

begin_comment
comment|/// in the type's memory representation.
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
argument|CodeGenFunction *CGF =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitNullConstant - Return the result of value-initializing the given
end_comment

begin_comment
comment|/// type, i.e. a null expression of the given type.  This is usually,
end_comment

begin_comment
comment|/// but not always, an LLVM null constant.
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
comment|/// EmitNullConstantForBase - Return a null constant appropriate for
end_comment

begin_comment
comment|/// zero-initializing a base class with the given type.  This is usually,
end_comment

begin_comment
comment|/// but not always, an LLVM null constant.
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
comment|/// Error - Emit a general error that something can't be done.
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
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
end_comment

begin_comment
comment|/// specified stmt yet.
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
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
end_comment

begin_comment
comment|/// specified decl yet.
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
comment|/// SetInternalFunctionAttributes - Set the attributes on the LLVM
end_comment

begin_comment
comment|/// function for the given decl and function info. This applies
end_comment

begin_comment
comment|/// attributes necessary for handling the ABI as well as user
end_comment

begin_comment
comment|/// specified attributes like section.
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
comment|/// SetLLVMFunctionAttributes - Set the LLVM function attributes
end_comment

begin_comment
comment|/// (sext, zext, etc).
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
comment|/// SetLLVMFunctionAttributesForDefinition - Set the LLVM function attributes
end_comment

begin_comment
comment|/// which only apply to a function definintion.
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
comment|/// ReturnTypeUsesSRet - Return true iff the given type uses 'sret' when used
end_comment

begin_comment
comment|/// as a return type.
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
comment|/// ReturnTypeUsesFPRet - Return true iff the given type uses 'fpret' when
end_comment

begin_comment
comment|/// used as a return type.
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
comment|/// ReturnTypeUsesFP2Ret - Return true iff the given type uses 'fp2ret' when
end_comment

begin_comment
comment|/// used as a return type.
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
comment|/// ConstructAttributeList - Get the LLVM attributes and calling convention to
end_comment

begin_comment
comment|/// use for a particular function type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Info - The function type information.
end_comment

begin_comment
comment|/// \param TargetDecl - The decl these attributes are being constructed
end_comment

begin_comment
comment|/// for. If supplied the attributes applied to this decl may contribute to the
end_comment

begin_comment
comment|/// function attributes and calling convention.
end_comment

begin_comment
comment|/// \param PAL [out] - On return, the attribute list to use.
end_comment

begin_comment
comment|/// \param CallingConv [out] - On return, the LLVM calling convention to use.
end_comment

begin_function_decl
name|void
name|ConstructAttributeList
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|Info
parameter_list|,
specifier|const
name|Decl
modifier|*
name|TargetDecl
parameter_list|,
name|AttributeListType
modifier|&
name|PAL
parameter_list|,
name|unsigned
modifier|&
name|CallingConv
parameter_list|,
name|bool
name|AttrOnCallSite
parameter_list|)
function_decl|;
end_function_decl

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
name|void
name|getBlockMangledName
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
name|MangleBuffer
modifier|&
name|Buffer
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
parameter_list|,
name|bool
name|DefinitionRequired
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitFundamentalRTTIDescriptors - Emit the RTTI descriptors for the
end_comment

begin_comment
comment|/// builtin types.
end_comment

begin_function_decl
name|void
name|EmitFundamentalRTTIDescriptors
parameter_list|()
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
name|GlobalValue
operator|*
name|V
argument_list|)
block|{
name|V
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
comment|/// getVTableLinkage - Return the appropriate linkage for the vtable, VTT,
end_comment

begin_comment
comment|/// and type information of the given class.
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
comment|/// GetTargetTypeStoreSize - Return the store size, in character units, of
end_comment

begin_comment
comment|/// the given LLVM type.
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
comment|/// GetLLVMLinkageVarDefinition - Returns LLVM linkage for a global
end_comment

begin_comment
comment|/// variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|GetLLVMLinkageVarDefinition
argument_list|(
argument|const VarDecl *D
argument_list|,
argument|bool isConstant
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
comment|/// EmitAnnotateAttr - Generate the llvm::ConstantStruct which contains the
end_comment

begin_comment
comment|/// annotation information for a given GlobalValue. The annotation struct is
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

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|SpecialCaseList
operator|&
name|getSanitizerBlacklist
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SanitizerBlacklist
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|SanitizerOptions
operator|&
name|getSanOpts
argument_list|()
specifier|const
block|{
return|return
name|SanOpts
return|;
block|}
end_expr_stmt

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
comment|/// EmitGlobal - Emit code for a singal global function or var decl. Forward
end_comment

begin_comment
comment|/// declarations are emitted lazily.
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

begin_label
name|private
label|:
end_label

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
argument|llvm::AttributeSet ExtraAttrs =                                             llvm::AttributeSet()
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
argument|bool UnnamedAddr = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SetCommonAttributes - Set attributes which are common to any
end_comment

begin_comment
comment|/// form of a global definition (alias, Objective-C method,
end_comment

begin_comment
comment|/// function, global variable).
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
comment|/// SetFunctionDefinitionAttributes - Set attributes for a global definition.
end_comment

begin_decl_stmt
name|void
name|SetFunctionDefinitionAttributes
argument_list|(
specifier|const
name|FunctionDecl
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
comment|/// SetFunctionAttributes - Set function attributes for a function
end_comment

begin_comment
comment|/// declaration.
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitGlobalDefinition
parameter_list|(
name|GlobalDecl
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitGlobalFunctionDefinition
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitGlobalVarDefinition
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
name|EmitAliasDefinition
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

begin_function_decl
name|void
name|EmitNamespace
parameter_list|(
specifier|const
name|NamespaceDecl
modifier|*
name|D
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

begin_function_decl
name|void
name|CompleteDIClassType
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCXXConstructor - Emit a single constructor with the given type from
end_comment

begin_comment
comment|/// a C++ constructor Decl.
end_comment

begin_function_decl
name|void
name|EmitCXXConstructor
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCXXDestructor - Emit a single destructor with the given type from
end_comment

begin_comment
comment|/// a C++ destructor Decl.
end_comment

begin_function_decl
name|void
name|EmitCXXDestructor
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|D
parameter_list|,
name|CXXDtorType
name|Type
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
comment|/// EmitCXXGlobalInitFunc - Emit the function that initializes C++ globals.
end_comment

begin_function_decl
name|void
name|EmitCXXGlobalInitFunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCXXGlobalDtorFunc - Emit the function that destroys C++ globals.
end_comment

begin_function_decl
name|void
name|EmitCXXGlobalDtorFunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitCXXGlobalVarDeclInitFunc - Emit the function that initializes the
end_comment

begin_comment
comment|/// specified global (if PerformInit is true) and registers its destructor.
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
comment|/// suitable for use as a LLVM constructor or destructor array.
end_comment

begin_function_decl
name|void
name|EmitCtorList
parameter_list|(
specifier|const
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
comment|/// EmitFundamentalRTTIDescriptor - Emit the RTTI descriptors for the
end_comment

begin_comment
comment|/// given type.
end_comment

begin_function_decl
name|void
name|EmitFundamentalRTTIDescriptor
parameter_list|(
name|QualType
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitDeferred - Emit any needed decls for which code generation
end_comment

begin_comment
comment|/// was deferred.
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

begin_function_decl
name|void
name|checkAliases
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitDeferredVTables - Emit any vtables which we deferred and
end_comment

begin_comment
comment|/// still have a use for.
end_comment

begin_function_decl
name|void
name|EmitDeferredVTables
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLLVMUsed - Emit the llvm.used metadata used to force
end_comment

begin_comment
comment|/// references to global which may otherwise be optimized out.
end_comment

begin_function_decl
name|void
name|EmitLLVMUsed
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
comment|/// EmitCoverageFile - Emit the llvm.gcov metadata used to tell LLVM where
end_comment

begin_comment
comment|/// to emit the .gcno and .gcda files in a way that persists in .bc files.
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
argument_list|,
argument|QualType IIDType
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// MayDeferGeneration - Determine if the given decl can be emitted
end_comment

begin_comment
comment|/// lazily; this is only relevant for definitions. The given decl
end_comment

begin_comment
comment|/// must be either a function or var decl.
end_comment

begin_function_decl
name|bool
name|MayDeferGeneration
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// SimplifyPersonality - Check whether we can use a "simpler", more
end_comment

begin_comment
comment|/// core exceptions personality function.
end_comment

begin_function_decl
name|void
name|SimplifyPersonality
parameter_list|()
function_decl|;
end_function_decl

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

end_unit

