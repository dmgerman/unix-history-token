begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Aic7xxx register and scratch ram definitions.  *  * Copyright (c) 1994, 1995 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  * This header should be shared by the sequencer code and the kernel  * level driver.  Unfortuanetly I haven't mangled the sequencer assembler  * into using cpp yet. Someday...  *  * All page numbers refer to the Adaptec AIC-7770 Data Book availible from  * Adaptec's Technical Documents Department 1-800-934-2766  */
end_comment

begin_comment
comment|/*  * SCSI Sequence Control (p. 3-11).  * Each bit, when set starts a specific SCSI sequence on the bus  */
end_comment

begin_define
define|#
directive|define
name|SCSISEQ
value|0x000
end_define

begin_define
define|#
directive|define
name|TEMODEO
value|0x80
end_define

begin_define
define|#
directive|define
name|ENSELO
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSELI
value|0x20
end_define

begin_define
define|#
directive|define
name|ENRSELI
value|0x10
end_define

begin_define
define|#
directive|define
name|ENAUTOATNO
value|0x08
end_define

begin_define
define|#
directive|define
name|ENAUTOATNI
value|0x04
end_define

begin_define
define|#
directive|define
name|ENAUTOATNP
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSIRSTO
value|0x01
end_define

begin_comment
comment|/*  * SCSI Transfer Control 0 Register (pp. 3-13).  * Controls the SCSI module data path.  */
end_comment

begin_define
define|#
directive|define
name|SXFRCTL0
value|0x001
end_define

begin_define
define|#
directive|define
name|DFON
value|0x80
end_define

begin_define
define|#
directive|define
name|DFPEXP
value|0x40
end_define

begin_define
define|#
directive|define
name|ULTRAEN
value|0x20
end_define

begin_define
define|#
directive|define
name|CLRSTCNT
value|0x10
end_define

begin_define
define|#
directive|define
name|SPIOEN
value|0x08
end_define

begin_define
define|#
directive|define
name|SCAMEN
value|0x04
end_define

begin_define
define|#
directive|define
name|CLRCHN
value|0x02
end_define

begin_comment
comment|/*  UNUSED			0x01 */
end_comment

begin_comment
comment|/*  * SCSI Transfer Control 1 Register (pp. 3-14,15).  * Controls the SCSI module data path.  */
end_comment

begin_define
define|#
directive|define
name|SXFRCTL1
value|0x002
end_define

begin_define
define|#
directive|define
name|BITBUCKET
value|0x80
end_define

begin_define
define|#
directive|define
name|SWRAPEN
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSPCHK
value|0x20
end_define

begin_define
define|#
directive|define
name|STIMESEL
value|0x18
end_define

begin_define
define|#
directive|define
name|ENSTIMER
value|0x04
end_define

begin_define
define|#
directive|define
name|ACTNEGEN
value|0x02
end_define

begin_define
define|#
directive|define
name|STPWEN
value|0x01
end_define

begin_comment
comment|/* Powered Termination */
end_comment

begin_comment
comment|/*  * SCSI Interrrupt Mode 1 (pp. 3-28,29).  * Set bits in this register enable the corresponding  * interrupt source.  */
end_comment

begin_define
define|#
directive|define
name|SIMODE1
value|0x011
end_define

begin_define
define|#
directive|define
name|ENSELTIMO
value|0x80
end_define

begin_define
define|#
directive|define
name|ENATNTARG
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSCSIRST
value|0x20
end_define

begin_define
define|#
directive|define
name|ENPHASEMIS
value|0x10
end_define

begin_define
define|#
directive|define
name|ENBUSFREE
value|0x08
end_define

begin_define
define|#
directive|define
name|ENSCSIPERR
value|0x04
end_define

begin_define
define|#
directive|define
name|ENPHASECHG
value|0x02
end_define

begin_define
define|#
directive|define
name|ENREQINIT
value|0x01
end_define

