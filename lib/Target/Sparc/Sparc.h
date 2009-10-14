begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Sparc.h - Top-level interface for Sparc representation --*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// Sparc back-end.
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
name|TARGET_SPARC_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_SPARC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|SparcTargetMachine
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createSparcISelDag
parameter_list|(
name|SparcTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createSparcDelaySlotFillerPass
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createSparcFPMoverPass
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|TheSparcTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for Sparc registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"SparcGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the Sparc instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"SparcGenInstrNames.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Enums corresponding to Sparc condition codes, both icc's and fcc's.  These
comment|// values must be kept in sync with the ones in the .td file.
name|namespace
name|SPCC
block|{
enum|enum
name|CondCodes
block|{
comment|//ICC_A   =  8   ,  // Always
comment|//ICC_N   =  0   ,  // Never
name|ICC_NE
init|=
literal|9
block|,
comment|// Not Equal
name|ICC_E
init|=
literal|1
block|,
comment|// Equal
name|ICC_G
init|=
literal|10
block|,
comment|// Greater
name|ICC_LE
init|=
literal|2
block|,
comment|// Less or Equal
name|ICC_GE
init|=
literal|11
block|,
comment|// Greater or Equal
name|ICC_L
init|=
literal|3
block|,
comment|// Less
name|ICC_GU
init|=
literal|12
block|,
comment|// Greater Unsigned
name|ICC_LEU
init|=
literal|4
block|,
comment|// Less or Equal Unsigned
name|ICC_CC
init|=
literal|13
block|,
comment|// Carry Clear/Great or Equal Unsigned
name|ICC_CS
init|=
literal|5
block|,
comment|// Carry Set/Less Unsigned
name|ICC_POS
init|=
literal|14
block|,
comment|// Positive
name|ICC_NEG
init|=
literal|6
block|,
comment|// Negative
name|ICC_VC
init|=
literal|15
block|,
comment|// Overflow Clear
name|ICC_VS
init|=
literal|7
block|,
comment|// Overflow Set
comment|//FCC_A   =  8+16,  // Always
comment|//FCC_N   =  0+16,  // Never
name|FCC_U
init|=
literal|7
operator|+
literal|16
block|,
comment|// Unordered
name|FCC_G
init|=
literal|6
operator|+
literal|16
block|,
comment|// Greater
name|FCC_UG
init|=
literal|5
operator|+
literal|16
block|,
comment|// Unordered or Greater
name|FCC_L
init|=
literal|4
operator|+
literal|16
block|,
comment|// Less
name|FCC_UL
init|=
literal|3
operator|+
literal|16
block|,
comment|// Unordered or Less
name|FCC_LG
init|=
literal|2
operator|+
literal|16
block|,
comment|// Less or Greater
name|FCC_NE
init|=
literal|1
operator|+
literal|16
block|,
comment|// Not Equal
name|FCC_E
init|=
literal|9
operator|+
literal|16
block|,
comment|// Equal
name|FCC_UE
init|=
literal|10
operator|+
literal|16
block|,
comment|// Unordered or Equal
name|FCC_GE
init|=
literal|11
operator|+
literal|16
block|,
comment|// Greater or Equal
name|FCC_UGE
init|=
literal|12
operator|+
literal|16
block|,
comment|// Unordered or Greater or Equal
name|FCC_LE
init|=
literal|13
operator|+
literal|16
block|,
comment|// Less or Equal
name|FCC_ULE
init|=
literal|14
operator|+
literal|16
block|,
comment|// Unordered or Less or Equal
name|FCC_O
init|=
literal|15
operator|+
literal|16
comment|// Ordered
block|}
enum|;
block|}
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|SPARCCondCodeToString
argument_list|(
name|SPCC
operator|::
name|CondCodes
name|CC
argument_list|)
block|{
switch|switch
condition|(
name|CC
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Unknown condition code"
argument_list|)
expr_stmt|;
case|case
name|SPCC
operator|::
name|ICC_NE
case|:
return|return
literal|"ne"
return|;
case|case
name|SPCC
operator|::
name|ICC_E
case|:
return|return
literal|"e"
return|;
case|case
name|SPCC
operator|::
name|ICC_G
case|:
return|return
literal|"g"
return|;
case|case
name|SPCC
operator|::
name|ICC_LE
case|:
return|return
literal|"le"
return|;
case|case
name|SPCC
operator|::
name|ICC_GE
case|:
return|return
literal|"ge"
return|;
case|case
name|SPCC
operator|::
name|ICC_L
case|:
return|return
literal|"l"
return|;
case|case
name|SPCC
operator|::
name|ICC_GU
case|:
return|return
literal|"gu"
return|;
case|case
name|SPCC
operator|::
name|ICC_LEU
case|:
return|return
literal|"leu"
return|;
case|case
name|SPCC
operator|::
name|ICC_CC
case|:
return|return
literal|"cc"
return|;
case|case
name|SPCC
operator|::
name|ICC_CS
case|:
return|return
literal|"cs"
return|;
case|case
name|SPCC
operator|::
name|ICC_POS
case|:
return|return
literal|"pos"
return|;
case|case
name|SPCC
operator|::
name|ICC_NEG
case|:
return|return
literal|"neg"
return|;
case|case
name|SPCC
operator|::
name|ICC_VC
case|:
return|return
literal|"vc"
return|;
case|case
name|SPCC
operator|::
name|ICC_VS
case|:
return|return
literal|"vs"
return|;
case|case
name|SPCC
operator|::
name|FCC_U
case|:
return|return
literal|"u"
return|;
case|case
name|SPCC
operator|::
name|FCC_G
case|:
return|return
literal|"g"
return|;
case|case
name|SPCC
operator|::
name|FCC_UG
case|:
return|return
literal|"ug"
return|;
case|case
name|SPCC
operator|::
name|FCC_L
case|:
return|return
literal|"l"
return|;
case|case
name|SPCC
operator|::
name|FCC_UL
case|:
return|return
literal|"ul"
return|;
case|case
name|SPCC
operator|::
name|FCC_LG
case|:
return|return
literal|"lg"
return|;
case|case
name|SPCC
operator|::
name|FCC_NE
case|:
return|return
literal|"ne"
return|;
case|case
name|SPCC
operator|::
name|FCC_E
case|:
return|return
literal|"e"
return|;
case|case
name|SPCC
operator|::
name|FCC_UE
case|:
return|return
literal|"ue"
return|;
case|case
name|SPCC
operator|::
name|FCC_GE
case|:
return|return
literal|"ge"
return|;
case|case
name|SPCC
operator|::
name|FCC_UGE
case|:
return|return
literal|"uge"
return|;
case|case
name|SPCC
operator|::
name|FCC_LE
case|:
return|return
literal|"le"
return|;
case|case
name|SPCC
operator|::
name|FCC_ULE
case|:
return|return
literal|"ule"
return|;
case|case
name|SPCC
operator|::
name|FCC_O
case|:
return|return
literal|"o"
return|;
block|}
block|}
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

