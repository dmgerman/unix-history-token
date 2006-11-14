begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_SB
value|1
end_define

begin_comment
comment|/* UWX_TRACE=b: scoreboard mgmt */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_UINFO
value|2
end_define

begin_comment
comment|/* UWX_TRACE=i: unwind info */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_RSTATE
value|4
end_define

begin_comment
comment|/* UWX_TRACE=r: reg state vector */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_STEP
value|8
end_define

begin_comment
comment|/* UWX_TRACE=s: step */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_UTABLE
value|16
end_define

begin_comment
comment|/* UWX_TRACE=t: unwind tbl search */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_CONTEXT
value|32
end_define

begin_comment
comment|/* UWX_TRACE=c: context */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_COPYIN
value|64
end_define

begin_comment
comment|/* UWX_TRACE=C: copyin callback */
end_comment

begin_define
define|#
directive|define
name|UWX_TRACE_LOOKUPIP
value|128
end_define

begin_comment
comment|/* UWX_TRACE=L: lookupip callback */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UWX_TRACE_ENABLE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|uwx_trace_init
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|uwx_dump_rstate
parameter_list|(
name|int
name|regid
parameter_list|,
name|uint64_t
name|rstate
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|uwx_rhdr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|uwx_dump_scoreboard
parameter_list|(
name|struct
name|uwx_scoreboard
modifier|*
name|scoreboard
parameter_list|,
name|int
name|nsbreg
parameter_list|,
name|struct
name|uwx_rhdr
modifier|*
name|rhdr
parameter_list|,
name|int
name|cur_slot
parameter_list|,
name|int
name|ip_slot
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRACE_INIT
value|uwx_trace_init(env);
end_define

begin_define
define|#
directive|define
name|TRACE_B_REUSE
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_alloc_scoreboard: reuse id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_ALLOC
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_alloc_scoreboard: alloc id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_POP
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_pop_scoreboards: free id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_LABEL
parameter_list|(
name|label
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_label_scoreboard: label %d\n", (label));
end_define

begin_define
define|#
directive|define
name|TRACE_B_LABEL_COPY
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_label_scoreboard: copy id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_LABEL_REVERSE
parameter_list|(
name|back
parameter_list|,
name|new
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_label_scoreboard: reverse link %d -> %d\n", \ 			    (new)->id, ((back) == 0) ? -1 : (back)->id);
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY
parameter_list|(
name|label
parameter_list|,
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_copy_scoreboard: label %d, cur sb id %d\n", (label), (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_FREE
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_copy_scoreboard: free id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_FOUND
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_copy_scoreboard: found id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_COPY
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_copy_scoreboard: copy id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_REVERSE
parameter_list|(
name|back
parameter_list|,
name|new
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_copy_scoreboard: reverse link %d -> %d\n", \ 			    (new)->id, ((back) == 0) ? -1 : (back)->id);
end_define

begin_define
define|#
directive|define
name|TRACE_B_FREE
parameter_list|(
name|id
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_SB) \ 	printf("uwx_free_scoreboards: free id %d\n", (id));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_RHDR_1
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_rhdr:     %02x                   %s\n", \ 			(b0), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_RHDR_1L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_rhdr:     %02x %08x          %s\n", \ 			(b0), (int)(val), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_RHDR_2L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_rhdr:     %02x %02x %08x       %s\n", \ 			(b0), (b1), (int)(val), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_1
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x                   %s\n", \ 			(b0), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_1L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x %08x          %s\n", \ 			(b0), (int)(val), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_1LL
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x %08x %08x %s\n", \ 			(b0), (int)(val1), (int)(val2), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_2
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x %02x                %s\n", \ 			(b0), (b1), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_2L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x %02x %08x       %s\n", \ 			(b0), (b1), (int)(val), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_3
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x %02x %02x             %s\n", \ 			(b0), (b1), (b2), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_4
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|,
name|b3
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: %02x %02x %02x %02x          %s\n", \ 			(b0), (b1), (b2), (b3), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_SPILL_BASE
parameter_list|(
name|spill_base
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: spill base = %08x\n", (int)(spill_base));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_MASKS
parameter_list|(
name|gr_mem_mask
parameter_list|,
name|gr_gr_mask
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: gr_mem_mask = %02x; gr_gr_mask = %02x\n", \ 			(gr_mem_mask), (gr_gr_mask));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_NSPILL
parameter_list|(
name|ngr
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_prologue: ngr = %d\n", (ngr));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_BODY_1
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_body:     %02x                   %s\n", \ 			(b0), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_BODY_1L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_body:     %02x %08x          %s\n", \ 			(b0), (int)(val), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_BODY_1LL
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UINFO) \ 	printf("uwx_decode_body:     %02x %08x %08x %s\n", \ 			(b0), (int)(val1), (int)(val2), (name));
end_define

begin_define
define|#
directive|define
name|TRACE_R_UIB
parameter_list|(
name|uentry
parameter_list|,
name|ulen
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_RSTATE) \ 	printf("Unwind info block (flags = %08x %08x, ulen = %d)\n", \ 		    (unsigned int)((uentry)->unwind_flags>> 32), \ 		    (unsigned int)(uentry)->unwind_flags, \ 		    (ulen));
end_define

begin_define
define|#
directive|define
name|TRACE_R_DUMP_SB
parameter_list|(
name|scoreboard
parameter_list|,
name|rhdr
parameter_list|,
name|cur_slot
parameter_list|,
name|ip_slot
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_RSTATE) \ 	uwx_dump_scoreboard(scoreboard, env->nsbreg, \&(rhdr), cur_slot, ip_slot);
end_define

begin_define
define|#
directive|define
name|TRACE_S_STEP
parameter_list|(
name|rstate
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_STEP) { \ 	printf("uwx_restore_markers:\n"); \ 	uwx_dump_rstate(SBREG_RP, (rstate)[SBREG_RP]); \ 	uwx_dump_rstate(SBREG_PSP, (rstate)[SBREG_PSP]); \ 	uwx_dump_rstate(SBREG_PFS, (rstate)[SBREG_PFS]); \     }
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_REG
parameter_list|(
name|regname
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_STEP) \ 	printf("  restore %-7s (rstate = %08x %08x) = %08x %08x\n", \ 			regname, \ 			(unsigned int) ((rstate)>> 32), \ 			(unsigned int) (rstate), \ 			(unsigned int) ((val)>> 32), \ 			(unsigned int) (val));
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_GR
parameter_list|(
name|regid
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_STEP) \ 	printf("  restore GR%d     (rstate = %08x %08x) = %08x %08x\n", \ 			(regid) + 4, \ 			(unsigned int) ((rstate)>> 32), \ 			(unsigned int) (rstate), \ 			(unsigned int) ((val)>> 32), \ 			(unsigned int) (val));
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_BR
parameter_list|(
name|regid
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_STEP) \ 	printf("  restore BR%d     (rstate = %08x %08x) = %08x %08x\n", \ 			(regid) + 1, \ 			(unsigned int) ((rstate)>> 32), \ 			(unsigned int) (rstate), \ 			(unsigned int) ((val)>> 32), \ 			(unsigned int) (val));
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_FR
parameter_list|(
name|regid
parameter_list|,
name|rstate
parameter_list|,
name|fval
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_STEP) \ 	printf("  restore FR%d     (rstate = %08x %08x) = %08x %08x %08x %08x\n", \ 			(regid) + 1, \ 			(unsigned int) ((rstate)>> 32), \ 			(unsigned int) (rstate), \ 			(unsigned int) ((fval[0])>> 32), \ 			(unsigned int) (fval[0]), \ 			(unsigned int) ((fval[1])>> 32), \ 			(unsigned int) (fval[1]));
end_define

begin_define
define|#
directive|define
name|TRACE_T_SEARCH32
parameter_list|(
name|ip
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UTABLE) \ 	printf("uwx_search_utable32 (relative ip = %08x)\n", (ip));
end_define

begin_define
define|#
directive|define
name|TRACE_T_BINSEARCH32
parameter_list|(
name|lb
parameter_list|,
name|ub
parameter_list|,
name|mid
parameter_list|,
name|code_start
parameter_list|,
name|code_end
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_UTABLE) \ 	printf("    lb/ub = %d/%d, mid = %d, start/end = %08x %08x\n", \ 			    lb, ub, mid, code_start, code_end);
end_define

begin_define
define|#
directive|define
name|TRACE_C_GET_REG
parameter_list|(
name|regid
parameter_list|,
name|bsp
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_CONTEXT) \ 	    printf("uwx_get_reg (gr%d, bsp = %08x %08x)\n", \ 			(regid) - UWX_REG_GR(0), \ 			(unsigned int) ((bsp)>> 32), \ 			(unsigned int) (bsp));
end_define

begin_define
define|#
directive|define
name|TRACE_C_ROTATE_GR
parameter_list|(
name|regid
parameter_list|,
name|sor
parameter_list|,
name|rrb_gr
parameter_list|,
name|newregid
parameter_list|)
define|\
value|if (env->trace& UWX_TRACE_CONTEXT) \ 	    printf("uwx_get_reg (gr%d, sor = %d, rrb = %d) --> gr%d\n", \ 			(regid) + 32, \ 			(sor), \ 			(rrb_gr), \ 			(newregid) + 32);
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_COPYIN4
parameter_list|(
name|rem
parameter_list|,
name|len
parameter_list|,
name|wp
parameter_list|)
define|\
value|if (info->trace& UWX_TRACE_COPYIN) \ 	printf("copyin (rem = %08x %08x, len = %d, val = %08x)\n", \ 			(unsigned int) ((rem)>> 32), \ 			(unsigned int) (rem), \ 			(len), *(wp));
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_COPYIN8
parameter_list|(
name|rem
parameter_list|,
name|len
parameter_list|,
name|dp
parameter_list|)
define|\
value|if (info->trace& UWX_TRACE_COPYIN) \ 	printf("copyin (rem = %08x %08x, len = %d, val = %08x %08x)\n", \ 			(unsigned int) ((rem)>> 32), \ 			(unsigned int) (rem), \ 			(len), \ 			((unsigned int *)(dp))[0], \ 			((unsigned int *)(dp))[1]);
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_LOOKUP
parameter_list|(
name|ip
parameter_list|)
define|\
value|if (info->trace& UWX_TRACE_LOOKUPIP) \ 	printf("Lookup IP callback: ip = %08x %08x\n", \ 			(unsigned int) ((ip)>> 32), \ 			(unsigned int) (ip));
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_LOOKUP_DESC
parameter_list|(
name|text_base
parameter_list|,
name|unwind_base
parameter_list|)
define|\
value|if (info->trace& UWX_TRACE_LOOKUPIP) { \ 	    printf("  text base:    %08x %08x\n", \ 			(unsigned int) ((text_base)>> 32), \ 			(unsigned int) (text_base)); \ 	    printf("  unwind base:  %08x %08x\n", \ 			(unsigned int) ((uint64_t)(unwind_base)>> 32), \ 			(unsigned int) (unwind_base)); \ 	    printf("  unwind flags: %08x %08x\n", \ 			(unsigned int) ((unwind_base)[0]>> 32), \ 			(unsigned int) (unwind_base)[0]); \ 	    printf("  unwind start: %08x %08x\n", \ 			(unsigned int) (((text_base)+(unwind_base)[1])>> 32), \ 			(unsigned int) ((text_base)+(unwind_base)[1])); \ 	    printf("  unwind end:   %08x %08x\n", \ 			(unsigned int) (((text_base)+(unwind_base)[2])>> 32), \ 			(unsigned int) ((text_base)+(unwind_base)[2])); \ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !UWX_TRACE_ENABLE */
end_comment

begin_define
define|#
directive|define
name|TRACE_INIT
end_define

begin_define
define|#
directive|define
name|TRACE_B_REUSE
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_ALLOC
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_POP
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_LABEL
parameter_list|(
name|label
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_LABEL_COPY
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_LABEL_REVERSE
parameter_list|(
name|back
parameter_list|,
name|new
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY
parameter_list|(
name|label
parameter_list|,
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_FREE
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_FOUND
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_COPY
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_COPY_REVERSE
parameter_list|(
name|back
parameter_list|,
name|new
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_B_FREE
parameter_list|(
name|id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_RHDR_1
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_RHDR_1L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_RHDR_2L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_1
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_1L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_1LL
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_2
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_2L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|parm1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_3
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_4
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|b1
parameter_list|,
name|b2
parameter_list|,
name|b3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_SPILL_BASE
parameter_list|(
name|spill_base
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_MASKS
parameter_list|(
name|gr_mem_mask
parameter_list|,
name|gr_gr_mask
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_PROLOGUE_NSPILL
parameter_list|(
name|ngr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_BODY_1
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_BODY_1L
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|parm1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_I_DECODE_BODY_1LL
parameter_list|(
name|name
parameter_list|,
name|b0
parameter_list|,
name|parm1
parameter_list|,
name|parm2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_R_UIB
parameter_list|(
name|uentry
parameter_list|,
name|ulen
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_R_DUMP_SB
parameter_list|(
name|scoreboard
parameter_list|,
name|rhdr
parameter_list|,
name|cur_slot
parameter_list|,
name|ip_slot
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_S_STEP
parameter_list|(
name|rstate
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_REG
parameter_list|(
name|regname
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_GR
parameter_list|(
name|regid
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_BR
parameter_list|(
name|regid
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_S_RESTORE_FR
parameter_list|(
name|regid
parameter_list|,
name|rstate
parameter_list|,
name|val
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_T_SEARCH32
parameter_list|(
name|ip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_T_BINSEARCH32
parameter_list|(
name|lb
parameter_list|,
name|ub
parameter_list|,
name|mid
parameter_list|,
name|code_start
parameter_list|,
name|code_end
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_C_GET_REG
parameter_list|(
name|regid
parameter_list|,
name|bsp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_C_ROTATE_GR
parameter_list|(
name|regid
parameter_list|,
name|sor
parameter_list|,
name|rrb_gr
parameter_list|,
name|newregid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_COPYIN4
parameter_list|(
name|rem
parameter_list|,
name|len
parameter_list|,
name|wp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_COPYIN8
parameter_list|(
name|rem
parameter_list|,
name|len
parameter_list|,
name|dp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_LOOKUP
parameter_list|(
name|ip
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TRACE_SELF_LOOKUP_DESC
parameter_list|(
name|text_base
parameter_list|,
name|unwind_base
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UWX_TRACE_ENABLE */
end_comment

end_unit