begin_comment
comment|/*  * SCSI Control Signal Read Register (p. 3-15).  * Reads the actual state of the SCSI bus pins  */
end_comment

begin_define
define|#
directive|define
name|SCSISIGI
value|0x003
end_define

begin_define
define|#
directive|define
name|CDI
value|0x80
end_define

begin_define
define|#
directive|define
name|IOI
value|0x40
end_define

begin_define
define|#
directive|define
name|MSGI
value|0x20
end_define

begin_define
define|#
directive|define
name|ATNI
value|0x10
end_define

begin_define
define|#
directive|define
name|SELI
value|0x08
end_define

begin_define
define|#
directive|define
name|BSYI
value|0x04
end_define

begin_define
define|#
directive|define
name|REQI
value|0x02
end_define

begin_define
define|#
directive|define
name|ACKI
value|0x01
end_define

begin_comment
comment|/*  * SCSI Contol Signal Write Register (p. 3-16).  * Writing to this register modifies the control signals on the bus.  Only  * those signals that are allowed in the current mode (Initiator/Target) are  * asserted.  */
end_comment

begin_define
define|#
directive|define
name|SCSISIGO
value|0x003
end_define

begin_define
define|#
directive|define
name|CDO
value|0x80
end_define

begin_define
define|#
directive|define
name|IOO
value|0x40
end_define

begin_define
define|#
directive|define
name|MSGO
value|0x20
end_define

begin_define
define|#
directive|define
name|ATNO
value|0x10
end_define

begin_define
define|#
directive|define
name|SELO
value|0x08
end_define

begin_define
define|#
directive|define
name|BSYO
value|0x04
end_define

begin_define
define|#
directive|define
name|REQO
value|0x02
end_define

begin_define
define|#
directive|define
name|ACKO
value|0x01
end_define

begin_comment
comment|/*   * SCSI Rate Control (p. 3-17).  * Contents of this register determine the Synchronous SCSI data transfer  * rate and the maximum synchronous Req/Ack offset.  An offset of 0 in the  * SOFS (3:0) bits disables synchronous data transfers.  Any offset value  * greater than 0 enables synchronous transfers.  */
end_comment

begin_define
define|#
directive|define
name|SCSIRATE
value|0x004
end_define

begin_define
define|#
directive|define
name|WIDEXFER
value|0x80
end_define

begin_comment
comment|/* Wide transfer control */
end_comment

begin_define
define|#
directive|define
name|SXFR
value|0x70
end_define

begin_comment
comment|/* Sync transfer rate */
end_comment

begin_define
define|#
directive|define
name|SOFS
value|0x0f
end_define

begin_comment
comment|/* Sync offset */
end_comment

begin_comment
comment|/*  * SCSI ID (p. 3-18).  * Contains the ID of the board and the current target on the  * selected channel  */
end_comment

begin_define
define|#
directive|define
name|SCSIID
value|0x005
end_define

begin_define
define|#
directive|define
name|TID
value|0xf0
end_define

begin_comment
comment|/* Target ID mask */
end_comment

begin_define
define|#
directive|define
name|OID
value|0x0f
end_define

begin_comment
comment|/* Our ID mask */
end_comment

begin_comment
comment|/*  * SCSI Transfer Count (pp. 3-19,20)  * These registers count down the number of bytes transfered  * across the SCSI bus.  The counter is decremented only once  * the data has been safely transfered.  SDONE in SSTAT0 is  * set when STCNT goes to 0  */
end_comment

begin_define
define|#
directive|define
name|STCNT
value|0x008
end_define

begin_comment
comment|/*  * SCSI Status 0 (p. 3-21)  * Contains one set of SCSI Interrupt codes  * These are most likely of interest to the sequencer  */
end_comment

begin_define
define|#
directive|define
name|SSTAT0
value|0x00b
end_define

begin_define
define|#
directive|define
name|TARGET
value|0x80
end_define

begin_comment
comment|/* Board is a target */
end_comment

begin_define
define|#
directive|define
name|SELDO
value|0x40
end_define

