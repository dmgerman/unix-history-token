begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86DisassemblerShared.h - Emitter shared header ----------*- C++ -*-===//
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
name|X86DISASSEMBLERSHARED_H
end_ifndef

begin_define
define|#
directive|define
name|X86DISASSEMBLERSHARED_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|INSTRUCTION_SPECIFIER_FIELDS
define|\
value|bool                    filtered;        \   InstructionContext      insnContext;     \   std::string             name;            \                                            \   InstructionSpecifier() {                 \     filtered = false;                      \     insnContext = IC;                      \     name = "";                             \     modifierType = MODIFIER_NONE;          \     modifierBase = 0;                      \     memset(operands, 0, sizeof(operands)); \   }
end_define

begin_define
define|#
directive|define
name|INSTRUCTION_IDS
define|\
value|InstrUID   instructionIDs[256];
end_define

begin_include
include|#
directive|include
file|"../../lib/Target/X86/Disassembler/X86DisassemblerDecoderCommon.h"
end_include

begin_undef
undef|#
directive|undef
name|INSTRUCTION_SPECIFIER_FIELDS
end_undef

begin_undef
undef|#
directive|undef
name|INSTRUCTION_IDS
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

