begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * from: Utah $Hdr: hpux.h 1.15 89/09/25$  *  *	@(#)hpux_termio.h	7.2 (Berkeley) 6/27/90  */
end_comment

begin_comment
comment|/* HP-UX termio stuff */
end_comment

begin_define
define|#
directive|define
name|HPUXNCC
value|8
end_define

begin_comment
comment|/* control characters */
end_comment

begin_define
define|#
directive|define
name|HPUXVINTR
value|0
end_define

begin_define
define|#
directive|define
name|HPUXVQUIT
value|1
end_define

begin_define
define|#
directive|define
name|HPUXVERASE
value|2
end_define

begin_define
define|#
directive|define
name|HPUXVKILL
value|3
end_define

begin_define
define|#
directive|define
name|HPUXVEOF
value|4
end_define

begin_define
define|#
directive|define
name|HPUXVEOL
value|5
end_define

begin_define
define|#
directive|define
name|HPUXVMIN
value|4
end_define

begin_define
define|#
directive|define
name|HPUXVTIME
value|5
end_define

begin_comment
comment|/* input modes */
end_comment

begin_define
define|#
directive|define
name|TIO_IGNBRK
value|0x00000001
end_define

begin_comment
comment|/* 0000001 */
end_comment

begin_define
define|#
directive|define
name|TIO_BRKINT
value|0x00000002
end_define

begin_comment
comment|/* 0000002 */
end_comment

begin_define
define|#
directive|define
name|TIO_IGNPAR
value|0x00000004
end_define

begin_comment
comment|/* 0000004 */
end_comment

begin_define
define|#
directive|define
name|TIO_PARMRK
value|0x00000008
end_define

begin_comment
comment|/* 0000010 */
end_comment

begin_define
define|#
directive|define
name|TIO_INPCK
value|0x00000010
end_define

begin_comment
comment|/* 0000020 */
end_comment

begin_define
define|#
directive|define
name|TIO_ISTRIP
value|0x00000020
end_define

begin_comment
comment|/* 0000040 */
end_comment

begin_define
define|#
directive|define
name|TIO_INLCR
value|0x00000040
end_define

begin_comment
comment|/* 0000100 */
end_comment

begin_define
define|#
directive|define
name|TIO_IGNCR
value|0x00000080
end_define

begin_comment
comment|/* 0000200 */
end_comment

begin_define
define|#
directive|define
name|TIO_ICRNL
value|0x00000100
end_define

begin_comment
comment|/* 0000400 */
end_comment

begin_define
define|#
directive|define
name|TIO_IUCLC
value|0x00000200
end_define

begin_comment
comment|/* 0001000 */
end_comment

begin_define
define|#
directive|define
name|TIO_IXON
value|0x00000400
end_define

begin_comment
comment|/* 0002000 */
end_comment

begin_define
define|#
directive|define
name|TIO_IXANY
value|0x00000800
end_define

begin_comment
comment|/* 0004000 */
end_comment

begin_define
define|#
directive|define
name|TIO_IXOFF
value|0x00001000
end_define

begin_comment
comment|/* 0010000 */
end_comment

begin_define
define|#
directive|define
name|TIO_IENQAK
value|0x00002000
end_define

begin_comment
comment|/* 0020000 */
end_comment

begin_comment
comment|/* output modes */
end_comment

begin_define
define|#
directive|define
name|TIO_OPOST
value|0x00000001
end_define

begin_comment
comment|/* 0000001 */
end_comment

begin_define
define|#
directive|define
name|TIO_OLCUC
value|0x00000002
end_define

begin_comment
comment|/* 0000002 */
end_comment

begin_define
define|#
directive|define
name|TIO_ONLCR
value|0x00000004
end_define

begin_comment
comment|/* 0000004 */
end_comment

begin_define
define|#
directive|define
name|TIO_OCRNL
value|0x00000008
end_define

begin_comment
comment|/* 0000010 */
end_comment

begin_define
define|#
directive|define
name|TIO_ONOCR
value|0x00000010
end_define

begin_comment
comment|/* 0000020 */
end_comment

begin_define
define|#
directive|define
name|TIO_ONLRET
value|0x00000020
end_define

begin_comment
comment|/* 0000040 */
end_comment

begin_define
define|#
directive|define
name|TIO_OFILL
value|0x00000040
end_define

begin_comment
comment|/* 0000100 */
end_comment

begin_define
define|#
directive|define
name|TIO_OFDEL
value|0x00000080
end_define

begin_comment
comment|/* 0000200 */
end_comment

begin_define
define|#
directive|define
name|TIO_NLDLY
value|0x00000100
end_define

begin_comment
comment|/* 0000400 */
end_comment

begin_define
define|#
directive|define
name|TIO_NL0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_NL1
value|0x00000100
end_define

begin_comment
comment|/* 0000400 */
end_comment

begin_define
define|#
directive|define
name|TIO_CRDLY
value|0x00000600
end_define

begin_comment
comment|/* 0003000 */
end_comment

begin_define
define|#
directive|define
name|TIO_CR0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_CR1
value|0x00000200
end_define

begin_comment
comment|/* 0001000 */
end_comment

begin_define
define|#
directive|define
name|TIO_CR2
value|0x00000400
end_define

begin_comment
comment|/* 0002000 */
end_comment

begin_define
define|#
directive|define
name|TIO_CR3
value|0x00000600
end_define

begin_comment
comment|/* 0003000 */
end_comment

begin_define
define|#
directive|define
name|TIO_TABDLY
value|0x00001800
end_define

begin_comment
comment|/* 0014000 */
end_comment

begin_define
define|#
directive|define
name|TIO_TAB0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_TAB1
value|0x00000800
end_define

begin_comment
comment|/* 0004000 */
end_comment

begin_define
define|#
directive|define
name|TIO_TAB2
value|0x00001000
end_define

begin_comment
comment|/* 0010000 */
end_comment

begin_define
define|#
directive|define
name|TIO_TAB3
value|0x00001800
end_define

begin_comment
comment|/* 0014000 */
end_comment

begin_define
define|#
directive|define
name|TIO_BSDLY
value|0x00002000
end_define

begin_comment
comment|/* 0020000 */
end_comment

begin_define
define|#
directive|define
name|TIO_BS0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_BS1
value|0x00002000
end_define

begin_comment
comment|/* 0020000 */
end_comment

begin_define
define|#
directive|define
name|TIO_VTDLY
value|0x00004000
end_define

begin_comment
comment|/* 0040000 */
end_comment

begin_define
define|#
directive|define
name|TIO_VT0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_VT1
value|0x00004000
end_define

begin_comment
comment|/* 0040000 */
end_comment

begin_define
define|#
directive|define
name|TIO_FFDLY
value|0x00008000
end_define

begin_comment
comment|/* 0100000 */
end_comment

begin_define
define|#
directive|define
name|TIO_FF0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_FF1
value|0x00008000
end_define

begin_comment
comment|/* 0100000 */
end_comment

begin_comment
comment|/* control modes */
end_comment

begin_define
define|#
directive|define
name|TIO_CBAUD
value|0x0000001f
end_define

begin_comment
comment|/* 0000037 */
end_comment

begin_define
define|#
directive|define
name|TIO_B0
value|0
end_define

begin_define
define|#
directive|define
name|TIO_B50
value|0x00000001
end_define

begin_comment
comment|/* 0000001 */
end_comment

begin_define
define|#
directive|define
name|TIO_B75
value|0x00000002
end_define

begin_comment
comment|/* 0000002 */
end_comment

begin_define
define|#
directive|define
name|TIO_B110
value|0x00000003
end_define

begin_comment
comment|/* 0000003 */
end_comment

begin_define
define|#
directive|define
name|TIO_B134
value|0x00000004
end_define

begin_comment
comment|/* 0000004 */
end_comment

begin_define
define|#
directive|define
name|TIO_B150
value|0x00000005
end_define

begin_comment
comment|/* 0000005 */
end_comment

begin_define
define|#
directive|define
name|TIO_B200
value|0x00000006
end_define

begin_comment
comment|/* 0000006 */
end_comment

begin_define
define|#
directive|define
name|TIO_B300
value|0x00000007
end_define

begin_comment
comment|/* 0000007 */
end_comment

begin_define
define|#
directive|define
name|TIO_B600
value|0x00000008
end_define

begin_comment
comment|/* 0000010 */
end_comment

begin_define
define|#
directive|define
name|TIO_B900
value|0x00000009
end_define

begin_comment
comment|/* 0000011 */
end_comment

begin_define
define|#
directive|define
name|TIO_B1200
value|0x0000000a
end_define

begin_comment
comment|/* 0000012 */
end_comment

begin_define
define|#
directive|define
name|TIO_B1800
value|0x0000000b
end_define

begin_comment
comment|/* 0000013 */
end_comment

begin_define
define|#
directive|define
name|TIO_B2400
value|0x0000000c
end_define

begin_comment
comment|/* 0000014 */
end_comment

begin_define
define|#
directive|define
name|TIO_B3600
value|0x0000000d
end_define

begin_comment
comment|/* 0000015 */
end_comment

begin_define
define|#
directive|define
name|TIO_B4800
value|0x0000000e
end_define

begin_comment
comment|/* 0000016 */
end_comment

begin_define
define|#
directive|define
name|TIO_B7200
value|0x0000000f
end_define

begin_comment
comment|/* 0000017 */
end_comment

begin_define
define|#
directive|define
name|TIO_B9600
value|0x00000010
end_define

begin_comment
comment|/* 0000020 */
end_comment

begin_define
define|#
directive|define
name|TIO_B19200
value|0x00000011
end_define

begin_comment
comment|/* 0000021 */
end_comment

begin_define
define|#
directive|define
name|TIO_B38400
value|0x00000012
end_define

begin_comment
comment|/* 0000022 */
end_comment

begin_define
define|#
directive|define
name|TIO_EXTA
value|0x0000001e
end_define

begin_comment
comment|/* 0000036 */
end_comment

begin_define
define|#
directive|define
name|TIO_EXTB
value|0x0000001f
end_define

begin_comment
comment|/* 0000037 */
end_comment

begin_define
define|#
directive|define
name|TIO_CSIZE
value|0x00000060
end_define

begin_comment
comment|/* 0000140 */
end_comment

begin_define
define|#
directive|define
name|TIO_CS5
value|0
end_define

begin_define
define|#
directive|define
name|TIO_CS6
value|0x00000020
end_define

begin_comment
comment|/* 0000040 */
end_comment

begin_define
define|#
directive|define
name|TIO_CS7
value|0x00000040
end_define

begin_comment
comment|/* 0000100 */
end_comment

begin_define
define|#
directive|define
name|TIO_CS8
value|0x00000060
end_define

begin_comment
comment|/* 0000140 */
end_comment

begin_define
define|#
directive|define
name|TIO_CSTOPB
value|0x00000080
end_define

begin_comment
comment|/* 0000200 */
end_comment

begin_define
define|#
directive|define
name|TIO_CREAD
value|0x00000100
end_define

begin_comment
comment|/* 0000400 */
end_comment

begin_define
define|#
directive|define
name|TIO_PARENB
value|0x00000200
end_define

begin_comment
comment|/* 0001000 */
end_comment

begin_define
define|#
directive|define
name|TIO_PARODD
value|0x00000400
end_define

begin_comment
comment|/* 0002000 */
end_comment

begin_define
define|#
directive|define
name|TIO_HUPCL
value|0x00000800
end_define

begin_comment
comment|/* 0004000 */
end_comment

begin_define
define|#
directive|define
name|TIO_CLOCAL
value|0x00001000
end_define

begin_comment
comment|/* 0010000 */
end_comment

begin_define
define|#
directive|define
name|TIO_CRTS
value|0x00002000
end_define

begin_comment
comment|/* 0020000 */
end_comment

begin_comment
comment|/* Obsolete */
end_comment

begin_comment
comment|/* line discipline 0 modes */
end_comment

begin_define
define|#
directive|define
name|TIO_ISIG
value|0x00000001
end_define

begin_comment
comment|/* 0000001 */
end_comment

begin_define
define|#
directive|define
name|TIO_ICANON
value|0x00000002
end_define

begin_comment
comment|/* 0000002 */
end_comment

begin_define
define|#
directive|define
name|TIO_XCASE
value|0x00000004
end_define

begin_comment
comment|/* 0000004 */
end_comment

begin_define
define|#
directive|define
name|TIO_ECHO
value|0x00000008
end_define

begin_comment
comment|/* 0000010 */
end_comment

begin_define
define|#
directive|define
name|TIO_ECHOE
value|0x00000010
end_define

begin_comment
comment|/* 0000020 */
end_comment

begin_define
define|#
directive|define
name|TIO_ECHOK
value|0x00000020
end_define

begin_comment
comment|/* 0000040 */
end_comment

begin_define
define|#
directive|define
name|TIO_ECHONL
value|0x00000040
end_define

begin_comment
comment|/* 0000100 */
end_comment

begin_define
define|#
directive|define
name|TIO_NOFLSH
value|0x00000080
end_define

begin_comment
comment|/* 0000200 */
end_comment

begin_struct
struct|struct
name|hpuxtermio
block|{
name|u_short
name|c_iflag
decl_stmt|;
comment|/* input modes */
name|u_short
name|c_oflag
decl_stmt|;
comment|/* output modes */
name|u_short
name|c_cflag
decl_stmt|;
comment|/* control modes */
name|u_short
name|c_lflag
decl_stmt|;
comment|/* line discipline modes */
name|char
name|c_line
decl_stmt|;
comment|/* line discipline */
name|u_char
name|c_cc
index|[
name|HPUXNCC
index|]
decl_stmt|;
comment|/* control chars */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HPUXTCGETA
value|_IOR('T', 1, struct hpuxtermio)
end_define

begin_define
define|#
directive|define
name|HPUXTCSETA
value|_IOW('T', 2, struct hpuxtermio)
end_define

begin_define
define|#
directive|define
name|HPUXTCSETAW
value|_IOW('T', 3, struct hpuxtermio)
end_define

begin_define
define|#
directive|define
name|HPUXTCSETAF
value|_IOW('T', 4, struct hpuxtermio)
end_define

end_unit

