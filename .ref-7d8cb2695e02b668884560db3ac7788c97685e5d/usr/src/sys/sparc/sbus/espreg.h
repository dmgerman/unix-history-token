begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)espreg.h	7.3 (Berkeley) %G%  *  * from: $Header: espreg.h,v 1.7 92/11/26 02:28:10 torek Exp $ (LBL)  *  * Derived from Mary Baker's devSCSIC90.c from the Berkeley  * Sprite project, which is:  *  * Copyright 1988 Regents of the University of California  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies.  The University of California  * makes no representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Emulex ESP100, ESP100A, and ESP200 registers, as found on the  * Sun-4c Sbus.  *  * The registers are all bytes, and all on longword boundaries.  * Grody to the max!  */
end_comment

begin_struct
struct|struct
name|espreg
block|{
name|u_char
name|esp_tcl
decl_stmt|;
comment|/* transfer count low (byte 0) (rw) */
name|u_char
name|esp_xxx0
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_tch
decl_stmt|;
comment|/* transfer count high (byte 1) (rw) */
name|u_char
name|esp_xxx1
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_fifo
decl_stmt|;
comment|/* fifo data register (rw) */
name|u_char
name|esp_xxx2
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_cmd
decl_stmt|;
comment|/* command (rw) */
name|u_char
name|esp_xxx3
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_stat
decl_stmt|;
comment|/* status (ro); scsi id (wo) */
define|#
directive|define
name|esp_id
value|esp_stat
name|u_char
name|esp_xxx4
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_intr
decl_stmt|;
comment|/* interrupt (ro); timeout (wo) */
define|#
directive|define
name|esp_timeout
value|esp_intr
name|u_char
name|esp_xxx5
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_step
decl_stmt|;
comment|/* sequence step (ro); sync period (wo) */
define|#
directive|define
name|esp_syncperiod
value|esp_step
name|u_char
name|esp_xxx6
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_fflags
decl_stmt|;
comment|/* fifo flags (ro); sync offset (wo) */
define|#
directive|define
name|esp_syncoff
value|esp_fflags
name|u_char
name|esp_xxx7
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_conf1
decl_stmt|;
comment|/* configuration #1 (rw) */
name|u_char
name|esp_xxx8
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_ccf
decl_stmt|;
comment|/* clock conversion factor (wo) */
name|u_char
name|esp_xxx9
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_test
decl_stmt|;
comment|/* test (do not use) */
name|u_char
name|esp_xxxA
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_conf2
decl_stmt|;
comment|/* configuration #2 (rw) */
name|u_char
name|esp_xxxB
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|esp_conf3
decl_stmt|;
comment|/* configuration #3 (rw, ESP-236) */
name|u_char
name|esp_xxxC
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* THE REST OF THESE NAMES COULD STAND TO BE SHORTENED */
end_comment

begin_comment
comment|/*  * Bits in esp_cmd.  Note that the cmd register is two levels deep (see  * Emulex documentation, p. 4-3); our typical usage is to set the command,  * then set it again with DMA.  *   * Targets will use disconnected and target mode commands; initiators will use  * disconnected and initiator mode commands. Bit 0x40 indicates disconnected  * mode, 0x20 target mode, and 0x10 initiator mode.  (However, everyone can  * use the miscellaneous commands, which have none of those bits set.)  */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DMA
value|0x80
end_define

begin_comment
comment|/* flag => do DMA */
end_comment

begin_comment
comment|/* miscellaneous */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_NOP
value|0x00
end_define

begin_comment
comment|/* do nothing */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_FLUSH_FIFO
value|0x01
end_define

begin_comment
comment|/* flush FIFO */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RESET_CHIP
value|0x02
end_define

begin_comment
comment|/* reset ESP chip */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RESET_BUS
value|0x03
end_define

begin_comment
comment|/* reset SCSI bus */
end_comment

begin_comment
comment|/* disconnected */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RESEL_SEQ
value|0x40
end_define

begin_comment
comment|/* reselect sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEL_NATN
value|0x41
end_define

begin_comment
comment|/* select without ATN sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEL_ATN
value|0x42
end_define

begin_comment
comment|/* select with ATN sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEL_ATNS
value|0x43
end_define

begin_comment
comment|/* select with ATN& stop seq */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEL_ENA
value|0x44
end_define

begin_comment
comment|/* enable selection/reselection */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEL_DIS
value|0x45
end_define

begin_comment
comment|/* disable selection/reselection */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEL_ATN3
value|0x46
end_define

begin_comment
comment|/* select with ATN3 sequence */
end_comment

begin_comment
comment|/* target state */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEND_MSG
value|0x20
end_define

begin_comment
comment|/* send message */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEND_STATUS
value|0x21
end_define

begin_comment
comment|/* send status */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SEND_DATA
value|0x22
end_define

begin_comment
comment|/* send data */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DIS_SEQ
value|0x23
end_define

begin_comment
comment|/* disconnect sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_TERM_SEQ
value|0x24
end_define

begin_comment
comment|/* terminate sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_TARG_COMP
value|0x25
end_define

begin_comment
comment|/* target command complete sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_DISCONNECT
value|0x27
end_define

begin_comment
comment|/* disconnect */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RCV_MSG
value|0x28
end_define

begin_comment
comment|/* receive message sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RCV_CMD
value|0x29
end_define

begin_comment
comment|/* receive command */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RCV_DATA
value|0x2a
end_define

begin_comment
comment|/* receive data */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_REC_CMD_SEQ
value|0x2b
end_define

begin_comment
comment|/* receive command sequence */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_STOP_DMA
value|0x04
end_define

begin_comment
comment|/* stop DMA (see p. 4-6) */
end_comment

begin_comment
comment|/*	ESPCMD_TARG_ABORT	0x06	   target abort sequence */
end_comment

begin_comment
comment|/* initiator state */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_XFER_INFO
value|0x10
end_define

begin_comment
comment|/* transfer information */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_INIT_COMP
value|0x11
end_define

begin_comment
comment|/* initiator command complete seq */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_MSG_ACCEPT
value|0x12
end_define

begin_comment
comment|/* message accepted */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_XFER_PAD
value|0x18
end_define

begin_comment
comment|/* transfer pad (use only w/ DMA) */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_SET_ATN
value|0x1a
end_define

begin_comment
comment|/* set ATN */
end_comment

begin_define
define|#
directive|define
name|ESPCMD_RESET_ATN
value|0x1b
end_define

begin_comment
comment|/* reset ATN */
end_comment

begin_comment
comment|/*  * Bits in esp_stat.  * Bits 3 through 7 are latched until esp_intr is read;  * bits 0 through 2 (the phase) are not normally latched.  * The interrupt bit is set even if interrupts are disabled.  * Hardware or software reset, or reading esp_intr, will  * clear the interrupt and turn off ESPSTAT_INT.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|ESPSTAT_INT
value|0x80
end_define

begin_comment
comment|/* ASC interrupting processor */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ESPSTAT_XXX
value|0x80
end_define

begin_comment
comment|/* rumored unreliable: use dma IP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ESPSTAT_GE
value|0x40
end_define

begin_comment
comment|/* gross error */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_PE
value|0x20
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_ERR
value|0x60
end_define

begin_comment
comment|/* pseudo composite */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_TC
value|0x10
end_define

begin_comment
comment|/* terminal count */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_VGC
value|0x08
end_define

begin_comment
comment|/* valid group code */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_MSG
value|0x04
end_define

begin_comment
comment|/* MSG line from SCSI bus */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_CD
value|0x02
end_define

begin_comment
comment|/* CD line from SCSI bus */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_IO
value|0x01
end_define

begin_comment
comment|/* IO line from SCSI bus */
end_comment

begin_define
define|#
directive|define
name|ESPSTAT_PHASE
value|7
end_define

begin_comment
comment|/* phase mask */
end_comment

begin_define
define|#
directive|define
name|ESPPHASE_DATA_OUT
value|0
end_define

begin_comment
comment|/* data out */
end_comment

begin_define
define|#
directive|define
name|ESPPHASE_DATA_IN
value|1
end_define

begin_comment
comment|/* data in */
end_comment

begin_define
define|#
directive|define
name|ESPPHASE_CMD
value|2
end_define

begin_comment
comment|/* command */
end_comment

begin_define
define|#
directive|define
name|ESPPHASE_STATUS
value|3
end_define

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|ESPPHASE_MSG_OUT
value|6
end_define

begin_comment
comment|/* message out (w.r.t. initiator) */
end_comment

begin_define
define|#
directive|define
name|ESPPHASE_MSG_IN
value|7
end_define

begin_comment
comment|/* message in */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ESP_PHASE_NAMES
end_ifdef

begin_comment
comment|/* printed as `... during %s phase' */
end_comment

begin_decl_stmt
name|char
modifier|*
name|espphases
index|[]
init|=
block|{
literal|"data out"
block|,
literal|"data in"
block|,
literal|"command"
block|,
literal|"status"
block|,
literal|"impossible(4)"
block|,
literal|"impossible(5)"
block|,
literal|"message out"
block|,
literal|"message in"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ESPSTAT_BITS
value|"\20\10INT\7GE\6PE\5TC\4VGC\3MSG\2CD\1IO"
end_define

begin_comment
comment|/*  * Bits in esp_intr.  */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SBR
value|0x80
end_define

begin_comment
comment|/* SCSI bus reset detected */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_ILC
value|0x40
end_define

begin_comment
comment|/* illegal command */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_DSC
value|0x20
end_define

begin_comment
comment|/* target disconnected, or timeout */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SVC
value|0x10
end_define

begin_comment
comment|/* a device wants bus service */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_CMP
value|0x08
end_define

begin_comment
comment|/* function complete */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_RSL
value|0x04
end_define

begin_comment
comment|/* reselected */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SAT
value|0x02
end_define

begin_comment
comment|/* selected with ATN */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_SEL
value|0x01
end_define

begin_comment
comment|/* selected (no ATN) */
end_comment

begin_define
define|#
directive|define
name|ESPINTR_BITS
value|"\20\10SBR\7ILC\6DSC\5SVC\4CMP\3RSL\2SAT\1SEL"
end_define

begin_comment
comment|/*  * Formula for select/reselect timeout (esp_timeout).  *	TU = 7682 * CCF * TCP  *	T / TU = register value  *	CCF = clock conversion factor  *	TCP = input clock period (in same units as T)  *	TU = time unit (i.e., the esp_timeout register counts in TUs)  *	T = desired timeout  * (i.e., we want ceil(timeout / (7682*ccf*tcp))).  If timeout is in ms.,  * and tcp is in MHz, then (ccf * 7682)/tcp gives us 1000*TU, and  * 1000*timeout/(1000*TU) gives us our result (but remember to round up).  *  * N.B.: The register value 0 gives a TU of 256.  */
end_comment

begin_define
define|#
directive|define
name|ESPTIMO_REGVAL
parameter_list|(
name|timo_ms
parameter_list|,
name|ccf
parameter_list|,
name|mhz
parameter_list|)
define|\
value|howmany(1000 * (timo_ms), ((ccf) * 7682) / (mhz))
end_define

begin_comment
comment|/*  * Value in esp_step.  These tell us how much of a `sequence' completed,  * and apply to the following sequenced operations:  *  [initiator]  *	select without ATN  *	select with ATN  *	select with ATN3  *	select with ATN and stop  *  [target]  *	bus-initiated select with ATN  *	bus-initiated select  *	receive command sequence  *	command complete sequence  *	disconnect sequence  *	terminate sequence  * The actual values are too complicated to define here, except that  * code 4 always means `everything worked and the command went out'  * (and is thus typical for everything except ATN-and-stop).  */
end_comment

begin_define
define|#
directive|define
name|ESPSTEP_MASK
value|0x07
end_define

begin_comment
comment|/* only these bits are valid */
end_comment

begin_define
define|#
directive|define
name|ESPSTEP_DONE
value|4
end_define

begin_comment
comment|/* command went out */
end_comment

begin_comment
comment|/*  * Synchronous transfer period (esp_syncper, 5 bits).  * The minimum clocks-per-period is 5 and the max is 35;  * the default on reset is 5.  Note that a period value of 4  * actually gives 5 clocks.  */
end_comment

begin_define
define|#
directive|define
name|ESP_CLOCKS_TO_PERIOD
parameter_list|(
name|nclocks
parameter_list|)
value|((nclocks)& 31)
end_define

begin_comment
comment|/*  * Bits in fifo flags (esp_fflags) register.  The FIFO itself  * is only 16 bytes, so the byte count fits in 5 bits.  Normally  * a copy of the sequence step register appears in the top 3 bits,  * but in test mode the chip re-uses one of those for a synchronous  * offset bit.  */
end_comment

begin_define
define|#
directive|define
name|ESP_NFIFO
parameter_list|(
name|esp
parameter_list|)
value|((esp)->esp_fflags& 0x1f)
end_define

begin_define
define|#
directive|define
name|ESP_FFSTEP
parameter_list|(
name|esp
parameter_list|)
value|(((esp)->esp_fflags>> 5)& 3)
end_define

begin_define
define|#
directive|define
name|ESPFFLAGS_TM_SOFFNZ
value|0x20
end_define

begin_comment
comment|/* nonzero sync offset (test mode) */
end_comment

begin_comment
comment|/*  * Bits in esp_conf1.  */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_SLOW_CABLE
value|0x80
end_define

begin_comment
comment|/* ``slow cable'' mode */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_REPORT
value|0x40
end_define

begin_comment
comment|/* disable reporting of interrupts 					   from scsi bus reset command */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_PARTST
value|0x20
end_define

begin_comment
comment|/* parity test mode */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_PARENB
value|0x10
end_define

begin_comment
comment|/* enable parity */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_TEST
value|0x08
end_define

begin_comment
comment|/* chip test mode */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_ID_MASK
value|0x07
end_define

begin_comment
comment|/* SCSI bus ID field */
end_comment

begin_define
define|#
directive|define
name|ESPCONF1_BITS
value|"\20\10SLOW_CABLE\7REPORT\6PARTST\5PARENB\4TEST"
end_define

begin_comment
comment|/*  * Values for clock conversion factor (esp_ccf).  */
end_comment

begin_define
define|#
directive|define
name|ESPCCF_FROMMHZ
parameter_list|(
name|mhz
parameter_list|)
value|(((mhz) + 4) / 5)
end_define

begin_define
define|#
directive|define
name|ESPCCF_MIN
value|2
end_define

begin_comment
comment|/* minimum CCF value */
end_comment

begin_comment
comment|/*  * Bits in esp_test (for board testing only; can only be used in test mode).  */
end_comment

begin_define
define|#
directive|define
name|ESPTEST_MBZ
value|0xf8
end_define

begin_comment
comment|/* reserved; must be 0 */
end_comment

begin_define
define|#
directive|define
name|ESPTEST_TRISTATE
value|0x04
end_define

begin_comment
comment|/* all output pins tristated */
end_comment

begin_define
define|#
directive|define
name|ESPTEST_INITIATOR
value|0x02
end_define

begin_comment
comment|/* operate as initiator */
end_comment

begin_define
define|#
directive|define
name|ESPTEST_TARGET
value|0x01
end_define

begin_comment
comment|/* operate as target */
end_comment

begin_comment
comment|/*  * Bits in esp_conf2.  */
end_comment

begin_define
define|#
directive|define
name|ESPCONF2_RSVD
value|0xe0
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|ESPCONF2_TRISTATE_DMA
value|0x10
end_define

begin_comment
comment|/* tristate the DMA REQ pin */
end_comment

begin_define
define|#
directive|define
name|ESPCONF2_SCSI2
value|0x08
end_define

begin_comment
comment|/* enable SCSI 2 (see p. 4-18) */
end_comment

begin_define
define|#
directive|define
name|ESPCONF2_TBPA
value|0x04
end_define

begin_comment
comment|/* enable target bad parity abort */
end_comment

begin_define
define|#
directive|define
name|ESPCONF2_RPE
value|0x02
end_define

begin_comment
comment|/* register parity ena (ESP2xx only) */
end_comment

begin_define
define|#
directive|define
name|ESPCONF2_DPE
value|0x01
end_define

begin_comment
comment|/* DMA parity enable (ESP2xx only) */
end_comment

end_unit

