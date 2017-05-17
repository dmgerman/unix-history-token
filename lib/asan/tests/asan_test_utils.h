begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_test_utils.h ---------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
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
name|ASAN_TEST_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_TEST_UTILS_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SANITIZER_EXTERNAL_TEST_CONFIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCLUDED_FROM_ASAN_TEST_UTILS_H
end_define

begin_include
include|#
directive|include
file|"asan_test_config.h"
end_include

begin_undef
undef|#
directive|undef
name|INCLUDED_FROM_ASAN_TEST_UTILS_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sanitizer_test_utils.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_pthread_wrappers.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<sys/prctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ASAN_HAS_EXCEPTIONS
end_if

begin_define
define|#
directive|define
name|ASAN_THROW
parameter_list|(
name|x
parameter_list|)
value|throw (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_THROW
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint8_t
name|U1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|U2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|U4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|U8
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|int
name|kPageSize
init|=
literal|4096
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Big enough to be handled by secondary allocator and small enough to fit into
end_comment

begin_comment
comment|// quarantine for all configurations.
end_comment

begin_decl_stmt
specifier|const
name|size_t
name|kLargeMalloc
init|=
literal|1
operator|<<
literal|22
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|free_aaa
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc_aaa
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|NOINLINE
name|void
name|asan_write
argument_list|(
argument|T *a
argument_list|)
block|{
operator|*
name|a
operator|=
literal|0
block|; }
name|string
name|RightOOBErrorMessage
argument_list|(
argument|int oob_distance
argument_list|,
argument|bool is_write
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|string
name|RightOOBWriteMessage
parameter_list|(
name|int
name|oob_distance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|string
name|RightOOBReadMessage
parameter_list|(
name|int
name|oob_distance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|string
name|LeftOOBErrorMessage
parameter_list|(
name|int
name|oob_distance
parameter_list|,
name|bool
name|is_write
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|string
name|LeftOOBWriteMessage
parameter_list|(
name|int
name|oob_distance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|string
name|LeftOOBReadMessage
parameter_list|(
name|int
name|oob_distance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|string
name|LeftOOBAccessMessage
parameter_list|(
name|int
name|oob_distance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MallocAndMemsetString
parameter_list|(
name|size_t
name|size
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MallocAndMemsetString
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|glob1
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob2
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob3
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob4
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob5
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob6
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob7
index|[
literal|7
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob8
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob9
index|[
literal|9
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob10
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob11
index|[
literal|11
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob12
index|[
literal|12
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob13
index|[
literal|13
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob14
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob15
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob16
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob17
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob1000
index|[
literal|1000
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob10000
index|[
literal|10000
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|glob100000
index|[
literal|100000
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|GlobalsTest
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_TEST_UTILS_H
end_comment

end_unit

