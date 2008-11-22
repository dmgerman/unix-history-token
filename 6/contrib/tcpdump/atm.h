begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 Guy Harris.  *                All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * The name of Guy Harris may not be used to endorse or promote products  * derived from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/atm.h,v 1.1.4.1 2005/06/20 07:45:05 hannes Exp $  */
end_comment

begin_comment
comment|/*  * Traffic types for ATM.  */
end_comment

begin_define
define|#
directive|define
name|ATM_UNKNOWN
value|0
end_define

begin_comment
comment|/* Unknown */
end_comment

begin_define
define|#
directive|define
name|ATM_LANE
value|1
end_define

begin_comment
comment|/* LANE */
end_comment

begin_define
define|#
directive|define
name|ATM_LLC
value|2
end_define

begin_comment
comment|/* LLC encapsulation */
end_comment

begin_comment
comment|/*  * some OAM cell captures (most notably Juniper's)  * do not deliver a heading HEC byte  */
end_comment

begin_define
define|#
directive|define
name|ATM_OAM_NOHEC
value|0
end_define

begin_define
define|#
directive|define
name|ATM_OAM_HEC
value|1
end_define

end_unit

