begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generated automatically by the program `genflags' from the machine description file `md'.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_tstsi_1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_tstsi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_tsthi_1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_tsthi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_tstqi_1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_tstqi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_tstsf_cc
value|(TARGET_80387&& ! TARGET_IEEE_FP)
end_define

begin_define
define|#
directive|define
name|HAVE_tstsf
value|(TARGET_80387&& ! TARGET_IEEE_FP)
end_define

begin_define
define|#
directive|define
name|HAVE_tstdf_cc
value|(TARGET_80387&& ! TARGET_IEEE_FP)
end_define

begin_define
define|#
directive|define
name|HAVE_tstdf
value|(TARGET_80387&& ! TARGET_IEEE_FP)
end_define

begin_define
define|#
directive|define
name|HAVE_tstxf_cc
value|(TARGET_80387&& ! TARGET_IEEE_FP)
end_define

begin_define
define|#
directive|define
name|HAVE_tstxf
value|(TARGET_80387&& ! TARGET_IEEE_FP)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpsi_1
value|(GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpsi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_cmphi_1
value|(GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
end_define

begin_define
define|#
directive|define
name|HAVE_cmphi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_cmpqi_1
value|(GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpqi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_cmpsf_cc_1
value|(TARGET_80387 \&& (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
end_define

begin_define
define|#
directive|define
name|HAVE_cmpxf
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpdf
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpsf
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpxf_cc
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpxf_ccfpeq
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpdf_cc
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpdf_ccfpeq
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpsf_cc
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_cmpsf_ccfpeq
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_movsi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movhi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movstricthi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movqi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movstrictqi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movsf
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_swapdf
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movdf
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_swapxf
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movxf
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movdi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_zero_extendhisi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_zero_extendqihi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_zero_extendqisi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_zero_extendsidi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_extendsidi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_extendhisi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_extendqihi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_extendqisi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_extendsfdf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_extenddfxf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_extendsfxf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_truncdfsf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_truncxfsf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_truncxfdf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fixuns_truncxfsi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fixuns_truncdfsi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fixuns_truncsfsi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fix_truncxfdi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fix_truncdfdi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fix_truncsfdi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fix_truncxfsi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fix_truncdfsi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_fix_truncsfsi2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_floatsisf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_floatdisf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_floatsidf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_floatdidf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_floatsixf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_floatdixf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_adddi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_addsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_addhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_addqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_addxf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_adddf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_addsf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_subdi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_subsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_subhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_subqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_subxf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_subdf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_subsf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_mulhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_mulsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_umulqihi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_mulqihi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_umulsidi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_mulsidi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_mulxf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_muldf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_mulsf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_divqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_udivqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_divxf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_divdf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_divsf3
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_divmodsi4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_divmodhi4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_udivmodsi4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_udivmodhi4
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_andsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_andhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_andqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_iorsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_iorhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_iorqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_xorsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_xorhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_xorqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_negdi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_negsi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_neghi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_negqi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_negsf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_negdf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_negxf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_abssf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_absdf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_absxf2
value|(TARGET_80387)
end_define

begin_define
define|#
directive|define
name|HAVE_sqrtsf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387 \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_sqrtdf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387 \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_sqrtxf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387  \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_sindf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387  \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_sinsf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387  \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_cosdf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387  \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_cossf2
value|(! TARGET_NO_FANCY_MATH_387&& TARGET_80387  \&& (TARGET_IEEE_FP || flag_fast_math) )
end_define

begin_define
define|#
directive|define
name|HAVE_one_cmplsi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_one_cmplhi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_one_cmplqi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashldi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashldi3_const_int
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashldi3_non_const_int
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashlsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashlhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashlqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashrdi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashrdi3_const_int
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashrdi3_non_const_int
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashrsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashrhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ashrqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_lshrdi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_lshrdi3_const_int
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_lshrdi3_non_const_int
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_lshrsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_lshrhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_lshrqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_rotlsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_rotlhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_rotlqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_rotrsi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_rotrhi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_rotrqi3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_seq
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sne
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sgt
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sgtu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_slt
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sltu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sge
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sgeu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sle
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_sleu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_beq
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bne
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bgt
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bgtu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_blt
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bltu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bge
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bgeu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ble
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_bleu
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_jump
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_indirect_jump
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_casesi
value|(flag_pic)
end_define

begin_define
define|#
directive|define
name|HAVE_tablejump
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_call_pop
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_call
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_call_value_pop
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_call_value
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_untyped_call
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_untyped_return
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_update_return
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_return
value|(simple_386_epilogue ())
end_define

begin_define
define|#
directive|define
name|HAVE_nop
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_movstrsi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_cmpstrsi
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ffssi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_ffshi2
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_strlensi
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_MD_PROTOTYPES
end_ifndef

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstsi_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstsi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tsthi_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tsthi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstqi_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstqi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstsf_cc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstsf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstdf_cc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstdf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstxf_cc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tstxf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpsi_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpsi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmphi_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmphi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpqi_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpqi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpsf_cc_1
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpxf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpdf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpsf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpxf_cc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpxf_ccfpeq
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpdf_cc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpdf_ccfpeq
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpsf_cc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpsf_ccfpeq
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movsi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movhi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movstricthi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movqi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movstrictqi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movsf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_swapdf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movdf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_swapxf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movxf
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movdi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_zero_extendhisi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_zero_extendqihi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_zero_extendqisi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_zero_extendsidi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extendsidi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extendhisi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extendqihi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extendqisi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extendsfdf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extenddfxf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extendsfxf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_truncdfsf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_truncxfsf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_truncxfdf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fixuns_truncxfsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fixuns_truncdfsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fixuns_truncsfsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fix_truncxfdi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fix_truncdfdi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fix_truncsfdi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fix_truncxfsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fix_truncdfsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_fix_truncsfsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_floatsisf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_floatdisf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_floatsidf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_floatdidf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_floatsixf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_floatdixf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_adddi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_addsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_addhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_addqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_addxf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_adddf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_addsf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subdi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subxf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subdf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_subsf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mulhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mulsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_umulqihi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mulqihi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_umulsidi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mulsidi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mulxf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_muldf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mulsf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_divqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_udivqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_divxf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_divdf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_divsf3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_divmodsi4
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_divmodhi4
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_udivmodsi4
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_udivmodhi4
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_andsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_andhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_andqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_iorsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_iorhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_iorqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_xorsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_xorhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_xorqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_negdi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_negsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_neghi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_negqi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_negsf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_negdf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_negxf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_abssf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_absdf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_absxf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sqrtsf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sqrtdf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sqrtxf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sindf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sinsf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cosdf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cossf2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_one_cmplsi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_one_cmplhi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_one_cmplqi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashldi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashldi3_const_int
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashldi3_non_const_int
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashlsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashlhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashlqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashrdi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashrdi3_const_int
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashrdi3_non_const_int
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashrsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashrhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ashrqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lshrdi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lshrdi3_const_int
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lshrdi3_non_const_int
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lshrsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lshrhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lshrqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rotlsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rotlhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rotlqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rotrsi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rotrhi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rotrqi3
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_seq
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sne
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sgt
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sgtu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_slt
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sltu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sge
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sgeu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sle
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sleu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_beq
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bne
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bgt
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bgtu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_blt
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bltu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bge
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bgeu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ble
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bleu
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_indirect_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_casesi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_tablejump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_untyped_call
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_untyped_return
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_update_return
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_return
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_nop
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_movstrsi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cmpstrsi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ffssi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ffshi2
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_strlensi
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MD_CALL_PROTOTYPES
end_ifdef

begin_decl_stmt
specifier|extern
name|rtx
name|gen_call_pop
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_call
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_call_value_pop
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_call_value
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MD_CALL_PROTOTYPES */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|gen_call_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call_value_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call_value
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MD_CALL_PROTOTYPES */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_MD_PROTOTYPES */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|gen_tstsi_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstsi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tsthi_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tsthi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstqi_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstqi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstsf_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstsf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstdf_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstdf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstxf_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tstxf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpsi_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpsi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmphi_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmphi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpqi_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpqi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpsf_cc_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpxf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpdf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpsf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpxf_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpxf_ccfpeq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpdf_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpdf_ccfpeq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpsf_cc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpsf_ccfpeq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movsi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movhi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movstricthi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movqi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movstrictqi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movsf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_swapdf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movdf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_swapxf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movxf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movdi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_zero_extendhisi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_zero_extendqihi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_zero_extendqisi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_zero_extendsidi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extendsidi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extendhisi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extendqihi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extendqisi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extendsfdf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extenddfxf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_extendsfxf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_truncdfsf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_truncxfsf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_truncxfdf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fixuns_truncxfsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fixuns_truncdfsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fixuns_truncsfsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fix_truncxfdi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fix_truncdfdi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fix_truncsfdi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fix_truncxfsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fix_truncdfsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_fix_truncsfsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_floatsisf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_floatdisf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_floatsidf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_floatdidf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_floatsixf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_floatdixf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_adddi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_addsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_addhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_addqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_addxf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_adddf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_addsf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subdi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subxf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subdf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_subsf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_mulhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_mulsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_umulqihi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_mulqihi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_umulsidi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_mulsidi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_mulxf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_muldf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_mulsf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_divqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_udivqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_divxf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_divdf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_divsf3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_divmodsi4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_divmodhi4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_udivmodsi4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_udivmodhi4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_andsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_andhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_andqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_iorsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_iorhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_iorqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_xorsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_xorhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_xorqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_negdi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_negsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_neghi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_negqi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_negsf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_negdf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_negxf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_abssf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_absdf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_absxf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sqrtsf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sqrtdf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sqrtxf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sindf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sinsf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cosdf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cossf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_one_cmplsi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_one_cmplhi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_one_cmplqi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashldi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashldi3_const_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashldi3_non_const_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashlsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashlhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashlqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashrdi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashrdi3_const_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashrdi3_non_const_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashrsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashrhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ashrqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lshrdi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lshrdi3_const_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lshrdi3_non_const_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lshrsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lshrhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lshrqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rotlsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rotlhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rotlqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rotrsi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rotrhi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rotrqi3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_seq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sne
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sgt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sgtu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_slt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sltu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sge
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sgeu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sleu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_beq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bne
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bgt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bgtu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_blt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bltu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bge
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bgeu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ble
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_bleu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_jump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_indirect_jump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_casesi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_tablejump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_untyped_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_untyped_return
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_update_return
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_return
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_nop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_movstrsi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_cmpstrsi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ffssi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_ffshi2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_strlensi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call_value_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_call_value
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_MD_PROTOTYPES */
end_comment

end_unit

