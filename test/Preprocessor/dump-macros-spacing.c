begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dD< %s | grep stdin | grep -v define
end_comment

begin_define
define|#
directive|define
name|A
value|A
end_define

begin_comment
comment|/* 1  * 2  * 3  * 4  * 5  * 6  * 7  * 8  */
end_comment

begin_define
define|#
directive|define
name|B
value|B
end_define

end_unit

