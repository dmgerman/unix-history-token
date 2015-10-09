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
struct|struct
name|PerFunctionMIParsingState
block|{
name|DenseMap
operator|<
name|unsigned
operator|,
name|MachineBasicBlock
operator|*
operator|>
name|MBBSlots
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|VirtualRegisterSlots
expr_stmt|;
block|}
struct|;
name|bool
name|parseMachineInstr
parameter_list|(
name|MachineInstr
modifier|*
modifier|&
name|MI
parameter_list|,
name|SourceMgr
modifier|&
name|SM
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|StringRef
name|Src
parameter_list|,
specifier|const
name|PerFunctionMIParsingState
modifier|&
name|PFS
parameter_list|,
specifier|const
name|SlotMapping
modifier|&
name|IRSlots
parameter_list|,
name|SMDiagnostic
modifier|&
name|Error
parameter_list|)
function_decl|;
name|bool
name|parseMBBReference
parameter_list|(
name|MachineBasicBlock
modifier|*
modifier|&
name|MBB
parameter_list|,
name|SourceMgr
modifier|&
name|SM
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|StringRef
name|Src
parameter_list|,
specifier|const
name|PerFunctionMIParsingState
modifier|&
name|PFS
parameter_list|,
specifier|const
name|SlotMapping
modifier|&
name|IRSlots
parameter_list|,
name|SMDiagnostic
modifier|&
name|Error
parameter_list|)
function_decl|;
name|bool
name|parseNamedRegisterReference
parameter_list|(
name|unsigned
modifier|&
name|Reg
parameter_list|,
name|SourceMgr
modifier|&
name|SM
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|StringRef
name|Src
parameter_list|,
specifier|const
name|PerFunctionMIParsingState
modifier|&
name|PFS
parameter_list|,
specifier|const
name|SlotMapping
modifier|&
name|IRSlots
parameter_list|,
name|SMDiagnostic
modifier|&
name|Error
parameter_list|)
function_decl|;
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

