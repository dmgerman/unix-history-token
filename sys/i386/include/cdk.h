begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  * cdk.h  -- CDK interface definitions.  *  * Copyright (c) 1994-1998 Greg Ungerer (gerg@stallion.oz.au).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Greg Ungerer.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CDK_H
end_ifndef

begin_define
define|#
directive|define
name|_CDK_H
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|2
name|)
end_pragma

begin_comment
comment|/*  *	The following set of definitions is used to communicate with the  *	shared memory interface of the Stallion intelligent multiport serial  *	boards. The definitions in this file are taken directly from the  *	document titled "Generic Stackable Interface, Downloader and  *	Communications Development Kit".  */
end_comment

begin_comment
comment|/*  *	Define the set of importrant shared memory addresses. These are  *	required to intialize the board and get things started. All of these  *	addresses are relative to the start of the shared memory.  */
end_comment

begin_define
define|#
directive|define
name|CDK_SIGADDR
value|0x200
end_define

begin_define
define|#
directive|define
name|CDK_FEATADDR
value|0x280
end_define

begin_define
define|#
directive|define
name|CDK_CDKADDR
value|0x300
end_define

begin_define
define|#
directive|define
name|CDK_RDYADDR
value|0x262
end_define

begin_define
define|#
directive|define
name|CDK_ALIVEMARKER
value|13
end_define

begin_comment
comment|/*  *	On hardware power up the ROMs located on the EasyConnection 8/64 will  *	fill out the following signature information into shared memory. This  *	way the host system can quickly determine that the board is present  *	and is operational.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkecpsig
block|{
name|unsigned
name|long
name|magic
decl_stmt|;
name|unsigned
name|short
name|romver
decl_stmt|;
name|unsigned
name|short
name|cputype
decl_stmt|;
name|unsigned
name|char
name|panelid
index|[
literal|8
index|]
decl_stmt|;
block|}
name|cdkecpsig_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ECP_MAGIC
value|0x21504345
end_define

begin_comment
comment|/*  *	On hardware power up the ROMs located on the ONboard, Stallion and  *	Brumbys will fill out the following signature information into shared  *	memory. This way the host system can quickly determine that the board  *	is present and is operational.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkonbsig
block|{
name|unsigned
name|short
name|magic0
decl_stmt|;
name|unsigned
name|short
name|magic1
decl_stmt|;
name|unsigned
name|short
name|magic2
decl_stmt|;
name|unsigned
name|short
name|magic3
decl_stmt|;
name|unsigned
name|short
name|romver
decl_stmt|;
name|unsigned
name|short
name|memoff
decl_stmt|;
name|unsigned
name|short
name|memseg
decl_stmt|;
name|unsigned
name|short
name|amask0
decl_stmt|;
name|unsigned
name|short
name|pic
decl_stmt|;
name|unsigned
name|short
name|status
decl_stmt|;
name|unsigned
name|short
name|btype
decl_stmt|;
name|unsigned
name|short
name|clkticks
decl_stmt|;
name|unsigned
name|short
name|clkspeed
decl_stmt|;
name|unsigned
name|short
name|amask1
decl_stmt|;
name|unsigned
name|short
name|amask2
decl_stmt|;
block|}
name|cdkonbsig_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ONB_MAGIC0
value|0xf2a7
end_define

begin_define
define|#
directive|define
name|ONB_MAGIC1
value|0xa149
end_define

begin_define
define|#
directive|define
name|ONB_MAGIC2
value|0x6352
end_define

begin_define
define|#
directive|define
name|ONB_MAGIC3
value|0xf121
end_define

begin_comment
comment|/*  *	Define the feature area structure. The feature area is the set of  *	startup parameters used by the slave image when it starts executing.  *	They allow for the specification of buffer sizes, debug trace, etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkfeature
block|{
name|unsigned
name|long
name|debug
decl_stmt|;
name|unsigned
name|long
name|banner
decl_stmt|;
name|unsigned
name|long
name|etype
decl_stmt|;
name|unsigned
name|long
name|nrdevs
decl_stmt|;
name|unsigned
name|long
name|brdspec
decl_stmt|;
name|unsigned
name|long
name|txrqsize
decl_stmt|;
name|unsigned
name|long
name|rxrqsize
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
block|}
name|cdkfeature_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ETYP_DDK
value|0
end_define

begin_define
define|#
directive|define
name|ETYP_CDK
value|1
end_define

begin_comment
comment|/*  *	Define the CDK header structure. This is the info that the slave  *	environment sets up after it has been downloaded and started. It  *	essentially provides a memory map for the shared memory interface.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkhdr
block|{
name|unsigned
name|short
name|command
decl_stmt|;
name|unsigned
name|short
name|status
decl_stmt|;
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|short
name|mode
decl_stmt|;
name|unsigned
name|long
name|cmd_buf
index|[
literal|14
index|]
decl_stmt|;
name|unsigned
name|short
name|alive_cnt
decl_stmt|;
name|unsigned
name|short
name|intrpt_mode
decl_stmt|;
name|unsigned
name|char
name|intrpt_id
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|ver_release
decl_stmt|;
name|unsigned
name|char
name|ver_modification
decl_stmt|;
name|unsigned
name|char
name|ver_fix
decl_stmt|;
name|unsigned
name|char
name|deadman_restart
decl_stmt|;
name|unsigned
name|short
name|deadman
decl_stmt|;
name|unsigned
name|short
name|nrdevs
decl_stmt|;
name|unsigned
name|long
name|memp
decl_stmt|;
name|unsigned
name|long
name|hostp
decl_stmt|;
name|unsigned
name|long
name|slavep
decl_stmt|;
name|unsigned
name|char
name|hostreq
decl_stmt|;
name|unsigned
name|char
name|slavereq
decl_stmt|;
name|unsigned
name|char
name|cmd_reserved
index|[
literal|30
index|]
decl_stmt|;
block|}
name|cdkhdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MODE_DDK
value|0
end_define

begin_define
define|#
directive|define
name|MODE_CDK
value|1
end_define

begin_define
define|#
directive|define
name|IMD_INTR
value|0x0
end_define

begin_define
define|#
directive|define
name|IMD_PPINTR
value|0x1
end_define

begin_define
define|#
directive|define
name|IMD_POLL
value|0xff
end_define

begin_comment
comment|/*  *	Define the memory mapping structure. This structure is pointed to by  *	the memp field in the stlcdkhdr struct. As many as these structures  *	as required are layed out in shared memory to define how the rest of  *	shared memory is divided up. There will be one for each port.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkmem
block|{
name|unsigned
name|short
name|dtype
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
block|}
name|cdkmem_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TYP_UNDEFINED
value|0x0
end_define

begin_define
define|#
directive|define
name|TYP_ASYNCTRL
value|0x1
end_define

begin_define
define|#
directive|define
name|TYP_ASYNC
value|0x20
end_define

begin_define
define|#
directive|define
name|TYP_PARALLEL
value|0x40
end_define

begin_define
define|#
directive|define
name|TYP_SYNCX21
value|0x60
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Following is a set of defines and structures used to actually deal  *	with the serial ports on the board. Firstly is the set of commands  *	that can be applied to ports.  */
end_comment

