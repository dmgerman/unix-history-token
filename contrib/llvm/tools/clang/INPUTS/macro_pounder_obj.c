begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This pounds on macro expansion for performance reasons.  This is currently
end_comment

begin_comment
comment|// heavily constrained by darwin's malloc.
end_comment

begin_comment
comment|// Object-like expansions
end_comment

begin_define
define|#
directive|define
name|A0
value|a b
end_define

begin_define
define|#
directive|define
name|A1
value|A0 A0 A0 A0 A0 A0
end_define

begin_define
define|#
directive|define
name|A2
value|A1 A1 A1 A1 A1 A1
end_define

begin_define
define|#
directive|define
name|A3
value|A2 A2 A2 A2 A2 A2
end_define

begin_define
define|#
directive|define
name|A4
value|A3 A3 A3 A3 A3 A3
end_define

begin_define
define|#
directive|define
name|A5
value|A4 A4 A4 A4 A4 A4
end_define

begin_define
define|#
directive|define
name|A6
value|A5 A5 A5 A5 A5 A5
end_define

begin_define
define|#
directive|define
name|A7
value|A6 A6 A6 A6 A6 A6
end_define

begin_define
define|#
directive|define
name|A8
value|A7 A7 A7 A7 A7 A7
end_define

begin_macro
name|A8
end_macro

end_unit

