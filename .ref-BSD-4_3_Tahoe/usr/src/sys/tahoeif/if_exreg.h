begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Excelan Inc.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_exreg.h	7.2 (Berkeley) 4/22/89  */
end_comment

begin_struct
struct|struct
name|exdevice
block|{
name|ushort
name|ex_porta
decl_stmt|;
comment|/* write on porta resets EXOS */
name|ushort
name|ex_portb
decl_stmt|;
comment|/* write on portb interrupts EXOS */
block|}
struct|;
end_struct

begin_comment
comment|/* EXOS I/O PORT A write definitions */
end_comment

begin_define
define|#
directive|define
name|EX_RESET
value|0
end_define

begin_comment
comment|/* value doesn't really matter... */
end_comment

begin_comment
comment|/* EXOS I/O PORT B write definitions */
end_comment

begin_define
define|#
directive|define
name|EX_NTRUPT
value|0
end_define

begin_comment
comment|/* EXOS I/O PORT B read definitions */
end_comment

begin_define
define|#
directive|define
name|EX_TESTOK
value|1
end_define

begin_comment
comment|/* set when self-diagnostics passed */
end_comment

begin_define
define|#
directive|define
name|EX_UNREADY
value|(1<<3)
end_define

begin_comment
comment|/* set until EXOS ready to read from B */
end_comment

begin_comment
comment|/* message buffer status field definitions */
end_comment

begin_define
define|#
directive|define
name|MH_OWNER
value|1
end_define

begin_comment
comment|/* mask for status bit for owner */
end_comment

begin_define
define|#
directive|define
name|MH_HOST
value|0
end_define

begin_comment
comment|/* if 0, the host owns the buffer */
end_comment

begin_define
define|#
directive|define
name|MH_EXOS
value|1
end_define

begin_comment
comment|/* if 1, the EXOS owns the buffer */
end_comment

begin_comment
comment|/* EXOS Link Level request codes */
end_comment

begin_define
define|#
directive|define
name|LLTRANSMIT
value|0xC
end_define

begin_comment
comment|/* send a packet */
end_comment

begin_define
define|#
directive|define
name|LLRTRANSMIT
value|0xE
end_define

begin_comment
comment|/* send a packet, and self-receive */
end_comment

begin_define
define|#
directive|define
name|LLRECEIVE
value|0xD
end_define

begin_comment
comment|/* receive a packet */
end_comment

begin_define
define|#
directive|define
name|LLNET_MODE
value|0x8
end_define

begin_comment
comment|/* read/write mode control objects */
end_comment

begin_define
define|#
directive|define
name|LLNET_ADDRS
value|0x9
end_define

begin_comment
comment|/* read/write receive address slots */
end_comment

begin_define
define|#
directive|define
name|LLNET_RECV
value|0xA
end_define

begin_comment
comment|/* read/alter receive slot enable bit */
end_comment

begin_define
define|#
directive|define
name|LLNET_STSTCS
value|0xB
end_define

begin_comment
comment|/* read/reset network statistics objects */
end_comment

begin_comment
comment|/* Link Level return codes common to all requests */
end_comment

begin_define
define|#
directive|define
name|LL_OK
value|0
end_define

begin_comment
comment|/* successful completion */
end_comment

begin_define
define|#
directive|define
name|LLX_MODE
value|0xA1
end_define

begin_comment
comment|/* EXOS not in link level mode (impossible) */
end_comment

begin_comment
comment|/* LLTRANSMIT unique return codes */
end_comment

begin_define
define|#
directive|define
name|LLXM_1RTRY
value|0x1
end_define

begin_comment
comment|/* successful xmission, 1 retry */
end_comment

begin_define
define|#
directive|define
name|LLXM_RTRYS
value|0x2
end_define

begin_comment
comment|/* successful xmission, more than 1 retry */
end_comment

begin_define
define|#
directive|define
name|LLXM_NSQE
value|0x8
end_define

begin_comment
comment|/* successful xmission, no SQE TEST signal */
end_comment

begin_define
define|#
directive|define
name|LLXM_CLSN
value|0x10
end_define

begin_comment
comment|/* xmission failed, excess retries */
end_comment

begin_define
define|#
directive|define
name|LLXM_NCS
value|0x20
end_define

begin_comment
comment|/* xmission failed, no carrier sense */
end_comment

begin_define
define|#
directive|define
name|LLXM_LNGTH
value|0x40
end_define

begin_comment
comment|/* xmission failed, bad packet length */
end_comment

