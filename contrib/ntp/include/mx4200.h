begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* records transmitted from extern CDU to MX 4200 */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_INITMODEA
value|0
end_define

begin_comment
comment|/* initialization/mode part A */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_INITMODEB
value|1
end_define

begin_comment
comment|/* initialization/mode part B*/
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_SATHEALTH
value|2
end_define

begin_comment
comment|/* satellite health control */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_DIFFNAV
value|3
end_define

begin_comment
comment|/* differential navigation control */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_PORTCONF
value|7
end_define

begin_comment
comment|/* control port configuration */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_GETSELFTEST
value|13
end_define

begin_comment
comment|/* self test (request results) */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_RTCMCONF
value|16
end_define

begin_comment
comment|/* RTCM port configuration */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_PASSTHRU
value|17
end_define

begin_comment
comment|/* equipment port pass-thru config */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_RESTART
value|18
end_define

begin_comment
comment|/* restart control */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_OSCPARAM
value|19
end_define

begin_comment
comment|/* oscillator parameter */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_DOSELFTEST
value|20
end_define

begin_comment
comment|/* self test (activate a test) */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_TRECOVCONF
value|23
end_define

begin_comment
comment|/* time recovery configuration */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_RAWDATASEL
value|24
end_define

begin_comment
comment|/* raw data port data selection */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_EQUIPCONF
value|26
end_define

begin_comment
comment|/* equipment port configuration */
end_comment

begin_define
define|#
directive|define
name|PMVXG_S_RAWDATACONF
value|27
end_define

begin_comment
comment|/* raw data port configuration */
end_comment

begin_comment
comment|/* records transmitted from MX 4200 to external CDU */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_STATUS
value|0
end_define

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_POSITION
value|1
end_define

begin_comment
comment|/* position */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_OPDOPS
value|3
end_define

begin_comment
comment|/* (optimum) DOPs */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_MODEDATA
value|4
end_define

begin_comment
comment|/* mode data */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SATPRED
value|5
end_define

begin_comment
comment|/* satellite predictions */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SATHEALTH
value|6
end_define

begin_comment
comment|/* satellite health status */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_UNRECOG
value|7
end_define

begin_comment
comment|/* unrecognized request response */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SIGSTRLOC
value|8
end_define

begin_comment
comment|/* sig strength& location (sats 1-4) */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SPEEDHEAD
value|11
end_define

begin_comment
comment|/* speed/heading data */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_OSELFTEST
value|12
end_define

begin_comment
comment|/* (old) self-test results */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SIGSTRLOC2
value|18
end_define

begin_comment
comment|/* sig strength& location (sats 5-8) */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_OSCPARAM
value|19
end_define

begin_comment
comment|/* oscillator parameter */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SELFTEST
value|20
end_define

begin_comment
comment|/* self test results */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_PHV
value|21
end_define

begin_comment
comment|/* position, height& velocity */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_DOPS
value|22
end_define

begin_comment
comment|/* DOPs */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_SOFTCONF
value|30
end_define

begin_comment
comment|/* software configuration */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_DIFFGPSMODE
value|503
end_define

begin_comment
comment|/* differential gps moding */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_TRECOVUSEAGE
value|523
end_define

begin_comment
comment|/* time recovery usage */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_RAWDATAOUT
value|524
end_define

begin_comment
comment|/* raw data port data output */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_TRECOVRESULT
value|828
end_define

begin_comment
comment|/* time recovery results */
end_comment

begin_define
define|#
directive|define
name|PMVXG_D_TRECOVOUT
value|830
end_define

begin_comment
comment|/* time recovery output message */
end_comment

end_unit

