begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)idp_var.h	7.3 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * IDP Kernel Structures and Variables  */
end_comment

begin_struct
struct|struct
name|idpstat
block|{
name|int
name|idps_badsum
decl_stmt|;
comment|/* checksum bad */
name|int
name|idps_tooshort
decl_stmt|;
comment|/* packet too short */
name|int
name|idps_toosmall
decl_stmt|;
comment|/* not enough data */
name|int
name|idps_badhlen
decl_stmt|;
comment|/* ip header length< data size */
name|int
name|idps_badlen
decl_stmt|;
comment|/* ip length< ip header length */
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
name|idpstat
name|idpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

