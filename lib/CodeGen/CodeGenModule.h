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
file|"clang/Basic/LangOptions.h"
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
file|"CGBlocks.h"
end_include

begin_include
include|#
directive|include
file|"CGCall.h"
end_include

begin_include
include|#
directive|include
file|"CGCXX.h"
end_include

begin_include
include|#
directive|include
file|"CGVtable.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenTypes.h"
end_include

begin_include
include|#
directive|include
file|"GlobalDecl.h"
end_include

begin_include
include|#
directive|include
file|"Mangle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|<list>
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
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|TargetData
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
name|Decl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|Stmt
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
name|Diagnostic
decl_stmt|;
name|class
name|AnnotateAttr
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CGDebugInfo
decl_stmt|;
name|class
name|CGObjCRuntime
decl_stmt|;
comment|/// CodeGenModule - This class organizes the cross-function state that is used
comment|/// while generating LLVM code.
name|class
name|CodeGenModule
range|:
name|public
name|BlockModule
block|{
name|CodeGenModule
argument_list|(
specifier|const
name|CodeGenModule
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenModule
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
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
name|Features
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
specifier|const
name|llvm
operator|::
name|TargetData
operator|&
name|TheTargetData
expr_stmt|;
name|mutable
specifier|const
name|TargetCodeGenInfo
modifier|*
name|TheTargetCodeGenInfo
decl_stmt|;
name|Diagnostic
modifier|&
name|Diags
decl_stmt|;
name|CodeGenTypes
name|Types
decl_stmt|;
name|MangleContext
name|MangleCtx
decl_stmt|;
comment|/// VtableInfo - Holds information about C++ vtables.
name|CGVtableInfo
name|VtableInfo
decl_stmt|;
name|CGObjCRuntime
modifier|*
name|Runtime
decl_stmt|;
name|CGDebugInfo
modifier|*
name|DebugInfo
decl_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|MemCpyFn
expr_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|MemMoveFn
expr_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|MemSetFn
expr_stmt|;
comment|/// GlobalDeclMap - Mapping of decl names (represented as unique
comment|/// character pointers from either the identifier table or the set
comment|/// of mangled names) to global variables we have already
comment|/// emitted. Note that the entries in this map are the actual
comment|/// globals and therefore may not be of the same type as the decl,
comment|/// they should be bitcasted on retrieval. Also note that the
comment|/// globals are keyed on their source mangled name, not the global name
comment|/// (which may change with attributes such as asm-labels).  The key
comment|/// to this map should be generated using getMangledName().
comment|///
comment|/// Note that this map always lines up exactly with the contents of the LLVM
comment|/// IR symbol table, but this is quicker to query since it is doing uniqued
comment|/// pointer lookups instead of full string lookups.
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
name|GlobalValue
operator|*
operator|>
name|GlobalDeclMap
expr_stmt|;
comment|/// \brief Contains the strings used for mangled names.
comment|///
comment|/// FIXME: Eventually, this should map from the semantic/canonical
comment|/// declaration for each global entity to its mangled name (if it
comment|/// has one).
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|MangledNames
expr_stmt|;
comment|/// DeferredDecls - This contains all the decls which have definitions but
comment|/// which are deferred for emission and therefore should only be output if
comment|/// they are actually used.  If a decl is in this, then it is known to have
comment|/// not been referenced yet.  The key to this map is a uniqued mangled name.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|char
operator|*
operator|,
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
name|Constant
operator|*
operator|>
name|ConstantStringMap
expr_stmt|;
comment|/// CXXGlobalInits - Variables with global initializers that need to run
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
comment|/// CFConstantStringClassRef - Cached reference to the class for constant
comment|/// strings. This value has type int * but is actually an Obj-C class pointer.
name|llvm
operator|::
name|Constant
operator|*
name|CFConstantStringClassRef
expr_stmt|;
comment|/// Lazily create the Objective-C runtime
name|void
name|createObjCRuntime
parameter_list|()
function_decl|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|VMContext
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
name|TargetData
operator|&
name|TD
argument_list|,
name|Diagnostic
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
name|Runtime
condition|)
name|createObjCRuntime
argument_list|()
expr_stmt|;
return|return
operator|*
name|Runtime
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
name|Runtime
return|;
block|}
name|CGDebugInfo
modifier|*
name|getDebugInfo
parameter_list|()
block|{
return|return
name|DebugInfo
return|;
block|}
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
specifier|const
name|LangOptions
operator|&
name|getLangOptions
argument_list|()
specifier|const
block|{
return|return
name|Features
return|;
block|}
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
name|CodeGenTypes
modifier|&
name|getTypes
parameter_list|()
block|{
return|return
name|Types
return|;
block|}
name|MangleContext
modifier|&
name|getMangleContext
parameter_list|()
block|{
return|return
name|MangleCtx
return|;
block|}
name|CGVtableInfo
modifier|&
name|getVtableInfo
parameter_list|()
block|{
return|return
name|VtableInfo
return|;
block|}
name|Diagnostic
operator|&
name|getDiags
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
specifier|const
name|llvm
operator|::
name|TargetData
operator|&
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
name|TheTargetData
return|;
block|}
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
specifier|const
name|TargetCodeGenInfo
operator|&
name|getTargetCodeGenInfo
argument_list|()
specifier|const
expr_stmt|;
comment|/// getDeclVisibilityMode - Compute the visibility of the decl \arg D.
name|LangOptions
operator|::
name|VisibilityMode
name|getDeclVisibilityMode
argument_list|(
argument|const Decl *D
argument_list|)
specifier|const
expr_stmt|;
comment|/// setGlobalVisibility - Set the visibility for the given LLVM
comment|/// GlobalValue.
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
name|Decl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
comment|/// GetAddrOfGlobalVar - Return the llvm::Constant for the address of the
comment|/// given global variable.  If Ty is non-null and if the global doesn't exist,
comment|/// then it will be greated with the specified type instead of whatever the
comment|/// normal requested type would be.
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
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// GetAddrOfFunction - Return the address of the given function.  If Ty is
comment|/// non-null, then this function will use the specified type if it has to
comment|/// create it.
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfFunction
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|const llvm::Type *Ty =
literal|0
argument_list|)
expr_stmt|;
comment|/// GetAddrOfRTTIDescriptor - Get the address of the RTTI descriptor
comment|/// for the given type.
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfRTTIDescriptor
argument_list|(
argument|QualType Ty
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfThunk
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|const ThunkAdjustment&ThisAdjustment
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfCovariantThunk
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|const CovariantThunkAdjustment&ThisAdjustment
argument_list|)
expr_stmt|;
name|void
name|BuildThunksForVirtual
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
name|void
name|BuildThunksForVirtualRecursive
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
name|GlobalDecl
name|BaseOGD
parameter_list|)
function_decl|;
comment|/// BuildThunk - Build a thunk for the given method.
name|llvm
operator|::
name|Constant
operator|*
name|BuildThunk
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|bool Extern
argument_list|,
argument|const ThunkAdjustment&ThisAdjustment
argument_list|)
expr_stmt|;
comment|/// BuildCoVariantThunk - Build a thunk for the given method
name|llvm
operator|::
name|Constant
operator|*
name|BuildCovariantThunk
argument_list|(
argument|const GlobalDecl&GD
argument_list|,
argument|bool Extern
argument_list|,
argument|const CovariantThunkAdjustment&Adjustment
argument_list|)
expr_stmt|;
comment|/// GetCXXBaseClassOffset - Returns the offset from a derived class to its
comment|/// base class. Returns null if the offset is 0.
name|llvm
operator|::
name|Constant
operator|*
name|GetCXXBaseClassOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|ClassDecl
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|)
expr_stmt|;
comment|/// ComputeThunkAdjustment - Returns the two parts required to compute the
comment|/// offset for an object.
name|ThunkAdjustment
name|ComputeThunkAdjustment
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|BaseClassDecl
parameter_list|)
function_decl|;
comment|/// GetStringForStringLiteral - Return the appropriate bytes for a string
comment|/// literal, properly padded to match the literal type. If only the address of
comment|/// a constant is needed consider using GetAddrOfConstantStringLiteral.
name|std
operator|::
name|string
name|GetStringForStringLiteral
argument_list|(
specifier|const
name|StringLiteral
operator|*
name|E
argument_list|)
expr_stmt|;
comment|/// GetAddrOfConstantCFString - Return a pointer to a constant CFString object
comment|/// for the given string.
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
comment|/// GetAddrOfConstantStringFromLiteral - Return a pointer to a constant array
comment|/// for the given string literal.
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
comment|/// GetAddrOfConstantStringFromObjCEncode - Return a pointer to a constant
comment|/// array for the given ObjCEncodeExpr node.
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
comment|/// GetAddrOfConstantString - Returns a pointer to a character array
comment|/// containing the literal. This contents are exactly that of the given
comment|/// string, i.e. it will not be null terminated automatically; see
comment|/// GetAddrOfConstantCString. Note that whether the result is actually a
comment|/// pointer to an LLVM constant depends on Feature.WriteableStrings.
comment|///
comment|/// The result has pointer to array type.
comment|///
comment|/// \param GlobalName If provided, the name to use for the global
comment|/// (if one is created).
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|char
operator|*
name|GlobalName
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// GetAddrOfConstantCString - Returns a pointer to a character array
comment|/// containing the literal and a terminating '\0' character. The result has
comment|/// pointer to array type.
comment|///
comment|/// \param GlobalName If provided, the name to use for the global (if one is
comment|/// created).
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfConstantCString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|,
specifier|const
name|char
operator|*
name|GlobalName
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// GetAddrOfCXXConstructor - Return the address of the constructor of the
comment|/// given type.
name|llvm
operator|::
name|Function
operator|*
name|GetAddrOfCXXConstructor
argument_list|(
argument|const CXXConstructorDecl *D
argument_list|,
argument|CXXCtorType Type
argument_list|)
expr_stmt|;
comment|/// GetAddrOfCXXDestructor - Return the address of the constructor of the
comment|/// given type.
name|llvm
operator|::
name|Function
operator|*
name|GetAddrOfCXXDestructor
argument_list|(
argument|const CXXDestructorDecl *D
argument_list|,
argument|CXXDtorType Type
argument_list|)
expr_stmt|;
comment|/// getBuiltinLibFunction - Given a builtin id for a function like
comment|/// "__builtin_fabsf", return a Function* for "fabsf".
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
name|llvm
operator|::
name|Function
operator|*
name|getMemCpyFn
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|getMemMoveFn
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|getMemSetFn
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|getIntrinsic
argument_list|(
argument|unsigned IID
argument_list|,
argument|const llvm::Type **Tys =
literal|0
argument_list|,
argument|unsigned NumTys =
literal|0
argument_list|)
expr_stmt|;
comment|/// EmitTopLevelDecl - Emit code for a single top level declaration.
name|void
name|EmitTopLevelDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// AddUsedGlobal - Add a global which should be forced to be
comment|/// present in the object file; these are emitted to the llvm.used
comment|/// metadata global.
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
name|void
name|AddAnnotation
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
block|{
name|Annotations
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// CreateRuntimeFunction - Create a new runtime function with the specified
comment|/// type and name.
name|llvm
operator|::
name|Constant
operator|*
name|CreateRuntimeFunction
argument_list|(
specifier|const
name|llvm
operator|::
name|FunctionType
operator|*
name|Ty
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|)
expr_stmt|;
comment|/// CreateRuntimeVariable - Create a new runtime global variable with the
comment|/// specified type and name.
name|llvm
operator|::
name|Constant
operator|*
name|CreateRuntimeVariable
argument_list|(
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|)
expr_stmt|;
name|void
name|UpdateCompletedType
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
block|{
comment|// Make sure that this type is translated.
name|Types
operator|.
name|UpdateCompletedType
argument_list|(
name|TD
argument_list|)
expr_stmt|;
block|}
comment|/// EmitConstantExpr - Try to emit the given expression as a
comment|/// constant; returns 0 if the expression cannot be emitted as a
comment|/// constant.
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
comment|/// EmitNullConstant - Return the result of value-initializing the given
comment|/// type, i.e. a null expression of the given type.  This is usually,
comment|/// but not always, an LLVM null constant.
name|llvm
operator|::
name|Constant
operator|*
name|EmitNullConstant
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
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
argument|unsigned LineNo
argument_list|)
expr_stmt|;
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
comment|/// specified stmt yet.
comment|/// \param OmitOnError - If true, then this error should only be emitted if no
comment|/// other errors have been reported.
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
parameter_list|,
name|bool
name|OmitOnError
init|=
name|false
parameter_list|)
function_decl|;
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
comment|/// specified decl yet.
comment|/// \param OmitOnError - If true, then this error should only be emitted if no
comment|/// other errors have been reported.
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
parameter_list|,
name|bool
name|OmitOnError
init|=
name|false
parameter_list|)
function_decl|;
comment|/// SetInternalFunctionAttributes - Set the attributes on the LLVM
comment|/// function for the given decl and function info. This applies
comment|/// attributes necessary for handling the ABI as well as user
comment|/// specified attributes like section.
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
comment|/// SetLLVMFunctionAttributes - Set the LLVM function attributes
comment|/// (sext, zext, etc).
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
comment|/// SetLLVMFunctionAttributesForDefinition - Set the LLVM function attributes
comment|/// which only apply to a function definintion.
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
comment|/// ReturnTypeUsesSret - Return true iff the given type uses 'sret' when used
comment|/// as a return type.
name|bool
name|ReturnTypeUsesSret
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
comment|/// ConstructAttributeList - Get the LLVM attributes and calling convention to
comment|/// use for a particular function type.
comment|///
comment|/// \param Info - The function type information.
comment|/// \param TargetDecl - The decl these attributes are being constructed
comment|/// for. If supplied the attributes applied to this decl may contribute to the
comment|/// function attributes and calling convention.
comment|/// \param PAL [out] - On return, the attribute list to use.
comment|/// \param CallingConv [out] - On return, the LLVM calling convention to use.
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
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|getMangledName
parameter_list|(
specifier|const
name|GlobalDecl
modifier|&
name|D
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|getMangledName
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|ND
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|getMangledCXXCtorName
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
specifier|const
name|char
modifier|*
name|getMangledCXXDtorName
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
name|void
name|EmitTentativeDefinition
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
enum|enum
name|GVALinkage
block|{
name|GVA_Internal
block|,
name|GVA_C99Inline
block|,
name|GVA_CXXInline
block|,
name|GVA_StrongExternal
block|,
name|GVA_TemplateInstantiation
block|}
enum|;
comment|/// getVtableLinkage - Return the appropriate linkage for the vtable, VTT,
comment|/// and type information of the given class.
specifier|static
name|llvm
operator|::
name|GlobalVariable
operator|::
name|LinkageTypes
name|getVtableLinkage
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// UniqueMangledName - Unique a name by (if necessary) inserting it into the
comment|/// MangledNames string map.
specifier|const
name|char
modifier|*
name|UniqueMangledName
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|NameEnd
parameter_list|)
function_decl|;
name|llvm
operator|::
name|Constant
operator|*
name|GetOrCreateLLVMFunction
argument_list|(
argument|const char *MangledName
argument_list|,
argument|const llvm::Type *Ty
argument_list|,
argument|GlobalDecl D
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|GetOrCreateLLVMGlobal
argument_list|(
specifier|const
name|char
operator|*
name|MangledName
argument_list|,
specifier|const
name|llvm
operator|::
name|PointerType
operator|*
name|PTy
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// SetCommonAttributes - Set attributes which are common to any
comment|/// form of a global definition (alias, Objective-C method,
comment|/// function, global variable).
comment|///
comment|/// NOTE: This should only be called for definitions.
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
comment|/// SetFunctionDefinitionAttributes - Set attributes for a global definition.
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
comment|/// SetFunctionAttributes - Set function attributes for a function
comment|/// declaration.
name|void
name|SetFunctionAttributes
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
argument_list|,
name|bool
name|IsIncompleteFunction
argument_list|)
decl_stmt|;
comment|/// EmitGlobal - Emit code for a singal global function or var decl. Forward
comment|/// declarations are emitted lazily.
name|void
name|EmitGlobal
parameter_list|(
name|GlobalDecl
name|D
parameter_list|)
function_decl|;
name|void
name|EmitGlobalDefinition
parameter_list|(
name|GlobalDecl
name|D
parameter_list|)
function_decl|;
name|void
name|EmitGlobalFunctionDefinition
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
name|void
name|EmitGlobalVarDefinition
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|EmitAliasDefinition
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|EmitObjCPropertyImplementations
parameter_list|(
specifier|const
name|ObjCImplementationDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|// C++ related functions.
name|void
name|EmitNamespace
parameter_list|(
specifier|const
name|NamespaceDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|EmitLinkageSpec
parameter_list|(
specifier|const
name|LinkageSpecDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// EmitCXXConstructors - Emit constructors (base, complete) from a
comment|/// C++ constructor Decl.
name|void
name|EmitCXXConstructors
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// EmitCXXConstructor - Emit a single constructor with the given type from
comment|/// a C++ constructor Decl.
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
comment|/// EmitCXXDestructors - Emit destructors (base, complete) from a
comment|/// C++ destructor Decl.
name|void
name|EmitCXXDestructors
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// EmitCXXDestructor - Emit a single destructor with the given type from
comment|/// a C++ destructor Decl.
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
comment|/// EmitCXXGlobalInitFunc - Emit a function that initializes C++ globals.
name|void
name|EmitCXXGlobalInitFunc
parameter_list|()
function_decl|;
name|void
name|EmitCXXGlobalVarDeclInitFunc
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|// FIXME: Hardcoding priority here is gross.
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
comment|/// EmitCtorList - Generates a global array of functions and priorities using
comment|/// the given list and name. This array will have appending linkage and is
comment|/// suitable for use as a LLVM constructor or destructor array.
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
name|void
name|EmitAnnotations
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// EmitDeferred - Emit any needed decls for which code generation
comment|/// was deferred.
name|void
name|EmitDeferred
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// EmitLLVMUsed - Emit the llvm.used metadata used to force
comment|/// references to global which may otherwise be optimized out.
name|void
name|EmitLLVMUsed
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/// MayDeferGeneration - Determine if the given decl can be emitted
comment|/// lazily; this is only relevant for definitions. The given decl
comment|/// must be either a function or var decl.
name|bool
name|MayDeferGeneration
parameter_list|(
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
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