begin_define
define|#
directive|define
name|ASYCMD
value|(((unsigned long) 'a')<< 8)
end_define

begin_define
define|#
directive|define
name|A_NULL
value|(ASYCMD | 0)
end_define

begin_define
define|#
directive|define
name|A_FLUSH
value|(ASYCMD | 1)
end_define

begin_define
define|#
directive|define
name|A_BREAK
value|(ASYCMD | 2)
end_define

begin_define
define|#
directive|define
name|A_GETPORT
value|(ASYCMD | 3)
end_define

begin_define
define|#
directive|define
name|A_SETPORT
value|(ASYCMD | 4)
end_define

begin_define
define|#
directive|define
name|A_SETPORTF
value|(ASYCMD | 5)
end_define

begin_define
define|#
directive|define
name|A_SETPORTFTX
value|(ASYCMD | 6)
end_define

begin_define
define|#
directive|define
name|A_SETPORTFRX
value|(ASYCMD | 7)
end_define

begin_define
define|#
directive|define
name|A_GETSIGNALS
value|(ASYCMD | 8)
end_define

begin_define
define|#
directive|define
name|A_SETSIGNALS
value|(ASYCMD | 9)
end_define

begin_define
define|#
directive|define
name|A_SETSIGNALSF
value|(ASYCMD | 10)
end_define

begin_define
define|#
directive|define
name|A_SETSIGNALSFTX
value|(ASYCMD | 11)
end_define

begin_define
define|#
directive|define
name|A_SETSIGNALSFRX
value|(ASYCMD | 12)
end_define

