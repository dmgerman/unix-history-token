begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Per Fogelstrom, Opsycon AB and RTMX Inc, USA.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed under OpenBSD by  *	Per Fogelstrom Opsycon AB for RTMX Inc, North Carolina, USA.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$NetBSD: pio.h,v 1.1 1998/05/15 10:15:54 tsubai Exp $  *	$OpenBSD: pio.h,v 1.1 1997/10/13 10:53:47 pefo Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PIO_H_
end_define

begin_comment
comment|/*  * I/O macros.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__outb
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
name|a
parameter_list|,
name|u_int8_t
name|v
parameter_list|)
block|{
operator|*
name|a
operator|=
name|v
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outw
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|u_int16_t
name|v
parameter_list|)
block|{
operator|*
name|a
operator|=
name|v
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outl
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
operator|*
name|a
operator|=
name|v
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outwrb
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|u_int16_t
name|v
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("sthbrx %0, 0, %1" :: "r"(v), "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outlrb
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("stwbrx %0, 0, %1" :: "r"(v), "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int8_t
name|__inb
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
name|a
parameter_list|)
block|{
name|u_int8_t
name|_v_
decl_stmt|;
name|_v_
operator|=
operator|*
name|a
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
return|return
name|_v_
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int16_t
name|__inw
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|)
block|{
name|u_int16_t
name|_v_
decl_stmt|;
name|_v_
operator|=
operator|*
name|a
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
return|return
name|_v_
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|__inl
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|)
block|{
name|u_int32_t
name|_v_
decl_stmt|;
name|_v_
operator|=
operator|*
name|a
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
return|return
name|_v_
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int16_t
name|__inwrb
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|)
block|{
name|u_int16_t
name|_v_
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("lhbrx %0, 0, %1" : "=r"(_v_) : "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
return|return
name|_v_
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|__inlrb
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|)
block|{
name|u_int32_t
name|_v_
decl_stmt|;
asm|__asm__
specifier|volatile
asm|("lwbrx %0, 0, %1" : "=r"(_v_) : "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
return|return
name|_v_
return|;
block|}
end_function

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__outb((volatile u_int8_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|out8
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outb(a,v)
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__outw((volatile u_int16_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|out16
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outw(a,v)
end_define

begin_define
define|#
directive|define
name|outl
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__outl((volatile u_int32_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|out32
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outl(a,v)
end_define

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|a
parameter_list|)
value|(__inb((volatile u_int8_t *)(a)))
end_define

begin_define
define|#
directive|define
name|in8
parameter_list|(
name|a
parameter_list|)
value|inb(a)
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|a
parameter_list|)
value|(__inw((volatile u_int16_t *)(a)))
end_define

begin_define
define|#
directive|define
name|in16
parameter_list|(
name|a
parameter_list|)
value|inw(a)
end_define

begin_define
define|#
directive|define
name|inl
parameter_list|(
name|a
parameter_list|)
value|(__inl((volatile u_int32_t *)(a)))
end_define

begin_define
define|#
directive|define
name|in32
parameter_list|(
name|a
parameter_list|)
value|inl(a)
end_define

begin_define
define|#
directive|define
name|out8rb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outb(a,v)
end_define

begin_define
define|#
directive|define
name|outwrb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__outwrb((volatile u_int16_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|out16rb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outwrb(a,v)
end_define

begin_define
define|#
directive|define
name|outlrb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(__outlrb((volatile u_int32_t *)(a), v))
end_define

begin_define
define|#
directive|define
name|out32rb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|outlrb(a,v)
end_define

begin_define
define|#
directive|define
name|in8rb
parameter_list|(
name|a
parameter_list|)
value|inb(a)
end_define

begin_define
define|#
directive|define
name|inwrb
parameter_list|(
name|a
parameter_list|)
value|(__inwrb((volatile u_int16_t *)(a)))
end_define

begin_define
define|#
directive|define
name|in16rb
parameter_list|(
name|a
parameter_list|)
value|inwrb(a)
end_define

begin_define
define|#
directive|define
name|inlrb
parameter_list|(
name|a
parameter_list|)
value|(__inlrb((volatile u_int32_t *)(a)))
end_define

begin_define
define|#
directive|define
name|in32rb
parameter_list|(
name|a
parameter_list|)
value|inlrb(a)
end_define

begin_function
specifier|static
name|__inline
name|void
name|__outsb
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
name|a
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|s
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
operator|*
name|a
operator|=
operator|*
name|s
operator|++
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outsw
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
name|s
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
operator|*
name|a
operator|=
operator|*
name|s
operator|++
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outsl
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
name|s
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
operator|*
name|a
operator|=
operator|*
name|s
operator|++
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outswrb
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|,
specifier|const
name|u_int16_t
modifier|*
name|s
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
asm|__asm__
specifier|volatile
asm|("sthbrx %0, 0, %1" :: "r"(*s++), "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__outslrb
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|,
specifier|const
name|u_int32_t
modifier|*
name|s
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
asm|__asm__
specifier|volatile
asm|("stwbrx %0, 0, %1" :: "r"(*s++), "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__insb
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
name|a
parameter_list|,
name|u_int8_t
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|a
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__insw
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|u_int16_t
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|a
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__insl
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|u_int32_t
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|a
expr_stmt|;
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__inswrb
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
name|a
parameter_list|,
name|u_int16_t
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
asm|__asm__
specifier|volatile
asm|("lhbrx %0, 0, %1" : "=r"(*d++) : "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__inslrb
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|a
parameter_list|,
name|u_int32_t
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
condition|)
asm|__asm__
specifier|volatile
asm|("lwbrx %0, 0, %1" : "=r"(*d++) : "r"(a));
asm|__asm__
specifier|volatile
asm|("eieio; sync");
block|}
end_function

begin_define
define|#
directive|define
name|outsb
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(__outsb((volatile u_int8_t *)(a), s, c))
end_define

begin_define
define|#
directive|define
name|outs8
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|outsb(a,s,c)
end_define

begin_define
define|#
directive|define
name|outsw
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(__outsw((volatile u_int16_t *)(a), s, c))
end_define

begin_define
define|#
directive|define
name|outs16
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|outsw(a,s,c)
end_define

begin_define
define|#
directive|define
name|outsl
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(__outsl((volatile u_int32_t *)(a), s, c))
end_define

begin_define
define|#
directive|define
name|outs32
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|outsl(a,s,c)
end_define

begin_define
define|#
directive|define
name|insb
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|(__insb((volatile u_int8_t *)(a), d, c))
end_define

begin_define
define|#
directive|define
name|ins8
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|insb(a,d,c)
end_define

begin_define
define|#
directive|define
name|insw
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|(__insw((volatile u_int16_t *)(a), d, c))
end_define

begin_define
define|#
directive|define
name|ins16
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|insw(a,d,c)
end_define

begin_define
define|#
directive|define
name|insl
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|(__insl((volatile u_int32_t *)(a), d, c))
end_define

begin_define
define|#
directive|define
name|ins32
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|insl(a,d,c)
end_define

begin_define
define|#
directive|define
name|outs8rb
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|outsb(a,s,c)
end_define

begin_define
define|#
directive|define
name|outswrb
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(__outswrb((volatile u_int16_t *)(a), s, c))
end_define

begin_define
define|#
directive|define
name|outs16rb
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|outswrb(a,s,c)
end_define

begin_define
define|#
directive|define
name|outslrb
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|(__outslrb((volatile u_int32_t *)(a), s, c))
end_define

begin_define
define|#
directive|define
name|outs32rb
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|outslrb(a,s,c)
end_define

begin_define
define|#
directive|define
name|ins8rb
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|insb(a,d,c)
end_define

begin_define
define|#
directive|define
name|inswrb
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|(__inswrb((volatile u_int16_t *)(a), d, c))
end_define

begin_define
define|#
directive|define
name|ins16rb
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|inswrb(a,d,c)
end_define

begin_define
define|#
directive|define
name|inslrb
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|(__inslrb((volatile u_int32_t *)(a), d, c))
end_define

begin_define
define|#
directive|define
name|ins32rb
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|inslrb(a,d,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_MACHINE_PIO_H_*/
end_comment

end_unit

