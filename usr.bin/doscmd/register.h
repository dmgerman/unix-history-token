begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Copyright (c) 1996 **	Michael Smith.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** ** THIS SOFTWARE IS PROVIDED BY Michael Smith ``AS IS'' AND ** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ** ARE DISCLAIMED.  IN NO EVENT SHALL Michael Smith BE LIABLE ** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL ** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS ** OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT ** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY ** OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF ** SUCH DAMAGE. ** ** $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************************** ** Abstractions to hide register access methods across different platforms. ** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VM86_H_
end_ifndef

begin_comment
comment|/* standard register representation */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_long
name|r_ex
decl_stmt|;
struct|struct
block|{
name|u_short
name|r_x
decl_stmt|;
name|u_short
label|:
literal|16
expr_stmt|;
block|}
name|r_w
struct|;
struct|struct
block|{
name|u_char
name|r_l
decl_stmt|;
name|u_char
name|r_h
decl_stmt|;
name|u_short
label|:
literal|16
expr_stmt|;
block|}
name|r_b
struct|;
block|}
name|reg86_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* layout must match definition of struct sigcontext in<machine/signal.h> */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|onstack
decl_stmt|;
name|reg86_t
name|gs
decl_stmt|;
name|reg86_t
name|fs
decl_stmt|;
name|reg86_t
name|es
decl_stmt|;
name|reg86_t
name|ds
decl_stmt|;
name|reg86_t
name|edi
decl_stmt|;
name|reg86_t
name|esi
decl_stmt|;
name|reg86_t
name|ebp
decl_stmt|;
name|reg86_t
name|isp
decl_stmt|;
name|reg86_t
name|ebx
decl_stmt|;
name|reg86_t
name|edx
decl_stmt|;
name|reg86_t
name|ecx
decl_stmt|;
name|reg86_t
name|eax
decl_stmt|;
name|int
name|pad
index|[
literal|2
index|]
decl_stmt|;
name|reg86_t
name|eip
decl_stmt|;
name|reg86_t
name|cs
decl_stmt|;
name|reg86_t
name|efl
decl_stmt|;
name|reg86_t
name|esp
decl_stmt|;
name|reg86_t
name|ss
decl_stmt|;
block|}
name|registers_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|mcontext_t
name|sc
decl_stmt|;
name|registers_t
name|r
decl_stmt|;
block|}
name|regcontext_t
typedef|;
end_typedef

begin_comment
comment|/*  ** passed around as a reference to the registers.  This must be in ** scope for the following register macros to work. */
end_comment

begin_comment
comment|/* register shorthands */
end_comment

begin_define
define|#
directive|define
name|R_ESP
value|(REGS->r.esp.r_ex)
end_define

