begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- armintr.h - ARM Windows intrinsics -------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_comment
comment|/* Only include this if we're compiling for the windows platform. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_empty
empty|#include_next<armintr.h>
end_empty

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__ARMINTR_H
end_ifndef

begin_define
define|#
directive|define
name|__ARMINTR_H
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|_ARM_BARRIER_SY
init|=
literal|0xF
block|,
name|_ARM_BARRIER_ST
init|=
literal|0xE
block|,
name|_ARM_BARRIER_ISH
init|=
literal|0xB
block|,
name|_ARM_BARRIER_ISHST
init|=
literal|0xA
block|,
name|_ARM_BARRIER_NSH
init|=
literal|0x7
block|,
name|_ARM_BARRIER_NSHST
init|=
literal|0x6
block|,
name|_ARM_BARRIER_OSH
init|=
literal|0x3
block|,
name|_ARM_BARRIER_OSHST
init|=
literal|0x2
block|}
name|_ARMINTR_BARRIER_TYPE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARMINTR_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

end_unit

