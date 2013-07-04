begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- stdalign.h - Standard header for alignment ------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDALIGN_H
end_ifndef

begin_define
define|#
directive|define
name|__STDALIGN_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|alignas
value|_Alignas
end_define

begin_define
define|#
directive|define
name|alignof
value|_Alignof
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__alignas_is_defined
value|1
end_define

begin_define
define|#
directive|define
name|__alignof_is_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDALIGN_H */
end_comment

end_unit

