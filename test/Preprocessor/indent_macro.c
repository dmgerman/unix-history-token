begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^   zzap$'
end_comment

begin_comment
comment|// zzap is on a new line, should be indented.
end_comment

begin_define
define|#
directive|define
name|BLAH
value|zzap
end_define

begin_macro
name|BLAH
end_macro

end_unit

