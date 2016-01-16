begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===----------------------- support/ibm/support.h ----------------------===//
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
name|_LIBCPP_SUPPORT_IBM_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_IBM_SUPPORT_H
end_define

begin_extern
extern|extern
literal|"builtin"
name|int
name|__popcnt4
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"builtin"
name|int
name|__popcnt8
parameter_list|(
name|unsigned
name|long
name|long
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"builtin"
name|unsigned
name|int
name|__cnttz4
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"builtin"
name|unsigned
name|int
name|__cnttz8
parameter_list|(
name|unsigned
name|long
name|long
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"builtin"
name|unsigned
name|int
name|__cntlz4
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"builtin"
name|unsigned
name|int
name|__cntlz8
parameter_list|(
name|unsigned
name|long
name|long
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|// Builtin functions for counting population
end_comment

begin_define
define|#
directive|define
name|__builtin_popcount
parameter_list|(
name|x
parameter_list|)
value|__popcnt4(x)
end_define

begin_define
define|#
directive|define
name|__builtin_popcountll
parameter_list|(
name|x
parameter_list|)
value|__popcnt8(x)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__builtin_popcountl
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcountll(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__builtin_popcountl
parameter_list|(
name|x
parameter_list|)
value|__builtin_popcount(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Builtin functions for counting trailing zeros
end_comment

begin_define
define|#
directive|define
name|__builtin_ctz
parameter_list|(
name|x
parameter_list|)
value|__cnttz4(x)
end_define

begin_define
define|#
directive|define
name|__builtin_ctzll
parameter_list|(
name|x
parameter_list|)
value|__cnttz8(x)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__builtin_ctzl
parameter_list|(
name|x
parameter_list|)
value|__builtin_ctzll(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__builtin_ctzl
parameter_list|(
name|x
parameter_list|)
value|__builtin_ctz(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Builtin functions for counting leading zeros
end_comment

begin_define
define|#
directive|define
name|__builtin_clz
parameter_list|(
name|x
parameter_list|)
value|__cntlz4(x)
end_define

begin_define
define|#
directive|define
name|__builtin_clzll
parameter_list|(
name|x
parameter_list|)
value|__cntlz8(x)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__builtin_clzl
parameter_list|(
name|x
parameter_list|)
value|__builtin_clzll(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__builtin_clzl
parameter_list|(
name|x
parameter_list|)
value|__builtin_clz(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__SIZE_WIDTH__
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__SIZE_WIDTH__
value|32
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
comment|// _LIBCPP_SUPPORT_IBM_SUPPORT_H
end_comment

end_unit

