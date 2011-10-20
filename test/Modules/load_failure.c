begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|NONEXISTENT
end_ifdef

begin_decl_stmt
name|__import_module__
name|load_nonexistent
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FAILURE
end_ifdef

begin_decl_stmt
name|__import_module__
name|load_failure
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: %clang_cc1 -x c++ -emit-module -o %T/load_failure.pcm %S/Inputs/load_failure.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodule-cache-path %T -fdisable-module-hash %s -DNONEXISTENT 2>&1 | FileCheck -check-prefix=CHECK-NONEXISTENT %s
end_comment

begin_comment
comment|// CHECK-NONEXISTENT: load_failure.c:2:19: fatal error: module 'load_nonexistent' not found
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fmodule-cache-path %T -fdisable-module-hash %s -DFAILURE 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-FAILURE %s< %t
end_comment

begin_comment
comment|// FIXME: Clean up diagnostic text below and give it a location
end_comment

begin_comment
comment|// CHECK-FAILURE: error: C99 was disabled in PCH file but is currently enabled
end_comment

end_unit

