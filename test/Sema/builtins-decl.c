begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -triple=i686-mingw32
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -triple=x86_64-mingw32
end_comment

begin_comment
comment|// mingw-w64's intrin.h has decls below.
end_comment

begin_comment
comment|// we should accept them.
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|__builtin_ia32_crc32qi
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|__builtin_ia32_crc32hi
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|__builtin_ia32_crc32si
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

