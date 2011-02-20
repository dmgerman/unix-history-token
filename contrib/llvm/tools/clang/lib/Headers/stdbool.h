begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- stdbool.h - Standard header for booleans -------------------------===  *  * Copyright (c) 2008 Eli Friedman  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDBOOL_H
end_ifndef

begin_define
define|#
directive|define
name|__STDBOOL_H
end_define

begin_comment
comment|/* Don't define bool, true, and false in C++, except as a GNU extension. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_elif

begin_comment
comment|/* Define _Bool, bool, false, true as a GNU extension. */
end_comment

begin_define
define|#
directive|define
name|_Bool
value|bool
end_define

begin_define
define|#
directive|define
name|bool
value|bool
end_define

begin_define
define|#
directive|define
name|false
value|false
end_define

begin_define
define|#
directive|define
name|true
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDBOOL_H */
end_comment

end_unit

