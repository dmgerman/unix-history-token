begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Tests for macro expansion backtraces. The RUN and CHECK lines are grouped
end_comment

begin_comment
comment|// below the test code to reduce noise when updating them.
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
comment|// RUN: %clang_cc1 -fsyntax-only -fmacro-backtrace-limit 5 %s 2>&1 \
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-LIMIT
comment|// CHECK-LIMIT: macro-backtrace.c:18:7: warning: comparison of distinct pointer types ('int *' and 'float *')
comment|// CHECK-LIMIT: if (M12(ip, fp)) { }
comment|// CHECK-LIMIT: macro-backtrace.c:15:19: note: expanded from macro 'M12'
comment|// CHECK-LIMIT: #define M12(A, B) M11(A, B)
comment|// CHECK-LIMIT: macro-backtrace.c:14:19: note: expanded from macro 'M11'
comment|// CHECK-LIMIT: #define M11(A, B) M10(A, B)
comment|// CHECK-LIMIT: note: (skipping 7 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
comment|// CHECK-LIMIT: macro-backtrace.c:6:18: note: expanded from macro 'M3'
comment|// CHECK-LIMIT: #define M3(A, B) M2(A, B)
comment|// CHECK-LIMIT: macro-backtrace.c:5:18: note: expanded from macro 'M2'
comment|// CHECK-LIMIT: #define M2(A, B) M1(A, B)
comment|// CHECK-LIMIT: macro-backtrace.c:4:23: note: expanded from macro 'M1'
comment|// CHECK-LIMIT: #define M1(A, B) ((A)< (B))
comment|// RUN: %clang_cc1 -fsyntax-only -fno-caret-diagnostics %s 2>&1 \
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-NO-CARETS
comment|// CHECK-NO-CARETS: macro-backtrace.c:18:7: warning: comparison of distinct pointer types ('int *' and 'float *')
comment|// CHECK-NO-CARETS-NEXT: macro-backtrace.c:15:19: note: expanded from macro 'M12'
comment|// CHECK-NO-CARETS-NEXT: macro-backtrace.c:14:19: note: expanded from macro 'M11'
comment|// CHECK-NO-CARETS-NEXT: macro-backtrace.c:13:19: note: expanded from macro 'M10'
comment|// CHECK-NO-CARETS-NEXT: note: (skipping 6 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
comment|// CHECK-NO-CARETS-NEXT: macro-backtrace.c:6:18: note: expanded from macro 'M3'
comment|// CHECK-NO-CARETS-NEXT: macro-backtrace.c:5:18: note: expanded from macro 'M2'
comment|// CHECK-NO-CARETS-NEXT: macro-backtrace.c:4:23: note: expanded from macro 'M1'
comment|// Check that the expansion notes respect the same formatting options as
comment|// other diagnostics.
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-format vi %s 2>&1 \
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-NOTE-FORMAT
comment|// CHECK-NOTE-FORMAT: macro-backtrace.c +18:7: warning:
comment|// CHECK-NOTE-FORMAT: macro-backtrace.c +15:19: note:
comment|// CHECK-NOTE-FORMAT: macro-backtrace.c +14:19: note:
comment|// CHECK-NOTE-FORMAT: note:
comment|// CHECK-NOTE-FORMAT: macro-backtrace.c +6:18: note:
comment|// CHECK-NOTE-FORMAT: macro-backtrace.c +5:18: note:
comment|// CHECK-NOTE-FORMAT: macro-backtrace.c +4:23: note:
block|}
end_function

end_unit