begin_comment
comment|/* Selection Done */
end_comment

begin_define
define|#
directive|define
name|SELDI
value|0x20
end_define

begin_comment
comment|/* Board has been selected */
end_comment

begin_define
define|#
directive|define
name|SELINGO
value|0x10
end_define

begin_comment
comment|/* Selection In Progress */
end_comment

begin_define
define|#
directive|define
name|SWRAP
value|0x08
end_define

begin_comment
comment|/* 24bit counter wrap */
end_comment

begin_define
define|#
directive|define
name|SDONE
value|0x04
end_define

begin_comment
comment|/* STCNT = 0x000000 */
end_comment

begin_define
define|#
directive|define
name|SPIORDY
value|0x02
end_define

begin_comment
comment|/* SCSI PIO Ready */
end_comment

begin_define
define|#
directive|define
name|DMADONE
value|0x01
end_define

begin_comment
comment|/* DMA transfer completed */
end_comment

begin_comment
comment|/*  * Clear SCSI Interrupt 1 (p. 3-23)  * Writing a 1 to a bit clears the associated SCSI Interrupt in SSTAT1.  */
end_comment

begin_define
define|#
directive|define
name|CLRSINT1
value|0x00c
end_define

begin_define
define|#
directive|define
name|CLRSELTIMEO
value|0x80
end_define

begin_define
define|#
directive|define
name|CLRATNO
value|0x40
end_define

begin_define
define|#
directive|define
name|CLRSCSIRSTI
value|0x20
end_define

begin_comment
comment|/*  UNUSED			0x10 */
end_comment

begin_define
define|#
directive|define
name|CLRBUSFREE
value|0x08
end_define

begin_define
define|#
directive|define
name|CLRSCSIPERR
value|0x04
end_define

begin_define
define|#
directive|define
name|CLRPHASECHG
value|0x02
end_define

begin_define
define|#
directive|define
name|CLRREQINIT
value|0x01
end_define

begin_comment
comment|/*  * SCSI Status 1 (p. 3-24)  * These interrupt bits are of interest to the kernel driver  */
end_comment

begin_define
define|#
directive|define
name|SSTAT1
value|0x00c
end_define

begin_define
define|#
directive|define
name|SELTO
value|0x80
end_define

begin_define
define|#
directive|define
name|ATNTARG
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSIRSTI
value|0x20
end_define

begin_define
define|#
directive|define
name|PHASEMIS
value|0x10
end_define

begin_define
define|#
directive|define
name|BUSFREE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSIPERR
value|0x04
end_define

begin_define
define|#
directive|define
name|PHASECHG
value|0x02
end_define

begin_define
define|#
directive|define
name|REQINIT
value|0x01
end_define

begin_comment
comment|/*  * SCSI/Host Address (p. 3-30)  * These registers hold the host address for the byte about to be  * transfered on the SCSI bus.  They are counted up in the same  * manner as STCNT is counted down.  SHADDR should always be used  * to determine the address of the last byte transfered since HADDR  * can be squewed by write ahead.  */
end_comment

begin_define
define|#
directive|define
name|SHADDR
value|0x014
end_define

begin_comment
comment|/*  * Selection/Reselection ID (p. 3-31)  * Upper four bits are the device id.  The ONEBIT is set when the re/selecting  * device did not set its own ID.  */
end_comment

begin_define
define|#
directive|define
name|SELID
value|0x019
end_define

begin_define
define|#
directive|define
name|SELID_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|ONEBIT
value|0x08
end_define

begin_comment
comment|/*  UNUSED			0x07 */
end_comment

begin_comment
comment|/*  * SCSI Block Control (p. 3-32)  * Controls Bus type and channel selection.  In a twin channel configuration  * addresses 0x00-0x1e are gated to the appropriate channel based on this  * register.  SELWIDE allows for the coexistence of 8bit and 16bit devices  * on a wide bus.  */
end_comment

