begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-feature +sse2 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-feature +sse2 -fsyntax-only -verify %s -x c++
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
operator|(
name|void
operator|)
name|_mm_getcsr
argument_list|()
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_getcsr'}} \
comment|// expected-note{{include the header<xmmintrin.h> or explicitly provide a declaration for '_mm_getcsr'}}
name|_mm_setcsr
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_setcsr'}} \
comment|// expected-note{{include the header<xmmintrin.h> or explicitly provide a declaration for '_mm_setcsr'}}
name|_mm_sfence
argument_list|()
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_sfence'}} \
comment|// expected-note{{include the header<xmmintrin.h> or explicitly provide a declaration for '_mm_sfence'}}
name|_mm_clflush
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_clflush'}} \
comment|// expected-note{{include the header<emmintrin.h> or explicitly provide a declaration for '_mm_clflush'}}
name|_mm_lfence
argument_list|()
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_lfence'}} \
comment|// expected-note{{include the header<emmintrin.h> or explicitly provide a declaration for '_mm_lfence'}}
name|_mm_mfence
argument_list|()
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_mfence'}} \
comment|// expected-note{{include the header<emmintrin.h> or explicitly provide a declaration for '_mm_mfence'}}
name|_mm_pause
argument_list|()
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_mm_pause'}} \
comment|// expected-note{{include the header<emmintrin.h> or explicitly provide a declaration for '_mm_pause'}}
block|}
end_function

begin_function_decl
name|unsigned
name|int
name|_mm_getcsr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mm_setcsr
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mm_sfence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mm_clflush
parameter_list|(
name|void
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mm_lfence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mm_mfence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mm_pause
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|()
block|{
operator|(
name|void
operator|)
name|_mm_getcsr
argument_list|()
expr_stmt|;
name|_mm_setcsr
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|_mm_sfence
argument_list|()
expr_stmt|;
name|_mm_clflush
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|_mm_lfence
argument_list|()
expr_stmt|;
name|_mm_mfence
argument_list|()
expr_stmt|;
name|_mm_pause
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

