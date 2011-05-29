begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- SystemZ.h - Top-level interface for SystemZ representation -*- C++ -*-==//
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
comment|// the LLVM SystemZ backend.
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
name|LLVM_TARGET_SystemZ_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_SystemZ_H
end_define

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
name|SystemZTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|namespace
name|SystemZCC
block|{
comment|// SystemZ specific condition code. These correspond to SYSTEMZ_*_COND in
comment|// SystemZInstrInfo.td. They must be kept in synch.
enum|enum
name|CondCodes
block|{
name|O
init|=
literal|0
block|,
name|H
init|=
literal|1
block|,
name|NLE
init|=
literal|2
block|,
name|L
init|=
literal|3
block|,
name|NHE
init|=
literal|4
block|,
name|LH
init|=
literal|5
block|,
name|NE
init|=
literal|6
block|,
name|E
init|=
literal|7
block|,
name|NLH
init|=
literal|8
block|,
name|HE
init|=
literal|9
block|,
name|NL
init|=
literal|10
block|,
name|LE
init|=
literal|11
block|,
name|NH
init|=
literal|12
block|,
name|NO
init|=
literal|13
block|,
name|INVALID
init|=
operator|-
literal|1
block|}
enum|;
block|}
name|FunctionPass
modifier|*
name|createSystemZISelDag
argument_list|(
name|SystemZTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
specifier|extern
name|Target
name|TheSystemZTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for SystemZ registers.
end_comment

begin_comment
comment|// This defines a mapping from register name to register number.
end_comment

begin_include
include|#
directive|include
file|"SystemZGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the SystemZ instructions.
end_comment

begin_include
include|#
directive|include
file|"SystemZGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

