begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Stephen Deering.  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Stephen Deering of Stanford University.  *  * %sccs.include.redist.c%  *  *	@(#)igmp.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Internet Group Management Protocol (IGMP) definitions. */
end_comment

begin_comment
comment|/*  * IGMP packet format.  */
end_comment

begin_struct
struct|struct
name|igmp
block|{
name|u_char
name|igmp_type
decl_stmt|;
comment|/* version& type of IGMP message  */
name|u_char
name|igmp_code
decl_stmt|;
comment|/* unused, should be zero          */
name|u_short
name|igmp_cksum
decl_stmt|;
comment|/* IP-style checksum               */
name|struct
name|in_addr
name|igmp_group
decl_stmt|;
comment|/* group address being reported    */
block|}
struct|;
end_struct

begin_comment
comment|/*  (zero for queries)             */
end_comment

begin_define
define|#
directive|define
name|IGMP_MINLEN
value|8
end_define

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_QUERY
value|0x11
end_define

begin_comment
comment|/* message types, incl. version */
end_comment

begin_define
define|#
directive|define
name|IGMP_HOST_MEMBERSHIP_REPORT
value|0x12
end_define

begin_define
define|#
directive|define
name|IGMP_DVMRP
value|0x13
end_define

begin_comment
comment|/* for experimental multicast   */
end_comment

begin_comment
comment|/*  routing protocol            */
end_comment

begin_define
define|#
directive|define
name|IGMP_MAX_HOST_REPORT_DELAY
value|10
end_define

begin_comment
comment|/* max delay for response to    */
end_comment

end_unit

