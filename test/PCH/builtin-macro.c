begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -D__DATE__= -D__TIMESTAMP__= -include %s -Wno-builtin-macro-redefined -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -D__DATE__= -D__TIMESTAMP__= -Wno-builtin-macro-redefined -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -D__DATE__= -D__TIMESTAMP__= -Wno-builtin-macro-redefined -include-pch %t -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HEADER
argument_list|)
end_if

begin_define
define|#
directive|define
name|HEADER
end_define

begin_define
define|#
directive|define
name|__TIME__
end_define

begin_undef
undef|#
directive|undef
name|__TIMESTAMP__
end_undef

begin_define
define|#
directive|define
name|__TIMESTAMP__
end_define

begin_comment
comment|// FIXME: undefs don't work well with pchs yet, see PR31311
end_comment

begin_comment
comment|// Once that's fixed, add -U__COUNTER__ to all command lines and check that
end_comment

begin_comment
comment|// an attempt to use __COUNTER__ at the bottom produces an error in both non-pch
end_comment

begin_comment
comment|// and pch case (works fine in the former case already).
end_comment

begin_comment
comment|// Same for #undef __FILE__ right here and a use of that at the bottom.
end_comment

begin_comment
comment|//#undef __FILE__
end_comment

begin_comment
comment|// Also spot-check a predefine
end_comment

begin_undef
undef|#
directive|undef
name|__STDC_HOSTED__
end_undef

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|const
name|char
name|s
index|[]
init|=
name|__DATE__
literal|" "
name|__TIME__
literal|" "
name|__TIMESTAMP__
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Check that we pick up __DATE__ from the -D flag:
end_comment

begin_decl_stmt
name|int
name|i
init|=
name|__DATE__
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|d
init|=
name|__STDC_HOSTED__
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{use of undeclared identifier '__STDC_HOSTED__'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

