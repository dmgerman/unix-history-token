begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* formatdef.c - some defines for sbr/formatsbr.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"@(#)$Id: formatdef.c,v 1.3 1992/12/15 00:20:22 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|"../h/addrsbr.h"
end_include

begin_decl_stmt
name|int
name|fmt_norm
init|=
name|AD_NAME
decl_stmt|;
end_decl_stmt

end_unit

