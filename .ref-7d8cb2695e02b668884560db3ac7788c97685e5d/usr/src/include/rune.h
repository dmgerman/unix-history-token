begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * %sccs.include.redist.c%  *  *	@(#)rune.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RUNE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RUNE_H_
end_define

begin_include
include|#
directive|include
file|<runetype.h>
end_include

begin_define
define|#
directive|define
name|_PATH_LOCALE
value|"/usr/share/locale"
end_define

begin_define
define|#
directive|define
name|_INVALID_RUNE
value|_CurrentRuneLocale->invalid_rune
end_define

begin_define
define|#
directive|define
name|__sgetrune
value|_CurrentRuneLocale->sgetrune
end_define

begin_define
define|#
directive|define
name|__sputrune
value|_CurrentRuneLocale->sputrune
end_define

begin_define
define|#
directive|define
name|sgetrune
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|r
parameter_list|)
value|(*__sgetrune)((s), (n), (r))
end_define

begin_define
define|#
directive|define
name|sputrune
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|r
parameter_list|)
value|(*__sputrune)((c), (s), (n), (r))
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|char
modifier|*
name|mbrune
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|rune_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mbrrune
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|rune_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mbmb
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setrunelocale
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setinvalidrune
name|__P
argument_list|(
operator|(
name|rune_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! _RUNE_H_ */
end_comment

end_unit