begin_define
define|#
directive|define
name|SBLKCTL
value|0x01f
end_define

begin_comment
comment|/*  UNUSED			0xc0 */
end_comment

begin_define
define|#
directive|define
name|AUTOFLUSHDIS
value|0x20
end_define

begin_comment
comment|/*  UNUSED			0x10 */
end_comment

begin_define
define|#
directive|define
name|SELBUSB
value|0x08
end_define

begin_comment
comment|/*  UNUSED			0x04 */
end_comment

begin_define
define|#
directive|define
name|SELWIDE
value|0x02
end_define

begin_comment
comment|/*  UNUSED			0x01 */
end_comment

begin_comment
comment|/*  * Sequencer Control (p. 3-33)  * Error detection mode and speed configuration  */
end_comment

begin_define
define|#
directive|define
name|SEQCTL
value|0x060
end_define

begin_define
define|#
directive|define
name|PERRORDIS
value|0x80
end_define

begin_define
define|#
directive|define
name|PAUSEDIS
value|0x40
end_define

begin_define
define|#
directive|define
name|FAILDIS
value|0x20
end_define

begin_define
define|#
directive|define
name|FASTMODE
value|0x10
end_define

begin_define
define|#
directive|define
name|BRKADRINTEN
value|0x08
end_define

begin_define
define|#
directive|define
name|STEP
value|0x04
end_define

begin_define
define|#
directive|define
name|SEQRESET
value|0x02
end_define

begin_define
define|#
directive|define
name|LOADRAM
value|0x01
end_define

begin_comment
comment|/*  * Sequencer RAM Data (p. 3-34)  * Single byte window into the Scratch Ram area starting at the address  * specified by SEQADDR0 and SEQADDR1.  To write a full word, simply write  * four bytes in sucessesion.  The SEQADDRs will increment after the most  * significant byte is written  */
end_comment

begin_define
define|#
directive|define
name|SEQRAM
value|0x061
end_define

begin_comment
comment|/*  * Sequencer Address Registers (p. 3-35)  * Only the first bit of SEQADDR1 holds addressing information  */
end_comment

begin_define
define|#
directive|define
name|SEQADDR0
value|0x062
end_define

begin_define
define|#
directive|define
name|SEQADDR1
value|0x063
end_define

begin_define
define|#
directive|define
name|SEQADDR1_MASK
value|0x01
end_define

begin_comment
comment|/*  * Accumulator  * We cheat by passing arguments in the Accumulator up to the kernel driver  */
end_comment

begin_define
define|#
directive|define
name|ACCUM
value|0x064
end_define

begin_define
define|#
directive|define
name|SINDEX
value|0x065
end_define

begin_comment
comment|/*  * Board Control (p. 3-43)  */
end_comment

begin_define
define|#
directive|define
name|BCTL
value|0x084
end_define

begin_comment
comment|/*   RSVD			0xf0 */
end_comment

begin_define
define|#
directive|define
name|ACE
value|0x08
end_define

begin_comment
comment|/* Support for external processors */
end_comment

begin_comment
comment|/*   RSVD			0x06 */
end_comment

begin_define
define|#
directive|define
name|ENABLE
value|0x01
end_define

begin_comment
comment|/*  * Bus On/Off Time (p. 3-44)  */
end_comment

begin_define
define|#
directive|define
name|BUSTIME
value|0x085
end_define

begin_define
define|#
directive|define
name|BOFF
value|0xf0
end_define

begin_define
define|#
directive|define
name|BON
value|0x0f
end_define

begin_comment
comment|/*  * Bus Speed (p. 3-45)  */
end_comment

begin_define
define|#
directive|define
name|BUSSPD
value|0x086
end_define

begin_define
define|#
directive|define
name|DFTHRSH
value|0xc0
end_define

begin_define
define|#
directive|define
name|STBOFF
value|0x38
end_define

begin_define
define|#
directive|define
name|STBON
value|0x07
end_define

