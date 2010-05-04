begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang-cc1 -fsyntax-only -fmacro-backtrace-limit 5 %s> %t 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t
end_comment

begin_define
define|#
directive|define
name|M1
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)< (B))
end_define

begin_define
define|#
directive|define
name|M2
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M1(A, B)
end_define

begin_define
define|#
directive|define
name|M3
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M2(A, B)
end_define

begin_define
define|#
directive|define
name|M4
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M3(A, B)
end_define

begin_define
define|#
directive|define
name|M5
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M4(A, B)
end_define

begin_define
define|#
directive|define
name|M6
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M5(A, B)
end_define

begin_define
define|#
directive|define
name|M7
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M6(A, B)
end_define

begin_define
define|#
directive|define
name|M8
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M7(A, B)
end_define

begin_define
define|#
directive|define
name|M9
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M8(A, B)
end_define

begin_define
define|#
directive|define
name|M10
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M9(A, B)
end_define

begin_define
define|#
directive|define
name|M11
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M10(A, B)
end_define

begin_define
define|#
directive|define
name|M12
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|M11(A, B)
end_define

begin_function
name|void
name|f
parameter_list|(
name|int
modifier|*
name|ip
parameter_list|,
name|float
modifier|*
name|fp
parameter_list|)
block|{
comment|// CHECK: macro-backtrace-limit.c:31:7: warning: comparison of distinct pointer types ('int *' and 'float *')
comment|// CHECK: if (M12(ip, fp)) { }
comment|// CHECK: macro-backtrace-limit.c:15:19: note: instantiated from:
comment|// CHECK: #define M12(A, B) M11(A, B)
comment|// CHECK: macro-backtrace-limit.c:14:19: note: instantiated from:
comment|// CHECK: #define M11(A, B) M10(A, B)
comment|// CHECK: note: (skipping 7 contexts in backtrace; use -fmacro-backtrace-limit=0 to see all)
comment|// CHECK: macro-backtrace-limit.c:6:18: note: instantiated from:
comment|// CHECK: #define M3(A, B) M2(A, B)
comment|// CHECK: macro-backtrace-limit.c:5:18: note: instantiated from:
comment|// CHECK: #define M2(A, B) M1(A, B)
comment|// CHECK: macro-backtrace-limit.c:4:23: note: instantiated from:
comment|// CHECK: #define M1(A, B) ((A)< (B))
if|if
condition|(
name|M12
argument_list|(
name|ip
argument_list|,
name|fp
argument_list|)
condition|)
block|{ }
block|}
end_function

end_unit

