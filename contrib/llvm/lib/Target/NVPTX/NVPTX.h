begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTX.h - Top-level interface for NVPTX representation --*- C++ -*-===//
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
comment|// the LLVM NVPTX back-end.
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
name|LLVM_TARGET_NVPTX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_NVPTX_H
end_define

begin_include
include|#
directive|include
file|"llvm/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

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
file|"MCTargetDesc/NVPTXBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|NVPTXTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|namespace
name|NVPTXCC
block|{
enum|enum
name|CondCodes
block|{
name|EQ
block|,
name|NE
block|,
name|LT
block|,
name|LE
block|,
name|GT
block|,
name|GE
block|}
enum|;
block|}
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|NVPTXCondCodeToString
argument_list|(
name|NVPTXCC
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
case|case
name|NVPTXCC
operator|::
name|NE
case|:
return|return
literal|"ne"
return|;
case|case
name|NVPTXCC
operator|::
name|EQ
case|:
return|return
literal|"eq"
return|;
case|case
name|NVPTXCC
operator|::
name|LT
case|:
return|return
literal|"lt"
return|;
case|case
name|NVPTXCC
operator|::
name|LE
case|:
return|return
literal|"le"
return|;
case|case
name|NVPTXCC
operator|::
name|GT
case|:
return|return
literal|"gt"
return|;
case|case
name|NVPTXCC
operator|::
name|GE
case|:
return|return
literal|"ge"
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown condition code"
argument_list|)
expr_stmt|;
block|}
name|FunctionPass
modifier|*
name|createNVPTXISelDag
argument_list|(
name|NVPTXTargetMachine
operator|&
name|TM
argument_list|,
name|llvm
operator|::
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
name|FunctionPass
modifier|*
name|createVectorElementizePass
parameter_list|(
name|NVPTXTargetMachine
modifier|&
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createLowerStructArgsPass
parameter_list|(
name|NVPTXTargetMachine
modifier|&
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createNVPTXReMatPass
parameter_list|(
name|NVPTXTargetMachine
modifier|&
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createNVPTXReMatBlockPass
parameter_list|(
name|NVPTXTargetMachine
modifier|&
parameter_list|)
function_decl|;
name|bool
name|isImageOrSamplerVal
parameter_list|(
specifier|const
name|Value
modifier|*
parameter_list|,
specifier|const
name|Module
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|TheNVPTXTarget32
decl_stmt|;
specifier|extern
name|Target
name|TheNVPTXTarget64
decl_stmt|;
name|namespace
name|NVPTX
block|{
enum|enum
name|DrvInterface
block|{
name|NVCL
block|,
name|CUDA
block|,
name|TEST
block|}
enum|;
comment|// A field inside TSFlags needs a shift and a mask. The usage is
comment|// always as follows :
comment|// ((TSFlags& fieldMask)>> fieldShift)
comment|// The enum keeps the mask, the shift, and all valid values of the
comment|// field in one place.
enum|enum
name|VecInstType
block|{
name|VecInstTypeShift
init|=
literal|0
block|,
name|VecInstTypeMask
init|=
literal|0xF
block|,
name|VecNOP
init|=
literal|0
block|,
name|VecLoad
init|=
literal|1
block|,
name|VecStore
init|=
literal|2
block|,
name|VecBuild
init|=
literal|3
block|,
name|VecShuffle
init|=
literal|4
block|,
name|VecExtract
init|=
literal|5
block|,
name|VecInsert
init|=
literal|6
block|,
name|VecDest
init|=
literal|7
block|,
name|VecOther
init|=
literal|15
block|}
enum|;
enum|enum
name|SimpleMove
block|{
name|SimpleMoveMask
init|=
literal|0x10
block|,
name|SimpleMoveShift
init|=
literal|4
block|}
enum|;
enum|enum
name|LoadStore
block|{
name|isLoadMask
init|=
literal|0x20
block|,
name|isLoadShift
init|=
literal|5
block|,
name|isStoreMask
init|=
literal|0x40
block|,
name|isStoreShift
init|=
literal|6
block|}
enum|;
name|namespace
name|PTXLdStInstCode
block|{
enum|enum
name|AddressSpace
block|{
name|GENERIC
init|=
literal|0
block|,
name|GLOBAL
init|=
literal|1
block|,
name|CONSTANT
init|=
literal|2
block|,
name|SHARED
init|=
literal|3
block|,
name|PARAM
init|=
literal|4
block|,
name|LOCAL
init|=
literal|5
block|}
enum|;
enum|enum
name|FromType
block|{
name|Unsigned
init|=
literal|0
block|,
name|Signed
block|,
name|Float
block|}
enum|;
enum|enum
name|VecType
block|{
name|Scalar
init|=
literal|1
block|,
name|V2
init|=
literal|2
block|,
name|V4
init|=
literal|4
block|}
enum|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for NVPTX registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"NVPTXGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the NVPTX instructions.
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"NVPTXGenInstrInfo.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

