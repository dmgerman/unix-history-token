begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)icmp_var.h	7.4 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Variables related to this implementation  * of the internet control message protocol.  */
end_comment

begin_struct
struct|struct
name|icmpstat
block|{
comment|/* statistics related to icmp packets generated */
name|int
name|icps_error
decl_stmt|;
comment|/* # of calls to icmp_error */
name|int
name|icps_oldshort
decl_stmt|;
comment|/* no error 'cuz old ip too short */
name|int
name|icps_oldicmp
decl_stmt|;
comment|/* no error 'cuz old was icmp */
name|int
name|icps_outhist
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* statistics related to input messages processed */
name|int
name|icps_badcode
decl_stmt|;
comment|/* icmp_code out of range */
name|int
name|icps_tooshort
decl_stmt|;
comment|/* packet< ICMP_MINLEN */
name|int
name|icps_checksum
decl_stmt|;
comment|/* bad checksum */
name|int
name|icps_badlen
decl_stmt|;
comment|/* calculated bound mismatch */
name|int
name|icps_reflect
decl_stmt|;
comment|/* number of responses */
name|int
name|icps_inhist
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|icmpstat
name|icmpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

