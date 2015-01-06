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
value|0
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
comment|/* These are the embedded boards; we don't currently support these */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* SPECTRAL SCAN defines begin */
end_comment

begin_comment
unit|typedef struct {         u_int16_t       ss_fft_period;
comment|/* Skip interval for FFT reports */
end_comment

begin_comment
unit|u_int16_t       ss_period;
comment|/* Spectral scan period */
end_comment

begin_comment
unit|u_int16_t       ss_count;
comment|/* # of reports to return from ss_active */
end_comment

begin_comment
unit|u_int16_t       ss_short_report;
comment|/* Set to report ony 1 set of FFT results */
end_comment

begin_comment
unit|u_int8_t        radar_bin_thresh_sel;         u_int16_t       ss_spectral_pri;
comment|/* are we doing a noise power cal ? */
end_comment

begin_comment
unit|int8_t          ss_nf_cal[AH_MAX_CHAINS*2];
comment|/* nf calibrated values for ctl+ext from eeprom */
end_comment

begin_comment
unit|int8_t          ss_nf_pwr[AH_MAX_CHAINS*2];
comment|/* nf pwr values for ctl+ext from eeprom */
end_comment

begin_comment
unit|int32_t         ss_nf_temp_data;
comment|/* temperature data taken during nf scan */
end_comment

begin_define
unit|} HAL_SPECTRAL_PARAM;
define|#
directive|define
name|HAL_SPECTRAL_PARAM_NOVAL
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|HAL_SPECTRAL_PARAM_ENABLE
value|0x8000
end_define

begin_comment
comment|/* Enable/Disable if applicable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOW_ACK_PWR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_LOWER_TX_PWR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ALLOW
value|0x00000004
end_define

begin_comment
comment|/* Check Rx Diversity is allowed */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_ANT_DIV_ENABLE
value|0x00000008
end_define

begin_comment
comment|/* Check Diversity is on or off */
end_comment

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_MCI_MAX_TX_PWR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_BT_COEX_FLAG_MCI_FTP_STOMP_RX
value|0x00000020
end_define

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

begin_typedef
typedef|typedef
enum|enum
name|mci_message_header
block|{
name|MCI_LNA_CTRL
init|=
literal|0x10
block|,
comment|/* len = 0 */
name|MCI_CONT_NACK
init|=
literal|0x20
block|,
comment|/* len = 0 */
name|MCI_CONT_INFO
init|=
literal|0x30
block|,
comment|/* len = 4 */
name|MCI_CONT_RST
init|=
literal|0x40
block|,
comment|/* len = 0 */
name|MCI_SCHD_INFO
init|=
literal|0x50
block|,
comment|/* len = 16 */
name|MCI_CPU_INT
init|=
literal|0x60
block|,
comment|/* len = 4 */
name|MCI_SYS_WAKING
init|=
literal|0x70
block|,
comment|/* len = 0 */
name|MCI_GPM
init|=
literal|0x80
block|,
comment|/* len = 16 */
name|MCI_LNA_INFO
init|=
literal|0x90
block|,
comment|/* len = 1 */
name|MCI_LNA_STATE
init|=
literal|0x94
block|,
name|MCI_LNA_TAKE
init|=
literal|0x98
block|,
name|MCI_LNA_TRANS
init|=
literal|0x9c
block|,
name|MCI_SYS_SLEEPING
init|=
literal|0xa0
block|,
comment|/* len = 0 */
name|MCI_REQ_WAKE
init|=
literal|0xc0
block|,
comment|/* len = 0 */
name|MCI_DEBUG_16
init|=
literal|0xfe
block|,
comment|/* len = 2 */
name|MCI_REMOTE_RESET
init|=
literal|0xff
comment|/* len = 16 */
block|}
name|MCI_MESSAGE_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Default remote BT device MCI COEX version */
end_comment

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MAJOR_VERSION_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MINOR_VERSION_DEFAULT
value|0
end_define

