begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)idp_var.h	7.1 (Berkeley) %G%  */
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

