begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 Distributed Processing Technology Corporation  * All rights reserved.  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OSD_UNIX_H
end_ifndef

begin_define
define|#
directive|define
name|__OSD_UNIX_H
end_define

begin_comment
comment|/*File - OSD_UNIX.H */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*Description:                                                               */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*    This file contains definitions for the UNIX OS dependent layer of the  */
end_comment

begin_comment
comment|/*DPT engine.                                                                */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*Copyright Distributed Processing Technology, Corp.                         */
end_comment

begin_comment
comment|/*        140 Candace Dr.                                                    */
end_comment

begin_comment
comment|/*        Maitland, Fl. 32751   USA                                          */
end_comment

begin_comment
comment|/*        Phone: (407) 830-5522  Fax: (407) 260-5366                         */
end_comment

begin_comment
comment|/*        All Rights Reserved                                                */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*Author:       Bob Pasteur                                                  */
end_comment

begin_comment
comment|/*Date:         5/28/93                                                      */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*Editors:                                                                   */
end_comment

begin_comment
comment|/*		3/7/96	salyzyn@dpt.com					     */
end_comment

begin_comment
comment|/*			Added BSDi extensions				     */
end_comment

begin_comment
comment|/*		30/9/99	salyzyn@dpt.com					     */
end_comment

begin_comment
comment|/*			Added I2ORESCANCMD				     */
end_comment

begin_comment
comment|/*		7/12/99	salyzyn@dpt.com					     */
end_comment

begin_comment
comment|/*			Added I2ORESETCMD				     */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*Remarks:                                                                   */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* Definitions - Defines& Constants ---------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DPT_TurnAroundKey
value|0x01
end_define

begin_comment
comment|/* TurnAround Message Type for engine      */
end_comment

begin_define
define|#
directive|define
name|DPT_EngineKey
value|0x02
end_define

begin_comment
comment|/* Message Que and Type for engine         */
end_comment

begin_define
define|#
directive|define
name|DPT_LoggerKey
value|0x03
end_define

begin_comment
comment|/* Message Type For Logger                 */
end_comment

begin_define
define|#
directive|define
name|DPT_CommEngineKey
value|0x04
end_define

begin_comment
comment|/* Message Que Type Created                */
end_comment

begin_define
define|#
directive|define
name|MSG_RECEIVE
value|0x40000000
end_define

begin_comment
comment|/* Ored Into Logger PID For Return Msg     */
end_comment

begin_define
define|#
directive|define
name|ENGMSG_ECHO
value|0x00
end_define

begin_comment
comment|/* Turnarround Echo Engine Message         */
end_comment

begin_define
define|#
directive|define
name|ENGMSG_OPEN
value|0x01
end_define

begin_comment
comment|/* Turnarround Open Engine Message         */
end_comment

begin_define
define|#
directive|define
name|ENGMSG_CLOSE
value|0x02
end_define

begin_comment
comment|/* Turnarround Close Engine Message        */
end_comment

begin_comment
comment|/* Message Que Creation Flags */
end_comment

begin_define
define|#
directive|define
name|MSG_URD
value|00400
end_define

begin_define
define|#
directive|define
name|MSG_UWR
value|00200
end_define

begin_define
define|#
directive|define
name|MSG_GRD
value|00040
end_define

begin_define
define|#
directive|define
name|MSG_GWR
value|00020
end_define

begin_define
define|#
directive|define
name|MSG_ORD
value|00004
end_define

begin_define
define|#
directive|define
name|MSG_OWR
value|00002
end_define

begin_define
define|#
directive|define
name|MSG_ALLRD
value|00444
end_define

begin_define
define|#
directive|define
name|MSG_ALLWR
value|00222
end_define

begin_comment
comment|/* Message Que Creation Flags */
end_comment

begin_define
define|#
directive|define
name|SHM_URD
value|00400
end_define

begin_define
define|#
directive|define
name|SHM_UWR
value|00200
end_define

begin_define
define|#
directive|define
name|SHM_GRD
value|00040
end_define

begin_define
define|#
directive|define
name|SHM_GWR
value|00020
end_define

begin_define
define|#
directive|define
name|SHM_ORD
value|00004
end_define

begin_define
define|#
directive|define
name|SHM_OWR
value|00002
end_define

begin_define
define|#
directive|define
name|SHM_ALLRD
value|00444
end_define

begin_define
define|#
directive|define
name|SHM_ALLWR
value|00222
end_define

begin_comment
comment|/* Program Exit Codes */
end_comment

begin_define
define|#
directive|define
name|ExitGoodStatus
value|0
end_define

begin_define
define|#
directive|define
name|ExitBadParameter
value|1
end_define

begin_define
define|#
directive|define
name|ExitSignalFail
value|3
end_define

