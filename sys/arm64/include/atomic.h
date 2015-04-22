begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Andrew Turner<andrew@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_define
define|#
directive|define
name|isb
parameter_list|()
value|__asm __volatile("isb" : : : "memory")
end_define

begin_define
define|#
directive|define
name|dsb
parameter_list|()
value|__asm __volatile("dsb sy" : : : "memory")
end_define

begin_define
define|#
directive|define
name|dmb
parameter_list|()
value|__asm __volatile("dmb sy" : : : "memory")
end_define

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|dmb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|dmb()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|dmb()
end_define

begin_function
specifier|static
name|__inline
name|void
name|atomic_add_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   add	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   bic	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov	%w1, #1        \n"
literal|"   ldxr	%w0, [%2]      \n"
literal|"   cmp	%w0, %w3       \n"
literal|"   b.ne	2f             \n"
literal|"   stxr	%w1, %w4, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_fetchadd_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w4, [%2]      \n"
literal|"   add	%w0, %w4, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"   mov	%w0, #0        \n"
literal|"1: ldxr	%w3, [%2]      \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   orr	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   sub	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_function
unit|static
name|__inline
name|void
name|atomic_add_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%w0, [%2]      \n"
literal|"   add	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%w0, [%2]      \n"
literal|"   bic	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov	%w1, #1        \n"
literal|"   ldaxr	%w0, [%2]      \n"
literal|"   cmp	%w0, %w3       \n"
literal|"   b.ne	2f             \n"
literal|"   stxr	%w1, %w4, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_load_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"ldar	%w0, [%1] \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%w0, [%2]      \n"
literal|"   orr	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%w0, [%2]      \n"
literal|"   sub	%w0, %w0, %w3  \n"
literal|"   stxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_acq_32
end_define

begin_comment
comment|/* The atomic functions currently are both acq and rel, we should fix this. */
end_comment

begin_function
unit|static
name|__inline
name|void
name|atomic_add_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   add	%w0, %w0, %w3  \n"
literal|"   stlxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   bic	%w0, %w0, %w3  \n"
literal|"   stlxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov	%w1, #1        \n"
literal|"   ldxr	%w0, [%2]      \n"
literal|"   cmp	%w0, %w3       \n"
literal|"   b.ne	2f             \n"
literal|"   stlxr	%w1, %w4, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   orr	%w0, %w0, %w3  \n"
literal|"   stlxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_store_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile(
literal|"stlr	%w0, [%1] \n"
operator|:
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%w0, [%2]      \n"
literal|"   sub	%w0, %w0, %w3  \n"
literal|"   stlxr	%w1, %w0, [%2] \n"
literal|"   cbnz	%w1, 1b        \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
value|atomic_store_rel_32
end_define

begin_function
unit|static
name|__inline
name|void
name|atomic_add_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   add	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   bic	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov	%w1, #1       \n"
literal|"   ldxr	%0, [%2]      \n"
literal|"   cmp	%0, %3        \n"
literal|"   b.ne	2f            \n"
literal|"   stxr	%w1, %4, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_fetchadd_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%4, [%2]      \n"
literal|"   add	%0, %4, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_readandclear_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"   mov	%0, #0        \n"
literal|"1: ldxr	%3, [%2]      \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   orr	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   sub	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|old
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   stxr	%w1, %3, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|old
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_add_long
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_long
value|atomic_fetchadd_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_64
end_define

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_ptr
value|atomic_fetchadd_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_64
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_64
end_define

begin_function
unit|static
name|__inline
name|void
name|atomic_add_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%0, [%2]      \n"
literal|"   add	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%0, [%2]      \n"
literal|"   bic	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov	%w1, #1       \n"
literal|"   ldaxr	%0, [%2]      \n"
literal|"   cmp	%0, %3        \n"
literal|"   b.ne	2f            \n"
literal|"   stxr	%w1, %4, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_load_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"ldar	%0, [%1] \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%0, [%2]      \n"
literal|"   orr	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldaxr	%0, [%2]      \n"
literal|"   sub	%0, %0, %3    \n"
literal|"   stxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_64
end_define

begin_comment
comment|/*  * TODO: The atomic functions currently are both acq and rel, we should fix  * this.  */
end_comment

begin_function
unit|static
name|__inline
name|void
name|atomic_add_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   add	%0, %0, %3    \n"
literal|"   stlxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   bic	%0, %0, %3    \n"
literal|"   stlxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov	%w1, #1       \n"
literal|"   ldxr	%0, [%2]      \n"
literal|"   cmp	%0, %3        \n"
literal|"   b.ne	2f            \n"
literal|"   stlxr	%w1, %4, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   orr	%0, %0, %3    \n"
literal|"   stlxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_store_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm __volatile(
literal|"stlr	%0, [%1] \n"
operator|:
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldxr	%0, [%2]      \n"
literal|"   sub	%0, %0, %3    \n"
literal|"   stlxr	%w1, %0, [%2] \n"
literal|"   cbnz	%w1, 1b       \n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
value|atomic_store_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

