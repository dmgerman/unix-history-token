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
name|liblldb_IRExecutionUnit_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IRExecutionUnit_h_
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
file|<memory>
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/SectionMemoryManager.h"
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
file|"lldb/Expression/IRMemoryMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataBufferHeap.h"
end_include

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
name|class
name|ObjectCache
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
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
comment|/// This class creates a subclass of LLVM's SectionMemoryManager, because that
comment|/// is
comment|/// how the JIT emits code.  Because LLDB needs to move JIT-compiled code
comment|/// into the target process, the IRExecutionUnit knows how to copy the
comment|/// emitted code into the target process.
comment|//----------------------------------------------------------------------
name|class
name|IRExecutionUnit
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|IRExecutionUnit
operator|>
decl_stmt|,
name|public
name|IRMemoryMap
decl_stmt|,
name|public
name|ObjectFileJITDelegate
block|{
name|public
label|:
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
specifier|const
name|SymbolContext
operator|&
name|sym_ctx
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
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|IRExecutionUnit
argument_list|()
name|override
expr_stmt|;
name|ConstString
name|GetFunctionName
parameter_list|()
block|{
return|return
name|m_name
return|;
block|}
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
return|return
operator|(
operator|(
name|m_module
operator|!=
name|nullptr
operator|)
operator|?
name|m_module
operator|->
name|getFunction
argument_list|(
name|m_name
operator|.
name|AsCString
argument_list|()
argument_list|)
operator|:
name|nullptr
operator|)
return|;
block|}
name|void
name|GetRunnableInfo
argument_list|(
name|Status
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
decl_stmt|;
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
argument|Status&error
argument_list|)
expr_stmt|;
name|void
name|FreeNow
argument_list|(
name|lldb
operator|::
name|addr_t
name|allocation
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// ObjectFileJITDelegate overrides
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
name|override
expr_stmt|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|PopulateSymtab
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|obj_file
argument_list|,
name|lldb_private
operator|::
name|Symtab
operator|&
name|symtab
argument_list|)
name|override
decl_stmt|;
name|void
name|PopulateSectionList
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|obj_file
argument_list|,
name|lldb_private
operator|::
name|SectionList
operator|&
name|section_list
argument_list|)
name|override
decl_stmt|;
name|bool
name|GetArchitecture
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
name|override
decl_stmt|;
name|lldb
operator|::
name|ModuleSP
name|GetJITModule
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|FindSymbol
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
expr_stmt|;
name|void
name|GetStaticInitializers
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
operator|&
name|static_initializers
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class JittedFunction IRExecutionUnit.h
comment|/// "lldb/Expression/IRExecutionUnit.h"
comment|/// @brief Encapsulates a single function that has been generated by the JIT.
comment|///
comment|/// Functions that have been generated by the JIT are first resident in the
comment|/// local process, and then placed in the target process.  JittedFunction
comment|/// represents a function possibly resident in both.
comment|//----------------------------------------------------------------------
struct|struct
name|JittedEntity
block|{
name|ConstString
name|m_name
decl_stmt|;
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
name|JittedEntity
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
block|{}
block|}
struct|;
name|struct
name|JittedFunction
range|:
name|JittedEntity
block|{
name|bool
name|m_external
block|;
name|JittedFunction
argument_list|(
argument|const char *name
argument_list|,
argument|bool external
argument_list|,
argument|lldb::addr_t local_addr = LLDB_INVALID_ADDRESS
argument_list|,
argument|lldb::addr_t remote_addr = LLDB_INVALID_ADDRESS
argument_list|)
operator|:
name|JittedEntity
argument_list|(
name|name
argument_list|,
name|local_addr
argument_list|,
name|remote_addr
argument_list|)
block|,
name|m_external
argument_list|(
argument|external
argument_list|)
block|{}
block|}
decl_stmt|;
name|struct
name|JittedGlobalVariable
range|:
name|JittedEntity
block|{
name|JittedGlobalVariable
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::addr_t local_addr = LLDB_INVALID_ADDRESS
argument_list|,
argument|lldb::addr_t remote_addr = LLDB_INVALID_ADDRESS
argument_list|)
operator|:
name|JittedEntity
argument_list|(
argument|name
argument_list|,
argument|local_addr
argument_list|,
argument|remote_addr
argument_list|)
block|{}
block|}
decl_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|JittedFunction
operator|>
operator|&
name|GetJittedFunctions
argument_list|()
block|{
return|return
name|m_jitted_functions
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|JittedGlobalVariable
operator|>
operator|&
name|GetJittedGlobalVariables
argument_list|()
block|{
return|return
name|m_jitted_global_variables
return|;
block|}
name|private
label|:
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
expr_stmt|;
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
name|lldb
operator|::
name|addr_t
name|local_address
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
name|Status
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
struct_decl|struct
name|SearchSpec
struct_decl|;
name|void
name|CollectCandidateCNames
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|C_specs
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
decl_stmt|;
name|void
name|CollectCandidateCPlusPlusNames
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|CPP_specs
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|C_specs
argument_list|,
specifier|const
name|SymbolContext
operator|&
name|sc
argument_list|)
decl_stmt|;
name|void
name|CollectFallbackNames
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|fallback_specs
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|C_specs
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|FindInSymbols
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|specs
argument_list|,
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|FindInRuntimes
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|specs
argument_list|,
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|FindInUserDefinedSymbols
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|SearchSpec
operator|>
operator|&
name|specs
argument_list|,
specifier|const
name|lldb_private
operator|::
name|SymbolContext
operator|&
name|sc
argument_list|)
expr_stmt|;
name|void
name|ReportSymbolLookupError
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|name
parameter_list|)
function_decl|;
name|class
name|MemoryManager
range|:
name|public
name|llvm
operator|::
name|SectionMemoryManager
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
operator|~
name|MemoryManager
argument_list|()
name|override
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
name|uint8_t
operator|*
name|allocateCodeSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|llvm::StringRef SectionName
argument_list|)
name|override
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
argument|llvm::StringRef SectionName
argument_list|,
argument|bool IsReadOnly
argument_list|)
name|override
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
name|finalizeMemory
argument_list|(
argument|std::string *ErrMsg
argument_list|)
name|override
block|{
comment|// TODO: Ensure that the instruction cache is flushed because
comment|// relocations are updated by dy-load.  See:
comment|//   sys::Memory::InvalidateInstructionCache
comment|//   llvm::SectionMemoryManager
return|return
name|false
return|;
block|}
name|void
name|registerEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|{}
name|uint64_t
name|getSymbolAddress
argument_list|(
argument|const std::string&Name
argument_list|)
name|override
block|;
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|SectionMemoryManager
operator|>
name|m_default_mm_ap
block|;
comment|///< The memory
comment|///allocator to use
comment|///in actually
comment|///creating space.
comment|///All calls are
comment|///passed through to
comment|///it.
name|IRExecutionUnit
operator|&
name|m_parent
block|;
comment|///< The execution unit this is a proxy for.
block|}
decl_stmt|;
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
comment|/// @class AllocationRecord IRExecutionUnit.h
comment|/// "lldb/Expression/IRExecutionUnit.h"
comment|/// @brief Encapsulates a single allocation request made by the JIT.
comment|///
comment|/// Allocations made by the JIT are first queued up and then applied in
comment|/// bulk to the underlying process.
comment|//----------------------------------------------------------------------
name|enum
name|class
name|AllocationKind
block|{
name|Stub
operator|,
name|Code
operator|,
name|Data
operator|,
name|Global
operator|,
name|Bytes
block|}
empty_stmt|;
specifier|static
name|lldb
operator|::
name|SectionType
name|GetSectionTypeFromSectionName
argument_list|(
argument|const llvm::StringRef&name
argument_list|,
argument|AllocationKind alloc_kind
argument_list|)
expr_stmt|;
struct|struct
name|AllocationRecord
block|{
name|std
operator|::
name|string
name|m_name
expr_stmt|;
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
name|lldb
operator|::
name|SectionType
name|m_sect_type
expr_stmt|;
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
argument|lldb::SectionType sect_type
argument_list|,
argument|size_t size
argument_list|,
argument|unsigned alignment
argument_list|,
argument|unsigned section_id
argument_list|,
argument|const char *name
argument_list|)
block|:
name|m_name
argument_list|()
operator|,
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
name|m_sect_type
argument_list|(
name|sect_type
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
block|{
if|if
condition|(
name|name
operator|&&
name|name
index|[
literal|0
index|]
condition|)
name|m_name
operator|=
name|name
expr_stmt|;
block|}
name|void
name|dump
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|)
function_decl|;
block|}
struct|;
name|bool
name|CommitOneAllocation
argument_list|(
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|,
name|Status
operator|&
name|error
argument_list|,
name|AllocationRecord
operator|&
name|record
argument_list|)
decl_stmt|;
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
name|ObjectCache
operator|>
name|m_object_cache_ap
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
name|std
operator|::
name|vector
operator|<
name|JittedFunction
operator|>
name|m_jitted_functions
expr_stmt|;
comment|///< A vector of all functions
comment|///that have been JITted into
comment|///machine code
name|std
operator|::
name|vector
operator|<
name|JittedGlobalVariable
operator|>
name|m_jitted_global_variables
expr_stmt|;
comment|///< A vector of
comment|///all functions
comment|///that have been
comment|///JITted into
comment|///machine code
specifier|const
name|ConstString
name|m_name
decl_stmt|;
name|SymbolContext
name|m_sym_ctx
decl_stmt|;
comment|///< Used for symbol lookups
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|m_failed_lookups
expr_stmt|;
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
name|bool
name|m_strip_underscore
decl_stmt|;
comment|///< True for platforms where global symbols have a _
comment|///prefix
name|bool
name|m_reported_allocations
decl_stmt|;
comment|///< True after allocations have been reported.
comment|///It is possible that
comment|///< sections will be allocated when this is true, in which case they weren't
comment|///< depended on by any function.  (Top-level code defining a variable, but
comment|///< defining no functions using that variable, would do this.)  If this
comment|///< is true, any allocations need to be committed immediately -- no
comment|///< opportunity for relocation.
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_IRExecutionUnit_h_
end_comment

end_unit

