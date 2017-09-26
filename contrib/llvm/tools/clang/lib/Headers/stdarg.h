begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- stdarg.h - Variable argument handling ----------------------------===  *  * Copyright (c) 2008 Eli Friedman  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDARG_H
end_ifndef

begin_define
define|#
directive|define
name|__STDARG_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|param
parameter_list|)
value|__builtin_va_start(ap, param)
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_va_end(ap)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg(ap, type)
end_define

begin_comment
comment|/* GCC always defines __va_copy, but does not define va_copy unless in c99 mode  * or -ansi is not specified, since it was not part of C90.  */
end_comment

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|__builtin_va_copy(d,s)
end_define

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|||
name|__cplusplus
operator|>=
literal|201103L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|__builtin_va_copy(dest, src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
value|1
end_define

begin_typedef
typedef|typedef
name|__builtin_va_list
name|__gnuc_va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDARG_H */
end_comment

end_unit

