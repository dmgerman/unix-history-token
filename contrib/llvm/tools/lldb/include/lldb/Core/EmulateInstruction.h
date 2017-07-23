begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EmulateInstruction.h ------------------------------------*- C++ -*-===//
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
name|lldb_EmulateInstruction_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_EmulateInstruction_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Opcode.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_comment
comment|// for Address
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for RegisterKind, ByteOrder
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for InstructionType
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-types.h"
end_include

begin_comment
comment|// for RegisterInfo
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t, uint64_t, int64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|OptionValueDictionary
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RegisterContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RegisterValue
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Target
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|UnwindPlan
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class EmulateInstruction EmulateInstruction.h
comment|/// "lldb/Core/EmulateInstruction.h"
comment|/// @brief A class that allows emulation of CPU opcodes.
comment|///
comment|/// This class is a plug-in interface that is accessed through the
comment|/// standard static FindPlugin function call in the EmulateInstruction
comment|/// class. The FindPlugin takes a target triple and returns a new object
comment|/// if there is a plug-in that supports the architecture and OS. Four
comment|/// callbacks and a baton are provided. The four callbacks are read
comment|/// register, write register, read memory and write memory.
comment|///
comment|/// This class is currently designed for these main use cases:
comment|/// - Auto generation of Call Frame Information (CFI) from assembly code
comment|/// - Predicting single step breakpoint locations
comment|/// - Emulating instructions for breakpoint traps
comment|///
comment|/// Objects can be asked to read an instruction which will cause a call
comment|/// to the read register callback to get the PC, followed by a read
comment|/// memory call to read the opcode. If ReadInstruction () returns true,
comment|/// then a call to EmulateInstruction::EvaluateInstruction () can be
comment|/// made. At this point the EmulateInstruction subclass will use all of
comment|/// the callbacks to emulate an instruction.
comment|///
comment|/// Clients that provide the callbacks can either do the read/write
comment|/// registers/memory to actually emulate the instruction on a real or
comment|/// virtual CPU, or watch for the EmulateInstruction::Context which
comment|/// is context for the read/write register/memory which explains why
comment|/// the callback is being called. Examples of a context are:
comment|/// "pushing register 3 onto the stack at offset -12", or "adjusting
comment|/// stack pointer by -16". This extra context allows the generation of
comment|/// CFI information from assembly code without having to actually do
comment|/// the read/write register/memory.
comment|///
comment|/// Clients must be prepared that not all instructions for an
comment|/// Instruction Set Architecture (ISA) will be emulated.
comment|///
comment|/// Subclasses at the very least should implement the instructions that
comment|/// save and restore registers onto the stack and adjustment to the stack
comment|/// pointer. By just implementing a few instructions for an ISA that are
comment|/// the typical prologue opcodes, you can then generate CFI using a
comment|/// class that will soon be available.
comment|///
comment|/// Implementing all of the instructions that affect the PC can then
comment|/// allow single step prediction support.
comment|///
comment|/// Implementing all of the instructions allows for emulation of opcodes
comment|/// for breakpoint traps and will pave the way for "thread centric"
comment|/// debugging. The current debugging model is "process centric" where
comment|/// all threads must be stopped when any thread is stopped; when
comment|/// hitting software breakpoints we must disable the breakpoint by
comment|/// restoring the original breakpoint opcode, single stepping and
comment|/// restoring the breakpoint trap. If all threads were allowed to run
comment|/// then other threads could miss the breakpoint.
comment|///
comment|/// This class centralizes the code that usually is done in separate
comment|/// code paths in a debugger (single step prediction, finding save
comment|/// restore locations of registers for unwinding stack frame variables)
comment|/// and emulating the instruction is just a bonus.
comment|//----------------------------------------------------------------------
name|class
name|EmulateInstruction
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
specifier|static
name|EmulateInstruction
operator|*
name|FindPlugin
argument_list|(
argument|const ArchSpec&arch
argument_list|,
argument|InstructionType supported_inst_type
argument_list|,
argument|const char *plugin_name
argument_list|)
block|;    enum
name|ContextType
block|{
name|eContextInvalid
operator|=
literal|0
block|,
comment|// Read an instruction opcode from memory
name|eContextReadOpcode
block|,
comment|// Usually used for writing a register value whose source value is an
comment|// immediate
name|eContextImmediate
block|,
comment|// Exclusively used when saving a register to the stack as part of the
comment|// prologue
name|eContextPushRegisterOnStack
block|,
comment|// Exclusively used when restoring a register off the stack as part of
comment|// the epilogue
name|eContextPopRegisterOffStack
block|,
comment|// Add or subtract a value from the stack
name|eContextAdjustStackPointer
block|,
comment|// Adjust the frame pointer for the current frame
name|eContextSetFramePointer
block|,
comment|// Typically in an epilogue sequence.  Copy the frame pointer back
comment|// into the stack pointer, use SP for CFA calculations again.
name|eContextRestoreStackPointer
block|,
comment|// Add or subtract a value from a base address register (other than SP)
name|eContextAdjustBaseRegister
block|,
comment|// Add or subtract a value from the PC or store a value to the PC.
name|eContextAdjustPC
block|,
comment|// Used in WriteRegister callbacks to indicate where the
name|eContextRegisterPlusOffset
block|,
comment|// Used in WriteMemory callback to indicate where the data came from
name|eContextRegisterStore
block|,
name|eContextRegisterLoad
block|,
comment|// Used when performing a PC-relative branch where the
name|eContextRelativeBranchImmediate
block|,
comment|// Used when performing an absolute branch where the
name|eContextAbsoluteBranchRegister
block|,
comment|// Used when performing a supervisor call to an operating system to
comment|// provide a service:
name|eContextSupervisorCall
block|,
comment|// Used when performing a MemU operation to read the PC-relative offset
comment|// from an address.
name|eContextTableBranchReadMemory
block|,
comment|// Used when random bits are written into a register
name|eContextWriteRegisterRandomBits
block|,
comment|// Used when random bits are written to memory
name|eContextWriteMemoryRandomBits
block|,
name|eContextArithmetic
block|,
name|eContextAdvancePC
block|,
name|eContextReturnFromException
block|}
block|;    enum
name|InfoType
block|{
name|eInfoTypeRegisterPlusOffset
block|,
name|eInfoTypeRegisterPlusIndirectOffset
block|,
name|eInfoTypeRegisterToRegisterPlusOffset
block|,
name|eInfoTypeRegisterToRegisterPlusIndirectOffset
block|,
name|eInfoTypeRegisterRegisterOperands
block|,
name|eInfoTypeOffset
block|,
name|eInfoTypeRegister
block|,
name|eInfoTypeImmediate
block|,
name|eInfoTypeImmediateSigned
block|,
name|eInfoTypeAddress
block|,
name|eInfoTypeISAAndImmediate
block|,
name|eInfoTypeISAAndImmediateSigned
block|,
name|eInfoTypeISA
block|,
name|eInfoTypeNoArgs
block|}
name|InfoType
block|;    struct
name|Context
block|{
name|ContextType
name|type
block|;     enum
name|InfoType
name|info_type
block|;
expr|union
block|{       struct
name|RegisterPlusOffset
block|{
name|RegisterInfo
name|reg
block|;
comment|// base register
name|int64_t
name|signed_offset
block|;
comment|// signed offset added to base register
block|}
name|RegisterPlusOffset
block|;        struct
name|RegisterPlusIndirectOffset
block|{
name|RegisterInfo
name|base_reg
block|;
comment|// base register number
name|RegisterInfo
name|offset_reg
block|;
comment|// offset register kind
block|}
name|RegisterPlusIndirectOffset
block|;        struct
name|RegisterToRegisterPlusOffset
block|{
name|RegisterInfo
name|data_reg
block|;
comment|// source/target register for data
name|RegisterInfo
name|base_reg
block|;
comment|// base register for address calculation
name|int64_t
name|offset
block|;
comment|// offset for address calculation
block|}
name|RegisterToRegisterPlusOffset
block|;        struct
name|RegisterToRegisterPlusIndirectOffset
block|{
name|RegisterInfo
name|base_reg
block|;
comment|// base register for address calculation
name|RegisterInfo
name|offset_reg
block|;
comment|// offset register for address calculation
name|RegisterInfo
name|data_reg
block|;
comment|// source/target register for data
block|}
name|RegisterToRegisterPlusIndirectOffset
block|;        struct
name|RegisterRegisterOperands
block|{
name|RegisterInfo
name|operand1
block|;
comment|// register containing first operand for binary op
name|RegisterInfo
name|operand2
block|;
comment|// register containing second operand for binary op
block|}
name|RegisterRegisterOperands
block|;
name|int64_t
name|signed_offset
block|;
comment|// signed offset by which to adjust self (for
comment|// registers only)
name|RegisterInfo
name|reg
block|;
comment|// plain register
name|uint64_t
name|unsigned_immediate
block|;
comment|// unsigned immediate value
name|int64_t
name|signed_immediate
block|;
comment|// signed immediate value
name|lldb
operator|::
name|addr_t
name|address
block|;
comment|// direct address
block|struct
name|ISAAndImmediate
block|{
name|uint32_t
name|isa
block|;
name|uint32_t
name|unsigned_data32
block|;
comment|// immediate data
block|}
name|ISAAndImmediate
block|;        struct
name|ISAAndImmediateSigned
block|{
name|uint32_t
name|isa
block|;
name|int32_t
name|signed_data32
block|;
comment|// signed immediate data
block|}
name|ISAAndImmediateSigned
block|;
name|uint32_t
name|isa
block|;     }
name|info
block|;
name|Context
argument_list|()
operator|:
name|type
argument_list|(
name|eContextInvalid
argument_list|)
block|,
name|info_type
argument_list|(
argument|eInfoTypeNoArgs
argument_list|)
block|{}
name|void
name|SetRegisterPlusOffset
argument_list|(
argument|RegisterInfo base_reg
argument_list|,
argument|int64_t signed_offset
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeRegisterPlusOffset
block|;
name|info
operator|.
name|RegisterPlusOffset
operator|.
name|reg
operator|=
name|base_reg
block|;
name|info
operator|.
name|RegisterPlusOffset
operator|.
name|signed_offset
operator|=
name|signed_offset
block|;     }
name|void
name|SetRegisterPlusIndirectOffset
argument_list|(
argument|RegisterInfo base_reg
argument_list|,
argument|RegisterInfo offset_reg
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeRegisterPlusIndirectOffset
block|;
name|info
operator|.
name|RegisterPlusIndirectOffset
operator|.
name|base_reg
operator|=
name|base_reg
block|;
name|info
operator|.
name|RegisterPlusIndirectOffset
operator|.
name|offset_reg
operator|=
name|offset_reg
block|;     }
name|void
name|SetRegisterToRegisterPlusOffset
argument_list|(
argument|RegisterInfo data_reg
argument_list|,
argument|RegisterInfo base_reg
argument_list|,
argument|int64_t offset
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeRegisterToRegisterPlusOffset
block|;
name|info
operator|.
name|RegisterToRegisterPlusOffset
operator|.
name|data_reg
operator|=
name|data_reg
block|;
name|info
operator|.
name|RegisterToRegisterPlusOffset
operator|.
name|base_reg
operator|=
name|base_reg
block|;
name|info
operator|.
name|RegisterToRegisterPlusOffset
operator|.
name|offset
operator|=
name|offset
block|;     }
name|void
name|SetRegisterToRegisterPlusIndirectOffset
argument_list|(
argument|RegisterInfo base_reg
argument_list|,
argument|RegisterInfo offset_reg
argument_list|,
argument|RegisterInfo data_reg
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeRegisterToRegisterPlusIndirectOffset
block|;
name|info
operator|.
name|RegisterToRegisterPlusIndirectOffset
operator|.
name|base_reg
operator|=
name|base_reg
block|;
name|info
operator|.
name|RegisterToRegisterPlusIndirectOffset
operator|.
name|offset_reg
operator|=
name|offset_reg
block|;
name|info
operator|.
name|RegisterToRegisterPlusIndirectOffset
operator|.
name|data_reg
operator|=
name|data_reg
block|;     }
name|void
name|SetRegisterRegisterOperands
argument_list|(
argument|RegisterInfo op1_reg
argument_list|,
argument|RegisterInfo op2_reg
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeRegisterRegisterOperands
block|;
name|info
operator|.
name|RegisterRegisterOperands
operator|.
name|operand1
operator|=
name|op1_reg
block|;
name|info
operator|.
name|RegisterRegisterOperands
operator|.
name|operand2
operator|=
name|op2_reg
block|;     }
name|void
name|SetOffset
argument_list|(
argument|int64_t signed_offset
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeOffset
block|;
name|info
operator|.
name|signed_offset
operator|=
name|signed_offset
block|;     }
name|void
name|SetRegister
argument_list|(
argument|RegisterInfo reg
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeRegister
block|;
name|info
operator|.
name|reg
operator|=
name|reg
block|;     }
name|void
name|SetImmediate
argument_list|(
argument|uint64_t immediate
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeImmediate
block|;
name|info
operator|.
name|unsigned_immediate
operator|=
name|immediate
block|;     }
name|void
name|SetImmediateSigned
argument_list|(
argument|int64_t signed_immediate
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeImmediateSigned
block|;
name|info
operator|.
name|signed_immediate
operator|=
name|signed_immediate
block|;     }
name|void
name|SetAddress
argument_list|(
argument|lldb::addr_t address
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeAddress
block|;
name|info
operator|.
name|address
operator|=
name|address
block|;     }
name|void
name|SetISAAndImmediate
argument_list|(
argument|uint32_t isa
argument_list|,
argument|uint32_t data
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeISAAndImmediate
block|;
name|info
operator|.
name|ISAAndImmediate
operator|.
name|isa
operator|=
name|isa
block|;
name|info
operator|.
name|ISAAndImmediate
operator|.
name|unsigned_data32
operator|=
name|data
block|;     }
name|void
name|SetISAAndImmediateSigned
argument_list|(
argument|uint32_t isa
argument_list|,
argument|int32_t data
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeISAAndImmediateSigned
block|;
name|info
operator|.
name|ISAAndImmediateSigned
operator|.
name|isa
operator|=
name|isa
block|;
name|info
operator|.
name|ISAAndImmediateSigned
operator|.
name|signed_data32
operator|=
name|data
block|;     }
name|void
name|SetISA
argument_list|(
argument|uint32_t isa
argument_list|)
block|{
name|info_type
operator|=
name|eInfoTypeISA
block|;
name|info
operator|.
name|isa
operator|=
name|isa
block|;     }
name|void
name|SetNoArgs
argument_list|()
block|{
name|info_type
operator|=
name|eInfoTypeNoArgs
block|; }
name|void
name|Dump
argument_list|(
argument|Stream&s
argument_list|,
argument|EmulateInstruction *instruction
argument_list|)
specifier|const
block|;   }
block|;
typedef|typedef
name|size_t
argument_list|(
argument|*ReadMemoryCallback
argument_list|)
operator|(
name|EmulateInstruction
operator|*
name|instruction
expr|,
name|void
operator|*
name|baton
expr|,
specifier|const
name|Context
operator|&
name|context
expr|,
name|lldb
operator|::
name|addr_t
name|addr
expr|,
name|void
operator|*
name|dst
expr|,
name|size_t
name|length
operator|)
expr_stmt|;
typedef|typedef
name|size_t
argument_list|(
argument|*WriteMemoryCallback
argument_list|)
operator|(
name|EmulateInstruction
operator|*
name|instruction
operator|,
name|void
operator|*
name|baton
operator|,
specifier|const
name|Context
operator|&
name|context
operator|,
name|lldb
operator|::
name|addr_t
name|addr
operator|,
specifier|const
name|void
operator|*
name|dst
operator|,
name|size_t
name|length
operator|)
expr_stmt|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|ReadRegisterCallback
function_decl|)
parameter_list|(
name|EmulateInstruction
modifier|*
name|instruction
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|WriteRegisterCallback
function_decl|)
parameter_list|(
name|EmulateInstruction
modifier|*
name|instruction
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|Context
modifier|&
name|context
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
specifier|const
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
comment|// Type to represent the condition of an instruction. The UINT32 value is
comment|// reserved for the
comment|// unconditional case and all other value can be used in an architecture
comment|// dependent way.
typedef|typedef
name|uint32_t
name|InstructionCondition
typedef|;
specifier|static
specifier|const
name|InstructionCondition
name|UnconditionalCondition
init|=
name|UINT32_MAX
decl_stmt|;
name|EmulateInstruction
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
operator|~
name|EmulateInstruction
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Mandatory overrides
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|SupportsEmulatingInstructionsOfType
parameter_list|(
name|InstructionType
name|inst_type
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|SetTargetTriple
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|arch
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|ReadInstruction
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|EvaluateInstruction
parameter_list|(
name|uint32_t
name|evaluate_options
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|InstructionCondition
name|GetInstructionCondition
parameter_list|()
block|{
return|return
name|UnconditionalCondition
return|;
block|}
name|virtual
name|bool
name|TestEmulation
parameter_list|(
name|Stream
modifier|*
name|out_stream
parameter_list|,
name|ArchSpec
modifier|&
name|arch
parameter_list|,
name|OptionValueDictionary
modifier|*
name|test_data
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|GetRegisterInfo
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|,
name|RegisterInfo
operator|&
name|reg_info
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// Optional overrides
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|SetInstruction
parameter_list|(
specifier|const
name|Opcode
modifier|&
name|insn_opcode
parameter_list|,
specifier|const
name|Address
modifier|&
name|inst_addr
parameter_list|,
name|Target
modifier|*
name|target
parameter_list|)
function_decl|;
name|virtual
name|bool
name|CreateFunctionEntryUnwind
parameter_list|(
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|TranslateRegister
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|,
name|std
operator|::
name|string
operator|&
name|reg_name
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// RegisterInfo variants
comment|//----------------------------------------------------------------------
name|bool
name|ReadRegister
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
name|uint64_t
name|ReadRegisterUnsigned
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|uint64_t
name|fail_value
parameter_list|,
name|bool
modifier|*
name|success_ptr
parameter_list|)
function_decl|;
name|bool
name|WriteRegister
parameter_list|(
specifier|const
name|Context
modifier|&
name|context
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|ref_info
parameter_list|,
specifier|const
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
name|bool
name|WriteRegisterUnsigned
parameter_list|(
specifier|const
name|Context
modifier|&
name|context
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|uint64_t
name|reg_value
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|// Register kind and number variants
comment|//----------------------------------------------------------------------
name|bool
name|ReadRegister
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|,
name|RegisterValue
operator|&
name|reg_value
argument_list|)
decl_stmt|;
name|bool
name|WriteRegister
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|,
specifier|const
name|RegisterValue
operator|&
name|reg_value
argument_list|)
decl_stmt|;
name|uint64_t
name|ReadRegisterUnsigned
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|,
name|uint64_t
name|fail_value
argument_list|,
name|bool
operator|*
name|success_ptr
argument_list|)
decl_stmt|;
name|bool
name|WriteRegisterUnsigned
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|,
name|uint64_t
name|reg_value
argument_list|)
decl_stmt|;
name|size_t
name|ReadMemory
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|)
decl_stmt|;
name|uint64_t
name|ReadMemoryUnsigned
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|byte_size
argument_list|,
name|uint64_t
name|fail_value
argument_list|,
name|bool
operator|*
name|success_ptr
argument_list|)
decl_stmt|;
name|bool
name|WriteMemory
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|size_t
name|src_len
argument_list|)
decl_stmt|;
name|bool
name|WriteMemoryUnsigned
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|uint64_t
name|uval
argument_list|,
name|size_t
name|uval_byte_size
argument_list|)
decl_stmt|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_arch
operator|.
name|GetAddressByteSize
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
block|{
return|return
name|m_arch
operator|.
name|GetByteOrder
argument_list|()
return|;
block|}
specifier|const
name|Opcode
operator|&
name|GetOpcode
argument_list|()
specifier|const
block|{
return|return
name|m_opcode
return|;
block|}
name|lldb
operator|::
name|addr_t
name|GetAddress
argument_list|()
specifier|const
block|{
return|return
name|m_addr
return|;
block|}
specifier|const
name|ArchSpec
operator|&
name|GetArchitecture
argument_list|()
specifier|const
block|{
return|return
name|m_arch
return|;
block|}
specifier|static
name|size_t
name|ReadMemoryFrame
argument_list|(
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
name|void
operator|*
name|baton
argument_list|,
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|length
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|WriteMemoryFrame
argument_list|(
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
name|void
operator|*
name|baton
argument_list|,
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
specifier|const
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|length
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|ReadRegisterFrame
parameter_list|(
name|EmulateInstruction
modifier|*
name|instruction
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
specifier|static
name|bool
name|WriteRegisterFrame
parameter_list|(
name|EmulateInstruction
modifier|*
name|instruction
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|Context
modifier|&
name|context
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
specifier|const
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
specifier|static
name|size_t
name|ReadMemoryDefault
argument_list|(
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
name|void
operator|*
name|baton
argument_list|,
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|length
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|WriteMemoryDefault
argument_list|(
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
name|void
operator|*
name|baton
argument_list|,
specifier|const
name|Context
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
specifier|const
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|length
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|ReadRegisterDefault
parameter_list|(
name|EmulateInstruction
modifier|*
name|instruction
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
specifier|static
name|bool
name|WriteRegisterDefault
parameter_list|(
name|EmulateInstruction
modifier|*
name|instruction
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|Context
modifier|&
name|context
parameter_list|,
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
specifier|const
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
function_decl|;
name|void
name|SetBaton
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|void
name|SetCallbacks
parameter_list|(
name|ReadMemoryCallback
name|read_mem_callback
parameter_list|,
name|WriteMemoryCallback
name|write_mem_callback
parameter_list|,
name|ReadRegisterCallback
name|read_reg_callback
parameter_list|,
name|WriteRegisterCallback
name|write_reg_callback
parameter_list|)
function_decl|;
name|void
name|SetReadMemCallback
parameter_list|(
name|ReadMemoryCallback
name|read_mem_callback
parameter_list|)
function_decl|;
name|void
name|SetWriteMemCallback
parameter_list|(
name|WriteMemoryCallback
name|write_mem_callback
parameter_list|)
function_decl|;
name|void
name|SetReadRegCallback
parameter_list|(
name|ReadRegisterCallback
name|read_reg_callback
parameter_list|)
function_decl|;
name|void
name|SetWriteRegCallback
parameter_list|(
name|WriteRegisterCallback
name|write_reg_callback
parameter_list|)
function_decl|;
specifier|static
name|bool
name|GetBestRegisterKindAndNumber
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb
operator|::
name|RegisterKind
operator|&
name|reg_kind
argument_list|,
name|uint32_t
operator|&
name|reg_num
argument_list|)
decl_stmt|;
specifier|static
name|uint32_t
name|GetInternalRegisterNumber
parameter_list|(
name|RegisterContext
modifier|*
name|reg_ctx
parameter_list|,
specifier|const
name|RegisterInfo
modifier|&
name|reg_info
parameter_list|)
function_decl|;
name|protected
label|:
name|ArchSpec
name|m_arch
decl_stmt|;
name|void
modifier|*
name|m_baton
decl_stmt|;
name|ReadMemoryCallback
name|m_read_mem_callback
decl_stmt|;
name|WriteMemoryCallback
name|m_write_mem_callback
decl_stmt|;
name|ReadRegisterCallback
name|m_read_reg_callback
decl_stmt|;
name|WriteRegisterCallback
name|m_write_reg_callback
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|m_addr
expr_stmt|;
name|Opcode
name|m_opcode
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For EmulateInstruction only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|EmulateInstruction
argument_list|)
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
comment|// lldb_EmulateInstruction_h_
end_comment

end_unit

