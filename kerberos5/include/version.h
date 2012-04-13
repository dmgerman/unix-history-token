begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_HIDDEN
end_ifndef

begin_define
define|#
directive|define
name|VERSION_HIDDEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|VERSION_HIDDEN
specifier|const
name|char
modifier|*
name|heimdal_long_version
init|=
literal|"@(#)$Version: Heimdal 1.5.2 (FreeBSD) $"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VERSION_HIDDEN
specifier|const
name|char
modifier|*
name|heimdal_version
init|=
literal|"Heimdal 1.5.2"
decl_stmt|;
end_decl_stmt

end_unit