begin_define
define|#
directive|define
name|ExitMsqAllocFail
value|5
end_define

begin_define
define|#
directive|define
name|ExitBuffAllocFail
value|6
end_define

begin_define
define|#
directive|define
name|ExitMsgSendFail
value|8
end_define

begin_define
define|#
directive|define
name|ExitMsgReceiveFail
value|9
end_define

begin_define
define|#
directive|define
name|ExitEngOpenFail
value|10
end_define

begin_define
define|#
directive|define
name|ExitDuplicateEngine
value|11
end_define

begin_define
define|#
directive|define
name|ExitCommAllocFail
value|12
end_define

begin_define
define|#
directive|define
name|ExitDuplicateCommEng
value|13
end_define

begin_define
define|#
directive|define
name|ExitCommConnectFail
value|14
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_HAS
end_ifndef

begin_define
define|#
directive|define
name|MAX_HAS
value|18
end_define

begin_define
define|#
directive|define
name|MAX_NAME
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef MAX_HAS */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uCHAR
name|ConfigLength
index|[
literal|4
index|]
decl_stmt|;
comment|/* Len in bytes after this field.      */
name|uCHAR
name|EATAsignature
index|[
literal|4
index|]
decl_stmt|;
name|uCHAR
name|EATAversion
decl_stmt|;
name|uCHAR
name|Flags1
decl_stmt|;
name|uCHAR
name|PadLength
index|[
literal|2
index|]
decl_stmt|;
name|uCHAR
name|HBA
index|[
literal|4
index|]
decl_stmt|;
name|uCHAR
name|CPlength
index|[
literal|4
index|]
decl_stmt|;
comment|/* Command Packet Length               */
name|uCHAR
name|SPlength
index|[
literal|4
index|]
decl_stmt|;
comment|/* Status Packet Length                */
name|uCHAR
name|QueueSize
index|[
literal|2
index|]
decl_stmt|;
comment|/* Controller Que depth                */
name|uCHAR
name|SG_Size
index|[
literal|4
index|]
decl_stmt|;
name|uCHAR
name|Flags2
decl_stmt|;
name|uCHAR
name|Reserved0
decl_stmt|;
comment|/* Reserved Field                       */
name|uCHAR
name|Flags3
decl_stmt|;
name|uCHAR
name|ScsiValues
decl_stmt|;
name|uCHAR
name|MaxLUN
decl_stmt|;
comment|/* Maximun LUN Supported                */
name|uCHAR
name|Flags4
decl_stmt|;
name|uCHAR
name|RaidNum
decl_stmt|;
comment|/* RAID HBA Number For Stripping        */
name|uCHAR
name|Reserved3
decl_stmt|;
comment|/* Reserved Field                       */
block|}
name|DptReadConfig_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DPT_SOLARIS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ddidmareq.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/scsi/scsi.h>
end_include

begin_comment
comment|//#define _KERNEL
end_comment

begin_include
include|#
directive|include
file|<sys/dditypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/ddi_impldefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/scsi/impl/transport.h>
end_include

begin_comment
comment|//#undef _KERNEL
end_comment

begin_undef
undef|#
directive|undef
name|MSG_DISCONNECT
end_undef

begin_define
define|#
directive|define
name|MSG_DISCONNECT
value|0x11L
end_define

begin_define
define|#
directive|define
name|EATAUSRCMD
value|1
end_define

begin_define
define|#
directive|define
name|DPT_SIGNATURE
value|2
end_define

begin_define
define|#
directive|define
name|DPT_NUMCTRLS
value|3
end_define

begin_define
define|#
directive|define
name|DPT_CTRLINFO
value|4
end_define

begin_define
define|#
directive|define
name|DPT_SYSINFO
value|5
end_define

begin_define
define|#
directive|define
name|DPT_BLINKLED
value|6
end_define

begin_define
define|#
directive|define
name|I2OUSRCMD
value|7
end_define

begin_comment
comment|//#define I2ORESCANCMD 8	/* Use DPT_IO_ACCESS instead */
end_comment

begin_comment
comment|//#define I2ORESETCMD  9	/* Use DPT_IO_ACCESS instead */
end_comment

begin_define
define|#
directive|define
name|DPT_MAX_DMA_SEGS
value|32
end_define

begin_comment
comment|/* Max used Scatter/Gather seg         */
end_comment

