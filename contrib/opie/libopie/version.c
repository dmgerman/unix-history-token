begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* version.c: The opieversion() library function.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1999 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.          History:  	Modified by cmetz for OPIE 2.2. Use FUNCTION declaration et al.         Created at NRL for OPIE 2.2 from opiesubr.c. */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_decl_stmt
name|VOIDRET
name|opieversion
name|FUNCTION_NOARGS
block|{
name|printf
argument_list|(
literal|"\nOPIE %s (%s)\n\n"
argument_list|,
name|VERSION
argument_list|,
name|DATE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

