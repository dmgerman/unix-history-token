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
comment|//  X86DisassemblerEmitter.h.
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
name|LLVM_UTILS_TABLEGEN_X86MODRMFILTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_X86MODRMFILTERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
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
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|bool
name|isDumb
argument_list|()
specifier|const
name|override
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
name|override
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
name|void
name|anchor
argument_list|()
name|override
block|;
name|bool
name|R
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// \param r        True if the mod bits of the ModR/M byte must be 11; false
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
name|override
block|{
return|return
operator|(
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
operator|)
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
name|void
name|anchor
argument_list|()
name|override
block|;
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
comment|/// \param r   True if the mod field must be set to 11; false otherwise.
comment|///            The name is explained at ModFilter.
comment|/// \param nnn The required value of the nnn field.
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
name|override
block|{
return|return
operator|(
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
operator|)
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
name|void
name|anchor
argument_list|()
name|override
block|;
name|uint8_t
name|ModRM
block|;
name|public
operator|:
comment|/// Constructor
comment|///
comment|/// \param modRM The required value of the full ModR/M byte.
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
name|override
block|{
return|return
operator|(
name|ModRM
operator|==
name|modRM
operator|)
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

