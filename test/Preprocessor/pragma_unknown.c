begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s | grep '#pragma foo bar'
end_comment

begin_comment
comment|// RUN: clang-cc -fsyntax-only -Wunknown-pragmas -verify %s
end_comment

begin_comment
comment|// GCC doesn't expand macro args for unrecognized pragmas.
end_comment

begin_define
define|#
directive|define
name|bar
value|xX
end_define

begin_pragma
pragma|#
directive|pragma
name|foo
name|bar
end_pragma

begin_comment
comment|// expected-warning {{unknown pragma ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|ON
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|OFF
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|DEFAULT
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FP_CONTRACT
name|IN_BETWEEN
end_pragma

begin_comment
comment|// expected-warning {{expected 'ON' or 'OFF' or 'DEFAULT' in pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FENV_ACCESS
name|ON
end_pragma

begin_comment
comment|// expected-warning {{pragma STDC FENV_ACCESS ON is not supported, ignoring pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FENV_ACCESS
name|OFF
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FENV_ACCESS
name|DEFAULT
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|FENV_ACCESS
name|IN_BETWEEN
end_pragma

begin_comment
comment|// expected-warning {{expected 'ON' or 'OFF' or 'DEFAULT' in pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
name|ON
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
name|OFF
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
name|DEFAULT
end_pragma

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
name|IN_BETWEEN
end_pragma

begin_comment
comment|// expected-warning {{expected 'ON' or 'OFF' or 'DEFAULT' in pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
end_pragma

begin_comment
comment|// expected-warning {{expected 'ON' or 'OFF' or 'DEFAULT' in pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
name|ON
name|FULL
name|POWER
end_pragma

begin_comment
comment|// expected-warning {{expected end of macro in STDC pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
name|SO_GREAT
end_pragma

begin_comment
comment|// expected-warning {{unknown pragma in STDC namespace}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|STDC
end_pragma

begin_comment
comment|// expected-warning {{unknown pragma in STDC namespace}}
end_comment

end_unit

