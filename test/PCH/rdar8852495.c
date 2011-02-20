begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include %s -verify -fsyntax-only -Wno-sign-compare -Wtautological-compare
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t -Wsign-compare -Wtautological-compare
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -include-pch %t -verify -fsyntax-only -Wno-sign-compare -Wtautological-compare
end_comment

begin_comment
comment|// This tests that diagnostic mappings from PCH are propagated for #pragma
end_comment

begin_comment
comment|// diagnostics but not for command-line flags.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wtautological-compare"
end_pragma

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|f
parameter_list|()
block|{
name|int
name|b
init|=
name|b
operator|==
name|b
decl_stmt|;
name|unsigned
name|x
decl_stmt|;
name|signed
name|y
decl_stmt|;
return|return
name|x
operator|==
name|y
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