begin_comment
comment|/* Local WLAN MCI COEX version */
end_comment

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MAJOR_VERSION_WLAN
value|3
end_define

begin_define
define|#
directive|define
name|MCI_GPM_COEX_MINOR_VERSION_WLAN
value|0
end_define

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_subtype
block|{
name|MCI_GPM_BT_CAL_REQ
init|=
literal|0
block|,
name|MCI_GPM_BT_CAL_GRANT
init|=
literal|1
block|,
name|MCI_GPM_BT_CAL_DONE
init|=
literal|2
block|,
name|MCI_GPM_WLAN_CAL_REQ
init|=
literal|3
block|,
name|MCI_GPM_WLAN_CAL_GRANT
init|=
literal|4
block|,
name|MCI_GPM_WLAN_CAL_DONE
init|=
literal|5
block|,
name|MCI_GPM_COEX_AGENT
init|=
literal|0x0C
block|,
name|MCI_GPM_RSVD_PATTERN
init|=
literal|0xFE
block|,
name|MCI_GPM_RSVD_PATTERN32
init|=
literal|0xFEFEFEFE
block|,
name|MCI_GPM_BT_DEBUG
init|=
literal|0xFF
block|}
name|MCI_GPM_SUBTYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_opcode
block|{
name|MCI_GPM_COEX_VERSION_QUERY
init|=
literal|0
block|,
name|MCI_GPM_COEX_VERSION_RESPONSE
init|=
literal|1
block|,
name|MCI_GPM_COEX_STATUS_QUERY
init|=
literal|2
block|,
name|MCI_GPM_COEX_HALT_BT_GPM
init|=
literal|3
block|,
name|MCI_GPM_COEX_WLAN_CHANNELS
init|=
literal|4
block|,
name|MCI_GPM_COEX_BT_PROFILE_INFO
init|=
literal|5
block|,
name|MCI_GPM_COEX_BT_STATUS_UPDATE
init|=
literal|6
block|,
name|MCI_GPM_COEX_BT_UPDATE_FLAGS
init|=
literal|7
block|}
name|MCI_GPM_COEX_OPCODE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_query_type
block|{
comment|/* WLAN information */
name|MCI_GPM_COEX_QUERY_WLAN_ALL_INFO
init|=
literal|0x01
block|,
comment|/* BT information */
name|MCI_GPM_COEX_QUERY_BT_ALL_INFO
init|=
literal|0x01
block|,
name|MCI_GPM_COEX_QUERY_BT_TOPOLOGY
init|=
literal|0x02
block|,
name|MCI_GPM_COEX_QUERY_BT_DEBUG
init|=
literal|0x04
block|}
name|MCI_GPM_COEX_QUERY_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_halt_bt_gpm
block|{
name|MCI_GPM_COEX_BT_GPM_UNHALT
init|=
literal|0
block|,
name|MCI_GPM_COEX_BT_GPM_HALT
init|=
literal|1
block|}
name|MCI_GPM_COEX_HALT_BT_GPM_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_profile_type
block|{
name|MCI_GPM_COEX_PROFILE_UNKNOWN
init|=
literal|0
block|,
name|MCI_GPM_COEX_PROFILE_RFCOMM
init|=
literal|1
block|,
name|MCI_GPM_COEX_PROFILE_A2DP
init|=
literal|2
block|,
name|MCI_GPM_COEX_PROFILE_HID
init|=
literal|3
block|,
name|MCI_GPM_COEX_PROFILE_BNEP
init|=
literal|4
block|,
name|MCI_GPM_COEX_PROFILE_VOICE
init|=
literal|5
block|,
name|MCI_GPM_COEX_PROFILE_MAX
block|}
name|MCI_GPM_COEX_PROFILE_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_profile_state
block|{
name|MCI_GPM_COEX_PROFILE_STATE_END
init|=
literal|0
block|,
name|MCI_GPM_COEX_PROFILE_STATE_START
init|=
literal|1
block|}
name|MCI_GPM_COEX_PROFILE_STATE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_profile_role
block|{
name|MCI_GPM_COEX_PROFILE_SLAVE
init|=
literal|0
block|,
name|MCI_GPM_COEX_PROFILE_MASTER
init|=
literal|1
block|}
name|MCI_GPM_COEX_PROFILE_ROLE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_bt_status_type
block|{
name|MCI_GPM_COEX_BT_NONLINK_STATUS
init|=
literal|0
block|,
name|MCI_GPM_COEX_BT_LINK_STATUS
init|=
literal|1
block|}
name|MCI_GPM_COEX_BT_STATUS_TYPE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_bt_status_state
block|{
name|MCI_GPM_COEX_BT_NORMAL_STATUS
init|=
literal|0
block|,
name|MCI_GPM_COEX_BT_CRITICAL_STATUS
init|=
literal|1
block|}
name|MCI_GPM_COEX_BT_STATUS_STATE_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MCI_GPM_INVALID_PROFILE_HANDLE
value|0xff
end_define

