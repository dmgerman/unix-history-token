begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** bi_vars.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	bi_vars.h,v $  * Revision 5.1  91/12/05  07:59:05  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* bi_vars.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BI_VARS_H
end_ifndef

begin_define
define|#
directive|define
name|BI_VARS_H
value|1
end_define

begin_comment
comment|/* builtin variables NF, RS, FS, OFMT are stored    internally in field[], so side effects of assignment can    be handled  */
end_comment

begin_comment
comment|/* NR and FNR must be next to each other */
end_comment

begin_define
define|#
directive|define
name|NR
value|bi_vars
end_define

begin_define
define|#
directive|define
name|FNR
value|(bi_vars+1)
end_define

begin_define
define|#
directive|define
name|ARGC
value|(bi_vars+2)
end_define

begin_define
define|#
directive|define
name|FILENAME
value|(bi_vars+3)
end_define

begin_define
define|#
directive|define
name|OFS
value|(bi_vars+4)
end_define

begin_define
define|#
directive|define
name|ORS
value|(bi_vars+5)
end_define

begin_define
define|#
directive|define
name|RLENGTH
value|(bi_vars+6)
end_define

begin_define
define|#
directive|define
name|RSTART
value|(bi_vars+7)
end_define

begin_define
define|#
directive|define
name|SUBSEP
value|(bi_vars+8)
end_define

begin_if
if|#
directive|if
name|MSDOS
operator|&&
name|NO_BINMODE
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|BINMODE
value|(bi_vars+9)
end_define

begin_define
define|#
directive|define
name|NUM_BI_VAR
value|10
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NUM_BI_VAR
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|CELL
name|bi_vars
index|[
name|NUM_BI_VAR
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

