begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vis.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIS_H_
end_define

begin_comment
comment|/*  * to select alternate encoding format  */
end_comment

begin_define
define|#
directive|define
name|VIS_OCTAL
value|0x01
end_define

begin_comment
comment|/* use octal \ddd format */
end_comment

begin_define
define|#
directive|define
name|VIS_CSTYLE
value|0x02
end_define

begin_comment
comment|/* use \[nrft0..] where appropiate */
end_comment

begin_comment
comment|/*  * to alter set of characters encoded (default is to encode all  * non-graphic except space, tab, and newline).  */
end_comment

begin_define
define|#
directive|define
name|VIS_SP
value|0x04
end_define

begin_comment
comment|/* also encode space */
end_comment

begin_define
define|#
directive|define
name|VIS_TAB
value|0x08
end_define

begin_comment
comment|/* also encode tab */
end_comment

begin_define
define|#
directive|define
name|VIS_NL
value|0x10
end_define

begin_comment
comment|/* also encode newline */
end_comment

begin_define
define|#
directive|define
name|VIS_WHITE
value|(VIS_SP | VIS_TAB | VIS_NL)
end_define

begin_define
define|#
directive|define
name|VIS_SAFE
value|0x20
end_define

begin_comment
comment|/* only encode "unsafe" characters */
end_comment

begin_comment
comment|/*  * other  */
end_comment

begin_define
define|#
directive|define
name|VIS_NOSLASH
value|0x40
end_define

begin_comment
comment|/* inhibit printing '\' */
end_comment

begin_comment
comment|/*  * unvis return codes  */
end_comment

begin_define
define|#
directive|define
name|UNVIS_VALID
value|1
end_define

begin_comment
comment|/* character valid */
end_comment

begin_define
define|#
directive|define
name|UNVIS_VALIDPUSH
value|2
end_define

begin_comment
comment|/* character valid, push back passed char */
end_comment

begin_define
define|#
directive|define
name|UNVIS_NOCHAR
value|3
end_define

begin_comment
comment|/* valid sequence, no character produced */
end_comment

begin_define
define|#
directive|define
name|UNVIS_SYNBAD
value|-1
end_define

begin_comment
comment|/* unrecognized escape sequence */
end_comment

begin_define
define|#
directive|define
name|UNVIS_ERROR
value|-2
end_define

begin_comment
comment|/* decoder in unknown state (unrecoverable) */
end_comment

begin_comment
comment|/*  * unvis flags  */
end_comment

begin_define
define|#
directive|define
name|UNVIS_END
value|1
end_define

begin_comment
comment|/* no more characters */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|char
modifier|*
name|vis
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strvis
name|__P
argument_list|(
operator|(
name|char
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
name|int
name|strvisx
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strunvis
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unvis
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
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
comment|/* !_VIS_H_ */
end_comment

end_unit

