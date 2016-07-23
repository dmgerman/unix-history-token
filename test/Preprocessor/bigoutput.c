begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -x c %s> /dev/tty
end_comment

begin_comment
comment|// The original bug requires UNIX line endings to trigger.
end_comment

begin_comment
comment|// The original bug triggers only when outputting directly to console.
end_comment

begin_comment
comment|// REQUIRES: console
end_comment

begin_comment
comment|// Make sure clang does not crash during preprocessing
end_comment

begin_define
define|#
directive|define
name|M0
value|extern int x;
end_define

begin_define
define|#
directive|define
name|M2
value|M0  M0  M0  M0
end_define

begin_define
define|#
directive|define
name|M4
value|M2  M2  M2  M2
end_define

begin_define
define|#
directive|define
name|M6
value|M4  M4  M4  M4
end_define

begin_define
define|#
directive|define
name|M8
value|M6  M6  M6  M6
end_define

begin_define
define|#
directive|define
name|M10
value|M8  M8  M8  M8
end_define

begin_define
define|#
directive|define
name|M12
value|M10 M10 M10 M10
end_define

begin_define
define|#
directive|define
name|M14
value|M12 M12 M12 M12
end_define

begin_macro
name|M14
end_macro

end_unit