begin_struct
struct|struct
name|dpt_sg
block|{
name|paddr_t
name|data_addr
decl_stmt|;
name|uLONG
name|data_len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|uSHORT
name|NumHBAs
decl_stmt|;
name|uLONG
name|IOAddrs
index|[
literal|18
index|]
decl_stmt|;
block|}
name|GetHbaInfo_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_DPT_DGUX
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOWR
end_ifndef

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(0x0fff3900|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOW
end_ifndef

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(0x0fff3900|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOR
end_ifndef

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(0x0fff3900|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IO
end_ifndef

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(0x0fff3900|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EATA PassThrough Command	*/
end_comment

begin_define
define|#
directive|define
name|EATAUSRCMD
value|_IOWR('D',65,EATA_CP)
end_define

begin_comment
comment|/* Get Signature Structure	*/
end_comment

begin_define
define|#
directive|define
name|DPT_SIGNATURE
value|_IOR('D',67,dpt_sig_S)
end_define

begin_comment
comment|/* Get Number Of DPT Adapters	*/
end_comment

begin_define
define|#
directive|define
name|DPT_NUMCTRLS
value|_IOR('D',68,int)
end_define

begin_comment
comment|/* Get Adapter Info Structure	*/
end_comment

begin_define
define|#
directive|define
name|DPT_CTRLINFO
value|_IOR('D',69,CtrlInfo)
end_define

begin_comment
comment|/* Get System Info Structure	*/
end_comment

begin_define
define|#
directive|define
name|DPT_SYSINFO
value|_IOR('D',72,sysInfo_S)
end_define

begin_comment
comment|/* Get Blink LED Code	        */
end_comment

begin_define
define|#
directive|define
name|DPT_BLINKLED
value|_IOR('D',75,int)
end_define

begin_comment
comment|/* Get Statistical information (if available) */
end_comment

begin_define
define|#
directive|define
name|DPT_STATS_INFO
value|_IOR('D',80,STATS_DATA)
end_define

begin_comment
comment|/* Clear the statistical information          */
end_comment

begin_define
define|#
directive|define
name|DPT_STATS_CLEAR
value|_IO('D',81)
end_define

begin_comment
comment|/* Send an I2O command */
end_comment

begin_define
define|#
directive|define
name|I2OUSRCMD
value|_IO('D',76)
end_define

begin_comment
comment|/* Inform driver to re-acquire LCT information */
end_comment

begin_define
define|#
directive|define
name|I2ORESCANCMD
value|_IO('D',77)
end_define

begin_comment
comment|/* Inform driver to reset adapter */
end_comment

begin_define
define|#
directive|define
name|I2ORESETCMD
value|_IO('D',78)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SNI_MIPS
argument_list|)
end_elif

begin_comment
comment|/* Unix Ioctl Command definitions */
end_comment

begin_define
define|#
directive|define
name|EATAUSRCMD
value|(('D'<<8)|65)
end_define

begin_define
define|#
directive|define
name|DPT_DEBUG
value|(('D'<<8)|66)
end_define

begin_define
define|#
directive|define
name|DPT_SIGNATURE
value|(('D'<<8)|67)
end_define

begin_define
define|#
directive|define
name|DPT_NUMCTRLS
value|(('D'<<8)|68)
end_define

begin_define
define|#
directive|define
name|DPT_CTRLINFO
value|(('D'<<8)|69)
end_define

begin_define
define|#
directive|define
name|DPT_STATINFO
value|(('D'<<8)|70)
end_define

begin_define
define|#
directive|define
name|DPT_CLRSTAT
value|(('D'<<8)|71)
end_define

begin_define
define|#
directive|define
name|DPT_SYSINFO
value|(('D'<<8)|72)
end_define

begin_comment
comment|/* Set Timeout Value		*/
end_comment

begin_define
define|#
directive|define
name|DPT_TIMEOUT
value|(('D'<<8)|73)
end_define

begin_comment
comment|/* Get config Data  		*/
end_comment

begin_define
define|#
directive|define
name|DPT_CONFIG
value|(('D'<<8)|74)
end_define

begin_comment
comment|/* Get config Data  		*/
end_comment

begin_define
define|#
directive|define
name|DPT_BLINKLED
value|(('D'<<8)|75)
end_define

begin_comment
comment|/* Get Statistical information (if available) */
end_comment

begin_define
define|#
directive|define
name|DPT_STATS_INFO
value|(('D'<<8)|80)
end_define

begin_comment
comment|/* Clear the statistical information          */
end_comment

begin_define
define|#
directive|define
name|DPT_STATS_CLEAR
value|(('D'<<8)|81)
end_define

begin_comment
comment|/* Send an I2O command */
end_comment

begin_define
define|#
directive|define
name|I2OUSRCMD
value|(('D'<<8)|76)
end_define

begin_comment
comment|/* Inform driver to re-acquire LCT information */
end_comment

begin_define
define|#
directive|define
name|I2ORESCANCMD
value|(('D'<<8)|77)
end_define

begin_comment
comment|/* Inform driver to reset adapter */
end_comment

begin_define
define|#
directive|define
name|I2ORESETCMD
value|(('D'<<8)|78)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Unix Ioctl Command definitions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DPT_AIX
end_ifdef

begin_undef
undef|#
directive|undef
name|_IOWR
end_undef

begin_undef
undef|#
directive|undef
name|_IOW
end_undef

begin_undef
undef|#
directive|undef
name|_IOR
end_undef

begin_undef
undef|#
directive|undef
name|_IO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOWR
end_ifndef

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)<<8)|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOW
end_ifndef

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)<<8)|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IOR
end_ifndef

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)<<8)|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_IO
end_ifndef

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<<8)|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EATA PassThrough Command	*/
end_comment

