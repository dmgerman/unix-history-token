begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BPFMCAsmInfo.h - BPF asm properties -------------------*- C++ -*--====//
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
comment|// This file contains the declaration of the BPFMCAsmInfo class.
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
name|LLVM_LIB_TARGET_BPF_MCTARGETDESC_BPFMCASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_BPF_MCTARGETDESC_BPFMCASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

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
name|BPFMCAsmInfo
range|:
name|public
name|MCAsmInfo
block|{
name|public
operator|:
name|explicit
name|BPFMCAsmInfo
argument_list|(
argument|const Triple&TT
argument_list|)
block|{
if|if
condition|(
name|TT
operator|.
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|bpfeb
condition|)
name|IsLittleEndian
operator|=
name|false
expr_stmt|;
name|PrivateGlobalPrefix
operator|=
literal|".L"
block|;
name|WeakRefDirective
operator|=
literal|"\t.weak\t"
block|;
name|UsesELFSectionDirectiveForBSS
operator|=
name|true
block|;
name|HasSingleParameterDotFile
operator|=
name|false
block|;
name|HasDotTypeDotSizeDirective
operator|=
name|false
block|;
name|SupportsDebugInformation
operator|=
name|true
block|;
name|ExceptionsType
operator|=
name|ExceptionHandling
operator|::
name|DwarfCFI
block|;
name|MinInstAlignment
operator|=
literal|8
block|;
comment|// the default is 4 and it only affects dwarf elf output
comment|// so if not set correctly, the dwarf data will be
comment|// messed up in random places by 4 bytes. .debug_line
comment|// section will be parsable, but with odd offsets and
comment|// line numbers, etc.
name|CodePointerSize
operator|=
literal|8
block|;   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

