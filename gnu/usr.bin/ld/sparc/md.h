begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * SPARC machine dependent definitions  */
end_comment

begin_define
define|#
directive|define
name|MAX_ALIGNMENT
value|(sizeof (double))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NetBSD
end_ifdef

begin_define
define|#
directive|define
name|PAGSIZ
value|__LDPGSZ
end_define

begin_define
define|#
directive|define
name|N_SET_FLAG
parameter_list|(
name|ex
parameter_list|,
name|f
parameter_list|)
value|N_SETMAGIC(ex,N_GETMAGIC(ex), \ 					MID_MACHINE, N_GETFLAG(ex)|(f))
end_define

begin_define
define|#
directive|define
name|N_IS_DYNAMIC
parameter_list|(
name|ex
parameter_list|)
value|((N_GETFLAG(ex)& EX_DYNAMIC))
end_define

begin_comment
comment|/*  * Should be handled by a.out.h ?  */
end_comment

begin_define
define|#
directive|define
name|N_ADJUST
parameter_list|(
name|ex
parameter_list|)
value|(((ex).a_entry< PAGSIZ) ? -PAGSIZ : 0)
end_define

begin_define
define|#
directive|define
name|TEXT_START
parameter_list|(
name|ex
parameter_list|)
value|(N_TXTADDR(ex) + N_ADJUST(ex))
end_define

begin_define
define|#
directive|define
name|DATA_START
parameter_list|(
name|ex
parameter_list|)
value|(N_DATADDR(ex) + N_ADJUST(ex))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Get the SunOS a.out and relocation nomenclature */
end_comment

begin_define
define|#
directive|define
name|EX_DYNAMIC
value|1
end_define

begin_define
define|#
directive|define
name|N_IS_DYNAMIC
parameter_list|(
name|ex
parameter_list|)
value|((ex).a_dynamic)
end_define

begin_define
define|#
directive|define
name|N_SET_FLAG
parameter_list|(
name|ex
parameter_list|,
name|f
parameter_list|)
value|{			\ 	(ex).a_dynamic = ((f)& EX_DYNAMIC);	\ }
end_define

begin_undef
undef|#
directive|undef
name|relocation_info
end_undef

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_sparc
end_define

begin_define
define|#
directive|define
name|r_symbolnum
value|r_index
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NetBSD */
end_comment

begin_define
define|#
directive|define
name|N_BADMID
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_GETMID(ex) != 0&& N_GETMID(ex) != MID_MACHINE&& \ 						!md_midcompat(&(ex)))
end_define

begin_comment
comment|/* Sparc (Sun 4) macros */
end_comment

begin_define
define|#
directive|define
name|RELOC_ADDRESS
parameter_list|(
name|r
parameter_list|)
value|((r)->r_address)
end_define

begin_define
define|#
directive|define
name|RELOC_EXTERN_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_extern)
end_define

begin_define
define|#
directive|define
name|RELOC_TYPE
parameter_list|(
name|r
parameter_list|)
value|((r)->r_symbolnum)
end_define

begin_define
define|#
directive|define
name|RELOC_SYMBOL
parameter_list|(
name|r
parameter_list|)
value|((r)->r_symbolnum)
end_define

begin_define
define|#
directive|define
name|RELOC_MEMORY_SUB_P
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RTLD
end_ifdef

begin_comment
comment|/* XXX - consider this making SUN_COMPAT --> repercussions on rrs.c */
end_comment

