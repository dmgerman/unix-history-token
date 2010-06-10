begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- PIC16MCAsmInfo.h - PIC16 asm properties -------------*- C++ -*--====//
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
comment|// This file contains the declaration of the PIC16MCAsmInfo class.
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
name|PIC16TARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16TARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Target
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|PIC16MCAsmInfo
range|:
name|public
name|MCAsmInfo
block|{
specifier|const
name|char
operator|*
name|RomData8bitsDirective
block|;
specifier|const
name|char
operator|*
name|RomData16bitsDirective
block|;
specifier|const
name|char
operator|*
name|RomData32bitsDirective
block|;
name|public
operator|:
name|PIC16MCAsmInfo
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|StringRef
operator|&
name|TT
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|getDataASDirective
argument_list|(
argument|unsigned size
argument_list|,
argument|unsigned AS
argument_list|)
specifier|const
block|;   }
decl_stmt|;
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

