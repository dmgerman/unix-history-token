begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"at.c @(#)at.c	1.1	10/1/82 Berkeley "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Declarations of all functions (required by Version 7 C  * for the array to be set up without warning messages)  */
end_comment

begin_extern
extern|extern ex_abs(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_add(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_and(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ap(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_arg1(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_arg2(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_asgn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_auto(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_base(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_botch(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_br(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_br0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_cat(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_catk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ceil(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_chdir(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_cir(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_close(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_com(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_com0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_comb(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_comk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_creat(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_crp(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ddom(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_deal(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_dfmt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_dibm(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_diot(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_div(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_drho(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_drop(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_dtrn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_dup(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_elid(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_eps(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_eq(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_exd(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_exd0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_exdk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_exec(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_exit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_exp(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_fac(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_fdef(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_float(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_nl(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_floor(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_fork(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_fun(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_gdd(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_gddk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_gdu(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_gduk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ge(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_gt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_hprint(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ibr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ibr0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_immed(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_index(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_iprod(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_kill(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_label(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_le(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_log(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_loge(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_lt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_max(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mdom(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_menc(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_meps(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mfmt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mibm(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_min(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_minus(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_miot(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mod(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mrho(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mtrn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_mul(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_nand(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_nc(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ne(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_nilret(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_nor(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_not(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_open(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_oprod(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_or(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_pi(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_pipe(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_plus(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_print(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_pwr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rand(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rav(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_ravk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rd(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_read(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_recip(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_red(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_red0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_redk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rep(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rest(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rev(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rev0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_revk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rot(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rot0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_rotk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_run(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_scan(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_scn0(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_scnk(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_seek(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_sgn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_signl(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_sub(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_take(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_unlink(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_wait(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern ex_write(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|exop
index|[]
function_decl|)
parameter_list|()
init|=
block|{
literal|0
operator|,
comment|/* 0 */
function_decl|ex_add
operator|,
comment|/* 1 */
function_decl|ex_plus
operator|,
comment|/* 2 */
function_decl|ex_sub
operator|,
comment|/* 3 */
function_decl|ex_minus
operator|,
comment|/* 4 */
function_decl|ex_mul
operator|,
comment|/* 5 */
function_decl|ex_sgn
operator|,
comment|/* 6 */
function_decl|ex_div
operator|,
comment|/* 7 */
function_decl|ex_recip
operator|,
comment|/* 8 */
function_decl|ex_mod
operator|,
comment|/* 9 */
function_decl|ex_abs
operator|,
comment|/* 10 */
function_decl|ex_min
operator|,
comment|/* 11 */
function_decl|ex_floor
operator|,
comment|/* 12 */
function_decl|ex_max
operator|,
comment|/* 13 */
function_decl|ex_ceil
operator|,
comment|/* 14 */
function_decl|ex_pwr
operator|,
comment|/* 15 */
function_decl|ex_exp
operator|,
comment|/* 16 */
function_decl|ex_log
operator|,
comment|/* 17 */
function_decl|ex_loge
operator|,
comment|/* 18 */
function_decl|ex_cir
operator|,
comment|/* 19 */
function_decl|ex_pi
operator|,
comment|/* 20 */
function_decl|ex_comb
operator|,
comment|/* 21 */
function_decl|ex_fac
operator|,
comment|/* 22 */
function_decl|ex_deal
operator|,
comment|/* 23 */
function_decl|ex_rand
operator|,
comment|/* 24 */
function_decl|ex_drho
operator|,
comment|/* 25 */
function_decl|ex_mrho
operator|,
comment|/* 26 */
function_decl|ex_diot
operator|,
comment|/* 27 */
function_decl|ex_miot
operator|,
comment|/* 28 */
function_decl|ex_rot0
operator|,
comment|/* 29 */
function_decl|ex_rev0
operator|,
comment|/* 30 */
function_decl|ex_dtrn
operator|,
comment|/* 31 */
function_decl|ex_mtrn
operator|,
comment|/* 32 */
function_decl|ex_dibm
operator|,
comment|/* 33 */
function_decl|ex_mibm
operator|,
comment|/* 34 */
function_decl|ex_gdu
operator|,
comment|/* 35 */
function_decl|ex_gduk
operator|,
comment|/* 36 */
function_decl|ex_gdd
operator|,
comment|/* 37 */
function_decl|ex_gddk
operator|,
comment|/* 38 */
function_decl|ex_exd
operator|,
comment|/* 39 */
function_decl|ex_scan
operator|,
comment|/* 40 */
function_decl|ex_exdk
operator|,
comment|/* 41 */
function_decl|ex_scnk
operator|,
comment|/* 42 */
function_decl|ex_iprod
operator|,
comment|/* 43 */
function_decl|ex_oprod
operator|,
comment|/* 44 */
function_decl|0
operator|,
comment|/* 45 */
function_decl|0
operator|,
comment|/* 46 */
function_decl|ex_br0
operator|,
comment|/* 47 */
function_decl|ex_br
operator|,
comment|/* 48 */
function_decl|ex_ddom
operator|,
comment|/* 49 */
function_decl|ex_mdom
operator|,
comment|/* 50 */
function_decl|ex_com
operator|,
comment|/* 51 */
function_decl|ex_red
operator|,
comment|/* 52 */
function_decl|ex_comk
operator|,
comment|/* 53 */
function_decl|ex_redk
operator|,
comment|/* 54 */
function_decl|ex_rot
operator|,
comment|/* 55 */
function_decl|ex_rev
operator|,
comment|/* 56 */
function_decl|ex_rotk
operator|,
comment|/* 57 */
function_decl|ex_revk
operator|,
comment|/* 58 */
function_decl|ex_cat
operator|,
comment|/* 59 */
function_decl|ex_rav
operator|,
comment|/* 60 */
function_decl|ex_catk
operator|,
comment|/* 61 */
function_decl|ex_ravk
operator|,
comment|/* 62 */
function_decl|ex_print
operator|,
comment|/* 63 */
function_decl|0
operator|,
comment|/* 64 */
function_decl|ex_elid
operator|,
comment|/* 65 */
function_decl|0
operator|,
comment|/* 66 */
function_decl|0
operator|,
comment|/* 67 */
function_decl|ex_index
operator|,
comment|/* 68 */
function_decl|ex_hprint
operator|,
comment|/* 69 */
function_decl|0
operator|,
comment|/* 70 */
function_decl|ex_lt
operator|,
comment|/* 71 */
function_decl|ex_le
operator|,
comment|/* 72 */
function_decl|ex_gt
operator|,
comment|/* 73 */
function_decl|ex_ge
operator|,
comment|/* 74 */
function_decl|ex_eq
operator|,
comment|/* 75 */
function_decl|ex_ne
operator|,
comment|/* 76 */
function_decl|ex_and
operator|,
comment|/* 77 */
function_decl|ex_or
operator|,
comment|/* 78 */
function_decl|ex_nand
operator|,
comment|/* 79 */
function_decl|ex_nor
operator|,
comment|/* 80 */
function_decl|ex_not
operator|,
comment|/* 81 */
function_decl|ex_eps
operator|,
comment|/* 82 */
function_decl|ex_meps
operator|,
comment|/* 83 */
function_decl|ex_rep
operator|,
comment|/* 84 */
function_decl|ex_take
operator|,
comment|/* 85 */
function_decl|ex_drop
operator|,
comment|/* 86 */
function_decl|ex_exd0
operator|,
comment|/* 87 */
function_decl|ex_asgn
operator|,
comment|/* 88 */
function_decl|ex_immed
operator|,
comment|/* 89 */
function_decl|0
operator|,
comment|/* 90 */
function_decl|0
operator|,
comment|/* 91 */
function_decl|ex_fun
operator|,
comment|/* 92 */
function_decl|ex_arg1
operator|,
comment|/* 93 */
function_decl|ex_arg2
operator|,
comment|/* 94 */
function_decl|ex_auto
operator|,
comment|/* 95 */
function_decl|ex_rest
operator|,
comment|/* 96 */
function_decl|ex_com0
operator|,
comment|/* 97 */
function_decl|ex_red0
operator|,
comment|/* 98 */
function_decl|ex_exd0
operator|,
comment|/* 99 */
function_decl|ex_scn0
operator|,
comment|/*100 */
function_decl|ex_base
operator|,
comment|/*101 */
function_decl|ex_menc
operator|,
comment|/*102 */
comment|/*      monadic encod   */
function_decl|ex_label
operator|,
comment|/*103 */
function_decl|0
operator|,
comment|/*104 */
function_decl|0
operator|,
comment|/*105 */
function_decl|0
operator|,
comment|/*106 */
function_decl|0
operator|,
comment|/*107 */
function_decl|0
operator|,
comment|/*108 */
function_decl|0
operator|,
comment|/*109 */
function_decl|0
operator|,
comment|/*110 */
function_decl|0
operator|,
comment|/*111 */
function_decl|ex_run
operator|,
comment|/*112 */
function_decl|ex_fork
operator|,
comment|/*113 */
function_decl|ex_wait
operator|,
comment|/*114 */
function_decl|ex_exec
operator|,
comment|/*115 */
function_decl|ex_fdef
operator|,
comment|/*116 */
function_decl|ex_exit
operator|,
comment|/*117 */
function_decl|ex_pipe
operator|,
comment|/*118 */
function_decl|ex_chdir
operator|,
comment|/*119 */
function_decl|ex_open
operator|,
comment|/*120 */
function_decl|ex_close
operator|,
comment|/*121 */
function_decl|ex_read
operator|,
comment|/*122 */
function_decl|ex_write
operator|,
comment|/*123 */
function_decl|ex_creat
operator|,
comment|/*124 */
function_decl|ex_seek
operator|,
comment|/*125 */
function_decl|ex_unlink
operator|,
comment|/*126 */
function_decl|ex_rd
operator|,
comment|/*127 */
function_decl|ex_dup
operator|,
comment|/*128 */
function_decl|ex_ap
operator|,
comment|/*129 */
function_decl|ex_kill
operator|,
comment|/*130 */
function_decl|ex_crp
operator|,
comment|/*131 */
function_decl|ex_dfmt
operator|,
comment|/*132 */
function_decl|ex_mfmt
operator|,
comment|/*133 */
function_decl|ex_nc
operator|,
comment|/*134 */
function_decl|ex_nilret
operator|,
comment|/*135 */
function_decl|ex_botch
operator|,
comment|/*136 	(XQUAD--never executed) */
function_decl|ex_ibr
operator|,
comment|/*137 */
function_decl|ex_ibr0
operator|,
comment|/*138 */
function_decl|ex_botch
operator|,
comment|/*139  (RVAL--in a1.c) */
function_decl|ex_signl
operator|,
comment|/*140 */
function_decl|ex_float
operator|,
comment|/*141 */
function_decl|ex_nl
operator|,
comment|/*142 */
function_decl|ex_botch
operator|,
comment|/*142 */
function_decl|ex_botch
operator|,
end_function_decl

begin_comment
comment|/*143 */
end_comment

unit|};
end_unit

