begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sockio.h	8.1 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOCKIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Socket ioctl's. */
end_comment

begin_define
define|#
directive|define
name|SIOCSHIWAT
value|_IOW('s',  0, int)
end_define

begin_comment
comment|/* set high watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCGHIWAT
value|_IOR('s',  1, int)
end_define

begin_comment
comment|/* get high watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCSLOWAT
value|_IOW('s',  2, int)
end_define

begin_comment
comment|/* set low watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCGLOWAT
value|_IOR('s',  3, int)
end_define

begin_comment
comment|/* get low watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCATMARK
value|_IOR('s',  7, int)
end_define

begin_comment
comment|/* at oob mark? */
end_comment

begin_define
define|#
directive|define
name|SIOCSPGRP
value|_IOW('s',  8, int)
end_define

begin_comment
comment|/* set process group */
end_comment

begin_define
define|#
directive|define
name|SIOCGPGRP
value|_IOR('s',  9, int)
end_define

begin_comment
comment|/* get process group */
end_comment

begin_define
define|#
directive|define
name|SIOCADDRT
value|_IOW('r', 10, struct ortentry)
end_define

begin_comment
comment|/* add route */
end_comment

begin_define
define|#
directive|define
name|SIOCDELRT
value|_IOW('r', 11, struct ortentry)
end_define

begin_comment
comment|/* delete route */
end_comment

begin_define
define|#
directive|define
name|SIOCGETVIFCNT
value|_IOWR('r', 15, struct sioc_vif_req)
end_define

begin_comment
comment|/* get vif pkt cnt */
end_comment

begin_define
define|#
directive|define
name|SIOCGETSGCNT
value|_IOWR('r', 16, struct sioc_sg_req)
end_define

begin_comment
comment|/* get s,g pkt cnt */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFADDR
value|_IOW('i', 12, struct ifreq)
end_define

begin_comment
comment|/* set ifnet address */
end_comment

begin_define
define|#
directive|define
name|OSIOCGIFADDR
value|_IOWR('i', 13, struct ifreq)
end_define

begin_comment
comment|/* get ifnet address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFADDR
value|_IOWR('i', 33, struct ifreq)
end_define

begin_comment
comment|/* get ifnet address */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFDSTADDR
value|_IOW('i', 14, struct ifreq)
end_define

begin_comment
comment|/* set p-p address */
end_comment

begin_define
define|#
directive|define
name|OSIOCGIFDSTADDR
value|_IOWR('i', 15, struct ifreq)
end_define

begin_comment
comment|/* get p-p address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFDSTADDR
value|_IOWR('i', 34, struct ifreq)
end_define

begin_comment
comment|/* get p-p address */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFFLAGS
value|_IOW('i', 16, struct ifreq)
end_define

begin_comment
comment|/* set ifnet flags */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFFLAGS
value|_IOWR('i', 17, struct ifreq)
end_define

begin_comment
comment|/* get ifnet flags */
end_comment

begin_define
define|#
directive|define
name|OSIOCGIFBRDADDR
value|_IOWR('i', 18, struct ifreq)
end_define

begin_comment
comment|/* get broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFBRDADDR
value|_IOWR('i', 35, struct ifreq)
end_define

begin_comment
comment|/* get broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFBRDADDR
value|_IOW('i', 19, struct ifreq)
end_define

begin_comment
comment|/* set broadcast addr */
end_comment

begin_define
define|#
directive|define
name|OSIOCGIFCONF
value|_IOWR('i', 20, struct ifconf)
end_define

begin_comment
comment|/* get ifnet list */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCONF
value|_IOWR('i', 36, struct ifconf)
end_define

begin_comment
comment|/* get ifnet list */
end_comment

begin_define
define|#
directive|define
name|OSIOCGIFNETMASK
value|_IOWR('i', 21, struct ifreq)
end_define

begin_comment
comment|/* get net addr mask */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFNETMASK
value|_IOWR('i', 37, struct ifreq)
end_define

begin_comment
comment|/* get net addr mask */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFNETMASK
value|_IOW('i', 22, struct ifreq)
end_define

begin_comment
comment|/* set net addr mask */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFMETRIC
value|_IOWR('i', 23, struct ifreq)
end_define

