begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- x86AssemblyInspectionEngine.h ---------------------------*- C++ -*-===//
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
name|liblldb_x86AssemblyInspectionEngine_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_x86AssemblyInspectionEngine_h_
end_define

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
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

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// x86AssemblyInspectionEngine - a class which will take a buffer of bytes
comment|// of i386/x86_64 instructions and create an UnwindPlan based on those
comment|// assembly instructions.
name|class
name|x86AssemblyInspectionEngine
block|{
name|public
label|:
comment|/// default ctor
name|x86AssemblyInspectionEngine
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
expr_stmt|;
comment|/// default dtor
operator|~
name|x86AssemblyInspectionEngine
argument_list|()
expr_stmt|;
comment|/// One of the two initialize methods that can be called on this object;
comment|/// they must be called before any of the assembly inspection methods
comment|/// are called.  This one should be used if the caller has access to a
comment|/// valid RegisterContext.
name|void
name|Initialize
argument_list|(
name|lldb
operator|::
name|RegisterContextSP
operator|&
name|reg_ctx
argument_list|)
decl_stmt|;
comment|/// One of the two initialize methods that can be called on this object;
comment|/// they must be called before any of the assembly inspection methods
comment|/// are called.  This one takes a vector of register name and lldb
comment|/// register numbers.
struct|struct
name|lldb_reg_info
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uint32_t
name|lldb_regnum
decl_stmt|;
name|lldb_reg_info
argument_list|()
operator|:
name|name
argument_list|(
name|nullptr
argument_list|)
operator|,
name|lldb_regnum
argument_list|(
argument|LLDB_INVALID_REGNUM
argument_list|)
block|{}
block|}
struct|;
name|void
name|Initialize
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb_reg_info
operator|>
operator|&
name|reg_info
argument_list|)
decl_stmt|;
comment|/// Create an UnwindPlan for a "non-call site" stack frame situation.
comment|/// This is usually when this function/method is currently executing, and may
comment|/// be at
comment|/// a location where exception-handling style unwind information (eh_frame,
comment|/// compact unwind info, arm unwind info)
comment|/// are not valid.
comment|/// \p data is a pointer to the instructions for the function
comment|/// \p size is the size of the instruction buffer above
comment|/// \p func_range is the start Address and size of the function, to be
comment|/// included in the UnwindPlan
comment|/// \p unwind_plan is the unwind plan that this method creates
comment|/// \returns true if it was able to create an UnwindPlan; false if not.
name|bool
name|GetNonCallSiteUnwindPlanFromAssembly
argument_list|(
name|uint8_t
operator|*
name|data
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb_private
operator|::
name|AddressRange
operator|&
name|func_range
argument_list|,
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
decl_stmt|;
comment|/// Take an existing UnwindPlan, probably from eh_frame which may be missing
comment|/// description
comment|/// of the epilogue instructions, and add the epilogue description to it based
comment|/// on the
comment|/// instructions in the function.
comment|///
comment|/// The \p unwind_plan 's register numbers must be converted into the lldb
comment|/// register numbering
comment|/// scheme OR a RegisterContext must be provided in \p reg_ctx.  If the \p
comment|/// unwind_plan
comment|/// register numbers are already in lldb register numbering, \p reg_ctx may be
comment|/// null.
comment|/// \returns true if the \p unwind_plan was updated, false if it was not.
name|bool
name|AugmentUnwindPlanFromCallSite
argument_list|(
name|uint8_t
operator|*
name|data
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb_private
operator|::
name|AddressRange
operator|&
name|func_range
argument_list|,
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|,
name|lldb
operator|::
name|RegisterContextSP
operator|&
name|reg_ctx
argument_list|)
decl_stmt|;
name|bool
name|FindFirstNonPrologueInstruction
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
modifier|&
name|offset
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|nonvolatile_reg_p
parameter_list|(
name|int
name|machine_regno
parameter_list|)
function_decl|;
name|bool
name|push_rbp_pattern_p
parameter_list|()
function_decl|;
name|bool
name|push_0_pattern_p
parameter_list|()
function_decl|;
name|bool
name|push_imm_pattern_p
parameter_list|()
function_decl|;
name|bool
name|push_extended_pattern_p
parameter_list|()
function_decl|;
name|bool
name|push_misc_reg_p
parameter_list|()
function_decl|;
name|bool
name|mov_rsp_rbp_pattern_p
parameter_list|()
function_decl|;
name|bool
name|sub_rsp_pattern_p
parameter_list|(
name|int
modifier|&
name|amount
parameter_list|)
function_decl|;
name|bool
name|add_rsp_pattern_p
parameter_list|(
name|int
modifier|&
name|amount
parameter_list|)
function_decl|;
name|bool
name|lea_rsp_pattern_p
parameter_list|(
name|int
modifier|&
name|amount
parameter_list|)
function_decl|;
name|bool
name|push_reg_p
parameter_list|(
name|int
modifier|&
name|regno
parameter_list|)
function_decl|;
name|bool
name|pop_reg_p
parameter_list|(
name|int
modifier|&
name|regno
parameter_list|)
function_decl|;
name|bool
name|pop_rbp_pattern_p
parameter_list|()
function_decl|;
name|bool
name|pop_misc_reg_p
parameter_list|()
function_decl|;
name|bool
name|leave_pattern_p
parameter_list|()
function_decl|;
name|bool
name|call_next_insn_pattern_p
parameter_list|()
function_decl|;
name|bool
name|mov_reg_to_local_stack_frame_p
parameter_list|(
name|int
modifier|&
name|regno
parameter_list|,
name|int
modifier|&
name|rbp_offset
parameter_list|)
function_decl|;
name|bool
name|ret_pattern_p
parameter_list|()
function_decl|;
name|uint32_t
name|extract_4
parameter_list|(
name|uint8_t
modifier|*
name|b
parameter_list|)
function_decl|;
name|bool
name|instruction_length
parameter_list|(
name|uint8_t
modifier|*
name|insn
parameter_list|,
name|int
modifier|&
name|length
parameter_list|)
function_decl|;
name|bool
name|machine_regno_to_lldb_regno
parameter_list|(
name|int
name|machine_regno
parameter_list|,
name|uint32_t
modifier|&
name|lldb_regno
parameter_list|)
function_decl|;
enum|enum
name|CPU
block|{
name|k_i386
block|,
name|k_x86_64
block|,
name|k_cpu_unspecified
block|}
enum|;
enum|enum
name|i386_register_numbers
block|{
name|k_machine_eax
init|=
literal|0
block|,
name|k_machine_ecx
init|=
literal|1
block|,
name|k_machine_edx
init|=
literal|2
block|,
name|k_machine_ebx
init|=
literal|3
block|,
name|k_machine_esp
init|=
literal|4
block|,
name|k_machine_ebp
init|=
literal|5
block|,
name|k_machine_esi
init|=
literal|6
block|,
name|k_machine_edi
init|=
literal|7
block|,
name|k_machine_eip
init|=
literal|8
block|}
enum|;
enum|enum
name|x86_64_register_numbers
block|{
name|k_machine_rax
init|=
literal|0
block|,
name|k_machine_rcx
init|=
literal|1
block|,
name|k_machine_rdx
init|=
literal|2
block|,
name|k_machine_rbx
init|=
literal|3
block|,
name|k_machine_rsp
init|=
literal|4
block|,
name|k_machine_rbp
init|=
literal|5
block|,
name|k_machine_rsi
init|=
literal|6
block|,
name|k_machine_rdi
init|=
literal|7
block|,
name|k_machine_r8
init|=
literal|8
block|,
name|k_machine_r9
init|=
literal|9
block|,
name|k_machine_r10
init|=
literal|10
block|,
name|k_machine_r11
init|=
literal|11
block|,
name|k_machine_r12
init|=
literal|12
block|,
name|k_machine_r13
init|=
literal|13
block|,
name|k_machine_r14
init|=
literal|14
block|,
name|k_machine_r15
init|=
literal|15
block|,
name|k_machine_rip
init|=
literal|16
block|}
enum|;
enum|enum
block|{
name|kMaxInstructionByteSize
init|=
literal|32
block|}
enum|;
name|uint8_t
modifier|*
name|m_cur_insn
decl_stmt|;
name|uint32_t
name|m_machine_ip_regnum
decl_stmt|;
name|uint32_t
name|m_machine_sp_regnum
decl_stmt|;
name|uint32_t
name|m_machine_fp_regnum
decl_stmt|;
name|uint32_t
name|m_lldb_ip_regnum
decl_stmt|;
name|uint32_t
name|m_lldb_sp_regnum
decl_stmt|;
name|uint32_t
name|m_lldb_fp_regnum
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|lldb_reg_info
operator|>
name|MachineRegnumToNameAndLLDBRegnum
expr_stmt|;
name|MachineRegnumToNameAndLLDBRegnum
name|m_reg_map
decl_stmt|;
name|lldb_private
operator|::
name|ArchSpec
name|m_arch
expr_stmt|;
name|CPU
name|m_cpu
decl_stmt|;
name|int
name|m_wordsize
decl_stmt|;
name|bool
name|m_register_map_initialized
decl_stmt|;
operator|::
name|LLVMDisasmContextRef
name|m_disasm_context
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|x86AssemblyInspectionEngine
argument_list|)
expr_stmt|;
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
comment|// liblldb_x86AssemblyInspectionEngine_h_
end_comment

end_unit

