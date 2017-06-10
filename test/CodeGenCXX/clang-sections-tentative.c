begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c -emit-llvm -triple arm-none-eabi -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test that section attributes are attached to C tentative definitions as per
end_comment

begin_comment
comment|// '#pragma clang section' directives.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
name|=
literal|".bss.1"
end_pragma

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// bss.1
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
name|=
literal|""
end_pragma

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// stays in .bss.1
end_comment

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// not assigned a section attribute
end_comment

begin_decl_stmt
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// not assigned a section attribute
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|bss
name|=
literal|".bss.2"
end_pragma

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// stays in .bss.1
end_comment

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// .bss.2
end_comment

begin_comment
comment|// Test the same for `const` declarations.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|rodata
name|=
literal|".rodata.1"
end_pragma

begin_decl_stmt
specifier|const
name|int
name|cx
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rodata.1
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|rodata
name|=
literal|""
end_pragma

begin_decl_stmt
specifier|const
name|int
name|cx
decl_stmt|;
end_decl_stmt

begin_comment
comment|// stays in .rodata.1
end_comment

begin_decl_stmt
specifier|const
name|int
name|cy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// not assigned a section attribute
end_comment

begin_decl_stmt
specifier|const
name|int
name|cz
decl_stmt|;
end_decl_stmt

begin_comment
comment|// not assigned a rodata section attribute
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|section
name|rodata
name|=
literal|".rodata.2"
end_pragma

begin_decl_stmt
specifier|const
name|int
name|cx
decl_stmt|;
end_decl_stmt

begin_comment
comment|// stays in .rodata.1
end_comment

begin_decl_stmt
specifier|const
name|int
name|cy
decl_stmt|;
end_decl_stmt

begin_comment
comment|// .rodata.2
end_comment

begin_comment
comment|// CHECK: @x = global i32 0, align 4 #0
end_comment

begin_comment
comment|// CHECK: @y = global i32 0, align 4 #1
end_comment

begin_comment
comment|// CHECK: @z = common global i32 0, align 4
end_comment

begin_comment
comment|// CHECK: @cx = constant i32 0, align 4 #2
end_comment

begin_comment
comment|// CHECK: @cy = constant i32 0, align 4 #3
end_comment

begin_comment
comment|// CHECK: @cz = constant i32 0, align 4 #1
end_comment

begin_comment
comment|// CHECK: attributes #0 = { "bss-section"=".bss.1" }
end_comment

begin_comment
comment|// CHECK: attributes #1 = { "bss-section"=".bss.2" }
end_comment

begin_comment
comment|// CHECK: attributes #2 = { "bss-section"=".bss.2" "rodata-section"=".rodata.1" }
end_comment

begin_comment
comment|// CHECK: attributes #3 = { "bss-section"=".bss.2" "rodata-section"=".rodata.2" }
end_comment

end_unit