begin_typedef
typedef|typedef
enum|enum
name|mci_gpm_coex_bt_updata_flags_op
block|{
name|MCI_GPM_COEX_BT_FLAGS_READ
init|=
literal|0x00
block|,
name|MCI_GPM_COEX_BT_FLAGS_SET
init|=
literal|0x01
block|,
name|MCI_GPM_COEX_BT_FLAGS_CLEAR
init|=
literal|0x02
block|}
name|MCI_GPM_COEX_BT_FLAGS_OP_T
typedef|;
end_typedef

begin_comment
comment|/* MCI GPM/Coex opcode/type definitions */
end_comment

begin_enum
enum|enum
block|{
name|MCI_GPM_COEX_W_GPM_PAYLOAD
init|=
literal|1
block|,
name|MCI_GPM_COEX_B_GPM_TYPE
init|=
literal|4
block|,
name|MCI_GPM_COEX_B_GPM_OPCODE
init|=
literal|5
block|,
comment|/* MCI_GPM_WLAN_CAL_REQ, MCI_GPM_WLAN_CAL_DONE */
name|MCI_GPM_WLAN_CAL_W_SEQUENCE
init|=
literal|2
block|,
comment|/* MCI_GPM_COEX_VERSION_QUERY */
comment|/* MCI_GPM_COEX_VERSION_RESPONSE */
name|MCI_GPM_COEX_B_MAJOR_VERSION
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_MINOR_VERSION
init|=
literal|7
block|,
comment|/* MCI_GPM_COEX_STATUS_QUERY */
name|MCI_GPM_COEX_B_BT_BITMAP
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_WLAN_BITMAP
init|=
literal|7
block|,
comment|/* MCI_GPM_COEX_HALT_BT_GPM */
name|MCI_GPM_COEX_B_HALT_STATE
init|=
literal|6
block|,
comment|/* MCI_GPM_COEX_WLAN_CHANNELS */
name|MCI_GPM_COEX_B_CHANNEL_MAP
init|=
literal|6
block|,
comment|/* MCI_GPM_COEX_BT_PROFILE_INFO */
name|MCI_GPM_COEX_B_PROFILE_TYPE
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_PROFILE_LINKID
init|=
literal|7
block|,
name|MCI_GPM_COEX_B_PROFILE_STATE
init|=
literal|8
block|,
name|MCI_GPM_COEX_B_PROFILE_ROLE
init|=
literal|9
block|,
name|MCI_GPM_COEX_B_PROFILE_RATE
init|=
literal|10
block|,
name|MCI_GPM_COEX_B_PROFILE_VOTYPE
init|=
literal|11
block|,
name|MCI_GPM_COEX_H_PROFILE_T
init|=
literal|12
block|,
name|MCI_GPM_COEX_B_PROFILE_W
init|=
literal|14
block|,
name|MCI_GPM_COEX_B_PROFILE_A
init|=
literal|15
block|,
comment|/* MCI_GPM_COEX_BT_STATUS_UPDATE */
name|MCI_GPM_COEX_B_STATUS_TYPE
init|=
literal|6
block|,
name|MCI_GPM_COEX_B_STATUS_LINKID
init|=
literal|7
block|,
name|MCI_GPM_COEX_B_STATUS_STATE
init|=
literal|8
block|,
comment|/* MCI_GPM_COEX_BT_UPDATE_FLAGS */
name|MCI_GPM_COEX_B_BT_FLAGS_OP
init|=
literal|10
block|,
name|MCI_GPM_COEX_W_BT_FLAGS
init|=
literal|6
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MCI_GPM_RECYCLE
parameter_list|(
name|_p_gpm
parameter_list|)
define|\
value|{                           \         *(((u_int32_t *)(_p_gpm)) + MCI_GPM_COEX_W_GPM_PAYLOAD) = MCI_GPM_RSVD_PATTERN32; \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_TYPE
parameter_list|(
name|_p_gpm
parameter_list|)
define|\
value|(*(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_TYPE)& 0xff)
end_define

begin_define
define|#
directive|define
name|MCI_GPM_OPCODE
parameter_list|(
name|_p_gpm
parameter_list|)
define|\
value|(*(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_OPCODE)& 0xff)
end_define

begin_define
define|#
directive|define
name|MCI_GPM_SET_CAL_TYPE
parameter_list|(
name|_p_gpm
parameter_list|,
name|_cal_type
parameter_list|)
define|\
value|{                                                       \         *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_TYPE) = (_cal_type)& 0xff; \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_SET_TYPE_OPCODE
parameter_list|(
name|_p_gpm
parameter_list|,
name|_type
parameter_list|,
name|_opcode
parameter_list|)
define|\
value|{                                                       \         *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_TYPE) = (_type)& 0xff;     \         *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_GPM_OPCODE) = (_opcode)& 0xff;   \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_IS_CAL_TYPE
parameter_list|(
name|_type
parameter_list|)
value|((_type)<= MCI_GPM_WLAN_CAL_DONE)
end_define

begin_define
define|#
directive|define
name|MCI_NUM_BT_CHANNELS
value|79
end_define

begin_define
define|#
directive|define
name|MCI_GPM_SET_CHANNEL_BIT
parameter_list|(
name|_p_gpm
parameter_list|,
name|_bt_chan
parameter_list|)
define|\
value|{                                                               \         if (_bt_chan< MCI_NUM_BT_CHANNELS) {                       \             *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_CHANNEL_MAP + \                 (_bt_chan / 8)) |= 1<< (_bt_chan& 7);             \         }                                                           \     }
end_define

