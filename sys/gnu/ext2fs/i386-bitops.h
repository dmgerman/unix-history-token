begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * this is mixture of i386/bitops.h and asm/string.h  * taken from the Linux source tree   *  * XXX replace with Mach routines or reprogram in C  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_GNU_EXT2FS_I386_BITOPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_GNU_EXT2FS_I386_BITOPS_H_
end_define

begin_comment
comment|/*  * Copyright 1992, Linus Torvalds.  */
end_comment

begin_comment
comment|/*  * These have to be done with inline assembly: that way the bit-setting  * is guaranteed to be atomic. All bit operations return 0 if the bit  * was cleared before the operation and != 0 if it was not.  *  * bit 0 is the LSB of addr; bit 32 is the LSB of (addr+1).  */
end_comment

begin_comment
comment|/*  * Some hacks to defeat gcc over-optimizations..  */
end_comment

begin_struct
struct|struct
name|__dummy
block|{
name|unsigned
name|long
name|a
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADDR
value|(*(struct __dummy *) addr)
end_define

begin_function
specifier|static
name|__inline__
name|int
name|set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|oldbit
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("btsl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit),"=m" (ADDR) 		:"ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|oldbit
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("btrl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit),"=m" (ADDR) 		:"ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|change_bit
parameter_list|(
name|int
name|nr
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|oldbit
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("btcl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit),"=m" (ADDR) 		:"ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_comment
comment|/*  * This routine doesn't need to be atomic, but it's faster to code it  * this way.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|oldbit
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("btl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit) 		:"m" (ADDR),"ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_comment
comment|/*  * Find-bit routines..  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|find_first_zero_bit
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
name|int
name|_count
init|=
operator|(
name|size
operator|+
literal|31
operator|)
operator|>>
literal|5
decl_stmt|;
if|if
condition|(
operator|!
name|size
condition|)
return|return
literal|0
return|;
asm|__asm__("			\n\ 		cld			\n\ 		movl $-1,%%eax		\n\ 		xorl %%edx,%%edx	\n\ 		repe; scasl		\n\ 		je 1f			\n\ 		xorl -4(%%edi),%%eax	\n\ 		subl $4,%%edi		\n\ 		bsfl %%eax,%%edx	\n\ 1:		subl %%ebx,%%edi	\n\ 		shll $3,%%edi		\n\ 		addl %%edi,%%edx" 		: "=c" (_count), "=D" (addr), "=d" (res) 		: "0" (_count), "1" (addr), "b" (addr) 		: "ax");
return|return
name|res
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|find_next_zero_bit
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|offset
parameter_list|)
block|{
name|unsigned
name|long
modifier|*
name|p
init|=
operator|(
operator|(
name|unsigned
name|long
operator|*
operator|)
name|addr
operator|)
operator|+
operator|(
name|offset
operator|>>
literal|5
operator|)
decl_stmt|;
name|int
name|set
init|=
literal|0
decl_stmt|,
name|bit
init|=
name|offset
operator|&
literal|31
decl_stmt|,
name|res
decl_stmt|;
if|if
condition|(
name|bit
condition|)
block|{
comment|/* 		 * Look for zero in first byte 		 */
asm|__asm__("			\n\ 			bsfl %1,%0		\n\ 			jne 1f			\n\ 			movl $32, %0		\n\ 1:			" 			: "=r" (set) 			: "r" (~(*p>> bit)));
if|if
condition|(
name|set
operator|<
operator|(
literal|32
operator|-
name|bit
operator|)
condition|)
return|return
name|set
operator|+
name|offset
return|;
name|set
operator|=
literal|32
operator|-
name|bit
expr_stmt|;
name|p
operator|++
expr_stmt|;
block|}
comment|/* 	 * No zero yet, search remaining full bytes for a zero 	 */
name|res
operator|=
name|find_first_zero_bit
argument_list|(
name|p
argument_list|,
name|size
operator|-
literal|32
operator|*
operator|(
name|p
operator|-
operator|(
name|unsigned
name|long
operator|*
operator|)
name|addr
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|offset
operator|+
name|set
operator|+
name|res
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * ffz = Find First Zero in word. Undefined if no zero exists,  * so code should check against ~0UL first..  */
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|long
name|ffz
parameter_list|(
name|unsigned
name|long
name|word
parameter_list|)
block|{
asm|__asm__("bsfl %1,%0" 		:"=r" (word) 		:"r" (~word));
return|return
name|word
return|;
block|}
end_function

begin_comment
comment|/*   * memscan() taken from linux asm/string.h  */
end_comment

begin_comment
comment|/*  * find the first occurrence of byte 'c', or 1 past the area if none  */
end_comment

begin_function
specifier|static
name|__inline__
name|char
modifier|*
name|memscan
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|unsigned
name|char
name|c
parameter_list|,
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
operator|!
name|size
condition|)
return|return
name|addr
return|;
asm|__asm__("			\n\ 		cld			\n\                 repnz; scasb		\n\                 jnz 1f			\n\                 dec %%edi		\n\ 1:              "                 : "=D" (addr), "=c" (size)                 : "0" (addr), "1" (size), "a" (c));
return|return
name|addr
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_GNU_EXT2FS_I386_BITOPS_H_ */
end_comment

end_unit