begin_define
define|#
directive|define
name|R_SP
value|(REGS->r.esp.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EBP
value|(REGS->r.ebp.r_ex)
end_define

begin_define
define|#
directive|define
name|R_BP
value|(REGS->r.ebp.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_ISP
value|(REGS->r.isp.r_ex)
end_define

begin_define
define|#
directive|define
name|R_EIP
value|(REGS->r.eip.r_ex)
end_define

begin_define
define|#
directive|define
name|R_IP
value|(REGS->r.eip.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EFLAGS
value|(REGS->r.efl.r_ex)
end_define

begin_define
define|#
directive|define
name|R_FLAGS
value|(REGS->r.efl.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EES
value|(REGS->r.es.r_ex)
end_define

begin_define
define|#
directive|define
name|R_ES
value|(REGS->r.es.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EDS
value|(REGS->r.ds.r_ex)
end_define

begin_define
define|#
directive|define
name|R_DS
value|(REGS->r.ds.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_ECS
value|(REGS->r.cs.r_ex)
end_define

begin_define
define|#
directive|define
name|R_CS
value|(REGS->r.cs.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_ESS
value|(REGS->r.ss.r_ex)
end_define

begin_define
define|#
directive|define
name|R_SS
value|(REGS->r.ss.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EDI
value|(REGS->r.edi.r_ex)
end_define

begin_define
define|#
directive|define
name|R_DI
value|(REGS->r.edi.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_ESI
value|(REGS->r.esi.r_ex)
end_define

begin_define
define|#
directive|define
name|R_SI
value|(REGS->r.esi.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EBX
value|(REGS->r.ebx.r_ex)
end_define

begin_define
define|#
directive|define
name|R_BX
value|(REGS->r.ebx.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_BL
value|(REGS->r.ebx.r_b.r_l)
end_define

begin_define
define|#
directive|define
name|R_BH
value|(REGS->r.ebx.r_b.r_h)
end_define

begin_define
define|#
directive|define
name|R_EDX
value|(REGS->r.edx.r_ex)
end_define

begin_define
define|#
directive|define
name|R_DX
value|(REGS->r.edx.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_DL
value|(REGS->r.edx.r_b.r_l)
end_define

begin_define
define|#
directive|define
name|R_DH
value|(REGS->r.edx.r_b.r_h)
end_define

begin_define
define|#
directive|define
name|R_ECX
value|(REGS->r.ecx.r_ex)
end_define

begin_define
define|#
directive|define
name|R_CX
value|(REGS->r.ecx.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_CL
value|(REGS->r.ecx.r_b.r_l)
end_define

begin_define
define|#
directive|define
name|R_CH
value|(REGS->r.ecx.r_b.r_h)
end_define

begin_define
define|#
directive|define
name|R_EAX
value|(REGS->r.eax.r_ex)
end_define

begin_define
define|#
directive|define
name|R_AX
value|(REGS->r.eax.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_AL
value|(REGS->r.eax.r_b.r_l)
end_define

begin_define
define|#
directive|define
name|R_AH
value|(REGS->r.eax.r_b.r_h)
end_define

begin_define
define|#
directive|define
name|R_EGS
value|(REGS->r.gs.r_ex)
end_define

begin_define
define|#
directive|define
name|R_GS
value|(REGS->r.gs.r_w.r_x)
end_define

begin_define
define|#
directive|define
name|R_EFS
value|(REGS->r.fs.r_ex)
end_define

begin_define
define|#
directive|define
name|R_FS
value|(REGS->r.fs.r_w.r_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** register manipulation macros  */
end_comment

begin_define
define|#
directive|define
name|PUTVEC
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|,
name|x
parameter_list|)
value|((s) = ((x)>> 16), (o) = (x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MAKEVEC
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|)
value|(((s)<< 16) + (o))
end_define

begin_define
define|#
directive|define
name|PUTPTR
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|,
name|x
parameter_list|)
value|(((s) = ((x)& 0xf0000)>> 4), (o) = (x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MAKEPTR
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|)
value|(((s)<< 4) + (o))
end_define

begin_define
define|#
directive|define
name|VECPTR
parameter_list|(
name|x
parameter_list|)
value|MAKEPTR((x)>> 16, (x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|REGISTERS
value|regcontext_t *REGS
end_define

begin_function
specifier|inline
specifier|static
name|void
name|PUSH
parameter_list|(
name|u_short
name|x
parameter_list|,
name|REGISTERS
parameter_list|)
block|{
name|R_SP
operator|-=
literal|2
expr_stmt|;
operator|*
operator|(
name|u_short
operator|*
operator|)
name|MAKEPTR
argument_list|(
name|R_SS
argument_list|,
name|R_SP
argument_list|)
operator|=
operator|(
name|x
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
specifier|static
name|u_short
name|POP
parameter_list|(
name|REGISTERS
parameter_list|)
block|{
name|u_short
name|x
decl_stmt|;
name|x
operator|=
operator|*
operator|(
name|u_short
operator|*
operator|)
name|MAKEPTR
argument_list|(
name|R_SS
argument_list|,
name|R_SP
argument_list|)
expr_stmt|;
name|R_SP
operator|+=
literal|2
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|PSL_ALLCC
end_ifndef

begin_comment
comment|/* Grr, FreeBSD doesn't have this */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|(PSL_C|PSL_PF|PSL_AF|PSL_Z|PSL_N)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

