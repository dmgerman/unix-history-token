begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- cpuid.h - X86 cpu model detection --------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|__x86_64__
operator|||
name|__i386__
operator|)
end_if

begin_error
error|#
directive|error
error|this header is for x86 only
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|int
name|__get_cpuid
parameter_list|(
name|unsigned
name|int
name|__level
parameter_list|,
name|unsigned
name|int
modifier|*
name|__eax
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ebx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ecx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__edx
parameter_list|)
block|{
asm|__asm("cpuid" : "=a"(*__eax), "=b" (*__ebx), "=c"(*__ecx), "=d"(*__edx)
block|:
literal|"0"
operator|(
name|__level
operator|)
block|)
function|;
end_function

begin_return
return|return
literal|1
return|;
end_return

unit|}
end_unit

