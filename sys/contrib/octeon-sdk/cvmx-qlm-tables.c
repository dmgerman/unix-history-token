begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/cvmx.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-qlm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<cvmx.h>
end_include

begin_include
include|#
directive|include
file|<cvmx-qlm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-qlm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|__cvmx_qlm_jtag_field_t
name|__cvmx_qlm_jtag_field_cn56xx
index|[]
init|=
block|{
block|{
literal|"prbs_error_count"
block|,
literal|267
block|,
literal|220
block|}
block|,
comment|// BIST/PRBS error count (only valid if pbrs_lock asserted)
block|{
literal|"prbs_unlock_count"
block|,
literal|219
block|,
literal|212
block|}
block|,
comment|// BIST/PRBS unlock count (only valid if pbrs_lock asserted)
block|{
literal|"prbs_locked"
block|,
literal|211
block|,
literal|211
block|}
block|,
comment|// BIST/PRBS lock (asserted after QLM achieves lock)
block|{
literal|"reset_prbs"
block|,
literal|210
block|,
literal|210
block|}
block|,
comment|// BIST/PRBS reset (write 0 to reset)
block|{
literal|"run_prbs"
block|,
literal|209
block|,
literal|209
block|}
block|,
comment|// run PRBS test pattern
block|{
literal|"run_bist"
block|,
literal|208
block|,
literal|208
block|}
block|,
comment|// run bist (May only work for PCIe ?)
block|{
literal|"unknown"
block|,
literal|207
block|,
literal|202
block|}
block|,
comment|//
block|{
literal|"biasdrvsel"
block|,
literal|201
block|,
literal|199
block|}
block|,
comment|//   assign biasdrvsel          = fus_cfg_reg[201:199] ^ jtg_cfg_reg[201:199] ^ ((pi_qlm_cfg == 2'h0) ? 3'h4 : (pi_qlm_cfg == 2'h2) ? 3'h7 : 3'h2);
block|{
literal|"biasbuffsel"
block|,
literal|198
block|,
literal|196
block|}
block|,
comment|//   assign biasbuffsel         = fus_cfg_reg[198:196] ^ jtg_cfg_reg[198:196] ^ 3'h4;
block|{
literal|"tcoeff"
block|,
literal|195
block|,
literal|192
block|}
block|,
comment|//   assign tcoeff              = fus_cfg_reg[195:192] ^ jtg_cfg_reg[195:192] ^ (pi_qlm_cfg[1] ? 4'h0 : 4'hc);
block|{
literal|"mb5000"
block|,
literal|181
block|,
literal|181
block|}
block|,
comment|//   assign mb5000              = fus_cfg_reg[181]     ^ jtg_cfg_reg[181]     ^ 1'h0;
block|{
literal|"interpbw"
block|,
literal|180
block|,
literal|176
block|}
block|,
comment|//   assign interpbw            = fus_cfg_reg[180:176] ^ jtg_cfg_reg[180:176] ^ ((qlm_spd == 2'h0) ? 5'h1f : (qlm_spd == 2'h1) ? 5'h10 : 5'h0);
block|{
literal|"mb"
block|,
literal|175
block|,
literal|172
block|}
block|,
comment|//   assign mb                  = fus_cfg_reg[175:172] ^ jtg_cfg_reg[175:172] ^ 4'h0;
block|{
literal|"bwoff"
block|,
literal|171
block|,
literal|160
block|}
block|,
comment|//   assign bwoff               = fus_cfg_reg[171:160] ^ jtg_cfg_reg[171:160] ^ 12'h0;
block|{
literal|"bg_ref_sel"
block|,
literal|153
block|,
literal|153
block|}
block|,
comment|//   assign bg_ref_sel          = fus_cfg_reg[153]     ^ jtg_cfg_reg[153]     ^ 1'h0;
block|{
literal|"div2en"
block|,
literal|152
block|,
literal|152
block|}
block|,
comment|//   assign div2en              = fus_cfg_reg[152]     ^ jtg_cfg_reg[152]     ^ 1'h0;
block|{
literal|"trimen"
block|,
literal|151
block|,
literal|150
block|}
block|,
comment|//   assign trimen              = fus_cfg_reg[151:150] ^ jtg_cfg_reg[151:150] ^ 2'h0;
block|{
literal|"clkr"
block|,
literal|149
block|,
literal|144
block|}
block|,
comment|//   assign clkr                = fus_cfg_reg[149:144] ^ jtg_cfg_reg[149:144] ^ 6'h0;
block|{
literal|"clkf"
block|,
literal|143
block|,
literal|132
block|}
block|,
comment|//   assign clkf                = fus_cfg_reg[143:132] ^ jtg_cfg_reg[143:132] ^ 12'h18;
block|{
literal|"bwadj"
block|,
literal|131
block|,
literal|120
block|}
block|,
comment|//   assign bwadj               = fus_cfg_reg[131:120] ^ jtg_cfg_reg[131:120] ^ 12'h30;
block|{
literal|"shlpbck"
block|,
literal|119
block|,
literal|118
block|}
block|,
comment|//   assign shlpbck             = fus_cfg_reg[119:118] ^ jtg_cfg_reg[119:118] ^ 2'h0;
block|{
literal|"serdes_pll_byp"
block|,
literal|117
block|,
literal|117
block|}
block|,
comment|//   assign serdes_pll_byp      = fus_cfg_reg[117]     ^ jtg_cfg_reg[117]     ^ 1'h0;
block|{
literal|"ic50dac"
block|,
literal|116
block|,
literal|112
block|}
block|,
comment|//   assign ic50dac             = fus_cfg_reg[116:112] ^ jtg_cfg_reg[116:112] ^ 5'h11;
block|{
literal|"sl_posedge_sample"
block|,
literal|111
block|,
literal|111
block|}
block|,
comment|//   assign sl_posedge_sample   = fus_cfg_reg[111]     ^ jtg_cfg_reg[111]     ^ 1'h0;
block|{
literal|"sl_enable"
block|,
literal|110
block|,
literal|110
block|}
block|,
comment|//   assign sl_enable           = fus_cfg_reg[110]     ^ jtg_cfg_reg[110]     ^ 1'h0;
block|{
literal|"rx_rout_comp_bypass"
block|,
literal|109
block|,
literal|109
block|}
block|,
comment|//   assign rx_rout_comp_bypass = fus_cfg_reg[109]     ^ jtg_cfg_reg[109]     ^ 1'h0;
block|{
literal|"ir50dac"
block|,
literal|108
block|,
literal|104
block|}
block|,
comment|//   assign ir50dac             = fus_cfg_reg[108:104] ^ jtg_cfg_reg[108:104] ^ 5'h11;
block|{
literal|"rx_res_offset"
block|,
literal|103
block|,
literal|100
block|}
block|,
comment|//   assign rx_res_offset       = fus_cfg_reg[103:100] ^ jtg_cfg_reg[103:100] ^ 4'h2;
block|{
literal|"rx_rout_comp_value"
block|,
literal|99
block|,
literal|96
block|}
block|,
comment|//   assign rx_rout_comp_value  = fus_cfg_reg[99:96]   ^ jtg_cfg_reg[99:96]   ^ 4'h7;
block|{
literal|"tx_rout_comp_value"
block|,
literal|95
block|,
literal|92
block|}
block|,
comment|//   assign tx_rout_comp_value  = fus_cfg_reg[95:92]   ^ jtg_cfg_reg[95:92]   ^ 4'h7;
block|{
literal|"tx_res_offset"
block|,
literal|91
block|,
literal|88
block|}
block|,
comment|//   assign tx_res_offset       = fus_cfg_reg[91:88]   ^ jtg_cfg_reg[91:88]   ^ 4'h1;
block|{
literal|"tx_rout_comp_bypass"
block|,
literal|87
block|,
literal|87
block|}
block|,
comment|//   assign tx_rout_comp_bypass = fus_cfg_reg[87]      ^ jtg_cfg_reg[87]      ^ 1'h0;
block|{
literal|"idle_dac"
block|,
literal|86
block|,
literal|84
block|}
block|,
comment|//   assign idle_dac            = fus_cfg_reg[86:84]   ^ jtg_cfg_reg[86:84]   ^ 3'h4;
block|{
literal|"hyst_en"
block|,
literal|83
block|,
literal|83
block|}
block|,
comment|//   assign hyst_en             = fus_cfg_reg[83]      ^ jtg_cfg_reg[83]      ^ 1'h1;
block|{
literal|"rndt"
block|,
literal|82
block|,
literal|82
block|}
block|,
comment|//   assign rndt                = fus_cfg_reg[82]      ^ jtg_cfg_reg[82]      ^ 1'h0;
block|{
literal|"cfg_tx_com"
block|,
literal|79
block|,
literal|79
block|}
block|,
comment|//   CN52XX cfg_tx_com     = fus_cfg_reg[79] ^ jtg_cfg_reg[79] ^ 1'h0;
block|{
literal|"cfg_cdr_errcor"
block|,
literal|78
block|,
literal|78
block|}
block|,
comment|//   CN52XX cfg_cdr_errcor = fus_cfg_reg[78] ^ jtg_cfg_reg[78] ^ 1'h0;
block|{
literal|"cfg_cdr_secord"
block|,
literal|77
block|,
literal|77
block|}
block|,
comment|//   CN52XX cfg_cdr_secord = fus_cfg_reg[77] ^ jtg_cfg_reg[77] ^ 1'h1;
block|{
literal|"cfg_cdr_rotate"
block|,
literal|76
block|,
literal|76
block|}
block|,
comment|//   assign cfg_cdr_rotate      = fus_cfg_reg[76]      ^ jtg_cfg_reg[76]      ^ 1'h0;
block|{
literal|"cfg_cdr_rqoffs"
block|,
literal|75
block|,
literal|68
block|}
block|,
comment|//   assign cfg_cdr_rqoffs      = fus_cfg_reg[75:68]   ^ jtg_cfg_reg[75:68]   ^ 8'h40;
block|{
literal|"cfg_cdr_incx"
block|,
literal|67
block|,
literal|64
block|}
block|,
comment|//   assign cfg_cdr_incx        = fus_cfg_reg[67:64]   ^ jtg_cfg_reg[67:64]   ^ 4'h2;
block|{
literal|"cfg_cdr_state"
block|,
literal|63
block|,
literal|56
block|}
block|,
comment|//   assign cfg_cdr_state       = fus_cfg_reg[63:56]   ^ jtg_cfg_reg[63:56]   ^ 8'h0;
block|{
literal|"cfg_cdr_bypass"
block|,
literal|55
block|,
literal|55
block|}
block|,
comment|//   assign cfg_cdr_bypass      = fus_cfg_reg[55]      ^ jtg_cfg_reg[55]      ^ 1'h0;
block|{
literal|"cfg_tx_byp"
block|,
literal|54
block|,
literal|54
block|}
block|,
comment|//   assign cfg_tx_byp          = fus_cfg_reg[54]      ^ jtg_cfg_reg[54]      ^ 1'h0;
block|{
literal|"cfg_tx_val"
block|,
literal|53
block|,
literal|44
block|}
block|,
comment|//   assign cfg_tx_val          = fus_cfg_reg[53:44]   ^ jtg_cfg_reg[53:44]   ^ 10'h0;
block|{
literal|"cfg_rx_pol_set"
block|,
literal|43
block|,
literal|43
block|}
block|,
comment|//   assign cfg_rx_pol_set      = fus_cfg_reg[43]      ^ jtg_cfg_reg[43]      ^ 1'h0;
block|{
literal|"cfg_rx_pol_clr"
block|,
literal|42
block|,
literal|42
block|}
block|,
comment|//   assign cfg_rx_pol_clr      = fus_cfg_reg[42]      ^ jtg_cfg_reg[42]      ^ 1'h0;
block|{
literal|"cfg_cdr_bw_ctl"
block|,
literal|41
block|,
literal|40
block|}
block|,
comment|//   assign cfg_cdr_bw_ctl      = fus_cfg_reg[41:40]   ^ jtg_cfg_reg[41:40]   ^ 2'h0;
block|{
literal|"cfg_rst_n_set"
block|,
literal|39
block|,
literal|39
block|}
block|,
comment|//   assign cfg_rst_n_set       = fus_cfg_reg[39]      ^ jtg_cfg_reg[39]      ^ 1'h0;
block|{
literal|"cfg_rst_n_clr"
block|,
literal|38
block|,
literal|38
block|}
block|,
comment|//   assign cfg_rst_n_clr       = fus_cfg_reg[38]      ^ jtg_cfg_reg[38]      ^ 1'h0;
block|{
literal|"cfg_tx_clk2"
block|,
literal|37
block|,
literal|37
block|}
block|,
comment|//   assign cfg_tx_clk2         = fus_cfg_reg[37]      ^ jtg_cfg_reg[37]      ^ 1'h0;
block|{
literal|"cfg_tx_clk1"
block|,
literal|36
block|,
literal|36
block|}
block|,
comment|//   assign cfg_tx_clk1         = fus_cfg_reg[36]      ^ jtg_cfg_reg[36]      ^ 1'h0;
block|{
literal|"cfg_tx_pol_set"
block|,
literal|35
block|,
literal|35
block|}
block|,
comment|//   assign cfg_tx_pol_set      = fus_cfg_reg[35]      ^ jtg_cfg_reg[35]      ^ 1'h0;
block|{
literal|"cfg_tx_pol_clr"
block|,
literal|34
block|,
literal|34
block|}
block|,
comment|//   assign cfg_tx_pol_clr      = fus_cfg_reg[34]      ^ jtg_cfg_reg[34]      ^ 1'h0;
block|{
literal|"cfg_tx_one"
block|,
literal|33
block|,
literal|33
block|}
block|,
comment|//   assign cfg_tx_one          = fus_cfg_reg[33]      ^ jtg_cfg_reg[33]      ^ 1'h0;
block|{
literal|"cfg_tx_zero"
block|,
literal|32
block|,
literal|32
block|}
block|,
comment|//   assign cfg_tx_zero         = fus_cfg_reg[32]      ^ jtg_cfg_reg[32]      ^ 1'h0;
block|{
literal|"cfg_rxd_wait"
block|,
literal|31
block|,
literal|28
block|}
block|,
comment|//   assign cfg_rxd_wait        = fus_cfg_reg[31:28]   ^ jtg_cfg_reg[31:28]   ^ 4'h3;
block|{
literal|"cfg_rxd_short"
block|,
literal|27
block|,
literal|27
block|}
block|,
comment|//   assign cfg_rxd_short       = fus_cfg_reg[27]      ^ jtg_cfg_reg[27]      ^ 1'h0;
block|{
literal|"cfg_rxd_set"
block|,
literal|26
block|,
literal|26
block|}
block|,
comment|//   assign cfg_rxd_set         = fus_cfg_reg[26]      ^ jtg_cfg_reg[26]      ^ 1'h0;
block|{
literal|"cfg_rxd_clr"
block|,
literal|25
block|,
literal|25
block|}
block|,
comment|//   assign cfg_rxd_clr         = fus_cfg_reg[25]      ^ jtg_cfg_reg[25]      ^ 1'h0;
block|{
literal|"cfg_loopback"
block|,
literal|24
block|,
literal|24
block|}
block|,
comment|//   assign cfg_loopback        = fus_cfg_reg[24]      ^ jtg_cfg_reg[24]      ^ 1'h0;
block|{
literal|"cfg_tx_idle_set"
block|,
literal|23
block|,
literal|23
block|}
block|,
comment|//   assign cfg_tx_idle_set     = fus_cfg_reg[23]      ^ jtg_cfg_reg[23]      ^ 1'h0;
block|{
literal|"cfg_tx_idle_clr"
block|,
literal|22
block|,
literal|22
block|}
block|,
comment|//   assign cfg_tx_idle_clr     = fus_cfg_reg[22]      ^ jtg_cfg_reg[22]      ^ 1'h0;
block|{
literal|"cfg_rx_idle_set"
block|,
literal|21
block|,
literal|21
block|}
block|,
comment|//   assign cfg_rx_idle_set     = fus_cfg_reg[21]      ^ jtg_cfg_reg[21]      ^ 1'h0;
block|{
literal|"cfg_rx_idle_clr"
block|,
literal|20
block|,
literal|20
block|}
block|,
comment|//   assign cfg_rx_idle_clr     = fus_cfg_reg[20]      ^ jtg_cfg_reg[20]      ^ 1'h0;
block|{
literal|"cfg_rx_idle_thr"
block|,
literal|19
block|,
literal|16
block|}
block|,
comment|//   assign cfg_rx_idle_thr     = fus_cfg_reg[19:16]   ^ jtg_cfg_reg[19:16]   ^ 4'h0;
block|{
literal|"cfg_com_thr"
block|,
literal|15
block|,
literal|12
block|}
block|,
comment|//   assign cfg_com_thr         = fus_cfg_reg[15:12]   ^ jtg_cfg_reg[15:12]   ^ 4'h3;
block|{
literal|"cfg_rx_offset"
block|,
literal|11
block|,
literal|8
block|}
block|,
comment|//   assign cfg_rx_offset       = fus_cfg_reg[11:8]    ^ jtg_cfg_reg[11:8]    ^ 4'h4;
block|{
literal|"cfg_skp_max"
block|,
literal|7
block|,
literal|4
block|}
block|,
comment|//   assign cfg_skp_max         = fus_cfg_reg[7:4]     ^ jtg_cfg_reg[7:4]     ^ 4'hc;
block|{
literal|"cfg_skp_min"
block|,
literal|3
block|,
literal|0
block|}
block|,
comment|//   assign cfg_skp_min         = fus_cfg_reg[3:0]     ^ jtg_cfg_reg[3:0]     ^ 4'h4;
block|{
name|NULL
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|__cvmx_qlm_jtag_field_t
name|__cvmx_qlm_jtag_field_cn52xx
index|[]
init|=
block|{
block|{
literal|"prbs_error_count"
block|,
literal|267
block|,
literal|220
block|}
block|,
comment|// BIST/PRBS error count (only valid if pbrs_lock asserted)
block|{
literal|"prbs_unlock_count"
block|,
literal|219
block|,
literal|212
block|}
block|,
comment|// BIST/PRBS unlock count (only valid if pbrs_lock asserted)
block|{
literal|"prbs_locked"
block|,
literal|211
block|,
literal|211
block|}
block|,
comment|// BIST/PRBS lock (asserted after QLM achieves lock)
block|{
literal|"reset_prbs"
block|,
literal|210
block|,
literal|210
block|}
block|,
comment|// BIST/PRBS reset (write 0 to reset)
block|{
literal|"run_prbs"
block|,
literal|209
block|,
literal|209
block|}
block|,
comment|// run PRBS test pattern
block|{
literal|"run_bist"
block|,
literal|208
block|,
literal|208
block|}
block|,
comment|// run bist (May only work for PCIe ?)
block|{
literal|"unknown"
block|,
literal|207
block|,
literal|202
block|}
block|,
comment|//
block|{
literal|"biasdrvsel"
block|,
literal|201
block|,
literal|199
block|}
block|,
comment|//   assign biasdrvsel          = fus_cfg_reg[201:199] ^ jtg_cfg_reg[201:199] ^ ((pi_qlm_cfg == 2'h0) ? 3'h4 : (pi_qlm_cfg == 2'h2) ? 3'h7 : 3'h2);
block|{
literal|"biasbuffsel"
block|,
literal|198
block|,
literal|196
block|}
block|,
comment|//   assign biasbuffsel         = fus_cfg_reg[198:196] ^ jtg_cfg_reg[198:196] ^ 3'h4;
block|{
literal|"tcoeff"
block|,
literal|195
block|,
literal|192
block|}
block|,
comment|//   assign tcoeff              = fus_cfg_reg[195:192] ^ jtg_cfg_reg[195:192] ^ (pi_qlm_cfg[1] ? 4'h0 : 4'hc);
block|{
literal|"mb5000"
block|,
literal|181
block|,
literal|181
block|}
block|,
comment|//   assign mb5000              = fus_cfg_reg[181]     ^ jtg_cfg_reg[181]     ^ 1'h0;
block|{
literal|"interpbw"
block|,
literal|180
block|,
literal|176
block|}
block|,
comment|//   assign interpbw            = fus_cfg_reg[180:176] ^ jtg_cfg_reg[180:176] ^ ((qlm_spd == 2'h0) ? 5'h1f : (qlm_spd == 2'h1) ? 5'h10 : 5'h0);
block|{
literal|"mb"
block|,
literal|175
block|,
literal|172
block|}
block|,
comment|//   assign mb                  = fus_cfg_reg[175:172] ^ jtg_cfg_reg[175:172] ^ 4'h0;
block|{
literal|"bwoff"
block|,
literal|171
block|,
literal|160
block|}
block|,
comment|//   assign bwoff               = fus_cfg_reg[171:160] ^ jtg_cfg_reg[171:160] ^ 12'h0;
block|{
literal|"bg_ref_sel"
block|,
literal|153
block|,
literal|153
block|}
block|,
comment|//   assign bg_ref_sel          = fus_cfg_reg[153]     ^ jtg_cfg_reg[153]     ^ 1'h0;
block|{
literal|"div2en"
block|,
literal|152
block|,
literal|152
block|}
block|,
comment|//   assign div2en              = fus_cfg_reg[152]     ^ jtg_cfg_reg[152]     ^ 1'h0;
block|{
literal|"trimen"
block|,
literal|151
block|,
literal|150
block|}
block|,
comment|//   assign trimen              = fus_cfg_reg[151:150] ^ jtg_cfg_reg[151:150] ^ 2'h0;
block|{
literal|"clkr"
block|,
literal|149
block|,
literal|144
block|}
block|,
comment|//   assign clkr                = fus_cfg_reg[149:144] ^ jtg_cfg_reg[149:144] ^ 6'h0;
block|{
literal|"clkf"
block|,
literal|143
block|,
literal|132
block|}
block|,
comment|//   assign clkf                = fus_cfg_reg[143:132] ^ jtg_cfg_reg[143:132] ^ 12'h18;
block|{
literal|"bwadj"
block|,
literal|131
block|,
literal|120
block|}
block|,
comment|//   assign bwadj               = fus_cfg_reg[131:120] ^ jtg_cfg_reg[131:120] ^ 12'h30;
block|{
literal|"shlpbck"
block|,
literal|119
block|,
literal|118
block|}
block|,
comment|//   assign shlpbck             = fus_cfg_reg[119:118] ^ jtg_cfg_reg[119:118] ^ 2'h0;
block|{
literal|"serdes_pll_byp"
block|,
literal|117
block|,
literal|117
block|}
block|,
comment|//   assign serdes_pll_byp      = fus_cfg_reg[117]     ^ jtg_cfg_reg[117]     ^ 1'h0;
block|{
literal|"ic50dac"
block|,
literal|116
block|,
literal|112
block|}
block|,
comment|//   assign ic50dac             = fus_cfg_reg[116:112] ^ jtg_cfg_reg[116:112] ^ 5'h11;
block|{
literal|"sl_posedge_sample"
block|,
literal|111
block|,
literal|111
block|}
block|,
comment|//   assign sl_posedge_sample   = fus_cfg_reg[111]     ^ jtg_cfg_reg[111]     ^ 1'h0;
block|{
literal|"sl_enable"
block|,
literal|110
block|,
literal|110
block|}
block|,
comment|//   assign sl_enable           = fus_cfg_reg[110]     ^ jtg_cfg_reg[110]     ^ 1'h0;
block|{
literal|"rx_rout_comp_bypass"
block|,
literal|109
block|,
literal|109
block|}
block|,
comment|//   assign rx_rout_comp_bypass = fus_cfg_reg[109]     ^ jtg_cfg_reg[109]     ^ 1'h0;
block|{
literal|"ir50dac"
block|,
literal|108
block|,
literal|104
block|}
block|,
comment|//   assign ir50dac             = fus_cfg_reg[108:104] ^ jtg_cfg_reg[108:104] ^ 5'h11;
block|{
literal|"rx_res_offset"
block|,
literal|103
block|,
literal|100
block|}
block|,
comment|//   assign rx_res_offset       = fus_cfg_reg[103:100] ^ jtg_cfg_reg[103:100] ^ 4'h2;
block|{
literal|"rx_rout_comp_value"
block|,
literal|99
block|,
literal|96
block|}
block|,
comment|//   assign rx_rout_comp_value  = fus_cfg_reg[99:96]   ^ jtg_cfg_reg[99:96]   ^ 4'h7;
block|{
literal|"tx_rout_comp_value"
block|,
literal|95
block|,
literal|92
block|}
block|,
comment|//   assign tx_rout_comp_value  = fus_cfg_reg[95:92]   ^ jtg_cfg_reg[95:92]   ^ 4'h7;
block|{
literal|"tx_res_offset"
block|,
literal|91
block|,
literal|88
block|}
block|,
comment|//   assign tx_res_offset       = fus_cfg_reg[91:88]   ^ jtg_cfg_reg[91:88]   ^ 4'h1;
block|{
literal|"tx_rout_comp_bypass"
block|,
literal|87
block|,
literal|87
block|}
block|,
comment|//   assign tx_rout_comp_bypass = fus_cfg_reg[87]      ^ jtg_cfg_reg[87]      ^ 1'h0;
block|{
literal|"idle_dac"
block|,
literal|86
block|,
literal|84
block|}
block|,
comment|//   assign idle_dac            = fus_cfg_reg[86:84]   ^ jtg_cfg_reg[86:84]   ^ 3'h4;
block|{
literal|"hyst_en"
block|,
literal|83
block|,
literal|83
block|}
block|,
comment|//   assign hyst_en             = fus_cfg_reg[83]      ^ jtg_cfg_reg[83]      ^ 1'h1;
block|{
literal|"rndt"
block|,
literal|82
block|,
literal|82
block|}
block|,
comment|//   assign rndt                = fus_cfg_reg[82]      ^ jtg_cfg_reg[82]      ^ 1'h0;
block|{
literal|"cfg_tx_com"
block|,
literal|79
block|,
literal|79
block|}
block|,
comment|//   CN52XX cfg_tx_com     = fus_cfg_reg[79] ^ jtg_cfg_reg[79] ^ 1'h0;
block|{
literal|"cfg_cdr_errcor"
block|,
literal|78
block|,
literal|78
block|}
block|,
comment|//   CN52XX cfg_cdr_errcor = fus_cfg_reg[78] ^ jtg_cfg_reg[78] ^ 1'h0;
block|{
literal|"cfg_cdr_secord"
block|,
literal|77
block|,
literal|77
block|}
block|,
comment|//   CN52XX cfg_cdr_secord = fus_cfg_reg[77] ^ jtg_cfg_reg[77] ^ 1'h1;
block|{
literal|"cfg_cdr_rotate"
block|,
literal|76
block|,
literal|76
block|}
block|,
comment|//   assign cfg_cdr_rotate      = fus_cfg_reg[76]      ^ jtg_cfg_reg[76]      ^ 1'h0;
block|{
literal|"cfg_cdr_rqoffs"
block|,
literal|75
block|,
literal|68
block|}
block|,
comment|//   assign cfg_cdr_rqoffs      = fus_cfg_reg[75:68]   ^ jtg_cfg_reg[75:68]   ^ 8'h40;
block|{
literal|"cfg_cdr_incx"
block|,
literal|67
block|,
literal|64
block|}
block|,
comment|//   assign cfg_cdr_incx        = fus_cfg_reg[67:64]   ^ jtg_cfg_reg[67:64]   ^ 4'h2;
block|{
literal|"cfg_cdr_state"
block|,
literal|63
block|,
literal|56
block|}
block|,
comment|//   assign cfg_cdr_state       = fus_cfg_reg[63:56]   ^ jtg_cfg_reg[63:56]   ^ 8'h0;
block|{
literal|"cfg_cdr_bypass"
block|,
literal|55
block|,
literal|55
block|}
block|,
comment|//   assign cfg_cdr_bypass      = fus_cfg_reg[55]      ^ jtg_cfg_reg[55]      ^ 1'h0;
block|{
literal|"cfg_tx_byp"
block|,
literal|54
block|,
literal|54
block|}
block|,
comment|//   assign cfg_tx_byp          = fus_cfg_reg[54]      ^ jtg_cfg_reg[54]      ^ 1'h0;
block|{
literal|"cfg_tx_val"
block|,
literal|53
block|,
literal|44
block|}
block|,
comment|//   assign cfg_tx_val          = fus_cfg_reg[53:44]   ^ jtg_cfg_reg[53:44]   ^ 10'h0;
block|{
literal|"cfg_rx_pol_set"
block|,
literal|43
block|,
literal|43
block|}
block|,
comment|//   assign cfg_rx_pol_set      = fus_cfg_reg[43]      ^ jtg_cfg_reg[43]      ^ 1'h0;
block|{
literal|"cfg_rx_pol_clr"
block|,
literal|42
block|,
literal|42
block|}
block|,
comment|//   assign cfg_rx_pol_clr      = fus_cfg_reg[42]      ^ jtg_cfg_reg[42]      ^ 1'h0;
block|{
literal|"cfg_cdr_bw_ctl"
block|,
literal|41
block|,
literal|40
block|}
block|,
comment|//   assign cfg_cdr_bw_ctl      = fus_cfg_reg[41:40]   ^ jtg_cfg_reg[41:40]   ^ 2'h0;
block|{
literal|"cfg_rst_n_set"
block|,
literal|39
block|,
literal|39
block|}
block|,
comment|//   assign cfg_rst_n_set       = fus_cfg_reg[39]      ^ jtg_cfg_reg[39]      ^ 1'h0;
block|{
literal|"cfg_rst_n_clr"
block|,
literal|38
block|,
literal|38
block|}
block|,
comment|//   assign cfg_rst_n_clr       = fus_cfg_reg[38]      ^ jtg_cfg_reg[38]      ^ 1'h0;
block|{
literal|"cfg_tx_clk2"
block|,
literal|37
block|,
literal|37
block|}
block|,
comment|//   assign cfg_tx_clk2         = fus_cfg_reg[37]      ^ jtg_cfg_reg[37]      ^ 1'h0;
block|{
literal|"cfg_tx_clk1"
block|,
literal|36
block|,
literal|36
block|}
block|,
comment|//   assign cfg_tx_clk1         = fus_cfg_reg[36]      ^ jtg_cfg_reg[36]      ^ 1'h0;
block|{
literal|"cfg_tx_pol_set"
block|,
literal|35
block|,
literal|35
block|}
block|,
comment|//   assign cfg_tx_pol_set      = fus_cfg_reg[35]      ^ jtg_cfg_reg[35]      ^ 1'h0;
block|{
literal|"cfg_tx_pol_clr"
block|,
literal|34
block|,
literal|34
block|}
block|,
comment|//   assign cfg_tx_pol_clr      = fus_cfg_reg[34]      ^ jtg_cfg_reg[34]      ^ 1'h0;
block|{
literal|"cfg_tx_one"
block|,
literal|33
block|,
literal|33
block|}
block|,
comment|//   assign cfg_tx_one          = fus_cfg_reg[33]      ^ jtg_cfg_reg[33]      ^ 1'h0;
block|{
literal|"cfg_tx_zero"
block|,
literal|32
block|,
literal|32
block|}
block|,
comment|//   assign cfg_tx_zero         = fus_cfg_reg[32]      ^ jtg_cfg_reg[32]      ^ 1'h0;
block|{
literal|"cfg_rxd_wait"
block|,
literal|31
block|,
literal|28
block|}
block|,
comment|//   assign cfg_rxd_wait        = fus_cfg_reg[31:28]   ^ jtg_cfg_reg[31:28]   ^ 4'h3;
block|{
literal|"cfg_rxd_short"
block|,
literal|27
block|,
literal|27
block|}
block|,
comment|//   assign cfg_rxd_short       = fus_cfg_reg[27]      ^ jtg_cfg_reg[27]      ^ 1'h0;
block|{
literal|"cfg_rxd_set"
block|,
literal|26
block|,
literal|26
block|}
block|,
comment|//   assign cfg_rxd_set         = fus_cfg_reg[26]      ^ jtg_cfg_reg[26]      ^ 1'h0;
block|{
literal|"cfg_rxd_clr"
block|,
literal|25
block|,
literal|25
block|}
block|,
comment|//   assign cfg_rxd_clr         = fus_cfg_reg[25]      ^ jtg_cfg_reg[25]      ^ 1'h0;
block|{
literal|"cfg_loopback"
block|,
literal|24
block|,
literal|24
block|}
block|,
comment|//   assign cfg_loopback        = fus_cfg_reg[24]      ^ jtg_cfg_reg[24]      ^ 1'h0;
block|{
literal|"cfg_tx_idle_set"
block|,
literal|23
block|,
literal|23
block|}
block|,
comment|//   assign cfg_tx_idle_set     = fus_cfg_reg[23]      ^ jtg_cfg_reg[23]      ^ 1'h0;
block|{
literal|"cfg_tx_idle_clr"
block|,
literal|22
block|,
literal|22
block|}
block|,
comment|//   assign cfg_tx_idle_clr     = fus_cfg_reg[22]      ^ jtg_cfg_reg[22]      ^ 1'h0;
block|{
literal|"cfg_rx_idle_set"
block|,
literal|21
block|,
literal|21
block|}
block|,
comment|//   assign cfg_rx_idle_set     = fus_cfg_reg[21]      ^ jtg_cfg_reg[21]      ^ 1'h0;
block|{
literal|"cfg_rx_idle_clr"
block|,
literal|20
block|,
literal|20
block|}
block|,
comment|//   assign cfg_rx_idle_clr     = fus_cfg_reg[20]      ^ jtg_cfg_reg[20]      ^ 1'h0;
block|{
literal|"cfg_rx_idle_thr"
block|,
literal|19
block|,
literal|16
block|}
block|,
comment|//   assign cfg_rx_idle_thr     = fus_cfg_reg[19:16]   ^ jtg_cfg_reg[19:16]   ^ 4'h0;
block|{
literal|"cfg_com_thr"
block|,
literal|15
block|,
literal|12
block|}
block|,
comment|//   assign cfg_com_thr         = fus_cfg_reg[15:12]   ^ jtg_cfg_reg[15:12]   ^ 4'h3;
block|{
literal|"cfg_rx_offset"
block|,
literal|11
block|,
literal|8
block|}
block|,
comment|//   assign cfg_rx_offset       = fus_cfg_reg[11:8]    ^ jtg_cfg_reg[11:8]    ^ 4'h4;
block|{
literal|"cfg_skp_max"
block|,
literal|7
block|,
literal|4
block|}
block|,
comment|//   assign cfg_skp_max         = fus_cfg_reg[7:4]     ^ jtg_cfg_reg[7:4]     ^ 4'hc;
block|{
literal|"cfg_skp_min"
block|,
literal|3
block|,
literal|0
block|}
block|,
comment|//   assign cfg_skp_min         = fus_cfg_reg[3:0]     ^ jtg_cfg_reg[3:0]     ^ 4'h4;
block|{
name|NULL
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|__cvmx_qlm_jtag_field_t
name|__cvmx_qlm_jtag_field_cn63xx
index|[]
init|=
block|{
block|{
literal|"prbs_err_cnt"
block|,
literal|299
block|,
literal|252
block|}
block|,
comment|// prbs_err_cnt[47..0]
block|{
literal|"prbs_lock"
block|,
literal|251
block|,
literal|251
block|}
block|,
comment|// prbs_lock
block|{
literal|"jtg_prbs_rst_n"
block|,
literal|250
block|,
literal|250
block|}
block|,
comment|// jtg_prbs_rst_n
block|{
literal|"jtg_run_prbs31"
block|,
literal|249
block|,
literal|249
block|}
block|,
comment|// jtg_run_prbs31
block|{
literal|"jtg_run_prbs7"
block|,
literal|248
block|,
literal|248
block|}
block|,
comment|// jtg_run_prbs7
block|{
literal|"Unused1"
block|,
literal|247
block|,
literal|245
block|}
block|,
comment|// 0
block|{
literal|"cfg_pwrup_set"
block|,
literal|244
block|,
literal|244
block|}
block|,
comment|// cfg_pwrup_set
block|{
literal|"cfg_pwrup_clr"
block|,
literal|243
block|,
literal|243
block|}
block|,
comment|// cfg_pwrup_clr
block|{
literal|"cfg_rst_n_set"
block|,
literal|242
block|,
literal|242
block|}
block|,
comment|// cfg_rst_n_set
block|{
literal|"cfg_rst_n_clr"
block|,
literal|241
block|,
literal|241
block|}
block|,
comment|// cfg_rst_n_clr
block|{
literal|"cfg_tx_idle_set"
block|,
literal|240
block|,
literal|240
block|}
block|,
comment|// cfg_tx_idle_set
block|{
literal|"cfg_tx_idle_clr"
block|,
literal|239
block|,
literal|239
block|}
block|,
comment|// cfg_tx_idle_clr
block|{
literal|"cfg_tx_byp"
block|,
literal|238
block|,
literal|238
block|}
block|,
comment|// cfg_tx_byp
block|{
literal|"cfg_tx_byp_inv"
block|,
literal|237
block|,
literal|237
block|}
block|,
comment|// cfg_tx_byp_inv
block|{
literal|"cfg_tx_byp_val"
block|,
literal|236
block|,
literal|227
block|}
block|,
comment|// cfg_tx_byp_val[9..0]
block|{
literal|"cfg_loopback"
block|,
literal|226
block|,
literal|226
block|}
block|,
comment|// cfg_loopback
block|{
literal|"shlpbck"
block|,
literal|225
block|,
literal|224
block|}
block|,
comment|// shlpbck[1..0]
block|{
literal|"sl_enable"
block|,
literal|223
block|,
literal|223
block|}
block|,
comment|// sl_enable
block|{
literal|"sl_posedge_sample"
block|,
literal|222
block|,
literal|222
block|}
block|,
comment|// sl_posedge_sample
block|{
literal|"trimen"
block|,
literal|221
block|,
literal|220
block|}
block|,
comment|// trimen[1..0]
block|{
literal|"serdes_tx_byp"
block|,
literal|219
block|,
literal|219
block|}
block|,
comment|// serdes_tx_byp
block|{
literal|"serdes_pll_byp"
block|,
literal|218
block|,
literal|218
block|}
block|,
comment|// serdes_pll_byp
block|{
literal|"lowf_byp"
block|,
literal|217
block|,
literal|217
block|}
block|,
comment|// lowf_byp
block|{
literal|"spdsel_byp"
block|,
literal|216
block|,
literal|216
block|}
block|,
comment|// spdsel_byp
block|{
literal|"div4_byp"
block|,
literal|215
block|,
literal|215
block|}
block|,
comment|// div4_byp
block|{
literal|"clkf_byp"
block|,
literal|214
block|,
literal|208
block|}
block|,
comment|// clkf_byp[6..0]
block|{
literal|"Unused2"
block|,
literal|207
block|,
literal|206
block|}
block|,
comment|// 0
block|{
literal|"biasdrv_hs_ls_byp"
block|,
literal|205
block|,
literal|201
block|}
block|,
comment|// biasdrv_hs_ls_byp[4..0]
block|{
literal|"tcoeff_hf_ls_byp"
block|,
literal|200
block|,
literal|197
block|}
block|,
comment|// tcoeff_hf_ls_byp[3..0]
block|{
literal|"biasdrv_hf_byp"
block|,
literal|196
block|,
literal|192
block|}
block|,
comment|// biasdrv_hf_byp[4..0]
block|{
literal|"tcoeff_hf_byp"
block|,
literal|191
block|,
literal|188
block|}
block|,
comment|// tcoeff_hf_byp[3..0]
block|{
literal|"Unused3"
block|,
literal|187
block|,
literal|186
block|}
block|,
comment|// 0
block|{
literal|"biasdrv_lf_ls_byp"
block|,
literal|185
block|,
literal|181
block|}
block|,
comment|// biasdrv_lf_ls_byp[4..0]
block|{
literal|"tcoeff_lf_ls_byp"
block|,
literal|180
block|,
literal|177
block|}
block|,
comment|// tcoeff_lf_ls_byp[3..0]
block|{
literal|"biasdrv_lf_byp"
block|,
literal|176
block|,
literal|172
block|}
block|,
comment|// biasdrv_lf_byp[4..0]
block|{
literal|"tcoeff_lf_byp"
block|,
literal|171
block|,
literal|168
block|}
block|,
comment|// tcoeff_lf_byp[3..0]
block|{
literal|"Unused4"
block|,
literal|167
block|,
literal|167
block|}
block|,
comment|// 0
block|{
literal|"interpbw"
block|,
literal|166
block|,
literal|162
block|}
block|,
comment|// interpbw[4..0]
block|{
literal|"pll_cpb"
block|,
literal|161
block|,
literal|159
block|}
block|,
comment|// pll_cpb[2..0]
block|{
literal|"pll_cps"
block|,
literal|158
block|,
literal|156
block|}
block|,
comment|// pll_cps[2..0]
block|{
literal|"pll_diffamp"
block|,
literal|155
block|,
literal|152
block|}
block|,
comment|// pll_diffamp[3..0]
block|{
literal|"Unused5"
block|,
literal|151
block|,
literal|150
block|}
block|,
comment|// 0
block|{
literal|"cfg_rx_idle_set"
block|,
literal|149
block|,
literal|149
block|}
block|,
comment|// cfg_rx_idle_set
block|{
literal|"cfg_rx_idle_clr"
block|,
literal|148
block|,
literal|148
block|}
block|,
comment|// cfg_rx_idle_clr
block|{
literal|"cfg_rx_idle_thr"
block|,
literal|147
block|,
literal|144
block|}
block|,
comment|// cfg_rx_idle_thr[3..0]
block|{
literal|"cfg_com_thr"
block|,
literal|143
block|,
literal|140
block|}
block|,
comment|// cfg_com_thr[3..0]
block|{
literal|"cfg_rx_offset"
block|,
literal|139
block|,
literal|136
block|}
block|,
comment|// cfg_rx_offset[3..0]
block|{
literal|"cfg_skp_max"
block|,
literal|135
block|,
literal|132
block|}
block|,
comment|// cfg_skp_max[3..0]
block|{
literal|"cfg_skp_min"
block|,
literal|131
block|,
literal|128
block|}
block|,
comment|// cfg_skp_min[3..0]
block|{
literal|"cfg_fast_pwrup"
block|,
literal|127
block|,
literal|127
block|}
block|,
comment|// cfg_fast_pwrup
block|{
literal|"Unused6"
block|,
literal|126
block|,
literal|100
block|}
block|,
comment|// 0
block|{
literal|"detected_n"
block|,
literal|99
block|,
literal|99
block|}
block|,
comment|// detected_n
block|{
literal|"detected_p"
block|,
literal|98
block|,
literal|98
block|}
block|,
comment|// detected_p
block|{
literal|"dbg_res_rx"
block|,
literal|97
block|,
literal|94
block|}
block|,
comment|// dbg_res_rx[3..0]
block|{
literal|"dbg_res_tx"
block|,
literal|93
block|,
literal|90
block|}
block|,
comment|// dbg_res_tx[3..0]
block|{
literal|"cfg_tx_pol_set"
block|,
literal|89
block|,
literal|89
block|}
block|,
comment|// cfg_tx_pol_set
block|{
literal|"cfg_tx_pol_clr"
block|,
literal|88
block|,
literal|88
block|}
block|,
comment|// cfg_tx_pol_clr
block|{
literal|"cfg_rx_pol_set"
block|,
literal|87
block|,
literal|87
block|}
block|,
comment|// cfg_rx_pol_set
block|{
literal|"cfg_rx_pol_clr"
block|,
literal|86
block|,
literal|86
block|}
block|,
comment|// cfg_rx_pol_clr
block|{
literal|"cfg_rxd_set"
block|,
literal|85
block|,
literal|85
block|}
block|,
comment|// cfg_rxd_set
block|{
literal|"cfg_rxd_clr"
block|,
literal|84
block|,
literal|84
block|}
block|,
comment|// cfg_rxd_clr
block|{
literal|"cfg_rxd_wait"
block|,
literal|83
block|,
literal|80
block|}
block|,
comment|// cfg_rxd_wait[3..0]
block|{
literal|"cfg_cdr_limit"
block|,
literal|79
block|,
literal|79
block|}
block|,
comment|// cfg_cdr_limit
block|{
literal|"cfg_cdr_rotate"
block|,
literal|78
block|,
literal|78
block|}
block|,
comment|// cfg_cdr_rotate
block|{
literal|"cfg_cdr_bw_ctl"
block|,
literal|77
block|,
literal|76
block|}
block|,
comment|// cfg_cdr_bw_ctl[1..0]
block|{
literal|"cfg_cdr_trunc"
block|,
literal|75
block|,
literal|74
block|}
block|,
comment|// cfg_cdr_trunc[1..0]
block|{
literal|"cfg_cdr_rqoffs"
block|,
literal|73
block|,
literal|64
block|}
block|,
comment|// cfg_cdr_rqoffs[9..0]
block|{
literal|"cfg_cdr_inc2"
block|,
literal|63
block|,
literal|58
block|}
block|,
comment|// cfg_cdr_inc2[5..0]
block|{
literal|"cfg_cdr_inc1"
block|,
literal|57
block|,
literal|52
block|}
block|,
comment|// cfg_cdr_inc1[5..0]
block|{
literal|"fusopt_voter_sync"
block|,
literal|51
block|,
literal|51
block|}
block|,
comment|// fusopt_voter_sync
block|{
literal|"rndt"
block|,
literal|50
block|,
literal|50
block|}
block|,
comment|// rndt
block|{
literal|"hcya"
block|,
literal|49
block|,
literal|49
block|}
block|,
comment|// hcya
block|{
literal|"hyst"
block|,
literal|48
block|,
literal|48
block|}
block|,
comment|// hyst
block|{
literal|"idle_dac"
block|,
literal|47
block|,
literal|45
block|}
block|,
comment|// idle_dac[2..0]
block|{
literal|"bg_ref_sel"
block|,
literal|44
block|,
literal|44
block|}
block|,
comment|// bg_ref_sel
block|{
literal|"ic50dac"
block|,
literal|43
block|,
literal|39
block|}
block|,
comment|// ic50dac[4..0]
block|{
literal|"ir50dac"
block|,
literal|38
block|,
literal|34
block|}
block|,
comment|// ir50dac[4..0]
block|{
literal|"tx_rout_comp_bypass"
block|,
literal|33
block|,
literal|33
block|}
block|,
comment|// tx_rout_comp_bypass
block|{
literal|"tx_rout_comp_value"
block|,
literal|32
block|,
literal|29
block|}
block|,
comment|// tx_rout_comp_value[3..0]
block|{
literal|"tx_res_offset"
block|,
literal|28
block|,
literal|25
block|}
block|,
comment|// tx_res_offset[3..0]
block|{
literal|"rx_rout_comp_bypass"
block|,
literal|24
block|,
literal|24
block|}
block|,
comment|// rx_rout_comp_bypass
block|{
literal|"rx_rout_comp_value"
block|,
literal|23
block|,
literal|20
block|}
block|,
comment|// rx_rout_comp_value[3..0]
block|{
literal|"rx_res_offset"
block|,
literal|19
block|,
literal|16
block|}
block|,
comment|// rx_res_offset[3..0]
block|{
literal|"rx_cap_gen2"
block|,
literal|15
block|,
literal|12
block|}
block|,
comment|// rx_cap_gen2[3..0]
block|{
literal|"rx_eq_gen2"
block|,
literal|11
block|,
literal|8
block|}
block|,
comment|// rx_eq_gen2[3..0]
block|{
literal|"rx_cap_gen1"
block|,
literal|7
block|,
literal|4
block|}
block|,
comment|// rx_cap_gen1[3..0]
block|{
literal|"rx_eq_gen1"
block|,
literal|3
block|,
literal|0
block|}
block|,
comment|// rx_eq_gen1[3..0]
block|{
name|NULL
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|__cvmx_qlm_jtag_field_t
name|__cvmx_qlm_jtag_field_cn66xx
index|[]
init|=
block|{
block|{
literal|"prbs_err_cnt"
block|,
literal|303
block|,
literal|256
block|}
block|,
comment|// prbs_err_cnt[47..0]
block|{
literal|"prbs_lock"
block|,
literal|255
block|,
literal|255
block|}
block|,
comment|// prbs_lock
block|{
literal|"jtg_prbs_rx_rst_n"
block|,
literal|254
block|,
literal|254
block|}
block|,
comment|// jtg_prbs_rx_rst_n
block|{
literal|"jtg_prbs_tx_rst_n"
block|,
literal|253
block|,
literal|253
block|}
block|,
comment|// jtg_prbs_tx_rst_n
block|{
literal|"jtg_prbs_mode"
block|,
literal|252
block|,
literal|251
block|}
block|,
comment|// jtg_prbs_mode[252:251]
block|{
literal|"jtg_prbs_rst_n"
block|,
literal|250
block|,
literal|250
block|}
block|,
comment|// jtg_prbs_rst_n
block|{
literal|"jtg_run_prbs31"
block|,
literal|249
block|,
literal|249
block|}
block|,
comment|// jtg_run_prbs31 - Use jtg_prbs_mode instead
block|{
literal|"jtg_run_prbs7"
block|,
literal|248
block|,
literal|248
block|}
block|,
comment|// jtg_run_prbs7 - Use jtg_prbs_mode instead
block|{
literal|"Unused1"
block|,
literal|247
block|,
literal|246
block|}
block|,
comment|// 0
block|{
literal|"div5_byp"
block|,
literal|245
block|,
literal|245
block|}
block|,
comment|// div5_byp
block|{
literal|"cfg_pwrup_set"
block|,
literal|244
block|,
literal|244
block|}
block|,
comment|// cfg_pwrup_set
block|{
literal|"cfg_pwrup_clr"
block|,
literal|243
block|,
literal|243
block|}
block|,
comment|// cfg_pwrup_clr
block|{
literal|"cfg_rst_n_set"
block|,
literal|242
block|,
literal|242
block|}
block|,
comment|// cfg_rst_n_set
block|{
literal|"cfg_rst_n_clr"
block|,
literal|241
block|,
literal|241
block|}
block|,
comment|// cfg_rst_n_clr
block|{
literal|"cfg_tx_idle_set"
block|,
literal|240
block|,
literal|240
block|}
block|,
comment|// cfg_tx_idle_set
block|{
literal|"cfg_tx_idle_clr"
block|,
literal|239
block|,
literal|239
block|}
block|,
comment|// cfg_tx_idle_clr
block|{
literal|"cfg_tx_byp"
block|,
literal|238
block|,
literal|238
block|}
block|,
comment|// cfg_tx_byp
block|{
literal|"cfg_tx_byp_inv"
block|,
literal|237
block|,
literal|237
block|}
block|,
comment|// cfg_tx_byp_inv
block|{
literal|"cfg_tx_byp_val"
block|,
literal|236
block|,
literal|227
block|}
block|,
comment|// cfg_tx_byp_val[9..0]
block|{
literal|"cfg_loopback"
block|,
literal|226
block|,
literal|226
block|}
block|,
comment|// cfg_loopback
block|{
literal|"shlpbck"
block|,
literal|225
block|,
literal|224
block|}
block|,
comment|// shlpbck[1..0]
block|{
literal|"sl_enable"
block|,
literal|223
block|,
literal|223
block|}
block|,
comment|// sl_enable
block|{
literal|"sl_posedge_sample"
block|,
literal|222
block|,
literal|222
block|}
block|,
comment|// sl_posedge_sample
block|{
literal|"trimen"
block|,
literal|221
block|,
literal|220
block|}
block|,
comment|// trimen[1..0]
block|{
literal|"serdes_tx_byp"
block|,
literal|219
block|,
literal|219
block|}
block|,
comment|// serdes_tx_byp
block|{
literal|"serdes_pll_byp"
block|,
literal|218
block|,
literal|218
block|}
block|,
comment|// serdes_pll_byp
block|{
literal|"lowf_byp"
block|,
literal|217
block|,
literal|217
block|}
block|,
comment|// lowf_byp
block|{
literal|"spdsel_byp"
block|,
literal|216
block|,
literal|216
block|}
block|,
comment|// spdsel_byp
block|{
literal|"div4_byp"
block|,
literal|215
block|,
literal|215
block|}
block|,
comment|// div4_byp
block|{
literal|"clkf_byp"
block|,
literal|214
block|,
literal|208
block|}
block|,
comment|// clkf_byp[6..0]
block|{
literal|"biasdrv_hs_ls_byp"
block|,
literal|207
block|,
literal|203
block|}
block|,
comment|// biasdrv_hs_ls_byp[4..0]
block|{
literal|"tcoeff_hf_ls_byp"
block|,
literal|202
block|,
literal|198
block|}
block|,
comment|// tcoeff_hf_ls_byp[4..0]
block|{
literal|"biasdrv_hf_byp"
block|,
literal|197
block|,
literal|193
block|}
block|,
comment|// biasdrv_hf_byp[4..0]
block|{
literal|"tcoeff_hf_byp"
block|,
literal|192
block|,
literal|188
block|}
block|,
comment|// tcoeff_hf_byp[4..0]
block|{
literal|"biasdrv_lf_ls_byp"
block|,
literal|187
block|,
literal|183
block|}
block|,
comment|// biasdrv_lf_ls_byp[4..0]
block|{
literal|"tcoeff_lf_ls_byp"
block|,
literal|182
block|,
literal|178
block|}
block|,
comment|// tcoeff_lf_ls_byp[4..0]
block|{
literal|"biasdrv_lf_byp"
block|,
literal|177
block|,
literal|173
block|}
block|,
comment|// biasdrv_lf_byp[4..0]
block|{
literal|"tcoeff_lf_byp"
block|,
literal|172
block|,
literal|168
block|}
block|,
comment|// tcoeff_lf_byp[4..0]
block|{
literal|"Unused4"
block|,
literal|167
block|,
literal|167
block|}
block|,
comment|// 0
block|{
literal|"interpbw"
block|,
literal|166
block|,
literal|162
block|}
block|,
comment|// interpbw[4..0]
block|{
literal|"pll_cpb"
block|,
literal|161
block|,
literal|159
block|}
block|,
comment|// pll_cpb[2..0]
block|{
literal|"pll_cps"
block|,
literal|158
block|,
literal|156
block|}
block|,
comment|// pll_cps[2..0]
block|{
literal|"pll_diffamp"
block|,
literal|155
block|,
literal|152
block|}
block|,
comment|// pll_diffamp[3..0]
block|{
literal|"cfg_err_thr"
block|,
literal|151
block|,
literal|150
block|}
block|,
comment|// cfg_err_thr
block|{
literal|"cfg_rx_idle_set"
block|,
literal|149
block|,
literal|149
block|}
block|,
comment|// cfg_rx_idle_set
block|{
literal|"cfg_rx_idle_clr"
block|,
literal|148
block|,
literal|148
block|}
block|,
comment|// cfg_rx_idle_clr
block|{
literal|"cfg_rx_idle_thr"
block|,
literal|147
block|,
literal|144
block|}
block|,
comment|// cfg_rx_idle_thr[3..0]
block|{
literal|"cfg_com_thr"
block|,
literal|143
block|,
literal|140
block|}
block|,
comment|// cfg_com_thr[3..0]
block|{
literal|"cfg_rx_offset"
block|,
literal|139
block|,
literal|136
block|}
block|,
comment|// cfg_rx_offset[3..0]
block|{
literal|"cfg_skp_max"
block|,
literal|135
block|,
literal|132
block|}
block|,
comment|// cfg_skp_max[3..0]
block|{
literal|"cfg_skp_min"
block|,
literal|131
block|,
literal|128
block|}
block|,
comment|// cfg_skp_min[3..0]
block|{
literal|"cfg_fast_pwrup"
block|,
literal|127
block|,
literal|127
block|}
block|,
comment|// cfg_fast_pwrup
block|{
literal|"Unused6"
block|,
literal|126
block|,
literal|101
block|}
block|,
comment|// 0
block|{
literal|"cfg_indep_dis"
block|,
literal|100
block|,
literal|100
block|}
block|,
comment|// cfg_indep_dis
block|{
literal|"detected_n"
block|,
literal|99
block|,
literal|99
block|}
block|,
comment|// detected_n
block|{
literal|"detected_p"
block|,
literal|98
block|,
literal|98
block|}
block|,
comment|// detected_p
block|{
literal|"dbg_res_rx"
block|,
literal|97
block|,
literal|94
block|}
block|,
comment|// dbg_res_rx[3..0]
block|{
literal|"dbg_res_tx"
block|,
literal|93
block|,
literal|90
block|}
block|,
comment|// dbg_res_tx[3..0]
block|{
literal|"cfg_tx_pol_set"
block|,
literal|89
block|,
literal|89
block|}
block|,
comment|// cfg_tx_pol_set
block|{
literal|"cfg_tx_pol_clr"
block|,
literal|88
block|,
literal|88
block|}
block|,
comment|// cfg_tx_pol_clr
block|{
literal|"cfg_rx_pol_set"
block|,
literal|87
block|,
literal|87
block|}
block|,
comment|// cfg_rx_pol_set
block|{
literal|"cfg_rx_pol_clr"
block|,
literal|86
block|,
literal|86
block|}
block|,
comment|// cfg_rx_pol_clr
block|{
literal|"cfg_rxd_set"
block|,
literal|85
block|,
literal|85
block|}
block|,
comment|// cfg_rxd_set
block|{
literal|"cfg_rxd_clr"
block|,
literal|84
block|,
literal|84
block|}
block|,
comment|// cfg_rxd_clr
block|{
literal|"cfg_rxd_wait"
block|,
literal|83
block|,
literal|80
block|}
block|,
comment|// cfg_rxd_wait[3..0]
block|{
literal|"cfg_cdr_limit"
block|,
literal|79
block|,
literal|79
block|}
block|,
comment|// cfg_cdr_limit
block|{
literal|"cfg_cdr_rotate"
block|,
literal|78
block|,
literal|78
block|}
block|,
comment|// cfg_cdr_rotate
block|{
literal|"cfg_cdr_bw_ctl"
block|,
literal|77
block|,
literal|76
block|}
block|,
comment|// cfg_cdr_bw_ctl[1..0]
block|{
literal|"cfg_cdr_trunc"
block|,
literal|75
block|,
literal|74
block|}
block|,
comment|// cfg_cdr_trunc[1..0]
block|{
literal|"cfg_cdr_rqoffs"
block|,
literal|73
block|,
literal|64
block|}
block|,
comment|// cfg_cdr_rqoffs[9..0]
block|{
literal|"cfg_cdr_inc2"
block|,
literal|63
block|,
literal|58
block|}
block|,
comment|// cfg_cdr_inc2[5..0]
block|{
literal|"cfg_cdr_inc1"
block|,
literal|57
block|,
literal|52
block|}
block|,
comment|// cfg_cdr_inc1[5..0]
block|{
literal|"fusopt_voter_sync"
block|,
literal|51
block|,
literal|51
block|}
block|,
comment|// fusopt_voter_sync
block|{
literal|"rndt"
block|,
literal|50
block|,
literal|50
block|}
block|,
comment|// rndt
block|{
literal|"hcya"
block|,
literal|49
block|,
literal|49
block|}
block|,
comment|// hcya
block|{
literal|"hyst"
block|,
literal|48
block|,
literal|48
block|}
block|,
comment|// hyst
block|{
literal|"idle_dac"
block|,
literal|47
block|,
literal|45
block|}
block|,
comment|// idle_dac[2..0]
block|{
literal|"bg_ref_sel"
block|,
literal|44
block|,
literal|44
block|}
block|,
comment|// bg_ref_sel
block|{
literal|"ic50dac"
block|,
literal|43
block|,
literal|39
block|}
block|,
comment|// ic50dac[4..0]
block|{
literal|"ir50dac"
block|,
literal|38
block|,
literal|34
block|}
block|,
comment|// ir50dac[4..0]
block|{
literal|"tx_rout_comp_bypass"
block|,
literal|33
block|,
literal|33
block|}
block|,
comment|// tx_rout_comp_bypass
block|{
literal|"tx_rout_comp_value"
block|,
literal|32
block|,
literal|29
block|}
block|,
comment|// tx_rout_comp_value[3..0]
block|{
literal|"tx_res_offset"
block|,
literal|28
block|,
literal|25
block|}
block|,
comment|// tx_res_offset[3..0]
block|{
literal|"rx_rout_comp_bypass"
block|,
literal|24
block|,
literal|24
block|}
block|,
comment|// rx_rout_comp_bypass
block|{
literal|"rx_rout_comp_value"
block|,
literal|23
block|,
literal|20
block|}
block|,
comment|// rx_rout_comp_value[3..0]
block|{
literal|"rx_res_offset"
block|,
literal|19
block|,
literal|16
block|}
block|,
comment|// rx_res_offset[3..0]
block|{
literal|"rx_cap_gen2"
block|,
literal|15
block|,
literal|12
block|}
block|,
comment|// rx_cap_gen2[3..0]
block|{
literal|"rx_eq_gen2"
block|,
literal|11
block|,
literal|8
block|}
block|,
comment|// rx_eq_gen2[3..0]
block|{
literal|"rx_cap_gen1"
block|,
literal|7
block|,
literal|4
block|}
block|,
comment|// rx_cap_gen1[3..0]
block|{
literal|"rx_eq_gen1"
block|,
literal|3
block|,
literal|0
block|}
block|,
comment|// rx_eq_gen1[3..0]
block|{
name|NULL
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|__cvmx_qlm_jtag_field_t
name|__cvmx_qlm_jtag_field_cn68xx
index|[]
init|=
block|{
block|{
literal|"prbs_err_cnt"
block|,
literal|303
block|,
literal|256
block|}
block|,
comment|// prbs_err_cnt[47..0]
block|{
literal|"prbs_lock"
block|,
literal|255
block|,
literal|255
block|}
block|,
comment|// prbs_lock
block|{
literal|"jtg_prbs_rx_rst_n"
block|,
literal|254
block|,
literal|254
block|}
block|,
comment|// jtg_prbs_rx_rst_n
block|{
literal|"jtg_prbs_tx_rst_n"
block|,
literal|253
block|,
literal|253
block|}
block|,
comment|// jtg_prbs_tx_rst_n
block|{
literal|"jtg_prbs_mode"
block|,
literal|252
block|,
literal|251
block|}
block|,
comment|// jtg_prbs_mode[252:251]
block|{
literal|"jtg_prbs_rst_n"
block|,
literal|250
block|,
literal|250
block|}
block|,
comment|// jtg_prbs_rst_n
block|{
literal|"jtg_run_prbs31"
block|,
literal|249
block|,
literal|249
block|}
block|,
comment|// jtg_run_prbs31 - Use jtg_prbs_mode instead
block|{
literal|"jtg_run_prbs7"
block|,
literal|248
block|,
literal|248
block|}
block|,
comment|// jtg_run_prbs7 - Use jtg_prbs_mode instead
block|{
literal|"Unused1"
block|,
literal|247
block|,
literal|245
block|}
block|,
comment|// 0
block|{
literal|"cfg_pwrup_set"
block|,
literal|244
block|,
literal|244
block|}
block|,
comment|// cfg_pwrup_set
block|{
literal|"cfg_pwrup_clr"
block|,
literal|243
block|,
literal|243
block|}
block|,
comment|// cfg_pwrup_clr
block|{
literal|"cfg_rst_n_set"
block|,
literal|242
block|,
literal|242
block|}
block|,
comment|// cfg_rst_n_set
block|{
literal|"cfg_rst_n_clr"
block|,
literal|241
block|,
literal|241
block|}
block|,
comment|// cfg_rst_n_clr
block|{
literal|"cfg_tx_idle_set"
block|,
literal|240
block|,
literal|240
block|}
block|,
comment|// cfg_tx_idle_set
block|{
literal|"cfg_tx_idle_clr"
block|,
literal|239
block|,
literal|239
block|}
block|,
comment|// cfg_tx_idle_clr
block|{
literal|"cfg_tx_byp"
block|,
literal|238
block|,
literal|238
block|}
block|,
comment|// cfg_tx_byp
block|{
literal|"cfg_tx_byp_inv"
block|,
literal|237
block|,
literal|237
block|}
block|,
comment|// cfg_tx_byp_inv
block|{
literal|"cfg_tx_byp_val"
block|,
literal|236
block|,
literal|227
block|}
block|,
comment|// cfg_tx_byp_val[9..0]
block|{
literal|"cfg_loopback"
block|,
literal|226
block|,
literal|226
block|}
block|,
comment|// cfg_loopback
block|{
literal|"shlpbck"
block|,
literal|225
block|,
literal|224
block|}
block|,
comment|// shlpbck[1..0]
block|{
literal|"sl_enable"
block|,
literal|223
block|,
literal|223
block|}
block|,
comment|// sl_enable
block|{
literal|"sl_posedge_sample"
block|,
literal|222
block|,
literal|222
block|}
block|,
comment|// sl_posedge_sample
block|{
literal|"trimen"
block|,
literal|221
block|,
literal|220
block|}
block|,
comment|// trimen[1..0]
block|{
literal|"serdes_tx_byp"
block|,
literal|219
block|,
literal|219
block|}
block|,
comment|// serdes_tx_byp
block|{
literal|"serdes_pll_byp"
block|,
literal|218
block|,
literal|218
block|}
block|,
comment|// serdes_pll_byp
block|{
literal|"lowf_byp"
block|,
literal|217
block|,
literal|217
block|}
block|,
comment|// lowf_byp
block|{
literal|"spdsel_byp"
block|,
literal|216
block|,
literal|216
block|}
block|,
comment|// spdsel_byp
block|{
literal|"div4_byp"
block|,
literal|215
block|,
literal|215
block|}
block|,
comment|// div4_byp
block|{
literal|"clkf_byp"
block|,
literal|214
block|,
literal|208
block|}
block|,
comment|// clkf_byp[6..0]
block|{
literal|"biasdrv_hs_ls_byp"
block|,
literal|207
block|,
literal|203
block|}
block|,
comment|// biasdrv_hs_ls_byp[4..0]
block|{
literal|"tcoeff_hf_ls_byp"
block|,
literal|202
block|,
literal|198
block|}
block|,
comment|// tcoeff_hf_ls_byp[4..0]
block|{
literal|"biasdrv_hf_byp"
block|,
literal|197
block|,
literal|193
block|}
block|,
comment|// biasdrv_hf_byp[4..0]
block|{
literal|"tcoeff_hf_byp"
block|,
literal|192
block|,
literal|188
block|}
block|,
comment|// tcoeff_hf_byp[4..0]
block|{
literal|"biasdrv_lf_ls_byp"
block|,
literal|187
block|,
literal|183
block|}
block|,
comment|// biasdrv_lf_ls_byp[4..0]
block|{
literal|"tcoeff_lf_ls_byp"
block|,
literal|182
block|,
literal|178
block|}
block|,
comment|// tcoeff_lf_ls_byp[4..0]
block|{
literal|"biasdrv_lf_byp"
block|,
literal|177
block|,
literal|173
block|}
block|,
comment|// biasdrv_lf_byp[4..0]
block|{
literal|"tcoeff_lf_byp"
block|,
literal|172
block|,
literal|168
block|}
block|,
comment|// tcoeff_lf_byp[4..0]
block|{
literal|"Unused4"
block|,
literal|167
block|,
literal|167
block|}
block|,
comment|// 0
block|{
literal|"interpbw"
block|,
literal|166
block|,
literal|162
block|}
block|,
comment|// interpbw[4..0]
block|{
literal|"pll_cpb"
block|,
literal|161
block|,
literal|159
block|}
block|,
comment|// pll_cpb[2..0]
block|{
literal|"pll_cps"
block|,
literal|158
block|,
literal|156
block|}
block|,
comment|// pll_cps[2..0]
block|{
literal|"pll_diffamp"
block|,
literal|155
block|,
literal|152
block|}
block|,
comment|// pll_diffamp[3..0]
block|{
literal|"cfg_err_thr"
block|,
literal|151
block|,
literal|150
block|}
block|,
comment|// cfg_err_thr
block|{
literal|"cfg_rx_idle_set"
block|,
literal|149
block|,
literal|149
block|}
block|,
comment|// cfg_rx_idle_set
block|{
literal|"cfg_rx_idle_clr"
block|,
literal|148
block|,
literal|148
block|}
block|,
comment|// cfg_rx_idle_clr
block|{
literal|"cfg_rx_idle_thr"
block|,
literal|147
block|,
literal|144
block|}
block|,
comment|// cfg_rx_idle_thr[3..0]
block|{
literal|"cfg_com_thr"
block|,
literal|143
block|,
literal|140
block|}
block|,
comment|// cfg_com_thr[3..0]
block|{
literal|"cfg_rx_offset"
block|,
literal|139
block|,
literal|136
block|}
block|,
comment|// cfg_rx_offset[3..0]
block|{
literal|"cfg_skp_max"
block|,
literal|135
block|,
literal|132
block|}
block|,
comment|// cfg_skp_max[3..0]
block|{
literal|"cfg_skp_min"
block|,
literal|131
block|,
literal|128
block|}
block|,
comment|// cfg_skp_min[3..0]
block|{
literal|"cfg_fast_pwrup"
block|,
literal|127
block|,
literal|127
block|}
block|,
comment|// cfg_fast_pwrup
block|{
literal|"Unused6"
block|,
literal|126
block|,
literal|100
block|}
block|,
comment|// 0
block|{
literal|"detected_n"
block|,
literal|99
block|,
literal|99
block|}
block|,
comment|// detected_n
block|{
literal|"detected_p"
block|,
literal|98
block|,
literal|98
block|}
block|,
comment|// detected_p
block|{
literal|"dbg_res_rx"
block|,
literal|97
block|,
literal|94
block|}
block|,
comment|// dbg_res_rx[3..0]
block|{
literal|"dbg_res_tx"
block|,
literal|93
block|,
literal|90
block|}
block|,
comment|// dbg_res_tx[3..0]
block|{
literal|"cfg_tx_pol_set"
block|,
literal|89
block|,
literal|89
block|}
block|,
comment|// cfg_tx_pol_set
block|{
literal|"cfg_tx_pol_clr"
block|,
literal|88
block|,
literal|88
block|}
block|,
comment|// cfg_tx_pol_clr
block|{
literal|"cfg_rx_pol_set"
block|,
literal|87
block|,
literal|87
block|}
block|,
comment|// cfg_rx_pol_set
block|{
literal|"cfg_rx_pol_clr"
block|,
literal|86
block|,
literal|86
block|}
block|,
comment|// cfg_rx_pol_clr
block|{
literal|"cfg_rxd_set"
block|,
literal|85
block|,
literal|85
block|}
block|,
comment|// cfg_rxd_set
block|{
literal|"cfg_rxd_clr"
block|,
literal|84
block|,
literal|84
block|}
block|,
comment|// cfg_rxd_clr
block|{
literal|"cfg_rxd_wait"
block|,
literal|83
block|,
literal|80
block|}
block|,
comment|// cfg_rxd_wait[3..0]
block|{
literal|"cfg_cdr_limit"
block|,
literal|79
block|,
literal|79
block|}
block|,
comment|// cfg_cdr_limit
block|{
literal|"cfg_cdr_rotate"
block|,
literal|78
block|,
literal|78
block|}
block|,
comment|// cfg_cdr_rotate
block|{
literal|"cfg_cdr_bw_ctl"
block|,
literal|77
block|,
literal|76
block|}
block|,
comment|// cfg_cdr_bw_ctl[1..0]
block|{
literal|"cfg_cdr_trunc"
block|,
literal|75
block|,
literal|74
block|}
block|,
comment|// cfg_cdr_trunc[1..0]
block|{
literal|"cfg_cdr_rqoffs"
block|,
literal|73
block|,
literal|64
block|}
block|,
comment|// cfg_cdr_rqoffs[9..0]
block|{
literal|"cfg_cdr_inc2"
block|,
literal|63
block|,
literal|58
block|}
block|,
comment|// cfg_cdr_inc2[5..0]
block|{
literal|"cfg_cdr_inc1"
block|,
literal|57
block|,
literal|52
block|}
block|,
comment|// cfg_cdr_inc1[5..0]
block|{
literal|"fusopt_voter_sync"
block|,
literal|51
block|,
literal|51
block|}
block|,
comment|// fusopt_voter_sync
block|{
literal|"rndt"
block|,
literal|50
block|,
literal|50
block|}
block|,
comment|// rndt
block|{
literal|"hcya"
block|,
literal|49
block|,
literal|49
block|}
block|,
comment|// hcya
block|{
literal|"hyst"
block|,
literal|48
block|,
literal|48
block|}
block|,
comment|// hyst
block|{
literal|"idle_dac"
block|,
literal|47
block|,
literal|45
block|}
block|,
comment|// idle_dac[2..0]
block|{
literal|"bg_ref_sel"
block|,
literal|44
block|,
literal|44
block|}
block|,
comment|// bg_ref_sel
block|{
literal|"ic50dac"
block|,
literal|43
block|,
literal|39
block|}
block|,
comment|// ic50dac[4..0]
block|{
literal|"ir50dac"
block|,
literal|38
block|,
literal|34
block|}
block|,
comment|// ir50dac[4..0]
block|{
literal|"tx_rout_comp_bypass"
block|,
literal|33
block|,
literal|33
block|}
block|,
comment|// tx_rout_comp_bypass
block|{
literal|"tx_rout_comp_value"
block|,
literal|32
block|,
literal|29
block|}
block|,
comment|// tx_rout_comp_value[3..0]
block|{
literal|"tx_res_offset"
block|,
literal|28
block|,
literal|25
block|}
block|,
comment|// tx_res_offset[3..0]
block|{
literal|"rx_rout_comp_bypass"
block|,
literal|24
block|,
literal|24
block|}
block|,
comment|// rx_rout_comp_bypass
block|{
literal|"rx_rout_comp_value"
block|,
literal|23
block|,
literal|20
block|}
block|,
comment|// rx_rout_comp_value[3..0]
block|{
literal|"rx_res_offset"
block|,
literal|19
block|,
literal|16
block|}
block|,
comment|// rx_res_offset[3..0]
block|{
literal|"rx_cap_gen2"
block|,
literal|15
block|,
literal|12
block|}
block|,
comment|// rx_cap_gen2[3..0]
block|{
literal|"rx_eq_gen2"
block|,
literal|11
block|,
literal|8
block|}
block|,
comment|// rx_eq_gen2[3..0]
block|{
literal|"rx_cap_gen1"
block|,
literal|7
block|,
literal|4
block|}
block|,
comment|// rx_cap_gen1[3..0]
block|{
literal|"rx_eq_gen1"
block|,
literal|3
block|,
literal|0
block|}
block|,
comment|// rx_eq_gen1[3..0]
block|{
name|NULL
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

