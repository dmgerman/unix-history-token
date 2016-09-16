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

begin_function
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
name|dst0
parameter_list|,
specifier|const
name|void
modifier|*
name|src0
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|int
name|dummy
decl_stmt|;
asm|asm
specifier|volatile
asm|(
ifndef|#
directive|ifndef
name|__OPTIMIZE_SIZE__
asm|"cmp	%2, #0x3\n\ 	bls	3f\n\ 	and	lr, %1, #0x3\n\ 	and	r3, %0, #0x3\n\ 	cmp	lr, r3\n\ 	bne	3f\n\ 	cmp	lr, #0x0\n\ 	beq	2f\n\ 	b	1f\n\ 0:\n\ 	ldrb	r3, [%1], #1\n\ " 	PRELOADSTR ("%1") "\n\ 	tst	%1, #0x3\n\ 	strb	r3, [%0], #1\n\ 	beq	3f\n\ 1:\n\ 	sub	%2, %2, #1\n\ 	cmn	%2, #1\n\ 	bne	0b\n\ 2:\n\ 	cmp	%2, #0xf\n\ 	bls	1f\n\ 0:\n\ 	ldmia	%1!, { r3, r4, r5, lr }\n\ " 	PRELOADSTR ("%1") "\n\ \n\ 	sub	%2, %2, #16\n\ 	cmp	%2, #0xf\n\ 	stmia	%0!, { r3, r4, r5, lr }\n\ 	bhi	0b\n\ 1:\n\ 	cmp	%2, #0x7\n\ 	bls	1f\n\ 0:\n\ 	ldmia	%1!, { r3, r4 }\n\ " 	PRELOADSTR ("%1") "\n\ \n\ 	sub	%2, %2, #8\n\ 	cmp	%2, #0x7\n\ 	stmia	%0!, { r3, r4 }\n\ 	bhi	0b\n\ 1:\n\ 	cmp	%2, #0x3\n\ 	bls	3f\n\ 0:\n\ 	sub	%2, %2, #4\n\ 	ldr	r3, [%1], #4\n\ " 	PRELOADSTR ("%1") "\n\ \n\ 	cmp	%2, #0x3\n\ 	str	r3, [%0], #4\n\ 	bhi	0b\n\ "
endif|#
directive|endif
comment|/* !__OPTIMIZE_SIZE__ */
asm|"\n\ 3:\n\ " 	PRELOADSTR ("%1") "\n\ 	sub	%2, %2, #1\n\ 	cmn	%2, #1\n\ 	beq	1f\n\ 0:\n\ 	sub	%2, %2, #1\n\ 	ldrb	r3, [%1], #1\n\ " 	PRELOADSTR ("%1") "\n\ 	cmn	%2, #1\n\ 	strb	r3, [%0], #1\n\ 	bne	0b\n\ 1:"        : "=&r" (dummy), "=&r" (src0), "=&r" (len)        : "0" (dst0), "1" (src0), "2" (len)        : "memory", "lr", "r3", "r4", "r5", "cc");
return|return
name|dst0
return|;
block|}
end_function

end_unit

