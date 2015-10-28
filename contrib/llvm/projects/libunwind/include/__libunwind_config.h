begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------------- __libunwind_config.h -----------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|____LIBUNWIND_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|____LIBUNWIND_CONFIG_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__USING_SJLJ_EXCEPTIONS__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__ARM_DWARF_EH__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_ARM_EHABI
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_LIBUNWIND_ARM_EHABI
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ____LIBUNWIND_CONFIG_H__
end_comment

end_unit

