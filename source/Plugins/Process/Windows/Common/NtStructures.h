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
name|liblldb_Plugins_Process_Windows_Common_NtStructures_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_Common_NtStructures_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/windows/windows.h"
end_include

begin_comment
comment|// This describes the layout of a TEB (Thread Environment Block) for a 64-bit
end_comment

begin_comment
comment|// process.  It's adapted from the 32-bit TEB in winternl.h.  Currently, we care
end_comment

begin_comment
comment|// only about the position of the TlsSlots.
end_comment

begin_struct
struct|struct
name|TEB64
block|{
name|ULONG64
name|Reserved1
index|[
literal|12
index|]
decl_stmt|;
name|ULONG64
name|ProcessEnvironmentBlock
decl_stmt|;
name|ULONG64
name|Reserved2
index|[
literal|399
index|]
decl_stmt|;
name|BYTE
name|Reserved3
index|[
literal|1952
index|]
decl_stmt|;
name|ULONG64
name|TlsSlots
index|[
literal|64
index|]
decl_stmt|;
name|BYTE
name|Reserved4
index|[
literal|8
index|]
decl_stmt|;
name|ULONG64
name|Reserved5
index|[
literal|26
index|]
decl_stmt|;
name|ULONG64
name|ReservedForOle
decl_stmt|;
comment|// Windows 2000 only
name|ULONG64
name|Reserved6
index|[
literal|4
index|]
decl_stmt|;
name|ULONG64
name|TlsExpansionSlots
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

