begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"xscale.h"
end_include

begin_define
define|#
directive|define
name|_CONST
value|const
end_define

begin_function
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|_CONST
name|char
modifier|*
name|start
init|=
name|str
decl_stmt|;
comment|/* Skip unaligned part.  */
if|if
condition|(
operator|(
name|long
operator|)
name|str
operator|&
literal|3
condition|)
block|{
name|str
operator|--
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|*
operator|++
name|str
operator|==
literal|'\0'
condition|)
goto|goto
name|out
goto|;
block|}
do|while
condition|(
operator|(
name|long
operator|)
name|str
operator|&
literal|3
condition|)
do|;
block|}
comment|/* Load two constants:      R4 = 0xfefefeff [ == ~(0x80808080<< 1) ]      R5 = 0x80808080  */
asm|asm ("mov	r5, #0x80\n\ 	add	r5, r5, #0x8000\n\ 	add	r5, r5, r5, lsl #16\n\ 	mvn	r4, r5, lsl #1\n\ "
if|#
directive|if
name|defined
name|__ARM_ARCH_5__
operator|||
name|defined
name|__ARM_ARCH_5T__
operator|||
name|defined
name|__ARM_ARCH_5E__
operator|||
name|defined
name|__ARM_ARCH_5TE__
operator|||
name|defined
name|__ARM_ARCH_7A__
asm|"	tst	%0, #0x7\n\ 	itt	eq\n\ 	ldreqd	r6, [%0]\n\ 	beq	1f\n\ 	ldr	r2, [%0]\n\         add     r3, r2, r4\n\         bic     r3, r3, r2\n\         ands    r2, r3, r5\n\ 	bne	2f\n\ 	sub	%0, %0, #4\n\ \n\ 0:\n\ 	ldrd	r6, [%0, #8]!\n\ " 	PRELOADSTR ("%0") "\n\ 1:\n\ 	add	r3, r6, r4\n\ 	add	r2, r7, r4\n\ 	bic	r3, r3, r6\n\ 	bic	r2, r2, r7\n\ 	and	r3, r3, r5\n\ 	and	r2, r2, r5\n\ 	orrs	r3, r2, r3\n\ 	beq	0b\n\ "
else|#
directive|else
asm|"	sub	%0, %0, #4\n\ \n\ 0:\n\ 	ldr	r6, [%0, #4]!\n\ " 	PRELOADSTR ("%0") "\n\ 	add	r3, r6, r4\n\ 	bic	r3, r3, r6\n\ 	ands	r3, r3, r5\n\ 	beq	0b\n\ "
endif|#
directive|endif
comment|/* __ARM_ARCH_5[T][E]__ */
asm|"\n\ 2:\n\ 	ldrb	r3, [%0]\n\ 	cmp	r3, #0x0\n\ 	beq	1f\n\ \n\ 0:\n\ 	ldrb	r3, [%0, #1]!\n\ " 	PRELOADSTR ("%0") "\n\ 	cmp	r3, #0x0\n\ 	bne	0b\n\ 1:\n\ "        : "=r" (str) : "0" (str) : "r2", "r3", "r4", "r5", "r6", "r7");
name|out
label|:
return|return
name|str
operator|-
name|start
return|;
block|}
end_function

end_unit

