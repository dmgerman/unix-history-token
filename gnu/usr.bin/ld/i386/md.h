begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: md.h,v 1.3 1993/11/22 19:05:24 jkh Exp $		- I386 dependent definitions  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CROSS_LINKER
argument_list|)
operator|&&
name|defined
argument_list|(
name|XHOST
argument_list|)
operator|&&
name|XHOST
operator|==
name|sparc
end_if

begin_define
define|#
directive|define
name|NEED_SWAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_ALIGNMENT
value|(sizeof (long))
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PAGSIZ
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_SET_FLAG
parameter_list|(
name|ex
parameter_list|,
name|f
parameter_list|)
value|N_SETMAGIC(ex,N_GETMAGIC(ex), MID_MACHINE, \ 						N_GETFLAG(ex)|(f))
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

begin_define
define|#
directive|define
name|RELOC_STATICS_THROUGH_GOT_P
parameter_list|(
name|r
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|JMPSLOT_NEEDS_RELOC
value|(0)
end_define

begin_define
define|#
directive|define
name|md_got_reloc
parameter_list|(
name|r
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|md_get_rt_segment_addend
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|)
value|md_get_addend(r,a)
end_define

begin_comment
comment|/* Width of a Global Offset Table entry */
end_comment

begin_define
define|#
directive|define
name|GOT_ENTRY_SIZE
value|4
end_define

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
name|u_short
name|opcode
decl_stmt|;
name|u_short
name|addr
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|reloc_index
decl_stmt|;
define|#
directive|define
name|JMPSLOT_RELOC_MASK
value|0xffff
block|}
name|jmpslot_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NOP
value|0x90
end_define

begin_define
define|#
directive|define
name|CALL
value|0xe890
end_define

begin_comment
comment|/* NOP + CALL opcode */
end_comment

begin_define
define|#
directive|define
name|JUMP
value|0xe990
end_define

begin_comment
comment|/* NOP + JMP opcode */
end_comment

begin_define
define|#
directive|define
name|TRAP
value|0xcc
end_define

begin_comment
comment|/* INT 3 */
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
name|md_swapin_link_dynamic
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_link_dynamic
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_link_dynamic_2
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_link_dynamic_2
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapin_ld_debug
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_ld_debug
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
name|md_swapin_link_object
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|md_swapout_link_object
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
name|md_swapin_link_dynamic
parameter_list|(
name|l
parameter_list|)
value|swap_link_dynamic(l)
end_define

begin_define
define|#
directive|define
name|md_swapout_link_dynamic
parameter_list|(
name|l
parameter_list|)
value|swap_link_dynamic(l)
end_define

begin_define
define|#
directive|define
name|md_swapin_link_dynamic_2
parameter_list|(
name|l
parameter_list|)
value|swap_link_dynamic_2(l)
end_define

begin_define
define|#
directive|define
name|md_swapout_link_dynamic_2
parameter_list|(
name|l
parameter_list|)
value|swap_link_dynamic_2(l)
end_define

begin_define
define|#
directive|define
name|md_swapin_ld_debug
parameter_list|(
name|d
parameter_list|)
value|swap_ld_debug(d)
end_define

begin_define
define|#
directive|define
name|md_swapout_ld_debug
parameter_list|(
name|d
parameter_list|)
value|swap_ld_debug(d)
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
name|md_swapin_link_object
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
value|swapin_link_object(l,n)
end_define

begin_define
define|#
directive|define
name|md_swapout_link_object
parameter_list|(
name|l
parameter_list|,
name|n
parameter_list|)
value|swapout_link_object(l,n)
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

end_unit

