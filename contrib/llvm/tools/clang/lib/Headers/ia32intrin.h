begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-------- ia32intrin.h ---------------------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86INTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<ia32intrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__IA32INTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__IA32INTRIN_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__readeflags
argument_list|(
name|void
argument_list|)
block|{
name|unsigned
name|long
name|long
name|__res
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("pushf\n\t"                         "popq %0\n"                         :"=r"(__res)                         :                         :                        );
return|return
name|__res
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__writeeflags
argument_list|(
name|unsigned
name|long
name|long
name|__f
argument_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("pushq %0\n\t"                         "popf\n"                         :                         :"r"(__f)                         :"flags"                        );
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__x86_64__ */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__readeflags
argument_list|(
name|void
argument_list|)
block|{
name|unsigned
name|int
name|__res
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("pushf\n\t"                         "popl %0\n"                         :"=r"(__res)                         :                         :                        );
return|return
name|__res
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__writeeflags
argument_list|(
name|unsigned
name|int
name|__f
argument_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("pushl %0\n\t"                         "popf\n"                         :                         :"r"(__f)                         :"flags"                        );
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__x86_64__ */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__rdpmc
argument_list|(
name|int
name|__A
argument_list|)
block|{
return|return
name|__builtin_ia32_rdpmc
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* __rdtsc */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__rdtsc
argument_list|(
name|void
argument_list|)
block|{
return|return
name|__builtin_ia32_rdtsc
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/* __rdtscp */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__rdtscp
argument_list|(
name|unsigned
name|int
operator|*
name|__A
argument_list|)
block|{
return|return
name|__builtin_ia32_rdtscp
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_rdtsc
parameter_list|()
value|__rdtsc()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IA32INTRIN_H */
end_comment

end_unit

