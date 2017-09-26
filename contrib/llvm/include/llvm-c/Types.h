begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Support.h - C Interface Types declarations ---------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file defines types used by the the C interface to LLVM.               *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_TYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
comment|/**  * @defgroup LLVMCSupportTypes Types and Enumerations  *  * @{  */
typedef|typedef
name|int
name|LLVMBool
typedef|;
comment|/* Opaque types. */
comment|/**  * LLVM uses a polymorphic type hierarchy which C cannot represent, therefore  * parameters must be passed as base types. Despite the declared types, most  * of the functions provided operate only on branches of the type hierarchy.  * The declared parameter names are descriptive and specify which type is  * required. Additionally, each type hierarchy is documented along with the  * functions that operate upon it. For more detail, refer to LLVM's C++ code.  * If in doubt, refer to Core.cpp, which performs parameter downcasts in the  * form unwrap<RequiredType>(Param).  */
comment|/**  * Used to pass regions of memory through LLVM interfaces.  *  * @see llvm::MemoryBuffer  */
typedef|typedef
name|struct
name|LLVMOpaqueMemoryBuffer
modifier|*
name|LLVMMemoryBufferRef
typedef|;
comment|/**  * The top-level container for all LLVM global data. See the LLVMContext class.  */
typedef|typedef
name|struct
name|LLVMOpaqueContext
modifier|*
name|LLVMContextRef
typedef|;
comment|/**  * The top-level container for all other LLVM Intermediate Representation (IR)  * objects.  *  * @see llvm::Module  */
typedef|typedef
name|struct
name|LLVMOpaqueModule
modifier|*
name|LLVMModuleRef
typedef|;
comment|/**  * Each value in the LLVM IR has a type, an LLVMTypeRef.  *  * @see llvm::Type  */
typedef|typedef
name|struct
name|LLVMOpaqueType
modifier|*
name|LLVMTypeRef
typedef|;
comment|/**  * Represents an individual value in LLVM IR.  *  * This models llvm::Value.  */
typedef|typedef
name|struct
name|LLVMOpaqueValue
modifier|*
name|LLVMValueRef
typedef|;
comment|/**  * Represents a basic block of instructions in LLVM IR.  *  * This models llvm::BasicBlock.  */
typedef|typedef
name|struct
name|LLVMOpaqueBasicBlock
modifier|*
name|LLVMBasicBlockRef
typedef|;
comment|/**  * Represents an LLVM Metadata.  *  * This models llvm::Metadata.  */
typedef|typedef
name|struct
name|LLVMOpaqueMetadata
modifier|*
name|LLVMMetadataRef
typedef|;
comment|/**  * Represents an LLVM basic block builder.  *  * This models llvm::IRBuilder.  */
typedef|typedef
name|struct
name|LLVMOpaqueBuilder
modifier|*
name|LLVMBuilderRef
typedef|;
comment|/**  * Represents an LLVM debug info builder.  *  * This models llvm::DIBuilder.  */
typedef|typedef
name|struct
name|LLVMOpaqueDIBuilder
modifier|*
name|LLVMDIBuilderRef
typedef|;
comment|/**  * Interface used to provide a module to JIT or interpreter.  * This is now just a synonym for llvm::Module, but we have to keep using the  * different type to keep binary compatibility.  */
typedef|typedef
name|struct
name|LLVMOpaqueModuleProvider
modifier|*
name|LLVMModuleProviderRef
typedef|;
comment|/** @see llvm::PassManagerBase */
typedef|typedef
name|struct
name|LLVMOpaquePassManager
modifier|*
name|LLVMPassManagerRef
typedef|;
comment|/** @see llvm::PassRegistry */
typedef|typedef
name|struct
name|LLVMOpaquePassRegistry
modifier|*
name|LLVMPassRegistryRef
typedef|;
comment|/**  * Used to get the users and usees of a Value.  *  * @see llvm::Use */
typedef|typedef
name|struct
name|LLVMOpaqueUse
modifier|*
name|LLVMUseRef
typedef|;
comment|/**  * Used to represent an attributes.  *  * @see llvm::Attribute  */
typedef|typedef
name|struct
name|LLVMOpaqueAttributeRef
modifier|*
name|LLVMAttributeRef
typedef|;
comment|/**  * @see llvm::DiagnosticInfo  */
typedef|typedef
name|struct
name|LLVMOpaqueDiagnosticInfo
modifier|*
name|LLVMDiagnosticInfoRef
typedef|;
comment|/**  * @}  */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

