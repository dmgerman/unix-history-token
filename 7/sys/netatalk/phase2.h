begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  * This product includes software developed by the University of  * California, Berkeley and its contributors.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Wesley Craig  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-764-2278  *	netatalk@umich.edu  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<net/if_llc.h>
end_include

begin_define
define|#
directive|define
name|llc_org_code
value|llc_un.type_snap.org_code
end_define

begin_define
define|#
directive|define
name|llc_ether_type
value|llc_un.type_snap.ether_type
end_define

begin_define
define|#
directive|define
name|SIOCPHASE1
value|_IOW('i', 100, struct ifreq)
end_define

begin_comment
comment|/* AppleTalk phase 1 */
end_comment

begin_define
define|#
directive|define
name|SIOCPHASE2
value|_IOW('i', 101, struct ifreq)
end_define

begin_comment
comment|/* AppleTalk phase 2 */
end_comment

end_unit

