begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|OBSCURE
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_define
define|#
directive|define
name|DECORATION
end_define

begin_define
define|#
directive|define
name|FNM
parameter_list|(
name|X
parameter_list|)
value|OBSCURE(X)
end_define

begin_typedef
typedef|typedef
name|int
name|T
typedef|;
end_typedef

begin_function
name|void
name|OBSCURE
function|(
name|func
function|)
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|OBSCURE
argument_list|(
argument|T
argument_list|)
name|DECORATION
name|value
decl_stmt|;
block|}
end_function

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_define
define|#
directive|define
name|A
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|X
parameter_list|)
value|A(X)
end_define

begin_macro
name|B
argument_list|(
argument|int x
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|fname
init|=
name|__FILE__
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<a.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OBSCURE
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBSCURE
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|C
parameter_list|(
name|A
parameter_list|)
value|A
end_define

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:1:11 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-1 %s
end_comment

begin_comment
comment|// CHECK-1: macro definition=OBSCURE
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:2:14 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-2 %s
end_comment

begin_comment
comment|// CHECK-2: macro definition=DECORATION
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:5:7 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-3 %s
end_comment

begin_comment
comment|// CHECK-3: macro expansion=OBSCURE:1:9
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:6:6 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-4 %s
end_comment

begin_comment
comment|// CHECK-4: macro expansion=OBSCURE:1:9
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:6:19 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-5 %s
end_comment

begin_comment
comment|// CHECK-5: macro expansion=DECORATION:2:9
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:9:10 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-6 %s
end_comment

begin_comment
comment|// CHECK-6: inclusion directive=a.h
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:14:1 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-7 %s
end_comment

begin_comment
comment|// CHECK-7: macro expansion=B:12:9
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:16:25 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-8 %s
end_comment

begin_comment
comment|// CHECK-8: macro expansion=__FILE__
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:18:12 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-9 %s
end_comment

begin_comment
comment|// CHECK-9: inclusion directive=a.h
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:20:10 -cursor-at=%s:23:15 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-10 %s
end_comment

begin_comment
comment|// CHECK-10: 20:8 macro expansion=OBSCURE
end_comment

begin_comment
comment|// CHECK-10: 23:13 macro expansion=OBSCURE
end_comment

begin_comment
comment|// RUN: c-index-test -cursor-at=%s:3:20 -cursor-at=%s:12:14 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:26:11 -cursor-at=%s:26:14 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-IN-MACRODEF %s
end_comment

begin_comment
comment|// CHECK-IN-MACRODEF: 3:16 macro expansion=OBSCURE
end_comment

begin_comment
comment|// CHECK-IN-MACRODEF: 12:14 macro expansion=A
end_comment

begin_comment
comment|// CHECK-IN-MACRODEF: 26:9 macro definition=C
end_comment

begin_comment
comment|// CHECK-IN-MACRODEF: 26:9 macro definition=C
end_comment

begin_comment
comment|// Same tests, but with "editing" optimizations
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -cursor-at=%s:1:11 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-1 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -cursor-at=%s:2:14 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-2 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -cursor-at=%s:5:7 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-3 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -cursor-at=%s:9:10 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-6 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -cursor-at=%s:3:20 -cursor-at=%s:12:14 \
end_comment

begin_comment
comment|// RUN:              -cursor-at=%s:26:11 -cursor-at=%s:26:14 -I%S/Inputs %s | FileCheck -check-prefix=CHECK-IN-MACRODEF %s
end_comment

end_unit

