begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* context.h */
end_comment

begin_define
define|#
directive|define
name|M
value|pos[0].g
end_define

begin_comment
comment|/* Index of current token in model. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|P
end_ifdef

begin_undef
undef|#
directive|undef
name|P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|P
value|pos[0].t
end_define

begin_comment
comment|/* Index of current group in pos. */
end_comment

begin_define
define|#
directive|define
name|G
value|pos[P].g
end_define

begin_comment
comment|/* Index of current group in model. */
end_comment

begin_define
define|#
directive|define
name|T
value|pos[P].t
end_define

begin_comment
comment|/* Index of current token in its group. */
end_comment

begin_define
define|#
directive|define
name|Tstart
value|pos[P].tstart
end_define

begin_comment
comment|/* Index of starting token in its group 				 for AND group testing. */
end_comment

begin_define
define|#
directive|define
name|H
value|pos[P].h
end_define

begin_comment
comment|/* Pointer to hit bits for current group. */
end_comment

begin_define
define|#
directive|define
name|GHDR
value|mod[G]
end_define

begin_comment
comment|/* Current group header. */
end_comment

begin_define
define|#
directive|define
name|TOKEN
value|mod[M]
end_define

begin_comment
comment|/* Current token. */
end_comment

begin_define
define|#
directive|define
name|TTYPE
value|(GET(TOKEN.ttype, TTMASK))
end_define

begin_comment
comment|/* Token type of current token. */
end_comment

begin_define
define|#
directive|define
name|TOCC
value|(GET(TOKEN.ttype, TOREP))
end_define

begin_comment
comment|/* Occurrence for current token. */
end_comment

begin_define
define|#
directive|define
name|GTYPE
value|(GET(GHDR.ttype, TTMASK))
end_define

begin_comment
comment|/* Token type of current group. */
end_comment

begin_define
define|#
directive|define
name|GOCC
value|(GET(GHDR.ttype, TOREP))
end_define

begin_comment
comment|/* Occurrence for current group. */
end_comment

begin_define
define|#
directive|define
name|GNUM
value|GHDR.tu.tnum
end_define

begin_comment
comment|/* Number of tokens in current grp. */
end_comment

end_unit

