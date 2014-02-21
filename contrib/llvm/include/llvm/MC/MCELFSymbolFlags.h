begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCELFSymbolFlags.h - ELF Symbol Flags ----------------*- C++ -*-===//
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
comment|// This file declares the SymbolFlags used for the ELF target.
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
name|LLVM_MC_MCELFSYMBOLFLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCELFSYMBOLFLAGS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/ELF.h"
end_include

begin_comment
comment|// Because all the symbol flags need to be stored in the MCSymbolData
end_comment

begin_comment
comment|// 'flags' variable we need to provide shift constants per flag type.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
enum|enum
block|{
name|ELF_STT_Shift
init|=
literal|0
block|,
comment|// Shift value for STT_* flags.
name|ELF_STB_Shift
init|=
literal|4
block|,
comment|// Shift value for STB_* flags.
name|ELF_STV_Shift
init|=
literal|8
block|,
comment|// Shift value for STV_* flags.
name|ELF_Other_Shift
init|=
literal|10
comment|// Shift value for other flags.
block|}
enum|;
enum|enum
name|ELFSymbolFlags
block|{
name|ELF_STB_Local
init|=
operator|(
name|ELF
operator|::
name|STB_LOCAL
operator|<<
name|ELF_STB_Shift
operator|)
block|,
name|ELF_STB_Global
init|=
operator|(
name|ELF
operator|::
name|STB_GLOBAL
operator|<<
name|ELF_STB_Shift
operator|)
block|,
name|ELF_STB_Weak
init|=
operator|(
name|ELF
operator|::
name|STB_WEAK
operator|<<
name|ELF_STB_Shift
operator|)
block|,
name|ELF_STB_Loproc
init|=
operator|(
name|ELF
operator|::
name|STB_LOPROC
operator|<<
name|ELF_STB_Shift
operator|)
block|,
name|ELF_STB_Hiproc
init|=
operator|(
name|ELF
operator|::
name|STB_HIPROC
operator|<<
name|ELF_STB_Shift
operator|)
block|,
name|ELF_STT_Notype
init|=
operator|(
name|ELF
operator|::
name|STT_NOTYPE
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Object
init|=
operator|(
name|ELF
operator|::
name|STT_OBJECT
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Func
init|=
operator|(
name|ELF
operator|::
name|STT_FUNC
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Section
init|=
operator|(
name|ELF
operator|::
name|STT_SECTION
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_File
init|=
operator|(
name|ELF
operator|::
name|STT_FILE
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Common
init|=
operator|(
name|ELF
operator|::
name|STT_COMMON
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Tls
init|=
operator|(
name|ELF
operator|::
name|STT_TLS
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Loproc
init|=
operator|(
name|ELF
operator|::
name|STT_LOPROC
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STT_Hiproc
init|=
operator|(
name|ELF
operator|::
name|STT_HIPROC
operator|<<
name|ELF_STT_Shift
operator|)
block|,
name|ELF_STV_Default
init|=
operator|(
name|ELF
operator|::
name|STV_DEFAULT
operator|<<
name|ELF_STV_Shift
operator|)
block|,
name|ELF_STV_Internal
init|=
operator|(
name|ELF
operator|::
name|STV_INTERNAL
operator|<<
name|ELF_STV_Shift
operator|)
block|,
name|ELF_STV_Hidden
init|=
operator|(
name|ELF
operator|::
name|STV_HIDDEN
operator|<<
name|ELF_STV_Shift
operator|)
block|,
name|ELF_STV_Protected
init|=
operator|(
name|ELF
operator|::
name|STV_PROTECTED
operator|<<
name|ELF_STV_Shift
operator|)
block|,
name|ELF_Other_Weakref
init|=
operator|(
literal|1
operator|<<
name|ELF_Other_Shift
operator|)
block|,
name|ELF_Other_ThumbFunc
init|=
operator|(
literal|2
operator|<<
name|ELF_Other_Shift
operator|)
block|}
enum|;
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

