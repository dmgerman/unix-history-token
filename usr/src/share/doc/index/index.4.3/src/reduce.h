begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* header for 4.3 index from thinking machines indexer */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Page
block|{
name|char
name|filename
index|[
literal|30
index|]
decl_stmt|;
name|char
name|percent
index|[
literal|30
index|]
decl_stmt|;
name|char
name|pageentry
index|[
literal|30
index|]
decl_stmt|;
comment|/* these entries are computed from pageentry 	or if unknown or blank, intuited from filename */
name|int
name|sortkey
decl_stmt|;
comment|/* output order, a function of vol and doc */
name|char
name|volname
index|[
literal|4
index|]
decl_stmt|;
comment|/* PRM, URM, USD, PS1, PS2, SMM */
name|int
name|section
decl_stmt|;
comment|/* for man pages: 1..8 */
name|int
name|docnum
decl_stmt|;
comment|/* for supplementary docs: 1..34 */
name|char
name|docname
index|[
literal|30
index|]
decl_stmt|;
comment|/* for man pages e.g. "cat" */
name|int
name|pagenum
decl_stmt|;
comment|/* page number within document; unknown = 0 */
block|}
name|Page
typedef|;
end_typedef

end_unit