begin_define
define|#
directive|define
name|XMIT_BITS
value|"\7\7LENGTH\6CARRIER\5XCLSNS\4SQETST"
end_define

begin_comment
comment|/*#define	LLXM_ERROR	(LLXM_NSQE|LLXM_CLSN|LLXM_NCS|LLXM_LNGTH)*/
end_comment

begin_define
define|#
directive|define
name|LLXM_ERROR
value|(LLXM_CLSN|LLXM_NCS|LLXM_LNGTH)
end_define

begin_comment
comment|/* LLRECEIVE unique return codes */
end_comment

begin_define
define|#
directive|define
name|LLRC_TRUNC
value|0x4
end_define

begin_comment
comment|/* pkt received, but truncated to fit buffer */
end_comment

begin_define
define|#
directive|define
name|LLRC_ALIGN
value|0x10
end_define

begin_comment
comment|/* pkt received, but with alignment error */
end_comment

begin_define
define|#
directive|define
name|LLRC_CRC
value|0x20
end_define

begin_comment
comment|/* pkt received, but with CRC error */
end_comment

begin_define
define|#
directive|define
name|LLRC_BUFLEN
value|0x40
end_define

begin_comment
comment|/* no pkt received, buffer less than 64 bytes */
end_comment

begin_comment
comment|/* this should never happen here */
end_comment

begin_define
define|#
directive|define
name|RECV_BITS
value|"\7\7BUFLEN\6CRC\5ALIGN\3TRUNC"
end_define

begin_comment
comment|/* LLNET_ADDRS unique return codes */
end_comment

begin_define
define|#
directive|define
name|LLNA_BADSLOT
value|0xD1
end_define

begin_comment
comment|/* slot doesn't exist or can't be accessed */
end_comment

begin_define
define|#
directive|define
name|LLNA_BADADDR
value|0xD3
end_define

begin_comment
comment|/* invalid address for designated slot */
end_comment

begin_comment
comment|/* LLNET_RECV unique return codes */
end_comment

begin_define
define|#
directive|define
name|LLNR_BADSLOT
value|0xD1
end_define

begin_comment
comment|/* slot doesn't exist or can't be accessed */
end_comment

begin_define
define|#
directive|define
name|LLNR_BADADDR
value|0xD2
end_define

begin_comment
comment|/* designated slot was empty */
end_comment

begin_comment
comment|/* address slot object indices */
end_comment

begin_define
define|#
directive|define
name|NULLSLOT
value|0
end_define

begin_comment
comment|/* the null slot */
end_comment

begin_define
define|#
directive|define
name|MINMCSLOT
value|1
end_define

begin_comment
comment|/* minimum multicast slot index */
end_comment

begin_define
define|#
directive|define
name|MAXMCSLOT
value|8
end_define

begin_comment
comment|/* default maximum multicast slot index */
end_comment

begin_define
define|#
directive|define
name|PHYSSLOT
value|253
end_define

begin_comment
comment|/* physical slot index */
end_comment

begin_define
define|#
directive|define
name|UNVRSSLOT
value|254
end_define

begin_comment
comment|/* universal slot index */
end_comment

begin_define
define|#
directive|define
name|BROADSLOT
value|255
end_define

begin_comment
comment|/* broadcast slot index */
end_comment

begin_comment
comment|/* request mask bit definitions */
end_comment

begin_define
define|#
directive|define
name|WRITE_OBJ
value|1
end_define

begin_comment
comment|/* write the object */
end_comment

begin_define
define|#
directive|define
name|READ_OBJ
value|2
end_define

begin_comment
comment|/* read the object */
end_comment

begin_define
define|#
directive|define
name|ENABLE_RCV
value|4
end_define

begin_comment
comment|/* enable reception on designated slot */
end_comment

begin_comment
comment|/* NET_MODE options mask bit definitions */
end_comment

begin_define
define|#
directive|define
name|OPT_ALIGN
value|0x10
end_define

begin_comment
comment|/* receive packets with alignment errors */
end_comment

begin_define
define|#
directive|define
name|OPT_CRC
value|0x20
end_define

begin_comment
comment|/* receive packets with CRC errors */
end_comment

begin_define
define|#
directive|define
name|OPT_DSABLE
value|0x80
end_define

begin_comment
comment|/* disconnect controller hardware */
end_comment

begin_comment
comment|/* NET_MODE mode field value definitions */
end_comment

begin_define
define|#
directive|define
name|MODE_OFF
value|0
end_define

