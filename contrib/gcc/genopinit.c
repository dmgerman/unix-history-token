begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generate code to initialize optabs from machine description.    Copyright (C) 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bconfig.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"errors.h"
end_include

begin_include
include|#
directive|include
file|"gensupport.h"
end_include

begin_comment
comment|/* Many parts of GCC use arrays that are indexed by machine mode and    contain the insn codes for pattern in the MD file that perform a given    operation on operands of that mode.     These patterns are present in the MD file with names that contain    the mode(s) used and the name of the operation.  This program    writes a function `init_all_optabs' that initializes the optabs with    all the insn codes of the relevant patterns present in the MD file.     This array contains a list of optabs that need to be initialized.  Within    each string, the name of the pattern to be matched against is delimited    with $( and $).  In the string, $a and $b are used to match a short mode    name (the part of the mode name not including `mode' and converted to    lower-case).  When writing out the initializer, the entire string is    used.  $A and $B are replaced with the full name of the mode; $a and $b    are replaced with the short form of the name, as above.     If $N is present in the pattern, it means the two modes must be consecutive    widths in the same mode class (e.g, QImode and HImode).  $I means that    only full integer modes should be considered for the next mode, and $F    means that only float modes should be considered.    $P means that both full and partial integer modes should be considered.     $V means to emit 'v' if the first mode is a MODE_FLOAT mode.     For some optabs, we store the operation by RTL codes.  These are only    used for comparisons.  In that case, $c and $C are the lower-case and    upper-case forms of the comparison, respectively.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|optabs
index|[]
init|=
block|{
literal|"sext_optab->handlers[$B][$A].insn_code = CODE_FOR_$(extend$a$b2$)"
block|,
literal|"zext_optab->handlers[$B][$A].insn_code = CODE_FOR_$(zero_extend$a$b2$)"
block|,
literal|"sfix_optab->handlers[$B][$A].insn_code = CODE_FOR_$(fix$F$a$I$b2$)"
block|,
literal|"ufix_optab->handlers[$B][$A].insn_code = CODE_FOR_$(fixuns$F$a$b2$)"
block|,
literal|"sfixtrunc_optab->handlers[$B][$A].insn_code = CODE_FOR_$(fix_trunc$F$a$I$b2$)"
block|,
literal|"ufixtrunc_optab->handlers[$B][$A].insn_code = CODE_FOR_$(fixuns_trunc$F$a$I$b2$)"
block|,
literal|"sfloat_optab->handlers[$B][$A].insn_code = CODE_FOR_$(float$I$a$F$b2$)"
block|,
literal|"ufloat_optab->handlers[$B][$A].insn_code = CODE_FOR_$(floatuns$I$a$F$b2$)"
block|,
literal|"trunc_optab->handlers[$B][$A].insn_code = CODE_FOR_$(trunc$a$b2$)"
block|,
literal|"add_optab->handlers[$A].insn_code = CODE_FOR_$(add$P$a3$)"
block|,
literal|"addv_optab->handlers[$A].insn_code =\n\     add_optab->handlers[$A].insn_code = CODE_FOR_$(add$F$a3$)"
block|,
literal|"addv_optab->handlers[$A].insn_code = CODE_FOR_$(addv$I$a3$)"
block|,
literal|"sub_optab->handlers[$A].insn_code = CODE_FOR_$(sub$P$a3$)"
block|,
literal|"subv_optab->handlers[$A].insn_code =\n\     sub_optab->handlers[$A].insn_code = CODE_FOR_$(sub$F$a3$)"
block|,
literal|"subv_optab->handlers[$A].insn_code = CODE_FOR_$(subv$I$a3$)"
block|,
literal|"smul_optab->handlers[$A].insn_code = CODE_FOR_$(mul$P$a3$)"
block|,
literal|"smulv_optab->handlers[$A].insn_code =\n\     smul_optab->handlers[$A].insn_code = CODE_FOR_$(mul$F$a3$)"
block|,
literal|"smulv_optab->handlers[$A].insn_code = CODE_FOR_$(mulv$I$a3$)"
block|,
literal|"umul_highpart_optab->handlers[$A].insn_code = CODE_FOR_$(umul$a3_highpart$)"
block|,
literal|"smul_highpart_optab->handlers[$A].insn_code = CODE_FOR_$(smul$a3_highpart$)"
block|,
literal|"smul_widen_optab->handlers[$B].insn_code = CODE_FOR_$(mul$a$b3$)$N"
block|,
literal|"umul_widen_optab->handlers[$B].insn_code = CODE_FOR_$(umul$a$b3$)$N"
block|,
literal|"usmul_widen_optab->handlers[$B].insn_code = CODE_FOR_$(usmul$a$b3$)$N"
block|,
literal|"sdiv_optab->handlers[$A].insn_code = CODE_FOR_$(div$a3$)"
block|,
literal|"sdivv_optab->handlers[$A].insn_code = CODE_FOR_$(div$V$I$a3$)"
block|,
literal|"udiv_optab->handlers[$A].insn_code = CODE_FOR_$(udiv$I$a3$)"
block|,
literal|"sdivmod_optab->handlers[$A].insn_code = CODE_FOR_$(divmod$a4$)"
block|,
literal|"udivmod_optab->handlers[$A].insn_code = CODE_FOR_$(udivmod$a4$)"
block|,
literal|"smod_optab->handlers[$A].insn_code = CODE_FOR_$(mod$a3$)"
block|,
literal|"umod_optab->handlers[$A].insn_code = CODE_FOR_$(umod$a3$)"
block|,
literal|"fmod_optab->handlers[$A].insn_code = CODE_FOR_$(fmod$a3$)"
block|,
literal|"drem_optab->handlers[$A].insn_code = CODE_FOR_$(drem$a3$)"
block|,
literal|"ftrunc_optab->handlers[$A].insn_code = CODE_FOR_$(ftrunc$F$a2$)"
block|,
literal|"and_optab->handlers[$A].insn_code = CODE_FOR_$(and$a3$)"
block|,
literal|"ior_optab->handlers[$A].insn_code = CODE_FOR_$(ior$a3$)"
block|,
literal|"xor_optab->handlers[$A].insn_code = CODE_FOR_$(xor$a3$)"
block|,
literal|"ashl_optab->handlers[$A].insn_code = CODE_FOR_$(ashl$a3$)"
block|,
literal|"ashr_optab->handlers[$A].insn_code = CODE_FOR_$(ashr$a3$)"
block|,
literal|"lshr_optab->handlers[$A].insn_code = CODE_FOR_$(lshr$a3$)"
block|,
literal|"rotl_optab->handlers[$A].insn_code = CODE_FOR_$(rotl$a3$)"
block|,
literal|"rotr_optab->handlers[$A].insn_code = CODE_FOR_$(rotr$a3$)"
block|,
literal|"smin_optab->handlers[$A].insn_code = CODE_FOR_$(smin$a3$)"
block|,
literal|"smax_optab->handlers[$A].insn_code = CODE_FOR_$(smax$a3$)"
block|,
literal|"umin_optab->handlers[$A].insn_code = CODE_FOR_$(umin$I$a3$)"
block|,
literal|"umax_optab->handlers[$A].insn_code = CODE_FOR_$(umax$I$a3$)"
block|,
literal|"pow_optab->handlers[$A].insn_code = CODE_FOR_$(pow$a3$)"
block|,
literal|"atan2_optab->handlers[$A].insn_code = CODE_FOR_$(atan2$a3$)"
block|,
literal|"neg_optab->handlers[$A].insn_code = CODE_FOR_$(neg$P$a2$)"
block|,
literal|"negv_optab->handlers[$A].insn_code =\n\     neg_optab->handlers[$A].insn_code = CODE_FOR_$(neg$F$a2$)"
block|,
literal|"negv_optab->handlers[$A].insn_code = CODE_FOR_$(negv$I$a2$)"
block|,
literal|"abs_optab->handlers[$A].insn_code = CODE_FOR_$(abs$P$a2$)"
block|,
literal|"absv_optab->handlers[$A].insn_code =\n\     abs_optab->handlers[$A].insn_code = CODE_FOR_$(abs$F$a2$)"
block|,
literal|"absv_optab->handlers[$A].insn_code = CODE_FOR_$(absv$I$a2$)"
block|,
literal|"copysign_optab->handlers[$A].insn_code = CODE_FOR_$(copysign$F$a3$)"
block|,
literal|"sqrt_optab->handlers[$A].insn_code = CODE_FOR_$(sqrt$a2$)"
block|,
literal|"floor_optab->handlers[$A].insn_code = CODE_FOR_$(floor$a2$)"
block|,
literal|"lfloor_optab->handlers[$A].insn_code = CODE_FOR_$(lfloor$a2$)"
block|,
literal|"ceil_optab->handlers[$A].insn_code = CODE_FOR_$(ceil$a2$)"
block|,
literal|"lceil_optab->handlers[$A].insn_code = CODE_FOR_$(lceil$a2$)"
block|,
literal|"round_optab->handlers[$A].insn_code = CODE_FOR_$(round$a2$)"
block|,
literal|"btrunc_optab->handlers[$A].insn_code = CODE_FOR_$(btrunc$a2$)"
block|,
literal|"nearbyint_optab->handlers[$A].insn_code = CODE_FOR_$(nearbyint$a2$)"
block|,
literal|"rint_optab->handlers[$A].insn_code = CODE_FOR_$(rint$a2$)"
block|,
literal|"lrint_optab->handlers[$A].insn_code = CODE_FOR_$(lrint$a2$)"
block|,
literal|"sincos_optab->handlers[$A].insn_code = CODE_FOR_$(sincos$a3$)"
block|,
literal|"sin_optab->handlers[$A].insn_code = CODE_FOR_$(sin$a2$)"
block|,
literal|"asin_optab->handlers[$A].insn_code = CODE_FOR_$(asin$a2$)"
block|,
literal|"cos_optab->handlers[$A].insn_code = CODE_FOR_$(cos$a2$)"
block|,
literal|"acos_optab->handlers[$A].insn_code = CODE_FOR_$(acos$a2$)"
block|,
literal|"exp_optab->handlers[$A].insn_code = CODE_FOR_$(exp$a2$)"
block|,
literal|"exp10_optab->handlers[$A].insn_code = CODE_FOR_$(exp10$a2$)"
block|,
literal|"exp2_optab->handlers[$A].insn_code = CODE_FOR_$(exp2$a2$)"
block|,
literal|"expm1_optab->handlers[$A].insn_code = CODE_FOR_$(expm1$a2$)"
block|,
literal|"ldexp_optab->handlers[$A].insn_code = CODE_FOR_$(ldexp$a3$)"
block|,
literal|"logb_optab->handlers[$A].insn_code = CODE_FOR_$(logb$a2$)"
block|,
literal|"ilogb_optab->handlers[$A].insn_code = CODE_FOR_$(ilogb$a2$)"
block|,
literal|"log_optab->handlers[$A].insn_code = CODE_FOR_$(log$a2$)"
block|,
literal|"log10_optab->handlers[$A].insn_code = CODE_FOR_$(log10$a2$)"
block|,
literal|"log2_optab->handlers[$A].insn_code = CODE_FOR_$(log2$a2$)"
block|,
literal|"log1p_optab->handlers[$A].insn_code = CODE_FOR_$(log1p$a2$)"
block|,
literal|"tan_optab->handlers[$A].insn_code = CODE_FOR_$(tan$a2$)"
block|,
literal|"atan_optab->handlers[$A].insn_code = CODE_FOR_$(atan$a2$)"
block|,
literal|"strlen_optab->handlers[$A].insn_code = CODE_FOR_$(strlen$a$)"
block|,
literal|"one_cmpl_optab->handlers[$A].insn_code = CODE_FOR_$(one_cmpl$a2$)"
block|,
literal|"bswap_optab->handlers[$A].insn_code = CODE_FOR_$(bswap$a2$)"
block|,
literal|"ffs_optab->handlers[$A].insn_code = CODE_FOR_$(ffs$a2$)"
block|,
literal|"clz_optab->handlers[$A].insn_code = CODE_FOR_$(clz$a2$)"
block|,
literal|"ctz_optab->handlers[$A].insn_code = CODE_FOR_$(ctz$a2$)"
block|,
literal|"popcount_optab->handlers[$A].insn_code = CODE_FOR_$(popcount$a2$)"
block|,
literal|"parity_optab->handlers[$A].insn_code = CODE_FOR_$(parity$a2$)"
block|,
literal|"mov_optab->handlers[$A].insn_code = CODE_FOR_$(mov$a$)"
block|,
literal|"movstrict_optab->handlers[$A].insn_code = CODE_FOR_$(movstrict$a$)"
block|,
literal|"movmisalign_optab->handlers[$A].insn_code = CODE_FOR_$(movmisalign$a$)"
block|,
literal|"cmp_optab->handlers[$A].insn_code = CODE_FOR_$(cmp$a$)"
block|,
literal|"tst_optab->handlers[$A].insn_code = CODE_FOR_$(tst$a$)"
block|,
literal|"addcc_optab->handlers[$A].insn_code = CODE_FOR_$(add$acc$)"
block|,
literal|"bcc_gen_fctn[$C] = gen_$(b$c$)"
block|,
literal|"setcc_gen_code[$C] = CODE_FOR_$(s$c$)"
block|,
literal|"movcc_gen_code[$A] = CODE_FOR_$(mov$acc$)"
block|,
literal|"cbranch_optab->handlers[$A].insn_code = CODE_FOR_$(cbranch$a4$)"
block|,
literal|"cmov_optab->handlers[$A].insn_code = CODE_FOR_$(cmov$a6$)"
block|,
literal|"cstore_optab->handlers[$A].insn_code = CODE_FOR_$(cstore$a4$)"
block|,
literal|"push_optab->handlers[$A].insn_code = CODE_FOR_$(push$a1$)"
block|,
literal|"reload_in_optab[$A] = CODE_FOR_$(reload_in$a$)"
block|,
literal|"reload_out_optab[$A] = CODE_FOR_$(reload_out$a$)"
block|,
literal|"movmem_optab[$A] = CODE_FOR_$(movmem$a$)"
block|,
literal|"cmpstr_optab[$A] = CODE_FOR_$(cmpstr$a$)"
block|,
literal|"cmpstrn_optab[$A] = CODE_FOR_$(cmpstrn$a$)"
block|,
literal|"cmpmem_optab[$A] = CODE_FOR_$(cmpmem$a$)"
block|,
literal|"setmem_optab[$A] = CODE_FOR_$(setmem$a$)"
block|,
literal|"sync_add_optab[$A] = CODE_FOR_$(sync_add$I$a$)"
block|,
literal|"sync_sub_optab[$A] = CODE_FOR_$(sync_sub$I$a$)"
block|,
literal|"sync_ior_optab[$A] = CODE_FOR_$(sync_ior$I$a$)"
block|,
literal|"sync_and_optab[$A] = CODE_FOR_$(sync_and$I$a$)"
block|,
literal|"sync_xor_optab[$A] = CODE_FOR_$(sync_xor$I$a$)"
block|,
literal|"sync_nand_optab[$A] = CODE_FOR_$(sync_nand$I$a$)"
block|,
literal|"sync_old_add_optab[$A] = CODE_FOR_$(sync_old_add$I$a$)"
block|,
literal|"sync_old_sub_optab[$A] = CODE_FOR_$(sync_old_sub$I$a$)"
block|,
literal|"sync_old_ior_optab[$A] = CODE_FOR_$(sync_old_ior$I$a$)"
block|,
literal|"sync_old_and_optab[$A] = CODE_FOR_$(sync_old_and$I$a$)"
block|,
literal|"sync_old_xor_optab[$A] = CODE_FOR_$(sync_old_xor$I$a$)"
block|,
literal|"sync_old_nand_optab[$A] = CODE_FOR_$(sync_old_nand$I$a$)"
block|,
literal|"sync_new_add_optab[$A] = CODE_FOR_$(sync_new_add$I$a$)"
block|,
literal|"sync_new_sub_optab[$A] = CODE_FOR_$(sync_new_sub$I$a$)"
block|,
literal|"sync_new_ior_optab[$A] = CODE_FOR_$(sync_new_ior$I$a$)"
block|,
literal|"sync_new_and_optab[$A] = CODE_FOR_$(sync_new_and$I$a$)"
block|,
literal|"sync_new_xor_optab[$A] = CODE_FOR_$(sync_new_xor$I$a$)"
block|,
literal|"sync_new_nand_optab[$A] = CODE_FOR_$(sync_new_nand$I$a$)"
block|,
literal|"sync_compare_and_swap[$A] = CODE_FOR_$(sync_compare_and_swap$I$a$)"
block|,
literal|"sync_compare_and_swap_cc[$A] = CODE_FOR_$(sync_compare_and_swap_cc$I$a$)"
block|,
literal|"sync_lock_test_and_set[$A] = CODE_FOR_$(sync_lock_test_and_set$I$a$)"
block|,
literal|"sync_lock_release[$A] = CODE_FOR_$(sync_lock_release$I$a$)"
block|,
literal|"vec_set_optab->handlers[$A].insn_code = CODE_FOR_$(vec_set$a$)"
block|,
literal|"vec_extract_optab->handlers[$A].insn_code = CODE_FOR_$(vec_extract$a$)"
block|,
literal|"vec_init_optab->handlers[$A].insn_code = CODE_FOR_$(vec_init$a$)"
block|,
literal|"vec_shl_optab->handlers[$A].insn_code = CODE_FOR_$(vec_shl_$a$)"
block|,
literal|"vec_shr_optab->handlers[$A].insn_code = CODE_FOR_$(vec_shr_$a$)"
block|,
literal|"vec_realign_load_optab->handlers[$A].insn_code = CODE_FOR_$(vec_realign_load_$a$)"
block|,
literal|"vcond_gen_code[$A] = CODE_FOR_$(vcond$a$)"
block|,
literal|"vcondu_gen_code[$A] = CODE_FOR_$(vcondu$a$)"
block|,
literal|"ssum_widen_optab->handlers[$A].insn_code = CODE_FOR_$(widen_ssum$I$a3$)"
block|,
literal|"usum_widen_optab->handlers[$A].insn_code = CODE_FOR_$(widen_usum$I$a3$)"
block|,
literal|"udot_prod_optab->handlers[$A].insn_code = CODE_FOR_$(udot_prod$I$a$)"
block|,
literal|"sdot_prod_optab->handlers[$A].insn_code = CODE_FOR_$(sdot_prod$I$a$)"
block|,
literal|"reduc_smax_optab->handlers[$A].insn_code = CODE_FOR_$(reduc_smax_$a$)"
block|,
literal|"reduc_umax_optab->handlers[$A].insn_code = CODE_FOR_$(reduc_umax_$a$)"
block|,
literal|"reduc_smin_optab->handlers[$A].insn_code = CODE_FOR_$(reduc_smin_$a$)"
block|,
literal|"reduc_umin_optab->handlers[$A].insn_code = CODE_FOR_$(reduc_umin_$a$)"
block|,
literal|"reduc_splus_optab->handlers[$A].insn_code = CODE_FOR_$(reduc_splus_$a$)"
block|,
literal|"reduc_uplus_optab->handlers[$A].insn_code = CODE_FOR_$(reduc_uplus_$a$)"
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|gen_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|gen_insn
parameter_list|(
name|rtx
name|insn
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|XSTR
argument_list|(
name|insn
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|m1
init|=
literal|0
decl_stmt|,
name|m2
init|=
literal|0
decl_stmt|,
name|op
init|=
literal|0
decl_stmt|;
name|size_t
name|pindex
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|const
name|char
modifier|*
name|np
decl_stmt|,
modifier|*
name|pp
decl_stmt|,
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
comment|/* Don't mention instructions whose names are the null string.      They are in the machine description just to be recognized.  */
if|if
condition|(
operator|*
name|name
operator|==
literal|0
condition|)
return|return;
comment|/* See if NAME matches one of the patterns we have for the optabs we know      about.  */
for|for
control|(
name|pindex
operator|=
literal|0
init|;
name|pindex
operator|<
name|ARRAY_SIZE
argument_list|(
name|optabs
argument_list|)
condition|;
name|pindex
operator|++
control|)
block|{
name|int
name|force_float
init|=
literal|0
decl_stmt|,
name|force_int
init|=
literal|0
decl_stmt|,
name|force_partial_int
init|=
literal|0
decl_stmt|;
name|int
name|force_consec
init|=
literal|0
decl_stmt|;
name|int
name|matches
init|=
literal|1
decl_stmt|;
for|for
control|(
name|pp
operator|=
name|optabs
index|[
name|pindex
index|]
init|;
name|pp
index|[
literal|0
index|]
operator|!=
literal|'$'
operator|||
name|pp
index|[
literal|1
index|]
operator|!=
literal|'('
condition|;
name|pp
operator|++
control|)
empty_stmt|;
for|for
control|(
name|pp
operator|+=
literal|2
operator|,
name|np
operator|=
name|name
init|;
name|matches
operator|&&
operator|!
operator|(
name|pp
index|[
literal|0
index|]
operator|==
literal|'$'
operator|&&
name|pp
index|[
literal|1
index|]
operator|==
literal|')'
operator|)
condition|;
name|pp
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|pp
operator|!=
literal|'$'
condition|)
block|{
if|if
condition|(
operator|*
name|pp
operator|!=
operator|*
name|np
operator|++
condition|)
break|break;
block|}
else|else
switch|switch
condition|(
operator|*
operator|++
name|pp
condition|)
block|{
case|case
literal|'N'
case|:
name|force_consec
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'I'
case|:
name|force_int
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
name|force_partial_int
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'F'
case|:
name|force_float
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'V'
case|:
break|break;
case|case
literal|'c'
case|:
for|for
control|(
name|op
operator|=
literal|0
init|;
name|op
operator|<
name|NUM_RTX_CODE
condition|;
name|op
operator|++
control|)
block|{
for|for
control|(
name|p
operator|=
name|GET_RTX_NAME
argument_list|(
name|op
argument_list|)
operator|,
name|q
operator|=
name|np
init|;
operator|*
name|p
condition|;
name|p
operator|++
operator|,
name|q
operator|++
control|)
if|if
condition|(
operator|*
name|p
operator|!=
operator|*
name|q
condition|)
break|break;
comment|/* We have to be concerned about matching "gt" and 		       missing "gtu", e.g., so verify we have reached the 		       end of thing we are to match.  */
if|if
condition|(
operator|*
name|p
operator|==
literal|0
operator|&&
operator|*
name|q
operator|==
literal|0
operator|&&
operator|(
name|GET_RTX_CLASS
argument_list|(
name|op
argument_list|)
operator|==
name|RTX_COMPARE
operator|||
name|GET_RTX_CLASS
argument_list|(
name|op
argument_list|)
operator|==
name|RTX_COMM_COMPARE
operator|)
condition|)
break|break;
block|}
if|if
condition|(
name|op
operator|==
name|NUM_RTX_CODE
condition|)
name|matches
operator|=
literal|0
expr_stmt|;
else|else
name|np
operator|+=
name|strlen
argument_list|(
name|GET_RTX_NAME
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
case|case
literal|'b'
case|:
comment|/* This loop will stop at the first prefix match, so                    look through the modes in reverse order, in case                    there are extra CC modes and CC is a prefix of the                    CC modes (as it should be).  */
for|for
control|(
name|i
operator|=
operator|(
name|MAX_MACHINE_MODE
operator|)
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
for|for
control|(
name|p
operator|=
name|GET_MODE_NAME
argument_list|(
name|i
argument_list|)
operator|,
name|q
operator|=
name|np
init|;
operator|*
name|p
condition|;
name|p
operator|++
operator|,
name|q
operator|++
control|)
if|if
condition|(
name|TOLOWER
argument_list|(
operator|*
name|p
argument_list|)
operator|!=
operator|*
name|q
condition|)
break|break;
if|if
condition|(
operator|*
name|p
operator|==
literal|0
operator|&&
operator|(
operator|!
name|force_int
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_INT
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_VECTOR_INT
operator|)
operator|&&
operator|(
operator|!
name|force_partial_int
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_INT
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_PARTIAL_INT
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_VECTOR_INT
operator|)
operator|&&
operator|(
operator|!
name|force_float
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_FLOAT
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_DECIMAL_FLOAT
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_COMPLEX_FLOAT
operator|||
name|mode_class
index|[
name|i
index|]
operator|==
name|MODE_VECTOR_FLOAT
operator|)
condition|)
break|break;
block|}
if|if
condition|(
name|i
operator|<
literal|0
condition|)
name|matches
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|pp
operator|==
literal|'a'
condition|)
name|m1
operator|=
name|i
operator|,
name|np
operator|+=
name|strlen
argument_list|(
name|GET_MODE_NAME
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|m2
operator|=
name|i
operator|,
name|np
operator|+=
name|strlen
argument_list|(
name|GET_MODE_NAME
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|force_int
operator|=
name|force_partial_int
operator|=
name|force_float
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|gcc_unreachable
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|matches
operator|&&
name|pp
index|[
literal|0
index|]
operator|==
literal|'$'
operator|&&
name|pp
index|[
literal|1
index|]
operator|==
literal|')'
operator|&&
operator|*
name|np
operator|==
literal|0
operator|&&
operator|(
operator|!
name|force_consec
operator|||
operator|(
name|int
operator|)
name|GET_MODE_WIDER_MODE
argument_list|(
name|m1
argument_list|)
operator|==
name|m2
operator|)
condition|)
break|break;
block|}
if|if
condition|(
name|pindex
operator|==
name|ARRAY_SIZE
argument_list|(
name|optabs
argument_list|)
condition|)
return|return;
comment|/* We found a match.  If this pattern is only conditionally present,      write out the "if" and two extra blanks.  */
if|if
condition|(
operator|*
name|XSTR
argument_list|(
name|insn
argument_list|,
literal|2
argument_list|)
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"  if (HAVE_%s)\n  "
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  "
argument_list|)
expr_stmt|;
comment|/* Now write out the initialization, making all required substitutions.  */
for|for
control|(
name|pp
operator|=
name|optabs
index|[
name|pindex
index|]
init|;
operator|*
name|pp
condition|;
name|pp
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|pp
operator|!=
literal|'$'
condition|)
name|putchar
argument_list|(
operator|*
name|pp
argument_list|)
expr_stmt|;
else|else
switch|switch
condition|(
operator|*
operator|++
name|pp
condition|)
block|{
case|case
literal|'('
case|:
case|case
literal|')'
case|:
case|case
literal|'I'
case|:
case|case
literal|'F'
case|:
case|case
literal|'N'
case|:
break|break;
case|case
literal|'V'
case|:
if|if
condition|(
name|SCALAR_FLOAT_MODE_P
argument_list|(
name|m1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"v"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
for|for
control|(
name|np
operator|=
name|GET_MODE_NAME
argument_list|(
name|m1
argument_list|)
init|;
operator|*
name|np
condition|;
name|np
operator|++
control|)
name|putchar
argument_list|(
name|TOLOWER
argument_list|(
operator|*
name|np
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
for|for
control|(
name|np
operator|=
name|GET_MODE_NAME
argument_list|(
name|m2
argument_list|)
init|;
operator|*
name|np
condition|;
name|np
operator|++
control|)
name|putchar
argument_list|(
name|TOLOWER
argument_list|(
operator|*
name|np
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'A'
case|:
name|printf
argument_list|(
literal|"%smode"
argument_list|,
name|GET_MODE_NAME
argument_list|(
name|m1
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'B'
case|:
name|printf
argument_list|(
literal|"%smode"
argument_list|,
name|GET_MODE_NAME
argument_list|(
name|m2
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|GET_RTX_NAME
argument_list|(
name|op
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'C'
case|:
for|for
control|(
name|np
operator|=
name|GET_RTX_NAME
argument_list|(
name|op
argument_list|)
init|;
operator|*
name|np
condition|;
name|np
operator|++
control|)
name|putchar
argument_list|(
name|TOUPPER
argument_list|(
operator|*
name|np
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|printf
argument_list|(
literal|";\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|rtx
name|desc
decl_stmt|;
name|progname
operator|=
literal|"genopinit"
expr_stmt|;
if|if
condition|(
name|init_md_reader_args
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|!=
name|SUCCESS_EXIT_CODE
condition|)
return|return
operator|(
name|FATAL_EXIT_CODE
operator|)
return|;
name|printf
argument_list|(
literal|"/* Generated automatically by the program `genopinit'\n\ from the machine description file `md'.  */\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"config.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"system.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"coretypes.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"tm.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"rtl.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"flags.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"insn-config.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"recog.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"expr.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"optabs.h\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#include \"reload.h\"\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"void\ninit_all_optabs (void)\n{\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\ #ifdef FIXUNS_TRUNC_LIKE_FIX_TRUNC\n\   int i, j;\n\ #endif\n"
argument_list|)
expr_stmt|;
comment|/* Read the machine description.  */
while|while
condition|(
literal|1
condition|)
block|{
name|int
name|line_no
decl_stmt|,
name|insn_code_number
init|=
literal|0
decl_stmt|;
name|desc
operator|=
name|read_md_rtx
argument_list|(
operator|&
name|line_no
argument_list|,
operator|&
name|insn_code_number
argument_list|)
expr_stmt|;
if|if
condition|(
name|desc
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|GET_CODE
argument_list|(
name|desc
argument_list|)
operator|==
name|DEFINE_INSN
operator|||
name|GET_CODE
argument_list|(
name|desc
argument_list|)
operator|==
name|DEFINE_EXPAND
condition|)
name|gen_insn
argument_list|(
name|desc
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
literal|"\ \n\ #ifdef FIXUNS_TRUNC_LIKE_FIX_TRUNC\n\   /* This flag says the same insns that convert to a signed fixnum\n\      also convert validly to an unsigned one.  */\n\   for (i = 0; i< NUM_MACHINE_MODES; i++)\n\     for (j = 0; j< NUM_MACHINE_MODES; j++)\n\       ufixtrunc_optab->handlers[i][j].insn_code\n\       = sfixtrunc_optab->handlers[i][j].insn_code;\n\ #endif\n\ }"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return
operator|(
name|ferror
argument_list|(
name|stdout
argument_list|)
operator|!=
literal|0
condition|?
name|FATAL_EXIT_CODE
else|:
name|SUCCESS_EXIT_CODE
operator|)
return|;
block|}
end_function

end_unit

