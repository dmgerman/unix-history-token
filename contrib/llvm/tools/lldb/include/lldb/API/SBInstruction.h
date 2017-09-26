begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBInstruction.h -----------------------------------------*- C++ -*-===//
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
name|LLDB_SBInstruction_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBInstruction_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// There's a lot to be fixed here, but need to wait for underlying insn
end_comment

begin_comment
comment|// implementation
end_comment

begin_comment
comment|// to be revised& settle down first.
end_comment

begin_decl_stmt
name|class
name|InstructionImpl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBInstruction
block|{
name|public
label|:
name|SBInstruction
argument_list|()
expr_stmt|;
name|SBInstruction
argument_list|(
specifier|const
name|SBInstruction
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|SBInstruction
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBInstruction
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|SBInstruction
argument_list|()
expr_stmt|;
name|bool
name|IsValid
parameter_list|()
function_decl|;
name|SBAddress
name|GetAddress
parameter_list|()
function_decl|;
name|lldb
operator|::
name|AddressClass
name|GetAddressClass
argument_list|()
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetMnemonic
argument_list|(
name|lldb
operator|::
name|SBTarget
name|target
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetOperands
argument_list|(
name|lldb
operator|::
name|SBTarget
name|target
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetComment
argument_list|(
name|lldb
operator|::
name|SBTarget
name|target
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBData
name|GetData
argument_list|(
argument|lldb::SBTarget target
argument_list|)
expr_stmt|;
name|size_t
name|GetByteSize
parameter_list|()
function_decl|;
name|bool
name|DoesBranch
parameter_list|()
function_decl|;
name|bool
name|HasDelaySlot
parameter_list|()
function_decl|;
name|bool
name|CanSetBreakpoint
parameter_list|()
function_decl|;
name|void
name|Print
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|bool
name|EmulateWithFrame
argument_list|(
name|lldb
operator|::
name|SBFrame
operator|&
name|frame
argument_list|,
name|uint32_t
name|evaluate_options
argument_list|)
decl_stmt|;
name|bool
name|DumpEmulation
parameter_list|(
specifier|const
name|char
modifier|*
name|triple
parameter_list|)
function_decl|;
comment|// triple is to specify the
comment|// architecture, e.g. 'armv6' or
comment|// 'armv7-apple-ios'
name|bool
name|TestEmulation
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|output_stream
argument_list|,
specifier|const
name|char
operator|*
name|test_file
argument_list|)
decl_stmt|;
name|protected
label|:
name|friend
name|class
name|SBInstructionList
decl_stmt|;
name|SBInstruction
argument_list|(
specifier|const
name|lldb
operator|::
name|DisassemblerSP
operator|&
name|disasm_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|InstructionSP
operator|&
name|inst_sp
argument_list|)
expr_stmt|;
name|void
name|SetOpaque
argument_list|(
specifier|const
name|lldb
operator|::
name|DisassemblerSP
operator|&
name|disasm_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|InstructionSP
operator|&
name|inst_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|InstructionSP
name|GetOpaque
argument_list|()
expr_stmt|;
name|private
label|:
name|std
operator|::
name|shared_ptr
operator|<
name|InstructionImpl
operator|>
name|m_opaque_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBInstruction_h_
end_comment

end_unit

