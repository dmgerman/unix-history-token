begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -triple x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -o - %s | FileCheck %s --check-prefix=ALL --check-prefix=SSE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -triple   i386-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -o - %s | FileCheck %s --check-prefix=ALL --check-prefix=SSE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -triple x86_64-apple-darwin10 -target-feature +avx \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -o - %s | FileCheck %s --check-prefix=ALL --check-prefix=AVX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -triple   i386-apple-darwin10 -target-feature +avx \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -o - %s | FileCheck %s --check-prefix=ALL --check-prefix=AVX
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -triple x86_64-apple-darwin10 -target-feature +avx512f \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -o - %s | FileCheck %s --check-prefix=ALL --check-prefix=AVX512
end_comment

begin_comment
comment|// RUN: %clang_cc1 -w -triple   i386-apple-darwin10 -target-feature +avx512f \
end_comment

begin_comment
comment|// RUN:  -emit-llvm -o - %s | FileCheck %s --check-prefix=ALL --check-prefix=AVX512
end_comment

begin_comment
comment|// rdar://11759609
end_comment

begin_comment
comment|// At or below target max alignment with no aligned attribute should align based
end_comment

begin_comment
comment|// on the size of vector.
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SSE: @v1 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX: @v1 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX512: @v1 {{.*}}, align 16
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|v2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SSE: @v2 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX: @v2 {{.*}}, align 32
end_comment

begin_comment
comment|// AVX512: @v2 {{.*}}, align 32
end_comment

begin_comment
comment|// Alignment above target max alignment with no aligned attribute should align
end_comment

begin_comment
comment|// based on the target max.
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|v3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SSE: @v3 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX: @v3 {{.*}}, align 32
end_comment

begin_comment
comment|// AVX512: @v3 {{.*}}, align 64
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|1024
argument_list|)
operator|)
argument_list|)
name|v4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SSE: @v4 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX: @v4 {{.*}}, align 32
end_comment

begin_comment
comment|// AVX512: @v4 {{.*}}, align 64
end_comment

begin_comment
comment|// Aliged attribute should always override.
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|,
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|v5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ALL: @v5 {{.*}}, align 16
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|,
name|aligned
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|v6
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ALL: @v6 {{.*}}, align 64
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|,
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|v7
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ALL: @v7 {{.*}}, align 16
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|,
name|aligned
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|v8
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ALL: @v8 {{.*}}, align 64
end_comment

begin_comment
comment|// Check non-power of 2 widths.
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|24
argument_list|)
operator|)
argument_list|)
name|v9
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SSE: @v9 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX: @v9 {{.*}}, align 32
end_comment

begin_comment
comment|// AVX512: @v9 {{.*}}, align 32
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|40
argument_list|)
operator|)
argument_list|)
name|v10
decl_stmt|;
end_decl_stmt

begin_comment
comment|// SSE: @v10 {{.*}}, align 16
end_comment

begin_comment
comment|// AVX: @v10 {{.*}}, align 32
end_comment

begin_comment
comment|// AVX512: @v10 {{.*}}, align 64
end_comment

begin_comment
comment|// Check non-power of 2 widths with aligned attribute.
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|24
argument_list|)
operator|,
name|aligned
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|v11
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ALL: @v11 {{.*}}, align 64
end_comment

begin_decl_stmt
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|80
argument_list|)
operator|,
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|v12
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ALL: @v12 {{.*}}, align 16
end_comment

end_unit

