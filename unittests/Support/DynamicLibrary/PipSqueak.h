begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/unittest/Support/DynamicLibrary/PipSqueak.h -------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_PIPSQUEAK_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PIPSQUEAK_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|// Disable warnings from inclusion of xlocale& exception
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4530
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4577
name|)
end_pragma

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|PIPSQUEAK_EXPORT
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIPSQUEAK_EXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
name|PIPSQUEAK_EXPORT
specifier|const
name|char
modifier|*
name|TestA
parameter_list|()
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

