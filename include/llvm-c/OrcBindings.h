begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===----------- llvm-c/OrcBindings.h - Orc Lib C Iface ---------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMOrcJIT.a, which implements  *| |* JIT compilation of LLVM IR.                                                *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| |* Note: This interface is experimental. It is *NOT* stable, and may be       *| |*       changed without warning.                                             *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_ORCBINDINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_ORCBINDINGS_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Object.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Support.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/TargetMachine.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
name|struct
name|LLVMOrcOpaqueJITStack
modifier|*
name|LLVMOrcJITStackRef
typedef|;
typedef|typedef
name|uint32_t
name|LLVMOrcModuleHandle
typedef|;
typedef|typedef
name|uint64_t
name|LLVMOrcTargetAddress
typedef|;
typedef|typedef
name|uint64_t
function_decl|(
modifier|*
name|LLVMOrcSymbolResolverFn
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
name|void
modifier|*
name|LookupCtx
parameter_list|)
function_decl|;
typedef|typedef
name|uint64_t
function_decl|(
modifier|*
name|LLVMOrcLazyCompileCallbackFn
function_decl|)
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|void
modifier|*
name|CallbackCtx
parameter_list|)
function_decl|;
comment|/**  * Create an ORC JIT stack.  *  * The client owns the resulting stack, and must call OrcDisposeInstance(...)  * to destroy it and free its memory. The JIT stack will take ownership of the  * TargetMachine, which will be destroyed when the stack is destroyed. The  * client should not attempt to dispose of the Target Machine, or it will result  * in a double-free.  */
name|LLVMOrcJITStackRef
name|LLVMOrcCreateInstance
parameter_list|(
name|LLVMTargetMachineRef
name|TM
parameter_list|)
function_decl|;
comment|/**  * Mangle the given symbol.  * Memory will be allocated for MangledSymbol to hold the result. The client  */
name|void
name|LLVMOrcGetMangledSymbol
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|char
modifier|*
modifier|*
name|MangledSymbol
parameter_list|,
specifier|const
name|char
modifier|*
name|Symbol
parameter_list|)
function_decl|;
comment|/**  * Dispose of a mangled symbol.  */
name|void
name|LLVMOrcDisposeMangledSymbol
parameter_list|(
name|char
modifier|*
name|MangledSymbol
parameter_list|)
function_decl|;
comment|/**  * Create a lazy compile callback.  */
name|LLVMOrcTargetAddress
name|LLVMOrcCreateLazyCompileCallback
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|LLVMOrcLazyCompileCallbackFn
name|Callback
parameter_list|,
name|void
modifier|*
name|CallbackCtx
parameter_list|)
function_decl|;
comment|/**  * Create a named indirect call stub.  */
name|void
name|LLVMOrcCreateIndirectStub
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
specifier|const
name|char
modifier|*
name|StubName
parameter_list|,
name|LLVMOrcTargetAddress
name|InitAddr
parameter_list|)
function_decl|;
comment|/**  * Set the pointer for the given indirect stub.  */
name|void
name|LLVMOrcSetIndirectStubPointer
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
specifier|const
name|char
modifier|*
name|StubName
parameter_list|,
name|LLVMOrcTargetAddress
name|NewAddr
parameter_list|)
function_decl|;
comment|/**  * Add module to be eagerly compiled.  */
name|LLVMOrcModuleHandle
name|LLVMOrcAddEagerlyCompiledIR
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|LLVMModuleRef
name|Mod
parameter_list|,
name|LLVMOrcSymbolResolverFn
name|SymbolResolver
parameter_list|,
name|void
modifier|*
name|SymbolResolverCtx
parameter_list|)
function_decl|;
comment|/**  * Add module to be lazily compiled one function at a time.  */
name|LLVMOrcModuleHandle
name|LLVMOrcAddLazilyCompiledIR
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|LLVMModuleRef
name|Mod
parameter_list|,
name|LLVMOrcSymbolResolverFn
name|SymbolResolver
parameter_list|,
name|void
modifier|*
name|SymbolResolverCtx
parameter_list|)
function_decl|;
comment|/**  * Add an object file.  */
name|LLVMOrcModuleHandle
name|LLVMOrcAddObjectFile
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|LLVMObjectFileRef
name|Obj
parameter_list|,
name|LLVMOrcSymbolResolverFn
name|SymbolResolver
parameter_list|,
name|void
modifier|*
name|SymbolResolverCtx
parameter_list|)
function_decl|;
comment|/**  * Remove a module set from the JIT.  *  * This works for all modules that can be added via OrcAdd*, including object  * files.  */
name|void
name|LLVMOrcRemoveModule
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
name|LLVMOrcModuleHandle
name|H
parameter_list|)
function_decl|;
comment|/**  * Get symbol address from JIT instance.  */
name|LLVMOrcTargetAddress
name|LLVMOrcGetSymbolAddress
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|,
specifier|const
name|char
modifier|*
name|SymbolName
parameter_list|)
function_decl|;
comment|/**  * Dispose of an ORC JIT stack.  */
name|void
name|LLVMOrcDisposeInstance
parameter_list|(
name|LLVMOrcJITStackRef
name|JITStack
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* extern "C" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_C_ORCBINDINGS_H */
end_comment

end_unit

