begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-extensions %s -triple x86_64-pc-win32
end_comment

begin_pragma
pragma|#
directive|pragma
name|const_seg
name|(
literal|".my_const"
name|)
end_pragma

begin_comment
comment|// expected-note 2 {{#pragma entered here}}
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|a
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 2 {{declared here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
literal|".my_const"
name|)
end_pragma

begin_comment
comment|// expected-note {{#pragma entered here}}
end_comment

begin_decl_stmt
name|int
name|b
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'b' causes a section type conflict with 'a'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
name|)
end_pragma

begin_decl_stmt
name|int
name|c
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|__declspec
argument_list|(
argument|allocate(
literal|".my_const"
argument|)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|d
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'d' causes a section type conflict with 'a'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
literal|"\u"
name|)
end_pragma

begin_comment
comment|// expected-error {{\u used with no following hex digits}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
literal|"a"
literal|L"b"
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected non-wide string literal in '#pragma data_seg'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
name|execute
name|)
end_pragma

begin_comment
comment|// expected-note 2 {{#pragma entered her}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|allocate(
literal|".my_seg"
argument|)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|int_my_seg
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|code_seg
name|(
literal|".my_seg"
name|)
end_pragma

begin_function
name|void
name|fn_my_seg
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|__declspec
argument_list|(
argument|allocate(
literal|".bad_seg"
argument|)
argument_list|)
end_macro

begin_decl_stmt
name|int
name|int_bad_seg
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{declared here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|code_seg
name|(
literal|".bad_seg"
name|)
end_pragma

begin_comment
comment|// expected-note {{#pragma entered here}}
end_comment

begin_function
name|void
name|fn_bad_seg
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error {{'fn_bad_seg' causes a section type conflict with 'int_bad_seg'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
end_pragma

begin_comment
comment|// expected-warning {{missing '(' after '#pragma bss_seg' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
literal|L".my_seg"
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected push, pop or a string literal for the section name in '#pragma bss_seg' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
name|1
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected push, pop or a string literal for the section name in '#pragma bss_seg' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
name|push
name|,
literal|".my_seg"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected a stack label or a string literal for the section name in '#pragma bss_seg'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
literal|".my_seg"
end_pragma

begin_comment
comment|// expected-warning {{missing '(' after '#pragma bss_seg' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
name|push
name|,
name|my_label
name|,
name|1
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected a string literal for the section name in '#pragma bss_seg' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
literal|".my_seg"
name|,
name|1
name|)
end_pragma

begin_comment
comment|// expected-warning {{missing ')' after '#pragma bss_seg' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|bss_seg
name|(
literal|".my_seg"
end_pragma

begin_comment
comment|// expected-warning {{missing ')' after '#pragma bss_seg' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
end_pragma

begin_comment
comment|// expected-warning {{missing '(' after '#pragma section' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
end_pragma

begin_comment
comment|// expected-warning {{expected a string literal for the section name in '#pragma section' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|L".my_seg"
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected a string literal for the section name in '#pragma section' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
end_pragma

begin_comment
comment|// expected-warning {{missing ')' after '#pragma section' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|1
end_pragma

begin_comment
comment|// expected-warning {{missing ')' after '#pragma section' - ignoring}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
end_pragma

begin_comment
comment|// expected-warning {{expected action or ')' in '#pragma section' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
name|read
name|)
end_pragma

begin_comment
comment|// expected-error {{this causes a section type conflict with a prior #pragma section}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
name|bogus
name|)
end_pragma

begin_comment
comment|// expected-warning {{unknown action 'bogus' for '#pragma section' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
name|nopage
name|)
end_pragma

begin_comment
comment|// expected-warning {{known but unsupported action 'nopage' for '#pragma section' - ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
name|read
name|,
name|write
name|)
end_pragma

begin_comment
comment|// expected-error {{this causes a section type conflict with a prior #pragma section}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|section
name|(
literal|".my_seg"
name|,
name|read
name|,
name|write
name|,
name|1
name|)
end_pragma

begin_comment
comment|//  expected-warning {{expected action or ')' in '#pragma section' - ignored}}
end_comment

end_unit

