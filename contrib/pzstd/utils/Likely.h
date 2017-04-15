begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/**  * Compiler hints to indicate the fast path of an "if" branch: whether  * the if condition is likely to be true or false.  *  * @author Tudor Bosman (tudorb@fb.com)  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_undef
undef|#
directive|undef
name|LIKELY
end_undef

begin_undef
undef|#
directive|undef
name|UNLIKELY
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|4
end_if

begin_define
define|#
directive|define
name|LIKELY
parameter_list|(
name|x
parameter_list|)
value|(__builtin_expect((x), 1))
end_define

begin_define
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|(__builtin_expect((x), 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

