begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Cronyx Tau-PCI DDK definitions.  *  * Copyright (C) 1999-2003 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * Copyright (C) 2000-2004 Cronyx Engineering.  * Author: Roman Kurakin,<rik@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations a permission to use,  * modify and redistribute this software in source and binary forms,  * as long as this message is kept with the software, all derivative  * works or modified versions.  *  * $Cronyx: cpddk.h,v 1.8.4.20 2004/12/06 16:21:06 rik Exp $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NBRD
value|6
end_define

begin_comment
comment|/* the maximum number of installed boards */
end_comment

begin_define
define|#
directive|define
name|NCHAN
value|4
end_define

begin_comment
comment|/* the number of channels on the board */
end_comment

begin_define
define|#
directive|define
name|NRBUF
value|64
end_define

begin_comment
comment|/* the number of receive buffers per channel, 				   min 2 */
end_comment

begin_define
define|#
directive|define
name|NTBUF
value|4
end_define

begin_comment
comment|/* the number of transmit buffers per channel */
end_comment

begin_define
define|#
directive|define
name|BUFSZ
value|1664
end_define

begin_comment
comment|/* i/o buffer size (26*64, min 1601) */
end_comment

begin_define
define|#
directive|define
name|QSZ
value|128
end_define

begin_comment
comment|/* intr queue size (multiple of 32, min 32) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPDDK_COBF_SAFE
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|bpv
decl_stmt|;
comment|/* bipolar violations */
name|unsigned
name|long
name|fse
decl_stmt|;
comment|/* frame sync errors */
name|unsigned
name|long
name|crce
decl_stmt|;
comment|/* CRC errors */
name|unsigned
name|long
name|rcrce
decl_stmt|;
comment|/* remote CRC errors (E-bit) */
name|unsigned
name|long
name|uas
decl_stmt|;
comment|/* unavailable seconds */
name|unsigned
name|long
name|les
decl_stmt|;
comment|/* line errored seconds */
name|unsigned
name|long
name|es
decl_stmt|;
comment|/* errored seconds */
name|unsigned
name|long
name|bes
decl_stmt|;
comment|/* bursty errored seconds */
name|unsigned
name|long
name|ses
decl_stmt|;
comment|/* severely errored seconds */
name|unsigned
name|long
name|oofs
decl_stmt|;
comment|/* out of frame seconds */
name|unsigned
name|long
name|css
decl_stmt|;
comment|/* controlled slip seconds */
name|unsigned
name|long
name|dm
decl_stmt|;
comment|/* degraded minutes */
block|}
name|cp_gstat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* cross-connector parameters */
name|unsigned
name|char
name|ts
index|[
literal|32
index|]
decl_stmt|;
comment|/* timeslot number */
name|unsigned
name|char
name|link
index|[
literal|32
index|]
decl_stmt|;
comment|/* E1 link number */
block|}
name|cp_dxc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|len
decl_stmt|;
comment|/* data buffer length, fe, hold, hi */
define|#
directive|define
name|DESC_FE
value|0x80000000
define|#
directive|define
name|DESC_HOLD
value|0x40000000
define|#
directive|define
name|DESC_HI
value|0x20000000
define|#
directive|define
name|DESC_LEN
parameter_list|(
name|v
parameter_list|)
value|((v)>> 16& 0x1fff)
name|unsigned
name|long
name|next
decl_stmt|;
comment|/* next descriptor pointer */
name|unsigned
name|long
name|data
decl_stmt|;
comment|/* pointer to data buffer */
name|unsigned
name|long
name|status
decl_stmt|;
comment|/* complete, receive abort, fe, len */
define|#
directive|define
name|DESC_RA
value|0x00000200
define|#
directive|define
name|DESC_C
value|0x40000000
name|unsigned
name|long
name|fe
decl_stmt|;
comment|/* pointer to frame end descriptor */
block|}
name|cp_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|cp_desc_t
name|tdesc
index|[
name|NTBUF
index|]
decl_stmt|;
comment|/* transmit buffer descriptors */
name|cp_desc_t
name|rdesc
index|[
name|NRBUF
index|]
decl_stmt|;
comment|/* receive buffer descriptors */
name|unsigned
name|char
name|tbuffer
index|[
name|NTBUF
index|]
index|[
name|BUFSZ
index|]
decl_stmt|;
comment|/* transmit buffers */
name|unsigned
name|char
name|rbuffer
index|[
name|NRBUF
index|]
index|[
name|BUFSZ
index|]
decl_stmt|;
comment|/* receive buffers  */
block|}
name|cp_buf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|iqrx
index|[
name|NCHAN
index|]
index|[
name|QSZ
index|]
decl_stmt|;
comment|/* rx intr queue */
name|unsigned
name|long
name|iqtx
index|[
name|NCHAN
index|]
index|[
name|QSZ
index|]
decl_stmt|;
comment|/* tx intr queue */
name|unsigned
name|long
name|iqlx
index|[
name|QSZ
index|]
decl_stmt|;
comment|/* LBI intr queue */
block|}
name|cp_qbuf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_cp_chan_t
block|{
name|unsigned
name|char
modifier|*
name|regs
decl_stmt|;
comment|/* base addr of channel registers */
specifier|volatile
name|unsigned
name|long
modifier|*
name|RXBAR
decl_stmt|,
modifier|*
name|TXBAR
decl_stmt|,
modifier|*
name|CFG
decl_stmt|;
specifier|volatile
name|unsigned
name|long
modifier|*
name|BRDA
decl_stmt|,
modifier|*
name|FRDA
decl_stmt|,
modifier|*
name|LRDA
decl_stmt|,
modifier|*
name|BTDA
decl_stmt|,
modifier|*
name|FTDA
decl_stmt|,
modifier|*
name|LTDA
decl_stmt|;
name|unsigned
name|char
name|CCR
decl_stmt|,
name|CSR
decl_stmt|,
name|GMD
decl_stmt|,
name|GLS
decl_stmt|,
name|E1CS
decl_stmt|,
name|E1CR
decl_stmt|,
name|E1EPS
decl_stmt|;
name|unsigned
name|char
name|num
decl_stmt|;
comment|/* channel number, 0..1 */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* channel type */
define|#
directive|define
name|T_NONE
value|0
comment|/* no channel */
define|#
directive|define
name|T_SERIAL
value|1
comment|/* V.35/RS */
define|#
directive|define
name|T_G703
value|2
comment|/* G.703 */
define|#
directive|define
name|T_E1
value|3
comment|/* E1 */
define|#
directive|define
name|T_E3
value|4
comment|/* E3 */
define|#
directive|define
name|T_HSSI
value|5
comment|/* HSSI */
define|#
directive|define
name|T_DATA
value|6
comment|/* no physical interface */
define|#
directive|define
name|T_T3
value|7
comment|/* T3 */
define|#
directive|define
name|T_STS1
value|8
comment|/* STS1 */
name|struct
name|_cp_board_t
modifier|*
name|board
decl_stmt|;
comment|/* board pointer */
name|unsigned
name|char
name|dtr
decl_stmt|;
comment|/* DTR signal value */
name|unsigned
name|char
name|rts
decl_stmt|;
comment|/* RTS signal value */
name|unsigned
name|long
name|baud
decl_stmt|;
comment|/* data rate, bps */
name|unsigned
name|char
name|dpll
decl_stmt|;
comment|/* dpll mode */
name|unsigned
name|char
name|nrzi
decl_stmt|;
comment|/* nrzi mode */
name|unsigned
name|char
name|invtxc
decl_stmt|;
comment|/* invert tx clock */
name|unsigned
name|char
name|invrxc
decl_stmt|;
comment|/* invert rx clock */
name|unsigned
name|char
name|lloop
decl_stmt|;
comment|/* local loopback mode */
name|unsigned
name|char
name|rloop
decl_stmt|;
comment|/* remote loopback mode */
name|unsigned
name|char
name|gsyn
decl_stmt|;
comment|/* G.703 clock mode */
define|#
directive|define
name|GSYN_INT
value|0
comment|/* internal transmit clock source */
define|#
directive|define
name|GSYN_RCV
value|1
comment|/* transmit clock source = receive */
define|#
directive|define
name|GSYN_RCV0
value|2
comment|/* tclk = rclk from channel 0 */
define|#
directive|define
name|GSYN_RCV1
value|3
comment|/* ...from channel 1 */
define|#
directive|define
name|GSYN_RCV2
value|4
comment|/* ...from channel 2 */
define|#
directive|define
name|GSYN_RCV3
value|5
comment|/* ...from channel 3 */
name|unsigned
name|char
name|scrambler
decl_stmt|;
comment|/* G.703 scrambler enable */
name|unsigned
name|long
name|ts
decl_stmt|;
comment|/* E1 timeslot mask */
name|unsigned
name|char
name|higain
decl_stmt|;
comment|/* E1 high gain mode */
name|unsigned
name|char
name|use16
decl_stmt|;
comment|/* E1 use ts 16 */
name|unsigned
name|char
name|crc4
decl_stmt|;
comment|/* E1 enable CRC4 */
name|unsigned
name|char
name|phony
decl_stmt|;
comment|/* E1 phony mode */
name|unsigned
name|char
name|unfram
decl_stmt|;
comment|/* E1 unframed mode */
name|unsigned
name|char
name|monitor
decl_stmt|;
comment|/* E1 monitoring mode */
name|unsigned
name|char
name|dir
decl_stmt|;
comment|/* E1 direction mode */
name|cp_dxc_t
name|dxc
decl_stmt|;
comment|/* E1 cross-connect params */
name|unsigned
name|char
name|ais
decl_stmt|;
comment|/* E3 AIS */
name|unsigned
name|char
name|losais
decl_stmt|;
comment|/* E3 AIS on LOS*/
name|unsigned
name|char
name|ber
decl_stmt|;
comment|/* E3 BER */
name|unsigned
name|char
name|cablen
decl_stmt|;
comment|/* E3 cable length */
name|unsigned
name|char
name|e3cr1
decl_stmt|;
comment|/* e3cr1 clone */
name|unsigned
name|char
name|scc_ien
decl_stmt|;
comment|/* SCC Interrupts enabled */
name|unsigned
name|char
name|ds_ien
decl_stmt|;
comment|/* DS Interrupts enabled */
name|unsigned
name|long
name|imr
decl_stmt|;
name|unsigned
name|char
name|ccr
decl_stmt|;
comment|/* CCR image */
name|unsigned
name|long
name|ccr0
decl_stmt|;
comment|/* CCR0 clone */
name|unsigned
name|long
name|ccr1
decl_stmt|;
comment|/* CCR1 clone */
name|unsigned
name|long
name|ccr2
decl_stmt|;
comment|/* CCR2 clone */
name|unsigned
name|char
name|gmd
decl_stmt|;
comment|/* G.703 MDi register image */
name|unsigned
name|char
name|e1cr
decl_stmt|;
comment|/* E1 CR register image */
name|unsigned
name|char
name|ds21x54
decl_stmt|;
comment|/* new tranceiver flag */
name|unsigned
name|long
name|rintr
decl_stmt|;
comment|/* receive interrupts */
name|unsigned
name|long
name|tintr
decl_stmt|;
comment|/* transmit interrupts */
name|ulong64
name|ibytes
decl_stmt|;
comment|/* input bytes */
name|ulong64
name|obytes
decl_stmt|;
comment|/* output bytes */
name|unsigned
name|long
name|ipkts
decl_stmt|;
comment|/* input packets */
name|unsigned
name|long
name|opkts
decl_stmt|;
comment|/* output packets */
name|unsigned
name|long
name|underrun
decl_stmt|;
comment|/* output underrun errors */
name|unsigned
name|long
name|overrun
decl_stmt|;
comment|/* input overrun errors */
name|unsigned
name|long
name|frame
decl_stmt|;
comment|/* input frame errors */
name|unsigned
name|long
name|crc
decl_stmt|;
comment|/* input crc errors */
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* E1/G.703 line status bit mask */
define|#
directive|define
name|ESTS_NOALARM
value|0x0001
comment|/* no alarm present */
define|#
directive|define
name|ESTS_FARLOF
value|0x0002
comment|/* receiving far loss of framing */
define|#
directive|define
name|ESTS_AIS
value|0x0008
comment|/* receiving all ones */
define|#
directive|define
name|ESTS_LOF
value|0x0020
comment|/* loss of framing */
define|#
directive|define
name|ESTS_LOS
value|0x0040
comment|/* loss of signal */
define|#
directive|define
name|ESTS_AIS16
value|0x0100
comment|/* receiving all ones in timeslot 16 */
define|#
directive|define
name|ESTS_FARLOMF
value|0x0200
comment|/* receiving alarm in timeslot 16 */
define|#
directive|define
name|ESTS_LOMF
value|0x0400
comment|/* loss of multiframe sync */
define|#
directive|define
name|ESTS_TSTREQ
value|0x0800
comment|/* test code detected */
define|#
directive|define
name|ESTS_TSTERR
value|0x1000
comment|/* test error */
name|unsigned
name|long
name|totsec
decl_stmt|;
comment|/* total seconds elapsed */
name|unsigned
name|long
name|cursec
decl_stmt|;
comment|/* current seconds elapsed */
name|unsigned
name|long
name|degsec
decl_stmt|;
comment|/* degraded seconds */
name|unsigned
name|long
name|degerr
decl_stmt|;
comment|/* errors during degraded seconds */
name|cp_gstat_t
name|currnt
decl_stmt|;
comment|/* current 15-min interval data */
name|cp_gstat_t
name|total
decl_stmt|;
comment|/* total statistics data */
name|cp_gstat_t
name|interval
index|[
literal|48
index|]
decl_stmt|;
comment|/* 12 hour period data */
name|unsigned
name|long
name|e3status
decl_stmt|;
comment|/* E3 status */
define|#
directive|define
name|E3STS_LOS
value|0x00000002
comment|/* Lost of synchronization */
define|#
directive|define
name|E3STS_TXE
value|0x00000004
comment|/* Transmit error */
define|#
directive|define
name|E3STS_AIS
value|0x00000008
comment|/* Transmit error */
name|unsigned
name|long
name|e3csec_5
decl_stmt|;
comment|/* 1/5 of second counter */
name|unsigned
name|long
name|e3tsec
decl_stmt|;
comment|/* total seconds coounter */
name|unsigned
name|long
name|e3ccv
decl_stmt|;
comment|/* E3 current 15-min cv errors */
name|unsigned
name|long
name|e3tcv
decl_stmt|;
comment|/* E3 total cv errors */
name|unsigned
name|long
name|e3icv
index|[
literal|48
index|]
decl_stmt|;
comment|/* E3 12 hour period cv errors */
name|unsigned
name|long
modifier|*
name|iqrx
decl_stmt|;
comment|/* rx intr queue */
name|unsigned
name|long
modifier|*
name|iqtx
decl_stmt|;
comment|/* tx intr queue */
name|int
name|irn
decl_stmt|,
name|itn
decl_stmt|;
name|unsigned
name|char
modifier|*
name|tbuf
index|[
name|NTBUF
index|]
decl_stmt|;
comment|/* transmit buffers */
name|cp_desc_t
modifier|*
name|tdesc
decl_stmt|;
comment|/* transmit buffer descriptors */
name|unsigned
name|long
name|tphys
index|[
name|NTBUF
index|]
decl_stmt|;
comment|/* transmit buffer phys address */
name|unsigned
name|long
name|tdphys
index|[
name|NTBUF
index|]
decl_stmt|;
comment|/* transmit descr phys addresses */
name|int
name|tn
decl_stmt|;
comment|/* first active transmit buffer */
name|int
name|te
decl_stmt|;
comment|/* first empty transmit buffer */
name|unsigned
name|char
modifier|*
name|rbuf
index|[
name|NRBUF
index|]
decl_stmt|;
comment|/* receive buffers */
name|cp_desc_t
modifier|*
name|rdesc
decl_stmt|;
comment|/* receive buffer descriptors */
name|unsigned
name|long
name|rphys
index|[
name|NRBUF
index|]
decl_stmt|;
comment|/* receive buffer phys address */
name|unsigned
name|long
name|rdphys
index|[
name|NRBUF
index|]
decl_stmt|;
comment|/* receive descr phys addresses */
name|int
name|rn
decl_stmt|;
comment|/* first active receive buffer */
name|void
modifier|*
name|tag
index|[
name|NTBUF
index|]
decl_stmt|;
comment|/* system dependent data per buffer */
name|void
modifier|*
name|sys
decl_stmt|;
comment|/* system dependent data per channel */
name|unsigned
name|char
name|debug
decl_stmt|;
comment|/* debug level, 0..2 */
name|void
function_decl|(
modifier|*
name|transmit
function_decl|)
parameter_list|(
name|struct
name|_cp_chan_t
modifier|*
name|c
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|receive
function_decl|)
parameter_list|(
name|struct
name|_cp_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|error
function_decl|)
parameter_list|(
name|struct
name|_cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
define|#
directive|define
name|CP_FRAME
value|1
define|#
directive|define
name|CP_CRC
value|2
define|#
directive|define
name|CP_UNDERRUN
value|3
define|#
directive|define
name|CP_OVERRUN
value|4
define|#
directive|define
name|CP_OVERFLOW
value|5
block|}
name|cp_chan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_cp_board_t
block|{
name|unsigned
name|char
modifier|*
name|base
decl_stmt|;
comment|/* base address of adapter registers */
name|unsigned
name|char
name|num
decl_stmt|;
comment|/* board number, 0..5 */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* board type Tau/TauE1/TauG703 */
define|#
directive|define
name|B_TAUPCI
value|1
comment|/* 2 channels V.35/RS */
define|#
directive|define
name|B_TAUPCI_E3
value|2
comment|/* 1 channel E3 */
define|#
directive|define
name|B_TAUPCI_HSSI
value|3
comment|/* 1 channel HSSI */
define|#
directive|define
name|B_TAUPCI_G703
value|4
comment|/* 2 channels G703 */
define|#
directive|define
name|B_TAUPCI_E1
value|5
comment|/* 2 channels E1 */
define|#
directive|define
name|B_TAUPCI4
value|6
comment|/* 4 channels V.35/RS */
define|#
directive|define
name|B_TAUPCI4_G703
value|7
comment|/* 2 channels G.703 + 2 channels V.35/RS */
define|#
directive|define
name|B_TAUPCI4_4G703
value|8
comment|/* 4 channels G.703 */
define|#
directive|define
name|B_TAUPCI_2E1
value|9
comment|/* 2 channels E1, 4 data ports */
define|#
directive|define
name|B_TAUPCI4_E1
value|10
comment|/* 2 channels E1 + 2 channels V.35/RS */
define|#
directive|define
name|B_TAUPCI4_4E1
value|11
comment|/* 4 channels E1 */
define|#
directive|define
name|B_TAUPCI_L
value|12
comment|/* 1 channel V.35/RS */
name|unsigned
name|long
name|osc
decl_stmt|;
comment|/* oscillator frequency */
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* board version name */
name|cp_chan_t
name|chan
index|[
name|NCHAN
index|]
decl_stmt|;
comment|/* channel structures */
name|unsigned
name|char
name|mux
decl_stmt|;
comment|/* E1 mux mode */
name|unsigned
name|char
name|dxc_cas
decl_stmt|;
comment|/* CAS cross-connection */
name|unsigned
name|char
name|bcr
decl_stmt|;
comment|/* BCR image */
name|unsigned
name|char
name|e1cfg
decl_stmt|;
comment|/* E1 CFG register image */
name|unsigned
name|char
name|gpidle
decl_stmt|;
comment|/* idle bits of gp port */
name|unsigned
name|char
name|E1DATA
decl_stmt|;
name|unsigned
name|long
name|intr
decl_stmt|;
comment|/* interrupt counter */
name|unsigned
name|long
modifier|*
name|iqlx
decl_stmt|;
comment|/* LBI intr queue */
name|int
name|iln
decl_stmt|;
name|unsigned
name|char
name|fw_type
decl_stmt|;
comment|/* firmware type */
define|#
directive|define
name|FW_TAUPCI_NONE
value|0
define|#
directive|define
name|FW_TAUPCI_E3_B
value|1
define|#
directive|define
name|FW_TAUPCI_2E1_B
value|2
define|#
directive|define
name|FW_TAUPCI_2E1_A
value|3
define|#
directive|define
name|FW_TAUPCI_4E1_B
value|6
define|#
directive|define
name|FW_TAUPCI_4E1_A
value|7
name|unsigned
name|char
modifier|*
name|firmware
index|[
literal|8
index|]
decl_stmt|;
comment|/* external firmware */
name|void
modifier|*
name|sys
decl_stmt|;
block|}
name|cp_board_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* PCI device identifiers. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|cp_vendor_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|cp_device_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialization. */
end_comment

begin_function_decl
name|unsigned
name|short
name|cp_init
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|unsigned
name|char
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_reset
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|cp_qbuf_t
modifier|*
name|buf
parameter_list|,
name|unsigned
name|long
name|phys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_hard_reset
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|cp_regio
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|op
parameter_list|,
name|int
name|reg
parameter_list|,
name|unsigned
name|long
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REGIO_INB
value|0
end_define

begin_define
define|#
directive|define
name|REGIO_IN
value|1
end_define

begin_define
define|#
directive|define
name|REGIO_INS
value|2
end_define

begin_define
define|#
directive|define
name|REGIO_INX
value|3
end_define

begin_define
define|#
directive|define
name|REGIO_INB_OUTB
value|4
end_define

begin_define
define|#
directive|define
name|REGIO_OUTB
value|5
end_define

begin_define
define|#
directive|define
name|REGIO_OUTX
value|6
end_define

begin_define
define|#
directive|define
name|REGIO_R_W
value|7
end_define

begin_define
define|#
directive|define
name|REGIO_OUT_IN
value|8
end_define

begin_define
define|#
directive|define
name|REGIO_OUTB_INB
value|9
end_define

begin_comment
comment|/* Callback registration. */
end_comment

begin_function_decl
name|void
name|cp_register_transmit
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cp_chan_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_register_receive
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cp_chan_t
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_register_error
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cp_chan_t
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Data transmittion. */
end_comment

begin_function_decl
name|void
name|cp_start_chan
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|tx
parameter_list|,
name|int
name|rx
parameter_list|,
name|cp_buf_t
modifier|*
name|cb
parameter_list|,
name|unsigned
name|long
name|phys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_stop_chan
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_start_e1
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_stop_e1
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_transmit_space
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_send_packet
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interrupt control. */
end_comment

begin_function_decl
name|int
name|cp_interrupt
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_interrupt_poll
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|int
name|ack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_handle_interrupt
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_enable_interrupt
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* G.703 timer. */
end_comment

begin_function_decl
name|void
name|cp_g703_timer
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* E1 timer. */
end_comment

begin_function_decl
name|void
name|cp_e1_timer
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* E3 timer. */
end_comment

begin_function_decl
name|void
name|cp_e3_timer
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LED control. */
end_comment

begin_function_decl
name|void
name|cp_led
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Modem signals. */
end_comment

begin_function_decl
name|void
name|cp_set_dtr
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_rts
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_dsr
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_cd
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_cts
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_txcerr
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_rxcerr
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* HDLC parameters. */
end_comment

begin_function_decl
name|void
name|cp_set_baud
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|baud
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_dpll
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_nrzi
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_invtxc
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_invrxc
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_lloop
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Channel status, cable type. */
end_comment

begin_function_decl
name|int
name|cp_get_rloop
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_lq
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cp_get_cable
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CABLE_RS232
value|0
end_define

begin_define
define|#
directive|define
name|CABLE_V35
value|1
end_define

begin_define
define|#
directive|define
name|CABLE_RS530
value|2
end_define

begin_define
define|#
directive|define
name|CABLE_X21
value|3
end_define

begin_define
define|#
directive|define
name|CABLE_RS485
value|4
end_define

begin_define
define|#
directive|define
name|CABLE_NOT_ATTACHED
value|9
end_define

begin_define
define|#
directive|define
name|CABLE_COAX
value|10
end_define

begin_define
define|#
directive|define
name|CABLE_TP
value|11
end_define

begin_comment
comment|/* E1/G.703 parameters. */
end_comment

begin_function_decl
name|void
name|cp_set_gsyn
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|syn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_ts
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|long
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_dir
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_mux
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_dxc_cas_enable
parameter_list|(
name|cp_board_t
modifier|*
name|b
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_dxc
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|cp_dxc_t
modifier|*
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_higain
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_use16
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_crc4
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_phony
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_unfram
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_scrambler
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_monitor
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* E3 parameters. */
end_comment

begin_function_decl
name|void
name|cp_set_rloop
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_ber
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_cablen
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_set_losais
parameter_list|(
name|cp_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPDDK_COBF_SAFE */
end_comment

end_unit

