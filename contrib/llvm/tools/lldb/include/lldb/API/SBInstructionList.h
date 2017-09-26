begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBInstructionList.h -------------------------------------*- C++ -*-===//
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
name|LLDB_SBInstructionList_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBInstructionList_h_
end_define

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

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBInstructionList
block|{
name|public
label|:
name|SBInstructionList
argument_list|()
expr_stmt|;
name|SBInstructionList
argument_list|(
specifier|const
name|SBInstructionList
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|SBInstructionList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBInstructionList
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|SBInstructionList
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|size_t
name|GetSize
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBInstruction
name|GetInstructionAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
comment|// ----------------------------------------------------------------------
comment|// Returns the number of instructions between the start and end address.
comment|// If canSetBreakpoint is true then the count will be the number of
comment|// instructions on which a breakpoint can be set.
comment|// ----------------------------------------------------------------------
name|size_t
name|GetInstructionsCount
parameter_list|(
specifier|const
name|SBAddress
modifier|&
name|start
parameter_list|,
specifier|const
name|SBAddress
modifier|&
name|end
parameter_list|,
name|bool
name|canSetBreakpoint
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|AppendInstruction
argument_list|(
name|lldb
operator|::
name|SBInstruction
name|inst
argument_list|)
decl_stmt|;
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
name|DumpEmulationForAllInstructions
parameter_list|(
specifier|const
name|char
modifier|*
name|triple
parameter_list|)
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBFunction
decl_stmt|;
name|friend
name|class
name|SBSymbol
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|void
name|SetDisassembler
argument_list|(
specifier|const
name|lldb
operator|::
name|DisassemblerSP
operator|&
name|opaque_sp
argument_list|)
decl_stmt|;
name|private
label|:
name|lldb
operator|::
name|DisassemblerSP
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
comment|// LLDB_SBInstructionList_h_
end_comment

end_unit