begin_define
define|#
directive|define
name|EATAUSRCMD
value|_IOWR('D',65,EATA_CP)
end_define

begin_comment
comment|/* Set Debug Level If Enabled	*/
end_comment

begin_define
define|#
directive|define
name|DPT_DEBUG
value|_IOW('D',66,int)
end_define

begin_comment
comment|/* Get Signature Structure	*/
end_comment

begin_define
define|#
directive|define
name|DPT_SIGNATURE
value|_IOR('D',67,dpt_sig_S)
end_define

begin_if
if|#
directive|if
name|defined
name|__bsdi__
end_if

begin_define
define|#
directive|define
name|DPT_SIGNATURE_PACKED
value|_IOR('D',67,dpt_sig_S_Packed)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get Number Of DPT Adapters	*/
end_comment

begin_define
define|#
directive|define
name|DPT_NUMCTRLS
value|_IOR('D',68,int)
end_define

begin_comment
comment|/* Get Adapter Info Structure	*/
end_comment

begin_define
define|#
directive|define
name|DPT_CTRLINFO
value|_IOR('D',69,CtrlInfo)
end_define

begin_comment
comment|/* Get Statistics If Enabled	*/
end_comment

begin_define
define|#
directive|define
name|DPT_STATINFO
value|_IO('D',70)
end_define

begin_comment
comment|/* Clear Stats If Enabled	*/
end_comment

begin_define
define|#
directive|define
name|DPT_CLRSTAT
value|_IO('D',71)
end_define

begin_comment
comment|/* Get System Info Structure	*/
end_comment

begin_define
define|#
directive|define
name|DPT_SYSINFO
value|_IOR('D',72,sysInfo_S)
end_define

begin_comment
comment|/* Set Timeout Value		*/
end_comment

begin_define
define|#
directive|define
name|DPT_TIMEOUT
value|_IO('D',73)
end_define

begin_comment
comment|/* Get config Data  		*/
end_comment

begin_define
define|#
directive|define
name|DPT_CONFIG
value|_IO('D',74)
end_define

begin_comment
comment|/* Get Blink LED Code	        */
end_comment

begin_define
define|#
directive|define
name|DPT_BLINKLED
value|_IOR('D',75,int)
end_define

begin_comment
comment|/* Get Statistical information (if available) */
end_comment

begin_define
define|#
directive|define
name|DPT_STATS_INFO
value|_IOR('D',80,STATS_DATA)
end_define

begin_comment
comment|/* Clear the statistical information          */
end_comment

begin_define
define|#
directive|define
name|DPT_STATS_CLEAR
value|_IO('D',81)
end_define

begin_comment
comment|/* Get Performance metrics */
end_comment

begin_define
define|#
directive|define
name|DPT_PERF_INFO
value|_IOR('D',82,dpt_perf_t)
end_define

begin_comment
comment|/* Send an I2O command */
end_comment

begin_define
define|#
directive|define
name|I2OUSRCMD
value|_IO('D',76)
end_define

begin_comment
comment|/* Inform driver to re-acquire LCT information */
end_comment

begin_define
define|#
directive|define
name|I2ORESCANCMD
value|_IO('D',77)
end_define

begin_comment
comment|/* Inform driver to reset adapter */
end_comment

begin_define
define|#
directive|define
name|I2ORESETCMD
value|_IO('D',78)
end_define

begin_if
if|#
directive|if
name|defined
name|_DPT_LINUX
end_if

begin_comment
comment|/* See if the target is mounted */
end_comment

begin_define
define|#
directive|define
name|DPT_TARGET_BUSY
value|_IOR('D',79, TARGET_BUSY_T)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DPT_SOLARIS else */
end_comment

begin_comment
comment|/* Adapter Flags Field Bit Definitions */
end_comment

begin_define
define|#
directive|define
name|CTLR_INSTALLED
value|0x00000001
end_define

begin_comment
comment|/* Adapter Was Installed        */
end_comment

begin_define
define|#
directive|define
name|CTLR_DMA
value|0x00000002
end_define

