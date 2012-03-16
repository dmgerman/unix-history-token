begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 2012 David Chisnall. All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE  * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNWIND_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|UNWIND_H_INCLUDED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__arm__
include|#
directive|include
file|"unwind-arm.h"
else|#
directive|else
include|#
directive|include
file|"unwind-itanium.h"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

