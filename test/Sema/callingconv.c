begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -triple i386-unknown-unknown -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -triple i386-unknown-unknown -fms-compatibility -DWIN -verify
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|foo
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|bar
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|baz
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{
comment|// expected-error {{'fastcall' attribute takes no arguments}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|test0
argument_list|()
block|{
comment|// expected-error {{function with no prototype cannot use fastcall calling convention}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|test1
argument_list|(
name|void
argument_list|)
block|{ }
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|test2
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
block|{
comment|// expected-warning {{fastcall calling convention ignored on variadic function}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|test3
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
block|{
comment|// expected-warning {{stdcall calling convention ignored on variadic function}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|thiscall
operator|)
argument_list|)
name|test4
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
block|{
comment|// expected-error {{variadic function cannot use thiscall calling convention}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
name|ctest0
argument_list|()
block|{}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|cdecl
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|ctest1
argument_list|(
name|float
name|x
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// expected-error {{'cdecl' attribute takes no arguments}}
end_comment

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
operator|*
name|pfoo
argument_list|)
argument_list|(
name|float
operator|*
argument_list|)
operator|=
name|foo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
operator|*
name|pbar
argument_list|)
argument_list|(
name|float
operator|*
argument_list|)
operator|=
name|bar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
operator|*
name|ptest1
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|test1
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{incompatible pointer types}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|pctest0
function_decl|)
parameter_list|()
init|=
name|ctest0
function_decl|;
end_function_decl

begin_function
name|void
name|ctest2
parameter_list|()
block|{}
end_function

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
operator|*
name|pctest2
argument_list|)
argument_list|()
operator|=
name|ctest2
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
operator|*
name|Handler
argument_list|)
argument_list|(
name|float
operator|*
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|Handler
name|H
init|=
name|foo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|"aapcs"
argument_list|,
literal|"aapcs"
argument_list|)
operator|)
argument_list|)
name|pcs1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'pcs' attribute takes one argument}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|()
operator|)
argument_list|)
name|pcs2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'pcs' attribute takes one argument}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
name|pcs1
argument_list|)
operator|)
argument_list|)
name|pcs3
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'pcs' attribute requires a string}} \
end_comment

begin_comment
comment|// expected-error {{invalid PCS type}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
name|pcs4
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'pcs' attribute requires a string}}
end_comment

begin_comment
comment|/* These are ignored because the target is i386 and not ARM */
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|"aapcs"
argument_list|)
operator|)
argument_list|)
name|pcs5
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{calling convention 'pcs' ignored for this target}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|"aapcs-vfp"
argument_list|)
operator|)
argument_list|)
name|pcs6
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{calling convention 'pcs' ignored for this target}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|pcs
argument_list|(
literal|"foo"
argument_list|)
operator|)
argument_list|)
name|pcs7
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid PCS type}}
end_comment

begin_comment
comment|// PR6361
end_comment

begin_function_decl
name|void
name|ctest3
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
name|ctest3
argument_list|()
block|{}
end_decl_stmt

begin_comment
comment|// PR6408
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(stdcall)
argument_list|)
name|void
function_decl|(
modifier|*
name|PROC
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|PROC
name|__attribute__
argument_list|(
operator|(
name|cdecl
operator|)
argument_list|)
name|ctest4
argument_list|(
specifier|const
name|char
operator|*
name|x
argument_list|)
block|{}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|pnaclcall
operator|)
argument_list|)
name|pnaclfunc
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// expected-warning {{calling convention 'pnaclcall' ignored for this target}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|intel_ocl_bicc
operator|)
argument_list|)
name|inteloclbifunc
argument_list|(
name|float
operator|*
name|a
argument_list|)
block|{}
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|typedef_fun_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|typedef_fun_t
name|typedef_fun
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|typedef_fun
argument_list|(
name|int
name|x
argument_list|)
block|{ }
end_decl_stmt

begin_comment
comment|// expected-error {{function declared 'stdcall' here was previously declared without calling convention}}
end_comment

begin_struct
struct|struct
name|type_test
block|{}
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// expected-warning {{'stdcall' attribute only applies to functions and methods}}
end_comment

end_unit

