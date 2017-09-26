begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARM64_DWARF_Registers.h ---------------------------------*- C++ -*-===//
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
name|utility_ARM64_DWARF_Registers_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_ARM64_DWARF_Registers_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|arm64_dwarf
block|{
enum|enum
block|{
name|x0
init|=
literal|0
block|,
name|x1
block|,
name|x2
block|,
name|x3
block|,
name|x4
block|,
name|x5
block|,
name|x6
block|,
name|x7
block|,
name|x8
block|,
name|x9
block|,
name|x10
block|,
name|x11
block|,
name|x12
block|,
name|x13
block|,
name|x14
block|,
name|x15
block|,
name|x16
block|,
name|x17
block|,
name|x18
block|,
name|x19
block|,
name|x20
block|,
name|x21
block|,
name|x22
block|,
name|x23
block|,
name|x24
block|,
name|x25
block|,
name|x26
block|,
name|x27
block|,
name|x28
block|,
name|x29
init|=
literal|29
block|,
name|fp
init|=
name|x29
block|,
name|x30
init|=
literal|30
block|,
name|lr
init|=
name|x30
block|,
name|x31
init|=
literal|31
block|,
name|sp
init|=
name|x31
block|,
name|pc
init|=
literal|32
block|,
name|cpsr
init|=
literal|33
block|,
comment|// 34-63 reserved
comment|// V0-V31 (128 bit vector registers)
name|v0
init|=
literal|64
block|,
name|v1
block|,
name|v2
block|,
name|v3
block|,
name|v4
block|,
name|v5
block|,
name|v6
block|,
name|v7
block|,
name|v8
block|,
name|v9
block|,
name|v10
block|,
name|v11
block|,
name|v12
block|,
name|v13
block|,
name|v14
block|,
name|v15
block|,
name|v16
block|,
name|v17
block|,
name|v18
block|,
name|v19
block|,
name|v20
block|,
name|v21
block|,
name|v22
block|,
name|v23
block|,
name|v24
block|,
name|v25
block|,
name|v26
block|,
name|v27
block|,
name|v28
block|,
name|v29
block|,
name|v30
block|,
name|v31
comment|// 96-127 reserved
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// namespace arm64_dwarf
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_ARM64_DWARF_Registers_h_
end_comment

end_unit

