begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -S -o -< %s | FileCheck %s --check-prefix=PLAIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -S -ffunction-sections -fno-function-sections -o -< %s | FileCheck %s --check-prefix=PLAIN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -S -ffunction-sections -o -< %s | FileCheck %s --check-prefix=FUNC_SECT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -S -fno-function-sections -ffunction-sections -o -< %s | FileCheck %s --check-prefix=FUNC_SECT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -S -fdata-sections -o -< %s | FileCheck %s --check-prefix=DATA_SECT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -S -fno-data-sections -fdata-sections -o -< %s | FileCheck %s --check-prefix=DATA_SECT
end_comment

begin_decl_stmt
specifier|const
name|int
name|hello
init|=
literal|123
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|world
parameter_list|()
block|{}
end_function

begin_comment
comment|// PLAIN-NOT: section
end_comment

begin_comment
comment|// PLAIN: world:
end_comment

begin_comment
comment|// PLAIN: section .rodata,
end_comment

begin_comment
comment|// PLAIN: hello:
end_comment

begin_comment
comment|// FUNC_SECT: section .text.world,
end_comment

begin_comment
comment|// FUNC_SECT: world:
end_comment

begin_comment
comment|// FUNC_SECT: section .rodata,
end_comment

begin_comment
comment|// FUNC_SECT: hello:
end_comment

begin_comment
comment|// DATA_SECT-NOT: section
end_comment

begin_comment
comment|// DATA_SECT: world:
end_comment

begin_comment
comment|// DATA_SECT: .section .rodata.hello,
end_comment

begin_comment
comment|// DATA_SECT: hello:
end_comment

end_unit

