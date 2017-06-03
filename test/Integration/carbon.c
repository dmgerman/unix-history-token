begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only %s
end_comment

begin_comment
comment|// REQUIRES: macos-sdk-10.12
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<Carbon/Carbon.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