begin_comment
comment|/*  * Host Control (p. 3-47) R/W  * Overal host control of the device.  */
end_comment

begin_define
define|#
directive|define
name|HCNTRL
value|0x087
end_define

begin_comment
comment|/*    UNUSED			0x80 */
end_comment

begin_define
define|#
directive|define
name|POWRDN
value|0x40
end_define

begin_comment
comment|/*    UNUSED			0x20 */
end_comment

begin_define
define|#
directive|define
name|SWINT
value|0x10
end_define

begin_define
define|#
directive|define
name|IRQMS
value|0x08
end_define

begin_define
define|#
directive|define
name|PAUSE
value|0x04
end_define

begin_define
define|#
directive|define
name|INTEN
value|0x02
end_define

begin_define
define|#
directive|define
name|CHIPRST
value|0x01
end_define

begin_comment
comment|/*  * Host Address (p. 3-48)  * This register contains the address of the byte about  * to be transfered across the host bus.  */
end_comment

begin_define
define|#
directive|define
name|HADDR
value|0x088
end_define

begin_comment
comment|/*  * SCB Pointer (p. 3-49)  * Gate one of the four SCBs into the SCBARRAY window.  */
end_comment

begin_define
define|#
directive|define
name|SCBPTR
value|0x090
end_define

begin_comment
comment|/*  * Interrupt Status (p. 3-50)  * Status for system interrupts  */
end_comment

begin_define
define|#
directive|define
name|INTSTAT
value|0x091
end_define

begin_define
define|#
directive|define
name|SEQINT_MASK
value|0xf0
end_define

begin_comment
comment|/* SEQINT Status Codes */
end_comment

begin_define
define|#
directive|define
name|BAD_PHASE
value|0x00
end_define

begin_define
define|#
directive|define
name|SEND_REJECT
value|0x10
end_define

begin_define
define|#
directive|define
name|NO_IDENT
value|0x20
end_define

begin_define
define|#
directive|define
name|NO_MATCH
value|0x30
end_define

begin_define
define|#
directive|define
name|MSG_SDTR
value|0x40
end_define

begin_define
define|#
directive|define
name|MSG_WDTR
value|0x50
end_define

begin_define
define|#
directive|define
name|MSG_REJECT
value|0x60
end_define

begin_define
define|#
directive|define
name|BAD_STATUS
value|0x70
end_define

begin_define
define|#
directive|define
name|RESIDUAL
value|0x80
end_define

begin_define
define|#
directive|define
name|ABORT_TAG
value|0x90
end_define

begin_define
define|#
directive|define
name|AWAITING_MSG
value|0xa0
end_define

begin_define
define|#
directive|define
name|IMMEDDONE
value|0xb0
end_define

begin_define
define|#
directive|define
name|BRKADRINT
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSIINT
value|0x04
end_define

begin_define
define|#
directive|define
name|CMDCMPLT
value|0x02
end_define

begin_define
define|#
directive|define
name|SEQINT
value|0x01
end_define

begin_define
define|#
directive|define
name|INT_PEND
value|(BRKADRINT | SEQINT | SCSIINT | CMDCMPLT)
end_define

begin_comment
comment|/*  * Hard Error (p. 3-53)  * Reporting of catastrophic errors.  You usually cannot recover from  * these without a full board reset.  */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|0x092
end_define

begin_comment
comment|/*    UNUSED			0xf0 */
end_comment

begin_define
define|#
directive|define
name|PARERR
value|0x08
end_define

begin_define
define|#
directive|define
name|ILLOPCODE
value|0x04
end_define

begin_define
define|#
directive|define
name|ILLSADDR
value|0x02
end_define

begin_define
define|#
directive|define
name|ILLHADDR
value|0x01
end_define

begin_comment
comment|/*  * Clear Interrupt Status (p. 3-52)  */
end_comment

begin_define
define|#
directive|define
name|CLRINT
value|0x092
end_define

begin_define
define|#
directive|define
name|CLRBRKADRINT
value|0x08
end_define

