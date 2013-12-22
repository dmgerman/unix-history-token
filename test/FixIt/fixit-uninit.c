begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wuninitialized -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wuninitialized -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_function
name|_Bool
name|test_bool_no_false
parameter_list|()
block|{
name|_Bool
name|var
decl_stmt|;
comment|// expected-note {{initialize}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:12-[[@LINE-1]]:12}:" = 0"
return|return
name|var
return|;
comment|// expected-warning {{uninitialized}}
block|}
end_function

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_define
define|#
directive|define
name|false
value|(bool)0
end_define

begin_define
define|#
directive|define
name|true
value|(bool)1
end_define

begin_function
name|bool
name|test_bool_with_false
parameter_list|()
block|{
name|bool
name|var
decl_stmt|;
comment|// expected-note {{initialize}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:11-[[@LINE-1]]:11}:" = false"
return|return
name|var
return|;
comment|// expected-warning {{uninitialized}}
block|}
end_function

begin_function
name|bool
name|test_bool_with_false_undefined
parameter_list|()
block|{
name|bool
undef|#
directive|undef
name|false
name|var
decl_stmt|;
comment|// expected-note {{initialize}}
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:10}:" = 0"
return|return
name|var
return|;
comment|// expected-warning {{uninitialized}}
block|}
end_function

end_unit