begin_comment
comment|/* DMA Supported                */
end_comment

begin_define
define|#
directive|define
name|CTLR_OVERLAP
value|0x00000004
end_define

begin_comment
comment|/* Overlapped Commands Support  */
end_comment

begin_define
define|#
directive|define
name|CTLR_SECONDARY
value|0x00000008
end_define

begin_comment
comment|/* I/O Address Not 0x1f0        */
end_comment

begin_define
define|#
directive|define
name|CTLR_BLINKLED
value|0x00000010
end_define

begin_comment
comment|/* Adapter In Blink LED State   */
end_comment

begin_define
define|#
directive|define
name|CTLR_HBACI
value|0x00000020
end_define

begin_comment
comment|/* Cache Inhibit Supported      */
end_comment

begin_define
define|#
directive|define
name|CTLR_CACHE
value|0x00000040
end_define

begin_comment
comment|/* Adapter Has Cache            */
end_comment

begin_define
define|#
directive|define
name|CTLR_SANE
value|0x00000080
end_define

begin_comment
comment|/* Adapter Functioning OK       */
end_comment

begin_define
define|#
directive|define
name|CTLR_BUS_QUIET
value|0x00000100
end_define

begin_comment
comment|/* Bus Quite On This Adapter    */
end_comment

begin_define
define|#
directive|define
name|CTLR_ABOVE_16
value|0x00000200
end_define

begin_comment
comment|/* Support For Mem. Above 16 MB */
end_comment

begin_define
define|#
directive|define
name|CTLR_SCAT_GATH
value|0x00000400
end_define

begin_comment
comment|/* Scatter Gather Supported     */
end_comment

begin_comment
comment|/* Definitions - Structure& Typedef ---------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uLONG
name|MsgID
decl_stmt|;
name|DPT_TAG_T
name|engineTag
decl_stmt|;
name|DPT_TAG_T
name|targetTag
decl_stmt|;
name|DPT_MSG_T
name|engEvent
decl_stmt|;
name|long
name|BufferID
decl_stmt|;
name|uLONG
name|FromEngBuffOffset
decl_stmt|;
name|uLONG
name|callerID
decl_stmt|;
name|DPT_RTN_T
name|result
decl_stmt|;
name|uLONG
name|timeOut
decl_stmt|;
block|}
name|MsgHdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MsgDataSize
value|sizeof(MsgHdr) - 4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SNI_MIPS
end_ifndef

begin_comment
comment|/*-------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*                     EATA Command Packet definition                      */
end_comment

begin_comment
comment|/*-------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|EATACommandPacket
block|{
ifdef|#
directive|ifdef
name|_DPT_UNIXWARE
name|uCHAR
name|EataID
index|[
literal|4
index|]
decl_stmt|;
name|uINT
name|EataCmd
decl_stmt|;
name|uCHAR
modifier|*
name|CmdBuffer
decl_stmt|;
endif|#
directive|endif
comment|/* _DPT_UNIXWARE */
ifdef|#
directive|ifdef
name|_DPT_AIX
name|uCHAR
name|HbaTargetID
decl_stmt|;
name|uCHAR
name|HbaLUN
decl_stmt|;
endif|#
directive|endif
comment|/* _DPT_AIX */
name|uCHAR
name|cp_Flags1
decl_stmt|;
comment|/* Command Flags                       */
name|uCHAR
name|cp_Req_Len
decl_stmt|;
comment|/* AutoRequestSense Data length.       */
name|uCHAR
name|cp_Resv1
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved Fields                     */
name|uCHAR
name|cp_Flags2
decl_stmt|;
name|uCHAR
name|cp_Flags3
decl_stmt|;
name|uCHAR
name|cp_ScsiAddr
decl_stmt|;
name|uCHAR
name|cp_msg0
decl_stmt|;
comment|/* Identify and Disconnect Message.    */
name|uCHAR
name|cp_msg1
decl_stmt|;
name|uCHAR
name|cp_msg2
decl_stmt|;
name|uCHAR
name|cp_msg3
decl_stmt|;
name|uCHAR
name|cp_cdb
index|[
literal|12
index|]
decl_stmt|;
comment|/* SCSI cdb for command.               */
name|uLONG
name|cp_dataLen
decl_stmt|;
comment|/* Data length in Bytes for command.   */
name|uLONG
name|cp_Vue
decl_stmt|;
comment|/* Vendor Unique Area                  */
name|uCHAR
modifier|*
name|cp_DataAddr
decl_stmt|;
comment|/* Data Address For The Command.       */
name|uCHAR
modifier|*
name|cp_SpAddr
decl_stmt|;
comment|/* Status Packet Physical Address.     */
name|uCHAR
modifier|*
name|cp_SenseAddr
decl_stmt|;
comment|/* AutoRequestSense Data Phy Address.  */
ifdef|#
directive|ifdef
name|_DPT_SOLARIS
name|uCHAR
name|HostStatus
decl_stmt|;
name|uCHAR
name|TargetStatus
decl_stmt|;
name|uCHAR
name|CdbLength
decl_stmt|;
name|uCHAR
name|SG_Size
decl_stmt|;
name|struct
name|scsi_arq_status
name|ReqSenseData
decl_stmt|;
name|struct
name|dpt_sg
name|SG_List
index|[
name|DPT_MAX_DMA_SEGS
index|]
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|b_scratch
decl_stmt|;
name|struct
name|scsi_cmd
modifier|*
name|b_ownerp
decl_stmt|;
block|}
name|cc
union|;
name|paddr_t
name|ccb_paddr
decl_stmt|;
name|uSHORT
name|IOAddress
decl_stmt|;
else|#
directive|else
comment|/* _DPT_SOLARIS */
name|uLONG
name|TimeOut
decl_stmt|;
name|uCHAR
name|HostStatus
decl_stmt|;
name|uCHAR
name|TargetStatus
decl_stmt|;
name|uCHAR
name|Retries
decl_stmt|;
endif|#
directive|endif
comment|/* _DPT_SOLARIS else */
block|}
name|EATA_CP
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SNI_MIPS
end_comment

