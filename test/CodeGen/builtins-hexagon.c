begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: hexagon-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple hexagon-unknown-elf -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|v16
name|__attribute__
argument_list|(
operator|(
name|__vector_size__
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|int
name|v32
name|__attribute__
argument_list|(
operator|(
name|__vector_size__
argument_list|(
literal|128
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|int
name|v64
name|__attribute__
argument_list|(
operator|(
name|__vector_size__
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// The circ/brev intrinsics do not have _HEXAGON_ in the name.
name|__builtin_brev_ldb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.ldb
name|__builtin_brev_ldd
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.ldd
name|__builtin_brev_ldh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.ldh
name|__builtin_brev_ldub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.ldub
name|__builtin_brev_lduh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.lduh
name|__builtin_brev_ldw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.ldw
name|__builtin_brev_stb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.stb
name|__builtin_brev_std
argument_list|(
literal|0
argument_list|,
literal|0LL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.std
name|__builtin_brev_sth
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.sth
name|__builtin_brev_sthhi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.sthhi
name|__builtin_brev_stw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.brev.stw
name|__builtin_circ_ldb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.ldb
name|__builtin_circ_ldd
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.ldd
name|__builtin_circ_ldh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.ldh
name|__builtin_circ_ldub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.ldub
name|__builtin_circ_lduh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.lduh
name|__builtin_circ_ldw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.ldw
name|__builtin_circ_stb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.stb
name|__builtin_circ_std
argument_list|(
literal|0
argument_list|,
literal|0LL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.std
name|__builtin_circ_sth
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.sth
name|__builtin_circ_sthhi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.sthhi
name|__builtin_circ_stw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: llvm.hexagon.circ.stw
name|__builtin_HEXAGON_A2_abs
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.abs
name|__builtin_HEXAGON_A2_absp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.absp
name|__builtin_HEXAGON_A2_abssat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.abssat
name|__builtin_HEXAGON_A2_add
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.add
name|__builtin_HEXAGON_A2_addh_h16_hh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.hh
name|__builtin_HEXAGON_A2_addh_h16_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.hl
name|__builtin_HEXAGON_A2_addh_h16_lh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.lh
name|__builtin_HEXAGON_A2_addh_h16_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.ll
name|__builtin_HEXAGON_A2_addh_h16_sat_hh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.sat.hh
name|__builtin_HEXAGON_A2_addh_h16_sat_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.sat.hl
name|__builtin_HEXAGON_A2_addh_h16_sat_lh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.sat.lh
name|__builtin_HEXAGON_A2_addh_h16_sat_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.h16.sat.ll
name|__builtin_HEXAGON_A2_addh_l16_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.l16.hl
name|__builtin_HEXAGON_A2_addh_l16_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.l16.ll
name|__builtin_HEXAGON_A2_addh_l16_sat_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.l16.sat.hl
name|__builtin_HEXAGON_A2_addh_l16_sat_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addh.l16.sat.ll
name|__builtin_HEXAGON_A2_addi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addi
name|__builtin_HEXAGON_A2_addp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addp
name|__builtin_HEXAGON_A2_addpsat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addpsat
name|__builtin_HEXAGON_A2_addsat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addsat
name|__builtin_HEXAGON_A2_addsp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.addsp
name|__builtin_HEXAGON_A2_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.and
name|__builtin_HEXAGON_A2_andir
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.andir
name|__builtin_HEXAGON_A2_andp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.andp
name|__builtin_HEXAGON_A2_aslh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.aslh
name|__builtin_HEXAGON_A2_asrh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.asrh
name|__builtin_HEXAGON_A2_combine_hh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.combine.hh
name|__builtin_HEXAGON_A2_combine_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.combine.hl
name|__builtin_HEXAGON_A2_combineii
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.combineii
name|__builtin_HEXAGON_A2_combine_lh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.combine.lh
name|__builtin_HEXAGON_A2_combine_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.combine.ll
name|__builtin_HEXAGON_A2_combinew
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.combinew
name|__builtin_HEXAGON_A2_max
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.max
name|__builtin_HEXAGON_A2_maxp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.maxp
name|__builtin_HEXAGON_A2_maxu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.maxu
name|__builtin_HEXAGON_A2_maxup
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.maxup
name|__builtin_HEXAGON_A2_min
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.min
name|__builtin_HEXAGON_A2_minp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.minp
name|__builtin_HEXAGON_A2_minu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.minu
name|__builtin_HEXAGON_A2_minup
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.minup
name|__builtin_HEXAGON_A2_neg
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.neg
name|__builtin_HEXAGON_A2_negp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.negp
name|__builtin_HEXAGON_A2_negsat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.negsat
name|__builtin_HEXAGON_A2_not
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.not
name|__builtin_HEXAGON_A2_notp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.notp
name|__builtin_HEXAGON_A2_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.or
name|__builtin_HEXAGON_A2_orir
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.orir
name|__builtin_HEXAGON_A2_orp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.orp
name|__builtin_HEXAGON_A2_roundsat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.roundsat
name|__builtin_HEXAGON_A2_sat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.sat
name|__builtin_HEXAGON_A2_satb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.satb
name|__builtin_HEXAGON_A2_sath
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.sath
name|__builtin_HEXAGON_A2_satub
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.satub
name|__builtin_HEXAGON_A2_satuh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.satuh
name|__builtin_HEXAGON_A2_sub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.sub
name|__builtin_HEXAGON_A2_subh_h16_hh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.hh
name|__builtin_HEXAGON_A2_subh_h16_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.hl
name|__builtin_HEXAGON_A2_subh_h16_lh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.lh
name|__builtin_HEXAGON_A2_subh_h16_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.ll
name|__builtin_HEXAGON_A2_subh_h16_sat_hh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.sat.hh
name|__builtin_HEXAGON_A2_subh_h16_sat_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.sat.hl
name|__builtin_HEXAGON_A2_subh_h16_sat_lh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.sat.lh
name|__builtin_HEXAGON_A2_subh_h16_sat_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.h16.sat.ll
name|__builtin_HEXAGON_A2_subh_l16_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.l16.hl
name|__builtin_HEXAGON_A2_subh_l16_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.l16.ll
name|__builtin_HEXAGON_A2_subh_l16_sat_hl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.l16.sat.hl
name|__builtin_HEXAGON_A2_subh_l16_sat_ll
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subh.l16.sat.ll
name|__builtin_HEXAGON_A2_subp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subp
name|__builtin_HEXAGON_A2_subri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subri
name|__builtin_HEXAGON_A2_subsat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.subsat
name|__builtin_HEXAGON_A2_svaddh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svaddh
name|__builtin_HEXAGON_A2_svaddhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svaddhs
name|__builtin_HEXAGON_A2_svadduhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svadduhs
name|__builtin_HEXAGON_A2_svavgh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svavgh
name|__builtin_HEXAGON_A2_svavghs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svavghs
name|__builtin_HEXAGON_A2_svnavgh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svnavgh
name|__builtin_HEXAGON_A2_svsubh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svsubh
name|__builtin_HEXAGON_A2_svsubhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svsubhs
name|__builtin_HEXAGON_A2_svsubuhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.svsubuhs
name|__builtin_HEXAGON_A2_swiz
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.swiz
name|__builtin_HEXAGON_A2_sxtb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.sxtb
name|__builtin_HEXAGON_A2_sxth
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.sxth
name|__builtin_HEXAGON_A2_sxtw
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.sxtw
name|__builtin_HEXAGON_A2_tfr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.tfr
name|__builtin_HEXAGON_A2_tfrih
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.tfrih
name|__builtin_HEXAGON_A2_tfril
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.tfril
name|__builtin_HEXAGON_A2_tfrp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.tfrp
name|__builtin_HEXAGON_A2_tfrpi
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.tfrpi
name|__builtin_HEXAGON_A2_tfrsi
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.tfrsi
name|__builtin_HEXAGON_A2_vabsh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vabsh
name|__builtin_HEXAGON_A2_vabshsat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vabshsat
name|__builtin_HEXAGON_A2_vabsw
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vabsw
name|__builtin_HEXAGON_A2_vabswsat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vabswsat
name|__builtin_HEXAGON_A2_vaddb_map
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddb.map
name|__builtin_HEXAGON_A2_vaddh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddh
name|__builtin_HEXAGON_A2_vaddhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddhs
name|__builtin_HEXAGON_A2_vaddub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddub
name|__builtin_HEXAGON_A2_vaddubs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddubs
name|__builtin_HEXAGON_A2_vadduhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vadduhs
name|__builtin_HEXAGON_A2_vaddw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddw
name|__builtin_HEXAGON_A2_vaddws
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vaddws
name|__builtin_HEXAGON_A2_vavgh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavgh
name|__builtin_HEXAGON_A2_vavghcr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavghcr
name|__builtin_HEXAGON_A2_vavghr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavghr
name|__builtin_HEXAGON_A2_vavgub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavgub
name|__builtin_HEXAGON_A2_vavgubr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavgubr
name|__builtin_HEXAGON_A2_vavguh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavguh
name|__builtin_HEXAGON_A2_vavguhr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavguhr
name|__builtin_HEXAGON_A2_vavguw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavguw
name|__builtin_HEXAGON_A2_vavguwr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavguwr
name|__builtin_HEXAGON_A2_vavgw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavgw
name|__builtin_HEXAGON_A2_vavgwcr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavgwcr
name|__builtin_HEXAGON_A2_vavgwr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vavgwr
name|__builtin_HEXAGON_A2_vcmpbeq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmpbeq
name|__builtin_HEXAGON_A2_vcmpbgtu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmpbgtu
name|__builtin_HEXAGON_A2_vcmpheq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmpheq
name|__builtin_HEXAGON_A2_vcmphgt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmphgt
name|__builtin_HEXAGON_A2_vcmphgtu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmphgtu
name|__builtin_HEXAGON_A2_vcmpweq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmpweq
name|__builtin_HEXAGON_A2_vcmpwgt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmpwgt
name|__builtin_HEXAGON_A2_vcmpwgtu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vcmpwgtu
name|__builtin_HEXAGON_A2_vconj
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vconj
name|__builtin_HEXAGON_A2_vmaxb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vmaxb
name|__builtin_HEXAGON_A2_vmaxh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vmaxh
name|__builtin_HEXAGON_A2_vmaxub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vmaxub
name|__builtin_HEXAGON_A2_vmaxuh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vmaxuh
name|__builtin_HEXAGON_A2_vmaxuw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vmaxuw
name|__builtin_HEXAGON_A2_vmaxw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vmaxw
name|__builtin_HEXAGON_A2_vminb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vminb
name|__builtin_HEXAGON_A2_vminh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vminh
name|__builtin_HEXAGON_A2_vminub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vminub
name|__builtin_HEXAGON_A2_vminuh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vminuh
name|__builtin_HEXAGON_A2_vminuw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vminuw
name|__builtin_HEXAGON_A2_vminw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vminw
name|__builtin_HEXAGON_A2_vnavgh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vnavgh
name|__builtin_HEXAGON_A2_vnavghcr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vnavghcr
name|__builtin_HEXAGON_A2_vnavghr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vnavghr
name|__builtin_HEXAGON_A2_vnavgw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vnavgw
name|__builtin_HEXAGON_A2_vnavgwcr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vnavgwcr
name|__builtin_HEXAGON_A2_vnavgwr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vnavgwr
name|__builtin_HEXAGON_A2_vraddub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vraddub
name|__builtin_HEXAGON_A2_vraddub_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vraddub.acc
name|__builtin_HEXAGON_A2_vrsadub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vrsadub
name|__builtin_HEXAGON_A2_vrsadub_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vrsadub.acc
name|__builtin_HEXAGON_A2_vsubb_map
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubb.map
name|__builtin_HEXAGON_A2_vsubh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubh
name|__builtin_HEXAGON_A2_vsubhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubhs
name|__builtin_HEXAGON_A2_vsubub
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubub
name|__builtin_HEXAGON_A2_vsububs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsububs
name|__builtin_HEXAGON_A2_vsubuhs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubuhs
name|__builtin_HEXAGON_A2_vsubw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubw
name|__builtin_HEXAGON_A2_vsubws
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.vsubws
name|__builtin_HEXAGON_A2_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.xor
name|__builtin_HEXAGON_A2_xorp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.xorp
name|__builtin_HEXAGON_A2_zxtb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.zxtb
name|__builtin_HEXAGON_A2_zxth
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A2.zxth
name|__builtin_HEXAGON_A4_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.andn
name|__builtin_HEXAGON_A4_andnp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.andnp
name|__builtin_HEXAGON_A4_bitsplit
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.bitsplit
name|__builtin_HEXAGON_A4_bitspliti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.bitspliti
name|__builtin_HEXAGON_A4_boundscheck
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.boundscheck
name|__builtin_HEXAGON_A4_cmpbeq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpbeq
name|__builtin_HEXAGON_A4_cmpbeqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpbeqi
name|__builtin_HEXAGON_A4_cmpbgt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpbgt
name|__builtin_HEXAGON_A4_cmpbgti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpbgti
name|__builtin_HEXAGON_A4_cmpbgtu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpbgtu
name|__builtin_HEXAGON_A4_cmpbgtui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpbgtui
name|__builtin_HEXAGON_A4_cmpheq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpheq
name|__builtin_HEXAGON_A4_cmpheqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmpheqi
name|__builtin_HEXAGON_A4_cmphgt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmphgt
name|__builtin_HEXAGON_A4_cmphgti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmphgti
name|__builtin_HEXAGON_A4_cmphgtu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmphgtu
name|__builtin_HEXAGON_A4_cmphgtui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cmphgtui
name|__builtin_HEXAGON_A4_combineir
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.combineir
name|__builtin_HEXAGON_A4_combineri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.combineri
name|__builtin_HEXAGON_A4_cround_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cround.ri
name|__builtin_HEXAGON_A4_cround_rr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.cround.rr
name|__builtin_HEXAGON_A4_modwrapu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.modwrapu
name|__builtin_HEXAGON_A4_orn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.orn
name|__builtin_HEXAGON_A4_ornp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.ornp
name|__builtin_HEXAGON_A4_rcmpeq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.rcmpeq
name|__builtin_HEXAGON_A4_rcmpeqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.rcmpeqi
name|__builtin_HEXAGON_A4_rcmpneq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.rcmpneq
name|__builtin_HEXAGON_A4_rcmpneqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.rcmpneqi
name|__builtin_HEXAGON_A4_round_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.round.ri
name|__builtin_HEXAGON_A4_round_ri_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.round.ri.sat
name|__builtin_HEXAGON_A4_round_rr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.round.rr
name|__builtin_HEXAGON_A4_round_rr_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.round.rr.sat
name|__builtin_HEXAGON_A4_tlbmatch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.tlbmatch
name|__builtin_HEXAGON_A4_vcmpbeq_any
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpbeq.any
name|__builtin_HEXAGON_A4_vcmpbeqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpbeqi
name|__builtin_HEXAGON_A4_vcmpbgt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpbgt
name|__builtin_HEXAGON_A4_vcmpbgti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpbgti
name|__builtin_HEXAGON_A4_vcmpbgtui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpbgtui
name|__builtin_HEXAGON_A4_vcmpheqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpheqi
name|__builtin_HEXAGON_A4_vcmphgti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmphgti
name|__builtin_HEXAGON_A4_vcmphgtui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmphgtui
name|__builtin_HEXAGON_A4_vcmpweqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpweqi
name|__builtin_HEXAGON_A4_vcmpwgti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpwgti
name|__builtin_HEXAGON_A4_vcmpwgtui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vcmpwgtui
name|__builtin_HEXAGON_A4_vrmaxh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrmaxh
name|__builtin_HEXAGON_A4_vrmaxuh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrmaxuh
name|__builtin_HEXAGON_A4_vrmaxuw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrmaxuw
name|__builtin_HEXAGON_A4_vrmaxw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrmaxw
name|__builtin_HEXAGON_A4_vrminh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrminh
name|__builtin_HEXAGON_A4_vrminuh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrminuh
name|__builtin_HEXAGON_A4_vrminuw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrminuw
name|__builtin_HEXAGON_A4_vrminw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A4.vrminw
name|__builtin_HEXAGON_A5_vaddhubs
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.A5.vaddhubs
name|__builtin_HEXAGON_C2_all8
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.all8
name|__builtin_HEXAGON_C2_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.and
name|__builtin_HEXAGON_C2_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.andn
name|__builtin_HEXAGON_C2_any8
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.any8
name|__builtin_HEXAGON_C2_bitsclr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.bitsclr
name|__builtin_HEXAGON_C2_bitsclri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.bitsclri
name|__builtin_HEXAGON_C2_bitsset
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.bitsset
name|__builtin_HEXAGON_C2_cmpeq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpeq
name|__builtin_HEXAGON_C2_cmpeqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpeqi
name|__builtin_HEXAGON_C2_cmpeqp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpeqp
name|__builtin_HEXAGON_C2_cmpgei
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgei
name|__builtin_HEXAGON_C2_cmpgeui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgeui
name|__builtin_HEXAGON_C2_cmpgt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgt
name|__builtin_HEXAGON_C2_cmpgti
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgti
name|__builtin_HEXAGON_C2_cmpgtp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgtp
name|__builtin_HEXAGON_C2_cmpgtu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgtu
name|__builtin_HEXAGON_C2_cmpgtui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgtui
name|__builtin_HEXAGON_C2_cmpgtup
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpgtup
name|__builtin_HEXAGON_C2_cmplt
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmplt
name|__builtin_HEXAGON_C2_cmpltu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.cmpltu
name|__builtin_HEXAGON_C2_mask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.mask
name|__builtin_HEXAGON_C2_mux
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.mux
name|__builtin_HEXAGON_C2_muxii
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.muxii
name|__builtin_HEXAGON_C2_muxir
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.muxir
name|__builtin_HEXAGON_C2_muxri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.muxri
name|__builtin_HEXAGON_C2_not
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.not
name|__builtin_HEXAGON_C2_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.or
name|__builtin_HEXAGON_C2_orn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.orn
name|__builtin_HEXAGON_C2_pxfer_map
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.pxfer.map
name|__builtin_HEXAGON_C2_tfrpr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.tfrpr
name|__builtin_HEXAGON_C2_tfrrp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.tfrrp
name|__builtin_HEXAGON_C2_vitpack
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.vitpack
name|__builtin_HEXAGON_C2_vmux
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.vmux
name|__builtin_HEXAGON_C2_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C2.xor
name|__builtin_HEXAGON_C4_and_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.and.and
name|__builtin_HEXAGON_C4_and_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.and.andn
name|__builtin_HEXAGON_C4_and_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.and.or
name|__builtin_HEXAGON_C4_and_orn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.and.orn
name|__builtin_HEXAGON_C4_cmplte
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.cmplte
name|__builtin_HEXAGON_C4_cmpltei
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.cmpltei
name|__builtin_HEXAGON_C4_cmplteu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.cmplteu
name|__builtin_HEXAGON_C4_cmplteui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.cmplteui
name|__builtin_HEXAGON_C4_cmpneq
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.cmpneq
name|__builtin_HEXAGON_C4_cmpneqi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.cmpneqi
name|__builtin_HEXAGON_C4_fastcorner9
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.fastcorner9
name|__builtin_HEXAGON_C4_fastcorner9_not
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.fastcorner9.not
name|__builtin_HEXAGON_C4_nbitsclr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.nbitsclr
name|__builtin_HEXAGON_C4_nbitsclri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.nbitsclri
name|__builtin_HEXAGON_C4_nbitsset
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.nbitsset
name|__builtin_HEXAGON_C4_or_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.or.and
name|__builtin_HEXAGON_C4_or_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.or.andn
name|__builtin_HEXAGON_C4_or_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.or.or
name|__builtin_HEXAGON_C4_or_orn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.C4.or.orn
name|__builtin_HEXAGON_F2_conv_d2df
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.d2df
name|__builtin_HEXAGON_F2_conv_d2sf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.d2sf
name|__builtin_HEXAGON_F2_conv_df2d
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2d
name|__builtin_HEXAGON_F2_conv_df2d_chop
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2d.chop
name|__builtin_HEXAGON_F2_conv_df2sf
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2sf
name|__builtin_HEXAGON_F2_conv_df2ud
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2ud
name|__builtin_HEXAGON_F2_conv_df2ud_chop
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2ud.chop
name|__builtin_HEXAGON_F2_conv_df2uw
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2uw
name|__builtin_HEXAGON_F2_conv_df2uw_chop
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2uw.chop
name|__builtin_HEXAGON_F2_conv_df2w
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2w
name|__builtin_HEXAGON_F2_conv_df2w_chop
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.df2w.chop
name|__builtin_HEXAGON_F2_conv_sf2d
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2d
name|__builtin_HEXAGON_F2_conv_sf2d_chop
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2d.chop
name|__builtin_HEXAGON_F2_conv_sf2df
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2df
name|__builtin_HEXAGON_F2_conv_sf2ud
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2ud
name|__builtin_HEXAGON_F2_conv_sf2ud_chop
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2ud.chop
name|__builtin_HEXAGON_F2_conv_sf2uw
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2uw
name|__builtin_HEXAGON_F2_conv_sf2uw_chop
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2uw.chop
name|__builtin_HEXAGON_F2_conv_sf2w
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2w
name|__builtin_HEXAGON_F2_conv_sf2w_chop
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.sf2w.chop
name|__builtin_HEXAGON_F2_conv_ud2df
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.ud2df
name|__builtin_HEXAGON_F2_conv_ud2sf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.ud2sf
name|__builtin_HEXAGON_F2_conv_uw2df
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.uw2df
name|__builtin_HEXAGON_F2_conv_uw2sf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.uw2sf
name|__builtin_HEXAGON_F2_conv_w2df
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.w2df
name|__builtin_HEXAGON_F2_conv_w2sf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.conv.w2sf
name|__builtin_HEXAGON_F2_dfclass
argument_list|(
literal|0.0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfclass
name|__builtin_HEXAGON_F2_dfcmpeq
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfcmpeq
name|__builtin_HEXAGON_F2_dfcmpge
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfcmpge
name|__builtin_HEXAGON_F2_dfcmpgt
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfcmpgt
name|__builtin_HEXAGON_F2_dfcmpuo
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfcmpuo
name|__builtin_HEXAGON_F2_dfimm_n
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfimm.n
name|__builtin_HEXAGON_F2_dfimm_p
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.dfimm.p
name|__builtin_HEXAGON_F2_sfadd
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfadd
name|__builtin_HEXAGON_F2_sfclass
argument_list|(
literal|0.0f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfclass
name|__builtin_HEXAGON_F2_sfcmpeq
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfcmpeq
name|__builtin_HEXAGON_F2_sfcmpge
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfcmpge
name|__builtin_HEXAGON_F2_sfcmpgt
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfcmpgt
name|__builtin_HEXAGON_F2_sfcmpuo
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfcmpuo
name|__builtin_HEXAGON_F2_sffixupd
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffixupd
name|__builtin_HEXAGON_F2_sffixupn
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffixupn
name|__builtin_HEXAGON_F2_sffixupr
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffixupr
name|__builtin_HEXAGON_F2_sffma
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffma
name|__builtin_HEXAGON_F2_sffma_lib
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffma.lib
name|__builtin_HEXAGON_F2_sffma_sc
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffma.sc
name|__builtin_HEXAGON_F2_sffms
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffms
name|__builtin_HEXAGON_F2_sffms_lib
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sffms.lib
name|__builtin_HEXAGON_F2_sfimm_n
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfimm.n
name|__builtin_HEXAGON_F2_sfimm_p
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfimm.p
name|__builtin_HEXAGON_F2_sfmax
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfmax
name|__builtin_HEXAGON_F2_sfmin
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfmin
name|__builtin_HEXAGON_F2_sfmpy
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfmpy
name|__builtin_HEXAGON_F2_sfsub
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.F2.sfsub
name|__builtin_HEXAGON_M2_acci
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.acci
name|__builtin_HEXAGON_M2_accii
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.accii
name|__builtin_HEXAGON_M2_cmaci_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmaci.s0
name|__builtin_HEXAGON_M2_cmacr_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmacr.s0
name|__builtin_HEXAGON_M2_cmacsc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmacsc.s0
name|__builtin_HEXAGON_M2_cmacsc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmacsc.s1
name|__builtin_HEXAGON_M2_cmacs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmacs.s0
name|__builtin_HEXAGON_M2_cmacs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmacs.s1
name|__builtin_HEXAGON_M2_cmpyi_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpyi.s0
name|__builtin_HEXAGON_M2_cmpyr_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpyr.s0
name|__builtin_HEXAGON_M2_cmpyrsc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpyrsc.s0
name|__builtin_HEXAGON_M2_cmpyrsc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpyrsc.s1
name|__builtin_HEXAGON_M2_cmpyrs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpyrs.s0
name|__builtin_HEXAGON_M2_cmpyrs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpyrs.s1
name|__builtin_HEXAGON_M2_cmpysc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpysc.s0
name|__builtin_HEXAGON_M2_cmpysc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpysc.s1
name|__builtin_HEXAGON_M2_cmpys_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpys.s0
name|__builtin_HEXAGON_M2_cmpys_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cmpys.s1
name|__builtin_HEXAGON_M2_cnacsc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cnacsc.s0
name|__builtin_HEXAGON_M2_cnacsc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cnacsc.s1
name|__builtin_HEXAGON_M2_cnacs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cnacs.s0
name|__builtin_HEXAGON_M2_cnacs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.cnacs.s1
name|__builtin_HEXAGON_M2_dpmpyss_acc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyss.acc.s0
name|__builtin_HEXAGON_M2_dpmpyss_nac_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyss.nac.s0
name|__builtin_HEXAGON_M2_dpmpyss_rnd_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyss.rnd.s0
name|__builtin_HEXAGON_M2_dpmpyss_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyss.s0
name|__builtin_HEXAGON_M2_dpmpyuu_acc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyuu.acc.s0
name|__builtin_HEXAGON_M2_dpmpyuu_nac_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyuu.nac.s0
name|__builtin_HEXAGON_M2_dpmpyuu_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.dpmpyuu.s0
name|__builtin_HEXAGON_M2_hmmpyh_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.hmmpyh.rs1
name|__builtin_HEXAGON_M2_hmmpyh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.hmmpyh.s1
name|__builtin_HEXAGON_M2_hmmpyl_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.hmmpyl.rs1
name|__builtin_HEXAGON_M2_hmmpyl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.hmmpyl.s1
name|__builtin_HEXAGON_M2_maci
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.maci
name|__builtin_HEXAGON_M2_macsin
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.macsin
name|__builtin_HEXAGON_M2_macsip
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.macsip
name|__builtin_HEXAGON_M2_mmachs_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmachs.rs0
name|__builtin_HEXAGON_M2_mmachs_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmachs.rs1
name|__builtin_HEXAGON_M2_mmachs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmachs.s0
name|__builtin_HEXAGON_M2_mmachs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmachs.s1
name|__builtin_HEXAGON_M2_mmacls_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacls.rs0
name|__builtin_HEXAGON_M2_mmacls_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacls.rs1
name|__builtin_HEXAGON_M2_mmacls_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacls.s0
name|__builtin_HEXAGON_M2_mmacls_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacls.s1
name|__builtin_HEXAGON_M2_mmacuhs_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacuhs.rs0
name|__builtin_HEXAGON_M2_mmacuhs_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacuhs.rs1
name|__builtin_HEXAGON_M2_mmacuhs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacuhs.s0
name|__builtin_HEXAGON_M2_mmacuhs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmacuhs.s1
name|__builtin_HEXAGON_M2_mmaculs_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmaculs.rs0
name|__builtin_HEXAGON_M2_mmaculs_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmaculs.rs1
name|__builtin_HEXAGON_M2_mmaculs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmaculs.s0
name|__builtin_HEXAGON_M2_mmaculs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmaculs.s1
name|__builtin_HEXAGON_M2_mmpyh_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyh.rs0
name|__builtin_HEXAGON_M2_mmpyh_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyh.rs1
name|__builtin_HEXAGON_M2_mmpyh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyh.s0
name|__builtin_HEXAGON_M2_mmpyh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyh.s1
name|__builtin_HEXAGON_M2_mmpyl_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyl.rs0
name|__builtin_HEXAGON_M2_mmpyl_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyl.rs1
name|__builtin_HEXAGON_M2_mmpyl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyl.s0
name|__builtin_HEXAGON_M2_mmpyl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyl.s1
name|__builtin_HEXAGON_M2_mmpyuh_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyuh.rs0
name|__builtin_HEXAGON_M2_mmpyuh_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyuh.rs1
name|__builtin_HEXAGON_M2_mmpyuh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyuh.s0
name|__builtin_HEXAGON_M2_mmpyuh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyuh.s1
name|__builtin_HEXAGON_M2_mmpyul_rs0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyul.rs0
name|__builtin_HEXAGON_M2_mmpyul_rs1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyul.rs1
name|__builtin_HEXAGON_M2_mmpyul_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyul.s0
name|__builtin_HEXAGON_M2_mmpyul_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mmpyul.s1
name|__builtin_HEXAGON_M2_mpy_acc_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.hh.s0
name|__builtin_HEXAGON_M2_mpy_acc_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.hh.s1
name|__builtin_HEXAGON_M2_mpy_acc_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.hl.s0
name|__builtin_HEXAGON_M2_mpy_acc_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.hl.s1
name|__builtin_HEXAGON_M2_mpy_acc_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.lh.s0
name|__builtin_HEXAGON_M2_mpy_acc_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.lh.s1
name|__builtin_HEXAGON_M2_mpy_acc_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.ll.s0
name|__builtin_HEXAGON_M2_mpy_acc_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.ll.s1
name|__builtin_HEXAGON_M2_mpy_acc_sat_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.hh.s0
name|__builtin_HEXAGON_M2_mpy_acc_sat_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.hh.s1
name|__builtin_HEXAGON_M2_mpy_acc_sat_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.hl.s0
name|__builtin_HEXAGON_M2_mpy_acc_sat_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.hl.s1
name|__builtin_HEXAGON_M2_mpy_acc_sat_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.lh.s0
name|__builtin_HEXAGON_M2_mpy_acc_sat_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.lh.s1
name|__builtin_HEXAGON_M2_mpy_acc_sat_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.ll.s0
name|__builtin_HEXAGON_M2_mpy_acc_sat_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.acc.sat.ll.s1
name|__builtin_HEXAGON_M2_mpyd_acc_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.hh.s0
name|__builtin_HEXAGON_M2_mpyd_acc_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.hh.s1
name|__builtin_HEXAGON_M2_mpyd_acc_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.hl.s0
name|__builtin_HEXAGON_M2_mpyd_acc_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.hl.s1
name|__builtin_HEXAGON_M2_mpyd_acc_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.lh.s0
name|__builtin_HEXAGON_M2_mpyd_acc_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.lh.s1
name|__builtin_HEXAGON_M2_mpyd_acc_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.ll.s0
name|__builtin_HEXAGON_M2_mpyd_acc_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.acc.ll.s1
name|__builtin_HEXAGON_M2_mpyd_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.hh.s0
name|__builtin_HEXAGON_M2_mpyd_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.hh.s1
name|__builtin_HEXAGON_M2_mpyd_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.hl.s0
name|__builtin_HEXAGON_M2_mpyd_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.hl.s1
name|__builtin_HEXAGON_M2_mpyd_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.lh.s0
name|__builtin_HEXAGON_M2_mpyd_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.lh.s1
name|__builtin_HEXAGON_M2_mpyd_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.ll.s0
name|__builtin_HEXAGON_M2_mpyd_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.ll.s1
name|__builtin_HEXAGON_M2_mpyd_nac_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.hh.s0
name|__builtin_HEXAGON_M2_mpyd_nac_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.hh.s1
name|__builtin_HEXAGON_M2_mpyd_nac_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.hl.s0
name|__builtin_HEXAGON_M2_mpyd_nac_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.hl.s1
name|__builtin_HEXAGON_M2_mpyd_nac_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.lh.s0
name|__builtin_HEXAGON_M2_mpyd_nac_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.lh.s1
name|__builtin_HEXAGON_M2_mpyd_nac_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.ll.s0
name|__builtin_HEXAGON_M2_mpyd_nac_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.nac.ll.s1
name|__builtin_HEXAGON_M2_mpyd_rnd_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.hh.s0
name|__builtin_HEXAGON_M2_mpyd_rnd_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.hh.s1
name|__builtin_HEXAGON_M2_mpyd_rnd_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.hl.s0
name|__builtin_HEXAGON_M2_mpyd_rnd_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.hl.s1
name|__builtin_HEXAGON_M2_mpyd_rnd_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.lh.s0
name|__builtin_HEXAGON_M2_mpyd_rnd_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.lh.s1
name|__builtin_HEXAGON_M2_mpyd_rnd_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.ll.s0
name|__builtin_HEXAGON_M2_mpyd_rnd_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyd.rnd.ll.s1
name|__builtin_HEXAGON_M2_mpy_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.hh.s0
name|__builtin_HEXAGON_M2_mpy_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.hh.s1
name|__builtin_HEXAGON_M2_mpy_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.hl.s0
name|__builtin_HEXAGON_M2_mpy_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.hl.s1
name|__builtin_HEXAGON_M2_mpyi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyi
name|__builtin_HEXAGON_M2_mpy_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.lh.s0
name|__builtin_HEXAGON_M2_mpy_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.lh.s1
name|__builtin_HEXAGON_M2_mpy_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.ll.s0
name|__builtin_HEXAGON_M2_mpy_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.ll.s1
name|__builtin_HEXAGON_M2_mpy_nac_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.hh.s0
name|__builtin_HEXAGON_M2_mpy_nac_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.hh.s1
name|__builtin_HEXAGON_M2_mpy_nac_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.hl.s0
name|__builtin_HEXAGON_M2_mpy_nac_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.hl.s1
name|__builtin_HEXAGON_M2_mpy_nac_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.lh.s0
name|__builtin_HEXAGON_M2_mpy_nac_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.lh.s1
name|__builtin_HEXAGON_M2_mpy_nac_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.ll.s0
name|__builtin_HEXAGON_M2_mpy_nac_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.ll.s1
name|__builtin_HEXAGON_M2_mpy_nac_sat_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.hh.s0
name|__builtin_HEXAGON_M2_mpy_nac_sat_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.hh.s1
name|__builtin_HEXAGON_M2_mpy_nac_sat_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.hl.s0
name|__builtin_HEXAGON_M2_mpy_nac_sat_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.hl.s1
name|__builtin_HEXAGON_M2_mpy_nac_sat_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.lh.s0
name|__builtin_HEXAGON_M2_mpy_nac_sat_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.lh.s1
name|__builtin_HEXAGON_M2_mpy_nac_sat_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.ll.s0
name|__builtin_HEXAGON_M2_mpy_nac_sat_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.nac.sat.ll.s1
name|__builtin_HEXAGON_M2_mpy_rnd_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.hh.s0
name|__builtin_HEXAGON_M2_mpy_rnd_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.hh.s1
name|__builtin_HEXAGON_M2_mpy_rnd_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.hl.s0
name|__builtin_HEXAGON_M2_mpy_rnd_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.hl.s1
name|__builtin_HEXAGON_M2_mpy_rnd_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.lh.s0
name|__builtin_HEXAGON_M2_mpy_rnd_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.lh.s1
name|__builtin_HEXAGON_M2_mpy_rnd_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.ll.s0
name|__builtin_HEXAGON_M2_mpy_rnd_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.rnd.ll.s1
name|__builtin_HEXAGON_M2_mpy_sat_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.hh.s0
name|__builtin_HEXAGON_M2_mpy_sat_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.hh.s1
name|__builtin_HEXAGON_M2_mpy_sat_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.hl.s0
name|__builtin_HEXAGON_M2_mpy_sat_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.hl.s1
name|__builtin_HEXAGON_M2_mpy_sat_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.lh.s0
name|__builtin_HEXAGON_M2_mpy_sat_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.lh.s1
name|__builtin_HEXAGON_M2_mpy_sat_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.ll.s0
name|__builtin_HEXAGON_M2_mpy_sat_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.ll.s1
name|__builtin_HEXAGON_M2_mpy_sat_rnd_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.hh.s0
name|__builtin_HEXAGON_M2_mpy_sat_rnd_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.hh.s1
name|__builtin_HEXAGON_M2_mpy_sat_rnd_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.hl.s0
name|__builtin_HEXAGON_M2_mpy_sat_rnd_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.hl.s1
name|__builtin_HEXAGON_M2_mpy_sat_rnd_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.lh.s0
name|__builtin_HEXAGON_M2_mpy_sat_rnd_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.lh.s1
name|__builtin_HEXAGON_M2_mpy_sat_rnd_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.ll.s0
name|__builtin_HEXAGON_M2_mpy_sat_rnd_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.sat.rnd.ll.s1
name|__builtin_HEXAGON_M2_mpysmi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpysmi
name|__builtin_HEXAGON_M2_mpysu_up
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpysu.up
name|__builtin_HEXAGON_M2_mpyu_acc_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.hh.s0
name|__builtin_HEXAGON_M2_mpyu_acc_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.hh.s1
name|__builtin_HEXAGON_M2_mpyu_acc_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.hl.s0
name|__builtin_HEXAGON_M2_mpyu_acc_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.hl.s1
name|__builtin_HEXAGON_M2_mpyu_acc_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.lh.s0
name|__builtin_HEXAGON_M2_mpyu_acc_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.lh.s1
name|__builtin_HEXAGON_M2_mpyu_acc_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.ll.s0
name|__builtin_HEXAGON_M2_mpyu_acc_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.acc.ll.s1
name|__builtin_HEXAGON_M2_mpyud_acc_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.hh.s0
name|__builtin_HEXAGON_M2_mpyud_acc_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.hh.s1
name|__builtin_HEXAGON_M2_mpyud_acc_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.hl.s0
name|__builtin_HEXAGON_M2_mpyud_acc_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.hl.s1
name|__builtin_HEXAGON_M2_mpyud_acc_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.lh.s0
name|__builtin_HEXAGON_M2_mpyud_acc_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.lh.s1
name|__builtin_HEXAGON_M2_mpyud_acc_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.ll.s0
name|__builtin_HEXAGON_M2_mpyud_acc_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.acc.ll.s1
name|__builtin_HEXAGON_M2_mpyud_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.hh.s0
name|__builtin_HEXAGON_M2_mpyud_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.hh.s1
name|__builtin_HEXAGON_M2_mpyud_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.hl.s0
name|__builtin_HEXAGON_M2_mpyud_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.hl.s1
name|__builtin_HEXAGON_M2_mpyud_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.lh.s0
name|__builtin_HEXAGON_M2_mpyud_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.lh.s1
name|__builtin_HEXAGON_M2_mpyud_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.ll.s0
name|__builtin_HEXAGON_M2_mpyud_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.ll.s1
name|__builtin_HEXAGON_M2_mpyud_nac_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.hh.s0
name|__builtin_HEXAGON_M2_mpyud_nac_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.hh.s1
name|__builtin_HEXAGON_M2_mpyud_nac_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.hl.s0
name|__builtin_HEXAGON_M2_mpyud_nac_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.hl.s1
name|__builtin_HEXAGON_M2_mpyud_nac_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.lh.s0
name|__builtin_HEXAGON_M2_mpyud_nac_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.lh.s1
name|__builtin_HEXAGON_M2_mpyud_nac_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.ll.s0
name|__builtin_HEXAGON_M2_mpyud_nac_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyud.nac.ll.s1
name|__builtin_HEXAGON_M2_mpyu_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.hh.s0
name|__builtin_HEXAGON_M2_mpyu_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.hh.s1
name|__builtin_HEXAGON_M2_mpyu_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.hl.s0
name|__builtin_HEXAGON_M2_mpyu_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.hl.s1
name|__builtin_HEXAGON_M2_mpyui
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyui
name|__builtin_HEXAGON_M2_mpyu_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.lh.s0
name|__builtin_HEXAGON_M2_mpyu_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.lh.s1
name|__builtin_HEXAGON_M2_mpyu_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.ll.s0
name|__builtin_HEXAGON_M2_mpyu_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.ll.s1
name|__builtin_HEXAGON_M2_mpyu_nac_hh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.hh.s0
name|__builtin_HEXAGON_M2_mpyu_nac_hh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.hh.s1
name|__builtin_HEXAGON_M2_mpyu_nac_hl_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.hl.s0
name|__builtin_HEXAGON_M2_mpyu_nac_hl_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.hl.s1
name|__builtin_HEXAGON_M2_mpyu_nac_lh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.lh.s0
name|__builtin_HEXAGON_M2_mpyu_nac_lh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.lh.s1
name|__builtin_HEXAGON_M2_mpyu_nac_ll_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.ll.s0
name|__builtin_HEXAGON_M2_mpyu_nac_ll_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.nac.ll.s1
name|__builtin_HEXAGON_M2_mpy_up
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.up
name|__builtin_HEXAGON_M2_mpy_up_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.up.s1
name|__builtin_HEXAGON_M2_mpy_up_s1_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpy.up.s1.sat
name|__builtin_HEXAGON_M2_mpyu_up
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.mpyu.up
name|__builtin_HEXAGON_M2_nacci
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.nacci
name|__builtin_HEXAGON_M2_naccii
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.naccii
name|__builtin_HEXAGON_M2_subacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.subacc
name|__builtin_HEXAGON_M2_vabsdiffh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vabsdiffh
name|__builtin_HEXAGON_M2_vabsdiffw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vabsdiffw
name|__builtin_HEXAGON_M2_vcmac_s0_sat_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vcmac.s0.sat.i
name|__builtin_HEXAGON_M2_vcmac_s0_sat_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vcmac.s0.sat.r
name|__builtin_HEXAGON_M2_vcmpy_s0_sat_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vcmpy.s0.sat.i
name|__builtin_HEXAGON_M2_vcmpy_s0_sat_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vcmpy.s0.sat.r
name|__builtin_HEXAGON_M2_vcmpy_s1_sat_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vcmpy.s1.sat.i
name|__builtin_HEXAGON_M2_vcmpy_s1_sat_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vcmpy.s1.sat.r
name|__builtin_HEXAGON_M2_vdmacs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vdmacs.s0
name|__builtin_HEXAGON_M2_vdmacs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vdmacs.s1
name|__builtin_HEXAGON_M2_vdmpyrs_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vdmpyrs.s0
name|__builtin_HEXAGON_M2_vdmpyrs_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vdmpyrs.s1
name|__builtin_HEXAGON_M2_vdmpys_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vdmpys.s0
name|__builtin_HEXAGON_M2_vdmpys_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vdmpys.s1
name|__builtin_HEXAGON_M2_vmac2
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2
name|__builtin_HEXAGON_M2_vmac2es
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2es
name|__builtin_HEXAGON_M2_vmac2es_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2es.s0
name|__builtin_HEXAGON_M2_vmac2es_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2es.s1
name|__builtin_HEXAGON_M2_vmac2s_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2s.s0
name|__builtin_HEXAGON_M2_vmac2s_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2s.s1
name|__builtin_HEXAGON_M2_vmac2su_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2su.s0
name|__builtin_HEXAGON_M2_vmac2su_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmac2su.s1
name|__builtin_HEXAGON_M2_vmpy2es_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2es.s0
name|__builtin_HEXAGON_M2_vmpy2es_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2es.s1
name|__builtin_HEXAGON_M2_vmpy2s_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2s.s0
name|__builtin_HEXAGON_M2_vmpy2s_s0pack
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2s.s0pack
name|__builtin_HEXAGON_M2_vmpy2s_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2s.s1
name|__builtin_HEXAGON_M2_vmpy2s_s1pack
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2s.s1pack
name|__builtin_HEXAGON_M2_vmpy2su_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2su.s0
name|__builtin_HEXAGON_M2_vmpy2su_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vmpy2su.s1
name|__builtin_HEXAGON_M2_vraddh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vraddh
name|__builtin_HEXAGON_M2_vradduh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vradduh
name|__builtin_HEXAGON_M2_vrcmaci_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmaci.s0
name|__builtin_HEXAGON_M2_vrcmaci_s0c
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmaci.s0c
name|__builtin_HEXAGON_M2_vrcmacr_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmacr.s0
name|__builtin_HEXAGON_M2_vrcmacr_s0c
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmacr.s0c
name|__builtin_HEXAGON_M2_vrcmpyi_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpyi.s0
name|__builtin_HEXAGON_M2_vrcmpyi_s0c
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpyi.s0c
name|__builtin_HEXAGON_M2_vrcmpyr_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpyr.s0
name|__builtin_HEXAGON_M2_vrcmpyr_s0c
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpyr.s0c
name|__builtin_HEXAGON_M2_vrcmpys_acc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpys.acc.s1
name|__builtin_HEXAGON_M2_vrcmpys_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpys.s1
name|__builtin_HEXAGON_M2_vrcmpys_s1rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrcmpys.s1rp
name|__builtin_HEXAGON_M2_vrmac_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrmac.s0
name|__builtin_HEXAGON_M2_vrmpy_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.vrmpy.s0
name|__builtin_HEXAGON_M2_xor_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M2.xor.xacc
name|__builtin_HEXAGON_M4_and_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.and.and
name|__builtin_HEXAGON_M4_and_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.and.andn
name|__builtin_HEXAGON_M4_and_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.and.or
name|__builtin_HEXAGON_M4_and_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.and.xor
name|__builtin_HEXAGON_M4_cmpyi_wh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.cmpyi.wh
name|__builtin_HEXAGON_M4_cmpyi_whc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.cmpyi.whc
name|__builtin_HEXAGON_M4_cmpyr_wh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.cmpyr.wh
name|__builtin_HEXAGON_M4_cmpyr_whc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.cmpyr.whc
name|__builtin_HEXAGON_M4_mac_up_s1_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.mac.up.s1.sat
name|__builtin_HEXAGON_M4_mpyri_addi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.mpyri.addi
name|__builtin_HEXAGON_M4_mpyri_addr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.mpyri.addr
name|__builtin_HEXAGON_M4_mpyri_addr_u2
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.mpyri.addr.u2
name|__builtin_HEXAGON_M4_mpyrr_addi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.mpyrr.addi
name|__builtin_HEXAGON_M4_mpyrr_addr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.mpyrr.addr
name|__builtin_HEXAGON_M4_nac_up_s1_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.nac.up.s1.sat
name|__builtin_HEXAGON_M4_or_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.or.and
name|__builtin_HEXAGON_M4_or_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.or.andn
name|__builtin_HEXAGON_M4_or_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.or.or
name|__builtin_HEXAGON_M4_or_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.or.xor
name|__builtin_HEXAGON_M4_pmpyw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.pmpyw
name|__builtin_HEXAGON_M4_pmpyw_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.pmpyw.acc
name|__builtin_HEXAGON_M4_vpmpyh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vpmpyh
name|__builtin_HEXAGON_M4_vpmpyh_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vpmpyh.acc
name|__builtin_HEXAGON_M4_vrmpyeh_acc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyeh.acc.s0
name|__builtin_HEXAGON_M4_vrmpyeh_acc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyeh.acc.s1
name|__builtin_HEXAGON_M4_vrmpyeh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyeh.s0
name|__builtin_HEXAGON_M4_vrmpyeh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyeh.s1
name|__builtin_HEXAGON_M4_vrmpyoh_acc_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyoh.acc.s0
name|__builtin_HEXAGON_M4_vrmpyoh_acc_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyoh.acc.s1
name|__builtin_HEXAGON_M4_vrmpyoh_s0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyoh.s0
name|__builtin_HEXAGON_M4_vrmpyoh_s1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.vrmpyoh.s1
name|__builtin_HEXAGON_M4_xor_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.xor.and
name|__builtin_HEXAGON_M4_xor_andn
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.xor.andn
name|__builtin_HEXAGON_M4_xor_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.xor.or
name|__builtin_HEXAGON_M4_xor_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M4.xor.xacc
name|__builtin_HEXAGON_M5_vdmacbsu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vdmacbsu
name|__builtin_HEXAGON_M5_vdmpybsu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vdmpybsu
name|__builtin_HEXAGON_M5_vmacbsu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vmacbsu
name|__builtin_HEXAGON_M5_vmacbuu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vmacbuu
name|__builtin_HEXAGON_M5_vmpybsu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vmpybsu
name|__builtin_HEXAGON_M5_vmpybuu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vmpybuu
name|__builtin_HEXAGON_M5_vrmacbsu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vrmacbsu
name|__builtin_HEXAGON_M5_vrmacbuu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vrmacbuu
name|__builtin_HEXAGON_M5_vrmpybsu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vrmpybsu
name|__builtin_HEXAGON_M5_vrmpybuu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.M5.vrmpybuu
name|__builtin_HEXAGON_S2_addasl_rrri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.addasl.rrri
name|__builtin_HEXAGON_S2_asl_i_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.p
name|__builtin_HEXAGON_S2_asl_i_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.p.acc
name|__builtin_HEXAGON_S2_asl_i_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.p.and
name|__builtin_HEXAGON_S2_asl_i_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.p.nac
name|__builtin_HEXAGON_S2_asl_i_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.p.or
name|__builtin_HEXAGON_S2_asl_i_p_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.p.xacc
name|__builtin_HEXAGON_S2_asl_i_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r
name|__builtin_HEXAGON_S2_asl_i_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r.acc
name|__builtin_HEXAGON_S2_asl_i_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r.and
name|__builtin_HEXAGON_S2_asl_i_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r.nac
name|__builtin_HEXAGON_S2_asl_i_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r.or
name|__builtin_HEXAGON_S2_asl_i_r_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r.sat
name|__builtin_HEXAGON_S2_asl_i_r_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.r.xacc
name|__builtin_HEXAGON_S2_asl_i_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.vh
name|__builtin_HEXAGON_S2_asl_i_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.i.vw
name|__builtin_HEXAGON_S2_asl_r_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.p
name|__builtin_HEXAGON_S2_asl_r_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.p.acc
name|__builtin_HEXAGON_S2_asl_r_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.p.and
name|__builtin_HEXAGON_S2_asl_r_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.p.nac
name|__builtin_HEXAGON_S2_asl_r_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.p.or
name|__builtin_HEXAGON_S2_asl_r_p_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.p.xor
name|__builtin_HEXAGON_S2_asl_r_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.r
name|__builtin_HEXAGON_S2_asl_r_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.r.acc
name|__builtin_HEXAGON_S2_asl_r_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.r.and
name|__builtin_HEXAGON_S2_asl_r_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.r.nac
name|__builtin_HEXAGON_S2_asl_r_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.r.or
name|__builtin_HEXAGON_S2_asl_r_r_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.r.sat
name|__builtin_HEXAGON_S2_asl_r_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.vh
name|__builtin_HEXAGON_S2_asl_r_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asl.r.vw
name|__builtin_HEXAGON_S2_asr_i_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p
name|__builtin_HEXAGON_S2_asr_i_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p.acc
name|__builtin_HEXAGON_S2_asr_i_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p.and
name|__builtin_HEXAGON_S2_asr_i_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p.nac
name|__builtin_HEXAGON_S2_asr_i_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p.or
name|__builtin_HEXAGON_S2_asr_i_p_rnd
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p.rnd
name|__builtin_HEXAGON_S2_asr_i_p_rnd_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.p.rnd.goodsyntax
name|__builtin_HEXAGON_S2_asr_i_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r
name|__builtin_HEXAGON_S2_asr_i_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r.acc
name|__builtin_HEXAGON_S2_asr_i_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r.and
name|__builtin_HEXAGON_S2_asr_i_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r.nac
name|__builtin_HEXAGON_S2_asr_i_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r.or
name|__builtin_HEXAGON_S2_asr_i_r_rnd
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r.rnd
name|__builtin_HEXAGON_S2_asr_i_r_rnd_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.r.rnd.goodsyntax
name|__builtin_HEXAGON_S2_asr_i_svw_trun
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.svw.trun
name|__builtin_HEXAGON_S2_asr_i_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.vh
name|__builtin_HEXAGON_S2_asr_i_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.i.vw
name|__builtin_HEXAGON_S2_asr_r_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.p
name|__builtin_HEXAGON_S2_asr_r_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.p.acc
name|__builtin_HEXAGON_S2_asr_r_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.p.and
name|__builtin_HEXAGON_S2_asr_r_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.p.nac
name|__builtin_HEXAGON_S2_asr_r_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.p.or
name|__builtin_HEXAGON_S2_asr_r_p_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.p.xor
name|__builtin_HEXAGON_S2_asr_r_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.r
name|__builtin_HEXAGON_S2_asr_r_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.r.acc
name|__builtin_HEXAGON_S2_asr_r_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.r.and
name|__builtin_HEXAGON_S2_asr_r_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.r.nac
name|__builtin_HEXAGON_S2_asr_r_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.r.or
name|__builtin_HEXAGON_S2_asr_r_r_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.r.sat
name|__builtin_HEXAGON_S2_asr_r_svw_trun
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.svw.trun
name|__builtin_HEXAGON_S2_asr_r_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.vh
name|__builtin_HEXAGON_S2_asr_r_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.asr.r.vw
name|__builtin_HEXAGON_S2_brev
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.brev
name|__builtin_HEXAGON_S2_brevp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.brevp
name|__builtin_HEXAGON_S2_cabacencbin
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.cabacencbin
name|__builtin_HEXAGON_S2_cl0
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.cl0
name|__builtin_HEXAGON_S2_cl0p
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.cl0p
name|__builtin_HEXAGON_S2_cl1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.cl1
name|__builtin_HEXAGON_S2_cl1p
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.cl1p
name|__builtin_HEXAGON_S2_clb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.clb
name|__builtin_HEXAGON_S2_clbnorm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.clbnorm
name|__builtin_HEXAGON_S2_clbp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.clbp
name|__builtin_HEXAGON_S2_clrbit_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.clrbit.i
name|__builtin_HEXAGON_S2_clrbit_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.clrbit.r
name|__builtin_HEXAGON_S2_ct0
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.ct0
name|__builtin_HEXAGON_S2_ct0p
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.ct0p
name|__builtin_HEXAGON_S2_ct1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.ct1
name|__builtin_HEXAGON_S2_ct1p
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.ct1p
name|__builtin_HEXAGON_S2_deinterleave
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.deinterleave
name|__builtin_HEXAGON_S2_extractu
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.extractu
name|__builtin_HEXAGON_S2_extractup
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.extractup
name|__builtin_HEXAGON_S2_extractup_rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.extractup.rp
name|__builtin_HEXAGON_S2_extractu_rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.extractu.rp
name|__builtin_HEXAGON_S2_insert
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.insert
name|__builtin_HEXAGON_S2_insertp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.insertp
name|__builtin_HEXAGON_S2_insertp_rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.insertp.rp
name|__builtin_HEXAGON_S2_insert_rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.insert.rp
name|__builtin_HEXAGON_S2_interleave
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.interleave
name|__builtin_HEXAGON_S2_lfsp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lfsp
name|__builtin_HEXAGON_S2_lsl_r_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.p
name|__builtin_HEXAGON_S2_lsl_r_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.p.acc
name|__builtin_HEXAGON_S2_lsl_r_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.p.and
name|__builtin_HEXAGON_S2_lsl_r_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.p.nac
name|__builtin_HEXAGON_S2_lsl_r_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.p.or
name|__builtin_HEXAGON_S2_lsl_r_p_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.p.xor
name|__builtin_HEXAGON_S2_lsl_r_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.r
name|__builtin_HEXAGON_S2_lsl_r_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.r.acc
name|__builtin_HEXAGON_S2_lsl_r_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.r.and
name|__builtin_HEXAGON_S2_lsl_r_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.r.nac
name|__builtin_HEXAGON_S2_lsl_r_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.r.or
name|__builtin_HEXAGON_S2_lsl_r_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.vh
name|__builtin_HEXAGON_S2_lsl_r_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsl.r.vw
name|__builtin_HEXAGON_S2_lsr_i_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.p
name|__builtin_HEXAGON_S2_lsr_i_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.p.acc
name|__builtin_HEXAGON_S2_lsr_i_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.p.and
name|__builtin_HEXAGON_S2_lsr_i_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.p.nac
name|__builtin_HEXAGON_S2_lsr_i_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.p.or
name|__builtin_HEXAGON_S2_lsr_i_p_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.p.xacc
name|__builtin_HEXAGON_S2_lsr_i_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.r
name|__builtin_HEXAGON_S2_lsr_i_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.r.acc
name|__builtin_HEXAGON_S2_lsr_i_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.r.and
name|__builtin_HEXAGON_S2_lsr_i_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.r.nac
name|__builtin_HEXAGON_S2_lsr_i_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.r.or
name|__builtin_HEXAGON_S2_lsr_i_r_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.r.xacc
name|__builtin_HEXAGON_S2_lsr_i_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.vh
name|__builtin_HEXAGON_S2_lsr_i_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.i.vw
name|__builtin_HEXAGON_S2_lsr_r_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.p
name|__builtin_HEXAGON_S2_lsr_r_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.p.acc
name|__builtin_HEXAGON_S2_lsr_r_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.p.and
name|__builtin_HEXAGON_S2_lsr_r_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.p.nac
name|__builtin_HEXAGON_S2_lsr_r_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.p.or
name|__builtin_HEXAGON_S2_lsr_r_p_xor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.p.xor
name|__builtin_HEXAGON_S2_lsr_r_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.r
name|__builtin_HEXAGON_S2_lsr_r_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.r.acc
name|__builtin_HEXAGON_S2_lsr_r_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.r.and
name|__builtin_HEXAGON_S2_lsr_r_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.r.nac
name|__builtin_HEXAGON_S2_lsr_r_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.r.or
name|__builtin_HEXAGON_S2_lsr_r_vh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.vh
name|__builtin_HEXAGON_S2_lsr_r_vw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.lsr.r.vw
name|__builtin_HEXAGON_S2_packhl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.packhl
name|__builtin_HEXAGON_S2_parityp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.parityp
name|__builtin_HEXAGON_S2_setbit_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.setbit.i
name|__builtin_HEXAGON_S2_setbit_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.setbit.r
name|__builtin_HEXAGON_S2_shuffeb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.shuffeb
name|__builtin_HEXAGON_S2_shuffeh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.shuffeh
name|__builtin_HEXAGON_S2_shuffob
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.shuffob
name|__builtin_HEXAGON_S2_shuffoh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.shuffoh
name|__builtin_HEXAGON_S2_svsathb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.svsathb
name|__builtin_HEXAGON_S2_svsathub
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.svsathub
name|__builtin_HEXAGON_S2_tableidxb_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.tableidxb.goodsyntax
name|__builtin_HEXAGON_S2_tableidxd_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.tableidxd.goodsyntax
name|__builtin_HEXAGON_S2_tableidxh_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.tableidxh.goodsyntax
name|__builtin_HEXAGON_S2_tableidxw_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.tableidxw.goodsyntax
name|__builtin_HEXAGON_S2_togglebit_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.togglebit.i
name|__builtin_HEXAGON_S2_togglebit_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.togglebit.r
name|__builtin_HEXAGON_S2_tstbit_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.tstbit.i
name|__builtin_HEXAGON_S2_tstbit_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.tstbit.r
name|__builtin_HEXAGON_S2_valignib
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.valignib
name|__builtin_HEXAGON_S2_valignrb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.valignrb
name|__builtin_HEXAGON_S2_vcnegh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vcnegh
name|__builtin_HEXAGON_S2_vcrotate
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vcrotate
name|__builtin_HEXAGON_S2_vrcnegh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vrcnegh
name|__builtin_HEXAGON_S2_vrndpackwh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vrndpackwh
name|__builtin_HEXAGON_S2_vrndpackwhs
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vrndpackwhs
name|__builtin_HEXAGON_S2_vsathb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsathb
name|__builtin_HEXAGON_S2_vsathb_nopack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsathb.nopack
name|__builtin_HEXAGON_S2_vsathub
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsathub
name|__builtin_HEXAGON_S2_vsathub_nopack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsathub.nopack
name|__builtin_HEXAGON_S2_vsatwh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsatwh
name|__builtin_HEXAGON_S2_vsatwh_nopack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsatwh.nopack
name|__builtin_HEXAGON_S2_vsatwuh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsatwuh
name|__builtin_HEXAGON_S2_vsatwuh_nopack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsatwuh.nopack
name|__builtin_HEXAGON_S2_vsplatrb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsplatrb
name|__builtin_HEXAGON_S2_vsplatrh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsplatrh
name|__builtin_HEXAGON_S2_vspliceib
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vspliceib
name|__builtin_HEXAGON_S2_vsplicerb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsplicerb
name|__builtin_HEXAGON_S2_vsxtbh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsxtbh
name|__builtin_HEXAGON_S2_vsxthw
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vsxthw
name|__builtin_HEXAGON_S2_vtrunehb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vtrunehb
name|__builtin_HEXAGON_S2_vtrunewh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vtrunewh
name|__builtin_HEXAGON_S2_vtrunohb
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vtrunohb
name|__builtin_HEXAGON_S2_vtrunowh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vtrunowh
name|__builtin_HEXAGON_S2_vzxtbh
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vzxtbh
name|__builtin_HEXAGON_S2_vzxthw
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S2.vzxthw
name|__builtin_HEXAGON_S4_addaddi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.addaddi
name|__builtin_HEXAGON_S4_addi_asl_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.addi.asl.ri
name|__builtin_HEXAGON_S4_addi_lsr_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.addi.lsr.ri
name|__builtin_HEXAGON_S4_andi_asl_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.andi.asl.ri
name|__builtin_HEXAGON_S4_andi_lsr_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.andi.lsr.ri
name|__builtin_HEXAGON_S4_clbaddi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.clbaddi
name|__builtin_HEXAGON_S4_clbpaddi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.clbpaddi
name|__builtin_HEXAGON_S4_clbpnorm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.clbpnorm
name|__builtin_HEXAGON_S4_extract
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.extract
name|__builtin_HEXAGON_S4_extractp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.extractp
name|__builtin_HEXAGON_S4_extractp_rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.extractp.rp
name|__builtin_HEXAGON_S4_extract_rp
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.extract.rp
name|__builtin_HEXAGON_S4_lsli
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.lsli
name|__builtin_HEXAGON_S4_ntstbit_i
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.ntstbit.i
name|__builtin_HEXAGON_S4_ntstbit_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.ntstbit.r
name|__builtin_HEXAGON_S4_or_andi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.or.andi
name|__builtin_HEXAGON_S4_or_andix
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.or.andix
name|__builtin_HEXAGON_S4_ori_asl_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.ori.asl.ri
name|__builtin_HEXAGON_S4_ori_lsr_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.ori.lsr.ri
name|__builtin_HEXAGON_S4_or_ori
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.or.ori
name|__builtin_HEXAGON_S4_parity
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.parity
name|__builtin_HEXAGON_S4_subaddi
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.subaddi
name|__builtin_HEXAGON_S4_subi_asl_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.subi.asl.ri
name|__builtin_HEXAGON_S4_subi_lsr_ri
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.subi.lsr.ri
name|__builtin_HEXAGON_S4_vrcrotate
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vrcrotate
name|__builtin_HEXAGON_S4_vrcrotate_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vrcrotate.acc
name|__builtin_HEXAGON_S4_vxaddsubh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vxaddsubh
name|__builtin_HEXAGON_S4_vxaddsubhr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vxaddsubhr
name|__builtin_HEXAGON_S4_vxaddsubw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vxaddsubw
name|__builtin_HEXAGON_S4_vxsubaddh
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vxsubaddh
name|__builtin_HEXAGON_S4_vxsubaddhr
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vxsubaddhr
name|__builtin_HEXAGON_S4_vxsubaddw
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S4.vxsubaddw
name|__builtin_HEXAGON_S5_asrhub_rnd_sat_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S5.asrhub.rnd.sat.goodsyntax
name|__builtin_HEXAGON_S5_asrhub_sat
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S5.asrhub.sat
name|__builtin_HEXAGON_S5_popcountp
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S5.popcountp
name|__builtin_HEXAGON_S5_vasrhrnd_goodsyntax
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S5.vasrhrnd.goodsyntax
name|__builtin_HEXAGON_S6_rol_i_p
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.p
name|__builtin_HEXAGON_S6_rol_i_p_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.p.acc
name|__builtin_HEXAGON_S6_rol_i_p_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.p.and
name|__builtin_HEXAGON_S6_rol_i_p_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.p.nac
name|__builtin_HEXAGON_S6_rol_i_p_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.p.or
name|__builtin_HEXAGON_S6_rol_i_p_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.p.xacc
name|__builtin_HEXAGON_S6_rol_i_r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.r
name|__builtin_HEXAGON_S6_rol_i_r_acc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.r.acc
name|__builtin_HEXAGON_S6_rol_i_r_and
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.r.and
name|__builtin_HEXAGON_S6_rol_i_r_nac
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.r.nac
name|__builtin_HEXAGON_S6_rol_i_r_or
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.r.or
name|__builtin_HEXAGON_S6_rol_i_r_xacc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.S6.rol.i.r.xacc
name|__builtin_HEXAGON_V6_extractw_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.extractw.128B
name|__builtin_HEXAGON_V6_extractw
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.extractw
name|__builtin_HEXAGON_V6_hi_128B
argument_list|(
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.hi.128B
name|__builtin_HEXAGON_V6_hi
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.hi
name|__builtin_HEXAGON_V6_lo_128B
argument_list|(
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.lo.128B
name|__builtin_HEXAGON_V6_lo
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.lo
name|__builtin_HEXAGON_V6_lvsplatw
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.lvsplatw
name|__builtin_HEXAGON_V6_lvsplatw_128B
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.lvsplatw.128B
name|__builtin_HEXAGON_V6_pred_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.and.128B
name|__builtin_HEXAGON_V6_pred_and_n_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.and.n.128B
name|__builtin_HEXAGON_V6_pred_and_n
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.and.n
name|__builtin_HEXAGON_V6_pred_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.and
name|__builtin_HEXAGON_V6_pred_not_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.not.128B
name|__builtin_HEXAGON_V6_pred_not
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.not
name|__builtin_HEXAGON_V6_pred_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.or.128B
name|__builtin_HEXAGON_V6_pred_or_n_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.or.n.128B
name|__builtin_HEXAGON_V6_pred_or_n
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.or.n
name|__builtin_HEXAGON_V6_pred_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.or
name|__builtin_HEXAGON_V6_pred_scalar2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.scalar2
name|__builtin_HEXAGON_V6_pred_scalar2_128B
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.scalar2.128B
name|__builtin_HEXAGON_V6_pred_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.xor.128B
name|__builtin_HEXAGON_V6_pred_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.pred.xor
name|__builtin_HEXAGON_V6_vabsdiffh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffh.128B
name|__builtin_HEXAGON_V6_vabsdiffh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffh
name|__builtin_HEXAGON_V6_vabsdiffub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffub.128B
name|__builtin_HEXAGON_V6_vabsdiffub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffub
name|__builtin_HEXAGON_V6_vabsdiffuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffuh.128B
name|__builtin_HEXAGON_V6_vabsdiffuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffuh
name|__builtin_HEXAGON_V6_vabsdiffw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffw.128B
name|__builtin_HEXAGON_V6_vabsdiffw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsdiffw
name|__builtin_HEXAGON_V6_vabsh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsh.128B
name|__builtin_HEXAGON_V6_vabsh_sat_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsh.sat.128B
name|__builtin_HEXAGON_V6_vabsh_sat
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsh.sat
name|__builtin_HEXAGON_V6_vabsh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsh
name|__builtin_HEXAGON_V6_vabsw_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsw.128B
name|__builtin_HEXAGON_V6_vabsw_sat_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsw.sat.128B
name|__builtin_HEXAGON_V6_vabsw_sat
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsw.sat
name|__builtin_HEXAGON_V6_vabsw
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vabsw
name|__builtin_HEXAGON_V6_vaddb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddb.128B
name|__builtin_HEXAGON_V6_vaddb_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddb.dv.128B
name|__builtin_HEXAGON_V6_vaddb_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddb.dv
name|__builtin_HEXAGON_V6_vaddbnq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddbnq.128B
name|__builtin_HEXAGON_V6_vaddbnq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddbnq
name|__builtin_HEXAGON_V6_vaddbq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddbq.128B
name|__builtin_HEXAGON_V6_vaddbq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddbq
name|__builtin_HEXAGON_V6_vaddb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddb
name|__builtin_HEXAGON_V6_vaddh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddh.128B
name|__builtin_HEXAGON_V6_vaddh_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddh.dv.128B
name|__builtin_HEXAGON_V6_vaddh_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddh.dv
name|__builtin_HEXAGON_V6_vaddhnq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhnq.128B
name|__builtin_HEXAGON_V6_vaddhnq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhnq
name|__builtin_HEXAGON_V6_vaddhq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhq.128B
name|__builtin_HEXAGON_V6_vaddhq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhq
name|__builtin_HEXAGON_V6_vaddhsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhsat.128B
name|__builtin_HEXAGON_V6_vaddhsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhsat.dv.128B
name|__builtin_HEXAGON_V6_vaddhsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhsat.dv
name|__builtin_HEXAGON_V6_vaddhsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhsat
name|__builtin_HEXAGON_V6_vaddh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddh
name|__builtin_HEXAGON_V6_vaddhw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhw.128B
name|__builtin_HEXAGON_V6_vaddhw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddhw
name|__builtin_HEXAGON_V6_vaddubh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddubh.128B
name|__builtin_HEXAGON_V6_vaddubh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddubh
name|__builtin_HEXAGON_V6_vaddubsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddubsat.128B
name|__builtin_HEXAGON_V6_vaddubsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddubsat.dv.128B
name|__builtin_HEXAGON_V6_vaddubsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddubsat.dv
name|__builtin_HEXAGON_V6_vaddubsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddubsat
name|__builtin_HEXAGON_V6_vadduhsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vadduhsat.128B
name|__builtin_HEXAGON_V6_vadduhsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vadduhsat.dv.128B
name|__builtin_HEXAGON_V6_vadduhsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vadduhsat.dv
name|__builtin_HEXAGON_V6_vadduhsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vadduhsat
name|__builtin_HEXAGON_V6_vadduhw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vadduhw.128B
name|__builtin_HEXAGON_V6_vadduhw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vadduhw
name|__builtin_HEXAGON_V6_vaddw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddw.128B
name|__builtin_HEXAGON_V6_vaddw_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddw.dv.128B
name|__builtin_HEXAGON_V6_vaddw_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddw.dv
name|__builtin_HEXAGON_V6_vaddwnq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwnq.128B
name|__builtin_HEXAGON_V6_vaddwnq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwnq
name|__builtin_HEXAGON_V6_vaddwq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwq.128B
name|__builtin_HEXAGON_V6_vaddwq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwq
name|__builtin_HEXAGON_V6_vaddwsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwsat.128B
name|__builtin_HEXAGON_V6_vaddwsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwsat.dv.128B
name|__builtin_HEXAGON_V6_vaddwsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwsat.dv
name|__builtin_HEXAGON_V6_vaddwsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddwsat
name|__builtin_HEXAGON_V6_vaddw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaddw
name|__builtin_HEXAGON_V6_valignb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.valignb.128B
name|__builtin_HEXAGON_V6_valignbi_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.valignbi.128B
name|__builtin_HEXAGON_V6_valignbi
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.valignbi
name|__builtin_HEXAGON_V6_valignb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.valignb
name|__builtin_HEXAGON_V6_vand_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vand.128B
name|__builtin_HEXAGON_V6_vandqrt_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandqrt.128B
name|__builtin_HEXAGON_V6_vandqrt_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandqrt.acc.128B
name|__builtin_HEXAGON_V6_vandqrt_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandqrt.acc
name|__builtin_HEXAGON_V6_vandqrt
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandqrt
name|__builtin_HEXAGON_V6_vand
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vand
name|__builtin_HEXAGON_V6_vandvrt_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandvrt.128B
name|__builtin_HEXAGON_V6_vandvrt_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandvrt.acc.128B
name|__builtin_HEXAGON_V6_vandvrt_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandvrt.acc
name|__builtin_HEXAGON_V6_vandvrt
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vandvrt
name|__builtin_HEXAGON_V6_vaslh_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslh.128B
name|__builtin_HEXAGON_V6_vaslhv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslhv.128B
name|__builtin_HEXAGON_V6_vaslh
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslh
name|__builtin_HEXAGON_V6_vaslhv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslhv
name|__builtin_HEXAGON_V6_vaslw_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslw.128B
name|__builtin_HEXAGON_V6_vaslw_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslw.acc.128B
name|__builtin_HEXAGON_V6_vaslw_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslw.acc
name|__builtin_HEXAGON_V6_vaslwv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslwv.128B
name|__builtin_HEXAGON_V6_vaslw
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslw
name|__builtin_HEXAGON_V6_vaslwv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vaslwv
name|__builtin_HEXAGON_V6_vasrh_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrh.128B
name|__builtin_HEXAGON_V6_vasrhbrndsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhbrndsat.128B
name|__builtin_HEXAGON_V6_vasrhbrndsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhbrndsat
name|__builtin_HEXAGON_V6_vasrhubrndsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhubrndsat.128B
name|__builtin_HEXAGON_V6_vasrhubrndsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhubrndsat
name|__builtin_HEXAGON_V6_vasrhubsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhubsat.128B
name|__builtin_HEXAGON_V6_vasrhubsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhubsat
name|__builtin_HEXAGON_V6_vasrhv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhv.128B
name|__builtin_HEXAGON_V6_vasrh
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrh
name|__builtin_HEXAGON_V6_vasrhv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrhv
name|__builtin_HEXAGON_V6_vasrw_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrw.128B
name|__builtin_HEXAGON_V6_vasrw_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrw.acc.128B
name|__builtin_HEXAGON_V6_vasrw_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrw.acc
name|__builtin_HEXAGON_V6_vasrwh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwh.128B
name|__builtin_HEXAGON_V6_vasrwhrndsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwhrndsat.128B
name|__builtin_HEXAGON_V6_vasrwhrndsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwhrndsat
name|__builtin_HEXAGON_V6_vasrwhsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwhsat.128B
name|__builtin_HEXAGON_V6_vasrwhsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwhsat
name|__builtin_HEXAGON_V6_vasrwh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwh
name|__builtin_HEXAGON_V6_vasrwuhsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwuhsat.128B
name|__builtin_HEXAGON_V6_vasrwuhsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwuhsat
name|__builtin_HEXAGON_V6_vasrwv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwv.128B
name|__builtin_HEXAGON_V6_vasrw
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrw
name|__builtin_HEXAGON_V6_vasrwv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vasrwv
name|__builtin_HEXAGON_V6_vassign_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vassign.128B
name|__builtin_HEXAGON_V6_vassignp_128B
argument_list|(
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vassignp.128B
name|__builtin_HEXAGON_V6_vassignp
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vassignp
name|__builtin_HEXAGON_V6_vassign
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vassign
name|__builtin_HEXAGON_V6_vavgh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgh.128B
name|__builtin_HEXAGON_V6_vavghrnd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavghrnd.128B
name|__builtin_HEXAGON_V6_vavghrnd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavghrnd
name|__builtin_HEXAGON_V6_vavgh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgh
name|__builtin_HEXAGON_V6_vavgub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgub.128B
name|__builtin_HEXAGON_V6_vavgubrnd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgubrnd.128B
name|__builtin_HEXAGON_V6_vavgubrnd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgubrnd
name|__builtin_HEXAGON_V6_vavgub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgub
name|__builtin_HEXAGON_V6_vavguh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavguh.128B
name|__builtin_HEXAGON_V6_vavguhrnd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavguhrnd.128B
name|__builtin_HEXAGON_V6_vavguhrnd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavguhrnd
name|__builtin_HEXAGON_V6_vavguh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavguh
name|__builtin_HEXAGON_V6_vavgw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgw.128B
name|__builtin_HEXAGON_V6_vavgwrnd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgwrnd.128B
name|__builtin_HEXAGON_V6_vavgwrnd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgwrnd
name|__builtin_HEXAGON_V6_vavgw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vavgw
name|__builtin_HEXAGON_V6_vcl0h_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vcl0h.128B
name|__builtin_HEXAGON_V6_vcl0h
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vcl0h
name|__builtin_HEXAGON_V6_vcl0w_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vcl0w.128B
name|__builtin_HEXAGON_V6_vcl0w
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vcl0w
name|__builtin_HEXAGON_V6_vcombine_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vcombine.128B
name|__builtin_HEXAGON_V6_vcombine
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vcombine
name|__builtin_HEXAGON_V6_vd0_128B
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vd0.128B
name|__builtin_HEXAGON_V6_vd0
argument_list|()
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vd0
name|__builtin_HEXAGON_V6_vdealb_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealb.128B
name|__builtin_HEXAGON_V6_vdealb4w_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealb4w.128B
name|__builtin_HEXAGON_V6_vdealb4w
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealb4w
name|__builtin_HEXAGON_V6_vdealb
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealb
name|__builtin_HEXAGON_V6_vdealh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealh.128B
name|__builtin_HEXAGON_V6_vdealh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealh
name|__builtin_HEXAGON_V6_vdealvdd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealvdd.128B
name|__builtin_HEXAGON_V6_vdealvdd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdealvdd
name|__builtin_HEXAGON_V6_vdelta_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdelta.128B
name|__builtin_HEXAGON_V6_vdelta
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdelta
name|__builtin_HEXAGON_V6_vdmpybus_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.128B
name|__builtin_HEXAGON_V6_vdmpybus_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.acc.128B
name|__builtin_HEXAGON_V6_vdmpybus_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.acc
name|__builtin_HEXAGON_V6_vdmpybus_dv_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.dv.128B
name|__builtin_HEXAGON_V6_vdmpybus_dv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.dv.acc.128B
name|__builtin_HEXAGON_V6_vdmpybus_dv_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.dv.acc
name|__builtin_HEXAGON_V6_vdmpybus_dv
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus.dv
name|__builtin_HEXAGON_V6_vdmpybus
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpybus
name|__builtin_HEXAGON_V6_vdmpyhb_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.128B
name|__builtin_HEXAGON_V6_vdmpyhb_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhb_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.acc
name|__builtin_HEXAGON_V6_vdmpyhb_dv_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.dv.128B
name|__builtin_HEXAGON_V6_vdmpyhb_dv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.dv.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhb_dv_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.dv.acc
name|__builtin_HEXAGON_V6_vdmpyhb_dv
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb.dv
name|__builtin_HEXAGON_V6_vdmpyhb
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhb
name|__builtin_HEXAGON_V6_vdmpyhisat_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhisat.128B
name|__builtin_HEXAGON_V6_vdmpyhisat_acc_128B
argument_list|(
name|v32
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhisat.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhisat_acc
argument_list|(
name|v16
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhisat.acc
name|__builtin_HEXAGON_V6_vdmpyhisat
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhisat
name|__builtin_HEXAGON_V6_vdmpyhsat_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsat.128B
name|__builtin_HEXAGON_V6_vdmpyhsat_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsat.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhsat_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsat.acc
name|__builtin_HEXAGON_V6_vdmpyhsat
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsat
name|__builtin_HEXAGON_V6_vdmpyhsuisat_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsuisat.128B
name|__builtin_HEXAGON_V6_vdmpyhsuisat_acc_128B
argument_list|(
name|v32
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsuisat.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhsuisat_acc
argument_list|(
name|v16
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsuisat.acc
name|__builtin_HEXAGON_V6_vdmpyhsuisat
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsuisat
name|__builtin_HEXAGON_V6_vdmpyhsusat_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsusat.128B
name|__builtin_HEXAGON_V6_vdmpyhsusat_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsusat.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhsusat_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsusat.acc
name|__builtin_HEXAGON_V6_vdmpyhsusat
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhsusat
name|__builtin_HEXAGON_V6_vdmpyhvsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhvsat.128B
name|__builtin_HEXAGON_V6_vdmpyhvsat_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhvsat.acc.128B
name|__builtin_HEXAGON_V6_vdmpyhvsat_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhvsat.acc
name|__builtin_HEXAGON_V6_vdmpyhvsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdmpyhvsat
name|__builtin_HEXAGON_V6_vdsaduh_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdsaduh.128B
name|__builtin_HEXAGON_V6_vdsaduh_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdsaduh.acc.128B
name|__builtin_HEXAGON_V6_vdsaduh_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdsaduh.acc
name|__builtin_HEXAGON_V6_vdsaduh
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vdsaduh
name|__builtin_HEXAGON_V6_veqb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.128B
name|__builtin_HEXAGON_V6_veqb_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.and.128B
name|__builtin_HEXAGON_V6_veqb_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.and
name|__builtin_HEXAGON_V6_veqb_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.or.128B
name|__builtin_HEXAGON_V6_veqb_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.or
name|__builtin_HEXAGON_V6_veqb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb
name|__builtin_HEXAGON_V6_veqb_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.xor.128B
name|__builtin_HEXAGON_V6_veqb_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqb.xor
name|__builtin_HEXAGON_V6_veqh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.128B
name|__builtin_HEXAGON_V6_veqh_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.and.128B
name|__builtin_HEXAGON_V6_veqh_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.and
name|__builtin_HEXAGON_V6_veqh_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.or.128B
name|__builtin_HEXAGON_V6_veqh_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.or
name|__builtin_HEXAGON_V6_veqh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh
name|__builtin_HEXAGON_V6_veqh_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.xor.128B
name|__builtin_HEXAGON_V6_veqh_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqh.xor
name|__builtin_HEXAGON_V6_veqw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.128B
name|__builtin_HEXAGON_V6_veqw_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.and.128B
name|__builtin_HEXAGON_V6_veqw_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.and
name|__builtin_HEXAGON_V6_veqw_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.or.128B
name|__builtin_HEXAGON_V6_veqw_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.or
name|__builtin_HEXAGON_V6_veqw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw
name|__builtin_HEXAGON_V6_veqw_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.xor.128B
name|__builtin_HEXAGON_V6_veqw_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.veqw.xor
name|__builtin_HEXAGON_V6_vgtb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.128B
name|__builtin_HEXAGON_V6_vgtb_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.and.128B
name|__builtin_HEXAGON_V6_vgtb_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.and
name|__builtin_HEXAGON_V6_vgtb_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.or.128B
name|__builtin_HEXAGON_V6_vgtb_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.or
name|__builtin_HEXAGON_V6_vgtb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb
name|__builtin_HEXAGON_V6_vgtb_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.xor.128B
name|__builtin_HEXAGON_V6_vgtb_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtb.xor
name|__builtin_HEXAGON_V6_vgth_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.128B
name|__builtin_HEXAGON_V6_vgth_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.and.128B
name|__builtin_HEXAGON_V6_vgth_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.and
name|__builtin_HEXAGON_V6_vgth_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.or.128B
name|__builtin_HEXAGON_V6_vgth_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.or
name|__builtin_HEXAGON_V6_vgth
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth
name|__builtin_HEXAGON_V6_vgth_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.xor.128B
name|__builtin_HEXAGON_V6_vgth_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgth.xor
name|__builtin_HEXAGON_V6_vgtub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.128B
name|__builtin_HEXAGON_V6_vgtub_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.and.128B
name|__builtin_HEXAGON_V6_vgtub_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.and
name|__builtin_HEXAGON_V6_vgtub_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.or.128B
name|__builtin_HEXAGON_V6_vgtub_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.or
name|__builtin_HEXAGON_V6_vgtub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub
name|__builtin_HEXAGON_V6_vgtub_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.xor.128B
name|__builtin_HEXAGON_V6_vgtub_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtub.xor
name|__builtin_HEXAGON_V6_vgtuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.128B
name|__builtin_HEXAGON_V6_vgtuh_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.and.128B
name|__builtin_HEXAGON_V6_vgtuh_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.and
name|__builtin_HEXAGON_V6_vgtuh_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.or.128B
name|__builtin_HEXAGON_V6_vgtuh_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.or
name|__builtin_HEXAGON_V6_vgtuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh
name|__builtin_HEXAGON_V6_vgtuh_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.xor.128B
name|__builtin_HEXAGON_V6_vgtuh_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuh.xor
name|__builtin_HEXAGON_V6_vgtuw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.128B
name|__builtin_HEXAGON_V6_vgtuw_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.and.128B
name|__builtin_HEXAGON_V6_vgtuw_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.and
name|__builtin_HEXAGON_V6_vgtuw_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.or.128B
name|__builtin_HEXAGON_V6_vgtuw_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.or
name|__builtin_HEXAGON_V6_vgtuw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw
name|__builtin_HEXAGON_V6_vgtuw_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.xor.128B
name|__builtin_HEXAGON_V6_vgtuw_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtuw.xor
name|__builtin_HEXAGON_V6_vgtw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.128B
name|__builtin_HEXAGON_V6_vgtw_and_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.and.128B
name|__builtin_HEXAGON_V6_vgtw_and
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.and
name|__builtin_HEXAGON_V6_vgtw_or_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.or.128B
name|__builtin_HEXAGON_V6_vgtw_or
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.or
name|__builtin_HEXAGON_V6_vgtw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw
name|__builtin_HEXAGON_V6_vgtw_xor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.xor.128B
name|__builtin_HEXAGON_V6_vgtw_xor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vgtw.xor
name|__builtin_HEXAGON_V6_vinsertwr_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vinsertwr.128B
name|__builtin_HEXAGON_V6_vinsertwr
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vinsertwr
name|__builtin_HEXAGON_V6_vlalignb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlalignb.128B
name|__builtin_HEXAGON_V6_vlalignbi_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlalignbi.128B
name|__builtin_HEXAGON_V6_vlalignbi
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlalignbi
name|__builtin_HEXAGON_V6_vlalignb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlalignb
name|__builtin_HEXAGON_V6_vlsrh_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrh.128B
name|__builtin_HEXAGON_V6_vlsrhv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrhv.128B
name|__builtin_HEXAGON_V6_vlsrh
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrh
name|__builtin_HEXAGON_V6_vlsrhv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrhv
name|__builtin_HEXAGON_V6_vlsrw_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrw.128B
name|__builtin_HEXAGON_V6_vlsrwv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrwv.128B
name|__builtin_HEXAGON_V6_vlsrw
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrw
name|__builtin_HEXAGON_V6_vlsrwv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlsrwv
name|__builtin_HEXAGON_V6_vlutb_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.128B
name|__builtin_HEXAGON_V6_vlutb_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.acc.128B
name|__builtin_HEXAGON_V6_vlutb_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.acc
name|__builtin_HEXAGON_V6_vlutb_dv_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.dv.128B
name|__builtin_HEXAGON_V6_vlutb_dv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.dv.acc.128B
name|__builtin_HEXAGON_V6_vlutb_dv_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.dv.acc
name|__builtin_HEXAGON_V6_vlutb_dv
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb.dv
name|__builtin_HEXAGON_V6_vlutb
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutb
name|__builtin_HEXAGON_V6_vlutvvb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvvb.128B
name|__builtin_HEXAGON_V6_vlutvvb_oracc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvvb.oracc.128B
name|__builtin_HEXAGON_V6_vlutvvb_oracc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvvb.oracc
name|__builtin_HEXAGON_V6_vlutvvb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvvb
name|__builtin_HEXAGON_V6_vlutvwh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvwh.128B
name|__builtin_HEXAGON_V6_vlutvwh_oracc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvwh.oracc.128B
name|__builtin_HEXAGON_V6_vlutvwh_oracc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvwh.oracc
name|__builtin_HEXAGON_V6_vlutvwh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vlutvwh
name|__builtin_HEXAGON_V6_vmaxh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxh.128B
name|__builtin_HEXAGON_V6_vmaxh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxh
name|__builtin_HEXAGON_V6_vmaxub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxub.128B
name|__builtin_HEXAGON_V6_vmaxub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxub
name|__builtin_HEXAGON_V6_vmaxuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxuh.128B
name|__builtin_HEXAGON_V6_vmaxuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxuh
name|__builtin_HEXAGON_V6_vmaxw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxw.128B
name|__builtin_HEXAGON_V6_vmaxw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmaxw
name|__builtin_HEXAGON_V6_vminh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminh.128B
name|__builtin_HEXAGON_V6_vminh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminh
name|__builtin_HEXAGON_V6_vminub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminub.128B
name|__builtin_HEXAGON_V6_vminub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminub
name|__builtin_HEXAGON_V6_vminuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminuh.128B
name|__builtin_HEXAGON_V6_vminuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminuh
name|__builtin_HEXAGON_V6_vminw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminw.128B
name|__builtin_HEXAGON_V6_vminw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vminw
name|__builtin_HEXAGON_V6_vmpabus_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabus.128B
name|__builtin_HEXAGON_V6_vmpabus_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabus.acc.128B
name|__builtin_HEXAGON_V6_vmpabus_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabus.acc
name|__builtin_HEXAGON_V6_vmpabusv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabusv.128B
name|__builtin_HEXAGON_V6_vmpabus
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabus
name|__builtin_HEXAGON_V6_vmpabusv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabusv
name|__builtin_HEXAGON_V6_vmpabuuv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabuuv.128B
name|__builtin_HEXAGON_V6_vmpabuuv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpabuuv
name|__builtin_HEXAGON_V6_vmpahb_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpahb.128B
name|__builtin_HEXAGON_V6_vmpahb_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpahb.acc.128B
name|__builtin_HEXAGON_V6_vmpahb_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpahb.acc
name|__builtin_HEXAGON_V6_vmpahb
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpahb
name|__builtin_HEXAGON_V6_vmpybus_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybus.128B
name|__builtin_HEXAGON_V6_vmpybus_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybus.acc.128B
name|__builtin_HEXAGON_V6_vmpybus_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybus.acc
name|__builtin_HEXAGON_V6_vmpybusv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybusv.128B
name|__builtin_HEXAGON_V6_vmpybus
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybus
name|__builtin_HEXAGON_V6_vmpybusv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybusv.acc.128B
name|__builtin_HEXAGON_V6_vmpybusv_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybusv.acc
name|__builtin_HEXAGON_V6_vmpybusv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybusv
name|__builtin_HEXAGON_V6_vmpybv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybv.128B
name|__builtin_HEXAGON_V6_vmpybv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybv.acc.128B
name|__builtin_HEXAGON_V6_vmpybv_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybv.acc
name|__builtin_HEXAGON_V6_vmpybv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpybv
name|__builtin_HEXAGON_V6_vmpyewuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyewuh.128B
name|__builtin_HEXAGON_V6_vmpyewuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyewuh
name|__builtin_HEXAGON_V6_vmpyh_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyh.128B
name|__builtin_HEXAGON_V6_vmpyhsat_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhsat.acc.128B
name|__builtin_HEXAGON_V6_vmpyhsat_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhsat.acc
name|__builtin_HEXAGON_V6_vmpyhsrs_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhsrs.128B
name|__builtin_HEXAGON_V6_vmpyhsrs
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhsrs
name|__builtin_HEXAGON_V6_vmpyhss_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhss.128B
name|__builtin_HEXAGON_V6_vmpyhss
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhss
name|__builtin_HEXAGON_V6_vmpyhus_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhus.128B
name|__builtin_HEXAGON_V6_vmpyhus_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhus.acc.128B
name|__builtin_HEXAGON_V6_vmpyhus_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhus.acc
name|__builtin_HEXAGON_V6_vmpyhus
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhus
name|__builtin_HEXAGON_V6_vmpyhv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhv.128B
name|__builtin_HEXAGON_V6_vmpyh
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyh
name|__builtin_HEXAGON_V6_vmpyhv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhv.acc.128B
name|__builtin_HEXAGON_V6_vmpyhv_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhv.acc
name|__builtin_HEXAGON_V6_vmpyhvsrs_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhvsrs.128B
name|__builtin_HEXAGON_V6_vmpyhvsrs
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhvsrs
name|__builtin_HEXAGON_V6_vmpyhv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyhv
name|__builtin_HEXAGON_V6_vmpyieoh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyieoh.128B
name|__builtin_HEXAGON_V6_vmpyieoh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyieoh
name|__builtin_HEXAGON_V6_vmpyiewh_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiewh.acc.128B
name|__builtin_HEXAGON_V6_vmpyiewh_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiewh.acc
name|__builtin_HEXAGON_V6_vmpyiewuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiewuh.128B
name|__builtin_HEXAGON_V6_vmpyiewuh_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiewuh.acc.128B
name|__builtin_HEXAGON_V6_vmpyiewuh_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiewuh.acc
name|__builtin_HEXAGON_V6_vmpyiewuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiewuh
name|__builtin_HEXAGON_V6_vmpyih_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyih.128B
name|__builtin_HEXAGON_V6_vmpyih_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyih.acc.128B
name|__builtin_HEXAGON_V6_vmpyih_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyih.acc
name|__builtin_HEXAGON_V6_vmpyihb_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyihb.128B
name|__builtin_HEXAGON_V6_vmpyihb_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyihb.acc.128B
name|__builtin_HEXAGON_V6_vmpyihb_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyihb.acc
name|__builtin_HEXAGON_V6_vmpyihb
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyihb
name|__builtin_HEXAGON_V6_vmpyih
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyih
name|__builtin_HEXAGON_V6_vmpyiowh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiowh.128B
name|__builtin_HEXAGON_V6_vmpyiowh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiowh
name|__builtin_HEXAGON_V6_vmpyiwb_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwb.128B
name|__builtin_HEXAGON_V6_vmpyiwb_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwb.acc.128B
name|__builtin_HEXAGON_V6_vmpyiwb_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwb.acc
name|__builtin_HEXAGON_V6_vmpyiwb
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwb
name|__builtin_HEXAGON_V6_vmpyiwh_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwh.128B
name|__builtin_HEXAGON_V6_vmpyiwh_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwh.acc.128B
name|__builtin_HEXAGON_V6_vmpyiwh_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwh.acc
name|__builtin_HEXAGON_V6_vmpyiwh
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyiwh
name|__builtin_HEXAGON_V6_vmpyowh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.128B
name|__builtin_HEXAGON_V6_vmpyowh_rnd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.rnd.128B
name|__builtin_HEXAGON_V6_vmpyowh_rnd_sacc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.rnd.sacc.128B
name|__builtin_HEXAGON_V6_vmpyowh_rnd_sacc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.rnd.sacc
name|__builtin_HEXAGON_V6_vmpyowh_rnd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.rnd
name|__builtin_HEXAGON_V6_vmpyowh_sacc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.sacc.128B
name|__builtin_HEXAGON_V6_vmpyowh_sacc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh.sacc
name|__builtin_HEXAGON_V6_vmpyowh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyowh
name|__builtin_HEXAGON_V6_vmpyub_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyub.128B
name|__builtin_HEXAGON_V6_vmpyub_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyub.acc.128B
name|__builtin_HEXAGON_V6_vmpyub_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyub.acc
name|__builtin_HEXAGON_V6_vmpyubv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyubv.128B
name|__builtin_HEXAGON_V6_vmpyub
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyub
name|__builtin_HEXAGON_V6_vmpyubv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyubv.acc.128B
name|__builtin_HEXAGON_V6_vmpyubv_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyubv.acc
name|__builtin_HEXAGON_V6_vmpyubv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyubv
name|__builtin_HEXAGON_V6_vmpyuh_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuh.128B
name|__builtin_HEXAGON_V6_vmpyuh_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuh.acc.128B
name|__builtin_HEXAGON_V6_vmpyuh_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuh.acc
name|__builtin_HEXAGON_V6_vmpyuhv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuhv.128B
name|__builtin_HEXAGON_V6_vmpyuh
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuh
name|__builtin_HEXAGON_V6_vmpyuhv_acc_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuhv.acc.128B
name|__builtin_HEXAGON_V6_vmpyuhv_acc
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuhv.acc
name|__builtin_HEXAGON_V6_vmpyuhv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmpyuhv
name|__builtin_HEXAGON_V6_vmux_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmux.128B
name|__builtin_HEXAGON_V6_vmux
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vmux
name|__builtin_HEXAGON_V6_vnavgh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnavgh.128B
name|__builtin_HEXAGON_V6_vnavgh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnavgh
name|__builtin_HEXAGON_V6_vnavgub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnavgub.128B
name|__builtin_HEXAGON_V6_vnavgub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnavgub
name|__builtin_HEXAGON_V6_vnavgw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnavgw.128B
name|__builtin_HEXAGON_V6_vnavgw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnavgw
name|__builtin_HEXAGON_V6_vnormamth_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnormamth.128B
name|__builtin_HEXAGON_V6_vnormamth
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnormamth
name|__builtin_HEXAGON_V6_vnormamtw_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnormamtw.128B
name|__builtin_HEXAGON_V6_vnormamtw
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnormamtw
name|__builtin_HEXAGON_V6_vnot_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnot.128B
name|__builtin_HEXAGON_V6_vnot
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vnot
name|__builtin_HEXAGON_V6_vor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vor.128B
name|__builtin_HEXAGON_V6_vor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vor
name|__builtin_HEXAGON_V6_vpackeb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackeb.128B
name|__builtin_HEXAGON_V6_vpackeb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackeb
name|__builtin_HEXAGON_V6_vpackeh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackeh.128B
name|__builtin_HEXAGON_V6_vpackeh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackeh
name|__builtin_HEXAGON_V6_vpackhb_sat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackhb.sat.128B
name|__builtin_HEXAGON_V6_vpackhb_sat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackhb.sat
name|__builtin_HEXAGON_V6_vpackhub_sat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackhub.sat.128B
name|__builtin_HEXAGON_V6_vpackhub_sat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackhub.sat
name|__builtin_HEXAGON_V6_vpackob_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackob.128B
name|__builtin_HEXAGON_V6_vpackob
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackob
name|__builtin_HEXAGON_V6_vpackoh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackoh.128B
name|__builtin_HEXAGON_V6_vpackoh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackoh
name|__builtin_HEXAGON_V6_vpackwh_sat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackwh.sat.128B
name|__builtin_HEXAGON_V6_vpackwh_sat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackwh.sat
name|__builtin_HEXAGON_V6_vpackwuh_sat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackwuh.sat.128B
name|__builtin_HEXAGON_V6_vpackwuh_sat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpackwuh.sat
name|__builtin_HEXAGON_V6_vpopcounth_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpopcounth.128B
name|__builtin_HEXAGON_V6_vpopcounth
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vpopcounth
name|__builtin_HEXAGON_V6_vrdelta_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrdelta.128B
name|__builtin_HEXAGON_V6_vrdelta
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrdelta
name|__builtin_HEXAGON_V6_vrmpybus_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybus.128B
name|__builtin_HEXAGON_V6_vrmpybus_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybus.acc.128B
name|__builtin_HEXAGON_V6_vrmpybus_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybus.acc
name|__builtin_HEXAGON_V6_vrmpybusi_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusi.128B
name|__builtin_HEXAGON_V6_vrmpybusi_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusi.acc.128B
name|__builtin_HEXAGON_V6_vrmpybusi_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusi.acc
name|__builtin_HEXAGON_V6_vrmpybusi
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusi
name|__builtin_HEXAGON_V6_vrmpybusv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusv.128B
name|__builtin_HEXAGON_V6_vrmpybus
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybus
name|__builtin_HEXAGON_V6_vrmpybusv_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusv.acc.128B
name|__builtin_HEXAGON_V6_vrmpybusv_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusv.acc
name|__builtin_HEXAGON_V6_vrmpybusv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybusv
name|__builtin_HEXAGON_V6_vrmpybv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybv.128B
name|__builtin_HEXAGON_V6_vrmpybv_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybv.acc.128B
name|__builtin_HEXAGON_V6_vrmpybv_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybv.acc
name|__builtin_HEXAGON_V6_vrmpybv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpybv
name|__builtin_HEXAGON_V6_vrmpyub_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyub.128B
name|__builtin_HEXAGON_V6_vrmpyub_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyub.acc.128B
name|__builtin_HEXAGON_V6_vrmpyub_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyub.acc
name|__builtin_HEXAGON_V6_vrmpyubi_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubi.128B
name|__builtin_HEXAGON_V6_vrmpyubi_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubi.acc.128B
name|__builtin_HEXAGON_V6_vrmpyubi_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubi.acc
name|__builtin_HEXAGON_V6_vrmpyubi
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubi
name|__builtin_HEXAGON_V6_vrmpyubv_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubv.128B
name|__builtin_HEXAGON_V6_vrmpyub
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyub
name|__builtin_HEXAGON_V6_vrmpyubv_acc_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubv.acc.128B
name|__builtin_HEXAGON_V6_vrmpyubv_acc
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubv.acc
name|__builtin_HEXAGON_V6_vrmpyubv
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrmpyubv
name|__builtin_HEXAGON_V6_vror_128B
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vror.128B
name|__builtin_HEXAGON_V6_vror
argument_list|(
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vror
name|__builtin_HEXAGON_V6_vroundhb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundhb.128B
name|__builtin_HEXAGON_V6_vroundhb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundhb
name|__builtin_HEXAGON_V6_vroundhub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundhub.128B
name|__builtin_HEXAGON_V6_vroundhub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundhub
name|__builtin_HEXAGON_V6_vroundwh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundwh.128B
name|__builtin_HEXAGON_V6_vroundwh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundwh
name|__builtin_HEXAGON_V6_vroundwuh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundwuh.128B
name|__builtin_HEXAGON_V6_vroundwuh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vroundwuh
name|__builtin_HEXAGON_V6_vrsadubi_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrsadubi.128B
name|__builtin_HEXAGON_V6_vrsadubi_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrsadubi.acc.128B
name|__builtin_HEXAGON_V6_vrsadubi_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrsadubi.acc
name|__builtin_HEXAGON_V6_vrsadubi
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vrsadubi
name|__builtin_HEXAGON_V6_vsathub_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsathub.128B
name|__builtin_HEXAGON_V6_vsathub
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsathub
name|__builtin_HEXAGON_V6_vsatwh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsatwh.128B
name|__builtin_HEXAGON_V6_vsatwh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsatwh
name|__builtin_HEXAGON_V6_vsb_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsb.128B
name|__builtin_HEXAGON_V6_vsb
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsb
name|__builtin_HEXAGON_V6_vsh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsh.128B
name|__builtin_HEXAGON_V6_vshufeh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufeh.128B
name|__builtin_HEXAGON_V6_vshufeh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufeh
name|__builtin_HEXAGON_V6_vshuffb_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffb.128B
name|__builtin_HEXAGON_V6_vshuffb
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffb
name|__builtin_HEXAGON_V6_vshuffeb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffeb.128B
name|__builtin_HEXAGON_V6_vshuffeb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffeb
name|__builtin_HEXAGON_V6_vshuffh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffh.128B
name|__builtin_HEXAGON_V6_vshuffh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffh
name|__builtin_HEXAGON_V6_vshuffob_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffob.128B
name|__builtin_HEXAGON_V6_vshuffob
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffob
name|__builtin_HEXAGON_V6_vshuffvdd_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffvdd.128B
name|__builtin_HEXAGON_V6_vshuffvdd
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshuffvdd
name|__builtin_HEXAGON_V6_vshufoeb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufoeb.128B
name|__builtin_HEXAGON_V6_vshufoeb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufoeb
name|__builtin_HEXAGON_V6_vshufoeh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufoeh.128B
name|__builtin_HEXAGON_V6_vshufoeh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufoeh
name|__builtin_HEXAGON_V6_vshufoh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufoh.128B
name|__builtin_HEXAGON_V6_vshufoh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vshufoh
name|__builtin_HEXAGON_V6_vsh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsh
name|__builtin_HEXAGON_V6_vsubb_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubb.128B
name|__builtin_HEXAGON_V6_vsubb_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubb.dv.128B
name|__builtin_HEXAGON_V6_vsubb_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubb.dv
name|__builtin_HEXAGON_V6_vsubbnq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubbnq.128B
name|__builtin_HEXAGON_V6_vsubbnq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubbnq
name|__builtin_HEXAGON_V6_vsubbq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubbq.128B
name|__builtin_HEXAGON_V6_vsubbq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubbq
name|__builtin_HEXAGON_V6_vsubb
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubb
name|__builtin_HEXAGON_V6_vsubh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubh.128B
name|__builtin_HEXAGON_V6_vsubh_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubh.dv.128B
name|__builtin_HEXAGON_V6_vsubh_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubh.dv
name|__builtin_HEXAGON_V6_vsubhnq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhnq.128B
name|__builtin_HEXAGON_V6_vsubhnq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhnq
name|__builtin_HEXAGON_V6_vsubhq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhq.128B
name|__builtin_HEXAGON_V6_vsubhq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhq
name|__builtin_HEXAGON_V6_vsubhsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhsat.128B
name|__builtin_HEXAGON_V6_vsubhsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhsat.dv.128B
name|__builtin_HEXAGON_V6_vsubhsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhsat.dv
name|__builtin_HEXAGON_V6_vsubhsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhsat
name|__builtin_HEXAGON_V6_vsubh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubh
name|__builtin_HEXAGON_V6_vsubhw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhw.128B
name|__builtin_HEXAGON_V6_vsubhw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubhw
name|__builtin_HEXAGON_V6_vsububh_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsububh.128B
name|__builtin_HEXAGON_V6_vsububh
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsububh
name|__builtin_HEXAGON_V6_vsububsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsububsat.128B
name|__builtin_HEXAGON_V6_vsububsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsububsat.dv.128B
name|__builtin_HEXAGON_V6_vsububsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsububsat.dv
name|__builtin_HEXAGON_V6_vsububsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsububsat
name|__builtin_HEXAGON_V6_vsubuhsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubuhsat.128B
name|__builtin_HEXAGON_V6_vsubuhsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubuhsat.dv.128B
name|__builtin_HEXAGON_V6_vsubuhsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubuhsat.dv
name|__builtin_HEXAGON_V6_vsubuhsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubuhsat
name|__builtin_HEXAGON_V6_vsubuhw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubuhw.128B
name|__builtin_HEXAGON_V6_vsubuhw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubuhw
name|__builtin_HEXAGON_V6_vsubw_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubw.128B
name|__builtin_HEXAGON_V6_vsubw_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubw.dv.128B
name|__builtin_HEXAGON_V6_vsubw_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubw.dv
name|__builtin_HEXAGON_V6_vsubwnq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwnq.128B
name|__builtin_HEXAGON_V6_vsubwnq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwnq
name|__builtin_HEXAGON_V6_vsubwq_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwq.128B
name|__builtin_HEXAGON_V6_vsubwq
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwq
name|__builtin_HEXAGON_V6_vsubwsat_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwsat.128B
name|__builtin_HEXAGON_V6_vsubwsat_dv_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwsat.dv.128B
name|__builtin_HEXAGON_V6_vsubwsat_dv
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwsat.dv
name|__builtin_HEXAGON_V6_vsubwsat
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubwsat
name|__builtin_HEXAGON_V6_vsubw
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vsubw
name|__builtin_HEXAGON_V6_vswap_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vswap.128B
name|__builtin_HEXAGON_V6_vswap
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vswap
name|__builtin_HEXAGON_V6_vtmpyb_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyb.128B
name|__builtin_HEXAGON_V6_vtmpyb_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyb.acc.128B
name|__builtin_HEXAGON_V6_vtmpyb_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyb.acc
name|__builtin_HEXAGON_V6_vtmpybus_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpybus.128B
name|__builtin_HEXAGON_V6_vtmpybus_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpybus.acc.128B
name|__builtin_HEXAGON_V6_vtmpybus_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpybus.acc
name|__builtin_HEXAGON_V6_vtmpybus
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpybus
name|__builtin_HEXAGON_V6_vtmpyb
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyb
name|__builtin_HEXAGON_V6_vtmpyhb_128B
argument_list|(
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyhb.128B
name|__builtin_HEXAGON_V6_vtmpyhb_acc_128B
argument_list|(
name|v64
argument_list|,
name|v64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyhb.acc.128B
name|__builtin_HEXAGON_V6_vtmpyhb_acc
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyhb.acc
name|__builtin_HEXAGON_V6_vtmpyhb
argument_list|(
name|v32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vtmpyhb
name|__builtin_HEXAGON_V6_vunpackb_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackb.128B
name|__builtin_HEXAGON_V6_vunpackb
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackb
name|__builtin_HEXAGON_V6_vunpackh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackh.128B
name|__builtin_HEXAGON_V6_vunpackh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackh
name|__builtin_HEXAGON_V6_vunpackob_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackob.128B
name|__builtin_HEXAGON_V6_vunpackob
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackob
name|__builtin_HEXAGON_V6_vunpackoh_128B
argument_list|(
name|v64
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackoh.128B
name|__builtin_HEXAGON_V6_vunpackoh
argument_list|(
name|v32
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackoh
name|__builtin_HEXAGON_V6_vunpackub_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackub.128B
name|__builtin_HEXAGON_V6_vunpackub
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackub
name|__builtin_HEXAGON_V6_vunpackuh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackuh.128B
name|__builtin_HEXAGON_V6_vunpackuh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vunpackuh
name|__builtin_HEXAGON_V6_vxor_128B
argument_list|(
name|v32
argument_list|,
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vxor.128B
name|__builtin_HEXAGON_V6_vxor
argument_list|(
name|v16
argument_list|,
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vxor
name|__builtin_HEXAGON_V6_vzb_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vzb.128B
name|__builtin_HEXAGON_V6_vzb
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vzb
name|__builtin_HEXAGON_V6_vzh_128B
argument_list|(
name|v32
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vzh.128B
name|__builtin_HEXAGON_V6_vzh
argument_list|(
name|v16
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.V6.vzh
name|__builtin_HEXAGON_Y2_dccleana
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.Y2.dccleana
name|__builtin_HEXAGON_Y2_dccleaninva
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.Y2.dccleaninva
name|__builtin_HEXAGON_Y2_dcinva
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.Y2.dcinva
name|__builtin_HEXAGON_Y2_dczeroa
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.Y2.dczeroa
name|__builtin_HEXAGON_Y4_l2fetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.Y4.l2fetch
name|__builtin_HEXAGON_Y5_l2fetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.hexagon.Y5.l2fetch
block|}
end_function

end_unit

