begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IRExecutionUnit.h ---------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_IRExecutionUnit_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_IRExecutionUnit_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/DataBufferHeap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITMemoryManager.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpressionParser.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/IRMemoryMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|ExecutionEngine
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Error
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class IRExecutionUnit IRExecutionUnit.h "lldb/Expression/IRExecutionUnit.h"
comment|/// @brief Contains the IR and, optionally, JIT-compiled code for a module.
comment|///
comment|/// This class encapsulates the compiled version of an expression, in IR
comment|/// form (for interpretation purposes) and in raw machine code form (for
comment|/// execution in the target).
comment|///
comment|/// This object wraps an IR module that comes from the expression parser,
comment|/// and knows how to use the JIT to make it into executable code.  It can
comment|/// then be used as input to the IR interpreter, or the address of the
comment|/// executable code can be passed to a thread plan to run in the target.
comment|///
comment|/// This class creates a subclass of LLVM's JITMemoryManager, because that is
comment|/// how the JIT emits code.  Because LLDB needs to move JIT-compiled code
comment|/// into the target process, the IRExecutionUnit knows how to copy the
comment|/// emitted code into the target process.
comment|//----------------------------------------------------------------------
name|class
name|IRExecutionUnit
range|:
name|public
name|IRMemoryMap
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|//------------------------------------------------------------------
name|IRExecutionUnit
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|LLVMContext
operator|>
operator|&
name|context_ap
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
operator|&
name|module_ap
argument_list|,
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|cpu_features
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|IRExecutionUnit
argument_list|()
block|;
name|llvm
operator|::
name|Module
operator|*
name|GetModule
argument_list|()
block|{
return|return
name|m_module
return|;
block|}
name|llvm
operator|::
name|Function
operator|*
name|GetFunction
argument_list|()
block|{
if|if
condition|(
name|m_module
condition|)
return|return
name|m_module
operator|->
name|getFunction
argument_list|(
name|m_name
operator|.
name|AsCString
argument_list|()
argument_list|)
return|;
else|else
return|return
name|NULL
return|;
block|}
name|void
name|GetRunnableInfo
argument_list|(
name|Error
operator|&
name|error
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|func_addr
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|func_end
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Accessors for IRForTarget and other clients that may want binary
comment|/// data placed on their behalf.  The binary data is owned by the
comment|/// IRExecutionUnit unless the client explicitly chooses to free it.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|WriteNow
argument_list|(
argument|const uint8_t *bytes
argument_list|,
argument|size_t size
argument_list|,
argument|Error&error
argument_list|)
block|;
name|void
name|FreeNow
argument_list|(
argument|lldb::addr_t allocation
argument_list|)
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|/// Look up the object in m_address_map that contains a given address,
comment|/// find where it was copied to, and return the remote address at the
comment|/// same offset into the copied entity
comment|///
comment|/// @param[in] local_address
comment|///     The address in the debugger.
comment|///
comment|/// @return
comment|///     The address in the target process.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetRemoteAddressForLocal
argument_list|(
argument|lldb::addr_t local_address
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Look up the object in m_address_map that contains a given address,
comment|/// find where it was copied to, and return its address range in the
comment|/// target process
comment|///
comment|/// @param[in] local_address
comment|///     The address in the debugger.
comment|///
comment|/// @return
comment|///     The range of the containing object in the target process.
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|uintptr_t
operator|>
name|AddrRange
expr_stmt|;
name|AddrRange
name|GetRemoteRangeForLocal
argument_list|(
argument|lldb::addr_t local_address
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Commit all allocations to the process and record where they were stored.
comment|///
comment|/// @param[in] process
comment|///     The process to allocate memory in.
comment|///
comment|/// @return
comment|///     True<=> all allocations were performed successfully.
comment|///     This method will attempt to free allocated memory if the
comment|///     operation fails.
comment|//------------------------------------------------------------------
name|bool
name|CommitAllocations
argument_list|(
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Report all committed allocations to the execution engine.
comment|///
comment|/// @param[in] engine
comment|///     The execution engine to notify.
comment|//------------------------------------------------------------------
name|void
name|ReportAllocations
argument_list|(
name|llvm
operator|::
name|ExecutionEngine
operator|&
name|engine
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Write the contents of all allocations to the process.
comment|///
comment|/// @param[in] local_address
comment|///     The process containing the allocations.
comment|///
comment|/// @return
comment|///     True<=> all allocations were performed successfully.
comment|//------------------------------------------------------------------
name|bool
name|WriteData
argument_list|(
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
name|Error
name|DisassembleFunction
argument_list|(
name|Stream
operator|&
name|stream
argument_list|,
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
name|class
name|MemoryManager
range|:
name|public
name|llvm
operator|::
name|JITMemoryManager
block|{
name|public
operator|:
name|MemoryManager
argument_list|(
name|IRExecutionUnit
operator|&
name|parent
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
name|setMemoryWritable
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
name|setMemoryExecutable
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
name|setPoisonMemory
argument_list|(
argument|bool poison
argument_list|)
block|{
name|m_default_mm_ap
operator|->
name|setPoisonMemory
argument_list|(
name|poison
argument_list|)
block|;         }
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
name|AllocateGOT
argument_list|()
block|{
name|m_default_mm_ap
operator|->
name|AllocateGOT
argument_list|()
block|;         }
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|getGOTBase
argument_list|()
specifier|const
block|{
return|return
name|m_default_mm_ap
operator|->
name|getGOTBase
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|startFunctionBody
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|,
name|uintptr_t
operator|&
name|ActualSize
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Allocate room for a dyld stub for a lazy-referenced function,
comment|/// and add it to the m_stubs map
comment|///
comment|/// @param[in] F
comment|///     The function being referenced.
comment|///
comment|/// @param[in] StubSize
comment|///     The size of the stub.
comment|///
comment|/// @param[in] Alignment
comment|///     The required alignment of the stub.
comment|///
comment|/// @return
comment|///     Allocated space for the stub.
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|allocateStub
argument_list|(
argument|const llvm::GlobalValue* F
argument_list|,
argument|unsigned StubSize
argument_list|,
argument|unsigned Alignment
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Complete the body of a function, and add it to the m_functions map
comment|///
comment|/// @param[in] F
comment|///     The function being completed.
comment|///
comment|/// @param[in] FunctionStart
comment|///     The first instruction of the function.
comment|///
comment|/// @param[in] FunctionEnd
comment|///     The last byte of the last instruction of the function.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|endFunctionBody
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|,
name|uint8_t
operator|*
name|FunctionStart
argument_list|,
name|uint8_t
operator|*
name|FunctionEnd
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Allocate space for an unspecified purpose, and add it to the
comment|/// m_spaceBlocks map
comment|///
comment|/// @param[in] Size
comment|///     The size of the area.
comment|///
comment|/// @param[in] Alignment
comment|///     The required alignment of the area.
comment|///
comment|/// @return
comment|///     Allocated space.
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|allocateSpace
argument_list|(
argument|intptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Allocate space for executable code, and add it to the
comment|/// m_spaceBlocks map
comment|///
comment|/// @param[in] Size
comment|///     The size of the area.
comment|///
comment|/// @param[in] Alignment
comment|///     The required alignment of the area.
comment|///
comment|/// @param[in] SectionID
comment|///     A unique identifier for the section.
comment|///
comment|/// @return
comment|///     Allocated space.
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|allocateCodeSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Allocate space for data, and add it to the m_spaceBlocks map
comment|///
comment|/// @param[in] Size
comment|///     The size of the area.
comment|///
comment|/// @param[in] Alignment
comment|///     The required alignment of the area.
comment|///
comment|/// @param[in] SectionID
comment|///     A unique identifier for the section.
comment|///
comment|/// @param[in] IsReadOnly
comment|///     Flag indicating the section is read-only.
comment|///
comment|/// @return
comment|///     Allocated space.
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|allocateDataSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|bool IsReadOnly
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Allocate space for a global variable, and add it to the
comment|/// m_spaceBlocks map
comment|///
comment|/// @param[in] Size
comment|///     The size of the variable.
comment|///
comment|/// @param[in] Alignment
comment|///     The required alignment of the variable.
comment|///
comment|/// @return
comment|///     Allocated space for the global.
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|allocateGlobal
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Called when object loading is complete and section page
comment|/// permissions can be applied. Currently unimplemented for LLDB.
comment|///
comment|/// @param[out] ErrMsg
comment|///     The error that prevented the page protection from succeeding.
comment|///
comment|/// @return
comment|///     True in case of failure, false in case of success.
comment|//------------------------------------------------------------------
name|bool
name|applyPermissions
argument_list|(
argument|std::string *ErrMsg
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
name|deallocateFunctionBody
argument_list|(
name|void
operator|*
name|Body
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|startExceptionTable
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|,
name|uintptr_t
operator|&
name|ActualSize
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Complete the exception table for a function, and add it to the
comment|/// m_exception_tables map
comment|///
comment|/// @param[in] F
comment|///     The function whose exception table is being written.
comment|///
comment|/// @param[in] TableStart
comment|///     The first byte of the exception table.
comment|///
comment|/// @param[in] TableEnd
comment|///     The last byte of the exception table.
comment|///
comment|/// @param[in] FrameRegister
comment|///     I don't know what this does, but it's passed through.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|endExceptionTable
argument_list|(
specifier|const
name|llvm
operator|::
name|Function
operator|*
name|F
argument_list|,
name|uint8_t
operator|*
name|TableStart
argument_list|,
name|uint8_t
operator|*
name|TableEnd
argument_list|,
name|uint8_t
operator|*
name|FrameRegister
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
name|deallocateExceptionTable
argument_list|(
name|void
operator|*
name|ET
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetDefaultCodeSlabSize
argument_list|()
block|{
return|return
name|m_default_mm_ap
operator|->
name|GetDefaultCodeSlabSize
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetDefaultDataSlabSize
argument_list|()
block|{
return|return
name|m_default_mm_ap
operator|->
name|GetDefaultDataSlabSize
argument_list|()
return|;
block|}
name|virtual
name|size_t
name|GetDefaultStubSlabSize
argument_list|()
block|{
return|return
name|m_default_mm_ap
operator|->
name|GetDefaultStubSlabSize
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|unsigned
name|GetNumCodeSlabs
argument_list|()
block|{
return|return
name|m_default_mm_ap
operator|->
name|GetNumCodeSlabs
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|unsigned
name|GetNumDataSlabs
argument_list|()
block|{
return|return
name|m_default_mm_ap
operator|->
name|GetNumDataSlabs
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|unsigned
name|GetNumStubSlabs
argument_list|()
block|{
return|return
name|m_default_mm_ap
operator|->
name|GetNumStubSlabs
argument_list|()
return|;
block|}
name|virtual
name|void
name|registerEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
block|{
return|return
name|m_default_mm_ap
operator|->
name|registerEHFrames
argument_list|(
name|llvm
operator|::
name|StringRef
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|Addr
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Passthrough interface stub
comment|//------------------------------------------------------------------
name|virtual
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
block|{
return|return
name|m_default_mm_ap
operator|->
name|getPointerToNamedFunction
argument_list|(
name|Name
argument_list|,
name|AbortOnFailure
argument_list|)
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|JITMemoryManager
operator|>
name|m_default_mm_ap
block|;
comment|///< The memory allocator to use in actually creating space.  All calls are passed through to it.
name|IRExecutionUnit
operator|&
name|m_parent
block|;
comment|///< The execution unit this is a proxy for.
block|}
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class JittedFunction IRExecutionUnit.h "lldb/Expression/IRExecutionUnit.h"
comment|/// @brief Encapsulates a single function that has been generated by the JIT.
comment|///
comment|/// Functions that have been generated by the JIT are first resident in the
comment|/// local process, and then placed in the target process.  JittedFunction
comment|/// represents a function possibly resident in both.
comment|//----------------------------------------------------------------------
struct|struct
name|JittedFunction
block|{
name|std
operator|::
name|string
name|m_name
expr_stmt|;
comment|///< The function's name
name|lldb
operator|::
name|addr_t
name|m_local_addr
expr_stmt|;
comment|///< The address of the function in LLDB's memory
name|lldb
operator|::
name|addr_t
name|m_remote_addr
expr_stmt|;
comment|///< The address of the function in the target's memory
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// Initializes class variabes.
comment|///
comment|/// @param[in] name
comment|///     The name of the function.
comment|///
comment|/// @param[in] local_addr
comment|///     The address of the function in LLDB, or LLDB_INVALID_ADDRESS if
comment|///     it is not present in LLDB's memory.
comment|///
comment|/// @param[in] remote_addr
comment|///     The address of the function in the target, or LLDB_INVALID_ADDRESS
comment|///     if it is not present in the target's memory.
comment|//------------------------------------------------------------------
name|JittedFunction
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::addr_t local_addr = LLDB_INVALID_ADDRESS
argument_list|,
argument|lldb::addr_t remote_addr = LLDB_INVALID_ADDRESS
argument_list|)
block|:
name|m_name
argument_list|(
name|name
argument_list|)
operator|,
name|m_local_addr
argument_list|(
name|local_addr
argument_list|)
operator|,
name|m_remote_addr
argument_list|(
argument|remote_addr
argument_list|)
block|{         }
block|}
struct|;
specifier|static
specifier|const
name|unsigned
name|eSectionIDInvalid
init|=
operator|(
name|unsigned
operator|)
operator|-
literal|1
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class AllocationRecord IRExecutionUnit.h "lldb/Expression/IRExecutionUnit.h"
comment|/// @brief Enacpsulates a single allocation request made by the JIT.
comment|///
comment|/// Allocations made by the JIT are first queued up and then applied in
comment|/// bulk to the underlying process.
comment|//----------------------------------------------------------------------
struct|struct
name|AllocationRecord
block|{
name|lldb
operator|::
name|addr_t
name|m_process_address
expr_stmt|;
name|uintptr_t
name|m_host_address
decl_stmt|;
name|uint32_t
name|m_permissions
decl_stmt|;
name|size_t
name|m_size
decl_stmt|;
name|unsigned
name|m_alignment
decl_stmt|;
name|unsigned
name|m_section_id
decl_stmt|;
name|AllocationRecord
argument_list|(
argument|uintptr_t host_address
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|size_t size
argument_list|,
argument|unsigned alignment
argument_list|,
argument|unsigned section_id = eSectionIDInvalid
argument_list|)
block|:
name|m_process_address
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|m_host_address
argument_list|(
name|host_address
argument_list|)
operator|,
name|m_permissions
argument_list|(
name|permissions
argument_list|)
operator|,
name|m_size
argument_list|(
name|size
argument_list|)
operator|,
name|m_alignment
argument_list|(
name|alignment
argument_list|)
operator|,
name|m_section_id
argument_list|(
argument|section_id
argument_list|)
block|{         }
name|void
name|dump
argument_list|(
name|Log
operator|*
name|log
argument_list|)
expr_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|AllocationRecord
operator|>
name|RecordVector
expr_stmt|;
name|RecordVector
name|m_records
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|LLVMContext
operator|>
name|m_context_ap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|ExecutionEngine
operator|>
name|m_execution_engine_ap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|m_module_ap
expr_stmt|;
comment|///< Holder for the module until it's been handed off
name|llvm
operator|::
name|Module
operator|*
name|m_module
expr_stmt|;
comment|///< Owned by the execution engine
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|m_cpu_features
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|JittedFunction
operator|,
literal|1
operator|>
name|m_jitted_functions
expr_stmt|;
comment|///< A vector of all functions that have been JITted into machine code
specifier|const
name|ConstString
name|m_name
decl_stmt|;
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_did_jit
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_function_load_addr
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_function_end_load_addr
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_IRExecutionUnit_h_
end_comment

end_unit

