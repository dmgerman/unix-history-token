begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-apple-darwin9 -fsyntax-only -verify %s
end_comment

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 8}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|/* expected-warning {{expected #pragma pack parameter to be}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|3
name|)
end_pragma

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 8}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 4}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|// resets to default
end_comment

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 8}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|2
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|eek
name|,
name|16
name|)
end_pragma

begin_comment
comment|// -> (eek, 2), 16
end_comment

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 16}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_comment
comment|// -> (eek, 2), (, 2), 16
end_comment

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 16}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|8
name|)
end_pragma

begin_comment
comment|// -> (eek, 2), (, 2), (, 1), 8
end_comment

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 8}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// -> (eek, 2), (,2), 1
end_comment

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 1}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|eek
name|)
end_pragma

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 2}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|/* expected-warning {{pack(pop, ...) failed: stack empty}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|16
name|)
end_pragma

begin_comment
comment|/* expected-warning {{value of #pragma pack(show) == 16}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

end_unit

