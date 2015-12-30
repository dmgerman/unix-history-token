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
name|BasicBlock
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MDNode
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
name|DenseMap
operator|<
name|unsigned
operator|,
name|int
operator|>
name|FixedStackObjectSlots
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|int
operator|>
name|StackObjectSlots
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|ConstantPoolSlots
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|JumpTableSlots
expr_stmt|;
block|}
struct|;
comment|/// Parse the machine basic block definitions, and skip the machine
comment|/// instructions.
comment|///
comment|/// This function runs the first parsing pass on the machine function's body.
comment|/// It parses only the machine basic block definitions and creates the machine
comment|/// basic blocks in the given machine function.
comment|///
comment|/// The machine instructions aren't parsed during the first pass because all
comment|/// the machine basic blocks aren't defined yet - this makes it impossible to
comment|/// resolve the machine basic block references.
comment|///
comment|/// Return true if an error occurred.
name|bool
name|parseMachineBasicBlockDefinitions
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|StringRef
name|Src
parameter_list|,
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
comment|/// Parse the machine instructions.
comment|///
comment|/// This function runs the second parsing pass on the machine function's body.
comment|/// It skips the machine basic block definitions and parses only the machine
comment|/// instructions and basic block attributes like liveins and successors.
comment|///
comment|/// The second parsing pass assumes that the first parsing pass already ran
comment|/// on the given source string.
comment|///
comment|/// Return true if an error occurred.
name|bool
name|parseMachineInstructions
parameter_list|(
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
name|bool
name|parseVirtualRegisterReference
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
name|bool
name|parseStackObjectReference
parameter_list|(
name|int
modifier|&
name|FI
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
name|parseMDNode
parameter_list|(
name|MDNode
modifier|*
modifier|&
name|Node
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

