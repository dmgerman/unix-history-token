begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_decl_stmt
specifier|const
endif|#
directive|endif
name|char
name|version_string
index|[]
init|=
literal|"GNU assembler version 1.38\n"
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* DO NOT PUT COMMENTS ABOUT CHANGES IN THIS FILE.     This file exists only to define `version_string'.     Log changes in ChangeLog.  The easiest way to do this is with    the Emacs command `add-change-log-entry'.  If you don't use Emacs,    add entries of the form:  Thu Jan  1 00:00:00 1970  Dennis Ritchie  (dmr at alice)  	* universe.c (temporal_reality): Began Time. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_macro
name|dummy3
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

