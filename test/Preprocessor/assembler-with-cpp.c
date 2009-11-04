begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -x assembler-with-cpp -fdollars-in-identifiers=0 -E %s -o - | FileCheck -strict-whitespace -check-prefix=CHECK-Identifiers-False %s&&
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_error
error|#
directive|error
literal|"__ASSEMBLER__ not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Invalid token pasting is ok.
end_comment

begin_define
define|#
directive|define
name|A
value|X ## .
end_define

begin_expr_stmt
literal|1
operator|:
name|A
comment|// CHECK-Identifiers-False: 1: X .
comment|// Line markers are not linemarkers in .S files, they are passed through.
empty|# 321
comment|// CHECK-Identifiers-False: # 321
comment|// Unknown directives are passed through.
empty|# B C
comment|// CHECK-Identifiers-False: # B C
comment|// Unknown directives are expanded.
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|BAR ## x
empty|# D(42)
comment|// CHECK-Identifiers-False: # BAR42
comment|// Unmatched quotes are permitted.
literal|2
operator|:
literal|' 3: " // CHECK-Identifiers-False: 2: '
comment|// CHECK-Identifiers-False: 3: "
comment|// (balance quotes to keep editors happy): "'
comment|// Empty char literals are ok.
literal|4
operator|:
literal|''
comment|// CHECK-Identifiers-False: 4: ''
comment|// Portions of invalid pasting should still expand as macros.
comment|// rdar://6709206
define|#
directive|define
name|M4
value|expanded
define|#
directive|define
name|M5
parameter_list|()
value|M4 ## (
literal|5
operator|:
name|M5
argument_list|()
comment|// CHECK-Identifiers-False: 5: expanded (
comment|// rdar://6804322
define|#
directive|define
name|FOO
parameter_list|(
name|name
parameter_list|)
value|name ## $foo
literal|6
operator|:
name|FOO
argument_list|(
name|blarg
argument_list|)
comment|// CHECK-Identifiers-False: 6: blarg $foo
comment|// RUN: clang-cc -x assembler-with-cpp -fdollars-in-identifiers=1 -E %s -o - | FileCheck -check-prefix=CHECK-Identifiers-True -strict-whitespace %s&&
define|#
directive|define
name|FOO
parameter_list|(
name|name
parameter_list|)
value|name ## $foo
literal|7
operator|:
name|FOO
argument_list|(
name|blarg
argument_list|)
comment|// CHECK-Identifiers-True: 7: blarg$foo
comment|//
define|#
directive|define
name|T6
parameter_list|()
value|T6 #nostring
define|#
directive|define
name|T7
parameter_list|(
name|x
parameter_list|)
value|T7 #x
literal|8
operator|:
name|T6
argument_list|()
literal|9
operator|:
name|T7
argument_list|(
name|foo
argument_list|)
comment|// CHECK-Identifiers-True: 8: T6 #nostring
comment|// CHECK-Identifiers-True: 9: T7 "foo"
comment|// Concatenation with period doesn't leave a space
define|#
directive|define
name|T8
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A ## B
literal|10
operator|:
name|T8
argument_list|(
operator|.
argument_list|,
name|T8
argument_list|)
comment|// CHECK-Identifiers-True: 10: .T8
comment|// This should not crash.
define|#
directive|define
name|T11
parameter_list|(
name|a
parameter_list|)
value|#0
literal|11
operator|:
name|T11
argument_list|(
argument|b
argument_list|)
end_expr_stmt

begin_comment
comment|// CHECK-Identifiers-True: 11: #0
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

