begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -DPP_ONLY=1 %s -o %t
end_comment

begin_comment
comment|// RUN: FileCheck --strict-whitespace --input-file=%t %s
end_comment

begin_comment
comment|// This file contains Unicode characters; please do not "fix" them!
end_comment

begin_extern
extern|extern intÂ x;
end_extern

begin_comment
comment|// expected-warning {{treating Unicode character as whitespace}}
end_comment

begin_extern
extern|extern intãx;
end_extern

begin_comment
comment|// expected-warning {{treating Unicode character as whitespace}}
end_comment

begin_comment
comment|// CHECK: extern intÂ {{x}}
end_comment

begin_comment
comment|// CHECK: extern intã{{x}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|mark
name|Â¡Unicode
name|!
end_pragma

begin_define
define|#
directive|define
name|COPYRIGHT
value|Copyright Â© 2012
end_define

begin_define
define|#
directive|define
name|XSTR
parameter_list|(
name|X
parameter_list|)
value|#X
end_define

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|X
parameter_list|)
value|XSTR(X)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|copyright
init|=
name|STR
argument_list|(
name|COPYRIGHT
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_comment
comment|// CHECK: static const char *copyright = "Copyright Â© {{2012}}";
end_comment

begin_if
if|#
directive|if
name|PP_ONLY
end_if

begin_decl_stmt
name|COPYRIGHT
comment|// CHECK: Copyright Â© {{2012}}
name|CHECK
range|:
name|The
name|preprocessor
name|should
name|not
name|complain
name|about
name|Unicode
name|characters
name|like
name|Â©
operator|.
endif|#
directive|endif
end_decl_stmt

end_unit

