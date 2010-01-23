begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MachOWriter.h - Target-independent Mach-O writer support --*- C++ -*-===//
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
comment|// This file defines the MachOWriter class.
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
name|MACHOWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|MACHOWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

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
name|GlobalVariable
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
comment|/// MachOWriter - This class implements the common target-independent code for
comment|/// writing Mach-O files.  Targets should derive a class from this to
comment|/// parameterize the output format.
comment|///
name|class
name|MachOWriter
range|:
name|public
name|MachineFunctionPass
block|{
specifier|static
name|char
name|ID
block|;
name|protected
operator|:
comment|/// Output stream to send the resultant object file to.
comment|///
name|formatted_raw_ostream
operator|&
name|O
block|;
comment|/// Target machine description.
comment|///
name|TargetMachine
operator|&
name|TM
block|;
comment|/// Target Asm Printer information.
comment|///
specifier|const
name|MCAsmInfo
operator|*
name|MAI
block|;
comment|/// MCCE - The MCCodeEmitter object that we are exposing to emit machine
comment|/// code for functions to the .o file.
name|MCCodeEmitter
operator|*
name|MCCE
block|;
comment|/// OutContext - This is the context for the output file that we are
comment|/// streaming.  This owns all of the global MC-related objects for the
comment|/// generated translation unit.
name|MCContext
operator|&
name|OutContext
block|;
comment|/// OutStreamer - This is the MCStreamer object for the file we are
comment|/// generating.  This contains the transient state for the current
comment|/// translation unit that we are generating (such as the current section
comment|/// etc).
name|MCStreamer
operator|&
name|OutStreamer
block|;
comment|/// Name-mangler for global names.
comment|///
name|Mangler
operator|*
name|Mang
block|;
comment|/// doInitialization - Emit the file header and all of the global variables
comment|/// for the module to the Mach-O file.
name|bool
name|doInitialization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// doFinalization - Now that the module has been completely processed, emit
comment|/// the Mach-O file to 'O'.
name|bool
name|doFinalization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|public
operator|:
name|explicit
name|MachOWriter
argument_list|(
name|formatted_raw_ostream
operator|&
name|O
argument_list|,
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|T
argument_list|,
name|MCCodeEmitter
operator|*
name|MCE
argument_list|)
block|;
name|virtual
operator|~
name|MachOWriter
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Mach-O Writer"
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

