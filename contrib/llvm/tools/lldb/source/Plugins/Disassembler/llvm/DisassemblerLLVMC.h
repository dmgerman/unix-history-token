begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DisassemblerLLVMC.h -------------------------------------*- C++ -*-===//
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
name|liblldb_DisassemblerLLVMC_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DisassemblerLLVMC_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_comment
comment|// Opaque references to C++ Objects in LLVM's MC.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
block|}
end_decl_stmt

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginManager.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|class
name|InstructionLLVMC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DisassemblerLLVMC
range|:
name|public
name|lldb_private
operator|::
name|Disassembler
block|{
comment|// Since we need to make two actual MC Disassemblers for ARM (ARM& THUMB), and there's a bit of goo to set up and own
comment|// in the MC disassembler world, I added this class to manage the actual disassemblers.
name|class
name|LLVMCDisassembler
block|{
name|public
operator|:
name|LLVMCDisassembler
argument_list|(
argument|const char *triple
argument_list|,
argument|unsigned flavor
argument_list|,
argument|DisassemblerLLVMC&owner
argument_list|)
block|;
operator|~
name|LLVMCDisassembler
argument_list|()
block|;
name|uint64_t
name|GetMCInst
argument_list|(
argument|const uint8_t *opcode_data
argument_list|,
argument|size_t opcode_data_len
argument_list|,
argument|lldb::addr_t pc
argument_list|,
argument|llvm::MCInst&mc_inst
argument_list|)
block|;
name|uint64_t
name|PrintMCInst
argument_list|(
argument|llvm::MCInst&mc_inst
argument_list|,
argument|char *output_buffer
argument_list|,
argument|size_t out_buffer_len
argument_list|)
block|;
name|void
name|SetStyle
argument_list|(
argument|bool use_hex_immed
argument_list|,
argument|HexImmediateStyle hex_style
argument_list|)
block|;
name|bool
name|CanBranch
argument_list|(
name|llvm
operator|::
name|MCInst
operator|&
name|mc_inst
argument_list|)
block|;
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|m_is_valid
return|;
block|}
name|private
operator|:
name|bool
name|m_is_valid
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCContext
operator|>
name|m_context_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCAsmInfo
operator|>
name|m_asm_info_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCSubtargetInfo
operator|>
name|m_subtarget_info_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCInstrInfo
operator|>
name|m_instr_info_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCRegisterInfo
operator|>
name|m_reg_info_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCInstPrinter
operator|>
name|m_instr_printer_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MCDisassembler
operator|>
name|m_disasm_ap
block|;     }
block|;
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|Disassembler
operator|*
name|CreateInstance
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
specifier|const
name|char
operator|*
name|flavor
argument_list|)
block|;
name|DisassemblerLLVMC
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
specifier|const
name|char
operator|*
name|flavor
comment|/* = NULL */
argument_list|)
block|;
name|virtual
operator|~
name|DisassemblerLLVMC
argument_list|()
block|;
name|virtual
name|size_t
name|DecodeInstructions
argument_list|(
argument|const lldb_private::Address&base_addr
argument_list|,
argument|const lldb_private::DataExtractor& data
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|size_t num_instructions
argument_list|,
argument|bool append
argument_list|,
argument|bool data_from_file
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|protected
operator|:
name|friend
name|class
name|InstructionLLVMC
block|;
name|virtual
name|bool
name|FlavorValidForArchSpec
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
specifier|const
name|char
operator|*
name|flavor
argument_list|)
block|;
name|bool
name|IsValid
argument_list|()
block|{
return|return
operator|(
name|m_disasm_ap
operator|.
name|get
argument_list|()
operator|!=
name|NULL
operator|&&
name|m_disasm_ap
operator|->
name|IsValid
argument_list|()
operator|)
return|;
block|}
name|int
name|OpInfo
argument_list|(
argument|uint64_t PC
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Size
argument_list|,
argument|int TagType
argument_list|,
argument|void *TagBug
argument_list|)
block|;
specifier|const
name|char
operator|*
name|SymbolLookup
argument_list|(
argument|uint64_t ReferenceValue
argument_list|,
argument|uint64_t *ReferenceType
argument_list|,
argument|uint64_t ReferencePC
argument_list|,
argument|const char **ReferenceName
argument_list|)
block|;
specifier|static
name|int
name|OpInfoCallback
argument_list|(
argument|void *DisInfo
argument_list|,
argument|uint64_t PC
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t Size
argument_list|,
argument|int TagType
argument_list|,
argument|void *TagBug
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|SymbolLookupCallback
argument_list|(
argument|void *DisInfo
argument_list|,
argument|uint64_t ReferenceValue
argument_list|,
argument|uint64_t *ReferenceType
argument_list|,
argument|uint64_t ReferencePC
argument_list|,
argument|const char **ReferenceName
argument_list|)
block|;
name|void
name|Lock
argument_list|(
argument|InstructionLLVMC *inst
argument_list|,
argument|const lldb_private::ExecutionContext *exe_ctx
argument_list|)
block|{
name|m_mutex
operator|.
name|Lock
argument_list|()
block|;
name|m_inst
operator|=
name|inst
block|;
name|m_exe_ctx
operator|=
name|exe_ctx
block|;     }
name|void
name|Unlock
argument_list|()
block|{
name|m_inst
operator|=
name|NULL
block|;
name|m_exe_ctx
operator|=
name|NULL
block|;
name|m_mutex
operator|.
name|Unlock
argument_list|()
block|;     }
specifier|const
name|lldb_private
operator|::
name|ExecutionContext
operator|*
name|m_exe_ctx
block|;
name|InstructionLLVMC
operator|*
name|m_inst
block|;
name|lldb_private
operator|::
name|Mutex
name|m_mutex
block|;
name|bool
name|m_data_from_file
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|LLVMCDisassembler
operator|>
name|m_disasm_ap
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|LLVMCDisassembler
operator|>
name|m_alternate_disasm_ap
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DisassemblerLLVM_h_
end_comment

end_unit

