begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonAsmPrinter.h - Print machine code to an Hexagon .s file ----===//
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
comment|// Hexagon Assembly printer class.
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
name|HEXAGONASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"Hexagon.h"
end_include

begin_include
include|#
directive|include
file|"HexagonTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
specifier|const
name|HexagonSubtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|HexagonAsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
operator|:
name|AsmPrinter
argument_list|(
argument|TM
argument_list|,
argument|Streamer
argument_list|)
block|{
name|Subtarget
operator|=
operator|&
name|TM
operator|.
name|getSubtarget
operator|<
name|HexagonSubtarget
operator|>
operator|(
operator|)
block|;     }
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Hexagon Assembly Printer"
return|;
block|}
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
name|void
name|EmitInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
name|void
name|printOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&OS
argument_list|)
name|override
block|;
name|bool
name|PrintAsmMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&OS
argument_list|)
name|override
block|;
specifier|static
specifier|const
name|char
operator|*
name|getRegisterName
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end of llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