begin_define
define|#
directive|define
name|MCI_GPM_CLR_CHANNEL_BIT
parameter_list|(
name|_p_gpm
parameter_list|,
name|_bt_chan
parameter_list|)
define|\
value|{                                                               \         if (_bt_chan< MCI_NUM_BT_CHANNELS) {                       \             *(((u_int8_t *)(_p_gpm)) + MCI_GPM_COEX_B_CHANNEL_MAP + \                 (_bt_chan / 8))&= ~(1<< (_bt_chan& 7));          \         }                                                           \     }
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_SW_MSG_DONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_CPU_INT_MSG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_CHKSUM_FAIL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_INVALID_HDR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_HW_MSG_FAIL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_SW_MSG_FAIL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_TX_HW_MSG_FAIL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_TX_SW_MSG_FAIL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_REMOTE_SLEEP_UPDATE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_CONT_INFO_TIMEOUT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_MSG_FAIL_MASK
value|( HAL_MCI_INTERRUPT_RX_HW_MSG_FAIL | \                                           HAL_MCI_INTERRUPT_RX_SW_MSG_FAIL | \                                           HAL_MCI_INTERRUPT_TX_HW_MSG_FAIL | \                                           HAL_MCI_INTERRUPT_TX_SW_MSG_FAIL )
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_REMOTE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_LNA_CONTROL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CONT_NACK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CONT_INFO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CONT_RST
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_SCHD_INFO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_CPU_INT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_GPM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_LNA_INFO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_SYS_SLEEPING
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_SYS_WAKING
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_REQ_WAKE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_INTERRUPT_RX_MSG_MONITOR
value|(HAL_MCI_INTERRUPT_RX_MSG_LNA_CONTROL | \                                                   HAL_MCI_INTERRUPT_RX_MSG_LNA_INFO    | \                                                   HAL_MCI_INTERRUPT_RX_MSG_CONT_NACK   | \                                                   HAL_MCI_INTERRUPT_RX_MSG_CONT_INFO   | \                                                   HAL_MCI_INTERRUPT_RX_MSG_CONT_RST)
end_define

