begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* header file for move generator hes 890318    Modified: 890510 minor bug fixed in Newataks              890606 NEWMOVE levels 1-6 */
end_comment

begin_if
if|#
directive|if
operator|(
name|NEWMOVE
operator|>=
literal|1
operator|)
end_if

begin_decl_stmt
specifier|extern
name|short
name|distdata
index|[
literal|64
index|]
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|taxidata
index|[
literal|64
index|]
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|taxicab
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|taxidata[a][b]
end_define

begin_define
define|#
directive|define
name|distance
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|distdata[a][b]
end_define

begin_function_decl
specifier|extern
name|void
name|Initialize_dist
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|NEWMOVE
operator|>=
literal|2
operator|)
end_if

begin_struct
struct|struct
name|sqdata
block|{
name|short
name|nextpos
decl_stmt|;
name|short
name|nextdir
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sqdata
name|posdata
index|[
literal|3
index|]
index|[
literal|8
index|]
index|[
literal|64
index|]
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|Initialize_moves
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ataks
parameter_list|(
name|side
parameter_list|,
name|a
parameter_list|)
define|\
value|{\   register short u,c,sq;\   register struct sqdata *p;\   short i,piece,*PL;\   \   for (u = 64; u; a[--u] = 0); \   PL = PieceList[side];\   for (i = 0; i<= PieceCnt[side]; i++)\     {\       sq = PL[i];\       piece = board[sq];\       c = control[piece];\       p = posdata[side][piece][sq];\       if (piece == pawn) {\ 	u = p[sq].nextdir;
comment|/* follow captures thread */
value|\ 	while (u != sq) {\ 	  a[u] = ++a[u] | c;\ 	  u = p[u].nextdir;\ 	}\       }\       else {\ 	u = p[sq].nextpos;\ 	while (u != sq) {\           a[u] = ++a[u] | c;\ 	  if (color[u] == neutral)\ 	    u = p[u].nextpos;\ 	  else\ 	    u = p[u].nextdir;\ 	}\       }\     }\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|NEWMOVE
operator|>=
literal|3
operator|)
end_if

begin_decl_stmt
specifier|extern
name|short
name|PieceList
index|[
literal|2
index|]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|Sqatakd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|NEWMOVE
operator|>
literal|3
operator|)
end_if

begin_decl_stmt
specifier|extern
name|short
name|Kfield
index|[
literal|2
index|]
index|[
literal|64
index|]
decl_stmt|,
name|PINVAL
decl_stmt|,
name|control
index|[
literal|7
index|]
decl_stmt|,
name|hung
index|[
literal|2
index|]
decl_stmt|,
name|XRAY
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern BRscan(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|NEWMOVE
operator|>
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|valueQ
value|1100
end_define

begin_decl_stmt
specifier|extern
name|short
name|PieceCnt
index|[
literal|2
index|]
decl_stmt|,
name|value
index|[
literal|7
index|]
decl_stmt|,
name|svalue
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern CaptureList(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|NEWMOVE
operator|>
literal|5
operator|)
end_if

begin_extern
extern|extern GenMoves(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

