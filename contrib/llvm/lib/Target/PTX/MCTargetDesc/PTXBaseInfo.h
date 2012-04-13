begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTXBaseInfo.h - Top level definitions for PTX -------- --*- C++ -*-===//
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
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the PTX target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core
end_comment

begin_comment
comment|// code gen types, passes, etc..
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
name|PTXBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PTXBASEINFO_H
end_define

begin_include
include|#
directive|include
file|"PTXMCTargetDesc.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PTXStateSpace
block|{
enum|enum
block|{
name|Global
init|=
literal|0
block|,
comment|// default to global state space
name|Constant
init|=
literal|1
block|,
name|Local
init|=
literal|2
block|,
name|Parameter
init|=
literal|3
block|,
name|Shared
init|=
literal|4
block|}
enum|;
block|}
comment|// namespace PTXStateSpace
name|namespace
name|PTXPredicate
block|{
enum|enum
block|{
name|Normal
init|=
literal|0
block|,
name|Negate
init|=
literal|1
block|,
name|None
init|=
literal|2
block|}
enum|;
block|}
comment|// namespace PTXPredicate
comment|/// Namespace to hold all target-specific flags.
name|namespace
name|PTXRoundingMode
block|{
comment|// Instruction Flags
enum|enum
block|{
comment|// Rounding Mode Flags
name|RndMask
init|=
literal|15
block|,
name|RndDefault
init|=
literal|0
block|,
comment|// ---
name|RndNone
init|=
literal|1
block|,
comment|//<NONE>
name|RndNearestEven
init|=
literal|2
block|,
comment|// .rn
name|RndTowardsZero
init|=
literal|3
block|,
comment|// .rz
name|RndNegInf
init|=
literal|4
block|,
comment|// .rm
name|RndPosInf
init|=
literal|5
block|,
comment|// .rp
name|RndApprox
init|=
literal|6
block|,
comment|// .approx
name|RndNearestEvenInt
init|=
literal|7
block|,
comment|// .rni
name|RndTowardsZeroInt
init|=
literal|8
block|,
comment|// .rzi
name|RndNegInfInt
init|=
literal|9
block|,
comment|// .rmi
name|RndPosInfInt
init|=
literal|10
comment|// .rpi
block|}
enum|;
block|}
comment|// namespace PTXII
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

