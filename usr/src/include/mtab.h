begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mtab.h	5.1 (Berkeley) 5/30/85  */
end_comment

begin_comment
comment|/*  * Mounted device accounting file.  */
end_comment

begin_struct
struct|struct
name|mtab
block|{
name|char
name|m_path
index|[
literal|32
index|]
decl_stmt|;
comment|/* mounted on pathname */
name|char
name|m_dname
index|[
literal|32
index|]
decl_stmt|;
comment|/* block device pathname */
name|char
name|m_type
index|[
literal|4
index|]
decl_stmt|;
comment|/* read-only, quotas */
block|}
struct|;
end_struct

end_unit

