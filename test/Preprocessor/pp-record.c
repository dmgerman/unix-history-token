begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -detailed-preprocessing-record %s
end_comment

begin_comment
comment|// http://llvm.org/PR11120
end_comment

begin_define
define|#
directive|define
name|FILE_HEADER_NAME
value|"pp-record.h"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FILE_HEADER_NAME
argument_list|)
end_if

begin_include
include|#
directive|include
include|FILE_HEADER_NAME
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

