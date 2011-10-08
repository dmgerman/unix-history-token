begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RegisterInfoEmitter.h - Generate a Register File Desc. ---*- C++ -*-===//
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
comment|// This tablegen backend is responsible for emitting a description of a target
end_comment

begin_comment
comment|// register file for a code generator.  It uses instances of the Register,
end_comment

begin_comment
comment|// RegisterAliases, and RegisterClass classes to gather this information.
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
name|REGISTER_INFO_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_INFO_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CodeGenRegBank
decl_stmt|;
name|class
name|CodeGenTarget
decl_stmt|;
name|class
name|RegisterInfoEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|public
operator|:
name|RegisterInfoEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
argument|R
argument_list|)
block|{}
comment|// runEnums - Print out enum values for all of the registers.
name|void
name|runEnums
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|CodeGenTarget
operator|&
name|Target
argument_list|,
name|CodeGenRegBank
operator|&
name|Bank
argument_list|)
block|;
comment|// runMCDesc - Print out MC register descriptions.
name|void
name|runMCDesc
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|CodeGenTarget
operator|&
name|Target
argument_list|,
name|CodeGenRegBank
operator|&
name|Bank
argument_list|)
block|;
comment|// runTargetHeader - Emit a header fragment for the register info emitter.
name|void
name|runTargetHeader
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|CodeGenTarget
operator|&
name|Target
argument_list|,
name|CodeGenRegBank
operator|&
name|Bank
argument_list|)
block|;
comment|// runTargetDesc - Output the target register and register file descriptions.
name|void
name|runTargetDesc
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|CodeGenTarget
operator|&
name|Target
argument_list|,
name|CodeGenRegBank
operator|&
name|Bank
argument_list|)
block|;
comment|// run - Output the register file description.
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

