begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Fake multiplexor routines to satisfy references  * if you don't want it.  */
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/tty.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/mx.h"
end_include

begin_macro
name|sdata
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|chan
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|mcttstart
argument_list|(
argument|tp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|mpxchan
argument_list|()
end_macro

begin_block
block|{
name|u
operator|.
name|u_error
operator|=
name|EINVAL
expr_stmt|;
block|}
end_block

begin_macro
name|mcstart
argument_list|(
argument|p
argument_list|,
argument|q
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|chan
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|q
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_macro
name|scontrol
argument_list|(
argument|chan
argument_list|,
argument|s
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|chan
modifier|*
name|chan
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

end_unit