begin_typedef
typedef|typedef
enum|enum
name|mci_bt_state
block|{
name|MCI_BT_SLEEP
block|,
name|MCI_BT_AWAKE
block|,
name|MCI_BT_CAL_START
block|,
name|MCI_BT_CAL
block|}
name|MCI_BT_STATE_T
typedef|;
end_typedef

begin_comment
comment|/* Type of state query */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|mci_state_type
block|{
name|HAL_MCI_STATE_ENABLE
block|,
name|HAL_MCI_STATE_INIT_GPM_OFFSET
block|,
name|HAL_MCI_STATE_NEXT_GPM_OFFSET
block|,
name|HAL_MCI_STATE_LAST_GPM_OFFSET
block|,
name|HAL_MCI_STATE_BT
block|,
name|HAL_MCI_STATE_SET_BT_SLEEP
block|,
name|HAL_MCI_STATE_SET_BT_AWAKE
block|,
name|HAL_MCI_STATE_SET_BT_CAL_START
block|,
name|HAL_MCI_STATE_SET_BT_CAL
block|,
name|HAL_MCI_STATE_LAST_SCHD_MSG_OFFSET
block|,
name|HAL_MCI_STATE_REMOTE_SLEEP
block|,
name|HAL_MCI_STATE_CONT_RSSI_POWER
block|,
name|HAL_MCI_STATE_CONT_PRIORITY
block|,
name|HAL_MCI_STATE_CONT_TXRX
block|,
name|HAL_MCI_STATE_RESET_REQ_WAKE
block|,
name|HAL_MCI_STATE_SEND_WLAN_COEX_VERSION
block|,
name|HAL_MCI_STATE_SET_BT_COEX_VERSION
block|,
name|HAL_MCI_STATE_SEND_WLAN_CHANNELS
block|,
name|HAL_MCI_STATE_SEND_VERSION_QUERY
block|,
name|HAL_MCI_STATE_SEND_STATUS_QUERY
block|,
name|HAL_MCI_STATE_NEED_FLUSH_BT_INFO
block|,
name|HAL_MCI_STATE_SET_CONCUR_TX_PRI
block|,
name|HAL_MCI_STATE_RECOVER_RX
block|,
name|HAL_MCI_STATE_NEED_FTP_STOMP
block|,
name|HAL_MCI_STATE_NEED_TUNING
block|,
name|HAL_MCI_STATE_SHARED_CHAIN_CONCUR_TX
block|,
name|HAL_MCI_STATE_DEBUG
block|,
name|HAL_MCI_STATE_MAX
block|}
name|HAL_MCI_STATE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAL_MCI_STATE_DEBUG_REQ_BT_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_UPDATE_CORR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_UPDATE_HDR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_UPDATE_PLD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_LNA_CTRL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_DEBUG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_SCHED_MSG
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_CONT_MSG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_COEX_GPM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_CPU_INT_MSG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_MCI_MODE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_EGRET_MODE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_JUPITER_MODE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_BT_MCI_FLAGS_OTHER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_DEFAULT_BT_MCI_FLAGS
value|0x00011dde
end_define

