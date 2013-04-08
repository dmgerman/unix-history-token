begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t1.pch -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-pch -o %t2.pch -include-pch %t1.pch -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -include-pch %t2.pch -verify
end_comment

begin_comment
comment|// Test that a redefinition inside the PCH won't manifest as an ambiguous macro.
end_comment

begin_comment
comment|// rdar://13016031
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER1
end_ifndef

begin_define
define|#
directive|define
name|HEADER1
end_define

begin_define
define|#
directive|define
name|M1
value|0
end_define

begin_comment
comment|// expected-note {{previous}}
end_comment

begin_define
define|#
directive|define
name|M1
value|1
end_define

begin_comment
comment|// expected-warning {{redefined}}
end_comment

begin_define
define|#
directive|define
name|M2
value|3
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|HEADER2
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HEADER2
end_define

begin_define
define|#
directive|define
name|M2
value|4
end_define

begin_comment
comment|// expected-warning {{redefined}}
end_comment

begin_comment
comment|// expected-note@-6 {{previous}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Use the error to verify it was parsed.
end_comment

begin_decl_stmt
name|int
name|x
init|=
name|M1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous}}
end_comment

begin_decl_stmt
name|int
name|x
init|=
name|M2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