begin_comment
comment|/* Control Flags 1 Definitions */
end_comment

begin_define
define|#
directive|define
name|SCSI_RESET
value|0x01
end_define

begin_comment
comment|/* Cause a SCSI Bus reset on the cmd */
end_comment

begin_define
define|#
directive|define
name|HBA_INIT
value|0x02
end_define

begin_comment
comment|/* Cause Controller to reInitialize  */
end_comment

begin_define
define|#
directive|define
name|AUTO_REQ_SENSE
value|0x04
end_define

begin_comment
comment|/* Do Auto Request Sense on errors   */
end_comment

begin_define
define|#
directive|define
name|SCATTER_GATHER
value|0x08
end_define

begin_comment
comment|/* Data Ptr points to a SG Packet    */
end_comment

begin_define
define|#
directive|define
name|INTERPRET
value|0x20
end_define

begin_comment
comment|/* Interpret the SCSI cdb of own use */
end_comment

begin_define
define|#
directive|define
name|DATA_OUT
value|0x04
end_define

begin_comment
comment|/* Data Out phase with command       */
end_comment

begin_define
define|#
directive|define
name|DATA_IN
value|0x08
end_define

begin_comment
comment|/* Data In phase with command        */
end_comment

begin_comment
comment|/* Control Flags 2 Definitions */
end_comment

begin_define
define|#
directive|define
name|FIRMWARE_NESTED
value|0x01
end_define

begin_comment
comment|/* Control Flags 3 Definitions */
end_comment

begin_define
define|#
directive|define
name|PHYSICAL_UNIT
value|0x01
end_define

begin_comment
comment|/* Send Command Directly To Target   */
end_comment

begin_define
define|#
directive|define
name|IAT
value|0x02
end_define

begin_comment
comment|/* Inhibit Address Translation       */
end_comment

begin_define
define|#
directive|define
name|HBACI
value|0x04
end_define

begin_comment
comment|/* Inhibit Caching                   */
end_comment

