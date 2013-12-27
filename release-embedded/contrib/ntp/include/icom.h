begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file for ICOM radios  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/*  * Common definitions  */
end_comment

begin_define
define|#
directive|define
name|P_ERMSG
value|0x1
end_define

begin_comment
comment|/* trace bus error messages */
end_comment

begin_define
define|#
directive|define
name|P_TRACE
value|0x2
end_define

begin_comment
comment|/* trace CI-V messges */
end_comment

begin_define
define|#
directive|define
name|RETRY
value|3
end_define

begin_comment
comment|/* max packet retries */
end_comment

begin_define
define|#
directive|define
name|IBAUD
value|B1200
end_define

begin_comment
comment|/* autotune port speed */
end_comment

begin_comment
comment|/*  * Radio identifier codes  */
end_comment

begin_define
define|#
directive|define
name|IC1271
value|0x24
end_define

begin_define
define|#
directive|define
name|IC1275
value|0x18
end_define

begin_define
define|#
directive|define
name|IC271
value|0x20
end_define

begin_define
define|#
directive|define
name|IC275
value|0x10
end_define

begin_define
define|#
directive|define
name|IC375
value|0x12
end_define

begin_define
define|#
directive|define
name|IC471
value|0x22
end_define

begin_define
define|#
directive|define
name|IC475
value|0x14
end_define

begin_define
define|#
directive|define
name|IC575
value|0x16
end_define

begin_define
define|#
directive|define
name|IC725
value|0x28
end_define

begin_define
define|#
directive|define
name|IC726
value|0x30
end_define

begin_define
define|#
directive|define
name|IC735
value|0x04
end_define

begin_define
define|#
directive|define
name|IC751
value|0x1c
end_define

begin_define
define|#
directive|define
name|IC761
value|0x1e
end_define

begin_define
define|#
directive|define
name|IC765
value|0x2c
end_define

begin_define
define|#
directive|define
name|IC775
value|0x46
end_define

begin_define
define|#
directive|define
name|IC781
value|0x26
end_define

begin_define
define|#
directive|define
name|IC970
value|0x2e
end_define

begin_define
define|#
directive|define
name|R7000
value|0x08
end_define

begin_define
define|#
directive|define
name|R71
value|0x1a
end_define

begin_define
define|#
directive|define
name|R7100
value|0x34
end_define

begin_define
define|#
directive|define
name|R72
value|0x32
end_define

begin_define
define|#
directive|define
name|R8500
value|0x4a
end_define

begin_define
define|#
directive|define
name|R9000
value|0x2a
end_define

begin_comment
comment|/*  * CI-V frame codes  */
end_comment

begin_define
define|#
directive|define
name|PR
value|0xfe
end_define

begin_comment
comment|/* preamble */
end_comment

begin_define
define|#
directive|define
name|TX
value|0xe0
end_define

begin_comment
comment|/* controller address */
end_comment

begin_define
define|#
directive|define
name|FI
value|0xfd
end_define

begin_comment
comment|/* end of message */
end_comment

begin_define
define|#
directive|define
name|ACK
value|0xfb
end_define

begin_comment
comment|/* controller normal reply */
end_comment

begin_define
define|#
directive|define
name|NAK
value|0xfa
end_define

begin_comment
comment|/* controller error reply */
end_comment

begin_define
define|#
directive|define
name|PAD
value|0xff
end_define

begin_comment
comment|/* transmit padding */
end_comment

begin_comment
comment|/*  * CI-V controller commands  */
end_comment

begin_define
define|#
directive|define
name|V_FREQT
value|0x00
end_define

begin_comment
comment|/* freq set (transceive) */
end_comment

begin_define
define|#
directive|define
name|V_MODET
value|0x01
end_define

begin_comment
comment|/* set mode (transceive) */
end_comment

begin_define
define|#
directive|define
name|V_RBAND
value|0x02
end_define

begin_comment
comment|/* read band edge */
end_comment

begin_define
define|#
directive|define
name|V_RFREQ
value|0x03
end_define

begin_comment
comment|/* read frequency */
end_comment

begin_define
define|#
directive|define
name|V_RMODE
value|0x04
end_define

begin_comment
comment|/* read mode */
end_comment

begin_define
define|#
directive|define
name|V_SFREQ
value|0x05
end_define

begin_comment
comment|/* set frequency */
end_comment

begin_define
define|#
directive|define
name|V_SMODE
value|0x06
end_define

begin_comment
comment|/* set mode */
end_comment

begin_define
define|#
directive|define
name|V_SVFO
value|0x07
end_define

begin_comment
comment|/* select vfo */
end_comment

begin_define
define|#
directive|define
name|V_SMEM
value|0x08
end_define

begin_comment
comment|/* select channel/bank */
end_comment

begin_define
define|#
directive|define
name|V_WRITE
value|0x09
end_define

begin_comment
comment|/* write channel */
end_comment

begin_define
define|#
directive|define
name|V_VFOM
value|0x0a
end_define

begin_comment
comment|/* memory -> vfo */
end_comment

begin_define
define|#
directive|define
name|V_CLEAR
value|0x0b
end_define

begin_comment
comment|/* clear channel */
end_comment

begin_define
define|#
directive|define
name|V_ROFFS
value|0x0c
end_define

begin_comment
comment|/* read tx offset */
end_comment

begin_define
define|#
directive|define
name|V_SOFFS
value|0x0d
end_define

begin_comment
comment|/* write tx offset */
end_comment

begin_define
define|#
directive|define
name|V_SCAN
value|0x0e
end_define

begin_comment
comment|/* scan control */
end_comment

begin_define
define|#
directive|define
name|V_SPLIT
value|0x0f
end_define

begin_comment
comment|/* split control */
end_comment

begin_define
define|#
directive|define
name|V_DIAL
value|0x10
end_define

begin_comment
comment|/* set dial tuning step */
end_comment

begin_define
define|#
directive|define
name|V_ATTEN
value|0x11
end_define

begin_comment
comment|/* set attenuator */
end_comment

begin_define
define|#
directive|define
name|V_SANT
value|0x12
end_define

begin_comment
comment|/* select antenna */
end_comment

begin_define
define|#
directive|define
name|V_ANNC
value|0x13
end_define

begin_comment
comment|/* announce control */
end_comment

begin_define
define|#
directive|define
name|V_WRCTL
value|0x14
end_define

begin_comment
comment|/* write controls */
end_comment

begin_define
define|#
directive|define
name|V_RDCTL
value|0x15
end_define

begin_comment
comment|/* read controls */
end_comment

begin_define
define|#
directive|define
name|V_TOGL
value|0x16
end_define

begin_comment
comment|/* set switches */
end_comment

begin_define
define|#
directive|define
name|V_ASCII
value|0x17
end_define

begin_comment
comment|/* send CW message */
end_comment

begin_define
define|#
directive|define
name|V_POWER
value|0x18
end_define

begin_comment
comment|/* power control */
end_comment

begin_define
define|#
directive|define
name|V_RDID
value|0x19
end_define

begin_comment
comment|/* read model ID */
end_comment

begin_define
define|#
directive|define
name|V_SETW
value|0x1a
end_define

begin_comment
comment|/* read/write channel/bank data */
end_comment

begin_define
define|#
directive|define
name|V_CTRL
value|0x7f
end_define

begin_comment
comment|/* miscellaneous control */
end_comment

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
name|int
name|icom_init
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|icom_freq
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

