begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple i386-linux-gnu %s | FileCheck %s
end_comment

begin_comment
comment|// This checks that the global won't be marked as common.
end_comment

begin_comment
comment|// (It shouldn't because it's being initialized).
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
init|=
literal|242
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @a = global i32 242
end_comment

begin_comment
comment|// This should get normal weak linkage.
end_comment

begin_decl_stmt
name|int
name|c
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @c = weak global i32 0
end_comment

begin_comment
comment|// Since this is marked const, it should get weak_odr linkage, since all
end_comment

begin_comment
comment|// definitions have to be the same.
end_comment

begin_comment
comment|// CHECK: @d = weak_odr constant i32 0
end_comment

begin_decl_stmt
specifier|const
name|int
name|d
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NOTE: tentative definitions are processed at the end of the translation unit.
end_comment

begin_comment
comment|// This shouldn't be emitted as common because it has an explicit section.
end_comment

begin_comment
comment|// rdar://7119244
end_comment

begin_decl_stmt
name|int
name|b
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"foo"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @b = global i32 0, section "foo"
end_comment

end_unit

