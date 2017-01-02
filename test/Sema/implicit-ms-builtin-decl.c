begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -fsyntax-only -verify %s -fms-extensions
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -fsyntax-only -verify %s -fms-extensions
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
operator|(
name|void
operator|)
name|_byteswap_ushort
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_byteswap_ushort'}} \
comment|// expected-note{{include the header<stdlib.h> or explicitly provide a declaration for '_byteswap_ushort'}}
operator|(
name|void
operator|)
name|_byteswap_uint64
argument_list|(
literal|42LL
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '_byteswap_uint64'}} \
comment|// expected-note{{include the header<stdlib.h> or explicitly provide a declaration for '_byteswap_uint64'}}
block|}
end_function

begin_function_decl
name|void
name|_byteswap_ulong
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{incompatible redeclaration of library function '_byteswap_ulong'}} \
end_comment

begin_comment
comment|// expected-note{{'_byteswap_ulong' is a builtin}}
end_comment

begin_function_decl
name|unsigned
name|short
name|_byteswap_ushort
parameter_list|(
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|long
name|_byteswap_uint64
parameter_list|(
name|unsigned
name|long
name|long
parameter_list|)
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
name|_byteswap_ushort
argument_list|(
literal|42
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|_byteswap_uint64
argument_list|(
literal|42LL
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|void
name|h
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__mulh
argument_list|(
literal|21
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '__mulh'}} \
comment|// expected-note{{include the header<intrin.h> or explicitly provide a declaration for '__mulh'}}
operator|(
name|void
operator|)
name|__umulh
argument_list|(
literal|21
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicitly declaring library function '__umulh'}} \
comment|// expected-note{{include the header<intrin.h> or explicitly provide a declaration for '__umulh'}}
block|}
end_function

begin_function_decl
name|long
name|long
name|__mulh
parameter_list|(
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|long
name|__umulh
parameter_list|(
name|unsigned
name|long
name|long
parameter_list|,
name|unsigned
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|i
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__mulh
argument_list|(
literal|21
argument_list|,
literal|2
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|__umulh
argument_list|(
literal|21
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_function
name|void
name|h
parameter_list|()
block|{
operator|(
name|void
operator|)
name|__mulh
argument_list|(
literal|21LL
argument_list|,
literal|2LL
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit declaration of function '__mulh' is invalid}}
operator|(
name|void
operator|)
name|__umulh
argument_list|(
literal|21ULL
argument_list|,
literal|2ULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit declaration of function '__umulh' is invalid}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

