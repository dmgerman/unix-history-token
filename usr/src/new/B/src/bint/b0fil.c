begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b0fil.c,v 1.4 85/08/22 16:48:05 timo Exp $ */
end_comment

begin_comment
comment|/* Built-in file names.  Some can be overridden by environment variables. */
end_comment

begin_comment
comment|/* Only recompilation of this file is necessary when a name is changed.   */
end_comment

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_include
include|#
directive|include
file|"b0fil.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IBMPC
end_ifdef

begin_decl_stmt
name|Visible
name|char
modifier|*
name|bpermfile
init|=
literal|"PERM.BIF"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|char
modifier|*
name|tempfile
init|=
literal|"TEMP.BIF"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|char
modifier|*
name|messfile
init|=
literal|"\\MESSAGES.BIF"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|Visible
name|char
modifier|*
name|bpermfile
init|=
literal|".b_perm"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|char
modifier|*
name|tempfile
init|=
literal|".@b_temp"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|char
modifier|*
name|messfile
init|=
literal|"/usr/local/lib/B/Messages"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BED
end_ifndef

begin_define
define|#
directive|define
name|BED
value|"/usr/local/lib/B/bed +"
end_define

begin_comment
comment|/* Trailing + if '+lineno' arg. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|Visible
name|char
modifier|*
name|editorfile
init|=
name|BED
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|Hidden
name|char
modifier|*
name|setdefault
parameter_list|(
name|envname
parameter_list|,
name|deflt
parameter_list|)
name|char
modifier|*
name|envname
decl_stmt|,
decl|*
name|deflt
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|p
init|=
name|getenv
argument_list|(
name|envname
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
operator|&&
name|p
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
return|return
name|p
return|;
return|return
name|deflt
return|;
block|}
end_block

begin_function
name|Visible
name|Procedure
name|set_file_names
parameter_list|()
block|{
name|messfile
operator|=
name|setdefault
argument_list|(
literal|"B_MESSAGES"
argument_list|,
name|messfile
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|INTEGRATION
name|editorfile
operator|=
name|setdefault
argument_list|(
literal|"B_EDITOR"
argument_list|,
name|setdefault
argument_list|(
literal|"BEDITOR"
argument_list|,
name|editorfile
argument_list|)
argument_list|)
expr_stmt|;
comment|/* BEDITOR used to be the name; officially it's now B_EDITOR */
endif|#
directive|endif
block|}
end_function

end_unit

