begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_I386_BITOPS_H
end_ifndef

begin_define
define|#
directive|define
name|_I386_BITOPS_H
end_define

begin_comment
comment|/*  * Copyright 1992, Linus Torvalds.  */
end_comment

begin_comment
comment|/*  * These have to be done with inline assembly: that way the bit-setting  * is guaranteed to be atomic. All bit operations return 0 if the bit  * was cleared before the operation and != 0 if it was not.  *  * bit 0 is the LSB of addr; bit 32 is the LSB of (addr+1).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SMP__
end_ifdef

begin_define
define|#
directive|define
name|LOCK_PREFIX
value|"lock ; "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCK_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Function prototypes to keep gcc -Wall happy  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|change_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|test_and_set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|test_and_clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|test_and_change_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__constant_test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|ffz
parameter_list|(
name|unsigned
name|long
name|word
parameter_list|)
function_decl|;
end_function_decl

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
value|(*(volatile struct __dummy *) addr)
end_define

begin_define
define|#
directive|define
name|CONST_ADDR
value|(*(volatile const struct __dummy *) addr)
end_define

begin_function
specifier|extern
name|__inline__
name|void
name|set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( LOCK_PREFIX 		"btsl %1,%0" 		:"=m" (ADDR) 		:"Ir" (nr));
block|}
end_function

begin_function
specifier|extern
name|__inline__
name|void
name|clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( LOCK_PREFIX 		"btrl %1,%0" 		:"=m" (ADDR) 		:"Ir" (nr));
block|}
end_function

begin_function
specifier|extern
name|__inline__
name|void
name|change_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( LOCK_PREFIX 		"btcl %1,%0" 		:"=m" (ADDR) 		:"Ir" (nr));
block|}
end_function

begin_function
specifier|extern
name|__inline__
name|int
name|test_and_set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
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
asm|( LOCK_PREFIX 		"btsl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit),"=m" (ADDR) 		:"Ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_function
specifier|extern
name|__inline__
name|int
name|test_and_clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
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
asm|( LOCK_PREFIX 		"btrl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit),"=m" (ADDR) 		:"Ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_function
specifier|extern
name|__inline__
name|int
name|test_and_change_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
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
asm|( LOCK_PREFIX 		"btcl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit),"=m" (ADDR) 		:"Ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_comment
comment|/*  * This routine doesn't need to be atomic.  */
end_comment

begin_function
specifier|extern
name|__inline__
name|int
name|__constant_test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|1UL
operator|<<
operator|(
name|nr
operator|&
literal|31
operator|)
operator|)
operator|&
operator|(
operator|(
operator|(
specifier|const
specifier|volatile
name|unsigned
name|int
operator|*
operator|)
name|addr
operator|)
index|[
name|nr
operator|>>
literal|5
index|]
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|extern
name|__inline__
name|int
name|__test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
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
asm|( 		"btl %2,%1\n\tsbbl %0,%0" 		:"=r" (oldbit) 		:"m" (ADDR),"Ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_define
define|#
directive|define
name|test_bit
parameter_list|(
name|nr
parameter_list|,
name|addr
parameter_list|)
define|\
value|(__builtin_constant_p(nr) ? \  __constant_test_bit((nr),(addr)) : \  __test_bit((nr),(addr)))
end_define

begin_comment
comment|/*  * Find-bit routines..  */
end_comment

begin_function
specifier|extern
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
name|d0
decl_stmt|,
name|d1
decl_stmt|,
name|d2
decl_stmt|;
name|int
name|res
decl_stmt|;
if|if
condition|(
operator|!
name|size
condition|)
return|return
literal|0
return|;
asm|__asm__("movl $-1,%%eax\n\t" 		"xorl %%edx,%%edx\n\t" 		"repe; scasl\n\t" 		"je 1f\n\t" 		"xorl -4(%%edi),%%eax\n\t" 		"subl $4,%%edi\n\t" 		"bsfl %%eax,%%edx\n" 		"1:\tsubl %%ebx,%%edi\n\t" 		"shll $3,%%edi\n\t" 		"addl %%edi,%%edx" 		:"=d" (res), "=&c" (d0), "=&D" (d1), "=&a" (d2) 		:"1" ((size + 31)>> 5), "2" (addr), "b" (addr));
return|return
name|res
return|;
block|}
end_function

begin_function
specifier|extern
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
asm|__asm__("bsfl %1,%0\n\t" 			"jne 1f\n\t" 			"movl $32, %0\n" 			"1:" 			: "=r" (set) 			: "r" (~(*p>> bit)));
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
specifier|extern
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

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * ffs: find first bit set. This is defined the same way as  * the libc and compiler builtin ffs routines, therefore  * differs in spirit from the above ffz (man ffs).  */
end_comment

begin_function
specifier|extern
name|__inline__
name|int
name|ffs
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
asm|__asm__("bsfl %1,%0\n\t" 		"jnz 1f\n\t" 		"movl $-1,%0\n" 		"1:" : "=r" (r) : "g" (x));
return|return
name|r
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * hweightN: returns the hamming weight (i.e. the number  * of bits set) of a N-bit word  */
end_comment

begin_define
define|#
directive|define
name|hweight32
parameter_list|(
name|x
parameter_list|)
value|generic_hweight32(x)
end_define

begin_define
define|#
directive|define
name|hweight16
parameter_list|(
name|x
parameter_list|)
value|generic_hweight16(x)
end_define

begin_define
define|#
directive|define
name|hweight8
parameter_list|(
name|x
parameter_list|)
value|generic_hweight8(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|ext2_set_bit
value|test_and_set_bit
end_define

begin_define
define|#
directive|define
name|ext2_clear_bit
value|test_and_clear_bit
end_define

begin_define
define|#
directive|define
name|ext2_test_bit
value|test_bit
end_define

begin_define
define|#
directive|define
name|ext2_find_first_zero_bit
value|find_first_zero_bit
end_define

begin_define
define|#
directive|define
name|ext2_find_next_zero_bit
value|find_next_zero_bit
end_define

begin_comment
comment|/* Bitmap functions for the minix filesystem.  */
end_comment

begin_define
define|#
directive|define
name|minix_set_bit
parameter_list|(
name|nr
parameter_list|,
name|addr
parameter_list|)
value|test_and_set_bit(nr,addr)
end_define

begin_define
define|#
directive|define
name|minix_clear_bit
parameter_list|(
name|nr
parameter_list|,
name|addr
parameter_list|)
value|test_and_clear_bit(nr,addr)
end_define

begin_define
define|#
directive|define
name|minix_test_bit
parameter_list|(
name|nr
parameter_list|,
name|addr
parameter_list|)
value|test_bit(nr,addr)
end_define

begin_define
define|#
directive|define
name|minix_find_first_zero_bit
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
value|find_first_zero_bit(addr,size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_BITOPS_H */
end_comment

end_unit

