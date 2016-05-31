begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__AR9300_FREEBSD_INC_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR9300_FREEBSD_INC_H__
end_define

begin_comment
comment|/*  * Define some configuration entries for the AR9300 HAL, so #if entries  * don't have to be removed.  */
end_comment

begin_define
define|#
directive|define
name|ATH_DRIVER_SIM
value|0
end_define

begin_comment
comment|/* SIM */
end_comment

begin_define
define|#
directive|define
name|ATH_WOW
value|0
end_define

begin_comment
comment|/* Wake on Wireless */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_MCI
value|1
end_define

begin_comment
comment|/* MCI btcoex */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_AIC
value|0
end_define

begin_comment
comment|/* XXX to do with btcoex? */
end_comment

begin_define
define|#
directive|define
name|AH_NEED_TX_DATA_SWAP
value|0
end_define

begin_comment
comment|/* TX descriptor swap? */
end_comment

begin_define
define|#
directive|define
name|AH_NEED_RX_DATA_SWAP
value|0
end_define

begin_comment
comment|/* TX descriptor swap? */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_WIRESHARK
value|0
end_define

begin_comment
comment|/* Radiotap HAL code */
end_comment

begin_define
define|#
directive|define
name|AH_SUPPORT_WRITE_EEPROM
value|0
end_define

begin_comment
comment|/* EEPROM write support */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_WAPI
value|0
end_define

begin_comment
comment|/* China WAPI support */
end_comment

begin_define
define|#
directive|define
name|ATH_ANT_DIV_COMB
value|1
end_define

begin_comment
comment|/* Antenna combining */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_RAW_ADC_CAPTURE
value|0
end_define

begin_comment
comment|/* Raw ADC capture support */
end_comment

begin_define
define|#
directive|define
name|ATH_TRAFFIC_FAST_RECOVER
value|0
end_define

begin_comment
comment|/* XXX not sure yet */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_SPECTRAL
value|1
end_define

begin_comment
comment|/* Spectral scan support */
end_comment

begin_define
define|#
directive|define
name|ATH_BT_COEX
value|1
end_define

begin_comment
comment|/* Enable BT Coex code */
end_comment

begin_define
define|#
directive|define
name|ATH_PCIE_ERROR_MONITOR
value|0
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_CRDC
value|0
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|ATH_LOW_POWER_ENABLE
value|0
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_VOW_DCS
value|0
end_define

begin_comment
comment|/* Video over wireless dynamic channel select */
end_comment

begin_define
define|#
directive|define
name|REMOVE_PKT_LOG
value|1
end_define

begin_define
define|#
directive|define
name|ATH_VC_MODE_PROXY_STA
value|0
end_define

begin_comment
comment|/* Azimuth + proxysta? */
end_comment

begin_define
define|#
directive|define
name|ATH_GEN_RANDOMNESS
value|0
end_define

begin_define
define|#
directive|define
name|__PKT_SERIOUS_ERRORS__
value|0
end_define

begin_define
define|#
directive|define
name|HAL_INTR_REFCOUNT_DISABLE
value|1
end_define

begin_comment
comment|/* XXX wha? And atomics in the HAL!? */
end_comment

begin_define
define|#
directive|define
name|UMAC_SUPPORT_SMARTANTENNA
value|0
end_define

begin_comment
comment|/* sigh.. */
end_comment

begin_define
define|#
directive|define
name|ATH_SMARTANTENNA_DISABLE_JTAG
value|0
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_WIRESHARK
value|0
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_WIFIPOS
value|0
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_PAPRD
value|1
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_TxBF
value|0
end_define

begin_define
define|#
directive|define
name|AH_PRIVATE_DIAG
value|1
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_KEYPLUMB_WAR
value|0
end_define

begin_comment
comment|/* XXX need to reverify these; they came in with qcamain */
end_comment

begin_define
define|#
directive|define
name|ATH_SUPPORT_FAST_CC
value|0
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_RADIO_RETENTION
value|0
end_define

begin_define
define|#
directive|define
name|ATH_SUPPORT_CAL_REUSE
value|0
end_define

begin_define
define|#
directive|define
name|ATH_WOW_OFFLOAD
value|0
end_define

begin_define
define|#
directive|define
name|HAL_NO_INTERSPERSED_READS
end_define

begin_comment
comment|/* Required or things will probe/attach, but not work right */
end_comment

begin_define
define|#
directive|define
name|AH_SUPPORT_OSPREY
value|1
end_define

begin_define
define|#
directive|define
name|AH_SUPPORT_POSEIDON
value|1
end_define

begin_define
define|#
directive|define
name|AH_SUPPORT_AR9300
value|1
end_define

