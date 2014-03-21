begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCMachOSymbolFlags.h - MachO Symbol Flags ----------------*- C++ -*-===//
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
comment|// This file declares the SymbolFlags used for the MachO target.
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
name|LLVM_MC_MCMACHOSYMBOLFLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCMACHOSYMBOLFLAGS_H
end_define

begin_comment
comment|// These flags are mostly used in MCMachOStreamer.cpp but also needed in
end_comment

begin_comment
comment|// MachObjectWriter.cpp to test for Weak Definitions of symbols to emit
end_comment

begin_comment
comment|// the correct relocation information.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MachOSymbolFlags - We store the value for the 'desc' symbol field in the
comment|/// lowest 16 bits of the implementation defined flags.
enum|enum
name|MachOSymbolFlags
block|{
comment|// See<mach-o/nlist.h>.
name|SF_DescFlagsMask
init|=
literal|0xFFFF
block|,
comment|// Reference type flags.
name|SF_ReferenceTypeMask
init|=
literal|0x0007
block|,
name|SF_ReferenceTypeUndefinedNonLazy
init|=
literal|0x0000
block|,
name|SF_ReferenceTypeUndefinedLazy
init|=
literal|0x0001
block|,
name|SF_ReferenceTypeDefined
init|=
literal|0x0002
block|,
name|SF_ReferenceTypePrivateDefined
init|=
literal|0x0003
block|,
name|SF_ReferenceTypePrivateUndefinedNonLazy
init|=
literal|0x0004
block|,
name|SF_ReferenceTypePrivateUndefinedLazy
init|=
literal|0x0005
block|,
comment|// Other 'desc' flags.
name|SF_ThumbFunc
init|=
literal|0x0008
block|,
name|SF_NoDeadStrip
init|=
literal|0x0020
block|,
name|SF_WeakReference
init|=
literal|0x0040
block|,
name|SF_WeakDefinition
init|=
literal|0x0080
block|,
name|SF_SymbolResolver
init|=
literal|0x0100
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