begin_define
define|#
directive|define
name|A_GETNOTIFY
value|(ASYCMD | 13)
end_define

begin_define
define|#
directive|define
name|A_SETNOTIFY
value|(ASYCMD | 14)
end_define

begin_define
define|#
directive|define
name|A_NOTIFY
value|(ASYCMD | 15)
end_define

begin_define
define|#
directive|define
name|A_PORTCTRL
value|(ASYCMD | 16)
end_define

begin_define
define|#
directive|define
name|A_GETSTATS
value|(ASYCMD | 17)
end_define

begin_define
define|#
directive|define
name|A_RQSTATE
value|(ASYCMD | 18)
end_define

begin_define
define|#
directive|define
name|A_FLOWSTATE
value|(ASYCMD | 19)
end_define

begin_define
define|#
directive|define
name|A_CLEARSTATS
value|(ASYCMD | 20)
end_define

begin_comment
comment|/*  *	Define those arguments used for simple commands.  */
end_comment

begin_define
define|#
directive|define
name|FLUSHRX
value|0x1
end_define

begin_define
define|#
directive|define
name|FLUSHTX
value|0x2
end_define

begin_define
define|#
directive|define
name|BREAKON
value|-1
end_define

begin_define
define|#
directive|define
name|BREAKOFF
value|-2
end_define