begin_comment
comment|/* Structure Returned From Get Controller Info                             */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uCHAR
name|state
decl_stmt|;
comment|/* Operational state               */
name|uCHAR
name|id
decl_stmt|;
comment|/* Host adapter SCSI id            */
name|int
name|vect
decl_stmt|;
comment|/* Interrupt vector number         */
name|int
name|base
decl_stmt|;
comment|/* Base I/O address                */
name|int
name|njobs
decl_stmt|;
comment|/* # of jobs sent to HA            */
name|int
name|qdepth
decl_stmt|;
comment|/* Controller queue depth.         */
name|int
name|wakebase
decl_stmt|;
comment|/* mpx wakeup base index.          */
name|uLONG
name|SGsize
decl_stmt|;
comment|/* Scatter/Gather list size.       */
name|unsigned
name|heads
decl_stmt|;
comment|/* heads for drives on cntlr.      */
name|unsigned
name|sectors
decl_stmt|;
comment|/* sectors for drives on cntlr.    */
name|uCHAR
name|do_drive32
decl_stmt|;
comment|/* Flag for Above 16 MB Ability    */
name|uCHAR
name|BusQuiet
decl_stmt|;
comment|/* SCSI Bus Quiet Flag             */
name|char
name|idPAL
index|[
literal|4
index|]
decl_stmt|;
comment|/* 4 Bytes Of The ID Pal           */
name|uCHAR
name|primary
decl_stmt|;
comment|/* 1 For Primary, 0 For Secondary  */
name|uCHAR
name|eataVersion
decl_stmt|;
comment|/* EATA Version                    */
name|uLONG
name|cpLength
decl_stmt|;
comment|/* EATA Command Packet Length      */
name|uLONG
name|spLength
decl_stmt|;
comment|/* EATA Status Packet Length       */
name|uCHAR
name|drqNum
decl_stmt|;
comment|/* DRQ Index (0,5,6,7)             */
name|uCHAR
name|flag1
decl_stmt|;
comment|/* EATA Flags 1 (Byte 9)           */
name|uCHAR
name|flag2
decl_stmt|;
comment|/* EATA Flags 2 (Byte 30)          */
block|}
name|CtrlInfo
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|SNI_MIPS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_DPT_UNIXWARE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uINT
name|state
decl_stmt|;
comment|/* Operational state            */
name|uCHAR
name|id
index|[
literal|4
index|]
decl_stmt|;
comment|/* Host adapter SCSI id         */
name|uINT
name|vect
decl_stmt|;
comment|/* Interrupt vector number      */
name|uLONG
name|base
decl_stmt|;
comment|/* Base I/O address             */
name|int
name|ha_max_jobs
decl_stmt|;
comment|/* Max number of Active Jobs    */
name|uLONG
name|ha_cacheParams
decl_stmt|;
name|int
name|ha_nbus
decl_stmt|;
comment|/* Number Of Busses on HBA      */
name|int
name|ha_ntargets
decl_stmt|;
comment|/* Number Of Targets Supported  */
name|int
name|ha_nluns
decl_stmt|;
comment|/* Number Of LUNs Supported     */
name|int
name|ha_tshift
decl_stmt|;
comment|/* Shift value for target       */
name|int
name|ha_bshift
decl_stmt|;
comment|/* Shift value for bus          */
name|uINT
name|ha_npend
decl_stmt|;
comment|/* # of jobs sent to HA         */
name|int
name|ha_active_jobs
decl_stmt|;
comment|/* Number Of Active Jobs        */
block|}
name|HbaInfo
typedef|;
end_typedef

begin_comment
comment|/* SDI ioctl prefix for hba specific ioctl's */
end_comment

begin_define
define|#
directive|define
name|SDI_IOC
value|(('S'<<24)|('D'<<16)|('I'<<8))
end_define

begin_define
define|#
directive|define
name|SDI_HBANAME
value|((SDI_IOC)|0x14)
end_define

begin_comment
comment|/* Get HBA module name      */
end_comment

begin_define
define|#
directive|define
name|SDI_SEND
value|0x0081
end_define

begin_comment
comment|/* Send a SCSI command      */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|uLONG
name|flags
decl_stmt|;
comment|/* Operational State Flags         */
name|uCHAR
name|id
index|[
literal|4
index|]
decl_stmt|;
comment|/* Host Adapter SCSI ID            */
name|int
name|vect
decl_stmt|;
comment|/* Interrupt Vector Number         */
name|int
name|base
decl_stmt|;
comment|/* Base I/O Address                */
name|int
name|njobs
decl_stmt|;
comment|/* # Of CCBs Outstanding To HBA    */
name|int
name|qdepth
decl_stmt|;
comment|/* Controller Queue depth.         */
name|uLONG
name|SGsize
decl_stmt|;
comment|/* Scatter/Gather List Size.       */
name|char
name|idPAL
index|[
literal|4
index|]
decl_stmt|;
comment|/* 4 Bytes Of The ID Pal           */
name|uCHAR
name|eataVersion
decl_stmt|;
comment|/* EATA Version                    */
name|uLONG
name|cpLength
decl_stmt|;
comment|/* EATA Command Packet Length      */
name|uLONG
name|spLength
decl_stmt|;
comment|/* EATA Status Packet Length       */
name|uCHAR
name|drqNum
decl_stmt|;
comment|/* DRQ Index (0,5,6,7)             */
name|uCHAR
name|eataflag1
decl_stmt|;
comment|/* EATA Flags 1 (Byte 9)           */
name|uCHAR
name|eataflag2
decl_stmt|;
comment|/* EATA Flags 2 (Byte 30)          */
name|uCHAR
name|maxChannel
decl_stmt|;
comment|/* Maximum Channel Number          */
name|uCHAR
name|maxID
decl_stmt|;
comment|/* Maximum Target ID               */
name|uCHAR
name|maxLUN
decl_stmt|;
comment|/* Maximum LUN                     */
name|uCHAR
name|HbaBusType
decl_stmt|;
comment|/* HBA Bus Type, EISA, PCI, etc    */
name|uCHAR
name|RaidNum
decl_stmt|;
comment|/* Host Adapter RAID Number        */
block|}
name|HbaInfo
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DPT_UNIXWARE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SNI_MIPS
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DPT_AIX
end_ifdef