begin_define
define|#
directive|define
name|CLRSCSIINT
value|0x04
end_define

begin_define
define|#
directive|define
name|CLRCMDINT
value|0x02
end_define

begin_define
define|#
directive|define
name|CLRSEQINT
value|0x01
end_define

begin_comment
comment|/*  * SCB Auto Increment (p. 3-59)  * Byte offset into the SCB Array and an optional bit to allow auto  * incrementing of the address during download and upload operations  */
end_comment

begin_define
define|#
directive|define
name|SCBCNT
value|0x09a
end_define

begin_define
define|#
directive|define
name|SCBAUTO
value|0x80
end_define

begin_define
define|#
directive|define
name|SCBCNT_MASK
value|0x1f
end_define

begin_comment
comment|/*  * Queue In FIFO (p. 3-60)  * Input queue for queued SCBs (commands that the seqencer has yet to start)  */
end_comment

begin_define
define|#
directive|define
name|QINFIFO
value|0x09b
end_define

begin_comment
comment|/*  * Queue In Count (p. 3-60)  * Number of queued SCBs  */
end_comment

begin_define
define|#
directive|define
name|QINCNT
value|0x09c
end_define

begin_comment
comment|/*  * Queue Out FIFO (p. 3-61)  * Queue of SCBs that have completed and await the host  */
end_comment

begin_define
define|#
directive|define
name|QOUTFIFO
value|0x09d
end_define

begin_comment
comment|/*  * Queue Out Count (p. 3-61)  * Number of queued SCBs in the Out FIFO  */
end_comment

begin_define
define|#
directive|define
name|QOUTCNT
value|0x09e
end_define

begin_define
define|#
directive|define
name|SCBARRAY
value|0x0a0
end_define

begin_comment
comment|/* --------------------- AIC-7870-only definitions -------------------- */
end_comment

begin_define
define|#
directive|define
name|DSPCISTATUS
value|0x086
end_define

begin_comment
comment|/*  * Serial EEPROM Control (p. 4-92 in 7870 Databook)  * Controls the reading and writing of an external serial 1-bit  * EEPROM Device.  In order to access the serial EEPROM, you must  * first set the SEEMS bit that generates a request to the memory  * port for access to the serial EEPROM device.  When the memory  * port is not busy servicing another request, it reconfigures  * to allow access to the serial EEPROM.  When this happens, SEERDY  * gets set high to verify that the memory port access has been  * granted.    *  * After successful arbitration for the memory port, the SEECS bit of   * the SEECTL register is connected to the chip select.  The SEECK,   * SEEDO, and SEEDI are connected to the clock, data out, and data in   * lines respectively.  The SEERDY bit of SEECTL is useful in that it   * gives us an 800 nsec timer.  After a write to the SEECTL register,   * the SEERDY goes high 800 nsec later.  The one exception to this is   * when we first request access to the memory port.  The SEERDY goes   * high to signify that access has been granted and, for this case, has   * no implied timing.  *  * See 93cx6.c for detailed information on the protocol necessary to   * read the serial EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|SEECTL
value|0x01e
end_define

begin_define
define|#
directive|define
name|EXTARBACK
value|0x80
end_define

begin_define
define|#
directive|define
name|EXTARBREQ
value|0x40
end_define

begin_define
define|#
directive|define
name|SEEMS
value|0x20
end_define

begin_define
define|#
directive|define
name|SEERDY
value|0x10
end_define

begin_define
define|#
directive|define
name|SEECS
value|0x08
end_define

begin_define
define|#
directive|define
name|SEECK
value|0x04
end_define

begin_define
define|#
directive|define
name|SEEDO
value|0x02
end_define

begin_define
define|#
directive|define
name|SEEDI
value|0x01
end_define

begin_comment
comment|/* ---------------------- Scratch RAM Offsets ------------------------- */
end_comment