begin_comment
comment|/* get IF metric */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFMETRIC
value|_IOW('i', 24, struct ifreq)
end_define

begin_comment
comment|/* set IF metric */
end_comment

begin_define
define|#
directive|define
name|SIOCDIFADDR
value|_IOW('i', 25, struct ifreq)
end_define

begin_comment
comment|/* delete IF addr */
end_comment

begin_define
define|#
directive|define
name|SIOCAIFADDR
value|_IOW('i', 26, struct ifaliasreq)
end_define

begin_comment
comment|/* add/chg IF alias */
end_comment

begin_define
define|#
directive|define
name|SIOCALIFADDR
value|_IOW('i', 27, struct if_laddrreq)
end_define

begin_comment
comment|/* add IF addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGLIFADDR
value|_IOWR('i', 28, struct if_laddrreq)
end_define

begin_comment
comment|/* get IF addr */
end_comment

begin_define
define|#
directive|define
name|SIOCDLIFADDR
value|_IOW('i', 29, struct if_laddrreq)
end_define

begin_comment
comment|/* delete IF addr */
end_comment

begin_define
define|#
directive|define
name|SIOCADDMULTI
value|_IOW('i', 49, struct ifreq)
end_define

begin_comment
comment|/* add m'cast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCDELMULTI
value|_IOW('i', 50, struct ifreq)
end_define

begin_comment
comment|/* del m'cast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFMTU
value|_IOWR('i', 51, struct ifreq)
end_define

begin_comment
comment|/* get IF mtu */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFMTU
value|_IOW('i', 52, struct ifreq)
end_define

begin_comment
comment|/* set IF mtu */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFPHYS
value|_IOWR('i', 53, struct ifreq)
end_define

begin_comment
comment|/* get IF wire */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFPHYS
value|_IOW('i', 54, struct ifreq)
end_define

begin_comment
comment|/* set IF wire */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFMEDIA
value|_IOWR('i', 55, struct ifreq)
end_define

begin_comment
comment|/* set net media */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFMEDIA
value|_IOWR('i', 56, struct ifmediareq)
end_define

begin_comment
comment|/* get net media */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFPHYADDR
value|_IOW('i', 70, struct ifaliasreq)
end_define

begin_comment
comment|/* set gif addres */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFPSRCADDR
value|_IOWR('i', 71, struct ifreq)
end_define

begin_comment
comment|/* get gif psrc addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFPDSTADDR
value|_IOWR('i', 72, struct ifreq)
end_define

begin_comment
comment|/* get gif pdst addr */
end_comment

begin_define
define|#
directive|define
name|SIOCDIFPHYADDR
value|_IOW('i', 73, struct ifreq)
end_define

begin_comment
comment|/* delete gif addrs */
end_comment

begin_define
define|#
directive|define
name|SIOCSLIFPHYADDR
value|_IOW('i', 74, struct if_laddrreq)
end_define

begin_comment
comment|/* set gif addrs */
end_comment

begin_define
define|#
directive|define
name|SIOCGLIFPHYADDR
value|_IOWR('i', 75, struct if_laddrreq)
end_define

begin_comment
comment|/* get gif addrs */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFGENERIC
value|_IOW('i', 57, struct ifreq)
end_define

begin_comment
comment|/* generic IF set op */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFGENERIC
value|_IOWR('i', 58, struct ifreq)
end_define

begin_comment
comment|/* generic IF get op */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFSTATUS
value|_IOWR('i', 59, struct ifstat)
end_define

begin_comment
comment|/* get IF status */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFLLADDR
value|_IOW('i', 60, struct ifreq)
end_define

begin_comment
comment|/* set link level addr */
end_comment

begin_define
define|#
directive|define
name|SIOCIFCREATE
value|_IOWR('i', 122, struct ifreq)
end_define

begin_comment
comment|/* create clone if */
end_comment

begin_define
define|#
directive|define
name|SIOCIFDESTROY
value|_IOW('i', 121, struct ifreq)
end_define

begin_comment
comment|/* destroy clone if */
end_comment

begin_define
define|#
directive|define
name|SIOCIFGCLONERS
value|_IOWR('i', 120, struct if_clonereq)
end_define

begin_comment
comment|/* get cloners */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SOCKIO_H_ */
end_comment

end_unit