begin_comment
comment|/* These are the embedded boards */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR9330
end_ifdef

begin_define
define|#
directive|define
name|AH_SUPPORT_HORNET
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_AR9330 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_AR9340
end_ifdef

begin_define
define|#
directive|define
name|AH_SUPPORT_WASP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_AR9340 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_QCA9550
end_ifdef

begin_define
define|#
directive|define
name|AH_SUPPORT_SCORPION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_QCA9550 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AH_SUPPORT_QCA9530
end_ifdef

begin_define
define|#
directive|define
name|AH_SUPPORT_HONEYBEE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_SUPPORT_QCA9530 */
end_comment

begin_define
define|#
directive|define
name|FIX_NOISE_FLOOR
value|1
end_define

begin_comment
comment|/* XXX this needs to be removed! No atomics in the HAL! */
end_comment

begin_typedef
typedef|typedef
name|int
name|os_atomic_t
typedef|;
end_typedef

begin_comment
comment|/* XXX shouldn't do atomics here! */
end_comment

begin_define
define|#
directive|define
name|OS_ATOMIC_INC
parameter_list|(
name|a
parameter_list|)
value|(*a)++
end_define

begin_define
define|#
directive|define
name|OS_ATOMIC_DEC
parameter_list|(
name|a
parameter_list|)
value|(*a)--
end_define

begin_comment
comment|/*  * HAL definitions which aren't necessarily for public consumption (yet).  */
end_comment

begin_enum
enum|enum
block|{
name|HAL_TRUE_CHIP
init|=
literal|1
block|,
name|HAL_MAC_TO_MAC_EMU
block|,
name|HAL_MAC_BB_EMU
block|, }
enum|;
end_enum

begin_comment
comment|/* HAL_KEY_TYPE */
end_comment

begin_enum
enum|enum
block|{
name|HAL_KEY_PROXY_STA_MASK
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_SMPS_DEFAULT
init|=
literal|0
block|,
name|HAL_SMPS_SW_CTRL_LOW_PWR
block|,
comment|/* Software control, low power setting */
name|HAL_SMPS_SW_CTRL_HIGH_PWR
block|,
comment|/* Software control, high power setting */
name|HAL_SMPS_HW_CTRL
comment|/* Hardware Control */
block|}
name|HAL_SMPS_MODE
typedef|;
end_typedef

begin_comment
comment|/*  * Green Tx, Based on different RSSI of Received Beacon thresholds,  * using different tx power by modified register tx power related values.  * The thresholds are decided by system team.  */
end_comment

begin_define
define|#
directive|define
name|GreenTX_thres1
value|56
end_define

begin_comment
comment|/* in dB */
end_comment

begin_define
define|#
directive|define
name|GreenTX_thres2
value|36
end_define

begin_comment
comment|/* in dB */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HAL_RSSI_TX_POWER_NONE
init|=
literal|0
block|,
name|HAL_RSSI_TX_POWER_SHORT
init|=
literal|1
block|,
comment|/* short range, reduce OB/DB bias current and disable PAL */
name|HAL_RSSI_TX_POWER_MIDDLE
init|=
literal|2
block|,
comment|/* middle range, reduce OB/DB bias current and PAL is enabled */
name|HAL_RSSI_TX_POWER_LONG
init|=
literal|3
block|,
comment|/* long range, orig. OB/DB bias current and PAL is enabled */
block|}
name|HAL_RSSI_TX_POWER
typedef|;
end_typedef

