begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16.h - Top-level interface for PIC16 representation --*- C++ -*-===//
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
comment|// the LLVM PIC16 back-end.
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
name|LLVM_TARGET_PIC16_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_PIC16_H
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

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PIC16TargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|namespace
name|PIC16CC
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
block|,
name|ULT
block|,
name|UGT
block|,
name|ULE
block|,
name|UGE
block|}
enum|;
block|}
enum|enum
name|PIC16SectionType
block|{
name|CODE
block|,
name|UDATA
block|,
name|IDATA
block|,
name|ROMDATA
block|,
name|UDATA_OVR
block|,
name|UDATA_SHR
block|}
enum|;
comment|// External symbol names require memory to live till the program end.
comment|// So we have to allocate it and keep.
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|createESName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
block|{
name|char
modifier|*
name|tmpName
init|=
name|new
name|char
index|[
name|name
operator|.
name|size
argument_list|()
operator|+
literal|1
index|]
decl_stmt|;
name|strcpy
argument_list|(
name|tmpName
argument_list|,
name|name
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|tmpName
return|;
block|}
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|PIC16CondCodeToString
argument_list|(
name|PIC16CC
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
name|PIC16CC
operator|::
name|NE
case|:
return|return
literal|"ne"
return|;
case|case
name|PIC16CC
operator|::
name|EQ
case|:
return|return
literal|"eq"
return|;
case|case
name|PIC16CC
operator|::
name|LT
case|:
return|return
literal|"lt"
return|;
case|case
name|PIC16CC
operator|::
name|ULT
case|:
return|return
literal|"lt"
return|;
case|case
name|PIC16CC
operator|::
name|LE
case|:
return|return
literal|"le"
return|;
case|case
name|PIC16CC
operator|::
name|ULE
case|:
return|return
literal|"le"
return|;
case|case
name|PIC16CC
operator|::
name|GT
case|:
return|return
literal|"gt"
return|;
case|case
name|PIC16CC
operator|::
name|UGT
case|:
return|return
literal|"gt"
return|;
case|case
name|PIC16CC
operator|::
name|GE
case|:
return|return
literal|"ge"
return|;
case|case
name|PIC16CC
operator|::
name|UGE
case|:
return|return
literal|"ge"
return|;
block|}
block|}
specifier|inline
specifier|static
name|bool
name|isSignedComparison
argument_list|(
name|PIC16CC
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
name|PIC16CC
operator|::
name|NE
case|:
case|case
name|PIC16CC
operator|::
name|EQ
case|:
case|case
name|PIC16CC
operator|::
name|LT
case|:
case|case
name|PIC16CC
operator|::
name|LE
case|:
case|case
name|PIC16CC
operator|::
name|GE
case|:
case|case
name|PIC16CC
operator|::
name|GT
case|:
return|return
name|true
return|;
case|case
name|PIC16CC
operator|::
name|ULT
case|:
case|case
name|PIC16CC
operator|::
name|UGT
case|:
case|case
name|PIC16CC
operator|::
name|ULE
case|:
case|case
name|PIC16CC
operator|::
name|UGE
case|:
return|return
name|false
return|;
comment|// condition codes for unsigned comparison.
block|}
block|}
name|FunctionPass
modifier|*
name|createPIC16ISelDag
parameter_list|(
name|PIC16TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|// Banksel optimizer pass.
name|FunctionPass
modifier|*
name|createPIC16MemSelOptimizerPass
parameter_list|()
function_decl|;
specifier|extern
name|Target
name|ThePIC16Target
decl_stmt|;
specifier|extern
name|Target
name|TheCooperTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for PIC16 registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_include
include|#
directive|include
file|"PIC16GenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the PIC16 instructions.
end_comment

begin_include
include|#
directive|include
file|"PIC16GenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