begin_comment
comment|/* stop transmission and reception */
end_comment

begin_define
define|#
directive|define
name|MODE_PERF
value|1
end_define

begin_comment
comment|/* perfect multicast address filtering */
end_comment

begin_define
define|#
directive|define
name|MODE_HW
value|2
end_define

begin_comment
comment|/* hardware-only multicast address filtering */
end_comment

begin_define
define|#
directive|define
name|MODE_PROM
value|3
end_define

begin_comment
comment|/* promiscuous reception */
end_comment

begin_define
define|#
directive|define
name|NFRAGMENTS
value|8
end_define

begin_comment
comment|/* number fragments that the EXOS will scatter/gather */
end_comment

begin_define
define|#
directive|define
name|EXMAXRBUF
value|1518
end_define

begin_comment
comment|/* per EXOS 202 manual 5.3.7 (maybe 1518 would do) */
end_comment

begin_comment
comment|/*  * N.B.  Structures below are carefully constructed so that  * they correspond to the message formats that NX firmware  * defines.  None of them should contain any compiler-instigated  * padding.  Be especially careful about VAX C longword alignment!  */
end_comment

begin_struct
struct|struct
name|ex_stat
block|{
name|u_long
name|sa_fsent
decl_stmt|;
comment|/* frames sent without errors */
name|u_long
name|sa_xsclsn
decl_stmt|;
comment|/* frames aborted excess collisions */
name|u_long
name|sa_nsqe
decl_stmt|;
comment|/* frames subject to heartbeat failure */
name|u_long
name|sa_undef
decl_stmt|;
comment|/* undefined (TDR on EXOS 101) */
name|u_long
name|sa_frcvd
decl_stmt|;
comment|/* frames received no errors */
name|u_long
name|sa_align
decl_stmt|;
comment|/* frames received alignment error */
name|u_long
name|sa_crc
decl_stmt|;
comment|/* frames received crc error */
name|u_long
name|sa_flost
decl_stmt|;
comment|/* frames lost */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buf_blk
block|{
comment|/* packet/buffer block descriptor */
name|u_short
name|bb_len
decl_stmt|;
comment|/* length of block, in bytes */
struct|struct
name|i86_long
block|{
name|u_short
name|realaddr
index|[
literal|2
index|]
decl_stmt|;
comment|/* address of block */
block|}
name|bb_addr
struct|;
comment|/* 	 * Array above is really a single u_long field. 	 * We kludge its definition to defeat word-alignment. 	 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|net_mode
block|{
comment|/* read/write mode control objects */
comment|/*12*/
name|u_char
name|nm_rqst
decl_stmt|;
comment|/* request code */
comment|/*13*/
name|u_char
name|nm_rply
decl_stmt|;
comment|/* reply code */
comment|/*14*/
name|u_char
name|nm_mask
decl_stmt|;
comment|/* bit-wise switches for read, write */
comment|/*15*/
name|u_char
name|nm_optn
decl_stmt|;
comment|/* acceptable packet reception errors */
comment|/*16*/
name|u_char
name|nm_mode
decl_stmt|;
comment|/* EXOS filtering mode */
comment|/*17*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|net_addrs
block|{
comment|/* read/write receive address slots */
comment|/*12*/
name|u_char
name|na_rqst
decl_stmt|;
comment|/* request code */
comment|/*13*/
name|u_char
name|na_rply
decl_stmt|;
comment|/* reply code */
comment|/*14*/
name|u_char
name|na_mask
decl_stmt|;
comment|/* bit-wise switches for read, write */
comment|/*15*/
name|u_char
name|na_slot
decl_stmt|;
comment|/* index of address slot */
comment|/*16*/
name|u_char
name|na_addrs
index|[
literal|6
index|]
decl_stmt|;
comment|/* address read and/or written */
comment|/*22*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|net_recv
block|{
comment|/* read/alter receive slot enable bit */
comment|/*12*/
name|u_char
name|nr_rqst
decl_stmt|;
comment|/* request code */
comment|/*13*/
name|u_char
name|nr_rply
decl_stmt|;
comment|/* reply code */
comment|/*14*/
name|u_char
name|nr_mask
decl_stmt|;
comment|/* bit-wise switches for read, write */
comment|/*15*/
name|u_char
name|nr_slot
decl_stmt|;
comment|/* index of address slot */
comment|/*16*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|net_ststcs
block|{
comment|/* read/reset network statistics objects */
comment|/*12*/
name|u_char
name|ns_rqst
decl_stmt|;
comment|/* request code */
comment|/*13*/
name|u_char
name|ns_rply
decl_stmt|;
comment|/* reply code */
comment|/*14*/
name|u_char
name|ns_mask
decl_stmt|;
comment|/* bit-wise switches for read, write */
comment|/*15*/
name|u_char
name|ns_rsrv
decl_stmt|;
comment|/* reserved for EXOS */
comment|/*16*/
name|u_short
name|ns_nobj
decl_stmt|;
comment|/* number of objects to work on */
comment|/*18*/
name|u_short
name|ns_xobj
decl_stmt|;
comment|/* index of first object to work on */
comment|/*20*/
name|u_long
name|ns_bufp
decl_stmt|;
comment|/* pointer to statistics buffer */
comment|/*24*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|enet_xmit
block|{
comment|/* send a packet on the Ethernet */
comment|/*12*/
name|u_char
name|et_rqst
decl_stmt|;
comment|/* request code */
comment|/*13*/
name|u_char
name|et_rply
decl_stmt|;
comment|/* reply code */
comment|/*14*/
name|u_char
name|et_slot
decl_stmt|;
comment|/* address slot matching dest address */
comment|/*15*/
name|u_char
name|et_nblock
decl_stmt|;
comment|/* number of blocks composing packet */
comment|/*16*/
name|struct
name|buf_blk
name|et_blks
index|[
name|NFRAGMENTS
index|]
decl_stmt|;
comment|/* array of block descriptors */
comment|/*22-64*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|enet_recv
block|{
comment|/* receive a packet on the Ethernet */
comment|/*12*/
name|u_char
name|er_rqst
decl_stmt|;
comment|/* request code */
comment|/*13*/
name|u_char
name|er_rply
decl_stmt|;
comment|/* reply code */
comment|/*14*/
name|u_char
name|er_slot
decl_stmt|;
comment|/* address slot matching dest address */
comment|/*15*/
name|u_char
name|er_nblock
decl_stmt|;
comment|/* number of blocks composing buffer */
comment|/*16*/
name|struct
name|buf_blk
name|er_blks
index|[
name|NFRAGMENTS
index|]
decl_stmt|;
comment|/* array of block descriptors */
comment|/*22-64*/
block|}
struct|;
end_struct

begin_comment
comment|/* we send requests and receive replys with the EXOS using this structure */
end_comment

begin_struct
struct|struct
name|ex_msg
block|{
comment|/*00*/
name|u_short
name|mb_link
decl_stmt|;
comment|/* address of next message buffer */
comment|/*02*/
name|u_char
name|mb_rsrv
decl_stmt|;
comment|/* reserved for use by EXOS */
comment|/*03*/
name|u_char
name|mb_status
decl_stmt|;
comment|/* used bit-wise for message protocol */
comment|/*04*/
name|u_short
name|mb_length
decl_stmt|;
comment|/* length, in bytes, of the rest */
comment|/*06*/
name|short
name|mb_1rsrv
decl_stmt|;
comment|/* reserved for used by EXOS */
comment|/*08*/
name|struct
name|ifvba
modifier|*
name|mb_pkb
decl_stmt|;
comment|/* available to user */
comment|/*12*/
union|union
name|mb_all
block|{
name|struct
name|net_mode
name|mb_net_mode
decl_stmt|;
name|struct
name|net_addrs
name|mb_net_addrs
decl_stmt|;
name|struct
name|net_recv
name|mb_net_recv
decl_stmt|;
name|struct
name|net_ststcs
name|mb_net_ststcs
decl_stmt|;
name|struct
name|enet_xmit
name|mb_enet_xmit
decl_stmt|;
name|struct
name|enet_recv
name|mb_enet_recv
decl_stmt|;
block|}
name|mb_all
union|;
comment|/* following field is used only by host, not read by board */
name|struct
name|ex_msg
modifier|*
name|mb_next
decl_stmt|;
comment|/* host's pointer to next message */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mb_nm
value|mb_all.mb_net_mode
end_define

begin_define
define|#
directive|define
name|mb_na
value|mb_all.mb_net_addrs
end_define

begin_define
define|#
directive|define
name|mb_nr
value|mb_all.mb_net_recv
end_define

begin_define
define|#
directive|define
name|mb_ns
value|mb_all.mb_net_ststcs
end_define

begin_define
define|#
directive|define
name|mb_et
value|mb_all.mb_enet_xmit
end_define

begin_define
define|#
directive|define
name|mb_er
value|mb_all.mb_enet_recv
end_define

begin_define
define|#
directive|define
name|mb_rqst
value|mb_nm.nm_rqst
end_define

begin_define
define|#
directive|define
name|mb_rply
value|mb_nm.nm_rply
end_define

begin_define
define|#
directive|define
name|MBDATALEN
value|(sizeof(union mb_all)+6)
end_define

begin_struct
struct|struct
name|ex_conf
block|{
comment|/*00*/
name|u_short
name|cm_1rsrv
decl_stmt|;
comment|/* reserved, must be 1 */
comment|/*02*/
name|char
name|cm_vc
index|[
literal|4
index|]
decl_stmt|;
comment|/* returns ASCII version code */
comment|/*06*/
name|u_char
name|cm_cc
decl_stmt|;
comment|/* returns config completion code */
comment|/*07*/
name|u_char
name|cm_opmode
decl_stmt|;
comment|/* specifies operation mode */
comment|/*08*/
name|u_short
name|cm_dfo
decl_stmt|;
comment|/* specifies host data format option */
comment|/*00*/
name|u_char
name|cm_dcn1
decl_stmt|;
comment|/* reserved, must be 1 */
comment|/*11*/
name|u_char
name|cm_2rsrv
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved, must be 0 */
comment|/*13*/
name|u_char
name|cm_ham
decl_stmt|;
comment|/* specifies host address mode */
comment|/*14*/
name|u_char
name|cm_3rsrv
decl_stmt|;
comment|/* reserved, must be 0 */
comment|/*15*/
name|u_char
name|cm_mapsiz
decl_stmt|;
comment|/* reserved, must be 0 */
comment|/*16*/
name|u_char
name|cm_byteptrn
index|[
literal|4
index|]
decl_stmt|;
comment|/* host data format option test pattern */
comment|/*20*/
name|u_short
name|cm_wordptrn
index|[
literal|2
index|]
decl_stmt|;
comment|/*24*/
name|u_long
name|cm_lwordptrn
decl_stmt|;
comment|/*28*/
name|u_char
name|cm_rsrvd
index|[
literal|20
index|]
decl_stmt|;
comment|/*48*/
name|u_long
name|cm_mba
decl_stmt|;
comment|/* use 0xFFFFFFFF in link level mode */
comment|/*52*/
name|u_char
name|cm_nproc
decl_stmt|;
comment|/* use 0xFF in link level mode */
comment|/*53*/
name|u_char
name|cm_nmbox
decl_stmt|;
comment|/* use 0xFF in link level mode */
comment|/*54*/
name|u_char
name|cm_nmcast
decl_stmt|;
comment|/* use 0xFF in link level mode */
comment|/*55*/
name|u_char
name|cm_nhost
decl_stmt|;
comment|/* use 1 in link level mode */
comment|/* the next five parameters define the request message queue */
comment|/*56*/
name|u_long
name|cm_h2xba
decl_stmt|;
comment|/* base address of message queue */
comment|/*60*/
name|u_short
name|cm_h2xhdr
decl_stmt|;
comment|/* address offset of msg Q header */
comment|/*62*/
name|u_char
name|cm_h2xtyp
decl_stmt|;
comment|/* interrupt type */
comment|/*63*/
name|u_char
name|cm_h2xval
decl_stmt|;
comment|/* interrupt value (not used) */
comment|/*64*/
name|u_short
name|cm_h2xaddr
decl_stmt|;
comment|/* interrupt vector */
comment|/*66*/
name|u_short
name|cm_h2xpad
decl_stmt|;
comment|/* pad out unused portion of vector */
comment|/* the next five parameters define the reply message queue */
comment|/*68*/
name|u_long
name|cm_x2hba
decl_stmt|;
comment|/* base address of message queue */
comment|/*72*/
name|u_short
name|cm_x2hhdr
decl_stmt|;
comment|/* address offset of msg Q header */
comment|/*74*/
name|u_char
name|cm_x2htyp
decl_stmt|;
comment|/* interrupt type */
comment|/*75*/
name|u_char
name|cm_x2hval
decl_stmt|;
comment|/* interrupt value (not used) */
comment|/*76*/
name|u_short
name|cm_x2haddr
decl_stmt|;
comment|/* interrupt vector */
comment|/*78*/
name|u_short
name|cm_x2hpad
decl_stmt|;
comment|/* pad out unused portion of vector */
comment|/*80*/
block|}
struct|;
end_struct

end_unit

