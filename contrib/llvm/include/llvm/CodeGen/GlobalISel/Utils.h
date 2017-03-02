begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/GlobalISel/Utils.h ---------------------------*- C++ -*-==//
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
comment|/// \file This file declares the API of helper functions used throughout the
end_comment

begin_comment
comment|/// GlobalISel pipeline.
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
name|LLVM_CODEGEN_GLOBALISEL_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_UTILS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MCInstrDesc
decl_stmt|;
name|class
name|RegisterBankInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// Try to constrain Reg so that it is usable by argument OpIdx of the
comment|/// provided MCInstrDesc \p II. If this fails, create a new virtual
comment|/// register in the correct class and insert a COPY before \p InsertPt.
comment|/// The debug location of \p InsertPt is used for the new copy.
comment|///
comment|/// \return The virtual register constrained to the right register class.
name|unsigned
name|constrainOperandRegClass
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|MF
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
parameter_list|,
specifier|const
name|RegisterBankInfo
modifier|&
name|RBI
parameter_list|,
name|MachineInstr
modifier|&
name|InsertPt
parameter_list|,
specifier|const
name|MCInstrDesc
modifier|&
name|II
parameter_list|,
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|OpIdx
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

