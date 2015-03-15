begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-------- vadefs.h ---------------------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_comment
comment|/* Only include this if we are aiming for MSVC compatibility. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_empty
empty|#include_next<vadefs.h>
end_empty

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__clang_vadefs_h
end_ifndef

begin_define
define|#
directive|define
name|__clang_vadefs_h
end_define

begin_empty
empty|#include_next<vadefs.h>
end_empty

begin_comment
comment|/* Override macros from vadefs.h with definitions that work with Clang. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_crt_va_start
end_ifdef

begin_undef
undef|#
directive|undef
name|_crt_va_start
end_undef

begin_define
define|#
directive|define
name|_crt_va_start
parameter_list|(
name|ap
parameter_list|,
name|param
parameter_list|)
value|__builtin_va_start(ap, param)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_crt_va_end
end_ifdef

begin_undef
undef|#
directive|undef
name|_crt_va_end
end_undef

begin_define
define|#
directive|define
name|_crt_va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_va_end(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_crt_va_arg
end_ifdef

begin_undef
undef|#
directive|undef
name|_crt_va_arg
end_undef

begin_define
define|#
directive|define
name|_crt_va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg(ap, type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VS 2015 switched to double underscore names, which is an improvement, but now  * we have to intercept those names too.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__crt_va_start
end_ifdef

begin_undef
undef|#
directive|undef
name|__crt_va_start
end_undef

begin_define
define|#
directive|define
name|__crt_va_start
parameter_list|(
name|ap
parameter_list|,
name|param
parameter_list|)
value|__builtin_va_start(ap, param)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__crt_va_end
end_ifdef

begin_undef
undef|#
directive|undef
name|__crt_va_end
end_undef

begin_define
define|#
directive|define
name|__crt_va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_va_end(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__crt_va_arg
end_ifdef

begin_undef
undef|#
directive|undef
name|__crt_va_arg
end_undef

begin_define
define|#
directive|define
name|__crt_va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg(ap, type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

