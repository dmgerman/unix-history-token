begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Henry Spencer.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer of the University of Toronto.  *  * %sccs.include.redist.c%  *  *	@(#)regex.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_REGEX_H_
end_define

begin_comment
comment|/* types */
end_comment

begin_typedef
typedef|typedef
name|off_t
name|regoff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|re_magic
decl_stmt|;
name|size_t
name|re_nsub
decl_stmt|;
comment|/* number of parenthesized subexpressions */
name|struct
name|re_guts
modifier|*
name|re_g
decl_stmt|;
comment|/* none of your business :-) */
block|}
name|regex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|regoff_t
name|rm_so
decl_stmt|;
comment|/* start of match */
name|regoff_t
name|rm_eo
decl_stmt|;
comment|/* end of match */
block|}
name|regmatch_t
typedef|;
end_typedef

begin_decl_stmt
name|int
name|regcomp
name|__P
argument_list|(
operator|(
name|regex_t
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|regerror
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|regex_t
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|regexec
name|__P
argument_list|(
operator|(
specifier|const
name|regex_t
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|,
name|regmatch_t
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|regfree
name|__P
argument_list|(
operator|(
name|regex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regcomp() flags */
end_comment

begin_define
define|#
directive|define
name|REG_EXTENDED
value|001
end_define

begin_define
define|#
directive|define
name|REG_ICASE
value|002
end_define

begin_define
define|#
directive|define
name|REG_NOSUB
value|004
end_define

begin_define
define|#
directive|define
name|REG_NEWLINE
value|010
end_define

begin_comment
comment|/* regexec() flags */
end_comment

begin_define
define|#
directive|define
name|REG_NOTBOL
value|00001
end_define

begin_define
define|#
directive|define
name|REG_NOTEOL
value|00002
end_define

begin_define
define|#
directive|define
name|REG_STARTEND
value|00004
end_define

begin_define
define|#
directive|define
name|REG_TRACE
value|00400
end_define

begin_comment
comment|/* debugging tracing */
end_comment

begin_define
define|#
directive|define
name|REG_LARGE
value|01000
end_define

begin_comment
comment|/* force large state model for debug */
end_comment

begin_comment
comment|/* errors */
end_comment

begin_define
define|#
directive|define
name|REG_NOMATCH
value|(1)
end_define

begin_define
define|#
directive|define
name|REG_BADPAT
value|(2)
end_define

begin_define
define|#
directive|define
name|REG_ECOLLATE
value|(3)
end_define

begin_define
define|#
directive|define
name|REG_ECTYPE
value|(4)
end_define

begin_define
define|#
directive|define
name|REG_EESCAPE
value|(5)
end_define

begin_define
define|#
directive|define
name|REG_ESUBREG
value|(6)
end_define

begin_define
define|#
directive|define
name|REG_EBRACK
value|(7)
end_define

begin_define
define|#
directive|define
name|REG_EPAREN
value|(8)
end_define

begin_define
define|#
directive|define
name|REG_EBRACE
value|(9)
end_define

begin_define
define|#
directive|define
name|REG_BADBR
value|(10)
end_define

begin_define
define|#
directive|define
name|REG_ERANGE
value|(11)
end_define

begin_define
define|#
directive|define
name|REG_ESPACE
value|(12)
end_define

begin_define
define|#
directive|define
name|REG_BADRPT
value|(13)
end_define

begin_define
define|#
directive|define
name|REG_EMPTY
value|(14)
end_define

begin_comment
comment|/* empty component */
end_comment

begin_define
define|#
directive|define
name|REG_ASSERT
value|(15)
end_define

begin_comment
comment|/* assertion failure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_REGEX_H_ */
end_comment

end_unit

