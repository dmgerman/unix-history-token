begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86ModRMFilters.h - Disassembler ModR/M filterss ---------*- C++ -*-===//
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
comment|// This file is part of the X86 Disassembler Emitter.
end_comment

begin_comment
comment|// It contains ModR/M filters that determine which values of the ModR/M byte
end_comment

begin_comment
comment|//  are valid for a partiuclar instruction.
end_comment

begin_comment
comment|// Documentation for the disassembler emitter in general can be found in
end_comment

begin_comment
comment|//  X86DisasemblerEmitter.h.
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
name|X86MODRMFILTERS_H
end_ifndef

begin_define
define|#
directive|define
name|X86MODRMFILTERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86Disassembler
block|{
comment|/// ModRMFilter - Abstract base class for clases that recognize patterns in
comment|///   ModR/M bytes.
name|class
name|ModRMFilter
block|{
name|public
label|:
comment|/// Destructor    - Override as necessary.
name|virtual
operator|~
name|ModRMFilter
argument_list|()
block|{ }
comment|/// isDumb        - Indicates whether this filter returns the same value for
comment|///                 any value of the ModR/M byte.
comment|///
comment|/// @result       - True if the filter returns the same value for any ModR/M
comment|///                 byte; false if not.
name|virtual
name|bool
name|isDumb
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// accepts       - Indicates whether the filter accepts a particular ModR/M
comment|///                 byte value.
comment|///
comment|/// @result       - True if the filter accepts the ModR/M byte; false if not.
name|virtual
name|bool
name|accepts
argument_list|(
name|uint8_t
name|modRM
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// DumbFilter - Accepts any ModR/M byte.  Used for instructions that do not
comment|///   require a ModR/M byte or instructions where the entire ModR/M byte is used
comment|///   for operands.
name|class
name|DumbFilter
range|:
name|public
name|ModRMFilter
block|{
name|public
operator|:
name|bool
name|isDumb
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|bool
name|accepts
argument_list|(
argument|uint8_t modRM
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ModFilter - Filters based on the mod bits [bits 7-6] of the ModR/M byte.
comment|///   Some instructions are classified based on whether they are 11 or anything
comment|///   else.  This filter performs that classification.
name|class
name|ModFilter
operator|:
name|public
name|ModRMFilter
block|{
name|private
operator|:
name|bool
name|R
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// @r            - True if the mod bits of the ModR/M byte must be 11; false
comment|///                 otherwise.  The name r derives from the fact that the mod
comment|///                 bits indicate whether the R/M bits [bits 2-0] signify a
comment|///                 register or a memory operand.
name|ModFilter
argument_list|(
argument|bool r
argument_list|)
operator|:
name|ModRMFilter
argument_list|()
block|,
name|R
argument_list|(
argument|r
argument_list|)
block|{   }
name|bool
name|accepts
argument_list|(
argument|uint8_t modRM
argument_list|)
specifier|const
block|{
if|if
condition|(
name|R
operator|==
operator|(
operator|(
name|modRM
operator|&
literal|0xc0
operator|)
operator|==
literal|0xc0
operator|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
expr|}
block|;
comment|/// EscapeFilter - Filters escape opcodes, which are classified in two ways.  If
comment|///   the ModR/M byte is between 0xc0 and 0xff, then there is one slot for each
comment|///   possible value.  Otherwise, there is one instruction for each value of the
comment|///   nnn field [bits 5-3], known elsewhere as the reg field.
name|class
name|EscapeFilter
operator|:
name|public
name|ModRMFilter
block|{
name|private
operator|:
name|bool
name|C0_FF
block|;
name|uint8_t
name|NNN_or_ModRM
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// @c0_ff        - True if the ModR/M byte must fall between 0xc0 and 0xff;
comment|///                 false otherwise.
comment|/// @nnn_or_modRM - If c0_ff is true, the required value of the entire ModR/M
comment|///                 byte.  If c0_ff is false, the required value of the nnn
comment|///                 field.
name|EscapeFilter
argument_list|(
argument|bool c0_ff
argument_list|,
argument|uint8_t nnn_or_modRM
argument_list|)
operator|:
name|ModRMFilter
argument_list|()
block|,
name|C0_FF
argument_list|(
name|c0_ff
argument_list|)
block|,
name|NNN_or_ModRM
argument_list|(
argument|nnn_or_modRM
argument_list|)
block|{   }
name|bool
name|accepts
argument_list|(
argument|uint8_t modRM
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|(
name|C0_FF
operator|&&
name|modRM
operator|>=
literal|0xc0
operator|&&
operator|(
name|modRM
operator|==
name|NNN_or_ModRM
operator|)
operator|)
operator|||
operator|(
operator|!
name|C0_FF
operator|&&
name|modRM
operator|<
literal|0xc0
operator|&&
operator|(
operator|(
name|modRM
operator|&
literal|0x38
operator|)
operator|>>
literal|3
operator|)
operator|==
name|NNN_or_ModRM
operator|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
expr|}
block|;
comment|/// AddRegEscapeFilter - Some escape opcodes have one of the register operands
comment|///   added to the ModR/M byte, meaning that a range of eight ModR/M values
comment|///   maps to a single instruction.  Such instructions require the ModR/M byte
comment|///   to fall between 0xc0 and 0xff.
name|class
name|AddRegEscapeFilter
operator|:
name|public
name|ModRMFilter
block|{
name|private
operator|:
name|uint8_t
name|ModRM
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// @modRM        - The value of the ModR/M byte when the register operand
comment|///                 refers to the first register in the register set.
name|AddRegEscapeFilter
argument_list|(
argument|uint8_t modRM
argument_list|)
operator|:
name|ModRM
argument_list|(
argument|modRM
argument_list|)
block|{   }
name|bool
name|accepts
argument_list|(
argument|uint8_t modRM
argument_list|)
specifier|const
block|{
if|if
condition|(
name|modRM
operator|>=
name|ModRM
operator|&&
name|modRM
operator|<
name|ModRM
operator|+
literal|8
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
expr|}
block|;
comment|/// ExtendedFilter - Extended opcodes are classified based on the value of the
comment|///   mod field [bits 7-6] and the value of the nnn field [bits 5-3].
name|class
name|ExtendedFilter
operator|:
name|public
name|ModRMFilter
block|{
name|private
operator|:
name|bool
name|R
block|;
name|uint8_t
name|NNN
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// @r            - True if the mod field must be set to 11; false otherwise.
comment|///                 The name is explained at ModFilter.
comment|/// @nnn          - The required value of the nnn field.
name|ExtendedFilter
argument_list|(
argument|bool r
argument_list|,
argument|uint8_t nnn
argument_list|)
operator|:
name|ModRMFilter
argument_list|()
block|,
name|R
argument_list|(
name|r
argument_list|)
block|,
name|NNN
argument_list|(
argument|nnn
argument_list|)
block|{   }
name|bool
name|accepts
argument_list|(
argument|uint8_t modRM
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|(
operator|(
name|R
operator|&&
operator|(
operator|(
name|modRM
operator|&
literal|0xc0
operator|)
operator|==
literal|0xc0
operator|)
operator|)
operator|||
operator|(
operator|!
name|R
operator|&&
operator|(
operator|(
name|modRM
operator|&
literal|0xc0
operator|)
operator|!=
literal|0xc0
operator|)
operator|)
operator|)
operator|&&
operator|(
operator|(
operator|(
name|modRM
operator|&
literal|0x38
operator|)
operator|>>
literal|3
operator|)
operator|==
name|NNN
operator|)
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
expr|}
block|;
comment|/// ExactFilter - The occasional extended opcode (such as VMCALL or MONITOR)
comment|///   requires the ModR/M byte to have a specific value.
name|class
name|ExactFilter
operator|:
name|public
name|ModRMFilter
block|{
name|private
operator|:
name|uint8_t
name|ModRM
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// @modRM        - The required value of the full ModR/M byte.
name|ExactFilter
argument_list|(
argument|uint8_t modRM
argument_list|)
operator|:
name|ModRMFilter
argument_list|()
block|,
name|ModRM
argument_list|(
argument|modRM
argument_list|)
block|{   }
name|bool
name|accepts
argument_list|(
argument|uint8_t modRM
argument_list|)
specifier|const
block|{
if|if
condition|(
name|ModRM
operator|==
name|modRM
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
expr|}
block|;  }
comment|// namespace X86Disassembler
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

