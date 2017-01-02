begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NtStructures.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Minidump_NtStructures_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Minidump_NtStructures_h_
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|minidump
block|{
comment|// This describes the layout of a TEB (Thread Environment Block) for a 64-bit
comment|// process.  It's adapted from the 32-bit TEB in winternl.h.  Currently, we care
comment|// only about the position of the tls_slots.
struct|struct
name|TEB64
block|{
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|reserved1
index|[
literal|12
index|]
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|process_environment_block
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|reserved2
index|[
literal|399
index|]
expr_stmt|;
name|uint8_t
name|reserved3
index|[
literal|1952
index|]
decl_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|tls_slots
index|[
literal|64
index|]
expr_stmt|;
name|uint8_t
name|reserved4
index|[
literal|8
index|]
decl_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|reserved5
index|[
literal|26
index|]
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|reserved_for_ole
expr_stmt|;
comment|// Windows 2000 only
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|reserved6
index|[
literal|4
index|]
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle64_t
name|tls_expansion_slots
expr_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|// liblldb_Plugins_Process_Minidump_NtStructures_h_
block|}
comment|// namespace minidump
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

end_unit

