begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x objective-c -fmodule-cache-path %t -fauto-module-import -F %S/Inputs -verify %s
end_comment

begin_include
include|#
directive|include
file|<DependsOnModule/DependsOnModule.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MODULE_H_MACRO
end_ifdef

begin_error
error|#
directive|error
error|MODULE_H_MACRO should have been hidden
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEPENDS_ON_MODULE
end_ifdef

begin_error
error|#
directive|error
error|DEPENDS_ON_MODULE should have been hidden
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

