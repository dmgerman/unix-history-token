begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_dmv.h	7.3 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * DMV-11 Driver  *  * Qbus Sync DDCMP interface - DMV operated in full duplex, point to point mode  *  * Written by Bob Kridle of Mt Xinu  * starting from if_dmc.h version 6.4 dated 6/8/85   */
end_comment

begin_struct
struct|struct
name|dmvdevice
block|{
union|union
block|{
name|u_char
name|xbsel
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|xwsel
decl_stmt|;
block|}
name|xw0
union|;
union|union
block|{
name|u_char
name|xbsel
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|xwsel
decl_stmt|;
block|}
name|xw1
union|;
union|union
block|{
name|u_char
name|xbsel
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|xwsel
decl_stmt|;
block|}
name|xw2
union|;
union|union
block|{
name|u_char
name|xbsel
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|xwsel
decl_stmt|;
block|}
name|xw3
union|;
union|union
block|{
name|u_char
name|xbsel
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|xwsel
decl_stmt|;
block|}
name|xw4
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bsel0
value|xw0.xbsel[0]
end_define

begin_define
define|#
directive|define
name|bsel1
value|xw0.xbsel[1]
end_define

begin_define
define|#
directive|define
name|bsel2
value|xw1.xbsel[0]
end_define

begin_define
define|#
directive|define
name|bsel3
value|xw1.xbsel[1]
end_define

begin_define
define|#
directive|define
name|bsel4
value|xw2.xbsel[0]
end_define

begin_define
define|#
directive|define
name|bsel5
value|xw2.xbsel[1]
end_define

begin_define
define|#
directive|define
name|bsel6
value|xw3.xbsel[0]
end_define

begin_define
define|#
directive|define
name|bsel7
value|xw3.xbsel[1]
end_define

begin_define
define|#
directive|define
name|bsel10
value|xw4.xbsel[0]
end_define

begin_define
define|#
directive|define
name|bsel11
value|xw4.xbsel[1]
end_define

begin_define
define|#
directive|define
name|wsel0
value|xw0.xwsel
end_define

begin_define
define|#
directive|define
name|wsel2
value|xw1.xwsel
end_define

begin_define
define|#
directive|define
name|wsel4
value|xw2.xwsel
end_define

begin_define
define|#
directive|define
name|wsel6
value|xw3.xwsel
end_define

begin_define
define|#
directive|define
name|wsel10
value|xw4.xwsel
end_define

begin_comment
comment|/*  * dmv software packet encapsulation.  This allows the dmv  * link to be multiplexed among several protocols.  * The first eight bytes of the dmc header are garbage,  * since on a vax the uba has been known to mung these  * bytes.  The next two bytes encapsulate packet type.  */
end_comment

begin_struct
struct|struct
name|dmv_header
block|{
name|short
name|dmv_type
decl_stmt|;
comment|/* encapsulate packet type */
block|}
struct|;
end_struct

begin_comment
comment|/* packet types */
end_comment

begin_define
define|#
directive|define
name|DMV_IPTYPE
value|1
end_define

begin_define
define|#
directive|define
name|DMV_TRAILER
value|2
end_define

begin_define
define|#
directive|define
name|DMV_NTRAILER
value|16
end_define

begin_comment
comment|/*  * DMVMTU includes space for data (1024) +   * protocol header (256) + trailer descriptor (4).  * The software link encapsulation header (dmv_header)  * is handled separately.  */
end_comment

begin_define
define|#
directive|define
name|DMVMTU
value|1284
end_define

begin_define
define|#
directive|define
name|RDYSCAN
value|16
end_define

begin_comment
comment|/* loop delay for RDYI after RQI */
end_comment

begin_comment
comment|/* defines for bsel0 */
end_comment

begin_define
define|#
directive|define
name|DMV_IEI
value|0x01
end_define

begin_comment
comment|/* interrupt enable, input */
end_comment

begin_define
define|#
directive|define
name|DMV_IEO
value|0x10
end_define

begin_comment
comment|/* interrupt enable, output */
end_comment

begin_define
define|#
directive|define
name|DMV_RQI
value|0x80
end_define

begin_comment
comment|/* request input */
end_comment

begin_define
define|#
directive|define
name|DMV0BITS
value|"\10\8RQI\5IEO\1IEI"
end_define

begin_comment
comment|/* defines for bsel1 */
end_comment

begin_define
define|#
directive|define
name|DMV_MCLR
value|0x40
end_define

begin_comment
comment|/* master clear */
end_comment

begin_define
define|#
directive|define
name|DMV_RUN
value|0x80
end_define

begin_comment
comment|/* run */
end_comment

begin_define
define|#
directive|define
name|DMV1BITS
value|"\10\8RUN\7MCLR"
end_define

begin_comment
comment|/* defines for bsel2 */
end_comment

begin_define
define|#
directive|define
name|DMV_CMD
value|0x07
end_define

begin_comment
comment|/* command/response type field */
end_comment

begin_comment
comment|/* input commands */
end_comment

begin_define
define|#
directive|define
name|DMV_BACCR
value|0x00
end_define

begin_comment
comment|/* buffer address, char. count - rec */
end_comment

begin_define
define|#
directive|define
name|DMV_BACCX
value|0x04
end_define

begin_comment
comment|/* buffer address, char. count - xmit */
end_comment

begin_define
define|#
directive|define
name|DMV_MDEFI
value|0x02
end_define

begin_comment
comment|/* mode definition input */
end_comment

begin_define
define|#
directive|define
name|DMV_CNTRLI
value|0x01
end_define

begin_comment
comment|/* control input */
end_comment

begin_comment
comment|/* response identifiers */
end_comment

begin_define
define|#
directive|define
name|DMV_CNTRLO
value|0x01
end_define

begin_comment
comment|/* control output */
end_comment

begin_define
define|#
directive|define
name|DMV_MDEFO
value|0x02
end_define

begin_comment
comment|/* information output */
end_comment

begin_define
define|#
directive|define
name|DMV_BDRUS
value|0x00
end_define

begin_comment
comment|/* buffer definition - rec. used */
end_comment

begin_define
define|#
directive|define
name|DMV_BDRUNUS
value|0x03
end_define

begin_comment
comment|/* buffer disposition - rec. unused */
end_comment

begin_define
define|#
directive|define
name|DMV_BDXSA
value|0x04
end_define

begin_comment
comment|/* buffer dispostiion - sent& ack */
end_comment

begin_define
define|#
directive|define
name|DMV_BDXSN
value|0x06
end_define

begin_comment
comment|/* buffer dispostiion - sent& not ack*/
end_comment

begin_define
define|#
directive|define
name|DMV_BDXNS
value|0x07
end_define

begin_comment
comment|/* buffer dispostiion - not sent */
end_comment

begin_define
define|#
directive|define
name|DMV_22BIT
value|0x08
end_define

begin_comment
comment|/* buffer address in 22 bit format */
end_comment

begin_define
define|#
directive|define
name|DMV_RDI
value|0x10
end_define

begin_comment
comment|/* ready for input */
end_comment

begin_define
define|#
directive|define
name|DMV_RDO
value|0x80
end_define

begin_comment
comment|/* ready for output */
end_comment

begin_define
define|#
directive|define
name|DMV2BITS
value|"\10\8RDO\5RDI"
end_define

begin_comment
comment|/* defines for CNTRLI mode */
end_comment

begin_define
define|#
directive|define
name|DMV_RDTSS
value|0x20
end_define

begin_comment
comment|/* read tributary status slot */
end_comment

begin_define
define|#
directive|define
name|DMV_RDCTSS
value|0x40
end_define

begin_comment
comment|/* read/clear tributary status slot */
end_comment

begin_define
define|#
directive|define
name|DMV_WRTSS
value|0x80
end_define

begin_comment
comment|/* write tributary status slot */
end_comment

begin_define
define|#
directive|define
name|DMV_TRIBN
value|0x1f
end_define

begin_comment
comment|/* tributary number */
end_comment

begin_define
define|#
directive|define
name|DMV_RQKEY
value|0x1f
end_define

begin_comment
comment|/* control command request key */
end_comment

begin_define
define|#
directive|define
name|DMV_ECBP
value|0x100
end_define

begin_comment
comment|/* establish common buffer pool */
end_comment

begin_comment
comment|/* relevant command request keys */
end_comment

begin_define
define|#
directive|define
name|DMV_NOP
value|0x00
end_define

begin_comment
comment|/* no-op */
end_comment

begin_define
define|#
directive|define
name|DMV_ESTTRIB
value|0x01
end_define

begin_comment
comment|/* establish tributary */
end_comment

begin_define
define|#
directive|define
name|DMV_REQSUS
value|0x03
end_define

begin_comment
comment|/* request start up state */
end_comment

begin_define
define|#
directive|define
name|DMV_REQHS
value|0x05
end_define

begin_comment
comment|/* request halt state */
end_comment

begin_define
define|#
directive|define
name|DMV_WMC
value|0x10
end_define

begin_comment
comment|/* write modem control */
end_comment

begin_define
define|#
directive|define
name|DMV_RMC
value|0x11
end_define

begin_comment
comment|/* read modem control */
end_comment

begin_comment
comment|/* some interesting CNTRLO codes  	 * 	 * use the manual if yours isn't here!! 	 */
end_comment

begin_define
define|#
directive|define
name|DMV_RTE
value|0002
end_define

begin_comment
comment|/* receive threshold error */
end_comment

begin_define
define|#
directive|define
name|DMV_TTE
value|0004
end_define

begin_comment
comment|/* xmit threshold error */
end_comment

begin_define
define|#
directive|define
name|DMV_STE
value|0006
end_define

begin_comment
comment|/* select threshold error */
end_comment

begin_define
define|#
directive|define
name|DMV_ORUN
value|0024
end_define

begin_comment
comment|/* other end enters run state */
end_comment

begin_define
define|#
directive|define
name|DMV_NXM
value|0302
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|DMV_MODD
value|0304
end_define

begin_comment
comment|/* modem disconnected */
end_comment

begin_define
define|#
directive|define
name|DMV_QOVF
value|0306
end_define

begin_comment
comment|/* response queue overflow */
end_comment

begin_define
define|#
directive|define
name|DMV_CXRL
value|0310
end_define

begin_comment
comment|/* modem cxr lost */
end_comment

begin_define
define|#
directive|define
name|DMV_EEC
value|0377
end_define

begin_comment
comment|/* CNTRLO error code mask */
end_comment

end_unit

