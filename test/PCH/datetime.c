begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c-header %s -emit-pch -o %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: precompiled header uses __DATE__ or __TIME__
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|p
init|=
name|__DATE__
decl_stmt|;
end_decl_stmt

end_unit