begin_comment
comment|/*  * DPT Host Adapter config information structure - this structure contains  * configuration information about an adapter.  It is imbedded into the   * dpt_ctl structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dpt_cfg
block|{
name|uchar
name|flags
decl_stmt|;
comment|/* Operational state flags	*/
name|uchar
name|id
index|[
literal|4
index|]
decl_stmt|;
comment|/* Host adapter SCSI IDs	*/
name|int
name|vect
decl_stmt|;
comment|/* Interrupt vector number	*/
name|ulong
name|base_addr
decl_stmt|;
comment|/* Base I/O address		*/
name|int
name|qdepth
decl_stmt|;
comment|/* Controller queue depth.	*/
name|ulong
name|SGsize
decl_stmt|;
comment|/* Max scatter/gather list sz	*/
name|ulong
name|SGmax
decl_stmt|;
comment|/* Max s/g we can use per req	*/
name|uchar
name|eataVersion
decl_stmt|;
comment|/* EATA version			*/
name|ushort
name|cpPadLen
decl_stmt|;
comment|/* # of pad bytes sent to HA for 					   PIO commands			*/
name|ulong
name|cpLength
decl_stmt|;
comment|/* EATA Command Packet length	*/
name|ulong
name|spLength
decl_stmt|;
comment|/* EATA Status Packet length	*/
name|uchar
name|eataflag1
decl_stmt|;
comment|/* EATA Flags 1 (Byte 9)	*/
name|uchar
name|eataflag2
decl_stmt|;
comment|/* EATA Flags 2 (Byte 30)	*/
name|uchar
name|maxChan
decl_stmt|;
comment|/* Maximum Channel number	*/
name|uchar
name|maxID
decl_stmt|;
comment|/* Maximum target ID		*/
name|uchar
name|maxLUN
decl_stmt|;
comment|/* Maximum LUN			*/
name|uchar
name|HbaBusType
decl_stmt|;
comment|/* HBA bus type, EISA, PCI, etc	*/
name|uchar
name|RaidNum
decl_stmt|;
comment|/* Host adapter RAID number	*/
block|}
name|DptCfg_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DPT_AIX */
end_comment

begin_define
define|#
directive|define
name|MAX_ELEMENT_COUNT
value|64
end_define

begin_define
define|#
directive|define
name|MAX_BUCKET_COUNT
value|10
end_define

begin_comment
comment|/*  * DPT statistics structure definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|IO_SIZE_STATS
block|{
name|uLONG
name|TotalIoCount
decl_stmt|;
name|uLONG
name|IoCountRead
decl_stmt|;
name|uLONG
name|IoCountReadSg
decl_stmt|;
name|uLONG
name|IoCountWrite
decl_stmt|;
name|uLONG
name|IoCountWriteSg
decl_stmt|;
name|uLONG
name|UnalignedIoAddress
decl_stmt|;
name|uLONG
name|SgElementCount
index|[
name|MAX_ELEMENT_COUNT
index|]
decl_stmt|;
block|}
name|IO_SIZE_STATS_T
operator|,
typedef|*
name|pIO_SIZE_STATS_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|STATS_DATA
block|{
name|uLONG
name|TotalIoCount
decl_stmt|;
name|uLONG
name|TotalUnCachedIoCount
decl_stmt|;
name|uLONG
name|MaxOutstandingIoCount
decl_stmt|;
name|uLONG
name|CurrentOutstandingIoCount
decl_stmt|;
name|uLONG
name|OutstandingIoRunningCount
decl_stmt|;
name|uLONG
name|UnalignedPktCount
decl_stmt|;
name|uLONG
name|UnalignedSgCount
decl_stmt|;
name|uLONG
name|NonPageListAddressSgCount
decl_stmt|;
name|uLONG
name|MaxMessagesPerInterrupt
decl_stmt|;
name|IO_SIZE_STATS_T
name|IoSize
index|[
name|MAX_BUCKET_COUNT
index|]
decl_stmt|;
block|}
name|STATS_DATA_T
operator|,
typedef|*
name|pSTATS_DATA_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|TARGET_BUSY
block|{
name|uLONG
name|channel
decl_stmt|;
name|uLONG
name|id
decl_stmt|;
name|uLONG
name|lun
decl_stmt|;
name|uLONG
name|isBusy
decl_stmt|;
block|}
name|TARGET_BUSY_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OSD_UNIX_H */
end_comment

end_unit

