begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Clang supports a very limited subset of -traditional-cpp, basically we only  * intend to add support for things that people actually rely on when doing  * things like using /usr/bin/cpp to preprocess non-source files. */
end_comment

begin_comment
comment|/*  RUN: %clang_cc1 -traditional-cpp %s -E | FileCheck -strict-whitespace %s  RUN: %clang_cc1 -traditional-cpp %s -E -C | FileCheck -check-prefix=CHECK-COMMENTS %s  RUN: %clang_cc1 -traditional-cpp -x c++ %s -E | FileCheck -check-prefix=CHECK-CXX %s */
end_comment

begin_comment
comment|/* -traditional-cpp should eliminate all C89 comments. */
end_comment

begin_comment
comment|/* CHECK-NOT: /*  * CHECK-COMMENTS: {{^}}/* -traditional-cpp should eliminate all C89 comments. *{{/$}}  */
end_comment

begin_comment
comment|/* -traditional-cpp should only eliminate "//" comments in C++ mode. */
end_comment

begin_comment
comment|/* CHECK: {{^}}foo // bar{{$}}  * CHECK-CXX: {{^}}foo {{$}}  */
end_comment

begin_expr_stmt
name|foo
comment|// bar
comment|/* The lines in this file contain hard tab characters and trailing whitespace;   * do not change them! */
comment|/* CHECK: {{^}}	indented!{{$}}  * CHECK: {{^}}tab	separated	values{{$}}  */
name|indented
operator|!
name|tab
name|separated
name|values
define|#
directive|define
name|bracket
parameter_list|(
name|x
parameter_list|)
value|>>>x<<<
name|bracket
argument_list|(
argument||  spaces  |
argument_list|)
comment|/* CHECK: {{^}}>>>|  spaces  |<<<{{$}}  */
comment|/* This is still a preprocessing directive. */
define|#
directive|define
name|foo
value|bar
name|foo
operator|!
operator|-
name|foo
operator|!
name|foo
operator|!
comment|/* CHECK: {{^}}bar!{{$}}  * CHECK: {{^}}	bar!	bar!	{{$}}  */
comment|/* Deliberately check a leading newline with spaces on that line. */
define|#
directive|define
name|foo
value|bar
name|foo
operator|!
operator|-
name|foo
operator|!
name|foo
operator|!
comment|/* CHECK: {{^}}bar!{{$}}  * CHECK: {{^}}	bar!	bar!	{{$}}  */
comment|/* FIXME: -traditional-cpp should not consider this a preprocessing directive  * because the # isn't in the first column.  */
define|#
directive|define
name|foo2
value|bar
name|foo2
operator|!
comment|/* If this were working, both of these checks would be on.  * CHECK-NOT: {{^}} #define foo2 bar{{$}}  * CHECK-NOT: {{^}}foo2!{{$}}  */
comment|/* FIXME: -traditional-cpp should not homogenize whitespace in macros.  */
define|#
directive|define
name|bracket2
parameter_list|(
name|x
parameter_list|)
value|>>>  x<<<
name|bracket2
argument_list|(
argument|spaces
argument_list|)
comment|/* If this were working, this check would be on.  * CHECK-NOT: {{^}}>>>  spaces<<<{{$}}  */
comment|/* Check that #if 0 blocks work as expected */
if|#
directive|if
literal|0
error|#
directive|error
literal|"this is not an error"
if|#
directive|if
literal|1
expr|a b c in skipped block
endif|#
directive|endif
comment|/* Comments are whitespace too */
endif|#
directive|endif
comment|/* CHECK-NOT: {{^}}a b c in skipped block{{$}}  * CHECK-NOT: {{^}}/* Comments are whitespace too  */
name|Preserve
name|URLs
operator|:
name|http
operator|:
comment|//clang.llvm.org
comment|/* CHECK: {{^}}Preserve URLs: http://clang.llvm.org{{$}}  */
comment|/* The following tests ensure we ignore # and ## in macro bodies */
define|#
directive|define
name|FOO_NO_STRINGIFY
parameter_list|(
name|a
parameter_list|)
value|test(# a)
name|FOO_NO_STRINGIFY
argument_list|(
argument|foobar
argument_list|)
comment|/* CHECK: {{^}}test(# foobar){{$}}  */
define|#
directive|define
name|FOO_NO_PASTE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|test(b##a)
name|FOO_NO_PASTE
argument_list|(
argument|foo
argument_list|,
argument|bar
argument_list|)
comment|/* CHECK {{^}}test(bar##foo){{$}}  */
define|#
directive|define
name|BAR_NO_STRINGIFY
parameter_list|(
name|a
parameter_list|)
value|test(#a)
name|BAR_NO_STRINGIFY
argument_list|(
argument|foobar
argument_list|)
end_expr_stmt

begin_comment
comment|/* CHECK: {{^}}test(#foobar){{$}}  */
end_comment

end_unit

