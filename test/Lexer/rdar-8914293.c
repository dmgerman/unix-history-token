begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar://8914293
end_comment

begin_comment
comment|// We want be compatible with gcc and warn, not error.
end_comment

begin_comment
comment|/* expected-warning {{missing terminating}} */
end_comment

begin_define
define|#
directive|define
name|FOO
value|"foo
end_define

begin_comment
comment|/* expected-warning {{missing terminating}} */
end_comment

begin_define
define|#
directive|define
name|KOO
value|'k
end_define

end_unit

