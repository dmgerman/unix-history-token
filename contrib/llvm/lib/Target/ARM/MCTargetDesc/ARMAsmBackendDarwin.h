begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMAsmBackendDarwin.h   ARM Asm Backend Darwin ----------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_ARMASMBACKENDDARWIN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMASMBACKENDDARWIN_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MachO.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_macro
name|namespace
end_macro

begin_block
block|{
name|class
name|ARMAsmBackendDarwin
range|:
name|public
name|ARMAsmBackend
block|{
name|public
operator|:
specifier|const
name|MachO
operator|::
name|CPUSubTypeARM
name|Subtype
block|;
name|ARMAsmBackendDarwin
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|MachO::CPUSubTypeARM st
argument_list|)
operator|:
name|ARMAsmBackend
argument_list|(
name|T
argument_list|,
name|TT
argument_list|,
comment|/* IsLittleEndian */
name|true
argument_list|)
block|,
name|Subtype
argument_list|(
argument|st
argument_list|)
block|{
name|HasDataInCodeSupport
operator|=
name|true
block|;   }
name|MCObjectWriter
operator|*
name|createObjectWriter
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|{
return|return
name|createARMMachObjectWriter
argument_list|(
name|OS
argument_list|,
comment|/*Is64Bit=*/
name|false
argument_list|,
name|MachO
operator|::
name|CPU_TYPE_ARM
argument_list|,
name|Subtype
argument_list|)
return|;
block|}
expr|}
block|; }
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

