begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -include %s -verify -fsyntax-only -DSET
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -include %s -verify -fsyntax-only -DRESET
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -include %s -verify -fsyntax-only -DPUSH
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -include %s -verify -fsyntax-only -DPUSH_POP
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -include %s -verify -fsyntax-only -DPUSH_POP_LABEL
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DSET -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DSET -verify -include-pch %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DRESET -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DRESET -verify -include-pch %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DPUSH -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DPUSH -verify -include-pch %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DPUSH_POP -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DPUSH_POP -verify -include-pch %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DPUSH_POP_LABEL -emit-pch -o %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 %s -DPUSH_POP_LABEL -verify -include-pch %t
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SET
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RESET
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|2
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH_POP
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|4
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH_POP_LABEL
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|a
name|,
name|4
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|b
name|,
name|1
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|c
name|,
name|2
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|b
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SET
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 1}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// expected-warning {{#pragma pack(pop, ...) failed: stack empty}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RESET
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 8}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|(
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 8}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 2}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 1}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 8}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// expected-warning {{#pragma pack(pop, ...) failed: stack empty}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH_POP
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 4}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 8}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// expected-warning {{#pragma pack(pop, ...) failed: stack empty}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH_POP_LABEL
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 4}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|c
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 4}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|a
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 8}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// expected-warning {{#pragma pack(pop, ...) failed: stack empty}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|,
name|b
name|)
end_pragma

begin_comment
comment|// expected-warning {{#pragma pack(pop, ...) failed: stack empty}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|show
name|)
end_pragma

begin_comment
comment|// expected-warning {{value of #pragma pack(show) == 8}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

