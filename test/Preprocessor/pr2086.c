begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s
end_comment

begin_define
define|#
directive|define
name|test
end_define

begin_include
include|#
directive|include
file|"pr2086.h"
end_include

begin_define
define|#
directive|define
name|test
end_define

begin_include
include|#
directive|include
file|"pr2086.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|test
end_ifdef

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

