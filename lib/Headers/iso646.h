begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- iso646.h - Standard header for alternate spellings of operators---===  *  * Copyright (c) 2008 Eli Friedman  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISO646_H
end_ifndef

begin_define
define|#
directive|define
name|__ISO646_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|and
value|&&
end_define

begin_define
define|#
directive|define
name|and_eq
value|&=
end_define

begin_define
define|#
directive|define
name|bitand
value|&
end_define

begin_define
define|#
directive|define
name|bitor
value||
end_define

begin_define
define|#
directive|define
name|compl
value|~
end_define

begin_define
define|#
directive|define
name|not
value|!
end_define

begin_define
define|#
directive|define
name|not_eq
value|!=
end_define

begin_define
define|#
directive|define
name|or
value|||
end_define

begin_define
define|#
directive|define
name|or_eq
value||=
end_define

begin_define
define|#
directive|define
name|xor
value|^
end_define

begin_define
define|#
directive|define
name|xor_eq
value|^=
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
comment|/* __ISO646_H */
end_comment

end_unit

