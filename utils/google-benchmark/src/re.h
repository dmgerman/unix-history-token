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
name|BENCHMARK_RE_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_RE_H_
end_define

begin_include
include|#
directive|include
file|"internal_macros.h"
end_include

begin_comment
comment|// Prefer C regex libraries when compiling w/o exceptions so that we can
end_comment

begin_comment
comment|// correctly report errors.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_HAS_NO_EXCEPTIONS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_STD_REGEX
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|HAVE_GNU_POSIX_REGEX
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_POSIX_REGEX
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_STD_REGEX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STD_REGEX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<regex>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_GNU_POSIX_REGEX
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<gnuregex.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_POSIX_REGEX
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No regular expression backend was found!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"check.h"
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
comment|// A wrapper around the POSIX regular expression API that provides automatic
comment|// cleanup
name|class
name|Regex
block|{
name|public
label|:
name|Regex
argument_list|()
operator|:
name|init_
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|Regex
argument_list|()
expr_stmt|;
comment|// Compile a regular expression matcher from spec.  Returns true on success.
comment|//
comment|// On failure (and if error is not nullptr), error is populated with a human
comment|// readable error message if an error occurs.
name|bool
name|Init
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|spec
argument_list|,
name|std
operator|::
name|string
operator|*
name|error
argument_list|)
decl_stmt|;
comment|// Returns whether str matches the compiled regular expression.
name|bool
name|Match
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
decl_stmt|;
name|private
label|:
name|bool
name|init_
decl_stmt|;
comment|// Underlying regular expression object
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STD_REGEX
argument_list|)
name|std
operator|::
name|regex
name|re_
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_POSIX_REGEX
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_GNU_POSIX_REGEX
argument_list|)
name|regex_t
name|re_
decl_stmt|;
else|#
directive|else
error|#
directive|error
error|No regular expression backend implementation available
endif|#
directive|endif
block|}
empty_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STD_REGEX
argument_list|)
specifier|inline
name|bool
name|Regex
operator|::
name|Init
argument_list|(
argument|const std::string& spec
argument_list|,
argument|std::string* error
argument_list|)
block|{
ifdef|#
directive|ifdef
name|BENCHMARK_HAS_NO_EXCEPTIONS
operator|(
operator|(
name|void
operator|)
name|error
operator|)
block|;
comment|// suppress unused warning
else|#
directive|else
name|try
block|{
endif|#
directive|endif
name|re_
operator|=
name|std
operator|::
name|regex
argument_list|(
name|spec
argument_list|,
name|std
operator|::
name|regex_constants
operator|::
name|extended
argument_list|)
block|;
name|init_
operator|=
name|true
block|;
ifndef|#
directive|ifndef
name|BENCHMARK_HAS_NO_EXCEPTIONS
block|}
name|catch
argument_list|(
argument|const std::regex_error& e
argument_list|)
block|{
if|if
condition|(
name|error
condition|)
block|{
operator|*
name|error
operator|=
name|e
operator|.
name|what
argument_list|()
expr_stmt|;
block|}
block|}
endif|#
directive|endif
return|return
name|init_
return|;
block|}
specifier|inline
name|Regex
operator|::
operator|~
name|Regex
argument_list|()
block|{}
specifier|inline
name|bool
name|Regex
operator|::
name|Match
argument_list|(
argument|const std::string& str
argument_list|)
block|{
if|if
condition|(
operator|!
name|init_
condition|)
block|{
return|return
name|false
return|;
block|}
return|return
name|std
operator|::
name|regex_search
argument_list|(
name|str
argument_list|,
name|re_
argument_list|)
return|;
block|}
else|#
directive|else
specifier|inline
name|bool
name|Regex
operator|::
name|Init
argument_list|(
argument|const std::string& spec
argument_list|,
argument|std::string* error
argument_list|)
block|{
name|int
name|ec
operator|=
name|regcomp
argument_list|(
operator|&
name|re_
argument_list|,
name|spec
operator|.
name|c_str
argument_list|()
argument_list|,
name|REG_EXTENDED
operator||
name|REG_NOSUB
argument_list|)
block|;
if|if
condition|(
name|ec
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|size_t
name|needed
init|=
name|regerror
argument_list|(
name|ec
argument_list|,
operator|&
name|re_
argument_list|,
name|nullptr
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|char
modifier|*
name|errbuf
init|=
name|new
name|char
index|[
name|needed
index|]
decl_stmt|;
name|regerror
argument_list|(
name|ec
argument_list|,
operator|&
name|re_
argument_list|,
name|errbuf
argument_list|,
name|needed
argument_list|)
expr_stmt|;
comment|// regerror returns the number of bytes necessary to null terminate
comment|// the string, so we move that when assigning to error.
name|CHECK_NE
argument_list|(
name|needed
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|error
operator|->
name|assign
argument_list|(
name|errbuf
argument_list|,
name|needed
operator|-
literal|1
argument_list|)
expr_stmt|;
name|delete
index|[]
name|errbuf
decl_stmt|;
block|}
return|return
name|false
return|;
block|}
name|init_
operator|=
name|true
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|inline
name|Regex
operator|::
operator|~
name|Regex
argument_list|()
block|{
if|if
condition|(
name|init_
condition|)
block|{
name|regfree
argument_list|(
operator|&
name|re_
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  inline
name|bool
name|Regex
operator|::
name|Match
argument_list|(
argument|const std::string& str
argument_list|)
block|{
if|if
condition|(
operator|!
name|init_
condition|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|regexec
argument_list|(
operator|&
name|re_
argument_list|,
name|str
operator|.
name|c_str
argument_list|()
argument_list|,
literal|0
argument_list|,
name|nullptr
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_RE_H_
end_comment

end_unit

