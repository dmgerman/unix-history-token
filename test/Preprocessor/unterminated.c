begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -verify %s
end_comment

begin_comment
comment|// PR3096
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOO
end_ifdef

begin_comment
comment|// expected-error {{unterminated conditional directive}}
end_comment

begin_comment
comment|/* /* */
end_comment

end_unit

