begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|start
end_pragma

begin_comment
comment|// expected-error{{expected 'begin' or 'end'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_comment
comment|// expected-note{{#pragma entered here}}
end_comment

begin_include
include|#
directive|include
file|"nullability-pragmas-3.h"
end_include

begin_comment
comment|// expected-error{{cannot #include files inside '#pragma clang assume_nonnull'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_comment
comment|// expected-note{{#pragma entered here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_comment
comment|// expected-error{{already inside '#pragma clang assume_nonnull'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|end
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_comment
comment|// expected-error{{'#pragma clang assume_nonnull' was not ended within this file}}
end_comment

end_unit

