begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990,1991 Regents of The University of Michigan.  * All Rights Reserved.  */
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

