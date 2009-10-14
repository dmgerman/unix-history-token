begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- MSP430.h - Top-level interface for MSP430 representation --*- C++ -*-==//
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
comment|// This file contains the entry points for global functions defined in
end_comment

begin_comment
comment|// the LLVM MSP430 backend.
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
name|LLVM_TARGET_MSP430_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_MSP430_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MSP430TargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createMSP430ISelDag
argument_list|(
name|MSP430TargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
specifier|extern
name|Target
name|TheMSP430Target
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for MSP430 registers.
end_comment

begin_comment
comment|// This defines a mapping from register name to register number.
end_comment

begin_include
include|#
directive|include
file|"MSP430GenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the MSP430 instructions.
end_comment

begin_include
include|#
directive|include
file|"MSP430GenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

