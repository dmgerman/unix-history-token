begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* typewriter driving table structure */
end_comment

begin_define
define|#
directive|define
name|NROFFCHARS
value|350
end_define

begin_comment
comment|/* ought to be dynamic */
end_comment

begin_struct
specifier|extern
struct|struct
name|t
block|{
name|int
name|bset
decl_stmt|;
comment|/* these bits have to be on */
name|int
name|breset
decl_stmt|;
comment|/* these bits have to be off */
name|int
name|Hor
decl_stmt|;
comment|/* #units in minimum horiz motion */
name|int
name|Vert
decl_stmt|;
comment|/* #units in minimum vert motion */
name|int
name|Newline
decl_stmt|;
comment|/* #units in single line space */
name|int
name|Char
decl_stmt|;
comment|/* #units in character width */
name|int
name|Em
decl_stmt|;
comment|/* ditto */
name|int
name|Halfline
decl_stmt|;
comment|/* half line units */
name|int
name|Adj
decl_stmt|;
comment|/* minimum units for horizontal adjustment */
name|char
modifier|*
name|twinit
decl_stmt|;
comment|/* initialize terminal */
name|char
modifier|*
name|twrest
decl_stmt|;
comment|/* reinitialize terminal */
name|char
modifier|*
name|twnl
decl_stmt|;
comment|/* terminal sequence for newline */
name|char
modifier|*
name|hlr
decl_stmt|;
comment|/* half-line reverse */
name|char
modifier|*
name|hlf
decl_stmt|;
comment|/* half-line forward */
name|char
modifier|*
name|flr
decl_stmt|;
comment|/* full-line reverse */
name|char
modifier|*
name|bdon
decl_stmt|;
comment|/* turn bold mode on */
name|char
modifier|*
name|bdoff
decl_stmt|;
comment|/* turn bold mode off */
name|char
modifier|*
name|iton
decl_stmt|;
comment|/* turn italic mode on */
name|char
modifier|*
name|itoff
decl_stmt|;
comment|/* turn italic mode off */
name|char
modifier|*
name|ploton
decl_stmt|;
comment|/* turn plot mode on */
name|char
modifier|*
name|plotoff
decl_stmt|;
comment|/* turn plot mode off */
name|char
modifier|*
name|up
decl_stmt|;
comment|/* sequence to move up in plot mode */
name|char
modifier|*
name|down
decl_stmt|;
comment|/* ditto */
name|char
modifier|*
name|right
decl_stmt|;
comment|/* ditto */
name|char
modifier|*
name|left
decl_stmt|;
comment|/* ditto */
name|char
modifier|*
name|eject
decl_stmt|;
comment|/* sequence to eject page */
name|char
modifier|*
name|codetab
index|[
name|NROFFCHARS
operator|-
literal|128
index|]
decl_stmt|;
name|char
name|width
index|[
name|NROFFCHARS
index|]
decl_stmt|;
block|}
name|t
struct|;
end_struct

end_unit

