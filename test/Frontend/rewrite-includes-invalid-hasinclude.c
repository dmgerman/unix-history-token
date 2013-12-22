begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -E -frewrite-includes -DFIRST -I %S/Inputs %s -o - | FileCheck -strict-whitespace %s
end_comment

begin_if
if|#
directive|if
name|__has_include
name|bar
operator|.
name|h
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include
argument_list|(
name|bar
operator|.
name|h
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|bar
operator|.
name|h
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CHECK: #if __has_include bar.h
end_comment

begin_comment
comment|// CHECK: #endif
end_comment

begin_comment
comment|// CHECK: #if __has_include(bar.h)
end_comment

begin_comment
comment|// CHECK: #endif
end_comment

begin_comment
comment|// CHECK: #if __has_include(<bar.h)
end_comment

begin_comment
comment|// CHECK: #endif
end_comment

end_unit