begin_struct
struct|struct
name|dfs_pulse
block|{
name|u_int32_t
name|rp_numpulses
decl_stmt|;
comment|/* Num of pulses in radar burst */
name|u_int32_t
name|rp_pulsedur
decl_stmt|;
comment|/* Duration of each pulse in usecs */
name|u_int32_t
name|rp_pulsefreq
decl_stmt|;
comment|/* Frequency of pulses in burst */
name|u_int32_t
name|rp_max_pulsefreq
decl_stmt|;
comment|/* Frequency of pulses in burst */
name|u_int32_t
name|rp_patterntype
decl_stmt|;
comment|/* fixed or variable pattern type*/
name|u_int32_t
name|rp_pulsevar
decl_stmt|;
comment|/* Time variation of pulse duration for 							  matched filter (single-sided) in usecs */
name|u_int32_t
name|rp_threshold
decl_stmt|;
comment|/* Threshold for MF output to indicate 							  radar match */
name|u_int32_t
name|rp_mindur
decl_stmt|;
comment|/* Min pulse duration to be considered for 							  this pulse type */
name|u_int32_t
name|rp_maxdur
decl_stmt|;
comment|/* Max pusle duration to be considered for 							  this pulse type */
name|u_int32_t
name|rp_rssithresh
decl_stmt|;
comment|/* Minimum rssi to be considered a radar pulse */
name|u_int32_t
name|rp_meanoffset
decl_stmt|;
comment|/* Offset for timing adjustment */
name|int32_t
name|rp_rssimargin
decl_stmt|;
comment|/* rssi threshold margin. In Turbo Mode HW reports rssi 3dBm */
comment|/* lower than in non TURBO mode. 							  This will be used to offset that diff.*/
name|u_int32_t
name|rp_ignore_pri_window
decl_stmt|;
name|u_int32_t
name|rp_pulseid
decl_stmt|;
comment|/* Unique ID for identifying filter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dfs_staggered_pulse
block|{
name|u_int32_t
name|rp_numpulses
decl_stmt|;
comment|/* Num of pulses in radar burst */
name|u_int32_t
name|rp_pulsedur
decl_stmt|;
comment|/* Duration of each pulse in usecs */
name|u_int32_t
name|rp_min_pulsefreq
decl_stmt|;
comment|/* Frequency of pulses in burst */
name|u_int32_t
name|rp_max_pulsefreq
decl_stmt|;
comment|/* Frequency of pulses in burst */
name|u_int32_t
name|rp_patterntype
decl_stmt|;
comment|/* fixed or variable pattern type*/
name|u_int32_t
name|rp_pulsevar
decl_stmt|;
comment|/* Time variation of pulse duration for                                                    matched filter (single-sided) in usecs */
name|u_int32_t
name|rp_threshold
decl_stmt|;
comment|/* Thershold for MF output to indicateC                                                   radar match */
name|u_int32_t
name|rp_mindur
decl_stmt|;
comment|/* Min pulse duration to be considered for                                                   this pulse type */
name|u_int32_t
name|rp_maxdur
decl_stmt|;
comment|/* Max pusle duration to be considered for                                                   this pulse type */
name|u_int32_t
name|rp_rssithresh
decl_stmt|;
comment|/* Minimum rssi to be considered a radar pulse */
name|u_int32_t
name|rp_meanoffset
decl_stmt|;
comment|/* Offset for timing adjustment */
name|int32_t
name|rp_rssimargin
decl_stmt|;
comment|/* rssi threshold margin. In Turbo Mode HW reports rssi 3dBm */
comment|/* lower than in non TURBO mode. This will be used to offset that diff.*/
name|u_int32_t
name|rp_pulseid
decl_stmt|;
comment|/* Unique ID for identifying filter */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dfs_bin5pulse
block|{
name|u_int32_t
name|b5_threshold
decl_stmt|;
comment|/* Number of bin5 pulses to indicate detection */
name|u_int32_t
name|b5_mindur
decl_stmt|;
comment|/* Min duration for a bin5 pulse */
name|u_int32_t
name|b5_maxdur
decl_stmt|;
comment|/* Max duration for a bin5 pulse */
name|u_int32_t
name|b5_timewindow
decl_stmt|;
comment|/* Window over which to count bin5 pulses */
name|u_int32_t
name|b5_rssithresh
decl_stmt|;
comment|/* Min rssi to be considered a pulse */
name|u_int32_t
name|b5_rssimargin
decl_stmt|;
comment|/* rssi threshold margin. In Turbo Mode HW reports rssi 3dB */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Noise power data definitions  * units are: 4 x dBm - NOISE_PWR_DATA_OFFSET (e.g. -25 = (-25/4 - 90) = -96.25 dBm)  * range (for 6 signed bits) is (-32 to 31) + offset => -122dBm to -59dBm  * resolution (2 bits) is 0.25dBm  */
end_comment

begin_define
define|#
directive|define
name|NOISE_PWR_DATA_OFFSET
value|-90
end_define

begin_comment
comment|/* dbm - all pwr report data is represented offset by this */
end_comment

begin_define
define|#
directive|define
name|INT_2_NOISE_PWR_DBM
parameter_list|(
name|_p
parameter_list|)
value|(((_p) - NOISE_PWR_DATA_OFFSET)<< 2)
end_define

begin_define
define|#
directive|define
name|NOISE_PWR_DBM_2_INT
parameter_list|(
name|_p
parameter_list|)
value|((((_p) + 3)>> 2) + NOISE_PWR_DATA_OFFSET)
end_define

begin_define
define|#
directive|define
name|NOISE_PWR_DBM_2_DEC
parameter_list|(
name|_p
parameter_list|)
value|(((-(_p))& 3) * 25)
end_define

begin_define
define|#
directive|define
name|N2DBM
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
value|((((_x) - NOISE_PWR_DATA_OFFSET)<< 2) - (_y)/25)
end_define

begin_comment
comment|/* SPECTRAL SCAN defines end */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|halvowstats
block|{
name|u_int32_t
name|tx_frame_count
decl_stmt|;
name|u_int32_t
name|rx_frame_count
decl_stmt|;
name|u_int32_t
name|rx_clear_count
decl_stmt|;
name|u_int32_t
name|cycle_count
decl_stmt|;
name|u_int32_t
name|ext_cycle_count
decl_stmt|;
block|}
name|HAL_VOWSTATS
typedef|;
end_typedef

begin_comment
comment|/*  * Weight table configurations.  */
end_comment

begin_define
define|#
directive|define
name|AR9300_BT_WGHT
value|0xcccc4444
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_WLAN_WGHT0
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_WLAN_WGHT1
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_WLAN_WGHT0
value|0x88888880
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_WLAN_WGHT1
value|0x88888880
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_NONE_WLAN_WGHT0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_NONE_WLAN_WGHT1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_FORCE_WLAN_WGHT0
value|0xffffffff
end_define

begin_comment
comment|// Stomp BT even when WLAN is idle
end_comment

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_FORCE_WLAN_WGHT1
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_FORCE_WLAN_WGHT0
value|0x88888888
end_define

begin_comment
comment|// Stomp BT even when WLAN is idle
end_comment

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_FORCE_WLAN_WGHT1
value|0x88888888
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT0
value|0x01017d01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT1
value|0x41414101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT2
value|0x41414101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT3
value|0x41414141
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT0
value|0x01017d01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT1
value|0x3b3b3b01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT2
value|0x3b3b3b01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT3
value|0x3b3b3b3b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FTP_WLAN_WGHT0
value|0x01017d01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FTP_WLAN_WGHT1
value|0x013b0101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FTP_WLAN_WGHT2
value|0x3b3b0101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FTP_WLAN_WGHT3
value|0x3b3b013b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT0
value|0x01017d01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT1
value|0x01010101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT2
value|0x01010101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT3
value|0x01010101
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT0
value|0x01017d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT1
value|0x7d7d7d01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT2
value|0x7d7d7d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT3
value|0x7d7d7d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT0
value|0x01013b3b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT1
value|0x3b3b3b01
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT2
value|0x3b3b3b3b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT3
value|0x3b3b3b3b
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT1_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT1_MASK_S
value|24
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT2_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT2_MASK_S
value|16
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT3_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT3_MASK_S
value|0
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT3_MASK2
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MCI_CONCUR_TX_WLAN_WGHT3_MASK2_S
value|16
end_define

begin_define
define|#
directive|define
name|MCI_QUERY_BT_VERSION_VERBOSE
value|0
end_define

begin_define
define|#
directive|define
name|MCI_LINKID_INDEX_MGMT_PENDING
value|1
end_define

begin_define
define|#
directive|define
name|HAL_MCI_FLAG_DISABLE_TIMESTAMP
value|0x00000001
end_define

begin_comment
comment|/* Disable time stamp */
end_comment

begin_comment
comment|/*   * The values below come from the system team test result.  * For Jupiter, BT tx power level is from 0(-20dBm) to 6(4dBm).  * Lowest WLAN tx power would be in bit[23:16] of dword 1.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u_int32_t
name|mci_concur_tx_max_pwr
index|[
literal|4
index|]
index|[
literal|8
index|]
init|=
block|{
comment|/* No limit */
block|{
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|,
literal|0x7f7f7f7f
block|}
block|,
comment|/* 11G */
block|{
literal|0x16161616
block|,
literal|0x12121516
block|,
literal|0x12121212
block|,
literal|0x12121212
block|,
literal|0x12121212
block|,
literal|0x12121212
block|,
literal|0x12121212
block|,
literal|0x7f121212
block|}
block|,
comment|/* HT20 */
block|{
literal|0x15151515
block|,
literal|0x14141515
block|,
literal|0x14141414
block|,
literal|0x14141414
block|,
literal|0x14141414
block|,
literal|0x14141414
block|,
literal|0x14141414
block|,
literal|0x7f141414
block|}
block|,
comment|/* HT40 */
block|{
literal|0x10101010
block|,
literal|0x10101010
block|,
literal|0x10101010
block|,
literal|0x10101010
block|,
literal|0x10101010
block|,
literal|0x10101010
block|,
literal|0x10101010
block|,
literal|0x7f101010
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_LOWEST_PWR_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_LOWEST_PWR_MASK_S
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR9300_FREEBSD_INC_H__ */
end_comment

end_unit