begin_define
define|#
directive|define
name|RELOC_MEMORY_ADD_P
parameter_list|(
name|r
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELOC_MEMORY_ADD_P
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RELOC_ADD_EXTRA
parameter_list|(
name|r
parameter_list|)
value|((r)->r_addend)
end_define

begin_define
define|#
directive|define
name|RELOC_PCREL_P
parameter_list|(
name|r
parameter_list|)
define|\
value|(((r)->r_type>= RELOC_DISP8&& (r)->r_type<= RELOC_WDISP22) \ 	 || ((r)->r_type == RELOC_PC10 || (r)->r_type == RELOC_PC22)  \ 	 || (r)->r_type == RELOC_JMP_TBL)
end_define

begin_define
define|#
directive|define
name|RELOC_VALUE_RIGHTSHIFT
parameter_list|(
name|r
parameter_list|)
value|(reloc_target_rightshift[(r)->r_type])
end_define

begin_define
define|#
directive|define
name|RELOC_TARGET_SIZE
parameter_list|(
name|r
parameter_list|)
value|(reloc_target_size[(r)->r_type])
end_define

begin_define
define|#
directive|define
name|RELOC_TARGET_BITPOS
parameter_list|(
name|r
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|RELOC_TARGET_BITSIZE
parameter_list|(
name|r
parameter_list|)
value|(reloc_target_bitsize[(r)->r_type])
end_define

begin_define
define|#
directive|define
name|RELOC_JMPTAB_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_type == RELOC_JMP_TBL)
end_define

begin_define
define|#
directive|define
name|RELOC_BASEREL_P
parameter_list|(
name|r
parameter_list|)
define|\
value|((r)->r_type>= RELOC_BASE10&& (r)->r_type<= RELOC_BASE22)
end_define

begin_define
define|#
directive|define
name|RELOC_RELATIVE_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_type == RELOC_RELATIVE)
end_define

begin_define
define|#
directive|define
name|RELOC_COPY_DAT
value|(RELOC_RELATIVE+1)
end_define

begin_comment
comment|/*XXX*/
end_comment

begin_define
define|#
directive|define
name|RELOC_COPY_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_type == RELOC_COPY_DAT)
end_define

begin_define
define|#
directive|define
name|RELOC_LAZY_P
parameter_list|(
name|r
parameter_list|)
value|((r)->r_type == RELOC_JMP_SLOT)
end_define

