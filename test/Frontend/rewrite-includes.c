begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -verify -E -frewrite-includes -DFIRST -I %S/Inputs %s -o - | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -verify -E -frewrite-includes -P -DFIRST -I %S/Inputs %s -o - | FileCheck -check-prefix=CHECKNL -strict-whitespace %s
end_comment

begin_comment
comment|// STARTCOMPARE
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_macro
name|A
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_include
include|#
directive|include
file|"rewrite-includes1.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FIRST
end_ifdef

begin_define
define|#
directive|define
name|HEADER
value|"rewrite-includes3.h"
end_define

begin_include
include|#
directive|include
include|HEADER
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"rewrite-includes4.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// indented
end_comment

begin_include
include|#
comment|/**/
directive|include
comment|/**/
file|"rewrite-includes5.h"
end_include

begin_comment
comment|/**/
end_comment

begin_include
unit|\
include|#
directive|include
file|"rewrite-includes6.h"
end_include

begin_comment
comment|// comment
end_comment

begin_include
include|#
directive|include
file|"rewrite-includes6.h"
end_include

begin_comment
comment|/* comment                                   continues */
end_comment

begin_include
include|#
directive|include
file|"rewrite-includes7.h"
end_include

begin_include
include|#
directive|include
file|"rewrite-includes7.h"
end_include

begin_include
include|#
directive|include
file|"rewrite-includes8.h"
end_include

begin_comment
comment|// ENDCOMPARE
end_comment

begin_comment
comment|// CHECK: {{^}}# 1 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK: {{^}}// STARTCOMPARE{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#define A(a,b) a ## b{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}A(1,2){{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes1.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 6 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes1.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#pragma clang system_header{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 2 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes1.h" 3{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes2.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 3 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes1.h" 3{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes2.h" 1 3{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 4 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes1.h" 2 3{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 7 "{{.*}}rewrite-includes.c" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#ifdef FIRST{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#define HEADER "rewrite-includes3.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include HEADER{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 9 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes3.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line3{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 10 "{{.*}}rewrite-includes.c" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#else{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 11 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes4.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 11 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 12 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 13 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}  // indented{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#/**/include /**/ "rewrite-includes5.h" /**/ {{\\}}{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}} {{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 15 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes5.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line5{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 16 "{{.*}}rewrite-includes.c" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes6.h" // comment{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 16 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes6.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#pragma once{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 2 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes6.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line6{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 17 "{{.*}}rewrite-includes.c" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}} {{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes6.h" /* comment{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}                                  continues */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 19 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 20 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes7.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 20 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes7.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#ifndef REWRITE_INCLUDES_7{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#define REWRITE_INCLUDES_7{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line7{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 5 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes7.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 21 "{{.*}}rewrite-includes.c" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes7.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 21 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 22 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "rewrite-includes8.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 22 "{{.*}}rewrite-includes.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes8.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if (1)/*__has_include_next(<rewrite-includes8.h>)*/{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#elif (0)/*__has_include(<rewrite-includes8.hfail>)*/{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 3 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes8.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 4 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes8.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#if !(1)/*__has_include("rewrite-includes8.h")*/{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 6 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes8.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 23 "{{.*}}rewrite-includes.c" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}// ENDCOMPARE{{$}}
end_comment

begin_comment
comment|// CHECKNL: {{^}}// STARTCOMPARE{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#define A(a,b) a ## b{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}A(1,2){{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes1.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#pragma clang system_header{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}included_line1{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes2.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}included_line2{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#ifdef FIRST{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#define HEADER "rewrite-includes3.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include HEADER{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}included_line3{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#else{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes4.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}  // indented{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#/**/include /**/ "rewrite-includes5.h" /**/ {{\\}}{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}} {{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}included_line5{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes6.h" // comment{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#pragma once{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}included_line6{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}} {{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes6.h" /* comment{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}                                  continues */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes7.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#ifndef REWRITE_INCLUDES_7{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#define REWRITE_INCLUDES_7{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}included_line7{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes7.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#include "rewrite-includes8.h"{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if (1)/*__has_include_next(<rewrite-includes8.h>)*/{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#elif (0)/*__has_include(<rewrite-includes8.hfail>)*/{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#if !(1)/*__has_include("rewrite-includes8.h")*/{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}#endif{{$}}
end_comment

begin_comment
comment|// CHECKNL-NEXT: {{^}}// ENDCOMPARE{{$}}
end_comment

end_unit