begin_comment
comment|/*  *	Define the port setting structure, and all those defines that go along  *	with it. Basically this structure defines the charcateristics of this  *	port: baud rate, chars, parity, input/output char cooking etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asyport
block|{
name|unsigned
name|long
name|baudout
decl_stmt|;
name|unsigned
name|long
name|baudin
decl_stmt|;
name|unsigned
name|long
name|iflag
decl_stmt|;
name|unsigned
name|long
name|oflag
decl_stmt|;
name|unsigned
name|long
name|lflag
decl_stmt|;
name|unsigned
name|long
name|pflag
decl_stmt|;
name|unsigned
name|long
name|flow
decl_stmt|;
name|unsigned
name|long
name|spare1
decl_stmt|;
name|unsigned
name|short
name|vtime
decl_stmt|;
name|unsigned
name|short
name|vmin
decl_stmt|;
name|unsigned
name|short
name|txlo
decl_stmt|;
name|unsigned
name|short
name|txhi
decl_stmt|;
name|unsigned
name|short
name|rxlo
decl_stmt|;
name|unsigned
name|short
name|rxhi
decl_stmt|;
name|unsigned
name|short
name|rxhog
decl_stmt|;
name|unsigned
name|short
name|spare2
decl_stmt|;
name|unsigned
name|char
name|csize
decl_stmt|;
name|unsigned
name|char
name|stopbs
decl_stmt|;
name|unsigned
name|char
name|parity
decl_stmt|;
name|unsigned
name|char
name|stopin
decl_stmt|;
name|unsigned
name|char
name|startin
decl_stmt|;
name|unsigned
name|char
name|stopout
decl_stmt|;
name|unsigned
name|char
name|startout
decl_stmt|;
name|unsigned
name|char
name|parmark
decl_stmt|;
name|unsigned
name|char
name|brkmark
decl_stmt|;
name|unsigned
name|char
name|cc
index|[
literal|11
index|]
decl_stmt|;
block|}
name|asyport_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PT_STOP1
value|0x0
end_define

begin_define
define|#
directive|define
name|PT_STOP15
value|0x1
end_define

begin_define
define|#
directive|define
name|PT_STOP2
value|0x2
end_define

begin_define
define|#
directive|define
name|PT_NOPARITY
value|0x0
end_define

begin_define
define|#
directive|define
name|PT_ODDPARITY
value|0x1
end_define

begin_define
define|#
directive|define
name|PT_EVENPARITY
value|0x2
end_define

begin_define
define|#
directive|define
name|PT_MARKPARITY
value|0x3
end_define

begin_define
define|#
directive|define
name|PT_SPACEPARITY
value|0x4
end_define

begin_define
define|#
directive|define
name|F_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|F_IXON
value|0x1
end_define

begin_define
define|#
directive|define
name|F_IXOFF
value|0x2
end_define

begin_define
define|#
directive|define
name|F_IXANY
value|0x4
end_define

begin_define
define|#
directive|define
name|F_IOXANY
value|0x8
end_define

begin_define
define|#
directive|define
name|F_RTSFLOW
value|0x10
end_define

begin_define
define|#
directive|define
name|F_CTSFLOW
value|0x20
end_define

begin_define
define|#
directive|define
name|F_DTRFLOW
value|0x40
end_define

begin_define
define|#
directive|define
name|F_DCDFLOW
value|0x80
end_define

begin_define
define|#
directive|define
name|F_DSROFLOW
value|0x100
end_define

begin_define
define|#
directive|define
name|F_DSRIFLOW
value|0x200
end_define

begin_define
define|#
directive|define
name|FI_NORX
value|0x1
end_define

begin_define
define|#
directive|define
name|FI_RAW
value|0x2
end_define

begin_define
define|#
directive|define
name|FI_ISTRIP
value|0x4
end_define

begin_define
define|#
directive|define
name|FI_UCLC
value|0x8
end_define

begin_define
define|#
directive|define
name|FI_INLCR
value|0x10
end_define

begin_define
define|#
directive|define
name|FI_ICRNL
value|0x20
end_define

begin_define
define|#
directive|define
name|FI_IGNCR
value|0x40
end_define

begin_define
define|#
directive|define
name|FI_IGNBREAK
value|0x80
end_define

begin_define
define|#
directive|define
name|FI_DSCRDBREAK
value|0x100
end_define

begin_define
define|#
directive|define
name|FI_1MARKBREAK
value|0x200
end_define

begin_define
define|#
directive|define
name|FI_2MARKBREAK
value|0x400
end_define

begin_define
define|#
directive|define
name|FI_XCHNGBREAK
value|0x800
end_define

begin_define
define|#
directive|define
name|FI_IGNRXERRS
value|0x1000
end_define

begin_define
define|#
directive|define
name|FI_DSCDRXERRS
value|0x2000
end_define

begin_define
define|#
directive|define
name|FI_1MARKRXERRS
value|0x4000
end_define

begin_define
define|#
directive|define
name|FI_2MARKRXERRS
value|0x8000
end_define

begin_define
define|#
directive|define
name|FI_XCHNGRXERRS
value|0x10000
end_define

begin_define
define|#
directive|define
name|FI_DSCRDNULL
value|0x20000
end_define

begin_define
define|#
directive|define
name|FO_OLCUC
value|0x1
end_define

begin_define
define|#
directive|define
name|FO_ONLCR
value|0x2
end_define

begin_define
define|#
directive|define
name|FO_OOCRNL
value|0x4
end_define

begin_define
define|#
directive|define
name|FO_ONOCR
value|0x8
end_define

begin_define
define|#
directive|define
name|FO_ONLRET
value|0x10
end_define

begin_define
define|#
directive|define
name|FO_ONL
value|0x20
end_define

begin_define
define|#
directive|define
name|FO_OBS
value|0x40
end_define

begin_define
define|#
directive|define
name|FO_OVT
value|0x80
end_define

begin_define
define|#
directive|define
name|FO_OFF
value|0x100
end_define

begin_define
define|#
directive|define
name|FO_OTAB1
value|0x200
end_define

begin_define
define|#
directive|define
name|FO_OTAB2
value|0x400
end_define

begin_define
define|#
directive|define
name|FO_OTAB3
value|0x800
end_define

begin_define
define|#
directive|define
name|FO_OCR1
value|0x1000
end_define

begin_define
define|#
directive|define
name|FO_OCR2
value|0x2000
end_define

begin_define
define|#
directive|define
name|FO_OCR3
value|0x4000
end_define

begin_define
define|#
directive|define
name|FO_OFILL
value|0x8000
end_define

begin_define
define|#
directive|define
name|FO_ODELL
value|0x10000
end_define

begin_define
define|#
directive|define
name|P_RTSLOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|P_CTSLOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|P_MAPRTS
value|0x4
end_define

begin_define
define|#
directive|define
name|P_MAPCTS
value|0x8
end_define

begin_define
define|#
directive|define
name|P_LOOPBACK
value|0x10
end_define

begin_define
define|#
directive|define
name|P_DTRFOLLOW
value|0x20
end_define

begin_define
define|#
directive|define
name|P_FAKEDCD
value|0x40
end_define

begin_define
define|#
directive|define
name|P_RXIMIN
value|0x10000
end_define

begin_define
define|#
directive|define
name|P_RXITIME
value|0x20000
end_define

begin_define
define|#
directive|define
name|P_RXTHOLD
value|0x40000
end_define

begin_comment
comment|/*  *	Define a structure to communicate serial port signal and data state  *	information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asysigs
block|{
name|unsigned
name|long
name|data
decl_stmt|;
name|unsigned
name|long
name|signal
decl_stmt|;
name|unsigned
name|long
name|sigvalue
decl_stmt|;
block|}
name|asysigs_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DT_TXBUSY
value|0x1
end_define

begin_define
define|#
directive|define
name|DT_TXEMPTY
value|0x2
end_define

begin_define
define|#
directive|define
name|DT_TXLOW
value|0x4
end_define

begin_define
define|#
directive|define
name|DT_TXHIGH
value|0x8
end_define

begin_define
define|#
directive|define
name|DT_TXFULL
value|0x10
end_define

begin_define
define|#
directive|define
name|DT_TXHOG
value|0x20
end_define

begin_define
define|#
directive|define
name|DT_TXFLOWED
value|0x40
end_define

begin_define
define|#
directive|define
name|DT_TXBREAK
value|0x80
end_define

begin_define
define|#
directive|define
name|DT_RXBUSY
value|0x100
end_define

begin_define
define|#
directive|define
name|DT_RXEMPTY
value|0x200
end_define

begin_define
define|#
directive|define
name|DT_RXLOW
value|0x400
end_define

begin_define
define|#
directive|define
name|DT_RXHIGH
value|0x800
end_define

begin_define
define|#
directive|define
name|DT_RXFULL
value|0x1000
end_define

begin_define
define|#
directive|define
name|DT_RXHOG
value|0x2000
end_define

begin_define
define|#
directive|define
name|DT_RXFLOWED
value|0x4000
end_define

begin_define
define|#
directive|define
name|DT_RXBREAK
value|0x8000
end_define

begin_define
define|#
directive|define
name|SG_DTR
value|0x1
end_define

begin_define
define|#
directive|define
name|SG_DCD
value|0x2
end_define

begin_define
define|#
directive|define
name|SG_RTS
value|0x4
end_define

begin_define
define|#
directive|define
name|SG_CTS
value|0x8
end_define

begin_define
define|#
directive|define
name|SG_DSR
value|0x10
end_define

begin_define
define|#
directive|define
name|SG_RI
value|0x20
end_define

begin_comment
comment|/*  *	Define the notification setting structure. This is used to tell the  *	port what events we want to be informed about. Fields here use the  *	same defines as for the asysigs structure above.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asynotify
block|{
name|unsigned
name|long
name|ctrl
decl_stmt|;
name|unsigned
name|long
name|data
decl_stmt|;
name|unsigned
name|long
name|signal
decl_stmt|;
name|unsigned
name|long
name|sigvalue
decl_stmt|;
block|}
name|asynotify_t
typedef|;
end_typedef

begin_comment
comment|/*  *	Define the port control structure. It is used to do fine grain  *	control operations on the port.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|rxctrl
decl_stmt|;
name|unsigned
name|long
name|txctrl
decl_stmt|;
name|char
name|rximdch
decl_stmt|;
name|char
name|tximdch
decl_stmt|;
name|char
name|spare1
decl_stmt|;
name|char
name|spare2
decl_stmt|;
block|}
name|asyctrl_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CT_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|CT_DISABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|CT_STOP
value|0x4
end_define

begin_define
define|#
directive|define
name|CT_START
value|0x8
end_define

begin_define
define|#
directive|define
name|CT_STARTFLOW
value|0x10
end_define

begin_define
define|#
directive|define
name|CT_STOPFLOW
value|0x20
end_define

begin_define
define|#
directive|define
name|CT_SENDCHR
value|0x40
end_define

begin_comment
comment|/*  *	Define the stats structure kept for each port. This is a useful set  *	of data collected for each port on the slave. The A_GETSTATS command  *	is used to retrive this data from the slave.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asystats
block|{
name|unsigned
name|long
name|opens
decl_stmt|;
name|unsigned
name|long
name|txchars
decl_stmt|;
name|unsigned
name|long
name|rxchars
decl_stmt|;
name|unsigned
name|long
name|txringq
decl_stmt|;
name|unsigned
name|long
name|rxringq
decl_stmt|;
name|unsigned
name|long
name|txmsgs
decl_stmt|;
name|unsigned
name|long
name|rxmsgs
decl_stmt|;
name|unsigned
name|long
name|txflushes
decl_stmt|;
name|unsigned
name|long
name|rxflushes
decl_stmt|;
name|unsigned
name|long
name|overruns
decl_stmt|;
name|unsigned
name|long
name|framing
decl_stmt|;
name|unsigned
name|long
name|parity
decl_stmt|;
name|unsigned
name|long
name|ringover
decl_stmt|;
name|unsigned
name|long
name|lost
decl_stmt|;
name|unsigned
name|long
name|rxstart
decl_stmt|;
name|unsigned
name|long
name|rxstop
decl_stmt|;
name|unsigned
name|long
name|txstart
decl_stmt|;
name|unsigned
name|long
name|txstop
decl_stmt|;
name|unsigned
name|long
name|dcdcnt
decl_stmt|;
name|unsigned
name|long
name|dtrcnt
decl_stmt|;
name|unsigned
name|long
name|ctscnt
decl_stmt|;
name|unsigned
name|long
name|rtscnt
decl_stmt|;
name|unsigned
name|long
name|dsrcnt
decl_stmt|;
name|unsigned
name|long
name|ricnt
decl_stmt|;
name|unsigned
name|long
name|txbreaks
decl_stmt|;
name|unsigned
name|long
name|rxbreaks
decl_stmt|;
name|unsigned
name|long
name|signals
decl_stmt|;
name|unsigned
name|long
name|state
decl_stmt|;
name|unsigned
name|long
name|hwid
decl_stmt|;
block|}
name|asystats_t
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	All command and control communication with a device on the slave is  *	via a control block in shared memory. Each device has its own control  *	block, defined by the following structure. The control block allows  *	the host to open, close and control the device on the slave.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkctrl
block|{
name|unsigned
name|char
name|open
decl_stmt|;
name|unsigned
name|char
name|close
decl_stmt|;
name|unsigned
name|long
name|openarg
decl_stmt|;
name|unsigned
name|long
name|closearg
decl_stmt|;
name|unsigned
name|long
name|cmd
decl_stmt|;
name|unsigned
name|long
name|status
decl_stmt|;
name|unsigned
name|long
name|args
index|[
literal|32
index|]
decl_stmt|;
block|}
name|cdkctrl_t
typedef|;
end_typedef

begin_comment
comment|/*  *	Each device on the slave passes data to and from the host via a ring  *	queue in shared memory. Define a ring queue structure to hold the  *	vital information about each ring queue. Two ring queues will be  *	allocated for each port, one for reveice data and one for transmit  *	data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkasyrq
block|{
name|unsigned
name|long
name|offset
decl_stmt|;
name|unsigned
name|short
name|size
decl_stmt|;
name|unsigned
name|short
name|head
decl_stmt|;
name|unsigned
name|short
name|tail
decl_stmt|;
block|}
name|cdkasyrq_t
typedef|;
end_typedef

begin_comment
comment|/*  *	Each asynchronous port is defined in shared memory by the following  *	structure. It contains a control block to command a device, and also  *	the neccessary data channel information as well.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cdkasy
block|{
name|cdkctrl_t
name|ctrl
decl_stmt|;
name|unsigned
name|short
name|notify
decl_stmt|;
name|asynotify_t
name|changed
decl_stmt|;
name|unsigned
name|short
name|receive
decl_stmt|;
name|cdkasyrq_t
name|rxq
decl_stmt|;
name|unsigned
name|short
name|transmit
decl_stmt|;
name|cdkasyrq_t
name|txq
decl_stmt|;
block|}
name|cdkasy_t
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
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the set of ioctls used by the driver to do special things  *	to the board. These include interrupting it, and initializeing  *	the driver after board startup and shutdown.  */
end_comment

begin_define
define|#
directive|define
name|STL_BINTR
value|_IO('s', 20)
end_define

begin_define
define|#
directive|define
name|STL_BSTART
value|_IO('s', 21)
end_define

begin_define
define|#
directive|define
name|STL_BSTOP
value|_IO('s', 22)
end_define

begin_define
define|#
directive|define
name|STL_BRESET
value|_IO('s', 23)
end_define

begin_comment
comment|/*  *	Define a set of ioctl extensions, used to get at special stuff.  */
end_comment

begin_define
define|#
directive|define
name|STL_GETPFLAG
value|_IOR('s', 80, unsigned long)
end_define

begin_define
define|#
directive|define
name|STL_SETPFLAG
value|_IOW('s', 81, unsigned long)
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

