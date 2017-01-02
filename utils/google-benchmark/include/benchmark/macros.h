begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2015 Google Inc. All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Licensed under the Apache License, Version 2.0 (the "License");
end_comment

begin_comment
comment|// you may not use this file except in compliance with the License.
end_comment

begin_comment
comment|// You may obtain a copy of the License at
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     http://www.apache.org/licenses/LICENSE-2.0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Unless required by applicable law or agreed to in writing, software
end_comment

begin_comment
comment|// distributed under the License is distributed on an "AS IS" BASIS,
end_comment

begin_comment
comment|// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
end_comment

begin_comment
comment|// See the License for the specific language governing permissions and
end_comment

begin_comment
comment|// limitations under the License.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_MACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_MACROS_H_
end_define

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_define
define|#
directive|define
name|BENCHMARK_HAS_CXX11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_HAS_CXX11
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|TypeName(const TypeName&);                         \   TypeName& operator=(const TypeName&)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|TypeName(const TypeName&) = delete;                \   TypeName& operator=(const TypeName&) = delete
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
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_UNUSED
value|__attribute__((unused))
end_define

begin_define
define|#
directive|define
name|BENCHMARK_ALWAYS_INLINE
value|__attribute__((always_inline))
end_define

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT
value|noexcept
end_define

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT_OP
parameter_list|(
name|x
parameter_list|)
value|noexcept(x)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BENCHMARK_UNUSED
end_define

begin_define
define|#
directive|define
name|BENCHMARK_ALWAYS_INLINE
value|__forceinline
end_define

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1900
end_if

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT
value|noexcept
end_define

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT_OP
parameter_list|(
name|x
parameter_list|)
value|noexcept(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT
end_define

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT_OP
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__func__
value|__FUNCTION__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_UNUSED
end_define

begin_define
define|#
directive|define
name|BENCHMARK_ALWAYS_INLINE
end_define

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT
end_define

begin_define
define|#
directive|define
name|BENCHMARK_NOEXCEPT_OP
parameter_list|(
name|x
parameter_list|)
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
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_BUILTIN_EXPECT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__builtin_expect(x, y)
end_define

begin_define
define|#
directive|define
name|BENCHMARK_DEPRECATED_MSG
parameter_list|(
name|msg
parameter_list|)
value|__attribute__((deprecated(msg)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_BUILTIN_EXPECT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|BENCHMARK_DEPRECATED_MSG
parameter_list|(
name|msg
parameter_list|)
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
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_GCC_VERSION
value|(__GNUC__ * 100 + __GNUC_MINOR__)
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
comment|// BENCHMARK_MACROS_H_
end_comment

end_unit

