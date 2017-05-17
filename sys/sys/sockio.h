begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sockio.h	8.1 (Berkeley) 3/28/94  * $FreeBSD$  */
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

begin_comment
comment|/*	SIOCADDRT	 _IOW('r', 10, struct ortentry)	4.3BSD */
end_comment

begin_comment
comment|/*	SIOCDELRT	 _IOW('r', 11, struct ortentry)	4.3BSD */
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

begin_comment
comment|/*	OSIOCGIFADDR	_IOWR('i', 13, struct ifreq)	4.3BSD */
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

begin_comment
comment|/*	OSIOCGIFDSTADDR	_IOWR('i', 15, struct ifreq)	4.3BSD */
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

begin_comment
comment|/*	OSIOCGIFBRDADDR	_IOWR('i', 18, struct ifreq)	4.3BSD */
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

begin_comment
comment|/*	OSIOCGIFCONF	_IOWR('i', 20, struct ifconf)	4.3BSD */
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

begin_comment
comment|/*	OSIOCGIFNETMASK	_IOWR('i', 21, struct ifreq)	4.3BSD */
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
name|OSIOCAIFADDR
value|_IOW('i', 26, struct oifaliasreq)
end_define

begin_comment
comment|/* FreeBSD 9.x */
end_comment

begin_comment
comment|/*	SIOCALIFADDR	 _IOW('i', 27, struct if_laddrreq) KAME */
end_comment

begin_comment
comment|/*	SIOCGLIFADDR	_IOWR('i', 28, struct if_laddrreq) KAME */
end_comment

begin_comment
comment|/*	SIOCDLIFADDR	 _IOW('i', 29, struct if_laddrreq) KAME */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFCAP
value|_IOW('i', 30, struct ifreq)
end_define

begin_comment
comment|/* set IF features */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCAP
value|_IOWR('i', 31, struct ifreq)
end_define

begin_comment
comment|/* get IF features */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFINDEX
value|_IOWR('i', 32, struct ifreq)
end_define

begin_comment
comment|/* get IF index */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFMAC
value|_IOWR('i', 38, struct ifreq)
end_define

begin_comment
comment|/* get IF MAC label */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFMAC
value|_IOW('i', 39, struct ifreq)
end_define

begin_comment
comment|/* set IF MAC label */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFNAME
value|_IOW('i', 40, struct ifreq)
end_define

begin_comment
comment|/* set IF name */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFDESCR
value|_IOW('i', 41, struct ifreq)
end_define

begin_comment
comment|/* set ifnet descr */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFDESCR
value|_IOWR('i', 42, struct ifreq)
end_define

begin_comment
comment|/* get ifnet descr */
end_comment

begin_define
define|#
directive|define
name|SIOCAIFADDR
value|_IOW('i', 43, struct ifaliasreq)
end_define

begin_comment
comment|/* add/chg IF alias */
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
comment|/* set linklevel addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGI2C
value|_IOWR('i', 61, struct ifreq)
end_define

begin_comment
comment|/* get I2C data  */
end_comment

begin_define
define|#
directive|define
name|SIOCGHWADDR
value|_IOWR('i', 62, struct ifreq)
end_define

begin_comment
comment|/* get hardware lladdr */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFPHYADDR
value|_IOW('i', 70, struct ifaliasreq)
end_define

begin_comment
comment|/* set gif address */
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

begin_comment
comment|/*	SIOCSLIFPHYADDR	 _IOW('i', 74, struct if_laddrreq) KAME */
end_comment

begin_comment
comment|/*	SIOCGLIFPHYADDR	_IOWR('i', 75, struct if_laddrreq) KAME */
end_comment

begin_define
define|#
directive|define
name|SIOCGPRIVATE_0
value|_IOWR('i', 80, struct ifreq)
end_define

begin_comment
comment|/* device private 0 */
end_comment

begin_define
define|#
directive|define
name|SIOCGPRIVATE_1
value|_IOWR('i', 81, struct ifreq)
end_define

begin_comment
comment|/* device private 1 */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFVNET
value|_IOWR('i', 90, struct ifreq)
end_define

begin_comment
comment|/* move IF jail/vnet */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFRVNET
value|_IOWR('i', 91, struct ifreq)
end_define

begin_comment
comment|/* reclaim vnet IF */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFFIB
value|_IOWR('i', 92, struct ifreq)
end_define

begin_comment
comment|/* get IF fib */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFFIB
value|_IOW('i', 93, struct ifreq)
end_define

begin_comment
comment|/* set IF fib */
end_comment

begin_define
define|#
directive|define
name|SIOCGTUNFIB
value|_IOWR('i', 94, struct ifreq)
end_define

begin_comment
comment|/* get tunnel fib */
end_comment

begin_define
define|#
directive|define
name|SIOCSTUNFIB
value|_IOW('i', 95, struct ifreq)
end_define

begin_comment
comment|/* set tunnel fib */
end_comment

begin_define
define|#
directive|define
name|SIOCSDRVSPEC
value|_IOW('i', 123, struct ifdrv)
end_define

begin_comment
comment|/* set driver-specific 								  parameters */
end_comment

begin_define
define|#
directive|define
name|SIOCGDRVSPEC
value|_IOWR('i', 123, struct ifdrv)
end_define

begin_comment
comment|/* get driver-specific 								  parameters */
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
name|SIOCIFCREATE2
value|_IOWR('i', 124, struct ifreq)
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

begin_define
define|#
directive|define
name|SIOCAIFGROUP
value|_IOW('i', 135, struct ifgroupreq)
end_define

begin_comment
comment|/* add an ifgroup */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFGROUP
value|_IOWR('i', 136, struct ifgroupreq)
end_define

begin_comment
comment|/* get ifgroups */
end_comment

begin_define
define|#
directive|define
name|SIOCDIFGROUP
value|_IOW('i', 137, struct ifgroupreq)
end_define

begin_comment
comment|/* delete ifgroup */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFGMEMB
value|_IOWR('i', 138, struct ifgroupreq)
end_define

begin_comment
comment|/* get members */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFXMEDIA
value|_IOWR('i', 139, struct ifmediareq)
end_define

begin_comment
comment|/* get net xmedia */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SOCKIO_H_ */
end_comment

end_unit

