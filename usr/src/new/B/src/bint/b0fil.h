begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b0fil.h,v 1.4 85/08/22 16:41:24 timo Exp $ */
end_comment

begin_comment
comment|/* Declarations for variables containing file names. */
end_comment

begin_comment
comment|/* The corresponding initializations are in b0fil.c. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bpermfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tempfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|messfile
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|editorfile
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BPERMFILE
value|bpermfile
end_define

end_unit

