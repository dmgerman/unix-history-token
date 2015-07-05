begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MIParser.h - Machine Instructions Parser ---------------------------===//
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
comment|// This file declares the function that parses the machine instructions.
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
name|LLVM_LIB_CODEGEN_MIRPARSER_MIPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_MIRPARSER_MIPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
struct_decl|struct
name|SlotMapping
struct_decl|;
name|class
name|SMDiagnostic
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|bool
name|parseMachineInstr
argument_list|(
name|MachineInstr
operator|*
operator|&
name|MI
argument_list|,
name|SourceMgr
operator|&
name|SM
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
name|StringRef
name|Src
argument_list|,
specifier|const
name|DenseMap
operator|<
name|unsigned
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|MBBSlots
argument_list|,
specifier|const
name|SlotMapping
operator|&
name|IRSlots
argument_list|,
name|SMDiagnostic
operator|&
name|Error
argument_list|)
decl_stmt|;
name|bool
name|parseMBBReference
argument_list|(
name|MachineBasicBlock
operator|*
operator|&
name|MBB
argument_list|,
name|SourceMgr
operator|&
name|SM
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
name|StringRef
name|Src
argument_list|,
specifier|const
name|DenseMap
operator|<
name|unsigned
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|MBBSlots
argument_list|,
specifier|const
name|SlotMapping
operator|&
name|IRSlots
argument_list|,
name|SMDiagnostic
operator|&
name|Error
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

