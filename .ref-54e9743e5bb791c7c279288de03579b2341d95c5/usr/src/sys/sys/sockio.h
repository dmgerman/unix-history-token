begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)sockio.h	8.1 (Berkeley) %G%  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SOCKIO_H_ */
end_comment

end_unit