begin_comment
comment|/* These offsets are either to values that are initialized by the board's  * BIOS or are specified by the Linux sequencer code.  If I can figure out  * how to read the EISA configuration info at probe time, the cards could  * be run without BIOS support installed  */
end_comment

begin_comment
comment|/*  * 1 byte per target starting at this address for configuration values  */
end_comment

begin_define
define|#
directive|define
name|HA_TARG_SCRATCH
value|0x020
end_define

begin_comment
comment|/*  * The sequencer will stick the frist byte of any rejected message here so  * we can see what is getting thrown away.  */
end_comment

begin_define
define|#
directive|define
name|HA_REJBYTE
value|0x031
end_define

begin_comment
comment|/*  * Bit vector of targets that have disconnection disabled.  */
end_comment

begin_define
define|#
directive|define
name|HA_DISC_DSB
value|0x032
end_define

begin_comment
comment|/*  * Length of pending message  */
end_comment

begin_define
define|#
directive|define
name|HA_MSG_LEN
value|0x034
end_define

begin_comment
comment|/*  * message body  */
end_comment

begin_define
define|#
directive|define
name|HA_MSG_START
value|0x035
end_define

begin_comment
comment|/* outgoing message body */
end_comment

begin_comment
comment|/*  * These are offsets into the card's scratch ram.  Some of the values are  * specified in the AHA2742 technical reference manual and are initialized  * by the BIOS at boot time.  */
end_comment

begin_define
define|#
directive|define
name|HA_ARG_1
value|0x04a
end_define

begin_define
define|#
directive|define
name|HA_RETURN_1
value|0x04a
end_define

begin_define
define|#
directive|define
name|SEND_SENSE
value|0x80
end_define

begin_define
define|#
directive|define
name|SEND_WDTR
value|0x80
end_define

begin_define
define|#
directive|define
name|SEND_SDTR
value|0x80
end_define

begin_define
define|#
directive|define
name|SEND_REJ
value|0x40
end_define

begin_define
define|#
directive|define
name|SG_COUNT
value|0x04d
end_define

begin_define
define|#
directive|define
name|SG_NEXT
value|0x04e
end_define

begin_define
define|#
directive|define
name|HA_SIGSTATE
value|0x04b
end_define

begin_define
define|#
directive|define
name|HA_SCBCOUNT
value|0x052
end_define

begin_define
define|#
directive|define
name|HA_FLAGS
value|0x053
end_define

begin_define
define|#
directive|define
name|SINGLE_BUS
value|0x00
end_define

begin_define
define|#
directive|define
name|TWIN_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|WIDE_BUS
value|0x02
end_define

begin_define
define|#
directive|define
name|ACTIVE_MSG
value|0x20
end_define

begin_define
define|#
directive|define
name|IDENTIFY_SEEN
value|0x40
end_define

begin_define
define|#
directive|define
name|RESELECTING
value|0x80
end_define

begin_define
define|#
directive|define
name|HA_ACTIVE0
value|0x054
end_define

begin_define
define|#
directive|define
name|HA_ACTIVE1
value|0x055
end_define

begin_define
define|#
directive|define
name|SAVED_TCL
value|0x056
end_define

begin_define
define|#
directive|define
name|WAITING_SCBH
value|0x057
end_define

begin_define
define|#
directive|define
name|WAITING_SCBT
value|0x058
end_define

begin_define
define|#
directive|define
name|HA_SCSICONF
value|0x05a
end_define

begin_define
define|#
directive|define
name|HA_HOSTCONF
value|0x05d
end_define

begin_define
define|#
directive|define
name|HA_274_BIOSCTRL
value|0x05f
end_define

begin_define
define|#
directive|define
name|BIOSMODE
value|0x30
end_define

begin_define
define|#
directive|define
name|BIOSDISABLED
value|0x30
end_define

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|MSG_BUS_DEVICE_RESET
value|0x0c
end_define

begin_define
define|#
directive|define
name|BUS_8_BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|BUS_16_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|BUS_32_BIT
value|0x02
end_define

end_unit

