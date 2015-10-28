begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MIRPrinter.h - MIR serialization format printer --------------------===//
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
comment|// This file declares the functions that print out the LLVM IR and the machine
end_comment

begin_comment
comment|// functions using the MIR serialization format.
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
name|LLVM_LIB_CODEGEN_MIRPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_MIRPRINTER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Print LLVM IR using the MIR serialization format to the given output stream.
name|void
name|printMIR
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// Print a machine function using the MIR serialization format to the given
comment|/// output stream.
name|void
name|printMIR
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|MachineFunction
modifier|&
name|MF
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