begin_define
define|#
directive|define
name|RELOC_STATICS_THROUGH_GOT_P
parameter_list|(
name|r
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|JMPSLOT_NEEDS_RELOC
value|(1)
end_define

begin_comment
comment|/*  * Define the range of usable Global Offset Table offsets  * when using sparc 13 bit relocation types (-4096 - 4092).  */
end_comment

begin_define
define|#
directive|define
name|MAX_GOTSIZE
value|(8192)
end_define

begin_define
define|#
directive|define
name|MAX_GOTOFF
value|(4092)
end_define

begin_define
define|#
directive|define
name|MIN_GOTOFF
value|(-4096)
end_define

begin_define
define|#
directive|define
name|CHECK_GOT_RELOC
parameter_list|(
name|r
parameter_list|)
define|\
value|((r)->r_type == RELOC_PC10 || (r)->r_type == RELOC_PC22)
end_define

begin_define
define|#
directive|define
name|md_got_reloc
parameter_list|(
name|r
parameter_list|)
value|(-(r)->r_address)
end_define

begin_define
define|#
directive|define
name|RELOC_INIT_SEGMENT_RELOC
parameter_list|(
name|r
parameter_list|)
value|((r)->r_type = RELOC_32)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUN_COMPAT
end_ifdef

begin_comment
comment|/*  * Sun plays games with `r_addend'  */
end_comment

begin_define
define|#
directive|define
name|md_get_rt_segment_addend
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Width of a Global Offset Table entry */
end_comment

begin_typedef
typedef|typedef
name|long
name|got_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|jmpslot
block|{
name|u_long
name|opcode1
decl_stmt|;
name|u_long
name|opcode2
decl_stmt|;
name|u_long
name|reloc_index
decl_stmt|;
define|#
directive|define
name|JMPSLOT_RELOC_MASK
value|(0x003fffff)
comment|/* 22 bits */
block|}
name|jmpslot_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAVE
value|0x9de3bfa0
end_define

begin_comment
comment|/* Build stack frame (opcode1) */
end_comment

begin_define
define|#
directive|define
name|SETHI
value|0x03000000
end_define

begin_comment
comment|/* %hi(addr) -> %g1 (opcode1) */
end_comment

begin_define
define|#
directive|define
name|CALL
value|0x40000000
end_define

begin_comment
comment|/* Call instruction (opcode2) */
end_comment

begin_define
define|#
directive|define
name|JMP
value|0x81c06000
end_define

begin_comment
comment|/* Jump %g1 instruction (opcode2) */
end_comment

begin_define
define|#
directive|define
name|NOP
value|0x01000000
end_define

begin_comment
comment|/* Delay slot NOP for (reloc_index) */
end_comment

begin_define
define|#
directive|define
name|TRAP
value|0x91d02001
end_define

begin_comment
comment|/* ta 0x1 */
end_comment

begin_comment
comment|/*  * Byte swap defs for cross linking  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEED_SWAP
argument_list|)
end_if

begin_define
define|#
directive|define
name|md_swapin_exec_hdr
parameter_list|(
name|h
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_exec_hdr
parameter_list|(
name|h
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_symbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_symbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_zsymbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_zsymbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_reloc
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_reloc
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin__dynamic
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout__dynamic
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_section_dispatch_table
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_section_dispatch_table
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_so_debug
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_so_debug
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_rrs_hash
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_rrs_hash
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_sod
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_sod
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_jmpslot
parameter_list|(
name|j
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_got
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_ranlib_hdr
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_ranlib_hdr
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_SWAP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_LINKER
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SWAP
end_ifdef

begin_comment
comment|/* Define IO byte swapping routines */
end_comment

begin_decl_stmt
name|void
name|md_swapin_exec_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapout_exec_hdr
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapin_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapout_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_swapout_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_swapin_symbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|swap_symbols(s,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_symbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|swap_symbols(s,n)
end_define

begin_define
define|#
directive|define
name|md_swapin_zsymbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|swap_zsymbols(s,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_zsymbols
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|swap_zsymbols(s,n)
end_define

begin_define
define|#
directive|define
name|md_swapin__dynamic
parameter_list|(
name|l
parameter_list|)
value|swap__dynamic(l)
end_define

begin_define
define|#
directive|define
name|md_swapout__dynamic
parameter_list|(
name|l
parameter_list|)
value|swap__dynamic(l)
end_define

begin_define
define|#
directive|define
name|md_swapin_section_dispatch_table
parameter_list|(
name|l
parameter_list|)
value|swap_section_dispatch_table(l)
end_define

begin_define
define|#
directive|define
name|md_swapout_section_dispatch_table
parameter_list|(
name|l
parameter_list|)
value|swap_section_dispatch_table(l)
end_define

begin_define
define|#
directive|define
name|md_swapin_so_debug
parameter_list|(
name|d
parameter_list|)
value|swap_so_debug(d)
end_define

begin_define
define|#
directive|define
name|md_swapout_so_debug
parameter_list|(
name|d
parameter_list|)
value|swap_so_debug(d)
end_define

begin_define
define|#
directive|define
name|md_swapin_rrs_hash
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|)
value|swap_rrs_hash(f,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_rrs_hash
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|)
value|swap_rrs_hash(f,n)
end_define

begin_define
define|#
directive|define
name|md_swapin_sod
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
value|swapin_sod(l,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_sod
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
value|swapout_sod(l,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_got
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
value|swap_longs((long*)(g),n)
end_define

begin_define
define|#
directive|define
name|md_swapin_ranlib_hdr
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|swap_ranlib_hdr(h,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_ranlib_hdr
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|swap_ranlib_hdr(h,n)
end_define

begin_define
define|#
directive|define
name|md_swap_short
parameter_list|(
name|x
parameter_list|)
value|( (((x)>> 8)& 0xff) | (((x)& 0xff)<< 8) )
end_define

begin_define
define|#
directive|define
name|md_swap_long
parameter_list|(
name|x
parameter_list|)
value|( (((x)>> 24)& 0xff    ) | (((x)>> 8 )& 0xff00   ) | \ 			(((x)<< 8 )& 0xff0000) | (((x)<< 24)& 0xff000000))
end_define

begin_define
define|#
directive|define
name|get_byte
parameter_list|(
name|p
parameter_list|)
value|( ((unsigned char *)(p))[0] )
end_define

begin_define
define|#
directive|define
name|get_short
parameter_list|(
name|p
parameter_list|)
value|( ( ((unsigned char *)(p))[1]<< 8) | \ 			  ( ((unsigned char *)(p))[0]     )   \ 			)
end_define

begin_define
define|#
directive|define
name|get_long
parameter_list|(
name|p
parameter_list|)
value|( ( ((unsigned char *)(p))[3]<< 24) | \ 			  ( ((unsigned char *)(p))[2]<< 16) | \ 			  ( ((unsigned char *)(p))[1]<< 8 ) | \ 			  ( ((unsigned char *)(p))[0]      )   \ 			)
end_define

begin_define
define|#
directive|define
name|put_byte
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ ((unsigned char *)(p))[0] = ((unsigned long)(v)); }
end_define

begin_define
define|#
directive|define
name|put_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ ((unsigned char *)(p))[1] =			\ 				((((unsigned long)(v))>> 8)& 0xff); 	\ 			  ((unsigned char *)(p))[0] =			\ 				((((unsigned long)(v))     )& 0xff); }
end_define

begin_define
define|#
directive|define
name|put_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ ((unsigned char *)(p))[3] =			\ 				((((unsigned long)(v))>> 24)& 0xff); 	\ 			  ((unsigned char *)(p))[2] =			\ 				((((unsigned long)(v))>> 16)& 0xff); 	\ 			  ((unsigned char *)(p))[1] =			\ 				((((unsigned long)(v))>>  8)& 0xff); 	\ 			  ((unsigned char *)(p))[0] =			\ 				((((unsigned long)(v))      )& 0xff); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We need not swap, but must pay attention to alignment: */
end_comment

begin_define
define|#
directive|define
name|md_swap_short
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|md_swap_long
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|get_byte
parameter_list|(
name|p
parameter_list|)
value|( ((unsigned char *)(p))[0] )
end_define

begin_define
define|#
directive|define
name|get_short
parameter_list|(
name|p
parameter_list|)
value|( ( ((unsigned char *)(p))[0]<< 8) | \ 			  ( ((unsigned char *)(p))[1]     )   \ 			)
end_define

begin_define
define|#
directive|define
name|get_long
parameter_list|(
name|p
parameter_list|)
value|( ( ((unsigned char *)(p))[0]<< 24) | \ 			  ( ((unsigned char *)(p))[1]<< 16) | \ 			  ( ((unsigned char *)(p))[2]<< 8 ) | \ 			  ( ((unsigned char *)(p))[3]      )   \ 			)
end_define

begin_define
define|#
directive|define
name|put_byte
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ ((unsigned char *)(p))[0] = ((unsigned long)(v)); }
end_define

begin_define
define|#
directive|define
name|put_short
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ ((unsigned char *)(p))[0] =			\ 				((((unsigned long)(v))>> 8)& 0xff); 	\ 			  ((unsigned char *)(p))[1] =			\ 				((((unsigned long)(v))     )& 0xff); }
end_define

begin_define
define|#
directive|define
name|put_long
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|{ ((unsigned char *)(p))[0] =			\ 				((((unsigned long)(v))>> 24)& 0xff); 	\ 			  ((unsigned char *)(p))[1] =			\ 				((((unsigned long)(v))>> 16)& 0xff); 	\ 			  ((unsigned char *)(p))[2] =			\ 				((((unsigned long)(v))>>  8)& 0xff); 	\ 			  ((unsigned char *)(p))[3] =			\ 				((((unsigned long)(v))      )& 0xff); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_SWAP */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not a cross linker: use native */
end_comment

begin_define
define|#
directive|define
name|md_swap_short
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|md_swap_long
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|get_byte
parameter_list|(
name|where
parameter_list|)
value|(*(char *)(where))
end_define

begin_define
define|#
directive|define
name|get_short
parameter_list|(
name|where
parameter_list|)
value|(*(short *)(where))
end_define

begin_define
define|#
directive|define
name|get_long
parameter_list|(
name|where
parameter_list|)
value|(*(long *)(where))
end_define

begin_define
define|#
directive|define
name|put_byte
parameter_list|(
name|where
parameter_list|,
name|what
parameter_list|)
value|(*(char *)(where) = (what))
end_define

begin_define
define|#
directive|define
name|put_short
parameter_list|(
name|where
parameter_list|,
name|what
parameter_list|)
value|(*(short *)(where) = (what))
end_define

begin_define
define|#
directive|define
name|put_long
parameter_list|(
name|where
parameter_list|,
name|what
parameter_list|)
value|(*(long *)(where) = (what))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_LINKER */
end_comment

begin_decl_stmt
name|void
name|md_init_header
name|__P
argument_list|(
operator|(
expr|struct
name|exec
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|md_get_addend
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_relocate
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
name|long
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_fix_jmpslot
name|__P
argument_list|(
operator|(
name|jmpslot_t
operator|*
operator|,
name|long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|md_make_reloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_jmpreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_gotreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_make_copyreloc
name|__P
argument_list|(
operator|(
expr|struct
name|relocation_info
operator|*
operator|,
expr|struct
name|relocation_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_set_breakpoint
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