begin_comment
comment|/*     HAL_MCI_BT_MCI_FLAGS_UPDATE_CORR  = 1     HAL_MCI_BT_MCI_FLAGS_UPDATE_HDR   = 1     HAL_MCI_BT_MCI_FLAGS_UPDATE_PLD   = 1     HAL_MCI_BT_MCI_FLAGS_LNA_CTRL     = 1     HAL_MCI_BT_MCI_FLAGS_DEBUG        = 0     HAL_MCI_BT_MCI_FLAGS_SCHED_MSG    = 1     HAL_MCI_BT_MCI_FLAGS_CONT_MSG     = 1     HAL_MCI_BT_MCI_FLAGS_COEX_GPM     = 1     HAL_MCI_BT_MCI_FLAGS_CPU_INT_MSG  = 0     HAL_MCI_BT_MCI_FLAGS_MCI_MODE     = 1     HAL_MCI_BT_MCI_FLAGS_EGRET_MODE   = 1     HAL_MCI_BT_MCI_FLAGS_JUPITER_MODE = 1     HAL_MCI_BT_MCI_FLAGS_OTHER        = 1 */
end_comment

begin_define
define|#
directive|define
name|HAL_MCI_TOGGLE_BT_MCI_FLAGS
define|\
value|(   HAL_MCI_BT_MCI_FLAGS_UPDATE_CORR    |   \         HAL_MCI_BT_MCI_FLAGS_UPDATE_HDR     |   \         HAL_MCI_BT_MCI_FLAGS_UPDATE_PLD     |   \         HAL_MCI_BT_MCI_FLAGS_MCI_MODE   )
end_define

begin_define
define|#
directive|define
name|HAL_MCI_2G_FLAGS_CLEAR_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_2G_FLAGS_SET_MASK
value|HAL_MCI_TOGGLE_BT_MCI_FLAGS
end_define

begin_define
define|#
directive|define
name|HAL_MCI_2G_FLAGS
value|HAL_MCI_DEFAULT_BT_MCI_FLAGS
end_define

begin_define
define|#
directive|define
name|HAL_MCI_5G_FLAGS_CLEAR_MASK
value|HAL_MCI_TOGGLE_BT_MCI_FLAGS
end_define

begin_define
define|#
directive|define
name|HAL_MCI_5G_FLAGS_SET_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HAL_MCI_5G_FLAGS
value|(HAL_MCI_DEFAULT_BT_MCI_FLAGS& \                                             ~HAL_MCI_TOGGLE_BT_MCI_FLAGS)
end_define

begin_define
define|#
directive|define
name|HAL_MCI_GPM_NOMORE
value|0
end_define

begin_define
define|#
directive|define
name|HAL_MCI_GPM_MORE
value|1
end_define

begin_define
define|#
directive|define
name|HAL_MCI_GPM_INVALID
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ATH_AIC_MAX_BT_CHANNEL
value|79
end_define

begin_comment
comment|/*  * Default value for Jupiter   is 0x00002201  * Default value for Aphrodite is 0x00002282  */
end_comment

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_CONCUR_TX
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_MCI
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_TXRX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_BT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_MCI_CAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_OSLA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_FTP_STOMP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_AGGR_THRESH
value|0x00000700
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_AGGR_THRESH_S
value|8
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_AGGR_THRESH
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_CLK_DIV
value|0x00003000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_CLK_DIV_S
value|12
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_TUNING
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_WEIGHT_DBG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_DISABLE_MCI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_MASK
value|( ATH_MCI_CONFIG_MCI_OBS_MCI | \                                           ATH_MCI_CONFIG_MCI_OBS_TXRX | \                                           ATH_MCI_CONFIG_MCI_OBS_BT )
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONFIG_MCI_OBS_GPIO
value|0x0000002F
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_SHARED_CHN
value|0x01
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_UNSHARED_CHN
value|0x02
end_define

begin_define
define|#
directive|define
name|ATH_MCI_CONCUR_TX_DEBUG
value|0x03
end_define

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

