begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -triple i686-pc-windows-msvc -Wcast-calling-convention -DMSVC -Wno-pointer-bool-conversion -verify -x c %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -triple i686-pc-windows-msvc -Wcast-calling-convention -DMSVC -Wno-pointer-bool-conversion -verify -x c++ %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -triple i686-pc-windows-msvc -Wcast-calling-convention -DMSVC -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s --check-prefix=MSFIXIT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-windows-gnu -Wcast-calling-convention -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s --check-prefix=GNUFIXIT
end_comment

begin_comment
comment|// expected-note@+1 {{consider defining 'mismatched_before_winapi' with the 'stdcall' calling convention}}
end_comment

begin_function
name|void
name|mismatched_before_winapi
parameter_list|(
name|int
name|x
parameter_list|)
block|{}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|MSVC
end_ifdef

begin_define
define|#
directive|define
name|WINAPI
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WINAPI
value|__attribute__((stdcall))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-note@+1 3 {{consider defining 'mismatched' with the 'stdcall' calling convention}}
end_comment

begin_function
name|void
name|mismatched
parameter_list|(
name|int
name|x
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note@+1 {{consider defining 'mismatched_declaration' with the 'stdcall' calling convention}}
end_comment

begin_function_decl
name|void
name|mismatched_declaration
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note@+1 {{consider defining 'suggest_fix_first_redecl' with the 'stdcall' calling convention}}
end_comment

begin_function_decl
name|void
name|suggest_fix_first_redecl
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|suggest_fix_first_redecl
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|WINAPI
modifier|*
name|callback_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|take_callback
parameter_list|(
name|callback_t
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|WINAPI
name|mismatched_stdcall
parameter_list|(
name|int
name|x
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|take_opaque_fn
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// expected-warning@+1 {{cast between incompatible calling conventions 'cdecl' and 'stdcall'}}
name|take_callback
argument_list|(
operator|(
name|callback_t
operator|)
name|mismatched
argument_list|)
expr_stmt|;
comment|// expected-warning@+1 {{cast between incompatible calling conventions 'cdecl' and 'stdcall'}}
name|callback_t
name|callback
init|=
operator|(
name|callback_t
operator|)
name|mismatched
decl_stmt|;
comment|// warns
operator|(
name|void
operator|)
name|callback
expr_stmt|;
comment|// expected-warning@+1 {{cast between incompatible calling conventions 'cdecl' and 'stdcall'}}
name|callback
operator|=
operator|(
name|callback_t
operator|)
operator|&
name|mismatched
expr_stmt|;
comment|// warns
comment|// No warning, just to show we don't drill through other kinds of unary operators.
name|callback
operator|=
operator|(
name|callback_t
operator|)
operator|!
name|mismatched
expr_stmt|;
comment|// expected-warning@+1 {{cast between incompatible calling conventions 'cdecl' and 'stdcall'}}
name|callback
operator|=
operator|(
name|callback_t
operator|)
operator|&
name|mismatched_before_winapi
expr_stmt|;
comment|// warns
comment|// Probably a bug, but we don't warn.
name|void
function_decl|(
modifier|*
name|callback2
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|mismatched
function_decl|;
name|take_callback
argument_list|(
operator|(
name|callback_t
operator|)
name|callback2
argument_list|)
expr_stmt|;
comment|// Another way to suppress the warning.
name|take_callback
argument_list|(
operator|(
name|callback_t
operator|)
operator|(
name|void
operator|*
operator|)
name|mismatched
argument_list|)
expr_stmt|;
comment|// Warn on declarations as well as definitions.
comment|// expected-warning@+1 {{cast between incompatible calling conventions 'cdecl' and 'stdcall'}}
name|take_callback
argument_list|(
operator|(
name|callback_t
operator|)
name|mismatched_declaration
argument_list|)
expr_stmt|;
comment|// expected-warning@+1 {{cast between incompatible calling conventions 'cdecl' and 'stdcall'}}
name|take_callback
argument_list|(
operator|(
name|callback_t
operator|)
name|suggest_fix_first_redecl
argument_list|)
expr_stmt|;
comment|// Don't warn, because we're casting from stdcall to cdecl. Usually that means
comment|// the programmer is rinsing the function pointer through some kind of opaque
comment|// API.
name|take_opaque_fn
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
name|mismatched_stdcall
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// MSFIXIT: fix-it:"{{.*}}callingconv-cast.c":{16:6-16:6}:"WINAPI "
end_comment

begin_comment
comment|// MSFIXIT: fix-it:"{{.*}}callingconv-cast.c":{16:6-16:6}:"WINAPI "
end_comment

begin_comment
comment|// MSFIXIT: fix-it:"{{.*}}callingconv-cast.c":{16:6-16:6}:"WINAPI "
end_comment

begin_comment
comment|// MSFIXIT: fix-it:"{{.*}}callingconv-cast.c":{7:6-7:6}:"__stdcall "
end_comment

begin_comment
comment|// GNUFIXIT: fix-it:"{{.*}}callingconv-cast.c":{16:6-16:6}:"WINAPI "
end_comment

begin_comment
comment|// GNUFIXIT: fix-it:"{{.*}}callingconv-cast.c":{16:6-16:6}:"WINAPI "
end_comment

begin_comment
comment|// GNUFIXIT: fix-it:"{{.*}}callingconv-cast.c":{16:6-16:6}:"WINAPI "
end_comment

begin_comment
comment|// GNUFIXIT: fix-it:"{{.*}}callingconv-cast.c":{7:6-7:6}:"__attribute__((stdcall)) "
end_comment

end_unit

