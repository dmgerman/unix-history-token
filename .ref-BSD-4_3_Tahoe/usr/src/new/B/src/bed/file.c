begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Bed -- file names collected together for easy reference and change. */
end_comment

begin_comment
comment|/* $Header: file.c,v 1.1 85/08/22 15:44:30 timo Exp $ */
end_comment

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_comment
comment|/* These are only defaults -- may be changed from environment */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|unix
end_ifdef

begin_decl_stmt
name|Visible
name|string
name|tmpdir
init|=
literal|"/tmp"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|homedir
init|=
literal|"."
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|libdir
init|=
literal|"/usr/new/lib/B"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|helpfile
init|=
literal|"/usr/new/lib/B/Bed_help"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|posfile
init|=
literal|".Bed_pos"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* With $HOME prepended */
end_comment

begin_decl_stmt
name|Visible
name|string
name|buffile
init|=
literal|".Bed_buf"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* With $HOME prepended */
end_comment

begin_decl_stmt
name|Visible
name|string
name|keyfile
init|=
literal|".Bed_"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some dir prepended, term.type appended */
end_comment

begin_decl_stmt
name|Visible
name|string
name|deftype
init|=
literal|"def"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default terminal type affix for keyfile */
end_comment

begin_endif
endif|#
directive|endif
endif|unix
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IBMPC
end_ifdef

begin_decl_stmt
name|Visible
name|string
name|tmpdir
init|=
literal|"\\"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|homedir
init|=
literal|"."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Can't get home... */
end_comment

begin_decl_stmt
name|Visible
name|string
name|libdir
init|=
literal|"\\LIB"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|helpfile
init|=
literal|"\\LIB\\BED.HLP"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|posfile
init|=
literal|"BED.POS"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|buffile
init|=
literal|"BED.BUF"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Visible
name|string
name|keyfile
init|=
literal|"BED."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some dir prepended, deftype appended */
end_comment

begin_decl_stmt
name|Visible
name|string
name|deftype
init|=
literal|"KEY"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default terminal type affix for keyfile */
end_comment

begin_endif
endif|#
directive|endif
endif|IBMPC
end_endif

begin_function
name|Hidden
name|string
name|setdefault
parameter_list|(
name|envname
parameter_list|,
name|def
parameter_list|)
name|string
name|envname
decl_stmt|;
name|string
name|def
decl_stmt|;
comment|/* 'default' is a C reserved word! */
block|{
name|string
name|envval
init|=
name|getenv
argument_list|(
name|envname
argument_list|)
decl_stmt|;
if|if
condition|(
name|envval
operator|!=
name|NULL
operator|&&
name|envval
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
return|return
name|envval
return|;
return|return
name|def
return|;
block|}
end_function

begin_function
name|Visible
name|initfile
parameter_list|()
block|{
specifier|static
name|char
name|copysavefile
index|[
literal|200
index|]
decl_stmt|;
specifier|static
name|char
name|saveposfile
index|[
literal|200
index|]
decl_stmt|;
name|homedir
operator|=
name|setdefault
argument_list|(
literal|"HOME"
argument_list|,
name|homedir
argument_list|)
expr_stmt|;
name|tmpdir
operator|=
name|setdefault
argument_list|(
literal|"TEMPDIR"
argument_list|,
name|tmpdir
argument_list|)
expr_stmt|;
name|libdir
operator|=
name|setdefault
argument_list|(
literal|"BED_LIB"
argument_list|,
name|libdir
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|copysavefile
argument_list|,
literal|"%.150s/%.40s"
argument_list|,
name|homedir
argument_list|,
name|buffile
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|saveposfile
argument_list|,
literal|"%.150s/%.40s"
argument_list|,
name|homedir
argument_list|,
name|posfile
argument_list|)
expr_stmt|;
name|helpfile
operator|=
name|setdefault
argument_list|(
literal|"BED_HELP"
argument_list|,
name|helpfile
argument_list|)
expr_stmt|;
name|posfile
operator|=
name|setdefault
argument_list|(
literal|"BED_POS"
argument_list|,
name|saveposfile
argument_list|)
expr_stmt|;
name|buffile
operator|=
name|setdefault
argument_list|(
literal|"BED_BUF"
argument_list|,
name|copysavefile
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

