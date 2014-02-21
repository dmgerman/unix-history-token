begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * amd64/xen/xen-os.h  *   * Random collection of macros and definition  *  * Copyright (c) 2003, 2004 Keir Fraser (on behalf of the Xen team)  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER   * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING   * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER   * DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_XEN_XEN_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_XEN_XEN_OS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_X86_PAE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Everything below this point is not included by assembler (.S) files. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_comment
comment|/* REP NOP (PAUSE) is a good thing to insert into busy-wait loops. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|rep_nop
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( "rep;nop" : : : "memory" );
block|}
end_function

begin_define
define|#
directive|define
name|cpu_relax
parameter_list|()
value|rep_nop()
end_define

begin_comment
comment|/* This is a barrier for the compiler only, NOT the processor! */
end_comment

begin_define
define|#
directive|define
name|barrier
parameter_list|()
value|__asm__ __volatile__("": : :"memory")
end_define

begin_define
define|#
directive|define
name|LOCK_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|LOCK
value|""
end_define

begin_define
define|#
directive|define
name|ADDR
value|(*(volatile long *) addr)
end_define

begin_comment
comment|/**  * test_and_clear_bit - Clear a bit and return its old value  * @nr: Bit to set  * @addr: Address to count from  *  * This operation is atomic and cannot be reordered.    * It also implies a memory barrier.  */
end_comment

begin_function
specifier|static
name|__inline
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
asm|( LOCK_PREFIX                 "btrl %2,%1\n\tsbbl %0,%0"                 :"=r" (oldbit),"=m" (ADDR)                 :"Ir" (nr) : "memory");
return|return
name|oldbit
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|constant_test_bit
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
specifier|static
name|__inline
name|int
name|variable_test_bit
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
asm|(         "btl %2,%1\n\tsbbl %0,%0"         :"=r" (oldbit)         :"m" (ADDR),"Ir" (nr));
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
value|(__builtin_constant_p(nr) ? \  constant_test_bit((nr),(addr)) : \  variable_test_bit((nr),(addr)))
end_define

begin_comment
comment|/**  * set_bit - Atomically set a bit in memory  * @nr: the bit to set  * @addr: the address to start counting from  *  * This function is atomic and may not be reordered.  See __set_bit()  * if you do not require the atomic guarantees.  * Note that @nr may be almost arbitrarily large; this function is not  * restricted to acting on a single-word quantity.  */
end_comment

begin_function
specifier|static
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
asm|( LOCK_PREFIX                 "btsl %1,%0"                 :"=m" (ADDR)                 :"Ir" (nr));
block|}
end_function

begin_comment
comment|/**  * clear_bit - Clears a bit in memory  * @nr: Bit to clear  * @addr: Address to start counting from  *  * clear_bit() is atomic and may not be reordered.  However, it does  * not contain a memory barrier, so if it is used for locking purposes,  * you should call smp_mb__before_clear_bit() and/or smp_mb__after_clear_bit()  * in order to ensure changes are visible on other processors.  */
end_comment

begin_function
specifier|static
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
asm|( LOCK_PREFIX                 "btrl %1,%0"                 :"=m" (ADDR)                 :"Ir" (nr));
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_XEN_XEN_OS_H_ */
end_comment

end_unit

